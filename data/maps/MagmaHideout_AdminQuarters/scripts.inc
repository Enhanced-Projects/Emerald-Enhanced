MagmaHideout_AdminQuarters_MapScripts::
	.byte 0
	
MHA_Courtney::
	lock
	faceplayer
	goto_if_unset FLAG_RYU_DS_COURTNEY_CLOSEFRIENDS, ryu_end
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGCOURTNEY
	goto_if_set FLAG_RYU_DS_COURTNEY_PARTNERS, MHAQ_PartnerCourtney
	msgbox MHAQ_StayTheNight, MSGBOX_YESNO
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	compare VAR_RESULT, YES
	goto_if_eq MHAQ_StayingWithCourtney1
	goto MHAQ_CourtneyFollowerActivate
	
MHAQ_StayingWithCourtney1::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 1, MHAQ_CourtneyToBed
	waitmovement 1
	msgbox MHAQ_WellComeOnThen
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MHAQ_PlayerToBed
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MHAQ_NeverGotTheChance
	closemessage
	fadeoutbgm 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	applymovement 1, Common_Movement_StepLeft
	fadescreen FADE_TO_BLACK
	msgbox MHAQ_PlayerAndCourtney
	setobjectxy 1, 13, 1
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	fadescreen FADE_FROM_BLACK
	playbgm MUS_AJITO, 0
	msgbox MHAQ_PlayerWakesUp
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MHAQ_PlayerToExit
	waitmovement OBJ_EVENT_ID_PLAYER
	setobjectxy 1, 1, 3
	setflag FLAG_RYU_DS_COURTNEY_PARTNERS
	release
	end
	
MHAQ_StayingWithCourtney2::
	msgbox MHAQ_OhYouCouldnt
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 1, MHAQ_CourtneyToBed
	waitmovement 1
	msgbox MHAQ_PlayerThoughts
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MHAQ_PlayerToBed
	waitmovement OBJ_EVENT_ID_PLAYER
	fadescreen FADE_TO_BLACK
	fadeoutbgm 0
	msgbox MHAQ_PlayerAndCourtneyStayedTogether
	closemessage
	delay 30
	applymovement 1, MHAQ_CourtneyToOtherSide
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, MHAQ_PlayerToOtherSide
	waitmovement OBJ_EVENT_ID_PLAYER
	fadescreen FADE_FROM_BLACK
	playbgm MUS_AJITO, 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MHAQ_HowdWeEndUpHere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	applymovement 1, Common_Movement_HeartEmote
	waitmovement 1
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, MHAQ_PlayerToExit2
	waitmovement OBJ_EVENT_ID_PLAYER
	setobjectxy 1, 1, 3
	setflag FLAG_RYU_DS_COURTNEY_PARTNERS
	release
	end
	
MHAQ_CourtneyFollowerActivate::
	msgbox MHAQ_ComeWithPlayer
	closemessage
	removeobject 1
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_F, RyuFollowerSelectNPCScript, DIR_NORTH
	setflag FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY
	clearfullscreenimage
	release
	end

MHAQ_PartnerCourtney::
	msgbox MHAQ_StayTheNight2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MHAQ_StayingWithCourtney2
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	msgbox MHAQ_ComeWithPlayer2
	closemessage
	removeobject 1
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_F, RyuFollowerSelectNPCScript, DIR_NORTH
	setflag FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY
	setvar VAR_TEMP_0, 100
	release
	end
	
MHAQ_CheckTerminateCourtney::
	goto_if_unset FLAG_RYU_HAS_FOLLOWER, ryu_end
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_MAGMA_MEMBER_F
	goto_if_ne ryu_end
	lock
	msgbox MHAQ_AskDismissCourtney, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ryu_end
	setvar VAR_TEMP_0, 100
	msgbox MHAQ_DismissCourtney
	call RF_FollowerLeaveCall
	addobject 1
	release
	end
	
MHAQ_StayTheNight:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Did you come here to stay\nthe night with me?$"
	
MHAQ_StayTheNight2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Came to stay again, eh?\nI'll take care of you...$"
	
MHAQ_OhYouCouldnt:
    .string "{COLOR LIGHT_RED}{SHADOW RED}You couldn't resist any longer, \n"
    .string "could you? No matter...$"

MHAQ_PlayerThoughts:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(There was this one thing you\n wanted to try...\p She'd probably be up for it...)$"
	
MHAQ_PlayerAndCourtneyStayedTogether:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} and Courtney spend another\n"
    .string " night together, this time with a\l"
    .string " new thing you wanted to try.\p"
    .string " She doesn't seem bothered by it...)$"

MHAQ_HowdWeEndUpHere:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Courtney... how'd we get down here?\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}You got a little carried away...\n"
    .string "It's okay though, I had fun.$"

MHAQ_ComeWithPlayer2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Ooooh, up to no good again, huh?\nWell, I'm ready, let's go!$"
	
MHAQ_WellComeOnThen:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Well, come on then. I'll make sure\n"
    .string "you sleep real good tonight, {PLAYER}.\p"
	.string "I've got some stress to work out...$"
	
MHAQ_NeverGotTheChance:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I never got a chance before...\n"
    .string "Now I do, and you can do whatever\l"
    .string "you want to me...$"
	
MHAQ_PlayerAndCourtney:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and Courtney enjoy a night\n"
    .string "of incredible stress relief and joy\p"
    .string "together, relaxing and having fun\n"
    .string "for the first time in a long while...)$"
	
MHAQ_PlayerWakesUp:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(When {PLAYER} wakes up, there's no\n"
    .string " sign of Courtney.\p"
    .string " Presumably she's off doing leader\n"
    .string " things, or making plans.)$"

MHAQ_AskDismissCourtney:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Did you want some space?$"

MHAQ_DismissCourtney:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Don't stay gone too long...\n"
    .string "Or I will chase you down.$"

MHAQ_ComeWithPlayer:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I will come with you now.$"
	
MHAQ_CourtneyToBed:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	face_up
	emote_heart
	step_end
	
MHAQ_PlayerToBed:
	walk_left
	walk_down
	walk_down
	step_end
	
MHAQ_PlayerToOtherSide:
	walk_left
	walk_left
	walk_left
	walk_down
	face_up
	step_end

MHAQ_CourtneyToOtherSide:
	walk_left
	walk_left
	walk_left
	face_up
	step_end
	
MHAQ_PlayerToExit:
	walk_right
	face_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MHAQ_PlayerToExit2:
	walk_up
	walk_up
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
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
	
MHAQ_Maxie::@@need to add post story events, like maybe heatran for when the player didn't romance courtney
	end
	
MHAQ_Blaise::@@need to add post story events for when the player /did/ romance courtney
	end
	
