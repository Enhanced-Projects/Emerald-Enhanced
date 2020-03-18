AlteringCave_MapScripts:: @ 823B177
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition: @ 823B17D
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AS_RegigigasEncounter::
	goto_if_set FLAG_RYU_REGIGIGAS, RyuLegendary_Stoneisdull
	msgbox AS_Regigigas_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox AS_Regigigas_TouchedStone
	playmoncry SPECIES_REGIGIGAS, 0
	closemessage
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, VAR_RESULT, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_REGIGIGAS
	release
	end

AS_Regigigas_TouchQuery::
	.string "The stone is ancient and has a\n"
	.string "mystical quality to it.\p"
	.string "Touch the stone?$"

AS_Regigigas_TouchedStone::
	.string "You feel older as soon as\n"
	.string "you make contact with the stone.$"
