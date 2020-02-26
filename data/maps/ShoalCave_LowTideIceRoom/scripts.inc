ShoalCave_LowTideIceRoom_MapScripts:: @ 82396A1
	.byte 0

SC1_Articuno::
	goto_if_set FLAG_RYU_ARTICUNO, RyuLegendary_Stoneisdull
	msgbox SC1_Articuno_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox SC1_Articuno_TouchedStone
	playmoncry SPECIES_ARTICUNO, 0
	closemessage
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 90, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_ARTICUNO
	release
	end

SC1_Articuno_TouchedStone:
    .string "{PLAYER} touched the stone.\p"
	.string "It's really cold!$"

SC1_Articuno_TouchQuery:
    .string "{PLAYER}: The stone is iced over.\n"
	.string "as if it was flash frozen!\p"
	.string "Touch the stone?$"

