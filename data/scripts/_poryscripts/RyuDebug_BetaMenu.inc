StartBetaMenu::
	setflag FLAG_RYU_BETA_MENU_USED
	msgbox BetaMenuIntro
	closemessage
	goto RDB_BetaMenuStandalone
	return


RDB_BetaMenuStandalone::
	multichoicedefault 30, 0, MULTI_BETA_MENU, 7, 0
	switch VAR_RESULT
	case 0, RDB_BetaMenuStandalone_3
	case 1, RDB_BetaMenuStandalone_4
	case 2, RDB_BetaMenuStandalone_5
	case 3, RDB_BetaMenuStandalone_6
	case 4, RDB_BetaMenuStandalone_7
	case 5, RDB_BetaMenuStandalone_8
	case 6, RDB_BetaMenuStandalone_9
	case 7, RDB_BetaMenuStandalone_10
RDB_BetaMenuStandalone_1:
	goto RDBM_ExitResetMenu
	return

RDB_BetaMenuStandalone_3:
	goto RDBM_ViewSaveVersion
	goto RDB_BetaMenuStandalone_1

RDB_BetaMenuStandalone_4:
	goto RDBM_CheckWaystone
	goto RDB_BetaMenuStandalone_1

RDB_BetaMenuStandalone_5:
	goto RDBM_BlankOption
	goto RDB_BetaMenuStandalone_1

RDB_BetaMenuStandalone_6:
	goto RDBM_ResetTemporaryBattleFlags
	goto RDB_BetaMenuStandalone_1

RDB_BetaMenuStandalone_7:
	goto RDBM_ResetBadges
	goto RDB_BetaMenuStandalone_1

RDB_BetaMenuStandalone_8:
	goto RDBM_ResetGCMS
	goto RDB_BetaMenuStandalone_1

RDB_BetaMenuStandalone_9:
	goto RDBM_TeleportHome
	goto RDB_BetaMenuStandalone_1

RDB_BetaMenuStandalone_10:
	goto RDBM_ExitResetMenu
	goto RDB_BetaMenuStandalone_1


RDBM_ViewSaveVersion::
	buffernumberstring 0, VAR_SAVE_FILE_CREATED_ON_VERSION
	msgbox RDBM_ShowSaveFileOriginalVersion
	release
	end


RDBM_BlankOption::
	msgbox RDBM_BlankOption_Text_0
	goto RDB_BetaMenuStandalone
	return


RDBM_CheckWaystone::
	specialvar VAR_RESULT, RyuCheckIfWaystoneShouldBeDisabled
	switch VAR_RESULT
	case 10, RDBM_CheckWaystone_3
	case 20, RDBM_CheckWaystone_4
	case 30, RDBM_CheckWaystone_5
	case 40, RDBM_CheckWaystone_6
	case 50, RDBM_CheckWaystone_7
	case 60, RDBM_CheckWaystone_8
	case 70, RDBM_CheckWaystone_9
	case 80, RDBM_CheckWaystone_10
	case 90, RDBM_CheckWaystone_11
	case 100, RDBM_CheckWaystone_12
	case 110, RDBM_CheckWaystone_13
	case 120, RDBM_CheckWaystone_14
RDBM_CheckWaystone_1:
	msgbox WaystoneEnabled
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	closemessage
	release
	end

RDBM_CheckWaystone_3:
	msgbox RDBM_CheckWaystone_Text_0
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_4:
	msgbox RDBM_CheckWaystone_Text_1
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_5:
	msgbox RDBM_CheckWaystone_Text_2
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_6:
	msgbox RDBM_CheckWaystone_Text_3
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_7:
	msgbox RDBM_CheckWaystone_Text_4
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_8:
	msgbox RDBM_CheckWaystone_Text_5
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_9:
	msgbox RDBM_CheckWaystone_Text_6
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_10:
	msgbox RDBM_CheckWaystone_Text_7
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_11:
	msgbox RDBM_CheckWaystone_Text_8
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_12:
	msgbox RDBM_CheckWaystone_Text_9
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_13:
	msgbox RDBM_CheckWaystone_Text_10
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1

RDBM_CheckWaystone_14:
	msgbox RDBM_CheckWaystone_Text_11
	goto RDBM_WaystoneDisabled
	goto RDBM_CheckWaystone_1


RDBM_WaystoneDisabled::
	msgbox WaystoneDisabled
	closemessage
	release
	end


RDBM_ResetTemporaryBattleFlags::
	clearflag FLAG_RYU_MAX_SCALE
	clearflag FLAG_RYU_BOSS_WILD
	clearflag FLAG_RYU_RANDOMBATTLE
	msgbox RDBM_ResetTempFlagsMsg
	release
	end


RDBM_ResetBadges::
	clearflag FLAG_BADGE01_GET
	clearflag FLAG_BADGE02_GET
	clearflag FLAG_BADGE03_GET
	clearflag FLAG_BADGE04_GET
	clearflag FLAG_BADGE05_GET
	clearflag FLAG_BADGE06_GET
	clearflag FLAG_BADGE07_GET
	clearflag FLAG_BADGE08_GET
	msgbox RDBM_BadgesReset
	release
	end


RDBM_ResetGCMS::
	lockall
	setvar VAR_RYU_GCMS_SPECIES, 0
	setvar VAR_RYU_GCMS_VALUE, 0
	msgbox RDBM_GCMSReset
	release
	end


RDBM_ExitResetMenu::
	msgbox RDBM_Exiting MSGBOX_DEFAULT
	release
	end


RDBM_TeleportHome::
	goto_if_set FLAG_RYU_FRONTIER_MODE, RDBM_TeleportHome_2
RDBM_TeleportHome_1:
	goto_if_set FLAG_RYU_LIMBO, RDBM_TeleportHome_5
	msgbox RGBM_TPHOME
	closemessage
	goto RT_Home
	return

RDBM_TeleportHome_2:
	goto Ryu_FrontierModeCheckLeave
	goto RDBM_TeleportHome_1

RDBM_TeleportHome_5:
	msgbox RDBM_TeleportHome_Text_0
	release
	end


RDBM_BlankOption_Text_0:
	.string "This option doesn't currently do\n"
	.string "anything.$"

RDBM_CheckWaystone_Text_0:
	.string "You have started the elite four. You\n"
	.string "cannot leave.$"

RDBM_CheckWaystone_Text_1:
	.string "Finish your Training Center session.$"

RDBM_CheckWaystone_Text_2:
	.string "Finish working with Blaise in Granite\n"
	.string "Cave$"

RDBM_CheckWaystone_Text_3:
	.string "Finish clearing Aqua out of the hideout\n"
	.string "with Courtney.$"

RDBM_CheckWaystone_Text_4:
	.string "Finish clearing out magma in the Space\n"
	.string "Center.$"

RDBM_CheckWaystone_Text_5:
	.string "Finish Escorting the Hexer to the top\n"
	.string "floor of Mt. Pyre.$"

RDBM_CheckWaystone_Text_6:
	.string "Finish robbing the Oldale Mart.$"

RDBM_CheckWaystone_Text_7:
	.string "Finish talking with the Devon Workers.$"

RDBM_CheckWaystone_Text_8:
	.string "Face off with Groudon.$"

RDBM_CheckWaystone_Text_9:
	.string "Finish your Trainer Hill challenge.$"

RDBM_CheckWaystone_Text_10:
	.string "You should be escorting the Nurse.$"

RDBM_CheckWaystone_Text_11:
	.string "You can't leave limbo, you lost your\n"
	.string "challenge.$"

RDBM_TeleportHome_Text_0:
	.string "You cannot teleport from Limbo.$"

WaystoneEnabled::
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Waystone should be Available.$"

WaystoneDisabled::
	.string "{COLOR LIGHT_RED}{SHADOW RED}Waystone should be disabled.$"

BetaMenuIntro::
	.string "You really shouldn't mess with these\noptions unless you were directed\pto do so. Save file damage can occur.\p"
	.string "{COLOR LIGHT_RED}{SHADOW TRANSPARENT}YOU HAVE BEEN WARNED!!$"

RDBM_ShowSaveFileOriginalVersion::
	.string "The save file was created on\nversion number {STR_VAR_1}.$"

RDBM_DisplayQuestVarsMsg::
	.string "Magma: {STR_VAR_1}, DevonM: {STR_VAR_2}, DevonS: {STR_VAR_3}\n"
	.string "Lana: {RYU_STR_1}, Lanette: {RYU_STR_2} Aqua: {RYU_STR_3}\l"
	.string "Nurse: {RYU_STR_4}$"

RDBM_ResetTempFlagsMsg::
	.string "{COLOR LIGHT_RED}{SHADOW RED} (Temporary battle flags have been\n reset)$"

RDBM_Unimplemented::
	.string "This option does nothing. It's\na placeholder for future options.$"

RDBM_BadgesReset::
	.string "All badges have been removed.$"

RDBM_GCMSReset::
	.string "Gcms has been reset.$"

RGBM_TPHOME::
	.string "Teleporting {PLAYER} home...$"

RDBM_Exiting::
	.string "Exiting menu without change...$"
