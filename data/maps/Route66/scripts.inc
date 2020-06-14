Route66_MapScripts::
	.byte 0


r66_Celebi::
	goto_if_set FLAG_RYU_CELEBI, RyuLegendary_Stoneisdull
	msgbox r66_Celebi_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox r66_Celebi_TouchedStone
	playmoncry SPECIES_CELEBI, 0
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setwildbattle SPECIES_CELEBI, VAR_RESULT, ITEM_BIG_ROOT
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
    .string "The stone is beautifully overgrown.\p"
	.string "Touch the stone?$"

Route66_EventScript_HintSign::
	msgbox Route66_Text_HintSign, MSGBOX_SIGN
	end

Route66_Text_HintSign:
	.string "Did you know Cut can get rid\n"
	.string "of Tall Grass?\p"
	.string "Use it to get to the other side.\p"
	.string "There is a catch, however.\p"
	.string "You can not Cut while riding\n"
	.string "on the rails.\p"
	.string "Hint: what do Krabby, Gligar,\n"
	.string "Trapinch, Mawile and Corphish\l"
	.string "have in common?$"
