LilycoveCity_AquaCorporateOffice_MapScripts::
	map_script ON_FRAME, ACO_OnFrameScript
	.byte 0
	
ACO_OnFrameScript::
	map_script_2 VAR_RYU_AQUA, 45, ACO_ReturnedFromMuseumWhiteout
	.2byte 0


ACO_EntranceScriptTrigger::
	switch VAR_RYU_AQUA
	case 5, ACO_StartAquaQuest
	case 10, ryu_end
	case 55, ryu_end
	case 72, ryu_end
	case 80, ryu_end
	case 160, ryu_end
	goto ACO_BlockEntry

ACO_Shelly::
	compare VAR_RYU_AQUA, 72
	goto_if_lt ryu_end
	compare VAR_RYU_AQUA, 80
	goto_If_eq ACO_AquaStage3_Waitforcall
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
	setvar VAR_RYU_AQUA, 80
	release
	end
	
ACO_AquaStage3_Waitforcall:
	msgbox ACO_AquaStage3_WaitForCallMsg
	release
	end
	
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




