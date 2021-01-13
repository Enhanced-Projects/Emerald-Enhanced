#include "global.h"
#include "main.h"
#include "event_data.h"
#include "ach_atlas.h"
#include "constants/items.h"
#include "item.h"

//platinum powers
const u8 sPlatinumLabel[] = _("Platinum");
const u8 sExtendedAPNameSprintBoost[] =     _("Sprint Boost        ...51AP");
const u8 sExtendedAPNameGlobalRepel[] =     _("Ignore Wild Enc     ...51AP");
const u8 sExtendedAPNameTrainerRepel[] =    _("Ignore Trainers     ...51AP");
const u8 sExtendedAPNameEVBoost[] =         _("Double EV Gain      ...51AP");

//gold powers
const u8 sGoldLabel[] = _("Gold");
const u8 sExtendedAPNameMobileStatCheck[] = _("Stat Device Access  ...33AP");
const u8 sExtendedAPNamePDA[] =             _("PDA Device Access   ...33AP");

//silver powers
const u8 sSilverLabel[] = _("Silver");
const u8 sExtendedAPNameWinningsBoost[] =   _("Winnings Boost      ...33AP");

//copper powers
const u8 sCopperLabel[] = _("Copper");
const u8 sExtendedAPNameCaptureBoost[] =    _("Capture Boost       ...25AP");

//Descriptions
const u8 sSprintBoostAPDesc[] = _("Allows you to run twice as fast.");
const u8 sGlobalRepelAPDesc[] = _("Ignore all wild encounters.");
const u8 sTrainerRepelAPDesc[] = _("Ignore trainer sight.");
const u8 sEVBoostAPDesc[] = _("Earn double EV's in battle.");
const u8 sMobileStatCheckAPDesc[] = _("Grants the StatAssist item which\nlets you see your IV's and EV's.");
const u8 sPDAAPDesc[] = _("Grants the PDA item which\nlets you shop remotely.");
const u8 sWinningsBoostAPDesc[] = _("Gain 10 percent more money\nfrom winning battles.");
const u8 sCaptureBoostAPDesc[] = _("Boost your base capture rate by\n5 percent.");


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
