MeteorFalls_3F_MapScripts::
	.byte 0

MeteorFalls_Necrozma::
	goto_if_set FLAG_RYU_NECROZMA, ryu_end
	goto_if_set FLAG_RYU_NECROZMA_RAN, ryu_end
	msgbox OverworldLegendary_IntroNecrozma
	setvar VAR_TEMP_5, SPECIES_NECROZMA
	setvar VAR_TEMP_9, ITEM_DARK_GEM
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, MeteorFalls_NecrozmaGotAway
	case B_OUTCOME_LOST, MeteorFalls_NecrozmaGotAway
	case B_OUTCOME_MON_FLED, MeteorFalls_NecrozmaGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_NecrozmaGotAway
	setflag FLAG_RYU_NECROZMA
	removeobject 1 @Put the porymap object ID here
	release
	end

MeteorFalls_NecrozmaGotAway::
	setflag FLAG_RYU_NECROZMA_RAN
	removeobject 1 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroNecrozma: @put your intro here
	.string "$"
