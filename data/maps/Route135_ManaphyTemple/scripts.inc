Route135_ManaphyTemple_MapScripts::
	.byte 0

r135_Manaphy::
	goto_if_set FLAG_RYU_HIDE_MANAPHY, ryu_end
	goto_if_set FLAG_RYU_MANAPHY_RAN, ryu_end
	msgbox OverworldLegendary_IntroManaphy
	setvar VAR_TEMP_5, SPECIES_MANAPHY
	setvar VAR_TEMP_9, ITEM_MYSTIC_WATER
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, r135_ManaphyGotAway
	case B_OUTCOME_LOST, r135_ManaphyGotAway
	case B_OUTCOME_MON_FLED, r135_ManaphyGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, r135_ManaphyGotAway
	setflag FLAG_RYU_HIDE_MANAPHY
	removeobject 1 @Put the porymap object ID here
	release
	end

r135_ManaphyGotAway::
	setflag FLAG_RYU_MANAPHY_RAN
	removeobject 1 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroManaphy: @put your intro here
	.string "$"

