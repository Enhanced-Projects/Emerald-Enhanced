EverGrandeCity_DrakesRoom_MapScripts:: @ 822869C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD , EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp: @ 82286AC
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth:: @ 82286B6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame: @ 82286BB
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	map_script_2 VAR_TEMP_9, 0, LRT_ResetFollower
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor:: @ 82286C5
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad: @ 82286D2
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 4
	call_if_eq EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom:: @ 82286E7
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor:: @ 82286ED
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake:: @ 82286F3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_DrakesRoom_Text_PreBattleSpeech, MSGBOX_DEFAULT
	setflag FLAG_RYU_DO_NOT_AUTOSCALE
	goto_if_set FLAG_SYS_GAME_CLEAR, EGC_AltDrake
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_FollowerDrake
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EGC_AltDrake::
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_FollowerDrakeRematch
	trainerbattle_no_intro TRAINER_DRAKE_REMATCH, EverGrandeCity_DrakesRoom_Text_Defeat
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	goto Ryu_DrakeMegaReward
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

Ryu_DrakeMegaReward::
	goto_if_set FLAG_RYU_DRAKE_MEGA, EverGrandeCity_DrakesRoom_EventScript_Defeated
	additem ITEM_SALAMENCITE
	msgbox DrakeMegaRewardMsg
	setflag FLAG_RYU_DRAKE_MEGA
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated

DrakeMegaRewardMsg::
	.string "You have the heart of a\ntrue dragon master. You should\phave no trouble controlling\nthe power of a mega Dragon.$"

EGC_FollowerDrake::
	call RyuFollowerAllySelector
	special SavePlayerParty
	trainerbattle 10 TRAINER_DRAKE, 0, NULL, EverGrandeCity_DrakesRoom_Text_Defeat
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto Ryu_DrakeMegaReward
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EGC_FollowerDrakeRematch::
	call RyuFollowerAllySelector
	special SavePlayerParty
	trainerbattle 10 TRAINER_DRAKE_REMATCH, 0, NULL, EverGrandeCity_DrakesRoom_Text_Defeat
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech:: @ 822871A
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated:: @ 8228724
	setvar VAR_0x8004, 0
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_PreBattleSpeech: @ 822873E
	.string "I am the last of the Pokémon League\n"
	.string "ELITE FOUR, DRAKE the DRAGON master!\p"
	.string "In their natural state, Pokémon are\n"
	.string "wild living things. They are free.\p"
	.string "At times, they hinder us.\n"
	.string "At times, they help us.\p"
	.string "For us to battle with Pokémon as\n"
	.string "partners, do you know what it takes?\p"
	.string "Do you know what is needed?\p"
	.string "If you don't, then you will never\n"
	.string "prevail over me!$"

EverGrandeCity_DrakesRoom_Text_Defeat: @ 8228895
	.string "Superb, it should be said.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech: @ 82288B0
	.string "You deserve every credit for coming\n"
	.string "this far as a Trainer of Pokémon.\p"
	.string "You do seem to know what is needed.\p"
	.string "Yes, what a Trainer needs is a\n"
	.string "virtuous heart.\p"
	.string "Pokémon touch the good hearts of\n"
	.string "Trainers and learn good from wrong.\p"
	.string "They touch the good hearts of\n"
	.string "Trainers and grow strong.\p"
	.string "Go! Go onwards!\n"
	.string "The Champion is waiting!$"

