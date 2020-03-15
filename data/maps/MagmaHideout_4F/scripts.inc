MagmaHideout_4F_MapScripts:: @ 823A55F
	.byte 0

MagmaHideout_4F_EventScript_Maxie:: @ 823A560
	lockall
	playbgm MUS_MGM0, 0
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_W197
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_ME_TAMA
	playse SE_TAMA
	special DoOrbEffect
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject 7  @ sleeping Groudon
	addobject 1     @ awakened Groudon
	waitstate
	delay 60
	applymovement 1, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 1, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject 1
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement 6, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject 6
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach: @ 823A672
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit: @ 823A67D
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround: @ 823A680
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11:: @ 823A68C
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12:: @ 823A6A3
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13:: @ 823A6BA
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Courtney:: @ 823A6D1
	trainerbattle_single TRAINER_COURTNEY_3, MagmaHideout_4F_Text_CourtneyIntro, MagmaHideout_4F_Text_CourtneyDefeat
	msgbox MagmaHideout_4F_Text_CourtneyPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro: @ 823A6E8
	.string "I want to see GROUDON, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat: @ 823A775
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_Grunt11PostBattle: @ 823A7B5
	.string "I wonder if GROUDON even has a tail?$"

MagmaHideout_4F_Text_Grunt12Intro: @ 823A7DA
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_Grunt12Defeat: @ 823A81B
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"

MagmaHideout_4F_Text_Grunt12PostBattle: @ 823A841
	.string "MAXIE, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_Grunt13Intro: @ 823A86D
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"

MagmaHideout_4F_Text_Grunt13Defeat: @ 823A8A7
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_Grunt13PostBattle: @ 823A8C6
	.string "C-come on, one more match…$"

MagmaHideout_4F_Text_CourtneyIntro: @ 823A8E1
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, GROUDON is sleeping!\p"
	.string "MAXIE went to GROUDON just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_CourtneyDefeat: @ 823A994
	.string "Taken down again…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_CourtneyPostBattle: @ 823A9AC
	.string "…And while you wasted time with me,\n"
	.string "MAXIE should have awakened GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon: @ 823A9F4
	.string "Maxie: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This BLUE ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the BLUE ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong: @ 823AADA
	.string "Maxie: GROUDON!\n"
	.string "What's wrong?\p"
	.string "Wasn't the BLUE ORB the key?\p"
	.string "GROUDON!\n"
	.string "Where have you gone…$"

MagmaHideout_4F_Text_MaxieOhItWasYou: @ 823AB33
	.string "Maxie: Oh, so it was you?\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must have pulled a cheap stunt!$"

MagmaHideout_4F_Text_MaxieDefeat: @ 823ABB5
	.string "What makes you so adept at handling\n"
	.string "Pokémon?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon: @ 823ABE2
	.string "Maxie: There has to be some reason\n"
	.string "why GROUDON fled…\p"
	.string "That's what you're trying to say,\n"
	.string "aren't you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "You think I didn't know that?\p"
	.string "With GROUDON gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "I am going after GROUDON, so this\n"
	.string "is where we part!$"

@===========================================ryu aqua

MH_CheckForStatus::
	goto_if_set FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, ryu_end
	goto_if_set FLAG_RYU_DS_SHELLY_CLOSEFRIENDS, MH_MapSetup_Duo
	goto MH_MapSetup_Solo
	
MH_MapSetup_Solo::
	lock
	addobject 5
	removeobject 10
	clearflag FLAG_RYU_MH_COURTNEY_SOLOMODE
	setflag FLAG_RYU_MH_COURTNEY_DUOMODE
	special DrawWholeMapView
	releaseall
	end
	
MH_MapSetup_Duo::
	lock
	addobject 10
	removeobject 5
	clearflag FLAG_RYU_MH_COURTNEY_DUOMODE
	setflag FLAG_RYU_MH_COURTNEY_SOLOMODE
	special DrawWholeMapView
	releaseall
	end
	
	
MH_RyuBossFight::
	goto_if_set FLAG_RYU_DS_SHELLY_CLOSEFRIENDS, MH_CourtneyMaxieAltBattle
	goto_if_set FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, ryu_end
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_Delay32
	waitmovement 0
	applymovement 6, MH_MaxieMove
	waitmovement 0
	msgbox MH_NormalBoss MSGBOX_DEFAULT
	trainerbattle_single TRAINER_MAXIE_3, MH_MaxieSoloIntro, MH_MaxieSoloDefeat, MH_AltGroudonScene
	goto MH_AltGroudonScene
	releaseall
	end
	
MH_CourtneyMaxieAltBattle::
	fadenewbgm MUS_MGM0
	applymovement EVENT_OBJ_ID_FOLLOWER, MH_FollowerToStatic
	waitmovement EVENT_OBJ_ID_FOLLOWER
	goto_if_set FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, ryu_end
	applymovement 6, Common_Movement_ExclamationMark
	applymovement 10, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_Delay32
	applymovement 10, Common_Movement_Delay32
	waitmovement 0
	applymovement 10, MH_CourtneyMove
	applymovement 6, MH_MaxieMove
	waitmovement 0
	msgbox MH_CourtneyIntro MSGBOX_DEFAULT
	msgbox MH_MaxieIntro MSGBOX_DEFAULT
	getplayerxy VAR_TEMP_8, VAR_TEMP_9
	addvar VAR_TEMP_9, 1
	addobject 9
	setobjectxy 9, VAR_TEMP_8, VAR_TEMP_9
	applymovement 9, Common_Movement_FaceRight
	waitmovement 9
	destroyfollower
	clearflag FLAG_RYU_HAS_FOLLOWER
	msgbox MH_ShellyAssistIntro MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_COURTNEY_3, 0, NULL, MH_CourtneySpcdefeat
	trainerbattle 11 TRAINER_MAXIE_3, 0, NULL, MH_MaxieSpcdefeat
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, TRAINER_SHELLY_2
	setvar VAR_0x8007, TRAINER_BACK_PIC_SHELLY
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto MH_RelGroudonScene

MH_FollowerToStatic:
	walk_right
	walk_down
	face_right
	step_end
	
MH_AltGroudonScene::
	lockall
	goto_if_set FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, ryu_end
	msgbox MH_MaxieSoloComplete, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	removeobject 6
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 10
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	clearflag FLAG_RYU_STARTING_M3
	fadescreen 0
	addobject 9
	applymovement 9, MH_ShellyBossEnter
	waitmovement 0
	msgbox MH_ShellyIndependentIntro MSGBOX_AUTOCLOSE
	setflag FLAG_RYU_MH_COURTNEY_SOLOMODE
	releaseall
	end
	
MH_RelGroudonScene::
	lockall
	msgbox MH_MaxieDuoComplete MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	removeobject 6
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	clearflag FLAG_RYU_STARTING_M3
	fadescreen 0
	applymovement 9, MH_Facedown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox MH_ShellyRelOutro MSGBOX_DEFAULT
	closemessage
	msgbox MH_CourtneyCry MSGBOX_DEFAULT
	closemessage
	applymovement 10, MH_RelCourtneySadLeave
	waitmovement 0
	playse SE_DOOR
	waitse
	removeobject 10
	msgbox MH_RelShellySorry
	setflag FLAG_RYU_MH_COURTNEY_DUOMODE
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	releaseall
	end

MH_RelShellySorry:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Wow, She really loves\n"
    .string "Maxie, and he ignores her completely\p"
    .string "It's such a shame that she doesn't\n"
    .string "have a loving, caring close friend\p"
    .string "like you. Good thing I got you\n"
    .string "first, huh, {PLAYER}?$"

	
MH_Facedown:
	walk_in_place_up
	step_end
	
MH_ShellyAfterFight::
	goto_if_unset FLAG_RYU_DS_SHELLY_CLOSEFRIENDS, MH_ShellyAfterFightNoRel
	faceplayer
	msgbox MH_ShellyAfterFightRelMsg MSGBOX_DEFAULT
	closemessage
	release
	end
	
MH_ShellyAfterFightNoRel::
	lock
	faceplayer
	msgbox MH_ShellyAfterFightMsg MSGBOX_DEFAULT
	closemessage
	release
	end
	
MH_ShellyBossEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MH_CourtneyMove:
	walk_left
	walk_left
	step_end
	
MH_MaxieMove:
	walk_left
	walk_left
	step_end
	
MH_RelCourtneySadLeave:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MH_ShellyFaceEnemy:
	walk_down
	walk_right
	walk_in_place_right
	step_end
	
MH_ShellyAfterFightRelMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: I'm staying here to make sure\nno one else comes to fiddle with Groudon.\pMeet me back at corporate later.$"
	
MH_ShellyAfterFightMsg:
	.string "Shelly: We did good work here, Lieutenant.\nHead back to corporate.\lI'll meet you there later.$"
	
MH_MaxieDuoComplete:
	.string "Maxie: I don't understand how...\nWhy am I not strong enough?\p... ... ... ... ... ...$"
	
MH_CourtneyCry:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN} (Courtney looks broken and dejected.\n She seems really upset.\l You can't help but feel sorry for her.)$"
	
MH_ShellyRelOutro:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: We make an amazing team,\n{PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, don't we?\p"
	.string "I'll stay here and make sure\nno other Magma thugs show up to\lmess with Groudon.\pMeet me back at Corporate later.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Shelly winks at you.\n you wonder what's in store...)$"
	
MH_ShellyIndependentIntro:
	.string "Shelly: Good job, Lieutenant.\pArchie will be pleased with your\nactions here, today. You've\lprevented Magma from realizing\l"
	.string "their goal. Now there's nothing\lstanding in the way of us and our\lgoals.\pI'll stay here to catch any\nstragglers that may have been left\l"
	.string "behind. Meet me back at Corporate.$"
	
MH_MaxieSoloComplete:
	.string "Maxie: Groudon... I...\pIt's clear to me that I am not\nstrong enough to control you...\lI think it's time I retire...$"
	
MH_NormalBoss::
	.string "Maxie: So, you've come to\n"
	.string "try to stop me.... Good luck!\p"
	.string "I will change the world for the\n"
	.string "better. \p"
	.string "Why do you resist?\p"
	.string "It will benefit all of mankind!$"
	
MH_MaxieSoloIntro::
	.string "I will NOT let a child stop me.\p"
	.string "I'm going to defeat you, and then\n"
	.string "I will force Groudon to reform this\l"
	.string "world!!$"
	
MH_CourtneyIntro:
	.string "Courtney: Aahahahah!\p"
	.string "Maxie and I are an unbreakable team!\p"
    .string "You don't stand a chance!$"
	
MH_MaxieIntro:
	.string "Isn't it obvious by now?\n"
	.string "That we can't be stopped?\p"
	.string "Groudon will awaken, and expand the\n"
	.string "landmass twofold!\p"
	.string "Overpopulation will no longer be a\n"
	.string "problem!$"
	
MH_ShellyAssistIntro:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Maxie and Courtney!\p"
	.string "Your crazy evil deeds stop NOW!\n"
	.string "{PLAYER}{COLOR LIGHT_RED}{SHADOW RED} and I will annihilate you!\p"
	.string "We won't allow you to destroy the\n"
	.string "world!$"
	
MH_MaxieSoloDefeat:
	.string "What!? Unbelievable!$"
	
MH_MaxieDefeated:
	.string "Groudon.... It's clear to me that\nI am not strong enough to control\lyou...\lYou're going to have to stay here,\ldormant...$"
	
MH_CourtneySpcdefeat:
	.string "Courtney: Maxie.... I'm sorry...\n"
	.string "I was too weak...$"
	
MH_MaxieSpcdefeat:
	.string "Maxie: Unbelievable! This can't be!$"

MH_Groudon_Enc::
	goto_if_set FLAG_RYU_GROUDON_ENCOUNTERED, ryu_end
	goto_if_unset FLAG_RYU_DS_SHELLY_LOVERS, ryu_end
	lockall
	setvar VAR_RESULT, 1
	playse SE_W197
	setfieldeffectargument 0, 18
	setfieldeffectargument 1, 42
	setfieldeffectargument 2, 0
	dofieldeffect 54
	waitfieldeffect 54
	setvar VAR_RESULT, 1
	playfanfare MUS_ME_TAMA
	playse SE_TAMA
	playmoncry SPECIES_GROUDON, 0
	waitmoncry
	special DoOrbEffect
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 150
	waitstate
	delay 60
	applymovement 1, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	applymovement 1, MagmaHideout_4F_Movement_23A67D
	waitmovement 0
	removeobject 1
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	delay 30
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_GROUDON, VAR_RESULT, ITEM_HARD_STONE
	msgbox MH_GroudonMsg MSGBOX_AUTOCLOSE
	special BattleSetup_StartLegendaryBattle
	removeobject 7
	special DrawWholeMapView
	setflag FLAG_RYU_GROUDON_ENCOUNTERED
	releaseall
	end

MagmaHideout_4F_Movement_23A67D: @ 823A67D
	slide_up
	slide_up
	step_end
	
MH_GroudonMsg:
	.string "Groudon stares at you intently...$"
