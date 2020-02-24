Route66_MapScripts::
	.byte 0


r66_Celebi::
	goto_if_set FLAG_RYU_CELEBI, RyuLegendary_Stoneisdull
	msgbox r66_Celebi_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox r66_Celebi_TouchedStone
	playmoncry SPECIES_CELEBI, 0
	closemessage
	waitmoncry
	setwildbattle SPECIES_CELEBI, 90, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_CELEBI
	release
	end

r66_Celebi_TouchedStone:
    .string "{PLAYER} touched the stone.\p"
	.string "It feels so old, but so new at the\n"
	.string "same time.$"

r66_Celebi_TouchQuery:
    .string "{PLAYER}: The stone is beautifully overgrown.\p"
	.string "Touch the stone?$"
