CableClub_OnTransition: @ 8276ACF
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CableClub_EventScript_HideOrShowMysteryGiftMan:: @ 8276AD5
	goto_if_set FLAG_SYS_GAME_CLEAR, CableClub_EventScript_ShowMysteryGiftMan
	goto_if_unset FLAG_SYS_GAME_CLEAR, CableClub_EventScript_HideMysteryGiftMan
	end

CableClub_EventScript_ShowMysteryGiftMan:: @ 8276AFB
	clearflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_HideMysteryGiftMan:: @ 8276AFF
	setflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_MysteryGiftMan:: @ 8276B03
	specialvar VAR_RESULT, ShouldDistributeEonTicket
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_DistributeEonTicket
	goto CableClub_EventScript_AlreadyGotEonTicket
	end

CableClub_EventScript_AlreadyGotEonTicket:: @ 8276B19
	gotoram

@ Unused?
CableClub_EventScript_MysteryGiftThankYou:: @ 8276B1A
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_EventScript_DistributeEonTicket:: @ 8276B23
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_AlreadyGotEonTicket
	goto_if_set FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, CableClub_EventScript_AlreadyGotEonTicket
	msgbox Mevent_Text_TheresATicketForYou, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	msgbox Mevent_Text_TryUsingItAtLilycovePort, MSGBOX_DEFAULT
	release
	end

@ Unused?
CableClub_EventScript_MysteryGiftThankYou2:: @ 8276B62
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_DEFAULT
	release
	end

CableClub_OnWarp: @ 8276B6C
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

CableClub_EventScript_CheckTurnAttendant:: @ 8276BAE
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_DontTurnAttendant
	turnobject VAR_0x8007, DIR_WEST
CableClub_EventScript_DontTurnAttendant:: @ 8276BBD
	end

CableClub_OnLoad: @ 8276BBE
	compare VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
	compare VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
	compare VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
	compare VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER
	goto_if_eq CableClub_EventScript_OnLoadFromTradeCenter
	compare VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER
	goto_if_eq CableClub_EventScript_OnLoadFromRecordCorner
	compare VAR_CABLE_CLUB_STATE, USING_UNION_ROOM
	goto_if_eq CableClub_EventScript_OnLoadFromUnionRoom
	compare VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH
	goto_if_eq CableClub_EventScript_OnLoadFromBerryCrush
	compare VAR_CABLE_CLUB_STATE, USING_MINIGAME
	goto_if_eq CableClub_EventScript_OnLoadFromGameCorner
	end

CableClub_EventScript_OnLoadFromColosseum:: @ 8276C17
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromTradeCenter:: @ 8276C1D
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromRecordCorner:: @ 8276C23
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromUnionRoom:: @ 8276C29
	call CableClub_EventScript_OpenUnionRoomBarrier
	end

CableClub_EventScript_OnLoadFromBerryCrush:: @ 8276C2F
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromGameCorner:: @ 8276C35
	call EventScript_OpenMossdeepGameCornerBarrier
	end

CableClub_OnFrame: @ 8276C3B
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_ExitRecordCorner
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

CableClub_EventScript_ExitLinkRoom:: @ 8276C85
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom:: @ 8276C9D
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call EventScript_CloseMossdeepGameCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom:: @ 8276CB5
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter:: @ 8276CE7
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter:: @ 8276CFF
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_ExitRecordCorner:: @ 8276D2C
	lockall
	call CableClub_EventScript_PlayerExitRecordCorner
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	releaseall
	end

CableClub_EventScript_PlayerExitRecordCorner:: @ 8276D44
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_ExitRecordCornerRet
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
CableClub_EventScript_ExitRecordCornerRet:: @ 8276D6B
	return

CableClub_EventScript_ExitUnionRoom:: @ 8276D6C
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom
	call CableClub_EventScript_CloseUnionRoomBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom:: @ 8276D84
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_TrainerCardDataOverwritten:: @ 8276DAE
	message CableClub_Text_TrainerCardDataOverwritten
	waitmessage
	playse SE_PIN
	delay 60
	message CableClub_Text_HopeToSeeYouAgain
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom:: @ 8276DD5
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial:: @ 8276DE0
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CableClub_Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime, MSGBOX_DEFAULT
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	releaseall
	end

CableClub_Movement_PlayerApproachCounter: @ 8276E10
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub:: @ 8276E13
	message CableClub_Text_WelcomeWhichCableClubService
	waitmessage
	delay 28
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_UnusedWelcomeToCableClub:: @ 8276E22
	msgbox CableClub_Text_WhichService, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_SelectCableClubRoom:: @ 8276E30
	setvar VAR_0x8004, 0
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_CableClubUnlockedRecordCorner
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_CableClubUnlockedRecordCorner:: @ 8276E75
	multichoice 0, 0, MULTI_CABLE_CLUB_WITH_RECORD_MIX, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_RecordCorner
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_Colosseum:: @ 8276EB7
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SelectBattleMode:: @ 8276EC2
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode
	case 1, CableClub_EventScript_DoubleBattleMode
	case 2, CableClub_EventScript_MultiBattleMode
	case 3, CableClub_EventScript_BattleModeInfo
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_BattleModeInfo:: @ 8276F15
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SingleBattleMode:: @ 8276F23
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_DoubleBattleMode:: @ 8276F2E
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne CableClub_EventScript_NeedTwoMonsForDoubleBattle
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle:: @ 8276F47
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_MultiBattleMode:: @ 8276F55
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_TryEnterColosseum:: @ 8276F60
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	waitstate
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterColosseum
	compare VAR_RESULT, LINKUP_SOMEONE_NOT_READY
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_AbortLink
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterColosseum:: @ 8276FBD
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	compare VAR_0x8004, USING_MULTI_BATTLE
	goto_if_eq CableClub_EventScript_WarpTo4PColosseum
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P, 255, 6, 8
	special DoCableClubWarp
	waitstate
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight:: @ 827702B
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum:: @ 8277036
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P, 255, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers:: @ 8277046
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle
	case USING_MULTI_BATTLE,  CableClub_EventScript_AbortLinkNeedFourPlayers
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	end

CableClub_EventScript_AbortLinkNeedFourPlayers:: @ 8277072
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle:: @ 8277083
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle:: @ 8277094
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_ConfirmNumberAndRestart:: @ 82770A5
	special CloseLink  @ Redundant
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_TradeCenter:: @ 82770B2
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterTradeCenter
	compare VAR_RESULT, LINKUP_SOMEONE_NOT_READY
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_AbortLink
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
	compare VAR_RESULT, LINKUP_PLAYER_NOT_READY
	goto_if_eq CableClub_EventScript_AbortLinkPlayerNotReady
	compare VAR_RESULT, LINKUP_PARTNER_NOT_READY
	goto_if_eq CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

CableClub_EventScript_EnterTradeCenter:: @ 827713A
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER, 255, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_CheckPartyTradeRequirements:: @ 8277199
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, 2
	goto_if_lt CableClub_EventScript_NeedTwoMonsToTrade
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_CantTradeEnigmaBerry
	setvar VAR_RESULT, 1
	return

CableClub_EventScript_NeedTwoMonsToTrade:: @ 82771BF
	msgbox CableClub_Text_NeedTwoMonsToTrade, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

CableClub_EventScript_CantTradeEnigmaBerry:: @ 82771CD
	msgbox CableClub_Text_CantTradeEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

CableClub_EventScript_RecordCorner:: @ 82771DB
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryRecordMixLinkup
	waitstate
	special ValidateMixingGameLanguage
	waitstate
	compare VAR_RESULT, LINKUP_FOREIGN_GAME
	goto_if_eq CableClub_EventScript_AbortLinkForeignGame
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterRecordCorner
	compare VAR_RESULT, LINKUP_SOMEONE_NOT_READY
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_AbortLink
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterRecordCorner:: @ 827724C
	setvar VAR_0x8004, USING_RECORD_CORNER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_RECORD_CORNER, 255, 8, 9
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkPlayerNotReady:: @ 82772AB
	special CloseLink
	msgbox CableClub_Text_NotSetUpForFarAwayRegion, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady:: @ 82772B8
	special CloseLink
	msgbox CableClub_Text_OtherTrainerNotReady, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkConnectionError:: @ 82772C5
	special CloseLink
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady:: @ 82772D2
	special CloseLink
	msgbox Text_SomeoneIsNotReadyToLink, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections:: @ 82772DF
	special CloseLink
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLink:: @ 82772EC
	special CloseLink
	msgbox CableClub_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_AbortMinigame:: @ 82772F9
	special CloseLink
	msgbox MossdeepCity_GameCorner_1F_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp:: @ 8277306
	special SetCableClubWarp
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants:: @ 827730E
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg:: @ 827731B
	special CloseLink
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkForeignGame:: @ 8277328
	special CloseLink
	msgbox CableClub_Text_CantMixWithJapaneseGame, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_WirelessClubAdjustements:: @ 8277335
	msgbox gText_SorryWirelessClubAdjustments, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_NotReadyYet:: @ 827733F
	msgbox gText_UndergoingAdjustments, MSGBOX_DEFAULT
	releaseall
	end

Movement_AttendantFaceDown: @ 8277349
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight: @ 827734B
	face_right
	step_end

Movement_AttendantFaceLeft: @ 827734D
	face_left
	step_end

Movement_PlayerExitLinkRoom: @ 827734F
	walk_down
	walk_down
	step_end

@ Functionally unused
Movement_PlayerApproachLinkRoomRight: @ 8277352
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft: @ 8277356
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom: @ 827735A
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft: @ 827735C
	face_left
	step_end

Movement_PlayerFaceAttendantRight: @ 827735E
	face_right
	step_end

Movement_PlayerEnterMinigameRoom: @ 8277360
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

EventScript_CableBoxResults:: @ 8277365
	lockall
	setvar VAR_0x8004, 0
	special ShowLinkBattleRecords
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

EventScript_BattleColosseum_2P_PlayerSpot0:: @ 8277374
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_2P_PlayerSpot1:: @ 827737E
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot0:: @ 8277388
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot1:: @ 82773A3
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot2:: @ 82773BE
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 2
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot3:: @ 82773D9
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 3
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_CancelSpotTrigger:: @ 82773F4
	end

EventScript_TradeCenter_Chair0:: @ 82773F5
	setvar VAR_0x8005, 0
	special PlayerEnteredTradeSeat
	waitstate
	end

EventScript_TradeCenter_Chair1:: @ 82773FF
	setvar VAR_0x8005, 1
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair2:: @ 8277409
	setvar VAR_0x8005, 2
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair3:: @ 8277413
	setvar VAR_0x8005, 3
	special PlayerEnteredTradeSeat
	waitstate
	end

@ VAR_TEMP_1 for below scripts set by ReceiveGiftItem
EventScript_RecordCenter_Spot0:: @ 827741D
	setvar VAR_0x8005, 0
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, ITEM_NONE
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot1:: @ 8277432
	setvar VAR_0x8005, 1
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, ITEM_NONE
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot2:: @ 8277447
	setvar VAR_0x8005, 2
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, ITEM_NONE
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot3:: @ 827745C
	setvar VAR_0x8005, 3
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, ITEM_NONE
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
	end

RecordCorner_EventScript_ReceivedGiftItem:: @ 8277471
	bufferitemname 1, VAR_TEMP_1
	message RecordCorner_Text_PlayerSentOverOneX
	waitmessage
	waitbuttonpress
	releaseall
	end

CableClub_EventScript_ReadTrainerCard:: @ 827747E
	msgbox CableClub_Text_GotToLookAtTrainerCard, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_ReadTrainerCardColored:: @ 827748D
	msgbox CableClub_Text_GotToLookAtColoredTrainerCard, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_TooBusyToNotice:: @ 827749C
	msgbox CableClub_Text_TooBusyToNotice, MSGBOX_DEFAULT
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant:: @ 82774A6
	special Script_FacePlayer
	msgbox BattleColosseum_2P_Text_TakePlaceStartBattle, MSGBOX_DEFAULT
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant:: @ 82774B6
	special Script_FacePlayer
	msgbox TradeCenter_Text_TakeSeatStartTrade, MSGBOX_DEFAULT
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_Attendant:: @ 82774C6
	compare VAR_TEMP_0, 0
	goto_if_ne RecordCorner_EventScript_AlreadyMixed
	special Script_FacePlayer
	message RecordCorner_Text_TakeSeatAndWait
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_AlreadyMixed:: @ 82774E0
	special Script_FacePlayer
	message RecordCorner_Text_ThanksForComing
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

EventScript_ConfirmLeaveTradeRoom:: @ 82774EF
	msgbox Text_TerminateLinkConfirmation, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_TerminateLink
	releaseall
	end

EventScript_TerminateLink:: @ 8277509
	messageautoscroll Text_TerminateLinkPleaseWait
	waitmessage
	special ExitLinkRoom
	end

EventScript_DoLinkRoomExit:: @ 8277513
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	waitstate
	end

CableClub_EventScript_UnionRoomAttendant:: @ 827751B
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FACILITY_UNION_ROOM
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_UnionRoomAdapterNotConnected
	message CableClub_Text_WelcomeUnionRoomEnter
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_UnionRoomSelect:: @ 827755C
	multichoice 17, 6, MULTI_YESNOINFO, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom
	case 1, CableClub_EventScript_AbortLink
	case 2, CableClub_EventScript_UnionRoomInfo
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_UnionRoomInfo:: @ 8277593
	message CableClub_Text_UnionRoomInfo
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_EnterUnionRoom:: @ 827759F
	call CableClub_EventScript_CheckPartyUnionRoomRequirements
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	msgbox CableClub_Text_EnjoyUnionRoom, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call CableClub_EventScript_OpenUnionRoomBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpteleport2 MAP_UNION_ROOM, 255, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements:: @ 8277626
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, 2
	goto_if_lt CableClub_EventScript_NeedTwoMonsForUnionRoom
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_NoEnigmaBerryInUnionRoom
	setvar VAR_RESULT, 1
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom:: @ 827764C
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom:: @ 827765A
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_UnionRoomAdapterNotConnected:: @ 8277668
	msgbox CableClub_Text_UnionRoomAdapterNotConnected, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_WirelessClubAttendant:: @ 8277672
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	msgbox CableClub_Text_AskAboutLinking, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CableClub_EventScript_DontAskAboutLinking
	msgbox CableClub_Text_ExplainWirelessClub, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_DontAskAboutLinking:: @ 827769A
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_DirectCornerAttendant:: @ 82776A4
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER  @ Set preemptively for multi battles, ignored otherwise
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_WelcomeToCableClub
	message CableClub_Text_WelcomeWhichDirectCornerRoom
	waitmessage
	delay 28
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_DirectCornerSelectService:: @ 82776E3
	checkitem ITEM_POWDER_JAR, 1
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_DirectCornerNoBerry
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerSelectAllServices
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessBerryCrush
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerSelectAllServices:: @ 827773E
	multichoice 0, 0, MULTI_WIRELESS_ALL_SERVICES, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessRecordMix
	case 3, CableClub_EventScript_WirelessBerryCrush
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerNoBerry:: @ 827778B
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerHasRecordMix
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerHasRecordMix:: @ 82777CB
	multichoice 0, 0, MULTI_WIRELESS_NO_BERRY, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessRecordMix
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessTrade:: @ 827780D
	msgbox CableClub_Text_TradePokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CableClub_EventScript_AbortLink
	call CableClub_EventScript_CheckPartyTradeRequirements
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	setvar VAR_0x8004, LINK_GROUP_TRADE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleSelect:: @ 827783B
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle
	case 1, CableClub_EventScript_WirelessDoubleBattle
	case 2, CableClub_EventScript_WirelessMultiBattle
	case 3, CableClub_EventScript_WirelessBattleInfo
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessSingleBattle:: @ 827788E
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessDoubleBattle:: @ 8277899
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle:: @ 82778B2
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessMultiBattle:: @ 82778C0
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleInfo:: @ 82778CB
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessRecordMix:: @ 82778D9
	msgbox CableClub_Text_AccessRecordCorner, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CableClub_EventScript_AbortLink
	setvar VAR_0x8004, LINK_GROUP_RECORD_CORNER
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBerryCrush:: @ 82778F7
	msgbox CableClub_Text_UseBerryCrush, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CableClub_EventScript_AbortLink
	special HasAtLeastOneBerry
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_NeedBerryForBerryCrush
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_NeedBerryForBerryCrush:: @ 8277923
	msgbox CableClub_Text_NeedBerryForBerryCrush, MSGBOX_DEFAULT
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_SaveAndChooseLinkLeader:: @ 8277931
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	switch VAR_0x8004
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader
	case LINK_GROUP_RECORD_CORNER, CableClub_EventScript_ChooseLinkLeader
	end

CableClub_EventScript_ChooseLinkLeaderFrom2:: @ 8277989
	message CableClub_Text_ChooseGroupLeaderOfTwo
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players
	case 1, CableClub_EventScript_TryLeadGroup2Players
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup2Players:: @ 82779C6
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom2
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq CableClub_EventScript_TryLeadGroup2Players
	release
	return

CableClub_EventScript_TryJoinGroup2Players:: @ 82779EE
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom2
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq CableClub_EventScript_TryJoinGroup2Players
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4:: @ 8277A16
	message CableClub_Text_ChooseGroupLeaderOfFour
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players
	case 1, CableClub_EventScript_TryLeadGroup4Players
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup4Players:: @ 8277A53
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom4
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq CableClub_EventScript_TryLeadGroup4Players
	release
	return

CableClub_EventScript_TryJoinGroup4Players:: @ 8277A7B
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom4
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq CableClub_EventScript_TryJoinGroup4Players
	release
	return

CableClub_EventScript_ChooseLinkLeader:: @ 8277AA3
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers
	case 1, CableClub_EventScript_TryLeadGroupXPlayers
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroupXPlayers:: @ 8277AE0
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_ChooseLinkLeader
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq CableClub_EventScript_TryLeadGroupXPlayers
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers:: @ 8277B08
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq CableClub_EventScript_ChooseLinkLeader
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq CableClub_EventScript_TryJoinGroupXPlayers
	release
	return

CableClub_EventScript_TryBecomeLinkLeader:: @ 8277B30
	special TryBecomeLinkLeader
	waitstate
	return

CableClub_EventScript_TryJoinLinkGroup:: @ 8277B35
	special TryJoinLinkGroup
	waitstate
	return

CableClub_EventScript_EnterWirelessLinkRoom:: @ 8277B3A
	messageautoscroll CableClub_Text_DirectYouToYourRoom
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

EventScript_WirelessBoxResults:: @ 8277B8A
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_AdapterNotConnected
	fadescreen FADE_TO_BLACK
	special ShowWirelessCommunicationScreen
	waitstate
	msgbox CableClub_Text_ParticipantsStepUpToCounter, MSGBOX_DEFAULT
	releaseall
	end

CableClub_EventScript_AdapterNotConnected:: @ 8277BB4
	msgbox CableClub_Text_AdapterNotConnected, MSGBOX_DEFAULT
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier:: @ 8277BBE
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
	setmetatile 5, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
	return

CableClub_EventScript_CloseUnionRoomBarrier:: @ 8277BD1
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
	setmetatile 5, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

CableClub_EventScript_OpenDirectCornerBarrier:: @ 8277BE4
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
	setmetatile 9, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
	return

CableClub_EventScript_CloseDirectCornerBarrier:: @ 8277BF7
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
	setmetatile 9, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

EventScript_OpenMossdeepGameCornerBarrier:: @ 8277C0A
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterOpen_Top, 0
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterOpen_Bottom, 0
	return

EventScript_CloseMossdeepGameCornerBarrier:: @ 8277C1D
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterClosed_Top, 1
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterClosed_Bottom, 1
	return

CableClub_OnResume: @ 8277C30
	@special InitUnionRoom
	end

MossdeepCity_GameCorner_1F_EventScript_InfoMan2:: @ 8277C34
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_DescribeWhichGame
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo
	case 1, MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo
	case 2, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
	end

MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo:: @ 8277C73
	msgbox MossdeepCity_GameCorner_1F_Text_PokemonJumpInfo, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo:: @ 8277C7D
	msgbox MossdeepCity_GameCorner_1F_Text_DodrioBerryPickingInfo, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit:: @ 8277C87
	msgbox MossdeepCity_GameCorner_1F_Text_TalkToOldManToPlay, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_OldMan2:: @ 8277C91
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_WelcomeCanYouWait
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected
	delay 60
	message MossdeepCity_GameCorner_1F_Text_PlayWhichGame
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump
	case 1, MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump:: @ 8277CE9
	setvar VAR_0x8005, 0
	special IsPokemonJumpSpeciesInParty
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	end

MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking:: @ 8277D35
	setvar VAR_0x8005, 1
	special IsDodrioInParty
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	end

MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader:: @ 8277D81
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
	case 1, MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader:: @ 8277DBE
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
	release
	return

MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup:: @ 8277DE6
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
	release
	return

MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom:: @ 8277E0E
	messageautoscroll MossdeepCity_GameCorner_1F_Text_AllGoodToGo
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call EventScript_OpenMossdeepGameCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	release
	waitstate
	end

MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected:: @ 8277E48
	delay 60
	msgbox MossdeepCity_GameCorner_1F_Text_AdapterNotConnected, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon:: @ 8277E55
	msgbox MossdeepCity_GameCorner_1F_Text_ExplainRequiredMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	compare VAR_0x8005, 0
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements
	compare VAR_0x8005, 1
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements
	goto MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements:: @ 8277E84
	msgbox MossdeepCity_GameCorner_1F_Text_ShortJumpingPokemonAllowed, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements:: @ 8277E8D
	msgbox MossdeepCity_GameCorner_1F_Text_OnlyDodrioAllowed, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_PokemonJumpRecords:: @ 8277E96
	lockall
	special ShowPokemonJumpRecords
	waitstate
	releaseall
	end

MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingRecords:: @ 8277E9D
	lockall
	special ShowDodrioBerryPickingRecords
	waitstate
	releaseall
	end

CableClub_TrainerResetter::
	lock
	faceplayer
	msgbox CableClub_TrainerResetter_WantToResetTrainers, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq CableClub_TrainerResetter_ResetTrainers
	compare VAR_RESULT, NO
	goto_if_eq CableClub_TrainerResetter_DontResetTrainers
	end

CableClub_TrainerResetter_ResetTrainers::
	cleartrainerflag TRAINER_SAWYER_1
	cleartrainerflag TRAINER_GABRIELLE_1
	cleartrainerflag TRAINER_MARCEL
	cleartrainerflag TRAINER_ALBERTO
	cleartrainerflag TRAINER_ED
	cleartrainerflag TRAINER_DECLAN
	cleartrainerflag TRAINER_FREDRICK
	cleartrainerflag TRAINER_MATT
	cleartrainerflag TRAINER_ZANDER
	cleartrainerflag TRAINER_LEAH
	cleartrainerflag TRAINER_DAISY
	cleartrainerflag TRAINER_ROSE_1
	cleartrainerflag TRAINER_FELIX
	cleartrainerflag TRAINER_VIOLET
	cleartrainerflag TRAINER_MORRIS
	cleartrainerflag TRAINER_BRINEY
	cleartrainerflag TRAINER_EMPTY_2
	cleartrainerflag TRAINER_EMPTY_3
	cleartrainerflag TRAINER_DUSTY_1
	cleartrainerflag TRAINER_CHIP
	cleartrainerflag TRAINER_FOSTER
	cleartrainerflag TRAINER_EMPTY_8
	cleartrainerflag TRAINER_EMPTY_9
	cleartrainerflag TRAINER_EMPTY_10
	cleartrainerflag TRAINER_EMPTY_11
	cleartrainerflag TRAINER_LOLA_1
	cleartrainerflag TRAINER_AUSTINA
	cleartrainerflag TRAINER_GWEN
	cleartrainerflag TRAINER_EMPTY_12
	cleartrainerflag TRAINER_EMPTY_13
	cleartrainerflag TRAINER_EMPTY_14
	cleartrainerflag TRAINER_EMPTY_15
	cleartrainerflag TRAINER_RICKY_1
	cleartrainerflag TRAINER_SIMON
	cleartrainerflag TRAINER_CHARLIE
	cleartrainerflag TRAINER_EMPTY_16
	cleartrainerflag TRAINER_EMPTY_17
	cleartrainerflag TRAINER_EMPTY_18
	cleartrainerflag TRAINER_EMPTY_19
	cleartrainerflag TRAINER_RANDALL
	cleartrainerflag TRAINER_PARKER
	cleartrainerflag TRAINER_GEORGE
	cleartrainerflag TRAINER_BERKE
	cleartrainerflag TRAINER_BRAXTON
	cleartrainerflag TRAINER_VINCENT
	cleartrainerflag TRAINER_LEROY
	cleartrainerflag TRAINER_WILTON_1
	cleartrainerflag TRAINER_EDGAR
	cleartrainerflag TRAINER_ALBERT
	cleartrainerflag TRAINER_SAMUEL
	cleartrainerflag TRAINER_VITO
	cleartrainerflag TRAINER_OWEN
	cleartrainerflag TRAINER_EMPTY_29
	cleartrainerflag TRAINER_EMPTY_30
	cleartrainerflag TRAINER_EMPTY_31
	cleartrainerflag TRAINER_EMPTY_32
	cleartrainerflag TRAINER_WARREN
	cleartrainerflag TRAINER_MARY
	cleartrainerflag TRAINER_ALEXIA
	cleartrainerflag TRAINER_JODY
	cleartrainerflag TRAINER_WENDY
	cleartrainerflag TRAINER_KEIRA
	cleartrainerflag TRAINER_BROOKE_1
	cleartrainerflag TRAINER_JENNIFER
	cleartrainerflag TRAINER_HOPE
	cleartrainerflag TRAINER_SHANNON
	cleartrainerflag TRAINER_MICHELLE
	cleartrainerflag TRAINER_CAROLINE
	cleartrainerflag TRAINER_JULIE
	cleartrainerflag TRAINER_EMPTY_28
	cleartrainerflag TRAINER_BROOKE_3
	cleartrainerflag TRAINER_BROOKE_4
	cleartrainerflag TRAINER_BROOKE_5
	cleartrainerflag TRAINER_PATRICIA
	cleartrainerflag TRAINER_KINDRA
	cleartrainerflag TRAINER_TAMMY
	cleartrainerflag TRAINER_VALERIE_1
	cleartrainerflag TRAINER_TASHA
	cleartrainerflag TRAINER_EMPTY_33
	cleartrainerflag TRAINER_EMPTY_34
	cleartrainerflag TRAINER_EMPTY_35
	cleartrainerflag TRAINER_EMPTY_36
	cleartrainerflag TRAINER_CINDY_1
	cleartrainerflag TRAINER_DAPHNE
	cleartrainerflag TRAINER_CINDY_2
	cleartrainerflag TRAINER_BRIANNA
	cleartrainerflag TRAINER_NAOMI
	cleartrainerflag TRAINER_EMPTY_37
	cleartrainerflag TRAINER_EMPTY_38
	cleartrainerflag TRAINER_CINDY_5
	cleartrainerflag TRAINER_CINDY_6
	cleartrainerflag TRAINER_MELISSA
	cleartrainerflag TRAINER_SHEILA
	cleartrainerflag TRAINER_SHIRLEY
	cleartrainerflag TRAINER_JESSICA_1
	cleartrainerflag TRAINER_CONNIE
	cleartrainerflag TRAINER_BRIDGET
	cleartrainerflag TRAINER_OLIVIA
	cleartrainerflag TRAINER_TIFFANY
	cleartrainerflag TRAINER_EMPTY_41
	cleartrainerflag TRAINER_EMPTY_42
	cleartrainerflag TRAINER_EMPTY_43
	cleartrainerflag TRAINER_EMPTY_44
	cleartrainerflag TRAINER_WINSTON_1
	cleartrainerflag TRAINER_MOLLIE
	cleartrainerflag TRAINER_GARRET
	cleartrainerflag TRAINER_EMPTY_45
	cleartrainerflag TRAINER_EMPTY_46
	cleartrainerflag TRAINER_EMPTY_47
	cleartrainerflag TRAINER_EMPTY_48
	cleartrainerflag TRAINER_STEVE_1
	cleartrainerflag TRAINER_THALIA_1
	cleartrainerflag TRAINER_MARK
	cleartrainerflag TRAINER_EMPTY_49
	cleartrainerflag TRAINER_EMPTY_50
	cleartrainerflag TRAINER_EMPTY_51
	cleartrainerflag TRAINER_EMPTY_52
	cleartrainerflag TRAINER_LUIS
	cleartrainerflag TRAINER_DOMINIK
	cleartrainerflag TRAINER_DOUGLAS
	cleartrainerflag TRAINER_DARRIN
	cleartrainerflag TRAINER_TONY_1
	cleartrainerflag TRAINER_JEROME
	cleartrainerflag TRAINER_MATTHEW
	cleartrainerflag TRAINER_DAVID
	cleartrainerflag TRAINER_SPENCER
	cleartrainerflag TRAINER_ROLAND
	cleartrainerflag TRAINER_NOLEN
	cleartrainerflag TRAINER_STAN
	cleartrainerflag TRAINER_BARRY
	cleartrainerflag TRAINER_DEAN
	cleartrainerflag TRAINER_RODNEY
	cleartrainerflag TRAINER_RICHARD
	cleartrainerflag TRAINER_HERMAN
	cleartrainerflag TRAINER_SANTIAGO
	cleartrainerflag TRAINER_GILBERT
	cleartrainerflag TRAINER_FRANKLIN
	cleartrainerflag TRAINER_KEVIN
	cleartrainerflag TRAINER_JACK
	cleartrainerflag TRAINER_DUDLEY
	cleartrainerflag TRAINER_CHAD
	cleartrainerflag TRAINER_EMPTY_53
	cleartrainerflag TRAINER_EMPTY_54
	cleartrainerflag TRAINER_EMPTY_55
	cleartrainerflag TRAINER_EMPTY_56
	cleartrainerflag TRAINER_TAKAO
	cleartrainerflag TRAINER_HITOSHI
	cleartrainerflag TRAINER_KIYO
	cleartrainerflag TRAINER_KOICHI
	cleartrainerflag TRAINER_NOB_1
	cleartrainerflag TRAINER_EMPTY_57
	cleartrainerflag TRAINER_EMPTY_58
	cleartrainerflag TRAINER_EMPTY_59
	cleartrainerflag TRAINER_EMPTY_60
	cleartrainerflag TRAINER_YUJI
	cleartrainerflag TRAINER_DAISUKE
	cleartrainerflag TRAINER_ATSUSHI
	cleartrainerflag TRAINER_KIRK
	cleartrainerflag TRAINER_SHAWN
	cleartrainerflag TRAINER_FERNANDO_1
	cleartrainerflag TRAINER_DALTON_1
	cleartrainerflag TRAINER_EMPTY_69
	cleartrainerflag TRAINER_DALTON_3
	cleartrainerflag TRAINER_DALTON_4
	cleartrainerflag TRAINER_DALTON_5
	cleartrainerflag TRAINER_COLE
	cleartrainerflag TRAINER_JEFF
	cleartrainerflag TRAINER_AXLE
	cleartrainerflag TRAINER_JACE
	cleartrainerflag TRAINER_KEEGAN
	cleartrainerflag TRAINER_BERNIE_1
	cleartrainerflag TRAINER_EMPTY_70
	cleartrainerflag TRAINER_EMPTY_71
	cleartrainerflag TRAINER_EMPTY_72
	cleartrainerflag TRAINER_EMPTY_73
	cleartrainerflag TRAINER_DREW
	cleartrainerflag TRAINER_BEAU
	cleartrainerflag TRAINER_LARRY
	cleartrainerflag TRAINER_SHANE
	cleartrainerflag TRAINER_JUSTIN
	cleartrainerflag TRAINER_ETHAN_1
	cleartrainerflag TRAINER_AUTUMN
	cleartrainerflag TRAINER_TRAVIS
	cleartrainerflag TRAINER_EMPTY_74
	cleartrainerflag TRAINER_EMPTY_75
	cleartrainerflag TRAINER_EMPTY_76
	cleartrainerflag TRAINER_EMPTY_77
	cleartrainerflag TRAINER_BRENT
	cleartrainerflag TRAINER_DONALD
	cleartrainerflag TRAINER_TAYLOR
	cleartrainerflag TRAINER_JEFFREY_1
	cleartrainerflag TRAINER_DEREK
	cleartrainerflag TRAINER_EMPTY_79
	cleartrainerflag TRAINER_JEFFREY_3
	cleartrainerflag TRAINER_JEFFREY_4
	cleartrainerflag TRAINER_JEFFREY_5
	cleartrainerflag TRAINER_EDWARD
	cleartrainerflag TRAINER_PRESTON
	cleartrainerflag TRAINER_VIRGIL
	cleartrainerflag TRAINER_BLAKE
	cleartrainerflag TRAINER_WILLIAM
	cleartrainerflag TRAINER_JOSHUA
	cleartrainerflag TRAINER_CAMERON_1
	cleartrainerflag TRAINER_EMPTY_80
	cleartrainerflag TRAINER_EMPTY_81
	cleartrainerflag TRAINER_EMPTY_82
	cleartrainerflag TRAINER_EMPTY_83
	cleartrainerflag TRAINER_JACLYN
	cleartrainerflag TRAINER_HANNAH
	cleartrainerflag TRAINER_SAMANTHA
	cleartrainerflag TRAINER_MAURA
	cleartrainerflag TRAINER_KAYLA
	cleartrainerflag TRAINER_ALEXIS
	cleartrainerflag TRAINER_JACKI_1
	cleartrainerflag TRAINER_EMPTY_84
	cleartrainerflag TRAINER_EMPTY_85
	cleartrainerflag TRAINER_EMPTY_86
	cleartrainerflag TRAINER_EMPTY_87
	cleartrainerflag TRAINER_WALTER_1
	cleartrainerflag TRAINER_MICAH
	cleartrainerflag TRAINER_THOMAS
	cleartrainerflag TRAINER_EMPTY_88
	cleartrainerflag TRAINER_EMPTY_89
	cleartrainerflag TRAINER_EMPTY_90
	cleartrainerflag TRAINER_EMPTY_91
	cleartrainerflag TRAINER_JERRY_1
	cleartrainerflag TRAINER_TED
	cleartrainerflag TRAINER_PAUL
	cleartrainerflag TRAINER_EMPTY_96
	cleartrainerflag TRAINER_EMPTY_97
	cleartrainerflag TRAINER_EMPTY_98
	cleartrainerflag TRAINER_EMPTY_99
	cleartrainerflag TRAINER_KAREN_1
	cleartrainerflag TRAINER_GEORGIA
	cleartrainerflag TRAINER_EMPTY_92
	cleartrainerflag TRAINER_EMPTY_93
	cleartrainerflag TRAINER_EMPTY_94
	cleartrainerflag TRAINER_EMPTY_95
	cleartrainerflag TRAINER_KATE_AND_JOY
	cleartrainerflag TRAINER_ANNA_AND_MEG_1
	cleartrainerflag TRAINER_EMPTY_100
	cleartrainerflag TRAINER_EMPTY_101
	cleartrainerflag TRAINER_EMPTY_102
	cleartrainerflag TRAINER_EMPTY_103
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_MIGUEL_1
	cleartrainerflag TRAINER_COLTON
	cleartrainerflag TRAINER_EMPTY_108
	cleartrainerflag TRAINER_EMPTY_109
	cleartrainerflag TRAINER_EMPTY_110
	cleartrainerflag TRAINER_EMPTY_111
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VANESSA
	cleartrainerflag TRAINER_BETHANY
	cleartrainerflag TRAINER_ISABEL_1
	cleartrainerflag TRAINER_EMPTY_104
	cleartrainerflag TRAINER_EMPTY_105
	cleartrainerflag TRAINER_EMPTY_106
	cleartrainerflag TRAINER_EMPTY_107
	cleartrainerflag TRAINER_TIMOTHY_1
	cleartrainerflag TRAINER_EMPTY_112
	cleartrainerflag TRAINER_EMPTY_113
	cleartrainerflag TRAINER_EMPTY_114
	cleartrainerflag TRAINER_EMPTY_115
	cleartrainerflag TRAINER_VICKY
	cleartrainerflag TRAINER_SHELBY_1
	cleartrainerflag TRAINER_EMPTY_116
	cleartrainerflag TRAINER_EMPTY_117
	cleartrainerflag TRAINER_EMPTY_118
	cleartrainerflag TRAINER_EMPTY_119
	cleartrainerflag TRAINER_CALVIN_1
	cleartrainerflag TRAINER_BILLY
	cleartrainerflag TRAINER_JOSH
	cleartrainerflag TRAINER_TOMMY
	cleartrainerflag TRAINER_JOEY
	cleartrainerflag TRAINER_BEN
	cleartrainerflag TRAINER_QUINCY
	cleartrainerflag TRAINER_KATELYNN
	cleartrainerflag TRAINER_JAYLEN
	cleartrainerflag TRAINER_DILLON
	cleartrainerflag TRAINER_EMPTY_120
	cleartrainerflag TRAINER_EMPTY_121
	cleartrainerflag TRAINER_EMPTY_122
	cleartrainerflag TRAINER_EMPTY_123
	cleartrainerflag TRAINER_EDDIE
	cleartrainerflag TRAINER_ALLEN
	cleartrainerflag TRAINER_TIMMY
	cleartrainerflag TRAINER_ANDREW
	cleartrainerflag TRAINER_IVAN
	cleartrainerflag TRAINER_CLAUDE
	cleartrainerflag TRAINER_ELLIOT_1
	cleartrainerflag TRAINER_NED
	cleartrainerflag TRAINER_DALE
	cleartrainerflag TRAINER_NOLAN
	cleartrainerflag TRAINER_BARNY
	cleartrainerflag TRAINER_WADE
	cleartrainerflag TRAINER_CARTER
	cleartrainerflag TRAINER_EMPTY_124
	cleartrainerflag TRAINER_ELLIOT_3
	cleartrainerflag TRAINER_ELLIOT_4
	cleartrainerflag TRAINER_ELLIOT_5
	cleartrainerflag TRAINER_RONALD
	cleartrainerflag TRAINER_JACOB
	cleartrainerflag TRAINER_ANTHONY
	cleartrainerflag TRAINER_BENJAMIN_1
	cleartrainerflag TRAINER_EMPTY_145
	cleartrainerflag TRAINER_EMPTY_146
	cleartrainerflag TRAINER_EMPTY_147
	cleartrainerflag TRAINER_EMPTY_148
	cleartrainerflag TRAINER_ABIGAIL_1
	cleartrainerflag TRAINER_JASMINE
	cleartrainerflag TRAINER_EMPTY_133
	cleartrainerflag TRAINER_EMPTY_134
	cleartrainerflag TRAINER_EMPTY_135
	cleartrainerflag TRAINER_EMPTY_136
	cleartrainerflag TRAINER_DYLAN_1
	cleartrainerflag TRAINER_EMPTY_137
	cleartrainerflag TRAINER_EMPTY_138
	cleartrainerflag TRAINER_EMPTY_139
	cleartrainerflag TRAINER_EMPTY_140
	cleartrainerflag TRAINER_MARIA_1
	cleartrainerflag TRAINER_EMPTY_129
	cleartrainerflag TRAINER_EMPTY_130
	cleartrainerflag TRAINER_EMPTY_131
	cleartrainerflag TRAINER_EMPTY_132
	cleartrainerflag TRAINER_CAMDEN
	cleartrainerflag TRAINER_DEMETRIUS
	cleartrainerflag TRAINER_ISAIAH_1
	cleartrainerflag TRAINER_PABLO_1
	cleartrainerflag TRAINER_CHASE
	cleartrainerflag TRAINER_EMPTY_125
	cleartrainerflag TRAINER_EMPTY_126
	cleartrainerflag TRAINER_EMPTY_127
	cleartrainerflag TRAINER_EMPTY_128
	cleartrainerflag TRAINER_ISOBEL
	cleartrainerflag TRAINER_DONNY
	cleartrainerflag TRAINER_TALIA
	cleartrainerflag TRAINER_KATELYN_1
	cleartrainerflag TRAINER_ALLISON
	cleartrainerflag TRAINER_EMPTY_141
	cleartrainerflag TRAINER_EMPTY_142
	cleartrainerflag TRAINER_EMPTY_143
	cleartrainerflag TRAINER_EMPTY_144
	cleartrainerflag TRAINER_NICOLAS_1
	cleartrainerflag TRAINER_EMPTY_153
	cleartrainerflag TRAINER_EMPTY_154
	cleartrainerflag TRAINER_EMPTY_155
	cleartrainerflag TRAINER_EMPTY_156
	cleartrainerflag TRAINER_AARON
	cleartrainerflag TRAINER_PERRY
	cleartrainerflag TRAINER_HUGH
	cleartrainerflag TRAINER_PHIL
	cleartrainerflag TRAINER_JARED
	cleartrainerflag TRAINER_HUMBERTO
	cleartrainerflag TRAINER_PRESLEY
	cleartrainerflag TRAINER_EDWARDO
	cleartrainerflag TRAINER_COLIN
	cleartrainerflag TRAINER_ROBERT_1
	cleartrainerflag TRAINER_BENNY
	cleartrainerflag TRAINER_CHESTER
	cleartrainerflag TRAINER_EMPTY_157
	cleartrainerflag TRAINER_EMPTY_158
	cleartrainerflag TRAINER_EMPTY_159
	cleartrainerflag TRAINER_EMPTY_160
	cleartrainerflag TRAINER_ALEX
	cleartrainerflag TRAINER_BECK
	cleartrainerflag TRAINER_YASU
	cleartrainerflag TRAINER_TAKASHI
	cleartrainerflag TRAINER_DIANNE
	cleartrainerflag TRAINER_JANI
	cleartrainerflag TRAINER_LAO_1
	cleartrainerflag TRAINER_LUNG
	cleartrainerflag TRAINER_EMPTY_161
	cleartrainerflag TRAINER_EMPTY_162
	cleartrainerflag TRAINER_EMPTY_163
	cleartrainerflag TRAINER_EMPTY_164
	cleartrainerflag TRAINER_JOCELYN
	cleartrainerflag TRAINER_LAURA
	cleartrainerflag TRAINER_CYNDY_1
	cleartrainerflag TRAINER_CORA
	cleartrainerflag TRAINER_PAULA
	cleartrainerflag TRAINER_EMPTY_165
	cleartrainerflag TRAINER_EMPTY_166
	cleartrainerflag TRAINER_EMPTY_167
	cleartrainerflag TRAINER_EMPTY_168
	cleartrainerflag TRAINER_MADELINE_1
	cleartrainerflag TRAINER_CLARISSA
	cleartrainerflag TRAINER_ANGELICA
	cleartrainerflag TRAINER_EMPTY_169
	cleartrainerflag TRAINER_EMPTY_170
	cleartrainerflag TRAINER_EMPTY_171
	cleartrainerflag TRAINER_EMPTY_172
	cleartrainerflag TRAINER_BEVERLY
	cleartrainerflag TRAINER_IMANI
	cleartrainerflag TRAINER_KYLA
	cleartrainerflag TRAINER_DENISE
	cleartrainerflag TRAINER_BETH
	cleartrainerflag TRAINER_TARA
	cleartrainerflag TRAINER_MISSY
	cleartrainerflag TRAINER_ALICE
	cleartrainerflag TRAINER_JENNY_1
	cleartrainerflag TRAINER_GRACE
	cleartrainerflag TRAINER_TANYA
	cleartrainerflag TRAINER_SHARON
	cleartrainerflag TRAINER_NIKKI
	cleartrainerflag TRAINER_BRENDA
	cleartrainerflag TRAINER_KATIE
	cleartrainerflag TRAINER_SUSIE
	cleartrainerflag TRAINER_KARA
	cleartrainerflag TRAINER_DANA
	cleartrainerflag TRAINER_SIENNA
	cleartrainerflag TRAINER_DEBRA
	cleartrainerflag TRAINER_LINDA
	cleartrainerflag TRAINER_KAYLEE
	cleartrainerflag TRAINER_LAUREL
	cleartrainerflag TRAINER_CARLEE
	cleartrainerflag TRAINER_EMPTY_173
	cleartrainerflag TRAINER_EMPTY_174
	cleartrainerflag TRAINER_EMPTY_175
	cleartrainerflag TRAINER_EMPTY_176
	cleartrainerflag TRAINER_HEIDI
	cleartrainerflag TRAINER_BECKY
	cleartrainerflag TRAINER_CAROL
	cleartrainerflag TRAINER_NANCY
	cleartrainerflag TRAINER_MARTHA
	cleartrainerflag TRAINER_DIANA_1
	cleartrainerflag TRAINER_CEDRIC
	cleartrainerflag TRAINER_IRENE
	cleartrainerflag TRAINER_EMPTY_177
	cleartrainerflag TRAINER_EMPTY_178
	cleartrainerflag TRAINER_EMPTY_179
	cleartrainerflag TRAINER_EMPTY_180
	cleartrainerflag TRAINER_AMY_AND_LIV_1
	cleartrainerflag TRAINER_EMPTY_181
	cleartrainerflag TRAINER_GINA_AND_MIA_1
	cleartrainerflag TRAINER_MIU_AND_YUKI
	cleartrainerflag TRAINER_AMY_AND_LIV_3
	cleartrainerflag TRAINER_GINA_AND_MIA_2
	cleartrainerflag TRAINER_EMPTY_182
	cleartrainerflag TRAINER_EMPTY_183
	cleartrainerflag TRAINER_EMPTY_184
	cleartrainerflag TRAINER_HUEY
	cleartrainerflag TRAINER_EDMOND
	cleartrainerflag TRAINER_ERNEST_1
	cleartrainerflag TRAINER_DWAYNE
	cleartrainerflag TRAINER_PHILLIP
	cleartrainerflag TRAINER_LEONARD
	cleartrainerflag TRAINER_DUNCAN
	cleartrainerflag TRAINER_EMPTY_185
	cleartrainerflag TRAINER_EMPTY_186
	cleartrainerflag TRAINER_EMPTY_187
	cleartrainerflag TRAINER_EMPTY_188
	cleartrainerflag TRAINER_ELI
	cleartrainerflag TRAINER_ANNIKA
	cleartrainerflag TRAINER_JAZMYN
	cleartrainerflag TRAINER_JONAS
	cleartrainerflag TRAINER_KAYLEY
	cleartrainerflag TRAINER_AURON
	cleartrainerflag TRAINER_KELVIN
	cleartrainerflag TRAINER_MARLEY
	cleartrainerflag TRAINER_REYNA
	cleartrainerflag TRAINER_HUDSON
	cleartrainerflag TRAINER_CONOR
	cleartrainerflag TRAINER_EDWIN_1
	cleartrainerflag TRAINER_HECTOR
	cleartrainerflag TRAINER_EMPTY_193
	cleartrainerflag TRAINER_EMPTY_194
	cleartrainerflag TRAINER_EMPTY_195
	cleartrainerflag TRAINER_EMPTY_196
	cleartrainerflag TRAINER_HAROLD
	cleartrainerflag TRAINER_TIM
	cleartrainerflag TRAINER_JIM
	cleartrainerflag TRAINER_JOYCE
	cleartrainerflag TRAINER_DELTON
	cleartrainerflag TRAINER_MARCUS
	cleartrainerflag TRAINER_NICK
	cleartrainerflag TRAINER_LEMMY
	cleartrainerflag TRAINER_TERRENCE
	cleartrainerflag TRAINER_MASAHIRO
	cleartrainerflag TRAINER_MIA_AND_JAKE
	cleartrainerflag TRAINER_ISAAC_1
	cleartrainerflag TRAINER_DAVIS
	cleartrainerflag TRAINER_MITCHELL
	cleartrainerflag TRAINER_EMPTY_201
	cleartrainerflag TRAINER_EMPTY_202
	cleartrainerflag TRAINER_EMPTY_203
	cleartrainerflag TRAINER_EMPTY_204
	cleartrainerflag TRAINER_LYDIA_1
	cleartrainerflag TRAINER_HALLE
	cleartrainerflag TRAINER_GARRISON
	cleartrainerflag TRAINER_EMPTY_197
	cleartrainerflag TRAINER_EMPTY_198
	cleartrainerflag TRAINER_EMPTY_199
	cleartrainerflag TRAINER_EMPTY_200
	cleartrainerflag TRAINER_JACKSON_1
	cleartrainerflag TRAINER_LORENZO
	cleartrainerflag TRAINER_SEBASTIAN
	cleartrainerflag TRAINER_EMPTY_211
	cleartrainerflag TRAINER_JACKSON_3
	cleartrainerflag TRAINER_JACKSON_4
	cleartrainerflag TRAINER_JACKSON_5
	cleartrainerflag TRAINER_CATHERINE_1
	cleartrainerflag TRAINER_JENNA
	cleartrainerflag TRAINER_SOPHIA
	cleartrainerflag TRAINER_EMPTY_207
	cleartrainerflag TRAINER_EMPTY_208
	cleartrainerflag TRAINER_EMPTY_209
	cleartrainerflag TRAINER_EMPTY_210
	cleartrainerflag TRAINER_JULIO
	cleartrainerflag TRAINER_MARC
	cleartrainerflag TRAINER_BRENDEN
	cleartrainerflag TRAINER_LILITH
	cleartrainerflag TRAINER_CRISTIAN
	cleartrainerflag TRAINER_SYLVIA
	cleartrainerflag TRAINER_LEONARDO
	cleartrainerflag TRAINER_ATHENA
	cleartrainerflag TRAINER_HARRISON
	cleartrainerflag TRAINER_CLARENCE
	cleartrainerflag TRAINER_TERRY
	cleartrainerflag TRAINER_NATE
	cleartrainerflag TRAINER_KATHLEEN
	cleartrainerflag TRAINER_CLIFFORD
	cleartrainerflag TRAINER_NICHOLAS
	cleartrainerflag TRAINER_MACEY
	cleartrainerflag TRAINER_PAXTON
	cleartrainerflag TRAINER_ISABELLA
	cleartrainerflag TRAINER_JONATHAN
	cleartrainerflag TRAINER_TIANA
	cleartrainerflag TRAINER_HALEY_1
	cleartrainerflag TRAINER_JANICE
	cleartrainerflag TRAINER_VIVI
	cleartrainerflag TRAINER_EMPTY_212
	cleartrainerflag TRAINER_HALEY_3
	cleartrainerflag TRAINER_HALEY_4
	cleartrainerflag TRAINER_HALEY_5
	cleartrainerflag TRAINER_SALLY
	cleartrainerflag TRAINER_ROBIN
	cleartrainerflag TRAINER_ANDREA
	cleartrainerflag TRAINER_CRISSY
	cleartrainerflag TRAINER_RICK
	cleartrainerflag TRAINER_LYLE
	cleartrainerflag TRAINER_JOSE
	cleartrainerflag TRAINER_DOUG
	cleartrainerflag TRAINER_GREG
	cleartrainerflag TRAINER_KENT
	cleartrainerflag TRAINER_JAMES_1
	cleartrainerflag TRAINER_JAMES_2
	cleartrainerflag TRAINER_JAMES_3
	cleartrainerflag TRAINER_JAMES_4
	cleartrainerflag TRAINER_EMPTY_213
	cleartrainerflag TRAINER_BRICE
	cleartrainerflag TRAINER_TRENT_1
	cleartrainerflag TRAINER_LENNY
	cleartrainerflag TRAINER_LUCAS_1
	cleartrainerflag TRAINER_ALAN
	cleartrainerflag TRAINER_CLARK
	cleartrainerflag TRAINER_ERIC
	cleartrainerflag TRAINER_LUCAS_2
	cleartrainerflag TRAINER_MIKE_1
	cleartrainerflag TRAINER_MIKE_2
	cleartrainerflag TRAINER_EMPTY_214
	cleartrainerflag TRAINER_EMPTY_215
	cleartrainerflag TRAINER_LORWYN
	cleartrainerflag TRAINER_MR_STONE
	cleartrainerflag TRAINER_DEZ_AND_LUKE
	cleartrainerflag TRAINER_LEA_AND_JED
	cleartrainerflag TRAINER_KIRA_AND_DAN_1
	cleartrainerflag TRAINER_DEVON_ENFORCER_5
	cleartrainerflag TRAINER_DEVON_ENFORCER_4
	cleartrainerflag TRAINER_DEVON_ENFORCER_3
	cleartrainerflag TRAINER_DEVON_ENFORCER_2
	cleartrainerflag TRAINER_JOHANNA
	cleartrainerflag TRAINER_GERALD
	cleartrainerflag TRAINER_VIVIAN
	cleartrainerflag TRAINER_DANIELLE
	cleartrainerflag TRAINER_HIDEO
	cleartrainerflag TRAINER_KEIGO
	cleartrainerflag TRAINER_RILEY
	cleartrainerflag TRAINER_FLINT
	cleartrainerflag TRAINER_ASHLEY
	cleartrainerflag TRAINER_ESKIMO_1
	cleartrainerflag TRAINER_JONAH
	cleartrainerflag TRAINER_HENRY
	cleartrainerflag TRAINER_ROGER
	cleartrainerflag TRAINER_ALEXA
	cleartrainerflag TRAINER_RUBEN
	cleartrainerflag TRAINER_KOJI_1
	cleartrainerflag TRAINER_WAYNE
	cleartrainerflag TRAINER_AIDAN
	cleartrainerflag TRAINER_REED
	cleartrainerflag TRAINER_TISHA
	cleartrainerflag TRAINER_TORI_AND_TIA
	cleartrainerflag TRAINER_KIM_AND_IRIS
	cleartrainerflag TRAINER_TYRA_AND_IVY
	cleartrainerflag TRAINER_MEL_AND_PAUL
	cleartrainerflag TRAINER_JOHN_AND_JAY_1
	cleartrainerflag TRAINER_JOHN_AND_JAY_2
	cleartrainerflag TRAINER_JOHN_AND_JAY_3
	cleartrainerflag TRAINER_JOHN_AND_JAY_4
	cleartrainerflag TRAINER_EMPTY_78
	cleartrainerflag TRAINER_RELI_AND_IAN
	cleartrainerflag TRAINER_LILA_AND_ROY_1
	cleartrainerflag TRAINER_EMPTY_20
	cleartrainerflag TRAINER_EMPTY_21
	cleartrainerflag TRAINER_EMPTY_22
	cleartrainerflag TRAINER_EMPTY_23
	cleartrainerflag TRAINER_LISA_AND_RAY
	cleartrainerflag TRAINER_CHRIS
	cleartrainerflag TRAINER_DAWSON
	cleartrainerflag TRAINER_SARAH
	cleartrainerflag TRAINER_DARIAN
	cleartrainerflag TRAINER_HAILEY
	cleartrainerflag TRAINER_CHANDLER
	cleartrainerflag TRAINER_KALEB
	cleartrainerflag TRAINER_JOSEPH
	cleartrainerflag TRAINER_ALYSSA
	cleartrainerflag TRAINER_MARCOS
	cleartrainerflag TRAINER_RHETT
	cleartrainerflag TRAINER_TYRON
	cleartrainerflag TRAINER_CELINA
	cleartrainerflag TRAINER_BIANCA
	cleartrainerflag TRAINER_HAYDEN
	cleartrainerflag TRAINER_SOPHIE
	cleartrainerflag TRAINER_COBY
	cleartrainerflag TRAINER_LAWRENCE
	cleartrainerflag TRAINER_WYATT
	cleartrainerflag TRAINER_ANGELINA
	cleartrainerflag TRAINER_KAI
	cleartrainerflag TRAINER_CHARLOTTE
	cleartrainerflag TRAINER_DEANDRE
	cleartrainerflag TRAINER_DARCY
	cleartrainerflag TRAINER_MAXIE_3
	cleartrainerflag TRAINER_PETE
	cleartrainerflag TRAINER_ISABELLE
	cleartrainerflag TRAINER_ANDRES_1
	cleartrainerflag TRAINER_JOSUE
	cleartrainerflag TRAINER_CAMRON
	cleartrainerflag TRAINER_CORY_1
	cleartrainerflag TRAINER_CAROLINA
	cleartrainerflag TRAINER_ELIJAH
	cleartrainerflag TRAINER_CELIA
	cleartrainerflag TRAINER_BRYAN
	cleartrainerflag TRAINER_BRANDEN
	cleartrainerflag TRAINER_BRYANT
	cleartrainerflag TRAINER_SHAYLA
	cleartrainerflag TRAINER_KYRA
	cleartrainerflag TRAINER_JAIDEN
	cleartrainerflag TRAINER_ALIX
	cleartrainerflag TRAINER_HELENE
	cleartrainerflag TRAINER_MARLENE
	cleartrainerflag TRAINER_DEVAN
	cleartrainerflag TRAINER_JOHNSON
	cleartrainerflag TRAINER_MELINA
	cleartrainerflag TRAINER_BRANDI
	cleartrainerflag TRAINER_AISHA
	cleartrainerflag TRAINER_MAKAYLA
	cleartrainerflag TRAINER_FABIAN
	cleartrainerflag TRAINER_DAYTON
	cleartrainerflag TRAINER_RACHEL
	cleartrainerflag TRAINER_LEONEL
	cleartrainerflag TRAINER_CALLIE
	cleartrainerflag TRAINER_CALE
	cleartrainerflag TRAINER_MYLES
	cleartrainerflag TRAINER_PAT
	cleartrainerflag TRAINER_CRISTIN_1
	cleartrainerflag TRAINER_ANGELO
	cleartrainerflag TRAINER_DARIUS
	cleartrainerflag TRAINER_BETTY
	cleartrainerflag TRAINER_GRANT
	cleartrainerflag TRAINER_RYUJI
	cleartrainerflag TRAINER_CHARLES
	cleartrainerflag TRAINER_YUNA
	cleartrainerflag TRAINER_JASON
	cleartrainerflag TRAINER_RODETTE
	cleartrainerflag TRAINER_TYRONE
	cleartrainerflag TRAINER_LUNA
	cleartrainerflag TRAINER_MELANIE
	cleartrainerflag TRAINER_NERA
	cleartrainerflag TRAINER_ARNOLD
	cleartrainerflag TRAINER_DEO
	cleartrainerflag TRAINER_MALCOLM
	cleartrainerflag TRAINER_MAURICE
	cleartrainerflag TRAINER_MARIELA
	cleartrainerflag TRAINER_ALVARO
	cleartrainerflag TRAINER_EVERETT
	msgbox CableClub_TrainerResetter_Finished MSGBOX_DEFAULT
	release
	end

CableClub_TrainerResetter_DontResetTrainers::
	msgbox CableClub_TrainerResetter_ComeBackIf MSGBOX_DEFAULT
	release
	end

CableClub_TrainerResetter_WantToResetTrainers::
	.string "Would you like to reset all normal\n"
	.string "trainers so you can rematch them?$"

CableClub_TrainerResetter_Finished::
	.string "Done! Come back if you ever\n"
	.string "run out of trainers to fight.$"

CableClub_TrainerResetter_ComeBackIf::
	.string "Alright, come back if you ever\n"
	.string "run out of trainers to fight.$"
