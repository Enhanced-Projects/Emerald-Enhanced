#include "global.h"
#include "StatAssist.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "script_menu.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "constants/rgb.h"
#include "overworld.h"
#include "dynamic_placeholder_text_util.h"
#include "trainer_pokemon_sprites.h"
#include "pokeball.h"
#include "battle_anim.h"
#include "battle_main.h"
#include "event_data.h"

/*
 * 
 */

//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
};

enum WindowIds
{
    MON_NICKNAME_WINDOW,
    STATS_WINDOW,
    LEVEL_WINDOW,
    SUMMARY_WINDOW,
    ABILITY_WINDOW,
    ITEM_EXP_WINDOW,
    BATTLE_MOVES_WINDOW,
    CONTEST_MOVES_WINDOW,
    WINDOWS_COUNT
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

//==========STATIC=DEFINES==========//
static void Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .priority = 0
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [MON_NICKNAME_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 2,   // position from left (per 8 pixels)
        .tilemapTop = 2,    // position from top (per 8 pixels)
        .width = 24,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
    [STATS_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 12,   // position from left (per 8 pixels)
        .tilemapTop = 4,    // position from top (per 8 pixels)
        .width = 15,        // width (per 8 pixels)
        .height = 14,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 50,     // tile start in VRAM
    },
    [LEVEL_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 2,   // position from left (per 8 pixels)
        .tilemapTop = 13,    // position from top (per 8 pixels)
        .width = 8,        // width (per 8 pixels)
        .height = 8,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 260,     // tile start in VRAM
    },
    [SUMMARY_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 12,   // position from left (per 8 pixels)
        .tilemapTop = 4,    // position from top (per 8 pixels)
        .width = 17,        // width (per 8 pixels)
        .height = 3,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 50,     // tile start in VRAM
    },
    [ABILITY_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 12,   // position from left (per 8 pixels)
        .tilemapTop = 8,    // position from top (per 8 pixels)
        .width = 17,        // width (per 8 pixels)
        .height = 4,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 110,     // tile start in VRAM
    },
    [ITEM_EXP_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 12,   // position from left (per 8 pixels)
        .tilemapTop = 13,    // position from top (per 8 pixels)
        .width = 17,        // width (per 8 pixels)
        .height = 5,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 326,     // tile start in VRAM
    },
    [BATTLE_MOVES_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 12,   // position from left (per 8 pixels)
        .tilemapTop = 4,    // position from top (per 8 pixels)
        .width = 15,        // width (per 8 pixels)
        .height = 14,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 50,     // tile start in VRAM
    },
    [CONTEST_MOVES_WINDOW] = 
    {
        .bg = 0,            // windowId bg to print text on
        .tilemapLeft = 12,   // position from left (per 8 pixels)
        .tilemapTop = 4,    // position from top (per 8 pixels)
        .width = 15,        // width (per 8 pixels)
        .height = 14,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 50,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[] =   INCBIN_U32("graphics/stat_assist/tiles.4bpp.lz");
static const u32 sStatsTilemap[] = INCBIN_U32("graphics/stat_assist/tilemap.bin.lz");
static const u32 sSummaryTilemap[] = INCBIN_U32("graphics/stat_assist/summary_tilemap.bin.lz");
const u8 sMainLabelStatsText[] = _("'s stats");
const u8 sMainLabelSummaryText[] = _("'s summary");
const u8 sMainLabelMovesText[] = _("'s moves");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GREY,  TEXT_COLOR_LIGHT_GREY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GREY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GREY},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GREY},
};
//==========FUNCTIONS==========//
// UI loader template
void Task_OpenMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        StatAssist_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void StatAssist_Init(MainCallback callback)
{
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;

    SetMainCallback2(Menu_RunSetup);
}

static void Menu_RunSetup(void)
{
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}
extern const struct MenuAction MultichoiceList_126[];

static EWRAM_DATA u8 specialPreviewSpriteID1 = 0xFF;
static EWRAM_DATA u8 specialPreviewSpriteID2 = 0xFF;

void RyuDrawPreviewSprite(void)
{
    u16 species = (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_SPECIES));
    if (specialPreviewSpriteID1 == 0)
        DestroySprite(&gSprites[specialPreviewSpriteID1]);
    specialPreviewSpriteID1 = CreateMonPicSprite(species, GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_OT_ID), GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_PERSONALITY), TRUE, 50, 65, 15, 0xFFFF);
    PlayCry1(species, 127);
}

void RyuDrawCaughtBall(void)//not working?
{
    u8 ball = ItemIdToBallId(GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_POKEBALL));

    LoadBallGfx(ball);
    if (specialPreviewSpriteID2 == 1)
        DestroySprite(&gSprites[specialPreviewSpriteID2]);
    specialPreviewSpriteID2 = CreateSprite(&gBallSpriteTemplates[ball], 222, 22, 0);
    gSprites[specialPreviewSpriteID2].callback = SpriteCallbackDummy;
    gSprites[specialPreviewSpriteID2].oam.priority = 3;
}

void FillStatsData(void)
{
    PrintToWindow(MON_NICKNAME_WINDOW, FONT_BLACK);
    PrintToWindow(LEVEL_WINDOW, FONT_BLACK);
    PrintToWindow(STATS_WINDOW, FONT_BLACK);
}

void FillSummaryData(void)
{
    PrintToWindow(MON_NICKNAME_WINDOW, FONT_BLACK);
    PrintToWindow(SUMMARY_WINDOW, FONT_BLACK);
    PrintToWindow(ABILITY_WINDOW, FONT_BLACK);
    PrintToWindow(LEVEL_WINDOW, FONT_BLACK);
    PrintToWindow(ITEM_EXP_WINDOW, FONT_BLACK);
}

void FillBattleMovesData(void)
{
    PrintToWindow(MON_NICKNAME_WINDOW, FONT_BLACK);
    PrintToWindow(LEVEL_WINDOW, FONT_BLACK);
    PrintToWindow(BATTLE_MOVES_WINDOW, FONT_BLACK);
}

void FillContestMovesData(void)
{
    PrintToWindow(MON_NICKNAME_WINDOW, FONT_BLACK);
    PrintToWindow(LEVEL_WINDOW, FONT_BLACK);
    PrintToWindow(CONTEST_MOVES_WINDOW, FONT_BLACK);
}

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (Menu_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        Menu_InitWindows();
        gMain.state++;
        break;
    case 5:
        RyuDrawPreviewSprite();
        RyuDrawCaughtBall();
        FillSummaryData();
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}


static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Menu_LoadGraphics(void)
{
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sSummaryTilemap, sBg1TilemapBuffer);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(GetOverworldTextboxPalettePtr(), 0, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_InitWindows(void)
{
    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    switch (gSpecialVar_0x8002) //which set of windows to load (page)
    {
        case 0:
            FillWindowPixelBuffer(MON_NICKNAME_WINDOW, 0);
            PutWindowTilemap(MON_NICKNAME_WINDOW);
            CopyWindowToVram(MON_NICKNAME_WINDOW, 3);
            FillWindowPixelBuffer(LEVEL_WINDOW, 0);
            PutWindowTilemap(LEVEL_WINDOW);
            CopyWindowToVram(LEVEL_WINDOW, 3);
            FillWindowPixelBuffer(SUMMARY_WINDOW, 0);
            PutWindowTilemap(SUMMARY_WINDOW);
            CopyWindowToVram(SUMMARY_WINDOW, 3);
            FillWindowPixelBuffer(ABILITY_WINDOW, 0);
            PutWindowTilemap(ABILITY_WINDOW);
            CopyWindowToVram(ABILITY_WINDOW, 3);
            FillWindowPixelBuffer(ITEM_EXP_WINDOW, 0);
            PutWindowTilemap(ITEM_EXP_WINDOW);
            CopyWindowToVram(ITEM_EXP_WINDOW, 3);
            break;
        case 1:
            FillWindowPixelBuffer(MON_NICKNAME_WINDOW, 0);
            PutWindowTilemap(MON_NICKNAME_WINDOW);
            CopyWindowToVram(MON_NICKNAME_WINDOW, 3);
            FillWindowPixelBuffer(STATS_WINDOW, 0);
            PutWindowTilemap(STATS_WINDOW);
            CopyWindowToVram(STATS_WINDOW, 3);
            FillWindowPixelBuffer(LEVEL_WINDOW, 0);
            PutWindowTilemap(LEVEL_WINDOW);
            CopyWindowToVram(LEVEL_WINDOW, 3);
            break;
        case 2:
            FillWindowPixelBuffer(MON_NICKNAME_WINDOW, 0);
            PutWindowTilemap(MON_NICKNAME_WINDOW);
            CopyWindowToVram(MON_NICKNAME_WINDOW, 3);
            FillWindowPixelBuffer(BATTLE_MOVES_WINDOW, 0);
            PutWindowTilemap(BATTLE_MOVES_WINDOW);
            CopyWindowToVram(BATTLE_MOVES_WINDOW, 3);
            FillWindowPixelBuffer(LEVEL_WINDOW, 0);
            PutWindowTilemap(LEVEL_WINDOW);
            CopyWindowToVram(LEVEL_WINDOW, 3);
            break;
        case 3:
            FillWindowPixelBuffer(MON_NICKNAME_WINDOW, 0);
            PutWindowTilemap(MON_NICKNAME_WINDOW);
            CopyWindowToVram(MON_NICKNAME_WINDOW, 3);
            FillWindowPixelBuffer(CONTEST_MOVES_WINDOW, 0);
            PutWindowTilemap(CONTEST_MOVES_WINDOW);
            CopyWindowToVram(CONTEST_MOVES_WINDOW, 3);
            FillWindowPixelBuffer(LEVEL_WINDOW, 0);
            PutWindowTilemap(LEVEL_WINDOW);
            CopyWindowToVram(LEVEL_WINDOW, 3);
            break;
    }

    ScheduleBgCopyTilemapToVram(2);
}

extern const u8 *const gNatureNamePointers[NUM_NATURES];

const u8 sSplitStrings[3][9] = {
    [SPLIT_PHYSICAL] = _("Physical"),
    [SPLIT_SPECIAL] = _("Special"),
    [SPLIT_STATUS] = _("Status"),
};

const u8 sStatStrings[15][12] = {
    [0] = _("HP: "),
    [1] = _("Atk: "),
    [2] = _("Def: "),
    [3] = _("Spe: "),
    [4] = _("SpAtk: "),
    [5] = _("SpDef: "),
    [6] = _("Affection: "),
    [7] = _("Types: "),
    [8] = _("Ability: "),
    [9] = _("Holding: "),
    [10] = _("Exp:"),
    [11] = _("Next:"),
    [12] = _("Pwr:"),
    [13] = _("     Split:"),
    [14] = _("    PP:")
};

const u8 sText_Newline[] = _("\n");
const u8 sText_SingleSpace[] = _(" ");
const u8 sText_SwitchToDefaultColor[] = _("{COLOR DARK_GREY}{SHADOW LIGHT_GREY}");
const u8 sText_SwitchToRed[] = _("{COLOR LIGHT_RED}{SHADOW RED}");
const u8 sText_SwitchToBlue[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}");
const u8 sText_SwitchToGreen[] = _("{COLOR LIGHT_GREEN}{SHADOW GREEN}");
const u8 sText_EV[] = _("ev");
const u8 sText_IV[] = _("iv");
const u8 sText_FwSlash[] = _("/");

 
void RyuBufferStats(void)
{   
    int i, temp;
    const s8 *natureMod = gNatureStatTable[GetNature(&gPlayerParty[gSpecialVar_0x8001])];

    StringCopy(gStringVar4, sStatStrings[0]);//buffer current / max hp
    temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_HP);
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_FwSlash);
    temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_MAX_HP);
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_SingleSpace);
    //buffer EV's
    StringAppend(gStringVar4, sText_SwitchToGreen);
    temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_HP_EV);
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_EV);
    StringAppend(gStringVar4, sText_FwSlash);
    //buffer IV's
    temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_HP_IV);
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_IV);
    for (i = 1;i < 6;i++)//buffer each stat after hp and copy to gs4
    {
        StringAppend(gStringVar4, sText_Newline);
        if (natureMod[i - 1] == 0)
            StringAppend(gStringVar4, sText_SwitchToDefaultColor);
        else if (natureMod[i - 1] > 0)
            StringAppend(gStringVar4, sText_SwitchToRed);
        else
            StringAppend(gStringVar4, sText_SwitchToBlue);

        StringAppend(gStringVar4, sStatStrings[i]);
        temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], (MON_DATA_MAX_HP + i));
        ConvertIntToDecimalStringN(gStringVar2, temp, 0, 4);
        StringAppend(gStringVar4, gStringVar2);
        //buffer EV's
        StringAppend(gStringVar4, sText_SingleSpace);
        StringAppend(gStringVar4, sText_SwitchToGreen);
        temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_HP_EV + i);
        ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
        StringAppend(gStringVar4, gStringVar1);
        StringAppend(gStringVar4, sText_EV);
        StringAppend(gStringVar4, sText_FwSlash);
        //buffer IV's
        temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_HP_IV + i);
        ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
        StringAppend(gStringVar4, gStringVar1);
        StringAppend(gStringVar4, sText_IV);
    }
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sText_SwitchToDefaultColor);
    StringAppend(gStringVar4, sStatStrings[6]);
    temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], (MON_DATA_FRIENDSHIP));
    ConvertIntToDecimalStringN(gStringVar2, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar2);
    //buffer types
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sStatStrings[7]);
    temp = (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_SPECIES));
    StringAppend(gStringVar4, gTypeNames[gBaseStats[temp].type1]);
    StringAppend(gStringVar4, sText_FwSlash);
    StringAppend(gStringVar4, gTypeNames[gBaseStats[temp].type2]);
    //buffer ability
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sStatStrings[8]);
    temp = GetMonAbility(&gPlayerParty[gSpecialVar_0x8001]);
    StringAppend(gStringVar4, gAbilityNames[temp]);

}

void RyuBufferGenderBossIcon(void)
{
    if (GetMonGender(&gPlayerParty[gSpecialVar_0x8001]) == MON_MALE)
        {
            if (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_BOSS_STATUS) == TRUE)
            {
                StringCopy(gStringVar1, ((const u8[])_("{COLOR LIGHT_BLUE}{SHADOW BLUE}{BOSS_INDI}")));
                StringExpandPlaceholders(gStringVar2, gStringVar1);
            }
            else
            {
                StringCopy(gStringVar1, ((const u8[])_("{COLOR LIGHT_BLUE}{SHADOW BLUE}♂")));
                StringExpandPlaceholders(gStringVar2, gStringVar1);
            }
        }  
        else if (GetMonGender(&gPlayerParty[gSpecialVar_0x8001]) == MON_FEMALE)
        {
            if (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_BOSS_STATUS) == TRUE)
            {
                StringCopy(gStringVar1, ((const u8[])_("{COLOR LIGHT_RED}{SHADOW RED}{BOSS_INDI}")));
                StringExpandPlaceholders(gStringVar2, gStringVar1);
            }
            else
            {
                StringCopy(gStringVar1, ((const u8[])_("{COLOR LIGHT_RED}{SHADOW RED}♀")));
                StringExpandPlaceholders(gStringVar2, gStringVar1);
            }
        }
        else
        {
            if (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_BOSS_STATUS) == TRUE)
            {
                StringCopy(gStringVar1, (const u8[])_("{BOSS_INDI}"));
                StringExpandPlaceholders(gStringVar2, gStringVar1);
            }
            else
            {
                StringCopy(gStringVar1, sText_SingleSpace);
                StringExpandPlaceholders(gStringVar2, gStringVar1);
            }
        }
}

void BufferTitleWindow(void)
{
    GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_NICKNAME, gStringVar4);
    switch (gSpecialVar_0x8002)
    {
        case 0:
            StringAppend(gStringVar4, sMainLabelSummaryText);
            break;
        case 1:
            StringAppend(gStringVar4, sMainLabelStatsText);
            break;
        case 2:
            StringAppend(gStringVar4, sMainLabelMovesText);
            break;
    }
    StringAppend(gStringVar4, sText_SingleSpace);
    StringCopy(gStringVar1, ((const u8[])_("{DPAD_UP}{DPAD_DOWN}: Slot, {DPAD_LEFT}{DPAD_RIGHT}: Page")));
    StringExpandPlaceholders(gStringVar2, gStringVar1);
    StringAppend(gStringVar4, gStringVar1);
}

void BufferLevelWindow(void)
{
    GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_NICKNAME, gStringVar4);
    StringAppend(gStringVar4, ((const u8[])_("/")));
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, gSpeciesNames[GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_SPECIES)]);
    StringAppend(gStringVar4, sText_Newline);
    RyuBufferGenderBossIcon();
    StringAppend(gStringVar4, gStringVar2);
    StringAppend(gStringVar4, sText_SingleSpace);
    StringAppend(gStringVar4, sText_SwitchToDefaultColor);
    StringAppend(gStringVar4, (const u8[])_("Lv. "));
    ConvertIntToDecimalStringN(gStringVar1, (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_LEVEL)), 0, 3);
    StringAppend(gStringVar4, gStringVar1);
}

void BufferSummaryWindow(void)
{  
    u16 temp = (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_SPECIES));
    StringCopy(gStringVar4, gTypeNames[gBaseStats[temp].type1]);
    StringAppend(gStringVar4, sText_FwSlash);
    StringAppend(gStringVar4, gTypeNames[gBaseStats[temp].type2]);
    StringAppend(gStringVar4, ((const u8[])_("      OT:")));
    GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_OT_NAME, gStringVar1);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, ((const u8[])_("No. ")));
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 3);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, ((const u8[])_("              ")));
    StringAppend(gStringVar4, gNatureNamePointers[GetNature(&gPlayerParty[gSpecialVar_0x8001])]);
}

void BufferAbilityWindow(void)
{
    u16 temp = 0;
    temp = GetMonAbility(&gPlayerParty[gSpecialVar_0x8001]);
    StringCopy(gStringVar4, sStatStrings[8]);
    StringAppend(gStringVar4, gAbilityNames[temp]);
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, gAbilityDescriptionPointers[temp]);
}

void BufferItemExpWindow(void)
{
    u16 temp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_HELD_ITEM);
    u16 species = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_SPECIES);
    u32 currentExp = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_EXP);
    u8 currentLevel = GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_LEVEL);
    u32 next = 0;
    StringCopy(gStringVar4, sStatStrings[9]);
    if (temp != 0)
        CopyItemName(temp, gStringVar1);
    else
        StringCopy(gStringVar1, ((const u8[])_("Nothing")));
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sStatStrings[10]);
    ConvertIntToDecimalStringN(gStringVar1, currentExp, 0, 10);
    StringAppend(gStringVar4, gStringVar1);
    if (currentLevel < MAX_LEVEL)
        next = gExperienceTables[gBaseStats[species].growthRate][currentLevel + 1] - currentExp;
    else
        next = 0;
    StringAppend(gStringVar4, sText_Newline);
    ConvertIntToDecimalStringN(gStringVar1, next, 0, 10);
    StringAppend(gStringVar4, sStatStrings[11]);
    StringAppend(gStringVar4, gStringVar1);
}

void RyuBufferBattleMovesData(void)
{
    u16 move1 = (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_MOVE1));
    u16 move2 = (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_MOVE2));
    u16 move3 = (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_MOVE3));
    u16 move4 = (GetMonData(&gPlayerParty[gSpecialVar_0x8001], MON_DATA_MOVE4));
    //buffer move 1
    StringCopy(gStringVar4, gMoveNames[move1]);
    StringAppend(gStringVar4, sText_SingleSpace);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move1].pp, 0, 2);
    StringAppend(gStringVar4, sStatStrings[14]),
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sStatStrings[12]);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move1].power, 0, 3);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_SingleSpace);
    StringAppend(gStringVar4, sStatStrings[13]);
    StringAppend(gStringVar4, sSplitStrings[gBattleMoves[move1].split]);
    StringAppend(gStringVar4, sText_Newline);
    //buffer move 2
    StringAppend(gStringVar4, gMoveNames[move2]);
    StringAppend(gStringVar4, sText_SingleSpace);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move2].pp, 0, 2);
    StringAppend(gStringVar4, sStatStrings[14]),
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sStatStrings[12]);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move2].power, 0, 3);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_SingleSpace);
    StringAppend(gStringVar4, sStatStrings[13]);
    StringAppend(gStringVar4, sSplitStrings[gBattleMoves[move2].split]);
    StringAppend(gStringVar4, sText_Newline);
    //buffer move 3
    StringAppend(gStringVar4, gMoveNames[move3]);
    StringAppend(gStringVar4, sText_SingleSpace);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move3].pp, 0, 2);
    StringAppend(gStringVar4, sStatStrings[14]),
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sStatStrings[12]);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move3].power, 0, 3);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_SingleSpace);
    StringAppend(gStringVar4, sStatStrings[13]);
    StringAppend(gStringVar4, sSplitStrings[gBattleMoves[move3].split]);
    StringAppend(gStringVar4, sText_Newline);
    //buffer move 4
    StringAppend(gStringVar4, gMoveNames[move4]);
    StringAppend(gStringVar4, sText_SingleSpace);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move4].pp, 0, 2);
    StringAppend(gStringVar4, sStatStrings[14]),
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_Newline);
    StringAppend(gStringVar4, sStatStrings[12]);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move4].power, 0, 3);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_SingleSpace);
    StringAppend(gStringVar4, sStatStrings[13]);
    StringAppend(gStringVar4, sSplitStrings[gBattleMoves[move4].split]);
    StringAppend(gStringVar4, sText_Newline);
}

void RyuBufferContestMovesData(void)
{

}

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    u16 temp = 0;
    int i;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    switch (windowId)
    {
    case MON_NICKNAME_WINDOW:
        BufferTitleWindow();
        AddTextPrinterParameterized4(MON_NICKNAME_WINDOW, 1, 1, 0, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(MON_NICKNAME_WINDOW);
        CopyWindowToVram(MON_NICKNAME_WINDOW, 3);
        break;
    case STATS_WINDOW:
        RyuBufferStats();
        AddTextPrinterParameterized4(STATS_WINDOW, 0, 1, 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(STATS_WINDOW);
        CopyWindowToVram(STATS_WINDOW, 3);
        break;
    case LEVEL_WINDOW:
        BufferLevelWindow();
        AddTextPrinterParameterized4(LEVEL_WINDOW, 1, 1, 0, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(LEVEL_WINDOW);
        CopyWindowToVram(LEVEL_WINDOW, 3);
        break;
    case SUMMARY_WINDOW:
        BufferSummaryWindow();
        AddTextPrinterParameterized4(SUMMARY_WINDOW, 0, 1, 0, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(SUMMARY_WINDOW);
        CopyWindowToVram(SUMMARY_WINDOW, 3);
        break;
    case ABILITY_WINDOW:
        BufferAbilityWindow();
        AddTextPrinterParameterized4(ABILITY_WINDOW, 0, 1, 0, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(ABILITY_WINDOW);
        CopyWindowToVram(ABILITY_WINDOW, 3);
        break;
    case ITEM_EXP_WINDOW:
        BufferItemExpWindow();
        AddTextPrinterParameterized4(ITEM_EXP_WINDOW, 0, 1, 0, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(ITEM_EXP_WINDOW);
        CopyWindowToVram(ITEM_EXP_WINDOW, 3);
        break;
    case BATTLE_MOVES_WINDOW:
        RyuBufferBattleMovesData();
        AddTextPrinterParameterized4(BATTLE_MOVES_WINDOW, 0, 1, 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        ClearWindowTilemap(BATTLE_MOVES_WINDOW);
        PutWindowTilemap(BATTLE_MOVES_WINDOW);
        CopyWindowToVram(BATTLE_MOVES_WINDOW, 3);
        break;
    case CONTEST_MOVES_WINDOW:
        RyuBufferContestMovesData();
        AddTextPrinterParameterized4(CONTEST_MOVES_WINDOW, 0, 1, 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        ClearWindowTilemap(CONTEST_MOVES_WINDOW);
        PutWindowTilemap(CONTEST_MOVES_WINDOW);
        CopyWindowToVram(CONTEST_MOVES_WINDOW, 3);
        break;
    }
}


static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

bool32 IsEmptySlot(u8 slot)
{
    if ((!(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) == SPECIES_NONE)) || (!(GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG) == TRUE)))
        return FALSE;
    return TRUE;
}

void LoadSelectedPage(void)
{
    int i;
    PlaySE(3);
    for (i = 0; i < WINDOWS_COUNT;i++)
        ClearWindowTilemap(i);
    
    switch (gSpecialVar_0x8002)//which page to load
    {
        case 0:
            LZDecompressWram(sSummaryTilemap, sBg1TilemapBuffer);
            FillSummaryData();
            break;
        case 1:
            LZDecompressWram(sStatsTilemap, sBg1TilemapBuffer);
            FillStatsData();
            break;
        case 2:
            LZDecompressWram(sStatsTilemap, sBg1TilemapBuffer);
            FillBattleMovesData();
            break;
        case 3:
            LZDecompressWram(sStatsTilemap, sBg1TilemapBuffer);
            FillContestMovesData();
            break;
    }
    ScheduleBgCopyTilemapToVram(1);
    return;
}


/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(3);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        gSpecialVar_0x8001++;
        if (gSpecialVar_0x8001 > 5)
            gSpecialVar_0x8001 = 0;
        LoadSelectedPage();
        RyuDrawPreviewSprite();
        RyuDrawCaughtBall();
    }
    else if (JOY_NEW(DPAD_UP))
    {   
        gSpecialVar_0x8001--;
        if (gSpecialVar_0x8001 > 5)
            gSpecialVar_0x8001 = 5;
        LoadSelectedPage();
        RyuDrawPreviewSprite();
        RyuDrawCaughtBall();
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        gSpecialVar_0x8002--;
        if (gSpecialVar_0x8002 > 3)
            gSpecialVar_0x8002 = 3;
        LoadSelectedPage();
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        gSpecialVar_0x8002++;
        if (gSpecialVar_0x8002 > 3)
            gSpecialVar_0x8002 = 0;
        LoadSelectedPage();
    }
}