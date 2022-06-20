#include "global.h"
#include "main.h"
#include "data.h"
#include "bg.h"
#include "window.h"
#include "factions.h"
#include "script.h"
#include "string_util.h"
#include "event_data.h"
#include "ach_atlas.h"
#include "pidgey_ui_sys.h"
#include "menu.h"
#include "palette.h"
#include "string_util.h"
#include "ach_atlas.h"

const u8 gFactionNames[8][15] = {
    [FACTION_NATURALISTS] = _("Naturalists"),
    [FACTION_STUDENTS] = _("Students"),
    [FACTION_NOBLES] = _("Nobles"),
    [FACTION_POKEFANS] = _("Pokéfans"),
    [FACTION_OUTCASTS] = _("Outcasts"),
    [FACTION_PROFESSIONALS] = _("Professionals"),
    [FACTION_POKEMON_LEAGUE] = _("Pokémon League"),
    [FACTION_OTHERS] = _("Unaffiliated")
};

extern const u8 RyuNaturalistsDailyQuest[];
extern const u8 RyuStudentsDailyQuest[];
extern const u8 RyuNoblesDailyQuest[];
extern const u8 RyuPokefansDailyQuest[];
extern const u8 RyuOutcastsDailyQuest[];
extern const u8 RyuProfessionalsDailyQuest[];
extern const u8 RyuAthletesDailyQuest[];

void RyuFactions_ResetAllStanding(void)
{
    u8 i = 0;
    for (i = 0; i < 7; i++)
        {
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[i] = 100;//new default/neutral standing is 100
        }
}


void RyuDebug_ViewFactionRelations(void)
{
    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_POKEFANS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NATURALISTS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_OUTCASTS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar1, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_PROFESSIONALS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar2, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NOBLES], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar3, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_STUDENTS], STR_CONV_MODE_LEFT_ALIGN, 3);
}

bool8 ScrCmd_checkfaction(struct ScriptContext *ctx)
{
    u16 trainerToCheck = (VarGet(ScriptReadHalfword(ctx)));
    u8 targetTrainerFaction = gTrainers[trainerToCheck].trainerFaction;
    u8 currentStanding = gSaveBlock1Ptr->gNPCTrainerFactionRelations[targetTrainerFaction];

    gSpecialVar_Result = targetTrainerFaction;
    ConvertIntToDecimalStringN(gRyuStringVar4, currentStanding, STR_CONV_MODE_LEFT_ALIGN, 3);
}

u8 GetFactionId(u16 trainerId)
{
    return (gTrainers[trainerId].trainerFaction);
}

u8 GetFactionStanding(u16 trainerId) //this should return the value of player's standing in trainerId's faction
{
    return gSaveBlock1Ptr->gNPCTrainerFactionRelations[(gTrainers[trainerId].trainerFaction)];
}

u32 ConvertFactionStandingToState(u32 standing)
{
    switch(standing)
    {
        default:
            return FACTION_STAND_INVALID;
        case 0:
            return FACTION_STAND_WORST;
        case 1 ... 19:
            return FACTION_STAND_REALLYBAD;
        case 20 ... 79:
            return FACTION_STAND_BAD;
        case 80 ... 120:
            return FACTION_STAND_NEUTRAL;
        case 121 ... 179:
            return FACTION_STAND_GOOD;
        case 180 ... 199:
            return FACTION_STAND_HIGH;
        case 200: 
            return FACTION_STAND_BEST;
    }
}

const u8 gText_RyuDailyNoneType[] = _("None");
const u8 gText_RyuDailyFetchType[] = _("Fetch");
const u8 gText_RyuDailyCaptureType[] = _("Capture");
const u8 gText_RyuDailyTravelType[] = _("Travel");
const u8 gText_RyuDailyHatchType[] = _("Hatch");

void BufferDailyQuestType (void)
{
    switch (VarGet(VAR_RYU_DAILY_QUEST_TYPE))
    {
        case 0:
            StringCopy(gStringVar2, gText_RyuDailyNoneType);
            break;
        case 1:
            StringCopy(gStringVar2, gText_RyuDailyFetchType);
            break;
        case 2:
            StringCopy(gStringVar2, gText_RyuDailyCaptureType);
            break;
        case 3:
            StringCopy(gStringVar2, gText_RyuDailyTravelType);
            break;
        case 4:
            StringCopy(gStringVar2, gText_RyuDailyHatchType);
            break;
    }
}

void RyuAdjustFactionValueInternal(u8 id, u8 amount, bool8 negative)
{
    s16 currentStanding = gSaveBlock1Ptr->gNPCTrainerFactionRelations[id]; //i need this to be able to hold values larger than 255 and lower than 0, just in case.
    if (negative)
    {
        if (currentStanding - amount >= 0)//new minimum value is 0.
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] -= amount;
        else
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] = 0;
    }
    else
    {
        if (currentStanding + amount <= 200)//new maximum value is 200.
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] += amount;
        else
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] = 200;
    }
}

// If/when there are more switches like this in the future, it might be worth making an array of opposites.
void RyuAdjustOpposingFactionValues(u8 id, u8 amount, bool8 negative)
{
    switch (id)
    {
    case FACTION_NATURALISTS:
        RyuAdjustFactionValueInternal(FACTION_NOBLES, amount, negative);
        break;
    case FACTION_STUDENTS:
        RyuAdjustFactionValueInternal(FACTION_OUTCASTS, amount, negative);
        break;
    case FACTION_NOBLES:
        RyuAdjustFactionValueInternal(FACTION_NATURALISTS, amount, negative);
        break;
    case FACTION_POKEFANS:
        RyuAdjustFactionValueInternal(FACTION_PROFESSIONALS, amount, negative);
        break;
    case FACTION_OUTCASTS:
        RyuAdjustFactionValueInternal(FACTION_STUDENTS, amount, negative);
        break;
    case FACTION_PROFESSIONALS:
        RyuAdjustFactionValueInternal(FACTION_POKEFANS, amount, negative);
        break;
    }
}

bool8 ScrCmd_changefactionstanding(struct ScriptContext *ctx)
{
    u8 factionId = ScriptReadByte(ctx);
    u8 amount = ScriptReadByte(ctx);
    bool8 negative = ScriptReadByte(ctx);

    RyuAdjustFactionValueInternal(factionId, amount, negative);
    RyuAdjustOpposingFactionValues(factionId, amount, !negative);
    return FALSE;
}

void RyuCheckForFactionAchievements(void)
{
    u8 i;

    for(i = 0; i < FACTION_OTHERS; i++)
    {
        if (gSaveBlock1Ptr->gNPCTrainerFactionRelations[i] > 174)
            if (CheckAchievement(42 + i) == FALSE)
                GiveAchievement(42 + i);
    }
    if ((gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_POKEMON_LEAGUE] < 13) && CheckAchievement(ACH_THE_WARRIOR) == FALSE)
        GiveAchievement(ACH_THE_WARRIOR);
}

bool8 ScrCmd_checkfactionstanding(struct ScriptContext *ctx)
{
    u8 factionId = ScriptReadByte(ctx);
    u8 amount = ScriptReadByte(ctx); //no longer doing negatives, script logic doesn't like it.

    if (gSaveBlock1Ptr->gNPCTrainerFactionRelations[factionId] >= amount)//just see if factionid's standing is at or above amount
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;

    return FALSE;
}

const u8 *RyuGetFactionDailyQuestScriptPtr(u8 factionId)
{
    switch (factionId)
    {
        case FACTION_NATURALISTS:
            return RyuNaturalistsDailyQuest;
        case FACTION_STUDENTS:
            return RyuStudentsDailyQuest;
        case FACTION_NOBLES:
            return RyuNoblesDailyQuest;
        case FACTION_POKEFANS:
            return RyuPokefansDailyQuest;
        case FACTION_OUTCASTS:
            return RyuOutcastsDailyQuest;
        case FACTION_PROFESSIONALS:
            return RyuProfessionalsDailyQuest;
        case FACTION_POKEMON_LEAGUE:
            return NULL;
        case FACTION_OTHERS:
            return NULL;
    }
}


void ClearDailyQuestData(void)
{
    VarSet(VAR_RYU_DAILY_QUEST_TYPE, 1000);
    VarSet(VAR_RYU_DAILY_QUEST_TARGET, 1000);
    VarSet(VAR_RYU_DAILY_QUEST_DATA, 1000);
    FlagClear(FLAG_DAILY_QUEST_ACTIVE);
    VarSet(VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_OTHERS);
}

void RyuSetFactionStandingPokemonLeagueDebug(void)
{
    gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_POKEMON_LEAGUE] = 12;
}

 /* FACTION STANDING UI CODE */ 

enum
{
    WIN_FACTION_STANDING_INFO,
    WIN_FACTION_NAMES,
    WIN_FACTION_STANDING,
    WIN_FACTION_BUTTON_INFO
};

static const struct WindowTemplate sFactionWindows[] =
{
    [WIN_FACTION_STANDING_INFO] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 17,
        .paletteNum = 13,
        .baseBlock = 1,
    },
    [WIN_FACTION_NAMES] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 13,
        .height = 14,
        .paletteNum = 13,
        .baseBlock = 1,
    },
    [WIN_FACTION_STANDING] =
    {
        .bg = 0,
        .tilemapLeft = 27,
        .tilemapTop = 4,
        .width = 2,
        .height = 13,
        .paletteNum = 13,
        .baseBlock = 1+13*15,
    },
    [WIN_FACTION_BUTTON_INFO] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 18,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1+28*19,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sFactionBGTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
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
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

void CB2_OpenJournal();
static void Task_HandleFactionUI(u8 taskId);
static void DrawFactionStandingText(u8);

static const u8 sFactionTiles[] = INCBIN_U8("graphics/journal/factions_tiles.4bpp"); 
static const u16 sFactionMap[] = INCBIN_U16("graphics/journal/factions_tiles.bin"); 
static const u16 sFactionPal[] = INCBIN_U16("graphics/journal/factions_tiles.gbapal"); 
static const u16 sFactionTextPal[] = INCBIN_U16("graphics/journal/factionsui_textpal.gbapal");

static const u8 sFactionInfoTiles[] = INCBIN_U8("graphics/journal/factionsui_textwindow.4bpp"); 
static const u16 sFactionInfoMap[] = INCBIN_U16("graphics/journal/factionsui_textwindow.bin"); 
static const u16 sFactionInfoPal[] = INCBIN_U16("graphics/journal/factionsui_textwindow.gbapal"); 

static const u8 sStandingInfo[] = 
_("When you increase standing for one faction, the\n\
opposed faction's standing will fall. \n\
The Colors are as follows:\n\
{COLOR 13}{SHADOW 14}Green: 200{COLOR 7}{SHADOW 8}, {COLOR 10}{SHADOW 12}Blue: 180 - 199{COLOR 7}{SHADOW 8}, {COLOR 9}{SHADOW 11}Cyan: 120 - 179\n\
{COLOR 7}{SHADOW 8}White: 81 - 119\n\
{COLOR 5}{SHADOW 6}Yellow: 51 - 80{COLOR 7}{SHADOW 8}, {COLOR 3}{SHADOW 4}Orange: 1 - 50{COLOR 7}{SHADOW 8}, {COLOR 1}{SHADOW 2}Red: 0\n\
\n{COLOR 7}{SHADOW 8}When you've reached 175, you can embark on\n\
the faction's special quest. When you're at or\n\
below 50, opposed trainers will be stronger,\n\
and below 20 will make them much stronger.");

static const struct UIData sJournalUIData =
{
    .returnCallback = CB2_OpenJournal,
    .taskFunc = Task_HandleFactionUI,
    .customInitFunc = DrawFactionStandingText,
    .bgData = {
        [0] = {
            .isVisible = TRUE,
            .palSlot = 0,
            .palCount = 16,
            .palette = sFactionPal,
            .tilemap = sFactionMap,
            .mapSize = sizeof(sFactionMap),
            .tiles = sFactionTiles,
            .tileSize = sizeof(sFactionTiles)
        },
        [1] = {
            .isVisible = TRUE,
            .palSlot = 1,
            .palCount = 16,
            .palette = sFactionInfoPal,
            .tilemap = sFactionInfoMap,
            .mapSize = sizeof(sFactionInfoMap),
            .tiles = sFactionInfoTiles,
            .tileSize = sizeof(sFactionInfoTiles)
        },
        [2] = {0},
    },
    .bgTemplates = sFactionBGTemplates,
    .windowTemplates = sFactionWindows,
};

void CB2_OpenFactionUI(void)
{
    StartPidgeyUI(&sJournalUIData);
}
const static u8 sStandingColors[][3] = 
{
    {0, 7, 8},
    {0, 1, 2},
    {0, 3, 4},
    {0, 5, 6},
    {0, 7, 8},
    {0, 9, 11},
    {0, 10, 12},
    {0, 13, 14}
};

const static u8 sTextColor[] =
{
    TEXT_COLOR_TRANSPARENT, 
    TEXT_COLOR_DARK_GREY, 
    TEXT_COLOR_LIGHT_GREY,
};

static void DrawFactionStandingText(u8 taskId)
{
    u32 i;
    //u8 * ptr;
    //ptr = gStringVar1;
    //ptr = 
    LoadPalette(sFactionTextPal, 13*16, 32);
    PutWindowTilemap(WIN_FACTION_BUTTON_INFO);
    PutWindowTilemap(WIN_FACTION_STANDING);
    PutWindowTilemap(WIN_FACTION_NAMES);
    AddTextPrinterParameterized3(WIN_FACTION_BUTTON_INFO, 1, 0, 0, (u8[]){TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY}, 0xFF, (u8[])_("{L_BUTTON}{R_BUTTON}: Info"));
    for(i = 0; i < FACTION_OTHERS; i++)
    {
        u32 standing = gSaveBlock1Ptr->gNPCTrainerFactionRelations[i];
        u32 factionState = ConvertFactionStandingToState(standing);
        ConvertIntToDecimalStringN(gStringVar4, standing, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized3(WIN_FACTION_STANDING, 0, 0, i * 14, sStandingColors[factionState], 0xFF, gStringVar4);
        AddTextPrinterParameterized3(WIN_FACTION_NAMES, 0, 2, i * 14, sStandingColors[factionState], 0xFF, gFactionNames[i]);
    }
    CopyWindowToVram(WIN_FACTION_BUTTON_INFO, 3);
    CopyWindowToVram(WIN_FACTION_STANDING, 3);
    CopyWindowToVram(WIN_FACTION_NAMES, 3);
}

static void Task_HandleFactionUI(u8 taskId)
{
    switch(gTasks[taskId].data[0])
    {
    case 0:
        if(JOY_NEW(R_BUTTON | L_BUTTON))
        {
            gTasks[taskId].data[0] = 2;
            ClearStdWindowAndFrameToTransparent(WIN_FACTION_NAMES, FALSE);
            ClearStdWindowAndFrameToTransparent(WIN_FACTION_STANDING, FALSE);
            PutWindowTilemap(WIN_FACTION_STANDING_INFO);
            AddTextPrinterParameterized3(WIN_FACTION_STANDING_INFO, 0, 0, 0, sStandingColors[4], 0xFF, sStandingInfo);
            return;
        }
        break;
    case 1:
        if(JOY_NEW(R_BUTTON | L_BUTTON))
        {
            gTasks[taskId].data[0] = 3;
            ClearStdWindowAndFrameToTransparent(WIN_FACTION_STANDING_INFO, FALSE);
            return;
        }
        break;
    case 2:
        gTasks[taskId].data[0] = 1;
        CopyWindowToVram(WIN_FACTION_STANDING_INFO, 3);
        HideBg(1);
        return;
    case 3:
        gTasks[taskId].data[0] = 0;
        CopyWindowToVram(WIN_FACTION_STANDING_INFO, 3);
        DrawFactionStandingText(taskId);
        ShowBg(1);
        return;
    }
    if(JOY_NEW(B_BUTTON))
        ClosePidgeyUI(taskId);
}
