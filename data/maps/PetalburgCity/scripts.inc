.set LOCALID_WALLY, 2
.set LOCALID_BOY, 3
.set LOCALID_WALLYS_DAD, 5
.set LOCALID_GYM_BOY, 8
.set LOCALID_SCOTT, 9

PetalburgCity_MapScripts::
	map_script ON_TRANSITION, PetalburgCity_OnTransition
	map_script ON_FRAME, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition: @ 81DC2D7
	setflag FLAG_VISITED_PETALBURG_CITY
	compare VAR_PETALBURG_CITY_STATE, 0
	call_if_eq PetalburgCity_EventScript_MoveBoyToWestEntrance
	compare VAR_PETALBURG_CITY_STATE, 2
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_CITY_STATE, 4
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_GYM_STATE, 8
	call_if_eq PetalburgCity_EventScript_SetGymDoorsUnlocked
	end

PetalburgCity_EventScript_MoveBoyToWestEntrance:: @ 81DC307
	setobjectxyperm 8, 5, 11
	return

PetalburgCity_EventScript_DisableMapNameAndMusic:: @ 81DC30F
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_TSURETEK
	return

PetalburgCity_EventScript_SetGymDoorsUnlocked:: @ 81DC316
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PetalburgCity_OnFrame: @ 81DC31C
	map_script_2 VAR_TEMP_A, 0, Ryu_CheckMagmaStatusForMissionCall
	map_script_2 VAR_RYU_MAGMA, 245, PC_DoMagmaStuffAfterHeist
	.2byte 0

PetalburgCity_EventScript_Boy1:: @ 81DC3E6
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_GymSign:: @ 81DC476
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign:: @ 81DC47F
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman:: @ 81DC488
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign:: @ 81DC491
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_ShowGymToPlayer0:: @ 81DC49A
	lockall
	setvar VAR_0x8008, 0
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer1:: @ 81DC4A6
	lockall
	setvar VAR_0x8008, 1
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer2:: @ 81DC4B2
	lockall
	setvar VAR_0x8008, 2
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer3:: @ 81DC4BE
	lockall
	setvar VAR_0x8008, 3
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer:: @ 81DC4CA
	applymovement 8, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_TSURETEK, 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer3
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym3
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
	applymovement 8, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
	closemessage
	applymovement 8, PetalburgCity_Movement_BoyWalkAway
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_EventScript_BoyApproachPlayer0:: @ 81DC57F
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer1:: @ 81DC594
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer1
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer2:: @ 81DC59F
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer3:: @ 81DC5B4
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym0:: @ 81DC5C9
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym1:: @ 81DC5DB
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym1
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym2:: @ 81DC5ED
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym3:: @ 81DC5FF
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym3
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
	waitmovement 0
	return

PetalburgCity_Movement_1DC611:: @ 81DC611
	delay_16
	delay_16
	delay_16
	step_end

PetalburgCity_Movement_BoyApproachPlayer0: @ 81DC615
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyApproachPlayer1: @ 81DC61A
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer2: @ 81DC61D
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyApproachPlayer3: @ 81DC622
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyWalkToGym0: @ 81DC628
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym1: @ 81DC633
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym2: @ 81DC641
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym3: @ 81DC64C
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkAway: @ 81DC658
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWalkToGym0: @ 81DC665
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym1: @ 81DC66F
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym2: @ 81DC67C
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym3: @ 81DC686
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_EventScript_Scott0:: @ 81DC691
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott1:: @ 81DC6A7
	releaseall
	end

PetalburgCity_EventScript_Scott2:: @ 81DC6BD
	releaseall
	end

PetalburgCity_EventScript_Scott3:: @ 81DC6D3
	releaseall
	end

PetalburgCity_EventScript_Scott:: @ 81DC6E9
	releaseall
	end

PetalburgCity_EventScript_ScottExit0:: @ 81DC78E
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
	applymovement 9, PetalburgCity_Movement_ScottExit0
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit1:: @ 81DC7A0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
	applymovement 9, PetalburgCity_Movement_ScottExit1
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit2:: @ 81DC7B2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
	applymovement 9, PetalburgCity_Movement_ScottExit2
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit3:: @ 81DC7C4
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
	applymovement 9, PetalburgCity_Movement_ScottExit3
	waitmovement 0
	return

PetalburgCity_Movement_ScottStartWalkLeft: @ 81DC7D6
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottApproachPlayer: @ 81DC7DB
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottExit0: @ 81DC7E0
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit0: @ 81DC7EE
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit1: @ 81DC7F5
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit1: @ 81DC802
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit2: @ 81DC808
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit2: @ 81DC815
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit3: @ 81DC81B
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit3: @ 81DC828
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_EventScript_Boy2:: @ 81DC82E
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_Text_AreYouRookieTrainer: @ 81DC881
	.string "Hiya! Are you maybe…\n"
	.string "A rookie Trainer?\p"
	.string "Do you know what Pokémon Trainers\n"
	.string "do when they reach a new town?\p"
	.string "They first check what kind of Gym\n"
	.string "is in the town.$"

PetalburgCity_Text_ThisIsPetalburgGym: @ 81DC91B
	.string "See? This is Petalburg City's Gym.$"

PetalburgCity_Text_ThisIsGymSign: @ 81DC93E
	.string "This is the Gym's sign. Look for it\n"
	.string "whenever you're looking for a Gym.$"

PetalburgCity_Text_WaterReflection: @ 81DC985
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"

PetalburgCity_Text_FullPartyExplanation: @ 81DCA30
	.string "Let's say you have six Pokémon.\n"
	.string "If you catch another one…\p"
	.string "It is automatically sent to a Storage\n"
	.string "Box over a PC connection.$"

PetalburgCity_Text_GymSign: @ 81DCAAA
	.string "Petalburg City Pokémon Gym\n"
	.string "Leader: Norman\l"
	.string "“A man in pursuit of power!”$"

PetalburgCity_Text_CitySign: @ 81DCAF1
	.string "Petalburg City\n"
	.string "“Where people mingle with nature.”$"

PetalburgCity_Text_WallyHouseSign: @ 81DCB23
	.string "For Sale$"

PetalburgCity_Text_AreYouATrainer: @ 81DCB31
	.string "Excuse me!\p"
	.string "Let me guess, from the way you're\n"
	.string "dressed, are you a Pokémon Trainer?$"

PetalburgCity_Text_WellMaybeNot: @ 81DCB82
	.string "… … … … … …\p"
	.string "Well, maybe not.\n"
	.string "Your clothes aren't all that dirty.\p"
	.string "You're either a rookie Trainer,\n"
	.string "or maybe you're just an ordinary kid.$"

PetalburgCity_Text_ImLookingForTalentedTrainers: @ 81DCC09
	.string "I'm roaming the land in search of\n"
	.string "talented Trainers.\p"
	.string "I'm sorry to have taken your time.$"
	
@==================================================================================================Mamga post-heist

PC_DoMagmaStuffAfterHeist::
	setvar VAR_RYU_MAGMA, 250
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	release
	end
	
PC_CheckForPlayerInWrongDirection::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq ryu_end
	compare VAR_RYU_MAGMA, 250
	goto_if_eq PC_YouCantLeaveThisDirection
	goto ryu_end
	
PC_NoTimeToSwim::
	compare VAR_RYU_MAGMA, 250
	goto_if_ne ryu_end
	lock
	msgbox PC_NotTheTime
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
PC_YouCantLeaveThisDirection::
	msgbox PC_YouShouldBeFleeingWest
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
PC_StopPlayerForDad::
	compare VAR_RYU_MAGMA, 250
	goto_if_ne ryu_end
	lock
	playbgm 350, 0
	setvar VAR_RYU_MAGMA, 255 @Dad notices player
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	addobject 7
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 7
	addobject 10
	addobject 11
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox PC_PlayerElipsis
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PC_ContinueEscapingLeft@6 left
	waitmovement OBJ_EVENT_ID_PLAYER
	getplayerxy VAR_TEMP_D, VAR_TEMP_E
	compare VAR_TEMP_E, 10
	call_if_eq PC_AdjustPlayerTop
	compare VAR_TEMP_E, 11
	call_if_eq PC_AdjustPlayerMid
	compare VAR_TEMP_E, 13
	call_if_eq PC_AdjustPlayerBottom
	msgbox PC_WeWontLet
	closemessage
	setvar VAR_RYU_MAGMA, 258@Player is about to fight enforcer
	trainerbattle_single TRAINER_DEVON_2, PC_DevonIntro, PC_DevonDefeated, PC_ContinueScene
	end
	
PC_AdjustPlayerTop::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	return
	
PC_AdjustPlayerMid::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	return
	
PC_AdjustPlayerBottom::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	return
	
PC_ContinueScene::
	applymovement OBJ_EVENT_ID_PLAYER, PC_MoveGuard
	applymovement 8, PC_MoveGuard
	waitmovement 8
	applymovement 10, PC_MagmaGruntEscape
	waitmovement 10
	removeobject 10
	applymovement OBJ_EVENT_ID_PLAYER PC_PlayerAttemptEscape
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 8, Common_Movement_FaceDown
	applymovement 9, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, PC_PlayerStruggle
	msgbox PC_LetGoYou
	closemessage
	applymovement 8, Common_Movement_FaceRight
	applymovement 9, Common_Movement_FaceRight
	waitmovement 9
	addobject 7
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 7, PC_DadToPlayer@leave 2 space gap
	waitmovement 7
	msgbox PC_DadPlayerLook
	applymovement 7, Common_Movement_StepLeft
	waitmovement 7
	fadescreen FADE_TO_WHITE
	fadescreen FADE_FROM_WHITE
	addobject 11
	applymovement 11, Common_Movement_FaceRight
	waitmovement 11
	msgbox PC_GetAwayFromMe
	closemessage
	applymovement 11, Common_Movement_FaceLeft
	waitmovement 11
	msgbox PC_WhoAreYou
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	delay 20
	applymovement 11, Common_Movement_StepLeft
	waitmovement 11
	msgbox PC_Bothersome
	closemessage
	applymovement 11, Common_Movement_FaceRight
	waitmovement 11
	msgbox PC_Deleting
	closemessage
	setvar VAR_RYU_MAGMA, 260@Player got warped to slateport beach by courtney
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	warpteleport MAP_ROUTE109, 255, 20, 24
	waitstate
	end
	
	
PC_NotTheTime:
	.string "This is not the time to be\nexploring. Escape west!$"
	
PC_YouShouldBeFleeingWest:
	.string "Make your escape to Route 104!$"
	
PC_PlayerElipsis:
	.string "{PLAYER}...?$"
	
PC_WeWontLet:
	.string "We won't let you escape!\p"
    .string "Back me up here, {PLAYER}!$"

PC_LetGoYou:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Let go, you lost!\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Hate to break it to ya, but winning\n"
    .string "pokémon battles won't get you out\p"
    .string "of this mess. You'll pay the price\n"
    .string "for your actions, and who better to\p"
    .string "deal out your punishment than...$"


PC_DadPlayerLook:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Dad...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}{PLAYER}, look at what's happened\n"
    .string "to you. Has my child become nothing\p"
    .string "more than a criminal? What'll your\n"
    .string "mother think?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I made this choice on my own. It's\n"
    .string "not your concern.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Of course it is! We're your parents,\n"
    .string "and a parent's duty is to discipline\p"
    .string "their child when they've taken a\n"
    .string "wrong turn. I will do the same, even\p"
    .string "if I have to turn you in myself.$"

PC_GetAwayFromMe:
	.string "Get away from me...$"
	
PC_WhoAreYou:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Who're you?\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}MOVE!\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Ah, right! Bye!$"
	
PC_Bothersome:
	.string "Bothersome...$"

PC_Deleting:
	.string "Deleting...$"
	
PC_DevonIntro:
	.string "I will stop you dead!$"
	
PC_DevonDefeated:
	.string "Oh well...$"

PC_ContinueEscapingLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
	
PC_MoveGuard:@up face left
	walk_fastest_up
	face_left
	step_end

PC_MagmaGruntEscape:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

PC_PlayerAttemptEscape:@down 1, left 1
	walk_down
	walk_left
	step_end
	
PC_PlayerStruggle:@in place 4
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	step_end
	
PC_DadToPlayer:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
