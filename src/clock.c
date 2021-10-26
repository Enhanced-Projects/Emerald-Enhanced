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

    if (FlagGet(FLAG_RYU_START_DELIVERY_TIMER) == TRUE)
        gSpecialVar_ProfessionalsDeliveryTimer += 1;
    if (gSpecialVar_ProfessionalsDeliveryTimer > 5)
        {
            //QueueNotification(NOTIFICATION_CATEGORY_MISSION, "You're late delivering packages. Your pay will be deducted.")
            FlagClear(FLAG_RYU_START_DELIVERY_TIMER);
            FlagSet(FLAG_RYU_PROF_DELIVERY_LATE);
            gSpecialVar_ProfessionalsDeliveryTimer = 0;
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
    VarSet(VAR_HOURS, gLocalTime.hours);
}

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
