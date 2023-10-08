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
#include "wild_encounter.h"
#include "scripted_encounters.h"
#include "sound.h"
#include "cutscene.h"
#include "DynamicObjects.h"
#include "RyuPokenavScheduler.h"

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
    int count = 0;
    if (FlagGet(FLAG_LANDMARK_FLOWER_SHOP) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_MR_BRINEY_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_ABANDONED_SHIP) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_SEASHORE_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_NEW_MAUVILLE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_OLD_LADY_REST_SHOP) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_TRICK_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_WINSTRATE_FAMILY) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_GLASS_WORKSHOP) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_LANETTES_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_POKEMON_DAYCARE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_BATTLE_FRONTIER) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_SOUTHERN_ISLAND) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_FIERY_PATH) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_POKEMON_LEAGUE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_ISLAND_CAVE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_SCORCHED_SLAB) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_TUNNELERS_REST_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_HUNTERS_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_BERRY_MASTERS_HOUSE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_ALTERING_CAVE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_DESERT_UNDERPASS) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_ARTISAN_CAVE) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_TRAINER_HILL) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_MIRAGE_TOWER) == TRUE)
        count++;
    if (FlagGet(FLAG_LANDMARK_SNOWY_SHORE) == TRUE)
        count++;

    if (count >= 25)
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

void RyuDelayTeleportTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tRyuTimerFrames < 240)
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
                SchedulePokenavCallInternal(NAVCALL_MAGMASTAGE130, 30);
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
                SchedulePokenavCallInternal(NAVCALL_MAGMASTAGE210, 30);
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
                SchedulePokenavCallInternal(NAVCALL_AQUASTAGE10, 30);
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
                SchedulePokenavCallInternal(NAVCALL_AQUASTAGE55, 30);
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
                SchedulePokenavCallInternal(NAVCALL_AQUASTAGE80, 30);
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
                SchedulePokenavCallInternal(NAVCALL_AQUASTAGE91, 30);
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
                SchedulePokenavCallInternal(NAVCALL_AQUASTAGE123, 30);
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

extern void RyuSavePlayTimeChallenge(void);
extern bool32 IsPlayerInUnderworld(void);
extern bool32 checkEscortMission(void);



void RyuDoNotifyTasks(void)
{

    if (FlagGet(FLAG_RYU_ENTERING_OWNED_HOME) == FALSE)
        FlagSet(FLAG_RYU_HIDE_HOME_ATTENDANT);

    if ((gPlayerPartyCount == 0) && (VarGet(VAR_LITTLEROOT_INTRO_STATE) >= 10)) //check blackout for challenge/hardcore
    {
        if (FlagGet(FLAG_RYU_LIMBO) == FALSE)
        {
            if (FlagGet(FLAG_RYU_HARDCORE_MODE) == TRUE)
                {
                    SchedulePokenavCallInternal(NAVCALL_DUSKULLAFTERLIFE, 0);
                    SetWarpDestination(MAP_GROUP(LIMBO), MAP_NUM(LIMBO), 255, 3, 3);
                    CreateTask(RyuDelayTimerTask, 255);
                }
        }
    }

    if ((CheckAchievement(ACH_THE_PHOENIX) == TRUE) && (FlagGet(FLAG_RYU_UNDERWORLD) == TRUE))
        FlagClear(FLAG_RYU_UNDERWORLD);

    if ((FlagGet(FLAG_RYU_UNDERWORLD) == FALSE) &&
        (CheckAchievement(ACH_MARKED_FOR_DEATH) == TRUE) &&
        (IsPlayerInUnderworld() == FALSE))
        {
            FlagSet(FLAG_RYU_UNDERWORLD);
        }

    if ((FlagGet(FLAG_RYU_UNDERWORLD) == TRUE) /*(&& (FlagGet(FLAG_TEMP_14) == FALSE)*/ && (FlagGet(FLAG_RYU_REAPER) == FALSE) && (IsPlayerInUnderworld() == FALSE))
        FlagClear(FLAG_RYU_NOTIFIED_UNDERWORLD);

    if ((FlagGet(FLAG_RYU_UNDERWORLD) == TRUE) && (CheckAchievement(ACH_THE_PHOENIX) == FALSE) && (FlagGet(FLAG_RYU_NOTIFIED_UNDERWORLD) == FALSE))
    {
        PlaySE(79);
        ShowFieldMessage((const u8[]) _(" {COLOR LIGHT_GREEN}{SHADOW GREEN}(A voice echoes in your head)\n{COLOR RED}{SHADOW BLUE}WHY DO YOU DENY FATE?!\pWE WILL NOT ABIDE DISOBEDIENCE!!"));
        FlagSet(FLAG_RYU_NOTIFIED_UNDERWORLD);
        SetWarpDestination(MAP_GROUP(UNDERWORLD), MAP_NUM(UNDERWORLD), 255, 5, 5);
        FlagClear(FLAG_RYU_UNDERWORLD);
        FlagSet(FLAG_TEMP_14);
        CreateTask(RyuDelayTeleportTask, 255);
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
            SchedulePokenavCallInternal(NAVCALL_FAILEDRYUCHALLENGE, 0);
        }

    if ((VarGet(VAR_RYU_SPECIAL_CHALLENGE_STATE) == 69) && (FlagGet(FLAG_RYU_NOTIFIED_CHALLENGE_SUCCESS) == FALSE))
    {
        SchedulePokenavCallInternal(NAVCALL_COMPLETEDRYUCHALLENGE, 0);
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
                FlagSet(FLAG_SYS_DEXNAV_GET);
                SchedulePokenavCallInternal(NAVCALL_DEXNAV, 10);
            }

    if (FlagGet(FLAG_RYU_OPTIONAL_QT_ACTION) == TRUE)
    {
        FlagClear(FLAG_RYU_OPTIONAL_QT_ACTION);
        ScriptContext1_SetupScript(RyuGlobal_CancelDailyQuest);
    }

    if ((checkEscortMission() == TRUE) && (VarGet(VAR_RYU_POKEFANS_OBJID) == (VarGet(VAR_RYU_FOLLOWER_ID))) && (FlagGet(FLAG_RYU_POKEFANS_ESCORT_DONE) == FALSE))
    {
        FlagSet(FLAG_RYU_POKEFANS_ESCORT_DONE);
        ShowFieldMessage((const u8[])_("Ah! Here we are.\nThank you so much for escorting me!"));
        CreateTask(RyuMessageTimerTask, 0xFF);
        DestroyFollowerObjectEvent();//delete the follower
        VarSet(VAR_RYU_POKEFANS_OBJID, 0);
        FlagClear(FLAG_RYU_HAS_FOLLOWER);
        VarSet(VAR_RYU_FOLLOWER_ID, 0);
    }

    DoScheduledNavCallCheck();

}

bool8 RyuCheckHasFighterDogs(void)
{
    u32 k;
    u32 count = 0;
    u32 virizionF = 1 << 0, cobalionF = 1 << 1, terrakionF = 1 << 2, ownAllF = 7;
    

    for (k = 0; k < CalculatePlayerPartyCount(); k++)
    {
        if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES2) == SPECIES_TERRAKION)
            count |= terrakionF;
        if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES2) == SPECIES_VIRIZION)
            count |= virizionF;
        if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES2) == SPECIES_COBALION)
            count |= cobalionF;
    }
    if (count == ownAllF)
        return TRUE;
    
    return FALSE;
}

static const u16 SteppedOnSpecies[] = {
    SPECIES_PYUKUMUKU, 
    SPECIES_SANDYGAST, 
    SPECIES_SHELLDER,
    SPECIES_MAREANIE,
    SPECIES_SKRELP
};

const u8 gText_Empty69[] = _("A cute Pokémon attacks!$");

extern void Task_MapNamePopUpWindow(u8 taskId);
extern void VBCB_FullscreenCutscene(void);

void RyuDoSpecialEncounterChecks(void)
{
    struct MapPosition position;
    u8 playerDirection;
    u16 metatileBehavior;
    u16 rand = (Random() % 99);
    u16 rand2 = (Random() % 5);
    u16 locSum = (gSaveBlock1Ptr->location.mapGroup << 8) + (gSaveBlock1Ptr->location.mapNum);
    u16 UBRotation = (VarGet(VAR_RYU_UB_EVENT_TIMER));//which UB group the player currently can encounter

    playerDirection = GetPlayerFacingDirection();
    GetPlayerPosition(&position);
    metatileBehavior = MapGridGetMetatileBehaviorAt(position.x, position.y);

    if (MetatileBehavior_IsSandOrDeepSand(GetPlayerCurMetatileBehavior(gPlayerAvatar.runningState)) && (!FuncIsActiveTask(Task_MapNamePopUpWindow)))
        {
            if (!(locSum == MAP_ROUTE111))
            {
                rand = (Random() % 256);
                if (!AreMonsRepelled() && ((rand == 69) || (rand == 169)))
                {
                    gSpecialVar_0x8009 = SteppedOnSpecies[rand2];//store species id.
                    CreateTask(Task_HatEncounter_SteppedOn, 0x80);
                }
            }
        }
        if (FlagGet(FLAG_TEMP_D) == 0)
        {
            if (RyuCheckPlayerisInMtPyreAndHasPikachu() == TRUE)
            {
                if (!AreMonsRepelled() && Random() % 256 == 128)
                {
                    CreateTask(Task_HatEncounter_Mimikyu, 1);
                }
            }
        }
        
        if (FlagGet(FLAG_RYU_ENCOUNTERED_MELOETTA) == FALSE)
            {
                if ((MetatileBehavior_IsTallGrass(GetPlayerCurMetatileBehavior(gPlayerAvatar.runningState)) == TRUE) && (FlagGet(FLAG_RYU_CAPTURED_MELOETTA) == FALSE))
                {
                    if (GetGameStat(GAME_STAT_USED_SOUND_MOVE) >= 255)
                    {
                        u16 rand = (Random() % 100);
                        if (rand < 20)
                        {
                            FlagSet(FLAG_RYU_ENCOUNTERED_MELOETTA);
                            PlaySE(21);
                            StartBGCutscene(SCENEBGMELOETTA);
                            SetVBlankCallback(VBCB_FullscreenCutscene);
                            SET_DYNAMIC_LEG_ENCOUNTER(SPECIES_MELOETTA, (u8[])_("A cute Pokémon attacks!"));
                        }
                    }
                    else if ((GetGameStat(GAME_STAT_USED_SOUND_MOVE) >= 200) && (FlagGet(FLAG_RYU_SECOND_MELOETTA_MSG) == FALSE))
                    {
                        ShowFieldMessage((const u8[])_("{COLOR LIGHT_GREEN}{SHADOW GREEN} (You hear a delightful melody from\nsomewhere nearby...)$"));
                        PlayCry1(SPECIES_MELOETTA, 0);
                        FlagSet(FLAG_RYU_SECOND_MELOETTA_MSG);
                        CreateTask(RyuMessageTimerTask, 0xFF);
                    }
                    else if ((GetGameStat(GAME_STAT_USED_SOUND_MOVE) >= 100) && (FlagGet(FLAG_RYU_FIRST_MELOETTA_MSG) == FALSE))
                    {
                        ShowFieldMessage((const u8[])_("{COLOR LIGHT_GREEN}{SHADOW GREEN} (You get the strangest feeling...\nas if someone or something is\lwatching over you...)$"));
                        FlagSet(FLAG_RYU_FIRST_MELOETTA_MSG);
                        CreateTask(RyuMessageTimerTask, 0xFF);
                    }
                    else if (GetGameStat(GAME_STAT_USED_SOUND_MOVE) < 50)
                    {
                        FlagSet(FLAG_TEMP_C);
                    }
                }
            }

    //Ultra beast encounter checks
    //now, extra-lewd!

    if ((FlagGet(FLAG_RYU_ULTRA_BEASTS_ESCAPED) == TRUE) && (FlagGet(FLAG_RYU_CAUGHT_ALL_UBS) == FALSE) && (rand < 5))//5% chance to find the UB here.
    {

        if ((FlagGet(FLAG_RYU_BUZZWOLE_CAUGHT) == FALSE) && (FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER) == FALSE) && (UBRotation == 0))
        {
            if (locSum == MAP_GRANITE_CAVE_1F ||
                locSum == MAP_GRANITE_CAVE_B1F ||
                locSum == MAP_GRANITE_CAVE_B2F)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                gSpecialVar_0x8009 = SPECIES_BUZZWOLE;
                StringCopy(gRyuStringVar4, (u8[])_("A mysterious Bug Pokémon attacks!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
            }
        }

        if (!(FlagGet(FLAG_RYU_PHEROMOSA_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 0))
        {
            if (locSum == MAP_ROUTE119)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                gSpecialVar_0x8009 = SPECIES_PHEROMOSA;
                StringCopy(gRyuStringVar4, (u8[])_("A feminine Bug Pokémon attacks!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
            }
        }

        if (!(FlagGet(FLAG_RYU_KARTANA_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 1))
        {
            if (gSaveBlock1Ptr->location.mapNum == MAP_ROUTE120)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                gSpecialVar_0x8009 = SPECIES_KARTANA;
                StringCopy(gRyuStringVar4, (u8[])_("Some animated origami attacks!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
            }
        }

        if (!(FlagGet(FLAG_RYU_XURKITREE_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 1))
        {
            if (locSum == MAP_NEW_MAUVILLE_INSIDE)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                gSpecialVar_0x8009 = SPECIES_XURKITREE;
                StringCopy(gRyuStringVar4, (u8[])_("Some living power lines attack!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
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
                gSpecialVar_0x8009 = SPECIES_NIHILEGO;
                StringCopy(gRyuStringVar4, (u8[])_("An odd wig-shaped jellyfish attacks!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
            }
        }

        if (!(FlagGet(FLAG_RYU_GUZZLORD_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 2))
        {
            if (locSum == MAP_FROSTY_GROTTO)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                gSpecialVar_0x8009 = SPECIES_GUZZLORD;
                StringCopy(gRyuStringVar4, (u8[])_("A Pokémon with a gaping maw attacks!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
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
                gSpecialVar_0x8009 = SPECIES_STAKATAKA;
                StringCopy(gRyuStringVar4, (u8[])_("A giant living box attacks!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
            }
        }

        if (!(FlagGet(FLAG_RYU_CELESTEELA_CAUGHT)) && (!(FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER))) && (UBRotation == 3))
        {
            if (locSum == MAP_ROUTE66)
            {
                FlagSet(FLAG_RYU_ENCOUNTERED_UB);
                gSpecialVar_0x8009 = SPECIES_CELESTEELA;
                StringCopy(gRyuStringVar4, (u8[])_("A magical statue attacks!"));
                CreateTask(Task_HatEncounter_UltraBeast, 1);
            }
        }
    

    }

    if ( (rand < 5) &&
         (locSum ==MAP_PETALBURG_WOODS) &&
         (RyuCheckHasFighterDogs() == TRUE) &&
         (FlagGet(FLAG_SYS_GAME_CLEAR) == TRUE) &&
         (FlagGet(FLAG_RYU_CAUGHT_KELDEO) == FALSE) &&
         (FlagGet(FLAG_RYU_PAUSE_UB_ENCOUNTER) == FALSE))
    {
        FlagSet(FLAG_RYU_PAUSE_UB_ENCOUNTER);
        CreateTask(Task_HatEncounter_Keldeo, 1);
    }
}
