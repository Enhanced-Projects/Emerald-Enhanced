#include "global.h"
#include "main.h"
#include "event_data.h"
#include "ach_atlas.h"

const u16 sAP_Requirements[][2] = {
    {AP_SPRINT_BOOST, 51},
    {AP_GLOBAL_REPEL, 51},
    {AP_TRAINER_REPEL, 51},
    {AP_LOOTING, 51},
    {AP_MOBILE_STAT_CHECKER, 33},
    {AP_PDA, 33},
    {AP_WINNINGS_BOOST, 25},
    {AP_CAPTURE_BOOST, 10},
};

void APDebugInfo(void)
{
    VarSet(VAR_TEMP_1, (GetPlayerAPMax()));
    VarSet(VAR_TEMP_2, (GetCurrentAPUsed()));
}

int GetCurrentAPUsed(void)//gets player's currently used AP's
{
    u8 i;
    u8 currentTotal = 0;

    for (i = 0; i < TOTAL_OBTAINABLE_ACHIEVEMENTS; i++)
    {
        if (CheckAPFlag(i) == TRUE)
            currentTotal += (sAP_Requirements[i][1]);
    }

    return currentTotal;
}


int GetPlayerAPMax(void)//checks how many achievements the player has and turns it into a percentage of maximum achivements obtained.
{
    u8 current = 0;
    u8 i = 0;

    for (i = 0; i < TOTAL_OBTAINABLE_ACHIEVEMENTS; i++)
        if (CheckAchievement(i) == TRUE)
            current++;

    current = ((current * 100) / TOTAL_OBTAINABLE_ACHIEVEMENTS);
    return current;
}

bool8 CheckCanIgnoreTrainers(void)
{
    if ((FlagGet(FLAG_TOBY_TRAINER_SIGHT) == 1) || (CheckAPFlag(AP_TRAINER_REPEL) == TRUE))
        return TRUE;

    return FALSE;
}

void SetAPFlag(u32 id)
{
    if(id > AP_FLAGS_COUNT)
        return;

    gSaveBlock2Ptr->achievementPowerFlags[id / 8] |= 1 << (id % 8);
    
}

bool32 CheckAPFlag(u32 id)
{
    if(id > AP_FLAGS_COUNT)
        return FALSE;

    return !!((gSaveBlock2Ptr->achievementPowerFlags[id / 8] >> (id % 8)) & 1);
}

void ClearAPFlag(u32 id)
{
    if(id > AP_FLAGS_COUNT)
        return;
        
    gSaveBlock2Ptr->achievementPowerFlags[id / 8] &= ~(1 << (id % 8));
}