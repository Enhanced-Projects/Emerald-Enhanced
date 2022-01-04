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
    u32 selection = gSpecialVar_32bit;

    if (selection == 0) //player did not make a selection
        return 3;

    if (selection > 899999999) //player entered "9" as the first (hundreds of millions) digit. Select all money (shortcut).
        selection = money;

        if (selection + balance >= 2000000000)
        {
            return 2; //Would exceed bank hard limit. Abort.
        }
    
        if (money < selection) //Player cant afford this deposit. Abort.
            return 0;

    //if it got this far, the it passed the above checks. Apply changes to balance and player's money
    ConvertIntToDecimalStringN(gStringVar1, selection, STR_CONV_MODE_LEFT_ALIGN, 10); //buffer the deposit amount
    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (balance + selection));; 
    RemoveMoney(&gSaveBlock1Ptr->money, selection);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10); //buffer new bank balance total
    return 1;// Deposit Successful.
}

int RyuFBDoWithdraw(void)
{
    s64 balance = GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE);
    s64 money = GetMoney(&gSaveBlock1Ptr->money);
    u32 selection = gSpecialVar_32bit;
    //@PIDGEY there needs to be a function here that finds out how much money is required to
    //get the player to max balance. If selected number(from script) is greater than 899m,
    //it should just withdraw whatever is required to get player to 1 billion. return 4. (Script for return 4 is already done.)

    //also note: For some reason, when you enter a withdrawal amount, it gives the player the money, but does NOT take
    //it out of the player's account. Could you look into this, please?


    if (selection == 0) //player did not make a selection or pressed B
        return 3;

    if (selection > balance)
        return 0;  //not enough money in account. Abort.

    if ((selection + money) > 1000000000)
        return 2; //Withdraw would exceed player MAX_MONEY. Abort.

    SetGameStat(GAME_STAT_FRONTIERBANK_BALANCE, (balance - selection));
    AddMoney(&gSaveBlock1Ptr->money, selection);
    ConvertIntToDecimalStringN(gStringVar1, selection, STR_CONV_MODE_LEFT_ALIGN, 10);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
    return 1; //Withdrawal successful
}