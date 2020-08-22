SnowyShore_Mart_MapScripts::
	map_script ON_TRANSITION, SnowyShore_Mart_OnTransition
	.byte 0

SnowyShore_Mart_OnTransition:
	setrespawn HEAL_LOCATION_SNOWY_SHORE
	end

SnowyShore_Mart_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SnowyShore_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SnowyShore_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SnowyShore_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_CHILL_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

SnowyShore_Mart_EventScript_LeftWoman::
	lock
	faceplayer
	msgbox SnowyShore_Mart_Text_BookAboutMtFreeze, MSGBOX_DEFAULT
	release
	end

SnowyShore_Mart_Text_BookAboutMtFreeze:
	.string "I'm looking for a book about the\n"
	.string "history of Mt Freeze.\p"
	.string "Did you know it's actually a\n"
	.string "volcano?$"

SnowyShore_Mart_EventScript_RightWoman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_SNOWY_SHORE_RECEIVED_BERRY, SnowyShore_Mart_EventScript_ReceivedBerry
	msgbox SnowyShore_Mart_Text_AreYouFromAroundHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SnowyShore_Mart_EventScript_Yes
	compare VAR_RESULT, NO
	goto_if_eq SnowyShore_Mart_EventScript_No
	end

SnowyShore_Mart_EventScript_Yes::
	msgbox SnowyShore_Mart_Text_YouShouldTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_ASPEAR_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SNOWY_SHORE_RECEIVED_BERRY
	msgbox SnowyShore_Mart_Text_AspearBerriesWarmYouUp, MSGBOX_DEFAULT
	release
	end

SnowyShore_Mart_EventScript_No::
	msgbox SnowyShore_Mart_Text_TakeGoodCare, MSGBOX_DEFAULT
	release
	end

SnowyShore_Mart_EventScript_ReceivedBerry::
	msgbox SnowyShore_Mart_Text_AspearBerriesWarmYouUp, MSGBOX_DEFAULT
	release
	end

SnowyShore_Mart_Text_AreYouFromAroundHere:
	.string "Are you cold?\n"
	.string "You look a little pale.$"

SnowyShore_Mart_Text_YouShouldTakeThis:
	.string "You should take this.$"

SnowyShore_Mart_Text_AspearBerriesWarmYouUp:
	.string "Aspear Berries warm you up when\n"
	.string "consumed. We use it in many dishes.$"

SnowyShore_Mart_Text_TakeGoodCare:
	.string "Take good care of yourself. It's\n"
	.string "easy to get cold out here.$"

SnowyShore_Mart_EventScript_Man::
	lock
	faceplayer
	msgbox SnowyShore_Mart_Text_ChillBall, MSGBOX_DEFAULT
	release
	end

SnowyShore_Mart_Text_ChillBall:
	.string "Did you know this is the only place\n"
	.string "where you can buy Chill Balls?\p"
	.string "Use them to catch the Ice type\n"
	.string "pokemon that inhabit this island.$"
