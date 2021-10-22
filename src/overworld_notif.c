#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "main.h"
#include "script.h"
#include "overworld_notif.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

#define MAX_NOTIFICATION_IN_QUEUE 4

#define NOTIF_ALLOCATED 0x1

struct NotificationQueueEntry
{
    u8 flags;
    u8 dispTime;
    u8 queuePos;
    u8 type;
    u8 notifText[0x40];
};

enum NotificationState
{
    NOTIF_STATE_IDLE = 0,
    NOTIF_STATE_FIND_IN_QUEUE,
    NOTIF_STATE_DISPLAYING,
    NOTIF_STATE_HIDE,
    NOTIF_STATE_INTERRUPTED,
};

struct Notification
{
    u8 state;
    u8 lastQueuePos;
    u8 currentNotif;
    u8 dispTimer;
    struct NotificationQueueEntry queue[MAX_NOTIFICATION_IN_QUEUE];
};

EWRAM_DATA struct Notification sNotification = {0};

const u16 gNotifyFrame[] = INCBIN_U16("graphics/notification/notify_window.4bpp");
const u16 gNotifyFramePal[] = INCBIN_U16("graphics/notification/notify_window.gbapal");

static const u8 * sNotificationTypeNames[] = 
{
    (u8[])_("Achievements"),
    (u8[])_("Interest"),
    (u8[])_("Real Estate"),
    (u8[])_("Pickup"),
    (u8[])_("Mission"),
    (u8[])_("Quest"),
}; 
void QueueNotification(u8 *message, u32 type, u32 time)
{
    int i;
    if (sNotification.lastQueuePos >= MAX_NOTIFICATION_IN_QUEUE)
        return;
    for (i = 0; i < MAX_NOTIFICATION_IN_QUEUE; i++)
    {
        if (!(sNotification.queue[i].flags & NOTIF_ALLOCATED))
        {
            sNotification.queue[i].queuePos = sNotification.lastQueuePos++;
            sNotification.queue[i].dispTime = time;
            sNotification.queue[i].type = type;
            sNotification.queue[i].flags |= NOTIF_ALLOCATED;
            StringCopy(sNotification.queue[i].notifText, message);
            break;
        }
    }
}

void ShowNotificationWindow(void);
void Task_DisplayNotification(u8);

void Task_NotificationWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    int i;
    u32 queuePos = 0xFF;
    int highest;
    //mgba_open();
    //mgba_printf(LOGINFO, "Notification state = %d ", sNotification.state);
    switch (sNotification.state)
    {
    case NOTIF_STATE_IDLE:
        if (sNotification.lastQueuePos > 0)
            sNotification.state = NOTIF_STATE_FIND_IN_QUEUE;
        break;
    case NOTIF_STATE_FIND_IN_QUEUE:
        if (sNotification.lastQueuePos <= 0)
        {
            sNotification.state = NOTIF_STATE_IDLE;
            break;
        }
        for (i = 0; i < MAX_NOTIFICATION_IN_QUEUE; i++)
        {
            if (sNotification.queue[i].flags & NOTIF_ALLOCATED)
            {
                if (queuePos > sNotification.queue[i].queuePos)
                {
                    queuePos = sNotification.queue[i].queuePos;
                    highest = i;
                }
            }
        }
        sNotification.currentNotif = highest;
        sNotification.state = NOTIF_STATE_DISPLAYING;
        task->data[0] = 0;
        break;
    case NOTIF_STATE_DISPLAYING:
        if (ScriptContext2_IsEnabled())
        {
            //mgba_printf(LOGINFO, "Notification %d interrupted", sNotification.currentNotif);
            sNotification.state = NOTIF_STATE_INTERRUPTED;
            HideNotificationWindow();
            break;
        }
        switch (task->data[0])
        {
        case 0:
            HideMapNamePopUpWindow();
            task->data[1] = 48;
            task->data[0]++;
            break;
        case 1:
            ShowNotificationWindow();
            task->data[0]++;
            break;
        case 2:
            task->data[1] -= 4;
            if (task->data[1] <= 0)
            {
                task->data[1] = 0;
                task->data[0]++;
            }
            break;
        case 3:
            if (sNotification.dispTimer++ >= sNotification.queue[sNotification.currentNotif].dispTime)
            {
                sNotification.dispTimer = 0;
                task->data[0]++;
            }
            break;
        case 4:
            task->data[1] += 4;
            if (task->data[1] >= 48)
            {
                task->data[1] = 48;
                task->data[0]++;
            }
            break;
        case 5:
            ClearStdWindowAndFrame(GetNotificationWindowId(), TRUE);
            task->data[1] = 0;
            task->data[0]++;
            break;
        case 6:
            sNotification.lastQueuePos--;
            sNotification.state = NOTIF_STATE_IDLE;
            sNotification.queue[sNotification.currentNotif].flags &= ~NOTIF_ALLOCATED;
            HideNotificationWindow();
            return;
        }

        SetGpuReg(REG_OFFSET_BG0VOFS, task->data[1]);
        break;
    case NOTIF_STATE_INTERRUPTED:
        if (!ScriptContext2_IsEnabled())
        {
            //mgba_printf(LOGINFO, "Notification interrupt finished");
            sNotification.state = NOTIF_STATE_DISPLAYING;
            sNotification.dispTimer = 0;
            if (task->data[0] < 4)
            {
                task->data[1] = 48;
                task->data[0] = 1;
            }
            else
                task->data[0] = 6;
        }
        break;
    }
}

void WindowFunc_DrawNotifyFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    int i;

    FillBgTilemapBufferRect(bg,
                            0x21D + 0,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            14);
    for(i = 0; i < 7; i++)
    {
        FillBgTilemapBufferRect(bg,
                        0x21D + 9 + i,
                        tilemapLeft + i,
                        tilemapTop - 1,
                        1,
                        1,
                        14);
        FillBgTilemapBufferRect(bg,
                        0x21D + 9 + i + 7,
                        tilemapLeft + i,
                        tilemapTop,
                        1,
                        1,
                        14);
    }
    FillBgTilemapBufferRect(bg,
                            0x21D + 1,
                            tilemapLeft+7,
                            tilemapTop - 1,
                            width-7,
                            1,
                            14);
    FillBgTilemapBufferRect(bg,
                            0x21D + 2,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            14);

    for (i = tilemapTop; i < tilemapTop + height; i++)
    {
        FillBgTilemapBufferRect(bg,
                                0x21D + 3,
                                tilemapLeft - 1,
                                i,
                                1,
                                1,
                                14);
        FillBgTilemapBufferRect(bg,
                                0x21D + 5,
                                tilemapLeft + width,
                                i,
                                1,
                                1,
                                14);
    }

    FillBgTilemapBufferRect(bg,
                            0x21D + 6,
                            tilemapLeft - 1,
                            tilemapTop + height,
                            1,
                            1,
                            14);
    FillBgTilemapBufferRect(bg,
                            0x21D + 7,
                            tilemapLeft,
                            tilemapTop + height,
                            width,
                            1,
                            14);
    FillBgTilemapBufferRect(bg,
                            0x21D + 8,
                            tilemapLeft + width,
                            tilemapTop + height,
                            1,
                            1,
                            14);
}

void ShowNotificationWindow(void)
{
    u32 windowId;
    const u8 color[] = {1, 6, 2};
    struct NotificationQueueEntry *notifData = &sNotification.queue[sNotification.currentNotif];
    windowId = AddNotificationWindow();
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), gNotifyFrame, 9*0x20, 0x21D);
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), gNotifyFrame+(notifData->type+1)*2*7*0x10, 2*7*0x20, 0x21D+9);
    LoadPalette(gNotifyFramePal, 0xE0, 0x20);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    CallWindowFunction(windowId, WindowFunc_DrawNotifyFrame);
    //AddTextPrinterParameterized(windowId, 0, sNotificationTypeNames[notifData->type], 2, 0, 0xFF, NULL);
    AddTextPrinterParameterized3(windowId, 1, 1, 5, color, 0xFF, notifData->notifText);
    AddTextPrinterParameterized3(windowId, 1, 1, 5+12, color, 0xFF, notifData->notifText);
    CopyWindowToVram(windowId, 3);
}

void HideNotificationWindow(void)
{
    if (GetNotificationWindowId() == 0xFF)
        return;
    if (sNotification.state == NOTIF_STATE_DISPLAYING)
        sNotification.state = NOTIF_STATE_INTERRUPTED;
    ClearStdWindowAndFrameToTransparent(GetNotificationWindowId(), TRUE);
    RemoveNotificationWindow();
    SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
}

bool32 IsNotificationBusy(void)
{
    return sNotification.state != NOTIF_STATE_IDLE;
}