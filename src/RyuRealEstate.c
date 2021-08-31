#include "global.h"
#include "event_data.h"
#include "RyuRealEstate.h"
#include "string_util.h"
#include "constants/game_stat.h"
#include "overworld.h"
#include "money.h"
#include "script.h"
#include "random.h"
#include "main.h"
#include "ach_atlas.h"

//DAILY TASKS
void DoDailyRealEstateTasks(void)
{
    if (FlagGet(FLAG_RYU_PLAYER_HAS_BANK_ACCOUNT))
    {
        u32 balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
        if (!(balance <= 999)) //no reason to give interest if balance is under $1000
        {
            u32 interest = balance / 200; // 0.5% interest rate
            if (interest + balance < balance) // happens if balance is close to the integer limit and the interest causes it to overflow and wrap to 0
                return;
            SetGameStat(GAME_STAT_INTEREST_RECEIVED, interest); // saves the last earned interest amount, potentially could be more than 65k, so use 32bit number.
            SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, balance + interest);
            VarSet(VAR_RYU_DAYS_INTEREST_GAINED, (VarGet(VAR_RYU_DAYS_INTEREST_GAINED) + 1));
            FlagSet(FLAG_RYU_INTEREST_ACCRUED);
            
        }
    }

    if (gSaveBlock2Ptr->playerIsRealtor == TRUE)
    {
        if (FlagGet(FLAG_RYU_PROPERTY_DAMAGED) == FALSE)
            TryDamageproperties();

        CollectRent();
    }

    if (FlagGet(FLAG_RYU_PROPERTY_UNDERGOING_MAINTENANCE) == TRUE)
        DecrementPropertyRepairTime();
}

void RyuResetRealEstateData(void)
{
    gSaveBlock2Ptr->playerIsRealtor = 0;
    VarSet(VAR_RYU_PROPERTY_DAMAGE_TYPE, NUM_DAMAGE_TYPES);
    VarSet(VAR_RYU_PROPERTY_DAMAGE_DAYS, 0);
}

//PROPERTY RELATED

const u16 gRyuPropertyData[NUM_PROPERTIES][7] = { //property id, property value, property rent, map group(interior), map num(interior), warp num(interior), x, y
    [PROPERTY_DEWFORD   ] = {31000, 1550, 5, 7, 255, 3, 8},
    [PROPERTY_FALLARBOR ] = {19000,  950, 9, 16, 255, 3, 8},
    [PROPERTY_LILYCOVE  ] = {38000, 1900, 12, 26, 255, 3, 8},
    [PROPERTY_MAUVILLE  ] = {42000, 2100, 7, 10, 255, 3, 8},
    [PROPERTY_OLDALE    ] = {18000,  900, 2, 2, 255, 3, 8},
    [PROPERTY_ROUTE119  ] = {22000, 1100, 32, 4, 255, 3, 5},
    [PROPERTY_RUSTBURO  ] = {20000, 1000, 4, 20, 255, 4, 8},
    [PROPERTY_SLATEPORT ] = {34000, 1700, 6, 15, 255, 7, 8},
    [PROPERTY_SNOWYSHORE] = {32000, 1600, 27, 25, 155, 2, 7},
    [PROPERTY_SOOTOPOLIS] = {33000, 1650, 14, 16, 255, 3, 6},
    [PROPERTY_VERDANTURF] = {24000, 1200, 8, 9, 255, 5, 8},
    [PROPERTY_MOSSDEEP  ] = {30000, 1500, 13, 14, 255, 3, 8},
};

const u8 gRyuPropertyNames[NUM_PROPERTIES][22] = {
    [PROPERTY_DEWFORD]    = _("Dewford Island Home"),
    [PROPERTY_FALLARBOR]  = _("Fallarbor Town House"),
    [PROPERTY_LILYCOVE]   = _("Lilycove Peninsula"),
    [PROPERTY_MAUVILLE]   = _("Mauville Estate"),
    [PROPERTY_OLDALE]     = _("Oldale Cottage"),
    [PROPERTY_ROUTE119]   = _("Treetop Fort"),
    [PROPERTY_RUSTBURO]   = _("Rustburo Flat"),
    [PROPERTY_SLATEPORT]  = _("Slateport Condo"),
    [PROPERTY_SNOWYSHORE] = _("Snowy Shore Cottage"),
    [PROPERTY_SOOTOPOLIS] = _("Sootopolis Condo"),
    [PROPERTY_VERDANTURF] = _("Verdanturf Town House"),
    [PROPERTY_MOSSDEEP]   = _("Mossdeep Quay Home"),
};

const u16 gRyuPropertyDamageTable[NUM_DAMAGE_TYPES][2] = {//[type] = {cost, daystoFix}
    [DAMAGE_BROKEN_WINDOW]       = {2500, 1},
    [DAMAGE_DOORFRAME_BROKEN]    = {2000, 1},
    [DAMAGE_MINOR_ELECTRICAL]    = {4000, 2},
    [DAMAGE_WATER_MINOR]         = {1800, 2},
    [DAMAGE_LIGHTBULB_REPLACE]   = {400,  1},
    [DAMAGE_MINOR_MECHANICAL]    = {1000, 2},
    [DAMAGE_FLOOR]               = {500,  1},
    [DAMAGE_APPLIANCE_REPLACE]   = {5000, 1},
    [DAMAGE_ELECTRICAL_MODERATE] = {8000, 4},
    [DAMAGE_WATER_MODERATE]      = {5400, 4},
    [DAMAGE_MAJOR]               = {10000, 5},
};

const u8 gRyuDamageTypeNamesTable[NUM_DAMAGE_TYPES][26] = { //will be buffered with "a <PROBLEM>" e.g. Your property at {NAME} has a {broken door}
    [DAMAGE_BROKEN_WINDOW]       = _("broken window"),
    [DAMAGE_DOORFRAME_BROKEN]    = _("broken door"),
    [DAMAGE_MINOR_ELECTRICAL]    = _("minor electrical fault"),
    [DAMAGE_WATER_MINOR]         = _("minor water leak"),
    [DAMAGE_LIGHTBULB_REPLACE]   = _("blown lightbulb"),
    [DAMAGE_MINOR_MECHANICAL]    = _("minor mechanical issue"),
    [DAMAGE_FLOOR]               = _("damaged floor"),
    [DAMAGE_APPLIANCE_REPLACE]   = _("broken appliance"),
    [DAMAGE_ELECTRICAL_MODERATE] = _("moderate electrical issue"),
    [DAMAGE_WATER_MODERATE]      = _("broken water pipe"),
    [DAMAGE_MAJOR]               = _("serious issue"),
};

void TryDamageproperties(void)
{
    u8 val = (Random() % 99);
    u8 id = 0;
    u8 damageType = (Random() % NUM_DAMAGE_TYPES);
    u8 damageDays = gRyuPropertyDamageTable[damageType][0];
    u32 maxPropertyDamageChance = (70 + VarGet(VAR_RYU_NUM_OWNED_PROPERTIES));

    if (val < 60)
        return;

    if ((val > 59) && (val <= maxPropertyDamageChance))//damage a random property. (10% plus number of owned properties.)
        {
            do {//only damage a property that is owned by the player.
                id = (Random() % NUM_PROPERTIES);
             } while(CheckOwnedProperty(id) == FALSE);
            FlagSet(FLAG_RYU_PROPERTY_DAMAGED);
            VarSet(VAR_RYU_DAMAGED_HOUSE_ID, id);
            VarSet(VAR_RYU_PROPERTY_DAMAGE_TYPE, damageType);
            VarSet(VAR_RYU_PROPERTY_DAMAGE_DAYS, gRyuPropertyDamageTable[damageType][1]);
            FlagSet(FLAG_RYU_NOTIFY_PROPERTY_DAMAGE);
            VarSet(VAR_TEMP_D, id);
            FlagSet(FLAG_HIDE_MAP_NAME_POPUP);
        }
    else
        return;
}

void RyuBufferRealEstateDetails(void)
{
    u8 id = (VarGet(VAR_TEMP_D));
    u16 sellprice = ((gRyuPropertyData[id][0] / 3) * 2);
    ConvertIntToDecimalStringN(gStringVar1, gRyuPropertyData[id][0], STR_CONV_MODE_LEFT_ALIGN, 5);//value
    StringCopy(gStringVar2, gRyuPropertyNames[id]);//name of property
    ConvertIntToDecimalStringN(gStringVar3, sellprice, STR_CONV_MODE_LEFT_ALIGN, 5);//sale price
}

u16 RyuReturnPropertyValueFromID(u8 id)
{
    return gRyuPropertyData[id][0];
}

u16 RyuReturnPropertyRentFromID(u8 id)
{
    return gRyuPropertyData[id][1];
}

u16 CheckIfPlayerOwnsCurrentProperty(void)
{
    u8 id = VarGet(VAR_TEMP_D);
    bool8 owned = CheckOwnedProperty(id);
    bool8 rented = CheckRentedProperty(id);

    if (owned == FALSE)
        return 0;

    if ((owned == TRUE) && (rented == FALSE) && ((FlagGet(FLAG_RYU_HAS_HOME_REGISTERED) == TRUE) && (VarGet(VAR_RYU_PLAYER_HOUSE_ID) == id)))
        return 1; 
    
    if ((owned == TRUE) && (rented == FALSE))
        return 2;

    if ((owned == TRUE) && (rented == TRUE))
        return 3; //rented out
    
    return 4;
}

bool32 CheckOwnedProperty(u32 id)
{
    if(id > PLAYER_PROPERTIES_COUNT)
        return FALSE;

    return !!((gSaveBlock2Ptr->propertyFlags[id / 8] >> (id % 8)) & 1);
}

void RemoveProperty(u32 id)
{
    if(id > PLAYER_PROPERTIES_COUNT)
        return;

    VarSet(VAR_RYU_NUM_OWNED_PROPERTIES, (VarGet(VAR_RYU_NUM_OWNED_PROPERTIES) - 1));
    gSaveBlock2Ptr->propertyFlags[id / 8] &= ~(1 << (id % 8));
}

void ScriptSellProperty(void)
{
    u8 id = VarGet(VAR_TEMP_D);
    RemoveProperty(id);
    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) + ((gRyuPropertyData[id][0] / 3) * 2)));
}

void AddProperty(u32 id)
{
    if(id > PLAYER_PROPERTIES_COUNT)
        return;

    VarSet(VAR_RYU_NUM_OWNED_PROPERTIES, (VarGet(VAR_RYU_NUM_OWNED_PROPERTIES) + 1));
    gSaveBlock2Ptr->propertyFlags[id / 8] |= 1 << (id % 8);
}

bool32 CheckRentedProperty(u32 id)
{
    if(id > PLAYER_PROPERTIES_COUNT)
        return FALSE;

    return !!((gSaveBlock2Ptr->propertyRentedFlags[id / 8] >> (id % 8)) & 1);
}

void ScriptCheckRentedProperty(void)
{
    u8 id = VarGet(VAR_TEMP_D);
    gSpecialVar_Result = CheckRentedProperty(id);
}

void VacateProperty(u32 id)
{
    if(id > PLAYER_PROPERTIES_COUNT)
        return;
        
    gSaveBlock2Ptr->propertyRentedFlags[id / 8] &= ~(1 << (id % 8));
}

void ScriptVacateProperty(void)
{
    u8 id = VarGet(VAR_TEMP_D);

    VacateProperty(id);
}

void LeaseProperty(u32 id)
{
    if(id > PLAYER_PROPERTIES_COUNT)
        return;

    gSaveBlock2Ptr->propertyRentedFlags[id / 8] |= 1 << (id % 8);
    
}

void ScriptLeaseProperty(void)
{
    u8 id = VarGet(VAR_TEMP_D);

    LeaseProperty(id);
}

void CollectRent(void)
{
    u32 rent = 0;
    u32 balance = (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE));
    u8 i;

    for (i = 0; i < NUM_PROPERTIES; i++){
        if (CheckOwnedProperty(i) && CheckRentedProperty(i))
            rent += gRyuPropertyData[i][1];
    }

    SetGameStat(GAME_STAT_RENT_COLLECTED, rent); 
    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (balance + rent));

    FlagSet(FLAG_RYU_NOTIFY_RENT);
}

int RyuCheckPropertyStatus(void)
{
    u8 id = (VarGet(VAR_TEMP_D));
    bool8 playerOwned = (CheckOwnedProperty(id));
    bool8 playerLeased = (CheckRentedProperty(id));

    if (playerOwned == FALSE)
        return 0;

    if ((playerOwned == TRUE) && (playerLeased == FALSE))
        return 1;

    if ((playerOwned == TRUE) && (playerLeased == TRUE) && (FlagGet(FLAG_RYU_PROPERTY_DAMAGED) == TRUE) && (VarGet(VAR_RYU_DAMAGED_HOUSE_ID) == id))
        return 3;
    
    if ((playerOwned == TRUE) && (playerLeased == TRUE))
        return 2;
}

void RyuBufferOwnedPropertyDetails(void)
{
    u8 id = (VarGet(VAR_TEMP_D));
    const u8 sYesMsg[] = _("Yes");
    const u8 sNoMsg[] = _("No");

    if (CheckRentedProperty(id) == TRUE)
        StringCopy(gStringVar3, sYesMsg);
    else
        StringCopy(gStringVar3, sNoMsg);

    if (VarGet(VAR_RYU_PLAYER_HOUSE_ID) == 0xFFFF)
        StringCopy(gRyuStringVar1, sNoMsg);
    else if (VarGet(VAR_RYU_PLAYER_HOUSE_ID) == id)
        StringCopy(gRyuStringVar1, sYesMsg);
    else
       StringCopy(gRyuStringVar1, sNoMsg);

    if ((FlagGet(FLAG_RYU_PROPERTY_DAMAGED) == 1) && (VarGet(VAR_RYU_DAMAGED_HOUSE_ID) == id))
        StringCopy(gRyuStringVar2, sYesMsg);
    else
        StringCopy(gRyuStringVar2, sNoMsg);
}

bool8 CheckIfPlayerIsRealtor(void)
{
    return(gSaveBlock2Ptr->playerIsRealtor);
}

void SetPlayerRealtorStatus(void)
{
    gSaveBlock2Ptr->playerIsRealtor = TRUE;
    GiveAchievement(ACH_REALTOR);
    VarSet(VAR_RYU_QUESTS_FINISHED, (VarGet(VAR_RYU_QUESTS_FINISHED) + 1));
}

void DecrementPropertyRepairTime(void)
{
    u16 days = VarGet(VAR_RYU_PROPERTY_DAMAGE_DAYS);
    bool8 maintenance = FlagGet(FLAG_RYU_PROPERTY_UNDERGOING_MAINTENANCE);

    if ((days == 0) && (maintenance = TRUE))
    {
        FlagClear(FLAG_RYU_PROPERTY_DAMAGED);
        FlagClear(FLAG_RYU_PROPERTY_UNDERGOING_MAINTENANCE);
        VarSet(VAR_RYU_PROPERTY_DAMAGE_TYPE, NUM_DAMAGE_TYPES);
    }
    else
        VarSet(VAR_RYU_PROPERTY_DAMAGE_DAYS, (VarGet(VAR_RYU_PROPERTY_DAMAGE_DAYS) - 1));
}

void RyuBufferPropertyDamageData(void)
{
    u8 id = (VarGet(VAR_RYU_DAMAGED_HOUSE_ID));
    u8 damageType = VarGet(VAR_RYU_PROPERTY_DAMAGE_TYPE);
    mgba_printf(LOGINFO, "Property num %d, damage type %d", id, damageType);

    StringCopy(gStringVar2, gRyuPropertyNames[id]);// buffer property name
    StringCopy(gStringVar1, (gRyuDamageTypeNamesTable[damageType])); //buffer damage type string
    ConvertIntToDecimalStringN(gStringVar3, (gRyuPropertyDamageTable[damageType][0]), STR_CONV_MODE_LEFT_ALIGN, 5); //buffer property damage cost
    ConvertIntToDecimalStringN(gRyuStringVar1, VarGet(VAR_RYU_PROPERTY_DAMAGE_DAYS), STR_CONV_MODE_LEFT_ALIGN, 2); //buffer property days required to fix
}

void RyuRE_TakeMoney(void)
{
    u8 id = (VarGet(VAR_TEMP_D));

    RemoveMoney(&gSaveBlock1Ptr->money, (gRyuPropertyData[id][0]));
    AddProperty(id);
}

void RyuRE_TakeRepairMoney(void)
{
    u8 id = VarGet(VAR_TEMP_D);
    RemoveMoney(&gSaveBlock1Ptr->money, (gRyuPropertyDamageTable[VarGet(VAR_RYU_PROPERTY_DAMAGE_TYPE)][0]));
}

void RyuLoadRepairCost(void)
{
    VarSet(VAR_TEMP_9, (gRyuPropertyDamageTable[VarGet(VAR_RYU_PROPERTY_DAMAGE_TYPE)][0]));
}

void RyuLoadPropertyCost(void)
{
    u8 id = VarGet(VAR_TEMP_D);
    VarSet(VAR_TEMP_9, gRyuPropertyData[id][0]);
}

void BufferPropertyRent(void)
{
    u8 id = VarGet(VAR_TEMP_D);
    ConvertIntToDecimalStringN(gStringVar1, gRyuPropertyData[id][1], STR_CONV_MODE_LEFT_ALIGN, 5);
}

void doSpecialHouseWarp(void)//Used to dynamically warp to the current house.
{
    u8 id = (VarGet(VAR_TEMP_D));
    u8 mapGroup = gRyuPropertyData[id][2];
    u8 mapNum = gRyuPropertyData[id][3];
    u8 warpId = gRyuPropertyData[id][4];
    u16 x = gRyuPropertyData[id][5];
    u16 y = gRyuPropertyData[id][6];
    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
}
