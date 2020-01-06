SootopolisCity_MapScripts:: @ 81E565C
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
	.byte 0

SootopolisCity_OnResume: @ 81E590B
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
	end

SootopolisCity_OnTransition: @ 81E56EF
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	end

SootopolisCity_EventScript_Kiri:: @ 81E5ED8
	lock
	faceplayer
	goto SootopolisCity_EventScript_KiriGiveBerry
	release
	end


@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
SootopolisCity_EventScript_KiriGiveBerry:: @ 81E5F1B
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem_std VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_EventScript_GiveFigyBerry
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_GiveIapapaBerry
	end

SootopolisCity_EventScript_GiveFigyBerry:: @ 81E5F79
	giveitem_std ITEM_FIGY_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveIapapaBerry:: @ 81E5F9A
	giveitem_std ITEM_IAPAPA_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry:: @ 81E5FBB
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn:: @ 81E5FD8
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman2:: @ 81E5FE2
	lockall
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EventScript_ClosedSootopolisDoor:: @ 81E615D
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
	end

SootopolisCity_Text_DoorIsClosed:
	.string "$"

SootopolisCity_EventScript_Man:: @ 81E6017
	lock
	faceplayer
	release
	end

SootopolisCity_EventScript_Woman1:: @ 81E6038
	lock
	faceplayer
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy:: @ 81E608E
	lockall
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	closemessage
	applymovement 4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1:: @ 81E60E3
	lockall
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	goto SootopolisCity_EventScript_Boy1Normal
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1Normal:: @ 81E6141
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GymSign:: @ 81E614B
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign:: @ 81E6154
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_Boy2:: @ 81E635D
	lockall
	applymovement 15, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 15, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_BlackBelt:: @ 81E6393
	lockall
	applymovement 14, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Girl:: @ 81E63DB
	lockall
	applymovement 13, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 13, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Maniac:: @ 81E6411
	lockall
	applymovement 12, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 12, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_Text_GymSign: @ 81E656F
	.string "SOOTOPOLIS CITY Pokémon GYM\n"
	.string "LEADER: JUAN\p"
	.string "“The GYM LEADER with the beauty\n"
	.string "of pure water!”$"

SootopolisCity_Text_CitySign: @ 81E65C8
	.string "SOOTOPOLIS CITY\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"

SootopolisCity_Text_PhysicallyFitLivingHere: @ 81E6618
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"

SootopolisCity_Text_CaveOfOriginPleaseLeave: @ 81E6D77
	.string "Who might you be?\p"
	.string "This is the CAVE OF ORIGIN.\p"
	.string "The spirits of Pokémon, becalmed at\n"
	.string "MT. PYRE, are said to be revived here.\p"
	.string "Please leave.$"

SootopolisCity_Text_LeadSuperiorTrainerToCave: @ 81E6DFE
	.string "A person with a strong will and\n"
	.string "superior talent…\p"
	.string "A TRAINER who has knowledge and\n"
	.string "experience of many kinds of Pokémon…\p"
	.string "If such a person were to appear, I was\n"
	.string "instructed by WALLACE to lead that\l"
	.string "TRAINER to this CAVE.$"

SootopolisCity_Text_CaveOfOriginSleepsToo: @ 81E6F38
	.string "This is the CAVE OF ORIGIN…\p"
	.string "With the passing of the crisis,\n"
	.string "the cave, too, shall sleep…$"

SootopolisCity_Text_SootopolisSkyBeautiful: @ 81E6F90
	.string "SOOTOPOLIS sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "SOOTOPOLIS the most beautiful.$"

SootopolisCity_Text_NightSkyFavoriteScenery: @ 81E710B
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"

SootopolisCity_Text_ExplainWaterfallGoToGym: @ 81E7B86
	.string "That HIDDEN MACHINE contains\n"
	.string "WATERFALL.\p"
	.string "If you have the RAIN BADGE, a Pokémon\n"
	.string "that has learned that HM move can\l"
	.string "force its way up waterfalls.\p"
	.string "And where does one get the RAIN BADGE?\n"
	.string "You know, don't you?\p"
	.string "That's right! You have to beat\n"
	.string "the SOOTOPOLIS GYM LEADER.\p"
	.string "When you're all set to go, step through\n"
	.string "that door.$"

SootopolisCity_Text_DazzledByMentor: @ 81E7CBC
	.string "WALLACE: I'm sure that you will be\n"
	.string "dazzled by my mentor's breathtakingly\l"
	.string "elegant battle style.$"
