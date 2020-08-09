Route66_MapScripts::
	.byte 0

r66_Celebi::
	goto_if_set FLAG_RYU_CELEBI, ryu_end
	goto_if_set FLAG_RYU_CELEBI_RAN, ryu_end
	msgbox OverworldLegendary_IntroCelebi
	setvar VAR_TEMP_5, SPECIES_CELEBI
	setvar VAR_TEMP_9, ITEM_BIG_ROOT
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, r66_CelebiGotAway
	case B_OUTCOME_LOST, r66_CelebiGotAway
	case B_OUTCOME_MON_FLED, r66_CelebiGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, r66_CelebiGotAway
	setflag FLAG_RYU_CELEBI
	removeobject 1 @Put the porymap object ID here
	release
	end

r66_CelebiGotAway::
	setflag FLAG_RYU_CELEBI_RAN
	removeobject 1 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroCelebi: @put your intro here
	.string "$"

Route66_EventScript_HintSign::
	msgbox Route66_Text_HintSign, MSGBOX_SIGN
	end

Route66_Text_HintSign:
	.string "Did you know you can use the bike\n"
	.string "anywhere, no matter the surface?$"
