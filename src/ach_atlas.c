#include "global.h"
#include "main.h"
#include "ach_atlas.h"
#include "task.h"
#include "m4a.h"
#include "bg.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "palette.h"
#include "scanline_effect.h"
#include "dma3.h"
#include "sprite.h"
#include "window.h"
#include "text.h"
#include "strings.h"
#include "menu.h"
#include "string_util.h"
#include "sound.h"
#include "overworld.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "event_data.h"
#include "script.h"

static const u8 sAchievementAtlasTileset[] = INCBIN_U8("graphics/achievement_atlas/achievement_atlas.4bpp");
static const u16 sAchievementAtlasTilemap[] = INCBIN_U16("graphics/achievement_atlas/achievement_atlas.bin");
static const u8 sAchievementAtlasPalette[] = INCBIN_U8("graphics/achievement_atlas/achievement_atlas.gbapal");

static const u8 sAtlasCursorTiles[] = INCBIN_U8("graphics/achievement_atlas/cursor.4bpp");
static const u16 sAtlasCursorPalette[] = INCBIN_U16("graphics/achievement_atlas/cursor.gbapal");

static const u8 sDescriptionNotAvailable[] = _("{COLOR LIGHT_GREY}{SHADOW LIGHT_RED}Locked.");

#include "data/achievements.h"

static const u8 sTextColors[][3] = {
    [CATEGORY_EXPLORATION] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY},
    [CATEGORY_BATTLE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED},
    [CATEGORY_COMPANIONS] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_BLUE, TEXT_COLOR_BLUE},
    [CATEGORY_QUESTING] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GREEN, TEXT_COLOR_GREEN},
};

enum
{
    WIN_ACH_LABEL,
    WIN_ACH_DESC
};

static const struct WindowTemplate sAtlasWindowTemplate[] =
{
    [WIN_ACH_LABEL] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 15,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_ACH_DESC] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 28,
        .height = 5,
        .paletteNum = 15,
        .baseBlock = 31,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct SpriteSheet sCursorTestTile = {
    .data = sAtlasCursorTiles,
    .size = sizeof(sAtlasCursorTiles),
    .tag = 0x6969
};
static const struct SpritePalette sCursorTestPal = {
    .data = sAtlasCursorPalette,
    .tag = 0x6969
};

const struct OamData sAtlasCursorOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const union AnimCmd sCursorIdleAnimation[] = {
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0),
    ANIMCMD_END
    //ANIMCMD_FRAME(32, 4),
};

static const union AnimCmd sCursorOnAchAnimation[] = {
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
    //ANIMCMD_FRAME(32, 4),
};

static const union AnimCmd *const sCursorAnims[] =
{
    sCursorIdleAnimation,
    sCursorOnAchAnimation
};


static const struct BgTemplate sAtlasBGTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static void AtlasCursorSpriteCB(struct Sprite *); // sprite template

const struct SpriteTemplate sAtlasCursorSpriteTemplate =
{
    .tileTag = 0x6969,
    .paletteTag = 0x6969,
    .oam = &sAtlasCursorOam,
    .anims = sCursorAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AtlasCursorSpriteCB,
};

static void CB2_Atlas(void);
static void VBlankCB_Atlas(void);

static bool8 IntializeAtlas(void);
static void DecideActionFromInput(u32 * action);
static void UpdateAtlasScroll(void);

static void Task_InitAtlas(u8);
static void Task_HandleAtlasInput(u8);
static void Task_UpdateAtlasStatus(u8);
static void Task_CloseAtlas(u8);

EWRAM_DATA static struct AchAtlas sAchAtlas = {0};

void CB2_OpenAtlas(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        gMain.state = 1;
        break;
    case 1:
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        gMain.state++;
        break;
    case 2:
        CreateTask(Task_InitAtlas, 0);
        gMain.state++;
        break;
    case 3:
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB_Atlas);
        SetMainCallback2(CB2_Atlas);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
        break;
    }
}

static void CB2_Atlas(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Atlas(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}


static void Task_InitAtlas(u8 taskId)
{
    if(IntializeAtlas())
        gTasks[taskId].func = Task_HandleAtlasInput;
}

static bool8 IntializeAtlas(void)
{
    u16 * map;
    u32 i, j;
    u32 tileX, tileY;
    switch (gMain.state)
    {
    case 0:
    default:
        if (gPaletteFade.active)
            return 0;
        SetVBlankCallback(NULL);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sAtlasBGTemplates, ARRAY_COUNT(sAtlasBGTemplates));
        SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
        RequestDma3Copy(sAchievementAtlasTileset, (u8*)VRAM, sizeof(sAchievementAtlasTileset), 0);
        map = GetBgTilemapBuffer(3);
        sAchAtlas.tilemapPosX = TILEMAP_START_X;
        sAchAtlas.tilemapPosY = TILEMAP_START_Y;
        tileY = sAchAtlas.tilemapPosY;
        for(i = 0; i < 22; i++, tileY++)
        {
            tileX = sAchAtlas.tilemapPosX;
            for(j = 0; j < 32; j++, tileX++)
            {
                map[i*32+j] = sAchievementAtlasTilemap[tileY*64+tileX];
            }
        }
        LoadPalette(sAchievementAtlasPalette, 0, 0x20);
        InitWindows(sAtlasWindowTemplate);
        DeactivateAllTextPrinters();
        PutWindowTilemap(0);
        CopyWindowToVram(0, 3);
        InitTextBoxGfxAndPrinters();
        gMain.state = 1;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LoadSpritePalette(&sCursorTestPal);
        LoadSpriteSheet(&sCursorTestTile);
        sAchAtlas.cursorSpriteId = CreateSprite(&sAtlasCursorSpriteTemplate, DISPLAY_WIDTH/2+4, (DISPLAY_HEIGHT/2)+4, 0);
        sAchAtlas.cursorX = sAchAtlas.tilemapPosX + DISPLAY_WIDTH/16;
        sAchAtlas.cursorY = sAchAtlas.tilemapPosY + DISPLAY_HEIGHT/16;
        gMain.state++;
        break;
    case 2:
        // i don't remember what this case was for but i copy pasted this from pokedex code so idk
        gMain.state++;
        break;
    case 3:
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_Atlas);
        gMain.state++;
        break;
    case 5:
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            gMain.state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static void Task_HandleAtlasInput(u8 taskId)
{
    u32 action = ACTION_NONE, speed = 8;
    u8 spriteId = sAchAtlas.cursorSpriteId;
    
    //StartSpriteAnim(&gSprites[spriteId], 1);
    
    DecideActionFromInput(&action);

    sAchAtlas.shouldUpdateTilemap = FALSE;
    if(!gTasks[taskId].data[1])
    {
        switch(action)
        {
        case ACTION_NONE:
        default:
            break;
        case ACTION_MOVE_LEFT:
            gSprites[spriteId].data[0] = action;
            gSprites[spriteId].data[1] = speed;
            sAchAtlas.cursorX -= speed / 8;
            if(sAchAtlas.cursorX < 1)
                sAchAtlas.cursorX = 1;
            if(sAchAtlas.tilemapPosX != 0 && sAchAtlas.cursorX <= (10 + sAchAtlas.tilemapPosX))
            {
                gSprites[spriteId].data[0] = 0;
                sAchAtlas.tilemapPosX -= speed / 8;
                if(sAchAtlas.tilemapPosX < 0)
                    sAchAtlas.tilemapPosX = 0;
                sAchAtlas.shouldUpdateTilemap = TRUE;
            }
            break;
        case ACTION_MOVE_RIGHT:
            gSprites[spriteId].data[0] = action;
            gSprites[spriteId].data[1] = speed;
            sAchAtlas.cursorX += speed / 8;
            if(sAchAtlas.cursorX >= ACH_ATLAS_WIDTH-2)
                sAchAtlas.cursorX = ACH_ATLAS_WIDTH-2;
            if(sAchAtlas.tilemapPosX != ACH_ATLAS_WIDTH-30 && sAchAtlas.cursorX >= (20 + sAchAtlas.tilemapPosX))
            {
                gSprites[spriteId].data[0] = 0;
                sAchAtlas.tilemapPosX += speed / 8;
                if(sAchAtlas.tilemapPosX >= ACH_ATLAS_WIDTH-30)
                    sAchAtlas.tilemapPosX = ACH_ATLAS_WIDTH-30;
                sAchAtlas.shouldUpdateTilemap = TRUE;
            }
            break;
        case ACTION_MOVE_UP:
            gSprites[spriteId].data[0] = action;
            gSprites[spriteId].data[1] = speed;
            sAchAtlas.cursorY -= speed / 8;
            if(sAchAtlas.cursorY < 1)
                sAchAtlas.cursorY = 1;
            if(sAchAtlas.tilemapPosY != 0 && sAchAtlas.cursorY <= (5 + sAchAtlas.tilemapPosY))
            {
                gSprites[spriteId].data[0] = 0;
                sAchAtlas.tilemapPosY -= speed / 8;
                if(sAchAtlas.tilemapPosY < 0)
                    sAchAtlas.tilemapPosY = 0;
                sAchAtlas.shouldUpdateTilemap = TRUE;
            }
            break;
        case ACTION_MOVE_DOWN:
            gSprites[spriteId].data[0] = action;
            gSprites[spriteId].data[1] = speed;
            sAchAtlas.cursorY += speed / 8;
            if(sAchAtlas.cursorY >= ACH_ATLAS_HEIGHT-2)
                sAchAtlas.cursorY = ACH_ATLAS_HEIGHT-2;
            if(sAchAtlas.tilemapPosY != ACH_ATLAS_HEIGHT-20 && sAchAtlas.cursorY >= (15 + sAchAtlas.tilemapPosY))
            {
                gSprites[spriteId].data[0] = 0;
                sAchAtlas.tilemapPosY += speed / 8;
                if(sAchAtlas.tilemapPosY >= ACH_ATLAS_HEIGHT-20)
                    sAchAtlas.tilemapPosY = ACH_ATLAS_HEIGHT-20;
                sAchAtlas.shouldUpdateTilemap = TRUE;   
            }
            break;
        case ACTION_GO_BACK:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_CloseAtlas;
            return;
        }
    }
    UpdateAtlasScroll();
    if(action != 0)
    {
        gTasks[taskId].data[0] = action;
        gTasks[taskId].func = Task_UpdateAtlasStatus;
    }
}

static void Task_CloseAtlas(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    }
}

static void Task_UpdateAtlasStatus(u8 taskId)
{
    u32 action = gTasks[taskId].data[0];
    u8 spriteId = sAchAtlas.cursorSpriteId;
    u32 achTileId;
    u32 i;
    u32 stringWidth;

    // really bad code to stop the cursor from moving when description window is visible
    if(sAchAtlas.isOnAchTile)
    {
        if(action == ACTION_GO_BACK && gTasks[taskId].data[1])
        {
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(WIN_ACH_DESC, TRUE);
            gTasks[taskId].data[1] = FALSE;
            gTasks[taskId].func = Task_HandleAtlasInput;
            return;
        }
        else if(action == ACTION_DISPLAY_DESC && !gTasks[taskId].data[1])
        {
            PlaySE(SE_SELECT);
            for(i = 0; i < ARRAY_COUNT(sAchAtlasData); i++)
            {
                if(sAchAtlasData[i].x == sAchAtlas.cursorX && sAchAtlasData[i].y == sAchAtlas.cursorY)
                {
                    
                    gTasks[taskId].data[1] = TRUE; 
                    DrawStdWindowFrame(WIN_ACH_DESC, TRUE);
                    if(CheckAchievement(sAchAtlasData[i].flagId))
                    {
                        StringExpandPlaceholders(gStringVar4, sAchAtlasData[i].descString);
                        AddTextPrinterParameterized3(WIN_ACH_DESC, 0, 0, 0, sTextColors[sAchAtlasData[i].category], 0, gStringVar4);
                    }
                    else
                    {
                        AddTextPrinterParameterized3(WIN_ACH_DESC, 0, 0, 0, sTextColors[0], 0, sDescriptionNotAvailable);
                    }
                    
                }
            }
            gTasks[taskId].func = Task_HandleAtlasInput;
            return;
        }
        else if(action == ACTION_DISPLAY_DESC && gTasks[taskId].data[1]) // edge case go brrr
        {
            gTasks[taskId].func = Task_HandleAtlasInput;
            return;
        }
        else if(gTasks[taskId].data[1])
        {
            gTasks[taskId].func = Task_HandleAtlasInput;
            return;
        }
    }
    for(i = 0; i < ARRAY_COUNT(sAchAtlasData); i++)
    {
        if(sAchAtlasData[i].x == sAchAtlas.cursorX && sAchAtlasData[i].y == sAchAtlas.cursorY)
        {
            StartSpriteAnim(&gSprites[spriteId], 1);
            ClearStdWindowAndFrameToTransparent(WIN_ACH_LABEL, TRUE);
            ClearStdWindowAndFrameToTransparent(WIN_ACH_DESC, TRUE);
            if(sAchAtlas.cursorY >= (13 + sAchAtlas.tilemapPosY)) // move around the windows because cursor will get in the way and we don't want that
            {
                SetWindowAttribute(WIN_ACH_LABEL, WINDOW_TILEMAP_TOP, 17);
                SetWindowAttribute(WIN_ACH_DESC, WINDOW_TILEMAP_TOP, 1);
            }
            else
            {
                SetWindowAttribute(WIN_ACH_LABEL, WINDOW_TILEMAP_TOP, 1);
                SetWindowAttribute(WIN_ACH_DESC, WINDOW_TILEMAP_TOP, 14);
            }
            stringWidth = GetStringWidth(0, sAchAtlasData[i].nameString, 0);
            SetWindowAttribute(WIN_ACH_LABEL, WINDOW_WIDTH, (stringWidth + 7) / 8); // This was not allowed in GF's own code so i edited the function to be able to do it
            DrawStdWindowFrame(WIN_ACH_LABEL, TRUE);
            sAchAtlas.isOnAchTile = TRUE;
            AddTextPrinterParameterized3(WIN_ACH_LABEL, 0, 0, 0, sTextColors[sAchAtlasData[i].category], 0, sAchAtlasData[i].nameString);
            achTileId = i;
            break;
        }
        achTileId = -1u;
    }
    if(achTileId == -1u)
    {
        if(sAchAtlas.isOnAchTile)
        {
            ClearStdWindowAndFrameToTransparent(WIN_ACH_LABEL, TRUE);
            ClearStdWindowAndFrameToTransparent(WIN_ACH_DESC, TRUE);
        }
        sAchAtlas.isOnAchTile = FALSE;
        StartSpriteAnimIfDifferent(&gSprites[spriteId], 0);
    }

    gTasks[taskId].func = Task_HandleAtlasInput;
}

static void DecideActionFromInput(u32 * action)
{
    // Test code lol
    /*
    if(JOY_HELD(B_BUTTON) && JOY_HELD(A_BUTTON) && JOY_NEW(SELECT_BUTTON))
    {
        GiveAchievement(0);
        GiveAchievement(1);
        GiveAchievement(2);
        GiveAchievement(3);
        GiveAchievement(4);
    }
    */

    // cursorHeldCounter is for making the motion of the cursor feel good
    // don't think it helped much but fine movement is easier like this at least
   
    if(JOY_NEW(DPAD_LEFT))
        *action = ACTION_MOVE_LEFT;
    else if(JOY_HELD(DPAD_LEFT)) 
        if(sAchAtlas.cursorHeldCounter > WAIT_FAST_SCROLL)
        {
            *action = ACTION_MOVE_LEFT;
            sAchAtlas.cursorHeldCounter = WAIT_FAST_SCROLL-1;
        }
        else if((sAchAtlas.cursorHeldCounter % WAIT_SLOW_SCROLL) == 0)
        {
            *action = ACTION_MOVE_LEFT;
            sAchAtlas.cursorHeldCounter++;
        }
        else
            sAchAtlas.cursorHeldCounter++;
    else if(JOY_NEW(DPAD_RIGHT))
        *action = ACTION_MOVE_RIGHT;
    else if(JOY_HELD(DPAD_RIGHT)) 
        if(sAchAtlas.cursorHeldCounter > WAIT_FAST_SCROLL)
        {
            *action = ACTION_MOVE_RIGHT;
            sAchAtlas.cursorHeldCounter = WAIT_FAST_SCROLL-1;
        }
        else if((sAchAtlas.cursorHeldCounter % WAIT_SLOW_SCROLL) == 0)
        {
            *action = ACTION_MOVE_RIGHT;
            sAchAtlas.cursorHeldCounter++;
        }
        else
            sAchAtlas.cursorHeldCounter++;
    else if(JOY_NEW(DPAD_UP))
        *action = ACTION_MOVE_UP;
    else if(JOY_HELD(DPAD_UP)) 
        if(sAchAtlas.cursorHeldCounter > WAIT_FAST_SCROLL)
        {
            *action = ACTION_MOVE_UP;
            sAchAtlas.cursorHeldCounter = WAIT_FAST_SCROLL-1;
        }
        else if((sAchAtlas.cursorHeldCounter % WAIT_SLOW_SCROLL) == 0)
        {
            *action = ACTION_MOVE_UP;
            sAchAtlas.cursorHeldCounter++;
        }
        else
            sAchAtlas.cursorHeldCounter++;
    else if(JOY_NEW(DPAD_DOWN))
        *action = ACTION_MOVE_DOWN;
    else if(JOY_HELD(DPAD_DOWN)) 
        if(sAchAtlas.cursorHeldCounter > WAIT_FAST_SCROLL)
        {
            *action = ACTION_MOVE_DOWN;
            sAchAtlas.cursorHeldCounter = WAIT_FAST_SCROLL-1;
        }
        else if((sAchAtlas.cursorHeldCounter % WAIT_SLOW_SCROLL) == 0)
        {
            *action = ACTION_MOVE_DOWN;
            sAchAtlas.cursorHeldCounter++;
        }
        else
            sAchAtlas.cursorHeldCounter++;
    else
    {
        sAchAtlas.cursorHeldCounter -= 5;
        if(sAchAtlas.cursorHeldCounter < 10) sAchAtlas.cursorHeldCounter = 1; 
    }

    if(JOY_NEW(A_BUTTON))
        *action = ACTION_DISPLAY_DESC;
    else if(JOY_NEW(B_BUTTON))
        *action = ACTION_GO_BACK;
}

static void UpdateAtlasScroll(void)
{
    u16 * map;
    u32 i, j;
    u32 tileX, tileY;

    if(sAchAtlas.shouldUpdateTilemap)
    {
        map = GetBgTilemapBuffer(3);
        tileY = sAchAtlas.tilemapPosY;
        for(i = 0; i < 22; i++, tileY++)
        {
            tileX = sAchAtlas.tilemapPosX;
            for(j = 0; j < 32; j++, tileX++)
            {
                map[i*32+j] = sAchievementAtlasTilemap[tileY*64+tileX];
            }
        }
        CopyBgTilemapBufferToVram(3);
    }
}


static void AtlasCursorSpriteCB(struct Sprite *sprite)
{
    u32 action = sprite->data[0];
    u32 speed = sprite->data[1];
    switch(action)
    {
        case ACTION_NONE:
        default:
            break;
        case ACTION_MOVE_LEFT:
            sprite->pos1.x -= speed;
            if(sprite->pos1.x < 8)
                sprite->pos1.x = 12;
            break;
        case ACTION_MOVE_RIGHT:
            sprite->pos1.x += speed;
            if(sprite->pos1.x > DISPLAY_WIDTH-12)
                sprite->pos1.x = DISPLAY_WIDTH-12;
            break;
        case ACTION_MOVE_UP:
            sprite->pos1.y -= speed;
            if(sprite->pos1.y < 8)
                sprite->pos1.y = 12;
            break;
        case ACTION_MOVE_DOWN:
            sprite->pos1.y += speed;
            if(sprite->pos1.y > DISPLAY_HEIGHT-12)
                sprite->pos1.y = DISPLAY_HEIGHT-12;
            break;
    }
    sprite->data[0] = ACTION_NONE;
}

void Ryu_GiveOrTakeAllAchievments(void)
{
    u8 current = 0;

    if (VarGet(VAR_TEMP_B) == 69)
    {
        do
        {
            GiveAchievement(current);
            current++;
        } while(current < 255);
    }
    else
    {
        do
        {
            TakeAchievement(current);
            current++;
        } while (current < 255);
        
    }
    
}

bool8 ScrCmd_ach(struct ScriptContext *ctx)// sorry for hacky solution, but we are nearly out of script commands.
{
    u8 mode = ScriptReadByte(ctx);
    u8 id = ScriptReadByte(ctx);

    switch (mode)
    {
    case 0:
            GiveAchievement(id);
            return FALSE;
    case 1:
            TakeAchievement(id);
            return FALSE;
    case 2:
            gSpecialVar_Result = (CheckAchievement(id));
            return FALSE;
    default:
            return FALSE;
    }
    
}

void GiveAchievement(u32 id)
{
    if(id > ACH_FLAGS_COUNT)
        return;

    gSaveBlock2Ptr->achFlags[id / 8] |= 1 << (id % 8);
}

bool32 CheckAchievement(u32 id)
{
    if(id > ACH_FLAGS_COUNT)
        return FALSE;

    return !!((gSaveBlock2Ptr->achFlags[id / 8] >> (id % 8)) & 1);
}

void TakeAchievement(u32 id)
{
    if(id > ACH_FLAGS_COUNT)
        return;
        
    gSaveBlock2Ptr->achFlags[id / 8] &= ~(1 << (id % 8));
}