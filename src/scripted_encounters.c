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

void CheckIfAllBeastsCaught()
{
    if (FlagGet(FLAG_RYU_CAUGHT_ALL_UBS) ||
        !FlagGet(FLAG_RYU_NIHILEGO_CAUGHT) ||
        !FlagGet(FLAG_RYU_BUZZWOLE_CAUGHT) ||
        !FlagGet(FLAG_RYU_PHEROMOSA_CAUGHT) ||
        !FlagGet(FLAG_RYU_XURKITREE_CAUGHT) ||
        !FlagGet(FLAG_RYU_CELESTEELA_CAUGHT) ||
        !FlagGet(FLAG_RYU_KARTANA_CAUGHT) ||
        !FlagGet(FLAG_RYU_GUZZLORD_CAUGHT) ||
        !FlagGet(FLAG_RYU_STAKATAKA_CAUGHT))
        return;
    FlagSet(FLAG_RYU_CAUGHT_ALL_UBS);
}

extern int CountBadges();

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
            CreateScriptedWildMon(gSpecialVar_0x8009, RyuGetSpecialEncounterScale(), gBaseStats[gSpecialVar_0x8009].item1);
            LegendaryDoBossRoll();
            BattleSetup_StartLegendaryBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            if (ScriptContext1_IsEnabled())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_END:
            FlagClear(FLAG_RYU_BOSS_WILD);
            if (B_OUTCOME_CAUGHT == gBattleOutcome) {
                u32 i;
                for (i = 0; i < ARRAY_COUNT(UBFlagIds); i++)
                {
                    if(gSpecialVar_0x8009 == UBFlagIds[i][0]) //should loop through above table and set the correct flag.
                        FlagSet(UBFlagIds[i][1]);
                }
                CheckIfAllBeastsCaught();
            }
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

int RyuGetSpecialEncounterScale(void)
{
    return _clamp(CountBadges()*12, 20, 110);
}

void Task_HatEncounter_SteppedOn(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            StringCopy(gStringVar1, gSpeciesNames[gSpecialVar_0x8009]);
            ShowFieldMessageOneLine((u8[])_("You stepped on a wild {STR_VAR_1}!$"));
            PlayCry5(gSpecialVar_0x8009, 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            CreateScriptedWildMon(gSpecialVar_0x8009, RyuGetSpecialEncounterScale(), gBaseStats[gSpecialVar_0x8009].item1);//there's no need to use saveblock vars here @Hat
            LegendaryDoBossRoll();
            BattleSetup_StartScriptedWildBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            if (ScriptContext1_IsEnabled())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_END:
            FlagClear(FLAG_RYU_BOSS_WILD);
            DestroyTask(taskId);
            break;
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
	        VarSet(VAR_TEMP_5, SPECIES_MIMIKYU);
            PlayCry5(VarGet(VAR_TEMP_5), 0);
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
            VarSet(VAR_TEMP_7, _clamp(CountBadges()*12, 20, 110));
            CreateScriptedWildMon(VarGet(VAR_TEMP_5), VarGet(VAR_TEMP_7), VarGet(VAR_TEMP_9));
            LegendaryDoBossRoll();
            BattleSetup_StartScriptedWildBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case 5:
            if (ScriptContext1_IsEnabled())
                gTasks[taskId].data[0]++;
            break;
        case 6:
            FlagClear(FLAG_RYU_BOSS_WILD);
            DestroyTask(taskId);
            break;
    }
}
;

void Task_HatEncounter_Keldeo(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("You hear trotting from the sky..."));
	        VarSet(VAR_TEMP_5, SPECIES_KELDEO);
            PlayCry5(VarGet(VAR_TEMP_5), 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            VarSet(VAR_TEMP_7, _clamp(CountBadges()*12, 20, 110));
            CreateScriptedWildMon(VarGet(VAR_TEMP_5), VarGet(VAR_TEMP_7), VarGet(VAR_TEMP_9));
            LegendaryDoBossRoll();
            BattleSetup_StartLegendaryBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            if (ScriptContext1_IsEnabled())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_END:
            FlagClear(FLAG_RYU_BOSS_WILD);
            if (B_OUTCOME_CAUGHT == gBattleOutcome) {
                FlagSet(FLAG_RYU_CAUGHT_KELDEO);
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Generic(u8 taskId) {
    
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
	        VarSet(VAR_TEMP_5, gTasks[taskId].data[1]);
            StringCopy(gStringVar1, gSpeciesNames[VarGet(VAR_TEMP_5)]);
            ShowFieldMessage((u8[])_("{RYU_STR_4}$"));
            PlayCry5(VarGet(VAR_TEMP_5), 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            VarSet(VAR_TEMP_7, _clamp(CountBadges()*12, 20, 110));
            CreateScriptedWildMon(VarGet(VAR_TEMP_5), VarGet(VAR_TEMP_7), VarGet(VAR_TEMP_9));
            LegendaryDoBossRoll();
            BattleSetup_StartScriptedWildBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            if (ScriptContext1_IsEnabled())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_END:
            FlagClear(FLAG_RYU_BOSS_WILD);
            if (gTasks[taskId].encounterEndFlag)
                FlagSet(gTasks[taskId].encounterEndFlag);
            if (gTasks[taskId].encounterOutcomeCheck == gBattleOutcome && gTasks[taskId].encounterOutcomeCheck && gTasks[taskId].encounterOutcomeFlag) {
                FlagSet(gTasks[taskId].encounterOutcomeFlag);
            }
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Legendary(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
	        VarSet(VAR_TEMP_5, gTasks[taskId].data[1]);
            StringCopy(gStringVar1, gSpeciesNames[VarGet(VAR_TEMP_5)]);
            ShowFieldMessage((u8[])_("{RYU_STR_4}$"));
            PlayCry5(VarGet(VAR_TEMP_5), 0);
            gTasks[taskId].data[0]++;
            break;
        case ENC_CRY:
            if (IsCryFinished())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_START:
            VarSet(VAR_TEMP_7, _clamp(CountBadges()*12, 20, 110));
            CreateScriptedWildMon(VarGet(VAR_TEMP_5), VarGet(VAR_TEMP_7), VarGet(VAR_TEMP_9));
            LegendaryDoBossRoll();
            BattleSetup_StartLegendaryBattle();
            ScriptContext1_Stop();
            gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE:
            if (ScriptContext1_IsEnabled())
                gTasks[taskId].data[0]++;
            break;
        case ENC_BATTLE_END:
            FlagClear(FLAG_RYU_BOSS_WILD);
            if (gTasks[taskId].encounterEndFlag)
                FlagSet(gTasks[taskId].encounterEndFlag);
            if (gTasks[taskId].encounterOutcomeCheck == gBattleOutcome && gTasks[taskId].encounterOutcomeCheck && gTasks[taskId].encounterOutcomeFlag) {
                FlagSet(gTasks[taskId].encounterOutcomeFlag);
            }
            DestroyTask(taskId);
            break;
    }
}

void HatSetDynamicEncounter(u16 speciesId, u8* msg, s16 endFlag, s16 outcomeCheck, s16 outcomeFlag)
{
    u8 taskId = CreateTask(Task_HatEncounter_Generic, 10);
    gTasks[taskId].encounterSpecies = speciesId;
    gTasks[taskId].encounterEndFlag = endFlag;
    gTasks[taskId].encounterOutcomeCheck = outcomeCheck;
    gTasks[taskId].encounterOutcomeFlag = outcomeFlag;
    StringCopy(gRyuStringVar4, msg);
    return;
}

void HatSetDynamicLegendaryEncounter(u16 speciesId, u8* msg, s16 endFlag, s16 outcomeCheck, s16 outcomeFlag)
{
    u8 taskId = CreateTask(Task_HatEncounter_Legendary, 10);
    gTasks[taskId].encounterSpecies = speciesId;
    gTasks[taskId].encounterEndFlag = endFlag;
    gTasks[taskId].encounterOutcomeCheck = outcomeCheck;
    gTasks[taskId].encounterOutcomeFlag = outcomeFlag;
    StringCopy(gRyuStringVar4, msg);
    return;
}