MossdeepCity_SpaceCenter_2F_MapScripts:: @ 8223D58
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
	.byte 0

SPC_PREVENT2fEXIT::
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 106
	goto_if_eq SPC_CANTLEAVE
	release
	end

SPC_CANTLEAVE::
	lockall
	msgbox spc_cantleavemsg
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

spc_cantleavemsg:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} You can't leave yet.\pYou have to deal with Magma's\npresence.$"

MossdeepCity_SpaceCenter_2F_OnTransition: @ 8223D63
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 106
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MoveStevenMaxieCourtney
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 106
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveStevenMaxieCourtney:: @ 8223D7A
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm 3, 16, 9
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 1, 14, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 2, 12, 5
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts:: @ 8223D9F
	setobjectxyperm 5, 11, 2
	setobjectxyperm 7, 15, 2
	setobjectxyperm 6, 13, 4
	return

MossdeepCity_SpaceCenter_2F_OnFrame: @ 8223DB5
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts:: @ 8223DBF
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 255, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_PlayerExit: @ 8223E07
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts:: @ 8223E09
	call_if_set FLAG_RYU_PLAYER_HELPING_AQUA, SPC_RemoveGruntsCuzAqua
	goto_if_set FLAG_RYU_PLAYER_HELPING_AQUA, ryu_end
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
	applymovement 6, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
	applymovement 5, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
	applymovement 7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
	removeobject 5
	removeobject 7
	removeobject 6
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_MAXIE
	addobject 9
	releaseall
	end
	
SPC_RemoveGruntsCuzAqua:
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	special DrawWholeMapView
	return

MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated: @ 8223E81
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated: @ 8223E85
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated: @ 8223E89
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist:: @ 8223E8D
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal:: @ 8223EB4
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma:: @ 8223EBE
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman:: @ 8223EC8
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal:: @ 8223EEF
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma:: @ 8223EF9
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy:: @ 8223F03
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal:: @ 8223F2A
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma:: @ 8223F34
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
	release
	end

@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6:: @ 8223F3E
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt7:: @ 8223F47
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt5:: @ 8223F50
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Courtney:: @ 8223F59
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
@===================================================================================================Scientist Devon

SPC_MaxieIntro:
	.string "I think you're in a little\nover your head.\lNo one can stop me now!$"
	
SPC_MaxieDefeat:
	.string "What?! NO! Why?!$"

SPC_Maxie::
	goto_if_unset FLAG_RYU_PLAYER_HELPING_DEVON, ryu_killMaxie
	goto_if_unset FLAG_RYU_DEVON_SCIENTIST, ryu_killMaxie
	trainerbattle_single TRAINER_MAXIE_3, SPC_MaxieIntro, SPC_MaxieDefeat, SPC_MaxieDefeated
	goto SPC_MaxieDefeated
	end

ryu_killMaxie::
	removeobject 9
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_MAXIE
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	release
	end
	
SPC_MaxieDefeated:: @ 8224071
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 9, Common_Movement_WalkInPlaceFastestLeft
	applymovement 8, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 60
	applymovement 9, Common_Movement_WalkInPlaceFastestUp
	applymovement 8, Common_Movement_WalkInPlaceFastestRight
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	fadescreen 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	removeobject 5
	removeobject 7
	removeobject 6
	removeobject 8
	removeobject 9
	setobjectxy 3, 5, 6
	turnobject 3, 1
	setobjectxy 2, 11, 8
	turnobject 2, 2
	setobjectxy 1, 6, 2
	turnobject 1, 2
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	fadescreen 0
	goto SPC_AfterMaxie
	end
	
SPC_AfterMaxie::
	lockall
	addobject 3
	setobjectxy 3, 16, 6
	applymovement 3 SPC_ScientistToRight
	waitmovement 3
	msgbox SPC_ScientistIntro
	closemessage
	playse SE_DOOR
	addobject 12
	setobjectxy 12, 21, 1
	applymovement 12, SPC_StevenEnters@down, right, down, face down.
	waitmovement 12
	msgbox SPC_WeveBeenExpecting
	closemessage
	msgbox SPC_WereSorryYouHad
	closemessage
	msgbox SPC_WeWereTold
	closemessage
	applymovement 3, Common_Movement_StepDown
	waitmovement 3
	msgbox SPC_AsItIs
	closemessage
	applymovement 3, Common_Movement_FaceUp
	waitmovement 3
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 12
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox SPC_ActuallyThatMight
	closemessage
	msgbox SPC_WhatsThat
	closemessage
	applymovement 3, Common_Movement_StepUp
	waitmovement 3
	msgbox SPC_NotOnlyThat
	closemessage
	fadenewbgm MUS_DUMMY
	closemessage
	msgbox SPC_MewtwoIntervenes
	goto SPC_AfterMaxie2

SPC_AfterMaxie2::
	fadenewbgm 501
	fadescreen 1
	playse SE_TK_WARPIN
	addobject 10
	delay 20
	fadescreen 2
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 12
	applymovement 12, SPC_StepBack
	waitmovement 12
	msgbox SPC_MewtwoIntro
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement 12, Common_Movement_FaceUp
	waitmovement 12
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox SPC_WhoreYouNameUnimportant
	closemessage
	playse SE_W089
	special DoSealedChamberShakingEffect1
	msgbox SPC_NoChoice
	closemessage
	delay 60
	special DrawWholeMapView
	drawcustompic 2, SPECIES_CASTFORM, 208, 104
	playmoncry SPECIES_CASTFORM, 5
	waitmoncry
	applymovement 10, Common_Movement_QuestionMark
	waitmovement 10
	msgbox SPC_YouAgreed
	closemessage
	playmoncry SPECIES_CASTFORM, 0
	waitmoncry
	msgbox SPC_YouStillSide
	closemessage
	fadedefaultbgm
	playse SE_TK_WARPOUT
	removeobject 10
	msgbox SPC_APlaceOnlyStrong
	closemessage
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 107
	release
	end
	
SPC_SetSecondScene::
	lock
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 109
	setobjectxyperm 3, 16, 9
	release
	end
	
SPC_Scientist::
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 107
	goto_if_eq SPC_headToVictoryRoad
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 109
	goto_if_eq SPC_MewtwoDefeated
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 115
	goto_if_eq SPC_Afterstory
	goto_if_set FLAG_RYU_SCIENTIST_DONE, SPC_Afterstory
	release
	end
	
SPC_headToVictoryRoad::
	msgbox SPC_YouShouldBeHeaded
	closemessage
	release
	end
	
SPC_MewtwoDefeated::
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 110
	goto_if_eq SPC_GoCheckSafariZone
	msgbox SPC_MeetMeAtTable
	closemessage
	applymovement 3, SPC_Sci2Desk
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SPC_Pl2Desk
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox SPC_WaitForOthers
	playse SE_DOOR
	delay 10
	addobject 12
	playse SE_DOOR
	addobject 11
	applymovement 12, SPC_StevenToDesk
	applymovement 11, SPC_NewSciToDesk
	waitmovement 11
	msgbox SPC_SoYouveReturned
	closemessage
	additem ITEM_FORECASTER
	delay 20
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 11
	msgbox SPC_YourNextAssignment
	closemessage
	applymovement 3, Common_Movement_FaceDown
	waitmovement 3
	msgbox SPC_SomethingTheMatter
	closemessage
	applymovement 11, Common_Movement_FaceLeft
	waitmovement 11
	msgbox SPC_ImPickingUp
	closemessage
	applymovement 3, Common_Movement_FaceRight
	waitmovement 3
	msgbox SPC_WellOffYou
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 110
	setflag FLAG_RYU_SCIENTIST_DONE
	release
	end
	
SPC_GoCheckSafariZone::
	lock
	msgbox SPC_GoCheckSafariZoneMsg
	release
	end
	
SPC_Afterstory:
	msgbox SPC_LineCompleted
	setflag FLAG_RYU_DEVON_LINE_FINISHED
	release
	end
	
SPC_LineCompleted:
	.string "Ah, so the anomaly was Mewtwo.\nWell, that's settled then.\pIn other news...\pCongratulations, You've officially\ncompleted your apprenticeship.\lOnce you get older, you can\pjoin us as a space researcher\nor work on other projects.$"

SPC_GoCheckSafariZoneMsg:
	.string "Bart: You should go check out the\n"
	.string "energy signature Cozmo's Rad\l"
	.string "Sensor picked up.$"
	
SPC_MeetMeAtTable:
	.string "Bart: Come to the empty\ndesk over here.$"
	
SPC_WaitForOthers:
	.string "Let's wait for the others, they\nshould be here soon.$"
	
SPC_SoYouveReturned:
	.string "Bart: So, you've returned. I trust\n"
	.string "things went well?\p"
	.string "Cozmo: {PLAYER}, we have news\n"
	.string "to share!\p"
	.string "Bart: Although Castform's still\n"
	.string "unable to form change in a\p"
	.string "sandstorm, we were able to obtain\n"
	.string "enough data to emulate the\p"
	.string "conditions necessary to simulate\n"
	.string "for our immediate use. As a result\l"
	.string "the Forecaster is now complete!\p"
	.string "Take it, my fellow scientist, as a\n"
	.string "reward for your contribution to\l"
	.string "the project.$"

SPC_YourNextAssignment:
	.string "Cozmo: Now, as to your next assignment...\n"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Hm?$"

SPC_SomethingTheMatter:
	.string "Bart: Problem, Cozmo?$"

SPC_ImPickingUp:
	.string "I'm picking up a high energy\n"
	.string "reading near the Safari Zone.\p"
	.string "Strange...that place hasn't been\n"
	.string "traversed since it shut down years\l"
	.string "ago...$"

SPC_WellOffYou:
	.string "Well, off you go, {PLAYER}! Your\n"
	.string "research continues!$"

SPC_YouShouldBeHeaded:
	.string "You should go face Mewtwo in\nVictory Road.$"
	
SPC_ScientistIntro:
	.string "Greetings. Who might you be?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I'm {PLAYER}, and understudy to\n"
	.string "Prof. Cozmo.$"

SPC_WeveBeenExpecting:
	.string "Ah yes. We've been\n"
	.string "expecting you.$"

SPC_WereSorryYouHad:
	.string "We're sorry you had to deal with\n"
	.string "Magma. Steven could have done it\p"
	.string "but I guess he wanted to see you\n"
	.string "work.$"

SPC_WeWereTold:
	.string "We were told of the\n"
	.string "situation, and we are willing to\p"
	.string "lend you a hand, however,\n"
	.string "according to the report, the\p"
	.string "problem lies with just how long\n"
	.string "Castform can sustain the sandstorm\p"
	.string "in order for its' cells to respond\n"
	.string "to the change.$"

SPC_AsItIs:
	.string "As it is, Castform cannot build up\n"
	.string "the energy necessary to change for\p"
	.string "form, and at the same time keep\l"
	.string "the sandstorm going.$"

SPC_ActuallyThatMight:
	.string "If there was a way for us to\n"
	.string "prolong the sandstorm while it\l"
	.string "concentrates on changing form...$"

	.string "Steven: Actually, that might be\n"
	.string "possible. Take a look.$"

SPC_WhatsThat:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}What's that?\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Its called a Smooth Rock. I\n"
	.string "found it during my travels in\p"
	.string "another region. From what I heard,\n"
	.string "it extends the caster's duration\p"
	.string "of Sandstorm. All your Castform\n"
	.string "would need to do is use the move.\p "
	.string "This stone should handle the rest.$"

SPC_NotOnlyThat:
	.string "Not only that, we'd also be able\n"
	.string "to monitor its' responses to a\p"
	.string "greater degree, all the while\n"
	.string "cutting down significantly on time\p"
	.string "spent. Steven, you're a genius!\n"
	.string "Let's get started right away!$"

SPC_MewtwoIntervenes:
	.string "{COLOR LIGHT_BLUE}{SHADOW RED}Experimentation...on a pokémon?$"

SPC_MewtwoIntro:
	.string "{COLOR LIGHT_BLUE}{SHADOW RED}I thought the human race had learned\n"
	.string "from their mistakes...$"

SPC_WhoreYouNameUnimportant:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Who're you?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW RED}My name is unimportant. What I\n"
	.string "won't stand for, however, is\p"
	.string "experimenting on pokémon simply to\n"
	.string "satisfy your own curiosity. Such\p"
	.string "thinking is what led to my\n"
	.string "creation, along with the pain and\p"
	.string "strife that followed. I suggest\n"
	.string "you put an end to this now,\l"
	.string "otherwise...$"

SPC_NoChoice:
	.string "{COLOR DARK_GREY}{SHADOW RED}I'll have no choice but to bring\n"
	.string "this building and everyone in it\l"
	.string "to the ground.$"

SPC_YouAgreed:
	.string "{COLOR DARK_GREY}{SHADOW RED}What? You...agreed to this?\p"
	.string "That's absurd! It's clearly\n"
	.string "obvious that humans willingly\p"
	.string "repeat their past mistakes,\n"
	.string "expecting a different outcome.\p"
	.string "I know better...they never learn.$"

SPC_YouStillSide:
	.string "{COLOR DARK_GREY}{SHADOW RED}You still side with them...then\n"
	.string "I'll show you firsthand...\p"
	.string "Trainer! What is your name?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}.\p"
	.string "{COLOR DARK_GREY}{SHADOW RED}{PLAYER}...you will show me your\n"
	.string "true intentions. Come and find me.\p"
	.string "To the place where only the strong\n"
	.string "may enter. We'll settle things\l"
	.string "there.$"

SPC_APlaceOnlyStrong:
	.string "'A place where only the strong may\n"
	.string "enter...' The only location I can\p"
	.string "think of is Victory Road. You\n"
	.string "better head on over there. Don't\l"
	.string "worry, I'll handle things here.$"

SPC_ScientistToRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
SPC_Sci2Desk:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_in_place_right
	step_end
	
SPC_Pl2Desk:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_up
	step_end

SPC_StevenToDesk:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_down
	step_end
	
SPC_NewSciToDesk:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_up
	step_end
	
SPC_StevenEnters:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_down
	step_end

SPC_StepBack::
	walk_diag_southwest
	walk_in_place_up
	step_end

@==================================================================================================end devon


MossdeepCity_SpaceCenter_2F_EventScript_Maxie:: @ 8223F6F
	lockall
	goto SPC_Maxie
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_StevenFight: @ 8223FC6
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth: @ 8223FCF
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_MaxieTrainer:: @ 8224157
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_MAXIE_3, 0, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
	end

MossdeepCity_SpaceCenter_2F_EventScript_CourtneyTrainer:: @ 8224166
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_COURTNEY_MOSSDEEP, 0, MossdeepCity_SpaceCenter_Text_CourtneyDefeat, MossdeepCity_SpaceCenter_Text_CourtneyDefeat
	end

MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall:: @ 8224175
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
	compare VAR_RESULT, FEMALE
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall:: @ 8224193
	pokenavcall MatchCall_Text_MayRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall:: @ 822419A
	pokenavcall MatchCall_Text_BrendanRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets: @ 82241A1
	.string "MOSSDEEP has mainly sunny weather,\n"
	.string "and its winds are stable.\p"
	.string "It's an ideal location for launching\n"
	.string "rockets.$"

MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel: @ 822420C
	.string "Why would Team Magma want to steal\n"
	.string "our rocket fuel in the first place?$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut: @ 8224253
	.string "If only I was a little younger, I would\n"
	.string "have liked being an astronaut…\p"
	.string "No… It's not too late!\n"
	.string "I can and will try!$"

MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis: @ 82242C5
	.string "If Team Magma takes the rocket fuel,\n"
	.string "I won't be able to go to space!\p"
	.string "They can't be allowed to get away\n"
	.string "with such an outrage!$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace: @ 8224342
	.string "I wish ordinary people could go into\n"
	.string "space one day…$"

MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace: @ 8224376
	.string "Team Magma…\n"
	.string "Do they want to go to space, too?$"

MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn: @ 82243A4
	.string "What's wrong with you?\p"
	.string "You're outnumbered three to one,\n"
	.string "but you still want to take us on?$"

MossdeepCity_SpaceCenter_2F_Text_GoodAnswer: @ 82243FE
	.string "Good answer!\n"
	.string "That's what a smart person'll do!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro: @ 822442D
	.string "A reckless go-getter, are you?\n"
	.string "Okay, I'll go first!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat: @ 8224461
	.string "I lost!\n"
	.string "But!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro: @ 822446E
	.string "It's too soon to be relieved!\n"
	.string "I'm up next!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat: @ 8224499
	.string "I lost, too!\n"
	.string "But!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro: @ 82244AB
	.string "I bet you want to take a break.\n"
	.string "But I'm not about to let you do that!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat: @ 82244F1
	.string "We should've taken a break…\n"
	.string "That's what we should've done…$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle: @ 822452C
	.string "Three of us here, and look at the sorry\n"
	.string "mess we got ourselves into.$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle: @ 8224570
	.string "We three losing like this…\n"
	.string "We look worse than usual by triple!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle: @ 82245AF
	.string "Are we being useful to our leader\n"
	.string "at all?$"

MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou: @ 82245D9
	.string "Hehehe!\p"
	.string "We come all the way here to get some\n"
	.string "fuel, and we're interfered with again!\p"
	.string "If you're going to mess with us too,\n"
	.string "we'll take care of you at the same time!$"

MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere: @ 822467B
	.string "Maxie: Clear out of the way!\n"
	.string "Don't you dare interfere!$"

MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel: @ 82246B2
	.string "STEVEN: Team Magma…\p"
	.string "What's the point of stealing rocket\n"
	.string "fuel?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano: @ 82246F0
	.string "Maxie: Fufufu… Since you're so\n"
	.string "curious, you deserve an explanation.\p"
	.string "We're going to jettison the entire\n"
	.string "load into MT. CHIMNEY!\p"
	.string "With GROUDON gone, we have no need\n"
	.string "for that slag heap of a mountain!\p"
	.string "So we'll use the fuel's power to make\n"
	.string "the volcano erupt!\p"
	.string "It will be savage!$"

MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle: @ 82247FF
	.string "STEVEN: {PLAYER}!\n"
	.string "You're going to help me?\p"
	.string "Let's go into battle together!\n"
	.string "Are you ready?$"

MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly: @ 8224854
	.string "STEVEN: Then, hurry!\n"
	.string "Get ready quickly!$"

MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand: @ 822487C
	.string "All I want…\n"
	.string "I just want to expand the land mass…$"

MossdeepCity_SpaceCenter_Text_CourtneyDefeat: @ 82248AD
	.string "I'm with our leader…$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided: @ 82248C2
	.string "Maxie: We failed to make the volcano\n"
	.string "erupt…\p"
	.string "We failed to control GROUDON after\n"
	.string "we had awoken it…\p"
	.string "Is our goal to expand the land\n"
	.string "misguided?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "If…\n"
	.string "If we, Team Magma, are wrong…\l"
	.string "… … … … … …\p"
	.string "Then might Team Aqua's goal to expand\n"
	.string "the sea also be equally misguided?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp: @ 82249DC
	.string "Maxie: All right…\n"
	.string "We will give up on the fuel…\p"
	.string "There appear to be more important\n"
	.string "matters that I must examine…$"

MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome: @ 8224A4A
	.string "STEVEN: Whew, that was too tense.\n"
	.string "{PLAYER}, thank you.\p"
	.string "I have something to give you as\n"
	.string "thanks for your support.\p"
	.string "Please come see me at home\n"
	.string "after this.\p"
	.string "Oh, yes, I don't live in RUSTBORO CITY.\n"
	.string "I live right here on this island.$"
