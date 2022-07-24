#include "global.h"
#include "constants/region_map_sections.h"
#include "constants/maps.h"
#include "field_message_box.h"
#include "random.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "fieldmap.h"
#include "script.h"
#include "task.h"
#include "ach_atlas.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "overworld_notif.h"
#include "factions.h"
#include "RyuRealEstate.h"
#include "RyuDynDeliveries.h"



extern const u8 SB_SetupRandomSteppedOnEncounter[];
extern const u8 SB_SetupRandomMimikyuEncounter[];
extern const u8 SB_CheckMeloettaEncounter[];
extern const u8 Ryu_BeingWatched[];
extern const u8 Ryu_MeloettaWatchingMsg[];
extern const u8 RyuScript_CheckGivenAchievement[];
extern const u8 RyuScript_GoToLimbo[];
extern const u8 RyuScript_EncounterBuzzwole[];
extern const u8 RyuScript_EncounterPheromosa[];
extern const u8 RyuScript_EncounterKartana[];
extern const u8 RyuScript_EncounterXurkitree[];
extern const u8 RyuScript_EncounterNihilego[];
extern const u8 RyuScript_EncounterGuzzlord[];
extern const u8 RyuScript_EncounterStakataka[];
extern const u8 RyuScript_EncounterCelesteela[];
extern const u8 RyuScript_EncounterKeldeo[];
extern const u8 RyuScript_NotifyFailedChallenge[];
extern const u8 RyuScript_NotifySucceededChallenge[];
extern const u8 RyuScript_Lv100FailMsg[];
extern const u8 RyuScript_Lv100SwitchMsg[];
extern const u8 RyuGlobal_CancelDailyQuest[];

extern void GetPlayerPosition(struct MapPosition *);
extern u16 GetPlayerCurMetatileBehavior(int);


bool8 RyuCheckPlayerHasPika(void)
{
    u8 i;
    bool8 hasPika = FALSE;
    for (i = 0; i < 6; i++)
    {
        if ((GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_PIKACHU))
            return TRUE;
    }

    return FALSE;
}

extern int RyuGetCurrentMapsec(void);
#define tQuestFrames data[0]

void RyuTravelQuestTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((tQuestFrames < 1200) && (RyuGetCurrentMapsec() == (VarGet(VAR_RYU_DAILY_QUEST_TARGET))) && (!(VarGet(VAR_RYU_DAILY_QUEST_DATA) == 4000)))
    {
        tQuestFrames++;
    }
    else
    {
        u8 buf[40];
        u8 factionId = (VarGet(VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION));
        DestroyTask(taskId);
        StringCopy(buf, gFactionNames[VarGet(VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION)]);
        StringAppend(buf, (const u8[]) _(" travel quest completed."));
        QueueNotification(buf, NOTIFY_MISSION, 120); 
        VarSet(VAR_RYU_DAILY_QUEST_DATA, 4000);
    }
}

void RyuCheckTravelTypeDaily(void)
{
    if ((FlagGet(FLAG_DAILY_QUEST_ACTIVE) == TRUE) &&
    (VarGet(VAR_RYU_DAILY_QUEST_TYPE) == TRAVEL_TYPE) &&
    (!(VarGet(VAR_RYU_DAILY_QUEST_DATA) == 4000)) &&
    (FlagGet(FLAG_RYU_STARTED_TRAVEL_TIMER) == FALSE))
    {
        FlagSet(FLAG_RYU_STARTED_TRAVEL_TIMER);
        CreateTask(RyuTravelQuestTask, 0xFF);
    }
}

bool8 RyuCheckPlayerisInMtPyreAndHasPikachu(void)
{
    u16 locGroup = gSaveBlock1Ptr->location.mapGroup;
    u16 locMap = gSaveBlock1Ptr->location.mapNum;
    if (locGroup == 24)
    {
        if ((locMap > 15) && (locMap < 21))
        {
            if (RyuCheckPlayerHasPika() == TRUE)
                return TRUE;
        }
    }
    FlagSet(FLAG_TEMP_D);
    return FALSE;
}

void RyuCheckForLNSU (void)
{
    int count = 0, slot;
    for (slot = FLAG_LANDMARK_FLOWER_SHOP; slot <= FLAG_LANDMARK_SNOWY_SHORE; slot++)
        count += FlagGet(slot);
    if (count >= 27)
        GiveAchievement(ACH_LEAVE_NO_STONE_UNTURNED);
}

extern int CountBadges(void);
extern void RyuCheckForFactionAchievements(void);

#define tRyuTimerFrames data[0]

void RyuMessageTimerTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tRyuTimerFrames < 300)
        tRyuTimerFrames++;
    else
    {
        HideFieldMessageBox();
        DestroyTask(taskId);
    }
}

void RyuDelayTimerTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tRyuTimerFrames < 600)
        tRyuTimerFrames++;
    else
    {
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
    }
}

void RyuCheckMagmaQuestNotifications(void)
{
    if ((FlagGet(FLAG_RYU_PLAYER_HELPING_MAGMA)) && (!(FlagGet(FLAG_TEMP_F))))//prevents the notification from showing up as soon as the player is assigned the task.
    {
        switch (VarGet(VAR_RYU_QUEST_MAGMA))
        {
            case 130:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 3) || FlagGet(FLAG_RYU_MAGMA_4_NOTIFY) == TRUE)
                {
                    break;
                }
                ShowPokenavFieldMessage((const u8[]) _("Report to the Mountain Ridge\nnorth of the desert for further\linstructions."));
                FlagClear(FLAG_RYU_HIDE_103_MAGMA_MEETING);
                FlagClear(FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA1);
                FlagClear(FLAG_RYU_ROUTE_111_MAGMA_MEETING_BLAISE);
                FlagSet(FLAG_RYU_MAGMA_4_NOTIFY);
                break;
            }
            case 210:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 6) || FlagGet(FLAG_RYU_MAGMA_6_NOTIFY) == TRUE)
                {
                    break;
                }
                FlagSet(FLAG_RYU_MAGMA_6_NOTIFY);
                ShowPokenavFieldMessage((const u8[]) _("Scheduled Heist at Oldale Town's\nPokéMart. Group meet north of town\pfor further briefing."));\
                FlagSet(FLAG_RYU_HIDE_111_MAGMA_MEETING);
                FlagSet(FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA1);
                FlagSet(FLAG_RYU_ROUTE_111_MAGMA_MEETING_BLAISE);
                FlagClear(FLAG_RYU_HIDE_103_MAGMA_MEETING);
                break;
            }
            case 350:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 7) || (FlagGet(FLAG_RYU_MAGMA_8_NOTIFY) == TRUE))
                {
                    break;
                }
                FlagSet(FLAG_RYU_MAGMA_8_NOTIFY);
                VarSet(VAR_RYU_QUEST_MAGMA, 400);
                ShowFieldMessage((const u8[]) _("I suppose it's time to head back to\nbase and see what's happened so far."));
                CreateTask(RyuMessageTimerTask, 0xFF);
                break;
            }
        }
    }

}

void RyuCheckAquaQuestNotifications(void)
{
    if ((FlagGet(FLAG_RYU_PLAYER_HELPING_AQUA)) && (!(FlagGet(FLAG_TEMP_F))))
    {
        switch (VarGet(VAR_RYU_QUEST_AQUA))
        {
            case 10:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 3) || FlagGet(FLAG_RYU_AQUA_1_NOTIFY) == TRUE)
                {
                    break;
                }
                ShowPokenavFieldMessage((const u8[]) _("This is Admin Shelly speaking.\nYou're to rendezvous with the rest of\lthe crew at Slateport Museum.\pYour objective is to detain and\ninterrogate Captain Stern."));
                FlagSet(FLAG_RYU_AQUA_1_NOTIFY);
                FlagSet(FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION);
                VarSet(VAR_RYU_QUEST_AQUA, 25);
                break;
            }
            case 55:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 5) || FlagGet(FLAG_RYU_AQUA_2_NOTIFY) == TRUE)
                {
                    break;
                }
                ShowPokenavFieldMessage((const u8[]) _("Admin Shelly speaking.\pI'm sending you to Meteor Falls to\nprovide some assistance to those\lalready in the area.\pDon't be a hero!"));
                VarSet(VAR_RYU_QUEST_AQUA, 60);
                FlagSet(FLAG_RYU_AQUA_2_NOTIFY);
                break;
            }
            case 80:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 6) || FlagGet(FLAG_RYU_AQUA_3_NOTIFY) == TRUE)
                {
                    break;
                }
                FlagSet(FLAG_RYU_AQUA_3_NOTIFY);
                ShowPokenavFieldMessage((const u8[]) _("This is an urgent message from Admin\nMatt!\pCalling all members to mobilize at\nthe peak of Mt. Pyre!\pI repeat: the peak of Mt. Pyre!This is an urgent message from Admin\nMatt!\pCalling all members to mobilize at\nthe peak of Mt. Pyre!\pI repeat: the peak of Mt. Pyre!"));
                FlagClear(FLAG_RYU_HIDE_AQUA_MTPYRE_EXT);
                VarSet(VAR_RYU_QUEST_AQUA, 82);
                break;
            }
            case 91:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 6) || FlagGet(FLAG_RYU_AQUA_3_NOTIFY) == TRUE)
                {
                    break;
                }
                FlagSet(FLAG_RYU_AQUA_3_NOTIFY);
                ShowPokenavFieldMessage((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, this is Shelly.\pWe've discovered what Magma is\nscheming, and it's far from good.\pWe were able to weaken their forces\nat Mt. Chimney, so now they're\ldesperate.\pIt's time to hit them while they're\nstill down!\pMeet me at their hideout located in\nJagged Pass."));
                FlagSet(FLAG_RYU_PLAYER_SENT_TO_JP_BY_SHELLY);
                VarSet(VAR_RYU_QUEST_AQUA, 93);
                break;
            }
            case 123:
            {
                FlagSet(FLAG_TEMP_F);
                if ((CountBadges() < 3) || FlagGet(FLAG_RYU_AQUA_4_NOTIFY) == TRUE)
                {
                    break;
                }
                FlagSet(FLAG_RYU_AQUA_4_NOTIFY);
                ShowPokenavFieldMessage((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, it's time...meet us in the\nmain Team Aqua Headquarters.\pWe'll be waiting by the dock."));
                FlagSet(FLAG_RYU_DEVON_HIDE_MATT_SUB);
                FlagSet(FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE);
                FlagSet(FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE);
                FlagClear(FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW);
                FlagClear(FLAG_HIDE_AQUA_HIDEOUT_GRUNTS);
                VarSet(VAR_RYU_QUEST_AQUA, 125);
                FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_AQUA_HIDEOUT_1);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_2);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_AQUA_HIDEOUT_3);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_21);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_25);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_4);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_22);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_GRUNT_26);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_SHELLY_2);
	            FlagSet(TRAINER_FLAGS_START + TRAINER_MATT);
                break;
            }
            break;
        }
    }
}
extern void RyuClearAlchemyEffect(void);

void RyuResetTimeBasedEvents(void)
{
    FlagClear(FLAG_RYU_VERBOSE_MODE);
    RyuClearAlchemyEffect();
    RyuResetRealEstateData();
    VarSet(VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, 7);
    VarSet(VAR_RYU_DAILY_QUEST_DATA, 0xFFFF);
    VarSet(VAR_RYU_DAILY_QUEST_TARGET, 0xFFFF);
    VarSet(VAR_RYU_DAILY_QUEST_TYPE, 0xFFFF);
    FlagSet(FLAG_FINISHED_PROFESSIONAL_DAILY);
    FlagSet(FLAG_FINISHED_STUDENT_DAILY);
    FlagSet(FLAG_FINISHED_POKEFAN_DAILY);
    FlagSet(FLAG_FINISHED_NOBLE_DAILY);
    FlagSet(FLAG_FINISHED_OUTCAST_DAILY);
    FlagSet(FLAG_FINISHED_NATURALIST_DAILY);
    FlagClear(FLAG_DAILY_QUEST_ACTIVE);
    RyuClearDeliveryQueue();
    SetWarpDestination(MAP_GROUP(PETALBURG_CITY), MAP_NUM(PETALBURG_CITY), 255, 10, 15);
    CreateTask(RyuDelayTimerTask, 255);
}

extern void RyuSavePlayTimeChallenge(void);
void RyuDoNotifyTasks(void)
{
    if (FlagGet(FLAG_RYU_ENTERING_OWNED_HOME) == FALSE)
        FlagSet(FLAG_RYU_HIDE_HOME_ATTENDANT);

    if ((gPlayerPartyCount == 0) && (VarGet(VAR_LITTLEROOT_INTRO_STATE) >= 10)) //check blackout for challenge/hardcore
    {
        if (FlagGet(FLAG_RYU_LIMBO) == FALSE)
        {
            if ((FlagGet(FLAG_RYU_CHALLENGEMODE) == TRUE) || (FlagGet(FLAG_RYU_HARDCORE_MODE) == TRUE))
                {
                    ShowPokenavFieldMessage((const u8[]) _("Hello. This is the Duskull afterlife\nservice calling.\pThis call is to notify you that\nyou will be escorted to the\lafterlife shortly."));
                    SetWarpDestination(MAP_GROUP(LIMBO), MAP_NUM(LIMBO), 255, 3, 3);
                    CreateTask(RyuDelayTimerTask, 255);
                }
        }
    }

    RyuCheckForFactionAchievements();

    RyuCheckMagmaQuestNotifications();

    RyuCheckAquaQuestNotifications();

    if ((CheckAchievement(ACH_LEAVE_NO_STONE_UNTURNED) == FALSE) && (VarGet(VAR_TEMP_E) == 0))
    {
        VarSet(VAR_TEMP_E, 100);
        RyuCheckForLNSU();//no longer a script, should be faster
    }

    if ((FlagGet(FLAG_RYU_FAILED_RYU_CHALLENGE) == TRUE) && (FlagGet(FLAG_RYU_NOTIFIED_CHALLENGE_FAILURE) == FALSE))
        {
            FlagSet(FLAG_RYU_NOTIFIED_CHALLENGE_FAILURE);
            FlagClear(FLAG_RYU_DOING_RYU_CHALLENGE);
            ShowPokenavFieldMessage((const u8[]) _("You have failed Ryu's Challenge.\nYou can try again in another\lNew Game Plus.\pWe look forward to you trying\nagain!"));
        }

    if ((VarGet(VAR_RYU_SPECIAL_CHALLENGE_STATE) == 69) && (FlagGet(FLAG_RYU_NOTIFIED_CHALLENGE_SUCCESS) == FALSE))
    {
        ShowPokenavFieldMessage((const u8[]) _("You have completed\nRyu's Challenge.\pPing Ryu in discord to get your\nsave checked and score posted!"));
        FlagClear(FLAG_RYU_DOING_RYU_CHALLENGE);
        FlagSet(FLAG_RYU_NOTIFIED_CHALLENGE_SUCCESS);
        RyuSavePlayTimeChallenge();
    }

    if (FlagGet(FLAG_RYU_FAILED_100_CAP_SWITCH) == TRUE)
    {
        ShowFieldMessage((const u8[]) _("Failed to switch to 100 cap.\nParty must all be below lv100."));
        CreateTask(RyuMessageTimerTask, 0xFF);
        FlagClear(FLAG_RYU_FAILED_100_CAP_SWITCH);
    }

    if (FlagGet(FLAG_RYU_NOTIFY_LV100_SWITCH) == TRUE)//Player switched to 100cap, warn about side effects.
    {
        ShowFieldMessage((const u8[]) _("100 cap has been activated."));
        CreateTask(RyuMessageTimerTask, 0xFF);
        FlagClear(FLAG_RYU_NOTIFY_LV100_SWITCH);
    }

    if (!(FlagGet(FLAG_SYS_DEXNAV_GET)) && (!(FlagGet(FLAG_TEMP_F)))) //notify and give Dexnav
        if (CountBadges() >= 6)
            {
                FlagSet(FLAG_SYS_DEXNAV_GET);//THE BELOW MESSAGE BOX WILL GET CORRUPTED IF THE USER GETS AN ACHIEVEMENT AT THE SAME TIME! @PIDGEY PLS FIX
                ShowPokenavFieldMessage((const u8[]) _("Hello Trainer!\pThe DexNav has been added to your\nStart Menu.\pPlease enjoy it!"));
            }

    if (FlagGet(FLAG_RYU_OPTIONAL_QT_ACTION) == TRUE)
    {
        FlagClear(FLAG_RYU_OPTIONAL_QT_ACTION);
        ScriptContext1_SetupScript(RyuGlobal_CancelDailyQuest);
    }
}

void RyuDoSpecialEncounterChecks(void)
{
    struct MapPosition position;
    u8 playerDirection;
    u16 metatileBehavior;
    u16 rand = (Random() % 99);
    u16 locSum = (gSaveBlock1Ptr->location.mapGroup << 8) + (gSaveBlock1Ptr->location.mapNum);
    u16 UBRotation = (VarGet(VAR_RYU_UB_EVENT_TIMER));//which UB group the player currently can encounter

    playerDirection = GetPlayerFacingDirection();
    GetPlayerPosition(&position);
    metatileBehavior = MapGridGetMetatileBehaviorAt(position.x, position.y);

    if (MetatileBehavior_IsSandOrDeepSand(GetPlayerCurMetatileBehavior(gPlayerAvatar.runningState)))
        {
            if (!(locSum == MAP_ROUTE111))
            {
                rand = (Random() % 256);
                if ((rand == 69) || (rand == 169))
                {
                    ScriptContext1_SetupScript(SB_SetupRandomSteppedOnEncounter);
                }
            }
        }
        if (FlagGet(FLAG_TEMP_D) == 0)
        {
            if (RyuCheckPlayerisInMtPyreAndHasPikachu() == TRUE)
            {
                rand = (Random() % 256);
                if (rand == 128)
                {
                    ScriptContext1_SetupScript(SB_SetupRandomMimikyuEncounter);
                }
            }
        }
        
        if (FlagGet(FLAG_TEMP_C) == 0)
            {
                if (MetatileBehavior_IsTallGrass(GetPlayerCurMetatileBehavior(gPlayerAvatar.runningState)))
                {
                    if (GetGameStat(GAME_STAT_USED_SOUND_MOVE) >= 255 && (FlagGet(FLAG_RYU_CAPTURED_MELOETTA) == 0))
                    {
                        ScriptContext1_SetupScript(SB_CheckMeloettaEncounter);
                    }
                    else if (GetGameStat(GAME_STAT_USED_SOUND_MOVE) >= 200)
                    {
                        ScriptContext1_SetupScript(Ryu_MeloettaWatchingMsg);
                    }
                    else if (GetGameStat(GAME_STAT_USED_SOUND_MOVE) >= 100)
                    {
                        ScriptContext1_SetupScript(Ryu_BeingWatched);
                    }
                    else if (GetGameStat(GAME_STAT_USED_SOUND_MOVE) < 50)
                    {
                        FlagSet(FLAG_TEMP_C);
                    }
                }
            }

    //Ultra beast encounter checks
    //I don't think this can be made much cleaner, but it shouldn't really cause lag, even if player is at the right locations
    //FLAG_TEMP_D is set after an encounter with a UB when it wasn't caught, so player has to leave map and come back for it to respawn
    //I wanted to also make it play the cries of the relevant UB once in a while in the correct area, but i'm not sure how without vastly
    //complicating this furtner.

    if ((FlagGet(FLAG_RYU_ULTRA_BEASTS_ESCAPED) == TRUE) && (FlagGet(FLAG_RYU_CAUGHT_ALL_UBS) == FALSE) && (rand < 5))//5% chance to find the UB here.
    {

        if ((FlagGet(FLAG_RYU_BUZZWOLE_CAUGHT) == FALSE) && (FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER) == FALSE) && (UBRotation == 0))
        {
            if (locSum == MAP_GRANITE_CAVE_1F ||
                locSum == MAP_GRANITE_CAVE_B1F ||
                locSum == MAP_GRANITE_CAVE_B2F)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterBuzzwole);
            }
        }

        if (!(FlagGet(FLAG_RYU_PHEROMOSA_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 0))
        {
            if (locSum == MAP_ROUTE119)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterPheromosa);
            }
        }

        if (!(FlagGet(FLAG_RYU_KARTANA_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 1))
        {
            if (gSaveBlock1Ptr->location.mapNum == MAP_ROUTE120)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterKartana);
            }
        }

        if (!(FlagGet(FLAG_RYU_XURKITREE_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 1))
        {
            if (locSum == MAP_NEW_MAUVILLE_INSIDE)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterXurkitree);
            }
        }

        if (!(FlagGet(FLAG_RYU_NIHILEGO_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 2))
        {
            if (locSum == MAP_METEOR_FALLS_2F ||
                locSum == MAP_METEOR_FALLS_1F_1R ||
                locSum == MAP_METEOR_FALLS_1F_2R ||
                locSum == MAP_METEOR_FALLS_1F_3R ||
                locSum == MAP_METEOR_FALLS_B1F_1R ||
                locSum == MAP_METEOR_FALLS_B1F_2R ||
                locSum == MAP_METEOR_FALLS_2F ||
                locSum == MAP_METEOR_FALLS_3F)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterNihilego);
            }
        }

        if (!(FlagGet(FLAG_RYU_GUZZLORD_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 2))
        {
            if (locSum == MAP_FROSTY_GROTTO)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterGuzzlord);
            }
        }

        if (!(FlagGet(FLAG_RYU_STAKATAKA_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 3))
        {
            if (locSum == MAP_MT_PYRE_2F ||
                locSum == MAP_MT_PYRE_3F ||
                locSum == MAP_MT_PYRE_4F ||
                locSum == MAP_MT_PYRE_5F ||
                locSum == MAP_MT_PYRE_6F)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterStakataka);
            }
        }

        if (!(FlagGet(FLAG_RYU_CELESTEELA_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 3))
        {
            if (locSum == MAP_ROUTE66)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                ScriptContext1_SetupScript(RyuScript_EncounterCelesteela);
            }
        }
    

    }

    if ((VarGet(VAR_TEMP_D) == 400) &&
         FlagGet(FLAG_SYS_GAME_CLEAR) &&
         FlagGet(FLAG_RYU_CAUGHT_KELDEO) == FALSE &&
         gSaveBlock1Ptr->location.mapGroup == (MAP_GROUP(PETALBURG_WOODS)) &&
         gSaveBlock1Ptr->location.mapNum == MAP_NUM(PETALBURG_WOODS) &&
         (Random() % 100 < 5) &&
         (FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER) == FALSE))
    {
        FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
        ScriptContext1_SetupScript(RyuScript_EncounterKeldeo);
    }
}
