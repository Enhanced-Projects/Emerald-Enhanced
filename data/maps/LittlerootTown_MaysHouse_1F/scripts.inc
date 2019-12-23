LittlerootTown_MaysHouse_1F_MapScripts:: @ 81F88A5
	.byte 0

LRT_leftSideTriggerFemale::
	goto_if_unset FLAG_SYS_GAME_CLEAR, ryu_end
	applymovement EVENT_OBJ_ID_PLAYER, Lrt_trigger_moveRight
	waitmovement 0
	goto LRT_GameClearTriggerFemale
	
LRT_rightSideTriggerFemale::
	goto_if_unset FLAG_SYS_GAME_CLEAR, ryu_end
	applymovement EVENT_OBJ_ID_PLAYER, Lrt_trigger_moveLeft
	waitmovement 0
	goto LRT_GameClearTriggerFemale

LRT_GameClearTriggerFemale::
	call LRT_FemaleRivalDSStage3
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq ryu_end
	goto_if_set FLAG_LATIOS_OR_LATIAS_ROAMING, ryu_end
	goto_if_unset FLAG_SYS_GAME_CLEAR, ryu_end
	applymovement 1, LRT_FemalePlayerMomMeetPlayer
	waitmovement 0
	msgbox LRT_MomGratz MSGBOX_DEFAULT
	closemessage
	applymovement 3, LRT_FemaleplayerDadGratz
	waitmovement 0
	msgbox LRT_FemalePlayerDadMsg MSGBOX_DEFAULT
	closemessage
	giveitem_std ITEM_SS_TICKET
	setflag FLAG_RECEIVED_SS_TICKET
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	setvar VAR_RESULT, 0
	setvar VAR_0x8004, 0
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	applymovement 3, LRT_FemaleDadLeave
	waitmovement 0
	playse SE_DOOR
	removeobject 3
	release
	end
	
LRT_FemalePlayerMomMeetPlayer:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_right
	step_end
	
LRT_FemaleplayerDadGratz:
	walk_up
	walk_left
	walk_left
	walk_up
	walk_in_place_left
	step_end
	
LRT_FemaleDadLeave:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end
	
LRT_MomGratz:
	.string "Mom: Congratulations on beating the\nHoenn  Master!\pI knew you had it in you!\nYou sure showed up your dear 'ol dad!$"
	
LRT_FemalePlayerDadMsg:
	.string "Dad: I... I can't believe it... \pYou succeeded where I failed.\nYou became Master, while I settled for\lLeader.\pI'm so very proud of you!\pI have a gift for you.\nTake this ticket and go to the\lBattle Fronter.\pYou can truly test your skill there!$"
	
LRT_FemaleRivalDSStage3::
	goto_if_set FLAG_RYU_DS_FEMALE_MOM_MET, ryu_end
	goto_if_set FLAG_RYU_DS_DAWN_PARTNERS, LRT_FRDSS3
	return
	
LRT_FRDSS3::
	applymovement 2, LRT_MeetMalePlayer
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LRT_facedown
	msgbox LRT_FemaleRivalMomCuteCouple MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_FEMALE_MOM_MET
	applymovement 2, LRT_ReturnToTable
	waitmovement 0
	return

LRT_FemaleRivalMomCuteCouple:
	.string "You've been spending an awful lot\nof time with my {RIVAL}.\pDon't worry, both me and the Professor\nthink you make a cute couple.\pI'm counting on you to take care\n of my {RIVAL}!$"

LRT_facedown:
	emote_question_mark
	walk_in_place_down
	step_end
	

LRT_MeetMalePlayer:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_up
	step_end
	
LRT_ReturnToTable:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_in_place_left
	step_end
