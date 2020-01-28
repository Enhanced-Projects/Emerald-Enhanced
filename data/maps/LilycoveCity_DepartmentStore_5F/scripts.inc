LilycoveCity_DepartmentStore_5F_MapScripts:: @ 821FF7A
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_OnWarp
	.byte 0

@ During the abnormal weather from Kyogre/Groudon awakening the dept store rooftop is inaccessible
@ Likely done to avoid dealing with showing the weather. Technically the rooftop is indoors
LilycoveCity_DepartmentStore_5F_OnWarp: @ 821FF80
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs:: @ 821FF9A
	setobjectxy 7, 16, 2
	turnobject 7, DIR_NORTH
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft:: @ 821FFA6
	lock
	faceplayer
	msgbox BallChangerQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuBallChanger
	goto_if_set FLAG_RYU_NUZLOCKEMODE, RyuMartsDisabledNuzlocke
	message LCC_BALL_STORE_MSG
	waitmessage
	pokemart LCC_BallItemMart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

BallChangerQuery:
	.string "Would you like to change the ball\nyour lead pokemon is stored in?$"

	.align 2
LCC_EvoItemMart: @ 821FFC0
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_METAL_COAT
	.2byte ITEM_PRISM_SCALE
	.2byte ITEM_PROTECTOR
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft:: @ 821FFDC
	lock
	faceplayer
	message LCC_EVO_STORE_MSG
	waitmessage
	pokemart LCC_EvoItemMart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LCC_BallItemMart: @ 821FFF4
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_SAFARI_BALL
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight:: @ 822000A
	lock
	faceplayer
	message LCC_BATTLE_ITEM_MSG
	waitmessage
	pokemart LCC_BattleItemMart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LCC_BattleItemMart: @ 8220024
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_CHOICE_SPECS
    .2byte ITEM_EXPERT_BELT
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_IRON_BALL
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_LAGGING_TAIL
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight:: @ 822003A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LCC_ShardItemMarket
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LCC_ShardItemMarket: @ 8220054
	.2byte 59
	.2byte 60
	.2byte 61
	.2byte 62
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_RED_SHARD
	.2byte ITEM_BLUE_SHARD
	.2byte ITEM_YELLOW_SHARD
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_PokefanF:: @ 822006C
	msgbox LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_EventScript_Woman:: @ 8220075
	lockall
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
	goto_if_eq LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	goto_if_ge LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal:: @ 822009C
	msgbox LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather:: @ 82200A7
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl:: @ 82200BC
	msgbox LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls: @ 82200C5
	.string "This place is full of cute DOLLS.\p"
	.string "I should buy some for me, instead of\n"
	.string "just for my children.$"

LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon: @ 8220122
	.string "I'm not big enough to raise Pokémon,\n"
	.string "so I'm getting a cute DOLL instead.$"

LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere: @ 822016B
	.string "They sell many cute MATS here.\p"
	.string "I wonder which one I should get?\n"
	.string "Maybe I'll buy them all…$"

LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather: @ 82201C4
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"

LCC_Jeweler::
	goto_if_set FLAG_RYU_PLAYER_AQUA_STONE, LCC_Jeweler_Customwork
	msgbox LCC_Jeweler_Welcome MSGBOX_DEFAULT
	pokemart LCC_Jewels
	msgbox LCC_Jeweler_exit MSGBOX_DEFAULT
	release
	end

	.align 2
LCC_Jewels:
	.2byte ITEM_PEARL
	.2byte ITEM_BIG_PEARL
	.2byte ITEM_STAR_PIECE
	.2byte ITEM_NONE
	
LCC_Jeweler_Customwork::
	msgbox LCC_Jeweler_MakeNecklace MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LCC_JewelEnd
	checkitem ITEM_STAR_PIECE, 1
	compare VAR_RESULT, 1
	goto_if_eq LCC_JewelerMakingNecklace
	goto LCC_JewelEndNoItem
	
LCC_JewelerMakingNecklace::
	msgbox LCC_JewelerMakingNecklaceMsg MSGBOX_DEFAULT
	removeitem ITEM_STAR_PIECE, 1
	msgbox LCC_NecklaceMade MSGBOX_DEFAULT
	clearflag FLAG_RYU_PLAYER_AQUA_STONE
	setflag FLAG_RYU_PLAYER_AQUA_NECKLACE
	release
	end
	
	
LCC_Jeweler_Welcome:
	.string "Welcome to my jewel gift shop.\n"
	.string "Get that special item for that special\p"
	.string "someone here!$"

LCC_Jeweler_exit:
	.string "Thanks for your patronage!$"
	
LCC_Jeweler_MakeNecklace:
	.string "Oh, my, that's a high quality star\n"
	.string "piece. Would you like me to turn it\p"
	.string "into a necklace? It would be so\n"
	.string "beautiful!$"
	
LCC_JewelEnd::
	msgbox LCC_JewelEndMsg MSGBOX_DEFAULT
	release
	end

LCC_JewelEndMsg:
	.string "Oh, that's such a same. Any woman\n"
	.string "would absolutely love it. My offer\p"
	.string "to do this has a limited time window\n"
	.string "come back if you change your mind!$"
	
LCC_JewelEndNoItem:
	.string "Oh, I was mistaken. That's just a\n"
	.string "mundane stone. I must be too\p"
	.string "tired.$"
	
LCC_JewelerMakingNecklaceMsg:
	.string "Give me a couple minutes to work\n"
	.string "with this stone. It will be worth it,\p"
	.string "I promise!$"
	
LCC_NecklaceMade:
	.string "All done! It turned out even more\n"
	.string "beautiful than I thought it would.\p"
	.string "You're going to make a girl very\n"
	.string "happy with this!$"

LCC_BALL_STORE_MSG:
    .string "Hello and welcome to the\n"
	.string "Ball Market.\l"
	.string "Get your balls here!$"

LCC_BATTLE_ITEM_MSG:
    .string "Hello and welcome to the Battle Item\n"
	.string "store. We carry all the latest battle\l"
	.string "tech and gear here!$"

LCC_EVO_STORE_MSG:
    .string "Hello and welcome to Darwin's market!\n"
	.string "All evolution needs can be found here!$"

