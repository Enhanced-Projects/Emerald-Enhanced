SeafloorCavern_Entrance_MapScripts:: @ 823446E
	map_script ON_RESUME, SeafloorCavern_Entrance_OnResume
	map_script ON_FRAME, SFC_OnFrameScript
	.byte 0

SFC_OnFrameScript::
	map_script_2 VAR_RYU_AQUA, 131, SFCEntrance_DoAquaScene
	.2byte 0

SeafloorCavern_Entrance_OnResume: @ 8234474
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	end

SFCEntrance_DoAquaScene::
	lockall
	setvar VAR_RYU_AQUA, 133 @Player is watching seafloor cavern entrance scene.
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	fadenewbgm 386
	delay 30
	msgbox SFC_WeveArrived
	closemessage
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	msgbox SFC_PlayerImLeaving
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox SFC_SorryAboutThis
	closemessage
	applymovement 2, Common_Movement_FaceUp
	waitmovement 2
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	call SFC_RemoveObjects
	fadenewbgm 438
	delay 60
	fadescreen FADE_FROM_BLACK
	setvar VAR_RYU_AQUA, 135 @Player is watching second part of seafloor cavern scene.
	goto SFC_DoAquaScenePart2

SFC_DoAquaScenePart2::
	applymovement OBJ_EVENT_ID_PLAYER, SFC_PlayerPacing @4 right, 9 left, 5 right
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox SFC_EllipsisGettingWorried
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, SFC_PlayerUp @up 3
	waitmovement 3
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	addobject 9
	applymovement 9, SFC_StevenToPlayer @up 4
	waitmovement 9
	msgbox SFC_YouAgain
	closemessage
	applymovement 9, Common_Movement_StepUp
	waitmovement 9
	msgbox SFC_DontYouGetIt
	closemessage
	fadenewbgm 470
	delay 20
	setvar VAR_RYU_AQUA, 137 @Player is watching third part of seafloor cavern scene
	goto SFC_DoAquaScenePart3

SFC_DoAquaScenePart3::
	playse SE_W089
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 9  @ num shakes
	setvar VAR_0x8007, 10  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_W088
	waitse
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 9
	fadenewbgm MUS_DUMMY
	delay 30
	playmoncry SPECIES_KYOGRE, 0
	waitmoncry
	fadenewbgm 470
	msgbox SFC_ItsTooLate
	closemessage
	applymovement 9, SFC_StevenEscapes @fast down 6
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOOR
	waitse
	addobject 10
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement 10, Common_Movement_StepDown
	waitmovement 10
	msgbox SFC_HahaWeDidIt
	closemessage
	setvar VAR_RYU_AQUA, 139 @Player is in the sub for the 4th part of the aqua shelly scene
	warpsilent MAP_AQUA_SUBMARINE, 255, 1, 18
	waitstate


SFC_WeveArrived:
	.string "We've arrived as expected.\p"
    .string "Now all that's left is to find Kyogre\n"
    .string "and awaken it.$"

SFC_PlayerImLeaving:
	.string "{PLAYER}, I'm leaving you in charge\n"
    .string "of guarding the sub as well as the\l"
    .string "cavern entrance.\p"
    .string "The rest of us will head inside.$"

SFC_SorryAboutThis:
	.string "Sorry about this, mate, but this is\n"
    .string "the most important task to handle,\l"
    .string "and only you can do it.$"

SFC_EllipsisGettingWorried:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ... ...\n"
    .string "I'm getting worried...maybe I should-$"

SFC_YouAgain:
	.string "You again...Team Aqua has gone too\n"
    .string "far this time.\p"
    .string "Don't you realize what you're doing\n"
    .string "will spell disaster for all Hoenn!?\p"
    .string "I found out only recently.\n"
    .string "And yet you're still going through\p"
    .string "with it.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I'm only following orders until-$"

SFC_DontYouGetIt:
	.string "Don't you get it? We don't have-!$"

SFC_ItsTooLate:
	.string "It's too late...!\n"
    .string "I must go warn the others!$"

SFC_HahaWeDidIt:
	.string "Hahaha! We've done it!\p"
    .string "Kyogre has been awakened, and now\n"
    .string "with its' power, we'll usher in a\p"
    .string "perfect utopia!\p"
    .string "Come, back to the sub!$"

SFC_PlayerPacing:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SFC_PlayerUp:
	walk_up
	walk_up
	walk_up
	step_end

SFC_StevenToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SFC_StevenEscapes:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end


SeafloorCavern_Entrance_EventScript_Grunt:: @ 8234485
	lockall
	compare VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	goto_if_eq SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	delay 20
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm 1
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort:: @ 82344ED
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast:: @ 8234523
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest:: @ 823452E
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth:: @ 8234539
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep: @ 8234544
	.string "Hey!\n"
	.string "I remember your face!\p"
	.string "If you're here, it must mean that\n"
	.string "you're about to mess with us again!\p"
	.string "A punk like you, do you really think\n"
	.string "you can take on Team Aqua?\p"
	.string "I'd say you're too early by about\n"
	.string "a trillion years!\p"
	.string "You're a perfect fit for the likes of\n"
	.string "Team Magma!\p"
	.string "Speaking of Team Magma, I hear they\n"
	.string "were spotted near Mossdeep.\p"
	.string "That bunch of goons, they sure don't\n"
	.string "look good near the sea!$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort: @ 82346C8
	.string "A punk like you, do you really think\n"
	.string "you can take on Team Aqua?\p"
	.string "I'd say you're too early by about\n"
	.string "a trillion years!\p"
	.string "You're a perfect fit for the likes of\n"
	.string "Team Magma!\p"
	.string "Speaking of Team Magma, I hear they\n"
	.string "were spotted near Mossdeep.\p"
	.string "That bunch of goons, they sure don't\n"
	.string "look good near the sea!$"


SFC_RemoveObjects::
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 1
	return

