PetalburgCity_Gym_MapScripts:: @ 8204889
	map_script ON_FRAME, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnLoad: @ 820489E
	end

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors:: @ 82048B5
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors:: @ 82048FF
	setvar VAR_0x8005, 1
	return

PetalburgCity_Gym_OnTransition: @ 820492D
	end

PetalburgCity_Gym_EventScript_MoveWallyToEntrance:: @ 820494D
	setobjectxyperm 10, 5, 108
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance:: @ 8204955
	setobjectxyperm 1, 4, 107
	return

PetalburgCity_Gym_EventScript_CheckNormanForRematch:: @ 820495D
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront:: @ 8204985
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_OnWarp: @ 820498B
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth:: @ 8204995
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame: @ 820499A
	map_script_2 VAR_TEMP_1, 0, PetalburgCity_Gym_CheckNormanState
	.2byte 0

PetalburgCity_Gym_CheckNormanState::
	setvar VAR_TEMP_1, 10
	special checkbadgecount
	compare VAR_RESULT, 4
	goto_if_lt PBG_MoveNormanSouth
	end

PBG_MoveNormanSouth::
	@addobject 1
	setobjectxy 1, 4, 106
	special DrawWholeMapView
	release
	end

PBG_NEWGYMBATTLE::
	lock
	faceplayer
	setflag FLAG_RYU_ALTERNATE_SCALE
	special checkbadgecount
    switch VAR_RESULT
	case 0, norman1
	case 1, norman1
	case 2, norman1
	case 3, norman2
	case 4, norman2
	case 5, norman3
	case 6, norman3
	case 7, norman4
	case 8, norman4
	end

PBG_AreYouSure:
    .string "Are you sure you want to fight me\n"
    .string "now?$"

PBG_NotReadyYet::
	msgbox PBG_PlayerNotReadyText
	release
	end

PBG_PlayerNotReadyText:
    .string "I brought you into this world, I can\n"
    .string "certainly take you right out of it!\p"
    .string "Come back when you are stronger!$"

PG_Reset::
	setvar VAR_TEMP_8, 5
	special checkbadgecount
	compare VAR_RESULT, 4
	call_if_ge PG_GiveMegaBracelet
	special checkbadgecount
	compare VAR_RESULT, 8
	call_if_eq RyuTier8GymMegaStoneReward
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setvar VAR_PETALBURG_GYM_STATE, 7
	cleartrainerflag TRAINER_NORMAN_1
	cleartrainerflag TRAINER_NORMAN_2
	cleartrainerflag TRAINER_NORMAN_3
	cleartrainerflag TRAINER_NORMAN_4
	clearflag FLAG_RYU_ALTERNATE_SCALE
	goto_if_set FLAG_RYU_HARDCORE_MODE, RyuScripts_HardcoreGymReward
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuHealedGym
	call_if_unset FLAG_RYU_GYM5HANDOUT, RyuGymItemReward5
	special InitBirchState
	release
	end

PG_GiveMegaBracelet::
	goto_if_set FLAG_RYU_RECEIVED_MEGA_BRACELET, ryu_return
	msgbox NormanGivesMB
	additem ITEM_MEGA_BRACELET
	closemessage
	msgbox NormanfinishGiveBracelet
	return

NormanGivesMB:
	.string "Ahh, by the way, {PLAYER},\n"
	.string "I got this for you, you should be\l"
	.string "strong enough to use it.$"

NormanfinishGiveBracelet:
	.string "While you have that item with\nyou, your Pokémon that have mega\pstones can mega-evolve in battle.\pMake good use of it!$"

norman1::
	msgbox PBG_AreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne PBG_NotReadyYet
	trainerbattle_single TRAINER_NORMAN_1, PG_Norman_Not4Badges_Intro, PetalburgCity_Gym_Text_NormanDefeat, PG_Reset
	release
	end

norman2::
	msgbox PBG_AreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne PBG_NotReadyYet
	trainerbattle_single TRAINER_NORMAN_2, PG_Norman_Not4Badges_Intro, PetalburgCity_Gym_Text_NormanDefeat, PG_Reset
	release
	end

norman3::
	trainerbattle_single TRAINER_NORMAN_3, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanDefeat, PG_Reset
	release
	end

norman4::
	call_if_set FLAG_RYU_DS_HAS_PARTNER, PG_PartnerQuery
	trainerbattle_single TRAINER_NORMAN_4, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanDefeat, PG_Reset
	release
	end
	
PG_PartnerQuery::
    msgbox RyuPartnerMultiText MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_eq PG_RelDialog
	goto PG_NoRelGymBattle
	return
	
	
PG_RelDialog::
	call RyuPartnerBattleMultichoice
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq PG_GymBattleIntroShelly
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq PG_GymBattleIntroDawn
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq PG_GymBattleIntroBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq PG_GymBattleIntroLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq PG_GymBattleIntroLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq PG_GymBattleIntroCourtney
	goto PG_NoRelGymBattle
	
PG_NoRelGymBattle::
	trainerbattle_single TRAINER_NORMAN_4, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanDefeat, PG_Reset
	release
	end
	
PG_NoRelationship1::
	msgbox Ryu_NOREL MSGBOX_DEFAULT
	closemessage
	goto PG_RelDialog
	
PG_GymBattleIntroShelly::
	msgbox Ryu_PlayerCalledShelly MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, PG_NoRelationship1
	addobject 11
	playse SE_DOOR
	applymovement 11, PG_PartnerEnter
	waitmovement 0
	msgbox PG_SHELLY_INTRO MSGBOX_DEFAULT
	goto PG_AltGymBattle
	
PG_GymBattleIntroLana::
	msgbox Ryu_PlayerCalledLana MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, PG_NoRelationship1
	addobject 13
	playse SE_DOOR
	applymovement 13, PG_PartnerEnter
	waitmovement 0
	msgbox PG_LANA_INTRO MSGBOX_DEFAULT
	goto PG_AltGymBattle
	
PG_GymBattleIntroDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, PG_NoRelationship1
	msgbox Ryu_PlayerCalledDawn MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 10
	playse SE_DOOR
	applymovement 10, PG_PartnerEnter
	waitmovement 0
	msgbox PG_DAWN_INTRO MSGBOX_DEFAULT
	goto PG_AltGymBattle
	
PG_GymBattleIntroBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, PG_NoRelationship1
	msgbox Ryu_PlayerCalledBrendan MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 12
	playse SE_DOOR
	applymovement 12, PG_PartnerEnter
	waitmovement 0
	msgbox PG_BRENDAN_INTRO MSGBOX_DEFAULT
	goto PG_AltGymBattle
	
PG_GymBattleIntroLanette::
	msgbox Ryu_PlayerCalledLanette MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, PG_NoRelationship1
	addobject 14
	playse SE_DOOR
	applymovement 14, PG_PartnerEnter
	waitmovement 14
	msgbox PG_LANETTE_INTRO MSGBOX_DEFAULT
	goto PG_AltGymBattle

PG_GymBattleIntroCourtney::
	goto_if_unset FLAG_RYU_DS_COURTNEY_PARTNERS, PG_NoRelationship1
	msgbox Ryu_PlayerCalledCourtney MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 15
	playse SE_DOOR
	applymovement 15, PG_PartnerEnter
	waitmovement 0
	msgbox PG_CourtneyPreBattleText MSGBOX_DEFAULT
	goto PG_AltGymBattle
	
PG_AltGymBattle::
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_MAGMA_MEMBER_F
	goto_if_eq PG_CourtneyAltGymBattle
	msgbox PG_PreBattleText MSGBOX_DEFAULT
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq PG_ChooseValidMons
	multi_2_vs_1 TRAINER_NORMAN_4, PG_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	delay 10
	goto PG_GymBattleEnd

PG_CourtneyAltGymBattle::
	msgbox PG_COURTNEY_INTRO MSGBOX_DEFAULT
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq PG_ChooseValidMons
	multi_2_vs_1 TRAINER_NORMAN_4, PG_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	delay 10
	goto PG_GymBattleEnd
	
PG_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto PG_AltGymBattle
	
PG_GymBattleEnd::
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq PG_GymBattleEndDawn
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq PG_GymBattleEndShelly
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq PG_GymBattleEndBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq PG_GymBattleEndLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq PG_GymBattleEndLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq PG_GymBattleEndCourtney
	release
	end
	
PG_GymBattleEndShelly::
	msgbox PG_ShellyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 11, PG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 11
	goto PG_Reset
	release
	end

PG_GymBattleEndDawn::
	msgbox PG_DawnGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 10, PG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 10
	goto PG_Reset
	release
	end
	
PG_GymBattleEndBrendan::
	msgbox PG_BrendanGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 12, PG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 12
	goto PG_Reset
	release
	end
	
PG_GymBattleEndLana::
	msgbox PG_LeafGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 13, PG_PartnerExit
	waitmovement 13
	playse SE_DOOR
	removeobject 13
	goto PG_Reset
	release
	end
	
PG_GymBattleEndLanette::
	msgbox PG_LanetteGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 14, PG_PartnerExit
	waitmovement 14
	playse SE_DOOR
	removeobject 14
	goto PG_Reset
	release
	end

PG_GymBattleEndCourtney::
	msgbox PG_CourtneyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 15, PG_PartnerExit
	waitmovement 15
	playse SE_DOOR
	removeobject 15
	goto PG_Reset
	release
	end
	
PG_PreBattleText:
    .string "Norman: Two challengers. Time for\n"
    .string "a double battle. You better have\l"
    .string "potions!$"

PG_CourtneyPreBattleText:
    .string "So... You're the one who corrupted\n"
    .string "my child...\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Not at all, In fact, {PLAYER} sought\n"
    .string "me out, and showed me a better life.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}I see... Well, I still can't approve.\n"
    .string "Let's see how close you really are!$"

PG_SHELLY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I didn't really expect to meet\nyour father this way, but battle is\las good a way as any, I guess.$"
	
PG_DAWN_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I've been wanting another crack\nat Norman since he beat me before.\pI bet we win this time!$"
	
PG_BRENDAN_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Best. Parent. Intro. Ever.\n"
    .string "Let's get it on!$"

PG_ALTTEXT1:
	.string "I'm quite proud of you, {PLAYER}!$"
	
PG_ShellyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Well, this was fun!\nNice to meet you, pops!$"
	
PG_LANA_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh, so your dad is a Gym\n"
    .string "Leader. Your strength makes sense\l"
    .string "now!$"
	
PG_LANETTE_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh... he's your father...\nUm... Hi...\p {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lanette looks at the floor)$"

PG_COURTNEY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}We do not need your approval.\nI never decline a challenge, though.$"
	
PG_DawnGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Ha! Got you this time!\nI knew you couldn't stand to both of us!\lSee you later, {PLAYER}!$"
	
PG_BrendanGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Ha! He's not so strong\n"
    .string "in a double battle.\l"
    .string "He can't beat our bond!$"
	
PG_LeafGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I can definetly see some of your\n"
    .string "dad's battle style in yours.$"
	
PG_LanetteGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Oh, that wasn't so bad\nNice to meet you!$"

PG_CourtneyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I hope you understand now.\nWe're inseperable.\pOf course, I don't care if you\napprove or not.$"
	
PG_DefeatText:
    .string "I didn't do enough damage...$"
	
PG_PartnerEnter:
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_up
	step_end
	
PG_FlanneryBackupEnter:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_down
	step_end

PG_PartnerExit:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_in_place_down
	step_end
	
PG_FlanneryLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_down
	step_end

PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough:: @ 820512D
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_SpeedRoomDoor:: @ 8205137
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_EnterRoom:: @ 820516C
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, 255, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_DontEnterRoom:: @ 820517B
	releaseall
	end

PetalburgCity_Gym_EventScript_DoorLocked:: @ 820517D
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
PetalburgCity_Gym_EventScript_AccuracyRoomDoor:: @ 8205187
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_ConfusionRoomDoor:: @ 82051BC
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor:: @ 82051EF
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightDefenseRoomDoor:: @ 8205222
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RecoveryRoomDoor:: @ 8205255
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor:: @ 8205288
	lockall
	checktrainerflag TRAINER_PARKER
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightStrengthRoomDoor:: @ 82052BB
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftOHKORoomDoor:: @ 82052EE
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightOHKORoomDoor:: @ 8205321
	lockall
	checktrainerflag TRAINER_GEORGE
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor:: @ 8205354
	lockall
	checktrainerflag TRAINER_JODY
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor:: @ 8205387
	lockall
	checktrainerflag TRAINER_BERKE
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_Randall:: @ 82053BA
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallPreBattle, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors:: @ 82053DE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_RandallPostBadge:: @ 82053ED
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker:: @ 82053F6
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerPreBattle, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors:: @ 820541A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge:: @ 8205429
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George:: @ 8205432
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgePreBattle, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors:: @ 8205456
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge:: @ 8205465
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke:: @ 820546E
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkePreBattle, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors:: @ 8205492
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_BerkePostBadge:: @ 82054A1
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary:: @ 82054AA
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryPreBattle, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors:: @ 82054CE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_MaryPostBadge:: @ 82054DD
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia:: @ 82054E6
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaPreBattle, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors:: @ 820550A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge:: @ 8205519
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody:: @ 8205522
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyPreBattle, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors:: @ 8205546
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_JodyPostBadge:: @ 8205555
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

@ VAR_0x8004 below is the room number
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors:: @ 820555E
	setvar VAR_0x8004, 1
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors:: @ 820557F
	setvar VAR_0x8004, 2
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors:: @ 82055A0
	setvar VAR_0x8004, 3
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors:: @ 82055C1
	setvar VAR_0x8004, 4
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors:: @ 82055E2
	setvar VAR_0x8004, 5
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors:: @ 8205603
	setvar VAR_0x8004, 6
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors:: @ 8205624
	setvar VAR_0x8004, 7
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenOHKORoomDoors:: @ 8205645
	setvar VAR_0x8004, 8
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles:: @ 8205666
	return

PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles:: @ 820568B
	return

PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles:: @ 82056B0
	return

PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles:: @ 82056D5
	return

PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles:: @ 82056E8
	return

PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles:: @ 820570D
	return

PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles:: @ 8205720
	return

PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles:: @ 8205733
	return

PetalburgCity_Gym_EventScript_SlideOpenRoomDoors:: @ 8205746
	return

PetalburgCity_Gym_EventScript_UnlockRoomDoors:: @ 820574B
	return

PetalburgCity_Gym_EventScript_GymGuide:: @ 820574F
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GymGuidePostVictory:: @ 8205764
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_LeftGymStatue:: @ 820576E
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_RightGymStatue:: @ 820577E
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_GymStatueCertified:: @ 820578E
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_GymStatue:: @ 8205798
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon: @ 82057A2
	.string "DAD: Hm?\p"
	.string "Well, if it isn't {PLAYER}!\n"
	.string "So you're all finished moving in?\p"
	.string "I'm surprised that you managed to\n"
	.string "get here by yourself.\p"
	.string "Oh, I see.\n"
	.string "You're with your Pokémon.\p"
	.string "Hm… Then I guess you're going to\n"
	.string "become a Trainer like me, {PLAYER}.\p"
	.string "That's great news!\n"
	.string "I'll be looking forward to it!$"

PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall: @ 8205A89
	.string "WALLY: Oh, wow!\n"
	.string "A Pokémon!\p"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
	.string "Go for it!\p"
	.string "WALLY received a POKé BALL!$"

PetalburgCity_Gym_Text_WallyOhWowThankYou: @ 8205AF4
	.string "WALLY: Oh, wow!\n"
	.string "Thank you!$"

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe: @ 8205B0F
	.string "{PLAYER}… Would you really come\n"
	.string "with me?$"

PetalburgCity_Gym_Text_DadSoDidItWorkOut: @ 8205B32
	.string "DAD: So, did it work out?$"

PetalburgCity_Gym_Text_WallyThankYouBye: @ 8205B4C
	.string "WALLY: Thank you, yes, it did.\n"
	.string "Here's your Pokémon back.\p"
	.string "{PLAYER}, thank you for coming along\n"
	.string "with me.\p"
	.string "You two are why I was able to catch\n"
	.string "my Pokémon.\p"
	.string "I promise I'll take really good\n"
	.string "care of it.\p"
	.string "Oh! My mom's waiting for me,\n"
	.string "so I have to go!\p"
	.string "Bye, {PLAYER}!$"

PetalburgCity_Gym_Text_DadGoCollectBadges: @ 8205C40
	.string "DAD: Now…\p"
	.string "{PLAYER}, if you want to become a\n"
	.string "strong Trainer, here's my advice.\p"
	.string "Head for RUSTBORO CITY beyond this\n"
	.string "town.\p"
	.string "There, you should challenge\n"
	.string "the Gym Leader, Roxanne.\p"
	.string "After her, go on to other Pokémon\n"
	.string "Gyms and defeat their LEADERS.\p"
	.string "Collect badges from them,\n"
	.string "understood?\p"
	.string "Of course, I'm a Gym Leader, too.\n"
	.string "We'll battle one day, {PLAYER}.\p"
	.string "But that's only after you become\n"
	.string "stronger.$"

PetalburgCity_Gym_Text_NormanGoToRustboro: @ 8205DB4
	.string "DAD: Hm? Aren't you going to the\n"
	.string "Pokémon Gym in RUSTBORO CITY?\p"
	.string "There's no challenge for me to\n"
	.string "battle a greenhorn Trainer.\p"
	.string "{PLAYER}, I want you to challenge me\n"
	.string "when you become a lot stronger.\p"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "can show me four Gym Badges, okay?$"

PetalburgCity_Gym_Text_NormanGoToDewford: @ 8205EAE
	.string "DAD: I see… So, you've beaten\n"
	.string "the Gym Leader in RUSTBORO CITY.\p"
	.string "But there are many more Trainers\n"
	.string "who are stronger than you, {PLAYER}.\p"
	.string "Across the sea in DEWFORD TOWN is a\n"
	.string "Gym Leader named Brawly.\p"
	.string "You should go challenge him.$"

PetalburgCity_Gym_Text_YouHaveGottenStronger: @ 8205F87
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
	.string "stronger.\p"
	.string "I can tell by the number of badges\n"
	.string "that you've earned.$"

PetalburgCity_Gym_Text_NormanPreBattle: @ 8205FE5
	.string "{PLAYER}…\p"
	.string "I'm so happy that I can have\n"
	.string "a real battle with my own child.\p"
	.string "But, a battle is a battle!\p"
	.string "I will do everything in my power as\n"
	.string "a Gym Leader to win.\p"
	.string "{PLAYER}, you'd better give it your\n"
	.string "best shot, too!$"

PetalburgCity_Gym_Text_NormanDefeat: @ 8206107
	.string "…\p"
	.string "I… I can't…\p"
	.string "I can't believe it. {PLAYER}…\p"
	.string "I lost to {PLAYER}?\p"
	.string "But, rules are rules!$"

PetalburgCity_Gym_Text_ReceivedBalanceBadge: @ 8206162
	.string "{PLAYER} received the BALANCE badge\n"
	.string "from DAD!$"

PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis: @ 820618A
	.string "DAD: With that badge, the DEFENSE\n"
	.string "of all your Pokémon will increase.\p"
	.string "Pokémon that know the HM move SURF\n"
	.string "will be able to travel over water.\p"
	.string "This is my gift to you. {PLAYER}, I'm\n"
	.string "sure you can use it correctly.$"

PetalburgCity_Gym_Text_ExplainFacade: @ 8206254
	.string "DAD: TM42 contains FACADE.\p"
	.string "It doubles the power of moves if\n"
	.string "the Pokémon is poisoned, paralyzed,\l"
	.string "or burned.\p"
	.string "It might be able to turn a bad\n"
	.string "situation into an advantage.$"

PetalburgCity_Gym_Text_DadHappyAndSad: @ 82062FB
	.string "DAD: As the Gym Leader, I can't\n"
	.string "express how upset I am…\p"
	.string "But as a father, it makes me both\n"
	.string "happy and a little sad. It's odd…$"

PetalburgCity_Gym_Text_PleaseComeWithMe: @ 8206377
	.string "Ah, there you are, {PLAYER}!\p"
	.string "Please come with me.\n"
	.string "I have something I want you to have.$"

PetalburgCity_Gym_Text_LetMeBorrowPlayer: @ 82063CA
	.string "Norman, you don't mind, do you?\p"
	.string "Let me borrow your {PLAYER} for\n"
	.string "a minute or two.$"

PetalburgCity_Gym_Text_DadGoingToKeepTraining: @ 8206417
	.string "DAD: {PLAYER}, you should go visit\n"
	.string "your mother every so often.\p"
	.string "I'm going to stay here and redouble\n"
	.string "my training.\p"
	.string "It would bother me as a Trainer to\n"
	.string "not avenge my loss to you, {PLAYER}!$"

PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough: @ 82064C3
	.string "DAD: {PLAYER}, how are things going?\p"
	.string "The world of Pokémon is deep.\p"
	.string "I honestly think that no amount of\n"
	.string "training would ever be enough.$"

PetalburgCity_Gym_Text_GymGuideAdvice: @ 8206542
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "The doors in this Gym open when you\n"
	.string "beat the awaiting Trainers.\p"
	.string "Whoops! The doors in this room are\n"
	.string "already open, so don't attack me!\p"
	.string "The Trainers of PETALBURG Gym\n"
	.string "use all kinds of items.\p"
	.string "The door at the left leads to\n"
	.string "the SPEED ROOM.\p"
	.string "The door at the right leads to\n"
	.string "the ACCURACY ROOM.\p"
	.string "The room's name will be on\n"
	.string "the door, so choose carefully.\p"
	.string "Once you've chosen the door…\n"
	.string "Well, hey, go for it!$"

PetalburgCity_Gym_Text_GymGuidePostVictory: @ 82066F3
	.string "{PLAYER}! Whoa! You've overcome even\n"
	.string "your own father!\p"
	.string "Like, whoa!\n"
	.string "What a stunning turn of events!$"

PetalburgCity_Gym_Text_RandallPreBattle: @ 820674F
	.string "The ability to attack before the\n"
	.string "opponent…\p"
	.string "Just that alone puts me at a great\n"
	.string "advantage, don't you agree?$"

PetalburgCity_Gym_Text_RandallDefeat: @ 82067B9
	.string "That was a magnificent battle!$"

PetalburgCity_Gym_Text_RandallPostBattle: @ 82067D8
	.string "Go on to the next room where a new\n"
	.string "challenge awaits you.\p"
	.string "At the left is the CONFUSION ROOM.\p"
	.string "The right door leads to the DEFENSE\n"
	.string "ROOM.$"

PetalburgCity_Gym_Text_RandallPostBadge: @ 820685E
	.string "Whomever you beat, and whomever you\n"
	.string "may lose to, you never shirk from\l"
	.string "training yourself and your Pokémon.\p"
	.string "That's what I think being a\n"
	.string "Gym Leader is all about.$"

PetalburgCity_Gym_Text_ParkerPreBattle: @ 82068FD
	.string "This is the CONFUSION ROOM.\p"
	.string "Let me see how well bonded you are\n"
	.string "with your Pokémon!$"

PetalburgCity_Gym_Text_ParkerDefeat: @ 820694F
	.string "I couldn't confuse your team enough…\n"
	.string "You share a strong bond together.$"

PetalburgCity_Gym_Text_ParkerPostBattle: @ 8206996
	.string "The next room is the STRENGTH ROOM.\n"
	.string "Can you withstand brute force?$"

PetalburgCity_Gym_Text_ParkerPostBadge: @ 82069D9
	.string "After you beat our LEADER, the\n"
	.string "training has become a lot tougher.$"

PetalburgCity_Gym_Text_GeorgePreBattle: @ 8206A1B
	.string "Just when you think you're going to\n"
	.string "win, your opponent restores HP…\p"
	.string "Can you just imagine how awful that\n"
	.string "must feel?\p"
	.string "I'll show you exactly how awful it\n"
	.string "feels!$"

PetalburgCity_Gym_Text_GeorgeDefeat: @ 8206AB8
	.string "I couldn't restore HP enough…\n"
	.string "What ATTACK power…$"

PetalburgCity_Gym_Text_GeorgePostBattle: @ 8206AE9
	.string "I should have expected no less from\n"
	.string "our LEADER's kid.\p"
	.string "No, wait! A Trainer's abilities are\n"
	.string "earned only through effort.\p"
	.string "I lost because my own efforts\n"
	.string "weren't enough.\p"
	.string "Go on! The ONE-HIT KO ROOM is next.$"

PetalburgCity_Gym_Text_GeorgePostBadge: @ 8206BB1
	.string "I'm going to keep training at Gyms.\n"
	.string "One day, I'll become a LEADER.$"

PetalburgCity_Gym_Text_BerkePreBattle: @ 8206BF4
	.string "I'm not going to take it easy just\n"
	.string "because you're our LEADER's kid.\p"
	.string "I'll show you how horrid it is for\n"
	.string "a Pokémon to take a critical hit!$"

PetalburgCity_Gym_Text_BerkeDefeat: @ 8206C7D
	.string "Your power…\n"
	.string "You're the real deal.$"

PetalburgCity_Gym_Text_BerkePostBattle: @ 8206C9F
	.string "Your father really is strong.\n"
	.string "He's a Trainer worth my respect.\p"
	.string "And, I sense the same glow coming\n"
	.string "from you as your father.\p"
	.string "I hope that you'll stage a terrific\n"
	.string "battle with your father!$"

PetalburgCity_Gym_Text_BerkePostBadge: @ 8206D56
	.string "Since your dad became the LEADER,\n"
	.string "the Trainers of PETALBURG CITY have\l"
	.string "become a lot tougher.$"

PetalburgCity_Gym_Text_MaryPreBattle: @ 8206DB2
	.string "Giggle…\n"
	.string "This is the ACCURACY ROOM.\p"
	.string "It's pretty nasty when every attack\n"
	.string "lands without fail.$"

PetalburgCity_Gym_Text_MaryDefeat: @ 8206E0D
	.string "You were a cut above me…$"

PetalburgCity_Gym_Text_MaryPostBattle: @ 8206E26
	.string "There are some even stronger\n"
	.string "Trainers waiting for you.\p"
	.string "The left is the DEFENSE ROOM, and\n"
	.string "the right is the RECOVERY ROOM.\p"
	.string "Your Pokémon's ATTACK power will be\n"
	.string "on trial either way.$"

PetalburgCity_Gym_Text_MaryPostBadge: @ 8206ED8
	.string "Do you know what we're trying to\n"
	.string "achieve as Trainers?\p"
	.string "We're striving to become soul mates\n"
	.string "with our Pokémon.$"

PetalburgCity_Gym_Text_AlexiaPreBattle: @ 8206F44
	.string "The higher the DEFENSE, the more\n"
	.string "reckless I can be in attack.$"

PetalburgCity_Gym_Text_AlexiaDefeat: @ 8206F82
	.string "Our defenses weren't enough…$"

PetalburgCity_Gym_Text_AlexiaPostBattle: @ 8206F9F
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "Now, go on! The left door goes to\n"
	.string "the STRENGTH ROOM.\p"
	.string "The right door opens to\n"
	.string "the ONE-HIT KO ROOM.\p"
	.string "Both of them have Trainers who are\n"
	.string "skilled at offense.$"

PetalburgCity_Gym_Text_AlexiaPostBadge: @ 8207069
	.string "Hi! Have you tried using SURF?$"

PetalburgCity_Gym_Text_JodyPreBattle: @ 8207088
	.string "Our Gym Leader told us to go all out\n"
	.string "and beat you.\p"
	.string "Even if you happen to be the\n"
	.string "LEADER's kid!$"

PetalburgCity_Gym_Text_JodyDefeat: @ 82070E6
	.string "But… I went all out!$"

PetalburgCity_Gym_Text_JodyPostBattle: @ 82070FB
	.string "The way you use your Pokémon…\n"
	.string "It's like your father's style.\p"
	.string "Go on through! The Gym Leader, your\n"
	.string "father, is waiting!$"

PetalburgCity_Gym_Text_JodyPostBadge: @ 8207170
	.string "Sure, it's fine to make your Pokémon\n"
	.string "stronger.\p"
	.string "But what decides the winner?\p"
	.string "Why, it's the feelings Trainers have\n"
	.string "for their Pokémon.$"

PetalburgCity_Gym_Text_DoorAppearsLocked: @ 82071F4
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_Text_EnterSpeedRoom: @ 820721E
	.string "“SPEED ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

@ Unused
PetalburgCity_Gym_Text_DoorAppearsLocked2: @ 8207256
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_Text_EnterAccuracyRoom: @ 8207280
	.string "“ACCURACY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterConfusionRoom: @ 82072BB
	.string "“CONFUSION ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterDefenseRoom: @ 82072F7
	.string "“DEFENSE ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterRecoveryRoom: @ 8207331
	.string "“RECOVERY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterStrengthRoom: @ 820736C
	.string "“STRENGTH ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterOHKORoom: @ 82073A7
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterGymLeadersRoom: @ 82073E4
	.string "“Gym Leader's ROOM\p"
	.string "“See for yourself what Pokémon await\n"
	.string "you!” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_GymStatue: @ 820744C
	.string "PETALBURG CITY Pokémon Gym$"

PetalburgCity_Gym_Text_GymStatueCertified: @ 8207467
	.string "PETALBURG CITY Pokémon Gym\p"
	.string "Norman's Certified Trainers:\n"
	.string "{PLAYER}$"

PG_Norman_Not4Badges_Intro:
    .string "I may have gotten older, but I can\n"
    .string "still teach you a lesson\p"
    .string "LET'S DO THIS!$"

PetalburgCity_Gym_Text_NormanPreRematch: @ 82074A2
	.string "{PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a Gym, it doesn't matter that\n"
	.string "we are family.\p"
	.string "…No, because we are family,\n"
	.string "we owe it to each other to do the best\l"
	.string "we can. Isn't that right, {PLAYER}?$"

PetalburgCity_Gym_Text_NormanRematchDefeat: @ 82075CE
	.string "Uh… Haha…\n"
	.string "Maybe that was going too hard…$"

PetalburgCity_Gym_Text_NormanPostRematch: @ 82075F7
	.string "{PLAYER}…\n"
	.string "What is your dream?\p"
	.string "My dream…\n"
	.string "Hahaha…\l"
	.string "It has already come true, actually.$"

PetalburgCity_Gym_Text_NormanRematchNeedTwoMons: @ 820764A
	.string "{PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a Gym, it doesn't matter that\n"
	.string "we are a parent and child.\p"
	.string "Hm? Wait a second, {PLAYER}.\p"
	.string "Do you only have one Pokémon that is\n"
	.string "capable of battle?\p"
	.string "Sorry, but you'll have to come back\n"
	.string "with at least two Pokémon.$"

