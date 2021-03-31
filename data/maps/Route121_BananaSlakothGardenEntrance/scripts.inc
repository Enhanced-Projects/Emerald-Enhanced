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

