LittlerootTown_MapScripts:: @ 81E7DCB
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScript1_1E7DDB
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScript2_1E7EC1
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScript2_1E7FE2
	.byte 0

LittlerootTown_MapScript1_1E7DDB: @ 81E7DDB
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	end
	
LRT_FollowerTest::
	lock
	msgbox LRT_FollowerMinnie MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LRT_CancelFollower
	setflag FLAG_TEMP_3
	closemessage
	setflag FLAG_RYU_HIDE_MINNIE
	removeobject 4
	createfollower EVENT_OBJ_GFX_TWIN, RyuFollowerSelectNPCScript, 1
	setflag FLAG_RYU_HAS_FOLLOWER
	setvar VAR_RYU_FOLLOWER_ID, EVENT_OBJ_GFX_TWIN
	release
	end
	
LRT_CancelFollower::
	msgbox LRT_NoFollower
	closemessage
	end
	
LRT_MinnieScript::
	msgbox LRT_FollowerHeal MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LRT_RemoveMinnie
	closemessage
	end

facingMsg:
	.string "You're facing direction {STR_VAR_2}!$"

LRT_RemoveMinnie:
	msgbox LRT_MinnieLeave
	closemessage
	destroyfollower
	clearflag FLAG_RYU_HIDE_MINNIE
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	release
	end

LRT_MinnieLeave:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Minnie: Okay! Have fun!$"
	
LRT_FollowerMinnie:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hi! I'm Minnie!\nMy sister guards the exit.\pI'm a bodyguard. Can I come with you?$"
	
LRT_NoFollower::
	.string "{COLOR LIGHT_RED}{SHADOW RED}Okay!\nLet me know if you change your mind!$"
	
LRT_FollowerHeal:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Minnie: Do you want me to leave?$"
	
LRT_BirchLabSignNormal::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_eq LRT_SealedChamber
	msgbox BirchsLabSign MSGBOX_SIGN
	release
	end
	
LRT_SealedChamber:
	warpteleport MAP_SEALED_CHAMBER_OUTER_ROOM, 0, 0, 0
	release
	end
	
LRT_sign::
	msgbox LittlerootSign MSGBOX_SIGN
	release
	end
	
LittlerootSign:
	.string "Littleroot Town\pThe town of humble beginnings.$"

BirchsLabSign: @ 81E8D69
	.string "Prof. Birch's Pokémon Lab$"
	
LRT_LittleGirlChatter::
	lock
	faceplayer
	msgbox LRT_LittleGirl MSGBOX_DEFAULT
	release
	end
	
LRT_LittleGirl:
	.string "Cute Girl: {COLOR LIGHT_RED}{SHADOW RED}Hi! I'm on guard duty!\nDon't go outside without friends, okay?$"

LRT_PreventLeave::
	goto_if_set FLAG_RYU_MET_RIVAL_LITTLEROOT, ryu_end
	lock
	faceplayer
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, LRT_StepRight
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LRT_cantLeaveFemale
	msgbox LRT_Girl_PreventLeave MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, LRT_CantLeave
	applymovement 1, LRT_StepLeft
	waitmovement 0
	release
	end
	
LRT_cantLeaveFemale:
	msgbox LRT_Girl_PreventLeaveFemale MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, LRT_CantLeave
	applymovement 1, LRT_StepLeft
	waitmovement 0
	release
	end
	
LRT_Girl_PreventLeaveFemale:
	.string "Cute Girl: {COLOR LIGHT_RED}{SHADOW RED}Um! Lady!\pIt's dangerous to go out there\nwithout Pokémon to protect you!$"
	
	
LRT_StepLeft:
	walk_left
	walk_in_place_down
	step_end

LRT_StepRight:
	walk_right
	walk_in_place_right
	step_end

LRT_Girl_PreventLeave:
	.string "Cute Girl: {COLOR LIGHT_RED}{SHADOW RED}Um! Mister!\pIt's dangerous to go out there\nwithout Pokémon to protect you!$"
	
LRT_CantLeave:
	walk_down
	walk_down
	step_end

LRT_BrendansHouseSign:: @ 81E818F
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LRT_PlayerHouseSign
	goto LRT_RivalHouseSign
	end
	
LRT_DawnsHouseSign::
	lockall
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LRT_PlayerHouseSign
	goto LRT_RivalHouseSign
	end

LRT_RivalHouseSign:: @ 81E81A9
	msgbox LRT_RIVALHOUSESIGNMSG, MSGBOX_DEFAULT
	releaseall
	end

LRT_PlayerHouseSign:: @ 81E81B2
	msgbox LRT_PLAYERHOUSESIGNMSG, MSGBOX_DEFAULT
	releaseall
	end
	
LRT_PLAYERHOUSESIGNMSG:
	.string "{PLAYER}'s House$"
	
LRT_RIVALHOUSESIGNMSG:
	.string "{RIVAL}'s House$"

LRT_GameStartInfoMsg:
	.string "New Game Flags and Variables Set.$"
	
LRT_StopGoingSouth::
	getpartysize
	compare VAR_RESULT, 0
	goto_if_eq LRT_StopPlayer
	release
	end

LRT_StopPlayer::
	msgbox LRT_CantExitSouthYet MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_StepUp
	waitmovement 0
	release
	end
	
LRT_CantExitSouthYet:
	.string "You have no Pokémon, you probably\ndon't want to go down here yet.$"
	
LRT_BoyChatter::
	lock
	faceplayer
	msgbox LRT_BC1 MSGBOX_DEFAULT
	release
	end
	
LRT_BC1:
	.string "Young Boy: Science is amazing!\p" 
	.string "People these days can modify data\n" 
	.string "within a regular game to create\l" 
	.string "a whole new experience!$"
	
LRT_FatManChatter::
	lock
	faceplayer
	msgbox LRT_FM1 MSGBOX_DEFAULT
	closemessage
	fadenewbgm MUS_DUMMY
	delay 230
	fadedefaultbgm
	msgbox LRT_FM2 MSGBOX_DEFAULT
	closemessage
	release
	end
	
LRT_FM1:
	.string "Man: It's hard to take a nap out\n"
    .string "here. I keep hearing the Pokémon\p"
    .string "that professor has preserved south\n"
    .string "of town making noises all the time\l"
    .string "Listen!$"
	
LRT_FM2:
    .string "Did you hear them? It's distracting\n"
    .string "right? Well anyways, bye!$"



