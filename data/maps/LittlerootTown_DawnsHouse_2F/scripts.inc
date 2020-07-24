LittlerootTown_DawnsHouse_2F_MapScripts:: @ 81F83E3
	map_script ON_FRAME, GameIntroSequenceCheck
	.byte 0

LRT_DawnAfterLilycoveSequence:: @ 81F951D
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_eq LRT_DawnIntroductionScene
	lock
	faceplayer
	goto_if_set FLAG_RYU_DS_DAWN_LOVERS, LRT_NIGHT2
	goto_if_set FLAG_RYU_DS_DAWN_ACQ, LRT_FZ
	specialvar VAR_RESULT, IsSneaselInParty
	compare VAR_RESULT, 1
	call_if_eq LRT_RivalsPokemonIsInParty
	msgbox LRT_DAWN_SORRYKISSED, MSGBOX_DEFAULT
	msgbox LRT_DAWN_KISS, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LRT_WONT_HAPPEN
    setflag	FLAG_RYU_DS_DAWN_CLOSEFRIENDS
	msgbox LRT_HAPPY, MSGBOX_DEFAULT
	goto LRT_NIGHT
	release
	end
	
LRT_RivalsPokemonIsInParty::
    goto_if_unset FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, LRT_NotReceived
	setflag FLAG_RYU_DS_DAWN_CLOSEFRIENDS
	msgbox LRT_RivalHappy MSGBOX_DEFAULT
	msgbox LRT_KeepQuery MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LRT_RivalLetDown
	msgbox LRT_ThanksForRaisingPokemon MSGBOX_DEFAULT
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	goto LRT_NIGHT
	
LRT_NotReceived::
	setflag FLAG_RYU_DAWN_GIFTPOKE_RECEIVED
	msgbox LRT_DAWN_SORRYKISSED, MSGBOX_DEFAULT
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	msgbox LRT_DAWN_KISS, MSGBOX_YESNO
	nop
    compare VAR_RESULT, 1
	goto_if_eq LRT_WONT_HAPPEN
    setflag	FLAG_RYU_DS_DAWN_CLOSEFRIENDS
	msgbox LRT_HAPPY, MSGBOX_DEFAULT
	goto LRT_NIGHT
	release
	end
	
LRT_RivalLetDown::
	msgbox LRT_RLD MSGBOX_DEFAULT
	goto LRT_NotReceived
	
LRT_RLD:
	.string "Well at least it got to stretch a\n"
	.string "little bit, I don't think I'd have\p"
	.string "been able to train it at all. \n"
	.string "thanks for keeping it company\p"
	.string "So, anyways...$"
	
LRT_RivalHappy:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: I'm so glad you decided to\n"
	.string "raise Sneasel. It really needed a\p"
	.string "masculine touch.$"

LRT_KeepQuery:
	.string "Do you plan on keeping it for\p"
	.string "the rest of your quest to \n"
	.string "become the Hoenn Master?$"
	
LRT_ThanksForRaisingPokemon:
	.string "Awesome. I think it'll be a great\n"
	.string "addition to your team!\p"
	.string "... ... ...\n"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(her face flushes a little)\p"
	.string "umm...$"

LRT_WONT_HAPPEN::
	setflag FLAG_RYU_DAWN_GIFTPOKE_RECEIVED @Makes it impossible to get the sneasel after this event.
    msgbox LRT_SORRY, MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_DAWN_ACQ @0x4A3
	msgbox LRT_BADEND, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER LRT_TURN
	waitmovement 0
	release
	end

LRT_NIGHT::
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGNIGHTDAWN
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
    msgbox LRT_STAY, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LRT_CANCEL
	msgbox LRT_ROMPre MSGBOX_DEFAULT
 	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	applymovement 2, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	applymovement 2 LRT_HEART2
	applymovement OBJ_EVENT_ID_PLAYER LRT_HEART
	fadescreen FADE_TO_BLACK
	delay 20
	fadeoutbgm 1
	special HealPlayerParty
	delay 20
	setobjectxy 2, 8, 2
	msgbox LRT_ROM, MSGBOX_DEFAULT
	fadescreen 0
	fadeinbgm 1
	msgbox LRT_DAWN_THANKS, MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_DAWN_LOVERS
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER LRT_HEART3
	waitmovement 0
	release
	end

LRT_NIGHT2::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGNIGHTDAWN
    msgbox LRT_STAY2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LRT_CANCEL
	msgbox LRT_ROM2Pre MSGBOX_DEFAULT
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement 2, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	applymovement 2, LRT_HEART2
	applymovement OBJ_EVENT_ID_PLAYER, LRT_HEART
	delay 20
	fadescreen FADE_TO_BLACK
	fadeoutbgm 1
	special HealPlayerParty
	delay 20
	msgbox LRT_ROM2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RYU_DS_DAWN_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGNIGHTDAWN
	fadeinbgm 1
	msgbox LRT_DAWN_THANKS2 MSGBOX_DEFAULT
	closemessage
	clearfullscreenimage
	setobjectxy 2, 8, 2
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER LRT_HEART3
	waitmovement 0
	release
	end

LRT_CANCEL::
	msgbox FollowerDawnQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FollowerDawnSetup
    msgbox LRT_DISPT MSGBOX_DEFAULT
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	release
	end

LRT_FZ::
    msgbox LRT_DS_FZ_DAWN MSGBOX_DEFAULT
	closemessage
	release
	end

FollowerDawnQuery:
    .string "I'd really like to get out for a\n"
    .string "while.\pOoh! did you come to get me?$"

LRT_BADEND:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You see sadness and disappointment in\n"
	.string "her eyes as you turn away...)$"

LRT_DAWN_KISS:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Did my kiss bother you? It just\n"
	.string "felt right at the time...$"

LRT_DISPT:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She looks a little disappointed.)$"

LRT_ROMPre:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Sorry, my bed might be a little small...$"
	
LRT_ROM:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and {RIVAL}{COLOR LIGHT_GREEN}{SHADOW GREEN} cuddled together\n"
	.string " and then enjoyed a long night's rest.)$"
	
LRT_ROM2Pre:
	.string "{COLOR LIGHT_RED}{SHADOW RED}It's so nice, snuggling with you,\n"
	.string "forgetting everything else.\p"
	.string "It always calms me down, no matter\n"
	.string "how much stress I have.$"

LRT_ROM2:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and {RIVAL}{COLOR LIGHT_GREEN}{SHADOW GREEN} deviously cuddle\n"
	.string " together for another night.)$"

LRT_DS_FZ_DAWN:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: Oh, hi, {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}. What are you\n"
	.string "up to today?$"

LRT_HAPPY:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: Oh, {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, what am I going\n"
	.string "to do with you.\p"
	.string "I'm glad you're not\n"
	.string "mad at me.$" 

LRT_STAY:
    .string "{COLOR LIGHT_RED}{SHADOW RED}So, {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, did you want to stay the\n"
	.string "night with me?$"

LRT_STAY2:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: Did you come to stay\n"
    .string "the night with me again?$"

LRT_SORRY:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'm sorry {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, I thought you\n"
	.string "liked me. It won't happen again.$"

LRT_DAWN_SORRYKISSED:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}!\p"
	.string "I'm sorry I kissed you.$"

LRT_DAWN_THANKS:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: I've never slept so good in my\n"
	.string "life. Thanks for spending the night\l"
	.string "with me.$"

LRT_DAWN_THANKS2:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Thanks for staying with me for another\n"
	.string "night. You might get me addicted...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(she gives a sheepish smile)$"

LRT_HEART:
	walk_down
	walk_left
	walk_down
	walk_right
	step_end

LRT_HEART2:
	walk_down
	walk_down
	walk_left
	step_end

LRT_HEART3:
	walk_left
	walk_left
	face_right
	delay_16
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

LRT_TURN:
    walk_left
	step_end

	@goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_1F954A

EventScript_PlayerPCFemale:: @ 81F9553
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_DawnsHouse_2F_EventScript_1F956C
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_DawnsHouse_2F_EventScript_1F9576
	end

LRT_PlayerPC:: @ 81F9576
	setvar VAR_0x8004, 2
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gUnknown_08272D87, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LRT_PlayerPC2:: @ 81F958F
	setvar VAR_0x8004, 2
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end
	
	
LRT_DawnIntroductionScene::
	lock
	faceplayer
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 0
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	msgbox GI_DawnIntro MSGBOX_DEFAULT
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	applymovement 2, GI_LeavingForRoute103
	waitmovement 0
	playse SE_DOOR
	removeobject 2
	setflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	msgbox GI_DawnMetMsg
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	additem ITEM_GO_GOGGLES, 1
	setflag FLAG_RECEIVED_GO_GOGGLES
	setflag FLAG_SYS_NATIONAL_DEX
	setflag FLAG_RYU_LT_RIVAL
	setflag FLAG_RYU_LT_RIVAL2
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	special EnableNationalPokedex
	setvar VAR_LITTLEROOT_INTRO_STATE, 8
	setflag FLAG_RYU_MET_RIVAL_LITTLEROOT
	release
	end
	
GI_DawnIntro:
	.string "{RIVAL}{COLOR LIGHT_RED}{SHADOW RED}: Oh? Who are you, and why\nare you in my room?\pOh, you're {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, Norman's son.\pI meant to say hi to you at some\npoint. I've been looking for a\lfriend to run around with when\ldoing tasks for my dad, Prof\lBirch.\pIt gets lonely at times.\p"
    .string "So, did you want me to catch you\la Pokémon?\pI can go grab you one\nfrom Route 101.\pOh! Shoot! I was supposed to go\nstudy Pokémon behaviors at Route 103!!\pSorry, {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, I have to run!$"
	
GI_DawnMetMsg:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN} (She seems like the outgoing sort.\p Not too shy, either.\n You can see yourself being good\l friends with her.)$"
	
GI_LeavingForRoute103:
	emote_exclamation_mark
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end
