#include "global.h"
#include "wild_encounter.h"
#include "pokemon.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "random.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "safari_zone.h"
#include "overworld.h"
#include "pokeblock.h"
#include "battle_setup.h"
#include "battle_main.h"
#include "roamer.h"
#include "tv.h"
#include "link.h"
#include "script.h"
#include "battle_debug.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "constants/abilities.h"
#include "constants/battle_config.h"
#include "constants/game_stat.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/maps.h"
#include "field_message_box.h"
#include "strings.h"
#include "constants/weather.h"
#include "autoscale_tables.h"
#include "constants/metatile_behaviors.h"

extern const u8 EventScript_RepelWoreOff[];
extern int CountBadges();

#define NUM_FEEBAS_SPOTS    6

// this file's functions
static u16 FeebasRandom(void);
static void FeebasSeedRng(u16 seed);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *encRate);
static void ApplyCleanseTagEncounterRateMod(u32 *encRate);
static bool8 TryGetAbilityInfluencedWildMonIndexFromTable(const struct WildPokemon *wildMon, u8 *monIndex, u8 encounterType);
static bool8 IsAbilityAllowingEncounter(u8 level);

// EWRAM vars
EWRAM_DATA static u8 sWildEncountersDisabled = 0;
EWRAM_DATA bool8 gIsFishingEncounter = 0;
EWRAM_DATA bool8 gIsSurfingEncounter = 0;
EWRAM_DATA static u32 sFeebasRngValue = 0;

#include "data/wild_encounters.h"

//Special Feebas-related data.
const struct WildPokemon gWildFeebasRoute119Data = {20, 25, SPECIES_FEEBAS};

const u16 gRoute119WaterTileData[] =
{
    0, 0x2D, 0,
    0x2E, 0x5B, 0x83,
    0x5C, 0x8B, 0x12A,
};

// code
void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

static u16 GetRoute119WaterTileNum(s16 x, s16 y, u8 section)
{
    u16 xCur;
    u16 yCur;
    u16 yMin = gRoute119WaterTileData[section * 3 + 0];
    u16 yMax = gRoute119WaterTileData[section * 3 + 1];
    u16 tileNum = gRoute119WaterTileData[section * 3 + 2];

    for (yCur = yMin; yCur <= yMax; yCur++)
    {
        for (xCur = 0; xCur < gMapHeader.mapLayout->width; xCur++)
        {
            u8 tileBehaviorId = MapGridGetMetatileBehaviorAt(xCur + 7, yCur + 7);
            if (MetatileBehavior_IsSurfableAndNotWaterfall(tileBehaviorId) == TRUE)
            {
                tileNum++;
                if (x == xCur && y == yCur)
                    return tileNum;
            }
        }
    }
    return tileNum + 1;
}

static bool8 CheckFeebas(void)
{
    u8 i;
    u16 feebasSpots[NUM_FEEBAS_SPOTS];
    s16 x;
    s16 y;
    u8 route119Section = 0;
    u16 waterTileNum;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE119)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE119))
    {
        GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
        x -= 7;
        y -= 7;

        if (y >= gRoute119WaterTileData[3 * 0 + 0] && y <= gRoute119WaterTileData[3 * 0 + 1])
            route119Section = 0;
        if (y >= gRoute119WaterTileData[3 * 1 + 0] && y <= gRoute119WaterTileData[3 * 1 + 1])
            route119Section = 1;
        if (y >= gRoute119WaterTileData[3 * 2 + 0] && y <= gRoute119WaterTileData[3 * 2 + 1])
            route119Section = 2;

        if (Random() % 100 > 49) // 50% chance of encountering Feebas
            return FALSE;

        FeebasSeedRng(gSaveBlock1Ptr->easyChatPairs[0].unk2);
        for (i = 0; i != NUM_FEEBAS_SPOTS;)
        {
            feebasSpots[i] = FeebasRandom() % 447;
            if (feebasSpots[i] == 0)
                feebasSpots[i] = 447;
            if (feebasSpots[i] < 1 || feebasSpots[i] >= 4)
                i++;
        }
        waterTileNum = GetRoute119WaterTileNum(x, y, route119Section);
        for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
        {
            if (waterTileNum == feebasSpots[i])
                return TRUE;
        }
    }
    return FALSE;
}

static u16 FeebasRandom(void)
{
    sFeebasRngValue = ISO_RANDOMIZE2(sFeebasRngValue);
    return sFeebasRngValue >> 16;
}

static void FeebasSeedRng(u16 seed)
{
    sFeebasRngValue = seed;
}

u8 ChooseWildMonIndex_Land(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        return 0;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        return 1;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        return 2;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        return 3;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        return 4;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        return 5;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        return 6;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        return 7;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        return 8;
    else if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 9;
    else if (rand == ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 10;
    else
        return 11;
}

u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        return 0;
    else if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        return 1;
    else if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        return 2;
    else if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        return 3;
    else
        return 4;
}

static u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    u8 rand = Random() % max(
        max(
            ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL,
            ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL
        ),
        ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL
    );

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand == ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 9;
        break;
    }
    return wildMonIndex;
}

u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == 0xFF)
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId > 8)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }

            return i;
        }
    }

    return -1;
}

static u8 PickWildMonNature(void)
{
    u8 i;
    u8 j;
    struct Pokeblock *safariPokeblock;
    u8 natures[NUM_NATURES];

    if (GetSafariZoneFlag() == TRUE && Random() % 100 < 80)
    {
        safariPokeblock = SafariZoneGetActivePokeblock();
        if (safariPokeblock != NULL)
        {
            for (i = 0; i < NUM_NATURES; i++)
                natures[i] = i;
            for (i = 0; i < NUM_NATURES - 1; i++)
            {
                for (j = i + 1; j < NUM_NATURES; j++)
                {
                    if (Random() & 1)
                    {
                        u8 temp;
                        SWAP(natures[i], natures[j], temp);
                    }
                }
            }
            for (i = 0; i < NUM_NATURES; i++)
            {
                if (PokeblockGetGain(natures[i], safariPokeblock) > 0)
                    return natures[i];
            }
        }
    }
    // check synchronize for a pokemon with the same ability
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_SYNCHRONIZE
        && ((B_SYNCHRONIZE_NATURE >= GEN_8) || Random() % 2 == 0))
    {
        return GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY) % NUM_NATURES;
    }

    // random nature
    return Random() % NUM_NATURES;
}

u32 RyuChooseWildLevel(void)
{
    return RyuChooseLevel(
        CountBadges(),
        FALSE,
        SCALING_TYPE_WILD,
        // The value is only used in NG+, so we can skip the calculation in the normal playthrough.
        FlagGet(FLAG_RYU_ISNGPLUS) ? CalculatePlayerPartyStrength() : 0
    );
}

void CreateWildMon(u16 species, u8 level)
{
    bool32 checkCuteCharm;

    ZeroEnemyPartyMons();
    checkCuteCharm = TRUE;

    switch (gBaseStats[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        checkCuteCharm = FALSE;
        break;
    }

    if (checkCuteCharm
        && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_CUTE_CHARM
        && Random() % 3 != 0)
    {
        u16 leadingMonSpecies = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
        u32 leadingMonPersonality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
        u8 gender = GetGenderFromSpeciesAndPersonality(leadingMonSpecies, leadingMonPersonality);

        // misses mon is genderless check, although no genderless mon can have cute charm as ability
        if (gender == MON_FEMALE)
            gender = MON_MALE;
        else
            gender = MON_FEMALE;

        CreateMonWithGenderNatureLetter(&gEnemyParty[0], species, level, 32, gender, PickWildMonNature(), 0);
        return;
    }

    CreateMonWithNature(&gEnemyParty[0], species, level, 32, PickWildMonNature());
}

enum
{
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

#define WILD_CHECK_REPEL    0x1
#define WILD_CHECK_KEEN_EYE 0x2

/*
 * Entry structure is as follows:
 * {
 *   {
 *     <type attracted on land>,
 *     <type attracted in water>,
 *   },
 *   TRUE to signal that this entry was set explicitly
 * }
 *
 * Most of the entries in this array are not initialized and therefore default to:
 * {{0, 0}, {0, 0}}
 * which translates to
 * {{TYPE_NORMAL, TYPE_NORMAL}, {FALSE, FALSE}}
 * By setting the boolean in the second array to TRUE,
 * we can differentiate between abilities that attract normal pokemon and uninitialized values.
 *
 * If we ever run out of memory, the size of this can be decreased by 25% by making it u8[ABILITIES_COUNT][3]
 * and storing the boolean in that third field instead of having an additional dimension.
 */
static const u8 sTypeAttractionTable[ABILITIES_COUNT][2][2] =
{
        [ABILITY_NORMALIZE] = {{TYPE_NORMAL, TYPE_NONE}, {TRUE}},
        [ABILITY_SIMPLE] = {{TYPE_NORMAL, TYPE_NONE}, {TRUE}},
        [ABILITY_DROUGHT] = {{TYPE_FIRE, TYPE_NONE}, {TRUE}},
        [ABILITY_BLAZE] = {{TYPE_FIRE, TYPE_NONE}, {TRUE}},
        [ABILITY_FLASH_FIRE] = {{TYPE_FIRE, TYPE_NONE}, {TRUE}},
        [ABILITY_DRIZZLE] = {{TYPE_WATER, TYPE_WATER}, {TRUE}},
        [ABILITY_DAMP] = {{TYPE_WATER, TYPE_WATER}, {TRUE}},
        [ABILITY_STORM_DRAIN] = {{TYPE_WATER, TYPE_WATER}, {TRUE}},
        [ABILITY_FLOWER_VEIL] = {{TYPE_GRASS, TYPE_NONE}, {TRUE}},
        [ABILITY_HARVEST] = {{TYPE_GRASS, TYPE_NONE}, {TRUE}},
        [ABILITY_OVERGROW] = {{TYPE_GRASS, TYPE_NONE}, {TRUE}},
        [ABILITY_GRASSY_SURGE] = {{TYPE_GRASS, TYPE_NONE}, {TRUE}},
        [ABILITY_STATIC] = {{TYPE_ELECTRIC, TYPE_ELECTRIC}, {TRUE}},
        [ABILITY_LIGHTNING_ROD] = {{TYPE_ELECTRIC, TYPE_ELECTRIC}, {TRUE}},
        [ABILITY_ELECTRIC_SURGE] = {{TYPE_ELECTRIC, TYPE_ELECTRIC}, {TRUE}},
        [ABILITY_SNOW_WARNING] = {{TYPE_ICE, TYPE_ICE}, {TRUE}},
        [ABILITY_REFRIGERATE] = {{TYPE_ICE, TYPE_ICE}, {TRUE}},
        [ABILITY_SCRAPPY] = {{TYPE_FIGHTING, TYPE_NONE}, {TRUE}},
        [ABILITY_DEFIANT] = {{TYPE_FIGHTING, TYPE_NONE}, {TRUE}},
        [ABILITY_HUSTLE] = {{TYPE_FIGHTING, TYPE_NONE}, {TRUE}},
        [ABILITY_STENCH] = {{TYPE_POISON, TYPE_POISON}, {TRUE}},
        [ABILITY_POISON_TOUCH] = {{TYPE_POISON, TYPE_POISON}, {TRUE}},
        [ABILITY_SAND_FORCE] = {{TYPE_GROUND, TYPE_GROUND}, {TRUE}},
        [ABILITY_EARLY_BIRD] = {{TYPE_FLYING, TYPE_FLYING}, {TRUE}},
        [ABILITY_AERILATE] = {{TYPE_FLYING, TYPE_FLYING}, {TRUE}},
        [ABILITY_TELEPATHY] = {{TYPE_PSYCHIC, TYPE_PSYCHIC}, {TRUE}},
        [ABILITY_PSYCHIC_SURGE] = {{TYPE_PSYCHIC, TYPE_PSYCHIC}, {TRUE}},
        [ABILITY_SWARM] = {{TYPE_BUG, TYPE_BUG}, {TRUE}},
        [ABILITY_SAND_STREAM] = {{TYPE_ROCK, TYPE_ROCK}, {TRUE}},
        [ABILITY_SHADOW_TAG] = {{TYPE_GHOST, TYPE_GHOST}, {TRUE}},
        [ABILITY_CURSED_BODY] = {{TYPE_GHOST, TYPE_GHOST}, {TRUE}},
        [ABILITY_STEELY_RESOLVE] = {{TYPE_DRAGON, TYPE_NONE}, {TRUE}},
        [ABILITY_PRANKSTER] = {{TYPE_DARK, TYPE_NONE}, {TRUE}},
        [ABILITY_BAD_DREAMS] = {{TYPE_DARK, TYPE_NONE}, {TRUE}},
        [ABILITY_DARK_AURA] = {{TYPE_DARK, TYPE_NONE}, {TRUE}},
        [ABILITY_MAGNET_PULL] = {{TYPE_STEEL, TYPE_STEEL}, {TRUE}},
        [ABILITY_PIXILATE] = {{TYPE_FAIRY, TYPE_FAIRY}, {TRUE}},
        [ABILITY_SWEET_VEIL] = {{TYPE_FAIRY, TYPE_FAIRY}, {TRUE}},
        [ABILITY_MISTY_SURGE] = {{TYPE_FAIRY, TYPE_FAIRY}, {TRUE}},
        [ABILITY_FAIRY_AURA] = {{TYPE_FAIRY, TYPE_FAIRY}, {TRUE}}
};

static bool8 TryGenerateWildMon(const struct WildPokemonInfo *wildMonInfo, u8 area, u8 flags)
{
    u8 wildMonIndex = 0;
    u8 level = RyuChooseWildLevel();
    u8 ability = 2;

    switch (area)
    {
    case WILD_AREA_LAND:
        if (TryGetAbilityInfluencedWildMonIndexFromTable(wildMonInfo->wildPokemon, &wildMonIndex, area))
            break;
        wildMonIndex = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        if (TryGetAbilityInfluencedWildMonIndexFromTable(wildMonInfo->wildPokemon, &wildMonIndex, area))
            break;
        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    case WILD_AREA_ROCKS:
        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    }

    if (gMapHeader.mapLayoutId != LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;
  
    GenerateWildMonWithBossProbability(wildMonInfo->wildPokemon[wildMonIndex].species, level, 128);

    return TRUE;
}

static void RyuGenerateBossMon(u16 species, u8 level)
    {
        u8 val[1] = {TRUE};
        u8 newAbility = Random() & 1;
        u8 iv = 31;
        u8 ability = 2;

        level = min(MAX_LEVEL, level + 5);
        FlagSet(FLAG_RYU_BOSS_WILD);
        CreateWildMon(species, level);
        ShowFieldMessage(gText_PowerfulWildAppears);
        SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &iv);
        SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &iv);
        SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &iv);
        SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &iv);
        SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &iv);
        SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &iv);
        SetMonData(&gEnemyParty[0], MON_DATA_LEVEL, &level);
        SetMonData(&gEnemyParty[0], MON_DATA_GIFT_RIBBON_7, val);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
        // If the pokemon has no hidden ability, set it to a random ability
        if (GetMonAbility(&gEnemyParty[0]) == ABILITY_NONE)
            SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &newAbility);

        // If the random ability was also none
        // (if the random ability was 1 but only one ability is defined),
        // set it to the default ability (whichever is defined at position 0)
        if (GetMonAbility(&gEnemyParty[0]) == ABILITY_NONE)
            SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, 0);
        
        CalculateMonStats(&gEnemyParty[0]);
    }

bool8 GenerateWildMonWithBossProbability(u16 species, u8 level, u16 rarity) {
    if ((Random() % rarity == 0)
        )// || (FlagGet(FLAG_RYU_DEV_MODE) == 1)) 
    {
        RyuGenerateBossMon(species, level);
        return TRUE;
    }
        
    CreateWildMon(species, level);
    return FALSE;
}

static u16 GenerateFishingWildMon(const struct WildPokemonInfo *wildMonInfo, u8 rod)
{
    u8 wildMonIndex = ChooseWildMonIndex_Fishing(rod);
    u8 level = RyuChooseWildLevel();

    GenerateWildMonWithBossProbability(wildMonInfo->wildPokemon[wildMonIndex].species, level, 128);
    return wildMonInfo->wildPokemon[wildMonIndex].species;
}

static bool8 SetUpMassOutbreakEncounter(u8 flags)
{
    u16 i;

    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(gSaveBlock1Ptr->outbreakPokemonLevel))
        return FALSE;

    CreateWildMon(gSaveBlock1Ptr->outbreakPokemonSpecies, gSaveBlock1Ptr->outbreakPokemonLevel);
    for (i = 0; i < 4; i++)
        SetMonMoveSlot(&gEnemyParty[0], gSaveBlock1Ptr->outbreakPokemonMoves[i], i);

    return TRUE;
}

static bool8 DoMassOutbreakEncounterTest(void)
{
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != 0
     && gSaveBlock1Ptr->location.mapNum == gSaveBlock1Ptr->outbreakLocationMapNum
     && gSaveBlock1Ptr->location.mapGroup == gSaveBlock1Ptr->outbreakLocationMapGroup)
    {
        if (Random() % 100 < gSaveBlock1Ptr->outbreakPokemonProbability)
            return TRUE;
    }
    return FALSE;
}

static bool8 DoWildEncounterRateDiceRoll(u16 encounterRate)
{
    if (FlagGet(FLAG_RYU_DEV_DISENC) == 1)
        return FALSE;
    // Bug: This check might return a random number higher than the party lead,
    // but since it’s rerolled during encounter generation, we might get a lower number there,
    // so repel will sometimes not work properly.
    else if (
        VarGet(VAR_REPEL_STEP_COUNT) >= 1
        && RyuChooseWildLevel() < GetMonData(&gPlayerParty[0], MON_DATA_LEVEL)
    )
        return FALSE;
    else
        return (Random() % 2880) < encounterRate;
}

static bool8 DoWildEncounterRateTest(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (!ignoreAbility && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u32 ability = GetMonAbility(&gPlayerParty[0]);

        if (ability == ABILITY_STENCH && gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            encounterRate = encounterRate * 3 / 4;
        else if (ability == ABILITY_STENCH)
            encounterRate /= 2;
        else if (ability == ABILITY_ILLUMINATE)
            encounterRate *= 2;
        else if (ability == ABILITY_WHITE_SMOKE)
            encounterRate /= 2;
        else if (ability == ABILITY_ARENA_TRAP)
            encounterRate *= 2;
        else if (ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == WEATHER_SANDSTORM)
            encounterRate /= 2;
        else if (ability == ABILITY_SNOW_CLOAK && gSaveBlock1Ptr->weather == WEATHER_SNOW)
            encounterRate /= 2;
        else if (ability == ABILITY_QUICK_FEET)
            encounterRate /= 2;
        else if (ability == ABILITY_INFILTRATOR)
            encounterRate /= 2;
        else if (ability == ABILITY_NO_GUARD)
            encounterRate = encounterRate * 3 / 2;
    }
    if (encounterRate > 2880)
        encounterRate = 2880;
    return DoWildEncounterRateDiceRoll(encounterRate);
}

static bool8 DoGlobalWildEncounterDiceRoll(void)
{
    if (Random() % 100 >= 60)
        return FALSE;
    else
        return TRUE;
}

bool8 RyuCheckForDarkGrass(void)
{
    u16 pX = gSaveBlock1Ptr->location.x;
    u16 pY = gSaveBlock1Ptr->location.y;

    if (MapGridGetMetatileBehaviorAt(pX, pY) == MB_DARK_GRASS)
        return TRUE;
    return FALSE;
}

bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior)
{
    u16 headerId;
    struct Roamer *roamer;
    
    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == 0xFFFF)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            else if (DoWildEncounterRateTest(gBattlePikeWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;
            else if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;

            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            else if (DoWildEncounterRateTest(gBattlePyramidWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(currMetaTileBehavior) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;
            else if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            else if (DoWildEncounterRateTest(gWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (FlagGet(FLAG_RYU_DEV_DISENC) == 1)
                    return FALSE;
                else if (
                    VarGet(VAR_REPEL_STEP_COUNT)
                    && RyuChooseWildLevel() < GetMonData(&gPlayerParty[0], MON_DATA_LEVEL)
                )
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else
            {
                if (DoMassOutbreakEncounterTest() == TRUE && SetUpMassOutbreakEncounter(WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                // try a regular wild land encounter
                if (TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    if (TryDoDoubleWildBattle() && (RyuCheckForDarkGrass() == TRUE) && (Random() % 100 >= 50))
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                        BattleSetup_StartWildBattle();
                    return TRUE;
                }
                return FALSE;
            }
        }
        else if (MetatileBehavior_IsWaterWildEncounter(currMetaTileBehavior) == TRUE
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridge(currMetaTileBehavior) == TRUE))
        {
            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;
            else if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            else if (DoWildEncounterRateTest(gWildMonHeaders[headerId].waterMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(RyuChooseWildLevel()))
                    return FALSE;
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    if (TryDoDoubleWildBattle())
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                    {
                        BattleSetup_StartWildBattle();
                    }
                    return TRUE;
                }
                return FALSE;
            }
        }
    }

    return FALSE;
}

void RockSmashWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].rockSmashMonsInfo;

        if (wildPokemonInfo == NULL)
            gSpecialVar_Result = FALSE;
        else if (DoWildEncounterRateTest(wildPokemonInfo->encounterRate, 1) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, 2, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
            gSpecialVar_Result = FALSE;
    }
    else
        gSpecialVar_Result = FALSE;
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u16 headerId;

    PlayerGetDestCoords(&x, &y);
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == 0xFFFF)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            if (DoMassOutbreakEncounterTest() == TRUE)
                SetUpMassOutbreakEncounter(0);
            else
                TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0);

            BattleSetup_StartWildBattle();
            return TRUE;
        }
        else if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, 0);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF && gWildMonHeaders[headerId].fishingMonsInfo != NULL)
        return TRUE;
    else
        return FALSE;
}

void FishingWildEncounter(u8 rod)
{
    u16 species;

    if (CheckFeebas() == TRUE)
    {
        u8 level = RyuChooseWildLevel();
        species = gWildFeebasRoute119Data.species;
        CreateWildMon(species, level);
    }
    else
    {
        species = GenerateFishingWildMon(gWildMonHeaders[GetCurrentMapWildMonHeaderId()].fishingMonsInfo, rod);
    }
    IncrementGameStat(GAME_STAT_FISHING_CAPTURES);
    SetPokemonAnglerSpecies(species);
    //gIsFishingEncounter = TRUE;
    BattleSetup_StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u16 headerId;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;

    *isWaterMon = FALSE;
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == 0xFFFF)
        return SPECIES_NONE;
    landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
    // Land Pokemon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    // Water Pokemon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    // Either land or water Pokemon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF)
    {
        const struct WildPokemonInfo *waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 steps;

    if (InBattlePike() || InBattlePyramid())
        return FALSE;
    if (InUnionRoom() == TRUE)
        return FALSE;

    steps = VarGet(VAR_REPEL_STEP_COUNT);

    if (steps != 0)
    {
        steps--;
        VarSet(VAR_REPEL_STEP_COUNT, steps);
        if (steps == 0)
        {
            ScriptContext1_SetupScript(EventScript_RepelWoreOff);
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!VarGet(VAR_REPEL_STEP_COUNT))
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            u8 ourLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);

            if (wildLevel < ourLevel)
                return FALSE;
            else
                return TRUE;
        }
    }

    return FALSE;
}

static bool8 IsAbilityAllowingEncounter(u8 level)
{
    u8 ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

// Mutable static to avoid reallocations.
// Only used in the function below.
static u8 validIndicesForWildMonByType[max(LAND_WILD_COUNT, WATER_WILD_COUNT)];

static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, u8 type, u8 numMons, u8 *monIndex)
{
    u8 validMonCount, currentMon;
    // zero the relevant portion of the array before reuse
    for (currentMon = 0; currentMon < numMons; currentMon++)
    {
        validIndicesForWildMonByType[currentMon] = 0;
    }

    for (validMonCount = 0, currentMon = 0; currentMon < numMons; currentMon++)
    {
        if (gBaseStats[wildMon[currentMon].species].type1 == type || gBaseStats[wildMon[currentMon].species].type2 == type)
            validIndicesForWildMonByType[validMonCount++] = currentMon;
    }

    if (validMonCount == 0 || validMonCount == numMons)
        return FALSE;

    *monIndex = validIndicesForWildMonByType[Random() % validMonCount];
    return TRUE;
}

static const u8 sWildCount[] =
{
    LAND_WILD_COUNT,
    WATER_WILD_COUNT,
    ROCK_WILD_COUNT,
    FISH_WILD_COUNT
};

// Returns true if monIndex has been mutated.
static bool8 TryGetAbilityInfluencedWildMonIndexFromTable(const struct WildPokemon *wildMon, u8 *monIndex, u8 encounterType)
{
    u32 ability = GetMonAbility(&gPlayerParty[0]);
    u8 attractedType = sTypeAttractionTable[ability][0][encounterType];
    u8 currentAbilityDoesAttract = sTypeAttractionTable[ability][1][0];

    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return FALSE;
    if (attractedType == TYPE_NONE || currentAbilityDoesAttract == FALSE)
        return FALSE;
    if (Random() % 2 != 0)
        return FALSE;

    return TryGetRandomWildMonIndexByType(wildMon, attractedType, sWildCount[encounterType], monIndex);
}

static void ApplyFluteEncounterRateMod(u32 *encRate)
{
    if (FlagGet(FLAG_SYS_ENC_UP_ITEM) == TRUE)
        *encRate += *encRate / 2;
    else if (FlagGet(FLAG_SYS_ENC_DOWN_ITEM) == TRUE)
        *encRate = *encRate / 2;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encRate)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM) == ITEM_CLEANSE_TAG)
        *encRate = *encRate * 2 / 3;
}

u8 ChooseHiddenMonIndex(void)
{
    #ifdef ENCOUNTER_CHANCE_HIDDEN_MONS_TOTAL
        u8 rand = Random() % ENCOUNTER_CHANCE_HIDDEN_MONS_TOTAL;

        if (rand < ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_0)
            return 0;
        else if (rand >= ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_1)
            return 1;
        else
            return 2;
    #else
        return 0xFF;
    #endif
}

bool8 TryDoDoubleWildBattle(void)
{
    if (GetSafariZoneFlag() || GetMonsStateToDoubles() != PLAYER_HAS_TWO_USABLE_MONS)
        return FALSE;
    else if (B_FLAG_FORCE_DOUBLE_WILD != 0 && FlagGet(B_FLAG_FORCE_DOUBLE_WILD))
        return TRUE;
    #if B_DOUBLE_WILD_CHANCE != 0
    else if ((Random() % 100) + 1 < B_DOUBLE_WILD_CHANCE)
        return TRUE;
    #endif
    return FALSE;
}
