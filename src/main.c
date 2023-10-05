#include "global.h"
#include "crt0.h"
#include "malloc.h"
#include "link.h"
#include "link_rfu.h"
#include "librfu.h"
#include "m4a.h"
#include "bg.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "overworld.h"
#include "play_time.h"
#include "random.h"
#include "dma3.h"
#include "gba/flash_internal.h"
#include "load_save.h"
#include "gpu_regs.h"
#include "agb_flash.h"
#include "sound.h"
#include "battle.h"
#include "battle_controllers.h"
#include "text.h"
#include "intro.h"
#include "main.h"
#include "trainer_hill.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "overworld_notif.h"

static void VBlankIntr(void);
static void HBlankIntr(void);
static void VCountIntr(void);
static void SerialIntr(void);
static void IntrDummy(void);

const u8 gGameVersion = GAME_VERSION;

const u8 gGameLanguage = GAME_LANGUAGE; // English

const char BuildDateTime[] = "2005 02 21 11:10";

const IntrFunc gIntrTableTemplate[] =
{
    VCountIntr, // V-count interrupt
    SerialIntr, // Serial interrupt
    Timer3Intr, // Timer 3 interrupt
    HBlankIntr, // H-blank interrupt
    VBlankIntr, // V-blank interrupt
    IntrDummy,  // Timer 0 interrupt
    IntrDummy,  // Timer 1 interrupt
    IntrDummy,  // Timer 2 interrupt
    IntrDummy,  // DMA 0 interrupt
    IntrDummy,  // DMA 1 interrupt
    IntrDummy,  // DMA 2 interrupt
    IntrDummy,  // DMA 3 interrupt
    IntrDummy,  // Key interrupt
    IntrDummy,  // Game Pak interrupt
};

#define INTR_COUNT ((int)(sizeof(gIntrTableTemplate)/sizeof(IntrFunc)))

static u16 gUnknown_03000000;

u16 gKeyRepeatStartDelay;
bool8 gLinkTransferringData;
struct Main gMain;
u16 gKeyRepeatContinueDelay;
bool8 gSoftResetDisabled;
IntrFunc gIntrTable[INTR_COUNT];
u8 gLinkVSyncDisabled;
u32 IntrMain_Buffer[0x200];
s8 gPcmDmaCounter;

static EWRAM_DATA u16 gTrainerId = 0;

EWRAM_DATA void (**gFlashTimerIntrFunc)(void) = NULL;

static void UpdateLinkAndCallCallbacks(void);
static void InitMainCallbacks(void);
static void CallCallbacks(void);
static void SeedRngWithRtc(void);
static void ReadKeys(void);
void InitIntrHandlers(void);
static void WaitForVBlank(void);
void EnableVCountIntrAtLine150(void);
#ifdef RYU_PUNISH_SAVE_STATE
bool8 IsRtcSynched(u32 rtcSec, u32 rtcSecRaw);
void RtcCheckCallback(void);
#endif

#define B_START_SELECT (B_BUTTON | START_BUTTON | SELECT_BUTTON)

extern u32 GetBoxMonData();

void AgbMain()
{
    u32 i;
    // Modern compilers are liberal with the stack on entry to this function,
    // so RegisterRamReset may crash if it resets IWRAM.
#if !MODERN
    RegisterRamReset(RESET_ALL);
#endif //MODERN
    *(vu16 *)BG_PLTT = 0x7FFF;
    InitGpuRegManager();
    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_S_1 | WAITCNT_WS0_N_3;
    InitKeys();
    InitIntrHandlers();
    m4aSoundInit();
    EnableVCountIntrAtLine150();
    InitRFU();
    RtcInit();
    CheckForFlashMemory();
    InitMainCallbacks();
    InitMapMusic();
    SeedRngWithRtc(); //see comment at SeedRngWithRtc declaration below
    ClearDma3Requests();
    ResetBgs();
    SetDefaultFontsPointer();
    InitHeap(gHeap, HEAP_SIZE);

    gSoftResetDisabled = FALSE;

    if (gFlashMemoryPresent != TRUE)
        SetMainCallback2(NULL);

    gLinkTransferringData = FALSE;
    gUnknown_03000000 = 0xFC0;
    #ifdef RYU_PUNISH_SAVE_STATE
    gSaveBlock2Ptr->RtcTimeSecond = RtcGetSecondCount();
    gSaveBlock2Ptr->RtcTimeSecondRAW = RtcGetSecondCountRAW();
    #endif

    for (i = 0; ; ++i)
    {
        ReadKeys();
        #ifdef RYU_PUNISH_SAVE_STATE
        if (!(i % 5))
            RtcCheckCallback();
        #endif

        if (gSoftResetDisabled == FALSE
         && (gMain.heldKeysRaw & A_BUTTON)
         && (gMain.heldKeysRaw & B_START_SELECT) == B_START_SELECT)
        {
            rfu_REQ_stopMode();
            rfu_waitREQComplete();
            DoSoftReset();
        }

        if (sub_8087634() == 1)
        {
            gLinkTransferringData = TRUE;
            UpdateLinkAndCallCallbacks();
            gLinkTransferringData = FALSE;
        }
        else
        {
            gLinkTransferringData = FALSE;
            UpdateLinkAndCallCallbacks();

            if (sub_80875C8() == 1)
            {
                gMain.newKeys = 0;
                ClearSpriteCopyRequests();
                gLinkTransferringData = TRUE;
                UpdateLinkAndCallCallbacks();
                gLinkTransferringData = FALSE;
            }
        }

        PlayTimeCounter_Update();
        MapMusicMain(); 
        WaitForVBlank();
    }
}

static void UpdateLinkAndCallCallbacks(void)
{
    if (!HandleLinkConnection())
        CallCallbacks();
}

static void InitMainCallbacks(void)
{
    gMain.vblankCounter1 = 0;
    gTrainerHillVBlankCounter = NULL;
    gMain.vblankCounter2 = 0;
    gMain.callback1 = NULL;
    SetMainCallback2(CB2_InitCopyrightScreenAfterBootup);
    gSaveBlock2Ptr = &gSaveblock2;
    gPokemonStoragePtr = &gPokemonStorage;
}

static void CallCallbacks(void)
{
    if (gMain.callback1)
        gMain.callback1();

    if (gMain.callback2)
        gMain.callback2();
}

void SetMainCallback2(MainCallback callback)
{
    gMain.callback2 = callback;
    gMain.state = 0;
}

void StartTimer1(void)
{
    REG_TM1CNT_H = 0x80;
}

void SeedRngAndSetTrainerId(void)
{
    u16 val = REG_TM1CNT_L;
    SeedRng(val);
    REG_TM1CNT_H = 0;
    gTrainerId = val;
}

u16 GetGeneratedTrainerIdLower(void)
{
    return gTrainerId;
}

void EnableVCountIntrAtLine150(void)
{
    u16 gpuReg = (GetGpuReg(REG_OFFSET_DISPSTAT) & 0xFF) | (150 << 8);
    SetGpuReg(REG_OFFSET_DISPSTAT, gpuReg | DISPSTAT_VCOUNT_INTR);
    EnableInterrupts(INTR_FLAG_VCOUNT);
}

// oops! FRLG commented this out to remove RTC, however Emerald didnt undo this!
static void SeedRngWithRtc(void)
{
    u32 seed = RtcGetMinuteCount();
    seed = (seed >> 16) ^ (seed & 0xFFFF);
    SeedRng(seed);
}

void InitKeys(void)
{
    gKeyRepeatContinueDelay = 5;
    gKeyRepeatStartDelay = 40;

    gMain.heldKeys = 0;
    gMain.newKeys = 0;
    gMain.newAndRepeatedKeys = 0;
    gMain.heldKeysRaw = 0;
    gMain.newKeysRaw = 0;
}

static void ReadKeys(void)
{
    u16 keyInput = REG_KEYINPUT ^ KEYS_MASK;
    gMain.newKeysRaw = keyInput & ~gMain.heldKeysRaw;
    gMain.newKeys = gMain.newKeysRaw;
    gMain.newAndRepeatedKeys = gMain.newKeysRaw;

    // BUG: Key repeat won't work when pressing L using L=A button mode
    // because it compares the raw key input with the remapped held keys.
    // Note that newAndRepeatedKeys is never remapped either.

    if (keyInput != 0 && gMain.heldKeys == keyInput)
    {
        gMain.keyRepeatCounter--;

        if (gMain.keyRepeatCounter == 0)
        {
            gMain.newAndRepeatedKeys = keyInput;
            gMain.keyRepeatCounter = gKeyRepeatContinueDelay;
        }
    }
    else
    {
        // If there is no input or the input has changed, reset the counter.
        gMain.keyRepeatCounter = gKeyRepeatStartDelay;
    }

    gMain.heldKeysRaw = keyInput;
    gMain.heldKeys = gMain.heldKeysRaw;

    if (gMain.newKeys & gMain.watchedKeysMask)
        gMain.watchedKeysPressed = TRUE;
}

void InitIntrHandlers(void)
{
    int i;

    for (i = 0; i < INTR_COUNT; i++)
        gIntrTable[i] = gIntrTableTemplate[i];

    DmaCopy32(3, IntrMain, IntrMain_Buffer, sizeof(IntrMain_Buffer));

    INTR_VECTOR = IntrMain_Buffer;

    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetSerialCallback(NULL);

    REG_IME = 1;

    EnableInterrupts(0x1);
}

void SetVBlankCallback(IntrCallback callback)
{
    gMain.vblankCallback = callback;
}

void SetHBlankCallback(IntrCallback callback)
{
    gMain.hblankCallback = callback;
}

void SetVCountCallback(IntrCallback callback)
{
    gMain.vcountCallback = callback;
}

void RestoreSerialTimer3IntrHandlers(void)
{
    gIntrTable[1] = SerialIntr;
    gIntrTable[2] = Timer3Intr;
}

void SetSerialCallback(IntrCallback callback)
{
    gMain.serialCallback = callback;
}

static void VBlankIntr(void)
{
    if (gWirelessCommType != 0)
        RfuVSync();
    else if (gLinkVSyncDisabled == FALSE)
        LinkVSync();

    gMain.vblankCounter1++;

    if (gTrainerHillVBlankCounter && *gTrainerHillVBlankCounter < 0xFFFFFFFF)
        (*gTrainerHillVBlankCounter)++;

    if (gMain.vblankCallback)
        gMain.vblankCallback();

    gMain.vblankCounter2++;

    CopyBufferedValuesToGpuRegs();
    ProcessDma3Requests();

    gPcmDmaCounter = gSoundInfo.pcmDmaCounter;

    m4aSoundMain();
    sub_8033648();

    if (!gMain.inBattle || !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_RECORDED)))
        Random();

    UpdateWirelessStatusIndicatorSprite();

    INTR_CHECK |= INTR_FLAG_VBLANK;
    gMain.intrCheck |= INTR_FLAG_VBLANK;
}

void InitFlashTimer(void)
{
    SetFlashTimerIntr(2, gIntrTable + 0x7);
}

static void HBlankIntr(void)
{
    if (gMain.hblankCallback)
        gMain.hblankCallback();

    INTR_CHECK |= INTR_FLAG_HBLANK;
    gMain.intrCheck |= INTR_FLAG_HBLANK;
}

static void VCountIntr(void)
{
    if (gMain.vcountCallback)
        gMain.vcountCallback();

    m4aSoundVSync();
    INTR_CHECK |= INTR_FLAG_VCOUNT;
    gMain.intrCheck |= INTR_FLAG_VCOUNT;
}

static void SerialIntr(void)
{
    if (gMain.serialCallback)
        gMain.serialCallback();

    INTR_CHECK |= INTR_FLAG_SERIAL;
    gMain.intrCheck |= INTR_FLAG_SERIAL;
}

static void IntrDummy(void)
{}


#define B_USE_RUBY_VBLANK
//#define B_USE_VANILLA_VBLANK
//#define B_USE_SHANTY_VBLANK


#ifdef B_USE_RUBY_VBLANK
static void WaitForVBlank(void)//Ruby's vblank
{
    gMain.intrCheck &= ~INTR_FLAG_VBLANK;
    asm("swi 0x5");
}
#endif

#ifdef B_USE_VANILLA_VBLANK
static void WaitForVBlank(void)// vanilla vblank
{
    gMain.intrCheck &= ~INTR_FLAG_VBLANK;

    while (!(gMain.intrCheck & INTR_FLAG_VBLANK))
        ;
}
#endif

#ifdef B_USE_SHANTY_VBLANK
static void WaitForVBlank(void) //shanty's vblank
{
    gMain.intrCheck &= ~INTR_FLAG_VBLANK;
    VBlankIntrWait();
}
#endif

void SetTrainerHillVBlankCounter(u32 *counter)
{
    gTrainerHillVBlankCounter = counter;
}

void ClearTrainerHillVBlankCounter(void)
{
    gTrainerHillVBlankCounter = NULL;
}

void DoSoftReset(void)
{
    REG_IME = 0;
    m4aSoundVSyncOff();
    ScanlineEffect_Stop();
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);
    SiiRtcProtect();
    SoftReset(RESET_ALL);
}

void ClearPokemonCrySongs(void)
{
    CpuFill16(0, gPokemonCrySongs, MAX_POKEMON_CRIES * sizeof(struct PokemonCrySong));
}

u8 RtcFrequenciesOffsets[90] =
{
    [9] = 16,
    [25] = 32,
    [41] = 48,
    [57] = 64,
    [73] = 80,
    [89] = 0
};
#ifdef RYU_PUNISH_SAVE_STATE
bool8 IsRtcSynched(u32 rtcSec, u32 rtcSecRaw)
{
    if (gSaveBlock2Ptr->RtcTimeSecond + 10 >= rtcSec)
        return TRUE;
    
    if ((gSaveBlock2Ptr->RtcTimeSecondRAW == 89 || RtcFrequenciesOffsets[gSaveBlock2Ptr->RtcTimeSecondRAW]) && RtcFrequenciesOffsets[gSaveBlock2Ptr->RtcTimeSecondRAW] == rtcSecRaw)
        return TRUE;

    return FALSE;
}

void RtcCheckCallback(void)
{
    u32 rtcSec;
    u32 rtcSecRaw;
    if ((RtcGetErrorStatus() & RTC_ERR_FLAG_MASK)) {
        FlagSet(FLAG_RYU_SAVE_STATE_DETECTED);
        return;
    }
    rtcSec = RtcGetSecondCount();
    rtcSecRaw = RtcGetSecondCountRAW();
    if (!IsRtcSynched(rtcSec, rtcSecRaw))
    {
        FlagSet(FLAG_RYU_SAVE_STATE_DETECTED);
        gSaveBlock2Ptr->SaveStateLastDetection = rtcSec;
    }
    //remove punishment after an hour if the user is in hardcore/challenge mode.
    if ((FlagGet(FLAG_RYU_SAVE_STATE_DETECTED) == TRUE) && (gSaveBlock2Ptr->SaveStateLastDetection + 3600 < rtcSec) && (VarGet(VAR_RYU_DIFFICULTY) == 2000))
    {
        FlagClear(FLAG_RYU_SAVE_STATE_DETECTED);
        gSaveBlock2Ptr->notifiedSaveState = TRUE;
        QueueNotification((const u8[])_("Save State penalty Lifted."), NOTIFY_GENERAL, 120);
    }


    gSaveBlock2Ptr->RtcTimeSecondRAW = rtcSecRaw;
    gSaveBlock2Ptr->RtcTimeSecond = rtcSec;
}
#endif
