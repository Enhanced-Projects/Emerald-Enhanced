#include "global.h"
#include "main.h"
#include "event_data.h"
#include "field_effect.h"
#include "field_specials.h"
#include "item.h"
#include "list_menu.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/script_menu.h"
#include "constants/songs.h"

#include "data/script_menu.h"

static EWRAM_DATA u8 sProcessInputDelay = 0;

static u8 sLilycoveSSTidalSelections[SSTIDAL_SELECTION_COUNT];

static void Task_HandleMultichoiceInput(u8 taskId);
static void Task_HandleYesNoInput(u8 taskId);
static void Task_HandleMultichoiceGridInput(u8 taskId);
static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 cursorPos);
static void InitMultichoiceCheckWrap(bool8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId);
static void DrawLinkServicesMultichoiceMenu(u8 multichoiceId);
static void CreatePCMultichoice(void);
static void CreateLilycoveSSTidalMultichoice(void);
static bool8 IsPicboxClosed(void);
static void CreateStartMenuForPokenavTutorial(void);
static void InitMultichoiceNoWrap(bool8 ignoreBPress, u8 unusedCount, u8 windowId, u8 multichoiceId);

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, 0);
        return TRUE;
    }
}

bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 defaultChoice)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, defaultChoice);
        return TRUE;
    }
}

// Unused
static u16 GetLengthWithExpandedPlayerName(const u8 *str)
{
    u16 length = 0;

    while (*str != EOS)
    {
        if (*str == PLACEHOLDER_BEGIN)
        {
            str++;
            if (*str == PLACEHOLDER_ID_PLAYER)
            {
                length += StringLength(gSaveBlock2Ptr->playerName);
                str++;
            }
        }
        else
        {
            str++;
            length++;
        }
    }

    return length;
}

static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 cursorPos)
{
    int i;
    u8 windowId;
    u8 count = sMultichoiceLists[multichoiceId].count;
    const struct MenuAction *actions = sMultichoiceLists[multichoiceId].list;
    int width = 0;
    u8 newWidth;

    for (i = 0; i < count; i++)
    {
        width = DisplayTextAndGetWidth(actions[i].text, width);
    }

    newWidth = ConvertPixelWidthToTileWidth(width);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, newWidth);
    windowId = CreateWindowFromRect(left, top, newWidth, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    PrintMenuTable(windowId, count, actions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    InitMultichoiceCheckWrap(ignoreBPress, count, windowId, multichoiceId);
}

#define tLeft           data[0]
#define tTop            data[1]
#define tRight          data[2]
#define tBottom         data[3]
#define tIgnoreBPress   data[4]
#define tDoWrap         data[5]
#define tWindowId       data[6]
#define tMultichoiceId  data[7]

static void InitMultichoiceCheckWrap(bool8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId)
{
    u8 i;
    u8 taskId;
    sProcessInputDelay = 2;

    for (i = 0; i < ARRAY_COUNT(sLinkServicesMultichoiceIds); i++)
    {
        if (sLinkServicesMultichoiceIds[i] == multichoiceId)
        {
            sProcessInputDelay = 12;
        }
    }

    taskId = CreateTask(Task_HandleMultichoiceInput, 80);

    gTasks[taskId].tIgnoreBPress = ignoreBPress;

    if (count > 3)
        gTasks[taskId].tDoWrap = TRUE;
    else
        gTasks[taskId].tDoWrap = FALSE;

    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;

    DrawLinkServicesMultichoiceMenu(multichoiceId);
}

static void Task_HandleMultichoiceInput(u8 taskId)
{
    s8 selection;
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        if (sProcessInputDelay)
        {
            sProcessInputDelay--;
        }
        else
        {
            if (!tDoWrap)
                selection = Menu_ProcessInputNoWrap();
            else
                selection = Menu_ProcessInput();

            if (JOY_NEW(DPAD_UP | DPAD_DOWN))
            {
                DrawLinkServicesMultichoiceMenu(tMultichoiceId);
            }

            if (selection != MENU_NOTHING_CHOSEN)
            {
                if (selection == MENU_B_PRESSED)
                {
                    if (tIgnoreBPress)
                        return;
                    PlaySE(SE_SELECT);
                    gSpecialVar_Result = MULTI_B_PRESSED;
                }
                else
                {
                    gSpecialVar_Result = selection;
                }
                ClearToTransparentAndRemoveWindow(tWindowId);
                DestroyTask(taskId);
                EnableBothScriptContexts();
            }
        }
    }
}

bool8 ScriptMenu_YesNo(u8 left, u8 top)
{
    u8 taskId;

    if (FuncIsActiveTask(Task_HandleYesNoInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DisplayYesNoMenuDefaultYes();
        taskId = CreateTask(Task_HandleYesNoInput, 0x50);
        return TRUE;
    }
}

// Unused
bool8 IsScriptActive(void)
{
    if (gSpecialVar_Result == 0xFF)
        return FALSE;
    else
        return TRUE;
}

static void Task_HandleYesNoInput(u8 taskId)
{
    if (gTasks[taskId].tRight < 5)
    {
        gTasks[taskId].tRight++;
        return;
    }

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0;
        break;
    case 0:
        gSpecialVar_Result = 1;
        break;
    }

    DestroyTask(taskId);
    EnableBothScriptContexts();
}

bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 columnCount)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceGridInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 rowCount, newWidth;
        int i, width;

        gSpecialVar_Result = 0xFF;
        width = 0;

        for (i = 0; i < sMultichoiceLists[multichoiceId].count; i++)
        {
            width = DisplayTextAndGetWidth(sMultichoiceLists[multichoiceId].list[i].text, width);
        }

        newWidth = ConvertPixelWidthToTileWidth(width);

        left = ScriptMenu_AdjustLeftCoordFromWidth(left, columnCount * newWidth);
        rowCount = sMultichoiceLists[multichoiceId].count / columnCount;

        taskId = CreateTask(Task_HandleMultichoiceGridInput, 80);

        gTasks[taskId].tIgnoreBPress = ignoreBPress;
        gTasks[taskId].tWindowId = CreateWindowFromRect(left, top, columnCount * newWidth, rowCount * 2);
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 0);
        PrintMenuGridTable(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, sMultichoiceLists[multichoiceId].list);
        sub_8199944(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, 0);
        CopyWindowToVram(gTasks[taskId].tWindowId, 3);
        return TRUE;
    }
}

static void Task_HandleMultichoiceGridInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 selection = Menu_ProcessInputGridLayout();

    switch (selection)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tIgnoreBPress)
            return;
        PlaySE(SE_SELECT);
        gSpecialVar_Result = MULTI_B_PRESSED;
        break;
    default:
        gSpecialVar_Result = selection;
        break;
    }

    ClearToTransparentAndRemoveWindow(tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

#undef tWindowId

bool16 ScriptMenu_CreatePCMultichoice(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreatePCMultichoice();
        return TRUE;
    }
}

static void CreatePCMultichoice(void)
{
    u8 y = 8;
    u32 pixelWidth = 0;
    u8 width;
    u8 numChoices;
    u8 windowId;
    int i;

    for (i = 0; i < ARRAY_COUNT(sPCNameStrings); i++)
    {
        pixelWidth = DisplayTextAndGetWidth(sPCNameStrings[i], pixelWidth);
    }

    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        pixelWidth = DisplayTextAndGetWidth(gText_HallOfFame, pixelWidth);
    }

    width = ConvertPixelWidthToTileWidth(pixelWidth);

    // Include Hall of Fame option if player is champion
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        numChoices = 4;
        windowId = CreateWindowFromRect(0, 0, width, 8);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_HallOfFame, y, 33, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 49, TEXT_SPEED_FF, NULL);
    }
    else
    {
        numChoices = 3;
        windowId = CreateWindowFromRect(0, 0, width, 6);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 33, TEXT_SPEED_FF, NULL);
    }

    // Change PC name if player has met Lanette
    if (FlagGet(FLAG_SYS_PC_LANETTE))
        AddTextPrinterParameterized(windowId, 1, gText_LanettesPC, y, 1, TEXT_SPEED_FF, NULL);
    else
        AddTextPrinterParameterized(windowId, 1, gText_SomeonesPC, y, 1, TEXT_SPEED_FF, NULL);

    StringExpandPlaceholders(gStringVar4, gText_PlayersPC);
    PrintPlayerNameOnWindow(windowId, gStringVar4, y, 17);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, numChoices, 0);
    CopyWindowToVram(windowId, 3);
    InitMultichoiceCheckWrap(FALSE, numChoices, windowId, MULTI_PC);
}

void ScriptMenu_DisplayPCStartupPrompt(void)
{
    sub_819786C(0, TRUE);
    AddTextPrinterParameterized2(0, 1, gText_WhichPCShouldBeAccessed, 0, NULL, 2, 1, 3);
}

bool8 ScriptMenu_CreateLilycoveSSTidalMultichoice(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreateLilycoveSSTidalMultichoice();
        return TRUE;
    }
}

// gSpecialVar_0x8004 is 1 if the Sailor was shown multiple event tickets at the same time
// otherwise gSpecialVar_0x8004 is 0
static void CreateLilycoveSSTidalMultichoice(void)
{
    u8 selectionCount = 0;
    u8 count;
    u32 pixelWidth;
    u8 width;
    u8 windowId;
    u8 i;
    u32 j;

    for (i = 0; i < SSTIDAL_SELECTION_COUNT; i++)
    {
        sLilycoveSSTidalSelections[i] = 0xFF;
    }

    GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);

    if (gSpecialVar_0x8004 == 0)
    {
        sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SLATEPORT;
        selectionCount++;

        if (FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BATTLE_FRONTIER;
            selectionCount++;
        }
    }

    if (CheckBagHasItem(ITEM_EON_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_SOUTHERN_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SOUTHERN_ISLAND;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_EON_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SOUTHERN_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_EON_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_MYSTIC_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_NAVEL_ROCK) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_NAVEL_ROCK;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_MYSTIC_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_NAVEL_ROCK;
            selectionCount++;
            FlagSet(FLAG_SHOWN_MYSTIC_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_AURORA_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_BIRTH_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BIRTH_ISLAND;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_AURORA_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BIRTH_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_AURORA_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_OLD_SEA_MAP, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_FARAWAY_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_FARAWAY_ISLAND;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_OLD_SEA_MAP) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_FARAWAY_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_OLD_SEA_MAP);
        }
    }

    sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_EXIT;
    selectionCount++;

    if (gSpecialVar_0x8004 == 0 && FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
    {
        count = selectionCount;
    }

    count = selectionCount;
    if (count == SSTIDAL_SELECTION_COUNT)
    {
        gSpecialVar_0x8004 = SCROLL_MULTI_SS_TIDAL_DESTINATION;
        ShowScrollableMultichoice();
    }
    else
    {
        pixelWidth = 0;

        for (j = 0; j < SSTIDAL_SELECTION_COUNT; j++)
        {
            u8 selection = sLilycoveSSTidalSelections[j];
            if (selection != 0xFF)
            {
                pixelWidth = DisplayTextAndGetWidth(sLilycoveSSTidalDestinations[selection], pixelWidth);
            }
        }

        width = ConvertPixelWidthToTileWidth(pixelWidth);
        windowId = CreateWindowFromRect(MAX_MULTICHOICE_WIDTH - width, (6 - count) * 2, width, count * 2);
        SetStandardWindowBorderStyle(windowId, 0);

        for (selectionCount = 0, i = 0; i < SSTIDAL_SELECTION_COUNT; i++)
        {
            if (sLilycoveSSTidalSelections[i] != 0xFF)
            {
                AddTextPrinterParameterized(windowId, 1, sLilycoveSSTidalDestinations[sLilycoveSSTidalSelections[i]], 8, selectionCount * 16 + 1, TEXT_SPEED_FF, NULL);
                selectionCount++;
            }
        }

        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, count - 1);
        CopyWindowToVram(windowId, 3);
        InitMultichoiceCheckWrap(FALSE, count, windowId, MULTI_SSTIDAL_LILYCOVE);
    }
}

void GetLilycoveSSTidalSelection(void)
{
    if (gSpecialVar_Result != MULTI_B_PRESSED)
    {
        gSpecialVar_Result = sLilycoveSSTidalSelections[gSpecialVar_Result];
    }
}

#define tState       data[0]
#define tMonSpecies  data[1]
#define tMonSpriteId data[2]
#define tWindowX     data[3]
#define tWindowY     data[4]
#define tWindowId    data[5]

static void Task_PokemonPicWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tState++;
        break;
    case 1:
        break;
    case 2:
        FreeResourcesAndDestroySprite(&gSprites[task->tMonSpriteId], task->tMonSpriteId);
        task->tState++;
        break;
    case 3:
        ClearToTransparentAndRemoveWindow(task->tWindowId);
        DestroyTask(taskId);
        break;
    }
}

bool8 ScriptMenu_ShowPokemonPic(u16 species, u8 x, u8 y)
{
    u8 taskId;
    u8 spriteId;

    if (FindTaskIdByFunc(Task_PokemonPicWindow) != 0xFF)
    {
        return FALSE;
    }
    else
    {
        spriteId = CreateMonSprite_PicBox(species, x * 8 + 40, y * 8 + 40, 0);
        taskId = CreateTask(Task_PokemonPicWindow, 0x50);
        gTasks[taskId].tWindowId = CreateWindowFromRect(x, y, 8, 8);
        gTasks[taskId].tState = 0;
        gTasks[taskId].tMonSpecies = species;
        gTasks[taskId].tMonSpriteId = spriteId;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 1);
        ScheduleBgCopyTilemapToVram(0);
        return TRUE;
    }
}

bool8 (*ScriptMenu_GetPicboxWaitFunc(void))(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PokemonPicWindow);

    if (taskId == 0xFF)
        return NULL;
    gTasks[taskId].tState++;
    return IsPicboxClosed;
}

static bool8 IsPicboxClosed(void)
{
    if (FindTaskIdByFunc(Task_PokemonPicWindow) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

#undef tState
#undef tMonSpecies
#undef tMonSpriteId
#undef tWindowX
#undef tWindowY
#undef tWindowId

u8 CreateWindowFromRect(u8 x, u8 y, u8 width, u8 height)
{
    struct WindowTemplate template = CreateWindowTemplate(0, x + 1, y + 1, width, height, 15, 100);
    u8 windowId = AddWindow(&template);
    PutWindowTilemap(windowId);
    return windowId;
}

void ClearToTransparentAndRemoveWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
}

static void DrawLinkServicesMultichoiceMenu(u8 multichoiceId)
{
    switch (multichoiceId)
    {
    case MULTI_WIRELESS_NO_BERRY:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptionsNoBerryCrush[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_CABLE_CLUB_WITH_RECORD_MIX:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sCableClubOptions_WithRecordMix[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_WIRELESS_NO_RECORD:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptions_NoRecordMix[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_WIRELESS_ALL_SERVICES:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptions_AllServices[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_WIRELESS_NO_RECORD_BERRY:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptions_NoRecordMixBerryCrush[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_CABLE_CLUB_NO_RECORD_MIX:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sCableClubOptions_NoRecordMix[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    }
}

bool16 ScriptMenu_CreateStartMenuForPokenavTutorial(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreateStartMenuForPokenavTutorial();
        return TRUE;
    }
}

static void CreateStartMenuForPokenavTutorial(void)
{
    u8 windowId = CreateWindowFromRect(21, 0, 7, 18);
    SetStandardWindowBorderStyle(windowId, 0);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokedex, 8, 9, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokemon, 8, 25, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionBag, 8, 41, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokenav, 8, 57, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gSaveBlock2Ptr->playerName, 8, 73, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionSave, 8, 89, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionOption, 8, 105, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionExit, 8, 121, TEXT_SPEED_FF, NULL);
    Menu_InitCursor(windowId, 1, 0, 9, 16, ARRAY_COUNT(MultichoiceList_ForcedStartMenu), 0);
    InitMultichoiceNoWrap(FALSE, ARRAY_COUNT(MultichoiceList_ForcedStartMenu), windowId, MULTI_FORCED_START_MENU);
    CopyWindowToVram(windowId, 3);
}

#define tWindowId       data[6]

static void InitMultichoiceNoWrap(bool8 ignoreBPress, u8 unusedCount, u8 windowId, u8 multichoiceId)
{
    u8 taskId;
    sProcessInputDelay = 2;
    taskId = CreateTask(Task_HandleMultichoiceInput, 80);
    gTasks[taskId].tIgnoreBPress = ignoreBPress;
    gTasks[taskId].tDoWrap = 0;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;
}

#undef tLeft
#undef tTop
#undef tRight
#undef tBottom
#undef tIgnoreBPress
#undef tDoWrap
#undef tWindowId
#undef tMultichoiceId

static int DisplayTextAndGetWidthInternal(const u8 *str)
{
    u8 temp[64];
    StringExpandPlaceholders(temp, str);
    return GetStringWidth(1, temp, 0);
}

int DisplayTextAndGetWidth(const u8 *str, int prevWidth)
{
    int width = DisplayTextAndGetWidthInternal(str);
    if (width < prevWidth)
    {
        width = prevWidth;
    }
    return width;
}

int ConvertPixelWidthToTileWidth(int width)
{
    return (((width + 9) / 8) + 1) > MAX_MULTICHOICE_WIDTH ? MAX_MULTICHOICE_WIDTH : (((width + 9) / 8) + 1);
}

int ScriptMenu_AdjustLeftCoordFromWidth(int left, int width)
{
    int adjustedLeft = left;

    if (left + width > MAX_MULTICHOICE_WIDTH)
    {
        if (MAX_MULTICHOICE_WIDTH - width < 0)
        {
            adjustedLeft = 0;
        }
        else
        {
            adjustedLeft = MAX_MULTICHOICE_WIDTH - width;
        }
    }

    return adjustedLeft;
}
static const u8 sText_DebugUtilityItem2[] = _("Phasing");
static const u8 sText_DebugUtilityItem3[] = _("Dev Repel");
static const u8 sText_DebugUtilityItem4[] = _("View Temp Vars");
static const u8 sText_DebugUtilityItem5[] = _("Set Time");
static const u8 sText_DebugUtilityItem6[] = _("Battle Sim");
static const u8 sText_DebugUtilityItem7[] = _("Set Exp Mult");
static const u8 sText_DebugUtilityItem8[] = _("All Badges");
static const u8 sText_DebugUtilityItem9[] = _("Heal Party");
static const u8 sText_DebugUtilityItem10[] = _("Saveblock Size");
static const u8 sText_DebugUtilityItem11[] = _("Complete Dex");
static const u8 sText_DebugUtilityItem12[] = _("Give/Take Achievements");
static const u8 sText_DebugUtilityItem13[] = _("Check AP Usage");
static const u8 sText_DebugUtilityItem14[] = _("Faction relations");
static const u8 sText_DebugUtilityItem15[] = _("Alchemy Info");
static const u8 sText_DebugUtilityItem16[] = _("Toggle Level Cap");
static const u8 sText_DebugUtilityItem17[] = _("Enable Real Estate");
static const u8 sText_DebugUtilityItem18[] = _("Exit");

// strings to display as items.
static const u8 sText_BotanyConsumableItem1[] = _("Muscle Powder");
static const u8 sText_BotanyConsumableItem2[] = _("Tough Powder");
static const u8 sText_BotanyConsumableItem3[] = _("Smart Powder");
static const u8 sText_BotanyConsumableItem4[] = _("Resist Powder");
static const u8 sText_BotanyConsumableItem5[] = _("Swift Powder");
static const u8 sText_BotanyConsumableItem6[] = _("Focus Powder");
static const u8 sText_BotanyConsumableItem7[] = _("Small Salad");
static const u8 sText_BotanyConsumableItem8[] = _("Medium Salad");
static const u8 sText_BotanyConsumableItem9[] = _("Large Salad");
static const u8 sText_BotanyConsumableItem10[] = _("Heal Chowder");
static const u8 sText_BotanyConsumableItem11[] = _("Lemonade");
static const u8 sText_BotanyConsumableItem12[] = _("Revital Ice");

static const u8 sText_BotanyMedicineItem1[] = _("HP Up");
static const u8 sText_BotanyMedicineItem2[] = _("Protein");
static const u8 sText_BotanyMedicineItem3[] = _("Iron");
static const u8 sText_BotanyMedicineItem4[] = _("Calcium");
static const u8 sText_BotanyMedicineItem5[] = _("Zinc");
static const u8 sText_BotanyMedicineItem6[] = _("Carbos");
static const u8 sText_BotanyMedicineItem7[] = _("Ether");
static const u8 sText_BotanyMedicineItem8[] = _("Elixir");

static const u8 sText_BotanyEvolutionItem1[] = _("Fire Stone");
static const u8 sText_BotanyEvolutionItem2[] = _("Water Stone");
static const u8 sText_BotanyEvolutionItem3[] = _("Thunder Stone");
static const u8 sText_BotanyEvolutionItem4[] = _("Leaf Stone");
static const u8 sText_BotanyEvolutionItem5[] = _("Moon Stone");
static const u8 sText_BotanyEvolutionItem6[] = _("Sun Stone");
static const u8 sText_BotanyEvolutionItem7[] = _("Shiny Stone");
static const u8 sText_BotanyEvolutionItem8[] = _("Dusk Stone");
static const u8 sText_BotanyEvolutionItem9[] = _("Dawn Stone");
static const u8 sText_BotanyEvolutionItem10[] = _("Ice Stone");

extern const u8 sRAEffectDamage1[];
extern const u8 sRAEffectDamage2[];
extern const u8 sRAEffectDamage3[];
extern const u8 sRAEffectDefense1[];
extern const u8 sRAEffectDefense2[];
extern const u8 sRAEffectDefense3[];
extern const u8 sRAEffectRepelT1[];
extern const u8 sRAEffectRepelT2[];
extern const u8 sRAEffectSuperCapture1[];
extern const u8 sRAEffectSuperCapture2[];
extern const u8 sRAEffectSuperCapture3[];
extern const u8 sRAEffectEXPBoost1[];
extern const u8 sRAEffectEXPBoost2[];
extern const u8 sRAEffectEXPBoost3[];
extern const u8 sRAEffectHealingFactor[];
static const u8 sRAItemStardust[] = _("Make Stardust");
static const u8 sRAItemFreshWater[] = _("Make Fresh Water");
static const u8 sRAItemTonicWater[] = _("Make Tonic Water");
static const u8 sRAItemMineralWater[] = _("Make Mineral Water");
static const u8 sRAItemRareCandy[] = _("Make Rare Candy");
static const u8 sRAItemGoldNugget[] = _("Make Gold Nugget");

static const struct ListMenuItem sBotanyConsumablesSet[] =
{
    {sText_BotanyConsumableItem1, 0},
    {sText_BotanyConsumableItem2, 1},
    {sText_BotanyConsumableItem3, 2},
    {sText_BotanyConsumableItem4, 3},
    {sText_BotanyConsumableItem5, 4},
    {sText_BotanyConsumableItem6, 5},
    {sText_BotanyConsumableItem7, 6},
    {sText_BotanyConsumableItem8, 7},
    {sText_BotanyConsumableItem9, 8},
    {sText_BotanyConsumableItem10, 9},
    {sText_BotanyConsumableItem11, 10},
    {sText_BotanyConsumableItem12, 11}
};

static const struct ListMenuItem sBotanyMedicineSet[] =
{
    {sText_BotanyMedicineItem1, 0},
    {sText_BotanyMedicineItem2, 1},
    {sText_BotanyMedicineItem3, 2},
    {sText_BotanyMedicineItem4, 3},
    {sText_BotanyMedicineItem5, 4},
    {sText_BotanyMedicineItem6, 5},
    {sText_BotanyMedicineItem7, 6},
    {sText_BotanyMedicineItem8, 7}
};

static const struct ListMenuItem sBotanyEvolutionSet[] =
{
    {sText_BotanyEvolutionItem1, 0},
    {sText_BotanyEvolutionItem2, 1},
    {sText_BotanyEvolutionItem3, 2},
    {sText_BotanyEvolutionItem4, 3},
    {sText_BotanyEvolutionItem5, 4},
    {sText_BotanyEvolutionItem6, 5},
    {sText_BotanyEvolutionItem7, 6},
    {sText_BotanyEvolutionItem8, 7},
    {sText_BotanyEvolutionItem9, 8},
    {sText_BotanyEvolutionItem10, 9}
};

static const struct ListMenuItem sDebugUtilitySet[] =
{
    {sText_DebugUtilityItem2, 0},
    {sText_DebugUtilityItem3, 1},
    {sText_DebugUtilityItem4, 2},
    {sText_DebugUtilityItem5, 3},
    {sText_DebugUtilityItem6, 4},
    {sText_DebugUtilityItem7, 5},
    {sText_DebugUtilityItem8, 6},
    {sText_DebugUtilityItem9, 7},
    {sText_DebugUtilityItem10, 8},
    {sText_DebugUtilityItem11, 9},
    {sText_DebugUtilityItem12, 10},
    {sText_DebugUtilityItem13, 11},
    {sText_DebugUtilityItem14, 12},
    {sText_DebugUtilityItem15, 13},
    {sText_DebugUtilityItem16, 14},
    {sText_DebugUtilityItem17, 15},
    {sText_DebugUtilityItem18, 16}
};

static const struct ListMenuItem sAlchemyMenu[] =
{
    {sRAEffectDamage1, 0},
    {sRAEffectDamage2, 1},
    {sRAEffectDamage3, 2},
    {sRAEffectDefense1, 3},
    {sRAEffectDefense2, 4},
    {sRAEffectDefense3, 5},
    {sRAEffectEXPBoost1, 6},
    {sRAEffectEXPBoost2, 7},
    {sRAEffectEXPBoost3, 8},
    {sRAEffectRepelT1, 9},
    {sRAEffectRepelT2, 10},
    {sRAEffectSuperCapture1, 11},
    {sRAEffectSuperCapture2, 12},
    {sRAEffectSuperCapture3, 13},
    {sRAEffectHealingFactor, 14},
    {sRAItemStardust, 15},
    {sRAItemFreshWater, 16},
    {sRAItemTonicWater, 17},
    {sRAItemMineralWater, 18},
    {sRAItemRareCandy, 19},
    {sRAItemGoldNugget, 20},
};


struct
{
    const struct ListMenuItem *set;
    int count;
} static const sScrollingSets[] =
{
    {sDebugUtilitySet, ARRAY_COUNT(sDebugUtilitySet)},
    {sBotanyConsumablesSet, ARRAY_COUNT(sBotanyConsumablesSet)},
    {sBotanyMedicineSet, ARRAY_COUNT(sBotanyMedicineSet)},
    {sBotanyEvolutionSet, ARRAY_COUNT(sBotanyEvolutionSet)},
    {sAlchemyMenu, ARRAY_COUNT(sAlchemyMenu)},
};

static void Task_ScrollingMultichoiceInput(u8 taskId);

static const struct ListMenuTemplate sMultichoiceListTemplate =
{
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

// 0x8004 = set id
// 0x8005 = window X
// 0x8006 = window y
// 0x8007 = showed at once
// 0x8008 = Allow B press
void ScriptMenu_ScrollingMultichoice(void)
{
    int i, windowId, taskId, width = 0;
    int setId = gSpecialVar_0x8004;
    int left = gSpecialVar_0x8005;
    int top = gSpecialVar_0x8006;
    int maxShowed = gSpecialVar_0x8007;

    for (i = 0; i < sScrollingSets[setId].count; i++)
        width = DisplayTextAndGetWidth(sScrollingSets[setId].set[i].name, width);

    width = ConvertPixelWidthToTileWidth(width);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, width);
    windowId = CreateWindowFromRect(left, top, width, maxShowed * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    CopyWindowToVram(windowId, 3);

    gMultiuseListMenuTemplate = sMultichoiceListTemplate;
    gMultiuseListMenuTemplate.windowId = windowId;
    gMultiuseListMenuTemplate.items = sScrollingSets[setId].set;
    gMultiuseListMenuTemplate.totalItems = sScrollingSets[setId].count;
    gMultiuseListMenuTemplate.maxShowed = maxShowed;

    taskId = CreateTask(Task_ScrollingMultichoiceInput, 0);
    gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
    gTasks[taskId].data[1] = gSpecialVar_0x8008;
    gTasks[taskId].data[2] = windowId;
}

static void Task_ScrollingMultichoiceInput(u8 taskId)
{
    bool32 done = FALSE;
    s32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    switch (input)
    {
    case LIST_HEADER:
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        if (gTasks[taskId].data[1])
        {
            gSpecialVar_Result = 0x7F;
            done = TRUE;
        }
        break;
    default:
        gSpecialVar_Result = input;
        done = TRUE;
        break;
    }

    if (done)
    {
        DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);
        RemoveWindow(gTasks[taskId].data[2]);
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}
