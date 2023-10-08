#include "global.h"
#include "overworld.h"
#include "battle_pyramid.h"
#include "battle_setup.h"
#include "berry.h"
#include "bg.h"
#include "cable_club.h"
#include "clock.h"
#include "dexnav.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_control_avatar.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_special_scene.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "gpu_regs.h"
#include "heal_location.h"
#include "constants/heal_locations.h"
#include "io_reg.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "map_name_popup.h"
#include "match_call.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "mirage_tower.h"
#include "money.h"
#include "new_game.h"
#include "palette.h"
#include "play_time.h"
#include "random.h"
#include "roamer.h"
#include "rotating_gate.h"
#include "safari_zone.h"
#include "save.h"
#include "save_location.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "secret_base.h"
#include "sound.h"
#include "start_menu.h"
#include "task.h"
#include "tileset_anims.h"
#include "time_events.h"
#include "trainer_hill.h"
#include "trainer_pokemon_sprites.h"
#include "tv.h"
#include "scanline_effect.h"
#include "wild_encounter.h"
#include "frontier_util.h"
#include "constants/abilities.h"
#include "constants/layouts.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"
#include "dns.h"
#include "constants/items.h"
#include "pokemon_storage_system.h"
#include "item.h"
#include "pokedex.h"
#include "ach_atlas.h"
#include "RyuRealEstate.h"
#include "overworld_notif.h"

#define PLAYER_TRADING_STATE_IDLE 0x80
#define PLAYER_TRADING_STATE_BUSY 0x81
#define PLAYER_TRADING_STATE_UNK_2 0x82
#define PLAYER_TRADING_STATE_EXITING_ROOM 0x83

#define FACING_NONE 0
#define FACING_UP 1
#define FACING_DOWN 2
#define FACING_LEFT 3
#define FACING_RIGHT 4
#define FACING_FORCED_UP 7
#define FACING_FORCED_DOWN 8
#define FACING_FORCED_LEFT 9
#define FACING_FORCED_RIGHT 10

extern const u8 gRyuWarpMaleHomeScript[];
extern const u8 gRyuWarpFemaleHomeScript[];

extern const struct MapLayout *const gMapLayouts[];
extern const struct MapHeader *const *const gMapGroups[];

extern void RyuKillMon(void);
extern void RyuWipeParty(void);

static void Overworld_ResetStateAfterWhiteOut(void);
static void CB2_ReturnToFieldLink(void);
static void CB2_LoadMapOnReturnToFieldCableClub(void);
static void CB2_LoadMap2(void);
static void VBlankCB_Field(void);
static void SpriteCB_LinkPlayer(struct Sprite *sprite);
static void ChooseAmbientCrySpecies(void);
static void DoMapLoadLoop(u8 *state);
static bool32 LoadMapInStepsLocal(u8 *state, bool32);
static bool32 LoadMapInStepsLink(u8 *state);
static bool32 ReturnToFieldLocal(u8 *state);
static bool32 ReturnToFieldLink(u8 *state);
static void InitObjectEventsLink(void);
static void InitObjectEventsLocal(void);
static void InitOverworldGraphicsRegisters(void);
static u8 GetSpriteForLinkedPlayer(u8);
static u16 KeyInterCB_SendNothing(u32 a1);
static void ResetMirageTowerAndSaveBlockPtrs(void);
static void sub_80867D8(void);
static void OffsetCameraFocusByLinkPlayerId(void);
static void SpawnLinkPlayers(void);
static void SetCameraToTrackGuestPlayer(void);
static void ResumeMap(bool32 arg0);
static void SetCameraToTrackPlayer(void);
static void sub_8086A68(void);
static void InitViewGraphics(void);
static void SetCameraToTrackGuestPlayer_2(void);
static void CreateLinkPlayerSprites(void);
static void ClearAllPlayerKeys(void);
static void ResetAllTradingStates(void);
static void UpdateHeldKeyCode(u16);
static void UpdateAllLinkPlayers(u16*, s32);
static u8 FlipVerticalAndClearForced(u8 a1, u8 a2);
static u8 LinkPlayerDetectCollision(u8 selfObjEventId, u8 a2, s16 x, s16 y);
static void CreateLinkPlayerSprite(u8 linkPlayerId, u8 gameVersion);
static void GetLinkPlayerCoords(u8 linkPlayerId, u16 *x, u16 *y);
static u8 GetLinkPlayerFacingDirection(u8 linkPlayerId);
static u8 GetLinkPlayerElevation(u8 linkPlayerId);
static s32 sub_80878E4(u8 linkPlayerId);
static u8 GetLinkPlayerIdAt(s16 x, s16 y);
static void SetPlayerFacingDirection(u8 linkPlayerId, u8 a2);
static void ZeroObjectEvent(struct ObjectEvent *objEvent);
static void SpawnLinkPlayerObjectEvent(u8 linkPlayerId, s16 x, s16 y, u8 a4);
static void InitLinkPlayerObjectEventPos(struct ObjectEvent *objEvent, s16 x, s16 y);
static void sub_80877DC(u8 linkPlayerId, u8 a2);
static void sub_808780C(u8 linkPlayerId);
static u8 GetSpriteForLinkedPlayer(u8 linkPlayerId);
static void RunTerminateLinkScript(void);
static u32 GetLinkSendQueueLength(void);
static void ZeroLinkPlayerObjectEvent(struct LinkPlayerObjectEvent *linkPlayerObjEvent);
static const u8 *TryInteractWithPlayer(struct TradeRoomPlayer *a1);
static u16 GetDirectionForEventScript(const u8 *script);
static void sub_8087510(void);
static void InitLinkRoomStartMenuScript(void);
static void sub_8087530(const u8 *script);
static void CreateConfirmLeaveTradeRoomPrompt(void);
static void InitMenuBasedScript(const u8 *script);
static void LoadTradeRoomPlayer(s32 linkPlayerId, s32 a2, struct TradeRoomPlayer *a3);
static bool32 sub_8087340(struct TradeRoomPlayer *a1);
static bool32 sub_8087340_2(struct TradeRoomPlayer *a1);
static u8 *TryGetTileEventScript(struct TradeRoomPlayer *a1);
static bool32 PlayerIsAtSouthExit(struct TradeRoomPlayer *a1);
static const u8 *TryInteractWithPlayer(struct TradeRoomPlayer *a1);
static u16 KeyInterCB_DeferToRecvQueue(u32);
static u16 KeyInterCB_DeferToSendQueue(u32);
static void ResetPlayerHeldKeys(u16 *a1);
static u16 KeyInterCB_SelfIdle(u32 a1);
static u16 KeyInterCB_DeferToEventScript(u32 a1);
static u16 GetDirectionForDpadKey(u16 a1);
static void CB1_UpdateLinkState(void);
static void SetKeyInterceptCallback(u16 (*func)(u32));
static void SetFieldVBlankCallback(void);
static void FieldClearVBlankHBlankCallbacks(void);
static u8 GetAdjustedInitialTransitionFlags(struct InitialPlayerAvatarState *playerStruct, u16 a2, u8 a3);
static u8 GetAdjustedInitialDirection(struct InitialPlayerAvatarState *playerStruct, u8 a2, u16 a3, u8 a4);
static u16 GetCenterScreenMetatileBehavior(void);

// IWRAM bss vars
static void *sUnusedOverworldCallback;
static u8 sPlayerTradingStates[MAX_LINK_PLAYERS];
// This callback is called with a player's key code. It then returns an
// adjusted key code, effectively intercepting the input before anything
// can process it.
static u16 (*sPlayerKeyInterceptCallback)(u32);
static bool8 sUnknown_03000E18;
static u8 sRfuKeepAliveTimer;
static u32 sUnusedVar;

// IWRAM common
u16 *gBGTilemapBuffers1;
u16 *gBGTilemapBuffers2;
u16 *gBGTilemapBuffers3;
u16 gHeldKeyCodeToSend;
void (*gFieldCallback)(void);
bool8 (*gFieldCallback2)(void);
u8 gLocalLinkPlayerId; // This is our player id in a multiplayer mode.
u8 gFieldLinkPlayerCount;
extern u8 RyuFollowerSelectNPCScript[];
extern u8 Ryu_StartRandomBattle[];
extern u8 Ryu_PlayerFailedChallengeHardcore[];
extern u8 RyuScript_VerifyStarterChoice[];

// EWRAM vars
EWRAM_DATA static u8 sObjectEventLoadFlag = 0;
EWRAM_DATA struct WarpData gLastUsedWarp = {0};
EWRAM_DATA static struct WarpData sWarpDestination = {0};  // new warp position
EWRAM_DATA static struct WarpData sFixedDiveWarp = {0};
EWRAM_DATA static struct WarpData sFixedHoleWarp = {0};
EWRAM_DATA static u16 sLastMapSectionId = 0;
EWRAM_DATA static struct InitialPlayerAvatarState sInitialPlayerAvatarState = {0};
EWRAM_DATA static u16 sAmbientCrySpecies = 0;
EWRAM_DATA static bool8 sIsAmbientCryWaterMon = FALSE;
EWRAM_DATA struct LinkPlayerObjectEvent gLinkPlayerObjectEvents[4] = {0};

// const rom data
static const struct WarpData sDummyWarpData =
{
    .mapGroup = -1,
    .mapNum = -1,
    .warpId = -1,
    .x = -1,
    .y = -1,
};

static const u32 sUnusedData[] =
{
    1200, 3600, 1200, 2400, 50, 80, -44, 44
};

static const u16 sRouteMusicSelection[15] = {
    359,
    361,
    401,
    402,
    409,
    411,
    431,
    434,
    491,
    504,
    505,
    506,
    526,
    545,
    547,
};

const struct UCoords32 gDirectionToVectors[] =
{
    [DIR_NONE] =
    {
        .x =  0,
        .y =  0,
    },
    [DIR_SOUTH] =
    {
        .x =  0,
        .y =  1,
    },
    [DIR_NORTH] =
    {
        .x =  0,
        .y = -1,
    },
    [DIR_WEST] =
    {
        .x = -1,
        .y =  0,
    },
    [DIR_EAST] =
    {
        .x =  1,
        .y =  0,
    },
    [DIR_SOUTHWEST] =
    {
        .x = -1,
        .y =  1,
    },
    [DIR_SOUTHEAST] =
    {
        .x =  1,
        .y =  1,
    },
    [DIR_NORTHWEST] =
    {
        .x = -1,
        .y = -1,
    },
    [DIR_NORTHEAST] =
    {
        .x =  1,
        .y = -1,
    },
};

static const struct BgTemplate sOverworldBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct ScanlineEffectParams sFlashEffectParams =
{
    (void *)REG_ADDR_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1,
    0,
};

static u8 MovementEventModeCB_Normal(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 MovementEventModeCB_Ignored(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 MovementEventModeCB_Normal_2(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);

static u8 (*const gLinkPlayerMovementModes[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8) =
{
    MovementEventModeCB_Normal, // MOVEMENT_MODE_FREE
    MovementEventModeCB_Ignored, // MOVEMENT_MODE_FROZEN
    MovementEventModeCB_Normal_2, // MOVEMENT_MODE_SCRIPTED
};

static u8 FacingHandler_DoNothing(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 FacingHandler_DpadMovement(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 FacingHandler_ForcedFacingChange(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);

// These handlers return TRUE if the movement was scripted and successful, and FALSE otherwise.
static bool8 (*const gLinkPlayerFacingHandlers[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8) =
{
    FacingHandler_DoNothing,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DoNothing,
    FacingHandler_DoNothing,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
};

static void MovementStatusHandler_EnterFreeMode(struct LinkPlayerObjectEvent *, struct ObjectEvent *);
static void MovementStatusHandler_TryAdvanceScript(struct LinkPlayerObjectEvent *, struct ObjectEvent *);

// These handlers are run after an attempted movement.
static void (*const gMovementStatusHandler[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *) =
{
    // FALSE:
    MovementStatusHandler_EnterFreeMode,
    // TRUE:
    MovementStatusHandler_TryAdvanceScript,
};

void SetWarpDestinationToHome(void)
{
    u8 homeId = (VarGet(VAR_RYU_PLAYER_HOUSE_ID));
    if (FlagGet(FLAG_RYU_HAS_HOME_REGISTERED) == TRUE) // && (VarGet(VAR_RYU_PLAYER_HOUSE_ID) == id))
    {
        SetWarpDestination(gRyuPropertyData[homeId][2], gRyuPropertyData[homeId][3], 255, gRyuPropertyData[homeId][5], gRyuPropertyData[homeId][6]);
    }
    else
    {
        SetWarpDestinationToLastHealLocation();
    }
    
}

void SetWarpDestinationToLimbo(void) //challenge over
{
        SetWarpDestination(33, 3, 255, 2, 1);
}

void SetWarpDestinationToUnderworld(void) //face death
{
        SetWarpDestination(33, 4, 255, 5, 10);
}


// code
void DoWhiteOut(void)
{
    if (FlagGet(FLAG_RYU_DOING_RYU_CHALLENGE) == TRUE) 
    {
        FlagSet(FLAG_RYU_FAILED_RYU_CHALLENGE);
        FlagClear(FLAG_RYU_DOING_RYU_CHALLENGE);
	    VarSet(VAR_RYU_SPECIAL_CHALLENGE_STATE, 666);
    }

    if (FlagGet(FLAG_RYU_RANDOMBATTLE) == 1)
    {
        FlagClear(FLAG_RYU_RANDOMBATTLE);
        DoSoftReset();
    }

    if (FlagGet(FLAG_RYU_HARDCORE_MODE) == 1)
        RyuWipeParty();

    if (FlagGet(FLAG_RYU_UNDERWORLD) == FALSE)
        FlagSet(FLAG_RYU_PREMATURE_DEATH);

    FlagClear(FLAG_RYU_PERSISTENT_WEATHER);

    if ((CalculatePlayerPartyCount() == 0) && (FlagGet(FLAG_RYU_CHALLENGEFAILED) == 1))
    {
        if (VarGet(VAR_RYU_NGPLUS_COUNT) > 1)
        {
            FlagSet(FLAG_SYS_GAME_CLEAR);
            VarSet(VAR_RYU_NGPLUS_COUNT, ((VarGet(VAR_RYU_NGPLUS_COUNT) - 1)));
            if ((CheckAchievement(ACH_WASTED) == FALSE) && (FlagGet(FLAG_RYU_CHALLENGEFAILED) == 1))
                GiveAchievement(ACH_WASTED);
        }
        HandleSavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        DoSoftReset();
    }
    if (CheckAchievement(ACH_YOU_DIED) == FALSE)
        GiveAchievement(ACH_YOU_DIED);

    FlagClear(FLAG_RYU_WAYSTONE_DISABLED);
    SetMoney(&gSaveBlock1Ptr->money, ((GetMoney(&gSaveBlock1Ptr->money) / 5) * 4));
    HealPlayerParty();
    IncrementGameStat(GAME_STAT_BATTLES_LOST);
    Overworld_ResetStateAfterWhiteOut();
	FlagClear(FLAG_RYU_TC_ENTERED);
	FlagClear(FLAG_RYU_WAYSTONE_DISABLED);
	FlagClear(FLAG_DEFEATED_ELITE_4_SIDNEY);
	FlagClear(FLAG_DEFEATED_ELITE_4_PHOEBE);
	FlagClear(FLAG_DEFEATED_ELITE_4_GLACIA);
	FlagClear(FLAG_DEFEATED_ELITE_4_DRAKE);
	VarSet(VAR_ELITE_4_STATE, 0);
    SetWarpDestinationToHome();
    WarpIntoMap();
}

void DoPartnerWhiteOut(void)
{
    if (FlagGet(FLAG_RYU_RANDOMBATTLE) == 1)
    {
        FlagClear(FLAG_RYU_RANDOMBATTLE);
        DoSoftReset();
    }

    if (FlagGet(FLAG_RYU_HARDCORE_MODE) == 1)
        RyuWipeParty();

    if (CheckAchievement(ACH_YOU_DIED) == FALSE)
        GiveAchievement(ACH_YOU_DIED);

    FlagClear(FLAG_RYU_WAYSTONE_DISABLED);
    SetMoney(&gSaveBlock1Ptr->money, ((GetMoney(&gSaveBlock1Ptr->money) / 5) * 4));
    HealPlayerParty();
    IncrementGameStat(GAME_STAT_BATTLES_LOST);
    Overworld_ResetStateAfterWhiteOut();
	FlagClear(FLAG_RYU_TC_ENTERED);
	FlagClear(FLAG_RYU_WAYSTONE_DISABLED);
	FlagClear(FLAG_DEFEATED_ELITE_4_SIDNEY);
	FlagClear(FLAG_DEFEATED_ELITE_4_PHOEBE);
	FlagClear(FLAG_DEFEATED_ELITE_4_GLACIA);
	FlagClear(FLAG_DEFEATED_ELITE_4_DRAKE);
	VarSet(VAR_ELITE_4_STATE, 0);
    SetWarpDestinationToHome();
    WarpIntoMap();
}

void Overworld_ResetStateAfterFly(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
}

void Overworld_ResetStateAfterTeleport(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
}

void Overworld_ResetStateAfterDigEscRope(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
}

static void Overworld_ResetStateAfterWhiteOut(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
}

static void sub_8084788(void)
{
    ChooseAmbientCrySpecies();
    //UpdateLocationHistoryForRoamer();
    //RoamerMoveToOtherLocationSet();
}

void ResetGameStats(void)
{
    s32 i;

    for (i = 0; i < NUM_GAME_STATS; i++)
        SetGameStat(i, 0);
}

void IncrementGameStat(u8 index)
{
    if (index < NUM_USED_GAME_STATS)
    {
        u32 statVal = GetGameStat(index);
        if (statVal < 0xFFFFFF)
            statVal++;
        else
            statVal = 0xFFFFFF;

        SetGameStat(index, statVal);
    }
}

u32 GetGameStat(u8 index)
{
    if (index >= NUM_USED_GAME_STATS)
        return 0;

    return gSaveBlock1Ptr->gameStats[index] ^ gSaveBlock2Ptr->encryptionKey;
}

void SetGameStat(u8 index, u32 value)
{
    if (index < NUM_USED_GAME_STATS)
        gSaveBlock1Ptr->gameStats[index] = value ^ gSaveBlock2Ptr->encryptionKey;
}

void ApplyNewEncryptionKeyToGameStats(u32 newKey)
{
    u8 i;

    for (i = 0; i < NUM_GAME_STATS; i++)
        ApplyNewEncryptionKeyToWord(&gSaveBlock1Ptr->gameStats[i], newKey);
}

void LoadObjEventTemplatesFromHeader(void)
{
    // Clear map object templates
    CpuFill32(0, gSaveBlock1Ptr->objectEventTemplates, sizeof(gSaveBlock1Ptr->objectEventTemplates));

    // Copy map header events to save block
    CpuCopy32(gMapHeader.events->objectEvents,
              gSaveBlock1Ptr->objectEventTemplates,
              gMapHeader.events->objectEventCount * sizeof(struct ObjectEventTemplate));
}

void LoadSaveblockObjEventScripts(void)
{
    struct ObjectEventTemplate *mapHeaderObjTemplates = gMapHeader.events->objectEvents;
    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;
    s32 i;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
        savObjTemplates[i].script = mapHeaderObjTemplates[i].script;
}

void Overworld_SetObjEventTemplateCoords(u8 localId, s16 x, s16 y)
{
    s32 i;
    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        struct ObjectEventTemplate *objectEventTemplate = &savObjTemplates[i];
        if (objectEventTemplate->localId == localId)
        {
            objectEventTemplate->x = x;
            objectEventTemplate->y = y;
            return;
        }
    }
}

void Overworld_SetObjEventTemplateMovementType(u8 localId, u8 movementType)
{
    s32 i;

    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;
    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        struct ObjectEventTemplate *objectEventTemplate = &savObjTemplates[i];
        if (objectEventTemplate->localId == localId)
        {
            objectEventTemplate->movementType = movementType;
            return;
        }
    }
}

static void InitMapView(void)
{
    ResetFieldCamera();
    CopyMapTilesetsToVram(gMapHeader.mapLayout);
    LoadMapTilesetPalettes(gMapHeader.mapLayout);
    DrawWholeMapView();
    InitTilesetAnimations();
}

const struct MapLayout *GetMapLayout(void)
{
    u16 mapLayoutId = gSaveBlock1Ptr->mapLayoutId;
    if (mapLayoutId)
        return gMapLayouts[mapLayoutId - 1];
    return NULL;
}

void ApplyCurrentWarp(void)
{
    gLastUsedWarp = gSaveBlock1Ptr->location;
    gSaveBlock1Ptr->location = sWarpDestination;
    sFixedDiveWarp = sDummyWarpData;
    sFixedHoleWarp = sDummyWarpData;
}

static void ClearDiveAndHoleWarps(void)
{
    sFixedDiveWarp = sDummyWarpData;
    sFixedHoleWarp = sDummyWarpData;
}

static void SetWarpData(struct WarpData *warp, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp->mapGroup = mapGroup;
    warp->mapNum = mapNum;
    warp->warpId = warpId;
    warp->x = x;
    warp->y = y;
}

static bool32 IsDummyWarp(struct WarpData *warp)
{
    if (warp->mapGroup != -1)
        return FALSE;
    else if (warp->mapNum != -1)
        return FALSE;
    else if (warp->warpId != -1)
        return FALSE;
    else if (warp->x != -1)
        return FALSE;
    else if (warp->y != -1)
        return FALSE;
    else
        return TRUE;
}

struct MapHeader const *const Overworld_GetMapHeaderByGroupAndId(u16 mapGroup, u16 mapNum)
{
    return gMapGroups[mapGroup][mapNum];
}

struct MapHeader const *const GetDestinationWarpMapHeader(void)
{
    return Overworld_GetMapHeaderByGroupAndId(sWarpDestination.mapGroup, sWarpDestination.mapNum);
}

static void LoadCurrentMapData(void)
{
    sLastMapSectionId = gMapHeader.regionMapSectionId;
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gSaveBlock1Ptr->mapLayoutId = gMapHeader.mapLayoutId;
    gMapHeader.mapLayout = GetMapLayout();
}

static void LoadSaveblockMapHeader(void)
{
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gMapHeader.mapLayout = GetMapLayout();
}

static void SetPlayerCoordsFromWarp(void)
{
    if (gSaveBlock1Ptr->location.warpId >= 0 && gSaveBlock1Ptr->location.warpId < gMapHeader.events->warpCount)
    {
        gSaveBlock1Ptr->pos.x = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].x;
        gSaveBlock1Ptr->pos.y = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].y;
    }
    else if (gSaveBlock1Ptr->location.x >= 0 && gSaveBlock1Ptr->location.y >= 0)
    {
        gSaveBlock1Ptr->pos.x = gSaveBlock1Ptr->location.x;
        gSaveBlock1Ptr->pos.y = gSaveBlock1Ptr->location.y;
    }
    else
    {
        gSaveBlock1Ptr->pos.x = gMapHeader.mapLayout->width / 2;
        gSaveBlock1Ptr->pos.y = gMapHeader.mapLayout->height / 2;
    }
}

void WarpIntoMap(void)
{
    ApplyCurrentWarp();
    LoadCurrentMapData();
    SetPlayerCoordsFromWarp();
}

void SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sWarpDestination, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToMapWarp(s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpDestination(mapGroup, mapNum, warpId, -1, -1);
}

void SetDynamicWarp(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpData(&gSaveBlock1Ptr->dynamicWarp, mapGroup, mapNum, warpId, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
}

void SetDynamicWarpWithCoords(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->dynamicWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToDynamicWarp(u8 unusedWarpId)
{
    sWarpDestination = gSaveBlock1Ptr->dynamicWarp;
}

void SetWarpDestinationToHealLocation(u8 healLocationId)
{
    const struct HealLocation *warp = GetHealLocation(healLocationId);
    if (warp)
        SetWarpDestination(warp->group, warp->map, -1, warp->x, warp->y);
}

void SetWarpDestinationToLastHealLocation(void)
{
    sWarpDestination = gSaveBlock1Ptr->lastHealLocation;
}

void SetLastHealLocationWarp(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);
    if (healLocation)
        SetWarpData(&gSaveBlock1Ptr->lastHealLocation, healLocation->group, healLocation->map, -1, healLocation->x, healLocation->y);
}

void UpdateEscapeWarp(s16 x, s16 y)
{
    u8 currMapType = GetCurrentMapType();
    u8 destMapType = GetMapTypeByGroupAndId(sWarpDestination.mapGroup, sWarpDestination.mapNum);
    if (IsMapTypeOutdoors(currMapType) && IsMapTypeOutdoors(destMapType) != TRUE)
        SetEscapeWarp(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x - 7, y - 6);
}

void SetEscapeWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->escapeWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToEscapeWarp(void)
{
    sWarpDestination = gSaveBlock1Ptr->escapeWarp;
}

void SetFixedDiveWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sFixedDiveWarp, mapGroup, mapNum, warpId, x, y);
}

static void SetWarpDestinationToDiveWarp(void)
{
    sWarpDestination = sFixedDiveWarp;
}

void SetFixedHoleWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sFixedHoleWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToFixedHoleWarp(s16 x, s16 y)
{
    if (IsDummyWarp(&sFixedHoleWarp) == TRUE)
        sWarpDestination = gLastUsedWarp;
    else
        SetWarpDestination(sFixedHoleWarp.mapGroup, sFixedHoleWarp.mapNum, -1, x, y);
}

static void SetWarpDestinationToContinueGameWarp(void)
{
    sWarpDestination = gSaveBlock1Ptr->continueGameWarp;
}

void SetContinueGameWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->continueGameWarp, mapGroup, mapNum, warpId, x, y);
}

void SetContinueGameWarpToHealLocation(u8 healLocationId)
{
    const struct HealLocation *warp = GetHealLocation(healLocationId);
    if (warp)
        SetWarpData(&gSaveBlock1Ptr->continueGameWarp, warp->group, warp->map, -1, warp->x, warp->y);
}

void SetContinueGameWarpToDynamicWarp(int unused)
{
    gSaveBlock1Ptr->continueGameWarp = gSaveBlock1Ptr->dynamicWarp;
}

const struct MapConnection *GetMapConnection(u8 dir)
{
    s32 i;
    s32 count = gMapHeader.connections->count;
    const struct MapConnection *connection = gMapHeader.connections->connections;

    if (connection == NULL)
        return NULL;

    for(i = 0; i < count; i++, connection++)
        if (connection->direction == dir)
            return connection;

    return NULL;
}

static bool8 SetDiveWarp(u8 dir, u16 x, u16 y)
{
    const struct MapConnection *connection = GetMapConnection(dir);

    if (connection != NULL)
    {
        SetWarpDestination(connection->mapGroup, connection->mapNum, -1, x, y);
    }
    else
    {
        RunOnDiveWarpMapScript();
        if (IsDummyWarp(&sFixedDiveWarp))
            return FALSE;
        SetWarpDestinationToDiveWarp();
    }
    return TRUE;
}

bool8 SetDiveWarpEmerge(u16 x, u16 y)
{
    return SetDiveWarp(CONNECTION_EMERGE, x, y);
}

bool8 SetDiveWarpDive(u16 x, u16 y)
{
    return SetDiveWarp(CONNECTION_DIVE, x, y);
}

void LoadMapFromCameraTransition(u8 mapGroup, u8 mapNum)
{
    s32 paletteIndex;

    SetWarpDestination(mapGroup, mapNum, -1, -1, -1);


    ApplyCurrentWarp();
    LoadCurrentMapData();
    LoadObjEventTemplatesFromHeader();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetDexNavSearch();
    DoTimeBasedEvents();
    SetSav1WeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    SetDefaultFlashLevel();

    if (gMapHeader.regionMapSectionId != 0x3A)
        LoadMapMusic();

    Overworld_ClearSavedMusic();
    RunOnTransitionMapScript();
    InitMap();
    CopySecondaryTilesetToVramUsingHeap(gMapHeader.mapLayout);
    LoadSecondaryTilesetPalette(gMapHeader.mapLayout);

    for (paletteIndex = 6; paletteIndex < 13; paletteIndex++)
        ApplyWeatherGammaShiftToPal(paletteIndex);

    InitSecondaryTilesetAnimation();
    DoCurrentWeather();
    ResetFieldTasksArgs();
    RunOnResumeMapScript();

    if (gMapHeader.regionMapSectionId != MAPSEC_BATTLE_FRONTIER 
     || gMapHeader.regionMapSectionId != sLastMapSectionId)
        ShowMapNamePopup();
}

static void LoadMapFromWarp(bool32 a1)
{
    bool8 isOutdoors;
    bool8 isIndoors;

    LoadCurrentMapData();
    if (!(sObjectEventLoadFlag & SKIP_OBJECT_EVENT_LOAD))
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            LoadBattlePyramidObjectEventTemplates();
        else if (InTrainerHill())
            LoadTrainerHillObjectEventTemplates();
        else
            LoadObjEventTemplatesFromHeader();
    }

    isOutdoors = IsMapTypeOutdoors(gMapHeader.mapType);
    isIndoors = IsMapTypeIndoors(gMapHeader.mapType);

    CheckLeftFriendsSecretBase();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetDexNavSearch();
    if (a1 != 1)
        DoTimeBasedEvents();
    SetSav1WeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();

    if (isOutdoors)
        if (FlagGet(FLAG_RYU_HAS_FOLLOWER) == 1)
            RyuAddFollower();

    SetDefaultFlashLevel();
    RunOnTransitionMapScript();
    //UpdateLocationHistoryForRoamer();
    //RoamerMoveToOtherLocationSet();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        InitBattlePyramidMap(FALSE);
    else if (InTrainerHill())
        InitTrainerHillMap();
    else
        InitMap();

    if (a1 != TRUE && isIndoors)
    {
        UpdateTVScreensOnMap(gBackupMapLayout.width, gBackupMapLayout.height);
        InitSecretBaseAppearance(TRUE);
    }
}

void RyuAddFollower(void)
{
    u8 graphicsId = (VarGet(VAR_RYU_FOLLOWER_ID));
    u8 *script = RyuFollowerSelectNPCScript;

    if ((GetPlayerFacingDirection()) == DIR_NORTH)
    {
        CreateFollowerObjectEvent(graphicsId, script, DIR_SOUTH);
    }
    else if ((GetPlayerFacingDirection()) == DIR_SOUTH)
    {
        CreateFollowerObjectEvent(graphicsId, script, DIR_NORTH);
    }
    else
    { 
        CreateFollowerObjectEvent(graphicsId, script, DIR_SOUTH);
    }

}

void ResetInitialPlayerAvatarState(void)
{
    sInitialPlayerAvatarState.direction = DIR_NORTH;
    sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
    if (FlagGet(FLAG_RYU_HAS_FOLLOWER) == 1)
        RyuAddFollower();
}

void StoreInitialPlayerAvatarState(void)
{
    sInitialPlayerAvatarState.direction = GetPlayerFacingDirection();

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_MACH_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ACRO_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_SURFING;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_UNDERWATER;
    else
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
}

static struct InitialPlayerAvatarState *GetInitialPlayerAvatarState(void)
{
    struct InitialPlayerAvatarState playerStruct;
    u8 mapType = GetCurrentMapType();
    u16 metatileBehavior = GetCenterScreenMetatileBehavior();
    u8 transitionFlags = GetAdjustedInitialTransitionFlags(&sInitialPlayerAvatarState, metatileBehavior, mapType);
    playerStruct.transitionFlags = transitionFlags;
    playerStruct.direction = GetAdjustedInitialDirection(&sInitialPlayerAvatarState, transitionFlags, metatileBehavior, mapType);
    sInitialPlayerAvatarState = playerStruct;
    return &sInitialPlayerAvatarState;
}

static u8 GetAdjustedInitialTransitionFlags(struct InitialPlayerAvatarState *playerStruct, u16 metatileBehavior, u8 mapType)
{
    if (mapType != MAP_TYPE_INDOOR && FlagGet(FLAG_SYS_CRUISE_MODE))
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else if (mapType == MAP_TYPE_UNDERWATER)
        return PLAYER_AVATAR_FLAG_UNDERWATER;
    else if (MetatileBehavior_IsSurfableWaterOrUnderwater(metatileBehavior) == TRUE)
        return PLAYER_AVATAR_FLAG_SURFING;
    else if (Overworld_IsBikingAllowed() != TRUE)
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else if (playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_MACH_BIKE)
        return PLAYER_AVATAR_FLAG_MACH_BIKE;
    else if (playerStruct->transitionFlags != PLAYER_AVATAR_FLAG_ACRO_BIKE)
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else
        return PLAYER_AVATAR_FLAG_ACRO_BIKE;
}

static u8 GetAdjustedInitialDirection(struct InitialPlayerAvatarState *playerStruct, u8 transitionFlags, u16 metatileBehavior, u8 mapType)
{
    if (FlagGet(FLAG_SYS_CRUISE_MODE) && mapType == MAP_TYPE_OCEAN_ROUTE)
        return DIR_EAST;
    else if (MetatileBehavior_IsDeepSouthWarp(metatileBehavior) == TRUE)
        return DIR_NORTH;
    else if (MetatileBehavior_IsNonAnimDoor(metatileBehavior) == TRUE || MetatileBehavior_IsDoor(metatileBehavior) == TRUE)
        return DIR_SOUTH;
    else if (MetatileBehavior_IsSouthArrowWarp(metatileBehavior) == TRUE)
        return DIR_NORTH;
    else if (MetatileBehavior_IsNorthArrowWarp(metatileBehavior) == TRUE)
        return DIR_SOUTH;
    else if (MetatileBehavior_IsWestArrowWarp(metatileBehavior) == TRUE)
        return DIR_EAST;
    else if (MetatileBehavior_IsEastArrowWarp(metatileBehavior) == TRUE)
        return DIR_WEST;
    else if ((playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_UNDERWATER  && transitionFlags == PLAYER_AVATAR_FLAG_SURFING)
          || (playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_SURFING && transitionFlags == PLAYER_AVATAR_FLAG_UNDERWATER))
        return playerStruct->direction;
    else if (MetatileBehavior_IsLadder(metatileBehavior) == TRUE)
        return playerStruct->direction;
    else
        return DIR_SOUTH;
}

static u16 GetCenterScreenMetatileBehavior(void)
{
    return MapGridGetMetatileBehaviorAt(gSaveBlock1Ptr->pos.x + 7, gSaveBlock1Ptr->pos.y + 7);
}

bool32 Overworld_IsBikingAllowed(void)
{
    if (!(gMapHeader.flags & MAP_ALLOW_CYCLING))
        return FALSE;
    else
        return TRUE;
}

void SetDefaultFlashLevel(void){}

void Overworld_SetFlashLevel(s32 flashLevel){}

u8 Overworld_GetFlashLevel(void)
{
    return 0;
}

void SetCurrentMapLayout(u16 mapLayoutId)
{
    gSaveBlock1Ptr->mapLayoutId = mapLayoutId;
    gMapHeader.mapLayout = GetMapLayout();
}

void SetObjectEventLoadFlag(u8 flag)
{
    sObjectEventLoadFlag = flag;
}

// Unused, sObjectEventLoadFlag is read directly
static u8 GetObjectEventLoadFlag(void)
{
    return sObjectEventLoadFlag;
}

u16 GetLocationMusic(struct WarpData *warp)
{
    return Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum)->music;    
}

u16 GetCurrLocationDefaultMusic(void)
{
    u16 music;
    music = GetLocationMusic(&gSaveBlock1Ptr->location);
    return music;
}

u16 GetWarpDestinationMusic(void)
{
    u16 music = GetLocationMusic(&sWarpDestination);

        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAUVILLE_CITY) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAUVILLE_CITY))
            return MUS_DOORO_X1;
        else
            return MUS_GRANROAD;

}

void Overworld_ResetMapMusic(void)
{   
    ResetMapMusic();
}

void Overworld_PlaySpecialMapMusic(void)
{
    LoadMapMusic();
}

void Overworld_SetSavedMusic(u16 songNum)
{
    gSaveBlock1Ptr->savedMusic = songNum;
}

void Overworld_ClearSavedMusic(void)
{
    gSaveBlock1Ptr->savedMusic = MUS_DUMMY;
}

void LoadMapMusic(void)
{
    u16 newMusic = 0;
    u16 currentMusic = GetCurrentMapMusic();
    u16 randomMusic = (sRouteMusicSelection[(Random() % ARRAY_COUNT(sRouteMusicSelection))]);
    u8 step = 1;

    if ((currentMusic > 557) || (currentMusic < 350))
    {
        newMusic = 350;
    }

    if (GetCurrentMapType() == (MAP_TYPE_CITY || MAP_TYPE_TOWN))
    {
        newMusic = GetCurrLocationDefaultMusic();
        step = 1;
    }
    if ((GetCurrentMapType() == MAP_TYPE_ROUTE) && (FlagGet(FLAG_RYU_RANDOMIZE_MUSIC) == 1))
    {
        step = 2;
        newMusic = randomMusic;
    }
    if (GetCurrentMapType() == (MAP_TYPE_INDOOR || MAP_TYPE_UNDERGROUND))
    {
        step = 3;
        newMusic = GetCurrLocationDefaultMusic();
    }
    if (newMusic == 0)
    {
        step = 5;
        newMusic = GetCurrLocationDefaultMusic();
    }
    if (newMusic != currentMusic)
    {
        switch (step)
        {
            case 1:
            case 3:
            case 5:
            {
                FadeOutAndPlayNewMapMusic(GetCurrLocationDefaultMusic(), 4);
                break;
            }
            case 2:
            {
                FadeOutAndPlayNewMapMusic(randomMusic, 4);
                break;
            }
            case 4:
            {
                break;
            }
            case 6:
            {
                StopMapMusic();
                break;
            }
            default:
            {
                FadeOutAndPlayNewMapMusic(350, 4);
                break;
            }    
        }
    }
}

void Overworld_ChangeMusicToDefault(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != GetCurrLocationDefaultMusic())
        FadeOutAndPlayNewMapMusic(GetCurrLocationDefaultMusic(), 8);
}

void Overworld_ChangeMusicTo(u16 newMusic)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != newMusic && currentMusic != MUS_ABNORMAL_WEATHER)
        FadeOutAndPlayNewMapMusic(newMusic, 8);
}

u8 GetMapMusicFadeoutSpeed(void)
{
    const struct MapHeader *mapHeader = GetDestinationWarpMapHeader();
    if (IsMapTypeIndoors(mapHeader->mapType) == TRUE)
        return 2;
    else
        return 4;
}

void TryFadeOutOldMapMusic(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    u16 warpMusic = GetWarpDestinationMusic();
    if (!(warpMusic == GetCurrentMapMusic()))
    {
        FadeOutMapMusic(GetMapMusicFadeoutSpeed());
    }
}

bool8 BGMusicStopped(void)
{
    return IsNotWaitingForBGMStop();
}

void Overworld_FadeOutMapMusic(void)
{
    FadeOutMapMusic(4);
}

static void PlayAmbientCry(void)
{
    s16 x, y;
    s8 pan;
    s8 volume;

    PlayerGetDestCoords(&x, &y);
    if (sIsAmbientCryWaterMon == TRUE
     && !MetatileBehavior_IsSurfableWaterOrUnderwater(MapGridGetMetatileBehaviorAt(x, y)))
        return;
    pan = (Random() % 88) + 212;
    volume = (Random() % 30) + 50;
    PlayCry2(sAmbientCrySpecies, pan, volume, 1);
}

void UpdateAmbientCry(s16 *state, u16 *delayCounter)
{
    u8 i, monsCount, divBy;

    switch (*state)
    {
    case 0:
        if (sAmbientCrySpecies == SPECIES_NONE)
            *state = 4;
        else
            *state = 1;
        break;
    case 1:
        *delayCounter = (Random() % 2400) + 1200;
        *state = 3;
        break;
    case 2:
        divBy = 1;
        monsCount = CalculatePlayerPartyCount();
        for (i = 0; i < monsCount; i++)
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
                && GetMonAbility(&gPlayerParty[0]) == ABILITY_SWARM)
            {
                divBy = 2;
                break;
            }
        }
        *delayCounter = ((Random() % 1200) + 1200) / divBy;
        *state = 3;
        break;
    case 3:
        (*delayCounter)--;
        if (*delayCounter == 0)
        {
            PlayAmbientCry();
            *state = 2;
        }
        break;
    case 4:
        break;
    }
}

static void ChooseAmbientCrySpecies(void)
{
    if ((gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE130)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE130))
     && !IsMirageIslandPresent())
    {
        // Only play water pokemon cries on this route
        // when Mirage Island is not present
        sIsAmbientCryWaterMon = TRUE;
        sAmbientCrySpecies = GetLocalWaterMon();
    }
    else
    {
        sAmbientCrySpecies = GetLocalWildMon(&sIsAmbientCryWaterMon);
    }
}

u8 GetMapTypeByGroupAndId(s8 mapGroup, s8 mapNum)
{
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->mapType;
}

u8 GetMapTypeByWarpData(struct WarpData *warp)
{
    return GetMapTypeByGroupAndId(warp->mapGroup, warp->mapNum);
}

u8 GetCurrentMapType(void)
{
    return GetMapTypeByWarpData(&gSaveBlock1Ptr->location);
}

u8 GetLastUsedWarpMapType(void)
{
    return GetMapTypeByWarpData(&gLastUsedWarp);
}

bool8 IsMapTypeOutdoors(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_UNDERWATER
     || mapType == MAP_TYPE_CITY
     || mapType == MAP_TYPE_OCEAN_ROUTE)
        return TRUE;
    else
        return FALSE;
}

bool8 Overworld_MapTypeAllowsTeleportAndFly(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_OCEAN_ROUTE
     || mapType == MAP_TYPE_CITY)
        return TRUE;
    else
        return FALSE;
}

bool8 IsMapTypeIndoors(u8 mapType)
{
    if (mapType == MAP_TYPE_INDOOR
     || mapType == MAP_TYPE_SECRET_BASE)
        return TRUE;
    else
        return FALSE;
}

u8 GetSavedWarpRegionMapSectionId(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->dynamicWarp.mapGroup, gSaveBlock1Ptr->dynamicWarp.mapNum)->regionMapSectionId;
}

u8 GetCurrentRegionMapSectionId(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->regionMapSectionId;
}

u8 GetCurrentMapBattleScene(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->battleType;
}

static void InitOverworldBgs(void)
{
    InitBgsFromTemplates(0, sOverworldBgTemplates, ARRAY_COUNT(sOverworldBgTemplates));
    SetBgAttribute(1, BG_ATTR_MOSAIC, 1);
    SetBgAttribute(2, BG_ATTR_MOSAIC, 1);
    SetBgAttribute(3, BG_ATTR_MOSAIC, 1);
    gBGTilemapBuffers2 = AllocZeroed(BG_SCREEN_SIZE);
    gBGTilemapBuffers1 = AllocZeroed(BG_SCREEN_SIZE);
    gBGTilemapBuffers3 = AllocZeroed(BG_SCREEN_SIZE);
    SetBgTilemapBuffer(1, gBGTilemapBuffers2);
    SetBgTilemapBuffer(2, gBGTilemapBuffers1);
    SetBgTilemapBuffer(3, gBGTilemapBuffers3);
    InitStandardTextBoxWindows();
}

void CleanupOverworldWindowsAndTilemaps(void)
{
    //ClearMirageTowerPulseBlendEffect();
    FreeAllOverworldWindowBuffers();
    if (gBGTilemapBuffers3)
        FREE_AND_SET_NULL(gBGTilemapBuffers3);
    if (gBGTilemapBuffers1)
        FREE_AND_SET_NULL(gBGTilemapBuffers1);
    if (gBGTilemapBuffers2)
        FREE_AND_SET_NULL(gBGTilemapBuffers2);
}

bool32 IsUpdateLinkStateCBActive(void)
{
    if (gMain.callback1 == CB1_UpdateLinkState)
        return TRUE;
    else
        return FALSE;
}

static void DoCB1_Overworld(u16 newKeys, u16 heldKeys)
{
    struct FieldInput inputStruct;

    UpdatePlayerAvatarTransitionState();
    FieldClearPlayerInput(&inputStruct);
    FieldGetPlayerInput(&inputStruct, newKeys, heldKeys);
    if (!ScriptContext2_IsEnabled())
    {
        if (ProcessPlayerFieldInput(&inputStruct) == 1)
        {
            ScriptContext2_Enable();
            HideMapNamePopUpWindow();
        }
        else
        {
            PlayerStep(inputStruct.dpadDirection, newKeys, heldKeys);
        }
    }
}

void CB1_Overworld(void)
{
    if (gMain.callback2 == CB2_Overworld)
        DoCB1_Overworld(gMain.newKeys, gMain.heldKeys);
}

static void OverworldBasic(void)
{
    ScriptContext2_RunScript();
    RunTasks();
    AnimateSprites();
    CameraUpdate();
    UpdateCameraPanning();
    BuildOamBufferNoOrder();
    UpdatePaletteFade();
    UpdateTilesetAnimations();
    DoScheduledBgTilemapCopiesToVram();
    DnsApplyFilters();
}

// This CB2 is used when starting
void CB2_OverworldBasic(void)
{
    OverworldBasic();
}

//
void VBCB_FullscreenCutscene(void);
//

void CB2_Overworld(void)
{
    bool32 fading = (gPaletteFade.active != 0) && gMain.vblankCallback != VBCB_FullscreenCutscene;
    if (fading)
        SetVBlankCallback(NULL);
    OverworldBasic();
    if (fading)
        SetFieldVBlankCallback();
}

void SetMainCallback1(MainCallback cb)
{
    gMain.callback1 = cb;
}

// This function is never called.
void SetUnusedCallback(void *func)
{
    sUnusedOverworldCallback = func;
}

static bool8 RunFieldCallback(void)
{
    if (gFieldCallback2)
    {
        if (!gFieldCallback2())
        {
            return FALSE;
        }
        else
        {
            gFieldCallback2 = NULL;
            gFieldCallback = NULL;
        }
    }
    else
    {
        if (gFieldCallback)
            gFieldCallback();
        else
            FieldCB_DefaultWarpExit();

        gFieldCallback = NULL;
    }

    return TRUE;
}


void ClearKeyItems(void)
{
    int i;
    for (i = 0; i < BAG_KEYITEMS_COUNT; i++)
    {
        gSaveBlock1Ptr->bagPocket_KeyItems[i].itemId = ITEM_NONE;
        gSaveBlock1Ptr->bagPocket_KeyItems[i].quantity = 0;
    }
}

void ClearPokedexFlags(void)
{
    gUnusedPokedexU8 = 0;
    memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));
}


void CB2_NewGame(void)
{
    bool8 isNGPlus = FALSE;
    bool8 hasExpDrive = FALSE;
    bool8 hasWaystone = FALSE;
    bool8 hasForecaster = FALSE;
    bool8 hasImprinter = FALSE;
    bool8 hasWirelessPC = FALSE;
    bool8 hasExpShare = FALSE;
    bool8 hasMachBike = FALSE;
    bool8 hasAcroBike = FALSE;
    bool8 hasDexNav = FALSE;
    bool8 hasShinyCharm = FALSE;
    bool8 hasOvalCharm = FALSE;
    bool8 hasMegaBracelet = FALSE;
    bool8 hasRecipeBook = FALSE;
    bool8 hasMomFollower = FALSE;
    u16 playerLifeSkills[3][2] = {0};
    bool8 hasRealEstate = gSaveBlock2Ptr->playerIsRealtor;
    bool8 hasSuperTraining = FALSE;

    playerLifeSkills[0][0] = VarGet(VAR_RYU_PLAYER_MINING_SKILL);
    playerLifeSkills[0][1] = VarGet(VAR_RYU_PLAYER_MINING_SKILL_EXP);
    playerLifeSkills[1][0] = VarGet(VAR_RYU_PLAYER_BOTANY_SKILL);
    playerLifeSkills[1][1] = VarGet(VAR_RYU_PLAYER_BOTANY_SKILL_EXP);
    playerLifeSkills[2][0] = VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL);
    playerLifeSkills[2][1] = VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP);

    if (FlagGet(FLAG_SYS_GAME_CLEAR) == 1)
        isNGPlus = TRUE;

    if (CheckBagHasItem(ITEM_WAYSTONE, 1))
        hasWaystone = TRUE;

    if (CheckBagHasItem(ITEM_EXP_DRIVE, 1))
        hasExpDrive = TRUE;

    if (CheckBagHasItem(ITEM_FORECASTER, 1))
        hasForecaster = TRUE;

    if (FlagGet(FLAG_RYU_DS_MOM_AVAILABLE) == TRUE)
        hasMomFollower = TRUE;

    if (CheckBagHasItem(ITEM_IMPRINTER, 1))
        hasImprinter = TRUE;

    if (CheckBagHasItem(ITEM_WIRELESSPC, 1))
        hasWirelessPC = TRUE;

    if (CheckBagHasItem(ITEM_EXP_SHARE, 1))
        hasExpShare = TRUE;

    if (CheckBagHasItem(ITEM_MACH_BIKE, 1))
        hasMachBike = TRUE;
        
    if (CheckBagHasItem(ITEM_SHINY_CHARM, 1))
        hasShinyCharm = TRUE;

    if (CheckBagHasItem(ITEM_OVAL_CHARM, 1))
        hasOvalCharm = TRUE;

    if (CheckBagHasItem(ITEM_ACRO_BIKE, 1))
        hasAcroBike = TRUE;

    if (CheckBagHasItem(ITEM_MEGA_BRACELET, 1))
        hasMegaBracelet = TRUE;

    if (FlagGet(FLAG_SYS_DEXNAV_GET) == 1)
        hasDexNav = TRUE;
    
    if (CheckBagHasItem(ITEM_RECIPE_BOOK, 1))
        hasRecipeBook = TRUE;

    if (FlagGet(FLAG_RYU_HAS_SUPER_TRAINING) == TRUE)
        hasSuperTraining = TRUE;


    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    NewGameInitData();
    ResetInitialPlayerAvatarState();
    PlayTimeCounter_Start();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    gFieldCallback2 = NULL;
    DoMapLoadLoop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
    if (isNGPlus == TRUE)
    {

        if (hasExpDrive == TRUE)
            FlagSet(FLAG_RYU_HAS_EXP_DRIVE);

        if (hasImprinter == TRUE)
            FlagSet(FLAG_RYU_HAS_IMPRINTER);

        if (hasForecaster == TRUE)
            FlagSet(FLAG_RYU_HAS_FORECASTER);

        if (hasWaystone == TRUE)
            FlagSet(FLAG_RYU_HAS_WAYSTONE);

        if (hasWirelessPC == TRUE)
            FlagSet(FLAG_RYU_HAS_WIRELESSPC);

        if (hasExpShare == TRUE)
            FlagSet(FLAG_RYU_HAS_EXPSHARE);

        if (hasDexNav == TRUE)
            FlagSet(FLAG_SYS_DEXNAV_GET);

        if (hasOvalCharm == TRUE)
            FlagSet(FLAG_RYU_HAS_OVAL_CHARM);

        if (hasShinyCharm == TRUE)
            FlagSet(FLAG_RYU_HAS_SHINY_CHARM);
        
        if (hasMegaBracelet == TRUE)
            FlagSet(FLAG_RYU_HAS_MEGA_BRACELET);

        if (hasRecipeBook == TRUE)
            FlagSet(FLAG_RYU_HAS_RECIPE_BOOK);

        if (hasMomFollower == TRUE)
            FlagSet(FLAG_RYU_DS_MOM_AVAILABLE);

        if (hasRealEstate == TRUE)
            gSaveBlock2Ptr->playerIsRealtor = 1;

        if (hasSuperTraining == TRUE)
            FlagSet(FLAG_RYU_HAS_SUPER_TRAINING);

        FlagSet(FLAG_SYS_POKEDEX_GET);
        FlagSet(FLAG_SYS_NATIONAL_DEX);
        FlagSet(FLAG_RYU_ISNGPLUS);
        VarSet(VAR_RYU_NGPLUS_COUNT, VarGet(VAR_RYU_NGPLUS_COUNT) + 1);
        
        //this should make life skills persist between new game +'s. If they aren't changed by the above code, they will set to zero.
        VarSet(VAR_RYU_PLAYER_MINING_SKILL, playerLifeSkills[0][0]);
        VarSet(VAR_RYU_PLAYER_MINING_SKILL_EXP, playerLifeSkills[0][1]);
        VarSet(VAR_RYU_PLAYER_BOTANY_SKILL, playerLifeSkills[1][0]);
        VarSet(VAR_RYU_PLAYER_BOTANY_SKILL_EXP, playerLifeSkills[1][1]);
        VarSet(VAR_RYU_PLAYER_ALCHEMY_SKILL, playerLifeSkills[2][0]);
        VarSet(VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP, playerLifeSkills[2][1]);
    }
    else
    {
        ResetPokemonStorageSystem();
    }
}

void CB2_WhiteOut(void)
{
    u8 state;

    if (FlagGet(FLAG_RYU_SPECIAL_STORY_WHITEOUT) == TRUE)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else if (++gMain.state >= 120)
    {
        FieldClearVBlankHBlankCallbacks();
        StopMapMusic();
        DoWhiteOut();
        ResetInitialPlayerAvatarState();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        gFieldCallback = FieldCB_WarpExitFadeFromBlack;
        state = 0;
        DoMapLoadLoop(&state);
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_LoadMap(void)
{
    FieldClearVBlankHBlankCallbacks();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    SetMainCallback1(NULL);
    SetMainCallback2(CB2_DoChangeMap);
    gMain.savedCallback = CB2_LoadMap2;
}

static void CB2_LoadMap2(void)
{
    DoMapLoadLoop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
    ResetDexNavSearch();
    FlagClear(FLAG_RYU_PAUSE_UB_ENCOUNTER);
}

void CB2_ReturnToFieldContestHall(void)
{
    if (!gMain.state)
    {
        FieldClearVBlankHBlankCallbacks();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        SetMainCallback1(NULL);
    }
    if (LoadMapInStepsLocal(&gMain.state, TRUE))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToFieldCableClub(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ReturnToFieldWirelessLink;
    SetMainCallback2(CB2_LoadMapOnReturnToFieldCableClub);
}

static void CB2_LoadMapOnReturnToFieldCableClub(void)
{
    if (LoadMapInStepsLink(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_UpdateLinkState);
        ResetAllMultiplayerState();
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToFieldLocal(void)
{
    if (ReturnToFieldLocal(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback2(CB2_Overworld);
    }

    if (FlagGet(FLAG_RYU_HARDCORE_MODE) == 1)
        RyuKillMon();
} 

void CB2_ReturnToField(void)
{
        FieldClearVBlankHBlankCallbacks();
        SetMainCallback2(CB2_ReturnToFieldLocal);
}

static void CB2_ReturnToFieldLink(void)
{
    if (!sub_8087598() && ReturnToFieldLink(&gMain.state))
        SetMainCallback2(CB2_Overworld);
}

void CB2_ReturnToFieldFromMultiplayer(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    SetMainCallback1(CB1_UpdateLinkState);
    ResetAllMultiplayerState();

    if (gWirelessCommType != 0)
        gFieldCallback = FieldCB_ReturnToFieldWirelessLink;
    else
        gFieldCallback = FieldCB_ReturnToFieldCableLink;

    ScriptContext1_Init();
    ScriptContext2_Disable();
    CB2_ReturnToField();
}

void CB2_ReturnToFieldWithOpenMenu(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback2 = FieldCB_ReturnToFieldOpenStartMenu;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScript(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ContinueScript;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScriptPlayMapMusic(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
    CB2_ReturnToField();
}

void sub_80861E8(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_WarpExitFadeFromBlack;
    CB2_ReturnToField();
}

static void sub_8086204(void)
{
    if (SHOW_MAP_NAME_ENABLED && SecretBaseMapPopupEnabled() == TRUE)
        ShowMapNamePopup();
    FieldCB_WarpExitFadeFromBlack();
}

void CB2_ContinueSavedGame(void)
{
    u8 trainerHillMapId;

    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    if (gSaveFileStatus == SAVE_STATUS_ERROR)
        ResetWinStreaks();

    LoadSaveblockMapHeader();
    ClearDiveAndHoleWarps();
    trainerHillMapId = GetCurrentTrainerHillMapId();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        LoadBattlePyramidFloorObjectEventScripts();
    else if (trainerHillMapId != 0 && trainerHillMapId != TRAINER_HILL_ENTRANCE)
        LoadTrainerHillFloorObjectEventScripts();
    else
        LoadSaveblockObjEventScripts();

    UnfreezeObjectEvents();
    DoTimeBasedEvents();
    sub_8084788();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        InitBattlePyramidMap(TRUE);
    else if (trainerHillMapId != 0)
        InitTrainerHillMap();
    else
        InitMapFromSavedGame();

    PlayTimeCounter_Start();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    if (FlagGet(FLAG_RYU_RANDOMBATTLE) == 1)
    {
        ScriptContext2_Enable();
        ScriptContext1_SetupScript(Ryu_StartRandomBattle);
    }

    if (FlagGet(FLAG_RYU_CHALLENGEFAILED) == 1)
    {
        FlagSet(FLAG_HIDE_MAP_NAME_POPUP);
        ScriptContext2_Enable();
        ScriptContext1_SetupScript(Ryu_PlayerFailedChallengeHardcore);
    }

    if (UseContinueGameWarp() == TRUE)
    {
        ClearContinueGameWarpStatus();
        SetWarpDestinationToContinueGameWarp();
        WarpIntoMap();
        TryPutTodaysRivalTrainerOnAir();
        SetMainCallback2(CB2_LoadMap);
    }
    else
    {
        TryPutTodaysRivalTrainerOnAir();
        gFieldCallback = sub_8086204;
        SetMainCallback1(CB1_Overworld);
        CB2_ReturnToField();
    }
}

static void FieldClearVBlankHBlankCallbacks(void)
{
    if (UsedPokemonCenterWarp() == TRUE)
        CloseLink();

    if (gWirelessCommType != 0)
    {
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        DisableInterrupts(INTR_FLAG_HBLANK);
    }
    else
    {
        u16 savedIme = REG_IME;
        REG_IME = 0;
        REG_IE &= ~INTR_FLAG_HBLANK;
        REG_IE |= INTR_FLAG_VBLANK;
        REG_IME = savedIme;
    }

    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void SetFieldVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_Field);
}

static void VBlankCB_Field(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
    FieldUpdateBgTilemapScroll();
    TransferPlttBuffer();
    TransferTilesetAnimsBuffer();
}

static void InitCurrentFlashLevelScanlineEffect(void)
{
    u8 flashLevel;

    if (InBattlePyramid_())
    {
        WriteBattlePyramidViewScanlineEffectBuffer();
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
    else if ((flashLevel = Overworld_GetFlashLevel()))
    {
        WriteFlashScanlineEffectBuffer(flashLevel);
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
}

static bool32 LoadMapInStepsLink(u8 *state)
{
    switch (*state)
    {
    case 0:
        InitOverworldBgs();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        ResetMirageTowerAndSaveBlockPtrs();
        sub_80867D8();
        (*state)++;
        break;
    case 1:
        LoadMapFromWarp(TRUE);
        (*state)++;
        break;
    case 2:
        ResumeMap(TRUE);
        (*state)++;
        break;
    case 3:
        OffsetCameraFocusByLinkPlayerId();
        InitObjectEventsLink();
        SpawnLinkPlayers();
        SetCameraToTrackGuestPlayer();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 5:
        ResetFieldCamera();
        (*state)++;
        break;
    case 6:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 LoadMapInStepsLocal(u8 *state, bool32 a2)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        LoadMapFromWarp(a2);
        (*state)++;
        break;
    case 1:
        ResetMirageTowerAndSaveBlockPtrs();
        sub_80867D8();
        (*state)++;
        break;
    case 2:
        ResumeMap(a2);
        (*state)++;
        break;
    case 3:
        InitObjectEventsLocal();
        SetCameraToTrackPlayer();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 5:
        ResetFieldCamera();
        (*state)++;
        break;
    case 6:
        //CopyPrimaryTilesetToVram(gMapHeader.mapLayout); //re-enable if problems pop up!
        (*state)++;
        break;
    case 7:
        //CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            CopyMapTilesetsToVram(gMapHeader.mapLayout);
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (SHOW_MAP_NAME_ENABLED && SecretBaseMapPopupEnabled() == TRUE)
            ShowMapNamePopup();
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 ReturnToFieldLocal(u8 *state)
{
    if (FlagGet(FLAG_RYU_HARDCORE_MODE) == 1)
        RyuKillMon();

    switch (*state)
    {
    case 0:
        ResetMirageTowerAndSaveBlockPtrs();
        sub_80867D8();
        ResumeMap(FALSE);
        sub_8086A68();
        SetCameraToTrackPlayer();
        (*state)++;
        break;
    case 1:
        InitViewGraphics();
        (*state)++;
        break;
    case 2:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 3:
        return TRUE;
    }

    return FALSE;
}

static bool32 ReturnToFieldLink(u8 *state)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        ResetMirageTowerAndSaveBlockPtrs();
        sub_80867D8();
        (*state)++;
        break;
    case 1:
        ResumeMap(TRUE);
        (*state)++;
        break;
    case 2:
        CreateLinkPlayerSprites();
        sub_8086A68();
        SetCameraToTrackGuestPlayer_2();
        (*state)++;
        break;
    case 3:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 4:
        ResetFieldCamera();
        (*state)++;
        break;
    case 5:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 6:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 8:
        DrawWholeMapView();
        (*state)++;
        break;
    case 9:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 10:
        (*state)++;
        break;
    case 13:
        SetFieldVBlankCallback();
        (*state)++;
        return TRUE;
    }

    return FALSE;
}

static void DoMapLoadLoop(u8 *state)
{
    while (!LoadMapInStepsLocal(state, FALSE));
}

static void ResetMirageTowerAndSaveBlockPtrs(void)
{
    //ClearMirageTowerPulseBlend();
    MoveSaveBlocks_ResetHeap();
}

static void sub_80867D8(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ScanlineEffect_Stop();

    DmaClear16(3, PLTT + 2, PLTT_SIZE - 2);

    // USE REGULAR FILL INSTEAD
    //DmaFillLarge16(3, 0, (void *)(VRAM + 0x0), 0x18000, 0x1000);
    DmaFill16(3, 0, (void *)(VRAM + 0x0), 0x18000);
    ResetOamRange(0, 128);
    LoadOam();
}

static void InitViewGraphics(void)
{
    InitCurrentFlashLevelScanlineEffect();
    InitOverworldGraphicsRegisters();
    InitTextBoxGfxAndPrinters();
    InitMapView();
}

static void InitOverworldGraphicsRegisters(void)
{
    ClearScheduledBgCopiesToVram();
    ResetTempTileDataBuffers();
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WINOBJ_BG0);
    SetGpuReg(REG_OFFSET_WIN0H, 0xFF);
    SetGpuReg(REG_OFFSET_WIN0V, 0xFF);
    SetGpuReg(REG_OFFSET_WIN1H, 0xFFFF);
    SetGpuReg(REG_OFFSET_WIN1V, 0xFFFF);
    SetGpuReg(REG_OFFSET_BLDCNT, gOverworldBackgroundLayerFlags[1] | gOverworldBackgroundLayerFlags[2] | gOverworldBackgroundLayerFlags[3]
                               | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(13, 7));
    InitOverworldBgs();
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON
                                | DISPCNT_OBJ_1D_MAP | DISPCNT_HBLANK_INTERVAL);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    InitFieldMessageBox();
}

static void ResumeMap(bool32 a1)
{
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    ScanlineEffect_Clear();
    ResetAllPicSprites();
    ResetCameraUpdateInfo();
    InstallCameraPanAheadCallback();
    FreeAllSpritePalettes();

    FieldEffectActiveListClear();
    if (FlagGet(FLAG_RYU_PERSISTENT_WEATHER) == 1 && (GetSav1Weather() != VarGet(VAR_RYU_WEATHER)))
        SetWeather(VarGet(VAR_RYU_WEATHER));
    StartWeather();
    ResumePausedWeather();
    FlagClear(FLAG_RYU_PERSISTENT_WEATHER);
    if (!a1)
        SetUpFieldTasks();
    RunOnResumeMapScript();
    //TryStartMirageTowerPulseBlendEffect();
}

static void InitObjectEventsLink(void)
{
    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetObjectEvents();
    TrySpawnObjectEvents(0, 0);
    TryRunOnWarpIntoMapScript();
}

static void InitObjectEventsLocal(void)
{
    s16 x, y;
    struct InitialPlayerAvatarState *player;

    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetObjectEvents();
    GetCameraFocusCoords(&x, &y);
    player = GetInitialPlayerAvatarState();
    InitPlayerAvatar(x, y, player->direction, gSaveBlock2Ptr->playerGender);
    SetPlayerAvatarTransitionFlags(player->transitionFlags);
    ResetInitialPlayerAvatarState();
    TrySpawnObjectEvents(0, 0);
    TryRunOnWarpIntoMapScript();
}

static void sub_8086A68(void)
{
    sub_808E16C(0, 0);
    RunOnReturnToFieldMapScript();
}

static void SetCameraToTrackPlayer(void)
{
    gObjectEvents[gPlayerAvatar.objectEventId].trackedByCamera = TRUE;
    InitCameraUpdateCallback(gPlayerAvatar.spriteId);
}

static void SetCameraToTrackGuestPlayer(void)
{
    InitCameraUpdateCallback(GetSpriteForLinkedPlayer(gLocalLinkPlayerId));
}

// Duplicate function.
static void SetCameraToTrackGuestPlayer_2(void)
{
    InitCameraUpdateCallback(GetSpriteForLinkedPlayer(gLocalLinkPlayerId));
}

static void OffsetCameraFocusByLinkPlayerId(void)
{
    u16 x, y;
    GetCameraFocusCoords(&x, &y);

    // This is a hack of some kind; it's undone in SpawnLinkPlayers, which is called
    // soon after this function.
    SetCameraFocusCoords(x + gLocalLinkPlayerId, y);
}

static void SpawnLinkPlayers(void)
{
    u16 i;
    u16 x, y;

    GetCameraFocusCoords(&x, &y);
    x -= gLocalLinkPlayerId;

    for (i = 0; i < gFieldLinkPlayerCount; i++)
    {
        SpawnLinkPlayerObjectEvent(i, i + x, y, gLinkPlayers[i].gender);
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
    }

    ClearAllPlayerKeys();
}

static void CreateLinkPlayerSprites(void)
{
    u16 i;
    for (i = 0; i < gFieldLinkPlayerCount; i++)
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
}


static void CB1_UpdateLinkState(void)
{
    if (gWirelessCommType == 0 || !IsRfuRecvQueueEmpty() || !IsSendingKeysToLink())
    {
        u8 selfId = gLocalLinkPlayerId;
        UpdateAllLinkPlayers(gLinkPartnersHeldKeys, selfId);

        // Note: Because guestId is between 0 and 4, while the smallest key code is
        // LINK_KEY_CODE_EMPTY, this is functionally equivalent to `sPlayerKeyInterceptCallback(0)`.
        // It is expecting the callback to be KeyInterCB_SelfIdle, and that will 
        // completely ignore any input parameters.
        //
        // UpdateHeldKeyCode performs a sanity check on its input; if 
        // sPlayerKeyInterceptCallback echoes back the argument, which is selfId, then
        // it'll use LINK_KEY_CODE_EMPTY instead.
        //
        // Note 2: There are some key intercept callbacks that treat the key as a player
        // ID. It's so hacky.
        UpdateHeldKeyCode(sPlayerKeyInterceptCallback(selfId));
        ClearAllPlayerKeys();
    }
}

void ResetAllMultiplayerState(void)
{
    ResetAllTradingStates();
    SetKeyInterceptCallback(KeyInterCB_SelfIdle);
}

static void ClearAllPlayerKeys(void)
{
    ResetPlayerHeldKeys(gLinkPartnersHeldKeys);
}

static void SetKeyInterceptCallback(u16 (*func)(u32))
{
    sRfuKeepAliveTimer = 0;
    sPlayerKeyInterceptCallback = func;
}

// Once every ~60 frames, if the link state hasn't changed (timer reset by calls
// to SetKeyInterceptCallback), it does a bunch of sanity checks on the connection.
// I'm not sure if sRfuKeepAliveTimer is reset in the process, though; rfu stuff is
// still undocumented.
static void CheckRfuKeepAliveTimer(void)
{
    if (gWirelessCommType != 0 && ++sRfuKeepAliveTimer > 60)
        LinkRfu_FatalError();
}

static void ResetAllTradingStates(void)
{
    s32 i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
        sPlayerTradingStates[i] = PLAYER_TRADING_STATE_IDLE;
}

// Returns true if all connected players are in tradingState.
static bool32 AreAllPlayersInTradingState(u16 tradingState)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sPlayerTradingStates[i] != tradingState)
            return FALSE;
    return TRUE;
}

static bool32 IsAnyPlayerInTradingState(u16 tradingState)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sPlayerTradingStates[i] == tradingState)
            return TRUE;
    return FALSE;
}

static void HandleLinkPlayerKeyInput(u32 playerId, u16 key, struct TradeRoomPlayer *trainer, u16 *forceFacing)
{
    const u8 *script;

    if (sPlayerTradingStates[playerId] == PLAYER_TRADING_STATE_IDLE)
    {
        script = TryGetTileEventScript(trainer);
        if (script)
        {
            *forceFacing = GetDirectionForEventScript(script);
            sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
            if (trainer->isLocalPlayer)
            {
                SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                sub_8087530(script);
            }
            return;
        }
        if (IsAnyPlayerInTradingState(PLAYER_TRADING_STATE_EXITING_ROOM) == TRUE)
        {
            sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
            if (trainer->isLocalPlayer)
            {
                SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                RunTerminateLinkScript();
            }
            return;
        }

        switch (key)
        {
        case LINK_KEY_CODE_START_BUTTON:
            if (sub_8087340_2(trainer))
            {
                sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    InitLinkRoomStartMenuScript();
                }
            }
            break;
        case LINK_KEY_CODE_DPAD_DOWN:
            if (PlayerIsAtSouthExit(trainer) == TRUE)
            {
                sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    CreateConfirmLeaveTradeRoomPrompt();
                }
            }
            break;
        case LINK_KEY_CODE_A_BUTTON:
            script = TryInteractWithPlayer(trainer);
            if (script)
            {
                sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    InitMenuBasedScript(script);
                }
            }
            break;
        case LINK_KEY_CODE_HANDLE_RECV_QUEUE:
            if (sub_8087340(trainer))
            {
                sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToRecvQueue);
                    sub_8087510();
                }
            }
            break;
        case LINK_KEY_CODE_HANDLE_SEND_QUEUE:
            if (sub_8087340(trainer))
            {
                sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToSendQueue);
                    sub_8087510();
                }
            }
            break;
        }
    }

    switch (key)
    {
    case LINK_KEY_CODE_EXIT_ROOM:
        sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_EXITING_ROOM;
        break;
    case LINK_KEY_CODE_UNK_2:
        sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_UNK_2;
        break;
    case LINK_KEY_CODE_UNK_4:
        sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_IDLE;
        if (trainer->isLocalPlayer)
            SetKeyInterceptCallback(KeyInterCB_SelfIdle);
        break;
    case LINK_KEY_CODE_UNK_7:
        if (sPlayerTradingStates[playerId] == PLAYER_TRADING_STATE_UNK_2)
            sPlayerTradingStates[playerId] = PLAYER_TRADING_STATE_BUSY;
        break;
    }
}

static void UpdateAllLinkPlayers(u16 *keys, s32 selfId)
{
    struct TradeRoomPlayer trainer;
    s32 i;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        u8 key = keys[i];
        u16 setFacing = FACING_NONE;
        LoadTradeRoomPlayer(i, selfId, &trainer);
        HandleLinkPlayerKeyInput(i, key, &trainer, &setFacing);
        if (sPlayerTradingStates[i] == PLAYER_TRADING_STATE_IDLE)
            setFacing = GetDirectionForDpadKey(key);
        SetPlayerFacingDirection(i, setFacing);
    }
}

static void UpdateHeldKeyCode(u16 key)
{
    if (key >= LINK_KEY_CODE_EMPTY && key < LINK_KEY_CODE_UNK_8)
        gHeldKeyCodeToSend = key;
    else
        gHeldKeyCodeToSend = LINK_KEY_CODE_EMPTY;

    if (gWirelessCommType != 0
        && GetLinkSendQueueLength() > 1
        && IsUpdateLinkStateCBActive() == TRUE
        && IsSendingKeysToLink() == TRUE)
    {
        switch (key)
        {
        case LINK_KEY_CODE_EMPTY:
        case LINK_KEY_CODE_DPAD_DOWN:
        case LINK_KEY_CODE_DPAD_UP:
        case LINK_KEY_CODE_DPAD_LEFT:
        case LINK_KEY_CODE_DPAD_RIGHT:
        case LINK_KEY_CODE_START_BUTTON:
        case LINK_KEY_CODE_A_BUTTON:
            gHeldKeyCodeToSend = LINK_KEY_CODE_NULL;
            break;
        }
    }
}

static u16 KeyInterCB_ReadButtons(u32 key)
{
    if (JOY_HELD(DPAD_UP))
        return LINK_KEY_CODE_DPAD_UP;
    if (JOY_HELD(DPAD_DOWN))
        return LINK_KEY_CODE_DPAD_DOWN;
    if (JOY_HELD(DPAD_LEFT))
        return LINK_KEY_CODE_DPAD_LEFT;
    if (JOY_HELD(DPAD_RIGHT))
        return LINK_KEY_CODE_DPAD_RIGHT;
    if (JOY_NEW(START_BUTTON))
        return LINK_KEY_CODE_START_BUTTON;
    if (JOY_NEW(A_BUTTON))
        return LINK_KEY_CODE_A_BUTTON;
    return LINK_KEY_CODE_EMPTY;
}

static u16 GetDirectionForDpadKey(u16 a1)
{
    switch (a1)
    {
    case LINK_KEY_CODE_DPAD_RIGHT:
        return FACING_RIGHT;
    case LINK_KEY_CODE_DPAD_LEFT:
        return FACING_LEFT;
    case LINK_KEY_CODE_DPAD_UP:
        return FACING_UP;
    case LINK_KEY_CODE_DPAD_DOWN:
        return FACING_DOWN;
    default:
        return FACING_NONE;
    }
}

// Overwrites the keys with 0x11
static void ResetPlayerHeldKeys(u16 *keys)
{
    s32 i;
    for (i = 0; i < 4; i++)
        keys[i] = LINK_KEY_CODE_EMPTY;
}


static u16 KeyInterCB_SelfIdle(u32 key)
{
    if (ScriptContext2_IsEnabled() == TRUE)
        return LINK_KEY_CODE_EMPTY;
    if (GetLinkRecvQueueLength() > 4)
        return LINK_KEY_CODE_HANDLE_RECV_QUEUE;
    if (GetLinkSendQueueLength() <= 4)
        return KeyInterCB_ReadButtons(key);
    return LINK_KEY_CODE_HANDLE_SEND_QUEUE;
}

static u16 sub_80870EC(u32 key)
{
    CheckRfuKeepAliveTimer();
    return LINK_KEY_CODE_EMPTY;
}

// Ignore the player's inputs as long as there is an event script
// in ScriptContext2.
static u16 KeyInterCB_DeferToEventScript(u32 key)
{
    u16 retVal;
    if (ScriptContext2_IsEnabled() == TRUE)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_UNK_4;
        SetKeyInterceptCallback(sub_80870EC);
    }
    return retVal;
}

// Ignore the player's inputs as long as there are events being recived.
static u16 KeyInterCB_DeferToRecvQueue(u32 key)
{
    u16 retVal;
    if (GetLinkRecvQueueLength() > 2)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_UNK_4;
        ScriptContext2_Disable();
        SetKeyInterceptCallback(sub_80870EC);
    }
    return retVal;
}

// Ignore the player's inputs as long as there are events being sent.
static u16 KeyInterCB_DeferToSendQueue(u32 key)
{
    u16 retVal;
    if (GetLinkSendQueueLength() > 2)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_UNK_4;
        ScriptContext2_Disable();
        SetKeyInterceptCallback(sub_80870EC);
    }
    return retVal;
}

static u16 KeyInterCB_DoNothingAndKeepAlive(u32 key)
{
    CheckRfuKeepAliveTimer();
    return LINK_KEY_CODE_EMPTY;
}

static u16 sub_8087170(u32 keyOrPlayerId)
{
    if (sPlayerTradingStates[keyOrPlayerId] == PLAYER_TRADING_STATE_UNK_2)
    {
        if (JOY_NEW(B_BUTTON))
        {
            SetKeyInterceptCallback(KeyInterCB_DoNothingAndKeepAlive);
            return LINK_KEY_CODE_UNK_7;
        }
        else
        {
            return LINK_KEY_CODE_EMPTY;
        }
    }
    else
    {
        CheckRfuKeepAliveTimer();
        return LINK_KEY_CODE_EMPTY;
    }
}

static u16 sub_80871AC(u32 a1)
{
    SetKeyInterceptCallback(sub_8087170);
    return LINK_KEY_CODE_UNK_2;
}

static u16 KeyInterCB_SendNothing(u32 key)
{
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_WaitForPlayersToExit(u32 keyOrPlayerId)
{
    // keyOrPlayerId could be any keycode. This callback does no sanity checking
    // on the size of the key. It's assuming that it is being called from
    // CB1_UpdateLinkState.
    if (sPlayerTradingStates[keyOrPlayerId] != PLAYER_TRADING_STATE_EXITING_ROOM)
        CheckRfuKeepAliveTimer();
    if (AreAllPlayersInTradingState(PLAYER_TRADING_STATE_EXITING_ROOM) == TRUE)
    {
        ScriptContext1_SetupScript(EventScript_DoLinkRoomExit);
        SetKeyInterceptCallback(KeyInterCB_SendNothing);
    }
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_SendExitRoomKey(u32 key)
{
    SetKeyInterceptCallback(KeyInterCB_WaitForPlayersToExit);
    return LINK_KEY_CODE_EXIT_ROOM;
}

// Duplicate function.
static u16 KeyInterCB_SendNothing_2(u32 key)
{
    return LINK_KEY_CODE_EMPTY;
}

u32 sub_8087214(void)
{
    if (IsAnyPlayerInTradingState(PLAYER_TRADING_STATE_EXITING_ROOM) == TRUE)
        return 2;
    if (sPlayerKeyInterceptCallback == sub_8087170 && sPlayerTradingStates[gLocalLinkPlayerId] != PLAYER_TRADING_STATE_UNK_2)
        return 0;
    if (sPlayerKeyInterceptCallback == KeyInterCB_DoNothingAndKeepAlive && sPlayerTradingStates[gLocalLinkPlayerId] == PLAYER_TRADING_STATE_BUSY)
        return 2;
    if (AreAllPlayersInTradingState(PLAYER_TRADING_STATE_UNK_2) != FALSE)
        return 1;
    return 0;
}

bool32 sub_808727C(void)
{
    return IsAnyPlayerInTradingState(PLAYER_TRADING_STATE_EXITING_ROOM);
}

u16 sub_8087288(void)
{
    SetKeyInterceptCallback(sub_80871AC);
    return 0;
}

u16 sub_808729C(void)
{
    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
    return 0;
}

// The exit room key will be sent at the next opportunity.
// The return value is meaningless.
u16 QueueExitLinkRoomKey(void)
{
    SetKeyInterceptCallback(KeyInterCB_SendExitRoomKey);
    return 0;
}

u16 sub_80872C4(void)
{
    SetKeyInterceptCallback(KeyInterCB_SendNothing_2);
    return 0;
}

static void LoadTradeRoomPlayer(s32 linkPlayerId, s32 myPlayerId, struct TradeRoomPlayer *trainer)
{
    s16 x, y;

    trainer->playerId = linkPlayerId;
    trainer->isLocalPlayer = (linkPlayerId == myPlayerId) ? 1 : 0;
    trainer->c = gLinkPlayerObjectEvents[linkPlayerId].movementMode;
    trainer->facing = GetLinkPlayerFacingDirection(linkPlayerId);
    GetLinkPlayerCoords(linkPlayerId, &x, &y);
    trainer->pos.x = x;
    trainer->pos.y = y;
    trainer->pos.height = GetLinkPlayerElevation(linkPlayerId);
    trainer->field_C = MapGridGetMetatileBehaviorAt(x, y);
}

static bool32 sub_8087340(struct TradeRoomPlayer *player)
{
    u8 v1 = player->c;
    if (v1 == MOVEMENT_MODE_SCRIPTED || v1 == MOVEMENT_MODE_FREE)
        return TRUE;
    else
        return FALSE;
}

// Duplicate function.
static bool32 sub_8087340_2(struct TradeRoomPlayer *player)
{
    u8 v1 = player->c;
    if (v1 == MOVEMENT_MODE_SCRIPTED || v1 == MOVEMENT_MODE_FREE)
        return TRUE;
    else
        return FALSE;
}

static u8 *TryGetTileEventScript(struct TradeRoomPlayer *player)
{
    if (player->c != MOVEMENT_MODE_SCRIPTED)
        return FACING_NONE;
    return GetCoordEventScriptAtMapPosition(&player->pos);
}

static bool32 PlayerIsAtSouthExit(struct TradeRoomPlayer *player)
{
    if (player->c != MOVEMENT_MODE_SCRIPTED && player->c != MOVEMENT_MODE_FREE)
        return FALSE;
    else if (!MetatileBehavior_IsSouthArrowWarp(player->field_C))
        return FALSE;
    else if (player->facing != DIR_SOUTH)
        return FALSE;
    else
        return TRUE;
}

static const u8 *TryInteractWithPlayer(struct TradeRoomPlayer *player)
{
    struct MapPosition otherPlayerPos;
    u8 linkPlayerId;

    if (player->c != MOVEMENT_MODE_FREE && player->c != MOVEMENT_MODE_SCRIPTED)
        return FACING_NONE;

    otherPlayerPos = player->pos;
    otherPlayerPos.x += gDirectionToVectors[player->facing].x;
    otherPlayerPos.y += gDirectionToVectors[player->facing].y;
    otherPlayerPos.height = 0;
    linkPlayerId = GetLinkPlayerIdAt(otherPlayerPos.x, otherPlayerPos.y);

    if (linkPlayerId != MAX_LINK_PLAYERS)
    {
        if (!player->isLocalPlayer)
            return CableClub_EventScript_TooBusyToNotice;
        else if (sPlayerTradingStates[linkPlayerId] != PLAYER_TRADING_STATE_IDLE)
            return CableClub_EventScript_TooBusyToNotice;
        else if (!GetLinkTrainerCardColor(linkPlayerId))
            return CableClub_EventScript_ReadTrainerCard;
        else
            return CableClub_EventScript_ReadTrainerCardColored;
    }

    return GetInteractedLinkPlayerScript(&otherPlayerPos, player->field_C, player->facing);
}

// This returns which direction to force the player to look when one of
// these event scripts runs.
static u16 GetDirectionForEventScript(const u8 *script)
{
    if (script == EventScript_BattleColosseum_4P_PlayerSpot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot2)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot3)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_RecordCenter_Spot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_RecordCenter_Spot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_RecordCenter_Spot2)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_RecordCenter_Spot3)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_BattleColosseum_2P_PlayerSpot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_2P_PlayerSpot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_TradeCenter_Chair0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_TradeCenter_Chair1)
        return FACING_FORCED_LEFT;
    else
        return FACING_NONE;
}

static void sub_8087510(void)
{
    ScriptContext2_Enable();
}

static void InitLinkRoomStartMenuScript(void)
{
    PlaySE(SE_WIN_OPEN);
    ShowStartMenu();
    ScriptContext2_Enable();
}

static void sub_8087530(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext1_SetupScript(script);
    ScriptContext2_Enable();
}

static void CreateConfirmLeaveTradeRoomPrompt(void)
{
    PlaySE(SE_WIN_OPEN);
    ScriptContext1_SetupScript(EventScript_ConfirmLeaveTradeRoom);
    ScriptContext2_Enable();
}

static void InitMenuBasedScript(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext1_SetupScript(script);
    ScriptContext2_Enable();
}

static void RunTerminateLinkScript(void)
{
    ScriptContext1_SetupScript(EventScript_TerminateLink);
    ScriptContext2_Enable();
}

bool32 sub_8087598(void)
{
    if (!IsUpdateLinkStateCBActive())
        return FALSE;
    if (GetLinkRecvQueueLength() >= 3)
        sUnknown_03000E18 = TRUE;
    else
        sUnknown_03000E18 = FALSE;
    return sUnknown_03000E18;
}

bool32 sub_80875C8(void)
{
    u8 temp;

    if (GetLinkRecvQueueLength() < 2)
        return FALSE;
    else if (IsUpdateLinkStateCBActive() != TRUE)
        return FALSE;
    else if (IsSendingKeysToLink() != TRUE)
        return FALSE;
    else if (sPlayerKeyInterceptCallback == KeyInterCB_DeferToRecvQueue)
        return TRUE;
    else if (sPlayerKeyInterceptCallback != KeyInterCB_DeferToEventScript)
        return FALSE;

    temp = sUnknown_03000E18;
    sUnknown_03000E18 = FALSE;

    if (temp == TRUE)
        return TRUE;
    else if (gPaletteFade.active && gPaletteFade.softwareFadeFinishing)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_8087634(void)
{
    if (GetLinkSendQueueLength() < 2)
        return FALSE;
    else if (IsUpdateLinkStateCBActive() != TRUE)
        return FALSE;
    else if (IsSendingKeysToLink() != TRUE)
        return FALSE;
    else if (sPlayerKeyInterceptCallback == KeyInterCB_DeferToSendQueue)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_808766C(void)
{
    if (gWirelessCommType != 0)
        return FALSE;
    else if (!IsSendingKeysToLink())
        return FALSE;
    else
        return TRUE;
}

static u32 GetLinkSendQueueLength(void)
{
    if (gWirelessCommType != 0)
        return Rfu.sendQueue.count;
    else
        return gLink.sendQueue.count;
}

static void ZeroLinkPlayerObjectEvent(struct LinkPlayerObjectEvent *linkPlayerObjEvent)
{
    memset(linkPlayerObjEvent, 0, sizeof(struct LinkPlayerObjectEvent));
}

void ClearLinkPlayerObjectEvents(void)
{
    memset(gLinkPlayerObjectEvents, 0, sizeof(gLinkPlayerObjectEvents));
}

static void ZeroObjectEvent(struct ObjectEvent *objEvent)
{
    memset(objEvent, 0, sizeof(struct ObjectEvent));
}

static void SpawnLinkPlayerObjectEvent(u8 linkPlayerId, s16 x, s16 y, u8 a4)
{
    u8 objEventId = GetFirstInactiveObjectEventId();
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];

    ZeroLinkPlayerObjectEvent(linkPlayerObjEvent);
    ZeroObjectEvent(objEvent);

    linkPlayerObjEvent->active = 1;
    linkPlayerObjEvent->linkPlayerId = linkPlayerId;
    linkPlayerObjEvent->objEventId = objEventId;
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FREE;

    objEvent->active = 1;
    objEvent->singleMovementActive = a4;
    objEvent->range.as_byte = 2;
    objEvent->spriteId = 64;

    InitLinkPlayerObjectEventPos(objEvent, x, y);
}

static void InitLinkPlayerObjectEventPos(struct ObjectEvent *objEvent, s16 x, s16 y)
{
    objEvent->currentCoords.x = x;
    objEvent->currentCoords.y = y;
    objEvent->previousCoords.x = x;
    objEvent->previousCoords.y = y;
    SetSpritePosToMapCoords(x, y, &objEvent->initialCoords.x, &objEvent->initialCoords.y);
    objEvent->initialCoords.x += 8;
    ObjectEventUpdateZCoord(objEvent);
}

static void sub_80877DC(u8 linkPlayerId, u8 a2)
{
    if (gLinkPlayerObjectEvents[linkPlayerId].active)
    {
        u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
        struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
        objEvent->range.as_byte = a2;
    }
}

static void sub_808780C(u8 linkPlayerId)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    if (objEvent->spriteId != MAX_SPRITES)
        DestroySprite(&gSprites[objEvent->spriteId]);
    linkPlayerObjEvent->active = 0;
    objEvent->active = 0;
}

// Returns the spriteId corresponding to this player.
static u8 GetSpriteForLinkedPlayer(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return objEvent->spriteId;
}

static void GetLinkPlayerCoords(u8 linkPlayerId, u16 *x, u16 *y)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    *x = objEvent->currentCoords.x;
    *y = objEvent->currentCoords.y;
}

static u8 GetLinkPlayerFacingDirection(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return objEvent->range.as_byte;
}

static u8 GetLinkPlayerElevation(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return objEvent->currentElevation;
}

static s32 sub_80878E4(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return 16 - (s8)objEvent->directionSequenceIndex;
}

static u8 GetLinkPlayerIdAt(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayerObjectEvents[i].active
         && (gLinkPlayerObjectEvents[i].movementMode == 0 || gLinkPlayerObjectEvents[i].movementMode == 2))
        {
            struct ObjectEvent *objEvent = &gObjectEvents[gLinkPlayerObjectEvents[i].objEventId];
            if (objEvent->currentCoords.x == x && objEvent->currentCoords.y == y)
                return i;
        }
    }
    return 4;
}

static void SetPlayerFacingDirection(u8 linkPlayerId, u8 facing)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];

    if (linkPlayerObjEvent->active)
    {
        if (facing > FACING_FORCED_RIGHT)
        {
            objEvent->triggerGroundEffectsOnMove = 1;
        }
        else
        {
            // This is a hack to split this code onto two separate lines, without declaring a local variable.
            // C++ style inline variables would be nice here.
            #define TEMP gLinkPlayerMovementModes[linkPlayerObjEvent->movementMode](linkPlayerObjEvent, objEvent, facing)

            gMovementStatusHandler[TEMP](linkPlayerObjEvent, objEvent);
            
            // Clean up the hack.
            #undef TEMP
        }
    }
}


static u8 MovementEventModeCB_Normal(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 a3)
{
    return gLinkPlayerFacingHandlers[a3](linkPlayerObjEvent, objEvent, a3);
}

static u8 MovementEventModeCB_Ignored(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 a3)
{
    return FACING_UP;
}

// Duplicate Function
static u8 MovementEventModeCB_Normal_2(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 a3)
{
    return gLinkPlayerFacingHandlers[a3](linkPlayerObjEvent, objEvent, a3);
}

static bool8 FacingHandler_DoNothing(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 a3)
{
    return FALSE;
}

static bool8 FacingHandler_DpadMovement(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 a3)
{
    s16 x, y;

    objEvent->range.as_byte = FlipVerticalAndClearForced(a3, objEvent->range.as_byte);
    ObjectEventMoveDestCoords(objEvent, objEvent->range.as_byte, &x, &y);

    if (LinkPlayerDetectCollision(linkPlayerObjEvent->objEventId, objEvent->range.as_byte, x, y))
    {
        return FALSE;
    }
    else
    {
        objEvent->directionSequenceIndex = 16;
        ShiftObjectEventCoords(objEvent, x, y);
        ObjectEventUpdateZCoord(objEvent);
        return TRUE;
    }
}

static bool8 FacingHandler_ForcedFacingChange(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 a3)
{
    objEvent->range.as_byte = FlipVerticalAndClearForced(a3, objEvent->range.as_byte);
    return FALSE;
}

// This is called every time a free movement happens. Most of the time it's a No-Op.
static void MovementStatusHandler_EnterFreeMode(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent)
{
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FREE;
}

static void MovementStatusHandler_TryAdvanceScript(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent)
{
    objEvent->directionSequenceIndex--;
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FROZEN;
    MoveCoords(objEvent->range.as_byte, &objEvent->initialCoords.x, &objEvent->initialCoords.y);
    if (!objEvent->directionSequenceIndex)
    {
        ShiftStillObjectEventCoords(objEvent);
        linkPlayerObjEvent->movementMode = MOVEMENT_MODE_SCRIPTED;
    }
}

// Flip Up/Down facing codes. If newFacing doesn't specify a direction, default
// to oldFacing. Note that this clears also the "FORCED" part of the facing code,
// even for Left/Right codes.
static u8 FlipVerticalAndClearForced(u8 newFacing, u8 oldFacing)
{
    switch (newFacing)
    {
    case FACING_UP:
    case FACING_FORCED_UP:
        return DIR_NORTH;
    case FACING_DOWN:
    case FACING_FORCED_DOWN:
        return DIR_SOUTH;
    case FACING_LEFT:
    case FACING_FORCED_LEFT:
        return DIR_WEST;
    case FACING_RIGHT:
    case FACING_FORCED_RIGHT:
        return DIR_EAST;
    }
    return oldFacing;
}

static u8 LinkPlayerDetectCollision(u8 selfObjEventId, u8 a2, s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < 16; i++)
    {
        if (i != selfObjEventId)
        {
            if ((gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
             || (gObjectEvents[i].previousCoords.x == x && gObjectEvents[i].previousCoords.y == y))
            {
                return 1;
            }
        }
    }
    return MapGridIsImpassableAt(x, y);
}

static void CreateLinkPlayerSprite(u8 linkPlayerId, u8 gameVersion)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    struct Sprite *sprite;

    if (linkPlayerObjEvent->active)
    {
        switch (gameVersion)
        {
        case VERSION_FIRE_RED:
        case VERSION_LEAF_GREEN:
            objEvent->spriteId = AddPseudoObjectEvent(GetFRLGAvatarGraphicsIdByGender(objEvent->singleMovementActive), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_RUBY:
        case VERSION_SAPPHIRE:
            objEvent->spriteId = AddPseudoObjectEvent(GetRSAvatarGraphicsIdByGender(objEvent->singleMovementActive), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_EMERALD:
            objEvent->spriteId = AddPseudoObjectEvent(GetRivalAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, objEvent->singleMovementActive), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        }

        sprite = &gSprites[objEvent->spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = linkPlayerId;
        objEvent->triggerGroundEffectsOnMove = 0;
    }
}

static void SpriteCB_LinkPlayer(struct Sprite *sprite)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[sprite->data[0]];
    struct ObjectEvent *objEvent = &gObjectEvents[linkPlayerObjEvent->objEventId];
    sprite->pos1.x = objEvent->initialCoords.x;
    sprite->pos1.y = objEvent->initialCoords.y;
    SetObjectSubpriorityByZCoord(objEvent->previousElevation, sprite, 1);
    sprite->oam.priority = ZCoordToPriority(objEvent->previousElevation);

    if (linkPlayerObjEvent->movementMode == MOVEMENT_MODE_FREE)
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(objEvent->range.as_byte));
    else
        StartSpriteAnimIfDifferent(sprite, GetMoveDirectionAnimNum(objEvent->range.as_byte));

    UpdateObjectEventSpriteVisibility(sprite, 0);
    if (objEvent->triggerGroundEffectsOnMove)
    {
        sprite->invisible = ((sprite->data[7] & 4) >> 2);
        sprite->data[7]++;
    }
}
