#include "global.h"
#include "constants/items.h"
#include "event_data.h"
#include "item.h"


const u16 gNormalContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
    ITEM_POKE_BALL,
};

const u16 gSuperContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
    ITEM_GREAT_BALL,
};

const u16 gHyperContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
    ITEM_ULTRA_BALL,
};

const u16 gMasterContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LUXURY_BALL,
};


u16 RyuGetContestRewards(void)
{
    u8 rank = VarGet(VAR_CONTEST_RANK);
    u16 rewardId = VarGet(VAR_RYU_CONTEST_REWARD);

    if (rewardId == 1000)//if somehow this code is called when the player has already received the item, reward nothing.
        return 1000;



    switch (rank)
    {
        case 0: //normal
        {
            if (CheckBagHasSpace((gNormalContestRewardsTable[rewardId]), 1) == FALSE)
                return 2000; //player doesn't have space for the given reward.
            else
                return gNormalContestRewardsTable[rewardId];
        }
        case 1: //super
        {
            if (CheckBagHasSpace((gSuperContestRewardsTable[rewardId]), 1) == FALSE)
                return 2000; //player doesn't have space for the given reward.
            else
                return gSuperContestRewardsTable[rewardId];
        }
        case 2: //hyper
        {
            if (CheckBagHasSpace((gHyperContestRewardsTable[rewardId]), 1) == FALSE)
                return 2000; //player doesn't have space for the given reward.
            else
                return gHyperContestRewardsTable[rewardId];
        }
        case 3: //master
        {
            if (CheckBagHasSpace((gNormalContestRewardsTable[rewardId]), 1) == FALSE)
                return 2000; //player doesn't have space for the given reward.
            else
                return gNormalContestRewardsTable[rewardId];
        }
    }
}