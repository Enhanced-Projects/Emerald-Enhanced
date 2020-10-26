DebugMap_MapScripts::
	map_script ON_FRAME DebugMap_OnFrameMapScript
	.byte 0

DebugMap_OnFrameMapScript:
	map_script_2 VAR_RYU_AQUA, 5, DebugMap_TestScene
	map_script_2 VAR_RYU_AQUA, 10, DebugMap_TestScene2
	.2byte 0

DebugMap_TestScene::
	fadescreen FADE_TO_BLACK
	setvar VAR_RYU_AQUA, 8
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, RDB_DesyncCamera
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	fadescreen FADE_FROM_BLACK
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	applymovement 1, DebugMap_ChaseScene
	applymovement 2, DebugMap_ChaseScene
	applymovement OBJ_EVENT_ID_PLAYER, DebugMap_ChaseScene
	delay 120
	msgbox DebugMap_ChaseSceneMsg
	closemessage
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 1, DM_TurnToSub
	waitmovement 1
	playse SE_W088
	waitse
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	applymovement 1, Common_Movement_FaceRight
	waitmovement 1
	removeobject 2
	fadescreen FADE_TO_BLACK
	setvar VAR_RYU_AQUA, 10
	warpsilent MAP_DEBUG_MAP, 255, 26, 11
	waitstate

DebugMap_TestScene2::
	fadescreen FADE_TO_BLACK
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, RDB_DesyncCamera
	waitmovement OBJ_EVENT_ID_CAMERA
	fadescreen FADE_FROM_BLACK
	setvar VAR_RYU_AQUA, 50
	setmetatile 27, 6, 736, 0
	setmetatile 27, 7, 240, 0
	special DrawWholeMapView
	playse SE_W088
	special DrawWholeMapView
	waitse
	msgbox DebugMap_OhNo
	closemessage
	fadescreen FADE_TO_BLACK
	end

DebugMap_OhNo:
	.string "Oh, no!$"

DebugMap_ChaseSceneMsg:
	.string "Kyogre! I have the Blue Orb!\nObey me!$"

DebugMap_ChaseScene:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

DM_TurnToSub:
	face_right
	walk_right
	walk_right
	walk_right
	step_end