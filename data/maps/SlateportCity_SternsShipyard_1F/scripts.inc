SlateportCity_SternsShipyard_1F_MapScripts:: @ 8207F3F
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock:: @ 8207F40
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady:: @ 8207F92
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined:: @ 8207FA6
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern:: @ 8207FBA
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran:: @ 8207FD9
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1:: @ 8207FED
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2:: @ 8207FF6
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney:: @ 8207FFF
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails: @ 8208008
	.string "Umm… If this goes here, and that\n"
	.string "goes over there…\p"
	.string "Then where does this thing go?\n"
	.string "And what about that doohickey?\p"
	.string "Aaargh! I can't make heads or tails\n"
	.string "of this!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern: @ 82080A5
	.string "Hm?\n"
	.string "Hi, I'm Dock.\p"
	.string "Capt. Stern commissioned me to\n"
	.string "design a ferry.\p"
	.string "Oh! That there…\n"
	.string "Are they Devon Goods?\p"
	.string "But, hmm…\n"
	.string "This won't do…\p"
	.string "Capt. Stern went off somewhere.\n"
	.string "He said he had some work to do.\p"
	.string "Could I get you to go find Capt.\n"
	.string "Stern and deliver that to him?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern: @ 82081A5
	.string "Dock: Where could Capt. Stern have\n"
	.string "gone off to?\p"
	.string "Could you go find Capt. Stern and\n"
	.string "deliver that parcel to him?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran: @ 8208213
	.string "Dock: Shipbuilding is an art.\p"
	.string "A lot of things can't be figured out\n"
	.string "just by calculating.\p"
	.string "I really could use advice from a veteran\n"
	.string "who knows the seas…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs: @ 82082A8
	.string "Dock: Hi! MR. Briney's joined us to\n"
	.string "lend us his help.\p"
	.string "Thanks to the veteran sailor, the\n"
	.string "ferry is steadily coming together.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady: @ 8208323
	.string "Dock: The ferry is finally ready!\p"
	.string "The new S.S. Tidal is truly a marvel\n"
	.string "of technology!\p"
	.string "But, I get the feeling that we can\n"
	.string "make something even better.\p"
	.string "You know, there's never an end to\n"
	.string "technology's march.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock: @ 82083EE
	.string "MR. Briney: Ah, {PLAYER}!\n"
	.string "It's been too long!\p"
	.string "Aye, since I met you, this old sea dog's\n"
	.string "been feeling frisky!\p"
	.string "So I've decided to help Dock make\n"
	.string "a ferry.\p"
	.string "Aye, after all, a ferry would be able\n"
	.string "to carry a lot of people.\p"
	.string "But, you know, that Dock is really\n"
	.string "something special.\p"
	.string "With his knack for technology and\n"
	.string "my experience, I'm sure that we can\l"
	.string "build one great ship, aye!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing: @ 8208558
	.string "The seasons, the weather, where\n"
	.string "the moon sits in the sky…\p"
	.string "These and other conditions make\n"
	.string "the sea change its expression.\p"
	.string "That's right!\n"
	.string "The sea is like a living thing!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily: @ 82085FF
	.string "I get seasick real easily.\n"
	.string "So I get to help out here instead.$"

@=========================================aqua events

SS_DevonEmployee1::
	trainerbattle_single TRAINER_DEVON_ENFORCER_1 SS_Devon1Intro, SS_Devon1Defeat
	msgbox SS_Devon1Msg
	end

SS_DevonEmployee2::
	trainerbattle_single TRAINER_DEVON_ENFORCER_1 SS_Devon2Intro, SS_Devon2Defeat @these need changed to their respective numbers
	msgbox SS_Devon2Msg
	end

SS_DevonEmployee3::
	trainerbattle_single TRAINER_DEVON_ENFORCER_1 SS_Devon3Intro, SS_Devon3Defeat
	msgbox SS_Devon3Msg
	end

SS_DevonEmployee4::
	trainerbattle_single TRAINER_DEVON_ENFORCER_1 SS_Devon4Intro, SS_Devon4Defeat
	msgbox SS_Devon4Msg
	end

SS_DevonEmployee5::
	trainerbattle_single TRAINER_DEVON_ENFORCER_1 SS_Devon5Intro, SS_Devon5Defeat
	msgbox SS_Devon5Msg
	end

SS_Devon1Intro:
	.string "I knew a criminal would\nfind its way in here.$"

SS_Devon1Defeat:
	.string "When did criminals get so strong?$"

SS_Devon1Msg:
	.string "You're still a criminal.$"


SS_Devon2Intro:	
	.string "I could use a vacation.\nOh well, you should make for\la good diversion.$"

SS_Devon2Defeat:
	.string "I don't get paid enough\nfor this.$"

SS_Devon2Msg:
	.string "I'm still waiting to get\nmore vacation days...$"


SS_Devon3Intro:
	.string "If I can stop you, I'll\nget a big fat bonus.\pThat bonus is as good as mine!$"

SS_Devon3Defeat:
	.string "No! My bonus! Curse you!$"

SS_Devon3Msg:
	.string "What am I going to do for\nmy son's birthday now?$"


SS_Devon4Intro:
	.string "Stop right there, criminal scum!$"

SS_Devon4Defeat:
	.string "I may have lost, but there\nare always more enforcers.$"

SS_Devon4Msg:
	.string "I made sure the others knew\nthat you were here!$"


SS_Devon5Intro:
	.string "Devon was employed to provide\nsecurity for Stern.\pThat means end of the line\nfor you!$"

SS_Devon5Defeat:
	.string "Good thing there's more of us!$"

SS_Devon5Msg:
	.string "We'll definitely stop you\neventually!$"

