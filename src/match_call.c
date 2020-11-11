#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/trainers.h"

struct MatchCallState
{
    u32 minutes;
    u16 trainerId;
    u8 stepCounter;
    u8 triggeredFromScript;
};

struct MatchCallTrainerTextInfo
{
    u16 trainerId;
    u16 unused;
    u16 battleTopicTextIds[3];
    u16 generalTextId;
    u8 battleFrontierRecordStreakTextIndex;
    u16 sameRouteMatchCallTextId;
    u16 differentRouteMatchCallTextId;
};

struct MatchCallText
{
    const u8 *text;
    s8 stringVarFuncIds[3];
};

struct MultiTrainerMatchCallText
{
    u16 trainerId;
    const u8 *text;
};

struct BattleFrontierStreakInfo
{
    u16 facilityId;
    u16 streak;
};

EWRAM_DATA struct MatchCallState gMatchCallState = {0};
EWRAM_DATA struct BattleFrontierStreakInfo gBattleFrontierStreakInfo = {0};

static u32 GetCurrentTotalMinutes(struct Time *);
static u32 GetNumRegisteredNPCs(void);
static u32 GetActiveMatchCallTrainerId(u32);
static int GetTrainerMatchCallId(int);
static void StartMatchCall(void);
static void ExecuteMatchCall(u8);
static void DrawMatchCallTextBoxBorder(u32, u32, u32);
static void sub_8196694(u8);
static void InitMatchCallTextPrinter(int, const u8 *);
static bool32 ExecuteMatchCallTextPrinter(int);
static const struct MatchCallText *GetSameRouteMatchCallText(int, u8 *);
static const struct MatchCallText *GetDifferentRouteMatchCallText(int, u8 *);
static const struct MatchCallText *GetBattleMatchCallText(int, u8 *);
static const struct MatchCallText *GetGeneralMatchCallText(int, u8 *);
static bool32 sub_8196D74(int);
static void BuildMatchCallString(int, const struct MatchCallText *, u8 *);
static u16 GetFrontierStreakInfo(u16, u32 *);
static void PopulateMatchCallStringVars(int, const s8 *);
static void PopulateMatchCallStringVar(int, int, u8 *);
static bool32 LoadMatchCallWindowGfx(u8);
static bool32 MoveMatchCallWindowToVram(u8);
static bool32 PrintMatchCallIntroEllipsis(u8);
static bool32 sub_81962B0(u8);
static bool32 sub_81962D8(u8);
static bool32 sub_8196330(u8);
static bool32 sub_8196390(u8);
static bool32 sub_81963F0(u8);
static void PopulateTrainerName(int, u8 *);
static void PopulateMapName(int, u8 *);
static void PopulateSpeciesFromTrainerLocation(int, u8 *);
static void PopulateSpeciesFromTrainerParty(int, u8 *);
static void PopulateBattleFrontierFacilityName(int, u8 *);
static void PopulateBattleFrontierStreak(int, u8 *);

#define TEXT_ID(topic, id) (((topic) << 8) | ((id) & 0xFF))

static const struct MatchCallTrainerTextInfo sMatchCallTrainers[] =
{
    
    {
        .trainerId = 0,
    },
};

static const struct MatchCallText *const sMatchCallBattleTopics[] =
{
};

static const struct MatchCallText *const sMatchCallBattleRequestTopics[] =
{
};

static const struct MatchCallText *const sMatchCallGeneralTopics[] =
{
};

extern const u8 gBirchDexRatingText_AreYouCurious[];
extern const u8 gBirchDexRatingText_SoYouveSeenAndCaught[];
extern const u8 gBirchDexRatingText_OnANationwideBasis[];

static u32 GetCurrentTotalMinutes(struct Time *time)
{
    return time->days * 1440 + time->hours * 60 + time->minutes;
}

bool32 TryStartMatchCall(void)
{
    return FALSE;
}

void StartMatchCallFromScript(const u8 *message)
{
    gMatchCallState.triggeredFromScript = 1;
    StartMatchCall();
}

bool32 IsMatchCallTaskActive(void)
{
    return FuncIsActiveTask(ExecuteMatchCall);
}

static void StartMatchCall(void)
{
    if (!gMatchCallState.triggeredFromScript)
    {
        ScriptContext2_Enable();
        FreezeObjectEvents();
        sub_808B864();
        sub_808BCF4();
    }

    PlaySE(SE_POKENAV_CALL);
    CreateTask(ExecuteMatchCall, 1);
}

static const u16 sUnknown_0860EA4C[] = INCBIN_U16("graphics/unknown/unknown_60EA4C.gbapal");
static const u8 sUnknown_0860EA6C[] = INCBIN_U8("graphics/interface/menu_border.4bpp");
static const u16 sPokeNavIconPalette[] = INCBIN_U16("graphics/pokenav/icon.gbapal");
static const u32 sPokeNavIconGfx[] = INCBIN_U32("graphics/pokenav/icon.4bpp.lz");

static const u8 sText_PokenavCallEllipsis[] = _("………………\p");

static bool32 (*const sMatchCallTaskFuncs[])(u8) =
{
    LoadMatchCallWindowGfx,
    MoveMatchCallWindowToVram,
    PrintMatchCallIntroEllipsis,
    sub_81962B0,
    sub_81962D8,
    sub_8196330,
    sub_8196390,
    sub_81963F0,
};

static void ExecuteMatchCall(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (sMatchCallTaskFuncs[taskData[0]](taskId))
    {
        taskData[0]++;
        taskData[1] = 0;
        if ((u16)taskData[0] > 7)
            DestroyTask(taskId);
    }
}

static const struct WindowTemplate sMatchCallTextWindow =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x200
};

static bool32 LoadMatchCallWindowGfx(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    taskData[2] = AddWindow(&sMatchCallTextWindow);
    if (taskData[2] == 0xFF)
    {
        DestroyTask(taskId);
        return FALSE;
    }

    if (LoadBgTiles(0, sUnknown_0860EA6C, sizeof(sUnknown_0860EA6C), 0x270) == 0xFFFF)
    {
        RemoveWindow(taskData[2]);
        DestroyTask(taskId);
        return FALSE;
    }

    if (!DecompressAndCopyTileDataToVram(0, sPokeNavIconGfx, 0, 0x279, 0))
    {
        RemoveWindow(taskData[2]);
        DestroyTask(taskId);
        return FALSE;
    }

    FillWindowPixelBuffer(taskData[2], PIXEL_FILL(8));
    LoadPalette(sUnknown_0860EA4C, 0xE0, 0x20);
    LoadPalette(sPokeNavIconPalette, 0xF0, 0x20);
    ChangeBgY(0, -0x2000, 0);
    return TRUE;
}

static bool32 MoveMatchCallWindowToVram(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (FreeTempTileDataBuffersIfPossible())
        return FALSE;

    PutWindowTilemap(taskData[2]);
    DrawMatchCallTextBoxBorder(taskData[2], 0x270, 14);
    WriteSequenceToBgTilemapBuffer(0, 0xF279, 1, 15, 4, 4, 17, 1);
    taskData[5] = CreateTask(sub_8196694, 10);
    CopyWindowToVram(taskData[2], 2);
    CopyBgTilemapBufferToVram(0);
    return TRUE;
}

static bool32 PrintMatchCallIntroEllipsis(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        InitMatchCallTextPrinter(taskData[2], sText_PokenavCallEllipsis);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_81962B0(u8 taskId)
{
    if (ChangeBgY(0, 0x600, 1) >= 0)
    {
        ChangeBgY(0, 0, 0);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_81962D8(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!ExecuteMatchCallTextPrinter(taskData[2]))
    {
        FillWindowPixelBuffer(taskData[2], PIXEL_FILL(8));
        if (!gMatchCallState.triggeredFromScript)
            SelectMatchCallMessage(gMatchCallState.trainerId, gStringVar4);

        InitMatchCallTextPrinter(taskData[2], gStringVar4);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_8196330(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!ExecuteMatchCallTextPrinter(taskData[2]) && !IsSEPlaying() && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        FillWindowPixelBuffer(taskData[2], PIXEL_FILL(8));
        CopyWindowToVram(taskData[2], 2);
        PlaySE(SE_POKENAV_HANG_UP);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_8196390(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (ChangeBgY(0, 0x600, 2) <= -0x2000)
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 14, 30, 6);
        DestroyTask(taskData[5]);
        RemoveWindow(taskData[2]);
        CopyBgTilemapBufferToVram(0);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_81963F0(u8 taskId)
{
    u8 playerObjectId;
    if (!IsDma3ManagerBusyWithBgCopy() && !IsSEPlaying())
    {
        ChangeBgY(0, 0, 0);
        if (!gMatchCallState.triggeredFromScript)
        {
            LoadMessageBoxAndBorderGfx();
            playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
            ScriptMovement_UnfreezeObjectEvents();
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
        }

        return TRUE;
    }

    return FALSE;
}

static void DrawMatchCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId)
{
    int bg, x, y, width, height;
    int tileNum;

    bg = GetWindowAttribute(windowId, WINDOW_BG);
    x = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    y = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    height = GetWindowAttribute(windowId, WINDOW_HEIGHT);
    tileNum = tileOffset + GetBgAttribute(bg, BG_ATTR_BASETILE);

    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 0), x - 1, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 1), x, y - 1, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 2), x + width, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 3), x - 1, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 4), x + width, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 5), x - 1, y + height, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 6), x, y + height, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 7), x + width, y + height, 1, 1);
}

static void InitMatchCallTextPrinter(int windowId, const u8 *str)
{
    struct TextPrinterTemplate printerTemplate;
    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = 1;
    printerTemplate.x = 32;
    printerTemplate.y = 1;
    printerTemplate.currentX = 32;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 10;
    printerTemplate.bgColor = 8;
    printerTemplate.shadowColor = 14;
    gTextFlags.useAlternateDownArrow = 0;

    AddTextPrinter(&printerTemplate, GetPlayerTextSpeedDelay(), NULL);
}

static bool32 ExecuteMatchCallTextPrinter(int windowId)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = 1;
    else
        gTextFlags.canABSpeedUpPrint = 0;

    RunTextPrinters();
    return IsTextPrinterActive(windowId);
}

static void sub_8196694(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (++taskData[0] > 8)
    {
        taskData[0] = 0;
        if (++taskData[1] > 7)
            taskData[1] = 0;

        taskData[2] = (taskData[1] * 16) + 0x279;
        WriteSequenceToBgTilemapBuffer(0, taskData[2] | ~0xFFF, 1, 15, 4, 4, 17, 1);
        CopyBgTilemapBufferToVram(0);
    }
}

bool32 SelectMatchCallMessage(int trainerId, u8 *str)
{
    u32 matchCallId;
    const struct MatchCallText *matchCallText;
    bool32 retVal = FALSE;

    matchCallId = GetTrainerMatchCallId(trainerId);
    gBattleFrontierStreakInfo.facilityId = 0;
    if (sub_8196D74(matchCallId))
    {
        matchCallText = GetDifferentRouteMatchCallText(matchCallId, str);
        retVal = TRUE;
    }
    else if (Random() % 3)
    {
        matchCallText = GetBattleMatchCallText(matchCallId, str);
    }
    else
    {
        matchCallText = GetGeneralMatchCallText(matchCallId, str);
    }

    BuildMatchCallString(matchCallId, matchCallText, str);
    return retVal;
}

static int GetTrainerMatchCallId(int trainerId)
{
    int i = 0;
    while (1)
    {
        if (sMatchCallTrainers[i].trainerId == trainerId)
            return i;
        else
            i++;
    }
}

static const struct MatchCallText *GetSameRouteMatchCallText(int matchCallId, u8 *str)
{
    u16 textId = sMatchCallTrainers[matchCallId].sameRouteMatchCallTextId;
    int mask = 0xFF;
    u32 topic = (textId >> 8) - 1;
    u32 id = (textId & mask) - 1;
    return &sMatchCallBattleRequestTopics[topic][id];
}

static const struct MatchCallText *GetDifferentRouteMatchCallText(int matchCallId, u8 *str)
{
    u16 textId = sMatchCallTrainers[matchCallId].differentRouteMatchCallTextId;
    int mask = 0xFF;
    u32 topic = (textId >> 8) - 1;
    u32 id = (textId & mask) - 1;
    return &sMatchCallBattleRequestTopics[topic][id];
}

static const struct MatchCallText *GetBattleMatchCallText(int matchCallId, u8 *str)
{
    int mask;
    u32 textId, topic, id;
    
    topic = Random() % 3;
    textId = sMatchCallTrainers[matchCallId].battleTopicTextIds[topic];
    if (!textId)
        SpriteCallbackDummy(NULL); // leftover debugging ???

    mask = 0xFF;
    topic = (textId >> 8) - 1;
    id = (textId & mask) - 1;
    return &sMatchCallBattleTopics[topic][id];
}

static const struct MatchCallText *GetGeneralMatchCallText(int matchCallId, u8 *str)
{
    int i;
    int count;
    u32 topic, id;
    u16 rand;
    u16 var3;

    rand = Random();
    if (!(rand & 1))
    {
        for (count = 0, i = 0; i < NUM_FRONTIER_FACILITIES; i++)
        {
            if (GetFrontierStreakInfo(i, &topic) > 1)
                count++;
        }

        if (count)
        {
            count = Random() % count;
            for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
            {
                gBattleFrontierStreakInfo.streak = GetFrontierStreakInfo(i, &topic);
                if (gBattleFrontierStreakInfo.streak < 2)
                    continue;

                if (!count)
                    break;

                count--;
            }

            gBattleFrontierStreakInfo.facilityId = i;
            id = sMatchCallTrainers[matchCallId].battleFrontierRecordStreakTextIndex - 1;
            return &sMatchCallGeneralTopics[topic][id];
        }
    }

    topic = (sMatchCallTrainers[matchCallId].generalTextId >> 8) - 1;
    id = (sMatchCallTrainers[matchCallId].generalTextId & 0xFF) - 1;
    return &sMatchCallGeneralTopics[topic][id];
}

static void BuildMatchCallString(int matchCallId, const struct MatchCallText *matchCallText, u8 *str)
{
    PopulateMatchCallStringVars(matchCallId, matchCallText->stringVarFuncIds);
    StringExpandPlaceholders(str, matchCallText->text);
}

static u8 *const sMatchCallTextStringVars[] = { gStringVar1, gStringVar2, gStringVar3 };

static void PopulateMatchCallStringVars(int matchCallId, const s8 *stringVarFuncIds)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (stringVarFuncIds[i] >= 0)
            PopulateMatchCallStringVar(matchCallId, stringVarFuncIds[i], sMatchCallTextStringVars[i]);
    }
}

static void (*const sPopulateMatchCallStringVarFuncs[])(int, u8 *) =
{
    PopulateTrainerName,
    PopulateMapName,
    PopulateSpeciesFromTrainerLocation,
    PopulateSpeciesFromTrainerParty,
    PopulateBattleFrontierFacilityName,
    PopulateBattleFrontierStreak,
};

static void PopulateMatchCallStringVar(int matchCallId, int funcId, u8 *destStr)
{
    sPopulateMatchCallStringVarFuncs[funcId](matchCallId, destStr);
}

static const struct MultiTrainerMatchCallText sMultiTrainerMatchCallTexts[] =
{
    { .trainerId = TRAINER_KIRA_AND_DAN_1, .text = gText_Kira },
    { .trainerId = TRAINER_AMY_AND_LIV_1,  .text = gText_Amy },
    { .trainerId = TRAINER_JOHN_AND_JAY_1, .text = gText_John },
    { .trainerId = TRAINER_LILA_AND_ROY_1, .text = gText_Roy },
    { .trainerId = TRAINER_GABBY_AND_TY_1, .text = gText_Gabby },
    { .trainerId = TRAINER_ANNA_AND_MEG_1, .text = gText_Anna },
};

static void PopulateTrainerName(int matchCallId, u8 *destStr)
{
    u32 i;
    u16 trainerId = sMatchCallTrainers[matchCallId].trainerId;
    for (i = 0; i < 6; i++)
    {
        if (sMultiTrainerMatchCallTexts[i].trainerId == trainerId)
        {
            StringCopy(destStr, sMultiTrainerMatchCallTexts[i].text);
            return;
        }
    }

    StringCopy(destStr, gTrainers[trainerId].trainerName);
}

static void PopulateMapName(int matchCallId, u8 *destStr)
{

}

static u8 GetLandEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 20)
        return 0;
    else if (rand >= 20 && rand < 40)
        return 1;
    else if (rand >= 40 && rand < 50)
        return 2;
    else if (rand >= 50 && rand < 60)
        return 3;
    else if (rand >= 60 && rand < 70)
        return 4;
    else if (rand >= 70 && rand < 80)
        return 5;
    else if (rand >= 80 && rand < 85)
        return 6;
    else if (rand >= 85 && rand < 90)
        return 7;
    else if (rand >= 90 && rand < 94)
        return 8;
    else if (rand >= 94 && rand < 98)
        return 9;
    else if (rand >= 98 && rand < 99)
        return 10;
    else
        return 11;
}

static u8 GetWaterEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 60)
        return 0;
    else if (rand >= 60 && rand < 90)
        return 1;
    else if (rand >= 90 && rand < 95)
        return 2;
    else if (rand >= 95 && rand < 99)
        return 3;
    else
        return 4;
}

static void PopulateSpeciesFromTrainerLocation(int matchCallId, u8 *destStr)
{
    u16 species[2];
    int numSpecies;
    u8 slot;
    int i = 0;

    if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED)) // ??? This check is nonsense.
    {
        if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED))
        {
            numSpecies = 0;
            if (gWildMonHeaders[i].landMonsInfo)
            {
                slot = GetLandEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].landMonsInfo->wildPokemon[slot].species;
                numSpecies++;
            }

            if (gWildMonHeaders[i].waterMonsInfo)
            {
                slot = GetWaterEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].waterMonsInfo->wildPokemon[slot].species;
                numSpecies++;
            }

            if (numSpecies)
            {
                StringCopy(destStr, gSpeciesNames[species[Random() % numSpecies]]);
                return;
            }
        }
    }

    destStr[0] = EOS;
}

static void PopulateSpeciesFromTrainerParty(int matchCallId, u8 *destStr)
{
    u16 trainerId;
    union TrainerMonPtr party;
    u8 monId;
    const u8 *speciesName;

    trainerId = 0;
    party = gTrainers[trainerId].party;
    monId = Random() % gTrainers[trainerId].partySize;

    switch (gTrainers[trainerId].partyFlags)
    {
    case 0:
    default:
        speciesName = gSpeciesNames[party.NoItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        speciesName = gSpeciesNames[party.NoItemCustomMoves[monId].species];
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemCustomMoves[monId].species];
        break;
    }

    StringCopy(destStr, speciesName);
}

static const u8 *const sBattleFrontierFacilityNames[] =
{
    gText_BattleTower2,
    gText_BattleDome,
    gText_BattlePalace,
    gText_BattleArena,
    gText_BattlePike,
    gText_BattleFactory,
    gText_BattlePyramid,
};

static void PopulateBattleFrontierFacilityName(int matchCallId, u8 *destStr)
{
    StringCopy(destStr, sBattleFrontierFacilityNames[gBattleFrontierStreakInfo.facilityId]);
}

static void PopulateBattleFrontierStreak(int matchCallId, u8 *destStr)
{
    int i = 0;
    int streak = gBattleFrontierStreakInfo.streak;
    while (streak != 0)
    {
        streak /= 10;
        i++;
    }
    
    ConvertIntToDecimalStringN(destStr, gBattleFrontierStreakInfo.streak, STR_CONV_MODE_LEFT_ALIGN, i);
}

static const u16 sBadgeFlags[NUM_BADGES] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
};

static int GetNumOwnedBadges(void)
{
    u32 i;

    for (i = 0; i < NUM_BADGES; i++)
    {
        if (!FlagGet(sBadgeFlags[i]))
            break;
    }

    return i;
}

static bool32 sub_8196D74(int matchCallId)
{
    return FALSE;
}

static u16 GetFrontierStreakInfo(u16 facilityId, u32 *topicTextId)
{
    int i;
    int j;
    u16 streak = 0;

    switch (facilityId)
    {
    case FRONTIER_FACILITY_DOME:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.domeRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.domeRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 3;
        break;
    case FRONTIER_FACILITY_FACTORY:
        for (i = 0; i < 2; i++)
        {
            // BUG: should be looking at Battle Factory records.
            if (streak < gSaveBlock2Ptr->frontier.pikeRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.pikeRecordStreaks[i];
        }
        *topicTextId = 4;
        break;
    case FRONTIER_FACILITY_TOWER:
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 2;
        break;
    case FRONTIER_FACILITY_PALACE:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 2;
        break;
    case FRONTIER_FACILITY_PIKE:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                // BUG: should be looking at Battle Pike records.
                if (streak < gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 2;
        break;
    case FRONTIER_FACILITY_ARENA:
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.arenaRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.arenaRecordStreaks[i];
        }
        *topicTextId = 2;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i];
        }
        *topicTextId = 5;
        break;
    }

    return streak;
}

static u8 GetPokedexRatingLevel(u16 numSeen)
{
    if (numSeen < 10)
        return 0;
    if (numSeen < 20)
        return 1;
    if (numSeen < 30)
        return 2;
    if (numSeen < 40)
        return 3;
    if (numSeen < 50)
        return 4;
    if (numSeen < 60)
        return 5;
    if (numSeen < 70)
        return 6;
    if (numSeen < 80)
        return 7;
    if (numSeen < 90)
        return 8;
    if (numSeen < 100)
        return 9;
    if (numSeen < 110)
        return 10;
    if (numSeen < 120)
        return 11;
    if (numSeen < 130)
        return 12;
    if (numSeen < 140)
        return 13;
    if (numSeen < 150)
        return 14;
    if (numSeen < 160)
        return 15;
    if (numSeen < 170)
        return 16;
    if (numSeen < 180)
        return 17;
    if (numSeen < 190)
        return 18;
    if (numSeen < 200)
        return 19;
    
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DEOXYS), FLAG_GET_CAUGHT))
        numSeen--;
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_JIRACHI), FLAG_GET_CAUGHT))
        numSeen--;

    if (numSeen < 200)
        return 19;
    else
        return 20;
}

static const u8 *const sBirchDexRatingTexts[] =
{
    gBirchDexRatingText_LessThan10,
    gBirchDexRatingText_LessThan20,
    gBirchDexRatingText_LessThan30,
    gBirchDexRatingText_LessThan40,
    gBirchDexRatingText_LessThan50,
    gBirchDexRatingText_LessThan60,
    gBirchDexRatingText_LessThan70,
    gBirchDexRatingText_LessThan80,
    gBirchDexRatingText_LessThan90,
    gBirchDexRatingText_LessThan100,
    gBirchDexRatingText_LessThan110,
    gBirchDexRatingText_LessThan120,
    gBirchDexRatingText_LessThan130,
    gBirchDexRatingText_LessThan140,
    gBirchDexRatingText_LessThan150,
    gBirchDexRatingText_LessThan160,
    gBirchDexRatingText_LessThan170,
    gBirchDexRatingText_LessThan180,
    gBirchDexRatingText_LessThan190,
    gBirchDexRatingText_LessThan200,
    gBirchDexRatingText_DexCompleted,
};

void BufferPokedexRatingForMatchCall(u8 *destStr)
{
    int numSeen, numCaught;
    u8 *str;
    u8 dexRatingLevel;

    u8 *buffer = Alloc(0x3E8);
    if (!buffer)
    {
        destStr[0] = EOS;
        return;
    }

    numSeen = GetHoennPokedexCount(FLAG_GET_SEEN);
    numCaught = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    ConvertIntToDecimalStringN(gStringVar1, numSeen, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, numCaught, STR_CONV_MODE_LEFT_ALIGN, 3);
    dexRatingLevel = GetPokedexRatingLevel(numCaught);
    str = StringCopy(buffer, gBirchDexRatingText_AreYouCurious);
    str[0] = CHAR_PROMPT_CLEAR;
    str++;
    str = StringCopy(str, gBirchDexRatingText_SoYouveSeenAndCaught);
    str[0] = CHAR_PROMPT_CLEAR;
    str++;
    StringCopy(str, sBirchDexRatingTexts[dexRatingLevel]);
    str = StringExpandPlaceholders(destStr, buffer);

    if (IsNationalPokedexEnabled())
    {
        str[0] = CHAR_PROMPT_CLEAR;
        str++;
        numSeen = GetNationalPokedexCount(FLAG_GET_SEEN);
        numCaught = GetNationalPokedexCount(FLAG_GET_CAUGHT);
        ConvertIntToDecimalStringN(gStringVar1, numSeen, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, numCaught, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(str, gBirchDexRatingText_OnANationwideBasis);
    }

    Free(buffer);
}

void sub_8197184(u32 windowId, u32 destOffset, u32 paletteId)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    LoadBgTiles(bg, sUnknown_0860EA6C, 0x100, destOffset);
    LoadPalette(sUnknown_0860EA4C, paletteId << 4, 0x20);
}

void sub_81971C4(u32 windowId, u32 tileOffset, u32 paletteId)
{
    DrawMatchCallTextBoxBorder(windowId, tileOffset, paletteId);
}
