Route135_ManaphyTemple_MapScripts::
	.byte 0

r135_Manaphy::
	goto_if_set FLAG_RYU_MANAPHY, RyuLegendary_Stoneisdull
	msgbox r135_Manaphy_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox r135_Manaphy_TouchedStone
	playmoncry SPECIES_MANAPHY, 0
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setwildbattle SPECIES_MANAPHY, VAR_RESULT, ITEM_MYSTIC_WATER
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_MANAPHY
	release
	end

r135_Manaphy_TouchedStone:
    .string "{PLAYER} touched the stone.\p"
	.string "It feels wet, as if it had been\n"
	.string "submerged.$"

r135_Manaphy_TouchQuery:
    .string "The stone is shining brightly.\p"
	.string "Touch the stone?$"
