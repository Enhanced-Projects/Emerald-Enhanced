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
// These can be any size, similar to my other tables.
// I recommend at least 20 per table, but up to whoever,
// just make sure they’re all the same size.

// all of the items here are placeholder until we decide what we're going to do with all this stuff.
const u16 gBotanyRewardTables[NUM_BOTANY_MAP_CATEGORIES][5] = {
    [BOTANY_MAP_CATEGORY_JUNGLE] = {
        ITEM_NONE, //ITEM_JUNGLE_CHESTNUT,
        ITEM_ENERGY_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_MIRACLE_SEED,
        ITEM_ENERGY_POWDER,
    },
    [BOTANY_MAP_CATEGORY_COLD] = {
        ITEM_NONE, //ITEM_FROST_MINT,
        ITEM_ENERGY_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_MENTAL_HERB,
        ITEM_REVIVAL_HERB,
    },
    [BOTANY_MAP_CATEGORY_VOLCANIC] = {
        ITEM_NONE, //ITEM_CHIMNEY_PEPPER,
        ITEM_ENERGY_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_BIG_MUSHROOM,
        ITEM_HARD_STONE,
    },
    [BOTANY_MAP_CATEGORY_SEASIDE] = {
        ITEM_NONE, //ITEM_SEASIDE_SPINACH,
        ITEM_ENERGY_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_HEART_SCALE,
        ITEM_MISTY_SEED,
    },
    [BOTANY_MAP_CATEGORY_AQUATIC] = {
        ITEM_NONE, //ITEM_DEEPSEA_KELP
        ITEM_ENERGY_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_HEART_SCALE,
        ITEM_MISTY_SEED,
    },
    [BOTANY_MAP_CATEGORY_SAVANNA] = {
        ITEM_NONE, //ITEM_SAVANNA_MELON
        ITEM_ENERGY_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_HEART_SCALE,
        ITEM_MISTY_SEED,
    },
    [BOTANY_MAP_CATEGORY_GENERAL] = {
        ITEM_ANTIDOTE,
        ITEM_ENERGY_POWDER,
        ITEM_ENERGY_POWDER,
        ITEM_PARALYZE_HEAL,
        ITEM_BURN_HEAL,
    },
};

const u16 gBotanyTreeRewards[] = {//need some placeholders for 'none', as the reward function loads item names into text buffers, which will cause overflow and glitchy text.
    ITEM_RED_APRICORN,
    ITEM_BLUE_APRICORN,
    ITEM_YELLOW_APRICORN,
    ITEM_GREEN_APRICORN,
    ITEM_PINK_APRICORN,
    ITEM_WHITE_APRICORN,
    ITEM_BLACK_APRICORN,
    ITEM_STICK,
    ITEM_MIRACLE_SEED,
    ITEM_POISON_BARB,
    ITEM_NONE,
    ITEM_NONE
};

#define NUM_INGREDIENTS_PER_RECIPE 5
#define NUM_RECIPES 9

//Recipe defines
#define MUSCLE_POWDER_RECIPE 0
#define TOUGH_POWDER_RECIPE 1
#define SMART_POWDER_RECIPE 2
#define RESIST_POWDER_RECIPE 3
#define SWIFT_POWDER_RECIPE 4
#define SMALL_SALAD_RECIPE 5
#define MEDIUM_SALAD_RECIPE 6
#define LARGE_SALAD_RECIPE 7
#define REVITAL_ICE_RECIPE 8

//TEMPORARY Item defines
#define ITEM_SEASIDE_SPINACH 0
#define ITEM_JUNGLE_CHESTNUT 1
#define ITEM_DEEPSEA_KELP 2
#define ITEM_FROST_MINT 3
#define ITEM_CHIMNEY_PEPPER 4
#define ITEM_LEEK 5
#define ITEM_BANANA 6

#define ITEM_MUSCLE_POWDER 0
#define ITEM_TOUGH_POWDER 1
#define ITEM_SMART_POWDER 2
#define ITEM_RESIST_POWDER 3
#define ITEM_SWIFT_POWDER 4
#define ITEM_SMALL_SALAD 5
#define ITEM_MEDIUM_SALAD 6
#define ITEM_LARGE_SALAD 7
#define ITEM_REVITAL_ICE 8
//recipe to item mapping

const u16 sBotanyRecipeToItemId[NUM_RECIPES] = {
    ITEM_MUSCLE_POWDER,
    ITEM_TOUGH_POWDER,
    ITEM_SMART_POWDER,
    ITEM_RESIST_POWDER,
    ITEM_SWIFT_POWDER,
    ITEM_SMALL_SALAD,
    ITEM_MEDIUM_SALAD,
    ITEM_LARGE_SALAD,
    ITEM_REVITAL_ICE
};

//recipe tables for lookup

const u16 sBotanyRecipes[NUM_RECIPES][NUM_INGREDIENTS_PER_RECIPE][2] = {
    [MUSCLE_POWDER_RECIPE] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_ORAN_BERRY, 1},
        {ITEM_SEASIDE_SPINACH, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [TOUGH_POWDER_RECIPE] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_ORAN_BERRY, 1},
        {ITEM_JUNGLE_CHESTNUT, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [SMART_POWDER_RECIPE] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_ORAN_BERRY, 1},
        {ITEM_DEEPSEA_KELP, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [RESIST_POWDER_RECIPE] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_ORAN_BERRY, 1},
        {ITEM_FROST_MINT, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [SWIFT_POWDER_RECIPE] = {
        {ITEM_ENERGY_POWDER, 1},
        {ITEM_ORAN_BERRY, 1},
        {ITEM_CHIMNEY_PEPPER, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [SMALL_SALAD_RECIPE] = {
        {ITEM_LEEK, 1},
        {ITEM_BANANA, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [MEDIUM_SALAD_RECIPE] = {
        {ITEM_GRASSY_SEED, 1},
        {ITEM_TINY_MUSHROOM, 1},
        {ITEM_LUMINOUS_MOSS, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [LARGE_SALAD_RECIPE] = {
        {ITEM_MIRACLE_SEED, 1},
        {ITEM_BIG_MUSHROOM, 1},
        {ITEM_BIG_ROOT, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    },
    [REVITAL_ICE_RECIPE] = {
        {ITEM_SNOWBALL, 1},
        {ITEM_MOOMOO_MILK, 1},
        {ITEM_BANANA, 1},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0},
    }
};
