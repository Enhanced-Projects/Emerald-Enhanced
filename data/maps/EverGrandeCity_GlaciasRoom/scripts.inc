EverGrandeCity_GlaciasRoom_MapScripts:: @ 8228412
	map_script ON_FRAME, EverGrandeCity_GlaciasRoom_OnFrame
	map_script ON_LOAD , EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp: @ 8228422
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth:: @ 822842C
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame: @ 8228431
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor:: @ 822843B
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad: @ 8228448
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 3
	call_if_eq EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom:: @ 822845D
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor:: @ 8228463
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia:: @ 8228469
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_GlaciasRoom_Text_PreBattleSpeech, MSGBOX_DEFAULT
	setflag FLAG_RYU_DO_NOT_AUTOSCALE
	goto_if_set FLAG_SYS_GAME_CLEAR, EGC_AltGlacia
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_FollowerGlacia	
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EGC_AltGlacia::
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_FollowerGlaciaRematch
	trainerbattle_no_intro TRAINER_GLACIA_REMATCH, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto RyuGlaciaMegaReward
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

RyuGlaciaMegaReward::
	goto_if_set FLAG_RYU_GLACIA_MEGA, EverGrandeCity_GlaciasRoom_EventScript_Defeated
	additem ITEM_GLALITITE
	msgbox GlaciaMegaRewardMsg
	setflag FLAG_RYU_GLACIA_MEGA
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated

GlaciaMegaRewardMsg::
	.string "You chilled me to the core.\pYou know the essence of Ice\nPokemon. This stone would be\lwell utilized by you.$"

EGC_FollowerGlacia::
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq EGC_GR_ChooseValidMons
	multi_2_vs_1 TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto RyuGlaciaMegaReward
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end
	
EGC_FollowerGlaciaRematch::
	setflag FLAG_TEMP_B
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq EGC_GR_ChooseValidMons
	multi_2_vs_1 TRAINER_GLACIA_REMATCH, EverGrandeCity_GlaciasRoom_Text_Defeat, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end
	
EGC_GR_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto_if_set FLAG_TEMP_B, EGC_FollowerGlaciaRematch
	goto EGC_FollowerGlacia

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech:: @ 8228490
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated:: @ 822849A
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	call Ryu_CheckForPartnerReward
	release
	end

EverGrandeCity_GlaciasRoom_Text_PreBattleSpeech: @ 82284AC
	.string "Welcome, my name is Glacia\n"
	.string "of the Elite Four.\p"
	.string "I've traveled from afar to Hoenn\n"
	.string "so that I may hone my ice skills.\p"
	.string "But all I have seen are challenges by\n"
	.string "weak Trainers and their Pokémon.\p"
	.string "What about you?\p"
	.string "It would please me to no end if I could\n"
	.string "go all out against you!$"

EverGrandeCity_GlaciasRoom_Text_Defeat: @ 82285B4
	.string "You and your Pokémon…\n"
	.string "How hot your spirits burn!\p"
	.string "The all-consuming heat overwhelms.\p"
	.string "It's no surprise that my icy skills\n"
	.string "failed to harm you.$"

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech: @ 8228640
	.string "Advance to the next room.\p"
	.string "And there, confirm the truly fearsome\n"
	.string "side of the Pokémon League.$"

