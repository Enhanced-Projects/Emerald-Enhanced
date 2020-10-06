Route66_MapScripts::
	.byte 0

RyuLegendary_Celebi::
	goto_if_set FLAG_RYU_CELEBI, ryu_end
	goto_if_set FLAG_RYU_CELEBI_RAN, ryu_end
	msgbox RyuLegendary_IntroCelebi
	setvar VAR_TEMP_5, SPECIES_CELEBI
	setvar VAR_TEMP_9, ITEM_BIG_ROOT
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, RyuLegendary_CaughtCelebi @if the mon was caught, set main flag and delete object permanently.
	setflag FLAG_RYU_CELEBI_RAN @since the outcome wasn't caught, the mon will disappear until player clears champion or title defense again.
	removeobject 1 @Put the porymap object ID here
	release
	end

	RyuLegendary_CaughtCelebi::
	setflag FLAG_RYU_CELEBI @once this flag is set, the mon will never come back.
	removeobject 1 @Put the porymap object ID here, this will be permanent since the main flag for legendary is set.
	release
	end


RyuLegendary_IntroCelebi: @put your intro here
	.string "$"

Route66_EventScript_HintSign::
	msgbox Route66_Text_HintSign, MSGBOX_SIGN
	end

Route66_Text_HintSign:
	.string "Did you know you can use the bike\n"
	.string "anywhere, no matter the surface?$"

Route66_AbsorbBulb::
	lockall
	goto_if_set FLAG_RYU_ROUTE_66_ABSORB_BULB, FrostyForestEnd
	giveitem ITEM_ABSORB_BULB
	setflag FLAG_RYU_ROUTE_66_ABSORB_BULB
	release
	end
