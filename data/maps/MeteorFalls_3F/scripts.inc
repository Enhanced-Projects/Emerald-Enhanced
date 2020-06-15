MeteorFalls_3F_MapScripts::
	.byte 0

MeteorFalls_Necrozma::
	goto_if_set FLAG_RYU_NECROZMA, RyuLegendary_Stoneisdull
	msgbox MeteorFalls_Necrozma_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox MeteorFalls_Necrozma_TouchedStone
	playmoncry SPECIES_NECROZMA, 0
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setwildbattle SPECIES_NECROZMA, VAR_RESULT, ITEM_MOON_STONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_NECROZMA
	release
	end

MeteorFalls_Necrozma_TouchedStone:
    .string "{PLAYER} touched the stone.\p"
	.string "The stone appears to be absorbing\n"
	.string "all light in the area.$"

MeteorFalls_Necrozma_TouchQuery:
    .string "The stone is made of black crystal.\p"
	.string "Touch the stone?$"
