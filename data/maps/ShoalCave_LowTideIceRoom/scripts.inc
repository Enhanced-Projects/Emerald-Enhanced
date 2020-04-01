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
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, VAR_RESULT, ITEM_NEVER_MELT_ICE
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
    .string "The stone is iced over, as if\n"
	.string "it was flash frozen!\p"
	.string "Touch the stone?$"

