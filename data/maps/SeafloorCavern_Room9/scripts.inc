SeafloorCavern_Room9_MapScripts:: @ 8234DC8
	.byte 0
	
SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
    releaseall
    end

SFC_AltKyogre::
	lockall
	playse SE_PIN
	goto_if_set FLAG_RYU_KYOGRE, ryu_end
	goto_if_unset FLAG_RYU_AQUA_LINE_DONE, ryu_end
	msgbox SFC_KyogreStaringIntently MSGBOX_DEFAULT
	playmoncry SPECIES_KYOGRE, 0
	closemessage
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	waitmoncry
	delay 10
	fadescreen 1
	removeobject 7
	removeobject 1
	fadescreen 0
	setwildbattle SPECIES_KYOGRE, VAR_RESULT, ITEM_MYSTIC_WATER
	setflag FLAG_RYU_KYOGRE
	special BattleSetup_StartLegendaryBattle
	waitstate
	setvar VAR_SKY_PILLAR_STATE, 3
	releaseall
	end
	
SFC_KyogreStaringIntently:
	.string "Kyogre is staring intently at you.$"
	
SFC_Setflags::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	setflag FLAG_RYU_AQUA_LINE_DONE
	clearflag FLAG_RYU_KYOGRE
	releaseall
	end
