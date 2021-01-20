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
#include "event_data.h"
#include "script.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static const u8 sAPMenuBackgroundTileset[] = INCBIN_U8("graphics/achievement_atlas/apscreen.8bpp");
static const u16 sAPMenuBackgroundTilemap[] = INCBIN_U16("graphics/achievement_atlas/apscreen.bin");
static const u8 sAPMenuBackgroundPalette[] = INCBIN_U8("graphics/achievement_atlas/apscreen.gbapal");

static const u8 sAPSelectTileset[] = INCBIN_U8("graphics/achievement_atlas/apselect_tile.4bpp");
static const u16 sAPSelectTilemap[] = INCBIN_U16("graphics/achievement_atlas/apselect.bin");
static const u8 sAPSelectPalette[] = INCBIN_U8("graphics/achievement_atlas/apselect_tile.gbapal");

static const u8 sAchievementAtlasStarTileset[] = INCBIN_U8("graphics/achievement_atlas/achievement_atlas.4bpp");
static const u16 sAchievementAtlasStarTilemap[] = INCBIN_U16("graphics/achievement_atlas/achievement_atlas.bin");
static const u8 sAchievementAtlasStarPalette[] = INCBIN_U8("graphics/achievement_atlas/achievement_atlas.gbapal");

static const u8 sAchievementAtlasPointsTile[] = INCBIN_U8("graphics/achievement_atlas/point_tiles.4bpp");
static const u8 sAchievementAtlasPointsPal[] = INCBIN_U8("graphics/achievement_atlas/point_tiles.gbapal");

static const u8 sAchievementAtlasBorderTiles[] = INCBIN_U8("graphics/achievement_atlas/border.4bpp");
static const u8 sAchievementAtlasBorderPal[] = INCBIN_U8("graphics/achievement_atlas/border.gbapal");
static const u8 sAchievementAtlasBorderTilemap[] = INCBIN_U8("graphics/achievement_atlas/border.bin");

static const u8 sAtlasCursorTiles[] = INCBIN_U8("graphics/achievement_atlas/cursor.4bpp");
static const u16 sAtlasCursorPalette[] = INCBIN_U16("graphics/achievement_atlas/cursor.gbapal");

static const u8 sDescriptionNotAvailable[] = _("{COLOR LIGHT_GREY}{SHADOW RED}Locked.");

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
    WIN_ACH_DESC,
    WIN_ACH_DEBUG,
};

static const struct WindowTemplate sAtlasWindowTemplate[] =
{
    [WIN_ACH_LABEL] = 
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_ACH_DESC] = 
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 13,
        .width = 26,
        .height = 5,
        .paletteNum = 15,
        .baseBlock = 53,
    },
    [WIN_ACH_DEBUG] =
    {
        .bg = 0,
        .tilemapLeft = 23,
        .tilemapTop = 2,
        .width = 5,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 183,
    },
    DUMMY_WIN_TEMPLATE
};

enum
{
    WIN_AP_TIERS,
    WIN_AP_TOTAL_AP,
    WIN_AP_SCROLL_NAME,
    WIN_AP_SCROLL_POWER_USAGE,
    WIN_AP_DESC
};

static const struct WindowTemplate sAPMenuWindowTemplates[] =
{
    [WIN_AP_TIERS] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 21,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_AP_TOTAL_AP] = 
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 1,
        .width = 5,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 43,
    },
    [WIN_AP_SCROLL_NAME] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 6,
        .width = 16,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 58,
    },
    [WIN_AP_SCROLL_POWER_USAGE] =
    {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 6,
        .width = 10,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 154,
    },
    [WIN_AP_DESC] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 214,
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

extern const u16 sEasyChatTriangleCursorPalette[];
extern const u32 sEasyChatTriangleCursorGfx[];

static const struct SpriteSheet sAPTierSelectTile = {
    .data = sEasyChatTriangleCursorGfx,
    .size = TILE_SIZE_4BPP,
    .tag = 0x7000
};
static const struct SpritePalette sAPTierSelectPal = {
    .data = sEasyChatTriangleCursorPalette,
    .tag = 0x7000
};

const struct OamData sAPTierSelectOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
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
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 26,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
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
/*
static const struct BgTemplate sAPMenuTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 26,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 1,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};
*/
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

const struct SpriteTemplate sAPTierSelectSpriteTemplate =
{
    .tileTag = 0x7000,
    .paletteTag = 0x7000,
    .oam = &sAPTierSelectOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
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

static void Task_OpenAPMenu(u8);
static void Task_HandleAPInput(u8);

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
        SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE*4));
        SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
        DmaCopy16(3, sAchievementAtlasStarTilemap, GetBgTilemapBuffer(3), sizeof(sAchievementAtlasStarTilemap));
        DmaCopy16(3, sAchievementAtlasPointsTile, BG_CHAR_ADDR(0), sizeof(sAchievementAtlasPointsTile));
        DmaCopy16(3, sAchievementAtlasBorderTiles, BG_CHAR_ADDR(0)+0x20*3, sizeof(sAchievementAtlasBorderTiles));
        DmaCopy16(3, sAchievementAtlasStarTileset, BG_CHAR_ADDR(0)+0x20*6, sizeof(sAchievementAtlasStarTileset));
        DmaCopy16(3, sAchievementAtlasBorderTilemap, GetBgTilemapBuffer(2), sizeof(sAchievementAtlasBorderTilemap));
        sAchAtlas.tilemapPosX = TILEMAP_START_X;
        sAchAtlas.tilemapPosY = TILEMAP_START_Y;
        LoadPalette(sAchievementAtlasStarPalette, 0, 0x20);
        LoadPalette(sAchievementAtlasPointsPal, 0x10, 0x20);
        LoadPalette(sAchievementAtlasBorderPal, 0x20, 0x20);
        InitWindows(sAtlasWindowTemplate);
        InitTextBoxGfxAndPrinters();
        DeactivateAllTextPrinters();
        PutWindowTilemap(0);
        CopyWindowToVram(0, 3);
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
        // this was empty before
        // now it isn't
        map = GetBgTilemapBuffer(1);
        for(i = 0; i < ARRAY_COUNT(sAchAtlasData); i++)
        {
            u32 x = sAchAtlasData[i].x;
            u32 y = sAchAtlasData[i].y;
            u32 index = ((y%32)*32 + ((y/32)*2048) + ((x)%32) + ((x/32)*1024));
            map[index] = CheckAchievement(i) ? (1 + 0x1000) : (2 + 0x1000);
        }
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
        SetGpuReg(REG_OFFSET_BG1HOFS, sAchAtlas.tilemapPosX*8);
        SetGpuReg(REG_OFFSET_BG1VOFS, sAchAtlas.tilemapPosY*8);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, sAchAtlas.tilemapPosX*3);
        SetGpuReg(REG_OFFSET_BG3VOFS, sAchAtlas.tilemapPosY*3);
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
            //gTasks[taskId].func = Task_OpenAPMenu;
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
    u32 i;
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        for(i = 0; i < 4; i++)
        {
            Free(GetBgTilemapBuffer(i));
            UnsetBgTilemapBuffer(i);
        }
        RemoveWindow(WIN_ACH_LABEL);
        RemoveWindow(WIN_ACH_DESC);
        RemoveWindow(WIN_ACH_DEBUG);
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    }
}

#define MCDBGAP

#define tSelectedTier data[0]
#define tSelectedAP data[1]
#define tSelectingAP data[2]
#define tChangedTier data[3]
#define tAPOffset data[4]
#define tChangedAP data[5]

static void Task_UpdateSelections(u8 taskId);

static void PrintAPUsageString(void)
{
    u8 * str;
    ClearWindowTilemap(WIN_AP_TOTAL_AP);
    str = ConvertUIntToDecimalStringN(gStringVar1, GetCurrentAPUsed(), STR_CONV_MODE_LEADING_ZEROS, 3);
    str[0] = CHAR_SLASH;
    ConvertUIntToDecimalStringN(str+1, GetPlayerAPMax(), STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized3(WIN_AP_TOTAL_AP, 0, 4, 2, sTextColors[0], 0, gStringVar1);
    
}

static void Task_OpenAPMenu(u8 taskId) // inefficient right from the start and that's how i like it jesus please help i'm stuck at home destroying my sanity
{
    //u16 * tilemaps[4];
    u32 i;
    
    if (gPaletteFade.active)
        return;

    //for(i = 0; i < 4; i++)
        //tilemaps[i] = GetBgTilemapBuffer(i);
    DestroySprite(&gSprites[sAchAtlas.cursorSpriteId]);
    LoadSpritePalette(&sAPTierSelectPal);
    LoadSpriteSheet(&sAPTierSelectTile);
    // repurposed the cursorspriteid field for later use since we delete the cursor sprite anyways
    sAchAtlas.cursorSpriteId = CreateSprite(&sAPTierSelectSpriteTemplate, 12, 19, 0);
    // selected tier
    gTasks[taskId].tSelectedTier = AP_TIER_PLATINUM;
    // selected AP
    gTasks[taskId].tSelectedAP = 0;
    //help
    /*
    // init slected Tier AP Count
    gTasks[taskId].tSelectedTierAPCount = 0;
    for(i = 0; i < TOTAL_AP_COUNT; i++) // this is redundant but the data containing this stuff is not necessarily structured the best way and i have myself to blame for that
    {
        if(gTasks[taskId].tSelectedTier == gAP_Info[i].tier)
            gTasks[taskId].tSelectedTierAPCount++;    
    }
    */
    HideBg(1);
    DmaCopy16(3, sAPMenuBackgroundTileset, BG_CHAR_ADDR(0), sizeof(sAPMenuBackgroundTileset));
    DmaCopy16(3, sAPMenuBackgroundTilemap, GetBgTilemapBuffer(2), sizeof(sAPMenuBackgroundTilemap));
    LoadPalette(sAPMenuBackgroundPalette, 0, sizeof(sAPMenuBackgroundPalette));
    SetBgAttribute(2, BG_ATTR_PALETTEMODE, 1);
    SetBgAttribute(2, BG_ATTR_PRIORITY, 3);
    ShowBg(2);
    DmaCopy16(3, sAPSelectTileset, BG_CHAR_ADDR(0)+0xF0*TILE_SIZE_4BPP, sizeof(sAPSelectTileset));
    DmaCopy16(3, sAPSelectTilemap, GetBgTilemapBuffer(3), sizeof(sAPSelectTilemap));
    LoadPalette(sAPSelectPalette, 0x80, sizeof(sAPSelectPalette));
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3X, 4);
    SetGpuReg(REG_OFFSET_BG3Y, 4);
    SetBgAttribute(3, BG_ATTR_PRIORITY, 2);
    ShowBg(3);
    CopyBgTilemapBufferToVram(2);
    CopyBgTilemapBufferToVram(3);
    //FreeAllWindowBuffers();
    ClearWindowTilemap(WIN_ACH_LABEL);
    ClearWindowTilemap(WIN_ACH_DESC);
    ClearWindowTilemap(WIN_ACH_DEBUG);
    RemoveWindow(WIN_ACH_LABEL);
    RemoveWindow(WIN_ACH_DESC);
    RemoveWindow(WIN_ACH_DEBUG);
    InitWindows(sAPMenuWindowTemplates);
    InitTextBoxGfxAndPrinters();
    DeactivateAllTextPrinters();
#ifdef MCDBGAP
    for(i = 0; i <= WIN_AP_DESC; i++)
    {
        PutWindowTilemap(i);
        CopyWindowToVram(i, 3);
        //DrawStdWindowFrame(i, TRUE);
    }
#endif
    PrintAPUsageString();
    //AddTextPrinterParameterized3(WIN_AP_TOTAL_AP)
    //AddTextPrinterParameterized3(WIN_AP_SCROLL_NAME, 0, 0, 0, sTextColors[0], 0xFF, gAP_Info[0].name);
    //CopyWindowToVram(WIN_AP_DESC, 2);
    gTasks[taskId].tChangedTier = TRUE; // debug
    gTasks[taskId].func = Task_UpdateSelections;
}

static void Task_HandleAPInput(u8 taskId)
{
    if(gMain.newKeys & A_BUTTON)
    {
        if(!gTasks[taskId].tSelectingAP)
        {
            gTasks[taskId].tSelectingAP = TRUE;
            FillWindowPixelBuffer(WIN_AP_DESC, 0);
            AddTextPrinterParameterized3(WIN_AP_DESC, 0, 4, 2, sTextColors[0], 0, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[gTasks[taskId].tSelectedAP].desc);
        }
    }
    if(gMain.newKeys & B_BUTTON)
    {
        if(gTasks[taskId].tSelectingAP)
        {
            gTasks[taskId].tSelectingAP = FALSE;
            // what the hell man
            FillWindowPixelBuffer(WIN_AP_DESC, 0);
            CopyWindowToVram(WIN_AP_DESC, 2);
        }
    }
        //gTasks[taskId].func = Task_CloseAtlas;
    if(gTasks[taskId].tSelectingAP)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            if(--gTasks[taskId].tSelectedAP < 0)
                gTasks[taskId].tSelectedAP = gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1;
            gTasks[taskId].tChangedAP = TRUE;
            gTasks[taskId].func = Task_UpdateSelections;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if(++gTasks[taskId].tSelectedAP > gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1)
                gTasks[taskId].tSelectedAP = 0;
            gTasks[taskId].tChangedAP = TRUE;
            gTasks[taskId].func = Task_UpdateSelections;
        }
    }
    else
    {
        if(gMain.newKeys & DPAD_LEFT)
        {
            if(--gTasks[taskId].tSelectedTier < AP_TIER_PLATINUM)
                gTasks[taskId].tSelectedTier = AP_TIER_COPPER;
            gTasks[taskId].tChangedTier = TRUE;
            gTasks[taskId].func = Task_UpdateSelections;
        }
        else if(gMain.newKeys & DPAD_RIGHT)
        {   
            if(++gTasks[taskId].tSelectedTier > AP_TIER_COPPER)
                gTasks[taskId].tSelectedTier = AP_TIER_PLATINUM;
            gTasks[taskId].tChangedTier = TRUE;
            gTasks[taskId].func = Task_UpdateSelections;
        }
    }
}

static void Task_UpdateSelections(u8 taskId)
{
    const u8 sTierCursorXPos[] = {12, 67, 100, 140}; // evil hardcoding
    u32 i;

    if(gTasks[taskId].tChangedTier) //ugh
    {
        gTasks[taskId].tChangedTier = FALSE;
        gTasks[taskId].tSelectedAP = 0;
        gSprites[sAchAtlas.cursorSpriteId].pos1.x = sTierCursorXPos[gTasks[taskId].tSelectedTier];
        FillWindowPixelBuffer(WIN_AP_SCROLL_NAME, 0);
        FillWindowPixelBuffer(WIN_AP_SCROLL_POWER_USAGE, 0);
        for(i = 0; i < 4 && i < gAP_Info[gTasks[taskId].tSelectedTier].tierCount; i++)
        {
            static const u8 usedAP[] = _("{STR_VAR_1}AP"); 
            const u8 * color = sTextColors[2];
            if(CheckAPFlag(gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i].apId))
                color = sTextColors[3];
            else if(gAP_Info[gTasks[taskId].tSelectedTier].requiredAP > (GetPlayerAPMax()-GetCurrentAPUsed())) // oh jesus christ
                color = sTextColors[1];
            AddTextPrinterParameterized3(WIN_AP_SCROLL_NAME, 0, 4, i * 12, color, 0, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i].name);
            ConvertUIntToDecimalStringN(gStringVar1, gAP_Info[gTasks[taskId].tSelectedTier].requiredAP, STR_CONV_MODE_LEFT_ALIGN, 2);
            StringExpandPlaceholders(gStringVar4, usedAP);
            AddTextPrinterParameterized3(WIN_AP_SCROLL_POWER_USAGE, 0, 4, i * 12, color, 0, gStringVar4);
        }
    }
    else if(gTasks[taskId].tChangedAP)
    {
        gTasks[taskId].tChangedAP = FALSE;
        FillWindowPixelBuffer(WIN_AP_DESC, 0);
        AddTextPrinterParameterized3(WIN_AP_DESC, 0, 4, 2, sTextColors[0], 0, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[gTasks[taskId].tSelectedAP].desc);
    }
    gTasks[taskId].func = Task_HandleAPInput;
}

static const u8 sXColon[] = _("X:");
static const u8 sYColon[] = _("Y:");

static void Task_UpdateAtlasStatus(u8 taskId)
{
    u32 action = gTasks[taskId].data[0];
    u8 spriteId = sAchAtlas.cursorSpriteId;
    u32 achTileId;
    u32 i;
    u32 stringWidth;

    if(FlagGet(FLAG_RYU_DEV_MODE))
    {
        u8 str[6];
        DrawStdWindowFrame(WIN_ACH_DEBUG, TRUE); // inefficient but it's for debugging
        StringCopy(str, sXColon);
        ConvertIntToDecimalStringN(gStringVar1, sAchAtlas.cursorX, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringAppend(str, gStringVar1);
        AddTextPrinterParameterized3(WIN_ACH_DEBUG, 0, 0, 0, sTextColors[0], 0, str);
        StringCopy(str, sYColon);
        ConvertIntToDecimalStringN(gStringVar1, sAchAtlas.cursorY, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringAppend(str, gStringVar1);
        AddTextPrinterParameterized3(WIN_ACH_DEBUG, 0, 0, 8, sTextColors[0], 0, str);
    }
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
                        AddTextPrinterParameterized3(WIN_ACH_DESC, 0, 0, 0, sTextColors[0], 0, gStringVar4);
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
            if(sAchAtlas.cursorY >= (12 + sAchAtlas.tilemapPosY)) // move around the windows because cursor will get in the way and we don't want that
            {
                SetWindowAttribute(WIN_ACH_LABEL, WINDOW_TILEMAP_TOP, 16);
                SetWindowAttribute(WIN_ACH_DESC, WINDOW_TILEMAP_TOP, 2);
            }
            else
            {
                SetWindowAttribute(WIN_ACH_LABEL, WINDOW_TILEMAP_TOP, 2);
                SetWindowAttribute(WIN_ACH_DESC, WINDOW_TILEMAP_TOP, 13);
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
        /*
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
        */
        SetGpuReg(REG_OFFSET_BG3VOFS, sAchAtlas.tilemapPosY*3);
        SetGpuReg(REG_OFFSET_BG3HOFS, sAchAtlas.tilemapPosX*3);
        SetGpuReg(REG_OFFSET_BG1VOFS, sAchAtlas.tilemapPosY*8);
        SetGpuReg(REG_OFFSET_BG1HOFS, sAchAtlas.tilemapPosX*8);
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

    if (VarGet(VAR_TEMP_B) == 69) // because nice
    {
        do
        {
            GiveAchievementDebug(current++);
        } while(current < 255);
    }
    else
    {
        do
        {
            TakeAchievement(current++);
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

void BufferGivenAchievement(void) //Buffers the last given achievement label for use in script.
{
    u16 ach = VarGet(VAR_TEMP_C);
    StringExpandPlaceholders(gStringVar4, sAchAtlasData[ach].nameString);
    StringCopy(gRyuStringVar4, gStringVar4);
}

void GiveAchievementDebug(u32 id)
{
    gSaveBlock2Ptr->achFlags[id / 8] |= 1 << (id % 8);
}

void GiveAchievement(u32 id)
{
    if(id > ACH_FLAGS_COUNT)
        return;

    if (CheckAchievement(id) == FALSE)
        VarSet(VAR_RYU_LAST_ACH, id);//let the global script know that player received an achievement recently.
    else
        VarSet(VAR_RYU_LAST_ACH, 300);//the achievment that was given was already owned by player.

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