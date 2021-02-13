#include "global.h"
#include "event_data.h"
#include "pokedex.h"

#define NUM_SPECIAL_FLAGS (SPECIAL_FLAGS_END - SPECIAL_FLAGS_START + 1)
#define NUM_TEMP_FLAGS    (TEMP_FLAGS_END - TEMP_FLAGS_START + 1)
#define NUM_DAILY_FLAGS   (DAILY_FLAGS_END - DAILY_FLAGS_START + 1)
#define NUM_TEMP_VARS     (TEMP_VARS_END - TEMP_VARS_START + 1)

#define SPECIAL_FLAGS_SIZE  (NUM_SPECIAL_FLAGS / 8)  // 8 flags per byte
#define TEMP_FLAGS_SIZE     (NUM_TEMP_FLAGS / 8)
#define DAILY_FLAGS_SIZE    (NUM_DAILY_FLAGS / 8)
#define TEMP_VARS_SIZE      (NUM_TEMP_VARS * 2)      // 1/2 var per byte

EWRAM_DATA u16 gSpecialVar_0x8000 = 0;
EWRAM_DATA u16 gSpecialVar_0x8001 = 0;
EWRAM_DATA u16 gSpecialVar_0x8002 = 0;
EWRAM_DATA u16 gSpecialVar_0x8003 = 0;
EWRAM_DATA u16 gSpecialVar_0x8004 = 0;
EWRAM_DATA u16 gSpecialVar_0x8005 = 0;
EWRAM_DATA u16 gSpecialVar_0x8006 = 0;
EWRAM_DATA u16 gSpecialVar_0x8007 = 0;
EWRAM_DATA u16 gSpecialVar_0x8008 = 0;
EWRAM_DATA u16 gSpecialVar_0x8009 = 0;
EWRAM_DATA u16 gSpecialVar_0x800A = 0;
EWRAM_DATA u16 gSpecialVar_0x800B = 0;
EWRAM_DATA u16 gSpecialVar_Result = 0;
EWRAM_DATA u16 gSpecialVar_LastTalked = 0;
EWRAM_DATA u16 gSpecialVar_Facing = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxId = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxPos = 0;
EWRAM_DATA u16 gSpecialVar_Unused_0x8014 = 0;
EWRAM_DATA static u8 gSpecialFlags[SPECIAL_FLAGS_SIZE] = {0};

extern u16 *const gSpecialVars[];

void InitEventData(void)
{
    memset(gSaveBlock1Ptr->flags, 0, sizeof(gSaveBlock1Ptr->flags));
    memset(gSaveBlock1Ptr->vars, 0, sizeof(gSaveBlock1Ptr->vars));
    memset(gSpecialFlags, 0, sizeof(gSpecialFlags));
}

void ClearTempFieldEventData(void)
{
    memset(gSaveBlock1Ptr->flags + (TEMP_FLAGS_START / 8), 0, TEMP_FLAGS_SIZE);
    memset(gSaveBlock1Ptr->vars + ((TEMP_VARS_START - VARS_START) * 2), 0, TEMP_VARS_SIZE);
    FlagClear(FLAG_SYS_ENC_UP_ITEM);
    FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_CTRL_OBJ_DELETE);
    FlagClear(FLAG_NURSE_UNION_ROOM_REMINDER);
}

void ClearDailyFlags(void)
{
    memset(gSaveBlock1Ptr->flags + (DAILY_FLAGS_START / 8), 0, DAILY_FLAGS_SIZE);
}

void DisableMysteryEvent(void)
{
    FlagClear(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void EnableMysteryEvent(void)
{
    FlagSet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

bool32 IsMysteryEventEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void DisableMysteryGift(void)
{
    FlagClear(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void EnableMysteryGift(void)
{
    FlagSet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

bool32 IsMysteryGiftEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void ClearMysteryEventFlags(void)
{
    FlagClear(FLAG_RYU_MAGMA_LINE_DONE);
    FlagSet(FLAG_HIDE_MAGMA_ADMIN_OFFICE_MAXIE);
    FlagSet(FLAG_HIDE_MAGMA_ADMIN_OFFICE_BLAISE);
    FlagSet(FLAG_HIDE_114_MAXIE);
    FlagClear(FLAG_RYU_MAGMA_INTENSE_SUN_ENABLED);
    FlagClear(FLAG_UNUSED_5);
    FlagClear(FLAG_UNUSED_6);
    FlagClear(FLAG_UNUSED_7);
    FlagClear(FLAG_UNUSED_8);
    FlagClear(FLAG_UNUSED_9);
    FlagClear(FLAG_UNUSED_10);
    FlagClear(FLAG_UNUSED_11);
    FlagClear(FLAG_UNUSED_12);
    FlagClear(FLAG_UNUSED_13);
    FlagClear(FLAG_UNUSED_14);
    FlagClear(FLAG_UNUSED_15);
}

void ClearMysteryEventVars(void)
{
    VarSet(VAR_EVENT_PICHU_SLOT, 0);
}

void DisableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0);
    FlagClear(FLAG_SYS_RESET_RTC_ENABLE);
}

void EnableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0x920);
    FlagSet(FLAG_SYS_RESET_RTC_ENABLE);
}

bool32 CanResetRTC(void)
{
    if (FlagGet(FLAG_SYS_RESET_RTC_ENABLE) && VarGet(VAR_RESET_RTC_ENABLE) == 0x920)
        return TRUE;
    else
        return FALSE;
}

u16 *GetVarPointer(u16 id)
{
    if (id < VARS_START)
        return NULL;
    else if (id < SPECIAL_VARS_START)
        return &gSaveBlock1Ptr->vars[id - VARS_START];
    else
        return gSpecialVars[id - SPECIAL_VARS_START];
}

u16 VarGet(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return id;
    return *ptr;
}

bool8 VarSet(u16 id, u16 value)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return FALSE;
    *ptr = value;
    return TRUE;
}

u8 VarGetObjectEventGraphicsId(u8 id)
{
    return VarGet(VAR_OBJ_GFX_ID_0 + id);
}

u8 *GetFlagPointer(u16 id)
{
    if (id == 0)
        return NULL;
    else if (id < SPECIAL_FLAGS_START)
        return &gSaveBlock1Ptr->flags[id / 8];
    else
        return &gSpecialFlags[(id - SPECIAL_FLAGS_START) / 8];
}

u8 FlagSet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
    return 0;
}

u8 FlagClear(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
    return 0;
}

bool8 FlagGet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}
