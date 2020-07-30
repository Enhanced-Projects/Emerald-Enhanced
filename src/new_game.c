#include "global.h"
#include "new_game.h"
#include "random.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "match_call.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "tv.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "constants/maps.h"
#include "constants/flags.h"
#include "pokedex.h"
#include "save.h"
#include "link_rfu.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_jump.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "player_pc.h"
#include "field_specials.h"
#include "berry_powder.h"
#include "mevent.h"
#include "union_room_chat.h"

extern const u8 EventScript_ResetAllMapFlags[];

// this file's functions
static void ClearFrontierRecord(void);
static void WarpToTruck(void);
static void ResetMiniGamesResults(void);

// EWRAM vars
EWRAM_DATA bool8 gDifferentSaveFile = FALSE;
EWRAM_DATA bool8 gEnableContestDebugging = FALSE;

// const rom data
static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

// code
void SetTrainerId(u32 trainerId, u8 *dst)
{
    dst[0] = trainerId;
    dst[1] = trainerId >> 8;
    dst[2] = trainerId >> 16;
    dst[3] = trainerId >> 24;
}

u32 GetTrainerId(u8 *trainerId)
{
    return (trainerId[3] << 24) | (trainerId[2] << 16) | (trainerId[1] << 8) | (trainerId[0]);
}

void CopyTrainerId(u8 *dst, u8 *src)
{
    s32 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        dst[i] = src[i];
}

static void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 0x10) | GetGeneratedTrainerIdLower();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
static void SetDefaultOptions(void)
{
    gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_FAST;
    gSaveBlock2Ptr->optionsWindowFrameType = 12;
    gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_STEREO;
    gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
}

static void ClearPokedexFlags(void)
{
    gUnusedPokedexU8 = 0;
    memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();
    for (i = 8; i < 13; i++)
        gSaveBlock1Ptr->contestWinners[i] = sContestWinnerPicDummy;
}

static void ClearFrontierRecord(void)
{
    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = EOS;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = EOS;
}

static void WarpToTruck(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        SetWarpDestination(1, 1, -1, 1, 4);
        WarpIntoMap();
    }
    else
    {
        SetWarpDestination(1, 3, -1, 7, 4);
        WarpIntoMap();
    }
    
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
}

void ResetMenuAndMonGlobals(void)
{
    gDifferentSaveFile = 0;
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

void NewGameInitData(void)
{
    if (!(FlagGet(FLAG_SYS_GAME_CLEAR)))
        RtcReset();

    gDifferentSaveFile = 1;
    gSaveBlock2Ptr->encryptionKey = 0;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetPokedex();
    ClearFrontierRecord();
    ClearSav1();
    ClearMailData();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    ClearPokedexFlags();
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ClearSecretBases();
    ClearBerryTrees();
    SetMoney(&gSaveBlock1Ptr->money, 3000);
    SetCoins(0);
    ResetLinkContestBoolean();
    ResetGameStats();
    ClearAllContestWinnerPics();
    ClearPlayerLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    gPlayerPartyCount = 0;
    ZeroPlayerPartyMons();
    //ResetPokemonStorageSystem();
    ClearRoamerData();
    ClearRoamerLocationData();
    gSaveBlock1Ptr->registeredItem = 0;
    ClearBag();
    NewGameInitPCItems();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    WarpToTruck();
    ScriptContext2_RunNewScript(EventScript_ResetAllMapFlags);
    ResetMiniGamesResults();
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    sub_801AFD8();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetContestLinkResults();
    VarSet(VAR_RYU_EXP_MULTIPLIER, 1);
    FlagSet(FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA);
    FlagSet(FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE);
    VarSet(VAR_MT_PYRE_STATE, 10);
    VarSet(VAR_RYU_BANK_APR, 0);
    FlagSet(FLAG_RYU_LT_RIVAL2);
    FlagSet(FLAG_RYU_LT_RIVAL);
    VarSet(VAR_RYU_JUKEBOX, 999);
    FlagSet(FLAG_HIDE_CHAMPIONS_ROOM_STEVEN);
    VarSet(VAR_RYU_SHELLY_STATUS, 0);
    FlagSet(FLAG_RYU_STARTER_CHOSEN);
    VarSet(VAR_METEOR_FALLS_STATE, 10);
    FlagSet(FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA);
    FlagSet(FLAG_HIDE_METEOR_FALLS_TEAM_AQUA);
    FlagSet(FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO);
    FlagSet(FLAG_RYU_MH_COURTNEY_DUOMODE);
    FlagSet(FLAG_RYU_MH_COURTNEY_SOLOMODE);
    VarSet(VAR_LITTLEROOT_INTRO_STATE, 4);
    FlagSet(FLAG_HIDE_BRENDANS_HOUSE_BRENDAN);
    FlagSet(FLAG_HIDE_DAWNS_HOUSE_DAWN);
    FlagSet(FLAG_RYU_KYOGRE);
    FlagSet(FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN);
    FlagSet(FLAG_HIDE_103_TEST_TRAINER);
    FlagSet(FLAG_HIDE_GRANITE_CAVE_STEVEN);
    FlagSet(FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA);
    FlagSet(FLAG_RYU_HIDE_R120_LANA_AND_HIKER);
    FlagSet(FLAG_RYU_HIDE_REL_OBJECTS);
    FlagSet(FLAG_HIDE_AQUA_HIDEOUT_GRUNTS);
    VarSet(VAR_JAGGED_PASS_STATE, 0);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE3);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_SCIENTIST);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MSITO);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE4);
    FlagSet(FLAG_RYU_DEFEATED_SS);
    FlagSet(FLAG_RYU_HIDE_LANETTE_BASEMENT);
    VarSet(VAR_RYU_GCMS_SPECIES, 0);
    VarSet(VAR_RYU_GCMS_VALUE, 0);
    VarSet(VAR_RYU_GCMS_MOVE1, 0);
    VarSet(VAR_RYU_GCMS_MOVE2, 0);
    VarSet(VAR_RYU_GCMS_MOVE3, 0);
    VarSet(VAR_RYU_GCMS_MOVE4, 0);
    VarSet(VAR_RYU_BANK_APR, 0);
    FlagClear(FLAG_RYU_TEMPTP);
    FlagClear(FLAG_RYU_HAS_FOLLOWER);
    VarSet(VAR_WEATHER_INSTITUTE_STATE, 1);
    FlagSet(FLAG_HIDE_TRICK_HOUSE_LANA);
    FlagSet(FLAG_HIDE_NM_LANA);
    FlagSet(FLAG_HIDE_ABN_SHIP_LANA);
    FlagSet(FLAG_HIDE_PCF_TOWN_LANA);
    FlagSet(FLAG_HIDE_SCH_LANA);
    FlagSet(FLAG_HIDE_DR_LANA);
    FlagSet(FLAG_HIDE_IC_LANA);
    FlagSet(FLAG_HIDE_AT1_LEAF);
    FlagSet(FLAG_HIDE_R110_LANA);
    FlagSet(FLAG_FORCE_MIRAGE_TOWER_VISIBLE);
    VarSet(VAR_CONTEST_HALL_STATE, 0);
    FlagSet(FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER);
    FlagSet(FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA);
    FlagSet(FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA);
    FlagSet(FLAG_RYU_HIDE_HAREM_EVENT_NPCS);
    FlagSet(FLAG_RYU_HIDE_HAREM_EVENT_BRENDAN);
    FlagSet(FLAG_RYU_HIDE_HAREM_EVENT_DAWN);
    FlagSet(FLAG_RYU_HIDE_MANAPHY);
    FlagSet(FLAG_RYU_HIDE_BRINEY_GUARD);
    FlagSet(FLAG_RYU_HIDE_GC_BLAISE);
    FlagSet(FLAG_RYU_HIDE_111_MAGMA_MEETING);
    FlagSet(FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA1);
    FlagSet(FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA2);
    FlagSet(FLAG_RYU_ROUTE_111_MAGMA_MEETING_BLAISE);
    FlagSet(LCC_MAGMA_HARBOR_REPORTERS);
    FlagSet(FLAG_RYU_MAGMA_LILYCOVE);
    FlagSet(FLAG_RYU_AQUA_IN_MAGMA_HIDEOUT_GRUNTS);
    FlagSet(FLAG_RYU_HIDE_MAGMA_HIDEOUT_MAXIE);
    FlagSet(FLAG_RYU_HIDE_R112_BLAISE);
    FlagSet(FLAG_HIDE_MAGMA_ARMY);
    FlagSet(FLAG_RYU_AQUA_IN_MAGMA_HIDEOUT_GRUNTS);
    FlagSet(FLAG_RYU_MAXIE_END_EVENT);
}

static void ResetMiniGamesResults(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokeJumpResults();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}
