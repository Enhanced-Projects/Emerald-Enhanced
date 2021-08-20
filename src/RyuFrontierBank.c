#include "global.h"
#include "event_data.h"
#include "string_util.h"
#include "constants/game_stat.h"
#include "overworld.h"
#include "money.h"
#include "script.h"
#include "random.h"
#include "main.h"


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
    u32 tempValue = 0;
    u8 selection = gSpecialVar_Result;

    if (selection == 0) { //deposit all
        tempValue = money;
        if (tempValue + balance >= 2000000000)
        {
            return 2; //Would exceed bank hard limit, abort.
        }
    }
    else if (selection >= 9) //exit
    {
        return 3;
    }
    else { // deposit amount by selection
        tempValue = sDepositAmounts[selection];
        if ((tempValue + balance) > 2000000000) //selected deposit amount would exceed bank hard limit. Abort.
            return 2;

        if (money < tempValue) //Player cant afford this deposit. Abort.
            return 0;
    }

    //if it got this far, the it passed the above checks. Apply changes to balance and player's money
    ConvertIntToDecimalStringN(gStringVar1, tempValue, STR_CONV_MODE_LEFT_ALIGN, 10); //buffer the deposit amount
    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (balance + tempValue));; 
    RemoveMoney(&gSaveBlock1Ptr->money, tempValue);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10); //buffer new bank balance total
    return 1;// Deposit Successful.
}

int RyuFBDoWithdraw(void)
{
    s64 tempValue = 0;
    s64 balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
    s64 money = GetMoney(&gSaveBlock1Ptr->money);
    u8 selection = gSpecialVar_Result;

    if (selection == 0)
        tempValue = balance;
    else if (selection >= 9)
        return 4;//exit
    else 
        tempValue = sDepositAmounts[selection];

    if (tempValue > balance)
        return 0;  //not enough money in account.

    if ((tempValue + money) > 1000000000)
        return 2; //Withdraw would exceed player MAX_MONEY

    //@kageru can you make the following modification, please? I can't wrap my head around the math required to do this.
    
    /*if Player selected withdraw ALL, but the withdraw would exceed MAX_MONEY, give the player the amount)
      requred to reach MAX_MONEY from the bank account instead.
      (do the balance and player money change as well as buffer the withdrawal amount in gStringVar1
      and buffer bank balance in gStringVar2 in this subroutine)

    return 3;*/

    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (balance - tempValue));
    AddMoney(&gSaveBlock1Ptr->money, tempValue);
    ConvertIntToDecimalStringN(gStringVar1, tempValue, STR_CONV_MODE_LEFT_ALIGN, 10);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
    return 1; //Withdrawal successful
}