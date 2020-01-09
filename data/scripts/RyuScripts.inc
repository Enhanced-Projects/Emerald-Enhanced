@@Custom Scripts


@@=================================================================================================EXP BATTERY

RyuExpBattery::
	lock
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_eq RyuExpBatteryDevMode
	goto RyuExpBatteryContd
	
RyuExpBatteryContd::
	buffernumberstring 0, VAR_RYU_EXP_BATTERY
	msgbox RyuExpBatteryStored MSGBOX_DEFAULT
	closemessage
	msgbox RyuExpBatteryUseOnPokemon MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RS_CancelPartySlot
	goto RS_SelectSlot

RyuExpBatteryDevModeMsg::
	.string "You have Dev Mode active.\nWould you like to max out EXP Drive?$"

RyuExpBatteryDevMode::
	msgbox RyuExpBatteryDevModeMsg MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RyuExpBatteryContd
	setvar VAR_RYU_EXP_BATTERY, 65000
	goto RyuExpBatteryContd

RS_SelectSlot::
	multichoicedefault 0, 0, 118, 0, 0
	switch VAR_RESULT
	case 0, RS_Slot1Selected
	case 1, RS_Slot2Selected
	case 2, RS_Slot3Selected
	case 3, RS_Slot4Selected
	case 4, RS_Slot5Selected
	case 5, RS_Slot6Selected
	case 127, RS_CancelPartySlot
	releaseall
	end

RS_DoExpBatteryDrain::
	special RyuGiveExpUnloadBattery
	bufferpartymonnick 1, VAR_TEMP_F
	setvar VAR_RYU_EXP_BATTERY, 1
	msgbox RyuExpBatterySuccess MSGBOX_DEFAULT
	release
	end

RyuExpBatteryStored:
	.string "You have {STR_VAR_1} Exp. Points stored.$"

RyuExpBatteryUseOnPokemon:
	.string "Would you like to give {STR_VAR_1}\nExp Points to a Pokémon?$"

RyuExpBatterySuccess:
	.string "Success! {STR_VAR_1} Exp. Points\nwere given to {STR_VAR_2}!$"
	
RS_Slot1Selected::
	setvar VAR_TEMP_F, 0
	goto RS_DoExpBatteryDrain
	
RS_Slot2Selected::
	getpartysize
	compare VAR_RESULT, 2
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 1
	goto RS_DoExpBatteryDrain
	
RS_Slot3Selected::
	getpartysize
	compare VAR_RESULT, 3
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 2
	goto RS_DoExpBatteryDrain
	
RS_Slot4Selected::
	getpartysize
	compare VAR_RESULT, 4
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 3
	goto RS_DoExpBatteryDrain
	
RS_Slot5Selected::
	getpartysize
	compare VAR_RESULT, 5
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 4
	goto RS_DoExpBatteryDrain
	
RS_Slot6Selected::
	getpartysize
	compare VAR_RESULT, 6
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 5
	goto RS_DoExpBatteryDrain
	
RS_SlotSelectEmpty::
	msgbox RS_SelectAnotherSlot MSGBOX_DEFAULT
	goto RS_SelectSlot

RS_SelectAnotherSlot:
	.string "You must select an occupied\nparty slot!$"

RS_CancelPartySlot::
	msgbox RS_CancelledMsg MSGBOX_DEFAULT
	closemessage
	msgbox RS_DisableEarnedEXPMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RS_DisableExpGaining
	msgbox RS_ExpWillStillBeEarned
	clearflag FLAG_RYU_EXP_DRIVE_DISABLE_EARNING
	releaseall
	end

RS_DisableExpGaining::
	setflag FLAG_RYU_EXP_DRIVE_DISABLE_EARNING
	msgbox RS_ExpEarningDisabled
	closemessage
	releaseall
	end

RS_CancelledMsg:
	.string "The exp in the Drive has been\npreserved.$"

RS_DisableEarnedEXPMsg:
	.string "Would you like to disable earning\nEXP in battle?$"

RS_ExpEarningDisabled:
	.string "Experience gain in battle is now\ndisabled.\pThe Drive will continue to collect\nEXP.$"

RS_ExpWillStillBeEarned:
	.string "Battle EXP will still be earned.$"




@==================================================================================================Beta Menu

RyuDebugBetaMenuScript::
	msgbox BetaMenuIntro MSGBOX_DEFAULT
	closemessage
	multichoicedefault 30, 0, 133, 7, 0
	switch VAR_RESULT
	case 0, RDBM_ResetDevon
	case 1, RDBM_Magma
	case 2, RDBM_ResetAqua
	case 3, RDBM_ResetLeaf
	case 4, RDBM_ResetRival
	case 5, RDBM_ResetBadges
	case 6, RDBM_TeleportHome
	case 7, RDBM_ExitResetMenu
	case 127, RDBM_ExitResetMenu
	release
	end

BetaMenuIntro:
	.string "You really shouldn't mess with these\noptions unless you were directed\pto do so. Save file damage can occur.\pIn some cases, these menus will\ndelete items given from the questline.\p"
	.string "{COLOR LIGHT_RED}{SHADOW TRANSPARENT}YOU HAVE BEEN WARNED!!$"

RDBM_ResetDevon::
	lockall
	msgbox RDBM_Devon_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	special RyuResetDevonFlags
	playse SE_EXPMAX
	waitse
	release
	end

RDBM_Devon_msg:
	.string "Resetting Devon storyline progress\n... ... ... ...$"

RDBM_Magma::
	lockall
	msgbox RDBM_Magma_msg MSGBOX_DEFAULT
	release
	end
	
RDBM_Magma_msg:
	.string "Magma hasn't been implemented yet.\nNo changes have been made.$"

RDBM_ResetAqua::
	lockall
	msgbox RDBM_Aqua_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	special RyuResetAquaFlags
	playse SE_EXPMAX
	waitse
	release
	end
	
RDBM_Aqua_msg:
	.string "Resetting Aqua storyline progress\n... ... ... ...$"

RDBM_ResetLeaf::
	lockall
	msgbox RDBM_Leaf_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	cleartrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_24
	special RyuResetLeafFlags
	playse SE_EXPMAX
	waitse
	release
	end
	
RDBM_Leaf_msg:
	.string "Resetting Leaf storyline progress\n... ... ... ...$"

RDBM_ResetRival::
	lockall
	msgbox RDBM_Rival_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	special RyuResetRivalFlags
	playse SE_EXPMAX
	waitse
	release
	end
	
RDBM_Rival_msg:
	.string "Resetting {RIVAL} storyline progress\n... ... ... ...$"

RDBM_ResetBadges::
	lockall
	setvar VAR_RYU_GCMS_SPECIES, 0
	setvar VAR_RYU_GCMS_VALUE, 0
	msgbox RDBM_GCMSReset
	release
	end

RDBM_GCMSReset:
	.string "GCMS has been reset.$"

RDBM_WeatherFixArchie:
	clearflag FLAG_RYU_ARCHIE_SUCCESSFUL
	doweather
	release
	end

RDBM_WeatherMsg:
	.string "Resetting all weather variables...$"

RDBM_WeatherMsg2:
	.string "Weather has been reset to default state.$"

RDBM_Badges_msg::
	.string "Not Implemented yet.\nNo changes made.$"

RDBM_ExitResetMenu::
	msgbox RDBM_Exiting MSGBOX_DEFAULT
	release
	end

RDBM_TeleportHome:
	msgbox RGBM_TPHOME MSGBOX_DEFAULT
	closemessage
	goto RT_Home

RGBM_TPHOME:
	.string "Teleporting {PLAYER} home...$"

RDBM_Exiting:
	.string "Exiting menu without change...$"
@==================================================================================================Passcode Menu

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
	setvar VAR_TEMP_0, 0
	msgbox MC_GC_RewardReceived MSGBOX_DEFAULT
	goto MC_GC_GetReward
	
MC_GC_GetReward::
	switch VAR_RESULT
	case 649, MasterBallReward
	case 910, TutorVoucherReward
	case 622, KoutaMawileReward
	case 842, GCMSReward
	msgbox MC_GC_NOREWARD MSGBOX_DEFAULT
	closemessage
	release
	end

MC_GC_DevModeItemGive::
	giveitem VAR_RESULT, 99
	msgbox MC_GC_RyuGiveItemDevMode
	clearflag FLAG_RYU_DEVELOPER_ITEM_MENU
	release
	end

MC_GC_DevModePokemonGive::
	givemon VAR_RESULT, 100, 0
	clearflag FLAG_RYU_DEVELOPER_POKEMON_MENU
	msgbox MC_GC_GivePokeMsg MSGBOX_DEFAULT
	clearflag FLAG_RYU_DEVELOPER_POKEMON_MENU
	release
	end

MC_GC_GivePokeMsg:
	.string "You've been given the Pokémon with\nthe ID number {STR_VAR_1}.$"

MC_GC_RyuGiveItemDevMode:
	.string "You've been given 99 of item ID {STR_VAR_1}.$"
	
MasterBallReward::
	goto_if_set FLAG_RYU_PASSCODE_MASTERBALL, MC_GC_Received
	msgbox MasterBallRewardMsg MSGBOX_DEFAULT
	playfanfare MUS_ME_BACHI
	waitfanfare
	closemessage
	giveitem ITEM_MASTER_BALL, 1
	setflag FLAG_RYU_PASSCODE_MASTERBALL
	release
	end
	
TutorVoucherReward::
	goto_if_set FLAG_RYU_PASSCODE_TUTORVOUCHER, MC_GC_Received
	msgbox MC_GC_TutorVoucherRewardMsg MSGBOX_DEFAULT
	playfanfare MUS_ME_BACHI
	waitfanfare
	closemessage
	giveitem ITEM_RETRO_MAIL, 4
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
	giveitem ITEM_EXPERT_BELT, 1
	buffernumberstring 0, VAR_TEMP_3
	msgbox MSG_KOUTA_GIFT MSGBOX_DEFAULT
	release
	end
	

GCMSReward:
	goto_if_set FLAG_RYU_PASSCODE_GCMS_GIFT, MC_GC_Received
	setvar VAR_RYU_GCMS_VALUE, 31
	msgbox GCMSRewardMsg
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


@==================================================================================================Relationship scripts

RyuPartnerMultiText:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Would you like to challenge this\n"
	.string "opponent with one of your partners?$"

RyuParterBattleMultichoice::
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq RyuPartnerMultiBattleChoiceMale
	multichoice 20, 4, 130, 1
	switch VAR_RESULT
	case 0, RyuMultiBattlePartnerDawn
	case 1, RyuMultiBattlePartnerShelly
	case 2, RyuMultiBattlePartnerLana
	case 3, RyuMultiBattlePartnerLanette
	
RyuPartnerMultiBattleChoiceMale::
	multichoice 20, 4, 132, 1
	switch VAR_RESULT
	case 0, RyuMultiBattlePartnerBrendan
	case 1, RyuMultiBattlePartnerShelly
	case 2, RyuMultiBattlePartnerLana
	case 3, RyuMultiBattlePartnerLanette
	
RyuPartnerNoRelationship::
	msgbox Ryu_NOREL
	closemessage
	goto RyuParterBattleMultichoice
	
RyuMultiBattlePartnerDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_DAWN
	setvar VAR_0x8007, TRAINER_BACK_PIC_MAY 
	return
	
RyuMultiBattlePartnerShelly::
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_SHELLY
	setvar VAR_0x8007, TRAINER_BACK_PIC_SHELLY
	return
	
RyuMultiBattlePartnerBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_BRENDAN
	setvar VAR_0x8007, TRAINER_BACK_PIC_BRENDAN
	return

RyuMultiBattlePartnerLana::
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_LANA
	setvar VAR_0x8007, TRAINER_BACK_PIC_LEAF
	return

RyuMultiBattlePartnerLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_LANETTE
	setvar VAR_0x8007, TRAINER_BACK_PIC_LANETTE
	return

	
Ryu_PlayerCalledDawn:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Dawn...\n... ... ... ... ... ...$"
	
Ryu_PlayerCalledShelly:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Shelly...\n... ... ... ... ... ...$"
	
Ryu_PlayerCalledBrendan:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Brendan...\n... ... ... ... ... ...$"

Ryu_PlayerCalledLana:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Lana...\n... ... ... ... ... ...$"

Ryu_PlayerCalledLanette:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Lanette...\n... ... ... ... ... ...$"
	
Ryu_NOREL:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}You don't have a good enough\nrelationship with this person.\pChoose a different partner.$"
	
@==================================================================================================General Purpose Scripts

RyuGivePokenav::
	msgbox RustboroCity_DevonCorp_3F_Text_ReceivedPokenav MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	return

@@MAIN DEBUG MENU==================================================================================
RyuDevSwitch::
	setflag FLAG_RYU_DEV_MODE
	clearflag FLAG_HIDE_103_TEST_TRAINER
	msgbox RyuNowDeveloper MSGBOX_SIGN
	end
	
RyuNowDeveloper:
	.string "{PLAYER} is now a developer.$"
	
RyuDebugMenuScript::
	msgbox RyuDebug_msg MSGBOX_SIGN
	multichoicedefault 0, 0, 115, 8, 0
	switch VAR_RESULT
	case 0, RyuDebug_PasscodeMenu
	case 1, RyuDebug_UtilitiesMenu
	case 2, RyuDebug_quickstart
	case 3, RyuDebug_pokeedit
	case 4, RyuDebug_enableWaystone
	case 5, RyuDebug_Init_GiveAllItems
	case 6, RyuDebug_DisableDebug
	case 7, RyuDebug_cancel
	goto RyuDebug_cancel
	releaseall
	end
	
RyuDebug_menu_nodevcheck::
	msgbox RyuDebug_msg MSGBOX_SIGN
	multichoicedefault 0, 0, 115, 7, 0
	switch VAR_RESULT
	case 0, RyuDebug_PasscodeMenu
	case 1, RyuDebug_UtilitiesMenu
	case 2, RyuDebug_quickstart
	case 3, RyuDebug_pokeedit
	case 4, RyuDebug_enableWaystone
	case 5, RyuDebug_Init_GiveAllItems
	case 6, RyuDebug_DisableDebug
	case 7, RyuDebug_cancel
	releaseall
	end

RyuDebug_UtilitiesMenu:
	multichoicedefault 0, 0, 143, 5, 0
	switch VAR_RESULT
	case 0, RyuDebug_Phasing
	case 1, RyuDebug_Encounters
	case 2, RyuDebug_EnableSaveViewer
	case 3, RyuDebug_ViewTempVars
	case 4, RyuDebug_Utility1
	case 5, RyuDebug_cancel
	goto RyuDebug_cancel
	
RyuDebug_pokeedit::
	msgbox OpeningPokeEdit
    goto RyuPokeEditMenu
	release
	end

OpeningPokeEdit:
	.string "Opening Poke Edit...$"

RyuDebug_money::
	setvar VAR_TEMP_A, 32000
    givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	msgbox RyuDebug_money_text MSGBOX_DEFAULT
	return

RyuDebug_Encounters::
	goto_if_set FLAG_RYU_DEV_DISENC, RyuDebug_EnENC
	setflag FLAG_RYU_DEV_DISENC
	msgbox RyuEncDisabled
	release
	end
	
RyuDebug_EnENC::
	clearflag FLAG_RYU_DEV_DISENC
	msgbox RyuEncEnabled
	release
	end
	
RyuEncDisabled:
	.string "Dev Repel on$"
	
RyuEncEnabled:
	.string "Dev Repel off$"

RyuDebug_money_text:
    .string "Given ¥250,000.$"

RyuDebug_DisableDebug::
	clearflag FLAG_RYU_DEV_MODE
	msgbox DevModeDisabled MSGBOX_DEFAULT
	releaseall
	end

RyuDebug_EnableSaveViewer::
	setvar VAR_RECYCLE_GOODS, 45454
	msgbox Ryu_saveViewerEnabled
	release
	end

Ryu_saveViewerEnabled:
	.string "First variable set to beacon the\nsave viewer.\pSave the game twice to make sure\nboth save banks are the same!$"

RyuDebug_Phasing::
	goto_if_set FLAG_RYU_COLLISION_OFF, Ryu_DisablePhasing
	setflag FLAG_RYU_COLLISION_OFF
	msgbox Ryu_CollisionOffMsg
	release
	end

Ryu_DisablePhasing::
	clearflag FLAG_RYU_COLLISION_OFF
	msgbox Ryu_CollisionOnMsg
	release
	end

Ryu_CollisionOffMsg:
	.string "Entered the Ethereal plane.$"

Ryu_CollisionOnMsg:
	.string "Returned to Material plane.$"

DevModeDisabled:
	.string "{PLAYER} is no longer a developer.$"
	
EGC_CLEARGAMECLEARFLAG::
    clearflag FLAG_SYS_GAME_CLEAR
	end

RyuDebug_waystone::
	giveitem_std ITEM_NUGGET, 1
	closemessage
	goto RyuDebug_menu_nodevcheck
	releaseall
	end

RyuDebug_enableWaystone::
	giveitem ITEM_NUGGET, 1
    setflag FLAG_VISITED_LITTLEROOT_TOWN
    setflag FLAG_VISITED_OLDALE_TOWN
    setflag FLAG_VISITED_DEWFORD_TOWN
    setflag FLAG_VISITED_LAVARIDGE_TOWN
    setflag FLAG_VISITED_FALLARBOR_TOWN
    setflag FLAG_VISITED_VERDANTURF_TOWN
    setflag FLAG_VISITED_PACIFIDLOG_TOWN
    setflag FLAG_VISITED_PETALBURG_CITY
    setflag FLAG_VISITED_SLATEPORT_CITY
    setflag FLAG_VISITED_MAUVILLE_CITY
    setflag FLAG_VISITED_RUSTBORO_CITY
    setflag FLAG_VISITED_FORTREE_CITY
    setflag FLAG_VISITED_LILYCOVE_CITY
    setflag FLAG_VISITED_MOSSDEEP_CITY
    setflag FLAG_VISITED_SOOTOPOLIS_CITY
    setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	setflag FLAG_RYU_LANDMARK_MTPYRE
	setflag FLAG_RYU_LANDMARK_LCCDEPTSTORE
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	setflag FLAG_LANDMARK_AQUA_OFFICE
	return

RyuDebug_ViewTempVars::
	special RyuCheckTempVars
	msgbox RDB_CTVMsg
	releaseall
	end

RDB_CTVMsg:
	.string "{STR_VAR_1}$"

RyuDebug_Utility1::
	special FillTheDex
	@setflag FLAG_RYU_NIGHT
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	release
	end

RDB_Readout:
	.string "You're on stage {STR_VAR_1} of Lana quest.$"

AltScaleOn::
	msgbox ScaleAltMsg
	release
	end

ScalingOff::
	msgbox NotScaling
	release
	end

ScaleAltMsg:
	.string "Alternate Scaling Enabled.$"

AltScaleOff:
	.string "Alternate Scaling Disabled.$"

ScalingOn:
	.string "Autoscale is on.$"

NotScaling:
	.string "Autoscale is being prevented.$" 


RyuDebug_Init_GiveAllItems::
	setvar VAR_TEMP_2, 482
	msgbox RyuDebug_GiveAllItemsBeginMsg MSGBOX_DEFAULT
	goto RyuDebug_GiveAllItems
	
RyuDebug_GiveAllItems::
	giveitem VAR_TEMP_2, 1
	addvar VAR_TEMP_2, 1
	goto RyuDebug_ReturnCallItems
	
RyuDebug_ReturnCallItems::
	compare VAR_TEMP_2, 581
	goto_if_eq RyuDebugGiveItemsDone
	goto RyuDebug_GiveAllItems
	
RyuDebugGiveItemsDone::
	giveitem ITEM_FULL_RESTORE, 64
	giveitem ITEM_MAX_ELIXIR, 64
	giveitem ITEM_MAX_REVIVE, 64
	giveitem ITEM_HEART_SCALE, 64
	giveitem ITEM_PP_MAX, 64
	giveitem ITEM_RARE_CANDY, 64
	giveitem ITEM_LUXURY_BALL, 64
	giveitem ITEM_MASTER_BALL, 64
	giveitem ITEM_MAX_REPEL, 64
	msgbox RyuDebug_GiveAllItemsDoneMsg MSGBOX_DEFAULT
	msgbox RyuDebug_givemonsquery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuDebug_Init_GiveAll
	msgbox RyuDebug_MoneyMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq RyuDebug_money
	release
	end

RyuDebug_MoneyMsg:
	.string "Give Dev Mode money payout?$"
	
RyuDebug_GiveAllItemsDoneMsg:
	.string "Finished giving starter kit.$"
	
RyuDebug_GiveAllItemsBeginMsg:
	.string "Giving all tms...$"

RyuDebug_givemonsquery:
	.string "Would you like to be given\nall the Pokémon in the game?$"

RyuDebug_cancel::
    closemessage
	end

RyuDebug_msg:
    .string "What would you like to activate?$"
	
RyuDebug_Init_GiveAll::
	setvar VAR_TEMP_0, 1
	msgbox RyuDebug_GiveAllBeginMsg MSGBOX_DEFAULT
	goto RyuDebug_GiveAllMons
	
RyuDebug_GiveAllMons::
	givemon VAR_TEMP_0, 5, 0x0
	addvar VAR_TEMP_0, 1
	goto RyuDebug_ReturnCall
	
RyuDebug_ReturnCall::
	compare VAR_TEMP_0, 410
	goto_if_eq RyuDebugGivePokeDone
	goto RyuDebug_GiveAllMons
	
RyuDebugGivePokeDone::
	msgbox RyuDebug_GiveAllDoneMsg MSGBOX_DEFAULT
	release
	end
	
RyuDebug_GiveAllDoneMsg:
	.string "Finished Giving all mons.$"
	
RyuDebug_GiveAllBeginMsg:
	.string "The process will begin when you\nclose this message.\lIt will take 30 seconds to a minute\lto complete, and the game may appear\lto be frozen.\pIf music is still playing,\nit is not frozen. Enjoy!$"

RyuDebug_quickstart::
    givemon SPECIES_PRIMARINA, 125, ITEM_EXPERT_BELT
	givemon SPECIES_PHEROMOSA, 125, ITEM_BLACK_BELT
	setmonmove 1, 0, MOVE_TRIPLE_KICK
	setmonmove 1, 1, MOVE_WILD_CHARGE
	setmonmove 1, 2, MOVE_EXTREME_SPEED
	setmonmove 1, 3, MOVE_MEGAHORN
	setmonmove 0, 0, MOVE_SPARKLING_ARIA
	setmonmove 0, 1, MOVE_MOONBLAST
	setmonmove 0, 2, MOVE_SHADOW_BALL
	setmonmove 0, 3, MOVE_ICE_BEAM
	setvar VAR_TEMP_1, 252
	setvar VAR_TEMP_2, 1
	special RyuSetEVATK
	special RyuSetEVSPE
	setvar VAR_TEMP_2, 2
	special RyuSetEVSPATK
	special RyuSetEVHP
	special RyuSetIVs
	giveitem ITEM_NUGGET 1
    setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	call RyuDebug_enableWaystone
	msgbox RyuNewGameQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuDebug_SkipTutorial
	closemessage
	goto RyuDebug_menu_nodevcheck
	releaseall
	end

RyuDebug_SkipTutorial::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	setvar VAR_LITTLEROOT_INTRO_STATE, 10
	setflag FLAG_RECEIVED_GO_GOGGLES
	setflag FLAG_RYU_MET_RIVAL_LITTLEROOT
	giveitem ITEM_GO_GOGGLES, 1
	setflag FLAG_SYS_B_DASH
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	setflag FLAG_RYU_INTRO_COMPLETE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	setflag FLAG_SYS_POKEDEX_GET
	special sub_81AFDA0
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	msgbox LRT_GameStartVariablesInfoMsg MSGBOX_DEFAULT
	closemessage
	msgbox RyuDebug_GiveItemQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuDebug_Init_GiveAllItems
	release
	end

LRT_GameStartVariablesInfoMsg:
	.string "New Game Flags and Variables Set.$"

RyuDebug_GiveItemQuery:
	.string "Would you like the starter kit\nfor core items?$"

RyuNewGameQuery:
	.string "Would you like to activate the new\ngame scripts?$"
	
@@EV DEBUG MENU====================================================================================

RyuPokeEditMenu::
	multichoicedefault 1, 0, 122, 0, 0
	switch VAR_RESULT
	case 0, RyuViewEvDebugMenu@
	case 1, RyuViewIvDebugMenu@
	case 2, RyuViewOtherDebugMenu@
	case 3, RyuSetExpMultMenu@
	case 4, RyuSetEvDebugMenu@
	case 5, RyuSetIvDebugMenu@
	case 6, RyuSetFriendshipDebugMenu@
	case 7, RyuExitPokeEditMenu@
	goto RyuExitPokeEditMenu
	
RyuExitPokeEditMenu::
	release
	end
	
RyuViewIvDebugMenu::
	special RyuIvCheckerDef
	msgbox RyuIvDebug1 MSGBOX_DEFAULT
	special RyuIvCheckerOff
	msgbox RyuIvDebug2 MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
	
RyuViewEvDebugMenu::
	special RyuEvCheckerDef
	msgbox RyuEVDebug1 MSGBOX_DEFAULT
	special RyuEvCheckerOff
	msgbox RyuEVDebug2 MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
RyuViewOtherDebugMenu::
	special RyuOtherDataChecker
	msgbox RyuOtherMenuMsg MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
RyuOtherMenuMsg:
	.string "Lead mon's Friendship Value is {STR_VAR_1}\p"
	.string "Lead mon's Personality Value is {STR_VAR_2}\p"
	.string "Lead mon's ribbon count is {STR_VAR_3}$"

RyuSetEvDebugMenu::
	msgbox RyuEvIntro MSGBOX_SIGN
	multichoicegrid 1, 0, 116, 4, 0
	switch VAR_RESULT
	case 0, RyuEvMenuHP
	case 1, RyuEvMenuHP126
	case 2, RyuEvMenuAtk
	case 3, RyuEvMenuAtk126
	case 4, RyuEvMenuDef
	case 5, RyuEvMenuDef126
	case 6, RyuEvMenuSpAtk
	case 7, RyuEvMenuSpAtk126
	case 8, RyuEvMenuSpDef
	case 9, RyuEvMenuSpDef126
	case 10, RyuEvMenuSpe
	case 11, RyuEvMenuSpe126
	case 12, RyuEvMenuReset
	case 13, RyuEvMenuExit
	case 14, RyuEvMenuExit
	case 15, RyuEvMenuExit
	case 127, RyuEvMenuExit
	release
	end

RyuEvMenuQuery:
	.string "Modify more EV's?$"

RyuEvIntro:
	.string "Choose which value to set.\n"
	.string "Insert/Extract from pc to apply.$"
	
RyuEvMenuReset::
	special RyuResetEvs
	msgbox RyuResetEvMessage MSGBOX_DEFAULT
	goto RyuSetEvDebugMenu
	
RyuResetEvMessage:
	.string "Lead mon Evs have been reset.\n"
	.string "You can now choose new ones.$"

RyuEvMenuExit::
	msgbox RyuEvMenuQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuSetEvDebugMenu
	goto RyuPokeEditMenu
	release
	end

RyuEvMenuHP::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	special RyuSetEVHP
	call RyuEvMenuExit
	release
	end

RyuEvMenuHP126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	special RyuSetEVHP
	call RyuEvMenuExit
	release
	end

RyuEvMenuAtk::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	special RyuSetEVATK
	call RyuEvMenuExit
	release
	end

RyuEvMenuAtk126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	special RyuSetEVATK
	call RyuEvMenuExit
	release
	end

RyuEvMenuDef::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	special RyuSetEVDEF
	call RyuEvMenuExit
	release
	end

RyuEvMenuDef126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	special RyuSetEVDEF
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpAtk::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	special RyuSetEVSPATK
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpAtk126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	special RyuSetEVSPATK
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpDef::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	special RyuSetEVSPDEF
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpDef126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	special RyuSetEVSPDEF
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpe::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	special RyuSetEVSPE
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpe126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	special RyuSetEVSPE
	call RyuEvMenuExit
	release
	end

RyuEvMenuMsg:
	.string "Would you like to modify EV's?"
	
RyuIvDebug1:
	.string "Lead Pokemon Defensive IVS:\n"
	.string "HP: {STR_VAR_1}    Def: {STR_VAR_2}     SpDef: {STR_VAR_3}$"
	
RyuIvDebug2:
	.string "Lead Pokemon Offensive IVS:\n"
	.string "Atk: {STR_VAR_1}    SpAtk: {STR_VAR_2}     Speed: {STR_VAR_3}$"

RyuEVDebug1:
	.string "Lead Pokemon Defensive EVS:\n"
	.string "HP: {STR_VAR_1}    Def: {STR_VAR_2}     SpDef: {STR_VAR_3}$"
	
RyuEVDebug2:
	.string "Lead Pokemon Offensive EVS:\n"
	.string "Atk: {STR_VAR_1}    SpAtk: {STR_VAR_2}     Speed: {STR_VAR_3}$"
	
RyuSetFriendshipDebugMenu::
	special RyuSetFriendship
	msgbox RyuSetFriendshipMsg MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
RyuSetFriendshipMsg:
	.string "Lead mon loves you now.$"
	
RyuSetExpMultMenu::
	compare VAR_RYU_EXP_MULTIPLIER, 1
	goto_if_eq RyuSetExpMultMenu2
	buffernumberstring 0, VAR_RYU_EXP_MULTIPLIER
	msgbox RyuCurrentExpMult MSGBOX_DEFAULT
	multichoicedefault 5, 0, 124, 0, 0
	switch VAR_RESULT
	case 0, RyuSetExpMult1
	case 1, RyuSetExpMultAuto
	case 2, RyuSetExpMult2
	case 3, RyuSetExpMult4
	case 4, RyuSetExpMult8
	case 5, RyuExitSetLevel
	case 127, RyuExitSetLevel

RyuSetExpMultMenu2::
	playse SE_EXPMAX
	waitse
	special RyuCalculateCurrentExpCoefficient
	buffernumberstring 0, VAR_TEMP_2
	msgbox RyuCurrentExpMult MSGBOX_DEFAULT
	multichoicedefault 5, 0, 124, 0, 0
	switch VAR_RESULT
	case 0, RyuSetExpMult1
	case 1, RyuSetExpMultAuto
	case 2, RyuSetExpMult2
	case 3, RyuSetExpMult4
	case 4, RyuSetExpMult8
	case 5, RyuExitSetLevel
	case 127, RyuExitSetLevel

RyuCurrentExpMult:
	.string "The multiplier coefficient is currently\n"
	.string "{STR_VAR_1}.$"
	
RyuSetExpMult1::@@exp is vanilla
	setvar VAR_RYU_EXP_MULTIPLIER, 1000
	setvar VAR_RYU_PRICE_MULTIPLIER, 200
	msgbox ExpMult1 MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
ExpMult1:
	.string "EXP Multiplier is now default.\n"
	.string "You gain exp at vanilla rate.$"
	
RyuSetExpMultAuto::@@exp is increased by 12.5% per gym badge
	msgbox ExpMultAuto MSGBOX_DEFAULT
	setvar VAR_RYU_EXP_MULTIPLIER, 1
	setvar VAR_RYU_PRICE_MULTIPLIER, 100
	closemessage
	goto RyuPokeEditMenu
	
ExpMultAuto:
	.string "EXP Multiplier is now Auto.\n"
	.string "You will gain additional exp per badge.$"
	
RyuSetExpMult2::@@exp is multiplied by 2
	setvar VAR_RYU_EXP_MULTIPLIER, 2000
	setvar VAR_RYU_PRICE_MULTIPLIER, 75
	msgbox ExpMult2 MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
ExpMult2:
	.string "EXP Multiplier is now 2.0x.$"
	
RyuSetExpMult4::@@exp is multiplied by 4
	setvar VAR_RYU_EXP_MULTIPLIER, 4000
	setvar VAR_RYU_PRICE_MULTIPLIER, 50
	msgbox ExpMult4 MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
ExpMult4:
	.string "EXP Multiplier is now 4.0x.$"
	
RyuSetExpMult8::@@exp is multiplied by 8
	setvar VAR_RYU_EXP_MULTIPLIER, 8000
	setvar VAR_RYU_PRICE_MULTIPLIER, 25
	msgbox ExpMult8 MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
ExpMult8:
	.string "EXP Multiplier is now 8.0x.$"
	
RyuDebug_PasscodeMenu::
	playse SE_EXPMAX
	waitse
	setvar VAR_TEMP_0, 0
	goto MC_GC_MENU
	
RyuSetLevel10::
	setvar VAR_TEMP_9, 10
	goto RyuPokeEditMenu
	
RyuSetLevel20::
	setvar VAR_TEMP_9, 20
	goto RyuPokeEditMenu
	
RyuSetLevel30::
	setvar VAR_TEMP_9, 30
	goto RyuPokeEditMenu
	
RyuSetLevel40::
	setvar VAR_TEMP_9, 40
	goto RyuPokeEditMenu
	
RyuSetLevel50::
	setvar VAR_TEMP_9, 50
	goto RyuPokeEditMenu
	
RyuSetLevel60::
	setvar VAR_TEMP_9, 60
	goto RyuPokeEditMenu
	
RyuSetLevel70::
	setvar VAR_TEMP_9, 70
	goto RyuPokeEditMenu
	
RyuSetLevel80::
	setvar VAR_TEMP_9, 80
	goto RyuPokeEditMenu
	
RyuSetLevel90::
	setvar VAR_TEMP_9, 90
	goto RyuPokeEditMenu
	
RyuSetLevel100::
	setvar VAR_RYU_PRICE_MULTIPLIER, 200
	release
	end

RyuExitSetLevel::
	setvar VAR_TEMP_9, 10
	goto RyuPokeEditMenu

RyuSetLevelBlankOption::
	setvar VAR_TEMP_9, 0
	goto RyuDebug_PasscodeMenu
	
RyuSetIvDebugMenu::
	special RyuIvSetter
	goto RyuPokeEditMenu
@==================================================================================================RYU EV USER MODE MENU

RyuUserModeEVMenu::
	msgbox RyuUserEVInfo MSGBOX_DEFAULT
	
	multichoicegrid 0, 4, 131, 2, 0
	switch VAR_RESULT
	case 0, RyuUserEVHp
	case 1, RyuUserEVAtk
	case 2, RyuUserEVDef
	case 3, RyuUserEVSpatk
	case 4, RyuUserEVSpdef
	case 5, RyuUserEVSpeed
	case 6, RyuUserEvExit
	case 7, RyuUserEvExit
	case 127, RyuUserEvExit
	release
	end
	
RyuUserEVHp::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_WAVE_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVHP
	addmonhappiness VAR_TEMP_2, 25
	takeitem ITEM_WAVE_MAIL, 1
	msgbox RyuEvSuccessMsgHP MSGBOX_DEFAULT
	release
	end

RyuUserEVAtk::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_BEAD_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_lt RyuUserEvNoImprint
	special RyuSetEVATK
	addmonhappiness VAR_TEMP_2, 25
	takeitem ITEM_BEAD_MAIL, 1
	msgbox RyuEvSuccessMsgAtk MSGBOX_DEFAULT
	release
	end
	
RyuUserEVDef::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_SHADOW_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVDEF
	addmonhappiness VAR_TEMP_2, 25
	takeitem ITEM_SHADOW_MAIL, 1
	msgbox RyuEvSuccessMsgDef MSGBOX_DEFAULT
	release
	end
	
RyuUserEVSpatk::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_TROPIC_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVSPATK
	addmonhappiness VAR_TEMP_2, 25
	takeitem ITEM_TROPIC_MAIL, 1
	msgbox RyuEvSuccessMsgSpatk MSGBOX_DEFAULT
	release
	end
	
RyuUserEVSpdef::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_DREAM_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVSPDEF
	addmonhappiness VAR_TEMP_2, 25
	takeitem ITEM_DREAM_MAIL, 1
	msgbox RyuEvSuccessMsgSpdef MSGBOX_DEFAULT
	release
	end
	
RyuUserEVSpeed::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_FAB_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVSPE
	addmonhappiness VAR_TEMP_2, 25
	takeitem ITEM_FAB_MAIL, 1
	msgbox RyuEvSuccessMsgSpeed MSGBOX_DEFAULT
	release
	end
	
RyuUserEvExit::
	closemessage
	release
	end
	
RyuUserEvNoImprint::
	msgbox EvNoImprints MSGBOX_DEFAULT
	closemessage
	release
	end
	
RyuUserEVInfo:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Genetic Imprinter\p"
	.string "{SHADOW LIGHT_GREY}Select a stat to reduce to\n"
	.string "0 for the first Pokémon\l"
	.string "in your party.\pThis operation cannot be\n"
	.string "undone.$"

RyuEvSuccessMsgHP:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}HP EV's were reduced to 0.\nOne HP Imprint consumed.$"
	
RyuEvSuccessMsgAtk:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Atk EV's were reduced to 0.\nOne Atk Imprint consumed.$"
	
RyuEvSuccessMsgDef:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Def EV's were reduced to 0.\nOne Def Imprint consumed.$"
	
RyuEvSuccessMsgSpatk:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}SpAtk EV's were reduced to 0.\nOne SpAtk Imprint consumed.$"
	
RyuEvSuccessMsgSpdef:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}SpDef EV's were reduced to 0.\nOne SpDef Imprint consumed.$"
	
RyuEvSuccessMsgSpeed:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Speed EV's were reduced to 0.\nOne Speed Imprint consumed.$"

EvNoImprints:
	.string "{COLOR LIGHT_RED}{SHADOW LIGHT_GREY}You don't have enough imprints.\pObtain more at Lilycove\nTraining Center.$"
	
@@MUSIC DEBUG MENU=================================================================================
	
RyuDebugMenu2::
	call_if_unset FLAG_RYU_JUKEBOX_ENABLED, RyuMusicFlagOff
	call_if_set FLAG_RYU_JUKEBOX_ENABLED, RyuMusicFlagOn
	msgbox RyuJukeboxIntro MSGBOX_DEFAULT
	multichoicegrid 3, 0, 121, 3, 0
	switch VAR_RESULT
	case 0, RyuBGMAshroad @MUS_ASHROAD
	case 1, RyuBGMCasino @MUS_CASINO
	case 2, RyuBGMMtPyre @MUS_MACHUPI
	case 3, RyuBGMMagmaHQ @MUS_AJITO
	case 4, RyuBGMDive @MUS_DEEPDEEP
	case 5, RyuBGMBiking @MUS_CYCLING
	case 6, RyuBGMField @MUS_FIELD13
	case 7, RyuBGMMuseum @MUS_FUNE_KAN
	case 8, RyuBGMLilyCov @MUS_MINAMO
	case 9, RyuBGMViridia @MUS_NIBI
	case 10, RyuBGMVermill @mus_rg_santoan
	case 11, RyuJukeboxCancel
	case 127, RyuJukeboxCancel
	
RyuMusicFlagOn:
	playse SE_EXPMAX
	waitse
	return
	
RyuMusicFlagOff:
	playse SE_PIN
	waitse
	return
	
RyuJukeboxIntro:
	.string "Pick a song to use in the overworld.\n"
	.string "It will play when normal BGM would.$"
	
RyuBGMAshroad::
	fadenewbgm MUS_ASHROAD
	setvar VAR_RYU_JUKEBOX, MUS_ASHROAD
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuBGMVermill::
	fadenewbgm MUS_RG_SANTOAN
	setvar VAR_RYU_JUKEBOX, MUS_RG_SANTOAN
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuBGMViridia::
	fadenewbgm MUS_NIBI
	setvar VAR_RYU_JUKEBOX, MUS_NIBI
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuBGMLilyCov::
	fadenewbgm MUS_MINAMO
	setvar VAR_RYU_JUKEBOX, MUS_MINAMO
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuBGMMuseum::
	fadenewbgm MUS_FUNE_KAN
	setvar VAR_RYU_JUKEBOX, MUS_FUNE_KAN
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuBGMField::
	fadenewbgm MUS_FIELD13
	setvar VAR_RYU_JUKEBOX, MUS_FIELD13
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuBGMBiking::
	fadenewbgm MUS_CYCLING
	setvar VAR_RYU_JUKEBOX, MUS_CYCLING
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end

RyuBGMDive::
	fadenewbgm MUS_DEEPDEEP
	setvar VAR_RYU_JUKEBOX, MUS_DEEPDEEP
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end

RyuBGMMagmaHQ::
	fadenewbgm MUS_AJITO
	setvar VAR_RYU_JUKEBOX, MUS_AJITO
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end

RyuBGMMtPyre::
	fadenewbgm MUS_MACHUPI
	setvar VAR_RYU_JUKEBOX, MUS_MACHUPI
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuBGMCasino::
	fadenewbgm MUS_CASINO
	setvar VAR_RYU_JUKEBOX, MUS_CASINO
	setflag FLAG_RYU_JUKEBOX_ENABLED
	release
	end
	
RyuJukeboxCancel::
	fadedefaultbgm
	clearflag FLAG_RYU_JUKEBOX_ENABLED
	setvar VAR_RYU_JUKEBOX, 999
	release
	end

@@------------------------------------------------------------------------------------------------- NUZLOCKE CHALLENGE RELATED
RyuMartsDisabledNuzlocke::
	msgbox RyuMartsDisabledNuzlockeMsg MSGBOX_DEFAULT
	release
	end

RyuTCDisabledNuzlocke::
	msgbox RyuTCDisabledNuzlockeMsg MSGBOX_DEFAULT
	release
	end

Ryu_YouHaveNoMons::
	msgbox CantHealNoMons
	release
	end

CantHealNoMons:
	.string "You don't have any pokemon to heal.\nPlease return another time!$"

RyuMartsDisabledNuzlockeMsg:
	.string "{COLOR DARK_GREY}{SHADOW RED}Sorry, but you can't use this while\n"
	.string "playing in nuzlocke mode. Fight more\p"
	.string "Gyms!$"

RyuTCDisabledNuzlockeMsg:
	.string "{COLOR DARK_GREY}{SHADOW RED}Sorry, but the Training Center is\n"
	.string "disabled while playing in nuzlocke\p"
	.string "mode. Grind in grass!$"
	
RyuHealed:
	.string "Your team has been restored to full\n"
	.string "health. Have a nice day!$"
	
RyuUsesGone:
	.string "{COLOR DARK_GREY}{SHADOW RED}You cannot use this Pokemon Center\n"
	.string "anymore.$"

RyuHealedGym::
	special HealPlayerParty
	msgbox RyuHealedGymMsg MSGBOX_DEFAULT
	closemessage
	return
	
RyuScripts_HardcoreGymReward::
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 1
	release
	end

RyuGymItemReward1::
	giveitem ITEM_SUPER_POTION, 1
	giveitem ITEM_GREAT_BALL, 1
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM1HANDOUT
	return

RyuGymItemReward2::
	giveitem ITEM_SUPER_POTION, 2
	giveitem ITEM_GREAT_BALL, 2
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM2HANDOUT
	return

RyuGymItemReward3::
	giveitem ITEM_SUPER_POTION, 3
	giveitem ITEM_GREAT_BALL, 3
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM3HANDOUT
	return

RyuGymItemReward4::
	giveitem ITEM_SUPER_POTION, 4
	giveitem ITEM_GREAT_BALL, 4
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM4HANDOUT
	return

RyuGymItemReward5::
	giveitem ITEM_SUPER_POTION, 5
	giveitem ITEM_GREAT_BALL, 5
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM5HANDOUT
	return

RyuGymItemReward6::
	giveitem ITEM_SUPER_POTION, 6
	giveitem ITEM_GREAT_BALL, 6
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM6HANDOUT
	return

RyuGymItemReward7::
	giveitem ITEM_SUPER_POTION, 7
	giveitem ITEM_GREAT_BALL, 7
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM7HANDOUT
	return

RyuGymItemReward8::
	giveitem ITEM_SUPER_POTION, 8
	giveitem ITEM_GREAT_BALL, 8
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	setflag FLAG_RYU_GYM8HANDOUT
	return

RyuHealedGymMsg:
	.string "I've restored your Pokémon to\n"
	.string "full health.$"

RyuGameClearedMsg:
	.string "{COLOR GREEN} {SHADOW LIGHT_GREY}Congratulations on clearing the game\n"
	.string "in nuzlocke mode! It's a momentous\p"
	.string "achievment, considering how hard\n"
	.string "the base game is. Add Ryuhouji/2180\p"
	.string "on discord and let me know you\n"
	.string "reached this point!\p"
	.string "Nuzlocke restrictions have been\p"
	.string "lifted, enjoy the battle frontier!$"
	
RyuEmptySpace:
	.string "$"
	
RyuFailedNuzlocke::
	msgbox NuzlockeFail MSGBOX_DEFAULT
	closemessage
	msgbox NormalModeStart MSGBOX_DEFAULT
	release
	end
	
NuzlockeFail:
	.string "You have failed this nuzlocke\n"
	.string "challenge. Take this token of\p"
	.string "pity.$"
	
NormalModeStart:
	.string "You've been given a Pokémon.\n"
	.string "You may now play the game normally.$"
	
	
@==================================================================================================PLAYER IS HELPING AQUA

Ryu_AquaEmployed::
	random 4
	switch VAR_RESULT
	case 0, RyuAquaSalute
	case 1, RyuAquaAdmin1
	case 2, RyuAquaAdmin2
	case 3, RyuNoSpc
	case 4, RyuAquaCommander


RyuAquaSalute::
	msgbox RyuAquaSaluteMsg MSGBOX_DEFAULT
	release
	end
	
RyuAquaAdmin1::
	msgbox RyuAA1 MSGBOX_DEFAULT
	release
	end
	
RyuAquaAdmin2::
	msgbox RyuAA2 MSGBOX_DEFAULT
	release
	end
	
RyuAquaCommander::
	msgbox RyuCmd MSGBOX_DEFAULT
	release
	end
	
RyuNoSpc::
	return
	
RyuAquaSaluteMsg:
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Halt! Oh, you're Shelly's new pet.\n"
	.string "Carry on, soldier!$"
	
RyuAA1:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The grunt salutes you.)\n"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Good afternoon, Lieutenant {PLAYER}.\p"
	.string "Everything's good on my front!$"
	
RyuAA2:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The grunt salutes you.)\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Lieutenant, Hi, What brings you here\n"
	.string "today?$"
	
RyuCmd:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(The grunt energetically salutes you)\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Commander, If there's anything I can\n"
	.string "do, please let me know!$"
	
@==================================================================================================Teleport multichoice
RyuTeleport::
	lock
	goto_if_set FLAG_RYU_WAYSTONE_DISABLED, RyuTeleportDisabled
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuTeleportUseCheck
	setflag FLAG_RYU_TEMPTP
	msgbox MSG_Teleport MSGBOX_SIGN
	multichoicegrid 0, 0, 126, 3, 0
	switch VAR_RESULT
	case 0, RT_Home
	case 1, RT_Oldale
	case 2, RT_Petalburg
	case 3, RT_Rustboro
	case 4, RT_Verdanturf
	case 5, RT_Slateport
	case 6, RT_Dewford
	case 7, RT_Pacifidlog
	case 8, RT_Lavaridge
	case 9, RT_Fallarbor
	case 10, RT_Fortree
	case 11, RT_Mauville
	case 12, RT_Lilycove
	case 13, RT_Sootopolis
	case 14, RT_Mossdeep
	case 15, RT_Evergrande
	case 16, RT_Landmarks
	case 17, RT_Exit
	case 127, RT_Exit
	closemessage
	release
	end

RyuTeleportUseCheck:
	compare VAR_RYU_NUZLOCKE_WAYSTONE_USES, 0
	goto_if_eq RyuTeleportUseExceeded
	subvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 1
	return

RyuTeleportUseExceeded:
	msgbox RTDNMUEMsg
	release
	end

RyuTeleportDisabled:
	msgbox RTDMsg
	release
	end

RTDMsg:
	.string "{COLOR LIGHT_RED}{SHADOW LIGHT_GREY}The waystone has been disabled\ntemporarily.\pFinish whatever you're doing\nand it will be enabled again.$"

RTDNMUEMsg:
	.string "You've exceeded the use count\nfor the waystone.\pDefeat a new Gym!$"

MSG_Teleport:
	.string "Teleport to where?$"
	
	
RT_Home::
	warpteleport MAP_LITTLEROOT_TOWN, 255, 10, 10
	release
	end
	
RT_Oldale::
	goto_if_unset FLAG_VISITED_OLDALE_TOWN, RT_NoFlag
	warpteleport MAP_OLDALE_TOWN, 255, 10, 9
	release
	end
	
RT_Petalburg::
    goto_if_unset FLAG_VISITED_PETALBURG_CITY, RT_NoFlag
	warpteleport MAP_PETALBURG_CITY, 255, 16, 16
	release
	end
	
RT_Rustboro::
    goto_if_unset FLAG_VISITED_RUSTBORO_CITY, RT_NoFlag
	warpteleport MAP_RUSTBORO_CITY, 255, 20, 49
	release
	end
	
RT_Verdanturf::
    goto_if_unset FLAG_VISITED_VERDANTURF_TOWN, RT_NoFlag
	warpteleport MAP_VERDANTURF_TOWN, 255, 13, 6
	release
	end
	
RT_Slateport::
    goto_if_unset FLAG_VISITED_SLATEPORT_CITY, RT_NoFlag
	warpteleport MAP_SLATEPORT_CITY, 255, 17, 22
	release
	end
	
RT_Dewford::
    goto_if_unset FLAG_VISITED_DEWFORD_TOWN, RT_NoFlag
	warpteleport MAP_DEWFORD_TOWN, 255, 9, 10
	release
	end
	
RT_Pacifidlog::
    goto_if_unset FLAG_VISITED_PACIFIDLOG_TOWN, RT_NoFlag
	warpteleport MAP_PACIFIDLOG_TOWN, 255, 8, 16
	release
	end
	
RT_Lavaridge::
    goto_if_unset FLAG_VISITED_LAVARIDGE_TOWN, RT_NoFlag
	warpteleport MAP_LAVARIDGE_TOWN, 255, 12, 8
	release
	end
	
RT_Fallarbor::
    goto_if_unset FLAG_VISITED_FALLARBOR_TOWN, RT_NoFlag
	warpteleport MAP_FALLARBOR_TOWN, 255, 9, 11
	release
	end
	
RT_Fortree::
    goto_if_unset FLAG_VISITED_FORTREE_CITY, RT_NoFlag
	warpteleport MAP_FORTREE_CITY, 255, 5, 9
	release
	end
	
RT_Mauville::
    goto_if_unset FLAG_VISITED_MAUVILLE_CITY, RT_NoFlag
	warpteleport MAP_MAUVILLE_CITY, 255, 18, 7
	release
	end
	
RT_Lilycove::
    goto_if_unset FLAG_VISITED_LILYCOVE_CITY, RT_NoFlag
	warpteleport MAP_LILYCOVE_CITY, 255, 22, 17
	release
	end
	
RT_Sootopolis::
    goto_if_unset FLAG_VISITED_SOOTOPOLIS_CITY, RT_NoFlag
	warpteleport MAP_SOOTOPOLIS_CITY, 255, 42, 37
	release
	end
	
RT_Mossdeep::
    goto_if_unset FLAG_VISITED_MOSSDEEP_CITY, RT_NoFlag
	warpteleport MAP_MOSSDEEP_CITY, 255, 25, 17
	release
	end
	
RT_Evergrande::
	goto_if_set FLAG_LANDMARK_POKEMON_LEAGUE, RT_PokemonLeague
	goto_if_unset FLAG_VISITED_EVER_GRANDE_CITY, RT_NoFlag
	warpteleport MAP_EVER_GRANDE_CITY, 255, 27, 49
	release
	end
	
RT_Landmarks::
	multichoicedefault 3, 0, 128, 9, 0
	switch VAR_RESULT
	case 0, RT_BattleFrontier
	case 1, RT_MtPyre
	case 2, RT_LCCDEPT
	case 3, RT_LCAH
	case 4, RT_MCMH
	case 5, RT_BF_AS
	case 6, RT_BF_CB
	case 127, RyuTeleport
	release
	end
	
RT_BattleFrontier::
    goto_if_unset FLAG_LANDMARK_BATTLE_FRONTIER, RT_NoBfFlag
	multichoicedefault 3, 0, 127, 9, 0
	switch VAR_RESULT
	case 0, RT_BF_GATE
	case 1, RT_BF_BT@tower
	case 2, RT_BF_BP@pike
	case 3, RT_BF_BP2@palace
	case 4, RT_BF_BP3@pyramid
	case 5, RT_BF_BF@factory
	case 6, RT_BF_BA@arena
	case 7, RT_BF_BD@dome
	case 8, RT_BF_CB@go back to main teleport menu
	case 127, RyuTeleport@also go back to teleport menu
	release
	end

RT_MtPyre::
	goto_if_unset FLAG_RYU_LANDMARK_MTPYRE, RT_NoFlag
	warpteleport MAP_MT_PYRE_EXTERIOR, 255, 19, 14
	release
	end

RT_LCCDEPT::
    goto_if_unset FLAG_RYU_LANDMARK_LCCDEPTSTORE, RT_NoFlag
	warpteleport MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP, 255, 4, 5
	release
	end

RT_LCAH::
    goto_if_unset FLAG_RYU_PLAYER_HELPING_AQUA, RT_NoFlag
	@warpteleport MAP_NEW_MAP4, 255, 7, 14
	release
	end
	
RT_MCMH::
	msgbox RT_NYI MSGBOX_SIGN
	@goto_if_unset FLAG_RYU_PLAYER_HELPING_MAGMA, RT_NoFlag
	goto RT_Landmarks
	release
	end
	
RT_BF_GATE::
	warpteleport MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 26, 50
	release
	end
	
RT_BF_BT::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 12, 6
	release
	end
	
RT_BF_BP::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 7
	release
	end
	
RT_BF_BP2::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 12, 10
	release
	end
	
RT_BF_BP3::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 14
	release
	end
	
RT_BF_BF::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 255, 9, 10
	release
	end
	
RT_BF_BA::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 10
	release
	end
	
RT_BF_BD::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 11, 11
	release
	end

RT_BF_AS::
	goto_if_unset FLAG_LANDMARK_ABANDONED_SHIP, RT_NoFlag
	warpteleport MAP_ABANDONED_SHIP_DECK, 255, 11, 6
	release
	end
	
RT_BF_CB::
	goto RyuTeleport
	
RT_NYI:
	.string "That storyline hasn't been\nimplemented yet.$"

	
RT_NoBfFlag::
	msgbox MSG_RT_NOFLAGBT MSGBOX_DEFAULT
	closemessage
	goto RyuTeleport
	
RT_NoFlag::
	msgbox RT_NOFLAGMSG MSGBOX_DEFAULT
	goto RyuTeleport
	
MSG_RT_NOFLAGBT:
	.string "You haven't been to the Frontier yet.$"
	
RT_NOFLAGMSG:
	.string "You haven't been here yet.$"
	
RT_PokemonLeague::
	warpteleport MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F, 255, 9, 6
	release
	end
	
RT_Exit::
	closemessage
	release
	end

@======================================== Forecaster

Ryu_Forecaster::
	msgbox RyuForecasterIntro MSGBOX_SIGN
	closemessage
	multichoicedefault 0, 0, 134, 0, 1 
	switch VAR_RESULT
	case 0, Ryu_FCClear
	case 1, Ryu_FCLightRain
	case 2, Ryu_FCStorm
	case 3, Ryu_FCDrought
	case 4, Ryu_FCSandstorm
	case 5, Ryu_FCSnow
	case 6, Ryu_FCShade
	case 7, Ryu_FCExit

RyuForecasterIntro:
	.string "Please select desired weather.\nSelecting 'Clear' will\lrevert to default.$"

Ryu_FCClear::
	lock
	setweather WEATHER_NONE
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_NONE
	clearflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCLightRain::
	lock
	setweather WEATHER_RAIN
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_RAIN
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCStorm::
	lock
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_RAIN_THUNDERSTORM
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCDrought::
	lock
	setweather WEATHER_DROUGHT
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_DROUGHT
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCSandstorm::
	lock
	setweather WEATHER_SANDSTORM
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_SANDSTORM
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCSnow::
	lock
	setweather WEATHER_SNOW
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_SNOW
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCShade::
	lock
	setweather WEATHER_SHADE
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_SHADE
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCExit::
	release
	end

@Random pokecenter music===========================================================================

PCCheckForMusicChange::
	map_script_2 VAR_TEMP_0, 0, Ryu_RandomizePCMusic
	.2byte 0

Ryu_RandomizePCMusic::
	setvar VAR_TEMP_0, 20
	gfec
	setobjectxy EVENT_OBJ_ID_FOLLOWER, VAR_TEMP_1, VAR_TEMP_2
	call_if_set FLAG_RYU_JUKEBOX_ENABLED, RyuRtMusicOverride
	random 6
	switch VAR_RESULT
	case 0, PCPlay1
	case 1, PCPlay2
	case 2, PCPlay3
	case 3, PCPlay1
	case 4, PCPlay2
	case 5, PCPlay3
	fadenewbgm MUS_NAMINORI
	release
	end
	
PCPlay1:
	fadenewbgm MUS_POKECEN
	release
	end
	
PCPlay2:
	fadenewbgm MUS_PCC
	release
	end
	
PCPlay3:
	fadenewbgm MUS_RG_POKECEN
	release
	end
	
PCPlay4:
	fadenewbgm MUS_NAMINORI
	release
	end
	
@==================================================Route Randomized Music==========================

RTCheckForMusicChange::
	call Ryu_RandomizeRTMusic
	.2byte 0
	
Ryu_RandomizeRTMusic::
	setvar VAR_TEMP_A, 20
	random 13
	call_if_set FLAG_RYU_JUKEBOX_ENABLED, RyuRtMusicOverride
	switch VAR_RESULT
	case 0, RTPlay1
	case 1, RTPlay2
	case 2, RTPlay3
	case 3, RTPlay4
	case 4, RTPlay5
	case 5, RTPlay6
	case 6, RTPlay7
	case 7, RTPlay8
	case 8, RTPlay9
	case 9, RTPlay10
	case 10, RTPlay11
	case 11, RTPlay12
	case 12, RTPlay13
	release
	end

RyuRtMusicOverride::
	savebgm VAR_RYU_JUKEBOX
	fadenewbgm VAR_RYU_JUKEBOX
	release
	end
	
RTPlay1::
	playbgm MUS_DOORO1, 0
	setvar VAR_TEMP_F, MUS_DOORO1
	release
	end
	
RTPlay2::
	playbgm MUS_DOORO_X1, 0
	setvar VAR_TEMP_F, MUS_DOORO_X1
	release
	end
	
RTPlay3::
	playbgm MUS_DOORO_X3, 0
	setvar VAR_TEMP_F, MUS_DOORO_X3
	release
	end
	
RTPlay4::
	playbgm MUS_DOORO_X4, 0
	setvar VAR_TEMP_F, MUS_DOORO_X4
	release
	end
	
RTPlay5::
	playbgm MUS_NEXTROAD, 0
	setvar VAR_TEMP_F, MUS_NEXTROAD
	release
	end
	
RTPlay6::
	playbgm MUS_GRANROAD, 0
	setvar VAR_TEMP_F, MUS_GRANROAD
	release
	end
	
RTPlay7::
	playbgm MUS_ASHROAD, 0
	setvar VAR_TEMP_F, MUS_ASHROAD
	release
	end
	
RTPlay8::
	playbgm MUS_KAZANBAI, 0
	setvar VAR_TEMP_F, MUS_KAZANBAI
	release
	end
	
RTPlay9::
	playbgm MUS_RG_LOAD01, 0
	setvar VAR_TEMP_F, MUS_RG_LOAD01
	release
	end
	
RTPlay10::
	playbgm MUS_RG_OPENING, 0
	setvar VAR_TEMP_F, MUS_RG_OPENING
	release
	end
	
	
RTPlay11:;
	playbgm MUS_RG_LOAD02, 0
	setvar VAR_TEMP_F, MUS_RG_LOAD02
	release
	end
	
	
RTPlay12::
	playbgm MUS_RG_LOAD03, 0
	setvar VAR_TEMP_F, MUS_RG_LOAD03
	release
	end
	
RTPlay13::
	playbgm MUS_RG_NANASHIMA, 0
	setvar VAR_TEMP_F, MUS_RG_NANASHIMA
	release
	end

Ryu_CantUsePcCharging::
	msgbox RyuCantUsePCCHARGING 
	closemessage
	release
	end

RyuCantUsePCCHARGING:
	.string "The Wireless PC needs to recharge.\nPlease try again later.$"
	

@+=================================================================================================Player RyuSetLevelBlankOption

BF_PlayerBank::
	msgbox Ryu_WTB
	showmoneybox 18, 0, 0
	nop
	nop
	multichoicedefault 0, 0, 137, 2, 1
	switch VAR_RESULT
	case 0, BF_PlayerBankDeposit
	case 1, BF_PlayerBankWithdraw
	case 2, BF_PlayerBankCancel
	goto BF_PlayerBankCancel
	end
	
Ryu_WTB:
	.string "Welcome to Frontier Bank.\pWhat would you like to do today?$"

BF_PlayerBankDeposit::
	msgbox BF_DepositQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne BF_CancelTransaction
	multichoice 0, 0, 138, 0
	switch VAR_RESULT
	case 0, BF_Dep10k
	case 1, BF_Dep50k
	case 2, BF_Dep100k
	case 3, BF_Dep1m
	case 4, BF_CancelTransaction
	goto BF_CancelTransaction
	end
	
BF_DepositQuery:
	.string "Would you like to\nmake a deposit?$"


BF_PlayerBankWithdraw::
	msgbox BF_WithdrawQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne BF_CancelTransaction
	multichoice 0, 0, 138, 0
	switch VAR_RESULT
	case 0, BF_Pull10k
	case 1, BF_Pull50k
	case 2, BF_Pull100k
	case 3, BF_Pull1m
	case 4, BF_CancelTransaction
	goto BF_CancelTransaction
	end
	
BF_WithdrawQuery:
	.string "Would you like to\nmake a withdrawal?$"

BF_PlayerBankCancel::
	special RyuGetPlayerBankBal
	msgbox BF_PlayerBankAccountStatus
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_PlayerBankAccountStatus:
	.string "Your balance is currently:\n{COLOR LIGHT_GREEN}{SHADOW GREEN} {STR_VAR_2}$"
	
BF_CancelTransaction::
	msgbox BF_TransCancel
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_TransCancel:
	.string "Cancelling the transaction.$"
	
BF_RyuInsufficientBalance::
	msgbox BF_NotEnoughBalance
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_NotEnoughBalance:
	.string "You do not have enough money in\nyour account to do this transaction.\pYour balance is: {COLOR LIGHT_GREEN}{SHADOW GREEN}{STR_VAR_2}$"
	
BF_HND:
	.string "Thanks for using Frontier Bank\n and have a nice day!$"

BF_Dep10k::
	setvar VAR_TEMP_A, 10000
	setvar VAR_TEMP_B, 1
	special RyuDepositPlayerMoney
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Dep50k::
	setvar VAR_TEMP_A, 50000
	setvar VAR_TEMP_B, 1
	special RyuDepositPlayerMoney
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Dep100k::
	setvar VAR_TEMP_A, 50000
	setvar VAR_TEMP_B, 2
	special RyuDepositPlayerMoney
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Dep1m::
	setvar VAR_TEMP_A, 50000
	setvar VAR_TEMP_B, 20
	special RyuDepositPlayerMoney
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Pull10k::
	setvar VAR_TEMP_A, 10000
	setvar VAR_TEMP_B, 1
	specialvar VAR_RESULT, RyuWithdrawPlayerMoney
	compare VAR_RESULT, TRUE
	goto_if_ne BF_RyuInsufficientBalance
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Pull50k::
	setvar VAR_TEMP_A, 50000
	setvar VAR_TEMP_B, 1
	specialvar VAR_RESULT, RyuWithdrawPlayerMoney
	compare VAR_RESULT, TRUE
	goto_if_ne BF_RyuInsufficientBalance
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Pull100k::
	setvar VAR_TEMP_A, 50000
	setvar VAR_TEMP_B, 2
	specialvar VAR_RESULT, RyuWithdrawPlayerMoney
	compare VAR_RESULT, TRUE
	goto_if_ne BF_RyuInsufficientBalance
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Pull1m::
	setvar VAR_TEMP_A, 50000
	setvar VAR_TEMP_B, 20
	specialvar VAR_RESULT, RyuWithdrawPlayerMoney
	compare VAR_RESULT, TRUE
	goto_if_ne BF_RyuInsufficientBalance
	msgbox BF_Processing
	delay 10
	closemessage
	msgbox BF_TransSuccessful
	closemessage
	updatemoneybox 0, 0
	nop
	nop
	msgbox BF_HND
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
BF_Processing:
	.string "We're currently processing\nthe transaction...$"
	
BF_TransSuccessful:
	.string "The transaction was successful.\pYour new balance is:\n{COLOR LIGHT_GREEN}{SHADOW GREEN}{STR_VAR_2}$"

@=================================================Ball checkplayergender


RyuBallChanger::
	msgbox BCIntro
	multichoicegrid 2, 0, 141, 3, 1
	switch VAR_RESULT
	case 0, BCPokeball
	case 1, BCGreatball
	case 2, BCUltraball
	case 3, BCLuxuryball
	case 4, BCPremierball
	case 5, BCRepeatball
	case 6, BCTimerball
	case 7, BCNestball
	case 8, BCNetball
	case 9, BCSafariball
	case 10, BCDiveball
	case 11, BCCancel
	end

BCPokeball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_POKE_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 4
	takeitem ITEM_POKE_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCGreatball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_GREAT_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 3
	takeitem ITEM_GREAT_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCUltraball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_ULTRA_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 2
	takeitem ITEM_ULTRA_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCLuxuryball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_LUXURY_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 11
	takeitem ITEM_LUXURY_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCPremierball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_PREMIER_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 12
	takeitem ITEM_PREMIER_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCRepeatball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_REPEAT_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 9
	takeitem ITEM_REPEAT_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCTimerball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_TIMER_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 10
	takeitem ITEM_TIMER_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCNestball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_NEST_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 8
	takeitem ITEM_NEST_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCNetball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_NET_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 6
	takeitem ITEM_NET_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCSafariball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_SAFARI_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 5
	takeitem ITEM_SAFARI_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCDiveball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_DIVE_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 7
	takeitem ITEM_DIVE_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCIntro:
	.string "Welcome to the ball changer menu.\pOnce you make your selection,\nyou will be charged ¥10000\land the chosen ball will be consumed.$"

BCCancel::
	msgbox BC_Cancelled
	closemessage
	release
	end

BC_NoBall::
	msgbox BC_NeedBall
	release
	end

BC_NotEnoughMoney:
	msgbox BC_NeedMoney
	release
	end

BC_Cancelled:
	.string "Okay. We can try again later.$"

BC_Success:
	.string "Success!\nThe ball has been changed.\pYou were charged ¥10000, and\nthe ball you changed to was consumed.$"

BC_NeedBall:
	.string "Sorry, but you must have at least\none of the ball you want to change to.$"

BC_NeedMoney:
	.string "Sorry, but you do not have enough\nmoney to do this.\pIt costs ¥10000.$"
	
@@+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Follower System

RyuCancelFollowerForQuest::  @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	msgbox RyuCantHaveFollower MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq RF_FollowerLeaveCall
	release
	end

RyuResetFollowerPosition::
	gfec
	setobjectxy EVENT_OBJ_ID_FOLLOWER, VAR_TEMP_1, VAR_TEMP_2
	setvar VAR_TEMP_9, 1
	end

RyuResetFollowerPositionAR::
	gfec
	setobjectxy EVENT_OBJ_ID_FOLLOWER, VAR_TEMP_1, VAR_TEMP_2
	setvar VAR_TEMP_9, 1
	return

RyuForceCancelFollowerForQuest:: @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	goto RF_FollowerLeaveCall
	

RyuFollowerSelectNPCScript::
	switch VAR_RYU_FOLLOWER_ID
	case EVENT_OBJ_GFX_TWIN, LRT_MinnieScript
	case EVENT_OBJ_GFX_AQUA_MEMBER_F, RyuFollower_ShellyScript
	case EVENT_OBJ_GFX_WOMAN_2, RyuFollower_LanetteScript
	end

RyuFollower_ShellyScript::
	goto_if_set FLAG_RYU_WAYSTONE_DISABLED, RyuFollower_MagmaShelly
	msgbox RyuFollower_ShellyLeaveMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RyuFollower_MagmaShelly::
	goto MH_FollowerShellyScript
	end
	
RyuFollower_LanetteScript::
	msgbox RyuFollowerLanetteLeaveMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RF_FollowerLeaveCall::
	clearflag FLAG_RYU_HAS_FOLLOWER
	destroyfollower
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	return
	
RF_FollowerLeave:
	clearflag FLAG_RYU_HAS_FOLLOWER
	destroyfollower
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	release
	end

RyuFollowerAllySelector::
	special RyuFollowerToTrainerID
	return
	
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


ryu_return::
	return

ryu_end::
	release
	end

@==================================================================================================Theme changer

Ryu_SwitchTheme::
	compare VAR_RYU_THEME_NUMBER, 0
	goto_if_eq Ryu_SwitchToDarkTheme
	compare VAR_RYU_THEME_NUMBER, 1
	goto_if_eq Ryu_SwitchToDefaultTheme
	end

Ryu_SwitchToDarkTheme::
	setvar VAR_RYU_THEME_NUMBER, 1
	msgbox RyuNowUsingDarkTheme
	release
	end

Ryu_SwitchToDefaultTheme::
	setvar VAR_RYU_THEME_NUMBER, 0
	msgbox RyuNowUsingDefaultTheme
	release
	end

RyuNowUsingDarkTheme:
	.string "You're now using the dark theme.$"

RyuNowUsingDefaultTheme:
	.string "Switched to default theme.$"


