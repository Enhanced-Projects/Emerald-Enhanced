
MC_GC_GiftCodeNPC::
	lock
	msgbox MC_GC_GiftIntro MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 0
	goto MC_GC_MENU

MC_GC_DEV_MENU_ITEM::
	msgbox MC_GC_DEV_GiftIntro MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 0
	goto MC_GC_MENU

MC_GC_DEV_MENU_POKE::
	msgbox MC_GC_DEV_PokeGiftIntro MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 0
	goto MC_GC_MENU

MC_GC_DEV_GiftIntro:
	.string "Welcome to the item Dev Menu.\pPlease enter the ID of the item\nyou want.$"

MC_GC_DEV_PokeGiftIntro:
	.string "Welcome to the Pokémon Dev Menu.\pPlease enter the ID of the Pokémon\nyou want.$"
	
MC_GC_MENU::
	multichoicegrid 17, 3, 129, 3, 0
	switch VAR_RESULT
	case 0, MC_GC_1A
	case 1, MC_GC_2A
	case 2, MC_GC_3A
	case 3, MC_GC_4A
	case 4, MC_GC_5A
	case 5, MC_GC_6A
	case 6, MC_GC_7A
	case 7, MC_GC_8A
	case 8, MC_GC_9A
	case 9, MC_GC_10A
	case 10, MC_GC_11
	case 11, MC_GC_12
	case 127, MC_GC_12
	
MC_GC_FINISH::
	goto MC_GC_PrepareReward
	
MC_GC_PrepareReward::
	special RyuGenerateReward
	goto_if_set FLAG_RYU_DEVELOPER_ITEM_MENU, MC_GC_DevModeItemGive
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, MC_GC_DevModePokemonGive
	goto_if_set FLAG_RYU_PASSCODE_FRONTIER_MON_DEV, MC_GC_FrontierMonGive
	setvar VAR_TEMP_0, 0
	msgbox MC_GC_RewardReceived MSGBOX_DEFAULT
	goto MC_GC_GetReward
	
MC_GC_GetReward::
	switch VAR_RESULT
	case 111, FrontierMonDev
	case 649, MasterBallReward
	case 910, TutorVoucherReward
	case 622, KoutaMawileReward
	case 842, GCMSReward
	msgbox MC_GC_NOREWARD MSGBOX_DEFAULT
	closemessage
	release
	end

MC_GC_FrontierMonGive::
	special RyuGiveFrontierMon
	buffernumberstring 0, VAR_TEMP_6
	msgbox MC_GC_YouveBeenGiven
	clearflag FLAG_RYU_PASSCODE_FRONTIER_MON_DEV
	closemessage
	release
	end

MC_GC_YouveBeenGiven::
	.string "You've been given the Frontier\nMon with id {STR_VAR_1}.$"


FrontierMonDev::
	goto_if_unset FLAG_RYU_DEV_MODE, NorewardNotDevmode
	msgbox pleaseEnterFID
	setflag FLAG_RYU_PASSCODE_FRONTIER_MON_DEV
	goto MC_GC_MENU

pleaseEnterFID:
	.string "Please enter the frontier mon ID.$"


NorewardNotDevmode::
	msgbox MC_GC_NOREWARD
	closemessage
	release
	end

MC_GC_DevModeItemGive::
	giveitem VAR_RESULT, 100
	msgbox MC_GC_RyuGiveItemDevMode
	clearflag FLAG_RYU_DEVELOPER_ITEM_MENU
	release
	end

MC_GC_DevModePokemonGive::
	copyvar VAR_TEMP_4, VAR_RESULT
	bufferspeciesname 0, VAR_TEMP_4
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq MC_GC_DevPokeNoSpace
	copyvar VAR_TEMP_8, VAR_RESULT
	call GCMS_NatureMenu
	clearflag FLAG_RYU_DEVELOPER_POKEMON_MENU
	msgbox MC_GC_GivePokeMsg MSGBOX_DEFAULT
	release
	end

MC_GC_DevPokeNoSpace::
	msgbox donthavespaceformon
	release
	end

donthavespaceformon:
	.string "You don't have space for\n a {STR_VAR_1}.$"

MC_GC_GivePokeMsg:
	.string "You've been given a tamed\n{STR_VAR_1}.$"

MC_GC_RyuGiveItemDevMode:
	.string "You've been given 99 of item ID {STR_VAR_1}.$"
	
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
	
TutorVoucherReward::
	goto_if_set FLAG_RYU_PASSCODE_TUTORVOUCHER, MC_GC_Received
	msgbox MC_GC_TutorVoucherRewardMsg MSGBOX_DEFAULT
	playfanfare MUS_ME_BACHI
	waitfanfare
	closemessage
	additem ITEM_RETRO_MAIL, 4
	setflag FLAG_RYU_PASSCODE_TUTORVOUCHER
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
	

GCMSReward:
	goto_if_set FLAG_RYU_PASSCODE_GCMS_GIFT, MC_GC_Received
	setvar VAR_RYU_GCMS_VALUE, 31
	msgbox GCMSRewardMsg
	setflag FLAG_RYU_PASSCODE_GCMS_GIFT
	release
	end

GCMSRewardMsg:
	.string "Your GCMS Map Status has been set\nto 31.\pYou can now get a free perfect\nspecimen from the GCMS.\pThanks for joining the discord!$"

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
	.string "Nothing! because\n"
	.string "You've already redeemed this code!$"
	
MC_GC_RewardReceived:
	.string "You entered {STR_VAR_1}.\pYour Reward is: $"
	
MC_GC_GiftIntro:
	.string "Welcome to the Redemption Corner.\pEnter the passcode you were given,\nand I'll tell you what you won.$"
	
MC_GC_TutorVoucherRewardMsg:
	.string "4 Tutor Vouchers!\pRedeem these at the\nLilycove Training Center!$"
	
MC_GC_1A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_1B
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_1B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_1C
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_1C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH
	
MC_GC_2A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_2B
	setvar VAR_TEMP_1, 2
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_2B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_2C
	setvar VAR_TEMP_2, 2
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_2C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 2
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH
	
MC_GC_3A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_3B
	setvar VAR_TEMP_1, 3
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_3B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_3C
	setvar VAR_TEMP_2, 3
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_3C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 3
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH
	
MC_GC_4A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_4B
	setvar VAR_TEMP_1, 4
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_4B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_4C
	setvar VAR_TEMP_2, 4
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_4C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 4
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH
	
MC_GC_5A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_5B
	setvar VAR_TEMP_1, 5
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_5B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_5C
	setvar VAR_TEMP_2, 5
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_5C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 5
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH

MC_GC_6A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_6B
	setvar VAR_TEMP_1, 6
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_6B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_6C
	setvar VAR_TEMP_2, 6
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_6C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 6
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH

MC_GC_7A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_7B
	setvar VAR_TEMP_1, 7
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_7B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_7C
	setvar VAR_TEMP_2, 7
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_7C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 7
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH
	
MC_GC_8A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_8B
	setvar VAR_TEMP_1, 8
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_8B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_8C
	setvar VAR_TEMP_2, 8
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_8C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 8
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH
	
MC_GC_9A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_9B
	setvar VAR_TEMP_1, 9
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_9B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_9C
	setvar VAR_TEMP_2, 9
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_9C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 9
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH
	
MC_GC_10A::
	compare VAR_TEMP_0, 0
	goto_if_ne MC_GC_10B
	setvar VAR_TEMP_1, 0
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_10B::
	compare VAR_TEMP_0, 1
	goto_if_ne MC_GC_10C
	setvar VAR_TEMP_2, 0
	addvar VAR_TEMP_0, 1
	goto MC_GC_MENU
	
MC_GC_10C::
	compare VAR_TEMP_0, 2
	goto_if_ne MC_GC_12
	setvar VAR_TEMP_3, 0
	addvar VAR_TEMP_0, 1
	goto MC_GC_FINISH

MC_GC_11::
	goto_if_unset FLAG_RYU_DEV_MODE, ryu_end
	setflag FLAG_RYU_DEVELOPER_ITEM_MENU
	goto MC_GC_DEV_MENU_ITEM
	release
	end
	
MC_GC_12::
	goto_if_unset FLAG_RYU_DEV_MODE, ryu_end
	setflag FLAG_RYU_DEVELOPER_POKEMON_MENU
	goto MC_GC_DEV_MENU_POKE
	release
	end

