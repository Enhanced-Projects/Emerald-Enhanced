MtFreeze_B1F_MapScripts::
	.byte 0

MtFreeze_B1F_Heatran::
	goto_if_set FLAG_RYU_HEATRAN, ryu_end
	msgbox OverworldLegendary_IntroHeatran
	setvar VAR_TEMP_5, SPECIES_HEATRAN
	setvar VAR_TEMP_9, ITEM_HEAT_ROCK
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, FP_HeatranGotAway
	case B_OUTCOME_LOST, FP_HeatranGotAway
	case B_OUTCOME_MON_FLED, FP_HeatranGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, FP_HeatranGotAway
	setflag FLAG_RYU_HEATRAN
	removeobject 2 @Put the porymap object ID here
	release
	end

FP_HeatranGotAway::
	setflag FLAG_RYU_HEATRAN_RAN
	removeobject 2 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroHeatran: @put your intro here
	.string "There is something on the ceiling…\n"
    .string "It is moving towards you!$"
