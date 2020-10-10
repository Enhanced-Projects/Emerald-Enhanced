MeteorFalls_3F_MapScripts::
	.byte 0

RyuLegendary_Necrozma::
	goto_if_set FLAG_RYU_NECROZMA, ryu_end
	goto_if_set FLAG_RYU_NECROZMA_RAN, ryu_end
	msgbox RyuLegendary_IntroNecrozma
	setvar VAR_TEMP_5, SPECIES_NECROZMA
	setvar VAR_TEMP_9, ITEM_DARK_GEM
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, RyuLegendary_CaughtNecrozma @if the mon was caught, set main flag and delete object permanently.
	setflag FLAG_RYU_NECROZMA_RAN @since the outcome wasn't caught, the mon will disappear until player clears champion or title defense again.
	removeobject 1 @Put the porymap object ID here
	release
	end

RyuLegendary_CaughtNecrozma::
	setflag FLAG_RYU_NECROZMA @once this flag is set, the mon will never come back.
	removeobject 1 @Put the porymap object ID here, this will be permanent since the main flag for legendary is set.
	release
	end


RyuLegendary_IntroNecrozma: @put your intro here
	.string "$"
