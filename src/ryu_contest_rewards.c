#include "global.h"
#include "constants/items.h"
#include "event_data.h"
#include "item.h"


const u16 gNormalContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_ORAN_BERRY,
    ITEM_ORAN_BERRY,
    ITEM_CHERI_BERRY,
    ITEM_CHERI_BERRY,
    ITEM_CHESTO_BERRY,
    ITEM_CHESTO_BERRY,
    ITEM_PECHA_BERRY,
    ITEM_PECHA_BERRY,
    ITEM_RAWST_BERRY,
    ITEM_RAWST_BERRY,
    ITEM_ASPEAR_BERRY,
    ITEM_ASPEAR_BERRY,
    ITEM_LEPPA_BERRY,
    ITEM_LEPPA_BERRY,
    ITEM_PERSIM_BERRY,
    ITEM_PERSIM_BERRY,
    ITEM_BANANA,
};

const u16 gSuperContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_MAGO_BERRY,
    ITEM_MAGO_BERRY,
    ITEM_AGUAV_BERRY,
    ITEM_AGUAV_BERRY,
    ITEM_IAPAPA_BERRY,
    ITEM_IAPAPA_BERRY,
    ITEM_RAZZ_BERRY,
    ITEM_BLUK_BERRY,
    ITEM_NANAB_BERRY,
    ITEM_WEPEAR_BERRY,
    ITEM_PINAP_BERRY,
};

const u16 gHyperContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_POMEG_BERRY,
    ITEM_KELPSY_BERRY,
    ITEM_QUALOT_BERRY,
    ITEM_HONDEW_BERRY,
    ITEM_GREPA_BERRY,
    ITEM_TAMATO_BERRY,
    ITEM_CORNN_BERRY,
    ITEM_MAGOST_BERRY,
    ITEM_RABUTA_BERRY,
    ITEM_NOMEL_BERRY,
    ITEM_SPELON_BERRY,
    ITEM_PAMTRE_BERRY,
    ITEM_WATMEL_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_BELUE_BERRY,
    ITEM_SWEET_HEART,
    ITEM_BIG_MALASADA,
};

const u16 gMasterContestRewardsTable[NUM_CONTEST_REWARDS] = {
    ITEM_PASSHO_BERRY,
    ITEM_WACAN_BERRY,
    ITEM_RINDO_BERRY,
    ITEM_YACHE_BERRY,
    ITEM_CHOPLE_BERRY,
    ITEM_KEBIA_BERRY,
    ITEM_SHUCA_BERRY,
    ITEM_COBA_BERRY,
    ITEM_PAYAPA_BERRY,
    ITEM_TANGA_BERRY,
    ITEM_CHARTI_BERRY,
    ITEM_KASIB_BERRY,
    ITEM_HABAN_BERRY,
    ITEM_COLBUR_BERRY,
    ITEM_BABIRI_BERRY,
    ITEM_CHILAN_BERRY,
    ITEM_ROSELI_BERRY,
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