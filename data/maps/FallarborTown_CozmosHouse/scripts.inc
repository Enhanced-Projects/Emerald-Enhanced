FallarborTown_CozmosHouse_MapScripts:: @ 8200F12
	.byte 0

FT_FixCozmo::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	release
	end

FallarborTown_CozmosHouse_EventScript_ProfCozmo:: @ 8200F13
	lock
	faceplayer
	goto_if_set FLAG_RYU_DEVON_MISSION6START, FT_Mission6
	goto_if_set FLAG_RYU_DEVON_MISSION5COMPLETE, FT_Mission5Done
	goto_if_set FLAG_RYU_DEVON_MISSION5START, FT_OnMission5
	goto_if_set FLAG_RYU_DEVON_MISSION_3_DONE, FT_DM3Done
	goto_if_set FLAG_RYU_DEVON_MISSION3START, FT_OnMission3
	msgbox FT_CozmoIntro MSGBOX_DEFAULT
	additem ITEM_BIG_PEARL, 1
	msgbox FT_OnMission3Msg MSGBOX_DEFAULT
	checkitem ITEM_METEORITE, 1
	compare VAR_RESULT, 1
	goto_if_eq FT_AlreadyHaveMeteorite
	setflag FLAG_RYU_DEVON_MISSION3START
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	release
	end
	
FT_OnMission3:
	lock
	faceplayer
	msgbox M3InProgress MSGBOX_DEFAULT
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	release
	end
	
FT_DevonMission3::
	goto_if_set FLAG_RYU_DEVON_MISSION_3_DONE, FT_DM3Done
	lock
	faceplayer
	msgbox FT_OnMission3Msg MSGBOX_DEFAULT
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	release
	end
	
FT_DM3Done::
    lock
	faceplayer
	msgbox FT_MeteorReward1 MSGBOX_DEFAULT
	removeitem ITEM_METEORITE, 1
	addmoney 40000
	setflag FLAG_RYU_DEVON_MISSION4COMPLETE
	goto FT_Mission4
	
FT_Mission4::
	lock
	faceplayer
	msgbox FT_Mission4Intro MSGBOX_DEFAULT
	setflag FLAG_RYU_DEVON_MISSION5START
	setflag FLAG_RYU_DEVON_HIDE_MATT_SUB
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	clearflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	release
	end
	
FT_Mission5Done::
	msgbox FT_M5Done MSGBOX_DEFAULT
	removeitem ITEM_FAME_CHECKER, 1
	giveitem ITEM_CHOICE_SCARF
	msgbox FT_M5RewardDesc MSGBOX_DEFAULT
	setflag FLAG_RYU_DEVON_MISSION6START
	goto FT_Mission6
	
FT_Mission6::
	goto_if_set FLAG_RYU_DEVON_CORPORATE, FT_NoInteract
    msgbox FT_CozmoOutro MSGBOX_DEFAULT
	multichoice 20, 8, 135, 1
	switch VAR_RESULT
	case 0, FT_CozmoNextMission
	case 1, FT_ReturnToDevon
	goto FT_ReturnToDevon
	
FT_NoInteract:
	msgbox FT_NoInteraction MSGBOX_DEFAULT
	release
	end
	
FT_CozmoNextMission::
	call_if_set FLAG_RYU_DS_LANETTE_ACQ, FT_CheckLanette
	call_if_set FLAG_RYU_DS_LANETTE_ACQ, FT_CheckLanette2
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	setflag FLAG_RYU_WAYSTONE_DISABLED
	closemessage
	msgbox FT_wait MSGBOX_DEFAULT
	setflag FLAG_RYU_DEVON_SCIENTIST
	fadescreen 0
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 101
	setvar VAR_WEATHER_INSTITUTE_STATE, 0
	warp MAP_ROUTE119_WEATHER_INSTITUTE_1F, 255, 10, 12
	release
	end
	
FT_CheckLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, FT_FinishQuestFirst
	return
	
FT_CheckLanette2::
	goto_if_unset FLAG_RYU_DS_LANETTE_BADEND, FT_FinishQuestFirst
	return
	
FT_FinishQuestFirst::
	msgbox FT_MustFinishLanette
	release
	end
	
FT_MustFinishLanette:
	.string "{COLOR RED}{SHADOW LIGHT_GREY} You must finish the Lanette quest\n"
	.string "before starting the Devon Line.$"
	

FT_OnMission5::
	msgbox FT_OnMission5Msg MSGBOX_DEFAULT
	release
	end
	
FT_ReturnToDevon::
	msgbox FT_DevonMsg MSGBOX_DEFAULT
	setflag FLAG_RYU_DEVON_CORPORATE
	closemessage
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27 , FT_CozmoHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FT_DefeatedMtChimney
	msgbox FT_CozmoWentToMF, MSGBOX_DEFAULT
	release
	end

FT_CozmoHappy:: @ 8200FE4
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FT_CozmoWentToMF:: @ 82012BC
	.string "Prof. Cozmo went off to Meteor Falls\n"
	.string "on Route 114 with some people from\l"
	.string "Team Magma.$"

FT_DefeatedMtChimney::
	msgbox FT_DefeatedMtChimneyText, MSGBOX_DEFAULT
	release
	end

FT_DefeatedMtChimneyText: @ 8201310
	.string "Poor Prof. Cozmo…\n"
	.string "He's so depressed… I feel sorry for him.$"
	
FT_wait:
	.string "Wait...you're interested in the\n"
	.string "affairs of a scientist? That's\l"
	.string "certainly surprising.\p"
	.string "Hmm...\p"
	.string "If that's the case, then how about\n"
	.string "becoming an apprentice at the\p"
	.string "Weather Institute? They're always\n"
	.string "eager to take on new recruits.\p"
	.string "Stick around for a moment, and\n"
	.string "I'll take you there.$"

	
FT_NoInteraction:
	.string "Why are you still here?\pYou should be heading back to\nsee Mr. Stone!$"
	
FT_DevonMsg:
	.string "Who knows? Maybe President Stone\nhas further work for you to do.\pThanks again!$"

FT_CozmoOutro:
	.string "What's that? There's no other\nassignment I have for you.\pYou may leave.$"

FT_M5Done:
    .string "Cozmo: Oh! You found it! Thanks!$"

FT_M5RewardDesc:
    .string "That item is useful to people who\n"
    .string "use strategy in their battles.\p"
    .string "Anyways, now that I have my Detector\n"
    .string "I can resume my research on the\l"
    .string "meteorite.\p"
	.string "Head back to Devon Corp and\n"
    .string "give Mr. Stone my regards!$"


FT_OnMission5Msg:
    .string "Cozmo: You should be on your way\n"
    .string "to Lilycove. I need my Radiation\l"
    .string "Detector.$"

FT_OnMission3Msg:
	.string "Can you go to Mt. Chimney and\nretrieve my meteorite? I don't\lknow what they plan to do with it,\lbut It's very valuable.\pI'd like it back, so I can continue\nmy research.$"
	
M3InProgress:
	.string "Cozmo: Have you been to Mt. Chimney\nyet? Please hurry.$"
	
FT_CozmoIntro:
	.string "Hi there! Allow me to formally\n"
	.string "introduce myself.\p"
	.string "I am Professor Cozmo, and I\n"
	.string "work with Mr Stone and other\l"
	.string "scientists on excavation projects.\p"
	.string "I am usually called when anything\n"
	.string "from space is involved.\l"
	.string "... ... ... ... ...\p"
	.string "Thank you so much for scaring off\n"
	.string "those goons. I'm not sure what they\l"
	.string "would have done to me if you\l"
	.string "didn't show up.\p"
	.string "Mr Stone says that you'd be, er, \n"
	.string "willing to help me out some more.\p"
	.string "Don't worry, I'll make sure you get\n"
	.string "paid properly for your time.$"
	
FT_AlreadyhaveMsg:
	.string "Prof. Cozmo: Oh! You already\nretreived my Meteorite! Wow,\lyou're quite good, aren't you?$"
	
FT_MeteorReward2:
	.string "Well here's my reward, ¥60000!\nYou deserve every single bit of it.$"
	
FT_MeteorReward1:
	.string "Ah! you got it! my Meteorite!\nThanks so much.\pHere's my reward, ¥40000!\nYou earned it!$"

FT_Mission4Intro:
	.string "Cozmo: So, {PLAYER}, can I get you\n"
    .string "to go to the cave in northeast\p"
    .string "Lilycove to retrieve my Radiation\n"
    .string "Detector?\p"
    .string "Aqua stole it a long time ago, and\n"
    .string "I simply can't afford a new one.$"

	
FT_AlreadyHaveMeteorite::
	msgbox FT_AlreadyhaveMsg MSGBOX_DEFAULT
	removeitem ITEM_METEORITE, 1
	addmoney 60000
	msgbox FT_MeteorReward1 MSGBOX_DEFAULT
	goto FT_Mission4

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow: @ 8200FEE
	.string "Prof. Cozmo: Oh…\n"
	.string "I never should have let myself be\l"
	.string "conned into telling Team Magma where\l"
	.string "you can find Meteorites…\p"
	.string "That Meteorite from Meteor Falls…\n"
	.string "It's never going to be mine now…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt: @ 82010A2
	.string "Oh!\n"
	.string "Hah?\p"
	.string "That item…\p"
	.string "Could it be?\p"
	.string "Is it the Meteorite that Team Magma\n"
	.string "took from Meteor Falls?\p"
	.string "Please, may I have it?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM: @ 8201159
	.string "Prof. Cozmo: This TM, it represents\n"
	.string "my feeling of gratitude.\l"
	.string "Please use it!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch: @ 82011A5
	.string "Prof. Cozmo: Oh, I can't believe it.\n"
	.string "This is really, really great!\p"
	.string "This is really going to help my research!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment: @ 8201212
	.string "Prof. Cozmo: Oh, but…\n"
	.string "I'm crushed with disappointment…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite: @ 8201249
	.string "Prof. Cozmo: Please, may I have that\n"
	.string "Meteorite?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls: @ 82012BC
	.string "Prof. Cozmo went off to Meteor Falls\n"
	.string "on Route 114 with some people from\l"
	.string "Team Magma.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo: @ 8201310
	.string "Poor Prof. Cozmo…\n"
	.string "He's so depressed… I feel sorry for him.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy: @ 820134B
	.string "Look at Prof. Cozmo…\n"
	.string "He's so happy! I think it's cute.$"

