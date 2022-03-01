#ifndef GUARD_LIFESKILL_H
#define GUARD_LIFESKILL_H

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

#define NUM_PICKUP_TABLE_ENTRIES 18

typedef struct Ingredient {
  u16 itemId;
  u8 quantity;
} Ingredient;


typedef struct AlchemyRecipe {
  u16 expGiven;
  Ingredient ingredients[3];
  u16 metal;
  u16 metalDustAmt;
  u8 requiredLevel;
  u8 givenCharges;
} AlchemyRecipe;

extern const u16 gGemTier3[];
extern const u16 gGemTier2[];
extern const u16 gGemTier1[];
extern const u16 gRyuLowPickupTable[];
extern const u16 gRyuMedPickupTable[];
extern const u16 gRyuHighPickupTable[];
extern const u16 gRyuMaxPickupTable[];
extern const u16 gFossilTable[];
extern const u16 gShardOreTable[];
extern const u16 gInsideMiningTier1[];
extern const u16 gInsideMiningTier2[];
extern const u16 gInsideMiningTier3[];
extern const u16 gOutsideMapSecs[];
extern const u16 gOutsideMiningTier1[];
extern const u16 gOutsideMiningTier2[];
extern const u16 gOutsideMiningTier3[];
extern const u16 gBotanyRewardTables[NUM_BOTANY_MAP_CATEGORIES][10];
extern const u16 gBotanyTreeRewards[];
extern const u16 sBotanyRecipeToItemId[NUM_RECIPES];
extern const u16 sBotanyRecipes[NUM_RECIPES][NUM_INGREDIENTS_PER_RECIPE][2];
extern const AlchemyRecipe gAlchemyRecipes[NUM_ALCHEMY_RECIPES];

#endif//GUARD_LIFESKILL_H