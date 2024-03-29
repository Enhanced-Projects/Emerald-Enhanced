TrainerHill_OnResume: @ 82C8336
	setvar VAR_TEMP_2, 0
	trainerhill_resumetimer
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq TrainerHill_1F_EventScript_Lost
	compare VAR_RESULT, B_OUTCOME_DREW
	goto_if_eq TrainerHill_1F_EventScript_Lost
	compare VAR_RESULT, B_OUTCOME_FORFEITED
	goto_if_eq TrainerHill_1F_EventScript_Lost
	end

TrainerHill_OnFrame: @ 82C8381
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

EventScript_TrainerHillTimer:: @ 82C8393
	lockall
	trainerhill_gettime
	msgbox TrainerHill_Entrance_Text_ChallengeTime, MSGBOX_DEFAULT
	releaseall
	end

TrainerHill_1F_EventScript_Lost:: @ 82C83C9
	trainerhill_settrainerflags
	trainerhill_lost
	setvar VAR_TEMP_1, 1
	end

TrainerHill_EventScript_WarpToEntranceCounter:: @ 82C83DF
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE, 255, 3, 8
	waitstate
	end

@ TRAINER_PHILLIP is an actual Trainer on the SS Tidal, but is used as a placeholder here
TrainerHill_EventScript_TrainerBattle:: @ 82C83F0
	trainerbattle TRAINER_BATTLE_HILL, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	trainerhill_postbattletext
	waitmessage
	waitbuttonpress
	closemessage
	end
