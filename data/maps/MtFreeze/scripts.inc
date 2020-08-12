MtFreeze_MapScripts::
	.byte 0

MtFreeze_Articuno::
	goto_if_set FLAG_RYU_ARTICUNO, ryu_end
	goto_if_set FLAG_RYU_ARTICUNO_RAN, ryu_end
	msgbox OverworldLegendary_IntroArticuno
	setvar VAR_TEMP_5, SPECIES_ARTICUNO
	setvar VAR_TEMP_9, ITEM_NEVER_MELT_ICE
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, MtFreeze_ArticunoGotAway
	case B_OUTCOME_LOST, MtFreeze_ArticunoGotAway
	case B_OUTCOME_MON_FLED, MtFreeze_ArticunoGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, MtFreeze_ArticunoGotAway
	setflag FLAG_RYU_ARTICUNO
	removeobject 3 @Put the porymap object ID here
	release
	end

MtFreeze_ArticunoGotAway::
	setflag FLAG_RYU_ARTICUNO_RAN
	removeobject 3 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroArticuno: @put your intro here
	.string "$"
