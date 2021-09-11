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
#include "constants/map_groups.h"
#include "factions.h"
#include "RyuRealEstate.h"

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
    gSaveBlock2Ptr->optionsThemeNumber = OPTIONS_THEME_DARK;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
    FlagClear(FLAG_RYU_VANILLA_CAP);
    FlagClear(FLAG_RYU_AUTORUN);
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

extern void RyuClearAlchemyEffect();

void NewGameInitData(void)
{
    u8 ngPlusCount = VarGet(VAR_RYU_NGPLUS_COUNT);
    u16 originalSaveFileVersion = VarGet(VAR_SAVE_FILE_CREATED_ON_VERSION);

    //I don't want people being able to newgame plus unless they have defeated the champion. Nuzlocke/Hardcore failure circumvents this.
    //It also allows people to start over if they want a fresh start without having to physically delete their save file.
    if (!FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        // reset ngPlusCount here. The var is overwritten with this value later in this function.
        ngPlusCount = 0;
        RtcReset();
        ClearSav1();
        memset(gSaveBlock2Ptr->achFlags, 0, 32);//initialize achievements on raw new game.
        memset(gSaveBlock2Ptr->achievementPowerFlags, 0, (sizeof(gSaveBlock2Ptr->achievementPowerFlags)));//disable all AP's on raw new game.
    }
    else //hacky, I know but it's the only way I could get it to work :shrug:
    {
        ClearSav1_SkipDex();
    }
    
    RyuFactions_ResetAllStanding();
    gDifferentSaveFile = 1;
    gSaveBlock2Ptr->encryptionKey = 0;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ClearFrontierRecord();
    ClearMailData();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
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
    ClearRoamerData();
    ClearRoamerLocationData();
    gSaveBlock1Ptr->registeredItem = 0;
    gSaveBlock2Ptr->expShare = 0;
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
    sub_801AFD8();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetContestLinkResults();
    ClearMysteryEventFlags();

    //flags
    FlagSet(FLAG_RYU_LT_RIVAL2);
    FlagSet(FLAG_RYU_LT_RIVAL);
    FlagSet(FLAG_HIDE_CHAMPIONS_ROOM_STEVEN);
    FlagSet(FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA);
    FlagSet(FLAG_HIDE_METEOR_FALLS_TEAM_AQUA);
    FlagSet(FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO);
    FlagSet(FLAG_RYU_AQUA_HIDE_MH4_COURTNEY_BOSS);
    FlagSet(FLAG_RYU_MH_COURTNEY_SOLOMODE);
    FlagSet(FLAG_HIDE_BRENDANS_HOUSE_BRENDAN);
    FlagSet(FLAG_HIDE_DAWNS_HOUSE_DAWN);
    FlagSet(FLAG_RYU_KYOGRE);
    FlagSet(FLAG_HIDE_103_TEST_TRAINER);
    FlagSet(FLAG_HIDE_GRANITE_CAVE_STEVEN);
    FlagSet(FLAG_RYU_HIDE_R120_LANA_AND_HIKER);
    FlagSet(FLAG_RYU_HIDE_REL_OBJECTS);
    FlagSet(FLAG_HIDE_AQUA_HIDEOUT_GRUNTS);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE3);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_SCIENTIST);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MSITO);
    FlagSet(FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE4);
    FlagSet(FLAG_RYU_DEFEATED_SS);
    FlagSet(FLAG_RYU_HIDE_LANETTE_BASEMENT);
    FlagSet(FLAG_HIDE_TRICK_HOUSE_LANA);
    FlagSet(FLAG_HIDE_NM_LANA);
    FlagSet(FLAG_HIDE_ABN_SHIP_LANA);
    FlagSet(FLAG_HIDE_PCF_TOWN_LANA);
    FlagSet(FLAG_HIDE_SCH_LANA);
    FlagSet(FLAG_HIDE_DR_LANA);
    FlagSet(FLAG_HIDE_IC_LANA);
    FlagSet(FLAG_HIDE_AT1_LEAF);
    FlagSet(FLAG_HIDE_R110_LANA);
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
    FlagSet(FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY);
    FlagSet(FLAG_RYU_MAXIE_END_EVENT);
    FlagSet(FLAG_RYU_COURTNEY_FIERY_PATH);
    FlagSet(FLAG_HIDE_UNION_ROOM_PLAYER_1);
    FlagSet(FLAG_RYU_HIDE_103_MAGMA_MEETING);
    FlagSet(FLAG_RYU_HIDE_114_MAXIE);
    FlagSet(FLAG_RYU_RUSTURF_CLEARING_MAGMA);
    FlagSet(FLAG_RYU_HIDE_AQUA_MTPYRE_EXT);
    FlagSet(FLAG_RYU_HIDE_CHIMNEY_GROUDON);
    FlagSet(FLAG_RYU_HIDE_SHIPYARD_DEVON_EMPLOYEES);    
    FlagSet(FLAG_RYU_HIDE_MOSSDEEP_MATT);
    FlagSet(FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_MAXIE);
    FlagSet(FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN);
    FlagSet(FLAG_HIDE_ROUTE_118_STEVEN);
    FlagSet(FLAG_RYU_HIDE_NPCS_MTPYRE_SUMMIT);
    FlagClear(FLAG_RYU_TEMPTP);
    FlagClear(FLAG_RYU_HAS_FOLLOWER);
    FlagClear(FLAG_OPTIONS_INSTANT_TRANSITION);
    FlagSet(FLAG_HIDE_ALL_KECLEON_OWS);// can't delete all kecleon overworlds because scripts, so this will do.
    FlagSet(FLAG_SYS_NATIONAL_DEX);

    //vars
    VarSet(VAR_RYU_GCMS_SPECIES, 0);
    VarSet(VAR_RYU_GCMS_VALUE, 0);
    VarSet(VAR_RYU_GCMS_MOVE1, 0);
    VarSet(VAR_RYU_GCMS_MOVE2, 0);
    VarSet(VAR_RYU_GCMS_MOVE3, 0);
    VarSet(VAR_RYU_GCMS_MOVE4, 0);
    VarSet(VAR_WEATHER_INSTITUTE_STATE, 1);
    VarSet(VAR_CONTEST_HALL_STATE, 0);
    VarSet(VAR_JAGGED_PASS_STATE, 0);
    VarSet(VAR_LITTLEROOT_INTRO_STATE, 4);
    VarSet(VAR_RYU_THEME_NUMBER, 1);
    VarSet(VAR_RYU_EXP_MULTIPLIER, 1);
    VarSet(VAR_RYU_JUKEBOX, 999);
    VarSet(VAR_RYU_AUTOSCALE_MIN_LEVEL, 2);
    VarSet(VAR_RYU_NGPLUS_COUNT, ngPlusCount);
    VarSet(VAR_OPTIONS_HP_BAR_SPEED, 6);
    VarSet(VAR_SAVE_FILE_CREATED_ON_VERSION, originalSaveFileVersion);
    VarSet(VAR_RYU_LAST_ACH, 300);
    VarSet(VAR_RYU_QUESTLINE_ID, 100); //No questline started
    VarSet(VAR_RYU_PLAYER_HOUSE_ID, 0xFFFF);//Which house the player has set as their own
    VarSet(VAR_RYU_CONTEST_REWARD, 1000); //'clear' ryu contest reward id.
    

    memset(gSaveBlock1Ptr->dexNavSearchLevels, 0, sizeof(gSaveBlock1Ptr->dexNavSearchLevels));
    gSaveBlock1Ptr->dexNavChain = 0;
    RyuClearAlchemyEffect();
    RyuResetRealEstateData();
}

static void ResetMiniGamesResults(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokeJumpResults();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}
