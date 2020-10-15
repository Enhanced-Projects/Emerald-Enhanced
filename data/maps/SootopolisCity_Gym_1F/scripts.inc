SootopolisCity_Gym_1F_MapScripts:: @ 8224E4C
	map_script ON_FRAME, SootopolisCity_Gym_1F_OnFrame
	map_script ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script ON_LOAD , SootopolisCity_Gym_1F_OnLoad
	map_script ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition: @ 8224E61
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume: @ 8224E67
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad: @ 8224E6A
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles:: @ 8224E73
	compare VAR_ICE_STEP_COUNT, 8
	goto_if_lt SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	compare VAR_ICE_STEP_COUNT, 28
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	compare VAR_ICE_STEP_COUNT, 67
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs:: @ 8224EA6
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs:: @ 8224EB8
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs:: @ 8224ECA
	return

SootopolisCity_Gym_1F_OnFrame: @ 8224ECB
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs:: @ 8224EED
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_RU_GASHIN
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs:: @ 8224F01
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_RU_GASHIN
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs:: @ 8224F15
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_RU_GASHIN
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce:: @ 8224F29
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce: @ 8224F42
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan:: @ 8224F44
	lock
	faceplayer
	setflag FLAG_RYU_BOSS_SCALE
	special checkbadgecount
    switch VAR_RESULT
    case 0, Juan1
	case 1, Juan1
	case 2, Juan1
	case 3, Juan2
	case 4, Juan2
	case 5, Juan3
	case 6, Juan3
	case 7, Juan4
	case 8, Juan4
	end

SG_Reset::
	setvar VAR_TEMP_8, 8
	special checkbadgecount
	compare VAR_RESULT, 8
	call_if_eq RyuTier8GymMegaStoneReward
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM 
	setflag FLAG_BADGE08_GET
	cleartrainerflag TRAINER_JUAN_1
	cleartrainerflag TRAINER_JUAN_2
	cleartrainerflag TRAINER_JUAN_3
	cleartrainerflag TRAINER_JUAN_4
	clearflag FLAG_RYU_BOSS_SCALE
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	goto_if_set FLAG_RYU_HARDCORE_MODE, RyuScripts_HardcoreGymReward
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuHealedGym
	call_if_unset FLAG_RYU_GYM8HANDOUT, RyuGymItemReward8
	release
	end

Juan1::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreBattle, SootopolisCity_Gym_1F_Text_JuanDefeat, SG_Reset
	release
	end

Juan2::
	trainerbattle_single TRAINER_JUAN_2, SootopolisCity_Gym_1F_Text_JuanPreBattle, SootopolisCity_Gym_1F_Text_JuanDefeat, SG_Reset
	release
	end

Juan3::
	trainerbattle_single TRAINER_JUAN_3, SootopolisCity_Gym_1F_Text_JuanPreBattle, SootopolisCity_Gym_1F_Text_JuanDefeat, SG_Reset
	release
	end

Juan4::
	goto_if_set FLAG_RYU_HAS_FOLLOWER, SG_FollowerMatch
	call_if_set FLAG_RYU_DS_HAS_PARTNER, SG_PartnerQuery
	trainerbattle_single TRAINER_JUAN_4, SootopolisCity_Gym_1F_Text_JuanPreBattle, SootopolisCity_Gym_1F_Text_JuanDefeat, SG_Reset
	release
	end
	
SG_PartnerQuery::
    msgbox RyuPartnerMultiText MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SG_RelDialog
	goto SG_NoRelGymBattle
	return
	
	
SG_RelDialog::
	call RyuPartnerBattleMultichoice
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq SG_GymBattleIntroShelly
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq SG_GymBattleIntroDawn
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq SG_GymBattleIntroBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq SG_GymBattleIntroLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq SG_GymBattleIntroLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq SG_GymBattleIntroCourtney
	compare VAR_0x8008, TRAINER_REL_NURSE
	goto_if_eq SG_GymBattleIntroJoy
	goto SG_NoRelGymBattle
	
SG_NoRelGymBattle::
	trainerbattle_single TRAINER_JUAN_4, SootopolisCity_Gym_1F_Text_JuanPreBattle, SootopolisCity_Gym_1F_Text_JuanDefeat, SG_Reset
	release
	end

SG_FollowerMatch::
	msgbox SootopolisCity_Gym_1F_Text_JuanPreBattle
	closemessage
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq SG_ChooseValidMons
	multi_2_vs_1 TRAINER_JUAN_4, SootopolisCity_Gym_1F_Text_JuanDefeat, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto SG_Reset
	end
	
SG_NoRelationship1::
	msgbox Ryu_NOREL MSGBOX_DEFAULT
	closemessage
	goto SG_RelDialog
	
SG_GymBattleIntroShelly::
	msgbox Ryu_PlayerCalledShelly MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, SG_NoRelationship1
	addobject 5
	playse SE_TK_WARPIN
	applymovement 5, SG_PartnerEnter
	waitmovement 0
	msgbox SG_SHELLY_INTRO MSGBOX_DEFAULT
	goto SG_AltGymBattle
	
SG_GymBattleIntroDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, SG_NoRelationship1
	msgbox Ryu_PlayerCalledDawn MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 3
	playse SE_TK_WARPIN
	applymovement 3, SG_PartnerEnter
	waitmovement 0
	msgbox SG_DAWN_INTRO MSGBOX_DEFAULT
	goto SG_AltGymBattle
	
SG_GymBattleIntroBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, SG_NoRelationship1
	msgbox Ryu_PlayerCalledBrendan MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 4
	playse SE_TK_WARPIN
	applymovement 4, SG_PartnerEnter
	waitmovement 0
	msgbox SG_BRENDAN_INTRO MSGBOX_DEFAULT
	goto SG_AltGymBattle
	
SG_GymBattleIntroLana::
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, SG_NoRelationship1
	msgbox Ryu_PlayerCalledLana MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 6
	playse SE_TK_WARPIN
	applymovement 6, SG_PartnerEnter
	waitmovement 6
	msgbox SG_LANA_INTRO MSGBOX_DEFAULT
	goto SG_AltGymBattle
	
SG_GymBattleIntroLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, SG_NoRelationship1
	msgbox Ryu_PlayerCalledLanette MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 7
	playse SE_TK_WARPIN
	applymovement 7, SG_PartnerEnter
	waitmovement 7
	msgbox SG_LANETTE_INTRO MSGBOX_DEFAULT
	goto SG_AltGymBattle

SG_GymBattleIntroCourtney::
	goto_if_unset FLAG_RYU_DS_COURTNEY_PARTNERS, SG_NoRelationship1
	msgbox Ryu_PlayerCalledCourtney MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 8
	playse SE_DOOR
	applymovement 8, SG_PartnerEnter
	waitmovement 0
	msgbox SG_COURTNEY_INTRO MSGBOX_DEFAULT
	goto SG_AltGymBattle

SG_GymBattleIntroJoy::
	goto_if_unset FLAG_RYU_DS_JOY_PARTNERS, SG_NoRelationship1
	msgbox Ryu_PlayerCalledJoy MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 9
	playse SE_DOOR
	applymovement 9, SG_PartnerEnter
	waitmovement 0
	msgbox SG_JOY_INTRO MSGBOX_DEFAULT
	goto SG_AltGymBattle
	
SG_AltGymBattle::
	msgbox SG_PreBattleText MSGBOX_DEFAULT
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq SG_ChooseValidMons
	multi_2_vs_1 TRAINER_JUAN_4, SG_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	delay 10
	goto SG_GymBattleEnd
	
SG_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto_if_set FLAG_RYU_HAS_FOLLOWER, SG_FollowerMatch
	goto SG_AltGymBattle
	
SG_GymBattleEnd::
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq SG_GymBattleEndDawn
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq SG_GymBattleEndShelly
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq SG_GymBattleEndBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq SG_GymBattleEndLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq SG_GymBattleEndLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq SG_GymBattleEndCourtney
	release
	end
	
SG_GymBattleEndShelly::
	msgbox SG_ShellyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 5, SG_PartnerExit
	waitmovement 0
	playse SE_TK_WARPOUT
	removeobject 5
	goto SG_Reset
	release
	end
	
SG_GymBattleEndDawn::
	msgbox SG_DawnGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 3, SG_PartnerExit
	waitmovement 0
	playse SE_TK_WARPOUT
	removeobject 3
	goto SG_Reset
	release
	end
	
SG_GymBattleEndBrendan::
	msgbox SG_BrendanGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 4, SG_PartnerExit
	waitmovement 0
	playse SE_TK_WARPOUT
	removeobject 4
	goto SG_Reset
	release
	end
	
SG_GymBattleEndLana::
	msgbox SG_LanaGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 6, SG_PartnerExit
	waitmovement 6
	playse SE_TK_WARPOUT
	removeobject 6
	special DrawWholeMapView
	goto SG_Reset
	release
	end
	
SG_GymBattleEndLanette::
	msgbox SG_LanetteGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 7, SG_PartnerExit
	waitmovement 7
	playse SE_TK_WARPOUT
	removeobject 7
	special DrawWholeMapView
	goto SG_Reset
	release
	end

SG_GymBattleEndCourtney::
	msgbox SG_CourtneyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 8, SG_PartnerExit
	waitmovement 8
	playse SE_TK_WARPOUT
	removeobject 8
	special DrawWholeMapView
	goto SG_Reset
	release
	end

SG_GymBattleEndJoy::
	msgbox SG_JoyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 9, SG_PartnerExit
	waitmovement 9
	playse SE_DOOR
	removeobject 9
	goto SG_Reset
	release
	end
	
SG_SHELLY_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'd say I probably wasn't\n"
    .string "the best person to call, but I'll\l"
    .string "support you any way I can!$"

	
SG_DAWN_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}This guy's creepy...\p"
    .string "Let's stomp him out of existence!$"
	
SG_LANA_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}This guy's annoying... can\n"
    .string "we get this over with quickly?\l"
    .string "He creeps me out...$"
	
SG_LANETTE_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hello, Juan. I see that\nyou are as flippant as ever$"

SG_BRENDAN_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Brendan: This guy is weird…\n"
    .string "I don't like him…\l"
    .string "Let's send him packing!$"

SG_COURTNEY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}An annoying person with\nannoying types.\pI really don't like it here.$"

SG_JOY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED} Wow! he's positively adorable!$"
	
SG_PreBattleText:
	.string "Juan: Oh, I get to have two dance\npartners. This will be magical!$"
	
SG_DefeatText:
	.string "You guys make a fantastic team!$"
	
SG_ShellyGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I got a little wetter than\n"
    .string "I expected to.\p"
    .string "Good thing I have my swimsuit on\n"
    .string "underneath!$"

SG_DawnGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I have the strangest urge\n"
    .string "to take a long, hot shower...\p"
    .string "You should join me after, {PLAYER}!$"
	
SG_BrendanGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Man, I really didn't feel\n"
    .string "like swimming today...$"
	
SG_LanaGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED} Normally I like getting wet,\n"
    .string "but this was a little excessive...$"
	
SG_LanetteGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}He almost shorted me out!$"

SG_CourtneyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}UGH! It's way too humid in here!$"

SG_JoyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED} It would be great to see Juan\nand Winona in a dance-off!$"
	
SG_PartnerEnter:
	walk_in_place_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_up
	step_end

SG_PartnerExit:
	walk_in_place_right
	walk_right
	walk_right
	walk_in_place_down
	walk_in_place_down
	step_end

SootopolisCity_Gym_1F_EventScript_JuanDefeated:: @ 8224F82
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse:: @ 8224FD4
	additem ITEM_TM03
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2:: @ 8224FF7
	additem ITEM_TM03
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge:: @ 822501B
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch:: @ 8225025
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide:: @ 8225040
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory:: @ 8225055
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue:: @ 822505F
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue:: @ 822506F
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified:: @ 822507F
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue:: @ 8225089
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice: @ 8225093
	.string "Yo! How's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Sootopolis's Gym Leader Juan is\n"
	.string "a master of WATER-type Pokémon.\p"
	.string "And, to get to Juan, an icy floor\n"
	.string "will hamper your progress…\p"
	.string "Listen, I'm sorry, but that's all the\n"
	.string "advice that I have for you.\p"
	.string "The rest of the way, you have to\n"
	.string "go for it yourself!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory: @ 82251AF
	.string "Yow! You've beaten even Juan, who\n"
	.string "was supposedly the best in all Hoenn!\p"
	.string "Okay! Check out your Trainer Card.\p"
	.string "If you've gotten all the badges, you're\n"
	.string "set for the Pokémon League challenge!$"

SootopolisCity_Gym_1F_Text_JuanPreBattle: @ 8225268
	.string "Let me ask you.\n"
	.string "Did you know?\l"
	.string "Ah, I should not be so coy.\p"
	.string "It was I who taught Wallace everything\n"
	.string "there is to know about Pokémon.\p"
	.string "Once, I had given up my position as\n"
	.string "the Gym Leader.\p"
	.string "In my place, I had entrusted Wallace\n"
	.string "with the Gym.\p"
	.string "However, a compelling reason arose for\n"
	.string "me to make a comeback.$"

SootopolisCity_Gym_1F_Text_JuanDefeat: @ 8225432
	.string "Ahahaha, excellent!\n"
	.string "Very well, you are the winner.\p"
	.string "From you, I sense the brilliant shine\n"
	.string "of skill that will overcome all.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge: @ 8225598
	.string "{PLAYER} received the RAIN badge\n"
	.string "from Juan.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis: @ 82255BE
	.string "Having the Rain badge shall assure you\n"
	.string "the full obedience of all your Pokémon\l"
	.string "to your every command.\p"
	.string "The Rain badge also allows the use\n"
	.string "of the HM move Waterfall to scale\l"
	.string "walls of cascading water.\p"
	.string "And, so that you never forget the\n"
	.string "battle we shared, take this…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse: @ 82256C1
	.string "The Technical Machine I handed you\n"
	.string "contains Water Pulse.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan: @ 822574D
	.string "Registered Gym Leader Juan\n"
	.string "in the Pokénav.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle: @ 8225778
	.string "The Trainers who have gathered all\n"
	.string "the Gym Badges of Hoenn should make\l"
	.string "way to the ultimate destination.\p"
	.string "The Pokémon League.\p"
	.string "Travel to the easternmost reaches\n"
	.string "of Hoenn, to the island Ever Grande.\p"
	.string "There, you shall find the Pokémon\n"
	.string "League.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge: @ 8225865
	.string "There remains but one badge to\n"
	.string "obtain in Hoenn.\p"
	.string "If you wish to challenge the Pokémon\n"
	.string "League, you must obtain the last\l"
	.string "badge from the Gym in Fortree.$"

SootopolisCity_Gym_1F_Text_GymStatue: @ 82258FA
	.string "Sootopolis City Pokémon Gym$"

SootopolisCity_Gym_1F_Text_GymStatueCertified: @ 8225916
	.string "Sootopolis City Pokémon Gym\p"
	.string "Juan's Certified Trainers:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch: @ 8225950
	.string "Juan: Ah, this Gym had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\p"
	.string "I shall be delighted to dance with you\n"
	.string "as often as you wish!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat: @ 8225A2E
	.string "Ahahaha, you are the winner!\n"
	.string "You have defeated me again!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch: @ 8225A67
	.string "Juan: If I told you to become my\n"
	.string "apprentice, you will refuse, I am sure.\p"
	.string "I would like to make a gift of my coat\n"
	.string "to you.\p"
	.string "But again, you will refuse.\n"
	.string "I imagine that to be so.\p"
	.string "And that, my friend, is a certain sign\n"
	.string "of nobility!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons: @ 8225B48
	.string "Juan: Ah, this Gym had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\n"
	.string "I shall be delighted to dance with you…\p"
	.string "Ah, no, no, no.\n"
	.string "You have with you but one Pokémon.\p"
	.string "I wish that you would return with\n"
	.string "two, perhaps more, Pokémon, please.$"

