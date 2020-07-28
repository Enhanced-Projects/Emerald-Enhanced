@@+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Follower System

RyuCancelFollowerForQuest::  @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	msgbox RyuCantHaveFollower MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq RF_FollowerLeaveCall
	release
	end

RyuResetFollowerPosition::
	gfec
	setobjectxy OBJ_EVENT_ID_FOLLOWER, VAR_TEMP_E, VAR_TEMP_F
	setvar VAR_TEMP_D, 1
	end

RyuResetFollowerPositionAR::
	gfec
	setobjectxy OBJ_EVENT_ID_FOLLOWER, VAR_TEMP_E, VAR_TEMP_F
	setvar VAR_TEMP_D, 1
	return

RyuForceCancelFollowerForQuest:: @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	goto RF_FollowerLeaveCall
	

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

RF_FollowerLeaveCall::
	clearflag FLAG_RYU_HAS_FOLLOWER
	destroyfollower
	setvar VAR_RYU_FOLLOWER_ID, 0
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_WOMAN_2
	goto_if_eq Ryu_RestoreLanetteAtHouse
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_TWIN
	goto_if_eq Ryu_RestoreMinnie
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL
	goto_if_eq Ryu_RestoreDawn
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	goto_if_eq Ryu_RestoreBrendan
    compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_LEAF
    goto_if_eq Ryu_RestoreLeaf
	return
	
RF_FollowerLeave::
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_WOMAN_2
	call_if_eq Ryu_RestoreLanetteAtHouse
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_TWIN
	call_if_eq Ryu_RestoreMinnie
	clearflag FLAG_RYU_HAS_FOLLOWER
	destroyfollower
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	release
	end

Ryu_RestoreLanetteAtHouse::
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

Ryu_RestoreMinnie::
	clearflag FLAG_RYU_HIDE_MINNIE
	release
	end

Ryu_RestoreDawn::
	clearflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	release
	end

Ryu_RestoreBrendan::
    clearflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
    release
    end

Ryu_RestoreLeaf::
    clearflag FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO
    release
    end

RyuFollowerAllySelector::
	special RyuFollowerToTrainerID
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

