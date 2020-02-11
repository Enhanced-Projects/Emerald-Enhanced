SealedChamber_InnerRoom_MapScripts:: @ 82391F7
	.byte 0

SCH_OpenDoors:: @ 82391F8
	fadeoutbgm 0
	playse SE_W089
	msgbox SCH_LanaMsgEQ MSGBOX_AUTOCLOSE
	closemessage
	playse SE_W089
	special DoSealedChamberShakingEffect1
	waitstate
	delay 40
	playse SE_W089
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	@msgbox gUnknown_0827301B, MSGBOX_DEFAULT
	@closemessage
	fadeinbgm 0
	setflag FLAG_REGI_DOORS_OPENED
	compare VAR_RYU_DS_LANA_STAGE, 41
	goto_if_ne ryu_end
	return
	releaseall
	end

SealedChamber_InnerRoom_EventScript_NoEffect:: @ 8239253
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart1:: @ 8239255
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart2:: @ 823925F
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart3:: @ 8239269
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart4:: @ 8239273
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_WeFearedIt
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart5:: @ 823927D
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart6:: @ 8239287
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
	waitbuttonpress
	closebraillemessage
	releaseall
	end
	
@==================================================================================================LANA SCRIPTS

SCH_LanaCheck::
	compare VAR_RYU_DS_LANA_STAGE, 30
	goto_if_ne ryu_end
	addobject 1
	clearflag FLAG_HIDE_SCH_LANA
	setvar VAR_RYU_DS_LANA_STAGE, 35
	release
	end

SCH_LanaEvent::
	faceplayer
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	specialvar VAR_RESULT, IsWailordInParty
	compare VAR_RESULT, 1
	goto_if_ne SCH_LanaDispt
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 1
	msgbox SCH_LanaMsg MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	msgbox SCH_LanaMsg2 MSGBOX_DEFAULT
	setflag FLAG_RYU_DO_NOT_AUTOSCALE
	setvar VAR_RYU_DS_LANA_STAGE, 40
	cleartrainerflag TRAINER_STORY_LEAF
	trainerbattle_no_intro TRAINER_STORY_LEAF, SCH_Victory
	goto SCH_AfterBattle
	release
	end
	
SCH_LanaDispt::
	msgbox SCH_LanaDisptMsg MSGBOX_DEFAULT
	applymovement 1 Common_Movement_FaceUp
	waitmovement 1
	release
	end
	
SCH_AfterBattle::
	setvar VAR_RYU_DS_LANA_STAGE, 41
	applymovement 1, SCH_Fall
	clearflag FLAG_RYU_DO_NOT_AUTOSCALE
	call SCH_OpenDoors
	applymovement 1, SCH_diagonal
	applymovement EVENT_OBJ_ID_PLAYER, SCH_diagonal
	waitmovement 1
	msgbox SCH_LanaMsg3 MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	drawheadshot HEAD_LANA
	msgbox SCH_LanaMsg4 MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	applymovement 1, SCH_LanaLeaves
	waitmovement 1
	removeobject 1
	setflag FLAG_HIDE_SCH_LANA
	msgbox SCH_PlayerMsg1 MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_LEAF_CLOSEFRIENDS
	goto_if_set FLAG_DEFEATED_REGIROCK, SCH_AlternateStoryTrigger
	goto_if_set FLAG_DEFEATED_REGICE, SCH_AlternateStoryTrigger
	goto_if_set FLAG_DEFEATED_REGISTEEL, SCH_AlternateStoryTrigger
	setvar VAR_RYU_DS_LANA_STAGE, 45
	clearflag FLAG_HIDE_DR_LANA
	release
	end
	
SCH_AlternateStoryTrigger::
	goto_if_set FLAG_RYU_DS_LANETTE_FRIENDS, Ryu_CancelLeafLanetteQuest
	setflag FLAG_RYU_LEAF_ALTERNATE_LINE
	fadenewbgm MUS_RG_NANADUNGEON
	msgbox SCH_AltStory1 MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox SCH_AltStory2 MSGBOX_DEFAULT
	drawheadshot HEAD_LANA
	msgbox SCH_AltStory22 MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	msgbox SCH_AltStory23 MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

Ryu_CancelLeafLanetteQuest::
	fadenewbgm MUS_RG_NANADUNGEON
	msgbox SCH_AltStory1 MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox SCH_AltAnotherNote
	setflag FLAG_RYU_DS_LEAF_LINE_CANCELLED
	setvar VAR_RYU_DS_LANA_STAGE, 666
	release
	end

	
SCH_AltStory1:
	.string "Another note...$"

SCH_AltAnotherNote:
    .string "There's another note..."
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'm going to go back to Kanto.\p"
    .string "I need some time to myself to\n"
    .string "reflect on things.\p"
	.string "There's nothing in Hoenn for me\n"
	.string "to focus on.\p"
    .string "Please, don't follow me. I want to\n"
    .string "be left alone.$"

	
SCH_AltStory2:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Wait, what's this?$"
	
SCH_AltStory22:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I don't deserve this...I can't go\non as if nothing happened. It'll\lonly wear me down...\pNo, it already has. There's no\nescaping this life...perhaps if I\p"
    .string "pay my respects, then this demon\nwill go away...$"
	
SCH_AltStory23:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Well if I wasn't worried enough\nthen, now I really am...\pLana...what's happening to you?$"


SCH_Fall:
	walk_fastest_down
	step_end
	
SCH_diagonal:
	walk_diag_southwest
	walk_in_place_fastest_up
	step_end
	
SCH_Ellipsis:
	.string "...$"
	
SCH_LanaDisptMsg:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She looks expectantly at you...\n soon frowning in disappointment.\p Am I missing something?)$"
	
SCH_LanaMsg:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Whew...I finally found you. Sure\ntook a while.\p{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ...$"
	
SCH_LanaMsg2:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She swipes a pokéball from your\n belt and puts it in your hand,\l soon after, taking out hers.)\p{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: What, you wanna battle?\pFine by me!\nGimme your best shot!$"
	
SCH_LanaMsg3:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}:Hey, you okay?\p{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ...$"

SCH_LanaMsgEQ:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(An earthquake suddenly occurs,\n causing Lana to crash into {PLAYER}.)$"

SCH_LanaMsg4:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana smiles in response before\n surprisingly opening her mouth.)\p{COLOR LIGHT_RED}{SHADOW RED}See...you...$"

SCH_Victory:
	.string "Strangely... \nshe seems happy she lost...$"

SCH_PlayerMsg1:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You begin to feel the slight\n pressure in your chest from\l before...motivating you to\l continue chasing after her.)$"
	
SCH_LanaLeaves:
	walk_right
	walk_in_place_left
	delay_8
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end
	
SCH_PlayerMoves:
	walk_fast_right
	step_end

