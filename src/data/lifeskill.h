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
    ITEM_BIG_ROOT
};

#define NUM_INGREDIENTS_PER_RECIPE 5

//Recipe defines
//consumable recipes
#define BR_MUSCLE_POWDER 0
#define BR_TOUGH_POWDER 1
#define BR_SMART_POWDER 2
#define BR_RESIST_POWDER 3
#define BR_SWIFT_POWDER 4
#define BR_FOCUS_POWDER 5
#define BR_SM_SALAD 6
#define BR_MD_SALAD 7
#define BR_LG_SALAD 8
#define BR_HEAL_CHOWDER 9
#define BR_LEMONADE 10
#define BR_REVITAL_ICE 11
//medicine recipes
#define BR_HP_UP 12
#define BR_PROTEIN 13
#define BR_IRON 14
#define BR_CALCIUM 15
#define BR_ZINC 16
#define BR_CARBOS 17
#define BR_ETHER 18
#define BR_ELIXIR 19
//evolution recipes
#define BR_FIRE_STONE 20
#define BR_WATER_STONE 21
#define BR_THUNDER_STONE 22
#define BR_LEAF_STONE 23
#define BR_MOON_STONE 24
#define BR_SUN_STONE 25
#define BR_SHINY_STONE 26
#define BR_DUSK_STONE 27
#define BR_DAWN_STONE 28
#define BR_ICE_STONE 29
//WHEN YOU ADD ANYTHING TO THE THREE ABOVE GROUPS, YOU MUST ALSO ADJUST THE DEFINES FOR THE
//NUM RECIPES IN include/constants/vars.h. THIS MAKES IT POSSIBLE FOR SCRIPT TO READ THEM

//recipe to item mapping
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
        {ITEM_FIRE_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_WATER_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_WATER_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_THUNDER_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_ELECTRIC_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_LEAF_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_GRASS_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_MOON_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_GHOST_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_SUN_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_PSYCHIC_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_SHINY_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_FAIRY_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_DUSK_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_DARK_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_DAWN_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_NORMAL_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
    [BR_ICE_STONE] = {
        {ITEM_POWER_HERB, 1},
        {ITEM_SOFT_SAND, 1},
        {ITEM_ICE_GEM, 0},
        {ITEM_NONE, 0},
        {ITEM_NONE, 0}
    },
};
