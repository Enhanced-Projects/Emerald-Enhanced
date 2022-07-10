#include "global.h"
#include "random.h"
#include "RyuDynDeliveries.h" 
#include "rtc.h"
#include "constants/event_object_movement.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "event_data.h"
#include "fieldmap.h"
#include "string_util.h"
#include "region_map.h"
#include "overworld_notif.h"
#include "item.h"
#include "constants/maps.h"
#include "lifeskill.h"

const u8 sText_comma[] = _(", ");
const u8 sText_locations[] = _("Delivery Locations:");

const u16 sRyuDeliveryObjEventIds[] = {
    OBJ_EVENT_GFX_CONTEST_JUDGE,
    OBJ_EVENT_GFX_POKEFAN_F,
    OBJ_EVENT_GFX_MAN_4,
    OBJ_EVENT_GFX_AQUA_MEMBER_F,
    OBJ_EVENT_GFX_MAGMA_MEMBER_M,
    OBJ_EVENT_GFX_EXPERT_F,
    OBJ_EVENT_GFX_MAN_1,
    OBJ_EVENT_GFX_WOMAN_5,
    OBJ_EVENT_GFX_SCIENTIST_1,
    OBJ_EVENT_GFX_WOMAN_4
};

const u8 sRyuDeliveryTargetToText[][13] = {
    [OBJ_EVENT_GFX_CONTEST_JUDGE] =  _("Reginald"),
    [OBJ_EVENT_GFX_POKEFAN_F] =      _("Miia"),
    [OBJ_EVENT_GFX_MAN_4] =          _("Jason"),
    [OBJ_EVENT_GFX_AQUA_MEMBER_F] =  _("Sandra"),
    [OBJ_EVENT_GFX_MAGMA_MEMBER_M] = _("Michael"),
    [OBJ_EVENT_GFX_EXPERT_F] =       _("Linda"),
    [OBJ_EVENT_GFX_MAN_1] =          _("Gerald"),
    [OBJ_EVENT_GFX_WOMAN_5] =        _("Miranda"),
    [OBJ_EVENT_GFX_SCIENTIST_1] =    _("Donovan"),
    [OBJ_EVENT_GFX_WOMAN_4] =        _("Eleanor")
};

const u8 mapNameList[][13] = {
    [0] = _("Mauville"),
    [1] = _("Rustboro"),
    [2] = _("Route 66"),
    [3] = _("Fallarbor"),
    [4] = _("Mossdeep"),
    [5] = _("Lilycove"),
    [6] = _("Oldale"),
    [7] = _("Dewford")
};

const u16 sRyuDeliveryPackagesList[] = {
    ITEM_COSMETIC_GOODS,
    ITEM_SPARE_PARTS,
    ITEM_HOME_GOODS,
    ITEM_GROCERIES,
    ITEM_MEDICAL_SUPPLIES,
    ITEM_FLOWERS,
    ITEM_OFFICE_SUPPLIES,
    ITEM_REFRESHMENTS, 
    ITEM_ANTIQUE,
    ITEM_ELECTRONICS
};

const u8 sRyuDeliveryMapsList[][2] = {
    {MAP_GROUP(MAUVILLE_CITY), MAP_NUM(MAUVILLE_CITY)},
    {MAP_GROUP(RUSTBORO_CITY), MAP_NUM(RUSTBORO_CITY)},
    {MAP_GROUP(ROUTE66), MAP_NUM(ROUTE66)},
    {MAP_GROUP(FALLARBOR_TOWN), MAP_NUM(FALLARBOR_TOWN)},
    {MAP_GROUP(MOSSDEEP_CITY), MAP_NUM(MOSSDEEP_CITY)},
    {MAP_GROUP(LILYCOVE_CITY), MAP_NUM(LILYCOVE_CITY)},
    {MAP_GROUP(OLDALE_TOWN), MAP_NUM(OLDALE_TOWN)},
    {MAP_GROUP(DEWFORD_TOWN), MAP_NUM(DEWFORD_TOWN)},
};

const u8 sRyuDeliveryCoords[][3][2] = {
    [0] = {{30, 5}, {36, 17}, {10, 14}},
    [1] = {{35, 32}, {15, 19}, {14, 37}},
    [2] = {{5, 22}, {29, 27}, {22, 6}},
    [3] = {{7, 6}, {17, 9}, {4, 17}},
    [4] = {{23, 16}, {33, 9}, {52, 18}},
    [5] = {{14, 20}, {53, 13}, {20, 6}},
    [6] = {{4, 2}, {17, 6}, {4, 16}},
    [7] = {{11, 14}, {26, 8}, {26, 3}},
};
void StartNewDeliveryQueue(void) 
{
    u8 numJobs = (Random() % 4) + 1;
    u8 i;
    u16 coordGroup = (Random() % 3);
    u16 lowReward = gRyuLowPickupTable[(Random() % NUM_PICKUP_TABLE_ENTRIES)];
    u16 highReward = gRyuMaxPickupTable[(Random() % NUM_PICKUP_TABLE_ENTRIES)];
    u16 mapsum = 0, maplistnum = 0;
    u16 seed = Random();
    u16 value[3], gap[3], threshold[3] = { 0 };
    RyuClearDeliveryQueue();

    VarSet(VAR_RYU_NUM_DELIVERIES, numJobs);
    for (i = 0;i < numJobs;i++)
    {
        gap[0] = 1 + (Random() % (ARRAY_COUNT(sRyuDeliveryMapsList) - threshold[0] - numJobs + i));
        value[0] = (seed + threshold[0] + (i != 0 ? gap[0] : 0)) % ARRAY_COUNT(sRyuDeliveryMapsList);
        threshold[0] = i != 0 ? threshold[0] + gap[0] : threshold[0];
        maplistnum = value[0];

        gSaveBlock2Ptr->Deliveries[i].finished = FALSE;

        gap[1] = 1 + (Random() % (ARRAY_COUNT(sRyuDeliveryObjEventIds) - threshold[1] - numJobs + i));
        value[1] = (seed + threshold[1] + (i != 0 ? gap[1] : 0)) % ARRAY_COUNT(sRyuDeliveryObjEventIds);
        threshold[1] = i != 0 ? threshold[1] + gap[1] : threshold[1];

        gSaveBlock2Ptr->Deliveries[i].GfxID =   sRyuDeliveryObjEventIds[value[1]];

        gap[2] = 1 + (Random() % (ARRAY_COUNT(sRyuDeliveryPackagesList) - threshold[2] - numJobs + i));
        value[2] = (seed + threshold[2] + (i != 0 ? gap[2] : 0)) % ARRAY_COUNT(sRyuDeliveryPackagesList);
        threshold[2] = i != 0 ? threshold[2] + gap[2] : threshold[1];

        gSaveBlock2Ptr->Deliveries[i].itemId = sRyuDeliveryPackagesList[value[2]];
        AddBagItem(gSaveBlock2Ptr->Deliveries[i].itemId, 1);
        gSaveBlock2Ptr->Deliveries[i].mapgroup =  sRyuDeliveryMapsList[maplistnum][0];
        gSaveBlock2Ptr->Deliveries[i].mapnum =  sRyuDeliveryMapsList[maplistnum][1];
        gSaveBlock2Ptr->Deliveries[i].xpos = sRyuDeliveryCoords[maplistnum][coordGroup][0];
        gSaveBlock2Ptr->Deliveries[i].ypos = sRyuDeliveryCoords[maplistnum][coordGroup][1];
        gSaveBlock2Ptr->Deliveries[i].mapNameId = maplistnum;
    }
    gSaveBlock2Ptr->DeliveryTimer.minutesGiven = numJobs;
    gSaveBlock2Ptr->DeliveryTimer.Timer = numJobs + 1;
    gSaveBlock2Ptr->DeliveryTimer.rtcTimeStart = gLocalTime.minutes;
    gSaveBlock2Ptr->DeliveryTimer.saveBlockTimeStart = gSaveBlock2Ptr->playTimeMinutes;
    if ((gSaveBlock2Ptr->DeliveryTimer.rtcTimeStart > 44) || (gSaveBlock2Ptr->playTimeMinutes > 44))
        gSaveBlock2Ptr->DeliveryTimer.saveBlockTimeSanity = FALSE;//save block minutes are in an unsafe state to test.
    else
        gSaveBlock2Ptr->DeliveryTimer.saveBlockTimeSanity = TRUE;//save block time can be safely compared with RTC time.
    gSaveBlock2Ptr->DeliveryTimer.active = TRUE;

    //roll rewards wheng iving the job so that the player can't savescum the reward item.
    VarSet(VAR_RYU_DELIVERY_SYSTEM_HIGH_REWARD_ROLL, highReward);
    VarSet(VAR_RYU_DELIVERY_SYSTEM_LOW_REWARD_ROLL, lowReward);

}
//u16 locSum = (gSaveBlock1Ptr->location.mapGroup << 8) + (gSaveBlock1Ptr->location.mapNum);

const u8 deliverA[] = _("Take ");
const u8 deliverto[] = _(" to ");
const u8 deliverAt[] = _(" at ");
const u8 deliverperiod[] = _(".$");
const u8 sText_emptyString[] = _(" $");
const u8 gText_JobEmpty[] = _("Job slot empty. $");
void RyuBufferCurrentJobs(void)
{
    u8 i;
    for (i = 0; i < 4; ++i) {
        u8* current = i == 0 ? gStringVar1 : i == 1 ? gStringVar2 : i == 2 ? gStringVar3 : gRyuStringVar1;
        if (gSaveBlock2Ptr->Deliveries[i].finished == FALSE && gSaveBlock2Ptr->Deliveries[i].itemId != 1023)
        {
            StringCopy(current, deliverA);
            CopyItemName(gSaveBlock2Ptr->Deliveries[i].itemId, gRyuStringVar2);
            StringAppend(current, gRyuStringVar2);
            StringAppend(current, deliverto);
            StringAppend(current, sRyuDeliveryTargetToText[gSaveBlock2Ptr->Deliveries[i].GfxID]);
            StringAppend(current, deliverAt);
            StringAppend(current, mapNameList[(gSaveBlock2Ptr->Deliveries[i].mapNameId)]);
            StringAppend(current, deliverperiod);
        }
        else
        {
            StringCopy(current, gText_JobEmpty);
        }
    }
}


void RyuCountActiveJobs(void)
{
    u32 i;
    u8 count = 0;
    for (i = 0;i < 4; i++)
        if (!((gSaveBlock2Ptr->Deliveries[i].GfxID) == 255))
            count++;

    gSpecialVar_Result = count;
}

bool32 CheckRTCHealth(void)
{
    s8 SBMins = gSaveBlock2Ptr->playTimeMinutes;
    s8 DTMins = gSaveBlock2Ptr->DeliveryTimer.saveBlockTimeStart;
    s8 RTCmins = gLocalTime.minutes;

    if (gSaveBlock2Ptr->DeliveryTimer.saveBlockTimeSanity == FALSE)//rtc mins was greater than 54, so hours would have to be checked.
        return TRUE; //passed check by default

    if (SBMins == DTMins)//if SB time hasn't advanced, fail test.
        return FALSE; //failed check

    if (gSaveBlock2Ptr->DeliveryTimer.rtcTimeStart == RTCmins)//rtc didn't advance any since the delivery was started. Fail test.
        return FALSE;

    return TRUE;//all checks passed
    
}

void RyuClearDeliveryQueue(void)
{
    u32 i;
    for (i = 0; i< 4; i++)
    {
        gSaveBlock2Ptr->Deliveries[i].finished = TRUE;
        gSaveBlock2Ptr->Deliveries[i].GfxID = 255;
        gSaveBlock2Ptr->Deliveries[i].itemId = 1023;
        gSaveBlock2Ptr->Deliveries[i].mapgroup = 0xFF;
        gSaveBlock2Ptr->Deliveries[i].mapnum = 0xFF;
        gSaveBlock2Ptr->Deliveries[i].xpos = 0;
        gSaveBlock2Ptr->Deliveries[i].ypos = 0;
    }

    gSaveBlock2Ptr->DeliveryTimer.active = FALSE;
    gSaveBlock2Ptr->DeliveryTimer.minutesGiven = 0;
    gSaveBlock2Ptr->DeliveryTimer.rtcTimeStart = 0;
    gSaveBlock2Ptr->DeliveryTimer.saveBlockTimeSanity = TRUE;
    gSaveBlock2Ptr->DeliveryTimer.Timer = 0;
    gSaveBlock2Ptr->DeliveryTimer.unusedDeliveryTimeBits = 0;
    gSaveBlock2Ptr->DeliveryTimer.rtcTimeStart = 0;
    gSaveBlock2Ptr->DeliveryTimer.quotaNum = 0;
    gSaveBlock2Ptr->DeliveryTimer.timeRanOut = FALSE;

}

int CheckDeliverySuccessful(void)
{
    u32 i;
    bool32 ret = FALSE; //value defaults to false, so that if the job isn't found in the loop, it's not done.
    u32 jobsDone = 0;
    for (i = 0;i<4;i++)
    {
        if ((gSaveBlock2Ptr->Deliveries[i].mapgroup == gSaveBlock1Ptr->location.mapGroup) &&
            (gSaveBlock2Ptr->Deliveries[i].mapnum == gSaveBlock1Ptr->location.mapNum) &&
            (!(gSaveBlock2Ptr->Deliveries[i].finished) == TRUE))
            {
                RemoveBagItem(gSaveBlock2Ptr->Deliveries[i].itemId, 1);
                gSaveBlock2Ptr->Deliveries[i].finished = TRUE;             
                ret = TRUE;
            }
    }
    for (i = 0;i < 4; i++)
    {
        if ((gSaveBlock2Ptr->Deliveries[i].finished) == TRUE)//check if any deliveries are unfinished
        {
            jobsDone++;
        }
    }

    if (jobsDone == (VarGet(VAR_RYU_NUM_DELIVERIES)))//if the number of finished jobs is the same as the number of jobs given
    {
        gSaveBlock2Ptr->DeliveryTimer.active = FALSE; //stop timer
        gSaveBlock2Ptr->DeliveryTimer.quotaNum = (VarGet(VAR_RYU_DELIVERY_SYSTEM_DATA)); //copy the quota to struct so it can be adavanced
        VarSet(VAR_RYU_DELIVERY_SYSTEM_DATA, 10);//change the quest tracker data to tell player to return for route reward
    }
    return ret;
}

int CheckFullDeliveryQueueFinished(void)
{
    u32 i;
    u32 jobsDone = 0;
    u16 highReward = VarGet(VAR_RYU_DELIVERY_SYSTEM_HIGH_REWARD_ROLL);
    u16 lowReward = VarGet(VAR_RYU_DELIVERY_SYSTEM_LOW_REWARD_ROLL);
    for (i = 0;i < 4; i++)
    {
        if ((gSaveBlock2Ptr->Deliveries[i].finished) == TRUE)//check if any deliveries are unfinished
        {
            jobsDone++;
        }
    }

    if (jobsDone == (VarGet(VAR_RYU_NUM_DELIVERIES)))//if the number of finished jobs is the same as the number of jobs given
    {
        VarSet(VAR_RYU_DELIVERY_SYSTEM_DATA, (gSaveBlock2Ptr->DeliveryTimer.quotaNum + 1));//advance quota data.
        if ((gSaveBlock2Ptr->DeliveryTimer.timeRanOut == FALSE) && (CheckRTCHealth() == TRUE))//check for broken/tampered RTC
        {
            return highReward;//player completed the queue in time
        }
        else
        {
            return lowReward;//player was late
        }
            
    } 
    return 0;//queue not done.
}