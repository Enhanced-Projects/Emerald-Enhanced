Route114_SuicuneCave_MapScripts::
	.byte 0

Route114_SuicuneCave_Suicune::
	goto_if_set FLAG_RYU_SUICUNE, RyuLegendary_Stoneisdull
	msgbox Route114_SuicuneCave_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox Route114_SuicuneCave_TouchedStone
	playmoncry SPECIES_SUICUNE, 0
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setwildbattle SPECIES_SUICUNE, VAR_RESULT, ITEM_MYSTIC_WATER
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_SUICUNE
	release
	end
	
Route114_SuicuneCave_TouchedStone:
    .string "{PLAYER} touched the stone.\p"
	.string "Ewww... Its gross!$"
	
Route114_SuicuneCave_TouchQuery:
    .string "The stone is slimy and wet.\p"
	.string "Touch the stone?$"
