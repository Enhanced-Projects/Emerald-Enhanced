#include "global.h"
#include "main.h"
#include "menu.h"
#include "text.h"
#include "bg.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "window.h"
#include "task.h"
#include "dma3.h"
#include "palette.h"
#include "scanline_effect.h"
#include "pidgey_ui_sys.h"
#include "constants/rgb.h"

static EWRAM_DATA const struct UIData * sUIDataPtr = NULL;

static void FreeWindowAndBgBuffers(void);
static void Task_WaitToExitUI(u8 taskId);
static bool8 IntializePidgeyUI(u8 taskId);
void Task_InitPidgeyUI(u8 taskId);
void CB2_IntializePidgeyUI(void);

/*
void CB2_PidgeyUIInitCleanup(void)
{
    if (gPaletteFade.active)
        return;
    FreeWindowAndBgBuffers();
    SetMainCallback2(CB2_IntializePidgeyUI);
}
*/

void StartPidgeyUI(const struct UIData * uidata)
{
    sUIDataPtr = uidata;
    SetMainCallback2(CB2_IntializePidgeyUI);
}

static void CB2_PidgeyUI(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_PidgeyUI(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_IntializePidgeyUI(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        gMain.state = 1;
        break;
    case 1:
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 0;
        gMain.state++;
        break;
    case 2:
        CreateTask(Task_InitPidgeyUI, 0);
        gMain.state++;
        break;
    case 3:
        EnableInterrupts(1);
        //SetVBlankCallback(VBlankCB_PidgeyUI);
        SetMainCallback2(CB2_PidgeyUI);
        break;
    }
}

void Task_InitPidgeyUI(u8 taskId)
{
    if(IntializePidgeyUI(taskId))
        gTasks[taskId].func = sUIDataPtr->taskFunc;
}

static bool8 IntializePidgeyUI(u8 taskId)
{
    const u16 tilemapBufferSizes[4] = {BG_SCREEN_SIZE, BG_SCREEN_SIZE*2, BG_SCREEN_SIZE*2, BG_SCREEN_SIZE*4};
    u32 i;
    switch (gMain.state)
    {
    case 0:
    default:
        if (gPaletteFade.active)
            return 0;
        //SetVBlankCallback(NULL);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sUIDataPtr->bgTemplates, 4);
        SetBgTilemapBuffer(0, AllocZeroed(tilemapBufferSizes[sUIDataPtr->bgTemplates[0].screenSize]));
        for(i = 0; i < 3; i++)
        {
            void * mapBuf;
            if(!sUIDataPtr->bgData[i].isVisible)
                continue;
            mapBuf = AllocZeroed(tilemapBufferSizes[sUIDataPtr->bgTemplates[i+1].screenSize]);
            SetBgTilemapBuffer(i+1, mapBuf);
            RequestDma3Copy(sUIDataPtr->bgData[i].tilemap, mapBuf, sUIDataPtr->bgData[i].mapSize, 0);
            RequestDma3Copy(sUIDataPtr->bgData[i].tiles, (void*)BG_CHAR_ADDR(sUIDataPtr->bgTemplates[i+1].charBaseIndex), sUIDataPtr->bgData[i].tileSize, 0);
            LoadPalette(sUIDataPtr->bgData[i].palette, sUIDataPtr->bgData[i].palSlot*16, sUIDataPtr->bgData[i].palCount*2);
        }
        InitWindows(sUIDataPtr->windowTemplates);
        InitTextBoxGfxAndPrinters();
        DeactivateAllTextPrinters();
        //PutWindowTilemap(0);
        //CopyWindowToVram(0, 3);
        gMain.state = 1;
        break;
    case 1:
        if(sUIDataPtr->customInitFunc)
            sUIDataPtr->customInitFunc(taskId);
        gMain.state++;
        break;
    case 2:
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 3:
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        for(i = 0; i < 3; i++)
        {
            if(sUIDataPtr->bgData[i].isVisible)
                ShowBg(i+1);
            else
                HideBg(i+1);
        }
        gMain.state++;
        break;
    case 4:
        //reserved
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_PidgeyUI);
        gMain.state++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            gMain.state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void ClosePidgeyUI(u8 taskId)
{
    gTasks[taskId].func = Task_WaitToExitUI;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
}

static void Task_WaitToExitUI(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeWindowAndBgBuffers();
        DestroyTask(taskId);
        SetMainCallback2(sUIDataPtr->returnCallback);
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        //FREE_AND_SET_NULL(sUIDataPtr);
        sUIDataPtr = NULL;
    }
}

static void FreeWindowAndBgBuffers(void)
{
    void* tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}
