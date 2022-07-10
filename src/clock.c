#include "global.h"
#include "event_data.h"
#include "rtc.h"
#include "time_events.h"
#include "field_specials.h"
#include "lottery_corner.h"
#include "dewford_trend.h"
#include "tv.h"
#include "field_weather.h"
#include "berry.h"
#include "main.h"
#include "overworld.h"
#include "wallclock.h"
#include "factions.h"
#include "RyuRealEstate.h"
#include "overworld_notif.h"

static void UpdatePerDay(struct Time *localTime);
void UpdatePerHour(struct Time *localTime);
static void UpdatePerMinute(struct Time *localTime);

static void InitTimeBasedEvents(void)
{
    FlagSet(FLAG_SYS_CLOCK_SET);
    RtcCalcLocalTime();
    gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
    VarSet(VAR_DAYS, gLocalTime.days);
    VarSet(VAR_HOURS, gLocalTime.hours);
}

void DoTimeBasedEvents(void)
{
    if (FlagGet(FLAG_SYS_CLOCK_SET) && !InPokemonCenter())
    {
        RtcCalcLocalTime();
        UpdatePerDay(&gLocalTime);
        UpdatePerHour(&gLocalTime);
        UpdatePerMinute(&gLocalTime);
    }

}

void RotateDailyUBGroup(void)
{
    VarSet(VAR_RYU_UB_EVENT_TIMER, (VarGet(VAR_RYU_UB_EVENT_TIMER) + 1));
        if (VarGet(VAR_RYU_UB_EVENT_TIMER) == 4)
            VarSet(VAR_RYU_UB_EVENT_TIMER, 0);
}

void UpdatePerHour(struct Time *localTime)
{

    if ((!(gLocalTime.hours == 0)) && (gLocalTime.hours > VarGet(VAR_HOURS))) //Had to make this change because this is called whenever time is checked, causing this to repeat many times a second.
    {
        DoHourlyRealEstateNotification();
        if ((FlagGet(FLAG_RYU_DS_BRENDAN_PARTNERS)) || (FlagGet(FLAG_RYU_DS_DAWN_PARTNERS)))//only need to check if player has finished companion line for rival to check this event 
        {
            if ((gLocalTime.hours >= 14) && (gLocalTime.hours <= 20)) //betwen 2pm and 8pm rival hangs out at lab. Different dialogue.
            {
                if (gSaveBlock2Ptr->playerGender == MALE)
                {                                     //OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == 105))// 3a. don't bother if they are currently following player.|No constant here because it's undefined in this context
                       {
                           FlagSet(FLAG_HIDE_DAWNS_HOUSE_DAWN);
                           FlagClear(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL);
                       }
                }
                else
                {                                     //OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == 100))//see 3a
                       {
                           FlagSet(FLAG_HIDE_BRENDANS_HOUSE_BRENDAN);
                           FlagClear(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL);
                       }
                }

            }
            else //Rival is at home. Remove them from lab.
            {
               if (gSaveBlock2Ptr->playerGender == FEMALE)
               {
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == 100))//see 3a
                       {
                           FlagClear(FLAG_HIDE_BRENDANS_HOUSE_BRENDAN);
                           FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL);
                       }
               }
               else
               {
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == 105)) //see 3a
                       {
                           FlagClear(FLAG_HIDE_DAWNS_HOUSE_DAWN);
                           FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL);
                       }
               }

            }
        }
    }
    if (((gLocalTime.hours >= 17) || (gLocalTime.hours <= 8)) && (VarGet(VAR_RYU_QUEST_MAY) > 10)) //birch is at the lab between 8am and 5pm if player unlocked May.
    {
        FlagClear(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH);
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            FlagSet(FLAG_HIDE_LRT_DH_BIRCH); //hide birch in Dawn's house
        }
        else
        {
            FlagSet(FLAG_HIDE_LRT_BH_BIRCH); //hide birch in Brendan's house
        }
    }
    else if (((gLocalTime.hours > 8) && (gLocalTime.hours < 17)) && (VarGet(VAR_RYU_QUEST_MAY) > 10)) //birch is at home from 6pm to 7am if player unlocked May.
    {
        FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH);
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            FlagClear(FLAG_HIDE_LRT_DH_BIRCH); //show birch in Dawn's house
        }
        else
        {
            FlagClear(FLAG_HIDE_LRT_BH_BIRCH); //show birch in Brendan's house
        }
    }
    else //default to having birch in the lab if above requirements aren't met.
    {
        FlagSet(FLAG_HIDE_LRT_DH_BIRCH);
        FlagSet(FLAG_HIDE_LRT_BH_BIRCH);
        FlagClear(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH);
    }
    VarSet(VAR_HOURS, gLocalTime.hours);
}

const u8 gRyuText_DailyQuestsReset[] = _("Daily quests have been reset.");

static void UpdatePerDay(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 daysSince;

    if (*days != localTime->days && *days <= localTime->days)
    {
        daysSince = localTime->days - *days;
        ClearDailyQuestData();
        ClearDailyFlags();
        DoDailyRealEstateTasks();
        RotateDailyUBGroup();
        UpdateDewfordTrendPerDay(daysSince);
        UpdateTVShowsPerDay(daysSince);
        UpdateWeatherPerDay(daysSince);
        UpdatePartyPokerusTime(daysSince);
        UpdateMirageRnd(daysSince);
        UpdateBirchState(daysSince);
        UpdateFrontierManiac(daysSince);
        UpdateFrontierGambler(daysSince);
        SetShoalItemFlag(daysSince);
        SetRandomLotteryNumber(daysSince);
        FlagClear(FLAG_RYU_FAILED_PROF_SPECIAL_QUEST);
        *days = localTime->days;
        QueueNotification(gRyuText_DailyQuestsReset, NOTIFY_GENERAL, 60);
    }
}

static void UpdatePerMinute(struct Time *localTime)
{
    struct Time difference;
    int minutes;

    CalcTimeDifference(&difference, &gSaveBlock2Ptr->lastBerryTreeUpdate, localTime);
    minutes = 24 * 60 * difference.days + 60 * difference.hours + difference.minutes;
    if (minutes != 0)
    {
        if (minutes >= 0)
        {
            BerryTreeTimeUpdate(minutes);
            gSaveBlock2Ptr->lastBerryTreeUpdate = *localTime;
            if (gSaveBlock2Ptr->DeliveryTimer.active == TRUE)
            {
                gSaveBlock2Ptr->DeliveryTimer.Timer -= 1;
                if (gSaveBlock2Ptr->DeliveryTimer.Timer == 0)
                {
                    gSaveBlock2Ptr->DeliveryTimer.active = FALSE;
                    gSaveBlock2Ptr->DeliveryTimer.timeRanOut = TRUE;
                    QueueNotification(((const u8 []) _("Delivery time limit expired.")), NOTIFY_GENERAL, 120);
                }
                else
                {
                    QueueNotification(((const u8 []) _("Delivery: {STR_VAR_1} min(s) left.")), NOTIFY_GENERAL, 120);
                }
            }
        }
    }
}

static void ReturnFromStartWallClock(void)
{
    InitTimeBasedEvents();
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void StartWallClock(void)
{
    SetMainCallback2(CB2_StartWallClock);
    gMain.savedCallback = ReturnFromStartWallClock;
}
