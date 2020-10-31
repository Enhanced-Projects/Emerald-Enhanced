SlateportCity_Harbor_MapScripts:: @ 820C97D
	map_script ON_TRANSITION, SlateportCity_Harbor_OnTransition
	map_script ON_FRAME, SCH_CheckAquaEvent
	.byte 0

SCH_CheckAquaEvent:
	map_script_2 VAR_RYU_AQUA, 102, SCH_AquaEvent
	.2byte 0

SlateportCity_Harbor_OnTransition: @ 820C983
	compare VAR_RYU_AQUA, 100
	goto_if_eq SCH_SetupAquaScene
	setescapewarp MAP_SLATEPORT_CITY, 255, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal:: @ 820C9A5
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SCH_SetupAquaScene::
	setvar VAR_RYU_AQUA, 102
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	addobject 9
	addobject 7
	addobject 8
	end

SCH_CantLeaveYet::
	compare VAR_RYU_AQUA, 102
	goto_if_ne ryu_end
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0:: @ 820CA89
	applymovement 4, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1:: @ 820CA9E
	applymovement 4, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer:: @ 820CAB3
	applymovement 4, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_SternApproachPlayer0: @ 820CAE0
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1: @ 820CAE6
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer: @ 820CAEB
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp: @ 820CAEF
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant:: @ 820CAF1
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket:: @ 820CB06
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination:: @ 820CB1A
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier:: @ 820CB50
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket:: @ 820CB88
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove:: @ 820CB92
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier:: @ 820CBBA
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination:: @ 820CBDD
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry:: @ 820CBE9
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	compare VAR_FACING, DIR_NORTH
	call_if_eq SlateportCity_Harbor_EventScript_BoardFerryNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_PETALBURG_CITY
	setvar VAR_0x8004, 5
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect:: @ 820CC2D
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast:: @ 820CC37
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth:: @ 820CC42
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast: @ 820CC4D
	walk_right
	walk_in_place_fastest_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth: @ 820CC50
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor:: @ 820CC52
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	compare VAR_0x8004, 2  @ Defeated both
	goto_if_eq SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather:: @ 820CC89
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary:: @ 820CC93
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan:: @ 820CC99
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment:: @ 820CD00
	compare VAR_TEMP_1, 1
	goto_if_eq SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished:: @ 820CD2E
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner:: @ 820CD38
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade:: @ 820CD44
	multichoice 0, 0, MULTI_STERN_DEEPSEA, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth:: @ 820CD7B
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER, 1
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale:: @ 820CDBB
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER, 1
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade:: @ 820CDFB
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade:: @ 820CE05
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner:: @ 820CE11
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable: @ 820CE20
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

SlateportCity_Harbor_Text_MayISeeYourTicket: @ 820CE87
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your Ticket?$"

SlateportCity_Harbor_Text_YouMustHaveTicket: @ 820CEC1
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a Ticket to board\n"
	.string "the ferry.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo: @ 820CF1C
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

SlateportCity_Harbor_Text_SailAnotherTime: @ 820CF71
	.string "Please sail with us another time!$"

SlateportCity_Harbor_Text_LilycoveItIs: @ 820CF93
	.string "Lilycove City it is, then!$"

SlateportCity_Harbor_Text_BattleFrontierItIs: @ 820CFAE
	.string "Battle Frontier it is, then!$"

SlateportCity_Harbor_Text_PleaseBoardFerry: @ 820CFCB
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo: @ 820CFFA
	.string "Then, where would you like to go?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday: @ 820D01C
	.string "A journey to the bottom of the sea…\n"
	.string "I wonder what it'd be like?\p"
	.string "I'd love to go deep underwater like\n"
	.string "that someday.$"

SlateportCity_Harbor_Text_AbnormalWeather: @ 820D08E
	.string "For a ship to sail safely, we need to\n"
	.string "know about the weather!\p"
	.string "Speaking of weather, I heard something\n"
	.string "from a guy at the Weather Institute.\p"
	.string "He was saying abnormal weather has\n"
	.string "been reported all over the place!\p"
	.string "You should visit the Weather Institute\n"
	.string "and ask around!$"

SlateportCity_Harbor_Text_SubTooSmallForMe: @ 820D194
	.string "I wanted to go with Capt. Stern on\n"
	.string "the ocean floor exploration.\p"
	.string "But the sub's too small for me.\p"
	.string "If I squeezed in, there wouldn't be\n"
	.string "any room for the Captain…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub: @ 820D58A
	.string "Capt. Stern: Trying to catch a\n"
	.string "submarine… It's impossible.\p"
	.string "You would need a Pokémon that knows\n"
	.string "how to Dive…\p"
	.string "Perhaps if you went out to\n"
	.string "Mossdeep City…\p"
	.string "A lot of divers live out there, so\n"
	.string "someone might teach you…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry: @ 820D65C
	.string "Capt. Stern: Oh, yes.\n"
	.string "MR. Briney came to our Shipyard.\p"
	.string "It won't be long now before we finish\n"
	.string "making the ferry!$"

SlateportCity_Harbor_Text_FinishedMakingFerry: @ 820D6CB
	.string "Capt. Stern: {PLAYER}!\p"
	.string "We finally finished making the ferry\n"
	.string "S.S. Tidal!\p"
	.string "We couldn't have done it without\n"
	.string "your friend MR. Briney.\p"
	.string "Please go for a short cruise on it!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner: @ 820D76C
	.string "Capt. Stern: Oh?\n"
	.string "{PLAYER}, that item you have…\p"
	.string "That's a Scanner! That would sure\n"
	.string "help us on our explorations.\p"
	.string "{PLAYER}, would you trade your\n"
	.string "Scanner for something?\p"
	.string "Like, say, a Deepseatooth or\n"
	.string "a Deepseascale that I have?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow: @ 820D841
	.string "Capt. Stern: Are you certain?\n"
	.string "It's useless to you, {PLAYER}…\p"
	.string "Well, okay, then. If you want to trade\n"
	.string "your Scanner, let me know.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth: @ 820D8BC
	.string "Capt. Stern: So you'll trade it for\n"
	.string "my Deepseatooth?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale: @ 820D8F1
	.string "Capt. Stern: So you'll trade it for\n"
	.string "my Deepseascale?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant: @ 820D926
	.string "Capt. Stern: Which one do you want?$"

SlateportCity_Harbor_Text_HandedScannerToStern: @ 820D94A
	.string "{PLAYER} handed the SCANNER to\n"
	.string "Capt. Stern.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch: @ 820D970
	.string "Capt. Stern: Thanks, {PLAYER}!\n"
	.string "This will help our research a lot!$"

@==================================================================================================Aqua

SCH_AquaEvent::
	applymovement OBJ_EVENT_ID_PLAYER, SCH_WalktoStern
	msgbox SCH_NowThenCapt
	closemessage
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox SCH_YouWillNot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SCH_HitStern
	playse SE_W003
	waitse
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	removeobject 4
	fadescreen FADE_FROM_BLACK
	msgbox GoodRiddance
	closemessage
	applymovement 8, Common_Movement_FaceUp
	waitmovement 8
	msgbox SCH_AhSeemsLike
	closemessage
	applymovement 8, Common_Movement_FaceDown
	waitmovement 8
	msgbox SCH_NowThenPlayer
	closemessage
	playse SE_DOOR
	waitse
	applymovement 8, Common_Movement_FaceUp
	applymovement 7, Common_Movement_FaceUp
	waitmovement 7
	setflag FLAG_RYU_HIDE_REL_OBJECTS
	removeobject 8
	removeobject 7
	applymovement 6, SCH_SubExits @ right 18, remove
	waitmovement 6
	removeobject 6
	setvar VAR_RYU_AQUA, 108 @player should be headed to Mossdeep to meet with Matt
	clearflag FLAG_RYU_HIDE_MOSSDEEP_MATT
	release
	end
	
SCH_NowThenCapt:
	.string "Now then, Capt. Stern, in the name\n"
    .string "of Team Aqua, I'll be taking command\l"
    .string "of this here vessel!$"

SCH_YouWillNot:
	.string "You absolutely will not!\n"
    .string "You think you can just waltz in her-$"

GoodRiddance:
	.string "Good riddance.$"
	
SCH_AhSeemsLike:
	.string "Ah, seems like the crew's all set.$"
	
SCH_NowThenPlayer:
	.string "Now then, {PLAYER}, I'd actually like\n"
    .string "for you to be stationed in Mossdeep\l"
    .string "City.\p"
    .string "Matt should already have arrived so\n"
    .string "rendezvous with him and witness our\l"
    .string "glory unfold!$"


SCH_WalktoStern:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end
	
SCH_HitStern:
	walk_in_place_fast_up
	step_end
	
SCH_SubExits:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SCH_SetInvisible::
	set_invisible
	step_end















