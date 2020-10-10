MirageCave_LakeCave_MapScripts::
	.byte 0

RyuLegendary_Hoopa::
	goto_if_set FLAG_RYU_HOOPA, ryu_end
	goto_if_set FLAG_RYU_HOOPA_RAN, ryu_end
	@msgbox RyuLegendary_IntroHoopa
	setvar VAR_TEMP_5, SPECIES_HOOPA
	setvar VAR_TEMP_9, ITEM_PSYCHIC_SEED
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, RyuLegendary_CaughtHoopa @if the mon was caught, set main flag and delete object permanently.
	setflag FLAG_RYU_HOOPA_RAN @since the outcome wasn't caught, the mon will disappear until player clears champion or title defense again.
	removeobject 1 @Put the porymap object ID here
	release
	end

RyuLegendary_CaughtHoopa::
	setflag FLAG_RYU_HOOPA @once this flag is set, the mon will never come back.
	removeobject 1 @Put the porymap object ID here, this will be permanent since the main flag for legendary is set.
	release
	end

RyuLegendary_IntroHoopa: @put your intro here
	.string "$"
