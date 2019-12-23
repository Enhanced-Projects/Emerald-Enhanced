LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
    .byte 0


LRT_leftSideTrigger::
	goto_if_unset FLAG_SYS_GAME_CLEAR, ryu_end
	applymovement EVENT_OBJ_ID_PLAYER, Lrt_trigger_moveRight
	waitmovement 0
	goto LRT_GameClearTriggerMale
	
LRT_rightSideTrigger::
	goto_if_unset FLAG_SYS_GAME_CLEAR, ryu_end
	applymovement EVENT_OBJ_ID_PLAYER, Lrt_trigger_moveLeft
	waitmovement 0
	goto LRT_GameClearTriggerMale
	
LRT_GameClearTriggerMale::
	call LRT_maleRivalDSStage3
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq ryu_end
	goto_if_set FLAG_LATIOS_OR_LATIAS_ROAMING, ryu_end
	goto_if_unset FLAG_SYS_GAME_CLEAR, ryu_end
	applymovement 1, LRT_MalePlayerMomMeetPlayer
	waitmovement 0
	msgbox LRT_MomGratz MSGBOX_DEFAULT
	closemessage
	applymovement 3, LRT_MaleplayerDadGratz
	waitmovement 0
	msgbox LRT_MalePlayerDadMsg MSGBOX_DEFAULT
	closemessage
	giveitem_std ITEM_SS_TICKET
	setflag FLAG_RECEIVED_SS_TICKET
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	setvar VAR_RESULT, 1
	setvar VAR_0x8004, 1
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	applymovement 3, LRT_MaleDadLeave
	waitmovement 0
	playse SE_DOOR
	removeobject 3
	release
	end
	
Lrt_trigger_moveRight:
	walk_right
	walk_in_place_down
	emote_question_mark
	step_end
	
Lrt_trigger_moveLeft:
	walk_left
	walk_in_place_down
	emote_question_mark
	step_end
	
LRT_MalePlayerMomMeetPlayer:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_left
	step_end
	
LRT_MaleplayerDadGratz:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_in_place_right
	step_end
	
LRT_MaleDadLeave:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	step_end
	
LRT_MalePlayerDadMsg:
	.string "Dad: I... I can't believe it... \pYou succeeded where I failed.\nYou became Master, while I settled for\lLeader.\pI'm so very proud of you!\pI have a gift for you.\nTake this ticket and go to the\lBattle Fronter.\pYou can truly test your skill there!$"

LRT_maleRivalDSStage3::
	goto_if_set FLAG_RYU_DS_MALE_MOM_MET, ryu_end
	goto_if_set FLAG_RYU_DS_BRENDAN_PARTNERS, LRT_MRDSS3
	return
	
LRT_MRDSS3::
	applymovement 2, LRT_MeetFemalePlayer
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LRT_facedown
	msgbox LRT_maleRivalMomCuteCouple MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_MALE_MOM_MET
	applymovement 2, LRT_ReturnToTable2
	waitmovement 0
	return

LRT_maleRivalMomCuteCouple:
	.string "You've been spending an awful lot\nof time with my {RIVAL}.\pDon't worry, both me and the Professor\nthink you make a cute couple.\pI'm counting on you to take care\n of my {RIVAL}!$"

LRT_MeetFemalePlayer:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end
	
LRT_ReturnToTable2:

	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_Right
	step_end


