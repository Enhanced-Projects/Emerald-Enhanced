MtChimney_MapScripts:: @ 822EDC1
	map_script ON_WARP, SFC_OnWarp
	map_script ON_RESUME, MtChimney_OnResume
	map_script ON_TRANSITION, MtChimney_OnTransition
	map_script ON_FRAME, MC_OnFrameScript
	.byte 0
	
MC_OnFrameScript::
	map_script_2 VAR_RYU_AQUA, 124, MC_DoAquaGroudonScene
	.2byte 0

MtChimney_OnTransition: @ 822EDCC
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume: @ 822EDD2
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie:: @ 822EDD5
	lock
	faceplayer
	goto_if_set FLAG_RYU_PLAYER_HELPING_DEVON, MC_ArchieEnemyIntro
	goto_if_set FLAG_RYU_PLAYER_HELPING_AQUA, MC_ArchiIntro
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MC_ArchieEnemyIntro::
	msgbox MC_EnemyArchieSpeech MSGBOX_DEFAULT
	release
	end
	
MC_EnemyArchieSpeech:
	.string "Archie: Oh, great,\nnow you're here too.\pWhy don't you do something\nconstructive... like fighting off\lteam Magma...$"

MC_ArchiIntro::
	goto_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MC_ArchieOrders
	msgbox MC_ArchieIntroMsg MSGBOX_DEFAULT
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end
	
MC_ArchieOrders::
	msgbox ArchieOrdersMsg MSGBOX_DEFAULT
	release
	end

ArchieOrdersMsg:
	.string "Archie: {PLAYER}! You have your orders.\l"
	.string "Get IT Done!$"
	
MC_ArchieIntroMsg:
	.string "Archie: {PLAYER}! I'm glad you're here...\n"
	.string "Maxie is over there with that machine, \p"
	.string "trying to erupt the volcano.\p"
	.string "we Must stop him! Do whatever it takes!$"

MtChimney_EventScript_ArchieGoStopTeamMagma:: @ 822EDF9
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting:: @ 822EE02
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie:: @ 822EE0B
	lockall
	playbgm MUS_MGM0, 0
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject 2
	removeobject 29
	removeobject 3
	removeobject 22
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA 
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm 1, 10, 12
	addobject 1
	compare VAR_FACING, DIR_EAST
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto_if_set FLAG_RYU_PLAYER_HELPING_AQUA, MC_PlayerAqua
	goto MC_PlayerNotAqua

MC_PlayerNotAqua::
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 4
	call_if_eq MtChimney_EventScript_ArchieExitEast
	compare VAR_FACING, 2
	call_if_eq MtChimney_EventScript_ArchieExitNorth
	removeobject 1
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	goto MtChimney_EventScript_MeteoriteMachine
	releaseall
	end

MC_PlayerAqua::
	msgbox MC_NiceJobPlayer
	closemessage
	compare VAR_FACING, 4
	call_if_eq MtChimney_EventScript_ArchieExitEast
	compare VAR_FACING, 2
	call_if_eq MtChimney_EventScript_ArchieExitNorth
	removeobject 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MC_YouSeeStarPiece
	closemessage
	giveitem ITEM_STAR_PIECE, 1
	setvar VAR_RYU_AQUA, 81 @Player finished event at Mt. Chimney. Take star piece to jeweler or return to shelly.
	release
	end

MC_NiceJobPlayer:
	.string "Nice job, {PLAYER}!\p"
    .string "With your help, we managed to beat\n"
    .string "Team Magma.\p"
    .string "I must say, I'm quite impressed with\n"
    .string "you, scamp!\p"
    .string "Report back to Shelly.\n"
    .string "We're done here.$"

MC_YouSeeStarPiece:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You see the meteorite Team Magma\n"
    .string " was using in the machine.\p"
    .string " It's actually a very shiny white\n"
    .string " fragment of some sort.)\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}{PLAYER} pocketed the fragment.\p"
	.string "Perhaps something beautiful could\n"
	.string "be made out of this?\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You vaguely remember a jeweler at\n"
	.string " the department store.)$"

MtChimney_EventScript_ArchieApproachPlayerEast:: @ 822EEC7
	applymovement 1, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth:: @ 822EED2
	applymovement 1, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast:: @ 822EEDD
	applymovement 1, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth:: @ 822EEE8
	applymovement 1, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady:: @ 822EEF3
	lock
	faceplayer
	showmoneybox 0, 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	compare VAR_RESULT, FALSE
	goto_if_eq MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE, 1
	compare VAR_RESULT, TRUE
	call_if_eq MtChimney_EventScript_TakeMoney
	giveitem ITEM_LAVA_COOKIE
	compare VAR_RESULT, FALSE
	goto_if_eq MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull:: @ 822EF51
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_TakeMoney:: @ 822EF5E
	takemoney 200
	updatemoneybox 0, 0
	return

MtChimney_EventScript_DeclineLavaCookie:: @ 822EF69
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney:: @ 822EF76
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast: @ 822EF83
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast: @ 822EF8B
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth: @ 822EF94
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth: @ 822EF9C
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_EventScript_BusyAquaGrunt1:: @ 822F053
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2:: @ 822F05C
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3:: @ 822F065
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Courtney:: @ 822F06E
	trainerbattle_single TRAINER_COURTNEY_MT_CHIMNEY, MtChimney_Text_CourtneyIntro, MtChimney_Text_CourtneyDefeat
	msgbox MtChimney_Text_CourtneyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2:: @ 822F085
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1:: @ 822F09C
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2:: @ 822F0A5
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3:: @ 822F0AE
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4:: @ 822F0B7
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5:: @ 822F0C0
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6:: @ 822F0C9
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena:: @ 822F0D2
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena:: @ 822F0DB
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine:: @ 822F0E4
	lockall
	goto_if_set FLAG_RECEIVED_METEORITE, ryu_end
	goto_if_unset FLAG_RYU_PLAYER_HELPING_DEVON, MtChimney_EventScript_MachineOn
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	setvar VAR_RYU_DEVON, 22 @Player got the meteorite. Return to Cozmo.
	releaseall
	end

MtChimney_EventScript_MachineOn:: @ 822F137
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign:: @ 822F141
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby:: @ 822F14A
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby:: @ 822F176
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	@nop Trainer_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby:: @ 822F195
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa:: @ 822F1AC
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila:: @ 822F1C3
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley:: @ 822F1DA
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1:: @ 822F1F1
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer:: @ 822F208
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated:: @ 822F234
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerRematch:: @ 822F253
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano: @ 822F26A
	.string "The power contained in the Meteorite…\p"
	.string "By amplifying its power with this\n"
	.string "machine, MT. Chimney's volcanic\l"
	.string "activity will instantly intensify…\p"
	.string "Its energy will grow deep inside\n"
	.string "the crater and…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro: @ 822F32E
	.string "Maxie: Hm?\n"
	.string "Who are you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph! So you're thinking of\n"
	.string "interfering with us, Team Magma?\p"
	.string "Now you listen.\n"
	.string "Long ago, living things used the\l"
	.string "land to live and grow.\p"
	.string "That is why land is all important!\n"
	.string "It is the cradle of all!\p"
	.string "That is why Team Magma is dedicated\n"
	.string "to the expansion of the land mass.\p"
	.string "It is for further advancement of\n"
	.string "humankind and Pokémon!\p"
	.string "And for that, we need the power of\n"
	.string "what sleeps within this mountain…\p"
	.string "Oh! There was no need for you to\n"
	.string "learn that much.\p"
	.string "But, no matter!\n"
	.string "I'll teach you the consequences of\l"
	.string "meddling in our grand design!$"

MtChimney_Text_MaxieDefeat: @ 822F5CF
	.string "What?!\p"
	.string "I, Maxie, was caught off guard?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma: @ 822F5F7
	.string "Maxie: But, enough.\n"
	.string "I will back off this time.\p"
	.string "But don't think that this is the last\n"
	.string "you've seen of Team Magma.\p"
	.string "Fufufu…\p"
	.string "Even without the Meteorite, if we\n"
	.string "obtain that Orb… Fufufu…$"

MtChimney_Text_CourtneyIntro: @ 822F6AA
	.string "Courtney: Hehehe!\p"
	.string "So you've come all the way here!\p"
	.string "But it's too late!\n"
	.string "When we finish our work in Hoenn,\p"
	.string "I'll get to spend even more time with\n"
	.string "Maxie...$"

MtChimney_Text_CourtneyDefeat: @ 822F72C
	.string "No... NO... NO! This isn't how it's\p"
	.string "supposed to be! I wanted to\n"
	.string "impress Maxie!$"

MtChimney_Text_CourtneyPostBattle: @ 822F76D
	.string "Maxie.... I'm sorry I've failed you.\n"
	.string "I hope you had enough time...\p"
	.string "…$"

MtChimney_Text_Grunt2Intro: @ 822F7A2
	.string "We of Team Magma are working hard for\n"
	.string "everyone's sake.\p"
	.string "Like, if that thing's power made more\n"
	.string "land, there'd be more places to live.\p"
	.string "Everyone'd be happy!$"

MtChimney_Text_Grunt2Defeat: @ 822F83A
	.string "Hunh?\n"
	.string "What do you mean I lost?$"

MtChimney_Text_Grunt2PostBattle: @ 822F859
	.string "Our boss says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"

MtChimney_Text_Grunt1Intro: @ 822F8B6
	.string "If there were more land, I'd be able\n"
	.string "to get a big house of my own!\p"
	.string "I'm going to build it on hardened lava!$"

MtChimney_Text_Grunt1Defeat: @ 822F921
	.string "My dream of a big house…$"

MtChimney_Text_Grunt1PostBattle: @ 822F93A
	.string "A kid like you, you ought to be\n"
	.string "splashing about in the waves!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans: @ 822F978
	.string "That annoying Team Aqua…\n"
	.string "They always mess with our plans!$"

MtChimney_Text_MeteoritesPackAmazingPower: @ 822F9B2
	.string "Meteorites pack amazing power!$"

MtChimney_Text_YouBetterNotMessWithUs: @ 822F9D1
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"

MtChimney_Text_AquasNameSimilar: @ 822FA2F
	.string "We're Team Magma!\p"
	.string "They're Team Aqua!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"

MtChimney_Text_DouseThemInFire: @ 822FA8B
	.string "Yeah!\n"
	.string "Douse them in fire!$"

MtChimney_Text_KeepMakingMoreLand: @ 822FAA5
	.string "We're going to keep making more land!$"

MtChimney_Text_Bufoh: @ 822FACB
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma: @ 822FAD2
	.string "Archie: Grr, {PLAYER}!\n"
	.string "I should've guessed you'd show up!\p"
	.string "See for yourself what the fanatics\n"
	.string "of Team Magma are up to!\p"
	.string "They're trying to inject the stolen\n"
	.string "Meteorite's power into the volcano!\p"
	.string "Doing something like that will cause\n"
	.string "the volcano's eruption!$"

MtChimney_Text_ArchieIHaveMyHandsFull: @ 822FBC7
	.string "Archie: Grrr…\p"
	.string "I want to stop that Maxie,\n"
	.string "but I can't!\p"
	.string "Not when I have my hands full battling\n"
	.string "three opponents at once!$"

MtChimney_Text_ArchieThankYou: @ 822FC3D
	.string "Archie: {PLAYER}!\n"
	.string "Thank you!\p"
	.string "With your help, we thwarted Team\n"
	.string "Magma's destructive plan!\p"
	.string "But… You…\n"
	.string "Whose side are you on?\p"
	.string "Ah, it doesn't matter.\p"
	.string "We will remain vigilant and keep up\n"
	.string "our pursuit of Team Magma.\p"
	.string "{PLAYER}, we shall meet again!$"

MtChimney_Text_MagmaOutnumbersUs: @ 822FD1F
	.string "Darn… Team Magma outnumbers us!\n"
	.string "We can't keep up with them!$"

MtChimney_Text_LessHabitatForWaterPokemon: @ 822FD5B
	.string "If they expand the land, there'll be\n"
	.string "less habitats for Water Pokémon!$"

MtChimney_Text_MagmasNameSimilar: @ 822FDA1
	.string "We're Team Aqua!\p"
	.string "They're Team Magma!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"

MtChimney_Text_Bushaa: @ 822FDFC
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200: @ 822FE04
	.string "Lava Cookies are MT. Chimney's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"

MtChimney_Text_ThankYouDear: @ 822FE4D
	.string "Thank you, dear!$"

MtChimney_Text_YouveNotGotTheMoney: @ 822FE5E
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"

MtChimney_Text_OhFineThen: @ 822FE9B
	.string "Oh, fine then.$"

MtChimney_Text_MetoriteFittedOnMachine: @ 822FEAA
	.string "A Meteorite is fitted on a mysterious\n"
	.string "machine…\p"
	.string "The machine seems to be storing\n"
	.string "energy in the Meteorite.$"

MtChimney_Text_RemoveTheMeteorite: @ 822FF12
	.string "A Meteorite is fitted on a mysterious\n"
	.string "machine…\p"
	.string "Do you want to remove the Meteorite?$"

MtChimney_Text_PlayerRemovedMeteorite: @ 822FF66
	.string "{PLAYER} removed the METEORITE from\n"
	.string "the mysterious machine.$"

MtChimney_Text_PlayerLeftMeteorite: @ 822FF9C
	.string "{PLAYER} left the METEORITE where\n"
	.string "it was.$"

MtChimney_Text_MachineMakesNoResponse: @ 822FFC0
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"

MtChimney_Text_RouteSign: @ 822FFFA
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "Lavaridge Town Ahead$"

MtChimney_Text_ShelbyIntro: @ 823001D
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"

MtChimney_Text_ShelbyDefeat: @ 8230076
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostBattle: @ 82300A2
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an Expert now, can I?$"

MtChimney_Text_ShelbyRegister: @ 82300E3
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"

MtChimney_Text_ShelbyRematchIntro: @ 8230153
	.string "If you can mesh your heart with those\n"
	.string "of your Pokémon, why, you should be\l"
	.string "able to achieve great things.$"

MtChimney_Text_ShelbyRematchDefeat: @ 82301BB
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostRematch: @ 82301E7
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your Pokémon.$"

MtChimney_Text_MelissaIntro: @ 823022A
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"

MtChimney_Text_MelissaDefeat: @ 823026D
	.string "Ooh, that was a scorching-hot match!$"

MtChimney_Text_MelissaPostBattle: @ 8230292
	.string "The heat of MT. Chimney warms\n"
	.string "me up, baby!$"

MtChimney_Text_SheilaIntro: @ 82302BD
	.string "I've finally made it to MT. Chimney.\n"
	.string "I want to make my Pokémon battle!$"

MtChimney_Text_SheilaDefeat: @ 8230304
	.string "The way you battle…\n"
	.string "It's like a MT. Chimney eruption!$"

MtChimney_Text_SheilaPostBattle: @ 823033A
	.string "Like I said, I've finally made it to\n"
	.string "MT. Chimney. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "Cookies as souvenirs.$"

MtChimney_Text_ShirleyIntro: @ 82303DF
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"

MtChimney_Text_ShirleyDefeat: @ 8230436
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"

MtChimney_Text_ShirleyPostBattle: @ 8230463
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"

MtChimney_Text_SawyerIntro: @ 82304B3
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"

MtChimney_Text_SawyerDefeat: @ 82304F7
	.string "Oh, you're a real firebrand, too!$"

MtChimney_Text_SawyerPostBattle: @ 8230519
	.string "I think I need a dip in Lavaridge\n"
	.string "Hot Spring with the locals!$"

MtChimney_Text_SawyerRegister: @ 8230557
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my Pokénav.$"

MtChimney_Text_SawyerRematchIntro: @ 823059C
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"

MtChimney_Text_SawyerRematchDefeat: @ 82305E3
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"

MtChimney_Text_SawyerPostRematch: @ 8230614
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"


@==================================================================================================
MC_DoAquaGroudonScene::
	setvar VAR_RYU_AQUA, 128 @player is watching scene in mtchimney
	applymovement 32, Common_Movement_FaceRight
	waitmovement 32
	delay 20
	applymovement 32, Common_Movement_FaceLeft
	waitmovement 32
	delay 20
	applymovement 32, Common_Movement_FaceUp
	waitmovement 32
	delay 20
	setweather WEATHER_DROUGHT
	doweather
	playmoncry SPECIES_GROUDON, 0
	waitmoncry
	delay 60
	warpsilent MAP_MOSSDEEP_CITY, 255, 46, 8
	waitstate


