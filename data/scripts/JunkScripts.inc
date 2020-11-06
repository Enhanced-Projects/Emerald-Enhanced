LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F863F
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_DawnsHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F958F
	setvar VAR_0x8004, 2
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_DawnsHouse_2F_EventScript_1F9576:: @ 81F9576
	setvar VAR_0x8004, 2
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

Common_Text_LookCloserAtMap: @ 81F8820
	.string "{PLAYER} took a closer look at the\n"
	.string "Hoenn region map.$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash: @ 81F826F
	.string "$"

PlayersHouse_1F_Text_IsntItNiceInHere: @ 81F7A1C
	.string "Mom: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

LittlerootTown_DawnsHouse_2F_EventScript_1F956C:: @ 81F956C
	msgbox gUnknown_08272CD5, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_EventScript_TownSign:: @ 81E8151
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_Text_TownSign: @ 81E8D32
	.string "Littleroot Town\n"
	.string "“A town that can't be shaded any hue.”$"

gUnknown_08272CD5:: @ 8272CD5
	.string "$"

PlayersHouse_2F_EventScript_Notebook:: @ 81F8656
	end

gUnknown_08272D87:: @ 8272D87
	.string "{PLAYER} booted up the PC.$"

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC:: @ 81F8626
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_GameCube:: @ 81F865F
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayersHouse_2F_Text_ItsAGameCube: @ 81F884F
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"

PlayersHouse_2F_Text_Notebook: @ 81F877F
	.string "$"

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC:: @ 81F864C
	end

PlayersHouse_1F_Text_MoversPokemonGoSetClock: @ 81F7A46
	.string "$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom: @ 81F7B24
	.string "$"

PlayersHouse_2F_Text_ClockIsStopped: @ 81F8668
	.string "$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom: @ 81F869A
	.string "$"

PlayersHouse_1F_Text_MaybeDadWillBeOn: @ 81F7BBC
	.string "$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor: @ 81F7C35
	.string "$"

LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetSlakothes:: @ 81F777A
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:: @ 81F778D
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F779A
	return

LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:: @ 81F77C6
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:: @ 81F77D2
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:: @ 81F77DE
	return

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs: @ 81F783A
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F783C
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport:: @ 81F784D
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor:: @ 81F785E
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach: @ 81F789C
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom:: @ 81F78A3
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0:: @ 81F78BE
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1:: @ 81F78CA
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2:: @ 81F78D6
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival:: @ 81F78E2
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan:: @ 81F7981
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0:: @ 81F798C
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1:: @ 81F7997
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2:: @ 81F79A2
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0: @ 81F79AD
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1: @ 81F79B5
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2: @ 81F79B9
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0:: @ 81F79C1
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1:: @ 81F79D3
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2:: @ 81F79E5
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0: @ 81F79F7
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1: @ 81F79FB
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2: @ 81F7A02
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0: @ 81F7A06
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1: @ 81F7A0C
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2: @ 81F7A16
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_GoSetTheClock: @ 81F7B67
	.string "$"

PlayersHouse_1F_Text_OhComeQuickly: @ 81F7B96
	.string "$"

PlayersHouse_1F_Text_ItsOverWeMissedHim: @ 81F7BF1
	.string "$"

PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
	.string "$"

PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
	.string "$"

PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
	.string "$"

PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
	.string "$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom: @ 81F7D73
	.string "$"

PlayersHouse_1F_Text_DontPushYourselfTooHard: @ 81F7DBE
	.string "$"

PlayersHouse_1F_Text_IsThatAPokenav: @ 81F7E0E
	.string "$"

PlayersHouse_1F_Text_RegisteredMom: @ 81F7E89
	.string "$"

PlayersHouse_1F_Text_Vigoroth1: @ 81F7EA8
	.string "$"

PlayersHouse_1F_Text_Vigoroth2: @ 81F7EB3
	.string "$"

PlayersHouse_1F_Text_ReportFromPetalburgGym: @ 81F7EC6
	.string "$"

PlayersHouse_1F_Text_TheresAMovieOnTV: @ 81F7F0F
	.string "$"

PlayersHouse_1F_Text_RunningShoesManual: @ 81F7F66
	.string "$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou: @ 81F800E
	.string "$"

PlayersHouse_1F_Text_PortsInSlateportLilycove: @ 81F80FE
	.string "$"

PlayersHouse_1F_Text_BetterGetBackToGym: @ 81F815B
	.string "$"

PlayersHouse_1F_Text_DadShouldStayLonger: @ 81F81B9
	.string "$"

PlayersHouse_1F_Text_IsThatABreakingStory: @ 81F824B
	.string "$"

PlayersHouse_1F_Text_WhatColorDidTheySay: @ 81F8351
	.string "$"

PlayersHouse_1F_Text_StillUnknownPokemon: @ 81F83A1
	.string "$"



