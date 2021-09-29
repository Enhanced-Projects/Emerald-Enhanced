//This file has all the rewards tables for the different life skills.
#include "constants/region_map_sections.h"
//gem tier list. These will be used when refining their respective ores.
const u16 gGemTier3[] = {//rare gem ore
    ITEM_FLYING_GEM,
    ITEM_DRAGON_GEM,
    ITEM_FIGHTING_GEM,
    ITEM_STEEL_GEM,
    ITEM_ICE_GEM,
    ITEM_NORMAL_GEM,
};

const u16 gGemTier2[] = {//uncommon gem ore
    ITEM_ROCK_GEM,
    ITEM_DARK_GEM,
    ITEM_FAIRY_GEM,
    ITEM_ELECTRIC_GEM,
    ITEM_FIRE_GEM,
    ITEM_GROUND_GEM,
};
const u16 gGemTier1[] = {//common gem ore
    ITEM_POISON_GEM,
    ITEM_WATER_GEM,
    ITEM_GHOST_GEM,
    ITEM_BUG_GEM,
    ITEM_PSYCHIC_GEM,
    ITEM_GRASS_GEM,
};

const u16 gRyuLowPickupTable[NUM_PICKUP_TABLE_ENTRIES] = { //level range 0 - 49
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_SUPER_POTION,
    ITEM_GREAT_BALL,
    ITEM_REPEL,
    ITEM_ESCAPE_ROPE,
    ITEM_X_ATTACK,
    ITEM_FULL_HEAL,
    ITEM_PREMIER_BALL,
    ITEM_HYPER_POTION,
    ITEM_LAVA_COOKIE,
    ITEM_PREMIER_BALL,
    ITEM_REVIVE,
    ITEM_ETHER,
    ITEM_SUPER_POTION,
    ITEM_MAX_REVIVE,
    ITEM_PP_UP,
    ITEM_MAX_ELIXIR,
};

const u16 gRyuMedPickupTable[NUM_PICKUP_TABLE_ENTRIES] = {//level range 50 - 109
    ITEM_HYPER_POTION,
    ITEM_FULL_HEAL,
    ITEM_SUPER_POTION,
    ITEM_GREAT_BALL,
    ITEM_SUPER_REPEL,
    ITEM_EVERSTONE,
    ITEM_X_ATTACK,
    ITEM_FULL_HEAL,
    ITEM_ULTRA_BALL,
    ITEM_HYPER_POTION,
    ITEM_LAVA_COOKIE,
    ITEM_ULTRA_BALL,
    ITEM_REVIVE,
    ITEM_HP_UP,
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_PP_UP,
    ITEM_PROTEIN,
};

const u16 gRyuHighPickupTable[NUM_PICKUP_TABLE_ENTRIES] = { //level range 110 - 129
    ITEM_BIG_PEARL,
    ITEM_KINGS_ROCK,
    ITEM_FULL_RESTORE,
    ITEM_ETHER,
    ITEM_WHITE_HERB,
    ITEM_MOON_STONE,
    ITEM_ELIXIR,
    ITEM_FIRE_STONE,
    ITEM_WATER_STONE,
    ITEM_LEAF_STONE,
    ITEM_DAWN_STONE,
    ITEM_DUSK_STONE,
    ITEM_SHINY_STONE,
    ITEM_SUN_STONE,
    ITEM_GOLD_ORE,
    ITEM_GOLD_NUGGET,
    ITEM_MAX_POTION,
    ITEM_GOLD_NUGGET
};

const u16 gRyuMaxPickupTable[NUM_PICKUP_TABLE_ENTRIES] = { //level range 130+
    ITEM_BIG_PEARL,
    ITEM_BEAST_BALL,
    ITEM_FULL_RESTORE,
    ITEM_STAR_PIECE,
    ITEM_REVITAL_ICE,
    ITEM_MOON_STONE,
    ITEM_MAX_ELIXIR,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_STARDUST,
    ITEM_DAWN_STONE,
    ITEM_DUSK_STONE,
    ITEM_SHINY_STONE,
    ITEM_SUN_STONE,
    ITEM_SOFT_SAND,
    ITEM_GOLD_NUGGET,
    ITEM_MAX_POTION,
    ITEM_GOLD_NUGGET
};

const u16 gFossilTable[] = {//used when refining fossil ore
    ITEM_DOME_FOSSIL,
    ITEM_DOME_FOSSIL,
    ITEM_HELIX_FOSSIL,
    ITEM_HELIX_FOSSIL,
    ITEM_OLD_AMBER,
    ITEM_OLD_AMBER,
    ITEM_ROOT_FOSSIL,
    ITEM_ROOT_FOSSIL,
    ITEM_CLAW_FOSSIL,
    ITEM_CLAW_FOSSIL,
    ITEM_SKULL_FOSSIL,
    ITEM_SKULL_FOSSIL,
    ITEM_ARMOR_FOSSIL,
    ITEM_ARMOR_FOSSIL,
    ITEM_COVER_FOSSIL,
    ITEM_COVER_FOSSIL,
    ITEM_PLUME_FOSSIL,
    ITEM_PLUME_FOSSIL,
    ITEM_JAW_FOSSIL,
    ITEM_JAW_FOSSIL,
    ITEM_SAIL_FOSSIL,
    ITEM_SAIL_FOSSIL,
    ITEM_THICK_CLUB,
    ITEM_RARE_BONE,
    ITEM_EVERSTONE,
    ITEM_HARD_STONE,
    ITEM_FLOAT_STONE,
    ITEM_DAMP_ROCK,
    ITEM_ICY_ROCK,
    ITEM_SMOOTH_ROCK,
    ITEM_HEAT_ROCK,
    ITEM_SOFT_SAND,
    ITEM_OVAL_STONE,
    ITEM_MASTER_BALL,//no item
    ITEM_MASTER_BALL,//no item
    ITEM_MASTER_BALL,//no item
    ITEM_MASTER_BALL,//no item
};

const u16 gShardOreTable[] = {//the table rolled on when refining shard ores.
    ITEM_DARK_SHARD,
    ITEM_DARK_SHARD,
    ITEM_LIGHT_SHARD,
    ITEM_LIGHT_SHARD,
    ITEM_CYAN_SHARD,
    ITEM_CYAN_SHARD,
    ITEM_GLOSSY_SHARD,
    ITEM_GLOSSY_SHARD,
    ITEM_GOLD_SHARD,
    ITEM_GOLD_SHARD,
    ITEM_GRAY_SHARD,
    ITEM_GRAY_SHARD,
    ITEM_RED_SHARD,
    ITEM_RED_SHARD,
    ITEM_BLUE_SHARD,
    ITEM_BLUE_SHARD,
    ITEM_YELLOW_SHARD,
    ITEM_YELLOW_SHARD,
    ITEM_GREEN_SHARD,
    ITEM_GREEN_SHARD,
    ITEM_LIGHT_CLAY,
    ITEM_IRON_BALL,
    ITEM_METAL_COAT,
    ITEM_STAR_PIECE,
    ITEM_STARDUST,
    ITEM_HEART_SCALE,
    ITEM_REVIVE,
    ITEM_MAX_REVIVE,
    ITEM_RARE_CANDY,
};

//Mining tables for interior maps

const u16 gInsideMiningTier1[] = {//level 1
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_COPPER_ORE,
    ITEM_COPPER_ORE,
    ITEM_COPPER_ORE,
    ITEM_SILVER_ORE,
};

const u16 gInsideMiningTier2[] = {//level 2
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_FOSSIL_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_COPPER_ORE,
    ITEM_COPPER_ORE,
    ITEM_SILVER_ORE,
    ITEM_SILVER_ORE,
    ITEM_GOLD_ORE
};
const u16 gInsideMiningTier3[] = {//level 3
    ITEM_GOLD_ORE,
    ITEM_RARE_GEM_ORE,
    ITEM_RARE_GEM_ORE,
    ITEM_RARE_GEM_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_FOSSIL_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_SILVER_ORE,
    ITEM_GOLD_ORE,
    ITEM_GOLD_ORE
};

//Mining table for list of 'outside' maps. 
//You need to add new outside locations here 
//when you add new rocks if you want the miningcheck to differentiate them.

const u16 gOutsideMapSecs[] = {
    MAPSEC_ROUTE_66,
    MAPSEC_ROUTE_114,
    MAPSEC_ROUTE_115,
    MAPSEC_ROUTE_116,
    MAPSEC_MT_PYRE,
    MAPSEC_JAGGED_PASS,
    MAPSEC_JAGGED_PASS2,
};

//mining tables for exterior maps
const u16 gOutsideMiningTier1[] = {//level 1
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_COPPER_ORE,
    ITEM_COPPER_ORE,
    ITEM_COPPER_ORE,
    ITEM_SILVER_ORE,
};

const u16 gOutsideMiningTier2[] = {//level 2
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_FOSSIL_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_SHARD_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_SHARD_ORE,
    ITEM_COPPER_ORE,
    ITEM_SILVER_ORE,
    ITEM_SILVER_ORE,
    ITEM_GOLD_ORE
};
const u16 gOutsideMiningTier3[] = {//level 3
    ITEM_COPPER_ORE,
    ITEM_RARE_GEM_ORE,
    ITEM_RARE_GEM_ORE,
    ITEM_FOSSIL_ORE,
    ITEM_SHARD_ORE,
    ITEM_COMMON_GEM_ORE,
    ITEM_NONE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_UNCOMMON_GEM_ORE,
    ITEM_SHARD_ORE,
    ITEM_SHARD_ORE,
    ITEM_NONE,
    ITEM_SILVER_ORE,
    ITEM_COPPER_ORE,
    ITEM_FOSSIL_ORE
};

//LIFESKILL BOTANY=================================================================================



// reward tables
// These tables can be any size, as long as they're all the same size
const u16 gBotanyRewardTables[NUM_BOTANY_MAP_CATEGORIES][10] = {
    [BOTANY_MAP_CATEGORY_JUNGLE] = {
        ITEM_JUNGLE_BEANS,
        ITEM_LUMINOUS_MOSS,
        ITEM_BIG_ROOT,
        ITEM_GRASSY_SEED,
        //Shared items:
        ITEM_MIRACLE_SEED,
        ITEM_HEAL_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_POWER_HERB,
        ITEM_MENTAL_HERB,
        ITEM_WHITE_HERB,
    },
    [BOTANY_MAP_CATEGORY_COLD] = {
        ITEM_FROST_MINT,
        ITEM_SNOWBALL,
        ITEM_NEVER_MELT_ICE,
        ITEM_MISTY_SEED,
        //Shared items:
        ITEM_MIRACLE_SEED,
        ITEM_HEAL_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_POWER_HERB,
        ITEM_MENTAL_HERB,
        ITEM_WHITE_HERB,
    },
    [BOTANY_MAP_CATEGORY_VOLCANIC] = {
        ITEM_CHIMNEY_PEPPER,
        ITEM_HARD_STONE,
        ITEM_CHARCOAL,
        ITEM_SOFT_SAND,
        //Shared items:
        ITEM_MIRACLE_SEED,
        ITEM_HEAL_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_POWER_HERB,
        ITEM_MENTAL_HERB,
        ITEM_WHITE_HERB,
    },
    [BOTANY_MAP_CATEGORY_SEASIDE] = {
        ITEM_SEASIDE_ALMOND,
        ITEM_SOFT_SAND,
        ITEM_SHOAL_SALT,
        ITEM_SHOAL_SHELL,
        //Shared items:
        ITEM_MIRACLE_SEED,
        ITEM_HEAL_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_POWER_HERB,
        ITEM_MENTAL_HERB,
        ITEM_WHITE_HERB,
    },
    [BOTANY_MAP_CATEGORY_AQUATIC] = {
        ITEM_DEEPSEA_KELP,
        ITEM_HEART_SCALE,
        ITEM_PEARL,
        ITEM_PSYCHIC_SEED,
        //Shared items:
        ITEM_MIRACLE_SEED,
        ITEM_HEAL_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_POWER_HERB,
        ITEM_MENTAL_HERB,
        ITEM_WHITE_HERB,
    },
    [BOTANY_MAP_CATEGORY_SAVANNA] = {
        ITEM_SAVANNA_MELON,
        ITEM_SOFT_SAND,
        ITEM_RARE_BONE,
        ITEM_ELECTRIC_SEED,
        //Shared items:
        ITEM_MIRACLE_SEED,
        ITEM_HEAL_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_POWER_HERB,
        ITEM_MENTAL_HERB,
        ITEM_WHITE_HERB,
    },
    [BOTANY_MAP_CATEGORY_GENERAL] = {
        ITEM_ABSORB_BULB,
        ITEM_LEEK,
        ITEM_TINY_MUSHROOM,
        ITEM_BIG_MUSHROOM,
        //Shared items:
        ITEM_MIRACLE_SEED,
        ITEM_HEAL_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_POWER_HERB,
        ITEM_MENTAL_HERB,
        ITEM_WHITE_HERB,
    },
};

const u16 gBotanyTreeRewards[] = {
    ITEM_RED_APRICORN,
    ITEM_BLUE_APRICORN,
    ITEM_YELLOW_APRICORN,
    ITEM_GREEN_APRICORN,
    ITEM_PINK_APRICORN,
    ITEM_WHITE_APRICORN,
    ITEM_BLACK_APRICORN,
    ITEM_MIRACLE_SEED,
    ITEM_GRASSY_SEED,
    ITEM_ABSORB_BULB,
    ITEM_LUMINOUS_MOSS,
    ITEM_BIG_ROOT,
    ITEM_TASTY_LEAF,
    ITEM_TASTY_LEAF,
    ITEM_TASTY_LEAF,
    ITEM_TASTY_LEAF
};

const u16 sBotanyRecipeToItemId[NUM_RECIPES] = {//must have exactly the same number of items as NUM_RECIPES, or rewards wont work.
    ITEM_MUSCLE_POWDER,
    ITEM_TOUGH_POWDER,
    ITEM_SMART_POWDER,
    ITEM_RESIST_POWDER,
    ITEM_SWIFT_POWDER,
    ITEM_FOCUS_POWDER,
    ITEM_SMALL_SALAD,
    ITEM_MEDIUM_SALAD,
    ITEM_LARGE_SALAD,
    ITEM_HEAL_CHOWDER,
    ITEM_LEMONADE,
    ITEM_REVITAL_ICE,
    ITEM_HP_UP,
    ITEM_PROTEIN,
    ITEM_IRON,
    ITEM_CALCIUM,
    ITEM_ZINC,
    ITEM_CARBOS,
    ITEM_ETHER,
    ITEM_ELIXIR,
    ITEM_FIRE_STONE,
    ITEM_WATER_STONE,
    ITEM_THUNDER_STONE,
    ITEM_LEAF_STONE,
    ITEM_MOON_STONE,
    ITEM_SUN_STONE,
    ITEM_SHINY_STONE,
    ITEM_DUSK_STONE,
    ITEM_DAWN_STONE,
    ITEM_ICE_STONE
};

//recipe tables for lookup

const u16 sBotanyRecipes[NUM_RECIPES][NUM_INGREDIENTS_PER_RECIPE][2] = {
    [BR_MUSCLE_POWDER] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_BANANA, 1},
        {ITEM_SEASIDE_ALMOND, 2},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_TOUGH_POWDER] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_BANANA, 1},
        {ITEM_SAVANNA_MELON, 2},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_SMART_POWDER] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_BANANA, 1},
        {ITEM_DEEPSEA_KELP, 2},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_RESIST_POWDER] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_BANANA, 1},
        {ITEM_FROST_MINT, 2},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_SWIFT_POWDER] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_BANANA, 1},
        {ITEM_CHIMNEY_PEPPER, 2},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_FOCUS_POWDER] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_BANANA, 1},
        {ITEM_JUNGLE_BEANS, 2},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_SM_SALAD] = {
        {ITEM_LEEK, 1},
        {ITEM_BANANA, 2},
        {ITEM_MIRACLE_SEED, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_MD_SALAD] = {
        {ITEM_GRASSY_SEED, 1},
        {ITEM_TINY_MUSHROOM, 2},
        {ITEM_ABSORB_BULB, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_LG_SALAD] = {
        {ITEM_LUMINOUS_MOSS, 1},
        {ITEM_BIG_MUSHROOM, 1},
        {ITEM_BIG_ROOT, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_HEAL_CHOWDER] = {
        {ITEM_HEAL_POWDER, 1},
        {ITEM_MOOMOO_MILK, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_LEMONADE] = {
        {ITEM_FRESH_WATER, 1},
        {ITEM_BANANA, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_REVITAL_ICE] = {
        {ITEM_SNOWBALL, 2},
        {ITEM_MOOMOO_MILK, 1},
        {ITEM_BANANA, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [BR_HP_UP] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_PROTEIN] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_MUSCLE_POWDER, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_IRON] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_TOUGH_POWDER, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_CALCIUM] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SMART_POWDER, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_ZINC] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_RESIST_POWDER, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_CARBOS] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SWIFT_POWDER, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_ETHER] = {
        {ITEM_BIG_ROOT, 1},
        {ITEM_LEMONADE, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_ELIXIR] = {
        {ITEM_ETHER, 2},
        {ITEM_BIG_ROOT, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_FIRE_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_FIRE_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_WATER_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_WATER_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_THUNDER_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_ELECTRIC_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_LEAF_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_GRASS_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_MOON_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_GHOST_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_SUN_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_PSYCHIC_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_SHINY_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_FAIRY_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_DUSK_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_DARK_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_DAWN_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_NORMAL_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_ICE_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_ICE_GEM, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
};

const AlchemyRecipe gAlchemyRecipes[NUM_ALCHEMY_RECIPES] = {
    [ALCHEMY_EFFECT_NONE] = {
          .expGiven = 0,
          .ingredients = {
          {ITEM_NONE, 0 },
          {ITEM_NONE, 0 },
          {ITEM_NONE, 0 },
        },
        .metal = 0,
        .metalDustAmt = 0,
        .requiredLevel = 1,
        .givenCharges = 5
  },
    [ALCHEMY_EFFECT_DAMAGE_BOOST_T1] = {
          .expGiven = 5,
          .ingredients = {
          {ITEM_MUSCLE_POWDER, 3 },
          {ITEM_STARDUST, 2 },
          {ITEM_FRESH_WATER, 1 },
        },
        .metal = 0,
        .metalDustAmt = 500,
        .requiredLevel = 1,
        .givenCharges = 5,
  },
    [ALCHEMY_EFFECT_DAMAGE_BOOST_T2] = {
          .expGiven = 10,
          .ingredients = {
          {ITEM_MUSCLE_POWDER, 6 },
          {ITEM_STARDUST, 4 },
          {ITEM_TONIC_WATER, 1 },
        },
        .metal = 2,
        .metalDustAmt = 500,
        .requiredLevel = 3,
        .givenCharges = 5,
  },
    [ALCHEMY_EFFECT_DAMAGE_BOOST_T3] = {
          .expGiven = 15,
          .ingredients = {
          {ITEM_MUSCLE_POWDER, 12 },
          {ITEM_STARDUST, 8 },
          {ITEM_MINERAL_WATER, 4 },
        },
        .metal = 3,
        .metalDustAmt = 750,
        .requiredLevel = 5,
        .givenCharges = 5,
  },
    [ALCHEMY_EFFECT_DEFENSE_BOOST_T1] = {
          .expGiven = 5,
          .ingredients = {
          {ITEM_TOUGH_POWDER, 3 },
          {ITEM_STARDUST, 2 },
          {ITEM_FRESH_WATER, 1 },
        },
        .metal = 0,
        .metalDustAmt = 500,
        .requiredLevel = 1,
        .givenCharges = 5,
  },
    [ALCHEMY_EFFECT_DEFENSE_BOOST_T2] = {
          .expGiven = 10,
          .ingredients = {
          {ITEM_TOUGH_POWDER, 6 },
          {ITEM_STARDUST, 4 },
          {ITEM_TONIC_WATER, 2 },
        },
        .metal = 2,
        .metalDustAmt = 500,
        .requiredLevel = 3,
        .givenCharges = 5,
  },
    [ALCHEMY_EFFECT_DEFENSE_BOOST_T3] = {
          .expGiven = 15,
          .ingredients = {
          {ITEM_TOUGH_POWDER, 12 },
          {ITEM_STARDUST, 8 },
          {ITEM_MINERAL_WATER, 4 },
        },
        .metal = 3,
        .metalDustAmt = 750,
        .requiredLevel = 5,
        .givenCharges = 5,
  },

    [ALCHEMY_EFFECT_EXP_BOOST_T1] = {
          .expGiven = 5,
          .ingredients = {
            {ITEM_RARE_CANDY, 1},
            {ITEM_FRESH_WATER, 1},
            {ITEM_STAR_PIECE, 1},
        },
        .metal = 0,
        .metalDustAmt = 250,
        .requiredLevel = 2,
        .givenCharges = 1,
    },
    [ALCHEMY_EFFECT_EXP_BOOST_T2] = {
          .expGiven = 10,
          .ingredients = {
            {ITEM_RARE_CANDY, 2},
            {ITEM_TONIC_WATER, 1},
            {ITEM_BIG_PEARL, 1},
        },
        .metal = 2,
        .metalDustAmt = 250,
        .requiredLevel = 2,
        .givenCharges = 1,
    },
    [ALCHEMY_EFFECT_EXP_BOOST_T3] = {
          .expGiven = 15,
          .ingredients = {
            {ITEM_RARE_CANDY, 3},
            {ITEM_MINERAL_WATER, 1},
            {ITEM_GOLD_NUGGET, 1},
        },
        .metal = 3,
        .metalDustAmt = 250,
        .requiredLevel = 2,
        .givenCharges = 10,
    },
    [ALCHEMY_EFFECT_REPEL_T1] = {
          .expGiven = 7,
          .ingredients = {
          {ITEM_RAWST_BERRY, 2 },
          {ITEM_STARDUST, 2 },
          {ITEM_TONIC_WATER, 1 },
        },
        .metal = 0,
        .metalDustAmt = 100,
        .requiredLevel = 2,
        .givenCharges = 1,
  },
    [ALCHEMY_EFFECT_REPEL_T2] = {
          .expGiven = 14,
          .ingredients = {
          {ITEM_RAWST_BERRY, 4 },
          {ITEM_STARDUST, 4 },
          {ITEM_TONIC_WATER, 1 },
        },
        .metal = 2,
        .metalDustAmt = 100,
        .requiredLevel = 2,
        .givenCharges = 1,
  },
    [ALCHEMY_EFFECT_SUPER_CAPTURE] = {
          .expGiven = 10,
          .ingredients = {
            {ITEM_BRIGHT_POWDER, 1},
            {ITEM_FRESH_WATER, 1},
            {ITEM_GREAT_BALL, 1},
        },
        .metal = 0,
        .metalDustAmt = 250,
        .requiredLevel = 1,
        .givenCharges = 1,
    },
    [ALCHEMY_EFFECT_ULTRA_CAPTURE] = {
          .expGiven = 20,
          .ingredients = {
            {ITEM_LUMINOUS_MOSS, 1},
            {ITEM_TONIC_WATER, 1},
            {ITEM_ULTRA_BALL, 1},
        },
        .metal = 2,
        .metalDustAmt = 250,
        .requiredLevel = 3,
        .givenCharges = 1,
    },
    [ALCHEMY_EFFECT_MASTER_CAPTURE] = {
          .expGiven = 30,
          .ingredients = {
            {ITEM_MENTAL_HERB, 1},
            {ITEM_MINERAL_WATER, 1},
            {ITEM_LUXURY_BALL, 1},
        },
        .metal = 3,
        .metalDustAmt = 250,
        .requiredLevel = 5,
        .givenCharges = 1,
    },
    [ALCHEMY_EFFECT_HEALING_FACTOR] = {
          .expGiven = 10,
          .ingredients = {
            {ITEM_HEAL_POWDER, 3},
            {ITEM_MINERAL_WATER, 1},
            {ITEM_ORAN_BERRY, 1},
        },
        .metal = 0,
        .metalDustAmt = 200,
        .requiredLevel = 2,
        .givenCharges = 5,
    },

    //Alchemy Item Recipes Below.
    [ALCHEMY_ITEM_RECIPE_STARDUST] = {
          .expGiven = 5,
          .ingredients = {
            {ITEM_SOFT_SAND, 2},
            {ITEM_GEM_POWDER, 2},
            {ITEM_NONE, 0},
        },
        .metal = 2,
        .metalDustAmt = 200,
        .requiredLevel = 1,
        .givenCharges = 255,
    },

    [ALCHEMY_ITEM_RECIPE_FRESH_WATER] = {
          .expGiven = 10,
          .ingredients = {
            {ITEM_SNOWBALL, 2},
            {ITEM_FIRE_STONE, 1},
            {ITEM_NONE, 1},
        },
        .metal = 2,
        .metalDustAmt = 100,
        .requiredLevel = 1,
        .givenCharges = 255,
    },

    [ALCHEMY_ITEM_RECIPE_TONIC_WATER] = {
          .expGiven = 20,
          .ingredients = {
            {ITEM_FRESH_WATER, 2},
            {ITEM_CHARCOAL, 1},
            {ITEM_NONE, 1},
        },
        .metal = 2,
        .metalDustAmt = 200,
        .requiredLevel = 1,
        .givenCharges = 255,
    },

    [ALCHEMY_ITEM_RECIPE_MINERAL_WATER] = {
          .expGiven = 40,
          .ingredients = {
            {ITEM_TONIC_WATER, 2},
            {ITEM_SOFT_SAND, 1},
          {ITEM_SHOAL_SALT, 1},
        },
        .metal = 2,
        .metalDustAmt = 300,
        .requiredLevel = 1,
        .givenCharges = 255,
    },

    [ALCHEMY_ITEM_RECIPE_RARE_CANDY] = {
          .expGiven = 20,
          .ingredients = {
            {ITEM_LEMONADE, 1},
            {ITEM_MINERAL_WATER, 1},
            {ITEM_SMART_POWDER, 1},
        },
        .metal = 3,
        .metalDustAmt = 200,
        .requiredLevel = 2,
        .givenCharges = 255,
    },

    [ALCHEMY_ITEM_RECIPE_GOLD_NUGGET] = {
          .expGiven = 20,
          .ingredients = {
            {ITEM_LEMONADE, 1},
            {ITEM_MINERAL_WATER, 1},
            {ITEM_SMART_POWDER, 1},
        },
        .metal = 3,
        .metalDustAmt = 200,
        .requiredLevel = 2,
        .givenCharges = 255,
    },
};

const u8 sRAEffectNoneDesc[] =         _("No Effect");
const u8 sRAEffectDamage1[] =          _("T1 Damage Boost");
const u8 sRAEffectDamage2[] =          _("T2 Damage Boost");
const u8 sRAEffectDamage3[] =          _("T3 Damage Boost");
const u8 sRAEffectDefense1[] =         _("T1 Defense Boost");
const u8 sRAEffectDefense2[] =         _("T2 Defense Boost");
const u8 sRAEffectDefense3[] =         _("T3 Defense Boost");
const u8 sRAEffectRepelT1[] =          _("T1 Ultra Repel");
const u8 sRAEffectRepelT2[] =          _("T2 Ultra Repel");
const u8 sRAEffectSuperCapture1[] =    _("T1 Capture Boost");
const u8 sRAEffectSuperCapture2[] =    _("T2 Capture Boost");
const u8 sRAEffectSuperCapture3[] =    _("T3 Capture Boost");
const u8 sRAEffectEXPBoost1[] =        _("T1 Exp Boost");
const u8 sRAEffectEXPBoost2[] =        _("T2 Exp Boost");
const u8 sRAEffectEXPBoost3[] =        _("T3 Exp Boost");
const u8 sRAEffectHealingFactor[] =    _("Healing Factor");

const u8 * const gRyuAlchemyEffectItemToStringTable[16] = {
    sRAEffectNoneDesc,
    sRAEffectDamage1,
    sRAEffectDamage2,
    sRAEffectDamage3,
    sRAEffectDefense1,
    sRAEffectDefense2,
    sRAEffectDefense3,
    sRAEffectEXPBoost1,
    sRAEffectEXPBoost2,
    sRAEffectEXPBoost3,
    sRAEffectRepelT1,
    sRAEffectRepelT2,
    sRAEffectSuperCapture1,
    sRAEffectSuperCapture2,
    sRAEffectSuperCapture3,
    sRAEffectHealingFactor
};


