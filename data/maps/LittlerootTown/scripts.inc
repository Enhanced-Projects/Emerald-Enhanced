LittlerootTown_MapScripts:: @ 81E7DCB
	map_script ON_TRANSITION, LittlerootTown_MapScript1_1E7DDB
	map_script ON_FRAME, Ryu_HaremEventCheck
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScript2_1E7FE2
	.byte 0

Ryu_HaremEventCheck::
	map_script_2 VAR_RYU_PARTNER_COUNT, 4, Ryu_HaremEvent
	.2byte 0


LittlerootTown_MapScript1_1E7DDB: @ 81E7DDB
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	end
	
LRT_FollowerTest::
	lock
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGMINNIE
	msgbox LRT_FollowerMinnie MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LRT_CancelFollower
	closemessage
	setflag FLAG_RYU_HIDE_MINNIE
	setflag FLAG_RYU_RECRUITED_MINNIE
	removeobject 4
	createfollower OBJ_EVENT_GFX_TWIN, RyuFollowerSelectNPCScript, 1
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	release
	end
	
LRT_CancelFollower::
	msgbox LRT_NoFollower
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
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
	applymovement OBJ_EVENT_ID_PLAYER, LRT_CantLeave
	applymovement 1, LRT_StepLeft
	waitmovement 0
	release
	end
	
LRT_cantLeaveFemale:
	msgbox LRT_Girl_PreventLeaveFemale MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LRT_CantLeave
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
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

Pidgey_NPC::
	lock
	faceplayer
	msgbox Pidgey_NPCText MSGBOX_ONELINE
	closemessage
	release
	end

Pidgey_NPCText:
    .string "Hello my name is Pidgey.\p"
    .string "i'm not actually a Pidgey but that's\p"
    .string "what most people on Discord call me!\p"
    .string "I added this NPC as an easter egg\p"
    .string "without the permission of Ryuhouji!\p"
    .string "Anyways i wanted to know if this\p"
    .string "would slip under his radar or not.\p"
    .string "If you see this message chances are\p"
    .string "that it did.$"

LRT_FM1:
    .string "Man: It's hard to take a nap out\n"
    .string "here. I keep hearing the Pokémon\p"
    .string "that professor has preserved south\n"
    .string "of town making noises all the time\l"
    .string "Listen!$"
	
LRT_FM2:
    .string "Did you hear them? It's distracting\n"
    .string "right? Well anyways, bye!$"

@HAREM EVENT=======================================================================================
Ryu_HaremEvent::
	goto_if_set FLAG_RYU_HAREM_EVENT_COMPLETED, ryu_end
	lockall
	checkplayergender
	compare VAR_RESULT, FEMALE
	call_if_eq Ryu_HaremEventMale
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Ryu_HaremEventFemale
	call_if_set FLAG_RYU_RECRUITED_MINNIE, LRT_Harem_AlsoMinnie
	fadescreen FADE_TO_BLACK
	@drawfullscreenimage SCENEBGHAREM
	msgbox LRT_Harem_Outro
	closemessage
	additem ITEM_SHINY_CHARM
	closemessage
	delay 60
	setflag FLAG_RYU_HAREM_EVENT_COMPLETED
	setflag FLAG_RYU_HIDE_HAREM_EVENT_NPCS
	setflag FLAG_RYU_HIDE_HAREM_EVENT_BRENDAN
	setflag FLAG_RYU_HIDE_HAREM_EVENT_DAWN
	removeobject 6
	removeobject 8
	removeobject 9
	@clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	msgbox LRT_HAREM_END_RIVALMSG
	closemessage
	applymovement 7, RivalToLab
	applymovement 10, RivalToLab
	waitmovement 7
	waitmovement 10
	removeobject 7
	removeobject 10
	setvar VAR_RYU_PARTNER_COUNT, 10
	release
	end
	
LRT_HAREM_END_RIVALMSG:
	.string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} Don't forget to take one\n"
	.string "of us with you to battle from\l"
	.string "time to time!$"

LRT_HAREM_INTRO:
    .string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} We all love you, and in\n"
    .string "return, you've shown us all love.\p"
    .string "We got together to get you a gift.$"
	
LRT_Harem_Outro:
    .string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} It's a Shiny Charm.$"
	
LRT_HAREM_INTRO_Shelly:
    .string "Shelly:{COLOR LIGHT_RED}{SHADOW RED} It's an incredibly rare\n"
    .string "artifact imported from Kalos.$"
	
LRT_HAREM_INTRO_Lanette:
    .string "Lanette:{COLOR LIGHT_RED}{SHADOW RED} I researched for HOURS to\n"
    .string "track it down!$"
	
LRT_HAREM_INTRO_Lana:
    .string "Lana:{COLOR LIGHT_RED}{SHADOW RED} I went to Kanto to fill out the\n"
    .string "paperwork to have it shipped here!$"

LRT_HAREM_INTRO_Rival:
    .string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} We hope you like it!\p"
    .string "You gave us your all, so we\n"
    .string "returned the favor!$"

	
LRT_Harem_AlsoMinnie::
	applymovement 4, MinnieToGroup
	waitmovement 4
	playse SE_PIN
	msgbox AlsoMinnieMsg
	closemessage
	return
	
AlsoMinnieMsg:
    .string "Minnie: {COLOR LIGHT_RED}{SHADOW RED}Hey! don't forget about me!\p"
    .string "You became my friend when I didn't\n"
    .string "have any. When I get older, I want to\p"
    .string "be with you like these other girls!\n"
    .string "Please wait for me!$"
	
MinnieToGroup:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_diag_southeast
	face_right
	emote_exclamation_mark
	step_end
	
RivalToLab:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Ryu_HaremEventMale::
	msgbox LRT_HAREM_INTRO
	closemessage
	applymovement 9, ShellyToDawn
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Shelly
	closemessage
	applymovement 8, LanaToDawn
	waitmovement 8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lana
	closemessage
	applymovement 6, LanetteToDawn
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lanette
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 10, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Rival
	closemessage
	return
	
Ryu_HaremEventFemale::
	msgbox LRT_HAREM_INTRO
	closemessage
	applymovement 6, LanetteToBrendan
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lanette
	closemessage
	applymovement 8, LanaToBrendan
	waitmovement 8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lana
	closemessage
	applymovement 9, ShellyToBrendan
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Shelly
	closemessage
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 7, Common_Movement_FaceLeft
	waitmovement 7
	msgbox LRT_HAREM_INTRO_Rival
	return
	
LanetteToDawn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_left
	step_end
	
LanaToDawn:
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_right
	face_down
	step_end
	
ShellyToDawn:
	walk_up
	walk_up
	face_up
	step_end
	
LanetteToBrendan:
	walk_up
	walk_up
	walk_up
	face_right
	step_end
	
LanaToBrendan:
	walk_up
	walk_up
	face_up
	step_end
	
ShellyToBrendan:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_down
	step_end


	

	
	
	
	
	
	
	
	
	
	
	
