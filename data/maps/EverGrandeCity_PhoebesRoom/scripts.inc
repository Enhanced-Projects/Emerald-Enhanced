EverGrandeCity_PhoebesRoom_MapScripts:: @ 8228174
	map_script ON_LOAD , EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script ON_FRAME, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp: @ 8228184
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth:: @ 822818E
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame: @ 8228193
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor:: @ 822819D
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad: @ 82281AA
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 2
	call_if_eq EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom:: @ 82281BF
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor:: @ 82281C5
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe:: @ 82281CB
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_PhoebesRoom_Text_PreBattleSpeech, MSGBOX_DEFAULT
	setflag FLAG_RYU_DO_NOT_AUTOSCALE
	goto_if_set FLAG_SYS_GAME_CLEAR, EGC_AltPhoebe
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_FollowerPhoebe
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EGC_FollowerPhoebe::
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq EGC_PR_ChooseValidMons
	multi_2_vs_1 TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto RyuPhoebeMegaReward
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

RyuPhoebeMegaReward::
	goto_if_set FLAG_RYU_PHOEBE_MEGA, EverGrandeCity_PhoebesRoom_EventScript_Defeated
	additem ITEM_SABLENITE
	msgbox PhoebeMegaRewardMsg
	setflag FLAG_RYU_PHOEBE_MEGA
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated

PhoebeMegaRewardMsg::
	.string "My ghosts didn't give you a\nhard time at all!\pYou should be able to use this.$"
	
EGC_FollowerPhoebeRematch::
	setflag FLAG_TEMP_B
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq EGC_PR_ChooseValidMons
	multi_2_vs_1 TRAINER_PHOEBE_REMATCH, EverGrandeCity_PhoebesRoom_Text_Defeat, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end
	
EGC_PR_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto_if_set FLAG_TEMP_B, EGC_FollowerPhoebeRematch
	goto EGC_FollowerPhoebe

EGC_AltPhoebe::
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_FollowerPhoebeRematch
	trainerbattle_no_intro TRAINER_PHOEBE_REMATCH, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto RyuPhoebeMegaReward
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech:: @ 82281F2
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated:: @ 82281FC
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	call Ryu_CheckForPartnerReward
	release
	end

EverGrandeCity_PhoebesRoom_Text_PreBattleSpeech: @ 822820E
	.string "Ahahaha!\p"
	.string "I'm PHOEBE of the ELITE FOUR.\n"
	.string "I did my training on Mt. Pyre.\p"
	.string "While I trained, I gained the ability\n"
	.string "to commune with GHOST-type Pokémon.\p"
	.string "Yes, the bond I developed with Pokémon\n"
	.string "is extremely tight.\p"
	.string "So, come on, just try and see if you can\n"
	.string "even inflict damage on my Pokémon!$"

EverGrandeCity_PhoebesRoom_Text_Defeat: @ 8228325
	.string "Oh, darn.\n"
	.string "I've gone and lost.$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech: @ 8228343
	.string "There's a definite bond between you\n"
	.string "and your Pokémon, too.\p"
	.string "I didn't recognize it, so it's only\n"
	.string "natural that I lost.\p"
	.string "Yup, I'd like to see how far your bond\n"
	.string "will carry you.\p"
	.string "Go ahead, move on to the next room.$"

