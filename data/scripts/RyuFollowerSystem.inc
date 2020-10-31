@@+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Follower System

RyuCancelFollowerForQuest::  @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	msgbox RyuCantHaveFollower MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq RF_FollowerLeaveCall
	release
	end

RyuResetFollowerPosition::
	end

RyuResetFollowerPositionAR::
	return

RyuForceCancelFollowerForQuest:: @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	call RF_FollowerLeaveCall
	return
	

RyuFollowerSelectNPCScript::
	switch VAR_RYU_FOLLOWER_ID
	case OBJ_EVENT_GFX_TWIN, LRT_MinnieScript
	case OBJ_EVENT_GFX_AQUA_MEMBER_F, RyuFollower_ShellyScript
	case OBJ_EVENT_GFX_WOMAN_2, RyuFollower_LanetteScript
	case OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL, RyuFollower_DawnScript
	case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, RyuFollower_BrendanScript
	case OBJ_EVENT_GFX_LEAF, RyuFollower_LeafScript
	case OBJ_EVENT_GFX_MAGMA_MEMBER_M, GC_BlaiseScript
	case OBJ_EVENT_GFX_MAGMA_MEMBER_F, MH4_CourtneyScript
	case OBJ_EVENT_GFX_NURSE, RyuFollower_NurseJoy
	end

RyuFollower_ShellyScript::
	goto_if_set FLAG_RYU_WAYSTONE_DISABLED, RyuFollower_MagmaShelly
	msgbox RyuFollower_ShellyLeaveMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RyuFollower_MagmaShelly::
	goto MH_FollowerShellyScript
	end
	
RyuFollower_LanetteScript::
	msgbox RyuFollowerLanetteLeaveMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RyuFollower_DawnScript::
	msgbox FollowerDawnChatter, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RyuFollower_BrendanScript::
	msgbox FollowerBrendanChatter, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RyuFollower_LeafScript::
	msgbox FollowerLeafChatter, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RyuFollower_CourtneyScript::
	msgbox RF_CourtneyMsg
	closemessage
	release
	end

RF_CourtneyMsg:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}I will follow you anywhere...\n"
	.string "Do... anything for you.\l"
	.string "Can we go hurt people?$"

RyuFollower_NurseJoy::
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGNURSE
	goto_if_set FLAG_TEMP_8, RyuFollower_NurseAlreadyHealed
	msgbox RF_ShouldIHeal, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RF_NurseHeal
	msgbox RF_OkayHereIfYouNeed
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	release
	end

RF_NurseHeal::
	special HealPlayerParty
	delay 10
	msgbox RF_OkayAllBetter
	setflag FLAG_TEMP_8
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	release
	end

RyuFollower_NurseAlreadyHealed::
	msgbox RF_NurseChatter
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	release
	end

RF_ShouldIHeal:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Should I heal your team?$"

RF_OkayHereIfYouNeed:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Okay, I'll be following if you\nneed me!$"

RF_NurseChatter:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Where should we go next?$"

RF_OkayAllBetter:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Okay!\nAll better!\pTry to be a little more gentle\nplease...$"

FollowerDawnSetup::
	removeobject 2
	createfollower OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL, RyuFollowerSelectNPCScript, DIR_EAST
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceLeft
	waitmovement 0
	clearfullscreenimage
	setflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	msgbox DawnOkLetsGo
	release
	end

FollowerBrendanSetup::
	removeobject 2
	createfollower OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, RyuFollowerSelectNPCScript, DIR_WEST
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceRight
	waitmovement 0
	clearfullscreenimage
	setflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	msgbox BrendanOkLetsGo
	release
	end

FollowerLeafSetup::
	removeobject 2
	createfollower OBJ_EVENT_GFX_LEAF, RyuFollowerSelectNPCScript, DIR_SOUTH
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement 0
	setflag FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO
	msgbox LeafOkLetsGo
	release
	end

FollowerNurseSetup::
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	playse SE_DOOR
	setmetatile 7, 3, 514, 0
	setmetatile 7, 2, 542, 0
	special DrawWholeMapView
	waitse
	setflag FLAG_RYU_HIDE_JOY
	applymovement 1, Common_Movement_StepDown
	waitmovement 1
	removeobject 1
	createfollower OBJ_EVENT_GFX_NURSE, RyuFollowerSelectNPCScript, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	setmetatile 7, 3, 517, 1
	setmetatile 7, 2, 519, 0
	playse SE_DOOR
	special DrawWholeMapView
	waitse
	msgbox NurseOkLetsGo
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	release
	end

NurseOkLetsGo:
	.string "{COLOR LIGHT_RED}{SHADOW RED}It should be okay for me to\nstep out a bit.$"

RF_FollowerLeaveCall::
	msgbox RyuFollowerLeavesService
	switch VAR_RYU_FOLLOWER_ID
	case OBJ_EVENT_GFX_WOMAN_2, Ryu_RestoreLanetteAtHouse
	case OBJ_EVENT_GFX_TWIN, Ryu_RestoreMinnie
	case OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL, Ryu_RestoreDawn
	case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, Ryu_RestoreBrendan
	case OBJ_EVENT_GFX_LEAF, Ryu_RestoreLeaf
	case OBJ_EVENT_GFX_MAGMA_MEMBER_F, Ryu_RestoreCourtney
	case OBJ_EVENT_GFX_AQUA_MEMBER_F, Ryu_RestoreShelly
	case OBJ_EVENT_GFX_NURSE, Ryu_RestoreNurse
	return
	
RF_FollowerLeave::
	call RF_FollowerLeaveCall
	release
	end

Ryu_RestoreLanetteAtHouse::
	destroyfollower
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

Ryu_RestoreMinnie::
	destroyfollower
	clearflag FLAG_RYU_HIDE_MINNIE
	release
	end

Ryu_RestoreDawn::
	destroyfollower
	clearflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	release
	end

Ryu_RestoreBrendan::
	destroyfollower
	clearflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	release
	end

Ryu_RestoreLeaf::
	destroyfollower
	clearflag FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO
	release
	end

Ryu_RestoreCourtney::
	destroyfollower
	clearflag FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY
	addobject 1
	release
	end

Ryu_RestoreShelly::
	destroyfollower
	clearflag FLAG_HIDE_AQUAHQ_SHELLY
	release
	end

Ryu_RestoreNurse::
	destroyfollower
	clearflag FLAG_RYU_HIDE_JOY
	release
	end

@ RyuFollowerToTrainerID will write the current follower’s ID and sprite to VAR_0x8008 and 0x8009
@ and return true if there is a follower or do nothing and return false otherwise.
RyuFollowerAllySelector::
	specialvar VAR_RESULT, RyuFollowerToTrainerID
	compare VAR_RESULT, FALSE
	goto_if_eq ryu_end
	return

LeafOkLetsGo:
	.string "Lana: {COLOR LIGHT_RED}{SHADOW RED}Okay, {PLAYER}!\nI'm as ready as I can be!$"

DawnOkLetsGo:
	.string "Dawn: {COLOR LIGHT_RED}{SHADOW RED}Okay! I'm ready to go!$"

BrendanOkLetsGo:
	.string "Brendan: {COLOR LIGHT_BLUE}{SHADOW BLUE}Okay! Let's hit the road!$"
	
RyuFollower_ShellyLeaveMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Should I go?$"
	
RyuFollowerLanetteLeaveMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lanette: Should I return to my lab??$"

RyuFollowerLeavesService:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Your follower\nleaves your service...$"

RyuCantHaveFollower:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}You're attempting to do a\n"
	.string "cinematic quest.\p"
	.string "You can't have a follower present\n"
	.string "for this quest. Would you like\l"
	.string "to dismiss your follower?$"

FollowerDawnChatter:
	.string "Dawn: {COLOR LIGHT_RED}{SHADOW RED}It's been really nice, hanging\n"
	.string "out with you. I wish we did this\p"
	.string "from the beginning.\p"
	.string "Would you like me to leave?$"

FollowerBrendanChatter:
	.string "Brendan: {COLOR LIGHT_BLUE}{SHADOW BLUE}You should have tagged\n"
	.string "along with me from the start. This\p"
	.string "has been some of the most enjoyable\n"
	.string "time in my life!\p"
	.string "Do you need to be alone?$"

FollowerLeafChatter:
	.string "Lana: {COLOR LIGHT_RED}{SHADOW RED}Boy, this sure brings back\n"
	.string "memories... with Him...\p"
	.string "I'm glad we found each other, really.\n"
	.string "I was in a real dark, place.\p"
	.string "Do you need some space?$"


ryu_return::
	return

ryu_end::
	release
	end

@+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Nurse quest

RyuFollower_CheckNurseQuestStage::
	switch VAR_RYU_DS_NURSE_STAGE
	case 0, ryu_end @@player hasn't met requirements for quest
	case 1, RF_NurseQuestStage1
	case 2, ryu_end
	@case 3, RF_NurseQuestStage2
	@case 5, RF_NurseQuestStage3
	@case 7, RF_NurseQuestStage4
	case 10, ryu_end @@Player already partners with nurse, or declined to help her. Check is no longer necessary.
	goto ryu_end @@prevent UB

RF_SetupNurseSpawnEvent::
	lockall
	goto_if_set FLAG_RYU_HAS_FOLLOWER, ryu_end @@can't do quest if follower is already present.
	setflag FLAG_RYU_HIDE_JOY
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown @@move player down to make space for nurse to spawn
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	drawfullscreenimage SCENEBGNURSE
	createfollower OBJ_EVENT_GFX_NURSE, RyuFollowerSelectNPCScript, DIR_NORTH
	return

RF_NurseQuestStage1::
	call RF_SetupNurseSpawnEvent
	msgbox RF_NurseRequestEscort1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RF_PlayerDeclinedNurseQuest1
	msgbox RF_NurseEscortQuestIntro1
	closemessage
	delay 10
	clearfullscreenimage
	setvar VAR_RYU_DS_NURSE_STAGE, 2
	release
	end

RF_CheckPlayerQualifiesForNurseQuest::@@this is sort of confusing, but it has to check for specific circumstances in order to work globally as is the intent.
	special checkbadgecount
	compare VAR_RESULT, 2
	goto_if_lt ryu_end
	compare VAR_RYU_DS_NURSE_STAGE, 10
	goto_if_eq ryu_end
	compare VAR_RYU_DS_NURSE_STAGE, 0
	call_if_eq RF_StartNurseQuest
	compare VAR_RYU_DS_NURSE_STAGE, 1
	goto_if_eq RF_NurseQuestStage1
	goto ryu_end

RF_StartNurseQuest::
	setvar VAR_RYU_DS_NURSE_STAGE, 2
	goto RyuFollower_CheckNurseQuestStage

RF_NurseRequestEscort1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hey!\nPlease wait a moment!\pWould you be willing to escort\nme to Verdanturf town?$"

RF_NurseEscortQuestIntro1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh! Wonderful! You're so kind!\pI just need help getting to\nVerdanturf.\pI'm not much of a fighter.$"

RF_PlayerDeclinedNurseQuest1::
	setvar VAR_RYU_DS_NURSE_STAGE, 10 @@ends the nurse quest. No partner.
	msgbox RF_NurseQuestCancelledText
	closemessage
	clearfullscreenimage
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	destroyfollower
	release
	end

RF_NurseQuestCancelledText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I see... well... I'm sure another\nstrong trainer will come along...\pSorry for taking up your time.$"

