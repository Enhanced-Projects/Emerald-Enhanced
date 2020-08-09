AlteringCave_MapScripts:: @ 823B177
	map_script ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition: @ 823B17D
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AS_RegigigasEncounter::
	goto_if_set FLAG_RYU_REGIGIGAS, ryu_end
	goto_if_set FLAG_RYU_REGIGIGAS_RAN, ryu_end
	msgbox OverworldLegendary_IntroRegigigas
	setvar VAR_TEMP_5, SPECIES_REGIGIGAS
	setvar VAR_TEMP_9, ITEM_EVERSTONE
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, AS_RegigigasGotAway
	case B_OUTCOME_LOST, AS_RegigigasGotAway
	case B_OUTCOME_MON_FLED, AS_RegigigasGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, AS_RegigigasGotAway
	setflag FLAG_RYU_REGIGIGAS
	removeobject 1 @Put the porymap object ID here
	release
	end

AS_RegigigasGotAway::
	setflag FLAG_RYU_REGIGIGAS_RAN
	removeobject 1 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroRegigigas: @put your intro here
	.string "$"
