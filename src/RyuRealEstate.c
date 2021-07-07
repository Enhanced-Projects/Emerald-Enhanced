#include "global.h"
#include "event_data.h"
#include "RyuRealEstate.h"
#include "string_util.h"
#include "constants/game_stat.h"
#include "overworld.h"
#include "money.h"
#include "script.h"

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
}

void RyuBufferInterestGamestat(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_INTEREST_RECEIVED), STR_CONV_MODE_LEFT_ALIGN, 10);
}

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
