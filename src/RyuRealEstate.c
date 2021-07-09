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

//DAILY TASKS
void DoDailyRealEstateTasks(void)
{
    if (FlagGet(FLAG_RYU_PLAYER_HAS_BANK_ACCOUNT))
    {
        u32 balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
        u32 interest = balance / 100; // 1% interest rate
        if (interest + balance < balance) // happens if balance is close to the integer limit and the interest causes it to overflow and wrap to 0
            return;
        SetGameStat(GAME_STAT_INTEREST_RECEIVED, interest); // saves the last earned interest amount, potentially could be more than 65k, so use 32bit number.
        SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, balance + interest);
        FlagSet(FLAG_RYU_INTEREST_ACCRUED);
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
    VarSet(VAR_RYU_PROPERTY_DAMAGE_DAYS, 0); //0 - 13
}


void RyuBufferInterestGamestat(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_INTEREST_RECEIVED), STR_CONV_MODE_LEFT_ALIGN, 10);
}


// FRONTIER BANK
void RyuBufferBankBalance(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
}

static const u32 sDepositAmounts[] = { 0, 10000, 50000, 100000, 250000, 500000, 1000000, 10000000, 100000000 };

int RyuFBDoDeposit(void)
{
    u32 money = GetMoney(&gSaveBlock1Ptr->money);
    u32 balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
    u32 amount = 0;
    u8 selection = gSpecialVar_Result;

    if (selection == 0)
    {
        balance = 0;
        amount = (GetMoney(&gSaveBlock1Ptr->money));
    } else if (selection >= 9) {
        // User selected exit
        return 5;
    } else {
        amount = sDepositAmounts[selection];
        balance += amount;
    }

    // player doesn't have enough money to deposit.
    if (GetMoney(&gSaveBlock1Ptr->money) < amount)
        return 0;

    // If the player has more than 900 million, there's a serious potential of overflow if the bank account has more than 1.1 billion.
    // Just abort to save time. Balance is zero if player is depositing all.
    if (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) > 1000000000 && GetMoney(&gSaveBlock1Ptr->money) >= 900000000 && (balance == 0))
        return 2; // Deposit amount would potentially put the bank above hard limit. Abort.

    if ((amount + GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)) > 2000000000) 
        return 3;// Deposit amount is above maximum allowed, abort.

    //if it got this far, the it passed the above checks. Apply player balance to bank balance.
    if (balance == 0)
    {
        amount = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) + money;
        SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, amount);
        SetMoney(&gSaveBlock1Ptr->money, 0);
        ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 10);
        ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
        return 4;// Player deposited entire personal money amount 
    }

    // Otherwise do a normal deposit.
    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, balance);
    RemoveMoney(&gSaveBlock1Ptr->money, amount);
    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 10);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10); 
    return 1; // Deposit was successful.
}

int RyuFBDoWithdraw(void)
{
    u32 amount = 0;
    u32 balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
    u32 money = GetMoney(&gSaveBlock1Ptr->money);
    u8 selection = gSpecialVar_Result;

    if (selection == 0)
    {
        amount = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
        balance = 0; // tell the code below that player is withdrawing all.
    } else if (selection >= 9) {
        // User selected exit
        return 5;
    } else {
        amount = sDepositAmounts[selection];
        balance -= amount;
    }

    if (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) < amount)
        return 0;//not enough money in bank to make the witdrawal

    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 10);
    // These two branches look similar enough to be combined at some point…
    if (balance == 0) // code above said to take ALL the money
    {
        // prevent player from withdrawing more than they can hold. If amount would go above 1 billion, then split the difference 
        if (amount + money > MAX_MONEY)
        {
            amount = MAX_MONEY - money;
            AddMoney(&gSaveBlock1Ptr->money, amount);
            SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) - amount);
            ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 10);
            ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
            return 3; // withdrew amount of money required to reach personal money cap.
        }
        else
        {
            AddMoney(&gSaveBlock1Ptr->money, amount);
            SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, 0);
            ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 10);
            ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
            return 2; // withdrew entire balance, player money isn't above cap.
        }
    }
    else
    {
        // check if the selected set withdrawal amount could exceed player maximum money.
        if (amount + money > MAX_MONEY)
        {
            u32 difference = amount + money - MAX_MONEY;
            amount -= difference;
            SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) - amount);
            AddMoney(&gSaveBlock1Ptr->money, amount);
            ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
            ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 10);
            return 4; // withdraw amount would have normally exceeded player max. Split the difference.
        }
        SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, balance);
        AddMoney(&gSaveBlock1Ptr->money, balance);
        ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10); 
        return 1; // normal withdraw
    }
}

//PROPERTY RELATED

const u16 gRyuPropertyData[NUM_PROPERTIES][5] = { //property id, property value, property rent, map group(interior), map num(interior), warp num(interior), x, y
    [PROPERTY_DEWFORD   ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_FALLARBOR ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_LILYCOVE  ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_MAUVILLE  ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_OLDALE    ] = {36000, 1800, 2, 2, 0, 3, 8},
    [PROPERTY_ROUTE119  ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_RUSTBURO  ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_SLATEPORT ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_SNOWSHORE ] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_SOOTOPOLIS] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_VERDANTURF] = {36000, 1800, 0, 0, 0, 0, 0},
    [PROPERTY_MOSSDEEP  ] = {36000, 1800, 0, 0, 0, 0, 0},
};

const u8 gRyuPropertyNames[NUM_PROPERTIES][22] = { //@TOBY: feel free to rename these
    [PROPERTY_DEWFORD]    = _("Dewford Island Home"),
    [PROPERTY_FALLARBOR]  = _("Fallarbor Town House"),
    [PROPERTY_LILYCOVE]   = _("Lilycove peninsula"),
    [PROPERTY_MAUVILLE]   = _("Mauville Estate"),
    [PROPERTY_OLDALE]     = _("Oldale Cottage"),
    [PROPERTY_ROUTE119]   = _("Treetop Fort"),
    [PROPERTY_RUSTBURO]   = _("Rustburo Flat"),
    [PROPERTY_SLATEPORT]  = _("Slateport Condo"),
    [PROPERTY_SNOWSHORE]  = _("Snowshore Cottage"),
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
    u8 damageType = (Random() % sizeof(gRyuPropertyDamageTable));
    u8 damageDays = gRyuPropertyDamageTable[damageType][0];

    if (val < 60)
        return;

    if ((val > 59) && (val < 70))//damage a random property. (10%)
        {
            do {//only damage a property that is owned by the player.
                gSpecialVar_0x8004 = (Random() % NUM_PROPERTIES);
            
             } while((!(CheckOwnedProperty(gSpecialVar_0x8004) == TRUE)));
            FlagSet(FLAG_RYU_PROPERTY_DAMAGED);
            VarSet(VAR_RYU_DAMAGED_HOUSE_ID, gSpecialVar_0x8004);
            VarSet(VAR_RYU_PROPERTY_DAMAGE_TYPE, damageType);
            VarSet(VAR_RYU_PROPERTY_DAMAGE_DAYS, gRyuPropertyDamageTable[damageType][1]);
        }

    if (val > 70) {}//should i do something else here?
}

void RyuBufferRealEstateDetails(void)
{
    u8 id = (VarGet(VAR_TEMP_D));
    ConvertIntToDecimalStringN(gStringVar1, gRyuPropertyData[id][0], STR_CONV_MODE_LEFT_ALIGN, 5);
    StringCopy(gStringVar2, gRyuPropertyNames[id]);
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

    if ((owned == TRUE) && (rented == FALSE) && (VarGet(VAR_RYU_PLAYER_HOUSE_ID == id)))
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
        
    gSaveBlock2Ptr->propertyFlags[id / 8] &= ~(1 << (id % 8));
}

void AddProperty(u32 id)
{
    if(id > PLAYER_PROPERTIES_COUNT)
        return;

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
    int rent = 0;
    u8 i;

    for (i = 0; i < NUM_PROPERTIES; i++){
        if (CheckOwnedProperty(i) && CheckRentedProperty(i))
            rent += gRyuPropertyData[i][1];
    }
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
}

void DecrementPropertyRepairTime(void)
{
    if (VarGet(VAR_RYU_PROPERTY_DAMAGE_DAYS) == 0)
    {
        FlagClear(FLAG_RYU_PROPERTY_DAMAGED);
        FlagClear(FLAG_RYU_PROPERTY_UNDERGOING_MAINTENANCE);
        VarSet(VAR_RYU_PROPERTY_DAMAGE_TYPE, NUM_DAMAGE_TYPES);
        return;
    }
    else
        VarSet(VAR_RYU_PROPERTY_DAMAGE_DAYS, (VarGet(VAR_RYU_PROPERTY_DAMAGE_DAYS) - 1));

}

void RyuBufferPropertyDamageData(void)
{
    u8 id = (VarGet(VAR_TEMP_D));
    u8 damageType = VarGet(VAR_RYU_PROPERTY_DAMAGE_TYPE);

    StringCopy(gStringVar1, gRyuPropertyNames[id]);
    StringCopy(gStringVar2, gRyuDamageTypeNamesTable[damageType]);
    ConvertIntToDecimalStringN(gStringVar3, gRyuPropertyDamageTable[damageType][0], STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gRyuStringVar1, VarGet(VAR_RYU_PROPERTY_DAMAGE_DAYS), STR_CONV_MODE_LEFT_ALIGN, 2);
    VarSet(VAR_TEMP_F, gRyuPropertyDamageTable[damageType][0]);
}

void RyuRE_TakeMoney(void)
{
    u8 id = (VarGet(VAR_TEMP_D));

    RemoveMoney(&gSaveBlock1Ptr->money, (gRyuPropertyData[id][0]));
    AddProperty(id);
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
    u16 x = 0;
    u16 y = 0;
    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
}
