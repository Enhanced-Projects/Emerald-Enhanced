LilycoveCity_AquaCorporateOffice_MapScripts::
	map_script ON_FRAME, ACO_OnFrameScript
	.byte 0
	
ACO_OnFrameScript::
	map_script_2 VAR_RYU_AQUA, 45, ACO_ReturnedFromMuseumWhiteout
	map_script_2 VAR_RYU_AQUA, 162, ACO_Night2Scene
	.2byte 0


ACO_EntranceScriptTrigger::
	switch VAR_RYU_AQUA
	case 5, ACO_StartAquaQuest
	case 10, ryu_end
	case 157, ACO_DoAquaOutro
	compare VAR_RYU_AQUA, 105
	goto_if_eq ACO_PlayerShellyReturnFromJaggedPass
	compare VAR_RYU_AQUA, 55
	goto_if_ge ryu_end	
	goto ACO_BlockEntry
	
ACO_PlayerShellyReturnFromJaggedPass:
	lockall
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	msgbox ACO_WereBack
	closemessage
	applymovement OBJ_EVENT_ID_FOLLOWER, ACO_ShellyFromplayerToDesk
	waitmovement OBJ_EVENT_ID_FOLLOWER
	setvar VAR_RYU_AQUA, 107 @Player returned to the aqua office from jagged pass. Player should see shelly for rewards.
	call RF_FollowerLeaveCall
	release
	end

ACO_Shelly::
	compare VAR_RYU_AQUA, 72
	goto_if_lt ryu_end
	switch VAR_RYU_AQUA
	case 80, ACO_AquaStage3_Waitforcall
	case 81, ACO_AquaStage3_Waitforcall
	case 85, ACO_PlayerReturnedFromChimneyWithNecklace
	case 91, ACO_PlayerWaitingForCallRomance
	case 107, ACO_ShellyAfterJaggedPassRomanceEvent
	case 111, ACO_PlayerShouldGoToShipyard
	case 161, ACO_ShellyAfterStory
	lockall
	msgbox ACO_SoHowDid
	closemessage
	delay 20
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox ACO_OhHeresYourPayment
	setvar VAR_TEMP_9, 10000
	addmoney VAR_TEMP_9
	closemessage
	msgbox ACO_AquaStage3_WaitForCallMsg
	closemessage
	setvar VAR_RYU_AQUA, 80 @returned from meteor falls. Player needs to get 6 badges to continue.
	release
	end

ACO_ShellyAfterJaggedPassRomanceEvent::
	setflag FLAG_RYU_DS_SHELLY_CLOSEFRIENDS
	setvar VAR_RYU_AQUA, 109 @player talked to shelly after returning from jagged pass
	msgbox ACO_ThatWasAClose
	closemessage
	applymovement 1, ACO_ShellyWalkAroundDesk 
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ACO_PlayerAchievedQuartermaster
	playfanfare MUS_FANFA4
	waitfanfare
	closemessage
	delay 30
	msgbox ACO_YouNoticeShelly
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	playse SE_PIN
	applymovement 1, Common_Movement_HeartEmote
	waitmovement 1
	delay 20
	applymovement 1, Common_Movement_StepLeft
	waitmovement 1
	turnobject 1, DIR_WEST
	msgbox ACO_ThatsToCongrat
	closemessage
	applymovement 1, ACO_ShellyBackBehindDesk @2 up, 2 left, face down
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox ACO_NowTheresSomething
	closemessage
	setvar VAR_RYU_AQUA, 111 @player should head to slateport shipyard to fight the enemies there.
	clearflag FLAG_RYU_HIDE_SHIPYARD_DEVON_EMPLOYEES
	warpsilent MAP_LILYCOVE_CITY, 255, 48, 9
	waitstate

ACO_PlayerShouldGoToShipyard:
	msgbox ACO_PlayerGoToShipyardMsg
	closemessage
	release
	end

ACO_PlayerWaitingForCallRomance:
	msgbox ACO_AquaStage3_WaitForCallMsg
	release
	end

ACO_PlayerReturnedFromChimneyWithNecklace:: @Romance line is much longer than non-romance line
	setvar VAR_RYU_AQUA, 87 @Player is giving necklace to Shelly. 
	msgbox ACO_SoHowDid
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	msgbox ACO_LostInThought
	setflag FLAG_RYU_DS_SHELLY_FRIENDS
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	msgbox ACO_HmmWhatsThis
	closemessage
	delay 30
	msgbox ACO_ShellyGiggles
	closemessage
	delay 30
	msgbox ACO_ToBeFrank
	closemessage
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox ACO_OhHeresYourPayment2
	setvar VAR_TEMP_B, 10000
	addmoney VAR_TEMP_B
	setvar VAR_RYU_AQUA, 91 @Player is doing romance line, wait for 6 badges.
	release
	end
	
ACO_AquaStage3_Waitforcall:
	msgbox ACO_AquaStage3_WaitForCallMsg
	release
	end

ACO_StartAquaQuest::
	msgbox ACO_WelcomeToAqueus
	closemessage
	applymovement 7, ACO_GuardToShelly @up 6, right 2
	waitmovement 7
	delay 20
	applymovement 7, ACO_GuardReturnToPost @left 2, down 6
	waitmovement 7
	addobject 10
	applymovement 10, ACO_ShellyToEntrance @ down 2 left 1, down 4
	waitmovement 10
	msgbox ACO_GreetingsStranger
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ACO_YouActAsIf
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	msgbox ACO_ForSomeoneTo
	closemessage
	msgbox ACO_ISimplyWish
	closemessage
	msgbox ACO_IsThatSo
	closemessage
	trainerbattle_single TRAINER_SHELLY_1, ACO_TryToBestMe, ACO_ShellyDefeated1, ACO_AfterShellyBattle, MUS_ENCOUNTER_AQUA
	waitstate
	
ACO_AfterShellyBattle::
	msgbox ACO_HavePotential
	setvar VAR_TEMP_3, 50000
	addmoney VAR_TEMP_3
	call RyuGivePokenav
	playfanfare MUS_FANFA5
	waitfanfare
	msgbox ACO_AWorkerShouldNot
	closemessage
	applymovement 10 ACO_ShellyExit1 @ up 3, disappear
	removeobject 10
	setvar VAR_RYU_AQUA, 10
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	release
	end

ACO_BlockEntry::
	lockall
	msgbox ACO_CantBeHere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
ACO_ReturnedFromMuseumWhiteout:
	special HealPlayerParty
	setvar VAR_RYU_AQUA, 50 @Player wakes up in shelly's quarters
	playse SE_DOOR
	waitse
	addobject 9
	applymovement 9, ACO_ShellyToPlayer2
	waitmovement 9
	msgbox ACO_HowYouFeeling
	closemessage
	msgbox ACO_EhAlright
	closemessage
	msgbox ACO_WhatWereYou
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ACO_ButTheMission
	closemessage
	msgbox ACO_YesTheMission
	closemessage
	delay 30
	msgbox ACO_NowThen
	closemessage
	applymovement 9, Common_Movement_StepLeft
	waitmovement 9
	applymovement 9, Common_Movement_StepLeft
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ACO_SoDoesThat
	closemessage
	applymovement 9, Common_Movement_FaceRight
	waitmovement 9
	msgbox ACO_PlayerHasAchieved
	closemessage
	applymovement 9, Common_Movement_StepLeft
	waitmovement 9
	applymovement 9, Common_Movement_FaceUp
	waitmovement 9
	msgbox ACO_BoatswainIs
	closemessage
	msgbox ACO_BetterThanBeing
	closemessage
	setvar VAR_RYU_AQUA, 55@Player finished scene in shelly's quarters and needs to get 5 badges.
	applymovement 9, ACO_ShellyLeavesRoom1
	waitmovement 9
	playse SE_DOOR
	removeobject 9
	applymovement OBJ_EVENT_ID_PLAYER, OM_PlayerExitShellyRoom @maybe reusable later
	waitmovement  OBJ_EVENT_ID_PLAYER
	playse SE_DOOR
	waitse
	warpsilent MAP_LILYCOVE_CITY_AQUA_CORPORATE_OFFICE, 255, 5, 4
	waitstate

ACO_DoAquaOutro::
	lockall
	call_if_set FLAG_RYU_DS_HAS_PARTNER, RF_FollowerLeaveCall
	msgbox ACO_OneMomentPlease
	closemessage
	setflag FLAG_HIDE_AQUAHQ_SHELLY
	addobject 11
	applymovement 11, ACO_GentlemanExit
	waitmovement 11
	playse SE_DOOR
	waitse
	removeobject 11
	addobject 10
	applymovement 10, ACO_ShellyToEntrance
	waitmovement 10
	applymovement 10, Common_Movement_StepDown
	waitmovement 10
	msgbox ACO_PlayerPleaseComeIn
	closemessage
	applymovement 10, ACO_Outro_FromEntranceToBedroom
	applymovement OBJ_EVENT_ID_PLAYER, ACO_Outro_FromEntranceToBedroom2
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOOR
	waitse
	removeobject 10
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, ACO_PlayerFromBehindDeskToBedroom
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject 9
	applymovement 9, Common_Movement_StepDown
	waitmovement 9
	fadescreen FADE_FROM_BLACK
	applymovement 9, ACO_ShellyFromBedroomDoorToCouch
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER, ACO_PlayerFromBedroomDoorToShelly
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ACO_WhoWasThat
	closemessage
	fadenewbgm 456
	playse SE_PIN
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ACO_OhWell
	closemessage
	delay 30
	msgbox ACO_WellOfCourse
	closemessage
	applymovement 9 ACO_PlayerSlideUp
	waitmovement 9
	playse SE_W204
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 9, Common_Movement_StepDown
	waitmovement 9
	applymovement 9, Common_Movement_FaceUp
	waitmovement 9
	goto ACO_ShellyNightScene
	
ACO_ShellyNightScene::
	applymovement 9, Common_Movement_StepRight
	waitmovement 9
	applymovement 9, Common_Movement_StepUp
	waitmovement 9
	applymovement 9, Common_Movement_FaceLeft
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ACO_QuartersScene MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	fadeoutbgm 2
	msgbox ACO_QuartersScene2 MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_CAMERA, ACO_CameraPan
	applymovement 9, ACO_ShellySlide
	waitmovement 9
	msgbox ACO_CONCLUSION MSGBOX_AUTOCLOSE
	fadescreenspeed 1, 10
	msgbox ACO_CONCLUSION2 MSGBOX_DEFAULT
	closemessage
	delay 40
	removeobject 9
	applymovement OBJ_EVENT_ID_CAMERA, ACO_CameraPan2
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	msgbox ACO_TRANSITION MSGBOX_DEFAULT
	fadescreenspeed 0, 10
	playbgm MUS_HIGHTOWN, 0
	clearflag FLAG_HIDE_AQUAHQ_SHELLY
	setflag FLAG_RYU_DS_SHELLY_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	setflag FLAG_RYU_AQUA_LINE_DONE
	setvar VAR_RYU_AQUA, 161 @Aqua line finished.
	special DrawWholeMapView
	releaseall
	end

ACO_ShellyAfterStory::
	lockall
	msgbox ACO_ShellyAfterstoryIntro
	closemessage
	msgbox ACO_ShellyStayTheNightQuery, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ACO_CheckFollowerShelly
	
	call_if_set FLAG_RYU_HAS_FOLLOWER, RF_FollowerLeaveCall
	setvar VAR_RYU_AQUA, 162
	warpsilent MAP_LILYCOVE_CITY_AQUA_CORPORATE_OFFICE, 255, 30, 2 
	waitstate

ACO_CheckFollowerShelly::
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, ryu_end
	msgbox ACO_ShellyFollowerQuery, MSGBOX_YESNO
	compare VAR_RESULT, YES
	msgbox ACO_LetsGo
	closemessage
	goto_if_eq FollowerShellySetup
	goto ryu_end

ACO_Night2Scene::
	setvar VAR_RYU_AQUA, 161
	addobject 9
	applymovement 9, ACO_Night_ShellyToCouch
	waitmovement 9
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	special SpawnCameraObject
	fadeoutbgm 2
	msgbox ACO_ShellyNight2Msg1
	closemessage
	msgbox ACO_ShellySlides
	applymovement OBJ_EVENT_ID_CAMERA, ACO_CameraPan
	closemessage
	applymovement 9, ACO_ShellySlide
	waitmovement 9
	fadescreenspeed 1, 10
	msgbox ACO_ShellyNight2Msg2
	closemessage
	delay 60
	msgbox ACO_NightScene2Wakeup
	closemessage
	delay 40
	removeobject 9
	applymovement OBJ_EVENT_ID_CAMERA, ACO_CameraPan2
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	fadescreenspeed 0, 10
	playbgm MUS_HIGHTOWN, 0
	release
	end

ACO_ShellyFollowerQuery:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I'm free if you want to hang\nout for a while.\pCan I come with you?$"

ACO_ShellyAfterstoryIntro:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Well I have Aqua's affairs in order.\nShould be smooth sailing from here!$"

ACO_ShellyStayTheNightQuery:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Did you come to stay the night?\nI could use the stress relief.$"

ACO_LetsGo:
	.string "{COLOR LIGHT_RED}{SHADOW RED}The Admins will take care of\nbusiness while I'm away.\pI'm ready to go when you are!$"

ACO_ShellyNight2Msg1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}So, my hero, are you here to\nsweep me off my feet?\pLet's find out if you can\nkeep up... eheheh.$"

ACO_ShellySlides:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (Shelly slides over to {PLAYER}...)$"

ACO_ShellyNight2Msg2:
	.string  "{COLOR LIGHT_GREEN}{SHADOW GREEN} ({PLAYER} and Shelly spend a blissful\n night in each other's arms...)$"

ACO_NightScene2Wakeup:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (As you wake up, Shelly is\n already gone.\p Probably attending business dealings.\p The briny air empowers you\n as you come to.)$"


ACO_Night_ShellyToCouch:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_left
	step_end

	
ACO_OneMomentPlease:
	.string "One moment, please.\n"
    .string "The Manager will be ready for you\p"
    .string "shortly.$"

ACO_PlayerPleaseComeIn:
	.string "{PLAYER}, please come in.$"
	
ACO_WhoWasThat:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Who was that?\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}No one special.\p"
    .string "Just going through the initial stages\n"
    .string "on conducting legitimate business.\p"
    .string "I've been tasked with spearheading\n"
    .string "the operation.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}What about Archie and Matt?\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}They're cooperating with authorities\n"
    .string "and pled guilty to all charges.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I see...so that means you're in\n"
    .string "charge.\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Did you forget?\n"
    .string "You're an Admin too.$"

ACO_OhWell:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh, well...\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}You thought you were really kicked\n"
    .string "out of Team Aqua?\p"
    .string "How gullible of you.\p"
    .string "I, for one, am not letting you go\n"
    .string "that easily after you stole my heart.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}So you admit you love me.$"
	
ACO_WellOfCourse:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Well of course I do, isn't that\n"
    .string "obvious?\p"
    .string "Seriously, you can be so dense...$"
	
ACO_TRANSITION:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You awaken to a few voices\n"
	.string " chattering in the main room.\p"
	.string " There's a nice breeze coming\n"
	.string " through the window, and you don't\l"
	.string " want to get up.)$"

ACO_ShellySlide:
	walk_slow_left
	step_end

ACO_GentlemanExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
ACO_Outro_FromEntranceToBedroom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

ACO_Outro_FromEntranceToBedroom2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

ACO_PlayerFromBehindDeskToBedroom: @could have done a map script here, but at this point, i just cant be bothered
	walk_up
	walk_up
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end
	
ACO_ShellyFromBedroomDoorToCouch:
	walk_down
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	face_up
	step_end

ACO_PlayerFromBedroomDoorToShelly:
	walk_right
	walk_right
	walk_up
	walk_right
	face_down
	step_end

ACO_PlayerSlideUp:
	slide_up
	step_end

ACO_QuartersScene:
	.string "{COLOR LIGHT_RED}{SHADOW RED}You know, before I met you\n"
	.string "I failed to see any of the signs\p"
	.string "that Archie was only thinking about\l"
	.string "himself.\p"
	.string "Ever since you started coming around\n"
	.string "I started to see the difference\l"
	.string "between good and evil.\p"
	.string "I'm so glad we're together.$"

ACO_QuartersScene2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Speaking of which...\p{COLOR LIGHT_GREEN}{SHADOW GREEN}(Shelly slides over and\n leans against your chest...)$"
	
ACO_CONCLUSION:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and Shelly snuggle\n closely and cover up.)$"
	
ACO_CONCLUSION2:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and Shelly fall into a\n"
	.string " peaceful sleep as the humid ocean\p"
	.string " air slightly jostles the curtains\n"
	.string " in the window.$"
	
ACO_HowYouFeeling:
	.string "How're you feeling?$"
	
ACO_EhAlright:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Eh, alright...could've been worse.$"
	
ACO_WhatWereYou:
	.string "What were you thinking, going up\n"
    .string "against a former Champion like that?\p"
    .string "Are you really that reckless?$"

ACO_ButTheMission:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}But, the mission was...$"
	
ACO_YesTheMission:
	.string "Yes, the mission is important, but so\n"
    .string "are our lives.\p"
    .string "That's the difference between us and\n"
    .string "Magma.\p"
    .string "We take care of our own.$"

ACO_NowThen:
	.string "Now then, the mission ended in\n"
    .string "shipwreck...\p"
	.string "But now we know that Devon is\n"
    .string "keeping close contact with Stern.\p"
    .string "We'll have to keep an eye on their\n"
    .string "progress.\p"
    .string "In the meantime, you should work on\n"
    .string "getting your team stronger.\p"
    .string "The tasks will only become more\n"
    .string "difficult as time goes on.$"

ACO_SoDoesThat:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}So...does that mean I'm in?$"

ACO_PlayerHasAchieved:
	.string " {PLAYER} has achieved the rank of\n"
    .string " Boatswain!$"

ACO_BoatswainIs:
	.string "Boatswain is just a fancy term for\n"
    .string "Junior Officer.\p"
    .string "Don't think too highly of it.$"
	
ACO_BetterThanBeing:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Better than being a Powder Monkey.$"
	
ACO_HahaTrue:
    .string "Heh, true!\p"
    .string "Anyways, you're dismissed.\n"
    .string "Expect new orders soon.$"

ACO_CantBeHere:
	.string "You can't be here, You don't\nhave clearance.$"

ACO_WelcomeToAqueus:
	.string "Welcome to Aqueus Corporation.\n"
    .string "What brings you here?\p"
    .string "... ... ...\n"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} shows the package.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}One moment, please.\l"
    .string "Let me get the Manager.$"

ACO_GreetingsStranger:
	.string "Greetings, stranger. I'm Shelly,\n"
    .string "co-owner of Aqueus Corp.\p"
    .string "I've been informed that you possess\n"
    .string "the LIDAR tech we've been seeking.\p"
    .string "Pray tell, where did you get that?\n"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ... ...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}I see...figures.\p"
    .string "The members of our crew can be such\n"
    .string "powder monkeys sometimes.\p"
    .string "Why bring it here, though?\p"
    .string "Nothing comes for free, so what do\n"
    .string "you really want?$"

ACO_YouActAsIf:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}You act as if I have some ulterior\n"
    .string "motive...$"

ACO_ForSomeoneTo:
	.string "For someone to waltz into our\n"
    .string "facility with an item that was\p"
    .string "already in our possession, you can't\n"
    .string "help but wonder...$"

ACO_ISimplyWish:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I simply wish to join Team Aqua.\n"
    .string "This way seemed like the best\l"
    .string "opportunity to do so.$"

ACO_IsThatSo:
	.string "Hunh...is that so?\p"
    .string "Well, to be perfectly frank, I still\p"
    .string "have my suspicions.\n"
    .string "Allow me to put you to a little test.$"

ACO_TryToBestMe:
	.string "Try to best me in battle.$"

ACO_ShellyDefeated1:
	.string "Hm, not bad.$"

ACO_HavePotential:
	.string "You certainly have potential.\p"
    .string "{PLAYER}, was it?\p"
    .string "Take these.\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} received ¥50,000.\n"
    .string "{PLAYER} received the Aqua Pendant.$"
	
ACO_AWorkerShouldNot:
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}A worker should not go without their\n"
    .string "wages...it's a little something for\l"
    .string "delivering the package.\p"
    .string "The money is a sign-on bonus.\n"
    .string "We'll keep you on as a retainer for\p"
    .string "now.\n"
    .string "You may leave.\p"
    .string "We'll contact you when there's a job.$"
	
ACO_WereBack:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Ah Finally, air conditioning.\pIt was way too hot there!\nSee me at my desk.$"

ACO_LostInThought:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (She seems lost in thought...\n You take this opportunity\l to give her the necklace.)$"

ACO_HmmWhatsThis:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hm...? What's this?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}It's something I got made for you.\n"
    .string "Thought it'd look best on a beauty\l"
    .string "such as yourself...$"

ACO_ShellyGiggles:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Shelly giggles.)\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}I knew you were bold, but not this\n"
    .string "bold...I underestimated you!$"

ACO_ToBeFrank:
	.string "{COLOR LIGHT_RED}{SHADOW RED}To be frank, I've noticed quite a few\n"
    .string "of the crew have been eyeing me for\p"
    .string "a while, and yet none of them had the\n"
    .string "guts to step up...until now, that is.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}So...?\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'll think about it.\p"
    .string "I really appreciate the thoughtful\n"
    .string "gift.$"

ACO_OhHeresYourPayment2:
	.string "Oh, here's your payment.\n"
    .string "Keep up the good work.\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} received ¥10,000.\n"
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'll call you when there's more work.$"

ACO_OhHeresYourPayment:
	.string "Oh, here's your payment.\n"
    .string "Keep up the good work.\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} received ¥10,000.$"

ACO_SoHowDid:
	.string "So, how did things go?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ... ...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}I see...well, in any case, it seems\n"
    .string "we stopped Magma just in time.\p"
    .string "Although, their true goal is yet to\n"
    .string "be known...$"

ACO_AquaStage3_WaitForCallMsg:
	.string "I'll call you when there's\nmore work to do.$"
	
ACO_ThatWasAClose:
	.string "{COLOR LIGHT_RED}{SHADOW RED}That was a close one.\p"
    .string "We barely averted the disaster that\n"
    .string "would've been if Groudon had been\l"
    .string "awakened...and yet...\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Is something wrong?\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}It's nothing, don't worry about it.\p"
    .string "Come to think of it, I believe you\n"
    .string "deserve a promotion.$"

ACO_PlayerAchievedQuartermaster:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} has risen to Quartermaster!\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Again, another fancy term, but for an\n"
    .string "Admin.\p"
    .string "That's right, now we're equals, so\n"
    .string "congratulations, you've earned it.$"
	
ACO_YouNoticeShelly:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You notice that Shelly is wearing\n"
    .string " the necklace you gave her.)\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I was right...it really suits you.\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Ah, so you noticed...well then...$"

ACO_ThatsToCongrat:
	.string "{COLOR LIGHT_RED}{SHADOW RED}That's to congratulate you on your\n"
    .string "promotion.\p"
    .string "Don't expect anything else!$"

ACO_NowTheresSomething:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Now, there's something I need to\n"
    .string "verify.\p"
    .string "In the meantime, I need you to head\n"
    .string "over to Stern's Shipyard in Slateport\p"
    .string "to retrieve files about the submarine\n"
    .string "we've taken off their hands.\p"
    .string "Be careful, though.\p"
    .string "At this point, it must be crawling\n"
    .string "with law enforcement.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Got it, see you soon.$"

ACO_PlayerGoToShipyardMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}You should be heading to the\nshipyard in Slateport.$"
	
ACO_CameraPan:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end
	
ACO_CameraPan2:	
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end
	
ACO_ShellyBackBehindDesk:
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_down
	step_end

ACO_ShellyWalkAroundDesk:
	walk_right
	walk_right
	walk_down
	walk_down
	face_left
	step_end


ACO_ShellyFromplayerToDesk:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
ACO_ShellyToPlayer2:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end
	
ACO_ShellyLeavesRoom1:
	walk_up
	walk_up
	walk_up
	step_end
	
ACO_GuardToShelly:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end
	
ACO_GuardReturnToPost:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
	
ACO_ShellyToEntrance: @ down 2 left 1, down 4
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
ACO_ShellyExit1:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
OM_PlayerExitShellyRoom:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end




