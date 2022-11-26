#include "global.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "script_movement.h"
#include "task.h"
#include "trainer_see.h"
#include "constants/event_objects.h"

bool8 IsPlayerStandingStill(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_TRANSITION)
        return FALSE;
    else
        return TRUE;
}

static void Task_FreezePlayer(u8 taskId)
{
    if (IsPlayerStandingStill())
    {
        PlayerFreeze();
        DestroyTask(taskId);
    }
}

bool8 IsFreezePlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezePlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}


void FreezeObjects_WaitForPlayer(void)
{
    FreezeObjectEvents();
    CreateTask(Task_FreezePlayer, 80);
}

static void Task_FreezeSelectedObjectAndPlayer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (!task->data[0] && IsPlayerStandingStill() == TRUE)
    {
        PlayerFreeze();
        task->data[0] = 1;
    }
    if (!task->data[1] && !gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
        task->data[1] = 1;
    }
    if (task->data[0] && task->data[1])
        DestroyTask(taskId);
}

bool8 IsFreezeSelectedObjectAndPlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezeSelectedObjectAndPlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}

void LockSelectedObjectEvent(void)
{
    u8 taskId;
    FreezeObjectEventsExceptOne(gSelectedObjectEvent);
    taskId = CreateTask(Task_FreezeSelectedObjectAndPlayer, 80);
    if (!gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
        gTasks[taskId].data[1] = 1;
    }
}

void ScriptUnfreezeObjectEvents(void)
{
    u8 playerObjectId = GetObjectEventIdByLocalIdAndMap(PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
}

void UnionRoom_UnlockPlayerAndChatPartner(void)
{
    u8 playerObjectId;

    if (gObjectEvents[gSelectedObjectEvent].active)
        ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gSelectedObjectEvent]);
    playerObjectId = GetObjectEventIdByLocalIdAndMap(PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
}

void Script_FacePlayer(void)
{
    ObjectEventFaceOppositeDirection(&gObjectEvents[gSelectedObjectEvent], gSpecialVar_Facing);
}

void Script_ClearHeldMovement(void)
{
    ObjectEventClearHeldMovementIfActive(&gObjectEvents[gSelectedObjectEvent]);
}

static void Task_FreezeObjectAndPlayer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 objectEventId = task->data[2];

    if (!task->data[0] && IsPlayerStandingStill() == TRUE)
    {
        PlayerFreeze();
        task->data[0] = 1;
    }
    if (!task->data[1] && !gObjectEvents[objectEventId].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[objectEventId]);
        task->data[1] = 1;
    }
    if (task->data[0] && task->data[1])
        DestroyTask(taskId);
}

void FreezeForApproachingTrainers(void)
{
    u8 trainerObjectId1, trainerObjectId2, taskId;
    trainerObjectId1 = GetChosenApproachingTrainerObjectEventId(0);
    if(gNoOfApproachingTrainers == 2)
    {
        trainerObjectId2 = GetChosenApproachingTrainerObjectEventId(1);
        FreezeObjectEventsExceptTwo(trainerObjectId1, trainerObjectId2);
        taskId = CreateTask(Task_FreezeObjectAndPlayer, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gObjectEvents[trainerObjectId1].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId1]);
            gTasks[taskId].data[1] = 1;
        }
        taskId = CreateTask(Task_FreezeObjectAndPlayer, 81);
        gTasks[taskId].data[2] = trainerObjectId2;
        if(!gObjectEvents[trainerObjectId2].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId2]);
            gTasks[taskId].data[1] = 1;
        }
    }
    else
    {
        FreezeObjectEventsExceptOne(trainerObjectId1);
        taskId = CreateTask(Task_FreezeObjectAndPlayer, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gObjectEvents[trainerObjectId1].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId1]);
            gTasks[taskId].data[1] = 1;
        }
    }
}

bool8 IsFreezeObjectAndPlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezeObjectAndPlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}
