DesertTomb1F_MapScripts::
	.byte 0
	
NM8_HardStone::@@
	lock
	goto_if_set FLAG_RYU_NM8_HARDSTONE, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_HARD_STONE
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_HARDSTONE
	releaseall
	end
	
NM8_MaxRepel::@@
	lock
	goto_if_set FLAG_RYU_NM8_MAXREPEL, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_MAX_REPEL
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_MAXREPEL
	releaseall
	end
	
NM8_LuxuryBall::@@
	lock
	goto_if_set FLAG_RYU_NM8_LUXBALL, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_LUXURY_BALL
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_LUXBALL
	releaseall
	end
	
NM8_Earthquake::@@
	lock
	goto_if_set FLAG_RYU_NM8_EQ, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_TM26
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_EQ
	releaseall
	end
	
NM8_PPMax::@@
	lock
	goto_if_set FLAG_RYU_NM8_PPMAX, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_PP_MAX
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_PPMAX
	releaseall
	end
	
NM11_MaxRevive::@@
	lock
	goto_if_set FLAG_RYU_NM8_MAXREV, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_MAX_REVIVE
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_MAXREV
	releaseall
	end

NM11_MaxElixer::@@
	lock
	goto_if_set FLAG_RYU_NM8_MAXELIX, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_SCIZORITE
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_MAXELIX
	releaseall
	end

NM10_BigPearl::@@
	lock
	goto_if_set FLAG_RYU_NM8_BIGPEARL, Ryu_ItemGivenScript
	setvar VAR_TEMP_7, ITEM_BIG_PEARL
	call Ryu_GiveItemScript
	setflag FLAG_RYU_NM8_BIGPEARL
	releaseall
	end


NM8_Gatekeeper::
	@trainerbattle_single TRAINER_GATEKEEPER, NM8_GK_Intro, NM8_GK_Defeat
	msgbox NM8_GK_Chat, MSGBOX_AUTOCLOSE
	end
	
NM8_GK_Intro:
    .string "I found this cave first, It will\n"
    .string "be named after me. I can't have\l"
    .string "you raiding this place before I do!$"


NM8_GK_Defeat:
    .string "No! The discovery of my lifetime!$"

NM8_GK_Chat:
    .string "You can have the stuff here, as\n"
    .string "long as the cave gets named after\l"
    .string "me!$"

NM10_CrystalOnix::
	msgbox NM10_CrystalOnixSpeech
	closemessage
	playmoncry SPECIES_ONIX, 0
	special checkbadgecount
	compare VAR_RESULT, 8
	goto_if_ne NM10_CONIXNA
	msgbox NM10_NotTooWeak
	waitmoncry
	setwildbattle SPECIES_CRYSTAL_ONIX, 90, ITEM_LAGGING_TAIL
	setflag FLAG_RYU_HIDE_CRYSTALONIX_OW
	removeobject 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	releaseall
	end

NM10_CONIXNA::
	msgbox NM10_NotWorthy
	releaseall
	end

NM10_NotWorthy:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}You briefly see it stare at you\n"
	.string "and then return to its\l"
	.string "original position.\p"
	.string "Maybe you should come back later.$"
	
NM10_CrystalOnixSpeech:
    .string "It is the most beautiful Pokémon\n"
    .string "statue you've ever seen.\p"
	.string "It has a faint yellow glow to it.\n$"

NM10_NotTooWeak:
    .string "... ... ... ...\p"
    .string "Wait...\p"
    .string "IT Moved!?$"


