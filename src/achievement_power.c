#include "global.h"
#include "main.h"
#include "event_data.h"
#include "ach_atlas.h"
#include "constants/items.h"
#include "item.h"

//platinum powers
const u8 sPlatinumLabel[] = _("Platinum");
const u8 sAPNameSprintBoost[] =     _("Sprint Boost");
const u8 sAPNameGlobalRepel[] =     _("Global Repel");
const u8 sAPNameTrainerRepel[] =    _("Trainer Repel");
const u8 sAPNameEVBoost[] =         _("Double EV Gain");

//gold powers
const u8 sGoldLabel[] = _("Gold");
const u8 sAPNameMobileStatCheck[] = _("Stat Device Access");
const u8 sAPNamePDA[] =             _("PDA Device Access");
const u8 sAPNameAlphaAura[] =       _("Alpha Aura");

//silver powers
const u8 sSilverLabel[] = _("Silver");
const u8 sAPNameWinningsBoost[] =   _("Winnings Boost");
const u8 sAPNameStrongerWildMons[]  = _("Stronger Wilds");

//copper powers
const u8 sCopperLabel[] = _("Copper");
const u8 sAPNameCaptureBoost[] = _("Capture Boost");
const u8 sAPNameNaturalTalent[] = _("Natural Talent");

//Descriptions
const u8 sSprintBoostAPDesc[] = _("Allows you to run twice as fast.");
const u8 sGlobalRepelAPDesc[] = _("Ignore all wild encounters.");
const u8 sTrainerRepelAPDesc[] = _("Ignore trainer sight.");
const u8 sEVBoostAPDesc[] = _("Earn double EV's in battle.");
const u8 sMobileStatCheckAPDesc[] = _("Grants the StatAssist item which\nlets you see your IV's and EV's.");
const u8 sPDAAPDesc[] = _("Grants the PDA item which\nlets you shop remotely.");
const u8 sWinningsBoostAPDesc[] = _("Gain 10 percent more money\nfrom winning battles.");
const u8 sCaptureBoostAPDesc[] = _("Boost your base capture rate by\n5 percent.");
const u8 sStrongerWildsAPDesc[] = _("Wild pokemon will scale to\nyour party instead of badges.");
const u8 sNaturalTalentAPDesc[] = _("You have the natural\nability to open secret bases.");
const u8 sAlphaAuraAPDesc[] = _("You are attacked more often\nby Boss pokemon in the area.");

static void DummyFunc(void);

const struct APInfoTier gAP_InfoPlat[] = 
{
    {AP_SPRINT_BOOST, sAPNameSprintBoost, sSprintBoostAPDesc, DummyFunc},
    {AP_GLOBAL_REPEL, sAPNameGlobalRepel, sGlobalRepelAPDesc, DummyFunc},
    {AP_TRAINER_REPEL, sAPNameTrainerRepel, sTrainerRepelAPDesc, DummyFunc},
    {AP_EV_BOOST, sAPNameEVBoost, sEVBoostAPDesc, DummyFunc},
};

const struct APInfoTier gAP_InfoGold[] = 
{
    {AP_MOBILE_STAT_CHECKER, sAPNameMobileStatCheck, sMobileStatCheckAPDesc, GiveTakeStatAssistItem},
    {AP_PDA, sAPNamePDA, sPDAAPDesc, GiveTakePDAItem},
    {AP_ALPHA_AURA, sAPNameAlphaAura, sAlphaAuraAPDesc, DummyFunc},
};

const struct APInfoTier gAP_InfoSilver[] = 
{
    {AP_WINNINGS_BOOST, sAPNameWinningsBoost, sWinningsBoostAPDesc, DummyFunc},
    {AP_STRONGER_WILDS, sAPNameStrongerWildMons, sStrongerWildsAPDesc, DummyFunc},
};

const struct APInfoTier gAP_InfoCopper[] = 
{
    {AP_CAPTURE_BOOST, sAPNameCaptureBoost, sCaptureBoostAPDesc, DummyFunc},
    {AP_NATURAL_TALENT, sAPNameNaturalTalent, sNaturalTalentAPDesc, DummyFunc},
};

const struct APInfo gAP_Info[4] =
{
    {gAP_InfoPlat, AP_TIER_PLATINUM, AP_PLATINUM_COUNT, 51},
    {gAP_InfoGold, AP_TIER_GOLD, AP_GOLD_COUNT, 34},
    {gAP_InfoSilver, AP_TIER_SILVER, AP_SILVER_COUNT, 26},
    {gAP_InfoCopper, AP_TIER_COPPER, AP_COPPER_COUNT, 10}
};

void APDebugInfo(void)
{
    VarSet(VAR_TEMP_1, (GetPlayerAPMax()));
    VarSet(VAR_TEMP_2, (GetCurrentAPUsed()));
}

int GetCurrentAPUsed(void)//gets player's currently used AP's
{
    u32 i, j;
    u8 currentTotal = 0;

    for (i = 0; i < 4; i++)
    {
        for(j = 0; j < gAP_Info[i].tierCount; j++)
        if (CheckAPFlag(gAP_Info[i].apInfo[j].apId) == TRUE)
            currentTotal += (gAP_Info[i].requiredAP);
    }

    return currentTotal;
}


int GetPlayerAPMax(void)//checks how many achievements the player has and turns it into a percentage of maximum achivements obtained.
{
    u8 current = 0;
    u32 i = 0;

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
static void DummyFunc(void)
{

}

bool8 CheckCanIgnoreTrainers(void)//Check if can ignore trainer sight
{
    if ((FlagGet(FLAG_TOBY_TRAINER_SIGHT) == 1) || (CheckAPFlag(AP_TRAINER_REPEL) == TRUE))
        return TRUE;

    return FALSE;
}

bool8 CheckIfAutolevelWilds(void) //checks if wilds should use autolevel for the AP
{
    if (CheckAPFlag(AP_STRONGER_WILDS) == TRUE)
        return TRUE;

    return FALSE;
}

void ToggleAPStrongerWilds(void) //Allows wild mons to use autolevel, for faster training.
{
    if (CheckAPFlag(AP_STRONGER_WILDS) == TRUE)
        ClearAPFlag(AP_STRONGER_WILDS);
    else
        SetAPFlag(AP_STRONGER_WILDS);
}

void GiveTakePDAItem(void)//gives the pda item when ap is active, You need to set/clear the flag in the function that calls this one.
{
    if (CheckAPFlag(AP_PDA) == TRUE)
        AddBagItem(ITEM_PDA, 1);
    else
        RemoveBagItem(ITEM_PDA, 1);
}

void GiveTakeStatAssistItem(void)//gives the pda item when ap is active. You need to set the AP flag in the function that calls this one.
{
    if (CheckAPFlag(AP_MOBILE_STAT_CHECKER) == TRUE)
        AddBagItem(ITEM_STATASSIST, 1);
    else
        RemoveBagItem(ITEM_STATASSIST, 1);
}

// @pidgey do i even need these?

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

void APNaturalTalentToggle(void) 
{
    if (CheckAPFlag(AP_NATURAL_TALENT) == TRUE)
        ClearAPFlag(AP_NATURAL_TALENT);
    else
        SetAPFlag(AP_NATURAL_TALENT);    
}
