DesertRuins_MapScripts:: @ 822D95B
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_OnResume
	map_script MAP_SCRIPT_ON_LOAD , DesertRuins_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_OnTransition
	.byte 0

DesertRuins_OnResume: @ 822D96B
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DesertRuins_EventScript_TryRemoveRegirock
	end

DesertRuins_EventScript_TryRemoveRegirock:: @ 822D975
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

DesertRuins_OnLoad: @ 822D989
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_HideRegiEntrance
	end

DesertRuins_EventScript_HideRegiEntrance:: @ 822D993
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

DesertRuins_OnTransition: @ 822D9CA
	setflag FLAG_LANDMARK_DESERT_RUINS
	call_if_unset FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_ShowRegirock
	end

DesertRuins_EventScript_ShowRegirock:: @ 822D9D7
	clearflag FLAG_HIDE_REGIROCK
	return

DesertRuins_EventScript_CaveEntranceMiddle:: @ 822D9DB
	lockall
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_BigHoleInWall
	braillemessage DesertRuins_Braille_UseRockSmash
	waitbuttonpress
	closebraillemessage
	releaseall
	end

DesertRuins_EventScript_BigHoleInWall:: @ 822D9EE
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

DesertRuins_EventScript_CaveEntranceSide:: @ 822D9F8
	lockall
	braillemessage DesertRuins_Braille_UseRockSmash
	waitbuttonpress
	closebraillemessage
	releaseall
	end

DesertRuins_EventScript_Regirock:: @ 822DA02
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIROCK, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIROCK, 40, ITEM_HARD_STONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DesertRuins_EventScript_DefeatedRegirock
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq DesertRuins_EventScript_RanFromRegirock
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq DesertRuins_EventScript_RanFromRegirock
	setflag FLAG_DEFEATED_REGIROCK
	release
	end

DesertRuins_EventScript_DefeatedRegirock:: @ 822DA49
	setflag FLAG_DEFEATED_REGIROCK
	goto Common_EventScript_RemoveStaticPokemon
	end

DesertRuins_EventScript_RanFromRegirock:: @ 822DA52
	setvar VAR_0x8004, SPECIES_REGIROCK
	goto Common_EventScript_LegendaryFlewAway
	end


@==================================================================================================Leaf Events

DR_SetStage::
	lock
	addobject 2
	clearflag FLAG_HIDE_DR_LANA
	setvar VAR_RYU_DS_LANA_STAGE, 46
	addobject 2
	goto DR_LeafEvent
	
	
DR_LeafEvent::
	lock
	setvar VAR_RYU_DS_LANA_STAGE, 47
	delay 25
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, DR_CameraSequence
	waitmovement 0
	applymovement 2 DR_OpenSequence
	waitmovement 2
	playse SE_W088
	waitse
	delay 25
	fadeoutbgm 0
	playse SE_W089
	special DoSealedChamberShakingEffect1
	waitse
	call DR_LeafOpenDoor
	applymovement 2, Common_Movement_ExclamationMark
	fadeinbgm 0
	playse SE_PIN
	waitse
	applymovement OBJ_EVENT_ID_CAMERA, DR_CameraFollowsLeaf
	applymovement 2, DR_LeafToBackDoor
	waitmovement 2
	playse SE_KAIDAN
	setobjectxy 2, 16, 32
	waitse
	removeobject 2
	applymovement OBJ_EVENT_ID_CAMERA, DR_CameraReturn
	waitmovement 0
	special RemoveCameraObject
	setflag FLAG_SYS_REGIROCK_PUZZLE_COMPLETED
	setvar VAR_RYU_DS_LANA_STAGE, 48
	release
	end
	
DR_LeafCheck2::
	addobject 4
	removeobject 2
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setvar VAR_RYU_DS_LANA_STAGE, 49
	setobjectxy 2, 16, 32
	clearflag FLAG_HIDE_DR_LANA
	warp MAP_DESERT_RUINS, 255, 8, 11
	release
	end
	
	
DR_LeafEvent2::
	setvar VAR_RYU_DS_LANA_STAGE, 50
	setflag FLAG_HIDE_REGIROCK
	removeobject 1
	special DrawWholeMapView
	playse SE_BOWA2
	waitse
	addobject 3
	delay 50
	applymovement 4, Common_Movement_FaceUp
	waitmovement 4
	removeobject 3
	applymovement 4, DR_LeafToPlayer
	waitmovement 4
	drawheadshot HEAD_LANA
	msgbox DR_LeafMsg MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	applymovement OBJ_EVENT_ID_PLAYER, DR_StepRight
	waitmovement 0
	applymovement 4, DR_LeafLeaves
	waitmovement 4
	playse SE_KAIDAN @Stairs
	removeobject 4
	setflag FLAG_HIDE_DR_LANA
	waitse
	setvar VAR_RYU_DS_LANA_STAGE, 55
	setflag FLAG_HIDE_DR_LANA
	release
	end
	
DR_Warp::
	release
	end
	
DR_LeafOpenDoor::
	setmetatile 7, 19, 554, 1
	setmetatile 8, 19, 555, 1
	setmetatile 9, 19, 556, 1
	setmetatile 7, 20, 562, 1
	setmetatile 8, 20, 563, 1
	setmetatile 9, 20, 564, 1
	special DrawWholeMapView
	return
	
DR_OpenSequence:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	walk_in_place_fast_down
	step_end

DR_CameraSequence:
	walk_fast_up
	walk_fast_up
	walk_diag_northwest
	walk_diag_northwest
	step_end
	
DR_LeafToBackDoor:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
DR_CameraFollowsLeaf:
	walk_diag_northeast
	walk_diag_northeast
	walk_up
	step_end

DR_CameraReturn:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
DR_LeafToPlayer:
	walk_down
	walk_in_place_down
	step_end
	
DR_StepRight:
	walk_right
	walk_in_place_left
	step_end
	
DR_LeafLeaves:
	walk_down
	walk_down
	walk_down
	step_end
	
DR_LeafMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lana: One down...$"
	
@==================================================================================================End Leaf Events

