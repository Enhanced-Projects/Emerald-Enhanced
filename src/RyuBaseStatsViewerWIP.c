#include "global.h"
#include "RyuBaseStatsViewerWIP.h"
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
    MainCallback savedCallback; // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
};

enum WindowIds
{
    MON_NICKNAME_WINDOWBS,
    STATS_WINDOWBS,
    LEVEL_WINDOWBS,
    WINDOWS_COUNTBS
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sBSMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBSBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 specialPreviewSpriteID1 = 1;

//==========STATIC=DEFINES==========//
static void BSMenu_RunSetup(void);
static bool8 BSMenu_DoGfxSetup(void);
static bool8 BSMenu_InitBgs(void);
static void BSMenu_FadeAndBail(void);
static bool8 BSMenu_LoadGraphics(void);
static void BSMenu_InitWindows(void);
static void BS_PrintToWindow(u8 windowId, u8 colorIdx);
static void BSTask_MenuWaitFadeIn(u8 taskId);
static void BSTask_MenuMain(u8 taskId);

//==========CONST=DATA==========//
static const struct BgTemplate sBSMenuBgTemplates[] =
    {
        {.bg = 0, // windows, etc
         .charBaseIndex = 0,
         .mapBaseIndex = 31,
         .priority = 1},
        {.bg = 1, // this bg loads the UI tilemap
         .charBaseIndex = 3,
         .mapBaseIndex = 30,
         .priority = 2},
        {.bg = 2, // this bg loads the UI tilemap
         .charBaseIndex = 0,
         .mapBaseIndex = 28,
         .priority = 0}};

static const struct WindowTemplate sBSMenuWindowTemplates[] =
    {
        [MON_NICKNAME_WINDOWBS] =
            {
                .bg = 0,          // windowId bg to print text on
                .tilemapLeft = 2, // position from left (per 8 pixels)
                .tilemapTop = 2,  // position from top (per 8 pixels)
                .width = 24,      // width (per 8 pixels)
                .height = 2,      // height (per 8 pixels)
                .paletteNum = 15, // palette index to use for text
                .baseBlock = 1,   // tile start in VRAM
            },
        [STATS_WINDOWBS] =
            {
                .bg = 0,           // windowId bg to print text on
                .tilemapLeft = 12, // position from left (per 8 pixels)
                .tilemapTop = 4,   // position from top (per 8 pixels)
                .width = 16,       // width (per 8 pixels)
                .height = 14,      // height (per 8 pixels)
                .paletteNum = 15,  // palette index to use for text
                .baseBlock = 49,   // tile start in VRAM
            },
        [LEVEL_WINDOWBS] =
            {
                .bg = 0,          // windowId bg to print text on
                .tilemapLeft = 2, // position from left (per 8 pixels)
                .tilemapTop = 12, // position from top (per 8 pixels)
                .width = 9,       // width (per 8 pixels)
                .height = 8,      // height (per 8 pixels)
                .paletteNum = 15, // palette index to use for text
                .baseBlock = 274, // tile start in VRAM
            }
    };

static const u32 sBSMenuTiles[] = INCBIN_U32("graphics/stat_assist/tiles.4bpp.lz");
static const u32 sBSStatsTilemap[] = INCBIN_U32("graphics/stat_assist/tilemap.bin.lz");
const u8 sBSMainLabelSummaryText[] = _("'s data");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sBSMenuWindowFontColors[][3] =
    {
        [FONT_BLACK] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY},
        [FONT_WHITE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY},
        [FONT_RED] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GREY},
        [FONT_BLUE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREY},
};
//==========FUNCTIONS==========//
// UI loader template
void BSTask_OpenMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        BSViewer_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void BSViewer_Init(MainCallback callback)
{
    if ((sBSMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sBSMenuDataPtr->gfxLoadState = 0;
    sBSMenuDataPtr->savedCallback = callback;

    SetMainCallback2(BSMenu_RunSetup);
}

static void BSMenu_RunSetup(void)
{
    while (1)
    {
        if (BSMenu_DoGfxSetup() == TRUE)
            break;
    }
}

static void BSMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void BSMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}
extern u16 CreateMonPicSprite(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag);
extern u16 FreeAndDestroyMonPicSprite(u16 spriteId);
void RyuBSDrawPreviewSprite(void)
{
    FreeSpriteOamMatrix(&gSprites[specialPreviewSpriteID1]);
    FreeAndDestroyMonPicSprite(specialPreviewSpriteID1);
    specialPreviewSpriteID1 = CreateMonPicSprite(gSpecialVar_0x8001, 0, 0x8000, TRUE, 50, 65, 0, 0xFFFF);
    PlayCry1(gSpecialVar_0x8001, 127);
}

void FillBSSummaryData(void)
{
    if (gSpecialVar_0x8001 == 0)
        gSpecialVar_0x8001 = 1;
    BS_PrintToWindow(MON_NICKNAME_WINDOWBS, FONT_BLACK);
    BS_PrintToWindow(LEVEL_WINDOWBS, FONT_BLACK);
    BS_PrintToWindow(STATS_WINDOWBS, FONT_BLACK);
}

static bool8 BSMenu_DoGfxSetup(void)
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
        if (BSMenu_InitBgs())
        {
            sBSMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            BSMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (BSMenu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        BSMenu_InitWindows();
        gMain.state++;
        break;
    case 5:
        RyuBSDrawPreviewSprite();
        FillBSSummaryData();
        taskId = CreateTask(BSTask_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(BSMenu_VBlankCB);
        SetMainCallback2(BSMenu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({            \
    void **ptr__ = (void **)&(ptr); \
    if (*ptr__ != NULL)             \
        Free(*ptr__);               \
})

static void Menu_FreeResources(void)
{
    try_free(sBSMenuDataPtr);
    try_free(sBSBg1TilemapBuffer);
    FreeAllWindowBuffers();
}

static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sBSMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void BSMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(BSMenu_VBlankCB);
    SetMainCallback2(BSMenu_MainCB);
}

static bool8 BSMenu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBSBg1TilemapBuffer = Alloc(0x800);
    if (sBSBg1TilemapBuffer == NULL)
        return FALSE;

    memset(sBSBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBSMenuBgTemplates, NELEMS(sBSMenuBgTemplates));
    SetBgTilemapBuffer(1, sBSBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 BSMenu_LoadGraphics(void)
{
    switch (sBSMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sBSMenuTiles, 0, 0, 0);
        sBSMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sBSStatsTilemap, sBSBg1TilemapBuffer);
            sBSMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(GetOverworldTextboxPalettePtr(), 0, 32);
        sBSMenuDataPtr->gfxLoadState++;
        break;
    default:
        sBSMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void BSMenu_InitWindows(void)
{
    InitWindows(sBSMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    switch (gSpecialVar_0x8002) // which set of windows to load (page)
    {
    case 0:
        FillWindowPixelBuffer(MON_NICKNAME_WINDOWBS, 0);
        PutWindowTilemap(MON_NICKNAME_WINDOWBS);
        CopyWindowToVram(MON_NICKNAME_WINDOWBS, 3);
        FillWindowPixelBuffer(LEVEL_WINDOWBS, 0);
        PutWindowTilemap(LEVEL_WINDOWBS);
        CopyWindowToVram(LEVEL_WINDOWBS, 3);
        FillWindowPixelBuffer(STATS_WINDOWBS, 0);
        PutWindowTilemap(STATS_WINDOWBS);
        CopyWindowToVram(STATS_WINDOWBS, 3);
        break;
    }

    ScheduleBgCopyTilemapToVram(2);
}

const u8 sText_BSNewline[] = _("\n");
const u8 sText_BSSingleSpace[] = _(" ");
const u8 sText_TripleSpace[] = _("   ");
const u8 sText_BSFwSlash[] = _("/");
const u8 sText_BSPct[] = _(" % ");

int RyuGetCurrentBST(void)
{
    u16 species = gSpecialVar_0x8001;
    return (gBaseStats[species].baseHP + 
            gBaseStats[species].baseAttack + 
            gBaseStats[species].baseSpAttack + 
            gBaseStats[species].baseDefense + 
            gBaseStats[species].baseSpeed + 
            gBaseStats[species].baseSpDefense);
}

void BSRyuBufferStats(void)
{
    int temp;
    // buffer HP
    StringCopy(gStringVar4, ((const u8[])_("Base HP: ")));
    temp = gBaseStats[gSpecialVar_0x8001].baseHP;
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_TripleSpace);
    // buffer speed
    StringAppend(gStringVar4, ((const u8[])_("Speed: ")));
    temp = gBaseStats[gSpecialVar_0x8001].baseSpeed;
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_BSNewline);
    // buffer atk
    StringAppend(gStringVar4, ((const u8[])_("Attack: ")));
    temp = gBaseStats[gSpecialVar_0x8001].baseAttack;
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_TripleSpace);
    // buffer spatk
    StringAppend(gStringVar4, ((const u8[])_("Sp Atk: ")));
    temp = gBaseStats[gSpecialVar_0x8001].baseSpAttack;
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_BSNewline);
    // buffer def
    StringAppend(gStringVar4, ((const u8[])_("Defense: ")));
    temp = gBaseStats[gSpecialVar_0x8001].baseSpAttack;
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_TripleSpace);
    // buffer SPDEF
    StringAppend(gStringVar4, ((const u8[])_("Sp Def: ")));
    temp = gBaseStats[gSpecialVar_0x8001].baseSpDefense;
    ConvertIntToDecimalStringN(gStringVar1, temp, 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_BSNewline);
    // buffer BST
    StringAppend(gStringVar4, (const u8[])_("Base Stat Total: "));
    ConvertIntToDecimalStringN(gStringVar1, RyuGetCurrentBST(), 0, 4);
    StringAppend(gStringVar4, gStringVar1);
    StringAppend(gStringVar4, sText_BSNewline);
    // buffer abilities
    StringAppend(gStringVar4, ((const u8[])_("Abilities:")));
    StringAppend(gStringVar4, sText_BSNewline);
    StringAppend(gStringVar4, gAbilityNames[gBaseStats[gSpecialVar_0x8001].abilities[0]]);
    StringAppend(gStringVar4, sText_BSSingleSpace);
    StringAppend(gStringVar4, sText_BSFwSlash);
    StringAppend(gStringVar4, sText_BSSingleSpace);
    StringAppend(gStringVar4, gAbilityNames[gBaseStats[gSpecialVar_0x8001].abilities[1]]);
    StringAppend(gStringVar4, sText_BSNewline);
    StringAppend(gStringVar4, ((const u8[])_("Hidden Ability:")));
    StringAppend(gStringVar4, sText_BSNewline);
    StringAppend(gStringVar4, gAbilityNames[gBaseStats[gSpecialVar_0x8001].abilityHidden]);
}

void BSBufferTitleWindow(void)
{
    StringCopy(gStringVar4, gSpeciesNames[gSpecialVar_0x8001]);
    StringAppend(gStringVar4, sBSMainLabelSummaryText);
    StringAppend(gStringVar4, sText_BSSingleSpace);
    StringCopy(gStringVar1, ((const u8[])_("{L_BUTTON}{R_BUTTON}: Change Pokémon")));
    StringExpandPlaceholders(gStringVar2, gStringVar1);
    StringAppend(gStringVar4, gStringVar1);
}

void BSBufferLevelWindow(void)
{
    int temp = (((gBaseStats[gSpecialVar_0x8001].genderRatio) + 1) * 100);
    int female = (temp / 256);
    int male = (100 - female);

    StringCopy(gStringVar4, ((const u8[])_("Gender ratio: ")));
    StringAppend(gStringVar4, sText_BSNewline);
    if (temp == 25600) //mon is genderless
    {
        StringAppend(gStringVar4, ((const u8[])_("Genderless")));
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, male, 0, 3);
        StringAppend(gStringVar4, ((const u8[])_("{COLOR LIGHT_BLUE}{SHADOW BLUE}")));
        StringAppend(gStringVar4, gStringVar1);
        StringAppend(gStringVar4, sText_BSPct);
        StringExpandPlaceholders(gRyuStringVar4, gStringVar4);
        StringCopy(gStringVar4, gRyuStringVar4);
        StringAppend(gStringVar4, ((const u8[])_(" {COLOR DARK_GREY}{SHADOW LIGHT_GREY}/ {COLOR LIGHT_RED}{SHADOW RED}")));
        ConvertIntToDecimalStringN(gStringVar1, female, 0, 3);
        StringAppend(gStringVar4, gStringVar1);
        StringAppend(gStringVar4, sText_BSPct);
        StringExpandPlaceholders(gRyuStringVar4, gStringVar4);
        StringCopy(gStringVar4, gRyuStringVar4);
        StringAppend(gStringVar4, ((const u8[])_("{COLOR DARK_GREY}{SHADOW LIGHT_GREY}")));
        StringExpandPlaceholders(gRyuStringVar4, gStringVar4);
        StringCopy(gStringVar4, gRyuStringVar4);
    }
    StringAppend(gStringVar4, sText_BSNewline);
    StringAppend(gStringVar4, ((const u8[])_("Type 1: ")));
    StringAppend(gStringVar4, gTypeNames[gBaseStats[gSpecialVar_0x8001].type1]);
    StringAppend(gStringVar4, sText_BSNewline);
    StringAppend(gStringVar4, ((const u8[])_("Type 2: ")));
    StringAppend(gStringVar4, gTypeNames[gBaseStats[gSpecialVar_0x8001].type2]);
}

static void BS_PrintToWindow(u8 windowId, u8 colorIdx)
{
    u16 temp = 0;
    int i;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    switch (windowId)
    {
    case STATS_WINDOWBS:
        BSRyuBufferStats();
        AddTextPrinterParameterized4(STATS_WINDOWBS, 0, 1, 4, 0, 0, sBSMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(STATS_WINDOWBS);
        CopyWindowToVram(STATS_WINDOWBS, 3);
        break;
    case MON_NICKNAME_WINDOWBS:
        BSBufferTitleWindow();
        AddTextPrinterParameterized4(MON_NICKNAME_WINDOWBS, 1, 1, 0, 0, 0, sBSMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(MON_NICKNAME_WINDOWBS);
        CopyWindowToVram(MON_NICKNAME_WINDOWBS, 3);
        break;
    case LEVEL_WINDOWBS:
        BSBufferLevelWindow();
        AddTextPrinterParameterized4(LEVEL_WINDOWBS, 0, 1, 0, 0, 0, sBSMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        PutWindowTilemap(LEVEL_WINDOWBS);
        CopyWindowToVram(LEVEL_WINDOWBS, 3);
        break;
    }
}

static void BSTask_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = BSTask_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sBSMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

extern bool32 IsEmptySlot(u8 slot);

void BSLoadSelectedPage(void)
{
    int i;
    PlaySE(3);
    for (i = 0; i < WINDOWS_COUNTBS; i++)
        ClearWindowTilemap(i);
    FillBSSummaryData();
    return;
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void BSTask_MenuMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(3);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }
    else if (JOY_NEW(L_BUTTON))
    {
        gSpecialVar_0x8001--;
        if (gSpecialVar_0x8001 == 0)
            gSpecialVar_0x8001 = SPECIES_ARCEUS;
        BSLoadSelectedPage();
    }
    else if (JOY_NEW(R_BUTTON))
    {
        gSpecialVar_0x8001++;
        if (gSpecialVar_0x8001 > SPECIES_ARCEUS)
            gSpecialVar_0x8001 = SPECIES_BULBASAUR;
        BSLoadSelectedPage();
    }
}