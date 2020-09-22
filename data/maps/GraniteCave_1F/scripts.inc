GraniteCave_1F_MapScripts:: @ 822DA5D
	.byte 0
	
GC_CheckMagmaMissionState::
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_MAGMA_MEMBER_M
	goto_if_ne ryu_end
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepUp
	msgbox GC_ME_CantLeaveUntilMission
	closemessage
	release
	end
	
GC_ME_CantLeaveUntilMission:
	.string "Blaise: You can't leave, we're\nnot done here, yet.\pGet to finding that stone!$"

GraniteCave_1F_EventScript_Hiker:: @ 822DA5E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM51, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_TM61
	setflag FLAG_RECEIVED_TM51
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash:: @ 822DA8A
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo: @ 822DA94
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "He didn't need this, so I'll\l"
	.string "give it to you!$"

GraniteCave_1F_Text_ExplainFlash: @ 822DBB7
	.string "That move flings gravel at\nthe enemy and can flinch.$"

