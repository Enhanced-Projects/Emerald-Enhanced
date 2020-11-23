.set LOCALID_NORMAN, 1

PetalburgCity_Gym_MapScripts:: @ 8204889
	map_script ON_FRAME, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnFrame: @ 820499A
	map_script_2 VAR_TEMP_1, 0, PetalburgCity_Gym_CheckNormanState
	map_script_2 VAR_TEMP_4, 0, PBG_CheckDoors
	.2byte 0

PetalburgCity_Gym_CheckNormanState::
	setvar VAR_TEMP_1, 10
	special checkbadgecount
	compare VAR_RESULT, 4
	goto_if_lt PBG_MoveNormanSouth
	end

PBG_MoveNormanSouth::
	setobjectxy 1, 4, 106
	special DrawWholeMapView
	release
	end

PBG_NEWGYMBATTLE::
	lock
	faceplayer
	setflag FLAG_RYU_BOSS_SCALE
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
	setvar VAR_PETALBURG_GYM_STATE, 10
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
	cleartrainerflag TRAINER_NORMAN_1
	cleartrainerflag TRAINER_NORMAN_2
	cleartrainerflag TRAINER_NORMAN_3
	cleartrainerflag TRAINER_NORMAN_4
	clearflag FLAG_RYU_BOSS_SCALE
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
	goto_if_set FLAG_RYU_HAS_FOLLOWER, PG_FollowerMatch
	call_if_set FLAG_RYU_DS_HAS_PARTNER, PG_PartnerQuery
	trainerbattle_single TRAINER_NORMAN_4, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanDefeat, PG_Reset
	release
	end
	
PG_PartnerQuery::
    msgbox RyuPartnerMultiText MSGBOX_YESNO
	compare VAR_RESULT, 1
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
	compare VAR_0x8008, TRAINER_REL_NURSE
	goto_if_eq PG_GymBattleIntroJoy
	goto PG_NoRelGymBattle
	
PG_NoRelGymBattle::
	trainerbattle_single TRAINER_NORMAN_4, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanDefeat, PG_Reset
	release
	end

PG_FollowerMatch::
	msgbox PetalburgCity_Gym_Text_NormanPreRematch
	closemessage
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq PG_ChooseValidMons
	multi_2_vs_1 TRAINER_NORMAN_4, PetalburgCity_Gym_Text_NormanDefeat, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto PG_Reset
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

PG_GymBattleIntroJoy::
	goto_if_unset FLAG_RYU_DS_JOY_PARTNERS, PG_NoRelationship1
	msgbox Ryu_PlayerCalledJoy MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 16
	playse SE_DOOR
	applymovement 16, PG_PartnerEnter
	waitmovement 0
	msgbox PG_JOY_INTRO MSGBOX_DEFAULT
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
	goto_if_set FLAG_RYU_HAS_FOLLOWER, PG_FollowerMatch
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

PG_GymBattleEndJoy::
	msgbox PG_JoyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 16, PG_PartnerExit
	waitmovement 16
	playse SE_DOOR
	removeobject 16
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

PG_JOY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED} Oh! Wow! Your father's a Gym\nLeader!\pI didn't know that!\pSo that's where your strength\ncomes from$"
	
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

PG_JoyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Yes, I can definitely see it.\nNice to meet you again!$"
	
PG_DefeatText:
    .string "I didn't do enough damage...$"
	
PG_PartnerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end


PG_PartnerExit:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PBG_UpdateVar:
	goto_if_set FLAG_BADGE05_GET, PBG_SetVar10
	checktrainerflag TRAINER_JODY
	call_if_eq PBG_SetVar2
	checktrainerflag TRAINER_BERKE
	call_if_eq PBG_SetVar3
	checktrainerflag TRAINER_PARKER
	call_if_eq PBG_SetVar4
	checktrainerflag TRAINER_ALEXIA
	call_if_eq PBG_SetVar5
	checktrainerflag TRAINER_GEORGE
	call_if_eq PBG_SetVar6
	checktrainerflag TRAINER_RANDALL
	call_if_eq PBG_SetVar7
	checktrainerflag TRAINER_MARY
	call_if_eq PBG_SetVar8
	call_if_set FLAG_RYU_PLAYER_CLEARED_PBG_DOORS, PBG_SetVar9
	goto PBG_CheckDoors

PBG_SetVar2:
	compare VAR_PETALBURG_GYM_STATE, 2
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 2
	return

PBG_SetVar3:
	compare VAR_PETALBURG_GYM_STATE, 3
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 3
	return

PBG_SetVar4:
	compare VAR_PETALBURG_GYM_STATE, 4
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 4
	return

PBG_SetVar5:
	compare VAR_PETALBURG_GYM_STATE, 5
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 5
	return

PBG_SetVar6:
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 6
	return

PBG_SetVar7:
	compare VAR_PETALBURG_GYM_STATE, 7
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PBG_SetVar8:
	compare VAR_PETALBURG_GYM_STATE, 8
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 8
	return

PBG_SetVar9:
	compare VAR_PETALBURG_GYM_STATE, 9
	goto_if_eq ryu_return
	setvar VAR_PETALBURG_GYM_STATE, 9
	return

PBG_SetVar10:
	setvar VAR_PETALBURG_GYM_STATE, 10
	end

PBG_CheckDoors::
	setvar VAR_TEMP_4, 10
	switch VAR_PETALBURG_GYM_STATE
	case 10, PBG_FinalDoor
	case 2, PBG_FirstDoor
	case 3, PBG_SecondDoor
	case 4, PBG_ThirdDoor
	case 5, PBG_FourthDoor
	case 6, PBG_FifthDoor
	case 7, PBG_SixthDoor
	case 8, PBG_SeventhDoor
	case 9, PBG_FinalDoor
	end

PBG_FinalDoor::                @@Theoretically, since none of these have terminators except the last one, each one should also
	setmetatile 16, 21, 645, 0 @@execute each one that follows, thus opening all doors up to the number called. Fancy script magic.
PBG_SeventhDoor::
	setmetatile 10, 25, 639, 0
	setmetatile 10, 26, 647, 0
PBG_SixthDoor::
	setmetatile 4, 21, 645, 0
PBG_FifthDoor::
	setmetatile 4, 10, 645, 0
PBG_FourthDoor::
	setmetatile 10, 3, 639, 0
	setmetatile 10, 4, 647, 0
PBG_ThirdDoor::
	setmetatile 22, 3, 639, 0
	setmetatile 22, 4, 647, 0
PBG_SecondDoor::
	setmetatile 28, 10, 645, 0
PBG_FirstDoor::
	setmetatile 28, 21, 645, 0
	special DrawWholeMapView
	playse SE_DOOR
	end
	

PetalburgCity_Gym_EventScript_Randall:: @ 82053BA
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallPreBattle, PetalburgCity_Gym_Text_RandallDefeat, PBG_UpdateVar
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_RandallPostBadge:: @ 82053ED
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker:: @ 82053F6
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerPreBattle, PetalburgCity_Gym_Text_ParkerDefeat, PBG_UpdateVar
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge:: @ 8205429
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George:: @ 8205432
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgePreBattle, PetalburgCity_Gym_Text_GeorgeDefeat, PBG_UpdateVar
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge:: @ 8205465
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke:: @ 820546E
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkePreBattle, PetalburgCity_Gym_Text_BerkeDefeat, PBG_UpdateVar
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_BerkePostBadge:: @ 82054A1
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary:: @ 82054AA
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryPreBattle, PetalburgCity_Gym_Text_MaryDefeat, PBG_UpdateVar
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_MaryPostBadge:: @ 82054DD
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia:: @ 82054E6
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaPreBattle, PetalburgCity_Gym_Text_AlexiaDefeat, PBG_UpdateVar
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge:: @ 8205519
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody:: @ 8205522
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyPreBattle, PetalburgCity_Gym_Text_JodyDefeat, PBG_UpdateVar
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_JodyPostBadge:: @ 8205555
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

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

PetalburgCity_Gym_Text_NormanDefeat: @ 8206107
	.string "…\p"
	.string "I… I can't…\p"
	.string "I can't believe it. {PLAYER}…\p"
	.string "I lost to {PLAYER}?\p"
	.string "But, rules are rules!$"

PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough: @ 82064C3
	.string "Dad: {PLAYER}, how are things going?\p"
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
	.string "The Trainers of Petalburg Gym\n"
	.string "use all kinds of items.\p"
	.string "The door at the left leads to\n"
	.string "the Speed Room.\p"
	.string "The door at the right leads to\n"
	.string "the Accuracy Room.\p"
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
	.string "At the left is the Confusion Room.\p"
	.string "The right door leads to the Defense\n"
	.string "Room.$"

PetalburgCity_Gym_Text_RandallPostBadge: @ 820685E
	.string "Whomever you beat, and whomever you\n"
	.string "may lose to, you never shirk from\l"
	.string "training yourself and your Pokémon.\p"
	.string "That's what I think being a\n"
	.string "Gym Leader is all about.$"

PetalburgCity_Gym_Text_ParkerPreBattle: @ 82068FD
	.string "This is the Confusion Room.\p"
	.string "Let me see how well bonded you are\n"
	.string "with your Pokémon!$"

PetalburgCity_Gym_Text_ParkerDefeat: @ 820694F
	.string "I couldn't confuse your team enough…\n"
	.string "You share a strong bond together.$"

PetalburgCity_Gym_Text_ParkerPostBattle: @ 8206996
	.string "The next room is the Strength Room.\n"
	.string "Can you withstand brute force?$"

PetalburgCity_Gym_Text_ParkerPostBadge: @ 82069D9
	.string "After you beat our Leader, the\n"
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
	.string "What Attack power…$"

PetalburgCity_Gym_Text_GeorgePostBattle: @ 8206AE9
	.string "I should have expected no less from\n"
	.string "our Leader's kid.\p"
	.string "No, wait! A Trainer's abilities are\n"
	.string "earned only through effort.\p"
	.string "I lost because my own efforts\n"
	.string "weren't enough.\p"
	.string "Go on! The ONE-HIT KO Room is next.$"

PetalburgCity_Gym_Text_GeorgePostBadge: @ 8206BB1
	.string "I'm going to keep training at Gyms.\n"
	.string "One day, I'll become a Leader.$"

PetalburgCity_Gym_Text_BerkePreBattle: @ 8206BF4
	.string "I'm not going to take it easy just\n"
	.string "because you're our Leader's kid.\p"
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
	.string "Since your dad became the Leader,\n"
	.string "the Trainers of Petalburg City have\l"
	.string "become a lot tougher.$"

PetalburgCity_Gym_Text_MaryPreBattle: @ 8206DB2
	.string "Giggle…\n"
	.string "This is the Accuracy Room.\p"
	.string "It's pretty nasty when every attack\n"
	.string "lands without fail.$"

PetalburgCity_Gym_Text_MaryDefeat: @ 8206E0D
	.string "You were a cut above me…$"

PetalburgCity_Gym_Text_MaryPostBattle: @ 8206E26
	.string "There are some even stronger\n"
	.string "Trainers waiting for you.\p"
	.string "The left is the Defense Room, and\n"
	.string "the right is the Recovery Room.\p"
	.string "Your Pokémon's Attack power will be\n"
	.string "on trial either way.$"

PetalburgCity_Gym_Text_MaryPostBadge: @ 8206ED8
	.string "Do you know what we're trying to\n"
	.string "achieve as Trainers?\p"
	.string "We're striving to become soul mates\n"
	.string "with our Pokémon.$"

PetalburgCity_Gym_Text_AlexiaPreBattle: @ 8206F44
	.string "The higher the Defense, the more\n"
	.string "reckless I can be in attack.$"

PetalburgCity_Gym_Text_AlexiaDefeat: @ 8206F82
	.string "Our defenses weren't enough…$"

PetalburgCity_Gym_Text_AlexiaPostBattle: @ 8206F9F
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "Now, go on! The left door goes to\n"
	.string "the Strength Room.\p"
	.string "The right door opens to\n"
	.string "the ONE-HIT KO Room.\p"
	.string "Both of them have Trainers who are\n"
	.string "skilled at offense.$"

PetalburgCity_Gym_Text_AlexiaPostBadge: @ 8207069
	.string "Hi! Have you tried using Surf?$"

PetalburgCity_Gym_Text_JodyPreBattle: @ 8207088
	.string "Our Gym Leader told us to go all out\n"
	.string "and beat you.\p"
	.string "Even if you happen to be the\n"
	.string "Leader's kid!$"

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

PetalburgCity_Gym_Text_GymStatue: @ 820744C
	.string "Petalburg City Pokémon Gym$"

PetalburgCity_Gym_Text_GymStatueCertified: @ 8207467
	.string "Petalburg City Pokémon Gym\p"
	.string "Norman's Certified Trainers:\n"
	.string "{PLAYER}$"

PG_Norman_Not4Badges_Intro:
    .string "I may have gotten older, but I can\n"
    .string "still teach you a lesson\p"
    .string "Let's do this!$"

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

@=============================================================================Quizzes

PBG_Door1Question::
	msgbox PBG_Quiz1, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES @put the correct answer, YES or NO here, it goes to the success script.
	goto_if_eq PBG_Quiz1Success
	playse SE_FAILURE
	waitse
	applymovement 7, Common_Movement_FaceUp
	waitmovement 7
	goto PetalburgCity_Gym_EventScript_Jody

PBG_Quiz1Success::
	playse SE_SUCCESS
	call PBG_SetVar2
	goto PBG_UpdateVar
	release
	end

PBG_Door2Question::
	msgbox PBG_Quiz2, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES @put the correct answer, YES or NO here, it goes to the success script.
	goto_if_eq PBG_Quiz2Success
	playse SE_FAILURE
	waitse
	applymovement 8, Common_Movement_FaceUp
	waitmovement 8
	goto PetalburgCity_Gym_EventScript_Berke

PBG_Quiz2Success::
	playse SE_SUCCESS
	call PBG_SetVar3
	goto PBG_UpdateVar
	release
	end

PBG_Door3Question::
	msgbox PBG_Quiz3, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES @put the correct answer, YES or NO here, it goes to the success script.
	goto_if_eq PBG_Quiz3Success
	playse SE_FAILURE
	waitse
	applymovement 4, ParkerToPlayer
	waitmovement 4
	goto PetalburgCity_Gym_EventScript_Parker

ParkerToPlayer:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

PBG_Quiz3Success::
	playse SE_SUCCESS
	call PBG_SetVar4
	goto PBG_UpdateVar
	release
	end

PBG_Door4Question::
	msgbox PBG_Quiz4
	multichoicegrid 6, 8, MULTI_PBG_TRICK_QUESTION, 2, 1
	closemessage
	delay 5
	goto PBG_Quiz4Success

PBG_Quiz4Success::
	playse SE_SUCCESS
	call PBG_SetVar5
	goto PBG_UpdateVar
	release
	end
 
PBG_Door5Question::
	msgbox PBG_Quiz5, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES @put the correct answer, YES or NO here, it goes to the success script.
	goto_if_eq PBG_Quiz5Success
	playse SE_FAILURE
	waitse
	applymovement 6, PBG_GeorgeToPlayer
	waitmovement 6
	goto PetalburgCity_Gym_EventScript_George

PBG_GeorgeToPlayer:
	walk_down
	walk_down
	walk_down
	step_end

PBG_Quiz5Success::
	playse SE_SUCCESS
	call PBG_SetVar6
	goto PBG_UpdateVar
	release
	end

PBG_Door6Question::
	msgbox PBG_Quiz6, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES @put the correct answer, YES or NO here, it goes to the success script.
	goto_if_eq PBG_Quiz6Success
	playse SE_FAILURE
	waitse
	applymovement 3, PBG_GeorgeToPlayer
	waitmovement 3
	goto PetalburgCity_Gym_EventScript_Randall

PBG_Quiz6Success::
	playse SE_SUCCESS
	call PBG_SetVar7
	goto PBG_UpdateVar
	release
	end

PBG_Door7Question::
	msgbox PBG_Quiz7, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES @put the correct answer, YES or NO here, it goes to the success script.
	goto_if_eq PBG_Quiz7Success
	playse SE_FAILURE
	waitse
	applymovement 2, PBG_MaryToPlayer
	waitmovement 2
	goto PetalburgCity_Gym_EventScript_Mary

PBG_MaryToPlayer:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PBG_Quiz7Success::
	playse SE_SUCCESS
	call PBG_SetVar8
	goto PBG_UpdateVar
	release
	end

PBG_Door8Question::
	compare VAR_PETALBURG_GYM_STATE, 8
	goto_if_lt ryu_end  @@Assures that the player can't interact with gym leader door until they clear all the other doors.
	msgbox PBG_Quiz8, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES @put the correct answer, YES or NO here, it goes to the success script.
	goto_if_eq PBG_Quiz8Success
	playse SE_FAILURE
	waitse
	release
	end

PBG_Quiz8Success::
	playse SE_SUCCESS
	buffernumberstring 0, VAR_PETALBURG_GYM_STATE
	msgbox PBGDB_Msg
	closemessage
	setflag FLAG_RYU_PLAYER_CLEARED_PBG_DOORS
	call PBG_SetVar9
	goto PBG_UpdateVar
	release
	end

PBGDB_Msg:
	.string "{STR_VAR_1}$"

PBG_Quiz1::
	.string "YesNo Question Here.$"

PBG_Quiz2::
	.string "YesNo Question Here.$"

PBG_Quiz3::
	.string "YesNo Question Here.$"

PBG_Quiz4::
	.string "Which pokemon was the first?$"

PBG_Quiz5::
	.string "YesNo Question Here.$"

PBG_Quiz6::
	.string "YesNo Question Here.$"

PBG_Quiz7::
	.string "YesNo Question Here.$"

PBG_Quiz8::
	.string "YesNo Question Here.$"

