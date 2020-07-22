AquaHideout_B2F_MapScripts:: @ 8233DCF
	map_script ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition: @ 8233DD5
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing:: @ 8233DDF
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer:: @ 8233DE5
	lockall
	goto_if_set FLAG_RYU_PLAYER_HELPING_DEVON, AC_DevonTrigger
	goto_if_set FLAG_RYU_ARCHIE_SUCCESSFUL, ryu_end
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	applymovement OBJ_EVENT_ID_PLAYER, AC_MoveLeft
	setvar VAR_0x8008, 1  @ Matt object event id
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AC_DevonTrigger:
	goto_if_set FLAG_RYU_SUB_ROOM_SHELLY, ryu_end
	addobject 8
	applymovement 8, AC_ShellyAttacksPlayer
	waitmovement 8
	msgbox AC_ShellyAttacks MSGBOX_DEFAULT
	closemessage
	cleartrainerflag TRAINER_SHELLY_2
	trainerbattle_single TRAINER_SHELLY_2, AC_Intro, AC_Defeat, AC_AfterFight
	
AC_AfterFight:
	msgbox AC_ShellyOutro MSGBOX_DEFAULT
	closemessage
	applymovement 8, AC_ShellyExiting
	waitmovement 8
	playse SE_TK_WARPOUT
	waitse
	removeobject 8
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	setflag FLAG_RYU_SUB_ROOM_SHELLY
	release
	end
	
AC_ShellyAttacksPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	emote_exclamation_mark
	step_end
	
AC_MoveLeft:
	walk_left
	emote_exclamation_mark
	step_end
	
AC_ShellyExiting:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end
	
AC_ShellyAttacks:
	.string "Woman: Who the hell are you and\n"
    .string "why are you trespassing in our\l"
    .string "hideout? Who let you in?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: I'm here to reclaim some\n"
    .string "stolen property. Heard of a\l"
    .string "radiation detector? It's owner\p"
    .string "wants it back, and I'm not leaving\n"
    .string "without it.$"
	
AC_Intro:
    .string "Shelly: Well, buddy, you stumbled\n"
    .string "onto the Worst possible person.\p"
    .string "I'm the administrator of this here\n"
    .string "structure. You will regret your\l"
    .string "trespassing very soon!$"

AC_Defeat:
    .string "I don't believe it!\p"
    .string "Mercenaries are getting pretty\n"
    .string "handsome these days...$"

AC_ShellyOutro:
    .string "Shelly: Fine... good luck finding\n"
    .string "it. I put that thing down a long\l"
    .string "time ago. I have no clue where it's\l"
    .string "at now.\p"
	.string "Pray you don't run into Matt...\p"
    .string "He will turn your world\n"
    .string "inside out.$"
	
AC_DevonMattTrigger::
	goto_if_unset FLAG_RYU_PLAYER_HELPING_DEVON, AC_NormalWarp
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	delay 10
	warpteleport MAP_AQUA_HIDEOUT_B1F, 255, 23, 10
	release
	end
	
AC_SetMissionDone::
	lockall
	setflag FLAG_RYU_DEVON_MISSION5COMPLETE
	release
	end
	
AC_MattTrigger::
	lockall
	goto_if_set FLAG_HIDE_CHAMPIONS_ROOM_RIVAL, ryu_end
	playse SE_PIN
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 10
	applymovement 10, AC_MattToPlayer
	waitmovement 10
	msgbox AC_MattIntercept MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_MATT, AC_Mattintro, AC_MattDefeat, AC_MatOutro
	
AC_MatOutro::
	msgbox AC_MattDefeated MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AC_PlayerMove
	applymovement 10, AC_MattExit
	waitmovement 10
	playse SE_TK_WARPOUT
	waitse
	removeobject 10
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	special DrawWholeMapView
	release
	end
	
AC_MattIntercept:
    .string "Matt: Ah, so you did show up.\p"
    .string "Shelly told me there was a stranger\n"
    .string "here. I guess this is the end of\l"
    .string "the line, friend.$"
	
AC_Mattintro:
	.string "Prepare to be\n"
    .string "expelled violently.$"
	
AC_MattDefeat:
	.string "No kidding! You're tough.$"
	
AC_MattDefeated:
    .string "Matt: Shelly was also right about\n"
    .string "you being one tough customer.\p"
    .string "Well, It didn't accomplish anything\n"
    .string "for you, but you win. Maybe one\l"
    .string "of the other Aqua members can stop\l"
    .string "you\p"
	.string "You should leave before Archie\n"
    .string "gets back. He'll really hurt you.$"
	
AC_MattExit:
	walk_right
	walk_in_place_down
	step_end

AC_PlayerMove:
	walk_down
	walk_in_place_up
	step_end

AC_MattToPlayer:
	walk_left
	walk_down
	walk_right
	walk_in_place_right
	step_end

AC_NormalWarp::
	warpteleport MAP_AQUA_HIDEOUT_B1F, 255, 32, 20
	release
	end

AquaHideout_B2F_EventScript_Matt:: @ 8233E09
	goto_if_set FLAG_RYU_ARCHIE_SUCCESSFUL, AquaHideoutKyogreGuardian
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	release
	end

AquaHideoutKyogreGuardian::
	lockall
	faceplayer
	msgbox KyogreGuardian
	closemessage
	giveitem ITEM_NET_BALL, 20
	msgbox KGGoodluck
	closemessage
	setflag FLAG_RYU_DEVON_HIDE_MATT_SUB
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_StepRight
	waitmovement EVENT_OBJ_ID_PLAYER
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	applymovement 1, KyogreGuardianLeaves
	waitmovement 1
	playse SE_TK_WARPOUT
	removeobject 1
	waitse
	release
	end

KyogreGuardian:
    .string "Matt: Heya {PLAYER}. I've been\n"
    .string "keeping an eye on Kyogre until you\p"
    .string "got here. It's been suprisingly calm,\n"
    .string "though I think it's because Archie\p"
    .string "told it that a powerful trainer was\n"
    .string "coming.\p"
    .string "Anyways... Here's some Net Balls, you\n"
    .string "may need them.$"

KGGoodluck:
    .string "Well... I'm off to explore the ocean\n"
    .string "to see where would be good ingress\p"
    .string "points to start expanding the sea.\n"
    .string "Good Luck, Soldier!$"

KyogreGuardianLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

AHQ_KyogreTrigger::
	goto_if_unset FLAG_RYU_AQUA_LINE_DONE, ryu_end
	goto AHQ_Kyogre

AHQ_Kyogre::
	goto_if_set FLAG_RYU_KYOGRE, ryu_end
	msgbox AHQ_KYOGRE_STARING
	setvar VAR_TEMP_5, SPECIES_KYOGRE
	setvar VAR_TEMP_9, ITEM_MYSTIC_WATER
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, AHQ_KyogreGotAway
	case B_OUTCOME_LOST, AHQ_KyogreGotAway
	case B_OUTCOME_MON_FLED, AHQ_KyogreGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, AHQ_KyogreGotAway
	setflag FLAG_RYU_KYOGRE
	removeobject 7 @Put the porymap object ID here
	release
	end

AHQ_KyogreGotAway::
	setflag FLAG_RYU_KYOGRE_RAN
	removeobject 7 @Put the porymap object ID here
	release
	end
	
AHQ_KYOGRE_STARING:
	.string "Kyogre is staring intently at you.$"

AquaHideout_B2F_EventScript_SubmarineEscape:: @ 8233E25
	setvar VAR_0x8008, 1  @ Matt object event id
	setvar VAR_0x8009, 4  @ Submarine object event id
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft: @ 8233E80
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AquaHideout_B2F_EventScript_Grunt4:: @ 8233E8A
	trainerbattle_single TRAINER_GRUNT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated:: @ 8233EA5
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6:: @ 8233EAF
	trainerbattle_single TRAINER_GRUNT_22, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8:: @ 8233EC6
	trainerbattle_single TRAINER_GRUNT_26, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro: @ 8233EDD
	.string "Hehehe…\p"
	.string "Got here already, did you?\n"
	.string "We underestimated you!\p"
	.string "But this is it!\p"
	.string "I'm a cut above the GRUNTS you've seen\n"
	.string "so far.\p"
	.string "I'm not stalling for time.\n"
	.string "I'm going to pulverize you!$"

AquaHideout_B2F_Text_MattDefeat: @ 8233F8D
	.string "Hehehe…\n"
	.string "So, I lost, too…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations: @ 8233FA6
	.string "Hehehe!\p"
	.string "While I was toying with you, our BOSS\n"
	.string "got through his preparations!$"

AquaHideout_B2F_Text_MattPostBattle: @ 8233FF2
	.string "Hehehe!\p"
	.string "Our BOSS has already gone on his way to\n"
	.string "some cave under the sea!\p"
	.string "If you're going to give chase, you'd\n"
	.string "better search the big, wide sea beyond\l"
	.string "LILYCOVE.\p"
	.string "But will you find it then?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro: @ 82340B4
	.string "Wahahah, I grew weary of waiting!\n"
	.string "You owe me a battle, too!$"

AquaHideout_B2F_Text_Grunt4Defeat: @ 82340F0
	.string "Tired of waiting…\n"
	.string "Lost and dazed…$"

AquaHideout_B2F_Text_Grunt4PostBattle: @ 8234112
	.string "BOSS…\n"
	.string "Is this good enough?$"

AquaHideout_B2F_Text_Grunt6Intro: @ 823412D
	.string "Warp panels, the HIDEOUT's pride\n"
	.string "and joy!\p"
	.string "You're clueless about where you are,\n"
	.string "aren't you?\p"
	.string "Fluster and tire out the enemy, then\n"
	.string "lower the boom! That's our plan!$"

AquaHideout_B2F_Text_Grunt6Defeat: @ 82341CE
	.string "What's wrong with you?\n"
	.string "You're not tired at all!$"

AquaHideout_B2F_Text_Grunt6PostBattle: @ 82341FE
	.string "That reminds me… I can't remember\n"
	.string "where I put the MASTER BALL.\p"
	.string "If I fail to guard it, our BOSS will\n"
	.string "chew me out…$"

AquaHideout_B2F_Text_Grunt8Intro: @ 823426F
	.string "When I joined Team Aqua, the first\n"
	.string "thing I had to learn was how these\l"
	.string "warp panels connected.$"

AquaHideout_B2F_Text_Grunt8Defeat: @ 82342CC
	.string "I was too occupied thinking about\n"
	.string "the warp panels…$"

AquaHideout_B2F_Text_Grunt8PostBattle: @ 82342FF
	.string "I'll have to learn about how I can\n"
	.string "battle more effectively…$"
