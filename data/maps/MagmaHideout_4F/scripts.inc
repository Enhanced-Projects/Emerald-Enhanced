MagmaHideout_4F_MapScripts:: @ 823A55F
	map_script ON_FRAME, MH_CheckSetMaxiePosition
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
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
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12:: @ 823A6A3
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13:: @ 823A6BA
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Courtney:: @ 823A6D1
	trainerbattle_single TRAINER_COURTNEY_3, MagmaHideout_4F_Text_CourtneyIntro, MagmaHideout_4F_Text_CourtneyDefeat
	call MH_CheckPlayerIsMagma
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
	compare VAR_RYU_MAGMA, 301
	goto_if_ge ryu_end
	goto_if_set FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, ryu_end
	goto_if_set FLAG_RYU_DS_SHELLY_CLOSEFRIENDS, MH_MapSetup_Duo
	goto MH_MapSetup_Solo
	
MH_MapSetup_Solo::
	lock
	addobject 5
	removeobject 10
	setobjectxy 9, 4, 15
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
	compare VAR_RYU_MAGMA, 301
	goto_if_ge ryu_end
	compare VAR_RYU_MAGMA, 450
	goto_if_eq MH4_MaxieAwakensGroudon
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
	compare VAR_RYU_MAGMA, 301
	goto_if_ge ryu_end
	fadenewbgm MUS_MGM0
	applymovement OBJ_EVENT_ID_FOLLOWER, MH_FollowerToStatic
	waitmovement OBJ_EVENT_ID_FOLLOWER
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
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
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	face_right
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
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
	
	
@==================================================================================================Magma side scripts

MH_CheckSetMaxiePosition:
	map_script_2 VAR_RYU_MAGMA, 301, SetMaxiePosition2
	map_script_2 VAR_TEMP_6, 0, CheckOpenAdminQuarters
	.2byte 0
	
CheckOpenAdminQuarters::
	compare VAR_RYU_MAGMA, 560
	goto_if_lt ryu_end
	setvar VAR_TEMP_6, 100
	setmetatile 20, 4, 606, 1
	setmetatile 20, 3, 598, 1
	end

SetMaxiePosition2::
	setvar VAR_RYU_MAGMA, 302@Player entered 4f to chat with maxie
	removeobject 6
	setflag FLAG_RYU_HIDE_MAGMA_HIDEOUT_MAXIE
	setmetatile 20, 3, 598, 1
	setmetatile 20, 4, 606, 1
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	addobject 11
	addobject 12
	end
	
MH4_MagmaAdminCheck::
	@goto_if_unset magma admin flag, ryu_end
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ryu_end
	compare VAR_RESULT, DIR_WEST
	goto_if_eq ryu_end
	msgbox MH4_NotAdminCantGoHere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
	
MH4_MagmaMaxieEvent::
	compare VAR_RYU_MAGMA 400
	goto_if_ge MH4_MagmaEvent8
	compare VAR_RYU_MAGMA, 305
	goto_if_eq MH4_ToldToGoOtherWay
	compare VAR_RYU_MAGMA, 302
	goto_if_ne ryu_end
	lock
	setvar VAR_RYU_MAGMA, 305@Player is meeting maxie in the hideout.
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	applymovement 11, MH4_MaxieToPlayer@left 3 up 1 left 2, up 3
	waitmovement 11
	msgbox MH4_SoItSeems
	closemessage
	applymovement 11, MH4_MaxieToCourtney@down 3, right 2, down1, right 3, down 2, right 2
	waitmovement 11
	release
	end
	
MH4_ToldToGoOtherWay::
	msgbox MH4_MaxieAsked
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
MH4_Maxie2Event::
	setvar VAR_RYU_MAGMA, 310@Player sees Groudon with Maxie
	applymovement 12, Common_Movement_FaceLeft
	waitmovement 12
	msgbox MH4_LeaderMaxieWelcome
	applymovement 11, Common_Movement_FaceRight
	waitmovement 11
	msgbox MH4_NowThenPlayer
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 11, Common_Movement_FaceUp
	waitmovement 11
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MH4_Cam1
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox MH4_TheAncientCreature
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, MH4_Cam2
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	msgbox MH4_HoweverThereAre
	closemessage
	playbgm MUS_EVENT0, 1
	addobject 15
	playse SE_DOOR
	waitse
	applymovement 15, Common_Movement_StepUp
	waitmovement 15
	applymovement 15, Common_Movement_FaceLeft
	waitmovement 15
	msgbox MH4_LeaderMaxieSir
	closemessage
	applymovement 12, MH4_CourtneyToGrunt
	applymovement 15, MH4_GruntPushed
	waitmovement 15
	msgbox MH4_Ellipsis
	playse SE_W025
	applymovement 12, MH4_WalkInPlaceUP
	fadedefaultbgm
	applymovement 15, MH4_GruntSlideUp2DiagNW
	waitmovement 15
	removeobject 15
	playse SE_W052
	delay 5
	playse SE_W052
	delay 15
	playse SE_W052
	waitse
	msgbox MH4_Wasteful
	applymovement 11, Common_Movement_FaceRight
	waitmovement 11
	msgbox MH4_IMustGo
	closemessage
	applymovement 11, Common_Movement_FaceLeft
	waitmovement 11
	msgbox MH4_DoNotDisappoint
	closemessage
	applymovement 11, MH4_MaxiExitsForPeak
	waitmovement 11
	playse SE_DOOR
	waitse
	removeobject 11
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	setvar VAR_RYU_MAGMA, 315@player is tasked with clearing out aqua grunts
	applymovement 12, MH4_CourtneyToPlayer@4 left, 1 down, 1 left, face up
	waitmovement 12
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MH4_Analyzing
	closemessage
	removeobject 12
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_F, RyuFollowerSelectNPCScript, 1
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	clearflag FLAG_RYU_AQUA_IN_MAGMA_HIDEOUT_GRUNTS
	setflag FLAG_RYU_WAYSTONE_DISABLED
	release
	end
	
MH4_CourtneyScript::
	compare VAR_RYU_MAGMA, 560
	goto_if_ge MH4_PostGroudonCourtneyFollower
	msgbox MH4_CourtneyChatter
	goto ryu_end

MH4_PostGroudonCourtneyFollower::
	msgbox MH4_CourtneyPostGroudonChatter
	release
	end

MH4_CourtneyPostGroudonChatter::
	.string "{COLOR LIGHT_RED}{SHADOW RED}We must find ex-leader Maxie.\nLast seen... Route 114.$"

MH4_CourtneyChatter:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Talking is... inefficient...\nLeader's orders... Go...$"
	
	
MH4_NotAdminCantGoHere:
	.string "You don't have permission\nto be in here.$"


MH4_SoItSeems:
	.string "So it seems you can follow directions\n"
    .string "after all, {PLAYER}.\p"
    .string "Very well then...I shall give you a\n"
    .string "glimpse of Team Magma's achievements.\p"
    .string "Come this way.$"

MH4_MaxieAsked:
	.string "Maxie asked you to follow\nhim around the lava pit.$"
	
MH4_LeaderMaxieWelcome:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Leader Maxie...welcome.\n"
    .string "Agent {PLAYER}...unwelcome.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Courtney, stand down.\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, don't like...troublesome...\n"
    .string "wasteful.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Hey now!\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}You may very well be right about that\n"
    .string "Courtney. However, {PLAYER} will\p"
    .string "be utilized for as long as I deem\n"
    .string "necessary. Are we clear?\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}...Understood.$"

MH4_NowThenPlayer:
	.string "Now then, {PLAYER}, look there.$"
	
MH4_TheAncientCreature:
	.string "The ancient creature slumbering\n"
    .string "before us...is the key.\p"
    .string "Within its' form lies the power\n"
    .string "necessary to shape the world as I\p"
    .string "see fit...\p"
    .string "With Groudon on our side, nothing\n"
    .string "will stand in the way of Team Magma!$"

MH4_HoweverThereAre:
	.string "However, there are still preparations\n"
    .string "to be made before that glorious time,\p"
    .string "which in turn, leads me to-$"
	
MH4_LeaderMaxieSir:
	.string "Leader Maxie, sir! Urgent report!\n"
    .string "Team Aqua has arrived on Mt. Chimney!\p"
    .string "They're attempting to-!$"

MH4_Ellipsis:
	.string "{COLOR LIGHT_RED}{SHADOW RED}... ... ... ...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Ms. Courtney, wai-!\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Burn.$"

MH4_Wasteful:
	.string "Wasteful.$"
	
MH4_IMustGo:
	.string "I must go to the peak. Courtney, you\n"
    .string "and {PLAYER} will dispose of the Aqua\l"
    .string "vermin infecting our base.$"

MH4_DoNotDisappoint:
	.string "Do not disappoint me.$"
	
MH4_Analyzing:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Analyzing...\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Listen, I wanted to-\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Leader's orders priority. Talking is\n"
    .string "wasteful.$"
	
MH4_MaxieToPlayer:@left 3 up 1 left 2, up 3
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end
	
MH4_MaxieToCourtney:@down 3, right 2, down1, right 3, down 2, right 2
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MH4_Cam1:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
MH4_Cam2:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
MH4_CourtneyToGrunt:
	walk_right
	walk_right
	walk_right
	face_up
	step_end
	
MH4_GruntPushed:
	delay_16
	delay_16
	delay_16
	slide_up
	step_end
	
MH4_WalkInPlaceUP:
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end
	
MH4_GruntSlideUp2DiagNW:
	slide_up
	slide_up
	walk_diag_northwest
	step_end
	
MH4_MaxiExitsForPeak:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

MH4_CourtneyToPlayer:@4 left, 1 down, 1 left, face up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	face_up
	step_end
	
MH4_MagmaEvent8::
	getplayerxy VAR_TEMP_4, VAR_TEMP_5
	compare VAR_TEMP_4, 4
	call_if_eq MH4_ME8_MovePlayerRight
	getplayerxy VAR_TEMP_4, VAR_TEMP_5
	compare VAR_TEMP_5, 6
	call_if_eq MH4_ME8_MovePlayerLeft
	compare VAR_RYU_MAGMA, 405
	goto_if_ge ryu_end
	lock
	special SpawnCameraObject
	addobject 16
	addobject 17
	addobject 18
	addobject 19
	applymovement OBJ_EVENT_ID_CAMERA, MH4_Cam3
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement 16, Common_Movement_FaceDown
	waitmovement 16
	msgbox MH4_WhatUtter
	closemessage
	delay 30
	msgbox MH4_ToThinkThat
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, MH4_Cam4
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MH4_PlayerSeesSomething
	waitmovement OBJ_EVENT_ID_CAMERA
	closemessage
	special RemoveCameraObject
	addobject 17
	addobject 18
	addobject 19
	applymovement OBJ_EVENT_ID_PLAYER, MH4_PlayerToAdmins
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 16, Common_Movement_FaceUp
	waitmovement 16
	msgbox MH4_AgentPlayerImpeccable
	closemessage
	applymovement 16, Common_Movement_FaceDown
	waitmovement 16
	delay 30
	msgbox MH4_TeamAquaHas
	closemessage
	applymovement 16, Common_Movement_StepUp
	waitmovement 16
	msgbox MH4_YoureTheOnly
	closemessage
	playse SE_PIN
	applymovement 19, Common_Movement_ExclamationMark
	waitmovement 19
	applymovement 19, Common_Movement_StepUp
	waitmovement 19
	msgbox MH4_LeaderMaxieNo
	closemessage
	applymovement 16, Common_Movement_FaceDown
	waitmovement 16
	msgbox MH4_Silence
	closemessage
	applymovement 16, MH2_MaxiePushesCourtney
	applymovement 19, MH2_DelayedStepDown
	waitmovement 19
	msgbox MH4_YouWillKnow
	closemessage
	applymovement 16, Common_Movement_StepUp
	waitmovement 16
	msgbox MH4_GoForthPlayer
	closemessage
	applymovement 19, MH4_CourtneyRunsOff
	waitmovement 19
	removeobject 19
	applymovement 16, MH4_MaxieToOffice
	waitmovement 16
	removeobject 16
	msgbox MH4_WellThatsThat
	closemessage
	applymovement 17, MH4_BlaiseToOffice
	waitmovement 17
	removeobject 17
	msgbox MH4_IllJustWait
	closemessage
	applymovement 18, MH4_TabithaToExit
	waitmovement 18
	removeobject 18
	setvar VAR_RYU_MAGMA, 405
	clearflag FLAG_RYU_COURTNEY_FIERY_PATH
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	clearflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	clearflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	callnative Ryu_ClearAquaSFCTrainerFlags
	release
	end
	
MH4_ME8_MovePlayerRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	return
	
MH4_ME8_MovePlayerLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	return

	
MH4_WhatUtter:
	.string "What utter incompetence!$"
	
MH4_ToThinkThat:
	.string "To think the Three Fires of Team\n"
    .string "Magma can't complete such a simple\l"
    .string "yet crucial task...!\p"
    .string "B-But Leader Maxie, sir!\n"
    .string "It wasn't just Team Aqua.\p"
    .string "Those Devon folk, as well as\n"
    .string "Gym Leaders were up there!\p"
    .string "We were ambushed!$"

MH4_PlayerSeesSomething:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} ({PLAYER} sees Maxie berating the\n"
	.string " Admins for something...)\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE} I wonder what happened?$"

MH4_AgentPlayerImpeccable:
	.string "Agent {PLAYER}, impeccable timing.\n"
    .string "I've come to understand that you were\l"
    .string "not given a mission assignment.\p"
    .string "Although I explicitly stated that\n"
    .string "every individual was to be utilized.\p"
    .string "Even so, I can see that you've used\n"
    .string "your time effectively and become\p"
    .string "strong enough to claim your seventh\l"
    .string "badge.\p"
    .string "I shall reward you in time, however,\n"
    .string "thanks to the failures of these three\l"
    .string "behind me, time is of the essence.$"

MH4_TeamAquaHas:
	.string "Team Aqua has obtained the Blue Orb\n"
    .string "and has gone to awaken Kyogre.\p"
    .string "It's a legendary sea creature whose\n"
    .string "power rivals Groudon's.\p"
    .string "Needless to say, it'll spell disaster\n"
    .string "for Team Magma.$"

MH4_YoureTheOnly:
	.string "You're the only one I can rely on\n"
    .string "now...\p"
    .string "Head to Seafloor Cavern, stop Team\n"
    .string "Aqua, Kyogre, and reclaim the Blue\l"
    .string "Orb.\p"
    .string "Return to me in this manner, and you\n"
    .string "shall be...$"

MH4_LeaderMaxieNo:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Leader Maxie, no!$"
	
MH4_Silence:
	.string "Silence!\p"
    .string "You've had your chance to show your\n"
    .string "loyalty, and you've failed!\p"
    .string "Now the task shall be given to\n"
    .string "someone more suitable.$"

MH4_YouWillKnow:
	.string "You will know your place if you wish\n"
    .string "to continue walking along the {COLOR DARK_GREY}{SHADOW RED}Fiery\l"
    .string "Path {COLOR DARK_GREY}{SHADOW LIGHT_GREY}with me.\p"
    .string "Begone, all of you!$"

MH4_GoForthPlayer:
	.string "Go forth, {PLAYER}.\n"
    .string "I place my trust in you.$"

MH4_WellThatsThat:
	.string "Well that's that I guess...$"
	
MH4_IllJustWait:
	.string "I'll just...wait until I'm summoned.$"



MH4_Cam3:
	walk_down
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_down
	walk_down
	step_end
	
MH4_Cam4:
	walk_up
	walk_up
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_up
	step_end

MH4_PlayerToAdmins:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end
	
MH2_MaxiePushesCourtney:
	walk_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end
	
MH2_DelayedStepDown:
	delay_16
	delay_8
	slide_down
	step_end
	
MH4_CourtneyRunsOff:
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
	step_end
	
MH4_MaxieToOffice:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
MH4_BlaiseToOffice:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
MH4_TabithaToExit:
	walk_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
	
	
MH4_AquaSeafloorCavernFinished::
	end
	
MH4_MaxieAwakensGroudon::
	end



	


	
	
	
	
	
