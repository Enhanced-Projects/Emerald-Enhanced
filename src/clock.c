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
#include "RyuDynDeliveries.h"
#include "ach_atlas.h"
#include "task.h"
#include "constants/weather.h"
#include "random.h"

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


void TryMoveRivalIdleLocation(void)
{
    if ((FlagGet(FLAG_RYU_DS_BRENDAN_PARTNERS)) || (FlagGet(FLAG_RYU_DS_DAWN_PARTNERS)))//only need to check if player has finished companion line for rival to check this event 
        {
            if ((gLocalTime.hours >= 14) && (gLocalTime.hours <= 20)) //betwen 2pm and 8pm rival hangs out at lab. Different dialogue.
            {
                if (gSaveBlock2Ptr->playerGender == MALE)
                {                                     
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == FOLLOWER_DAWN))// 3a. don't bother if they are currently following player.
                       {
                           FlagSet(FLAG_HIDE_DAWNS_HOUSE_DAWN);
                           FlagClear(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL);
                       }
                }
                else
                {                                     
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == FOLLOWER_BRENDAN))//see 3a
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
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == FOLLOWER_BRENDAN))//see 3a
                       {
                           FlagClear(FLAG_HIDE_BRENDANS_HOUSE_BRENDAN);
                           FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL);
                       }
               }
               else
               {
                   if (!(VarGet(VAR_RYU_FOLLOWER_ID) == FOLLOWER_DAWN)) //see 3a
                       {
                           FlagClear(FLAG_HIDE_DAWNS_HOUSE_DAWN);
                           FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL);
                       }
               }

            }
        }
}

void TryMoveBirchLocationPostMay(void)
{
        if (VarGet(VAR_RYU_QUEST_MAY) > 10)
    {//birch is at the lab between 8am and 5pm if player unlocked May.
        if ((gLocalTime.hours >= 17) || (gLocalTime.hours <= 8))
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
        else
        {//birch is at home between 6pm and 7am if player unlocked may.
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
    }
    else //default to having birch in the lab if above requirements aren't met.
    {
        FlagSet(FLAG_HIDE_LRT_DH_BIRCH);
        FlagSet(FLAG_HIDE_LRT_BH_BIRCH);
        FlagClear(FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH);
    }
}

void UpdatePerHour(struct Time *localTime)
{

    if ((!(gLocalTime.hours == 0)) && (gLocalTime.hours > VarGet(VAR_HOURS))) //Had to make this change because this is called whenever time is checked, causing this to repeat many times a second.
    {
        DoHourlyRealEstateNotification();
    }
    VarSet(VAR_HOURS, gLocalTime.hours);
}

const u8 gRyuText_DailyQuestsReset[] = _("Daily quests have been reset.");

void RyuChooseSeasonalWeather(void)
{
    int temp = 0;
    u8 currentSeason = VarGet(VAR_RYU_WEEK_COUNTER);
    u16 rngval = (Random() % 100);

    switch (currentSeason)
    {
        case 0: //spring
            {
                if (rngval == 0) //0, 1%
                    temp = WEATHER_SHADE;
                else if (rngval > 0 && rngval < 11) //1 to 10, 10%
                    temp = WEATHER_RAIN_THUNDERSTORM;
                else if (rngval > 11 && rngval < 41)//12 to 40, 38%
                    temp = WEATHER_SUNNY_CLOUDS;
                else // 41 to 99, 51%
                    temp = WEATHER_RAIN;
                break;

            }
        case 1: //summer
            {
                if (rngval == 0) //0, 1%
                    temp == WEATHER_SHADE;
                else if (rngval > 0 && rngval < 6) //1 to 5, 5%
                    temp = WEATHER_RAIN_THUNDERSTORM;
                else if (rngval > 4 && rngval < 17 ) //5 to 16, 12% 
                    temp = WEATHER_RAIN;
                else //17 to 99, 82%
                    temp = WEATHER_SUNNY_CLOUDS;
                break;
            }
        case 2: //fall
            {
                if (rngval < 2) //0 to 1, 2%
                    temp = WEATHER_SHADE;
                else if (rngval > 2 && rngval < 44) //3 to 43, 40%
                    temp = WEATHER_WINDY;
                else if (rngval > 43 && rngval < 84) // 44 to 83, 40%
                    temp = WEATHER_SUNNY_CLOUDS;
                else //84 to 99, 18%
                    temp = WEATHER_RAIN;
                break;
            }
        case 3: //winter
            {
                if (rngval < 4) //0 to 3, 4%
                    temp = WEATHER_SHADE;
                else if (rngval > 3 && rngval < 14) //4 to 13, 10%
                    temp = WEATHER_WINDY;
                else if (rngval > 13 && rngval < 29)// 14 to 29, 15%
                    temp = WEATHER_SUNNY_CLOUDS;
                else if (rngval > 28 && rngval < 55)// 28 to 54, 25%
                    temp = WEATHER_RAIN;
                else //55 to 99, 46%
                    temp = WEATHER_SNOW;
                break;
            }
    }
    VarSet(VAR_RYU_SEASONAL_WEATHER, temp);
}

static void UpdatePerDay(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 daysSince;

    if (*days != localTime->days && *days <= localTime->days)
    {
        daysSince = localTime->days - *days;
        VarSet(VAR_RYU_DAY_COUNTER, (VarGet(VAR_RYU_DAY_COUNTER) + 1));
        if (VarGet(VAR_RYU_DAY_COUNTER) > 6)
        {
            VarSet(VAR_RYU_WEEK_COUNTER, (VarGet(VAR_RYU_WEEK_COUNTER) + 1));
            VarSet(VAR_RYU_DAY_COUNTER, 0);
        }
        if (VarGet(VAR_RYU_WEEK_COUNTER) > SEASON_WINTER)
            VarSet(VAR_RYU_WEEK_COUNTER, SEASON_SPRING);
        RyuChooseSeasonalWeather();
        ClearDailyQuestData();
        ClearDailyFlags();
        DoDailyRealEstateTasks();
        RotateDailyUBGroup();
        UpdateDewfordTrendPerDay(daysSince);
        UpdateTVShowsPerDay(daysSince);
        UpdatePartyPokerusTime(daysSince);
        UpdateMirageRnd(daysSince);
        UpdateBirchState(daysSince);
        UpdateFrontierManiac(daysSince);
        UpdateFrontierGambler(daysSince);
        SetShoalItemFlag(daysSince);
        SetRandomLotteryNumber(daysSince);
        *days = localTime->days;
        FlagClear(FLAG_RYU_DELIVERY_IN_PROGRESS);
        RyuClearDeliveryQueue();
        if ((VarGet(VAR_RYU_DELIVERY_SYSTEM_DATA) > 0) && (VarGet(VAR_RYU_DELIVERY_SYSTEM_DATA) <= 10))//only reset delivery data if in quota range.
            VarSet(VAR_RYU_DELIVERY_SYSTEM_DATA, 0);
        QueueNotification(gRyuText_DailyQuestsReset, NOTIFY_GENERAL, 60);
        VarSet(VAR_RYU_DAILY_VENDING_MACHINE_PURCHASES, 0); //reset daily purchase quota
        if ((CheckAchievement(ACH_THE_PHOENIX) == FALSE) && (CheckAchievement(ACH_MARKED_FOR_DEATH) == TRUE))
            FlagClear(FLAG_RYU_NOTIFIED_UNDERWORLD);
        FlagSet(FLAG_RYU_MINNIE_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_RIVAL_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_MOM_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_MAY_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_LEAF_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_SHELLY_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_COURTNEY_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_LANETTE_STAMINA_CHARGE);
        FlagSet(FLAG_RYU_LUCY_STAMINA_CHARGE);
        if (FlagGet(FLAG_RYU_HAS_SUPER_TRAINING) == TRUE)
            VarSet(VAR_RYU_PLAYER_STAMINA, 100);

    }
}
extern void Task_MapNamePopUpWindow(u8 taskId);
extern void RyuDoNotifyTasks(void);

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
            TryMoveRivalIdleLocation();
            TryMoveBirchLocationPostMay();
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
                    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock2Ptr->DeliveryTimer.Timer, STR_CONV_MODE_LEFT_ALIGN, 2);
                    QueueNotification(((const u8 []) _("Delivery: {STR_VAR_1} min(s) left.")), NOTIFY_GENERAL, 120);
                }
            }

            if ((VarGet(VAR_RYU_PLAYER_STAMINA) < 100) && (FlagGet(FLAG_RYU_HAS_SUPER_TRAINING) == TRUE))
                VarSet(VAR_RYU_PLAYER_STAMINA, (VarGet(VAR_RYU_PLAYER_STAMINA) + 1));
            if (VarGet(VAR_RYU_PLAYER_STAMINA) > 100)
                VarSet(VAR_RYU_PLAYER_STAMINA, 100);
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
