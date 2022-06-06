#ifndef OVERWORLD_NOTIF_H_GUARD
#define OVERWORLD_NOTIF_H_GUARD

void Task_NotificationWindow(u8 taskId);
void HideNotificationWindow(void);
bool32 IsNotificationBusy(void);
void QueueNotification(const u8 *message, u32 type, u32 time);
void debugprint(const u8 *buffer);

#endif//OVERWORLD_NOTIF_H_GUARD