#include "scripted_encounters.h"
#include "global.h"
#include "random.h"
#include "sound.h"
#include "data.h"
#include "string_util.h"
#include "script_movement.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "task.h"
#include "event_data.h"
#include "field_message_box.h"
#include "script_pokemon_util.h"
#include "battle_setup.h"
#include "script.h"
#include "battle.h"
#include "ach_atlas.h"
#include "overworld_notif.h"
#include "main.h"
#include "malloc.h"
#include "overworld.h"
#include "main.h"
#include "callback_utils.h"

static u16 EndFlags[ENCOUNTER_MAX_FLAG];
static u16 OutcomeChecks[ENCOUNTER_MAX_FLAG];
static u16 OutcomeFlags[ENCOUNTER_MAX_FLAG];

void LegendaryDoBossRoll(void)
{
    u32 randomvalue = (Random() % 99);
    if (CheckAPFlag(AP_ALPHA_AURA) == TRUE)
    {
        if (randomvalue < 11)
            FlagSet(FLAG_RYU_BOSS_WILD);
        else
            FlagClear(FLAG_RYU_BOSS_WILD);
    }
    else 
    {
        if (randomvalue == 0)
            FlagSet(FLAG_RYU_BOSS_WILD);
        else
            FlagClear(FLAG_RYU_BOSS_WILD);
    }
}

void CheckIfAllBeastsCaught(void)
{
    if    ((FlagGet(FLAG_RYU_NIHILEGO_CAUGHT) == TRUE) &&
           (FlagGet(FLAG_RYU_BUZZWOLE_CAUGHT) == TRUE) &&
          (FlagGet(FLAG_RYU_PHEROMOSA_CAUGHT) == TRUE) &&
          (FlagGet(FLAG_RYU_XURKITREE_CAUGHT) == TRUE) &&
         (FlagGet(FLAG_RYU_CELESTEELA_CAUGHT) == TRUE) &&
            (FlagGet(FLAG_RYU_KARTANA_CAUGHT) == TRUE) &&
           (FlagGet(FLAG_RYU_GUZZLORD_CAUGHT) == TRUE) &&
          (FlagGet(FLAG_RYU_STAKATAKA_CAUGHT) == TRUE))
        {
            if (CheckAchievement(ACH_ULTRA_BEASTLY) == FALSE)
                GiveAchievement(ACH_ULTRA_BEASTLY);
            FlagSet(FLAG_RYU_CAUGHT_ALL_UBS);
            return;
        }
}

extern int CountBadges();

void ResetEndBattleFlags() {
    memset(EndFlags, 0, sizeof EndFlags);
    memset(OutcomeChecks, 0, sizeof OutcomeChecks);
    memset(OutcomeFlags, 0, sizeof OutcomeFlags);
}

void HatSetDynamicEncounter(u16 speciesId, u8* msg, s16 endFlag, s16 outcomeCheck, s16 outcomeFlag)
{
    u8 taskId = CreateTask(Task_HatEncounter_Generic, 10);
    ResetCallbacks();
    gTasks[taskId].encounterSpecies = speciesId;
    ResetEndBattleFlags();
    EndFlags[0] = endFlag;
    OutcomeChecks[0] = outcomeCheck;
    OutcomeFlags[0] = outcomeFlag;
    StringCopy(gRyuStringVar4, msg);
    return;
}

void HatSetDynamicLegendaryEncounter(u16 speciesId, u8* msg, s16 endFlag, s16 outcomeCheck, s16 outcomeFlag)
{
    u8 taskId = CreateTask(Task_HatEncounter_Legendary, 10);
    gTasks[taskId].encounterSpecies = speciesId;
    ResetEndBattleFlags();
    EndFlags[0] = endFlag;
    OutcomeChecks[0] = outcomeCheck;
    OutcomeFlags[0] = outcomeFlag;
    StringCopy(gRyuStringVar4, msg);
    return;
}

void Task_HatEncounter_Generic(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessage((u8[])_("{RYU_STR_4}$"));
            PlayCry5(gTasks[taskId].encounterSpecies, 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            CreateScriptedWildMon(gTasks[taskId].encounterSpecies, ENCOUNTER_SCALE, gBaseStats[gTasks[taskId].encounterSpecies].item1);
            LegendaryDoBossRoll();
            BattleSetup_StartScriptedWildBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            gMain.callback1 = HatEncounterEndWithFlagCallback;
            gTasks[taskId].data[0]++;
            DestroyTask(taskId);
            return;
    }
}

void Task_HatEncounter_Legendary(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessage((u8[])_("{RYU_STR_4}$"));
            PlayCry5(gTasks[taskId].encounterSpecies, 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            CreateScriptedWildMon(gTasks[taskId].encounterSpecies, ENCOUNTER_SCALE, gBaseStats[gTasks[taskId].encounterSpecies].item1);
            LegendaryDoBossRoll();
            BattleSetup_StartLegendaryBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            gMain.callback1 = HatEncounterEndWithFlagCallback;
            gTasks[taskId].data[0]++;
            DestroyTask(taskId);
            return;
    }
}

void Task_HatEncounter_SteppedOn(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            StringCopy(gRyuStringVar4, gSpeciesNames[gSpecialVar_0x8009]);
            ShowFieldMessageOneLine((u8[])_("You stepped on a wild {RYU_STR_4}!$"));
            PlayCry5(gSpecialVar_0x8009, 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            CreateScriptedWildMon(gSpecialVar_0x8009, ENCOUNTER_SCALE, gBaseStats[gSpecialVar_0x8009].item1);//there's no need to use saveblock vars here @Hat
            LegendaryDoBossRoll();
            BattleSetup_StartScriptedWildBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            gMain.callback1 = HatEncounterEndCallback;
            DestroyTask(taskId);
            return;
    }
}

static const u8 sMovement_ExclamationMark[] =
{
    MOVEMENT_ACTION_EMOTE_EXCLAMATION_MARK,
    MOVEMENT_ACTION_STEP_END
};

void Task_HatEncounter_Mimikyu(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case 0:
            ScriptContext2_Enable();
            PlayCry5(SPECIES_MIMIKYU, 0);
            gTasks[taskId].data[0]++;
            break;
        case 1:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case 2:
            PlaySE(21);
            ScriptMovement_StartObjectMovementScript(PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, sMovement_ExclamationMark);
            ScriptMovement_StartObjectMovementScript(FOLLOWER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, sMovement_ExclamationMark);
            gTasks[taskId].data[0]++;
            break;
        case 3:
            if (ScriptMovement_IsObjectMovementFinished(PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup))
                gTasks[taskId].data[0]++;
            break;
        case 4:
            ShowFieldMessage((u8[])_("You stumbled across\na wild Mimikyu!$"));
            CreateScriptedWildMon(SPECIES_MIMIKYU, ENCOUNTER_SCALE, gBaseStats[SPECIES_MIMIKYU].item1);
            LegendaryDoBossRoll();
            BattleSetup_StartScriptedWildBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case 5:
            gMain.callback1 = HatEncounterEndCallback;
            DestroyTask(taskId);
            return;
    }
}

void Task_HatEncounter_Keldeo(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessage((u8[])_("You hear trotting from the sky..."));
            PlayCry5(SPECIES_KELDEO, 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            CreateScriptedWildMon(SPECIES_KELDEO, ENCOUNTER_SCALE, gBaseStats[SPECIES_KELDEO].item1);
            LegendaryDoBossRoll();
            BattleSetup_StartLegendaryBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            gMain.callback1 = HatEncounterEndKeldeoCallback;
            gTasks[taskId].data[0]++;
            DestroyTask(taskId);
            return;
    }
}

const u16 UBFlagIds[][2] = {
    [1] = {SPECIES_NIHILEGO, FLAG_RYU_NIHILEGO_CAUGHT},
    [2] = {SPECIES_BUZZWOLE ,FLAG_RYU_BUZZWOLE_CAUGHT},
    [3] = {SPECIES_PHEROMOSA ,FLAG_RYU_PHEROMOSA_CAUGHT},
    [4] = {SPECIES_XURKITREE ,FLAG_RYU_XURKITREE_CAUGHT},
    [5] = {SPECIES_CELESTEELA ,FLAG_RYU_CELESTEELA_CAUGHT},
    [6] = {SPECIES_KARTANA ,FLAG_RYU_KARTANA_CAUGHT},
    [7] = {SPECIES_GUZZLORD ,FLAG_RYU_GUZZLORD_CAUGHT},
    [8] = {SPECIES_STAKATAKA ,FLAG_RYU_STAKATAKA_CAUGHT}
};

void Task_HatEncounter_UltraBeast(u8 taskId)
{
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine(gRyuStringVar4);
            PlayCry5(gSpecialVar_0x8009, 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            CreateScriptedWildMon(gSpecialVar_0x8009, ENCOUNTER_SCALE, gBaseStats[gSpecialVar_0x8009].item1);
            LegendaryDoBossRoll();
            BattleSetup_StartLegendaryBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            gMain.callback1 = HatEncounterEndUBCallback;
            DestroyTask(taskId);
            return;
    }
}

void HatEncounterEndCallback(void) {
    if (ScriptContext1_IsEnabled()) {
        FlagClear(FLAG_RYU_BOSS_WILD);
        ResetToOverworldMainCallback();
    }
}

void HatEncounterEndWithFlagCallback(void) {
    u32 i;
    if (ScriptContext1_IsEnabled()) {
        FlagClear(FLAG_RYU_BOSS_WILD);
        for (i = 0; i < ENCOUNTER_MAX_FLAG; ++i) {
            if (EndFlags[i])
                FlagSet(EndFlags[i]);
        }
        for (i = 0; i < ENCOUNTER_MAX_FLAG; ++i) {
            if (OutcomeChecks[i] == gBattleOutcome)
                FlagSet(OutcomeFlags[i]);
        }
        ResetToOverworldMainCallback();
    }
}

void HatEncounterEndKeldeoCallback(void) {
    if (ScriptContext1_IsEnabled()) {
        FlagClear(FLAG_RYU_BOSS_WILD);
        if (B_OUTCOME_CAUGHT == gBattleOutcome) {
            FlagSet(FLAG_RYU_CAUGHT_KELDEO);
        }
        FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
        FlagClear(FLAG_RYU_ENCOUNTERED_UB);
        ResetToOverworldMainCallback();
    }
}

void HatEncounterEndUBCallback(void) {
    u32 i;
    if (ScriptContext1_IsEnabled()) {
        FlagClear(FLAG_RYU_BOSS_WILD);
        if (B_OUTCOME_CAUGHT == gBattleOutcome) {
            for (i = 0; i < ARRAY_COUNT(UBFlagIds); i++)
            {
                if (gSpecialVar_0x8009 == UBFlagIds[i][0])
                    FlagSet(UBFlagIds[i][1]);
            }
            CheckIfAllBeastsCaught();
        }
        FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
        FlagClear(FLAG_RYU_ENCOUNTERED_UB);
        ResetToOverworldMainCallback();
    }
}

