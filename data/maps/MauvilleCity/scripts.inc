MauvilleCity_MapScripts:: @ 81DF385
	map_script ON_TRANSITION, MauvilleCity_OnTransition
	map_script ON_FRAME, MauvilleCity_OnFrame
	.byte 0

MauvilleCity_OnTransition: @ 81DF38B
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_OnFrame::
	map_script_2 VAR_TEMP_5, 0, CheckFollowerLanette
	map_script_2 VAR_TEMP_A, 0, Ryu_CheckMagmaStatusForMissionCall
	map_script_2 VAR_TEMP_6, 0, Ryu_CheckEnableDexNav
	.2byte 0

CheckFollowerLanette::
	setvar VAR_TEMP_5, 100
	goto_if_unset FLAG_RYU_HAS_FOLLOWER, ryu_end
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_WOMAN_2
	goto_if_eq MC_LanetteInteraction
	goto ryu_end

MauvilleCity_EventScript_MoveWattsonBackToGym:: @ 81DF3A9
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	return

MauvilleCity_EventScript_Boy:: @ 81DF3B3
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac:: @ 81DF3BC
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman:: @ 81DF3C5
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy:: @ 81DF3CE
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign:: @ 81DF3D7
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign:: @ 81DF3E0
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign:: @ 81DF3E9
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign:: @ 81DF3F2
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM:: @ 81DF3FB
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained:: @ 81DF413
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_Wattson:: @ 81DF73A
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	compare VAR_NEW_MAUVILLE_STATE, 2
	goto_if_eq MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville:: @ 81DF77A
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville:: @ 81DF784
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveegg SPECIES_ZERAORA
	setflag FLAG_GOT_TM24_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt:: @ 81DF7B0
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Text_WattsonNeedFavorTakeKey: @ 81DFFE4
	.string "Wattson: Oh, {PLAYER}!\n"
	.string "You look like you have a lot of zip!\l"
	.string "That's a good thing, wahahahaha!\p"
	.string "Fine! I've decided!\n"
	.string "I need a favor, {PLAYER}!\p"
	.string "Mauville City has an underground\n"
	.string "sector called New Mauville.\p"
	.string "{PLAYER}, I'd like you to go there and\n"
	.string "switch off the generator.\p"
	.string "The generator has been running a bit\n"
	.string "haywire. It's getting unsafe.\p"
	.string "Here, this is the Key to get into\n"
	.string "New Mauville.$"

MauvilleCity_Text_WattsonWontBeChallenge: @ 81E0154
	.string "Wattson: Don't you worry about it.\n"
	.string "It won't be a challenge to you.\p"
	.string "The entrance to New Mauville is just\n"
	.string "a short swim away from Route 110.\p"
	.string "That's it, then, you have my trust!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM: @ 81E020E
    .string "Wattson: Wahahahaha!\p"
    .string "I knew it, {PLAYER}! I knew I'd made\n"
    .string "the right choice asking you!\p"
    .string "This is my thanks--an egg!\p"
    .string "I found it in a magnetic field,\n"
    .string "maybe a special pokemon is inside?\p"
    .string "Go on, you've earned it!$"

MauvilleCity_Text_WattsonYoungTakeCharge: @ 81E02AA
	.string "Wattson: Wahahahaha!\p"
	.string "It pleases me to no end to see\n"
	.string "the young step up and take charge!$"

MauvilleCity_Text_NurseHurtMonBackToHealth: @ 81E0301
	.string "You know, it's cool to have Pokémon\n"
	.string "battles and stuff…\p"
	.string "But if your Pokémon gets hurt,\n"
	.string "you have to nurse it back to health.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough: @ 81E037C
	.string "The roads of this town stretch north\n"
	.string "and south, and east and west.\p"
	.string "Because of that, we get all sorts of\n"
	.string "people coming through.$"

MauvilleCity_Text_RydelVeryGenerous: @ 81E03FB
	.string "Have you been to Rydel's Cycles yet?\p"
	.string "Rydel, the owner, is a very generous\n"
	.string "man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike: @ 81E044A
	.string "Even if you're riding a Bike,\n"
	.string "wild Pokémon could jump you.$"

MauvilleCity_Text_CitySign: @ 81E0485
	.string "Mauville City\n"
	.string "“The bright and shiny city of fun!”$"

MauvilleCity_Text_GymSign: @ 81E04B7
	.string "Mauville City Pokemon Gym\n"
	.string "Leader: Wattson\l"
	.string "“The cheerfully electrifying man!”$"

MauvilleCity_Text_BikeShopSign: @ 81E0504
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "Rydel's Cycles$"

MauvilleCity_Text_GameCornerSign: @ 81E053C
	.string "“The play spot for all!”\n"
	.string "Mauville Game Corner$"

MauvilleCity_Text_ExplainTV: @ 81E056A
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"

MauvilleCity_Text_BeenCheckingOutTV: @ 81E0699
	.string "Hi, have you been checking out TVs?$"


@=================================================================================================== Lanette interaction

MC_LanetteInteraction::
	lock
	switch VAR_FACING
	case DIR_NORTH, MC_LI_North
	case DIR_SOUTH, MC_LI_South
	case DIR_EAST, MC_LI_East
	case DIR_WEST, MC_LI_West
	goto MC_LI_Main
	

MC_LI_North::
	applymovement OBJ_EVENT_ID_FOLLOWER MC_LI_MoveNorth
	goto MC_LI_Main

MC_LI_South::
	applymovement OBJ_EVENT_ID_FOLLOWER MC_LI_MoveSouth
	goto MC_LI_Main

MC_LI_East::
	applymovement OBJ_EVENT_ID_FOLLOWER MC_LI_MoveEast
	goto MC_LI_Main

MC_LI_West::
	applymovement OBJ_EVENT_ID_FOLLOWER MC_LI_MoveWest
	goto MC_LI_Main


MC_LI_Main::
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox MC_LI_Intro
	release
	end


MC_LI_MoveNorth:
	walk_right
	walk_up
	walk_in_place_up
	step_end

MC_LI_MoveSouth:
	walk_left
	walk_down
	walk_in_place_down
	step_end

MC_LI_MoveEast:
	walk_up
	walk_left
	walk_in_place_left
	step_end

MC_LI_MoveWest:
	walk_down
	walk_left
	walk_in_place_left
	step_end

MC_LI_Intro:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I always did love this city\n"
    .string "It's a shame that New Mauville\p"
    .string "never got finished. I was looking\n"
    .string "forwards to programming the power\l"
    .string "distribution system.\p"
    .string "I found that Rotom I gave you down\n"
    .string "there. It was posessing a lamp.\p"
    .string "I hope one day that I can program\n"
    .string "virtual reality worlds, where we can\p"
    .string "go anywhere and do anything without\n"
    .string "the effort of walking. I'm not a\l"
    .string "fan of exercise.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Are you sure about that?\p"
    .string "What do you call what we did that\n"
    .string "one night?\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}... ... ... ..."
    .string "That's different!\p"
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lanette flushes brightly and\n"
    .string " stops talking)$"
