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
	goto_if_set FLAG_RYU_ENTEI, ryu_end
	msgbox OverworldLegendary_IntroEntei
	setvar VAR_TEMP_5, SPECIES_ENTEI
	setvar VAR_TEMP_7, ITEM_FLAME_ORB
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, FP_EnteiGotAway
	case B_OUTCOME_LOST, FP_EnteiGotAway
	case B_OUTCOME_MON_FLED, FP_EnteiGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, FP_EnteiGotAway
	setflag FLAG_RYU_ENTEI
	removeobject 2 @Put the porymap object ID here
	release
	end

FP_EnteiGotAway::
	setflag FLAG_RYU_ENTEI_RAN
	removeobject 2 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroEntei: @put your intro here
	.string "$"

