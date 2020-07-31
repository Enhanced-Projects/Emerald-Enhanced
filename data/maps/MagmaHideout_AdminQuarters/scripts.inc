MagmaHideout_AdminQuarters_MapScripts::
	.byte 0
	
MHA_Courtney::@Still need to add stay the night
	msgbox MHA_ComeWithPlayer
	closemessage
	removeobject 1
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_F, RyuFollowerSelectNPCScript, DIR_NORTH
	setflag FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY
	release
	end
	
MHAQ_CheckTerminateCourtney::
	goto_if_unset FLAG_RYU_HAS_FOLLOWER, ryu_end
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_MAGMA_MEMBER_F
	goto_if_ne ryu_end
	lock
	msgbox MHAQ_DismissCourtney
	call RF_FollowerLeaveCall
	release
	end

MHAQ_DismissCourtney:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Don't stay gone too long...\n"
    .string "Or I will chase you down.$"

MHA_ComeWithPlayer:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I will come with {PLAYER} now.$"
	
MHAQ_Maxie::@@need to add post story events, like maybe heatran
	end
	
MHAQ_Blaise::
	end
