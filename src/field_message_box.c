#include "global.h"
#include "field_message_box.h"
#include "menu.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "match_call.h"

EWRAM_DATA u8 gFieldMessageBoxMode = 0;

static void textbox_auto_and_task_add(void);

void InitFieldMessageBox(void)
{
    gFieldMessageBoxMode = 0;
    gTextFlags.canABSpeedUpPrint = 0;
    gTextFlags.useAlternateDownArrow = 0;
    gTextFlags.autoScroll = 0;
    gTextFlags.forceMidTextSpeed = 0;
}

static void sub_8098154(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
        case 0:
           sub_81973A4();
           task->data[0]++;
           break;
        case 1:
           DrawDialogueFrame(0, 1);
           task->data[0]++;
           break;
        case 2:
            if (RunTextPrintersAndIsPrinter0Active() != 1)
            {
                gFieldMessageBoxMode = 0;
                DestroyTask(taskId);
            }
    }
}

static void task_add_textbox(void)
{
    CreateTask(sub_8098154, 0x50);
}

static void task_del_textbox(void)
{
    u8 taskId = FindTaskIdByFunc(sub_8098154);
    if (taskId != 0xFF)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(const u8 *message)
{
    if (gFieldMessageBoxMode != 0)
        return FALSE;
    textbox_fdecode_auto_and_task_add(message, 1);
    gFieldMessageBoxMode = 2;
    return TRUE;
}

void sub_8098214(u8 taskId)
{
    if (!IsMatchCallTaskActive())
    {
        gFieldMessageBoxMode = 0;
        DestroyTask(taskId);
    }
}

bool8 sub_8098238(const u8 *message)
{
    if (gFieldMessageBoxMode != 0)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, message);
    CreateTask(sub_8098214, 0);
    StartMatchCallFromScript(message);
    gFieldMessageBoxMode = 2;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(const u8 *message)
{
    if (gFieldMessageBoxMode != 0)
        return FALSE;
    gFieldMessageBoxMode = 3;
    textbox_fdecode_auto_and_task_add(message, 0);
    return TRUE;
}

bool8 sub_80982A0(u8 *str)
{
    gFieldMessageBoxMode = 3;
    textbox_fdecode_auto_and_task_add(str, 1);
    return TRUE;
}

bool8 sub_80982B8(void)
{
    if (gFieldMessageBoxMode != 0)
        return FALSE;
    gFieldMessageBoxMode = 2;
    textbox_auto_and_task_add();
    return TRUE;
}

void textbox_fdecode_auto_and_task_add(const u8* str, bool32 allowSkippingDelayWithButtonPress)
{
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterForMessage(allowSkippingDelayWithButtonPress);
    task_add_textbox();
}

static void textbox_auto_and_task_add(void)
{
    AddTextPrinterForMessage(TRUE);
    task_add_textbox();
}

void HideFieldMessageBox(void)
{
    task_del_textbox();
    ClearDialogWindowAndFrame(0, 1);
    gFieldMessageBoxMode = 0;
}

u8 GetFieldMessageBoxMode(void)
{
    return gFieldMessageBoxMode;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (gFieldMessageBoxMode == 0)
        return TRUE;
    return FALSE;
}

void sub_8098358(void)
{
    task_del_textbox();
    DrawStdWindowFrame(0, 1);
    gFieldMessageBoxMode = 0;
}

void sub_8098374(void)
{
    task_del_textbox();
    gFieldMessageBoxMode = 0;
}
