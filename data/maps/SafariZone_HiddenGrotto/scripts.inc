SafariZone_HiddenGrotto_MapScripts::
	.byte 0


NM17_MewtwoFight2::
	lock
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 111
	goto_if_eq NM17_Continue
	trainerbattle_single TRAINER_STORY_MEWTWO_2, NM17_M2Intro, NM17_M2Defeat, NM17_Continue
	end
	
NM17_Continue::
	goto_if_set FLAG_RYU_MEWTWO_OBTAINED, Nm17_NiceTry
	msgbox NM17_M2Joins
	closemessage
	specialvar VAR_RESULT RyuGiveMewtwo
	compare VAR_RESULT, 1
	goto_if_ne NM17_ReturnQuery
	playfanfare MUS_FANFA5
	msgbox NM17_MewTwoJoinedParty
	waitfanfare
	closemessage
	setflag FLAG_RYU_MEWTWO_OBTAINED
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 115
	removeobject 1
	release
	end
	
NM17_ReturnQuery::
	msgbox NM17_partyFull
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 111
	release
	end
	
Nm17_NiceTry::
	msgbox NiceTryMsg
	release
	end
	
NM17_MewTwoJoinedParty:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Mewtwo has joined your party!$"
	
NM17_M2Joins:
	.string "Mewtwo: Your partners trust you\nimplicitly. I have only known\psuffering at the hands of humans\nbut you have shown me that\lnot all humans are bad.\pI would like to join you\nand know what it's like to\lbe cared for.$"
	
NM17_partyFull:
	.string "Mewtwo: You don't have space\nin your party for me.\pMake space and return.$"

NiceTryMsg:
	.string "Nice try, but you have already\nobtained Mewtwo$"

NM17_M2Intro:
	.string "You've found me yet again...since\n"
	.string "we have this opportunity, allow me\l"
	.string "to test your resolve once more.$"
	
NM17_M2Defeat:
	.string "Your strength, your ideals...they\n"
	.string "remind me of him...$"

