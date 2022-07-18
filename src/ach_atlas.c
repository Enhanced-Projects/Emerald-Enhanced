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
#include "graphics.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "overworld_notif.h"
#include "constants/items.h"
#include "item.h"

static const u8 sAPMenuBackgroundTileset[] = INCBIN_U8("graphics/achievement_atlas/apscreen.8bpp");
static const u16 sAPMenuBackgroundTilemap[] = INCBIN_U16("graphics/achievement_atlas/apscreen.bin");
static const u8 sAPMenuBackgroundPalette[] = INCBIN_U8("graphics/achievement_atlas/apscreen.gbapal");


static const u8 sAPSelectTileset[] = INCBIN_U8("graphics/achievement_atlas/apselectbar.4bpp");
static const u16 sAPSelectTilemap[] = INCBIN_U16("graphics/achievement_atlas/apselect.bin");
static const u16 sAPSelectPalette[] = INCBIN_U16("graphics/achievement_atlas/apselectbar.gbapal");

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

static const u8 sGoldTextColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2};
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

static const struct SpriteSheet sAPSelectSpriteSheet = {
    .data = sAPSelectTileset,
    .size = TILE_SIZE_4BPP,
    .tag = 0x7001
};
static const struct SpritePalette sAPSelectSpritePal = {
    .data = sAPSelectPalette,
    .tag = 0x7001
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

const struct SpriteTemplate sAPSelectSpriteTemplate =
{
    .tileTag = 0x7001,
    .paletteTag = 0x7001,
    .oam = &sAPTierSelectOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct Subsprite sAPSelectSubsprites[] =
{
    {.x =  0, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 0, .priority = 1},
    {.x =  32, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 8, .priority = 1},
    {.x =  64, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 16, .priority = 1},
    {.x =  96, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 24, .priority = 1},
    {.x =  128, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 32, .priority = 1},
};

static const struct SubspriteTable sAPSelectSubspriteTable[] =
{
    {ARRAY_COUNT(sAPSelectSubsprites), sAPSelectSubsprites},
};

static void CB2_Atlas(void);
static void VBlankCB_Atlas(void);

static bool8 IntializeAtlas(void);
static void DecideActionFromInput(u32 * action);
static void UpdateAtlasScroll(void);

void Task_InitAtlas(u8);
static void Task_HandleAtlasInput(u8);
static void Task_UpdateAtlasStatus(u8);
static void Task_CloseAtlas(u8);

void Task_OpenAPMenu(u8);
static void Task_HandleAPInput(u8);

EWRAM_DATA static struct AchAtlas sAchAtlas = {0};

EWRAM_DATA static u8 sAPBorderSpriteIDs[4] = {0};

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
        gReservedSpritePaletteCount = 0;
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
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
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


void Task_InitAtlas(u8 taskId)
{
    if(IntializeAtlas())
        gTasks[taskId].func = Task_HandleAtlasInput;
}

void CB2_OpenJournal(void);

static void Task_OpenJournalAfterFade(u8 taskId)
{
    if(gPaletteFade.active)
        return;
    SetMainCallback2(CB2_OpenJournal);
}

// FULL_COLOR
static bool8 IntializeAtlas(void)
{
    u16 buf[32];
    u16 * map;
    u16 tempColor;
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
        DmaCopy16(3, sAchievementAtlasPointsTile, BG_CHAR_ADDR(0), sizeof(sAchievementAtlasPointsTile)); // first 13 tiles reserved for this
        DmaCopy16(3, sAchievementAtlasBorderTiles, BG_CHAR_ADDR(0)+0x20*13, sizeof(sAchievementAtlasBorderTiles)); // 3 TILES for this at the end
        DmaCopy16(3, sAchievementAtlasStarTileset, BG_CHAR_ADDR(0)+0x20*16, sizeof(sAchievementAtlasStarTileset)); // rest of the tiles in char 1 is for this
        DmaCopy16(3, sAchievementAtlasBorderTilemap, GetBgTilemapBuffer(2), sizeof(sAchievementAtlasBorderTilemap));
        sAchAtlas.tilemapPosX = TILEMAP_START_X;
        sAchAtlas.tilemapPosY = TILEMAP_START_Y;
        LoadPalette(sAchievementAtlasStarPalette, 0, 0x20);
        LoadPalette(sAchievementAtlasPointsPal, 0x10, 0x20);
        //FULL_COLOR TODO impl vanilla and switch(VAR)
        if (VarGet(VAR_RYU_THEME_NUMBER) == 2) {
            CpuCopy16(sAchievementAtlasBorderPal, buf, 0x20);
            buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[1];       // 1 = bg
            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[13];       // 2 = window border
            buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[14];       // 13 = text color
            LoadPalette(buf, 0x20, 0x20);
        } else
            LoadPalette(sAchievementAtlasBorderPal, 0x20, 0x20);
        InitWindows(sAtlasWindowTemplate);
        InitTextBoxGfxAndPrinters();
        DeactivateAllTextPrinters();
        tempColor = RGB(25, 20, 2);
        LoadPalette(&tempColor, 0xF0 + TEXT_DYNAMIC_COLOR_1, 0x2);
        tempColor = RGB(18, 14, 0);
        LoadPalette(&tempColor, 0xF0 + TEXT_DYNAMIC_COLOR_2, 0x2);
        PutWindowTilemap(0);
        CopyWindowToVram(0, 3);
        gMain.state = 1;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 0;
        LoadSpritePalette(&sCursorTestPal);
        LoadSpriteSheet(&sCursorTestTile);
        sAchAtlas.cursorSpriteId = CreateSprite(&sAtlasCursorSpriteTemplate, DISPLAY_WIDTH/2+4, (DISPLAY_HEIGHT/2)+4, 0);
        sAchAtlas.cursorX = sAchAtlas.tilemapPosX + DISPLAY_WIDTH/16;
        sAchAtlas.cursorY = sAchAtlas.tilemapPosY + DISPLAY_HEIGHT/16;
        gMain.state++;
        break;
    case 2: // Draw Achivement icons on BG 1
        // this was empty before
        // now it isn't
        map = GetBgTilemapBuffer(1);
        for(i = 0; i < ARRAY_COUNT(sAchAtlasData); i++)
        {
            u32 x = sAchAtlasData[i].x;
            u32 y = sAchAtlasData[i].y;
            u32 index = ((y%32)*32 + ((y/32)*2048) + ((x)%32) + ((x/32)*1024));
            if(CheckAchievement(i))
            {
                if(sAchAtlasData[i].category & CATEGORY_FLAG_GOLD)
                    map[index] = 3 + 0x1000;
                else
                    map[index] = 1 + 0x1000;
            }
            else
                map[index] = 2 + 0x1000;

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
            gTasks[taskId].func = Task_CloseAtlas;
            return;
        /*
        case ACTION_OPEN_APMENU:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_OpenAPMenu;
            return;
        */
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
        SetMainCallback2(CB2_OpenJournal);
        //SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    }
}

#define tSelectedTier data[0]
#define tSelectedAP data[1]
#define tSelectAPPos data[2] // god knows what i'm trying to say
#define tSelectedAPOffset data[3]

/*
enum
{
    APSTATE_INPUT_WAIT,
    APSTATE_TIER_CHANGE,
    APSTATE_AP_SCROLL,
};
*/

enum
{
    APSTATE_INPUT_TIERSELECT,
    APSTATE_INPUT_APSELECT,
    APSTATE_APOFFSET_CHANGED
};

#define tAPState data[4]
#define tDisEnaAP data[5] // if you're wondering what the fuck this name is supposed to be
// then fear not since i am commenting this code like a fucking 2 year old
// this "field" is used to see if we are supposed to disable or enable an AP
// in the Yes/No box, where 0 means disable and 1 means enable

/* hell no
#define tChangedTier data[3]
#define tChangedAP data[4]
#define tChangedAPOffset data[7] // only 8 u16s jesus
// position of the border around the selected AP because i can't use tSelectedAP since it's for something else
// on second thought i could use an offset + position but it would be the same deal but easier to handle the box
// god have mercy on whoever is editing this code, i'm watching 4 dimensional chess, my brain has ascended
*/


static void Task_UpdateTierSelections(u8 taskId);
static void Task_UpdateAPSelections(u8 taskId);

static void PrintAPUsageString(void)
{
    u8 * str;
    //ClearWindowTilemap(WIN_AP_TOTAL_AP);　ばか
    FillWindowPixelBuffer(WIN_AP_TOTAL_AP, 0);
    str = ConvertUIntToDecimalStringN(gStringVar1, GetCurrentAPUsed(), STR_CONV_MODE_LEADING_ZEROS, 3);
    str[0] = CHAR_SLASH;
    ConvertUIntToDecimalStringN(str+1, GetPlayerAPMax(), STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized3(WIN_AP_TOTAL_AP, 0, 4, 2, sTextColors[0], 0, gStringVar1);
    
}
// NOT A TASK FUNCTION
static void UpdateSelectionCorners(u8 taskId)
{
    u32 i, spriteId, width;
    for(i = 0; i < 4; i++)
    {
        spriteId = sAPBorderSpriteIDs[i];
        //gTasks[taskId].tSelectedAP
        width = GetStringWidth(0, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[gTasks[taskId].tSelectedAP].name, 0);
        // fear my magic numbers
        gSprites[spriteId].pos1.x = 13 + width * (i&1); 
        gSprites[spriteId].pos1.y = 53 + gTasks[taskId].tSelectAPPos * 12 + (!!(i & 2)) * 6;
    }
}

static void HideSelectionCorners(void)
{
    u32 i, spriteId;
    for(i = 0; i < 4; i++)
    {
        spriteId = sAPBorderSpriteIDs[i];
        gSprites[spriteId].invisible = TRUE;
    }
}

static void ShowSelectionCorners(void)
{
    u32 i, spriteId;
    for(i = 0; i < 4; i++)
    {
        spriteId = sAPBorderSpriteIDs[i];
        gSprites[spriteId].invisible = FALSE;
    }
}

static bool8 IntializeAP(u8 taskId);
void Task_InitAPMenu(u8 taskId)
{
    if(IntializeAP(taskId))
        gTasks[taskId].func = Task_UpdateTierSelections;
}

void CB2_OpenAPMenu(void)
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
        gReservedSpritePaletteCount = 0;
        gMain.state++;
        break;
    case 2:
        CreateTask(Task_InitAPMenu, 0);
        gMain.state++;
        break;
    case 3:
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB_Atlas);
        SetMainCallback2(CB2_Atlas);
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
        break;
    }
}

//FULL_COLOR
static bool8 IntializeAP(u8 taskId)
{
    static const u8 usedAP[] = _("{STR_VAR_1}AP");
    u16 * map;
    u16 buf[sizeof(sAPMenuBackgroundPalette)];
    u32 i;
    u32 spriteId;
    switch (gMain.state)
    {
    case 0:
    default:
        if (gPaletteFade.active)
            return 0;
        SetVBlankCallback(NULL);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sAtlasBGTemplates, ARRAY_COUNT(sAtlasBGTemplates));
        //SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
        DmaCopy16(3, sAPMenuBackgroundTileset, BG_CHAR_ADDR(0), sizeof(sAPMenuBackgroundTileset));
        DmaCopy16(3, sAPMenuBackgroundTilemap, GetBgTilemapBuffer(2), sizeof(sAPMenuBackgroundTilemap));
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_LIGHT:
                CpuCopy16(sAPMenuBackgroundPalette, buf, sizeof(sAPMenuBackgroundPalette));
                buf[1] = COLOR_NEON_BORDER_1;       // 1 = window highlight
                buf[2] = COLOR_NEON_BORDER_2;       // 2 = window border
                buf[13] = COLOR_LIGHT_THEME_TEXT;       // 13 = text color
                buf[16] = COLOR_LIGHT_THEME_TEXT_SHADOW;       // 16 = text shadowx
                buf[20] = COLOR_LIGHT_THEME_BG_LIGHT;       // 4 = bg
                LoadPalette(buf, 0, sizeof(sAPMenuBackgroundPalette));
                break;
            case THEME_COLOR_DARK:
                LoadPalette(sAPMenuBackgroundPalette, 0, sizeof(sAPMenuBackgroundPalette));
                break;
            case THEME_COLOR_USER:
                CpuCopy16(sAPMenuBackgroundPalette, buf, sizeof(sAPMenuBackgroundPalette));
                buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // 1 = window highlight
                buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];       // 2 = window border
                buf[13] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];       // 13 = text color
                buf[16] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];       // 16 = text shadowx
                buf[20] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];       // 4 = bg
                LoadPalette(buf, 0, sizeof(sAPMenuBackgroundPalette));
                break;
            case THEME_COLOR_VANILLA:
                //FULL_COLOR TODO impl vanilla palette
                LoadPalette(sAPMenuBackgroundPalette, 0, sizeof(sAPMenuBackgroundPalette));
                break;
        }
        /*if (VarGet(VAR_RYU_THEME_NUMBER) == 2) {
            CpuCopy16(sAPMenuBackgroundPalette, buf, sizeof(sAPMenuBackgroundPalette));
            buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[14];       // 1 = window highlight
            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[13];       // 2 = window border
            buf[13] = gSaveBlock2Ptr->userInterfaceTextboxPalette[2];       // 13 = text color
            buf[16] = gSaveBlock2Ptr->userInterfaceTextboxPalette[3];       // 16 = text shadowx
            buf[20] = gSaveBlock2Ptr->userInterfaceTextboxPalette[1];       // 4 = bg
            LoadPalette(buf, 0, sizeof(sAPMenuBackgroundPalette));
        } else
            LoadPalette(sAPMenuBackgroundPalette, 0, sizeof(sAPMenuBackgroundPalette));*/
        InitWindows(sAPMenuWindowTemplates);
        InitTextBoxGfxAndPrinters();
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_LIGHT:
                LoadPalette(gHatLightTheme_Pal, 0xF0, 0x20);
                break;
            case THEME_COLOR_DARK:
                LoadPalette(gRyuDarkTheme_Pal, 0xF0, 0x20);
                break;
            case THEME_COLOR_USER:            
                CpuCopy16(gRyuDarkTheme_Pal, buf, 0x20);
                buf[1] = COLOR_CREATE_LIGHT_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG]);         // L R button background
                buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];             //actual text
                buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];       //actual text shadow
                LoadPalette(buf, 0xF0, 0x20);
                break;
            case THEME_COLOR_VANILLA:
                LoadPalette(gMessageBox_Pal, 0xF0, 0x20);
                break;
        }
        /*if (VarGet(VAR_RYU_THEME_NUMBER) != 2)
            LoadPalette(gRyuDarkTheme_Pal, 0xF0, 0x20);
        else {
            CpuCopy16(gRyuDarkTheme_Pal, buf, 0x20);
            buf[1] = COLOR_CREATE_LIGHT_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG]);         // L R button background
            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];             //actual text
            buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];       //actual text shadow
            LoadPalette(buf, 0xF0, 0x20);
        }*/
        DeactivateAllTextPrinters();
        for(i = 0; i <= WIN_AP_DESC; i++)
        {
            PutWindowTilemap(i);
            CopyWindowToVram(i, 3);
            //DrawStdWindowFrame(i, TRUE);
        }
        PrintAPUsageString();
        gMain.state = 1;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 0;
        LoadSpritePalette(&sAPSelectSpritePal);
        LoadSpriteSheet(&sAPSelectSpriteSheet);
        for(i = 0; i < 4; i++)
        {   
            spriteId = sAPBorderSpriteIDs[i] = CreateSprite(&sAPSelectSpriteTemplate, 0, 0, 4);
            gSprites[spriteId].invisible = TRUE;
            gSprites[spriteId].oam.matrixNum = i << 3; // i'm proud of this one
        }
        //UpdateSelectionCorners(taskId);
        gMain.state++;
        break;
    case 2: // redundant case didn't bother to delete
        LoadSpritePalette(&sAPTierSelectPal);
        LoadSpriteSheet(&sAPTierSelectTile);
        // repurposed the cursorspriteid field for later use since we delete the cursor sprite anyways
        sAchAtlas.cursorSpriteId = CreateSprite(&sAPTierSelectSpriteTemplate, 12, 19, 0);
        // selected tier
        gTasks[taskId].tSelectedTier = AP_TIER_PLATINUM;
        // selected AP
        gTasks[taskId].tSelectedAP = 0;
        //help
        gTasks[taskId].tSelectAPPos = 0;
        FillWindowPixelBuffer(WIN_AP_SCROLL_NAME, 0);
        FillWindowPixelBuffer(WIN_AP_SCROLL_POWER_USAGE, 0);
        for(i = 0; i < 4 && i < gAP_Info[gTasks[taskId].tSelectedTier].tierCount; i++)
        { 
            const u8 * color = sTextColors[2];
            if(CheckAPFlag(gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i].apId))
                color = sTextColors[3];
            else if(gAP_Info[gTasks[taskId].tSelectedTier].requiredAP > (GetPlayerAPMax()-GetCurrentAPUsed())) // oh jesus christ
                color = sTextColors[1];
            AddTextPrinterParameterized3(WIN_AP_SCROLL_NAME, 0, 4, i * 12, color, 0xFF, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i].name);
            ConvertUIntToDecimalStringN(gStringVar1, gAP_Info[gTasks[taskId].tSelectedTier].requiredAP, STR_CONV_MODE_LEFT_ALIGN, 2);
            StringExpandPlaceholders(gStringVar4, usedAP);
            AddTextPrinterParameterized3(WIN_AP_SCROLL_POWER_USAGE, 0, 4, i * 12, color, 0xFF, gStringVar4);
        }
        CopyWindowToVram(WIN_AP_SCROLL_NAME, 2);
        CopyWindowToVram(WIN_AP_SCROLL_POWER_USAGE, 2);
        gMain.state++;
        break;
    case 3:
        CopyBgTilemapBufferToVram(0);
        //CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        //CopyBgTilemapBufferToVram(3);
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
        //SetGpuReg(REG_OFFSET_BG1HOFS, sAchAtlas.tilemapPosX*8);
        //SetGpuReg(REG_OFFSET_BG1VOFS, sAchAtlas.tilemapPosY*8);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        SetBgAttribute(2, BG_ATTR_PALETTEMODE, 1);
        SetBgAttribute(2, BG_ATTR_PRIORITY, 3);
        SetBgAttribute(3, BG_ATTR_PRIORITY, 2);
        ShowBg(0);
        HideBg(1);
        ShowBg(2);
        HideBg(3);
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

#if 0
void Task_OpenAPMenu(u8 taskId) // inefficient right from the start and that's how i like it jesus please help i'm stuck at home destroying my sanity
{
    //u16 * tilemaps[4];
    u32 i;
    u32 spriteId;
    
    if (gPaletteFade.active)
        return;

    //for(i = 0; i < 4; i++)
        //tilemaps[i] = GetBgTilemapBuffer(i);
    //DestroySprite(&gSprites[sAchAtlas.cursorSpriteId]);

    /*
    // init slected Tier AP Count
    gTasks[taskId].tSelectedTierAPCount = 0;
    for(i = 0; i < TOTAL_AP_COUNT; i++) // this is redundant but the data containing this stuff is not necessarily structured the best way and i have myself to blame for that
    {
        if(gTasks[taskId].tSelectedTier == gAP_Info[i].tier)
            gTasks[taskId].tSelectedTierAPCount++;    
    }
    */
    //if (GetSpriteTileStartByTag(ANIM_TAG_ICE_CUBE) == 0xFFFF)
    //SetSubspriteTables(&gSprites[spriteId], sAPSelectSubspriteTable);

    /* NO
    DmaCopy16(3, sAPSelectTileset, BG_CHAR_ADDR(0)+0xF0*TILE_SIZE_4BPP, sizeof(sAPSelectTileset));
    DmaCopy16(3, sAPSelectTilemap, GetBgTilemapBuffer(3), sizeof(sAPSelectTilemap));
    LoadPalette(sAPSelectPalette, 0x80, sizeof(sAPSelectPalette));
    */
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3X, 4);
    SetGpuReg(REG_OFFSET_BG3Y, 4); 
    CopyBgTilemapBufferToVram(2);
    CopyBgTilemapBufferToVram(3);
    //FreeAllWindowBuffers();
    //FillWindowPixelBuffer(WIN_ACH_LABEL, 0);
    //FillWindowPixelBuffer(WIN_ACH_DESC, 0);
    //FillWindowPixelBuffer(WIN_ACH_DEBUG, 0);
    //ClearStdWindowAndFrameToTransparent(WIN_ACH_LABEL, 0);
    //ClearStdWindowAndFrameToTransparent(WIN_ACH_DESC, 0);
    //ClearStdWindowAndFrameToTransparent(WIN_ACH_DEBUG, 0);
    //CopyWindowToVram(WIN_ACH_LABEL, 3);
    //CopyWindowToVram(WIN_ACH_DESC, 3);
    //CopyWindowToVram(WIN_ACH_DEBUG, 3);
    //RemoveWindow(WIN_ACH_LABEL);
    //RemoveWindow(WIN_ACH_DESC);
    //RemoveWindow(WIN_ACH_DEBUG);
    InitWindows(sAPMenuWindowTemplates);
    InitTextBoxGfxAndPrinters();
    LoadPalette(gRyuDarkTheme_Pal, 0xF0, 0x20);
    DeactivateAllTextPrinters();
    for(i = 0; i <= WIN_AP_DESC; i++)
    {
        PutWindowTilemap(i);
        CopyWindowToVram(i, 3);
        //DrawStdWindowFrame(i, TRUE);
    }
    PrintAPUsageString();
    //AddTextPrinterParameterized3(WIN_AP_TOTAL_AP)
    //AddTextPrinterParameterized3(WIN_AP_SCROLL_NAME, 0, 0, 0, sTextColors[1], 0xFF, gAP_Info[0].name);
    //CopyWindowToVram(WIN_AP_DESC, 2);
    //gTasks[taskId].tAPState = APSTATE_TIER_CHANGE; // debug
    gTasks[taskId].func = Task_UpdateTierSelections;
}
#endif

static const struct WindowTemplate sWindowTemplate_YesNoBox = {
    .bg = 0x00,
    .tilemapLeft = 23,
    .tilemapTop = 10,
    .width = 0x06,
    .height = 0x04,
    .paletteNum = 15,
    .baseBlock = 0x150
};

static void Task_ActivateAPYesNoChoice(u8 taskId);
u16 sub_8197A38(void);

static const u8 gText_DoYouWantToEnableAP[] = _("Do you want to enable this AP?");
static const u8 gText_DoYouWantToDisableAP[] = _("Do you want to disable this AP?");
static const u8 gText_NotEnoughAP[] = _("You don't have enough AP to enable\nthis　power.");

static void Task_HandleAPInput(u8 taskId)
{
    switch(gTasks[taskId].tAPState)
    {
        case APSTATE_INPUT_APSELECT:
            if(gMain.newKeys & A_BUTTON)
            {
                if(CheckAPFlag(gAP_Info[gTasks[taskId].tSelectedTier].apInfo[gTasks[taskId].tSelectedAP].apId))
                {
                    FillWindowPixelBuffer(WIN_AP_DESC, 0);
                    AddTextPrinterParameterized3(WIN_AP_DESC, 0, 4, 2, sTextColors[3], 0xFF, gText_DoYouWantToDisableAP);
                    CopyWindowToVram(WIN_AP_DESC, 2);
                    // TODO: ask for confirmation and activate AP
                    CreateYesNoMenu(&sWindowTemplate_YesNoBox, sub_8197A38(), 14, 0);
                    gTasks[taskId].tDisEnaAP = 0;
                    gTasks[taskId].func = Task_ActivateAPYesNoChoice; 
                }
                else if(gAP_Info[gTasks[taskId].tSelectedTier].requiredAP > (GetPlayerAPMax()-GetCurrentAPUsed()))
                {
                    FillWindowPixelBuffer(WIN_AP_DESC, 0);
                    AddTextPrinterParameterized3(WIN_AP_DESC, 0, 4, 2, sTextColors[1], 0xFF, gText_NotEnoughAP);
                    CopyWindowToVram(WIN_AP_DESC, 2);
                }
                else
                {
                    FillWindowPixelBuffer(WIN_AP_DESC, 0);
                    AddTextPrinterParameterized3(WIN_AP_DESC, 0, 4, 2, sTextColors[3], 0xFF, gText_DoYouWantToEnableAP);
                    CopyWindowToVram(WIN_AP_DESC, 2);
                    // TODO: ask for confirmation and activate AP
                    CreateYesNoMenu(&sWindowTemplate_YesNoBox, sub_8197A38(), 14, 0);
                    gTasks[taskId].tDisEnaAP = 1;
                    gTasks[taskId].func = Task_ActivateAPYesNoChoice;   
                }
                PlaySE(SE_SELECT);
            }
            if(gMain.newKeys & B_BUTTON)
            {
                PlaySE(SE_SELECT);
                gTasks[taskId].tAPState = APSTATE_INPUT_TIERSELECT;
                FillWindowPixelBuffer(WIN_AP_DESC, 0);
                CopyWindowToVram(WIN_AP_DESC, 2);
                HideSelectionCorners();
            }
            if (gMain.newKeys & DPAD_UP)
            {
                if(gAP_Info[gTasks[taskId].tSelectedTier].tierCount != 1)
                    PlaySE(SE_SELECT);
                if(--gTasks[taskId].tSelectAPPos < 0)
                    gTasks[taskId].tSelectAPPos = min(gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1, 3);
                if(--gTasks[taskId].tSelectedAP < 0)
                {
                    gTasks[taskId].tSelectAPPos = min(gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1, 3);
                    gTasks[taskId].tSelectedAP = gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1;
                    if(gAP_Info[gTasks[taskId].tSelectedTier].tierCount > 4)
                    {
                        gTasks[taskId].tSelectedAPOffset = gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1-3;
                        gTasks[taskId].tAPState = APSTATE_APOFFSET_CHANGED;
                    }
                    else
                    {
                        gTasks[taskId].tSelectedAPOffset = 0;
                        gTasks[taskId].tAPState = APSTATE_APOFFSET_CHANGED;
                    }
                }
                else if(gTasks[taskId].tSelectAPPos == 0 && gTasks[taskId].tSelectedAP > 0)
                {
                    gTasks[taskId].tSelectAPPos++;
                    gTasks[taskId].tSelectedAPOffset--;
                    gTasks[taskId].tAPState = APSTATE_APOFFSET_CHANGED;
                }
                gTasks[taskId].func = Task_UpdateAPSelections;
            }
            else if (gMain.newKeys & DPAD_DOWN)
            {
                if(gAP_Info[gTasks[taskId].tSelectedTier].tierCount != 1)
                    PlaySE(SE_SELECT);
                if(++gTasks[taskId].tSelectAPPos > 3 || gTasks[taskId].tSelectAPPos > gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1)
                    gTasks[taskId].tSelectAPPos = 0;
                if(++gTasks[taskId].tSelectedAP > gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1)
                {
                    gTasks[taskId].tSelectAPPos = 0;
                    gTasks[taskId].tSelectedAP = 0;
                    gTasks[taskId].tSelectedAPOffset = 0;
                    gTasks[taskId].tAPState = APSTATE_APOFFSET_CHANGED;
                }
                else if(gTasks[taskId].tSelectAPPos == 3 && gTasks[taskId].tSelectedAP < gAP_Info[gTasks[taskId].tSelectedTier].tierCount-1)
                {
                    gTasks[taskId].tSelectAPPos--;
                    gTasks[taskId].tSelectedAPOffset++;
                    gTasks[taskId].tAPState = APSTATE_APOFFSET_CHANGED;
                }
                gTasks[taskId].func = Task_UpdateAPSelections;
            }
            break;
        case APSTATE_INPUT_TIERSELECT:
            if(gMain.newKeys & A_BUTTON)
            {
                gTasks[taskId].tAPState = APSTATE_INPUT_APSELECT;
                FillWindowPixelBuffer(WIN_AP_DESC, 0);
                AddTextPrinterParameterized3(WIN_AP_DESC, 0, 4, 2, sTextColors[0], 0, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[gTasks[taskId].tSelectedAP].desc);
                ShowSelectionCorners();
                UpdateSelectionCorners(taskId);
                PlaySE(SE_SELECT);
                return;
            }
            else if(gMain.newKeys & B_BUTTON)
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                //gTasks[taskId].data[0] = 0;
                //gTasks[taskId].data[1] = 0;
                gTasks[taskId].func = Task_OpenJournalAfterFade;
                //SetMainCallback2(CB2_OpenJournal);
                return;
            }
            if(gMain.newKeys & DPAD_LEFT)
            {
                PlaySE(SE_SELECT);
                if(--gTasks[taskId].tSelectedTier < AP_TIER_PLATINUM)
                    gTasks[taskId].tSelectedTier = AP_TIER_COPPER;
                gTasks[taskId].func = Task_UpdateTierSelections;
            }
            else if(gMain.newKeys & DPAD_RIGHT)
            {
                PlaySE(SE_SELECT);
                if(++gTasks[taskId].tSelectedTier > AP_TIER_COPPER)
                    gTasks[taskId].tSelectedTier = AP_TIER_PLATINUM;
                gTasks[taskId].func = Task_UpdateTierSelections;
            }
            break;
    }
    /*
    if(gMain.newKeys & B_BUTTON)
    {
        if(gTasks[taskId].tSelectingAP)
        {
            gTasks[taskId].tSelectingAP = FALSE;
            // what the hell man
            FillWindowPixelBuffer(WIN_AP_DESC, 0);
            CopyWindowToVram(WIN_AP_DESC, 2);
            HideSelectionCorners();
        }
    }
        //gTasks[taskId].func = Task_CloseAtlas;
    if(gTasks[taskId].tSelectingAP)
    {

    }
    else
    {
    }
    */
}

static void Task_ActivateAPYesNoChoice(u8 taskId)
{
    const struct APInfoTier * apinfo = &gAP_Info[gTasks[taskId].tSelectedTier].apInfo[gTasks[taskId].tSelectedAP];
    
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        if(gTasks[taskId].tDisEnaAP)
            SetAPFlag(apinfo->apId);
        else
            ClearAPFlag(apinfo->apId);
        apinfo->func();
        PrintAPUsageString();
        gTasks[taskId].tAPState = APSTATE_APOFFSET_CHANGED; // force redraw
        gTasks[taskId].func = Task_UpdateAPSelections;
        PlaySE(SE_SELECT);
        break;
    case 1:
    case -1:
        gTasks[taskId].tAPState = APSTATE_APOFFSET_CHANGED; // force redraw
        gTasks[taskId].func = Task_UpdateAPSelections;
        PlaySE(SE_SELECT);
        break;
    }
}

static void Task_UpdateTierSelections(u8 taskId)
{
    static const u8 sTierCursorXPos[] = {12, 67, 100, 140}; // evil hardcoding
    static const u8 usedAP[] = _("{STR_VAR_1}AP");
    u32 i;
    gTasks[taskId].tSelectedAP = 0;
    gTasks[taskId].tSelectAPPos = 0;
    gTasks[taskId].tSelectedAPOffset = 0;
    gSprites[sAchAtlas.cursorSpriteId].pos1.x = sTierCursorXPos[gTasks[taskId].tSelectedTier];
    FillWindowPixelBuffer(WIN_AP_SCROLL_NAME, 0);
    FillWindowPixelBuffer(WIN_AP_SCROLL_POWER_USAGE, 0);
    for(i = 0; i < 4 && i < gAP_Info[gTasks[taskId].tSelectedTier].tierCount; i++)
    { 
        const u8 * color = sTextColors[2];
        if(CheckAPFlag(gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i].apId))
            color = sTextColors[3];
        else if(gAP_Info[gTasks[taskId].tSelectedTier].requiredAP > (GetPlayerAPMax()-GetCurrentAPUsed())) // oh jesus christ
            color = sTextColors[1];
        AddTextPrinterParameterized3(WIN_AP_SCROLL_NAME, 0, 4, i * 12, color, 0xFF, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i].name);
        ConvertUIntToDecimalStringN(gStringVar1, gAP_Info[gTasks[taskId].tSelectedTier].requiredAP, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, usedAP);
        AddTextPrinterParameterized3(WIN_AP_SCROLL_POWER_USAGE, 0, 4, i * 12, color, 0xFF, gStringVar4);
    }
    CopyWindowToVram(WIN_AP_SCROLL_NAME, 2);
    CopyWindowToVram(WIN_AP_SCROLL_POWER_USAGE, 2);
    UpdateSelectionCorners(taskId);
    gTasks[taskId].tAPState = APSTATE_INPUT_TIERSELECT;
    gTasks[taskId].func = Task_HandleAPInput;
}

static void Task_UpdateAPSelections(u8 taskId)
{
    static const u8 sTierCursorXPos[] = {12, 67, 100, 140}; // evil hardcoding
    static const u8 usedAP[] = _("{STR_VAR_1}AP");
    u32 i;
    //gTasks[taskId].tChangedAP = FALSE;
    FillWindowPixelBuffer(WIN_AP_DESC, 0);
    AddTextPrinterParameterized3(WIN_AP_DESC, 0, 4, 2, sTextColors[0], 0, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[gTasks[taskId].tSelectedAP].desc);
    UpdateSelectionCorners(taskId);
    FillWindowPixelBuffer(WIN_AP_SCROLL_NAME, 0);
    FillWindowPixelBuffer(WIN_AP_SCROLL_POWER_USAGE, 0);
    if(gTasks[taskId].tAPState == APSTATE_APOFFSET_CHANGED)
    {
        for(i = 0; i < 4 && (i+gTasks[taskId].tSelectedAPOffset) < gAP_Info[gTasks[taskId].tSelectedTier].tierCount; i++)
        {
            const u8 * color = sTextColors[2];
            if(CheckAPFlag(gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i].apId))
                color = sTextColors[3];
            else if(gAP_Info[gTasks[taskId].tSelectedTier].requiredAP > (GetPlayerAPMax()-GetCurrentAPUsed())) // oh jesus christ
                color = sTextColors[1];
            AddTextPrinterParameterized3(WIN_AP_SCROLL_NAME, 0, 4, i * 12, color, 0xFF, gAP_Info[gTasks[taskId].tSelectedTier].apInfo[i+gTasks[taskId].tSelectedAPOffset].name);
            ConvertUIntToDecimalStringN(gStringVar1, gAP_Info[gTasks[taskId].tSelectedTier].requiredAP, STR_CONV_MODE_LEFT_ALIGN, 2);
            StringExpandPlaceholders(gStringVar4, usedAP);
            AddTextPrinterParameterized3(WIN_AP_SCROLL_POWER_USAGE, 0, 4, i * 12, color, 0xFF, gStringVar4);
        }
        CopyWindowToVram(WIN_AP_SCROLL_NAME, 2);
        CopyWindowToVram(WIN_AP_SCROLL_POWER_USAGE, 2);
        gTasks[taskId].tAPState = APSTATE_INPUT_APSELECT;
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
                        StringExpandPlaceholders(gStringVar4, sAchAtlasData[i].hintString);
                        AddTextPrinterParameterized3(WIN_ACH_DESC, 0, 0, 0, sTextColors[0], 0, gStringVar4);
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
            const u8 * color;
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
            if(sAchAtlasData[i].category & CATEGORY_FLAG_GOLD)
                color = sGoldTextColor;
            else
                color = sTextColors[sAchAtlasData[i].category];
            AddTextPrinterParameterized3(WIN_ACH_LABEL, 0, 0, 0, color, 0, sAchAtlasData[i].nameString);
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
    else if(JOY_NEW(R_BUTTON))
        *action = ACTION_OPEN_APMENU;
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

u8 gGoldAchNotif[] = _("Awarded Master Ball for Gold Achievement.");
void CheckFormasterBallGift(u8 id)
{
    if (((id == ACH_POKEMON_MASTER) ||
        (id == ACH_THE_UNIVERSALIST) ||
        (id == ACH_LOREMASTER) ||
        (id == ACH_TOURIST) ||
        (id == ACH_MILLIONAIRE) ||
        (id == ACH_MONEYBAGS) ||
        (id == ACH_ULTRA_BEASTLY)))
        {
            AddBagItem(ITEM_MASTER_BALL, 1);
            QueueNotification(gGoldAchNotif, NOTIFY_GENERAL, 120);
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

const u8 gAchievementNotifyString[] = _("Achievement Get! {COLOR 6}{SHADOW 4} {STR_VAR_1}");
const u8 gGoldAchievementNotifyString[] = _("Golden Achievement Get! {COLOR 12}{SHADOW 7} {STR_VAR_1}");



void GiveAchievement(u32 id)
{
    if(id > ACH_FLAGS_COUNT)
        return;

    if (CheckAchievement(id) == FALSE)
    {
        if(sAchAtlasData[id].category & CATEGORY_FLAG_GOLD)
        {
            StringCopy(gStringVar1, sAchAtlasData[id].nameString);
            QueueNotification(gGoldAchievementNotifyString, NOTIFY_ACHIEVEMENT, 120);
            CheckFormasterBallGift(id);
        }
        else
        {
            StringCopy(gStringVar1, sAchAtlasData[id].nameString);
            QueueNotification(gAchievementNotifyString, NOTIFY_ACHIEVEMENT, 120);
        }
        VarSet(VAR_RYU_LAST_ACH, id);//let the global script know that player received an achievement recently.
    }
    else
    {
        VarSet(VAR_RYU_LAST_ACH, 300);//the achievment that was given was already owned by player.
    }

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

u32 CountTakenAchievements(void)
{
    u32 count = 0;
    u32 i, j;
    for(i = 0; i < ARRAY_COUNT(gSaveBlock2Ptr->achFlags); i++)
    {
        u32 flagBits = gSaveBlock2Ptr->achFlags[i];
        for(j = 0; flagBits; j++)
            flagBits &= flagBits - 1;
        count += j;
    }
    return count;
}