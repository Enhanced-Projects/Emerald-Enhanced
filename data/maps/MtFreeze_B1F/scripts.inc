MtFreeze_B1F_MapScripts::
	.byte 0

MtFreeze_B1F_Heatran::
	goto_if_set FLAG_RYU_HEATRAN, ryu_end
	setvar VAR_TEMP_5, SPECIES_HEATRAN
	setvar VAR_TEMP_9, ITEM_HEAT_ROCK
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGHEATRAN
	msgbox OverworldLegendary_IntroHeatran
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, FP_HeatranCaught
	setflag FLAG_RYU_HEATRAN_RAN
	removeobject 2 @Put the porymap object ID here
	release
	end

FP_HeatranCaught::
	setflag FLAG_RYU_HEATRAN
	removeobject 2 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroHeatran: @put your intro here
	.string "There is something on the ceiling…\n"
    .string "It is moving towards you!$"
