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
#include "event_data.h"

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

//FULL_COLOR
static bool8 IntializePidgeyUI(u8 taskId)
{
    const u16 tilemapBufferSizes[4] = {BG_SCREEN_SIZE, BG_SCREEN_SIZE*2, BG_SCREEN_SIZE*2, BG_SCREEN_SIZE*4};
    u32 i;
    u16 buf[64];
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
            CpuCopy16(sUIDataPtr->bgData[i].palette, buf, 0x20);
            switch (VarGet(VAR_RYU_THEME_NUMBER)) {
                case THEME_COLOR_LIGHT:
                    switch (i) {
                        case 0:
                            buf[1] = COLOR_LIGHT_THEME_TEXT;       // 1 = text color
                            buf[2] = COLOR_NEON_BORDER_2;       // 2 = window highlight
                            buf[3] = COLOR_LIGHT_THEME_BG_DARK;       // 3 = window border
                            buf[4] = COLOR_LIGHT_THEME_BG_LIGHT;       // 4 = bg
                            buf[5] = COLOR_NEON_BORDER_2;       // 5 = external pixel border before last color
                            buf[6] = COLOR_LIGHT_THEME_TEXT_SHADOW;       // 1 = text color
                            break;
                        case 1:
                            buf[1] = COLOR_NEON_BORDER_2;       // 1 = window highlight
                            buf[2] = COLOR_LIGHT_THEME_BG_DARK;       // 2 = window border
                            buf[3] = COLOR_LIGHT_THEME_BG_LIGHT;       // 3 = bg
                            break;
                        case 2:
                            break;
                    }
                    break;
                case THEME_COLOR_DARK:
                    break;
                case THEME_COLOR_USER:
                    switch (i) {
                        case 0:
                            buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];       // 1 = text color
                            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // window highlight
                            buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];       // 3 = window border
                            buf[4] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];       // 4 = bg
                            buf[5] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];            // 5 = external pixel border before last color
                            buf[6] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];       // 2 = text shadow & window highlight
                            break;
                        case 1:
                            buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // 1 = window highlight
                            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];       // 2 = window border
                            buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];       // 3 = bg
                            break;
                        case 2:
                            break;
                    }
                    break;
                case THEME_COLOR_VANILLA:
                    break;
                
            }
            LoadPalette(buf, sUIDataPtr->bgData[i].palSlot*16, sUIDataPtr->bgData[i].palCount*2);
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
