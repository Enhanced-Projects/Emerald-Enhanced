RustburoCity_DevonCorp1fStoryMap_MapScripts::
	.byte 0

	
DC_FirstFloorSceneStart::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, DC_FirstFloorPlayerEntry
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	msgbox DC_YouHearNoise
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, DC_FirstFloorCamera1
	waitmovement OBJ_EVENT_ID_CAMERA
	savebgm 423
	fadenewbgm 423
	msgbox DC_BeenThroughThis
	closemessage
	msgbox DC_WeKnowInfoIsHere
	closemessage
	msgbox DC_ItsOurJob
	closemessage
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 4
	applymovement OBJ_EVENT_ID_CAMERA, DC_ReturnCameraToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, DC_PlayerToEmployees
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 4, Common_Movement_FaceUp
	waitmovement 4
	msgbox DC_DoMeAFavor
	clearflag FLAG_RYU_DEVON_CORPORATE_HIDE_MSITO
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DC_ExitFirstFloor
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOOR
	setvar VAR_RYU_DEVON, 45 @Player needs to go find Ms. Ito north of rustburo.
	fadescreen 1
	warpsilent MAP_RUSTBORO_CITY, 255, 12, 15
	delay 20
	release
	end
	
	
DC_YouHearNoise:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You hear an argument in the lobby.)$"
	
DC_BeenThroughThis:
	.string "We've been through this countless\n"
	.string "times! Only authorized people are\l"
	.string "allowed to enter here.$"

DC_WeKnowInfoIsHere:
	.string "Gabby: We know the info is here,\n"
	.string "and we're not leaving here without\l"
	.string "it.\p"
	.string "We're the voice of the people,\n"
	.string "and the people have the right to\l"
	.string "know!$"
	
DC_ItsOurJob:
	.string "Ty: Plus, it's our job so...\p"
	.string "Worker: Why me...$"
	
DC_DoMeAFavor:
	.string "Hey, you're that new hire, right?\p"
	.string "I'm Hajio...\p"
	.string "... … ...\p"
	.string "Do me a favor and go find Ms. Ito.\n"
	.string "She's the woman who sits at the\p"
	.string "Front Desk here. She's been on\n"
	.string "lunch break for over an hour and\p"
	.string "hasn't come back. Because of that,\n"
	.string "now it's up to us to deal with\l"
	.string "this situation...\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Sure thing.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Ms. Ito...she's gotta be somewhere\n"
	.string " around town. I should ask the\l"
	.string " locals.)$"

DC_FirstFloorPlayerEntry:
	walk_down
	walk_down
	emote_exclamation_mark
	step_end
	
DC_FirstFloorCamera1:
	walk_diag_southwest
	walk_left
	walk_left
	walk_left
	step_end
	
DC_ReturnCameraToPlayer:
	walk_diag_northeast
	walk_right
	walk_right
	walk_right
	step_end
	
DC_PlayerToEmployees:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_down
	step_end
	
DC_ExitFirstFloor:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_down
	step_end

