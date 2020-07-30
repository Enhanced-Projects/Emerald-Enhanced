MagmaHideout_AdminQuarters_MapScripts::
	.byte 0
	
MHA_Courtney::
	msgbox MHA_ComeWithPlayer
	closemessage
	removeobject 1
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_F, RyuFollowerSelectNPCScript, DIR_NORTH
	setflag FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY
	release
	end
	
MHA_ComeWithPlayer:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I will come with {PLAYER} now.$"
	
