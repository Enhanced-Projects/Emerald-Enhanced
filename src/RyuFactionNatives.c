#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "constants/event_objects.h"
#include "string_util.h"
#include "region_map.h"
#include "constants/items.h"
#include "item.h"
#include "DynamicObjects.h"

const u16 gRyuEggHatchFactionsQuestTable[8][5] ={
    [FACTION_NATURALISTS] = {SPECIES_SEEDOT, SPECIES_SUNKERN, SPECIES_SNIVY, SPECIES_PIDGEY, SPECIES_ZIGZAGOON},
    [FACTION_STUDENTS] = {SPECIES_POOCHYENA, SPECIES_BUNEARY, SPECIES_ROCKRUFF, SPECIES_CATERPIE, SPECIES_MARILL},
    [FACTION_NOBLES] = {SPECIES_TRAPINCH, SPECIES_MEOWTH, SPECIES_MUDKIP, SPECIES_POPPLIO, SPECIES_PIKIPEK},
    [FACTION_POKEFANS] = {SPECIES_PIKACHU, SPECIES_PICHU, SPECIES_MINUN, SPECIES_JOLTIK, SPECIES_TEDDIURSA},
    [FACTION_OUTCASTS] = {SPECIES_GASTLY, SPECIES_MAWILE, SPECIES_SABLEYE, SPECIES_SNORUNT, SPECIES_TENTACOOL},
    [FACTION_PROFESSIONALS] = {SPECIES_ELEKID, SPECIES_MAGBY, SPECIES_ZANGOOSE, SPECIES_ELECTRIKE, SPECIES_NUMEL},
    [FACTION_POKEMON_LEAGUE] = {0,0,0,0,0},
    [FACTION_OTHERS] = {0,0,0,0,0},
};

const u16 gRyuPotentialMapsecsForEscort[] = {
    MAPSEC_LILYCOVE_TRAINING_CENTER,
    MAPSEC_VERDANTURF_TOWN,
    MAPSEC_ROUTE_110,
    MAPSEC_RUSTURF_TUNNEL,
    MAPSEC_FALLARBOR_TOWN,
    MAPSEC_SLATEPORT_CITY,
    MAPSEC_BANANA_SLAKOTH_GARDEN,
    MAPSEC_EMBER_SPA,
    MAPSEC_PETALBURG_CITY,
    MAPSEC_PETALBURG_WOODS
};

const u16 gRyuPotentialObjectsForEscort[] = {
    OBJ_EVENT_GFX_EXPERT_F,
    OBJ_EVENT_GFX_PSYCHIC_M,
    OBJ_EVENT_GFX_LASS,
    OBJ_EVENT_GFX_GIRL_2,
    OBJ_EVENT_GFX_CAMPER,
    OBJ_EVENT_GFX_BUG_CATCHER,
    OBJ_EVENT_GFX_BEAUTY,
    OBJ_EVENT_GFX_POKEFAN_F
};

const u16 gRyuEscortRewardsTable[] = {// 70/30 split for token reward.
    ITEM_TRAINING_TOKEN,
    ITEM_TRAINING_TOKEN,
    ITEM_TRAINING_TOKEN,
    ITEM_TRAINING_TOKEN,
    ITEM_TRAINING_TOKEN,
    ITEM_TRAINING_TOKEN,
    ITEM_TRAINING_TOKEN,
    ITEM_GROOMING_TOKEN,
    ITEM_GROOMING_TOKEN,
    ITEM_GROOMING_TOKEN
};

void RyuSetupEggHatchQuest(void)
{
    u8 faction = VarGet(VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION);
    u8 whichEgg = gSpecialVar_Result;
    u16 eggSpecies = gRyuEggHatchFactionsQuestTable[faction][whichEgg];
    VarSet(VAR_RYU_DAILY_QUEST_TARGET, eggSpecies);
}


void RyuSetupPokefansEscortQuest(void)
{
    u16 location = (Random() % (ARRAY_COUNT(gRyuPotentialMapsecsForEscort)));
    u16 person = gRyuPotentialObjectsForEscort[(Random() % (ARRAY_COUNT(gRyuPotentialObjectsForEscort)))];
    VarSet(VAR_RYU_POKEFANS_LOCID, location);
    VarSet(VAR_RYU_POKEFANS_OBJID, person);
    StringCopy(gStringVar1, gRegionMapEntries[location].name);
}

void RyuRandomizeEscortReward(void)
{
    u16 reward = VarGet(VAR_RYU_POKEFANS_REWID);
    VarSet(VAR_RYU_POKEFANS_REWID, gRyuEscortRewardsTable[reward]);
}

void RyuBufferPokefansTarget(void)
{
    u16 loc = VarGet(VAR_RYU_POKEFANS_LOCID);
    StringCopy(gStringVar1, gRegionMapEntries[loc].name);
}
extern int RyuGetCurrentMapsec(void);

bool32 checkEscortMission(void)
{
    if (VarGet(VAR_RYU_POKEFANS_LOCID) == RyuGetCurrentMapsec())
        return TRUE;
    return FALSE;
}

void RyuClearTemporaryPokefansEscortObject(void)
{
    u16 id = (VarGet(VAR_RYU_POKEFANS_LOCID));
    RemoveDynamicObject(id);
}
