#include "global.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "frontier_pass.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "link.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokenav.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "window.h"
#include "constants/songs.h"
#include "union_room.h"
#include "dexnav.h"
#include "constants/rgb.h"
#include "field_message_box.h"
#include "constants/event_objects.h"
#include "rtc.h"
#include "ach_atlas.h"
#include "gba/m4a_internal.h"
#include "RyuRealEstate.h"
#include "overworld_notif.h"
#include "wild_encounter.h"
#include "start_menu_helper.h"

extern u8 RyuDebugMenuScript[];
extern u8 RyuStartMenuConfigInfoScript[];
extern const u8 gText_RyuVersion[];

// Menu actions
enum
{
    MENU_ACTION_DEXNAV,
    MENU_ACTION_POKEDEX,
    MENU_ACTION_POKEMON,
    MENU_ACTION_BAG,
    MENU_ACTION_POKENAV,
    MENU_ACTION_PLAYER,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTION,
    MENU_ACTION_EXIT,
    MENU_ACTION_PLAYER_LINK,
    MENU_ACTION_REST_FRONTIER,
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG,
};

// Save status
enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

// IWRAM common
bool8 (*gMenuCallback)(void);

// EWRAM
EWRAM_DATA static u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA static u8 sStartMenuCursorPos = 0;
EWRAM_DATA static u8 sNumStartMenuActions = 0;
EWRAM_DATA static u8 sCurrentStartMenuActions[9] = {0};
EWRAM_DATA static u8 sInitStartMenuData[2] = {0};
EWRAM_DATA static u8 sStartMenuActionSpriteIds[16] = {0};

EWRAM_DATA static u8 (*sSaveDialogCallback)(void) = NULL;
EWRAM_DATA static u8 sSaveDialogTimer = 0;
EWRAM_DATA static bool8 sSavingComplete = FALSE;
EWRAM_DATA static u8 sSaveInfoWindowId = 0;

// Menu action callbacks
static bool8 StartMenuPokedexCallback(void);
static bool8 StartMenuPokemonCallback(void);
static bool8 StartMenuBagCallback(void);
static bool8 StartMenuPokeNavCallback(void);
static bool8 StartMenuJournalCallback(void);
static bool8 StartMenuPlayerNameCallback(void);
static bool8 StartMenuSaveCallback(void);
static bool8 StartMenuOptionCallback(void);
static bool8 StartMenuExitCallback(void);
static bool8 StartMenuLinkModePlayerNameCallback(void);
static bool8 StartMenuBattlePyramidRetireCallback(void);
static bool8 StartMenuBattlePyramidBagCallback(void);
static bool8 StartMenuDexNavCallback(void);
static bool8 StartMenuAtlasCallback(void);

// Menu callbacks
static bool8 SaveStartCallback(void);
static bool8 SaveCallback(void);
static bool8 BattlePyramidRetireStartCallback(void);
static bool8 BattlePyramidRetireReturnCallback(void);
static bool8 BattlePyramidRetireCallback(void);
static bool8 HandleStartMenuInput(void);
// Save dialog callbacks
static u8 SaveConfirmSaveCallback(void);
static u8 SaveYesNoCallback(void);
static u8 SaveConfirmInputCallback(void);
static u8 SaveFileExistsCallback(void);
static u8 SaveConfirmOverwriteDefaultNoCallback(void);
static u8 SaveConfirmOverwriteCallback(void);
static u8 SaveOverwriteInputCallback(void);
static u8 SaveSavingMessageCallback(void);
static u8 SaveDoSaveCallback(void);
static u8 SaveSuccessCallback(void);
static u8 SaveReturnSuccessCallback(void);
static u8 SaveErrorCallback(void);
static u8 SaveReturnErrorCallback(void);
static u8 BattlePyramidConfirmRetireCallback(void);
static u8 BattlePyramidRetireYesNoCallback(void);
static u8 BattlePyramidRetireInputCallback(void);

// Task callbacks
static void StartMenuTask(u8 taskId);
static void SaveGameTask(u8 taskId);
static void Task_SaveAfterLinkBattle(u8 taskId);
static void Task_WaitForBattleTowerLinkSave(u8 taskId);
static bool8 FieldCB_ReturnToFieldStartMenu(void);

extern int CountBadges();

static const u8 *const sPyramindFloorNames[] =
    {
        gText_Floor1,
        gText_Floor2,
        gText_Floor3,
        gText_Floor4,
        gText_Floor5,
        gText_Floor6,
        gText_Floor7,
        gText_Peak};

static const struct WindowTemplate sPyramidFloorWindowTemplate_2 = {0, 1, 15, 0xA, 4, 0xF, 8};
static const struct WindowTemplate sPyramidFloorWindowTemplate_1 = {0, 1, 15, 0xC, 4, 0xF, 8};

const u8 sText_PlayTime[] = _("Play Time: ");

const u16 gStartMenuButton_Bag[] = INCBIN_U16("graphics/start_menu/start_icon_bag.4bpp");
const u16 gStartMenuButton_Dexnav[] = INCBIN_U16("graphics/start_menu/start_icon_dexnav.4bpp");
const u16 gStartMenuButton_Empty[] = INCBIN_U16("graphics/start_menu/start_icon_empty.4bpp");
const u16 gStartMenuButton_Error[] = INCBIN_U16("graphics/start_menu/start_icon_error.4bpp");
const u16 gStartMenuButton_Journal[] = INCBIN_U16("graphics/start_menu/start_icon_journal.4bpp");
const u16 gStartMenuButton_Options[] = INCBIN_U16("graphics/start_menu/start_icon_options.4bpp");
const u16 gStartMenuButton_Pokedex[] = INCBIN_U16("graphics/start_menu/start_icon_pokedex.4bpp");
const u16 gStartMenuButton_Pokemon[] = INCBIN_U16("graphics/start_menu/start_icon_pokemon.4bpp");
const u16 gStartMenuButton_Pokenav[] = INCBIN_U16("graphics/start_menu/start_icon_pokenav.4bpp");
const u16 gStartMenuButton_Save[] = INCBIN_U16("graphics/start_menu/start_icon_save.4bpp");
const u16 gStartMenuButtonPal[] = INCBIN_U16("graphics/start_menu/start_icon.gbapal");

const struct SpriteFrameImage gStartMenuButtonImages_Bag[] = 
{
    {gStartMenuButton_Bag, 0x200},
    {gStartMenuButton_Bag+0x100, 0x200},
};

const struct SpriteFrameImage gStartMenuButtonImages_Dexnav[] = 
{
    {gStartMenuButton_Dexnav, 0x200},
    {gStartMenuButton_Dexnav+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Empty[] = 
{
    {gStartMenuButton_Empty, 0x200},
    {gStartMenuButton_Empty+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Error[] = 
{
    {gStartMenuButton_Error, 0x200},
    {gStartMenuButton_Error+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Journal[] = 
{
    {gStartMenuButton_Journal, 0x200},
    {gStartMenuButton_Journal+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Options[] = 
{
    {gStartMenuButton_Options, 0x200},
    {gStartMenuButton_Options+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Pokedex[] = 
{
    {gStartMenuButton_Pokedex, 0x200},
    {gStartMenuButton_Pokedex+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Pokemon[] = 
{
    {gStartMenuButton_Pokemon, 0x200},
    {gStartMenuButton_Pokemon+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Pokenav[] = 
{
    {gStartMenuButton_Pokenav, 0x200},
    {gStartMenuButton_Pokenav+0x100, 0x200},
};
const struct SpriteFrameImage gStartMenuButtonImages_Save[] = 
{
    {gStartMenuButton_Save, 0x200},
    {gStartMenuButton_Save+0x100, 0x200},
};
struct StartMenuAction
{
    const struct SpriteFrameImage *image;
    const u8 *text;
    union {
        void (*void_u8)(u8);
        u8 (*u8_void)(void);
    } func;
};

static const struct StartMenuAction sStartMenuItems[] =
    {
        {gStartMenuButtonImages_Dexnav, gText_MenuDexNav, {.u8_void = StartMenuDexNavCallback}},
        {gStartMenuButtonImages_Pokedex, gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
        {gStartMenuButtonImages_Pokemon, gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
        {gStartMenuButtonImages_Bag, gText_MenuBag, {.u8_void = StartMenuBagCallback}},
        {gStartMenuButtonImages_Pokenav, gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
        {gStartMenuButtonImages_Journal, gText_MenuJournal, {.u8_void = StartMenuJournalCallback}},
        {gStartMenuButtonImages_Save, gText_MenuSave, {.u8_void = StartMenuSaveCallback}},
        {gStartMenuButtonImages_Options, gText_MenuOption, {.u8_void = StartMenuOptionCallback}},
        {gStartMenuButtonImages_Empty, gText_MenuExit, {.u8_void = StartMenuExitCallback}},
        {gStartMenuButtonImages_Empty, gText_MenuPlayer, {.u8_void = StartMenuLinkModePlayerNameCallback}},
        {gStartMenuButtonImages_Empty, gText_MenuRest, {.u8_void = StartMenuSaveCallback}},
        {gStartMenuButtonImages_Empty, gText_MenuRetire, {.u8_void = StartMenuBattlePyramidRetireCallback}},
        {gStartMenuButtonImages_Bag, gText_MenuBag, {.u8_void = StartMenuBattlePyramidBagCallback}}};

static const struct BgTemplate sUnknown_085105A8[] =
    {
        {.bg = 0,
         .charBaseIndex = 2,
         .mapBaseIndex = 31,
         .screenSize = 0,
         .paletteMode = 0,
         .priority = 0,
         .baseTile = 0}};

static const struct WindowTemplate sUnknown_085105AC[] =
    {
        {0, 2, 0xF, 0x1A, 4, 0xF, 0x194},
        DUMMY_WIN_TEMPLATE};

static const struct WindowTemplate sSaveInfoWindowTemplate = {0, 1, 1, 0xF, 0xA, 0xF, 8};

// Local functions
static void BuildStartMenuActions(void);
static void AddStartMenuAction(u8 action);
static void BuildNormalStartMenu(void);
static void BuildLinkModeStartMenu(void);
static void BuildUnionRoomStartMenu(void);
static void BuildBattlePikeStartMenu(void);
static void BuildBattlePyramidStartMenu(void);
static void BuildMultiPartnerRoomStartMenu(void);
static void BuildDexnavStartMenu(void);
static void ShowPyramidFloorWindow(void);
static void RemoveExtraStartMenuWindows(void);
static bool32 PrintStartMenuActions(s8 *pIndex, u32 count);
static bool32 InitStartMenuStep(void);
static void InitStartMenu(void);
static void CreateStartMenuTask(TaskFunc followupFunc);
static void InitSave(void);
static u8 RunSaveCallback(void);
static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void));
static void sub_80A0014(void);
static void HideSaveInfoWindow(void);
static void SaveStartTimer(void);
static bool8 SaveSuccesTimer(void);
static bool8 SaveErrorTimer(void);
static void InitBattlePyramidRetire(void);
static void sub_80A03D8(void);
static bool32 InitSaveWindowAfterLinkBattle(u8 *par1);
static void CB2_SaveAfterLinkBattle(void);
static void ShowSaveInfoWindow(void);
static void RemoveSaveInfoWindow(void);
static void HideStartMenuWindow(void);
void RemoveInfoBoxWindow(void);
static void PrintActionName(u32);

void SetDexPokemonPokenavFlags(void) // unused
{
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_SYS_POKEMON_GET);
    FlagSet(FLAG_SYS_POKENAV_GET);
}

bool8 PlayerHasDexnav(void)
{
    if (FlagGet(FLAG_SYS_DEXNAV_GET) == 1)
        return TRUE;
}

static void BuildStartMenuActions(void)
{
    sNumStartMenuActions = 0;

    if (IsUpdateLinkStateCBActive() == TRUE)
    {
        BuildLinkModeStartMenu();
    }
    else if (InUnionRoom() == TRUE)
    {
        BuildUnionRoomStartMenu();
    }
    else if (InBattlePike())
    {
        BuildBattlePikeStartMenu();
    }
    else if (InBattlePyramid())
    {
        BuildBattlePyramidStartMenu();
    }
    else if (InMultiPartnerRoom())
    {
        BuildMultiPartnerRoomStartMenu();
    }
    else if (PlayerHasDexnav())
    {
        BuildDexnavStartMenu();
    }
    else
    {
        BuildNormalStartMenu();
    }
}

static void AddStartMenuAction(u8 action)
{
    AppendToList(sCurrentStartMenuActions, &sNumStartMenuActions, action);
}

static void BuildNormalStartMenu(void)
{
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);

    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
    {
        if (!(CalculatePlayerPartyCount() == 0))
            AddStartMenuAction(MENU_ACTION_POKEMON);
    }

    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        if (!(CalculatePlayerPartyCount() == 0))
        {
            AddStartMenuAction(MENU_ACTION_POKENAV);
        }
    }

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildDexnavStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_DEXNAV);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);

    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
    {
        if (!(CalculatePlayerPartyCount() == 0))
            AddStartMenuAction(MENU_ACTION_POKEMON);
    }

    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        if (!(CalculatePlayerPartyCount() == 0))
        {
            AddStartMenuAction(MENU_ACTION_POKENAV);
        }
    }

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildLinkModeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildUnionRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildBattlePikeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildBattlePyramidStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PYRAMID_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_REST_FRONTIER);
    AddStartMenuAction(MENU_ACTION_RETIRE_FRONTIER);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildMultiPartnerRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void ShowPyramidFloorWindow(void)
{
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum == 7)
        sBattlePyramidFloorWindowId = AddWindow(&sPyramidFloorWindowTemplate_1);
    else
        sBattlePyramidFloorWindowId = AddWindow(&sPyramidFloorWindowTemplate_2);

    PutWindowTilemap(sBattlePyramidFloorWindowId);
    DrawStdWindowFrame(sBattlePyramidFloorWindowId, FALSE);
    StringCopy(gStringVar1, sPyramindFloorNames[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
    StringExpandPlaceholders(gStringVar4, gText_BattlePyramidFloor);
    AddTextPrinterParameterized(sBattlePyramidFloorWindowId, 1, gStringVar4, 0, 1, 0xFF, NULL);
    CopyWindowToVram(sBattlePyramidFloorWindowId, 2);
}

static void RemoveExtraStartMenuWindows(void)
{
    if (InBattlePyramid())
    {
        ClearStdWindowAndFrameToTransparent(sBattlePyramidFloorWindowId, FALSE);
        RemoveWindow(sBattlePyramidFloorWindowId);
    }
    RemoveInfoBoxWindow();
}

EWRAM_DATA static u8 sPrintNumberWindowId = 1;
EWRAM_DATA static u8 sPrintNumberWindow2Id = 2;
EWRAM_DATA static u8 sActionNameWindowId = 0;
const u8 gText_RyuLifeSkills[] = _("Skills    ");
const u8 gText_RyuMiningSkillPrefix[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE} M:{COLOR DARK_GREY}{SHADOW LIGHT_GREY}");
const u8 gText_RyuBotanySkillPrefix[] = _("{COLOR LIGHT_GREEN}{SHADOW GREEN} B:{COLOR DARK_GREY}{SHADOW LIGHT_GREY}");
const u8 gText_RyuAlchemySkillPrefix[] = _("{COLOR LIGHT_RED}{SHADOW RED} A:{COLOR DARK_GREY}{SHADOW LIGHT_GREY}");
const u8 gText_SomeSpaces[] = _("  ");

void AddInfoBoxWindow(void)
{
    struct WindowTemplate template;
    int Time = (RyuGetTimeOfDay());

    // prepare window
    SetWindowTemplateFields(&template, 0, -1, 15, 32, 3, 15, 106);
    sPrintNumberWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sPrintNumberWindowId, 0);
    PutWindowTilemap(sPrintNumberWindowId);
    DrawStdFrameWithCustomTileAndPalette(sPrintNumberWindowId, FALSE, 0x214, 14);
    sPrintNumberWindow2Id = 0xFF;
}
extern const u8 sText_Colon[];

void PrintNumberToScreen(s32 num)
{
    int Time = (RyuGetTimeOfDay());

    // song readout
    StringCopy(gStringVar1, gText_HighlightTransparent);
    StringAppend(gStringVar1, gText_ryuJukeboxLabel);
    if (gSaveBlock2Ptr->disableBGM == TRUE)
    {
        StringAppend(gStringVar1, (const u8[])_("{COLOR LIGHT_RED}{SHADOW RED}BGM Off"));
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar2, num, 0, 3);
        StringAppend(gStringVar1, gStringVar2);
    }
    if ((FlagGet(FLAG_RYU_RANDOMIZE_MUSIC) == TRUE) && (gSaveBlock2Ptr->disableBGM == FALSE))
        StringAppend(gStringVar1, (const u8[])_("{COLOR LIGHT_RED}{SHADOW BLUE}(R)"));
    if ((FlagGet(FLAG_RYU_JUKEBOX_ENABLED) == TRUE) && (gSaveBlock2Ptr->disableBGM == FALSE))
        StringAppend(gStringVar1, (const u8[])_("{COLOR LIGHT_GREEN}{SHADOW BLUE}(J)"));

    // playtime readout
    StringCopy(gRyuStringVar1, sText_PlayTime);
    ConvertIntToDecimalStringN(gRyuStringVar2, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gRyuStringVar1, gRyuStringVar2);
    StringAppend(gRyuStringVar1, sText_Colon);
    ConvertIntToDecimalStringN(gRyuStringVar2, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gRyuStringVar1, gRyuStringVar2);
    StringAppend(gRyuStringVar1, sText_Colon);
    ConvertIntToDecimalStringN(gRyuStringVar2, gSaveBlock2Ptr->playTimeSeconds, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gRyuStringVar1, gRyuStringVar2);
    AddTextPrinterParameterized(sPrintNumberWindowId, 0, gRyuStringVar1, 106, 12, 0xFF, NULL);//play time

    // time readout
    RtcCalcLocalTime();
    StringCopy(gStringVar3, gText_HighlightTransparent);
    StringAppend(gStringVar3, gText_SpaceTime);
    ConvertIntToDecimalStringN(gStringVar2, gLocalTime.hours, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringAppend(gStringVar3, gStringVar2);
    StringAppend(gStringVar3, gText_colon);
    ConvertIntToDecimalStringN(gStringVar2, gLocalTime.minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gStringVar3, gStringVar2);
    StringAppend(gStringVar3, gText_ThisIsAPokemon);
    StringAppend(gStringVar3, gText_SomeSpaces);
    // print 'day', 'dusk', 'night' or 'dawn' in reference to evolution

    if (Time == RTC_TIME_NIGHT)
    {

        StringAppend(gStringVar3, gText_ColorLightBlueShadowBlue);
        StringAppend(gStringVar3, gText_Night);
    }
    else if (Time == RTC_TIME_EVENING)
    {
        StringAppend(gStringVar3, gText_ColorLightBlueShadowDarkGrey);
        StringAppend(gStringVar3, gText_Dusk);
    }
    else if (Time == RTC_TIME_MORNING)
    {
        StringAppend(gStringVar3, gText_ColorLightRedShadowDarkGrey);
        StringAppend(gStringVar3, gText_RyuDawn);
    }
    else
    {
        StringAppend(gStringVar3, gText_ColorLightRedShadowRed);
        StringAppend(gStringVar3, gText_RyuDay);
    }

    switch(VarGet(VAR_RYU_GAME_MODE))
    {
        case 0:
            StringCopy(gRyuStringVar1, (const u8[])_("Easy Mode"));
            break;
        case 1:
        {
            if (FlagGet(FLAG_RYU_DOING_RYU_CHALLENGE) == TRUE)
            {
                StringCopy(gRyuStringVar1, (const u8[])_("Normal{COLOR LIGHT_RED}{SHADOW RED}(RC)"));
                break;
            }
            else
            {
                StringCopy(gRyuStringVar1, (const u8[])_("Normal Mode"));
                break;
            }
        }
        case 2:
            StringCopy(gRyuStringVar1, (const u8[])_("{COLOR LIGHT_RED}{SHADOW RED}Challenge Mode"));
            break;
        case 3:
            StringCopy(gRyuStringVar1, (const u8[])_("{COLOR LIGHT_RED}{SHADOW LIGHT_GREY}HARDCORE Mode"));
            break;
        case 4:
            StringCopy(gRyuStringVar1, (const u8[])_("{COLOR LIGHT_GREEN}{SHADOW GREEN}Frontier Mode"));
            break;
    }
    AddTextPrinterParameterized(sPrintNumberWindowId, 0, gRyuStringVar1, 152, 0, 0xFF, NULL);

    // print version number
    StringCopy(gStringVar2, gText_RyuVersion);
    ConvertIntToDecimalStringN(gStringVar4, VarGet(VAR_LAST_KNOWN_GAME_VERSION), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gStringVar2, gStringVar4);

    // print all text
    AddTextPrinterParameterized(sPrintNumberWindowId, 0, gStringVar1, 10, 0, 0xFF, NULL); // song data
    AddTextPrinterParameterized(sPrintNumberWindowId, 0, gStringVar2, 106, 0, 0xFF, NULL); //version number
    AddTextPrinterParameterized(sPrintNumberWindowId, 0, gStringVar3, 10, 12, 0xFF, NULL); //rtc time

}

void RemoveInfoBoxWindow(void)
{
    if(sPrintNumberWindowId != 0xFF) {
        ClearStdWindowAndFrameToTransparent(sPrintNumberWindowId, FALSE);
        RemoveWindow(sPrintNumberWindowId);
        sPrintNumberWindowId = 0xFF;
    }
    if (sPrintNumberWindow2Id != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(sPrintNumberWindow2Id, FALSE);
        RemoveWindow(sPrintNumberWindow2Id);
        sPrintNumberWindow2Id = 0xFF;
    }

}

void PrintSongNumber(u16 song)
{
    PrintNumberToScreen(song);
}

static bool32 PrintStartMenuActions(s8 *pIndex, u32 count)
{
    s8 index = *pIndex;

    do
    {
        {
            StringExpandPlaceholders(gStringVar4, sStartMenuItems[sCurrentStartMenuActions[index]].text);
            AddTextPrinterParameterized(GetStartMenuWindowId(), 1, gStringVar4, 8, (index << 4) + 9, 0xFF, NULL);
        }

        index++;
        if (index >= sNumStartMenuActions)
        {
            *pIndex = index;
            return TRUE;
        }

        count--;
    } while (count != 0);

    *pIndex = index;
    return FALSE;
}

const struct SpritePalette sStartMenuButtonPalette =
{
    .data = gStartMenuButtonPal,
    .tag = 0x1400
};

static const struct OamData sStartMenuButtonOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0,
};

static const union AnimCmd sButtonNormalAnimation[] = {
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sButtonGlowAnimation[] = {
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sButtonAnims[] =
{
    sButtonNormalAnimation,
    sButtonGlowAnimation
};

static const union AffineAnimCmd sUnselectAffineAnim[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    //AFFINEANIMCMD_FRAME(-0x8, -0x8, 0, 4),
    //AFFINEANIMCMD_FRAME(-0x10, -0x10, 0, 2),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSelectAffineAnim[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -2, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 3),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 3),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 2, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSelectLeftAffineAnim[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 2, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 3),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 3),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -2, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSelectedAffineAnim[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sNotSelectedAffineAnim[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sButtonAffineAnims[] =
{
    sNotSelectedAffineAnim,
    sUnselectAffineAnim,
    sSelectAffineAnim,
    sSelectedAffineAnim,
    sSelectLeftAffineAnim,
};

const struct SpriteTemplate sStartMenuButtonTemplate =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1400,
    .oam = &sStartMenuButtonOam,
    .anims = sButtonAnims,
    .images = NULL,
    .affineAnims = sButtonAffineAnims,
    .callback = SpriteCallbackDummy
};

// ! Don't call this before window id variables are initialized or whatever
static void CleanupStartMenuElements(void) 
{
    int i;
    for(i = 0; i < sNumStartMenuActions; i++) 
    {
        struct Sprite * sprite = &gSprites[sStartMenuActionSpriteIds[i]];
        DestroySpriteAndFreeResources(sprite);
        LoadOam();
        //sStartMenuActionSpriteIds[i] = 0xFF;
    }
    SetGpuReg(REG_OFFSET_WIN1H, 0xFFFF);
    SetGpuReg(REG_OFFSET_WIN1V, 0xFFFF);
    ClearStdWindowAndFrameToTransparent(sActionNameWindowId, TRUE);
    //ClearWindowTilemap(sActionNameWindowId);
    //FillWindowPixelBuffer(sActionNameWindowId, 0);
    //CopyWindowToVram(sActionNameWindowId, 3);
    RemoveWindow(sActionNameWindowId);
    sActionNameWindowId = 0xFF;
}

void WindowFunc_DrawStartMenuFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum);

static bool32 InitStartMenuStep(void)
{
    s8 state = sInitStartMenuData[0];
    int i;
    switch (state)
    {
    case 0:
        sInitStartMenuData[0]++;
        break;
    case 1:
        BuildStartMenuActions();
        sInitStartMenuData[0]++;
        break;
    case 2:

        LoadMessageBoxAndBorderGfx();
        //DrawStdWindowFrame(sub_81979C4(sNumStartMenuActions), FALSE);
        sInitStartMenuData[1] = 0;
        sInitStartMenuData[0]++;
        break;
    case 3:
        sPrintNumberWindowId = 0xFF;
        sPrintNumberWindow2Id = 0xFF;
        if (InBattlePyramid()) {
            ShowPyramidFloorWindow();
        }
        else {
            AddInfoBoxWindow();
            if (FlagGet(FLAG_RYU_JUKEBOX_ENABLED) == 1)
                PrintSongNumber(VarGet(VAR_RYU_JUKEBOX));
            else
                PrintSongNumber(GetCurrentMapMusic());
            CopyWindowToVram(sPrintNumberWindowId, 3);
            DrawTeamLogo();
        }
        sInitStartMenuData[0]++;
        break;
    case 4:{
        // TODO: having a window this big is wasteful but it works right now
        // change it so that it just adds a proper backdrop and border or something later
        struct WindowTemplate * actionNameTemplate = &(struct WindowTemplate){0, 0, 1, 30, 6, 15, 0x114};
        sActionNameWindowId = AddWindow(actionNameTemplate);
        //PutWindowTilemap(sActionNameWindowId);
        //FillWindowPixelBuffer(sActionNameWindowId, PIXEL_FILL(1));
        //DrawStdFrameWithCustomTileAndPalette(sActionNameWindowId, FALSE, 0x214, 14);
        //DrawStdWindowFrame(sActionNameWindowId, FALSE);
        CallWindowFunction(sActionNameWindowId, WindowFunc_DrawStartMenuFrame);
        FillWindowPixelBuffer(sActionNameWindowId, PIXEL_FILL(1));
        PutWindowTilemap(sActionNameWindowId);
        CopyWindowToVram(sActionNameWindowId, 3);
        SetGpuReg(REG_OFFSET_WIN1H, 0xFF);
        SetGpuReg(REG_OFFSET_WIN1V, 0x23C);
        sInitStartMenuData[0]++;
        break;
        }
    case 5:
        {
            int spacingX = 30;
            int width = sNumStartMenuActions * spacingX;
            int offsetY = 16 + 6;
            int offsetX = 16 + (DISPLAY_WIDTH - width) / 2;
            for(i = 0; i < sNumStartMenuActions; i++) 
            {
                u32 spriteId;
                const struct StartMenuAction * item = &sStartMenuItems[sCurrentStartMenuActions[i]];
                struct SpriteTemplate spriteTemplate = sStartMenuButtonTemplate;
                spriteTemplate.images = item->image;
                LoadSpritePalette(&sStartMenuButtonPalette);
                spriteId = CreateSprite(&spriteTemplate, offsetX + spacingX * i, offsetY, 0);
                if(sStartMenuCursorPos == i) {
                    StartSpriteAnim(&gSprites[spriteId], 1);
                    StartSpriteAffineAnim(&gSprites[spriteId], 3);
                }
                sStartMenuActionSpriteIds[i] = spriteId;
            }
            BuildOamBuffer(); // Force resort sprites to mitigate the object priority bug
            PrintActionName(sStartMenuCursorPos);
            sInitStartMenuData[0]++;
            return TRUE;
        }
        case 6:
        {
            return TRUE;
        }
    }
return FALSE;
}

static void InitStartMenu(void)
{
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    while (!InitStartMenuStep())
        ;
}

static void StartMenuTask(u8 taskId)
{
    if (InitStartMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

extern void RyuClearAlchemyEffect(void);

void RyuDoOneTImeSaveFixes(void) {}

bool32 RyuCheckFactionAchievements(void)
{
    u8 count = 0;

    if (CheckAchievement(ACH_THE_EXPLORER) == TRUE)
        count++;

    if (CheckAchievement(ACH_THE_EMPEROR) == TRUE)
        count++;

    if (CheckAchievement(ACH_THE_TRADESMAN) == TRUE)
        count++;

    if (CheckAchievement(ACH_THE_MAGICIAN) == TRUE)
        count++;

    if (CheckAchievement(ACH_THE_GUARDIAN) == TRUE)
        count++;

    if (CheckAchievement(ACH_THE_PROTEGE) == TRUE)
        count++;

    if (CheckAchievement(ACH_THE_WARRIOR) == TRUE)
        count++;

    if (CheckAchievement(ACH_MENTOR) == TRUE)
        count++;

    if (CheckAchievement(ACH_FIELD_MEDIC) == TRUE)
        count++;

    if (CheckAchievement(ACH_UNDERTAKER) == TRUE)
        count++;

    if (count >= 10)
        return TRUE;

    return FALSE;
}

bool32 RyuCheckForAllQuestAchievements(void)
{
    u8 count = 0;

    if (CheckAchievement(ACH_DEJA_VU) == TRUE)
        count++;

    if (CheckAchievement(ACH_FWB) == TRUE)
        count++;

    if (CheckAchievement(ACH_NERD_LOVE) == TRUE)
        count++;

    if (CheckAchievement(ACH_SILENT_STRONG_TYPE) == TRUE)
        count++;

    if (CheckAchievement(ACH_LOST_GIRL) == TRUE)
        count++;

    if (count >= 5)
        return TRUE;

    return FALSE;
}

bool32 RyuCheckForAllExplorationAchievements(void)
{
    u8 count = 0;

    if (CheckAchievement(ACH_WELL_TRAVELLED) == TRUE)
        count++;

    if (CheckAchievement(ACH_NTMO) == TRUE)
        count++;

    if (CheckAchievement(ACH_YOU_DIED) == TRUE)
        count++;

    if (CheckAchievement(ACH_LEAVE_NO_STONE_UNTURNED) == TRUE)
        count++;

    if (CheckAchievement(ACH_POKEMON_MASTER) == TRUE)
        count++;

    if (CheckAchievement(ACH_PLOT_ARMOR) == TRUE)
        count++;

    if (CheckAchievement(ACH_GREEN_THUMB) == TRUE)
        count++;

    if (CheckAchievement(ACH_1337) == TRUE)
        count++;

    if (CheckAchievement(ACH_MASTER_BREEDER) == TRUE)
        count++;

    if (count >= 9)
        return TRUE;

    return FALSE;
}

extern int RyuGetTotalCaughtMons();
extern void TryGiveLeetAch();

static void CreateStartMenuTask(TaskFunc followupFunc)
{
    u8 taskId;

    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    taskId = CreateTask(StartMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, StartMenuTask, followupFunc);
    VarSet(VAR_LAST_KNOWN_GAME_VERSION, EE_GAME_VERSION);
    // This should let me know what the original save file version was, so i can tell if someone used an old save or not.
    if (VarGet(VAR_SAVE_FILE_CREATED_ON_VERSION) == 0)
        VarSet(VAR_SAVE_FILE_CREATED_ON_VERSION, EE_GAME_VERSION);
    VarSet(VAR_RYU_SAVE_VIEWER_ENTRYPOINT, 45454);
    FlagSet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
    if (CheckAchievement(ACH_POKEMON_MASTER) == FALSE)
        if (RyuGetTotalCaughtMons() >= 386)
            GiveAchievement(ACH_POKEMON_MASTER);

    if (CheckAchievement(ACH_THE_UNIVERSALIST) == FALSE)
        if (RyuCheckFactionAchievements() == TRUE)
            GiveAchievement(ACH_THE_UNIVERSALIST);

    if (CheckAchievement(ACH_LOREMASTER) == FALSE)
        if (RyuCheckForAllQuestAchievements() == TRUE)
            GiveAchievement(ACH_LOREMASTER);

    if (CheckAchievement(ACH_TOURIST) == FALSE)
        if (RyuCheckForAllExplorationAchievements() == TRUE)
            GiveAchievement(ACH_TOURIST);

    if ((FlagGet(FLAG_SYS_GAME_CLEAR) == TRUE) && (CheckAchievement(ACH_1337) == FALSE))
        TryGiveLeetAch();
}

static bool8 FieldCB_ReturnToFieldStartMenu(void)
{
    if (InitStartMenuStep() == FALSE)
    {
        return FALSE;
    }

    ReturnToFieldOpenStartMenu();
    return TRUE;
}

void ShowReturnToFieldStartMenu(void)
{
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    gFieldCallback2 = FieldCB_ReturnToFieldStartMenu;
}

void Task_ShowStartMenu(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (InUnionRoom() == TRUE)
            SetUsingUnionRoomStartMenu();

        gMenuCallback = HandleStartMenuInput;
        task->data[0]++;
        break;
    case 1:
        if (gMenuCallback() == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void ShowStartMenu(void)
{
    if (!IsUpdateLinkStateCBActive())
    {
        FreezeObjectEvents();
        sub_808B864();
        sub_808BCF4();
    }

    CreateStartMenuTask(Task_ShowStartMenu);
    ScriptContext2_Enable();
}

void PlayNextTrack(void)
{
    u16 song = (VarGet(VAR_RYU_JUKEBOX));
    PlaySE(SE_PIN);
    PlayBGM(song);
    FillWindowPixelBuffer(sPrintNumberWindowId, PIXEL_FILL(1));
    PrintNumberToScreen(song);
    CopyWindowToVram(sPrintNumberWindowId, 2);
}

extern u8 RyuFollowerSelectNPCScript[];

#define WIN_ACTION_TEXT_MARGIN 2

static void PrintActionName(u32 pos)
{
    struct Sprite * sprite = gSprites + sStartMenuActionSpriteIds[pos];
    u32 action = sCurrentStartMenuActions[pos];
    u32 width = GetStringWidth(1, sStartMenuItems[action].text, 0);
    s32 left = WIN_ACTION_TEXT_MARGIN;
    s32 right = DISPLAY_WIDTH - WIN_ACTION_TEXT_MARGIN;
    s32 x = (right - width)/2;
    s32 y = 4 * 8;
    if(x + width > right) {
        x = right - width;
    } else if(x < left){
        x = left;
    }
    FillWindowPixelBuffer(sActionNameWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(sActionNameWindowId, 1, sStartMenuItems[action].text, x, y, 0xFF, NULL);
    CopyWindowToVram(sActionNameWindowId, 2);
}

static s32 MainMenu_MoveSelectedAction(s32 delta)
{
    s32 newPos;
    struct Sprite * oldSprite;
    struct Sprite * newSprite;
    newPos = sStartMenuCursorPos + delta;
    if(newPos >= sNumStartMenuActions) {
        newPos %= sNumStartMenuActions;
    } else if (newPos < 0){
        newPos = sNumStartMenuActions - abs(newPos) % sNumStartMenuActions;
    }
    oldSprite = gSprites + sStartMenuActionSpriteIds[sStartMenuCursorPos];
    newSprite = gSprites + sStartMenuActionSpriteIds[newPos];
    StartSpriteAnim(oldSprite, 0);
    StartSpriteAffineAnim(oldSprite, 1);
    StartSpriteAnim(newSprite, 1);
    StartSpriteAffineAnim(newSprite, delta > 0 ? 2 : 4); // If going to the right play right shake otherwise left shake
    PrintActionName(newPos);
    return newPos;
}

bool8 DoesCurrentMapHaveEncounters(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF
     && (gWildMonHeaders[headerId].landMonsInfo != NULL
     || gWildMonHeaders[headerId].waterMonsInfo != NULL
     || gWildMonHeaders[headerId].fishingMonsInfo != NULL
     || gWildMonHeaders[headerId].rockSmashMonsInfo != NULL))
        return TRUE;
    else
        return FALSE;
}

bool8 RyuMapIsValidForDexnav(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if ((headerId == 0xFFFF) && (gWildMonHeaders[headerId].landMonsInfo == NULL) && (gWildMonHeaders[headerId].waterMonsInfo == NULL))
    {
        if (FlagGet(FLAG_RYU_VERBOSE_MODE) == TRUE)
        {
            DebugPrint((const u8[])_("No Encounters."), 0);
        }
        return FALSE;
    }
    else
        return TRUE;
}

static bool8 HandleStartMenuInput(void)
{
    u16 song = VarGet(VAR_RYU_JUKEBOX);
    song = song + 1;
    switch (song)
    {
    case 1:
    case 999:
    case 557:
        song = 350;
        break;
    default:
        break;
    }
    if (song > 1000)
    {
        song = 350;
    }
    if (((FlagGet(FLAG_RYU_JUKEBOX_ENABLED) == 1) && gMain.newKeys & R_BUTTON) && (!(gSaveBlock2Ptr->disableBGM == 1)))
    {
        PlaySE(SE_PIN);
        while (gSongTable[song].me != 0 && song != 0)
            song++;
        VarSet(VAR_RYU_JUKEBOX, song);
        PlayNextTrack();
    }

    /*
    // place holder keycombo
    if(gMain.heldKeys & DPAD_RIGHT && gMain.newKeys & SELECT_BUTTON)
    {
        gMenuCallback = StartMenuAtlasCallback;
        FadeScreen(FADE_TO_BLACK, 0);
        return FALSE;
    }*/

    if (gMain.newKeys & SELECT_BUTTON)
    {
        if (FlagGet(FLAG_RYU_DEV_MODE) == 1)
        {
            RemoveExtraStartMenuWindows();
            if (!(MenuSpriteId1 == 0))
            {
                DestroySpriteAndFreeResources(&gSprites[MenuSpriteId1]);
                MenuSpriteId1 = 0;
            }

            HideStartMenu();
            HideFieldMessageBox();
            ScriptContext2_Enable();
            ScriptContext1_SetupScript(RyuDebugMenuScript);
            return TRUE;
        }
        else
        {
            RemoveExtraStartMenuWindows();
            if (!(MenuSpriteId1 == 0))
            {
                DestroySpriteAndFreeResources(&gSprites[MenuSpriteId1]);
                MenuSpriteId1 = 0;
            }

            HideStartMenu();
            HideFieldMessageBox();
            ScriptContext2_Enable();
            ScriptContext1_SetupScript(RyuStartMenuConfigInfoScript);
            return TRUE;
        }
    }

    if (JOY_NEW(DPAD_LEFT))
    {
        PlaySE(SE_SELECT);
        sStartMenuCursorPos = MainMenu_MoveSelectedAction(-1);
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        PlaySE(SE_SELECT);
        sStartMenuCursorPos = MainMenu_MoveSelectedAction(1);
    }

    if (JOY_NEW(DPAD_DOWN))
    {
        if (FlagGet(FLAG_RYU_HAS_FOLLOWER) == 1)
        {
            DestroyFollowerObjectEvent();
            CreateFollowerObjectEvent((VarGet(VAR_RYU_FOLLOWER_ID)), RyuFollowerSelectNPCScript, (GetPlayerFacingDirection()));
        }
    }
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if (sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void == StartMenuPokedexCallback)
        {
            if (GetNationalPokedexCount(FLAG_GET_SEEN) == 0)
                return FALSE;
        }

        gMenuCallback = sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void;

        if (((DoesCurrentMapHaveEncounters()) == FALSE) && (gMenuCallback == StartMenuDexNavCallback))
            gMenuCallback = StartMenuExitCallback;

        if (gMenuCallback != StartMenuSaveCallback
            && gMenuCallback != StartMenuExitCallback
            && gMenuCallback != StartMenuBattlePyramidRetireCallback)
        {
            FadeScreen(FADE_TO_BLACK, 0);
        }

        return FALSE;
    }

    if (JOY_NEW(START_BUTTON | B_BUTTON))
    {
        RemoveExtraStartMenuWindows();
        HideStartMenu();
        if (!(MenuSpriteId1 == 0))
        {
            DestroySpriteAndFreeResources(&gSprites[MenuSpriteId1]);
            MenuSpriteId1 = 0;
        }
        return TRUE;
    }

        if (gMain.heldKeys & L_BUTTON && gMain.newKeys & R_BUTTON)
        {   
            u16 curmusic = 0;
            u16 song = 350;
            switch (FlagGet(FLAG_RYU_JUKEBOX_ENABLED))//0 for unset, 1 for set
            {
                case 0:
                    FlagSet(FLAG_RYU_JUKEBOX_ENABLED);
                    PlaySE(SE_PC_ON);
                    
                    if (VarGet(VAR_RYU_SAVED_BGM) > 350 && (VarGet(VAR_RYU_SAVED_BGM) < 558))
                    {
                        song = VarGet(VAR_RYU_SAVED_BGM);
                        song --;
                    }

                    VarSet(VAR_RYU_JUKEBOX, song);
                    PlayBGM(song);
                    PlayNextTrack();
                    break;
                case 1:
                    FlagClear(FLAG_RYU_JUKEBOX_ENABLED);
                    VarSet(VAR_RYU_SAVED_BGM, VarGet(VAR_RYU_JUKEBOX));
                    ResetMapMusic();
                    Overworld_ChangeMusicToDefault();
                    VarSet(VAR_RYU_JUKEBOX, 998);
                    PlaySE(SE_PC_OFF);
                    break;
                default:
                    break;
            }
        }

    return FALSE;
}

bool8 StartMenuAtlasCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenAtlas);

        return TRUE;
    }

    return FALSE;
}

bool8 StartMenuPokedexCallback(void)
{
    if (!gPaletteFade.active)
    {
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenPokedex);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokemonCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokeNavCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitPokeNav); // Display PokeNav

        return TRUE;
    }

    return FALSE;
}
void CB2_OpenJournal(void);
static bool8 StartMenuJournalCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenJournal);
    }
    return FALSE;
}

static bool8 StartMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();

        if (IsUpdateLinkStateCBActive() || InUnionRoom())
        {
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
        }
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
        else
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuSaveCallback(void)
{
    // this check was completely redundant lol
    //if (InBattlePyramid())
    RemoveExtraStartMenuWindows();
    CleanupStartMenuElements();
    if (!(MenuSpriteId1 == 0))
    {
        DestroySpriteAndFreeResources(&gSprites[MenuSpriteId1]);
        MenuSpriteId1 = 0;
    }
    gMenuCallback = SaveStartCallback; // Display save menu

    return FALSE;
}

static bool8 StartMenuOptionCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuExitCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu();
    HideFieldMessageBox();
    return TRUE;
}

static bool8 StartMenuLinkModePlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        ShowTrainerCardInLink(gLocalLinkPlayerId, CB2_ReturnToFieldWithOpenMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBattlePyramidRetireCallback(void)
{
    gMenuCallback = BattlePyramidRetireStartCallback; // Confirm retire

    return FALSE;
}

// Functionally unused
void ShowBattlePyramidStartMenu(void)
{
    ClearDialogWindowAndFrameToTransparent(0, FALSE);
    ScriptUnfreezeObjectEvents();
    CreateStartMenuTask(Task_ShowStartMenu);
    ScriptContext2_Enable();
}

static bool8 StartMenuBattlePyramidBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PyramidBagMenuFromStartMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 SaveStartCallback(void)
{
    InitSave();
    gMenuCallback = SaveCallback;

    return FALSE;
}

static bool8 SaveCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Back to start menu
        ClearDialogWindowAndFrameToTransparent(0, FALSE);
        InitStartMenu();
        gMenuCallback = HandleStartMenuInput;
        return FALSE;
    case SAVE_SUCCESS:
    case SAVE_ERROR: // Close start menu
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        ScriptContext2_Disable();
        SoftResetInBattlePyramid();
        return TRUE;
    }

    return FALSE;
}

static bool8 BattlePyramidRetireStartCallback(void)
{
    InitBattlePyramidRetire();
    gMenuCallback = BattlePyramidRetireCallback;

    return FALSE;
}

static bool8 BattlePyramidRetireReturnCallback(void)
{
    InitStartMenu();
    gMenuCallback = HandleStartMenuInput;

    return FALSE;
}

static bool8 BattlePyramidRetireCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_SUCCESS: // No (Stay in Battle Pyramid)
        RemoveExtraStartMenuWindows();
        gMenuCallback = BattlePyramidRetireReturnCallback;
        return FALSE;
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Yes (Retire from Battle Pyramid)
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        ScriptContext2_Disable();
        ScriptContext1_SetupScript(BattlePyramid_Retire);
        return TRUE;
    }

    return FALSE;
}

static void InitSave(void)
{
    save_serialize_map();
    sSaveDialogCallback = SaveConfirmSaveCallback;
    sSavingComplete = FALSE;
}

static u8 RunSaveCallback(void)
{
    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
    {
        return SAVE_IN_PROGRESS;
    }

    sSavingComplete = FALSE;
    return sSaveDialogCallback();
}

void SaveGame(void)
{
    InitSave();
    CreateTask(SaveGameTask, 0x50);
}

static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void))
{
    StringExpandPlaceholders(gStringVar4, message);
    sub_819786C(0, TRUE);
    AddTextPrinterForMessage_2(TRUE);
    sSavingComplete = TRUE;
    sSaveDialogCallback = saveCallback;
}

static void SaveGameTask(u8 taskId)
{
    u8 status = RunSaveCallback();

    switch (status)
    {
    case SAVE_CANCELED:
    case SAVE_ERROR:
        gSpecialVar_Result = 0;
        break;
    case SAVE_SUCCESS:
        gSpecialVar_Result = status;
        break;
    case SAVE_IN_PROGRESS:
        return;
    }

    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void sub_80A0014(void)
{
    ClearDialogWindowAndFrame(0, TRUE);
}

static void HideSaveInfoWindow(void)
{
    RemoveSaveInfoWindow();
}

static void SaveStartTimer(void)
{
    sSaveDialogTimer = 60;
}

static bool8 SaveSuccesTimer(void)
{
    sSaveDialogTimer--;

    if (JOY_HELD(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sSaveDialogTimer == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static bool8 SaveErrorTimer(void)
{
    if (sSaveDialogTimer != 0)
    {
        sSaveDialogTimer--;
    }
    else if (JOY_HELD(A_BUTTON))
    {
        return TRUE;
    }

    return FALSE;
}

static u8 SaveConfirmSaveCallback(void)
{
    /*
    ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    RemoveStartMenuWindow();
    */

    ShowSaveInfoWindow();

    if (InBattlePyramid())
    {
        ShowSaveMessage(gText_BattlePyramidConfirmRest, SaveYesNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_ConfirmSave, SaveYesNoCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveYesNoCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveConfirmInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_EMPTY:
        case SAVE_STATUS_CORRUPT:
            if (gDifferentSaveFile == FALSE)
            {
                sSaveDialogCallback = SaveFileExistsCallback;
                return SAVE_IN_PROGRESS;
            }

            sSaveDialogCallback = SaveSavingMessageCallback;
            return SAVE_IN_PROGRESS;
        default:
            sSaveDialogCallback = SaveFileExistsCallback;
            return SAVE_IN_PROGRESS;
        }
    case -1: // B Button
    case 1:  // No
        HideSaveInfoWindow();
        sub_80A0014();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

// A different save file exists
static u8 SaveFileExistsCallback(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        ShowSaveMessage(gText_DifferentSaveFile, SaveConfirmOverwriteDefaultNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_AlreadySavedFile, SaveConfirmOverwriteCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteDefaultNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveOverwriteInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        sSaveDialogCallback = SaveSavingMessageCallback;
        return SAVE_IN_PROGRESS;
    case -1: // B Button
    case 1:  // No
        HideSaveInfoWindow();
        sub_80A0014();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveSavingMessageCallback(void)
{
    ShowSaveMessage(gText_SavingDontTurnOff, SaveDoSaveCallback);
    return SAVE_IN_PROGRESS;
}

static u8 SaveDoSaveCallback(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);
    PausePyramidChallenge();

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == SAVE_STATUS_OK)
        ShowSaveMessage(gText_PlayerSavedGame, SaveSuccessCallback);
    else
        ShowSaveMessage(gText_SaveError, SaveErrorCallback);

    SaveStartTimer();
    return SAVE_IN_PROGRESS;
}

static u8 SaveSuccessCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_SAVE);
        sSaveDialogCallback = SaveReturnSuccessCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnSuccessCallback(void)
{
    if (!IsSEPlaying() && SaveSuccesTimer())
    {
        HideSaveInfoWindow();
        return SAVE_SUCCESS;
    }
    else
    {
        return SAVE_IN_PROGRESS;
    }
}

static u8 SaveErrorCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_BOO);
        sSaveDialogCallback = SaveReturnErrorCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnErrorCallback(void)
{
    if (!SaveErrorTimer())
    {
        return SAVE_IN_PROGRESS;
    }
    else
    {
        HideSaveInfoWindow();
        return SAVE_ERROR;
    }
}

static void InitBattlePyramidRetire(void)
{
    sSaveDialogCallback = BattlePyramidConfirmRetireCallback;
    sSavingComplete = FALSE;
}

static u8 BattlePyramidConfirmRetireCallback(void)
{
    //ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    //RemoveStartMenuWindow();
    RemoveExtraStartMenuWindows();
    CleanupStartMenuElements();
    ShowSaveMessage(gText_BattlePyramidConfirmRetire, BattlePyramidRetireYesNoCallback);

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireYesNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = BattlePyramidRetireInputCallback;

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        return SAVE_CANCELED;
    case -1: // B Button
    case 1:  // No
        sub_80A0014();
        return SAVE_SUCCESS;
    }

    return SAVE_IN_PROGRESS;
}

static void sub_80A03D8(void)
{
    TransferPlttBuffer();
}

static bool32 InitSaveWindowAfterLinkBattle(u8 *state)
{
    switch (*state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        DmaClear16(3, PLTT, PLTT_SIZE);
        DmaFillLarge16(3, 0, (void *)(VRAM + 0x0), 0x18000, 0x1000);
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        ResetPaletteFade();
        ScanlineEffect_Clear();
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sUnknown_085105A8, ARRAY_COUNT(sUnknown_085105A8));
        InitWindows(sUnknown_085105AC);
        LoadUserWindowBorderGfx_(0, 8, 224);
        Menu_LoadStdPalAt(240);
        break;
    case 3:
        ShowBg(0);
        BlendPalettes(-1, 16, 0);
        SetVBlankCallback(sub_80A03D8);
        EnableInterrupts(1);
        break;
    case 4:
        return TRUE;
    }

    (*state)++;
    return FALSE;
}

void CB2_SetUpSaveAfterLinkBattle(void)
{
    if (InitSaveWindowAfterLinkBattle(&gMain.state))
    {
        CreateTask(Task_SaveAfterLinkBattle, 0x50);
        SetMainCallback2(CB2_SaveAfterLinkBattle);
    }
}

static void CB2_SaveAfterLinkBattle(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void Task_SaveAfterLinkBattle(u8 taskId)
{
    s16 *state = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (*state)
        {
        case 0:
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0,
                                         1,
                                         gText_SavingDontTurnOffPower,
                                         TEXT_SPEED_FF,
                                         NULL,
                                         TEXT_COLOR_DARK_GREY,
                                         TEXT_COLOR_WHITE,
                                         TEXT_COLOR_LIGHT_GREY);
            DrawTextBorderOuter(0, 8, 14);
            PutWindowTilemap(0);
            CopyWindowToVram(0, 3);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);

            if (gWirelessCommType != 0 && InUnionRoom())
            {
                if (Link_AnyPartnersPlayingFRLG_JP())
                {
                    *state = 1;
                }
                else
                {
                    *state = 5;
                }
            }
            else
            {
                gSoftResetDisabled = 1;
                *state = 1;
            }
            break;
        case 1:
            SetContinueGameWarpStatusToDynamicWarp();
            FullSaveGame();
            *state = 2;
            break;
        case 2:
            if (CheckSaveFile())
            {
                ClearContinueGameWarpStatus2();
                *state = 3;
                gSoftResetDisabled = 0;
            }
            break;
        case 3:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            *state = 4;
            break;
        case 4:
            FreeAllWindowBuffers();
            SetMainCallback2(gMain.savedCallback);
            DestroyTask(taskId);
            break;
        case 5:
            CreateTask(Task_LinkSave, 5);
            *state = 6;
            break;
        case 6:
            if (!FuncIsActiveTask(Task_LinkSave))
            {
                *state = 3;
            }
            break;
        }
    }
}

static void ShowSaveInfoWindow(void)
{
    struct WindowTemplate saveInfoWindow = sSaveInfoWindowTemplate;
    u8 gender;
    u8 color;
    u32 xOffset;
    u32 yOffset;

    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        saveInfoWindow.height -= 2;
    }

    sSaveInfoWindowId = AddWindow(&saveInfoWindow);
    DrawStdWindowFrame(sSaveInfoWindowId, FALSE);

    gender = gSaveBlock2Ptr->playerGender;
    color = TEXT_COLOR_RED; // Red when female, blue when male.

    if (gender == MALE)
    {
        color = TEXT_COLOR_BLUE;
    }

    // Print region name
    yOffset = 1;
    BufferSaveMenuText(SAVE_MENU_LOCATION, gStringVar4, TEXT_COLOR_GREEN);
    AddTextPrinterParameterized(sSaveInfoWindowId, 1, gStringVar4, 0, yOffset, 0xFF, NULL);

    // Print player name
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, 1, gText_SavingPlayer, 0, yOffset, 0xFF, NULL);
    BufferSaveMenuText(SAVE_MENU_NAME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
    PrintPlayerNameOnWindow(sSaveInfoWindowId, gStringVar4, xOffset, yOffset);

    // Print badge count
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, 1, gText_SavingBadges, 0, yOffset, 0xFF, NULL);
    BufferSaveMenuText(SAVE_MENU_BADGES, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, 1, gStringVar4, xOffset, yOffset, 0xFF, NULL);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        // Print pokedex count
        yOffset += 16;
        AddTextPrinterParameterized(sSaveInfoWindowId, 1, gText_SavingPokedex, 0, yOffset, 0xFF, NULL);
        BufferSaveMenuText(SAVE_MENU_CAUGHT, gStringVar4, color);
        xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
        AddTextPrinterParameterized(sSaveInfoWindowId, 1, gStringVar4, xOffset, yOffset, 0xFF, NULL);
    }

    // Print play time
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, 1, gText_SavingTime, 0, yOffset, 0xFF, NULL);
    BufferSaveMenuText(SAVE_MENU_PLAY_TIME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, 1, gStringVar4, xOffset, yOffset, 0xFF, NULL);

    CopyWindowToVram(sSaveInfoWindowId, 2);
}

static void RemoveSaveInfoWindow(void)
{
    ClearStdWindowAndFrame(sSaveInfoWindowId, FALSE);
    RemoveWindow(sSaveInfoWindowId);
}

static void Task_WaitForBattleTowerLinkSave(u8 taskId)
{
    if (!FuncIsActiveTask(Task_LinkSave))
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

#define tPartialSave data[2]

void SaveForBattleTowerLink(void)
{
    u8 taskId = CreateTask(Task_LinkSave, 5);
    gTasks[taskId].tPartialSave = TRUE;
    gTasks[CreateTask(Task_WaitForBattleTowerLinkSave, 6)].data[1] = taskId;
}

#undef tPartialSave

static void HideStartMenuWindow(void)
{
    /*
    ClearStdWindowAndFrame(GetStartMenuWindowId(), TRUE);
    RemoveStartMenuWindow();
    */
    CleanupStartMenuElements();
    if (!(MenuSpriteId1 == 0))
    {
        DestroySpriteAndFreeResources(&gSprites[MenuSpriteId1]);
        MenuSpriteId1 = 0;
    }
    ScriptUnfreezeObjectEvents();
    ScriptContext2_Disable();
}

void HideStartMenu(void)
{
    PlaySE(SE_SELECT);
    HideStartMenuWindow();
}

void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}

static bool8 StartMenuDexNavCallback(void)
{
    CreateTask(Task_OpenDexNavFromStartMenu, 0);
    return TRUE;
}
