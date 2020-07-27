GraniteCave_B2F_MapScripts:: @ 822DC79
	.byte 0


GC_Everstone_2::
	goto_if_set FLAG_RYU_PLAYER_HELPING_MAGMA, ryu_end
	giveitem ITEM_EVERSTONE, 1
	setflag FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_1
	release
	end
	
GC_ME_MagmaEverstone::
	goto GC_ME_BlaiseEvent
	end
	
GC_ME_BlaiseEvent:
	lockall
	faceplayer
	msgbox GC_ME_WellLooksLike
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox GC_ME_WhatDontYou
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 10
	setflag FLAG_RYU_HIDE_GC_BLAISE
	addobject 11
	applymovement 11, Common_Movement_FaceRight
	waitmovement 11
	fadescreen FADE_FROM_BLACK
	msgbox GC_ME_BetterWeDo
	closemessage
	applymovement 11, Common_Movement_FaceDown
	waitmovement 11
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq GC_ME_NormalMovement
	goto GC_ME_AlternateMovement
	
	
GC_ME_NormalMovement::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	goto GC_ME_BlaiseContd
	
GC_ME_AlternateMovement::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	goto GC_ME_BlaiseContd
	
	
GC_ME_BlaiseContd::
	msgbox GC_ME_ItsCalledAn
	closemessage
	delay 20
	msgbox GC_ME_AlrightNewbieNext
	closemessage
	applymovement 11, Common_Movement_StepRight
	waitmovement 11
	applymovement 11, Common_Movement_FaceUp
	waitmovement 11
	removeobject 11
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_M, GC_BlaiseScript, DIR_NORTH
	setvar VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_MAGMA_MEMBER_M
	setflag FLAG_RYU_HAS_FOLLOWER
	setflag FLAG_RYU_WAYSTONE_DISABLED
	msgbox GC_ME_BlaiseJoinsYourAdventure
	closemessage
	setvar VAR_RYU_MAGMA, 120@Player is looking for second everstone mount
	release
	end
	
GC_ME_WellLooksLike::
	.string "Well, looks like you can follow\n"
    .string "directions after all.$"

GC_ME_WhatDontYou::
	.string "What? Don't you recognize me?$"
	
GC_ME_BetterWeDo::
	.string "Better? We do run covert operations\n"
    .string "as well y'know. How else would we get\p"
    .string "around Hoenn so easily?$"
    .string "Anyways, take a look at this.$"

GC_ME_ItsCalledAn::
	.string "It's called an Everstone. It hosts a\n"
    .string "strange power that cancels pokémon\p"
    .string "evolution, but it's ultimately\n"
    .string "worthless...$"

GC_ME_AlrightNewbieNext::
	.string "Alright newbie, next assignment. I\n"
    .string "want you to find another of these\p"
    .string "Everstones. It's hidden deeper within\n"
    .string "the cave system.$"
	
GC_ME_BlaiseJoinsYourAdventure::
	.string "This time, I'll tag along as well.\p"
    .string "(Magma Admin Blaise has joined.)$"

@==========================Follower Blaise scripts	
GC_BlaiseScript:
	random 1
	switch VAR_RESULT
	case 0, GC_BlaiseMsg1
	case 1, GC_BlaiseMsg2
	goto GC_BlaiseMsg2
	end
	
GC_BlaiseMsg1:
	msgbox GC_B1Msg
	release
	end
	
GC_BlaiseMsg2:
	msgbox GC_B2Msg
	release
	end

GC_B1Msg:
	.string "Hurry and find that Everstone!$"
	
GC_B2Msg:
	.string "Let's get moving!$"
	
@===========================

GC_ME_Everstone1::
	lock
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	setvar VAR_RYU_MAGMA, 125 @player found the second everstone mound
	msgbox GC_ME_YupRightOn
	closemessage
	addobject 12
	applymovement 12, GC_ME_StevenEntry
	waitmovement 12
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceDown
	waitmovement 0xFF
	msgbox GC_ME_TeamMagma
	closemessage
	msgbox GC_ME_StevenStoneFormer
	closemessage
	msgbox GC_ME_NothingGoodCan
	closemessage
	msgbox GC_ME_YouveGotIt
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, GC_ME_PlayerToSteven
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 12
	msgbox GC_ME_WhatYoureOn
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox GC_ME_QuiteTheEager
	closemessage
	trainerbattle_single TRAINER_STEVEN_STORY1, GC_ME_IllPutBoth, GC_ME_YoullRegretThis, GC_ME_Event3
	waitstate
	end
	
GC_ME_Event3::
	applymovement 12, GC_ME_StevenLeaves
	waitmovement 12
	removeobject 12
	msgbox GC_ME_AndOnThat
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	playfanfare MUS_FANFA1
	giveitem ITEM_MAGMA_EMBLEM, 1
	call RyuGivePokenav
	waitfanfare
	msgbox GC_ME_NowIveGotta
	fadescreen FADE_TO_BLACK
	destroyfollower
	fadescreen FADE_FROM_BLACK
	setvar VAR_RYU_FOLLOWER_ID, 0
	clearflag FLAG_RYU_HAS_FOLLOWER
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	setflag FLAG_RYU_PLAYER_MAGMA_MEMBER
	setvar VAR_RYU_MAGMA, 130@Player defeated steven in granite cave
	release
	end
	
GC_ME_YupRightOn:
	.string "Yup, right on the money. Good work,\n"
    .string "grunt. Now, for our next location...$"
	
GC_ME_TeamMagma:
	.string "Team Magma...$"

GC_ME_StevenStoneFormer:
	.string "Steven Stone, former Hoenn Champion.\n"
    .string "To what do I owe this honor?$"

GC_ME_NothingGoodCan:
	.string "Nothing good can come of this if\n"
    .string "you're here. Leave that Trainer be!$"

GC_ME_YouveGotIt:
	.string "You've got it all wrong, Steven...\n"
    .string "for you see-$"

GC_ME_WhatYoureOn:
	.string "What? You're...on their side!?$"
	
GC_ME_QuiteTheEager:
	.string "Quite the eager one, aren't you?\n"
    .string "Well {PLAYER}, let's see how you do.$"
	
GC_ME_IllPutBoth:
	.string "I'll put both of you in your place!$"

GC_ME_YoullRegretThis:
	.string "You'll regret this, Trainer.$"
	
GC_ME_AndOnThat:
	.string "You've certainly got guts taking on\n"
    .string "Steven...between this and handing\p"
    .string "over the Devon Goods to us, no doubt\n"
    .string "you'll be marked as an enemy of\p"
    .string "Devon Corp. If I were you, I'd steer\n"
    .string "clear of that place.\p"
    .string "Anyways, this is for you. Welcome\n"
    .string "aboard!$"

GC_ME_NowIveGotta:
	.string "Now, I've gotta go file the report\n"
    .string "with Boss, so we'll part ways here.\p"
    .string "You'll be contacted again once we\n"
    .string "have a mission for you. Later!$"
	
GC_ME_StevenEntry:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
	
GC_ME_PlayerToSteven:
	walk_right
	walk_down
	walk_down
	walk_left
	face_down
	step_end
	
GC_ME_StevenLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


















