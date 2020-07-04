Route114_SuicuneCave_MapScripts::
	.byte 0


Route114_Suicune::
	goto_if_set FLAG_RYU_SUICUNE, ryu_end
	msgbox OverworldLegendary_IntroSuicune
	setvar VAR_TEMP_5, SPECIES_SUICUNE
	setvar VAR_TEMP_9, ITEM_MYSTIC_WATER
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, Route114_SuicuneGotAway
	case B_OUTCOME_LOST, Route114_SuicuneGotAway
	case B_OUTCOME_MON_FLED, Route114_SuicuneGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, Route114_SuicuneGotAway
	setflag FLAG_RYU_SUICUNE
	removeobject 1 @Put the porymap object ID here
	release
	end

Route114_SuicuneGotAway::
	setflag FLAG_RYU_SUICUNE_RAN
	removeobject 1 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroSuicune: @put your intro here
	.string "$"
