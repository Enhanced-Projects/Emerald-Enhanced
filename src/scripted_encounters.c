#include "global.h"
#include "task.h"
#include "scripted_encounters.h"
#include "event_data.h"
#include "field_message_box.h"
#include "script_pokemon_util.h"
#include "battle_setup.h"
#include "script.h"
#include "battle.h"
#include "ach_atlas.h"
#include "random.h"
#include "sound.h"
#include "data.h"
#include "string_util.h"
#include "script_movement.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "songs.h"

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

void Task_HatEncounter_Buzzwole(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("A mysterious Bug Pokémon attacks!"));
	        VarSet(VAR_TEMP_5, SPECIES_BUZZWOLE);
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
                FlagSet(FLAG_RYU_BUZZWOLE_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Pheromosa(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("A feminine Bug Pokémon attacks!"));
	        VarSet(VAR_TEMP_5, SPECIES_PHEROMOSA);
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
                FlagSet(FLAG_RYU_PHEROMOSA_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}


void Task_HatEncounter_Kartana(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("Some animated origami attacks!"));
	        VarSet(VAR_TEMP_5, SPECIES_KARTANA);
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
                FlagSet(FLAG_RYU_KARTANA_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Xurkitree(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("Some living power lines attack!"));
	        VarSet(VAR_TEMP_5, SPECIES_XURKITREE);
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
                FlagSet(FLAG_RYU_XURKITREE_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Nihilego(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("An odd wig-shaped jellyfish attacks!"));
	        VarSet(VAR_TEMP_5, SPECIES_NIHILEGO);
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
                FlagSet(FLAG_RYU_NIHILEGO_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Guzzlord(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("A Pokémon with a gaping maw attacks!"));
	        VarSet(VAR_TEMP_5, SPECIES_GUZZLORD);
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
                FlagSet(FLAG_RYU_GUZZLORD_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Stakataka(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("A giant living box attacks!"));
	        VarSet(VAR_TEMP_5, SPECIES_STAKATAKA);
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
                FlagSet(FLAG_RYU_STAKATAKA_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}

void Task_HatEncounter_Celesteela(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            ShowFieldMessageOneLine((u8[])_("A magical statue attacks!"));
	        VarSet(VAR_TEMP_5, SPECIES_CELESTEELA);
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
                FlagSet(FLAG_RYU_CELESTEELA_CAUGHT);
                CheckIfAllBeastsCaught();
            }
            FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
            FlagClear(FLAG_RYU_ENCOUNTERED_UB);
            DestroyTask(taskId);
            break;
    }
}


u16 SteppedOnSpecies[] = {
    SPECIES_PYUKUMUKU, 
    SPECIES_SANDYGAST, 
    SPECIES_SHELLDER,
    SPECIES_MAREANIE,
    SPECIES_SKRELP
};

void Task_HatEncounter_SteppedOn(u8 taskId) {
    switch (gTasks[taskId].data[0]) {
        case ENC_MESSAGE:
            ScriptContext2_Enable();
            gTasks[taskId].data[1] = Random() % 5;
	        VarSet(VAR_TEMP_5, SteppedOnSpecies[gTasks[taskId].data[1]]);
            StringCopy(gStringVar1, gSpeciesNames[VarGet(VAR_TEMP_5)]);
            ShowFieldMessageOneLine((u8[])_("You stepped on a wild {STR_VAR_1}!$"));
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
            PlaySE(SE_PIN);
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


/*
bool8 ScrCmd_applymovement(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    const void *movementScript = (const void *)ScriptReadWord(ctx);

    ScriptMovement_StartObjectMovementScript(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, movementScript);
    sMovingNpcId = localId;
    return FALSE;
}


SB_SetupRandomMimikyuEncounter::
	lock
	clearflag FLAG_TEMP_A
	specialvar VAR_TEMP_7, CountBadges
	multvar VAR_TEMP_7, 12
	compare VAR_TEMP_7, 110
	call_if_gt RyuLegendary_SetMaxScale
	compare VAR_TEMP_7, 20
	call_if_le RyuLegendary_SetBaseScale
	setwildbattle SPECIES_MIMIKYU, VAR_TEMP_7, ITEM_NONE
	playmoncry SPECIES_MIMIKYU, 0
	waitmoncry
	playse SE_PIN
	applymovement PLAYER, Common_Movement_ExclamationMark
	applymovement FOLLOWER, Common_Movement_ExclamationMark
	waitmovement PLAYER
	msgbox StumbledOnMimikyu
	closemessage
	dowildbattle
	release
	end

StumbledOnMimikyu:
	.string "You stumbled across\na wild Mimikyu!$"*/