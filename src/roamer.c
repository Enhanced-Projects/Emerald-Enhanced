#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "constants/maps.h"

static const u8 sRoamerLocations = 0;

void ClearRoamerData(void){}

void ClearRoamerLocationData(void){}

static void CreateInitialRoamerMon(bool16 createLatios){}

void InitRoamer(void){}

void UpdateLocationHistoryForRoamer(void){}

void RoamerMoveToOtherLocationSet(void){}

void RoamerMove(void){}

bool8 IsRoamerAt(u8 mapGroup, u8 mapNum)
{
    return FALSE;
}

void CreateRoamerMonInstance(void){}

bool8 TryStartRoamerEncounter(void)
{
    return FALSE;
}

void UpdateRoamerHPStatus(struct Pokemon *mon){}

void SetRoamerInactive(void){}

void GetRoamerLocation(u8 *mapGroup, u8 *mapNum){}
