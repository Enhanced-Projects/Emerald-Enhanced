FieryPath_MapScripts:: @ 8230F24
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition: @ 8230F2A
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor:: @ 8230F37
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FP_Entei::
	goto_if_set FLAG_RYU_ENTEI, RyuLegendary_Stoneisdull
	msgbox FP_Entei_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox FP_Entei_TouchedStone
	playmoncry SPECIES_ENTEI, 0
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setwildbattle SPECIES_ENTEI, VAR_RESULT, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_ENTEI
	release
	end

FP_Entei_TouchQuery:
	.string "The stone is toasty.\n"
	.string "Touch the stone?$"

FP_Entei_TouchedStone:
	.string "{PLAYER} touched the stone.\n"
	.string "It's so nice and warm...$"

