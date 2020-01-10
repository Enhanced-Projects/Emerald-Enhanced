SafariZone_HiddenGrotto_MapScripts::
	.byte 0


SZ_HG_MewtwoFight2::
	lock
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 111
	goto_if_eq SZ_HG_Continue
	trainerbattle_single TRAINER_STORY_MEWTWO_2, SZ_HG_M2Intro, SZ_HG_M2Defeat, SZ_HG_Continue
	end
	
SZ_HG_Continue::
	goto_if_set FLAG_RYU_MEWTWO_OBTAINED, SZ_HG_NiceTry
	msgbox SZ_HG_M2Joins
	closemessage
	specialvar VAR_RESULT RyuGiveMewtwo
	compare VAR_RESULT, 1
	goto_if_ne SZ_HG_ReturnQuery
	playfanfare MUS_FANFA5
	msgbox SZ_HG_MewTwoJoinedParty
	waitfanfare
	closemessage
	setflag FLAG_RYU_MEWTWO_OBTAINED
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 115
	removeobject 1
	release
	end
	
SZ_HG_ReturnQuery::
	msgbox SZ_HG_partyFull
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 111
	release
	end
	
SZ_HG_NiceTry::
	msgbox NiceTryMsg
	release
	end
	
SZ_HG_MewTwoJoinedParty:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Mewtwo has joined your party!$"
	
SZ_HG_M2Joins:
	.string "Mewtwo: Your partners trust you\nimplicitly. I have only known\psuffering at the hands of humans\nbut you have shown me that\lnot all humans are bad.\pI would like to join you\nand know what it's like to\lbe cared for.$"
	
SZ_HG_partyFull:
	.string "Mewtwo: You don't have space\nin your party for me.\pMake space and return.$"

NiceTryMsg:
	.string "Nice try, but you have already\nobtained Mewtwo$"

SZ_HG_M2Intro:
	.string "You've found me yet again...since\n"
	.string "we have this opportunity, allow me\l"
	.string "to test your resolve once more.$"
	
SZ_HG_M2Defeat:
	.string "Your strength, your ideals...they\n"
	.string "remind me of him...$"

