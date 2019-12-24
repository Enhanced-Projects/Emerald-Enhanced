AncientTomb1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AT1_LeafEventRop
	.byte 0
	
AT1_LeafEventRop::
	map_script_2 VAR_RYU_DS_LANA_STAGE, 68, AT1_LeafStoryEvent
	map_script_2 VAR_RYU_DS_LANA_STAGE, 72, AT1_LeafStoryEvent2
	.2byte 0
	
AT1_LeafStoryEvent::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	setvar VAR_RYU_DS_LANA_STAGE, 69
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, AT1_Cam1
	waitmovement EVENT_OBJ_ID_CAMERA
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement EVENT_OBJ_ID_PLAYER
	msgbox AT1_Story1 MSGBOX_DEFAULT
	closemessage
	applymovement 2, AT1_WalkUp
	applymovement EVENT_OBJ_ID_CAMERA, AT1_WalkUp
	applymovement EVENT_OBJ_ID_PLAYER, AT1_RunUp
	waitmovement EVENT_OBJ_ID_CAMERA
	applymovement 2, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 2
	drawheadshot HEAD_LANA
	msgbox AT1_Story2 MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	msgbox AT1_Story21 MSGBOX_DEFAULT
	closemessage
	drawheadshot HEAD_LANA
	msgbox AT1_Story22 MSGBOX_DEFAULT
	closemessage
	setvar VAR_RYU_DS_LANA_STAGE, 70
	goto AT1_LeafStoryEvent15
	
AT1_LeafStoryEvent15::
	setvar VAR_RYU_DS_LANA_STAGE, 71
	applymovement 2, Common_Movement_FaceRight
	waitmovement 2
	removecutscenesprites
	msgbox AT1_Story23 MSGBOX_DEFAULT
	msgbox AT1_Story3 MSGBOX_DEFAULT
	delay 25
	fadeoutbgm 0
	playse SE_W089
	special DoSealedChamberShakingEffect1
	waitse
	call IC_LeafOpenDoor
	fadenewbgm MUS_MABOROSI
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox AT1_Story4 MSGBOX_DEFAULT
	closemessage
	applymovement 2, AT1_LanaWalkUp2
	waitmovement 2
	removeobject 2
	setflag FLAG_RYU_HIDE_R120_LANA_AND_HIKER
	setflag FLAG_HIDE_AT1_LEAF
	applymovement EVENT_OBJ_ID_CAMERA, AT1_Cam2
	waitmovement EVENT_OBJ_ID_CAMERA
	special RemoveCameraObject
	applymovement EVENT_OBJ_ID_PLAYER, AT1_PlayerFollow
	waitmovement EVENT_OBJ_ID_PLAYER
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	setvar VAR_RYU_DS_LANA_STAGE, 72
	warp MAP_ANCIENT_TOMB1F, 255, 8, 11
	release
	end
	
AT1_LeafStoryEvent2::
	setvar VAR_RYU_DS_LANA_STAGE, 73
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	special DrawWholeMapView
	delay 10
	lock
	msgbox AT1_Story5 MSGBOX_DEFAULT
	closemessage
	msgbox AT1_Story6 MSGBOX_DEFAULT
	playse SE_NAGERU
	waitse
	closemessage
	playmoncry SPECIES_REGISTEEL, 0
	waitmoncry
	msgbox AT1_Story7 MSGBOX_DEFAULT
	playmoncry SPECIES_REGISTEEL, 2
	delay 20
	waitmoncry
	applymovement 3, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 3
	msgbox AT1_Story8 MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, AT1_SaveLana
	waitmovement EVENT_OBJ_ID_PLAYER
	playse SE_W120
	fadescreen 1
	msgbox AT1_BlackedOut MSGBOX_DEFAULT
	closemessage
	setvar VAR_RYU_DS_LANA_STAGE, 74
	call AT1_Warp
	release
	end

AT1_Warp::
	checkplayergender
	setvar VAR_RYU_DS_LANA_STAGE, 75
	compare VAR_RESULT, FEMALE
	goto_if_eq AT1_AltTeleport
	delay 5
	special RyuWarp
	fadescreen 0
	release
	end 
	
AT1_AltTeleport::
	delay 5
	special RyuWarp2
	fadescreen 0
	release
	end
	
AT1_Cam1:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
AT1_WalkUp:
	walk_slow_up
	walk_slow_up
	step_end

AT1_RunUp:
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_up
	step_end
	
AT1_Cam2:
	walk_fast_down
	step_end
	
AT1_LanaWalkUp2:
	walk_up
	walk_up
	walk_up
	walk_in_place_up
	step_end
	
AT1_PlayerFollow:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AT1_Story1:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Yo, Lana, hold up!\nWhat's the deal? Why're you doing\lall of this?$"

AT1_Story2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Let...go!$"
	
AT1_Story21:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Not until you tell me what's going\non. This doesn't make any sense!\pWhy won't you say anything? Why\nwon't you speak to me? We're\lfriends, aren't we?$"

AT1_Story22:	
	.string "{COLOR LIGHT_RED}{SHADOW RED}Friends...? With a nobody like me?$"
	
AT1_Story23:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Who told you that?\p{COLOR LIGHT_RED}{SHADOW RED}... ... ... ...$"

AT1_Story3:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}C'mon Lana...talk to me.$"

AT1_Story4:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Lana, don't!$"
	
AT1_Story5:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Strong...!$"
	
AT1_Story6:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Lana, stop! You're gonna get hurt!\p{COLOR LIGHT_RED}{SHADOW RED}... ... ... ...\pGo!$"
	
AT1_Story7:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana sends out another pokémon,\n only for it to be defeated moments\l later.)$"
	
AT1_Story8:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Look out!$"
	
AT1_BlackedOut:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} feels a white hot twinge of pain\n before passing out...)$"

AT1_SaveLana:
	walk_fastest_up
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_right
	walk_in_place_fastest_up
	emote_exclamation_mark
	step_end

