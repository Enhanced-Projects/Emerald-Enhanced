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
    if (FlagGet(FLAG_RYU_PLAYER_HAS_BANK_ACCOUNT) == TRUE)
    {
        u32 balance = (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE));
        balance /= 100;
        SetGameStat(GAME_STAT_INTEREST_RECEIVED, balance);//saves the last earned interest amount, potentially could be more than 65k, so use 32bit number.
        SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (balance * 101)); //this should give 1% interest.
        FlagSet(FLAG_RYU_INTREST_ACCRUED);
    }
            

}

void RyuBufferInterestGamestat(void)
{
    ConvertIntToDecimalStringN(gStringVar1, (GetGameStat(GAME_STAT_INTEREST_RECEIVED)), STR_CONV_MODE_LEFT_ALIGN, 10);
}

void RyuBufferBankBalance(void)
{
    ConvertIntToDecimalStringN(gStringVar1, (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)), STR_CONV_MODE_LEFT_ALIGN, 10);
}

int RyuFBDoDeposit(void)
{
    u32 money = (GetMoney(&gSaveBlock1Ptr->money));
    u32 Balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
    u32 Amount = 0;
    u8 Selection = gSpecialVar_Result;

    switch (Selection)
    {
        case 0:
            Balance = 0;
            Amount = (GetMoney(&gSaveBlock1Ptr->money));
            break;
        case 1:
            Amount = 10000;
            Balance += Amount;
            break;
        case 2:
            Amount = 50000;
            Balance += Amount;
            break;
        case 3:
            Amount = 100000;
            Balance += Amount;
            break;
        case 4:
            Amount = 250000;
            Balance += Amount;
            break;
        case 5:
            Amount = 500000;
            Balance += Amount;
            break;
        case 6:
            Amount = 1000000;
            Balance += Amount;
            break;
        case 7:
            Amount = 10000000;
            Balance += Amount;
            break;
        case 8:
            Amount = 100000000;
            Balance += Amount;
            break;
        case 9:
            return 5;//User selected exit.
            break;
    }

    if ((GetMoney(&gSaveBlock1Ptr->money)) < Amount)
        return 0;//player doesn't have enough money to deposit.

    //if the player has more than 900 million, there's a serious potential of overflow if the bank account has more than 1.1 billion.
    //just abort to save time. Balance is zero if player is depositing all.
    if ((GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) > 1000000000 && (GetMoney(&gSaveBlock1Ptr->money) >= 900000000)) && (Balance == 0))
    {
        return 2; //Deposit amount would potentially put the bank above hard limit. Abort.
    }

    if ((Amount + GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)) > 2000000000) 
    {                                                                   
        return 3;//Deposit amount is above maximum allowed, abort.
    }

    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, Balance);
    RemoveMoney(&gSaveBlock1Ptr->money, Amount);
    ConvertIntToDecimalStringN(gStringVar1, Amount, STR_CONV_MODE_LEFT_ALIGN, 10);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10); 
    return 1;//deposit was successful.
}

int RyuFBDoWithdraw(void)
{
    u32 Amount = 0;
    u32 Balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
    u32 money = (GetMoney(&gSaveBlock1Ptr->money));
    u8 Selection = gSpecialVar_Result;

    switch (Selection)
    {
        case 0:
            Amount = (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE));
            Balance = 0;//tell the code below that player is withdrawing all.
            break;
        case 1:
            Amount = 10000;
            Balance -= Amount;
            break;
        case 2:
            Amount = 50000;
            Balance -= Amount;
            break;
        case 3:
            Amount = 100000;
            Balance -= Amount;
            break;
        case 4:
            Amount = 250000;
            Balance -= Amount;
            break;
        case 5:
            Amount = 500000;
            Balance -= Amount;
            break;
        case 6:
            Amount = 1000000;
            Balance -= Amount;
            break;
        case 7:
            Amount = 10000000;
            Balance -= Amount;
            break;
        case 8:
            Amount = 100000000;
            Balance -= Amount;
            break;
        case 9:
            return 5;//user selected Exit.
            break;
    }

    if ((GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)) < Amount)
        return 0;//not enough money in bank to make the witdrawal

    ConvertIntToDecimalStringN(gStringVar1, Amount, STR_CONV_MODE_LEFT_ALIGN, 10);
    if (Balance == 0)// code above said to take ALL the money
    {
        //prevent player from withdrawing more than they can hold. If amount would go above 1 billion, then split the difference 
        u32 total = (Amount + money);
        if (total > 1000000000)
        {
            Amount = (1000000000 - money);
            AddMoney(&gSaveBlock1Ptr->money, Amount);
            SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, ((GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)) - Amount));
            ConvertIntToDecimalStringN(gStringVar1, Amount, STR_CONV_MODE_LEFT_ALIGN, 10);
            ConvertIntToDecimalStringN(gStringVar2, (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)), STR_CONV_MODE_LEFT_ALIGN, 10);
            return 3;// withdrew amount of money required to reach personal money cap.
        }
        else
        {
            AddMoney(&gSaveBlock1Ptr->money, Amount);
            SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, 0);
            return 2;// withdrew entire balance, player money isn't above cap.
        }
    }
    else
    {   //check if the selected set withdrawal amount could exceed player maximum money.
        if ((Amount + money) > 1000000000)
        {
            u32 difference = ((Amount + money) - 1000000000);
            Amount -= difference;
            SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE) - Amount));
            AddMoney(&gSaveBlock1Ptr->money, Amount);
            ConvertIntToDecimalStringN(gStringVar2, (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)), STR_CONV_MODE_LEFT_ALIGN, 10);
            ConvertIntToDecimalStringN(gStringVar1, Amount, STR_CONV_MODE_LEFT_ALIGN, 10);
            return 4;//withdraw amount would have normally exceeded player max. Split the difference.
        }
        SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, Balance);
        AddMoney(&gSaveBlock1Ptr->money, Balance);
        ConvertIntToDecimalStringN(gStringVar2, (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE)), STR_CONV_MODE_LEFT_ALIGN, 10); 
        return 1;// normal withdraw
    }
}