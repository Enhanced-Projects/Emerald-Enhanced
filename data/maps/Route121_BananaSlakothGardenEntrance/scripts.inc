Route121_BananaSlakothGardenEntrance_MapScripts::
	.byte 0

BotanyMaster_Master::
	faceplayer
    compare VAR_RYU_PLAYER_BOTANY_SKILL, 1
    goto_if_ge BotanyMaster_AlreadyTaught
    specialvar VAR_RESULT, CountBadges
    compare VAR_RESULT, 2
    goto_if_lt BotanyMaster_NoBadges
    msgbox BotanyMaster_BotanyIntroduction
    closemessage
	fadescreen FADE_TO_BLACK
	delay 60
	fadescreen FADE_FROM_BLACK
    setvar VAR_RYU_PLAYER_BOTANY_SKILL, 1
    setvar VAR_RYU_PLAYER_BOTANY_SKILL_EXP, 0
	giveitem ITEM_RECIPE_BOOK, 1
	msgbox BotanyMaster_GoForthAndCut
    release
    end

BotanyMaster_AlreadyTaught:
    msgbox BotanyMaster_LearnCutQuery, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq BotanyMaster_CutTutor
    msgbox BotanyMaster_CutDeclinedMsg
    closemessage
    release
    end

BotanyMaster_NoBadges:
    msgbox BotanyMaster_DefaultIntro
    closemessage
    release
    end

BotanyMaster_DefaultIntro:
	.string "Hello, traveller.\n"
	.string "They call me the Botany Master.\p"
	.string "If you show me your intelligence by\n"
	.string "obtaining 2 badges, I'll teach you\l"
	.string "a special skill.$"

BotanyMaster_BotanyIntroduction:
	.string "Welcome to our banana garden!\p"
	.string "I am the Botany Master.\p"
	.string "I will teach you the skill to cut\n"
	.string "grass and trees to get natural\l"
	.string "resources.$"

BotanyMaster_GoForthAndCut:
	.string "...and that's all there is to it!\p"
	.string "Now go forth and discover\n"
	.string "some organic treasures!$"

BotanyMaster_LearnCutQuery:
    .string "Would you like to teach a pokemon\nhow to harvest herbs?$"

Route121_BananaSlakothGardenEntrance_EventScript_Camper::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_SLAKOTH_BANANA_GARDEN_BANANAS, Route121_BananaSlakothGardenEntrance_EventScript_Welcome
	checkmoney 1500
	compare VAR_RESULT, FALSE
	goto_if_eq Route121_BananaSlakothGardenEntrance_EventScript_Welcome
	showmoneybox 0, 0, 0
	msgbox Route121_BananaSlakothGardenEntrance_Text_WelcomeWouldYouLike, MSGBOX_DEFAULT
	msgbox Route121_BananaSlakothGardenEntrance_Text_ItIsThisAmount, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route121_BananaSlakothGardenEntrance_EventScript_AcceptTrade
	compare VAR_RESULT, NO
	goto_if_eq Route121_BananaSlakothGardenEntrance_EventScript_DeclineTrade
	release
	end

Route121_BananaSlakothGardenEntrance_EventScript_Welcome::
	msgbox Route121_BananaSlakothGardenEntrance_Text_Welcome, MSGBOX_DEFAULT
	release
	end

Route121_BananaSlakothGardenEntrance_Text_Welcome:
	.string "Welcome to the Slakoth Banana Garden!\n"
	.string "The tastiest Bananas grow here!$"

Route121_BananaSlakothGardenEntrance_Text_WelcomeWouldYouLike:
	.string "Welcome to the Slakoth Banana Garden!\n"
	.string "Would you like to buy five of our\l"
	.string "hand picked Bananas?$"

Route121_BananaSlakothGardenEntrance_Text_ItIsThisAmount:
	.string "It's ¥1500 for a batch of five.$"

Route121_BananaSlakothGardenEntrance_EventScript_AcceptTrade::
	takemoney 1500
	updatemoneybox 0, 0
	giveitem ITEM_BANANA, 5
	setflag FLAG_DAILY_SLAKOTH_BANANA_GARDEN_BANANAS
	hidemoneybox
	release
	end

Route121_BananaSlakothGardenEntrance_EventScript_DeclineTrade::
	hidemoneybox
	release
	end

Route121_BananaSlakothGardenEntrance_EventScript_Picnicker::
	lock
	faceplayer
	msgbox Route121_BananaSlakothGardenEntrance_Text_ThisFellow, MSGBOX_DEFAULT
	release
	end

Route121_BananaSlakothGardenEntrance_Text_ThisFellow:
	.string "This fellow keeps crawling around\n"
	.string "when I am trying to examine him!\p"
	.string "Slakoth may be slow but this one\n"
	.string "sure isn't lazy.$"

Route121_BananaSlakothGardenEntrance_EventScript_VendingMachine::
	lockall
	message Route121_BananaSlakothGardenEntrance_Text_WhichSnackWouldYouLike
	waitmessage
	showmoneybox 0, 0, 0
	goto Route121_BananaSlakothGardenEntrance_EventScript_ChooseSnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_ChooseSnack::
	multichoice 16, 0, MULTI_SLAKOTH_VENDING_MACHINE, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Route121_BananaSlakothGardenEntrance_EventScript_SweetHeart
	case 1, Route121_BananaSlakothGardenEntrance_EventScript_BerryJuice
	case 2, Route121_BananaSlakothGardenEntrance_EventScript_MoomooMilk
	case 3, Route121_BananaSlakothGardenEntrance_EventScript_OldGateau
	case 4, Route121_BananaSlakothGardenEntrance_EventScript_BigMalasada
	msgbox Route121_BananaSlakothGardenEntrance_Text_DecidedAgainstBuyingSnack, MSGBOX_DEFAULT
	goto Route121_BananaSlakothGardenEntrance_EventScript_ExitVendingMachine
	end

Route121_BananaSlakothGardenEntrance_EventScript_SweetHeart::
	setvar VAR_TEMP_0, ITEM_SWEET_HEART
	goto Route121_BananaSlakothGardenEntrance_EventScript_TryBuySnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_BerryJuice::
	setvar VAR_TEMP_0, ITEM_BERRY_JUICE
	goto Route121_BananaSlakothGardenEntrance_EventScript_TryBuySnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_MoomooMilk::
	setvar VAR_TEMP_0, ITEM_MOOMOO_MILK
	goto Route121_BananaSlakothGardenEntrance_EventScript_TryBuySnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_OldGateau::
	setvar VAR_TEMP_0, ITEM_OLD_GATEAU
	goto Route121_BananaSlakothGardenEntrance_EventScript_TryBuySnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_BigMalasada::
	setvar VAR_TEMP_0, ITEM_BIG_MALASADA
	goto Route121_BananaSlakothGardenEntrance_EventScript_TryBuySnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneySweetHeart::
	setvar VAR_TEMP_0, 4000
	checkmoney VAR_TEMP_0
	return

Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyBerryJuice::
	checkmoney 1000
	return

Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyMoomooMilk::
	checkmoney 750
	return

Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyOldGateau::
	setvar VAR_TEMP_0, 4000
	checkmoney VAR_TEMP_0
	return

Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyBigMalasada::
	checkmoney 2000
	return

Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneySweetHeart::
	takemoney VAR_TEMP_0
	return

Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyBerryJuice::
	takemoney VAR_TEMP_0
	return

Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyMoomooMilk::
	takemoney 750
	return

Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyOldGateau::
	takemoney VAR_TEMP_0
	return

Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyBigMalasada::
	takemoney 2000
	return

Route121_BananaSlakothGardenEntrance_EventScript_TryBuySnack::
	compare VAR_TEMP_1, 0
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneySweetHeart
	compare VAR_TEMP_1, 1
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyBerryJuice
	compare VAR_TEMP_1, 2
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyMoomooMilk
	compare VAR_TEMP_1, 3
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyOldGateau
	compare VAR_TEMP_1, 4
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_CheckMoneyBigMalasada
	compare VAR_RESULT, FALSE
	goto_if_eq Route121_BananaSlakothGardenEntrance_EventScript_NotEnoughMoneyForSnack
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route121_BananaSlakothGardenEntrance_EventScript_NoRoomForSnack
	compare VAR_TEMP_1, 0
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneySweetHeart
	compare VAR_TEMP_1, 1
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyBerryJuice
	compare VAR_TEMP_1, 2
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyMoomooMilk
	compare VAR_TEMP_1, 3
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyOldGateau
	compare VAR_TEMP_1, 4
	call_if_eq Route121_BananaSlakothGardenEntrance_EventScript_TakeMoneyBigMalasada
	updatemoneybox 0, 0
	bufferitemname 0, VAR_TEMP_0
	playse SE_JIHANKI
	msgbox Route121_BananaSlakothGardenEntrance_Text_SnackDroppedDown, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0, 1
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional snack dropping
	compare VAR_RESULT, 0
	goto_if_ne Route121_BananaSlakothGardenEntrance_EventScript_ChooseNewSnack
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route121_BananaSlakothGardenEntrance_EventScript_NoRoomForSnack
	playse SE_JIHANKI
	msgbox Route121_BananaSlakothGardenEntrance_Text_ExtraSnackDroppedDown, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0, 1
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional snack dropping, ~ 0.02% chance
	compare VAR_RESULT, 0
	goto_if_ne Route121_BananaSlakothGardenEntrance_EventScript_ChooseNewSnack
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq Route121_BananaSlakothGardenEntrance_EventScript_NoRoomForSnack
	playse SE_JIHANKI
	msgbox Route121_BananaSlakothGardenEntrance_Text_ExtraSnackDroppedDown, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0, 1
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto Route121_BananaSlakothGardenEntrance_EventScript_ChooseNewSnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_ChooseNewSnack::
	message Route121_BananaSlakothGardenEntrance_Text_WhichSnackWouldYouLike
	waitmessage
	goto Route121_BananaSlakothGardenEntrance_EventScript_ChooseSnack
	end

Route121_BananaSlakothGardenEntrance_EventScript_NotEnoughMoneyForSnack::
	msgbox Route121_BananaSlakothGardenEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Route121_BananaSlakothGardenEntrance_EventScript_ExitVendingMachine
	end

Route121_BananaSlakothGardenEntrance_EventScript_NoRoomForSnack::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto Route121_BananaSlakothGardenEntrance_EventScript_ExitVendingMachine
	end

Route121_BananaSlakothGardenEntrance_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

Route121_BananaSlakothGardenEntrance_Text_WhichSnackWouldYouLike:
	.string "It's a Vending Machine.\n"
	.string "Which snack would you like?$"

Route121_BananaSlakothGardenEntrance_Text_SnackDroppedDown:
	.string "Clang!\p"
	.string "A {STR_VAR_1} dropped down.$"

Route121_BananaSlakothGardenEntrance_Text_ExtraSnackDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra {STR_VAR_1}\n"
	.string "dropped down!$"

Route121_BananaSlakothGardenEntrance_Text_NotEnoughMoney:
	.string "Not enough money…$"

Route121_BananaSlakothGardenEntrance_Text_DecidedAgainstBuyingSnack:
	.string "Decided against buying a snack.$"
