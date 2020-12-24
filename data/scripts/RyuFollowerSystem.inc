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
	goto_if_set FLAG_RYU_WAYSTONE_DISABLED, MH_FollowerShellyScript
	msgbox RyuFollower_ShellyLeaveMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
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
	switch VAR_RYU_DS_NURSE_STAGE
	case 2, RF_Nurse_Stage1
	case 4, RF_Nurse_Stage2
	case 6, RF_Nurse_Stage3
	msgbox RF_DismissNurseQuery, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq RyuForceCancelFollowerForQuest
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

FollowerShellySetup::
	applymovement 1, ACO_ShellyWalkAroundDesk
	waitmovement 1
	removeobject 1
	createfollower OBJ_EVENT_GFX_AQUA_MEMBER_F, RyuFollowerSelectNPCScript, DIR_EAST
	setflag FLAG_HIDE_AQUAHQ_SHELLY
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
	closemessage
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
	return

Ryu_RestoreDawn::
	destroyfollower
	clearflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	return

Ryu_RestoreBrendan::
	destroyfollower
	clearflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	return

Ryu_RestoreLeaf::
	destroyfollower
	clearflag FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO
	return

Ryu_RestoreCourtney::
	destroyfollower
	clearflag FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY
	addobject 1
	return

Ryu_RestoreShelly::
	destroyfollower
	clearflag FLAG_HIDE_AQUAHQ_SHELLY
	return

Ryu_RestoreNurse::
	destroyfollower
	clearflag FLAG_RYU_HIDE_JOY
	return

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

RF_CheckPlayerQualifiesForNurseQuest::@ This is the script that activates when player is about to enter a pokemon center that has a gym on it.
	goto_if_unset FLAG_RYU_CAN_DO_NURSE_QUEST, ryu_end
	special checkbadgecount
	compare VAR_RESULT, 2
	goto_if_lt ryu_end
	switch VAR_RYU_DS_NURSE_STAGE
	case 10, ryu_end @@Player finished or cancelled quest. Don't even bother checking other stages.
	case 0, RF_NurseQuestStage1
	case 1, RF_NurseQuestStage1
	case 3, RF_NurseQuestStage2
	case 5, RF_NurseQuestStage3
	case 7, RF_NurseQuestStage4
	goto ryu_end

RF_SetupNurseSpawnEvent:: @Generates a nurse NPC to interact with.
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
	specialvar VAR_RESULT, RyuGetCurrentMapsec
	compare VAR_RESULT, 0x05 @player is already in verdanturf
	goto_if_eq ryu_end
	setflag FLAG_RYU_WAYSTONE_DISABLED
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

RF_NurseQuestStage2::
	specialvar VAR_RESULT, RyuGetCurrentMapsec
	compare VAR_RESULT, 0x04 @player is already in fallarbor
	goto_if_eq ryu_end
	setflag FLAG_RYU_WAYSTONE_DISABLED
	call RF_SetupNurseSpawnEvent
	msgbox RF_NurseRequestEscort2, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RF_PlayerDeclinedNurseQuest1
	msgbox RF_NurseEscortQuestIntro2
	closemessage
	delay 10
	clearfullscreenimage
	setvar VAR_RYU_DS_NURSE_STAGE, 4
	release
	end

RF_NurseQuestStage3::
	specialvar VAR_RESULT, RyuGetCurrentMapsec
	compare VAR_RESULT, 0x01 @player is already in oldale
	goto_if_eq ryu_end
	setflag FLAG_RYU_WAYSTONE_DISABLED
	call RF_SetupNurseSpawnEvent
	msgbox RF_NurseRequestEscort3, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RF_PlayerDeclinedNurseQuest1
	msgbox RF_NurseEscortQuestIntro3
	closemessage
	delay 10
	clearfullscreenimage
	setvar VAR_RYU_DS_NURSE_STAGE, 6
	release
	end

RF_NurseQuestStage4::
	call RF_SetupNurseSpawnEvent
	msgbox RF_NurseRequestEscort4, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RF_PlayerDeclinedNurseQuest1
	msgbox RF_NurseEscortQuestIntro4
	closemessage
	delay 10
	clearfullscreenimage
	setvar VAR_RYU_DS_NURSE_STAGE, 8
	warpsilent MAP_LILYCOVE_CITY_POKEMON_CENTER_2F, 255, 3, 6
	waitstate

VT_FinishNurseQuest1::
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_NURSE
	goto_if_ne ryu_end
	lockall
	msgbox VT_NurseStage1Done
	giveitem ITEM_FULL_RESTORE, 1
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	setflag FLAG_RYU_DS_JOY_ACQ
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_FOLLOWER
	call RF_FollowerLeaveCall
	clearflag FLAG_RYU_HIDE_JOY
	setvar VAR_RYU_DS_NURSE_STAGE, 3
	release
	end

FT_FinishNurseQuest2::
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_NURSE
	goto_if_ne ryu_end
	lockall
	msgbox FT_NurseStage2Done
	giveitem ITEM_MAX_ELIXIR, 1
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	setflag FLAG_RYU_DS_JOY_FRIENDS
	ach give ACH_NEW_REGION_WHO_DIS
	ach give ACH_TRUE_LOVE
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_FOLLOWER
	call RF_FollowerLeaveCall
	clearflag FLAG_RYU_HIDE_JOY
	setvar VAR_RYU_DS_NURSE_STAGE, 5
	release
	end


OT_FinishNurseQuest3::
	compare VAR_RYU_DS_NURSE_STAGE, 6
	goto_if_ne ryu_end
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_NURSE
	goto_if_ne ryu_end
	lockall
	msgbox RC_NurseStage3Done
	giveitem ITEM_PP_MAX, 1
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	setflag FLAG_RYU_DS_JOY_CLOSEFRIENDS
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_FOLLOWER
	call RF_FollowerLeaveCall
	clearflag FLAG_RYU_HIDE_JOY
	setvar VAR_RYU_DS_NURSE_STAGE, 7
	release
	end


RF_FinishNurseQuest4:: @Will take player to lilycove city as that is Hoenn's capital.
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_NURSE
	goto_if_ne ryu_end
	lockall
	msgbox RF_NurseStage4Done
	giveitem ITEM_HP_UP, 4
	setflag FLAG_RYU_DS_JOY_LOVERS
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_FOLLOWER
	call RF_FollowerLeaveCall
	clearflag FLAG_RYU_HIDE_JOY
	setvar VAR_RYU_DS_NURSE_STAGE, 10 @Player did all the nurse quest stages, no longer need to check.
	release
	end


RF_PlayerDeclinedNurseQuest1::
	setvar VAR_RYU_DS_NURSE_STAGE, 10 @@ends the nurse quest. No partner.
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	msgbox RF_NurseQuestCancelledText
	closemessage
	clearfullscreenimage
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	call RF_FollowerLeaveCall
	release
	end

RF_Nurse_Stage1::
	msgbox RF_NurseS1Text
	release
	end

RF_Nurse_Stage2::
	msgbox RF_NurseS2Text
	release
	end
	
RF_Nurse_Stage3::
	msgbox RF_NurseS3Text
	release
	end

RF_DismissNurseQuery::
	.string "{COLOR LIGHT_RED}{SHADOW RED}Would you like for me to leave?$"

RF_NurseS1Text:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Let's continue to Verdanturf!$"

RF_NurseS2Text:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Let's take our time heading\nto Fallarbor.$"

RF_NurseS3Text:	
	.string "{COLOR LIGHT_RED}{SHADOW RED}I'm so happy to have you with me.\pI do need to get to Oldale\neventually though. No hurry!$"

RF_NurseRequestEscort1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hey!\n"
	.string "Please wait a moment!\p"
	.string "Would you be willing to escort\n"
	.string "me to Verdanturf town?$"

RF_NurseEscortQuestIntro1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh! Wonderful! You're so kind!\p"
	.string "I just need help getting to\n"
	.string "Verdanturf.\p"
	.string "I'm not much of a fighter.$"

VT_NurseStage1Done:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Ah! here we are!\p"
	.string "Thank you so much for escorting\n"
	.string "me!\p"
	.string "I can't really offer much\n"
	.string "payment, but perhaps this would\l"
	.string "be useful.$"

RF_NurseRequestEscort2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hey!\n"
	.string "{PLAYER}!\p"
	.string "Can you accompany me to Fallarbor,\n"
	.string "please?$"

RF_NurseEscortQuestIntro2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Great! It really makes me feel\n"
	.string "safer. I appreciate it.$"

FT_NurseStage2Done:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh we made it already!\n"
	.string "Wow, time really flew by.\p"
	.string "Thanks so much for helping, {PLAYER}!$"

RF_NurseRequestEscort3:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hi, {PLAYER}!\n"
	.string "Fancy meeting you here.\p"
	.string "I was just heading to Oldale\n"
	.string "Town.\p"
	.string "Could you please go with me?$"

RF_NurseEscortQuestIntro3:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Excellent!\n"
	.string "I always feel so much safer with\l"
	.string	"you around.$"

RC_NurseStage3Done:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Aww, we're already here...\n"
	.string "Next time let's take the scenic\l"
	.string "route!\p"
	.string "Thanks for spending this time\n"
	.string "with me, {PLAYER}.$"

RF_NurseRequestEscort4:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You notice that she's a little more\n"
	.string " flushed than usual)\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hiya, {PLAYER}!\n"
	.string "Can I escort you...\p"
	.string "To my room?$"

RF_NurseEscortQuestIntro4:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Yay!\n"
	.string "I mean... let's go to Lilycove.\p" 
	.string "It's got my favorite quarters.\n"
	.string "This time I'll take you there!$"

RF_NurseStage4Done:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, We made it to the primary\n"
	.string "Pokecenter in Hoenn.\p"
	.string "My favorite living quarters are\n"
	.string "here.\p"
	.string "Follow me upstairs, please.$"

RF_NurseQuestCancelledText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I see... well... I'm sure another\n"
	.string "strong trainer will come along...\p"
	.string "Sorry for taking up your time.$"

