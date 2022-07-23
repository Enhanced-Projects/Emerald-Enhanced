#include "global.h"
#include "option_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "event_data.h"
#include "constants/vars.h"
#include "graphics.h"
#include "constants/rgb.h"

#define Y_DIFF 16 // Difference in pixels between items.

// Menu items page 1
enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_FORCESETBATTLE,
    //FULL_COLOR
    MENUITEM_THEME_UI,
    MENUITEM_THEME,
    MENUITEM_FRAMETYPE,
    MENUITEM_RDM_MUSIC,
    MENUITEM_BAR_SPEED,
    MENUITEM_TRANSITION,
    MENUITEM_VANILLACAP,
    MENUITEM_AUTORUN,
    MENUITEM_TRAINERSLIDE,
    MENUITEM_SAVE,
    MENUITEM_COUNT,
};

// Window Ids
enum
{
    WIN_TEXT_OPTION,
    WIN_OPTIONS,
    WIN_COLOR_PICKER
};

struct OptionMenu
{
    u8 sel[MENUITEM_COUNT];
    int menuCursor;
    int visibleCursor;
};

// this file's functions
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void Task_OptionColorPicker(u8 taskId);
static void HighlightOptionMenuItem(int cursor);
static void TextSpeed_DrawChoices(int selection, int y, u8 textSpeed);
static void BattleScene_DrawChoices(int selection, int y, u8 textSpeed);
static void VanillaCap_DrawChoices(int selection, int y, u8 textSpeed);
static void TrainerSlide_DrawChoices(int selection, int y, u8 textSpeed);
static void ToggleAutoRun_DrawChoices(int selection, int y, u8 textSpeed);
static void ThemeSelection_DrawChoices(int selection, int y, u8 textSpeed);
//FULL_COLOR
static void ThemeUISelection_DrawChoices(int selection, int y, u8 textSpeed);
static int ThemeUI_ProcessInput(int selection);

static void HpBar_DrawChoices(int selection, int y, u8 textSpeed);
static void Transition_DrawChoices(int selection, int y, u8 textSpeed);
static void RandomMusic_DrawChoices(int selection, int y, u8 textSpeed);
static void FrameType_DrawChoices(int selection, int y, u8 textSpeed);
static void ForceBattleSet_DrawChoices(int selection, int y, u8 textSpeed);
static int FrameType_ProcessInput(int selection);
static int FourOptions_ProcessInput(int selection);
static int ThreeOptions_ProcessInput(int selection);
static int TwoOptions_ProcessInput(int selection);
static int ElevenOptions_ProcessInput(int selection);
static int Theme_ProcessInput(int selection);
static int Sound_ProcessInput(int selection);
static void DrawTextOption(void);
static void DrawOptionMenuTexts(void);
static void sub_80BB154(void);


struct
{
    void (*drawChoices)(int selection, int y, u8 textSpeed);
    int (*processInput)(int selection);
} 

static const sItemFunctions[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED] = {TextSpeed_DrawChoices, ThreeOptions_ProcessInput},
    [MENUITEM_BATTLESCENE] = {BattleScene_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_FORCESETBATTLE] = {ForceBattleSet_DrawChoices, TwoOptions_ProcessInput},
    //FULL_COLOR
    [MENUITEM_THEME_UI] = {ThemeUISelection_DrawChoices, ThemeUI_ProcessInput},
    [MENUITEM_THEME] = {ThemeSelection_DrawChoices, Theme_ProcessInput},
    [MENUITEM_FRAMETYPE] = {FrameType_DrawChoices, FrameType_ProcessInput},
    [MENUITEM_RDM_MUSIC] = {RandomMusic_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_BAR_SPEED] = {HpBar_DrawChoices, ElevenOptions_ProcessInput},
    [MENUITEM_TRANSITION] = {Transition_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_VANILLACAP] = {VanillaCap_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_AUTORUN] = {ToggleAutoRun_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_TRAINERSLIDE] = {TrainerSlide_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_SAVE] = {NULL, NULL},
};

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;

// const rom data
static const u16 sUnknown_0855C604[] = INCBIN_U16("graphics/misc/option_menu_text.gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/misc/option_menu_equals_sign.4bpp");
static const u8 sTextBarSpeed[] = _("Bar Anim Spe");
static const u8 sText_ExpBar[] = _("EXP BAR");
static const u8 sText_Transition[] = _("B. Transition");
static const u8 sText_ForceSetBattleMode[] = _("Battle Style");
static const u8 sText_Dynamic[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Dynamic");
static const u8 sText_Set[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Set");
static const u8 sText_VanillaLevelCap[] = _("Lv cap 100");
static const u8 sText_ToggleAutoRun[] = _("Auto Run");
static const u8 sText_TrainerSlideOption[] = _("Slide in msg");

//FULL_COLOR
static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_FORCESETBATTLE]     = sText_ForceSetBattleMode,
    //FULL_COLOR
    [MENUITEM_THEME_UI]    = gText_ThemeUISelector,
    [MENUITEM_THEME]       = gText_ThemeSelector,
    [MENUITEM_FRAMETYPE]   = gText_Frame,
    [MENUITEM_RDM_MUSIC]   = gText_RandomRouteMusic,
    [MENUITEM_BAR_SPEED]   = sTextBarSpeed,
    [MENUITEM_TRANSITION]  = sText_Transition,
    [MENUITEM_VANILLACAP]  = sText_VanillaLevelCap,
    [MENUITEM_AUTORUN]  = sText_ToggleAutoRun,
    [MENUITEM_TRAINERSLIDE]  = sText_TrainerSlideOption,
    [MENUITEM_SAVE]        = gText_OptionMenuSave,
};

static const u8 sText_Instant[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Instant");

static const u8 *const sTextSpeedStrings[] = {gText_TextSpeedSlow, gText_TextSpeedMid, gText_TextSpeedFast};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    {
        .bg = 1,
        .tilemapLeft = 10,
        .tilemapTop = 8,
        .width = 17,
        .height = 10,
        .paletteNum = 7,
        .baseBlock = 0x36+30*15
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
   {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   }
};

static const u16 sUnknown_0855C6A0[] = {0x7E51};

// code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void DrawChoices(u32 id, int y, u8 textSpeed)
{
    if (sItemFunctions[id].drawChoices != NULL)
        sItemFunctions[id].drawChoices(sOptions->sel[id], y, textSpeed);
}

void CB2_InitOptionMenu(void)
{
    u16 buf[0x20];
    u32 i, taskId;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void*)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ResetBgPositions();
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 1 | WININ_WIN1_BG1);
        SetGpuReg(REG_OFFSET_WINOUT, 35);
        SetGpuReg(REG_OFFSET_BLDCNT, 193);
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(0, 32));
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gReservedSpritePaletteCount = 6;
        gMain.state++;
        break;
    case 3:
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_VANILLA:
            case THEME_COLOR_LIGHT:
                LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
                break;
            case THEME_COLOR_DARK:
                LoadBgTiles(1, GetWindowFrameDarkTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
                break;
            case THEME_COLOR_USER:
                LoadBgTiles(1, GetWindowFrameUserTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
                break;
        }
        gMain.state++;
        break;
    case 4:
        LoadPalette(sUnknown_0855C6A0, 0, sizeof(sUnknown_0855C6A0));
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_VANILLA:
            case THEME_COLOR_LIGHT:
                LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
                break;
            case THEME_COLOR_DARK:
                LoadPalette(GetWindowFrameDarkTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
                break;
            case THEME_COLOR_USER:
                CpuCopy16(GetWindowFrameUserTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, buf, 0x20);
                buf[14] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];
                if (gSaveBlock2Ptr->optionsWindowFrameType == 0) {
                    buf[3] = COLOR_AUTO_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER], THRESHOLD_DEFAULT);
                    buf[5] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];
                    buf[13] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];
                }
                LoadPalette(buf, 0x70, 0x20);
                break;
        }
        gMain.state++;
        break;
    case 5:
        CpuCopy16(sUnknown_0855C604, buf, sizeof(sUnknown_0855C604));
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_DARK:
                buf[1] = RGB(3, 3, 3);
                buf[6] = RGB(26, 26, 25);
                buf[7] = RGB(9, 9, 9);
                break;
            case THEME_COLOR_USER:
                buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];
                break;
        }
        LoadPalette(buf, 0x10, sizeof(sUnknown_0855C604));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(0);
        DrawTextOption();
        gMain.state++;
        break;
    case 7:
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(1);
        DrawOptionMenuTexts();
        gMain.state++;
    case 9:
        sub_80BB154();
        gMain.state++;
        break;
    case 10:
        taskId = CreateTask(Task_OptionMenuFadeIn, 0);

        sOptions = AllocZeroed(sizeof(*sOptions));
        sOptions->sel[MENUITEM_TEXTSPEED] = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->sel[MENUITEM_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel[MENUITEM_FORCESETBATTLE] = gSaveBlock2Ptr->forceSetBattleType;
        //FULL_COLOR
        sOptions->sel[MENUITEM_THEME_UI] = VarGet(VAR_HAT_THEME_UI_NUMBER);

        sOptions->sel[MENUITEM_THEME] = VarGet(VAR_RYU_THEME_NUMBER);
        sOptions->sel[MENUITEM_RDM_MUSIC] = FlagGet(FLAG_RYU_RANDOMIZE_MUSIC);
        sOptions->sel[MENUITEM_FRAMETYPE] = gSaveBlock2Ptr->optionsWindowFrameType;
        sOptions->sel[MENUITEM_BAR_SPEED] = (VarGet(VAR_OPTIONS_HP_BAR_SPEED));
        sOptions->sel[MENUITEM_TRANSITION] = FlagGet(FLAG_OPTIONS_INSTANT_TRANSITION);
        sOptions->sel[MENUITEM_VANILLACAP] = FlagGet(FLAG_RYU_VANILLA_CAP);
        sOptions->sel[MENUITEM_TRAINERSLIDE] = gSaveBlock2Ptr->trainerSlideEnabled;
        sOptions->sel[MENUITEM_AUTORUN] = FlagGet(FLAG_RYU_AUTORUN);


        for (i = 0; i < 8; i++)
            DrawChoices(i, i * Y_DIFF, 0xFF);

        HighlightOptionMenuItem(sOptions->menuCursor);

        CopyWindowToVram(WIN_OPTIONS, 3);
        gMain.state++;
        break;
    case 11:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void ScrollMenu(int direction)
{
    int menuItem, pos;
    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor + 3, pos = 6;
    else
        menuItem = sOptions->menuCursor - 3, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF, 0xFF);
    AddTextPrinterParameterized(WIN_OPTIONS, 1, sOptionMenuItemsNames[menuItem], 8, (pos * Y_DIFF) + 1, 0xFF, NULL);
    CopyWindowToVram(WIN_OPTIONS, 2);
}

static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount = MENUITEM_COUNT - 7;
    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(0));

    // Clear moved items
    if (direction == 0)
    {
        y = 7 - scrollCount;
        if (y < 0)
            y = 7;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MENUITEM_COUNT - 1 - i, pos = 6 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF, 0xFF);
        AddTextPrinterParameterized(WIN_OPTIONS, 1, sOptionMenuItemsNames[menuItem], 8, (pos * Y_DIFF) + 1, 0xFF, NULL);
    }
    CopyWindowToVram(WIN_OPTIONS, 2);
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    int i, scrollCount = 0, itemsToRedraw;
    if (gMain.newKeys & A_BUTTON)
    {
        if (sOptions->menuCursor == MENUITEM_SAVE)
            gTasks[taskId].func = Task_OptionMenuSave;
        else if (sOptions->menuCursor == MENUITEM_THEME
        && sOptions->sel[MENUITEM_THEME] == 2)
            gTasks[taskId].func = Task_OptionColorPicker;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (sOptions->visibleCursor == 3) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor == sOptions->visibleCursor - 1)
                sOptions->visibleCursor--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor = sOptions->menuCursor = 3;
                ScrollAll(0);
                sOptions->visibleCursor = 6;
                sOptions->menuCursor = MENUITEM_COUNT - 1;
            }
            else
            {
                sOptions->visibleCursor--;
            }
        }
        HighlightOptionMenuItem(sOptions->visibleCursor);
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (sOptions->visibleCursor == 3) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor == MENUITEM_COUNT - 3)
                sOptions->visibleCursor++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor >= MENUITEM_COUNT) // Scroll all the way to the tom.
            {
                sOptions->visibleCursor = 3;
                sOptions->menuCursor = MENUITEM_COUNT - 4;
                ScrollAll(1);
                sOptions->visibleCursor = sOptions->menuCursor = 0;
            }
            else
            {
                sOptions->visibleCursor++;
            }
        }
        HighlightOptionMenuItem(sOptions->visibleCursor);
    }
    else if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
    {
        int cursor = sOptions->menuCursor;
        u8 previousOption = sOptions->sel[cursor];
        if (sItemFunctions[cursor].processInput != NULL)
            sOptions->sel[cursor] = sItemFunctions[cursor].processInput(previousOption);

        if (previousOption != sOptions->sel[cursor])
            DrawChoices(cursor, sOptions->visibleCursor * Y_DIFF, 0);
    }
}

static const struct OamData sHueBarOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_8BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct OamData sSaturationBarOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 4,
};

static const struct OamData sValueBarOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 5,
};

static const struct SpriteTemplate sHueBarSpriteTemplate =
{
    .tileTag = 0x7000,
    .paletteTag = 0xFFFF,
    .oam = &sHueBarOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSaturationBarSpriteTemplate =
{
    .tileTag = 0x7001,
    .paletteTag = 0xFFFF,
    .oam = &sSaturationBarOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sValueBarSpriteTemplate =
{
    .tileTag = 0x7002,
    .paletteTag = 0xFFFF,
    .oam = &sValueBarOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sSelectorOamData = {
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

void SelectorSpriteCallback(struct Sprite * sprite) {
    if(!sprite->data[0]) {
        sprite->oam.objMode = ST_OAM_OBJ_NORMAL;
        return;
    }
    if(!(sprite->data[1]--)) {
        sprite->data[1] = 20;
        sprite->oam.objMode = !(sprite->oam.objMode-1) + 1;
    }
}

static const struct SpriteTemplate sSelectorSpriteTemplate =
{
    .tileTag = 0x7003,
    .paletteTag = 0x7003,
    .oam = &sSelectorOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SelectorSpriteCallback,
};

static const u8 sHueBarTiles[] = INCBIN_U8("graphics/misc/hue_bar.8bpp");
static const u16 sHueBarPalette[] = INCBIN_U16("graphics/misc/hue_bar.gbapal");
static const u8 sSaturationBarTiles[] = INCBIN_U8("graphics/misc/saturation_bar.4bpp");
static const u8 sValueBarTiles[] = INCBIN_U8("graphics/misc/value_bar.4bpp");
static const u8 sSelectorTiles[] = INCBIN_U8("graphics/misc/color_picker_point.4bpp");
static const u16 sSelectorPalette[] = INCBIN_U16("graphics/misc/color_picker_point.gbapal");

static const struct SpriteSheet sHsvSpriteSheets[] = {
    {sHueBarTiles, sizeof(sHueBarTiles), 0x7000},
    {sSaturationBarTiles, sizeof(sSaturationBarTiles), 0x7001},
    {sValueBarTiles, sizeof(sValueBarTiles), 0x7002},
    {sSelectorTiles, sizeof(sSelectorTiles), 0x7003}
};

static const struct SpritePalette sSelectorSpritePalette = {
    .data = sSelectorPalette,
    .tag = 0x7003,
};

struct HSV {
    u8 h;
    u8 s;
    u8 v;
};

static inline struct HSV ConvertRGB2HSV(u32 rgb) {
    s32 r = GET_R(rgb);
    s32 g = GET_G(rgb);
    s32 b = GET_B(rgb);
    s32 cmax = max(g, b);
    s32 cmin = min(g, b);
    s32 cdiff;
    s32 h, s, v;
    cmax = max(r, cmax);
    cmin = min(r, cmin);
    cdiff = cmax - cmin;
    if(cmax != cmin) {
        if(cmax == r) {
            h = 240 + ((g - b) * 40) / cdiff;
        } else if (cmax == g) {
            h = 80 + ((b - r) * 40) / cdiff;
        } else if (cmax == b) {
            h = 160 + ((r - g) * 40) / cdiff;
        }
        h %= 240;
    } else {
        h = 0;
    }
    //dest[0] = h;
    if(cmax)
        s = ((cdiff * 120) / cmax);
    else
        s = 0;
    //dest[1] = s;
    v = (cmax * 120) / 31;
    //dest[2] = v;
    return (struct HSV){h, s, v};
}

static u16 GetHueColor(struct HSV hsv) {
    u32 section = hsv.h / 40;
    u32 remainder = hsv.h % 40;
    u32 x = (remainder * 31) / 40;
    u32 r, g, b;
    switch(section) {
    case 0:
        r = 31;
        g = x;
        b = 0;
        break;
    case 1:
        r = 31 - x;
        g = 31;
        b = 0;
        break;
    case 2:
        r = 0;
        g = 31;
        b = x;
        break;
    case 3:
        r = 0;
        g = 31 - x;
        b = 31;
        break;
    case 4:
        r = x;
        g = 0;
        b = 31;
        break;
    case 5:
        r = 31;
        g = 0;
        b = 31 - x;
        break;
    }
    return RGB(r, g, b);
}

static void MakeSaturationBarPalette(struct HSV hsv)
{
    int i;
    u16 pal[16];
    u32 baseColor = GetHueColor(hsv);
    u32 cmax = (31 * hsv.v) / 120;
    u32 r = GET_R(baseColor);
    u32 g = GET_G(baseColor);
    u32 b = GET_B(baseColor);
    r = (r * hsv.v) / 120;
    g = (g * hsv.v) / 120;
    b = (b * hsv.v) / 120;
    pal[0] = 0x7C1F;
    for(i = 0; i < 15; i++) {
        pal[i+1] = RGB(r + ((cmax-r) * i) / 14, 
                     g + ((cmax-g) * i) / 14,
                     b + ((cmax-b) * i) / 14);
    }
    LoadPalette(pal, 0x140, 0x20);
}

static void MakeValueBarPalette(struct HSV hsv)
{
    int i;
    u16 pal[16];
    u32 baseColor = GetHueColor(hsv);
    //u32 cmax = (31 * hsv.v) / 120;
    u32 r = GET_R(baseColor);
    u32 g = GET_G(baseColor);
    u32 b = GET_B(baseColor);
    r += ((31-r) * (120 - hsv.s)) / 120; 
    g += ((31-g) * (120 - hsv.s)) / 120;
    b += ((31-b) * (120 - hsv.s)) / 120;
    pal[0] = 0x7C1F;
    for(i = 0; i < 15; i++) {
        pal[i+1] = RGB((r * i) / 14, 
                       (g * i) / 14,
                       (b * i) / 14);
    }
    LoadPalette(pal, 0x150, 0x20);
}

void SetPaletteBufferColor(u32 idx, u32 color)
{
    gPlttBufferUnfaded[idx] = color;
    gPlttBufferFaded[idx] = color;
}

extern const u16 CustomInterfacePaletteSlots[];
static void AdjustThemePalette(struct HSV hsv, u16 * colors, u32 idx) {
    u32 section = hsv.h / 40;
    u32 remainder = hsv.h % 40;
    u32 x = (remainder * 31) / 40;
    u32 r, g, b;
    switch(section) {
    case 0:
        r = 31;
        g = x;
        b = 0;
        break;
    case 1:
        r = 31 - x;
        g = 31;
        b = 0;
        break;
    case 2:
        r = 0;
        g = 31;
        b = x;
        break;
    case 3:
        r = 0;
        g = 31 - x;
        b = 31;
        break;
    case 4:
        r = x;
        g = 0;
        b = 31;
        break;
    case 5:
        r = 31;
        g = 0;
        b = 31 - x;
        break;
    }
    r += ((31-r) * (120 - hsv.s)) / 120; 
    g += ((31-g) * (120 - hsv.s)) / 120;
    b += ((31-b) * (120 - hsv.s)) / 120;
    r = (r * hsv.v) / 120;
    g = (g * hsv.v) / 120;
    b = (b * hsv.v) / 120;
    colors[idx] = RGB(r, g, b);
    //gSaveBlock2Ptr->userInterfaceTextboxPalette[CustomInterfacePaletteSlots[idx]] = RGB(r, g, b);
    if (idx == 4)
    {
        SetPaletteBufferColor(0x70+11, RGB(r, g, b));
        SetPaletteBufferColor(0x70+12, RGB(r, g, b));
        SetPaletteBufferColor(0x70+1, RGB(r, g, b));
        //gSaveBlock2Ptr->userInterfaceTextboxPalette[11] = RGB(r, g, b);
        //gSaveBlock2Ptr->userInterfaceTextboxPalette[12] = RGB(r, g, b);
        //gSaveBlock2Ptr->userInterfaceTextboxPalette[1] = RGB(r, g, b);
        SetPaletteBufferColor(0x11, RGB(r, g, b));
    }
    SetPaletteBufferColor(0x70+CustomInterfacePaletteSlots[idx], RGB(r, g, b));
    //LoadPalette(gSaveBlock2Ptr->userInterfaceTextboxPalette, 0x70, 0x20);
}

struct ColorPickerData {
    u8 state;
    u8 sliderSpriteIds[3];
    s8 heldTimer;
    s8 selectedBar;
    s8 selectedElement;
    struct HSV hsv;
    u16 colorBuffer[5];
};

enum {
    INPUT_PREV_ELEM,
    INPUT_NEXT_ELEM,
    INPUT_PREV_SLIDER,
    INPUT_NEXT_SLIDER,
    INPUT_INC_VALUE,
    INPUT_DEC_VALUE,
    INPUT_CANCEL,
    INPUT_APPLY,
};
static u32 ColorPickerProcessInput(void) {
    if(JOY_NEW(A_BUTTON)) {
        return INPUT_APPLY;
    }
    if(JOY_NEW(B_BUTTON)) {
        return INPUT_CANCEL;
    }
    if(JOY_NEW(L_BUTTON)) {
        return INPUT_PREV_ELEM;
    } else if(JOY_NEW(R_BUTTON)) {
        return INPUT_NEXT_ELEM;
    }
    if(JOY_NEW(DPAD_UP)) {
        return INPUT_PREV_SLIDER;
    } else if(JOY_NEW(DPAD_DOWN)) {
        return INPUT_NEXT_SLIDER;
    }
    
    if(JOY_HELD(DPAD_LEFT)) {
        return INPUT_DEC_VALUE;
    } else if(JOY_HELD(DPAD_RIGHT)) {
        return INPUT_INC_VALUE;
    }
    return -1u;
}

static const u8 * gElementNames[] = {
    (u8[])_("Text Color"),
    (u8[])_("Text Shadow Color"),
    (u8[])_("Window Highlight"),
    (u8[])_("Window Border"),
    (u8[])_("Window Background"),
};

static void Task_OptionColorPicker(u8 taskId)
{
    struct ColorPickerData * taskData = (void*)gTasks[taskId].data;
    int i;

    switch(taskData->state)
    {
        case 0: {
            FreeAllSpritePalettes();
            ResetSpriteData();
            gReservedSpritePaletteCount = 6;
            gKeyRepeatStartDelay = 0;
            SetGpuRegBits(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1);
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_OBJ | WININ_WIN0_BG1 | WININ_WIN0_BG0 | WININ_WIN1_BG1);
            SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_CLR | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG0);
            PutWindowTilemap(WIN_COLOR_PICKER);
            DrawStdFrameWithCustomTileAndPalette(WIN_COLOR_PICKER, TRUE, 0x1A2, 7);
            AddTextPrinterParameterized(WIN_COLOR_PICKER, 1, (u8[])_("{LEFT_ARROW_2}{L_BUTTON} Element{R_BUTTON}{RIGHT_ARROW_2} "), 17*4-48, 0, 0xFF, NULL);
            AddTextPrinterParameterized(WIN_COLOR_PICKER, 1, gElementNames[taskData->selectedElement], ((17*8)-GetStringWidth(1, gElementNames[taskData->selectedElement], 0)) / 2, 16, 0xFF, NULL);
            AddTextPrinterParameterized(WIN_COLOR_PICKER, 1, (u8[])_("Example Text"), 2, 52, 0xFF, NULL);
            AddTextPrinterParameterized(WIN_COLOR_PICKER, 0, (u8[])_("Example Text"), 2, 66, 0xFF, NULL);
            CopyWindowToVram(WIN_COLOR_PICKER, 3);
            SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(74, 222));
            SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(58, 150));
            LoadPalette(sHueBarPalette, 0x100, sizeof sHueBarPalette);
            for(i = 0; i < 5; i++) {
                taskData->colorBuffer[i] = gSaveBlock2Ptr->userInterfaceTextboxPalette[CustomInterfacePaletteSlots[i]];
            }
            taskData->hsv = ConvertRGB2HSV(taskData->colorBuffer[taskData->selectedElement]);
            MakeSaturationBarPalette(taskData->hsv);
            MakeValueBarPalette(taskData->hsv);
            //LoadPalette(sHueBarPalette, 0x140, 0x20);
            //LoadPalette(sHueBarPalette, 0x150, 0x20);
            LoadSpriteSheet(sHsvSpriteSheets);
            LoadSpriteSheet(sHsvSpriteSheets+1);
            LoadSpriteSheet(sHsvSpriteSheets+2);
            LoadSpriteSheet(sHsvSpriteSheets+3);
            LoadSpritePalette(&sSelectorSpritePalette);
            CreateSprite(&sHueBarSpriteTemplate, 90+32+64, 40+58+32+8, 100);
            CreateSprite(&sSaturationBarSpriteTemplate, 90+32+64, 40+74+32+8, 100);
            CreateSprite(&sValueBarSpriteTemplate, 90+32+64, 40+90+32+8, 100);
            taskData->sliderSpriteIds[0] = CreateSprite(&sSelectorSpriteTemplate, 90+64+taskData->hsv.h/4, 40+58+12, 0);
            taskData->sliderSpriteIds[1] = CreateSprite(&sSelectorSpriteTemplate, 90+64+taskData->hsv.s/2, 40+74+12, 0);
            taskData->sliderSpriteIds[2] = CreateSprite(&sSelectorSpriteTemplate, 90+64+taskData->hsv.v/2, 40+90+12, 0);
            gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[0] = 1;
            //DrawStdWindowFrame();
            taskData->state++;
            break;
        }
        case 1: {
            u32 input = ColorPickerProcessInput();
            if(input == -1u) 
                break;
            switch(input) {
                case INPUT_CANCEL:
                    LoadPalette(gSaveBlock2Ptr->userInterfaceTextboxPalette, 0x70, 0x20);
                    taskData->state++;
                    break;
                case INPUT_APPLY:
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[1] = taskData->colorBuffer[4];
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[2] = taskData->colorBuffer[0];
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[3] = taskData->colorBuffer[1];
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[11] = taskData->colorBuffer[4];
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[12] = taskData->colorBuffer[4];
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[13] = taskData->colorBuffer[3];
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[14] = taskData->colorBuffer[2];
                    taskData->state++;
                    break;
                case INPUT_PREV_ELEM:
                    taskData->selectedElement--;
                    if(taskData->selectedElement < 0)
                        taskData->selectedElement = 4;
                    break;
                case INPUT_NEXT_ELEM:
                    taskData->selectedElement++;
                    if(taskData->selectedElement > 4)
                        taskData->selectedElement = 0;
                    break;
                case INPUT_PREV_SLIDER:
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[0] = 0;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[1] = 20;
                    taskData->selectedBar--;
                    if(taskData->selectedBar < 0)
                        taskData->selectedBar = 2;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[0] = 1;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].oam.objMode = 2;
                    break;
                case INPUT_NEXT_SLIDER:
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[0] = 0;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[1] = 20;
                    taskData->selectedBar++;
                    if(taskData->selectedBar > 2)
                        taskData->selectedBar = 0;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[0] = 1;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].oam.objMode = 2;
                    break;
                case INPUT_INC_VALUE: {
                    u8 * val = NULL;
                    u32 bound;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].oam.objMode = 1;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[1] = 20;
                    switch(taskData->selectedBar) {
                    case 0:
                        val = &taskData->hsv.h;
                        bound = 239;
                        break;
                    case 1:
                        val = &taskData->hsv.s;
                        bound = 120;
                        break;
                    case 2:
                        val = &taskData->hsv.v;
                        bound = 120;
                        break;
                    }
                    if(val == NULL) break;
                    *val = *val + 1;
                    if(*val > bound)
                        *val = bound;
                    break;
                }
                case INPUT_DEC_VALUE: {
                    u8 * val;
                    u32 bound;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].oam.objMode = 1;
                    gSprites[taskData->sliderSpriteIds[taskData->selectedBar]].data[1] = 20;
                    switch(taskData->selectedBar) {
                    case 0:
                        val = &taskData->hsv.h;
                        bound = 239;
                        break;
                    case 1:
                        val = &taskData->hsv.s;
                        bound = 120;
                        break;
                    case 2:
                        val = &taskData->hsv.v;
                        bound = 120;
                        break;
                    default:
                        val = NULL;
                    }
                    if(val == NULL) break;
                    *val = *val - 1;
                    if(*val > bound)
                        *val = 0;
                    break;
                }
            }
            if(input == INPUT_PREV_ELEM
            || input == INPUT_NEXT_ELEM
            || input == INPUT_INC_VALUE
            || input == INPUT_DEC_VALUE) {
                if(input == INPUT_PREV_ELEM
                || input == INPUT_NEXT_ELEM) {
                    taskData->hsv = ConvertRGB2HSV(taskData->colorBuffer[taskData->selectedElement]);
                    FillWindowPixelRect(WIN_COLOR_PICKER, 0x11, 0, 16, 17*8, 32);
                    //AddTextPrinterParameterized(WIN_COLOR_PICKER, 1, (u8[])_("            "), 0, 16, 0xFF, NULL);
                    AddTextPrinterParameterized(WIN_COLOR_PICKER, 1, gElementNames[taskData->selectedElement], ((17*8)-GetStringWidth(1, gElementNames[taskData->selectedElement], 0)) / 2, 16, 0xFF, NULL);
                    CopyWindowToVram(WIN_COLOR_PICKER, 2);
                }
                if(input == INPUT_INC_VALUE
                || input == INPUT_DEC_VALUE) {
                    AdjustThemePalette(taskData->hsv, taskData->colorBuffer, taskData->selectedElement);
                }
                MakeSaturationBarPalette(taskData->hsv);
                MakeValueBarPalette(taskData->hsv);
                gSprites[taskData->sliderSpriteIds[0]].pos1.x = 90+64+(taskData->hsv.h+1)/4;
                gSprites[taskData->sliderSpriteIds[1]].pos1.x = 90+64+taskData->hsv.s/2;
                gSprites[taskData->sliderSpriteIds[2]].pos1.x = 90+64+taskData->hsv.v/2;
            }
            break;
        }
        case 2:
            SetGpuReg(REG_OFFSET_WININ, 1 | WININ_WIN1_BG1);
            SetGpuReg(REG_OFFSET_WINOUT, 35);
            SetGpuReg(REG_OFFSET_BLDCNT, 193);
            SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 240));
            SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(0, 32));
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 4);
            HighlightOptionMenuItem(3);
            ClearStdWindowAndFrameToTransparent(WIN_COLOR_PICKER, TRUE);
            CpuFill32(0, gTasks[taskId].data, sizeof(gTasks[taskId].data));
            gTasks[taskId].func = Task_OptionMenuProcessInput;
            break;
    }
}

extern bool32 RyuCheckFor100Lv(void);

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = sOptions->sel[MENUITEM_TEXTSPEED];
    if (sOptions->sel[MENUITEM_TEXTSPEED] == 3)
        gSaveBlock2Ptr->optionsTextSpeed = 2;
        

    gSaveBlock2Ptr->optionsBattleSceneOff = sOptions->sel[MENUITEM_BATTLESCENE];
    gSaveBlock2Ptr->optionsThemeNumber = sOptions->sel[MENUITEM_THEME];
    
    gSaveBlock2Ptr->forceSetBattleType = sOptions->sel[MENUITEM_FORCESETBATTLE];
    if ((gSaveBlock2Ptr->optionsBattleSceneOff) == TRUE)
    {
        FlagSet(FLAG_RYU_DISABLED_ANIMS);
    }
    if (sOptions->sel[MENUITEM_RDM_MUSIC])
    {
        FlagSet(FLAG_RYU_RANDOMIZE_MUSIC);
        FlagClear(FLAG_RYU_NOTIFIED_RDM_MUSIC);
    }
    else
    {
        FlagClear(FLAG_RYU_RANDOMIZE_MUSIC);
        FlagSet(FLAG_RYU_NOTIFIED_RDM_MUSIC);
    }

    VarSet(VAR_RYU_THEME_NUMBER, sOptions->sel[MENUITEM_THEME]);
    //FULL_COLOR
    VarSet(VAR_HAT_THEME_UI_NUMBER, sOptions->sel[MENUITEM_THEME_UI]);
    
    //if (sOptions->sel[MENUITEM_THEME] == 2)
    //    gSaveBlock2Ptr->optionsWindowFrameType = 0;
    //else
    gSaveBlock2Ptr->optionsWindowFrameType = sOptions->sel[MENUITEM_FRAMETYPE];

    VarSet(VAR_OPTIONS_HP_BAR_SPEED, sOptions->sel[MENUITEM_BAR_SPEED]);
    if ((VarGet(VAR_OPTIONS_EXP_BAR_SPEED) > 7) || (VarGet(VAR_OPTIONS_HP_BAR_SPEED) > 7))
    {
        FlagSet(FLAG_RYU_CHANGED_BAR_SPEED);
    }
    if (sOptions->sel[MENUITEM_TRANSITION])
    {
        FlagSet(FLAG_OPTIONS_INSTANT_TRANSITION);
        FlagSet(FLAG_RYU_USED_INSTANT_TRANSITION);
    }
    else
        FlagClear(FLAG_OPTIONS_INSTANT_TRANSITION);

    if (sOptions->sel[MENUITEM_AUTORUN])
        FlagSet(FLAG_RYU_AUTORUN);
    else
        FlagClear(FLAG_RYU_AUTORUN);

    if (sOptions->sel[MENUITEM_VANILLACAP])
    {
        bool32 check = RyuCheckFor100Lv();
        if (check == TRUE)
        {
            FlagSet(FLAG_RYU_VANILLA_CAP);
            FlagSet(FLAG_RYU_NOTIFY_LV100_SWITCH);
            FlagSet(FLAG_RYU_USED_100_CAP);
        }
        else
        {
            FlagSet(FLAG_RYU_FAILED_100_CAP_SWITCH);
        }
    }
    else
        {
            FlagClear(FLAG_RYU_VANILLA_CAP);
        }

    gSaveBlock2Ptr->trainerSlideEnabled = sOptions->sel[MENUITEM_TRAINERSLIDE];
        
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sOptions);
        SetMainCallback2(gMain.savedCallback);
    }
}

static void HighlightOptionMenuItem(int cursor)
{
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 40, cursor * Y_DIFF + 56));
}

// Process Input functions
static int XOptions_ProcessInput(int x, int selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int ThreeOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

static int FourOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

static int ElevenOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(11, selection);
}

static int TwoOptions_ProcessInput(int selection)
{
    if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int Sound_ProcessInput(int selection)
{
    return selection;
}

//FULL_COLOR
static int ThemeUI_ProcessInput(int selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < 2)
            selection++;
        else
            selection = 0;

    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

    }
    return selection;
}

//FULL_COLOR
static int Theme_ProcessInput(int selection)
{
    u16 pal;
    u16 buf[0x20];
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < 3)
            selection++;
        else
            selection = 0;

    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = 3;

    }
    switch (selection) {
        case THEME_COLOR_LIGHT:
        case THEME_COLOR_VANILLA:
            LoadPalette(sUnknown_0855C604, 0x10, sizeof(sUnknown_0855C604));
            LoadBgTiles(1, GetWindowFrameLightTilesPal(sOptions->sel[MENUITEM_FRAMETYPE])->tiles, 0x120, 0x1A2);
            LoadPalette(GetWindowFrameLightTilesPal(sOptions->sel[MENUITEM_FRAMETYPE])->pal, 0x70, 0x20);
            break;
        case THEME_COLOR_DARK:
            CpuCopy16(sUnknown_0855C604, buf, sizeof(sUnknown_0855C604));
            buf[1] = RGB(3, 3, 3);
            buf[6] = RGB(26, 26, 25);
            buf[7] = RGB(9, 9, 9);
            LoadPalette(buf, 0x10, sizeof(sUnknown_0855C604));
            LoadBgTiles(1, GetWindowFrameDarkTilesPal(sOptions->sel[MENUITEM_FRAMETYPE])->tiles, 0x120, 0x1A2);
            LoadPalette(GetWindowFrameDarkTilesPal(sOptions->sel[MENUITEM_FRAMETYPE])->pal, 0x70, 0x20);
            break;
        case THEME_COLOR_USER:
            CpuCopy16(sUnknown_0855C604, buf, sizeof(sUnknown_0855C604));
            buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];
            LoadPalette(buf, 0x10, sizeof(sUnknown_0855C604));
            LoadBgTiles(1, GetWindowFrameUserTilesPal(sOptions->sel[MENUITEM_FRAMETYPE])->tiles, 0x120, 0x1A2);
            CpuCopy16(GetWindowFrameUserTilesPal(sOptions->sel[MENUITEM_FRAMETYPE])->pal, buf, 0x20);
            buf[14] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];
            if (sOptions->sel[MENUITEM_FRAMETYPE] == 0) {
                buf[3] = COLOR_AUTO_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER], THRESHOLD_DEFAULT);
                buf[5] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];
                buf[13] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];
            }
            LoadPalette(buf, 0x70, 0x20);
            DrawChoices(sOptions->menuCursor+1, (sOptions->visibleCursor + 1) * Y_DIFF, 0);
            break;
    }
    return selection;
}

static int FrameType_ProcessInput(int selection)
{
    u16 buf[0x20];
    const struct TilesPal * frame;
    //if(sOptions->sel[MENUITEM_THEME] == 2) return selection;
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;
    }
    switch (sOptions->sel[MENUITEM_THEME]) {
        case THEME_COLOR_LIGHT:
        case THEME_COLOR_VANILLA:
            frame = GetWindowFrameLightTilesPal(selection);
            CpuCopy16(frame->pal, buf, 0x20);
            break;
        case THEME_COLOR_DARK:
            frame = GetWindowFrameDarkTilesPal(selection);
            CpuCopy16(frame->pal, buf, 0x20);
            break;
        case THEME_COLOR_USER:
            frame = GetWindowFrameUserTilesPal(selection);
            CpuCopy16(frame->pal, buf, 0x20);
            buf[14] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];
            if (selection == 0) {
                buf[3] = COLOR_AUTO_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER], THRESHOLD_DEFAULT);
                buf[5] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];
                buf[13] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];
            }
            break;
    }
    LoadBgTiles(1, frame->tiles, 0x120, 0x1A2);
    LoadPalette(buf, 0x70, 0x20);
    return selection;
}

static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

//FULL_COLOR
static void GetMiddleX1X2(const u8 *txt1, const u8 *txt2, const u8 *txt3, const u8 *txt4, u8* x1, u8* x2)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid1 = GetStringWidth(1, txt2, 0);
    int widthMid2 = GetStringWidth(1, txt3, 0);
    int widthRight = GetStringWidth(1, txt4, 0);
    
    xMid = (198 - widthRight - widthLeft - 78) / 2 + 78 + widthLeft;
    *x1 = (xMid - widthLeft - 78 - widthMid1) * 2 / 3 + 78 + widthLeft;
    *x2 = (198 - widthRight - xMid - widthMid2) / 3 + xMid;
}

// Draw Choices functions
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, u8 textSpeed)
{
    u8 dst[16];
    u32 i;

    for (i = 0; *text != EOS && i <= 14; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = 4;
        dst[5] = 5;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, 1, dst, x, y + 1, textSpeed, NULL);
}

static void HpBar_DrawChoices(int selection, int y, u8 textSpeed)
{
    if (selection < 10)
    {
        u8 textPlus[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}+1{0x77}{0x77}{0x77}{0x77}{0x77}"); // 0x77 is to clear INSTANT text
        textPlus[7] = CHAR_0 + selection;
        DrawOptionMenuChoice(textPlus, 104, y, 1, textSpeed);
    }
    else
    {
        DrawOptionMenuChoice(sText_Instant, 104, y, 1, textSpeed);
    }
}

static void BattleScene_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOn, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(1, gText_BattleSceneOff, 198), y, styles[1], textSpeed);
}

static void VanillaCap_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOff, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_BattleSceneOn, GetStringRightAlignXOffset(1, gText_BattleSceneOn, 198), y, styles[1], textSpeed);
}

static void ToggleAutoRun_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOff, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_BattleSceneOn, GetStringRightAlignXOffset(1, gText_BattleSceneOn, 198), y, styles[1], textSpeed);
}

//FULL_COLOR
static void ThemeUISelection_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[3] = {0};    
    int xMid = GetMiddleX(gText_UiThemeModern, gText_UiThemeClassic, gText_UiThemeVanilla);
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_UiThemeModern, 78, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_UiThemeClassic, xMid-(104-78)/2, y, styles[1], textSpeed);
    DrawOptionMenuChoice(gText_UiThemeVanilla, GetStringRightAlignXOffset(1, gText_UiThemeVanilla, 198), y, styles[2], textSpeed);
}
//FULL_COLOR
static void ThemeSelection_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[4] = {0};
    u8 x1, x2;
    GetMiddleX1X2(gText_UiThemeLight, gText_UiThemeDark, gText_UiThemeUser, gText_UiThemeVanilla, &x1, &x2);

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_UiThemeLight, 78, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_UiThemeDark, x1, y, styles[1], textSpeed);
    DrawOptionMenuChoice(gText_UiThemeUser, x2, y, styles[2], textSpeed);
    DrawOptionMenuChoice(gText_UiThemeVanilla, GetStringRightAlignXOffset(1, gText_UiThemeVanilla, 198), y, styles[3], textSpeed);
}

static void Transition_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_TransitionStyleNormal, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_TransitionStyleInstant, GetStringRightAlignXOffset(1, gText_TransitionStyleInstant, 198), y, styles[1], textSpeed);
}


static void FourOptions_DrawChoices(const u8 *const *const strings, int selection, int y, u8 textSpeed)
{
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {1, 2, 3},
        {1, 2, 3},
    };
    u8 styles[4] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];

    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 104, y, 26 * 8 - 104, Y_DIFF);
    CopyWindowToVram(WIN_OPTIONS, 2);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], textSpeed);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], textSpeed);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], textSpeed);
}

static void TextSpeed_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(gText_TextSpeedSlow, gText_TextSpeedMid, gText_TextSpeedFast);

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_TextSpeedMid, xMid, y, styles[1], textSpeed);
    DrawOptionMenuChoice(gText_TextSpeedFast, GetStringRightAlignXOffset(1, gText_TextSpeedFast, 198), y, styles[2], textSpeed);
}


static void RandomMusic_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_SoundMono, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(1, gText_SoundStereo, 198), y, styles[1], textSpeed);
}

static void FrameType_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 text[16];
    u32 n = selection + 1;
    u32 i = 0;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = 0x77;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, y, 0, textSpeed);
    DrawOptionMenuChoice(text, 128, y, 1, textSpeed);
}

static void DrawTextOption(void)
{
    FillWindowPixelBuffer(WIN_TEXT_OPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_TEXT_OPTION, 1, gText_Option, 8, 1, 0, NULL);
    CopyWindowToVram(WIN_TEXT_OPTION, 3);
}

static void ForceBattleSet_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(sText_Dynamic, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(sText_Set, GetStringRightAlignXOffset(1, sText_Set, 198), y, styles[1], textSpeed);
}

static void TrainerSlide_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOff, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_BattleSceneOn, GetStringRightAlignXOffset(1, gText_BattleSceneOn, 198), y, styles[1], textSpeed);
}

static void DrawOptionMenuTexts(void)
{
    u32 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < 7; i++)
        AddTextPrinterParameterized(WIN_OPTIONS, 1, sOptionMenuItemsNames[i], 8, (i * Y_DIFF) + 1, 0, NULL);

    CopyWindowToVram(WIN_OPTIONS, 3);
}

static void sub_80BB154(void)
{
    //                   bg, tileNum, x,    y,    width, height,  pal
    FillBgTilemapBufferRect(1, 0x1A2, 1,    0,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A3, 2,    0,      0x1B,   1,      7);
    FillBgTilemapBufferRect(1, 0x1A4, 28,   0,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A5, 1,    1,      1,      2,      7);
    FillBgTilemapBufferRect(1, 0x1A7, 28,   1,      1,      2,      7);
    FillBgTilemapBufferRect(1, 0x1A8, 1,    3,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A9, 2,    3,      0x1B,   1,      7);
    FillBgTilemapBufferRect(1, 0x1AA, 28,   3,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A2, 1,    4,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A3, 2,    4,      0x1A,   1,      7);
    FillBgTilemapBufferRect(1, 0x1A4, 28,   4,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A5, 1,    5,      1,      0x12,   7);
    FillBgTilemapBufferRect(1, 0x1A7, 28,   5,      1,      0x12,   7);
    FillBgTilemapBufferRect(1, 0x1A8, 1,    19,     1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A9, 2,    19,     0x1A,   1,      7);
    FillBgTilemapBufferRect(1, 0x1AA, 28,   19,     1,      1,      7);

    CopyBgTilemapBufferToVram(1);
}
