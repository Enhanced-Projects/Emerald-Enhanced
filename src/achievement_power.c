#include "global.h"
#include "main.h"
#include "event_data.h"
#include "ach_atlas.h"
#include "constants/items.h"
#include "item.h"

const u16 sAP_Requirements[][2] = {
    {AP_SPRINT_BOOST, 51},
    {AP_GLOBAL_REPEL, 51},
    {AP_TRAINER_REPEL, 51},
    {AP_EV_BOOST, 51},
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

//ap flag related
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

//actual ap powers
bool8 CheckCanIgnoreTrainers(void)//toggles trainer repel
{
    if ((FlagGet(FLAG_TOBY_TRAINER_SIGHT) == 1) || (CheckAPFlag(AP_TRAINER_REPEL) == TRUE))
        return TRUE;

    return FALSE;
}

void GiveTakePDAItem(void)//gives the pda item when ap is active, You need to set/clear the flag in the function that calls this one.
{
    if (CheckAPFlag(AP_PDA) == TRUE)
        AddBagItem(ITEM_PDA, 1);
    else
        RemoveBagItem(ITEM_PDA, 2);
}

void GiveTakeStatAssistItem(void)//gives the pda item when ap is active. You need to set the AP flag in the function that calls this one.
{
    if (CheckAPFlag(AP_MOBILE_STAT_CHECKER) == TRUE)
        AddBagItem(ITEM_STATASSIST, 1);
    else
        RemoveBagItem(ITEM_STATASSIST, 2);
}

void APGlobalRepelToggle(void) //toggles the global repel
{
    if (CheckAPFlag(AP_GLOBAL_REPEL) == TRUE)
        ClearAPFlag(AP_GLOBAL_REPEL);
    else
        SetAPFlag(AP_GLOBAL_REPEL);
}

void APTrainerRepelToggle(void)//toggles trainer repel
{
    if (CheckAPFlag(AP_TRAINER_REPEL) == TRUE)
        ClearAPFlag(AP_TRAINER_REPEL);
    else
        SetAPFlag(AP_TRAINER_REPEL);
}

void APSprintBoostToggle(void)//toggles sprint boost
{
    if (CheckAPFlag(AP_SPRINT_BOOST) == TRUE)
        ClearAPFlag(AP_SPRINT_BOOST);
    else
        SetAPFlag(AP_SPRINT_BOOST);
}

void APWinningsBoostToggle(void) //toggles winnings boost
{
    if (CheckAPFlag(AP_WINNINGS_BOOST) == TRUE)
        ClearAPFlag(AP_WINNINGS_BOOST);
    else
        SetAPFlag(AP_WINNINGS_BOOST);
}

void APCaptureBoostToggle(void) //toggles capture boost
{
    if (CheckAPFlag(AP_CAPTURE_BOOST) == TRUE)
        ClearAPFlag(AP_CAPTURE_BOOST);
    else
        SetAPFlag(AP_CAPTURE_BOOST);
}
