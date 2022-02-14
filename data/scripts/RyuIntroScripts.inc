GameIntroSequencePart1::
	clearflag FLAG_RYU_RANDOMBATTLE
	goto GameModeSelect
	
LRT_IntroMsg1:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You awaken later than you expected.\p It seems like your clock's\n battery died.)$"

GameModeSelect:: @ 823BF04
	lockall
	closemessage
	goto_if_set FLAG_RYU_ISNGPLUS, Ryu_NewGamePlus
	msgbox RI_CheckPreviousExp, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NGNormalMode
	closemessage
	msgbox Ryu_PleaseSelectDifficulty
	multichoicedefault 1, 2, MULTI_SELECT_FRESH_NEW_GAME_MODE, 0, 0
	switch VAR_RESULT
	case 0, IT_EasyMode
	case 1, IT_NormalMode
	case 2, IT_ChallengeMode
	case 3, IT_FrontierMode
	goto IT_NormalMode
	end

NGNormalMode::
	msgbox RI_ConfirmDifficulty
	goto IT_NormalMode

RI_ConfirmDifficulty:
	.string "You have been set to the\nrecommended mode.$"

GameModeSelectLati::
	msgbox GMS_WhichColor
	multichoice 22, 8, MULTI_TV_LATI, 1
	compare VAR_RESULT, 0
	call_if_eq RyuIntro_SetLatiGenderMale
	compare VAR_RESULT, 1
	call_if_eq RYuIntro_SetLatiGenderFemale
	return

RyuIntro_SetLatiGenderMale::
	setvar VAR_ROAMER_POKEMON, 0 @should make it so that the roamer is latios
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special InitRoamer
	return

RYuIntro_SetLatiGenderFemale::
	setvar VAR_ROAMER_POKEMON, 0 @should make it so that the roamer is latias
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special InitRoamer
	return

GMS_WhichColor:
	.string "Which color is your favorite?$"

Ryu_PleaseSelectDifficulty::
	.string "Please choose a mode to play.$"

Ryu_NewGamePlus::
	clearflag FLAG_RYU_RANDOMBATTLE
	msgbox RyuNGPInfo
	closemessage
	call_if_set FLAG_RYU_HAS_WAYSTONE, Ryu_NGP_Waystone
	call_if_set FLAG_RYU_HAS_IMPRINTER, Ryu_NGP_Imprinter
	call_if_set FLAG_RYU_HAS_FORECASTER, Ryu_NGP_Forecaster
	call_if_set FLAG_RYU_HAS_EXP_DRIVE, Ryu_NGP_ExpDrive
	call_if_set FLAG_RYU_HAS_WIRELESSPC, Ryu_NGP_WirelessPC
	call_if_set FLAG_RYU_HAS_EXPSHARE, Ryu_NGP_ExpShare
	call_if_set FLAG_HAS_ACRO_BIKE, Ryu_NGP_AcroBike
	call_if_set FLAG_HAS_MACH_BIKE, Ryu_NGP_MachBike
	call_if_set FLAG_RYU_HAS_MEGA_BRACELET, Ryu_NGP_MegaBracelet
	call_if_set FLAG_RYU_HAS_SHINY_CHARM, Ryu_NGP_ShinyCharm
	call_if_set FLAG_RYU_HAS_OVAL_CHARM, Ryu_NGP_OvalCharm
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	closemessage
	msgbox Ryu_PleaseSelectDifficulty
	multichoicedefault 1, 2, MULTI_SELECT_NEW_GAME_PLUS_MODE, 3, 0
	switch VAR_RESULT
	case 0, IT_NormalMode	
	case 1, IT_ChallengeMode
    case 2, IT_HardcoreMode
	goto IT_NormalMode

RI_CheckPreviousExp:
	.string "Have you played Emerald Enhanced\nbefore?$"

Ryu_NGP_Waystone:
	additem ITEM_WAYSTONE, 1
	return

Ryu_NGP_Forecaster:
	additem ITEM_FORECASTER, 1
	return

Ryu_NGP_ExpDrive:
	additem ITEM_EXP_DRIVE, 1
	return

Ryu_NGP_Imprinter:
	additem ITEM_IMPRINTER, 1
	return

Ryu_NGP_WirelessPC:
	additem ITEM_WIRELESSPC, 1
	return

Ryu_NGP_ExpShare::
	additem ITEM_EXP_SHARE, 1
	return

Ryu_NGP_AcroBike:: @// broken
	additem ITEM_ACRO_BIKE 1
	return

Ryu_NGP_MachBike:: @// broken
	additem ITEM_MACH_BIKE, 1
	return

Ryu_NGP_OvalCharm::
	additem ITEM_OVAL_CHARM, 1
	return

Ryu_NGP_MegaBracelet::
	additem ITEM_MEGA_BRACELET, 1
	return

Ryu_NGP_ShinyCharm::
	additem ITEM_SHINY_CHARM, 1
	return

RyuNGPInfo:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Welcome to New Game +.\p"
	.string "In this mode, you get to keep any\n"
	.string "unique quest reward items, such as\l"
	.string "the Waystone and the Exp Drive.\p"
	.string "Your Pokémon storage is still\n"
	.string "intact, including any held items.\p"
	.string "In addition, enemy levels are scaled\n"
	.string "to your own party instead of badges.$"

RyuSetTime:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} put a new battery in the alarm.)$"

IT_EasyMode::
	setvar VAR_RYU_EXP_MULTIPLIER, 4000
	setvar VAR_RYU_PRICE_MULTIPLIER, 500
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SetMaleStartingVariables
	compare VAR_RESULT, FEMALE
	goto_if_eq SetFemaleStartingVariables
	end
	
IT_NormalMode::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_RYU_PRICE_MULTIPLIER, 1000
	call_if_set FLAG_RYU_ISNGPLUS, Normalmode_NGP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SetMaleStartingVariables
	compare VAR_RESULT, FEMALE
	goto_if_eq SetFemaleStartingVariables
	end

Normalmode_NGP::
	setvar VAR_RYU_AUTOLEVEL_MODIFIER, -2
	setvar VAR_RYU_EXP_MULTIPLIER, 10 @arbitrary value to tell getExp to use the ngp scaling
	return
	
IT_ChallengeMode::
	msgbox IT_ChallengeIntro MSGBOX_SIGN
	call_if_set FLAG_RYU_ISNGPLUS, Challengemode_NGP
	setvar VAR_RYU_EXP_MULTIPLIER, 2000
	setvar VAR_RYU_PRICE_MULTIPLIER, 1500
	setvar VAR_RYU_CHALLENGE_WAYSTONE_USES, 3
	setvar VAR_RYU_PC_USES, 3
	additem ITEM_POKE_BALL, 10
	additem ITEM_POTION, 5
	additem ITEM_SUPER_POTION, 2
	additem ITEM_ELIXIR, 2
	removemoney 3000
	msgbox IT_ChallengeOutro MSGBOX_SIGN
	setflag FLAG_RYU_CHALLENGEMODE
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SetMaleStartingVariables
	compare VAR_RESULT, FEMALE
	goto_if_eq SetFemaleStartingVariables
	end

Challengemode_NGP::
	setvar VAR_RYU_AUTOLEVEL_MODIFIER, -2
	return

IT_FrontierMode::
	msgbox IT_FrontierIntro
	setvar VAR_RYU_EXP_MULTIPLIER, 1
	setvar VAR_RYU_PRICE_MULTIPLIER 1000
	removemoney 3000
	giveitem ITEM_MEGA_BRACELET
	msgbox IT_FrontierOutro
	additem ITEM_SS_TICKET
	setflag FLAG_SYS_FRONTIER_PASS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setflag FLAG_RYU_FRONTIER_MODE
	setflag FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT
	setflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SetMaleStartingVariables
	compare VAR_RESULT, FEMALE
	goto_if_eq SetFemaleStartingVariables

IT_HardcoreMode::
	msgbox IT_HardcoreIntro
	setvar VAR_RYU_AUTOLEVEL_MODIFIER, 5
	setvar VAR_RYU_EXP_MULTIPLIER, 2000
	setvar VAR_RYU_PRICE_MULTIPLIER, 2000
	setflag FLAG_RYU_HARDCORE_MODE
	setvar VAR_RYU_CHALLENGE_WAYSTONE_USES, 1
	removemoney 2750
	msgbox IT_HardcoreOutro
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SetMaleStartingVariables
	compare VAR_RESULT, FEMALE
	goto_if_eq SetFemaleStartingVariables
	end

IT_FrontierOutro:
    .string "All game flags and variables have\n"
    .string "been intialized.\p"
    .string "You can spend your earned BP in the\n"
    .string "BP Exchange Service Corner to get\l"
    .string "new pokemon for your team.$"

IT_FrontierIntro:
    .string "Welcome to frontier mode, trainer.\p"
    .string "In this mode you pick a starter\n"
    .string "team of 3 pokemon and you don't\l"
    .string "do any of the normal intro stuff.\p"
    .string "You earn BP to expand your team.\p"
    .string "You must get all silver medals to\n"
    .string "be able to leave the Frontier.$"
	
IT_HardcoreIntro:
    .string "Hello, and welcome to Hardcore\n"
    .string "mode.\p"
    .string "In this mode, you are restricted\n"
    .string "even further than Challenge mode.\p"
    .string "You make 15% the money you normally\n"
    .string "you normally would.\p"
    .string "You can't use pokecenters, and you\n"
    .string "will not get healed or recieve\l"
    .string "handouts from gym leaders.$"
	
IT_HardcoreOutro:
	.string "Welcome to the nightmare.$"

IT_ChallengeIntro:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}You have opted to do Challenge mode.\n"
	.string "Emerald Enhanced uses a special set\p"
	.string "of rules, and enforces them. They are:\p"
	.string "1: No marts.\p"
	.string "2: Can use PC 3 times between\n"
	.string "  badges. Clear a gym to restore.\p"
	.string "3: You start with balls and potions.\p"
	.string "4: Black-Out ends the game.\p"
	.string "5: Gym Leaders heal and give items\p"
	.string "6: Exp is doubled, to make up for the\n"
	.string "difficulty of the game.\p"
	.string "7: You can't deposit mons in the PC.\p"
	.string "Finally: Any mon that faints is\n"
	.string "deleted from your party.\p"
	.string "Enjoy your challenge!\n"
	.string "--Ryu, Creator of Emerald Enhanced$"
	
IT_ChallengeOutro:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Challenge rules are now active!\n"
	.string "Starter Kit has been given!$"
	

SetMaleStartingVariables:: @ 823BF20
	call RyuSetUpMoneyMode
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_BH_DAD
	setflag FLAG_HIDE_DH_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	goto_if_set FLAG_RYU_FRONTIER_MODE, Ryu_FrontierModeBegin
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 3, 10
	msgbox LRT_IntroMsg1 MSGBOX_SIGN
	msgbox RyuSetTime MSGBOX_SIGN
	goto RyuSetRTC
	releaseall
	end

SetFemaleStartingVariables:: @ 823BF46
	call RyuSetUpMoneyMode
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_DAWNS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	setflag FLAG_HIDE_BH_DAD
	setflag FLAG_HIDE_DH_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_SIBLING
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	goto_if_set FLAG_RYU_FRONTIER_MODE, Ryu_FrontierModeBegin
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	msgbox LRT_IntroMsg1 MSGBOX_SIGN
	msgbox RyuSetTime MSGBOX_SIGN
	goto RyuSetRTC
	releaseall
	end

Ryu_FrontierModeBegin::
	call RyuSetRTCFrontier
	end

InsideOfTruck_EventScript_23BF6C:: @ 823BF6C
	end

RyuSetRTC::
	goto_if_set FLAG_SET_WALL_CLOCK, ViewClock
	msgbox ClockStopped, MSGBOX_DEFAULT
	call SetClockStage1
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	setflag FLAG_SET_WALL_CLOCK
	goto GameIntroSequencePart2
	releaseall
	end

RyuSetRTCFrontier::
	msgbox FrontierClockStopped, MSGBOX_DEFAULT
	call SetClockStage1
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 10
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_RYU_MET_RIVAL_LITTLEROOT
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
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	goto GameIntroSequenceFrontier
	releaseall
	end

GameIntroSequenceFrontier::
	msgbox FrontierModeBegin
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 26, 65
	releaseall
	release
	end

FrontierModeBegin:
	.string "Your frontier challenge begins now!$"

FrontierClockStopped::
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (Please set the time.)$"
	
ViewClock:: @ 829283F
	incrementgamestat 45
	fadescreen 1
	special Special_ViewWallClock
	waitstate
	releaseall
	end


ClockStopped:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}The clock is stopped…\p"
	.string "Better set it and start it!$"
	
SetClockStage1:: @ 8292849
	fadescreen 1
	special StartWallClock
	waitstate
	return
	
GameIntroSequencePart2::
	lock
    checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq GameIntroFemalePart2
	applymovement PLAYER, GI_Male_GetOutOfBed
	waitmovement 0
	playse SE_PC_ON
	waitse
	playse SE_PIN
	applymovement PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	msgbox GI_CheckedEmail MSGBOX_SIGN
	closemessage
	playse SE_PC_OFF
	waitse
	msgbox GI_GoSeeRivalMaleMsg MSGBOX_SIGN
	closemessage
	clearflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	releaseall
	end
	
GameIntroFemalePart2::
	applymovement PLAYER, GI_Female_GetOutOfBed
	waitmovement 0
	playse SE_PC_ON
	waitse
	playse SE_PIN
	applymovement PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	msgbox GI_CheckedEmail MSGBOX_SIGN
	closemessage
	playse SE_PC_OFF
	checkplayergender
	msgbox GI_GoSeeRivalFemaleMsg MSGBOX_SIGN
	closemessage
	clearflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	releaseall
	end
	
GI_Male_GetOutOfBed:
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	walk_in_place_up
	step_end
	
GI_Female_GetOutOfBed:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_in_place_up
	step_end
	
GI_CheckedEmail:
	.string "{PLAYER} checked email.\pThere's 2 new emails.\pOne from the online market which says:\n 'The ordered item was delivered to\l your item box!'\pThere's another one here... \nIt's from Prof. Birch! It says: \p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}! I'm glad you decided to \nstart your journey!\pCome see me in my lab to get\nyour starting partner!\pI'm looking forward to meeting you!$"
	
GI_GoSeeRivalMaleMsg:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You remember that the professor\n has a daughter.\l Maybe you should go meet her?)$"
	
GI_GoSeeRivalFemaleMsg:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You remember that the professor\n has a son.\l Maybe you should go meet him?)$"

LRT_MOM::
	lock
	faceplayer
	msgbox MomIntro
	closemessage
	special checkbadgecount
	compare VAR_RESULT, 4
	goto_if_ge LRT_Mom_4Badges
	goto LRT_Mom_base

LRT_Mom_4Badges::
	goto_if_set  FLAG_RYU_MOM_EXP_SHARE, LRT_Check6B
	msgbox mom4badgesmsg
	giveitem ITEM_EXP_SHARE
	setvar VAR_RYU_TITLE_DEFENSE_WINS, 0
	setflag FLAG_RYU_MOM_EXP_SHARE
	goto LRT_Mom_base

LRT_Check6B::
	special checkbadgecount
	compare VAR_RESULT, 6
	goto_if_ge LRT_Mom_6badges
	goto LRT_Mom_base

LRT_Mom_6badges::
	goto_if_set FLAG_RYU_MOM_LOPUNNITE, LRT_Check8B
	msgbox mom6badgesmsg
	additem ITEM_LOPUNNITE
	setflag FLAG_RYU_MOM_LOPUNNITE
	goto LRT_Mom_base

LRT_Check8B::
	special checkbadgecount
	compare VAR_RESULT, 8
	goto_if_ge LRT_Mom_8badges
	goto LRT_Mom_base

LRT_Mom_8badges::
	goto_if_set FLAG_RYU_MOM_AMULET_COIN, LRT_Mom_base
	msgbox mom8badgesmsg
	giveitem ITEM_AMULET_COIN
	setflag FLAG_RYU_MOM_AMULET_COIN
	goto LRT_Mom_base

LRT_Mom_base::
	goto_if_set FLAG_RYU_CHALLENGEMODE, LRT_MOM_Restricted
	goto_if_set FLAG_RYU_HARDCORE_MODE, LRT_MOM_Restricted
	msgbox Momwouldyouliketoheal, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LRT_Mom_Heal
	msgbox MomGoGetThem

LRT_MOM_Restricted::
	msgbox Mom_IBelieveInYou
	release
	end

LRT_Mom_Heal::
	playbgm MUS_DUMMY, 1
	fadescreen FADE_TO_BLACK
	delay 30
	special HealPlayerParty
	delay 30
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	msgbox Mom_IBelieveInYou
	release
	end

MomIntro:
	.string "Mom: Hi, {PLAYER}! Did you come to visit\n"
	.string "dear old mom?$"

Momwouldyouliketoheal:
	.string "Would you like to rest\nin your old room?$"

mom4badgesmsg:
	.string "Oh, you're off to the Hoenn\n"
	.string "League soon, aren't you?\p"
	.string "Well you're going to need to\n"
	.string "train up! This should help.$"

mom6badgesmsg:
	.string "Mom: Oh, {PLAYER}, I saw a cute\n"
	.string "Pokémon on TV recently, and I\p"
	.string "ordered this stone, but I guess\n"
	.string "it only works if you have a Mega\l"
	.string "Bracelet. So here, you can have it!$"

mom8badgesmsg:
	.string "Mom: I see you've been moving\n"
	.string "up in the world. Here! take\l"
	.string "this from me!\p"
	.string "It was a gift from your father\n"
	.string "when we were dating.\p"
	.string "I don't actively battle anymore,\n"
	.string "so I don't need it!$"

MomGoGetThem:
	.string "Mom: I believe in you, {PLAYER}!\n"
	.string "Teach your father some humility!$"

Mom_IBelieveInYou:
	.string "Mom: Keep at it!$"
