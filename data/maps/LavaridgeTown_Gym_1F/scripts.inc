LavaridgeTown_Gym_1F_MapScripts:: @ 81FE6F4
	map_script ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition: @ 81FE6FA
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckHideTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars:: @ 81FE705
	checktrainerflag TRAINER_COLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar:: @ 81FE72C
	checktrainerflag TRAINER_GERALD
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar:: @ 81FE73A
	checktrainerflag TRAINER_AXLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar:: @ 81FE748
	checktrainerflag TRAINER_DANIELLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars:: @ 81FE756
	return

LavaridgeTown_Gym_1F_EventScript_CheckHideTrainers:: @ 81FE757
	checktrainerflag TRAINER_COLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_CheckHideGerald
	setobjectmovementtype 2, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_1F_EventScript_CheckHideGerald:: @ 81FE764
	checktrainerflag TRAINER_GERALD
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_CheckHideAxle
	setobjectmovementtype 3, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_1F_EventScript_CheckHideAxle:: @ 81FE771
	checktrainerflag TRAINER_AXLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_CheckHideDanielle
	setobjectmovementtype 4, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_1F_EventScript_CheckHideDanielle:: @ 81FE77E
	checktrainerflag TRAINER_DANIELLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_EndCheckHideTrainers
	setobjectmovementtype 5, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_1F_EventScript_EndCheckHideTrainers:: @ 81FE78B
	return

LavaridgeTown_Gym_1F_EventScript_Flannery:: @ 81FE78C
	lock
	setflag FLAG_RYU_ALTERNATE_SCALE
	special checkbadgecount
    switch VAR_RESULT
	case 0, FLANNERY1
	case 1, FLANNERY1
	case 2, FLANNERY1
	case 3, FLANNERY2
	case 4, FLANNERY2
	case 5, FLANNERY3
	case 6, FLANNERY3
	case 7, FLANNERY4
	case 8, FLANNERY4
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated:: @ 81FE7C1
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	release
	end
	
LG_Reset::
	setvar VAR_TEMP_8, 4
	special checkbadgecount
	compare VAR_RESULT, 8
	call_if_eq RyuTier8GymMegaStoneReward
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
    setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	cleartrainerflag TRAINER_FLANNERY_1
	cleartrainerflag TRAINER_FLANNERY_2
	cleartrainerflag TRAINER_FLANNERY_3
	cleartrainerflag TRAINER_FLANNERY_4
	clearflag FLAG_RYU_ALTERNATE_SCALE
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	goto_if_set FLAG_RYU_HARDCORE_MODE, RyuScripts_HardcoreGymReward
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuHealedGym
	call_if_unset FLAG_RYU_GYM4HANDOUT, RyuGymItemReward4
	release
	end


FLANNERY1::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreBattle, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LG_Reset
	release
	end

FLANNERY2::
	trainerbattle_single TRAINER_FLANNERY_2, LavaridgeTown_Gym_1F_Text_FlanneryPreBattle, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LG_Reset
	release
	end

FLANNERY3::
	trainerbattle_single TRAINER_FLANNERY_3, LavaridgeTown_Gym_1F_Text_FlanneryPreBattle, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LG_Reset
	release
	end

FLANNERY4::
	call_if_set FLAG_RYU_DS_HAS_PARTNER, LG_PartnerQuery
	trainerbattle_single TRAINER_FLANNERY_4, LavaridgeTown_Gym_1F_Text_FlanneryPreBattle, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LG_Reset
	release
	end
	
LG_PartnerQuery::
    msgbox RyuPartnerMultiText MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_eq LG_RelDialog
	goto LG_NoRelGymBattle
	return
	
	
LG_RelDialog::
	call RyuPartnerBattleMultichoice
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq LG_GymBattleIntroShelly
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq LG_GymBattleIntroDawn
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq LG_GymBattleIntroBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq LG_GymBattleIntroLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq LG_GymBattleIntroLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq LG_GymBattleIntroCourtney
	goto LG_NoRelGymBattle
	
LG_NoRelGymBattle::
	trainerbattle_single TRAINER_FLANNERY_4, LavaridgeTown_Gym_1F_Text_FlanneryPreBattle, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LG_Reset
	release
	end
	
LG_NoRelationship1::
	msgbox Ryu_NOREL MSGBOX_DEFAULT
	closemessage
	goto LG_RelDialog
	
LG_GymBattleIntroShelly::
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, LG_NoRelationship1
	msgbox Ryu_PlayerCalledShelly MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_FU_ZUZUZU
	addobject 7
	applymovement 7, LG_PartnerEnter
	waitmovement 0
	msgbox LG_SHELLY_INTRO MSGBOX_DEFAULT
	goto LG_AltGymBattle
	
LG_GymBattleIntroDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, LG_NoRelationship1
	msgbox Ryu_PlayerCalledDawn MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_FU_ZUZUZU
	addobject 9
	applymovement 9, LG_PartnerEnter
	waitmovement 0
	msgbox LG_DAWN_INTRO MSGBOX_DEFAULT
	goto LG_AltGymBattle
	
LG_GymBattleIntroLana::
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, LG_NoRelationship1
	msgbox Ryu_PlayerCalledLana MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_FU_ZUZUZU
	addobject 10
	applymovement 10, LG_PartnerEnter
	waitmovement 10
	msgbox LG_LANA_INTRO MSGBOX_DEFAULT
	goto LG_AltGymBattle
	
LG_GymBattleIntroBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, LG_NoRelationship1
	msgbox Ryu_PlayerCalledBrendan MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_FU_ZUZUZU
	addobject 8
	applymovement 8, LG_PartnerEnter
	waitmovement 0
	msgbox LG_BRENDAN_INTRO MSGBOX_DEFAULT
	goto LG_AltGymBattle
	
LG_GymBattleIntroLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, LG_NoRelationship1
	msgbox Ryu_PlayerCalledLanette MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_FU_ZUZUZU
	addobject 11
	applymovement 11, LG_PartnerEnter
	waitmovement 11
	msgbox LG_LANETTE_INTRO MSGBOX_DEFAULT
	goto LG_AltGymBattle

LG_GymBattleIntroCourtney::
	goto_if_unset FLAG_RYU_DS_COURTNEY_PARTNERS, LG_NoRelationship1
	msgbox Ryu_PlayerCalledCourtney MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 12
	playse SE_DOOR
	applymovement 12, LG_PartnerEnter
	waitmovement 0
	msgbox LG_COURTNEY_INTRO MSGBOX_DEFAULT
	goto LG_AltGymBattle
	
LG_AltGymBattle::
	msgbox LG_PreBattleText MSGBOX_DEFAULT
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq LG_ChooseValidMons
	multi_2_vs_1 TRAINER_FLANNERY_4, LG_DefeatText, VAR_0x8008, VAR_0x8009
	waitstate
	special LoadPlayerParty
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	delay 10
	goto LG_GymBattleEnd

LG_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto LG_AltGymBattle
	
LG_GymBattleEnd::
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq LG_GymBattleEndDawn
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq LG_GymBattleEndShelly
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq LG_GymBattleEndBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq LG_GymBattleEndLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq LG_GymBattleEndLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq LG_GymBattleEndCourtney
	release
	end
	
LG_GymBattleEndShelly::
	msgbox LG_ShellyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 7, LG_PartnerExit
	waitmovement 0
	playse SE_FU_ZUZUZU
	removeobject 7
	goto LG_Reset
	release
	end
	
LG_GymBattleEndDawn::
	msgbox LG_DawnGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 9, LG_PartnerExit
	waitmovement 0
	playse SE_FU_ZUZUZU
	removeobject 9
	goto LG_Reset
	release
	end
	
LG_GymBattleEndBrendan::
	msgbox LG_BrendanGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 8, LG_PartnerExit
	waitmovement 0
	playse SE_FU_ZUZUZU
	removeobject 8
	goto LG_Reset
	release
	end
	
LG_GymBattleEndLana::
	msgbox LG_LanaGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 10, LG_PartnerExit
	waitmovement 10
	playse SE_FU_ZUZUZU
	removeobject 10
	special DrawWholeMapView
	goto LG_Reset
	release
	end
	
LG_GymBattleEndLanette::
	msgbox LG_LanetteGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 11, LG_PartnerExit
	waitmovement 11
	playse SE_FU_ZUZUZU
	removeobject 11
	special DrawWholeMapView
	goto LG_Reset
	release
	end

LG_GymBattleEndCourtney::
	msgbox LG_CourtneyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 12, LG_PartnerExit
	waitmovement 12
	playse SE_FU_ZUZUZU
	removeobject 12
	goto LG_Reset
	release
	end
	
LG_SHELLY_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Hey, {PLAYER}!\p"
    .string "I got a break from admin stuff, so\n"
    .string "I have time to help you crush this\l"
    .string "hothead. LETS GO!$"

LG_DAWN_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Hiya {PLAYER}! I'm not the\n"
    .string "greatest against fire types, but\l"
    .string "I'm willing to try for you!$"
	
LG_LANA_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I never really liked fire\n"
    .string "types. It might be tough, but\l"
    .string "I can overcome it!$"
	
LG_LANETTE_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Ohoho, quite the aggressive\ntraining style. Let's show what a cool\ltemper can do for a battle.$"

LG_COURTNEY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Ah yes, a fello pyromaniac.\nGood times.$"

LG_PreBattleText:
    .string "Flannery: Oh, ho ho ho...\p"
    .string "Even with backup you won't be able\n"
    .string "to handle me... I'm too hot!$"

LG_BRENDAN_INTRO:
    .string "Brendan:{COLOR LIGHT_BLUE}{SHADOW BLUE} Hey, {PLAYER}, I got your\n"
    .string "back, babe. Let's do this!$"

LG_DefeatText:
    .string "Ow! You quenched me!$"
	
LG_ShellyGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}She stood no chance against\n"
    .string "my water types.\p"
    .string "It's no suprise!$"

LG_DawnGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}That was really hard, but\n"
    .string "I'm glad it worked out!\p"
	.string "See you later, {PLAYER}!$"
	
LG_LanetteGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}This girl has much promise.\nShe just needs to settle down.\lBeing hotheaded doesn't win battles!$"

LG_BrendanGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Well, that was a fun\n"
    .string "work-out. Don't hesitate to call\l"
    .string "me if you want my help again!$"
	
LG_LanaGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}That wasn't too bad after\n"
    .string "all! I was concerned for no reason!$"

LG_CourtneyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Fire is the best way to remove\nscum from the face of the earth.$"

LG_PartnerEnter:
	walk_in_place_up
	walk_in_place_up
	walk_up
	walk_up
	walk_in_place_right
	step_end

LG_PartnerExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2:: @ 81FE81D
	goto_if_set FLAG_RECEIVED_TM50, ryu_end
	giveitem ITEM_TM50
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat:: @ 81FE841
	additem ITEM_TM50
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch:: @ 81FE864
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole:: @ 81FE87F
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, 2, LavaridgeTown_Gym_1F_Text_ColePreBattle, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript:: @ 81FE89A
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	compare VAR_RESULT, 1
	goto_if_eq EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle:: @ 81FE8AF
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, 4, LavaridgeTown_Gym_1F_Text_AxlePreBattle, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan:: @ 81FE8CA
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, 2, LavaridgeTown_Gym_B1F_Text_KeeganPreBattle, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle:: @ 81FE8E5
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, 5, LavaridgeTown_Gym_1F_Text_DaniellePreBattle, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald:: @ 81FE900
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, 3, LavaridgeTown_Gym_1F_Text_GeraldPreBattle, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace:: @ 81FE91B
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, 1, LavaridgeTown_Gym_B1F_Text_JacePreBattle, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff:: @ 81FE936
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, 3, LavaridgeTown_Gym_B1F_Text_JeffPreBattle, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli:: @ 81FE951
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, 4, LavaridgeTown_Gym_B1F_Text_EliPreBattle, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide:: @ 81FE96C
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory:: @ 81FE981
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue:: @ 81FE98B
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue:: @ 81FE99B
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified:: @ 81FE9AB
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue:: @ 81FE9B5
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice: @ 81FE9BF
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "LAVARIDGE's Gym Leader Flannery\n"
	.string "uses FIRE-type Pokémon.\p"
	.string "Her passion for Pokémon burns stronger\n"
	.string "and hotter than a volcano.\p"
	.string "Don't get too close to her--you'll burn!\n"
	.string "Hose her down with water and then\l"
	.string "go for it!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory: @ 81FEAB8
	.string "Yow! That was a scorching-hot battle!$"

LavaridgeTown_Gym_1F_Text_ColePreBattle: @ 81FEADE
	.string "Owowowowow!\n"
	.string "Yikes, it's hot!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat: @ 81FEAFB
	.string "I'm blinded by sweat in my eyes…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle: @ 81FEB1C
	.string "Being buried in hot sand promotes\n"
	.string "circulation.\p"
	.string "It's effective for healing pain in\n"
	.string "your joints.$"

LavaridgeTown_Gym_1F_Text_AxlePreBattle: @ 81FEB7B
	.string "I'm trying to relieve my stress.\n"
	.string "Don't come along and stress me out!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat: @ 81FEBC0
	.string "I hope Flannery flames you good!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle: @ 81FEBE1
	.string "Haaah… Whew…\p"
	.string "If you spend too much time buried in\n"
	.string "hot sand, it tuckers you out…$"

LavaridgeTown_Gym_B1F_Text_KeeganPreBattle: @ 81FEC31
	.string "You must be getting tired by now.\n"
	.string "You'd like to rest in the hot sand,\l"
	.string "wouldn't you?\p"
	.string "But you should know that maintaining\n"
	.string "your willpower is an important ability\l"
	.string "for all Trainers.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat: @ 81FECE3
	.string "Play with fire, and be burned…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle: @ 81FED02
	.string "Your skill is real…\n"
	.string "But our LEADER Flannery is strong.\p"
	.string "If you don't watch yourself, you'll be\n"
	.string "burned seriously.$"

LavaridgeTown_Gym_1F_Text_GeraldPreBattle: @ 81FED72
	.string "Can your Pokémon withstand\n"
	.string "392-degree heat?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat: @ 81FED9E
	.string "It didn't burn hotly enough…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle: @ 81FEDBB
	.string "The temperature of magma is\n"
	.string "392 degrees.\p"
	.string "Your Pokémon beat me, so they should\n"
	.string "easily survive in magma.$"

LavaridgeTown_Gym_1F_Text_DaniellePreBattle: @ 81FEE22
	.string "Um…\n"
	.string "Okay, I'll battle with you.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat: @ 81FEE42
	.string "Oh, but you're too strong.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle: @ 81FEE5D
	.string "I'm going to be a pretty and strong\n"
	.string "Trainer just like Flannery.$"

LavaridgeTown_Gym_B1F_Text_JacePreBattle: @ 81FEE9D
	.string "Come on, get with it!\n"
	.string "Let's go before my feelings cool!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat: @ 81FEED5
	.string "It's so hot, and yet my heart is\n"
	.string "clutched by ice…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle: @ 81FEF07
	.string "The way the battling spirit burns\n"
	.string "within you, you may stand a chance\l"
	.string "against our LEADER.$"

LavaridgeTown_Gym_B1F_Text_JeffPreBattle: @ 81FEF60
	.string "See how the flames blaze wildly?\n"
	.string "They flare in anticipation of my win!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat: @ 81FEFA7
	.string "Something didn't go right.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle: @ 81FEFC2
	.string "Well, so what? I say so what?\n"
	.string "I can walk on hot coals barefoot!\p"
	.string "…Don't even think about trying it!$"

LavaridgeTown_Gym_B1F_Text_EliPreBattle: @ 81FF025
	.string "As much as I love mountains,\n"
	.string "I especially love volcanoes.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat: @ 81FF05F
	.string "Well, it seems to me I lost without\n"
	.string "ever being in control.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle: @ 81FF09A
	.string "I stay here because I became a fan\n"
	.string "of Flannery's power.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryPreBattle: @ 81FF0DC
	.string "Welcome… No, wait.\p"
	.string "Puny Trainer, how good to see you've\n"
	.string "made it here!\p"
	.string "I have been entrusted with the…\n"
	.string "No, wait.\p"
	.string "I am Flannery, and I'm the Gym\n"
	.string "LEADER here!\p"
	.string "Uh…\n"
	.string "Dare not underestimate me, though\l"
	.string "I have been LEADER only a short time!\p"
	.string "With skills inherited from my grand-\n"
	.string "father, I shall, uh…demonstrate the\l"
	.string "hot moves we have honed on this land!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat: @ 81FF233
	.string "Oh…\n"
	.string "I guess I was trying too hard…$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge: @ 81FF32F
	.string "{PLAYER} received the HEAT badge\n"
	.string "from Flannery.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis: @ 81FF359
	.string "If you have a HEAT badge, all Pokémon\n"
	.string "up to Level 50, even those you get in\l"
	.string "trades from other people, will obey\l"
	.string "you completely.\p"
	.string "And, it lets Pokémon use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "This is a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat: @ 81FF45C
	.string "That TM50 contains OVERHEAT.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the SP. ATK\n"
	.string "of the Pokémon using it. It might not\l"
	.string "be suitable for longer battles.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery: @ 81FF517
	.string "Registered Gym Leader Flannery\n"
	.string "in the Pokénav.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle: @ 81FF546
	.string "Your power reminds me of someone…\p"
	.string "Oh! I know! You battle like Norman,\n"
	.string "the Gym Leader of PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue: @ 81FF5A9
	.string "LAVARIDGE TOWN Pokémon Gym$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified: @ 81FF5C4
	.string "LAVARIDGE TOWN Pokémon Gym\p"
	.string "Flannery's Certified Trainers:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch: @ 81FF601
	.string "Flannery: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love Pokémon.\n"
	.string "I love to battle.\l"
	.string "And… I love this Gym!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat: @ 81FF69F
	.string "Whew!\n"
	.string "On the verge of eruption!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch: @ 81FF6BF
	.string "Flannery: I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons: @ 81FF75E
	.string "Flannery: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love Pokémon.\n"
	.string "I love to battle.\l"
	.string "And… I love this Gym!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Oh, wait. Do you only have one Pokémon\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two Pokémon.$"
