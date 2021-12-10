
MC_GC_GiftCodeNPC::
	lock
	msgbox MC_GC_GiftIntro MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 0
	goto MC_GC_MENU

MC_GC_MENU::
	numberentry 0, 9, 3
	switch VAR_RESULT
	case 649, MasterBallReward
	case 622, KoutaMawileReward
	goto MC_GC_NOREWARDSCCR

MC_GC_NOREWARDSCCR::
	msgbox MC_GC_NOREWARD MSGBOX_DEFAULT
	closemessage
	release
	end

MC_GC_FINISH::
	goto MC_GC_PrepareReward

MC_GC_PrepareReward::
	special RyuGenerateReward
	setvar VAR_TEMP_0, 0
	msgbox MC_GC_RewardReceived MSGBOX_DEFAULT
	goto MC_GC_GetReward

MC_GC_GetReward::
	switch VAR_RESULT
	case 649, MasterBallReward
	case 622, KoutaMawileReward
	msgbox MC_GC_NOREWARD MSGBOX_DEFAULT
	closemessage
	release
	end
	
MasterBallReward::
	goto_if_set FLAG_RYU_PASSCODE_MASTERBALL, MC_GC_Received
	msgbox MasterBallRewardMsg MSGBOX_DEFAULT
	playfanfare MUS_ME_BACHI
	waitfanfare
	closemessage
	additem ITEM_MASTER_BALL, 1
	setflag FLAG_RYU_PASSCODE_MASTERBALL
	release
	end
	
KoutaMawileReward::
	goto_if_set FLAG_RYU_PASSCODE_KOUTA, MC_GC_Received
	getpartysize
	special RyuGiveKoutaMawile
	setmonmove VAR_TEMP_3, 0, MOVE_CRUNCH
	setmonmove VAR_TEMP_3, 1, MOVE_BRICK_BREAK
	setmonmove VAR_TEMP_3, 2, MOVE_IRON_HEAD
	setmonmove VAR_TEMP_3, 3, MOVE_PLAY_ROUGH
	additem ITEM_EXPERT_BELT, 1
	buffernumberstring 0, VAR_TEMP_3
	msgbox MSG_KOUTA_GIFT MSGBOX_DEFAULT
	release
	end

MSG_KOUTA_GIFT:
	.string "A level 80 Adamant Mawile with\ncustom moves, as well as an Expert Belt.\pIt's in slot {STR_VAR_1} of your party!\nCongrats on doing the contest challenge!\pThere's a message attached:\nRyuhouji: Thanks for playing\l{COLOR LIGHT_GREEN}{SHADOW GREEN}Emerald Enhanced!$"
	
MC_GC_Received::
	msgbox MC_GC_ReceivedMsg MSGBOX_DEFAULT
	release
	end
	
MC_GC_NOREWARD:
	.string "Nothing!$"
	
MasterBallRewardMsg:
	.string "a Master Ball!$"
	
MC_GC_ReceivedMsg:
	.string "Nothing! because you have already\n"
	.string "redeemed this code!$"
	
MC_GC_RewardReceived:
	.string "You entered {STR_VAR_1}.\pYour Reward is: $"
	
MC_GC_GiftIntro:
	.string "Welcome to the Redemption Corner.\pEnter the passcode you were given,\nand I'll tell you what you won.$"

