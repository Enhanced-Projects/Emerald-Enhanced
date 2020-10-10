LilycoveCity_DepartmentStore_5F_MapScripts:: @ 821FF7A
	.byte 0

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
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_METAL_COAT
	.2byte ITEM_PROTECTOR
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_REAPER_CLOTH
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
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_CHOICE_SPECS
    .2byte ITEM_CHOICE_SCARF
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_WEAKNESS_POLICY
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_BLACK_SLUDGE
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_EVIOLITE
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_IRON_BALL
	.2byte ITEM_LAGGING_TAIL
	.2byte ITEM_AIR_BALLOON
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight:: @ 822003A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LCC_NaturalMedicineMarket
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LCC_NaturalMedicineMarket: @ 8220054
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_SWEET_HEART
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_OLD_GATEAU
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
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
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
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
	.string "This place sells so many balls.\p"
	.string "Which will be most fitting for my\n"
	.string "darling Azumarill?$"

LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon: @ 8220122
	.string "I'm going to buy a Moon Stone to\n"
	.string "evolve my sweet Skitty.$"

LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere: @ 822016B
	.string "They sell many powerfull battle\n"
	.string "items here.\p"
	.string "I wonder which one will improve my\n"
	.string "Wigglytuff the most?$"

LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather: @ 82201C4
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"

LCC_Jeweler::
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
	.2byte ITEM_NORMAL_GEM
	.2byte ITEM_FIRE_GEM
	.2byte ITEM_WATER_GEM
	.2byte ITEM_ELECTRIC_GEM
	.2byte ITEM_GRASS_GEM
	.2byte ITEM_ICE_GEM
	.2byte ITEM_FIGHTING_GEM
	.2byte ITEM_POISON_GEM
	.2byte ITEM_GROUND_GEM
	.2byte ITEM_FLYING_GEM
	.2byte ITEM_PSYCHIC_GEM
	.2byte ITEM_BUG_GEM
	.2byte ITEM_ROCK_GEM
	.2byte ITEM_GHOST_GEM
	.2byte ITEM_DRAGON_GEM
	.2byte ITEM_DARK_GEM
	.2byte ITEM_STEEL_GEM
	.2byte ITEM_FAIRY_GEM
	.2byte ITEM_NONE
	
LCC_Jeweler_Welcome:
	.string "Welcome to my jewel gift shop.\p"
	.string "Get that special item for that special\n"
	.string "someone here!$"

LCC_Jeweler_exit:
	.string "Thanks for your patronage!$"

LCC_BALL_STORE_MSG:
    .string "Hello and welcome to the\n"
	.string "Ball Market.\l"
	.string "Get your balls here!$"

LCC_BATTLE_ITEM_MSG:
    .string "Hello and welcome to the Battle Item\n"
	.string "Store.\p"
	.string "We carry all the latest battle tech\n"
	.string "and gear here!$"

LCC_EVO_STORE_MSG:
    .string "Hello and welcome to Darwin's market!\n"
	.string "Evolution needs can be found here!$"

