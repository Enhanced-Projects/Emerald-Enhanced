#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_tower.h"
#include "cable_club.h"
#include "cutscene.h"
#include "data.h"
#include "decoration.h"
#include "diploma.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item_icon.h"
#include "link.h"
#include "list_menu.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "rayquaza_scene.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "starter_choose.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "wallclock.h"
#include "window.h"
#include "constants/battle_frontier.h"
#include "constants/battle_tower.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/item.h"
#include "constants/heal_locations.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/mevent.h"
#include "constants/tv.h"
#include "constants/script_menu.h"
#include "constants/slot_machine.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/battle_frontier.h"
#include "constants/weather.h"
#include "constants/metatile_labels.h"
#include "constants/rgb.h"
#include "constants/trainers.h"
#include "palette.h"
#include "item.h"
#include "decompress.h"
#include "constants/trainers.h"
#include "pokedex.h"
#include "money.h"
#include "menu_helpers.h"
#include "rtc.h"
#include "constants/region_map_sections.h"
#include "field_specials.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "strings.h"
#include "ach_atlas.h"
#include "lifeskill.h"
#include "script_pokemon_util.h"
#include "data/lifeskill.h"
#include "RyuEnemyEnhancementSystem.h"
#include "overworld_notif.h"
#include "factions.h"
#include "scripted_encounters.h"
#include "StatAssist.h"

extern u8 GetObjectEventIdByLocalId(u8 id);

extern u8 RyuScript_CheckCompleteDailyQuest[];


void ApplyDaycareExperience(struct Pokemon *mon)
{
    s32 i;
    bool8 firstMove;
    u16 learnedMove;

    for (i = 0; i < MAX_LEVEL; i++)
    {
        // Add the mon's gained daycare experience level by level until it can't level up anymore.
        if (TryIncrementMonLevel(mon))
        {
            // Teach the mon new moves it learned while in the daycare.
            firstMove = TRUE;
            while ((learnedMove = MonTryLearningNewMove(mon, firstMove)) != 0)
            {
                firstMove = FALSE;
                if (learnedMove == 0xFFFF)
                {
                    // Mon already knows 4 moves.
                    //DeleteFirstMoveAndGiveMoveToMon(mon, gMoveToLearn);
                    //FlagSet(FLAG_RYU_BATTERY_MON_LEARNED_MOVE);
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }

    // Re-calculate the mons stats at its new level.
    CalculateMonStats(mon);
}

void GivePlayerModdedMon(void)
{
    u16 species = (VarGet(VAR_RYU_GCMS_SPECIES));
    u8 nature = (VarGet(VAR_TEMP_C));
    u8 fixedIv = (VarGet(VAR_RYU_GCMS_VALUE));
    u8 slot = (VarGet(VAR_TEMP_8));
    u8 ability = (Random() % 3);
    u8 level = 1;
    if (ability == 3)
        ability = 2;

    if (fixedIv > 31)
        fixedIv = 31;
    if (FlagGet(FLAG_RYU_DISABLE_NATURE_SELECTION_IN_GCMS) == TRUE)
    {
        gPlayerParty[slot] = gSaveBlock1Ptr->GCMS;
        SetMonData(&gPlayerParty[slot], MON_DATA_HP_IV, &fixedIv);
        SetMonData(&gPlayerParty[slot], MON_DATA_ATK_IV, &fixedIv);
        SetMonData(&gPlayerParty[slot], MON_DATA_DEF_IV, &fixedIv);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_IV, &fixedIv);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_IV, &fixedIv);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPEED_IV, &fixedIv);
    }
    else
    {
        CreateMonWithNature(&gPlayerParty[slot], species, level, fixedIv, nature);
        SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
        SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);
    }

    CalculateMonStats(&gPlayerParty[slot]);
}

extern int CountBadges();

void PasscodeGiveMonWithNature(void)
{
    u8 slot = (VarGet(VAR_TEMP_8));
    u16 species = (VarGet(VAR_TEMP_4));
    u8 nature = (VarGet(VAR_TEMP_C));
    u8 fixedIv = 31;
    u8 level = 100;
    u8 scaleMode = 0;
    bool8 maxScale = FALSE;

    if (VarGet(VAR_TEMP_9) == 69)
    {
        scaleMode = 2;
        maxScale = TRUE;
    }
    
    level = RyuChooseLevel(CountBadges(), maxScale, scaleMode, CalculatePlayerPartyStrength());

    CreateMonWithNature(&gPlayerParty[slot], species, level, fixedIv, nature);
    CalculateMonStats(&gPlayerParty[slot]);
}

void SetMonAbility(void)
{
    u8 slot = (VarGet(VAR_TEMP_8));
    u8 ability = (VarGet(VAR_TEMP_7));
    u16 species = GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES2);
    if ((gBaseStats[species].abilities[ability]) == 0)
        ability = 0;
    SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);
}


void SetMonPid(void)
{
    u8 slot = (VarGet(VAR_TEMP_8));
    u8 nature = (VarGet(VAR_TEMP_C));
    u8 gender = (VarGet(VAR_TEMP_9));
    u16 range = 25657;
    u16 start1 = range + 1;
    u32 start2 = 0;
    u32 a[128];
    u32 i;
    while (start1 != range) {
        for (i = 0; i < 128; ++i) {
            a[i] = (start2++)*25+nature;
        }
        for (i = 0; i < 128; ++i) {
            if ((gender == MON_GENDERLESS || (gender == MON_MALE && (a[i] % 256) > 225) || (gender == MON_FEMALE && a[i] % 256 < 31)) && (a[i] % 25 == nature)) {
                ChangeBoxMonDataPersonality(&gPlayerParty[slot].box, &a[i]);
                return;
            }
        }
    }
}


void SetMonShinyPid(void)
{
    u8 slot = (VarGet(VAR_TEMP_8));
    u8 nature = (VarGet(VAR_TEMP_C));
    u8 gender = (VarGet(VAR_TEMP_9));
    u32 OTID = GetMonData(&gPlayerParty[slot], MON_DATA_OT_ID);
    u16 tid = OTID % 65536;
    u16 sid = OTID >> 16;
    u16 calcID = (tid ^ sid) >> 3;
    u16 range = 25657;
    u16 start1 = range + 1;
    u32 p1, p2;
    u32 a[128];
    u32 i;
    while (start1 != range) {
        p1 = start1++;
        p2 = p1 ^ calcID;
        for (i = 0; i < 128; ++i) {
            a[i] = (((p1 << 3) | (i % 8)) << ((i < 64) ? 16 : 0)) | (((p2 << 3) | ((i / 8) % 8)) << (i < 64 ? 0 : 16));
        }
        for (i = 0; i < 128; ++i) {
            if ((gender == MON_GENDERLESS || (gender == MON_MALE && (a[i] % 256) > 225) || (gender == MON_FEMALE && a[i] % 256 < 31)) && (a[i] % 25 == nature)) {
                ChangeBoxMonDataPersonality(&gPlayerParty[slot].box, &a[i]);
                return;
            }
        }
    }
    
}

bool8 RyuGiveMewtwo(void)
{
    u8 ev = 252;
    u8 slot = CalculatePlayerPartyCount();
    u8 boss = TRUE;
    // empty party (how?) or full party
    if (slot == 0 || slot > 5) {
      return FALSE;
    }
    if (Random() % 100 < 50)
    {
        CreateMonWithNature(&gPlayerParty[slot], SPECIES_MEWTWO, 95, 31, NATURE_ADAMANT);
        SetMonData(&gPlayerParty[slot], MON_DATA_DEF_EV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_ATK_EV, &ev);
    }
    else
    {
        CreateMonWithNature(&gPlayerParty[slot], SPECIES_MEWTWO, 95, 31, NATURE_MODEST);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_EV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_EV, &ev);
    }
    if (Random() % 100 < 30) 
    {
        SetMonData(&gPlayerParty[slot], MON_DATA_BOSS_STATUS, &boss);
    }
    return TRUE;
}

void RyuKillMon(void)
{
    u8 i;
    u8 partyCount = CalculatePlayerPartyCount();

    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
        {
            ZeroMonData(&gPlayerParty[i]);
            PlaySE(SE_POKE_DEAD);
        }
    }

    CompactPartySlots();
    if ((CalculatePlayerPartyCount) == 0)
        FlagSet(FLAG_RYU_CHALLENGEFAILED);
}

bool32 isMonLegendaryID (u16 speciesid)
{
    if ((gBaseStats[speciesid].isLegendary) == TRUE)
        return TRUE;
    return FALSE;
}

bool32 isMonUltraBeastID (u16 speciesid)
{
    if ((speciesid > 792) && (speciesid < 800))
        return TRUE;
    return FALSE;
}

bool32 isMonMegaID (u16 speciesid)
{
    if ((speciesid >= 809) && (speciesid < 858))
        return TRUE;
    return FALSE;
}

extern const u16 gFrontierBannedSpecies[27];
extern const u16 gChallengeBannedSpecies[69];

int CheckValidMonsForSpecialChallenge (void)
{
    s32 k = 0;
    for (k = 0; k < 6; k++)
    {
        if ((isMonLegendaryID(GetMonData(&gPlayerParty[k], MON_DATA_SPECIES)) == TRUE))
                return 666;
        if ((isMonUltraBeastID(GetMonData(&gPlayerParty[k], MON_DATA_SPECIES)) == TRUE))
                return 668;
        if ((isMonMegaID(GetMonData(&gPlayerParty[k], MON_DATA_SPECIES)) == TRUE))
                return 667;
    }
}


int RyuSacrificeMon(void)//eats the selected mon and saves certain values to be used by gcms.
{
    u8 slot = gSpecialVar_0x8000;
    u16 species = (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES2, NULL));
    u8 i;

    for (; gFrontierBannedSpecies[i] != 0xFFFF; i++)
        {
            if (gFrontierBannedSpecies[i] == (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES2)))
                return 2;
        }

    if (FlagGet(FLAG_TEMP_5) == 1)//is initial species
    {
        VarSet(VAR_RYU_GCMS_SPECIES, species);
        gSaveBlock1Ptr->GCMS = gPlayerParty[slot];
        ZeroMonData(&gPlayerParty[slot]);
        CompactPartySlots();
        FlagClear(FLAG_TEMP_5);
        return 1;
    }
    else if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES2, NULL) == (VarGet(VAR_RYU_GCMS_SPECIES)))
    {
        ZeroMonData(&gPlayerParty[slot]);
        CompactPartySlots();
        return 1;
    }
    return 0;
}

void RyuWipeParty(void)
{
    ZeroMonData(&gPlayerParty[5]);
    ZeroMonData(&gPlayerParty[4]);
    ZeroMonData(&gPlayerParty[3]);
    ZeroMonData(&gPlayerParty[2]);
    ZeroMonData(&gPlayerParty[1]);
    ZeroMonData(&gPlayerParty[0]);
    CompactPartySlots();
}

void RyuDawnGiftPoke(void)
{
    u8 iv = 126;
    u8 partycount = (CalculatePlayerPartyCount());
    u8 friendship = 70;
    u8 gender = FEMALE;
    const u8 otname[] = ((const u8[]) _("Dawn"));
    u8 level = (RyuChooseLevel(CountBadges(), FALSE, SCALING_TYPE_TRAINER, CalculatePlayerPartyStrength()));

    CreateMonWithGenderNatureLetter(&gPlayerParty[partycount], SPECIES_SNEASEL, level, 31, MON_FEMALE, NATURE_ADAMANT, 0);
    SetMonData(&gPlayerParty[partycount], MON_DATA_ATK_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_SPEED_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(&gPlayerParty[partycount], MON_DATA_OT_GENDER, &gender);
    SetMonData(&gPlayerParty[partycount], MON_DATA_OT_NAME, &otname);
}

void RyuBrendanGiftPoke(void)
{
    u8 iv = 126;
    u8 partycount = (CalculatePlayerPartyCount());
    u8 friendship = 70;
    u8 gender = MALE;
    const u8 otname[] = ((const u8[]) _("Brendan"));
    u8 level = (RyuChooseLevel(CountBadges(), FALSE, SCALING_TYPE_TRAINER, CalculatePlayerPartyStrength()));

    partycount = VarGet(gSpecialVar_Result);
    CreateMonWithGenderNatureLetter(&gPlayerParty[partycount], SPECIES_SNORUNT, level, 31, MON_FEMALE, NATURE_MODEST, 0);
    SetMonData(&gPlayerParty[partycount], MON_DATA_SPATK_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_SPEED_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(&gPlayerParty[partycount], MON_DATA_OT_GENDER, &gender);
    SetMonData(&gPlayerParty[partycount], MON_DATA_OT_NAME, &otname);
}

void RyuChallengeCheck (void)
{
    if ((JOY_HELD(L_BUTTON)) && (JOY_HELD(R_BUTTON)))
    {
        gSpecialVar_Result = 420;
        return;
    }
}

void RyuDevCheck(void)
{
    if ((JOY_HELD(L_BUTTON)) && (JOY_HELD(R_BUTTON)) && (JOY_HELD(B_BUTTON)) && (JOY_HELD(START_BUTTON)) && (JOY_HELD(SELECT_BUTTON)))
    {
        gSpecialVar_Result = 777;
        return;
    }
    if ((JOY_HELD(L_BUTTON)) && (JOY_HELD(R_BUTTON)) && (JOY_HELD(B_BUTTON)))
    {
        gSpecialVar_Result = 69;
        return;
    }
}

int CountBadges(void)
{
    int count = 0, badge;
    for (badge = FLAG_BADGE01_GET; badge <= FLAG_BADGE08_GET; badge++)
        count += FlagGet(badge);
    if (count > 4)//if player has more than 4 badges, hide Lucy at her home in lavaridge and prevent quest start.
    {
        FlagSet(FLAG_RYU_LAVARIDGE_LUCY);
        if ((VarGet(VAR_RYU_QUEST_LUCY) != 100) || (VarGet(VAR_RYU_QUEST_LUCY) != 0))
            VarSet(VAR_RYU_QUEST_LUCY, 555);//@Player got too many badges during lucy quest
    }
    return count;
}

void checkbadgecount(void)
{
    gSpecialVar_Result = CountBadges();
}

void checksymbolcount(void)
{
    s32 i;
    s32 symbolcount = 0;

    for(i = FLAG_SYS_TOWER_SILVER; i < FLAG_SYS_PYRAMID_GOLD; i += 2)
    {
        if(FlagGet(i))
            symbolcount++;
    }

    gSpecialVar_Result = symbolcount;
}

extern const u8 gText_EmptyString2[]; 

void RyuClearStringVars(void)
{
    StringCopy(gStringVar1, gText_EmptyString2);
    StringCopy(gStringVar2, gText_EmptyString2);
    StringCopy(gStringVar3, gText_EmptyString2);
    StringCopy(gRyuStringVar1, gText_EmptyString2);
    StringCopy(gRyuStringVar2, gText_EmptyString2);
    StringCopy(gRyuStringVar2, gText_EmptyString2);
}

void RyuIvSetter(void)
{
    u8 iv = 31;
    PlaySE(SE_EXPMAX);
    SetMonData(&gPlayerParty[0], MON_DATA_HP_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_ATK_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_DEF_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_SPATK_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_SPDEF_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_SPEED_IV, &iv);
}

void RyuSetFriendship(void)
{
    u8 value = 250;
    u8 slot = VarGet(VAR_TEMP_2);
    SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &value);
    CalculateMonStats(&gPlayerParty[slot]);
}

static const u16 RyuValToEv[] = {
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV
};

static const u16 RyuValToIv[] = {
    MON_DATA_HP_IV,
    MON_DATA_ATK_IV,
    MON_DATA_DEF_IV,
    MON_DATA_SPEED_IV,
    MON_DATA_SPATK_IV,
    MON_DATA_SPDEF_IV
};

void CheckSuperTrainingTotalEV (void)
{
    u16 value = gSpecialVar_0x8000;
    u16 slot = gSpecialVar_0x8001; 
    u16 stat = gSpecialVar_0x8002;
    u32 i;
    u16 total = 0;
    
    for (i = 0; i < 6;i++)
        total += (GetMonData(&gPlayerParty[slot], MON_DATA_HP_EV + i));

    if (total >= 510)
        gSpecialVar_Result = 3;//mon is maxed
    else if ((GetMonData(&gPlayerParty[slot], RyuValToEv[stat])) + value > 252)
        gSpecialVar_Result = 2;//slot is maxed
    else
        gSpecialVar_Result = 0;//slot can take all the requested EV
}

void RyuSetSlotStatIVEV(void)//Now with extra lewd
{
    u16 value = gSpecialVar_0x8000; //set stat to this value
    u16 slot = gSpecialVar_0x8001; //which mon slot
    u16 stat = gSpecialVar_0x8002; //which mon stat
    u16 mode = gSpecialVar_0x8003;//0 = ev, 1 = iv, 2 = additive EV
    u16 evmax = 252;
    u16 ivmax = 31;
    int i;

    if (mode == 0)
    {
        if (stat > 6)// user probably pressed B during stat selection menu. just set all stats to max.
        {
            if (value > evmax)
                value = evmax;
            for (i = 0;i<6;i++)
                SetMonData(&gPlayerParty[slot], MON_DATA_HP_EV + i, &evmax);
            CalculateMonStats(&gPlayerParty[slot]);
            return;
        }
        if (value > evmax)
        {
            value = evmax;
            SetMonData(&gPlayerParty[slot], RyuValToEv[stat], &value);
            CalculateMonStats(&gPlayerParty[slot]);
            return;
        }
        else
        {
            SetMonData(&gPlayerParty[slot], RyuValToEv[stat], &value);
            CalculateMonStats(&gPlayerParty[slot]);
            return;
        }
    }
    
    if (mode == 1)
    {
        if (stat > 6)// user probably pressed B during stat selection menu. just set all stats to max.
        {
            if (value > ivmax)
                value = 31;
            for (i = 0;i<6;i++)
                SetMonData(&gPlayerParty[slot], MON_DATA_HP_IV + i, &ivmax);
            CalculateMonStats(&gPlayerParty[slot]);
            return;
        }
        if (value > ivmax)
        {
            value = ivmax;
            SetMonData(&gPlayerParty[slot], RyuValToIv[stat], &value);
            CalculateMonStats(&gPlayerParty[slot]);
            return;
        }
        else
        {
            SetMonData(&gPlayerParty[slot], RyuValToIv[stat], &value);
            CalculateMonStats(&gPlayerParty[slot]);
        }
        
    } 

    if (mode == 2)
    {
        u16 current = GetMonData(&gPlayerParty[slot], RyuValToEv[stat]);
        if ((current + value) > 252)
        {
            value = evmax;
            SetMonData(&gPlayerParty[slot], RyuValToEv[stat], &value);
            CalculateMonStats(&gPlayerParty[slot]);
            return;
        }
        else
        {
            u16 newVal = (current + value);
            SetMonData(&gPlayerParty[slot], RyuValToEv[stat], &newVal);
            CalculateMonStats(&gPlayerParty[slot]);
        }
        
    } 
}

void RyuResetIvEvs(void)
{
    u8 ev = 0;
    u16 slot = gSpecialVar_0x8001;
    u16 mode = gSpecialVar_0x8003;
    PlaySE(SE_EXPMAX);
    if (mode == 0)
    {
        SetMonData(&gPlayerParty[slot], MON_DATA_HP_IV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_ATK_IV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_DEF_IV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_IV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_IV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPEED_IV, &ev);
    }
    else
    {
        SetMonData(&gPlayerParty[slot], MON_DATA_HP_EV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_ATK_EV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_DEF_EV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_EV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_EV, &ev);
        SetMonData(&gPlayerParty[slot], MON_DATA_SPEED_EV, &ev);
    }
    CalculateMonStats(&gPlayerParty[slot]);
    return;
}

void RyuSetMonMove(void)
{
    u16 move = VarGet(VAR_TEMP_3);
    u8 partyslot = VarGet(VAR_TEMP_1);
    u8 moveslot = VarGet(VAR_TEMP_2);
    switch (moveslot)
    {
    case 0:
        SetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE1, &move);
        break;
    case 1:
        SetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE2, &move);
        break;
    case 2:
        SetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE3, &move);
        break;
    case 3:
        SetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE4, &move);
        break;
    default:
        break;
    }
}

int RyuCalculateCurrentExpCoefficient(void)//uses the same formula as my exp multiplier. see `calculatedExp` in battle_script_commands.c
{
    u16 calc = 0;
    u16 badges = (CountBadges());
    calc = (1000 + (badges * 250));
    return calc;
}

void RyuGenerateReward(void)//combines the return values from the passcode menu into one integer, 
{                           //which is then returned to the script to determine if and what reward
    u8 v1 = VarGet(VAR_TEMP_1);//the player gets.
    u8 v2 = VarGet(VAR_TEMP_2);
    u8 v3 = VarGet(VAR_TEMP_3);
    gSpecialVar_Result = (v1 * 100) + (v2 * 10) + v3;
    VarSet(VAR_TEMP_6, gSpecialVar_Result);
    ConvertIntToDecimalStringN(gStringVar1, gSpecialVar_Result, STR_CONV_MODE_RIGHT_ALIGN, 3);
}

void RyuGiveKoutaMawile(void)
{
    u8 iv = 252;
    u8 partycount = CalculatePlayerPartyCount();

    CreateMonWithNature(&gPlayerParty[partycount], SPECIES_MAWILE, 80, 31, NATURE_ADAMANT);
    SetMonData(&gPlayerParty[partycount], MON_DATA_ATK_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_HP_EV, &iv);
    VarSet(VAR_TEMP_3, 2);
}

void RyuWarp()//this and the function below were added because lana's quest script was so complicated, it overwrote other bits of RAM causing random crashes on
{             //warp. I have since avoided making such long scripts, but for now these are still necessary until they can be fixed.
    u8 mapGroup = 1;
    u8 mapNum = 1;
    u8 warpId = 255;
    u16 x = 1;
    u16 y = 4;
    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
    EnableBothScriptContexts();
}

void RyuWarp2()
{
    u8 mapGroup = 1;
    u8 mapNum = 3;
    u8 warpId = 255;
    u16 x = 7;
    u16 y = 4;
    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
    EnableBothScriptContexts();
}

const u8 gText_OneSpace[] = _(" ");
const u8 gRyu_TempVarIntro[] = _("\n");

void RyuCheckTempVars(void)//buffers the values of all temporary map vars to a single text buffer to be displayed in a string.
{
    u16 v0 = VarGet(VAR_TEMP_0);
    u16 v1 = VarGet(VAR_TEMP_1);
    u16 v2 = VarGet(VAR_TEMP_2);
    u16 v3 = VarGet(VAR_TEMP_3);
    u16 v4 = VarGet(VAR_TEMP_4);
    u16 v5 = VarGet(VAR_TEMP_5);
    u16 v6 = VarGet(VAR_TEMP_6);
    u16 v7 = VarGet(VAR_TEMP_7);
    u16 v8 = VarGet(VAR_TEMP_8);
    u16 v9 = VarGet(VAR_TEMP_9);
    u16 vA = VarGet(VAR_TEMP_A);
    u16 vB = VarGet(VAR_TEMP_B);
    u16 vC = VarGet(VAR_TEMP_C);
    u16 vD = VarGet(VAR_TEMP_D);
    u16 vE = VarGet(VAR_TEMP_E);
    u16 vF = VarGet(VAR_TEMP_F);
    //1
    ConvertIntToDecimalStringN(gStringVar1, v0, STR_CONV_MODE_LEFT_ALIGN, 5);
    //2
    ConvertIntToDecimalStringN(gStringVar3, v1, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //3
    ConvertIntToDecimalStringN(gStringVar3, v2, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //4
    ConvertIntToDecimalStringN(gStringVar3, v3, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //5
    ConvertIntToDecimalStringN(gStringVar3, v4, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //6
    ConvertIntToDecimalStringN(gStringVar3, v5, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //7
    ConvertIntToDecimalStringN(gStringVar3, v6, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //8
    ConvertIntToDecimalStringN(gStringVar3, v7, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //adding linbreak
    StringAppend(gStringVar1, gRyu_TempVarIntro);
    //9
    ConvertIntToDecimalStringN(gStringVar3, v8, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gStringVar3);
    //10
    ConvertIntToDecimalStringN(gStringVar3, v9, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //11
    ConvertIntToDecimalStringN(gStringVar3, vA, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //12
    ConvertIntToDecimalStringN(gStringVar3, vB, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //13
    ConvertIntToDecimalStringN(gStringVar3, vC, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //14
    ConvertIntToDecimalStringN(gStringVar3, vD, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //15
    ConvertIntToDecimalStringN(gStringVar3, vE, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
    //16
    ConvertIntToDecimalStringN(gStringVar3, vF, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, gText_OneSpace);
    StringAppend(gStringVar1, gStringVar3);
}
//Ball changer

void RyuChangeUsedPokeball(void)
{
    u32 newBall = VarGet(VAR_ITEM_ID);
    u32 slot = VarGet(VAR_TEMP_C);
    SetMonData(&gPlayerParty[slot], MON_DATA_POKEBALL, &newBall);
}

bool8 RyuSwapAbility(void)//ability switcher, which requires a big pearl in the script.
{
    u8 currentAbility = (GetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM));

    if (currentAbility == 0)
    {
        u8 ability = 1;
        SetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM, &ability);
        return TRUE;
    }
    else if (currentAbility == 1)
    {
        u8 ability = 0;
        SetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM, &ability);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int RyuCountBoxedPokemon(void)//used by lanette to determine how many box pokemon player has
{
    int i,k;
    u16 count = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
        for (k = 0;k < IN_BOX_COUNT;k++)
                if ((GetBoxMonDataAt(i, k, MON_DATA_IS_EGG) == FALSE) && (!(GetBoxMonDataAt(i, k, MON_DATA_SPECIES) == SPECIES_NONE)))
                    count++;
    if (FlagGet(FLAG_RYU_VERBOSE_MODE) == TRUE)
        DebugPrint(((const u8[])_("Total box mons: ")), 1, count);
    return count;
}

static const u16 sRotomForms[6] = {
    SPECIES_ROTOM_HEAT,
    SPECIES_ROTOM_WASH,
    SPECIES_ROTOM_FROST,
    SPECIES_ROTOM_FAN,
    SPECIES_ROTOM_MOW,
    SPECIES_ROTOM,
};

static const u16 sRotomMoves[6] = {
    87,
    315,
    56,
    542,
    58,
    437,
};

int RyuSwapRotomForm(void)//Toby had concerns that this wasn't as 'nice' as the one he saw somewhere else, but this performs all the same functions.
{                         //He just wanted it so that base rotom doesn't require thunder.
    u16 i = 0;
    u16 j = 0;
    u16 rotomSpecies = 0;
    u16 rotomMove = 0;
    u16 moveSlot = 69;
    bool8 hasMon = FALSE;
    u16 monSlot = 0;
    u16 move = 0;
    u16 species = 0;

    for (i = 0; i < (CalculatePlayerPartyCount()); i++)
    {
        for (j = 0; j < ARRAY_COUNT(sRotomForms); j++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == (sRotomForms[j]))
            {
                hasMon = TRUE;
                monSlot = i;
            }
        }
    }

    if (hasMon == FALSE)
    {
        return 0;
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        for (j = 0; j < ARRAY_COUNT(sRotomMoves); j++)
        {
            if (GetMonData(&gPlayerParty[monSlot], MON_DATA_MOVE1 + i) == (sRotomMoves[j]))
            {
                moveSlot = i;
            }
        }
    }
    move = (VarGet(VAR_TEMP_4));
    species = (VarGet(VAR_TEMP_5));

    if (moveSlot == 69)
    {
        return 2;
    }
    SetMonMoveSlot(&gPlayerParty[monSlot], move, moveSlot);
    SetMonData(&gPlayerParty[monSlot], MON_DATA_SPECIES, &species);
    return 1;
}

bool8 checkForOverlordRyuEncounter(void)
{
    u16 rv = (Random() % 100);
    ConvertIntToDecimalStringN(gStringVar1, rv, 0, 2);
    if (VarGet(VAR_RYU_TITLE_DEFENSE_WINS) >= 10 && (FlagGet(FLAG_RYU_DEFEATED_OVERLORD) == 1))
    {
        if (rv <= 25)
        {
            gSpecialVar_0x8002 = 2;
            return 2;
        }
    }
    else if (VarGet(VAR_RYU_TITLE_DEFENSE_WINS) >= 10)
    {
        if (rv <= 10)
        {
            gSpecialVar_0x8002 = 1;
            return 1;
        }
    }
    else
    {
        gSpecialVar_0x8002 = 0;
        return 0;
    }
}

void CheckSaveFileSize(void)//used in debug menu from time to time as a special to check saveblock space and buffer to strings for output.
{
    u32 size = (sizeof(struct SaveBlock1));
    u32 size2 = (sizeof(struct SaveBlock2));
    u32 size3 = (sizeof(struct DynamicMapObjects));
    u32 size4 = (sizeof(struct ObjectEventTemplate));
    ConvertIntToDecimalStringN(gStringVar1, size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar2, size2, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar3, size3, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gRyuStringVar1, size4, STR_CONV_MODE_LEFT_ALIGN, 6);
}

void ForceSoftReset(void)//only used when you use Random Battle from the main menu. Otherwise, the player would lose their party and/or keep their random mons.
{
    DoSoftReset();
}

int RyuMeloettaFormSwitcher(void)
{
    u8 i;
    u8 partyCount = CalculatePlayerPartyCount();
    u16 m1 = 648;
    u16 m2 = 896;
    
    for (i = 0; i < partyCount; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_MELOETTA)
            {
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &m2);
                CalculateMonStats(&gPlayerParty[i]);
                VarSet(VAR_TEMP_9, i);
                VarSet(VAR_TEMP_A, SPECIES_MELOETTA_PIROUETTE);
                return 2;
            }

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_MELOETTA_PIROUETTE)
            {
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &m1);
                CalculateMonStats(&gPlayerParty[i]);
                VarSet(VAR_TEMP_9, i);
                VarSet(VAR_TEMP_A, SPECIES_MELOETTA);
                return 2;
            }
        }

    if (GetSetPokedexFlag(NATIONAL_DEX_MELOETTA, FLAG_GET_CAUGHT) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void VBCB_FullscreenCutscene(void) //callback for below function
{
	UpdatePidgeyPaletteFade();
	UpdateBgPan();
}

bool8 ScrCmd_drawfullscreenimage(struct ScriptContext *ctx)//draws the fullscreen pic with index. Needs to be removed with the below function
{                                                          //also causes a screen refresh, so if you're hiding npc's or changing map tiles
    u8 index = ScriptReadByte(ctx);                        //you don't need to also special DrawWholeScreenView.
    SetVBlankCallback(NULL);
    StartBGCutscene(index);
    SetVBlankCallback(VBCB_FullscreenCutscene);
    return TRUE;   
}

bool8 ScrCmd_clearfullscreenimage(struct ScriptContext *ctx)
{
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_ReturnToFieldContinueScript);
    return TRUE;
}

bool8 ScrCmd_checkspecies(struct ScriptContext *ctx)//this lewd function checks if player has mon, and if so,
{                                                   //sets VAR_RESULT to TRUE, and slot number to VAR_TEMP_F
    u16 speciesId = VarGet(ScriptReadHalfword(ctx));//see the relevant script command in asm/macros/event.inc
    u8 i;

    for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == speciesId)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == FALSE)
            {
                gSpecialVar_Result = TRUE;
                VarSet(VAR_TEMP_F, i);
                return TRUE;
            }
            else
            {
                VarSet(VAR_TEMP_F, 32768);//is an egg
                return TRUE;
            }
        }
    }
    FlagClear(FLAG_TEMP_C);
    VarSet(VAR_TEMP_F, 65535);//does not have
    return TRUE;
}

static EWRAM_DATA u8 specialCutsceneSprite = 0;

bool8 ScrCmd_drawcustompic(struct ScriptContext *ctx)//this function draws either a pokemon sprite or a trainer sprite depending on mode.
{                                                    //I may just remove this function entirely, since it's unused. Always had trouble with this anyway.
    u8 mode = ScriptReadByte(ctx);
    u16 id = VarGet(ScriptReadHalfword(ctx));
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    if (mode == 1)//I intended to use this for when the player talks to npc's but couldn't find a way to dynamically call this function based on the OW GraphicsID
    {
        specialCutsceneSprite = (CreateTrainerSprite(FacilityClassToPicIndex(id), x, y, 0, &gDecompressionBuffer[0x800]));//trainer sprites i.e. FACILITY_CLASS_COOLTRAINER_M
        return FALSE;
    }

    if (mode == 2)//you can theoretically just use the drawmonpic script command, but this has the ability to draw backsprites as well.
    {
        VarSet(VAR_TEMP_7, id);
        VarSet(VAR_TEMP_8, 2);
        specialCutsceneSprite = CreateMonSpriteFromNationalDexNumber(id, x, y, 15);
        return FALSE;
    }

    if (mode == 3)//i don't remember why i did this
    {
        CreateMonSprite_PicBox(id, x, y, 0);
    }
}

bool8 ScrCmd_getobjectxy(struct ScriptContext *ctx)
{
    u8 localId = VarGet(ScriptReadHalfword(ctx));
    struct ObjectEvent *objectEvent = &gObjectEvents[GetObjectEventIdByLocalId(localId)];
    gSpecialVar_0x8001 = objectEvent->currentCoords.x - 7;
    gSpecialVar_0x8002 = objectEvent->currentCoords.y - 7;

    return FALSE;
}

void FillTheDex(void)
{
    u16 i = 0;
    u16 idno = NATIONAL_DEX_COUNT;
    for (i = 0; i < idno; i++)
    {
        GetSetPokedexFlag(i, FLAG_SET_CAUGHT);
        GetSetPokedexFlag(i, FLAG_SET_SEEN);
    }
    
}

int ChangeDarmanitanForm(void)
{
    u8 i;
    u16 darmi = SPECIES_DARMANITAN;
    u16 darm2 = SPECIES_DARMANITAN_ZEN;
    u8 hasDarmi = 0;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_DARMANITAN)
        {
            hasDarmi = 1;
            SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &darm2);
            CalculateMonStats(&gPlayerParty[i]);
            return hasDarmi;
        }
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_DARMANITAN_ZEN)
        {
            hasDarmi = 2;
            SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &darmi);
            CalculateMonStats(&gPlayerParty[i]);
            return hasDarmi;
        }

    }
    return hasDarmi;
}

bool8 ScrCmd_dominingcheck(struct ScriptContext *ctx) //rolls the inside/outside table for items from the relevant skill level
{
    u16 reward = 0;
    bool8 inside = TRUE;
    u8 amount = 1;
    u8 i = 0;
    u8 outsideCount = (ARRAY_COUNT(gOutsideMapSecs));
    u16 playerMLv = (VarGet(VAR_RYU_PLAYER_MINING_SKILL));
    u16 playerMHVLv = (VarGet(VAR_RYU_MINING_HARVEST_LV));
    u16 miningLevel = 0;
    if (playerMHVLv == 0)
        playerMHVLv++;

    if (playerMLv == playerMHVLv)
        miningLevel = playerMLv;
    else
        miningLevel = playerMHVLv;

    for (i = 0; i < outsideCount; i++)
    {
        if (gMapHeader.regionMapSectionId == gOutsideMapSecs[i])
        {
            inside = FALSE;
        }
    }

    switch (miningLevel)//I feel like this could be made more efficient
    {
    case 0:
        {
            reward = 0;
            amount = 0;
            break;
        }
    case 1:
        {
            if (inside == TRUE)
                {
                    reward = gInsideMiningTier1[(Random() % ARRAY_COUNT(gInsideMiningTier1))];
                    break;
                }
            else
                {
                    reward = gOutsideMiningTier1[(Random() % ARRAY_COUNT(gOutsideMiningTier1))];
                    break;
                }
        }
    case 2:
        {
            if (inside == TRUE)
                {
                    reward = gInsideMiningTier2[(Random() % ARRAY_COUNT(gInsideMiningTier2))];
                    break;
                }
            else
                {
                    reward = gOutsideMiningTier2[(Random() % ARRAY_COUNT(gOutsideMiningTier2))];
                    break;
                }
        }
    case 3:
        {
            amount = ((Random() % 2) + 1);
            if (inside == TRUE)
                {
                    reward = gInsideMiningTier3[(Random() % ARRAY_COUNT(gInsideMiningTier3))];
                    break;
                }
            else
                {
                    reward = gOutsideMiningTier3[(Random() % ARRAY_COUNT(gOutsideMiningTier3))];
                    break;
                }
        }
    }
    VarSet(VAR_TEMP_B, reward);
    VarSet(VAR_TEMP_C, amount);
    return TRUE;
    
}

int RyuGetItemQuantity(u16 *quantity)
{
    return gSaveBlock2Ptr->encryptionKey ^ *quantity;
}

void RyuCountGemOres(void)//buffers the number of each gem ore the player has to be used in a dynamic menu.
{
    u8 i;
    u16 total1 = 0;
    u16 total2 = 0;
    u16 total3 = 0;

    for (i = 0; i < gBagPockets[ITEMS_POCKET].capacity; i++)
    {
        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_COMMON_GEM_ORE)
        {
            total1 += RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_UNCOMMON_GEM_ORE)
        {
            total2 += RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_RARE_GEM_ORE)
        {
            total3 += RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }
    }

    ConvertIntToDecimalStringN(gRyuStringVar3, total3, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar2, total2, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar1, total1, STR_CONV_MODE_LEFT_ALIGN, 3);
}

void RyuBufferRepelItemCounts(void)
{
    u32 i;
    u16 total1 = 0;
    u16 total2 = 0;
    u16 total3 = 0;
    for (i = 0; i < gBagPockets[ITEMS_POCKET].capacity; i++)
    {
        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_REPEL)
        {
            total1 += RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_SUPER_REPEL)
        {
            total2 += RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_MAX_REPEL)
        {
            total3 += RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }
    }

    ConvertIntToDecimalStringN(gRyuStringVar3, total3, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar2, total2, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar1, total1, STR_CONV_MODE_LEFT_ALIGN, 3);
}

void RyuChooseFromGemList(void)//rolls the relevant table for gems
{
    u16 mode = (VarGet(VAR_TEMP_A));
    u16 Result = 0;

    switch (mode)
    {
        case 1:
            {
                Result = gGemTier1[(Random() %(ARRAY_COUNT(gGemTier1)))];
                break;
            }
        case 2:
            {
                Result = gGemTier2[(Random() %(ARRAY_COUNT(gGemTier2)))];
                break;
            }
        case 3:
            {
                Result = gGemTier3[(Random() %(ARRAY_COUNT(gGemTier3)))];
                break;
            }
    }
    VarSet(VAR_TEMP_B, Result);
}

int RyuFossilReward(void)//rolls a table for a random fossil reward
{
    u16 itemReward = gFossilTable[(Random() %(ARRAY_COUNT(gFossilTable)))];
    bool8 hasItem = (CheckBagHasItem(ITEM_FOSSIL_ORE, 1));
    
    if (hasItem == FALSE)
    {
        return 0;
    }
    else
    {
        return itemReward;
    }

}

int RyuShardReward(void)//Rolls shard table for a random shard.
{
    u16 itemReward = gShardOreTable[(Random() %(ARRAY_COUNT(gShardOreTable)))];
    bool8 hasItem = (CheckBagHasItem(ITEM_SHARD_ORE, 1));
    
    if (hasItem == FALSE)
    {
        return 0;
    }
    else
    {
        return itemReward;
    }

}

int RyuChooseRandomGhostId(void)
{
    u32 val = Random() % 100;
    do
    {
       val = (Random() % ((NUM_SPECIES) - 1));
    }while (!((gBaseStats[val].type1 == TYPE_GHOST) || (gBaseStats[val].type2 == TYPE_GHOST)) || (IS_ULTRA_BEAST(val) || IS_MEGA_EVOLVED(val)));
    gSpecialVar_0x8005 = val;

    return val;
}

int Ryu_GiveRevivedFossilEgg(void)//gives the player a revived fossil mon with 3 random stats at 31 IV
{
    u16 species = (VarGet(VAR_TEMP_4));
    u8 iv = 31;
    u8 rnd1, rnd2, rnd3;
    u8 slot = CalculatePlayerPartyCount();
    u8 level = 5;
    u8 fixedIV = 32;
    u8 egg = TRUE;

    if (slot == 6)
    {
        return 0;
    }
    do
    {
        rnd1 = ((Random() %6) + 39);
        rnd2 = ((Random() %6) + 39);
        rnd3 = ((Random() %6) + 39);
    }while (((rnd1 != rnd2) && (rnd2 != rnd3) && (rnd3 != rnd1)) == FALSE);//This loop makes sure that rnd 1 - 3 are not the same

    CreateMon(&gPlayerParty[slot], species, level, fixedIV, 0, 0, OT_ID_PLAYER_ID, 0);//this creates a fossil mon with 3 random iv's of 31

    gSpecialVar_0x8003 = species;

    SetMonData(&gPlayerParty[slot], rnd1, &iv);
    SetMonData(&gPlayerParty[slot], rnd2, &iv);
    SetMonData(&gPlayerParty[slot], rnd3, &iv);

    if ((slot <= 4) && (Random() % 1000 < 19))
    {
        SetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG, &egg);
        SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
        slot += 1;
         do
        {
            rnd1 = ((Random() %6) + 39);
            rnd2 = ((Random() %6) + 39);
            rnd3 = ((Random() %6) + 39);
        }while (((rnd1 != rnd2) && (rnd2 != rnd3) && (rnd3 != rnd1)) == FALSE);
        CreateMon(&gPlayerParty[slot], RyuChooseRandomGhostId(), level, fixedIV, 0, 0, OT_ID_PLAYER_ID, 0);
        SetMonData(&gPlayerParty[slot], rnd1, &iv);
        SetMonData(&gPlayerParty[slot], rnd2, &iv);
        SetMonData(&gPlayerParty[slot], rnd3, &iv);
        SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
        return 3;
    }
    SetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG, &egg);
    SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
    return 1;
}  

extern const u8 gText_ColorLightRedShadowRed[];
extern const u8 gText_ColorLightBlueShadowBlue[];
const u8 gText_ColorDarkGreyShadowLightGrey[] = _("{COLOR DARK_GREY}{SHADOW LIGHT_GREY}");
const u8 gText_RyuStatsHP[] =    _("                HP: ");
const u8 gText_RyuStatsAtk[] =   _("        Attack: ");
const u8 gText_RyuStatsDef[] =   _("      Defense: ");
const u8 gText_RyuStatsSpAtk[] = _("  Sp. Attack: ");
const u8 gText_RyuStatsSpDef[] = _("Sp. Defense: ");
const u8 gText_RyuStatsSpeed[] = _("          Speed: ");
const u8 gText_RyuStatsIv[] = _(", Iv: ");
const u8 gText_RyuStatsEv[] = _(", Ev: ");


bool8 RyuFillStatsBuffers(void)
{
    s8 NatureBoost = 0;
    u8 statIndex = 1;
    u8 nature = (GetNature(&gPlayerParty[0]));
    u8 gTextBuffer1[64];
    u8 gTextBuffer2[64];
    u8 gTextBuffer3[64];
    u8 gTextBuffer4[64];
    u16 slot = gSpecialVar_0x8001;

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey);
    StringAppend(gTextBuffer1, gText_RyuStatsHP);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[slot], MON_DATA_MAX_HP, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[slot], MON_DATA_HP_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[slot], MON_DATA_HP_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gStringVar1, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsAtk);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[slot], MON_DATA_ATK, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[slot], MON_DATA_ATK_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[slot], MON_DATA_ATK_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gStringVar2, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsDef);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[slot], MON_DATA_DEF, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[slot], MON_DATA_DEF_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[slot], MON_DATA_DEF_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gStringVar3, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsSpAtk);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[slot], MON_DATA_SPATK, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[slot], MON_DATA_SPATK_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[slot], MON_DATA_SPATK_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gRyuStringVar1, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsSpDef);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[slot], MON_DATA_SPDEF, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gRyuStringVar2, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsSpeed);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[slot], MON_DATA_SPEED, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[slot], MON_DATA_SPEED_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[slot], MON_DATA_SPEED_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gRyuStringVar3, gTextBuffer1);
}

extern const u8 *const gNatureNamePointers[NUM_NATURES];
extern const u8 gText_BirchBoy[];
extern const u8 gText_BirchGirl[];
void RyuBufferMonZeroNature(void)
{
    u8 nature = GetNature(&gPlayerParty[0]);
    u8 nick = (GetMonData(&gPlayerParty[0], MON_DATA_NICKNAME, gStringVar1));
    StringCopy(gStringVar2, gNatureNamePointers[nature]);
    switch (GetMonGender(&gPlayerParty[0]))
    {
        case MON_MALE:
            StringCopy(gStringVar3, gText_BirchBoy);
        break;
        case MON_FEMALE:
            StringCopy(gStringVar3, gText_BirchGirl);
        break;
        case MON_GENDERLESS:
            StringCopy(gStringVar3, ((const u8[])_("Unknown")));
        break;
    }
    StringCopy(gRyuStringVar3, gAbilityNames[GetMonAbility(&gPlayerParty[0])]);

}
//FULL_COLOR
void RyuSetUpSaveBlockStuff(void)
{
    gSaveBlock1Ptr->registeredItem = ITEM_WAYSTONE;
}

void Ryu_ClearAquaSFCTrainerFlags(void)
{
    FlagClear(TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_1);
    FlagClear(TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_2);
    FlagClear(TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_5);
    FlagClear(TRAINER_FLAGS_START + TRAINER_SHELLY_2);
    FlagClear(TRAINER_FLAGS_START + TRAINER_GRUNT_WEATHER_INST_4);
    FlagClear(TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_4);
    FlagClear(TRAINER_FLAGS_START + TRAINER_MATT);
}


bool8 hasChampionRibbon(u8 index) {
    return GetMonData(&gPlayerParty[index], MON_DATA_CHAMPION_RIBBON, NULL);
}

/**
 * Return 0 if the player does not have the gift mon,
 * 1-4 if the player has it depending on the evolution stage,
 * and 5 if the player has it and has beaten the elite 4 with it.
 */
int CheckRivalGiftMonStatus(void)
{
    u8 gender = gSaveBlock2Ptr->playerGender;
    u8 i;

    if (gender == MALE)
    {
        for (i = 0; i < CalculatePlayerPartyCount(); i++)
        {
            if ((GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_SNEASEL) && (GetMonData(&gPlayerParty[i], MON_DATA_OT_GENDER) == 1))
                return hasChampionRibbon(i) ? 5 : 1;

            if ((GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_WEAVILE)  && (GetMonData(&gPlayerParty[i], MON_DATA_OT_GENDER) == 1))
                return hasChampionRibbon(i) ? 5 : 2;
        }
    }
    else
    {
        for (i = 0; i < CalculatePlayerPartyCount(); i++)
        {
            if ((GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_SNORUNT) && (GetMonData(&gPlayerParty[i], MON_DATA_OT_GENDER) == 0))
                return hasChampionRibbon(i) ? 5 : 1;

            if ((GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_FROSLASS) && (GetMonData(&gPlayerParty[i], MON_DATA_OT_GENDER) == 0))
                return hasChampionRibbon(i) ? 5 : 2;

            if ((GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_GLALIE) && (GetMonData(&gPlayerParty[i], MON_DATA_OT_GENDER) == 0))
                return hasChampionRibbon(i) ? 5 : 3;
        }
    }
    return 0;
} 

int RyuGetTimeOfDay(void)
{
    u8 hour;
    RtcCalcLocalTime();
    hour = gLocalTime.hours;

    if (hour >= 6 && hour < 10) //6am to 9:59am
        return RTC_TIME_MORNING;

    if (hour >= 10 && hour < 18) // 10am to 5:59pm
        return RTC_TIME_DAY;

    if (hour >= 18 && hour <= 20) // 6pm to 8:59pm
        return RTC_TIME_EVENING;

    //between 9pm and 5:59am
    return RTC_TIME_NIGHT;
}

extern u8 RyuScript_FieldCut[];

bool32 RyuBotanySpecial(void)
{
    ScriptContext1_SetupScript(RyuScript_FieldCut);
    return FALSE;
}

void BotanyCheck(void)
{
    u16 currentMapGroup = VarGet(VAR_TEMP_6);
    u16 tableSize = ARRAY_COUNT(gBotanyRewardTables[currentMapGroup]);
    bool16 isHyperCutting = FlagGet(FLAG_BOTANY_HAS_HYPER_CUTTER);
    VarSet(VAR_TEMP_0, gBotanyRewardTables[currentMapGroup][Random() % tableSize]);
    gSpecialVar_Result = isHyperCutting;
}

void BotanyTreeChop(void)
{
    u16 rewardItem = gBotanyTreeRewards[Random() % (ARRAY_COUNT(gBotanyTreeRewards))];
    VarSet(VAR_TEMP_0, rewardItem);
}

bool8 ScrCmd_trycraftingrecipe(struct ScriptContext *ctx)
{
    u16 recipeNum = VarGet(ScriptReadHalfword(ctx)); //the recipe to try to craft
    u8 i;
    u16 itemId, requiredQuantity, quantityInBag;
    u16 rewardItem = sBotanyRecipeToItemId[recipeNum];

    // 2000 is the magic number for "You do not have enough space for the resulting item"
    if (!CheckBagHasSpace(rewardItem, 1)) {
        VarSet(VAR_TEMP_C, 2000);
        return FALSE;
    }

    for (i = 0; i < NUM_INGREDIENTS_PER_RECIPE; i++) {
        itemId = sBotanyRecipes[recipeNum][i][0];
        if (itemId == ITEM_NONE) // NONE is used as a placeholder for trailing slots, so we can early exit here
            break;
        requiredQuantity = sBotanyRecipes[recipeNum][i][1];
        quantityInBag = GetItemQuantity(itemId);
        if (quantityInBag < requiredQuantity) {
            // 4000 is the magic number for “you don’t have the ingredient”
            VarSet(VAR_TEMP_C, 4000);
            if (quantityInBag > 0)
                // 8000 is the magic number for “you have at least one but need more of that ingredient”
                VarSet(VAR_TEMP_C, 8000);

            return FALSE;
        }
    }

    for (i = 0; i < NUM_INGREDIENTS_PER_RECIPE; i++) {
        itemId = sBotanyRecipes[recipeNum][i][0];
        if (itemId == ITEM_NONE)
            break;
        requiredQuantity = sBotanyRecipes[recipeNum][i][1];
        RemoveBagItem(itemId, requiredQuantity);
    }
    VarSet(VAR_TEMP_C, rewardItem);

    return FALSE;
}

int RyuGetCurrentMapsec(void)
{
    return gMapHeader.regionMapSectionId;
}

void RyuBufferNumApricornsForMenu(void)
{
    u8 i;
    u16 total1 = 0;
    u16 total2 = 0;
    u16 total3 = 0;
    u16 total4 = 0;
    u16 total5 = 0;
    u16 total6 = 0;
    u16 total7 = 0;

    for (i = 0; i < gBagPockets[ITEMS_POCKET].capacity; i++)
    {
        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_RED_APRICORN)
        {
            total1 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_BLUE_APRICORN)
        {
            total2 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_YELLOW_APRICORN)
        {
            total3 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_GREEN_APRICORN)
        {
            total4 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_PINK_APRICORN)
        {
            total5 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_WHITE_APRICORN)
        {
            total6 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_BLACK_APRICORN)
        {
            total7 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }
    }

    ConvertIntToDecimalStringN(gStringVar1, total1, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, total2, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, total3, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar1, total4, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar2, total5, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar3, total6, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar4, total7, STR_CONV_MODE_LEFT_ALIGN, 3);
}


void RyuHolidayGiftMonSetData(void)
{
    u8 slot = VarGet(VAR_TEMP_E);
    u8 iv = 31;
    u8 ability = 2;
    u8 ribbon[1] = {TRUE};

    SetMonData(&gPlayerParty[slot], MON_DATA_ATK_IV, &iv);
    SetMonData(&gPlayerParty[slot], MON_DATA_DEF_IV, &iv);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_IV, &iv);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_IV, &iv);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPEED_IV, &iv);
    SetMonData(&gPlayerParty[slot], MON_DATA_HP_IV, &iv);

    SetMonData(&gPlayerParty[slot], MON_DATA_BOSS_STATUS, &ribbon);
    SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);

}

void RyuCheckForDejavuAch(void)
{
    u8 questAch = 0;

    if (CheckAchievement(ACH_ETERNAL_DAMNATION) == 1)
        questAch++;
    
    if (CheckAchievement(ACH_HUNTING_TRIP) == 1)
        questAch++;

    if (CheckAchievement(ACH_THROUGH_THE_FIRE) == 1)
        questAch++;

    if (CheckAchievement(ACH_HEATED_ARGUMENT) == 1)
        questAch++;

    if (CheckAchievement(ACH_EYE_OF_STORM) == 1)
        questAch++;

    if (CheckAchievement(ACH_WATER_LOGGED) == 1)
        questAch++;

    if (CheckAchievement(ACH_ASTRONOMICAL) == 1)
        questAch++;

    if (CheckAchievement(ACH_CORPORATE_SHILL) == 1)
        questAch++;

    if(questAch >= 8)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

void SetSprintBoost(void)
{
    SetAPFlag(AP_SPRINT_BOOST);
}


int RyuGetTotalCaughtMons(void)
{
    return GetNationalPokedexCount(FLAG_GET_CAUGHT);
}

void TryGiveLeetAch(void)
{
    if ((gSaveBlock2Ptr->playTimeHours <= 13) && (gSaveBlock2Ptr->playTimeMinutes <= 37) && FlagGet(FLAG_SYS_GAME_CLEAR))
        if (CheckAchievement(ACH_1337) == FALSE)
            GiveAchievement(ACH_1337);
}

void TryGiveFitnessGuruAch(void)
{
    u8 i, k;
    u8 maxEvStat = 0;

    for (k = 0; k < CalculatePlayerPartyCount(); k++)
    {
        for (i = 0; i < 6; i++)
        {
            if (GetMonData(&gPlayerParty[k], MON_DATA_HP_EV + i) >= 252)
                maxEvStat++;
        }
    }
    
    if ((maxEvStat > 0) && (CheckAchievement(ACH_FITNESS_GURU) == FALSE))
        GiveAchievement(ACH_FITNESS_GURU);
}

void RyuClearAlchemyEffect(void)
{
    gSaveBlock2Ptr->alchemyCharges = 0;
    gSaveBlock2Ptr->alchemyEffect = 0;
    gSaveBlock2Ptr->hasAlchemyEffectActive = 0;
    if (FlagGet(FLAG_RYU_VERBOSE_MODE) == TRUE)
        DebugPrint((const u8[]) _("Cleared Alchemy Effects."), 0);
}

void RyuSetupAlchemicalRepel(void) //There's no need to assume there's an alchemy effect active with this.
{                                  //The idea being, player created an alchemical repel that's more potent. Won't hurt to stack it with other things.
    if (gSaveBlock2Ptr->alchemyEffect == ALCHEMY_EFFECT_REPEL_T1)
        VarSet(VAR_REPEL_STEP_COUNT, 500);
    if (gSaveBlock2Ptr->alchemyEffect == ALCHEMY_EFFECT_REPEL_T2)
        VarSet(VAR_REPEL_STEP_COUNT, 1000);
    
    PlaySE(SE_TU_SAA);
    RyuClearAlchemyEffect();
}

const u16 gRyuAlchemyItems[] = {
    ITEM_STARDUST,
    ITEM_FRESH_WATER,
    ITEM_TONIC_WATER,
    ITEM_MINERAL_WATER,
    ITEM_RARE_CANDY,
    ITEM_GOLD_NUGGET,
};

u32 RyuGetAlchemyItemId(u32 recipeId)
{
    return gRyuAlchemyItems[recipeId - NUM_ALCHEMY_EFFECTS];
}


u16 RyuAlchemy_TryCraftingItem(void)
{
    u8 recipe = (VarGet(VAR_TEMP_A));
    u8 levelReq = 0;
    u8 currentLevel = (VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL));
    u16 currentExp = (VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP));
    u8 metal = 0;
    u16 item1 = 0;
    u16 item2 = 0;
    u16 item3 = 0;
    u16 metalAmountRequired = 0;
    u16 playerMetalAmt = 0;

    //fill vars
    item1 = gAlchemyRecipes[recipe].ingredients[0].itemId;
    item2 = gAlchemyRecipes[recipe].ingredients[1].itemId;
    item3 = gAlchemyRecipes[recipe].ingredients[2].itemId;
    metal = gAlchemyRecipes[recipe].metal;
    metalAmountRequired = gAlchemyRecipes[recipe].metalDustAmt;

    if (gAlchemyRecipes[recipe].requiredLevel > currentLevel)
        return 2000; //Level requirement not met for recipe
    
    if (CheckBagHasItem(item1, (gAlchemyRecipes[recipe].ingredients[0].quantity)) == FALSE)
        return 4100; //Player doesn't have enough of ingredient 1

    if (CheckBagHasItem(item2, (gAlchemyRecipes[recipe].ingredients[1].quantity)) == FALSE)
        return 4200; //Player doesn't have enough of ingredient 2

    if (CheckBagHasItem(item3, (gAlchemyRecipes[recipe].ingredients[2].quantity)) == FALSE)
        return 4300; //Player doesn't have enough of ingredient 3

    switch (metal)
    {
        case 0:
        {
            playerMetalAmt = (VarGet(VAR_RYU_ALCHEMY_COPPER));
            if (playerMetalAmt < metalAmountRequired)
                return 1000; //Player doesn't have enough metal dust for this recipe

            VarSet(VAR_RYU_ALCHEMY_COPPER, (VarGet(VAR_RYU_ALCHEMY_COPPER) - metalAmountRequired));
            break;
        }
        case 1:
        {
            playerMetalAmt = (VarGet(VAR_RYU_ALCHEMY_SILVER));
            if (playerMetalAmt < metalAmountRequired)
                    return 1000; //Player doesn't have enough metal dust for this recipe

            VarSet(VAR_RYU_ALCHEMY_SILVER, (VarGet(VAR_RYU_ALCHEMY_SILVER) - metalAmountRequired));
            break;
        }
        case 2:
        {
            playerMetalAmt = (VarGet(VAR_RYU_ALCHEMY_GOLD));
            if (playerMetalAmt < metalAmountRequired)
                    return 1000; //Player doesn't have enough metal dust for this recipe

            VarSet(VAR_RYU_ALCHEMY_GOLD, (VarGet(VAR_RYU_ALCHEMY_GOLD) - metalAmountRequired));
            break;
        }
    }

    RemoveBagItem(item1, (gAlchemyRecipes[recipe].ingredients[0].quantity));
    RemoveBagItem(item2, (gAlchemyRecipes[recipe].ingredients[1].quantity));
    RemoveBagItem(item3, (gAlchemyRecipes[recipe].ingredients[2].quantity));

    if (recipe < ALCHEMY_ITEM_RECIPE_STARDUST) //don't set an effect if the crafting result is an item instead of effect.
    {
        gSaveBlock2Ptr->alchemyEffect = recipe;
        gSaveBlock2Ptr->alchemyCharges = gAlchemyRecipes[recipe].givenCharges;
        gSaveBlock2Ptr->hasAlchemyEffectActive = TRUE;
    }
    StringCopy(gStringVar1, gRyuAlchemyEffectItemToStringTable[(recipe)]);
    ConvertIntToDecimalStringN(gStringVar2, gAlchemyRecipes[recipe].givenCharges, STR_CONV_MODE_LEFT_ALIGN, 4);
    currentExp += gAlchemyRecipes[recipe].expGiven;
    ConvertIntToDecimalStringN(gStringVar3, gAlchemyRecipes[recipe].expGiven, STR_CONV_MODE_LEFT_ALIGN, 3);
    VarSet(VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP, currentExp);
    DebugPrint((const u8[])_("recipe:"), 1, recipe);
    if (recipe > ALCHEMY_EFFECT_MASTER_CAPTURE)
        return RyuGetAlchemyItemId(recipe - 2);
    else
        return recipe;
}

void RyuDebug_CheckAlchemyStatus(void)
{
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->alchemyEffect, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock2Ptr->hasAlchemyEffectActive, STR_CONV_MODE_LEFT_ALIGN, 1);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock2Ptr->alchemyCharges, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(gRyuStringVar1, VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL), STR_CONV_MODE_LEFT_ALIGN, 1);
    ConvertIntToDecimalStringN(gRyuStringVar2, VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP), STR_CONV_MODE_LEFT_ALIGN, 5);
}


int RyuGetPartnerCount(void)//also gives partner based achievements.
{
    u16 partners = 0;

    if ((FlagGet(FLAG_RYU_DS_DAWN_PARTNERS) == 1) || (FlagGet(FLAG_RYU_DS_BRENDAN_PARTNERS) == 1))
    {
        partners++;
        GiveAchievement(ACH_CHILDHOOD_FRIEND);
    }

    if (FlagGet(FLAG_RYU_DS_LANETTE_PARTNERS) == 1)
    {
        partners++;
        GiveAchievement(ACH_NERD_LOVE);
    }

    if (FlagGet(FLAG_RYU_DS_LEAF_PARTNERS) == 1)
    {
        partners++;
        GiveAchievement(ACH_SILENT_STRONG_TYPE);
    }

    if (FlagGet(FLAG_RYU_DS_SHELLY_PARTNERS) == 1)
    {
        partners++;
        GiveAchievement(ACH_WET_N_WILD);
    }

    if (FlagGet(FLAG_RYU_DS_LUCY_PARTNERS) == 1)
    {
        partners++;
        GiveAchievement(ACH_SERPENTINE);
    }

    if (FlagGet(FLAG_RYU_DS_COURTNEY_PARTNERS) == 1)
    {
        partners++;
        GiveAchievement(ACH_FIERY_PASSION);
    }

    if (FlagGet(FLAG_RYU_DS_JOY_PARTNERS) == 1)
    {
        partners++;
        GiveAchievement(ACH_FWB);
    }

    if (FlagGet(FLAG_RYU_DS_MAY_PARTNERS) == 1) //may doesn't count for the true ending.
    {
        partners++;
        GiveAchievement(ACH_LOST_GIRL);
    }

    if ((partners >= 5) && (FlagGet(FLAG_RYU_FIRST_GAME_CLEAR) == 1))
    {
        GiveAchievement(ACH_TRUE_ENDING);
        VarSet(VAR_RYU_QUESTS_FINISHED, (VarGet(VAR_RYU_QUESTS_FINISHED) + 1));
    }

    VarSet(VAR_RYU_PARTNER_COUNT, partners);

    return partners;
}

extern const u8 *gOriginalNPCScript;
extern u8 RyuOutcastsSpecialQuestIntro[];

void RyuSummonOriginalNPCscript(void)
{
    const u8 *script = NULL;
    script = GetRamScript(gSpecialVar_LastTalked, gOriginalNPCScript);
    ScriptContext1_SetupScript(script);
}

void RyuBufferSkillLevels(void)
{
    u16 alchExp = (VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP));
    u16 alchLvl = (VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL));
    u16 botExp = (VarGet(VAR_RYU_PLAYER_BOTANY_SKILL_EXP));
    u16 botLvl = (VarGet(VAR_RYU_PLAYER_BOTANY_SKILL));
    u16 minExp = (VarGet(VAR_RYU_PLAYER_MINING_SKILL_EXP));
    u16 minLvl = (VarGet(VAR_RYU_PLAYER_MINING_SKILL));

    ConvertIntToDecimalStringN(gStringVar1, alchExp, STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gStringVar2, alchLvl, STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gStringVar3, botExp, STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gRyuStringVar1, botLvl, STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gRyuStringVar2, minExp, STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gRyuStringVar3, minLvl, STR_CONV_MODE_LEFT_ALIGN, 5);
}

int RyuCheckIfWaystoneShouldBeDisabled(void) //checks various things in the game to decide if waystone should be disabled or not.
{
    u16 currentGroup = (gSaveBlock1Ptr->location.mapGroup);
    u16 currentMap = (gSaveBlock1Ptr->location.mapNum);
    
    gSpecialVar_Result = FALSE;

    if(currentGroup == 16) //player is doing the elite four
        if(currentMap < 12)
            return 10;

    if (FlagGet(FLAG_RYU_TC_ENTERED) == 1)//player is using training center
        return 20;

    if (VarGet(VAR_RYU_QUEST_MAGMA) > 119 && VarGet(VAR_RYU_QUEST_MAGMA) < 130) //player is doing blaise's granite cave event
        return 30;

    if (VarGet(VAR_RYU_QUEST_MAGMA) == 315)// player is working with courtney to clear out aqua in the magma hideout.
        return 40;

    if (VarGet(VAR_RYU_QUEST_DEVON_SCIENTIST) == 106) //player is doing magma event in space center.
        return 50;

    if (VarGet(VAR_RYU_FOLLOWER_ID) == OBJ_EVENT_GFX_HEX_MANIAC)//player is doing the Outcasts faction quest
        return 60;

    if (VarGet(VAR_RYU_QUEST_MAGMA) == 230)//player is doing the oldale heist event
        return 70;
    
    if (VarGet(VAR_RYU_QUEST_DEVON_CORPORATE) > 29 && VarGet(VAR_RYU_QUEST_DEVON_CORPORATE) < 60)//player is interrogating devon employees
        return 80;
    
    if (VarGet(VAR_RYU_QUEST_MAGMA) == 555)//player is fighting groudon
        return 90;
    
    if (VarGet(VAR_TRAINER_HILL_IS_ACTIVE) == 1)//player is doing trainer hill
        return 100;

    if (VarGet(VAR_RYU_QUEST_NURSE) == 2 || VarGet(VAR_RYU_QUEST_NURSE) == 4 || VarGet(VAR_RYU_QUEST_NURSE) == 6)//player is escorting nurse
        return 110;
    
    if (FlagGet(FLAG_RYU_LIMBO) == 1)//Player is in Limbo after failing challenge or hardcore.
        return 120;
    
    if (VarGet(VAR_RYU_QUEST_MAY) == 50) //Player is investigating wally's house with May
        return 130;
    
    if ((FlagGet(FLAG_RYU_UNDERWORLD) == TRUE) && (CheckAchievement(ACH_THE_PHOENIX) == FALSE))
        return 140;

    if ((VarGet(VAR_RYU_QUEST_LUCY) == 80) || (VarGet(VAR_RYU_QUEST_LUCY) == 65) || (VarGet(VAR_RYU_QUEST_LUCY) == 40))
        return 150;

    return 0;
}

extern u8 TrySavingData(u8 saveType);
void RyuForceSaveTheGame(void)
{
    TrySavingData(0);
}

void RyuMaxFactionStanding(void)
{
    u8 i;
    for(i = 0; i < FACTION_OTHERS; i++)
        gSaveBlock2Ptr->gNPCTrainerFactionRelations[i] = 200;
}

void SetAlchemyEffect(void)
{
    gSaveBlock2Ptr->alchemyEffect = ALCHEMY_EFFECT_MASTER_CAPTURE;
    gSaveBlock2Ptr->alchemyCharges = 1;
    gSaveBlock2Ptr->hasAlchemyEffectActive = TRUE;
}

u16 RyuCheckMoney(void)
{
    u16 toCompare = (VarGet(VAR_TEMP_9));
    if (IsEnoughMoney(&gSaveBlock1Ptr->money, toCompare))
        return TRUE;
    
    return FALSE;
}

void giveContestMon(void)
{
    u8 slot = CalculatePlayerPartyCount();
    u8 stat = 255;
    u16 moves[4] = {
        MOVE_CALM_MIND,
        MOVE_PSYCHO_BOOST,
        MOVE_DESTINY_BOND,
        MOVE_FUTURE_SIGHT
    };
    
    CreateMonWithNature(&gPlayerParty[slot], SPECIES_MEGA_RAYQUAZA, 100, 31, NATURE_ADAMANT);
    SetMonData(&gPlayerParty[slot], MON_DATA_SMART, &stat);
    SetMonData(&gPlayerParty[slot], MON_DATA_TOUGH, &stat);
    SetMonData(&gPlayerParty[slot], MON_DATA_COOL, &stat);
    SetMonData(&gPlayerParty[slot], MON_DATA_SMART, &stat);
    SetMonData(&gPlayerParty[slot], MON_DATA_CUTE, &stat);
    SetMonData(&gPlayerParty[slot], MON_DATA_BEAUTY, &stat);

    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE1, &moves[0]);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE2, &moves[1]);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE3, &moves[2]);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE4, &moves[3]);
    SetMonData(&gPlayerParty[slot], MON_DATA_SHEEN, &stat);
    CalculateMonStats(&gPlayerParty[slot]);

}


void RyuGiveDevMon(void)
{
    u8 nature = VarGet(VAR_TEMP_A);
    u16 species = VarGet(VAR_TEMP_B);
    u8 ability = VarGet(VAR_TEMP_C);
    u8 gender = VarGet(VAR_TEMP_D);
    u16 move1 = VarGet(VAR_TEMP_1);
    u16 move2 = VarGet(VAR_TEMP_2);
    u16 move3 = VarGet(VAR_TEMP_3);
    u16 move4 = VarGet(VAR_TEMP_4);
    u8 slot = (CalculatePlayerPartyCount());
    u16 item = (VarGet(VAR_TEMP_E));
    u16 i = 0;
    u8 ev = 252;
    u8 ppmax = 255;
    u8 iv = 31;
    u8 lv = 250;//TRUE_MAX_LEVEL;
    u8 what = 0;
    u8 ribbon = TRUE;


    CreateMonWithGenderNatureLetter(&gPlayerParty[slot], species, lv, iv, gender, nature, what); 
    
    CalculateMonStats(&gPlayerParty[slot]);

    SetMonData(&gPlayerParty[slot], MON_DATA_PP_BONUSES, &ppmax); //sets all pp to max bonus

    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE1, &move1);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE2, &move2);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE3, &move3);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE4, &move4);

    SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);

    SetMonData(&gPlayerParty[slot], MON_DATA_HP_EV, &ev);
    SetMonData(&gPlayerParty[slot], MON_DATA_ATK_EV, &ev);
    SetMonData(&gPlayerParty[slot], MON_DATA_DEF_EV, &ev);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPEED_EV, &ev);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_EV, &ev);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_EV, &ev);

    SetMonData(&gPlayerParty[slot], MON_DATA_BOSS_STATUS, &ribbon); //make it a boss because why not
    SetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM, &item);
    CalculateMonStats(&gPlayerParty[slot]);
}

bool32 ScrCmd_bufferdynamicmulti(struct ScriptContext *ctx)
{
    const u8 *ptr1 = (const u8 *)ScriptReadWord(ctx);
    const u8 *ptr2 = (const u8 *)ScriptReadWord(ctx);
    const u8 *ptr3 = (const u8 *)ScriptReadWord(ctx);
    const u8 *ptr4 = (const u8 *)ScriptReadWord(ctx);
    const u8 *ptr5 = (const u8 *)ScriptReadWord(ctx);
    const u8 *ptr6 = (const u8 *)ScriptReadWord(ctx);
    StringCopy(gStringVar1, ptr1);
    StringCopy(gStringVar2, ptr2);
    StringCopy(gStringVar3, ptr3);
    StringCopy(gRyuStringVar1, ptr4);
    StringCopy(gRyuStringVar2, ptr5);
    StringCopy(gRyuStringVar3, ptr6);
    return FALSE;
}

void RyuExpDriveInternalOperation(u8 mode, u32 value)
{
    u32 current = GetGameStat(GAME_STAT_EXP_DRIVE);

    if (mode == EXP_DRIVE_MODE_ADD)
    {
        if ((current + value) >= EXP_DRIVE_MAX)
            SetGameStat(GAME_STAT_EXP_DRIVE, EXP_DRIVE_MAX);
        else
            SetGameStat(GAME_STAT_EXP_DRIVE, (current + value));
    }
    else
    {
        if (value > current)
            SetGameStat(GAME_STAT_EXP_DRIVE, 0);
        else
            SetGameStat(GAME_STAT_EXP_DRIVE, (current - value));
    }

}

void RyuExpDriveOperation(void)
{
    u16 mode = (VarGet(VAR_TEMP_2));
    u16 scriptChangeAmount = (VarGet(VAR_TEMP_3));
    u32 tempValue = 0;

    if (mode == EXP_DRIVE_MODE_RESET)
        SetGameStat(GAME_STAT_EXP_DRIVE, 0);

    if ((mode == EXP_DRIVE_MODE_ADD) || (mode == EXP_DRIVE_MODE_SUBTRACT))
        RyuExpDriveInternalOperation(mode, scriptChangeAmount);

    if (mode == EXP_DRIVE_MODE_BUFFER)
        ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_EXP_DRIVE), STR_CONV_MODE_LEFT_ALIGN, 8);
    
    if (mode == EXP_DRIVE_MODE_USE_ON_MON)
        {
            u8 MonSlotData = (VarGet(VAR_TEMP_F));
            s32 MonCurrExp = GetMonData(&gPlayerParty[MonSlotData], MON_DATA_EXP);
            u32 newMonExp = (MonCurrExp + (GetGameStat(GAME_STAT_EXP_DRIVE)));

            SetMonData(&gPlayerParty[MonSlotData], MON_DATA_EXP, &newMonExp);
            ApplyDaycareExperience(&gPlayerParty[MonSlotData]);
            CalculateMonStats(&gPlayerParty[MonSlotData]);
            ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_EXP_DRIVE), STR_CONV_MODE_LEFT_ALIGN, 8);
            SetGameStat(GAME_STAT_EXP_DRIVE, 0);

            GetMonData(&gPlayerParty[MonSlotData], MON_DATA_NICKNAME, gStringVar2);
            StringGetEnd10(gStringVar2);

        }

    if (mode == EXP_DRIVE_MODE_SET_DEV_AMOUNT)
    {
        SetGameStat(GAME_STAT_EXP_DRIVE, EXP_DRIVE_MAX);
    }

}

void RyuForceUpdateTime(void)
{
    u16 hours = (VarGet(VAR_TEMP_1));
    u16 minutes = (VarGet(VAR_TEMP_2));

    RtcInitLocalTimeOffset(hours, minutes);
}

static const u8 gRyuString_CommonItem[] = _("a Common ");
static const u8 gRyuString_UncommonItem[] = _("an {COLOR LIGHT_BLUE}Uncommon{COLOR DARK_GREY} ");
static const u8 gRyuString_RareItem[] = _("a {COLOR LIGHT_RED}Rare{COLOR DARK_GREY} ");
static const u8 gRyuString_SuperRareItem[] = _("a {COLOR LIGHT_GREEN}Very Rare{COLOR DARK_GREY} ");

void RyuNotifyPickupItemBufferValues (void)
{
    CopyItemName(VarGet(VAR_RYU_LAST_PICKUP_ITEM), gStringVar2);
    GetMonData(&gPlayerParty[VarGet(VAR_RYU_LAST_PICKUP_SLOT)], MON_DATA_NICKNAME, gStringVar1);
    StringGetEnd10(gStringVar1);
    switch (VarGet(VAR_RYU_LAST_PICKUP_RARITY))
    {
        case 0:
            StringCopy(gStringVar4, gRyuString_CommonItem);
            break;
        case 1:
            StringCopy(gStringVar4, gRyuString_UncommonItem);
            break;
        case 2:
            StringCopy(gStringVar4, gRyuString_RareItem);
            break;
        case 3:
            StringCopy(gStringVar4, gRyuString_SuperRareItem);
            break;
    }
    StringExpandPlaceholders(gStringVar3, gStringVar4);
}

bool32 RyuCheckFor100Lv(void) //player can only switch to 100 cap if party is at or below.
{
    u8 k;
    for (k = 0; k < 6; k++)
    {
        if (GetMonData(&gPlayerParty[k], MON_DATA_LEVEL) > VANILLA_MAX_LEVEL)
            return FALSE;
    }
    return TRUE;
}

void RyuLegendaryDoBossRoll(void)
{
    u32 randomvalue = (Random() % 99);
    randomvalue = 0;
    if (CheckAPFlag(AP_ALPHA_AURA) == TRUE)
    {
        if (randomvalue < 11)
            FlagSet(FLAG_RYU_BOSS_WILD);
        else
            FlagClear(FLAG_RYU_BOSS_WILD);
    }
    else 
    {
        if (randomvalue == 0)
            FlagSet(FLAG_RYU_BOSS_WILD);
        else
            FlagClear(FLAG_RYU_BOSS_WILD);
    }
}

bool32 CheckIfSelectedSlotIsValid(void)
{
    u8 selection = VarGet(VAR_RESULT);
    u8 partySize = CalculatePlayerPartyCount();
    if (selection > (partySize - 1))
        return FALSE;

    return TRUE;
}

void RDB_DevModeGiveMoney(void)
{
    u32 Amt = gSpecialVar_32bit;
    AddMoney(&gSaveBlock1Ptr->money, Amt);
    ConvertIntToDecimalStringN(gStringVar1, Amt, STR_CONV_MODE_LEFT_ALIGN, 9);
}

void RyuGiveHolidayModdedMon(void)
{   u16 slot = gSpecialVar_0x8002;
    u16 species = gSpecialVar_0x8005;
    u16 level = 50;
    u16 fixedIv = 31;
    u16 g69 = 69;
    u16 nature = gSpecialVar_0x8001;
    u16 loc = MAPSEC_AETHER_PARADISE;
    u16 itm = ITEM_ANCIENT_COIN;
    u16 tru = TRUE;
    bool16 isBoss = TRUE;
    CreateMonWithNature(&gPlayerParty[slot], species, level, fixedIv, nature);
    SetMonData(&gPlayerParty[slot], MON_DATA_BOSS_STATUS, &isBoss);
    SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
    SetMonData(&gPlayerParty[slot], MON_DATA_OT_NAME, ((const u8[])_("Ryu")));
    SetMonData(&gPlayerParty[slot], MON_DATA_OT_GENDER, MALE);
    SetMonData(&gPlayerParty[slot], MON_DATA_MET_LEVEL, &g69);
    SetMonData(&gPlayerParty[slot], MON_DATA_MET_LOCATION, &loc);
    SetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM, &itm);
    SetMonData(&gPlayerParty[slot], MON_DATA_FATEFUL_ENCOUNTER, &tru);
    CalculateMonStats(&gPlayerParty[slot]);
}

void RyuSetupRandomForE4(void)
{
    u8 r1, r2, r3, r4;
    r1 = (Random() % 2);
    r2 = (Random() % 2);
    r3 = (Random() % 2);
    r4 = (Random() % 2);
    VarSet(VAR_RYU_E41, r1);
    VarSet(VAR_RYU_E42, r2);
    VarSet(VAR_RYU_E43, r3);
    VarSet(VAR_RYU_E44, r4);
    if (FlagGet(FLAG_RYU_VERBOSE_MODE) == TRUE)
    {
            ConvertIntToDecimalStringN(gStringVar1, r1, 0, 1);
            ConvertIntToDecimalStringN(gStringVar2, r2, 0, 1);
            ConvertIntToDecimalStringN(gRyuStringVar1, r3, 0, 1);
            ConvertIntToDecimalStringN(gRyuStringVar2, r4, 0, 1);
            StringCopy(gRyuStringVar3, gStringVar1);
            StringAppend(gRyuStringVar3, gText_Space2);
            StringAppend(gRyuStringVar3, gStringVar2);
            StringAppend(gRyuStringVar3, gText_Space2);
            StringAppend(gRyuStringVar3, gRyuStringVar1);
            StringAppend(gRyuStringVar3, gText_Space2);
            StringAppend(gRyuStringVar3, gRyuStringVar2);
            DebugPrint((const u8[]) _("Rolled for elite four.({RYU_STR_3})"), 0);
    }

    if (VarGet(VAR_RYU_SPECIAL_CHALLENGE_STATE) == 100) //special challenge active, always give rematch 2 parties on rematch.
        {
            VarSet(VAR_RYU_E41, 1);
            VarSet(VAR_RYU_E42, 1);
            VarSet(VAR_RYU_E43, 1);
            VarSet(VAR_RYU_E44, 1);
        }
}

void RyuCheckIfInWallysHouse (void)
{
    if ((gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PETALBURG_CITY_WALLYS_HOUSE)) && (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PETALBURG_CITY_WALLYS_HOUSE)))
    {
        gSpecialVar_Result = TRUE;
        return;
    }
    gSpecialVar_Result = FALSE;
    return;
}

void RyuMaxHappiness (void)
{
    u8 max = 255;
    SetMonData(&gPlayerParty[0], MON_DATA_FRIENDSHIP, &max);
}

void RyuGetMayDailyReward (void) //generates a random berry and quantity for may's daily reward for neutral and good ends.
{
    gSpecialVar_0x8004 = ((Random() % 66) + 144);
    gSpecialVar_0x8005 = (Random() % 3);
}

const u8 sText_SpeedOptionsUsed[] = _(" bs  / 1c  / its / da \n");
const u8 sText_one[] = _("  {COLOR LIGHT_RED}{SHADOW RED}y{COLOR DARK_GREY}{SHADOW LIGHT_GREY}   ");
const u8 sText_zero[] = _("  {COLOR LIGHT_GREEN}{SHADOW GREEN}n{COLOR DARK_GREY}{SHADOW LIGHT_GREY}   ");
const u8 sText_slash[] = _("/");
void RyuCheckSpecialChallengeStatus (void)
{
    bool32 UsedBarSpeed = (FlagGet(FLAG_RYU_CHANGED_BAR_SPEED));
    bool32 Used100Cap = (FlagGet(FLAG_RYU_USED_100_CAP));
    bool32 UsedInstantText = (FlagGet(FLAG_RYU_USED_INSTANT_TEXT));
    bool32 UsedInstantTransition = (FlagGet(FLAG_RYU_USED_INSTANT_TRANSITION));
    bool32 DisabledAnims = (FlagGet(FLAG_RYU_DISABLED_ANIMS));
    StringCopy(gStringVar1, sText_SpeedOptionsUsed);

    if (UsedBarSpeed)
        StringAppend(gStringVar1, sText_one);
    else
        StringAppend(gStringVar1, sText_zero);
    
    StringAppend(gStringVar1, sText_slash);

    if (Used100Cap)
        StringAppend(gStringVar1, sText_one);
    else
        StringAppend(gStringVar1, sText_zero);

    StringAppend(gStringVar1, sText_slash);

    if (UsedInstantTransition)
        StringAppend(gStringVar1, sText_one);
    else
        StringAppend(gStringVar1, sText_zero);

    StringAppend(gStringVar1, sText_slash);

    if (DisabledAnims)
        StringAppend(gStringVar1, sText_one);
    else
        StringAppend(gStringVar1, sText_zero);
}

void RyuSavePlayTimeChallenge (void)
{
    u16 hours = (gSaveBlock2Ptr->playTimeHours);
    u16 minutes = (gSaveBlock2Ptr->playTimeMinutes);
    u16 seconds = (gSaveBlock2Ptr->playTimeSeconds);
    
    if (hours > 60)
        hours = 60;
    
    if (minutes > 60)
        minutes = 60;
    
    if (seconds > 60)
        seconds = 60;

    gSaveBlock2Ptr->challengeTimeBlockHours = hours;
    gSaveBlock2Ptr->challengeTimeBlockMinutes = minutes;
    gSaveBlock2Ptr->challengeTimeBlockSeconds = seconds;
}

void RyuSaveChallengeStartTime (void)
{
    u16 hours = (gSaveBlock2Ptr->playTimeHours);
    u16 minutes = (gSaveBlock2Ptr->playTimeMinutes);

    gSaveBlock2Ptr->challengeTimeBlockStartHours = hours;
    gSaveBlock2Ptr->challengeTimeBlockStartMinutes = minutes;
}

void RyuLoadPlayTimeChallenge (void)
{
    u16 hours = gSaveBlock2Ptr->challengeTimeBlockHours;
    u16 minutes = gSaveBlock2Ptr->challengeTimeBlockMinutes;
    u16 seconds = gSaveBlock2Ptr->challengeTimeBlockSeconds;
    u16 startHours = gSaveBlock2Ptr->challengeTimeBlockStartHours;
    u16 startMinutes = gSaveBlock2Ptr->challengeTimeBlockStartMinutes;
    u16 hourDifference = hours - startHours;
    u16 minuteDifference = minutes - startMinutes;
    u16 challengeMinutes = 0;
    hourDifference *= 60;
    challengeMinutes = hourDifference + minuteDifference;


    ConvertIntToDecimalStringN(gRyuStringVar1, hours, STR_CONV_MODE_LEADING_ZEROS, 2);    
    ConvertIntToDecimalStringN(gRyuStringVar2, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);    
    ConvertIntToDecimalStringN(gRyuStringVar3, seconds, STR_CONV_MODE_LEADING_ZEROS, 2);
    ConvertIntToDecimalStringN(gRyuStringVar4, challengeMinutes, STR_CONV_MODE_LEFT_ALIGN, 4);
}

const u8 sText_CurrentPT[] = _("Current exact play time (HH:MM:SS:FF)\n");
extern const u8 sText_Colon[];
void RyuBufferLongPlayTimeString (void)
{
    u16 hours = gSaveBlock2Ptr->playTimeHours;
    u16 minutes = gSaveBlock2Ptr->playTimeMinutes;
    u16 seconds = gSaveBlock2Ptr->playTimeSeconds;
    u16 frames = gSaveBlock2Ptr->playTimeVBlanks;

    ConvertIntToDecimalStringN(gRyuStringVar1, hours, STR_CONV_MODE_LEFT_ALIGN, 3);    
    ConvertIntToDecimalStringN(gRyuStringVar2, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);    
    ConvertIntToDecimalStringN(gRyuStringVar3, seconds, STR_CONV_MODE_LEADING_ZEROS, 2);    
    ConvertIntToDecimalStringN(gRyuStringVar4, frames, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringCopy(gStringVar1, sText_CurrentPT);    
    StringAppend(gStringVar1, gRyuStringVar1);    
    StringAppend(gStringVar1, sText_Colon);    
    StringAppend(gStringVar1, gRyuStringVar2);
    StringAppend(gStringVar1, sText_Colon);     
    StringAppend(gStringVar1, gRyuStringVar3);
    StringAppend(gStringVar1, sText_Colon);     
    StringAppend(gStringVar1, gRyuStringVar4);    
}

void RyuToggleBossStatus (void)
{
    u8 slot = gSpecialVar_0x8001;
    u8 tru = 1;
    u8 fals = 0;

    if (GetMonData(&gPlayerParty[slot], MON_DATA_BOSS_STATUS) == TRUE)
        SetMonData(&gPlayerParty[slot], MON_DATA_BOSS_STATUS, &fals);
    else
        SetMonData(&gPlayerParty[slot], MON_DATA_BOSS_STATUS, &tru);
}

void RyuCalcPartyStats (void)
{
    u32 i;

    for (i = 0;i < PARTY_SIZE;i++)
        CalculateMonStats(&gPlayerParty[i]);
}

const u8 sRepelNotifyMsg[] = _("Repel Used. {STR_VAR_1}% reduction for {STR_VAR_2} steps.");
void RyuSetUpRepelNotify (void)
{
    int cmax = sWildRange[CountBadges()][1];
    int cmin = sWildRange[CountBadges()][0];
    int slot1level = (GetMonData(&gPlayerParty[0], MON_DATA_LEVEL));
    int percent = 0;


    percent = ((slot1level - cmin) * 100) / (cmax - cmin);
    if (percent > 100)
        percent = 100;
    
    ConvertIntToDecimalStringN(gStringVar1, percent, STR_CONV_MODE_LEFT_ALIGN, 4);
    ConvertIntToDecimalStringN(gStringVar2, VarGet(VAR_REPEL_STEP_COUNT), STR_CONV_MODE_LEFT_ALIGN, 4);
    QueueNotification(sRepelNotifyMsg, NOTIFY_GENERAL, 60);
}

const u8 sTemporaryDebugText[] = _("Testing Printing");

#define tFrames data[0]
#define tScriptDBWindowData data[1]

void RyuScriptDebugPrintTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tFrames < 60)
    {
        tFrames++;
    }
    else
    {
        ClearStdWindowAndFrameToTransparent(tScriptDBWindowData, TRUE);
        RemoveWindow(tScriptDBWindowData);
        DestroyTask(taskId);
    }
}

bool8 ScrCmd_debugprint(struct ScriptContext *ctx) //this will still only print a single string from script. no variable support.
{
    unsigned taskId;
    unsigned tDebugWindow;
    struct WindowTemplate template;

    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];

    StringExpandPlaceholders(gStringVar4, msg);
    SetWindowTemplateFields(&template, 0, 1, 1, 20, 2, 15, 100);
    tDebugWindow = AddWindow(&template);
    FillWindowPixelBuffer(tDebugWindow, 0);
    PutWindowTilemap(tDebugWindow);
    CopyWindowToVram(tDebugWindow, 1);
    AddTextPrinterParameterized(tDebugWindow, 1, gStringVar4, 0, 0, 0, NULL);
    taskId = CreateTask(RyuScriptDebugPrintTask, 0x64);
    gTasks[taskId].tScriptDBWindowData = tDebugWindow;
    return FALSE;
}

extern u8 RDBM_ScriptDelay2s[];


void RyuDebug_ShowActiveAlchemy(void)
{
    if (gSaveBlock2Ptr->hasAlchemyEffectActive == TRUE)
    {
        u8 effectid = gSaveBlock2Ptr->alchemyEffect;
        StringCopy(gStringVar3, gRyuAlchemyEffectItemToStringTable[effectid]);
        DebugPrint(((const u8[]) _("Alchemy: {STR_VAR_3}.")), 0);
    }
}

void RyuBuildDailyQuestInfoString(void)
{
    u8 temp[50];
    u16 type = (VarGet(VAR_RYU_DAILY_QUEST_TYPE));
    u16 target = (VarGet(VAR_RYU_DAILY_QUEST_TARGET));
    u16 data = (VarGet(VAR_RYU_DAILY_QUEST_DATA));
    u16 from = (VarGet(VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION));
    switch (type)
    {
        case FETCH_TYPE:
            {
                StringCopy(temp, gFactionDailyQuestTypeNames[type]);//collect
                StringAppend(temp, (const u8[]) _(" "));//space
                ConvertIntToDecimalStringN(gStringVar1, data, STR_CONV_MODE_LEFT_ALIGN, 2);//quantity
                StringAppend(temp, gStringVar1);//space
                StringAppend(temp, (const u8[]) _(" "));//space
                CopyItemName(target, gStringVar1);//item name
                StringAppend(temp, gStringVar1);
                StringAppend(temp, (const u8 []) _("(s)."));//just in case plural.
                //should look like     Faction Daily:/nNaturalists: Collect 3 Pretty Wing(s).
                break;
            }
        case CAPTURE_TYPE:
            {
                StringCopy(temp, gFactionDailyQuestTypeNames[type]);//Capture
                StringAppend(temp, (const u8[]) _(" a "));//space
                StringAppend(temp, gSpeciesNames[target]);//species name
                StringAppend(temp, (const u8[]) _("."));
                //should look like     Faction Daily:/nStudents: Capture a Pikachu.
                break;
            }
        case TRAVEL_TYPE:
            {
                StringCopy(temp, gFactionDailyQuestTypeNames[type]);//Travel
                StringAppend(temp, (const u8[]) _(" to "));
                GetMapName(gStringVar1, target, 0);
                StringAppend(temp, gStringVar1);//mapsec name
                //should look like     Faction Daily:\nNobles: Travel to Devon Corp.
                break;
            }
        case HATCH_TYPE:
            {
                StringCopy(temp, gFactionDailyQuestTypeNames[type]);//Hatch
                StringAppend(temp, (const u8[]) _(" the given Egg."));//space
                //should look like     Faction Daily:/nProfessionals: Hatch the given Egg.
                break;
            }
    }
    StringCopy(gRyuStringVar2, temp);
}

void RyuDisableTrainerRepelAp (void)
{
    ClearAPFlag(AP_TRAINER_REPEL);
    QueueNotification((const u8[])_("Trainer Repel was disabled."), NOTIFY_GENERAL, 120);
}

void Ryu_SVM_CheckQuantityCost(void)
{
    u32 baseCost = gSpecialVar_0x8002;
    u32 quantity = gSpecialVar_0x8003;
    baseCost *= quantity;
    if (baseCost > (GetMoney(&gSaveBlock1Ptr->money)))
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
    gSpecialVar_32bit = baseCost;
    ConvertUIntToDecimalStringN(gStringVar3, baseCost, STR_CONV_MODE_LEFT_ALIGN, 10);
}

void Ryu_SVM_TakeMoney(void)
{
    u8 currentDailyPurchases = (VarGet(VAR_RYU_DAILY_VENDING_MACHINE_PURCHASES));
    currentDailyPurchases += gSpecialVar_0x8003;
    RemoveMoney(&gSaveBlock1Ptr->money, gSpecialVar_32bit);
    VarSet(VAR_RYU_DAILY_VENDING_MACHINE_PURCHASES, currentDailyPurchases);
}

void RyuResetMoney(void)
{
    SetMoney(&gSaveBlock1Ptr->money, 0);
}

void Ryu_SVM_CheckDailyQuota(void)
{
    u16 currentPurchased = (VarGet(VAR_RYU_DAILY_VENDING_MACHINE_PURCHASES));
    u16 max = 50;
    u16 newvalue = 0;
    newvalue = (max - currentPurchased);
    ConvertIntToDecimalStringN(gRyuStringVar1, newvalue, STR_CONV_MODE_LEFT_ALIGN, 2);
}

void Ryu_SVM_CheckQuantityExceedsQuota(void)
{
    u16 currentPurchased = (VarGet(VAR_RYU_DAILY_VENDING_MACHINE_PURCHASES));
    u16 max = 50;
    u16 newvalue = 0;
    newvalue = (max - currentPurchased);
    if (newvalue < gSpecialVar_0x8003)
        gSpecialVar_0x8004 = 666;
}

void RyuBetaMenuDynamicInfoBox(void)
{
    u8 buffer1[20];
    u8 savestateDetected = (FlagGet(FLAG_RYU_SAVE_STATE_DETECTED));
    u8 devModeon = (FlagGet(FLAG_RYU_DEV_MODE));
    ConvertIntToDecimalStringN(buffer1, (VarGet(VAR_LAST_KNOWN_GAME_VERSION)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringCopy(gStringVar1, (const u8[])_("The last known game version: {COLOR LIGHT_GREEN}{SHADOW GREEN}"));
    StringAppend(gStringVar1, buffer1);
    ConvertIntToDecimalStringN(buffer1, (VarGet(VAR_SAVE_FILE_CREATED_ON_VERSION)), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringCopy(gStringVar2, (const u8[])_("Save file created on version: {COLOR LIGHT_GREEN}{SHADOW GREEN}"));
    StringAppend(gStringVar2, buffer1);
    ConvertIntToDecimalStringN(buffer1, savestateDetected, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringCopy(gStringVar3, (const u8[])_("Save state detection: {COLOR LIGHT_GREEN}{SHADOW GREEN}"));
    StringAppend(gStringVar3, buffer1);
    ConvertIntToDecimalStringN(buffer1, devModeon, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringCopy(gRyuStringVar1, (const u8[])_("Dev mode enabled: {COLOR LIGHT_GREEN}{SHADOW GREEN}"));
    StringAppend(gRyuStringVar1, buffer1);
    ConvertIntToDecimalStringN(buffer1, VarGet(VAR_RYU_AUTOFILL_ERROR_COUNT), 0, 4);
    StringCopy(gRyuStringVar2, (const u8[])_("Autofill Error Count: {COLOR LIGHT_BLUE}{SHADOW BLUE}"));
    StringAppend(gRyuStringVar2, buffer1);
    StringCopy(gRyuStringVar3, (const u8[])_("{COLOR LIGHT_BLUE}{SHADOW BLUE}And details of your bug."));
}

void RyuSetCustomNature (void)
{
    bool8 tru = TRUE;
    bool8 fals = FALSE;
    u8 nature = gSpecialVar_0x8005;
    u8 slot = gSpecialVar_0x8001;
    SetMonData(&gPlayerParty[slot], MON_DATA_HAS_CUSTOM_NATURE, &tru);
    SetMonData(&gPlayerParty[slot], MON_DATA_CUSTOM_NATURE, &nature);
    CalculateMonStats(&gPlayerParty[slot]);
}

void SwapPlayerGender (void)
{
    if ((gSaveBlock2Ptr->playerGender) == 0)
        gSaveBlock2Ptr->playerGender = 1;
    else
        gSaveBlock2Ptr->playerGender = 0;
}

void RetroPokedexRegister (void)
{
    int i = 0;
    int k = 0;
    int count = 0;
    for (i = 0;i < TOTAL_BOXES_COUNT;i++)
    {
        for(k = 0;k < IN_BOX_COUNT;k++)
        {
            if(!(GetBoxMonDataAt(i, k, MON_DATA_SPECIES) == SPECIES_NONE))
            {
                if (GetSetPokedexFlag(GetBoxMonDataAt(i, k, MON_DATA_SPECIES), FLAG_GET_CAUGHT) == FALSE)
                {
                    count++;
                    GetSetPokedexFlag(GetBoxMonDataAt(i, k, MON_DATA_SPECIES), FLAG_SET_CAUGHT);
                    GetSetPokedexFlag(GetBoxMonDataAt(i, k, MON_DATA_SPECIES), FLAG_SET_SEEN);
                }
            }
        }
    }
    gSpecialVar_Result = count;
}

void Ryu_Restorefollowers(void)
{
    u8 count = 0;
    if (FlagGet(FLAG_RYU_DS_DAWN_PARTNERS) == TRUE) 
    {
        FlagClear(FLAG_HIDE_DAWNS_HOUSE_DAWN);
        count++;
    }
    
    if (FlagGet(FLAG_RYU_DS_BRENDAN_PARTNERS) == TRUE)
    {
        FlagClear(FLAG_HIDE_BRENDANS_HOUSE_BRENDAN);
        count++;
    }
    
    if (FlagGet(FLAG_RYU_DS_LEAF_PARTNERS) == TRUE)
    {
        FlagClear(FLAG_HIDE_LEAFS_HOUSE_LEAF_AND_BRO);
        count++;
    }

    if (FlagGet(FLAG_RYU_DS_LANETTE_PARTNERS) == TRUE)
    {
        FlagClear(FLAG_HIDE_LANETTES_HOUSE_LANETTE);
        count++;
    }

    if (FlagGet(FLAG_RYU_DS_SHELLY_PARTNERS) == TRUE)
    {
        FlagClear(FLAG_HIDE_AQUAHQ_SHELLY);
        count++;
    }

    if (FlagGet(FLAG_RYU_DS_COURTNEY_PARTNERS) == TRUE)
    {
        FlagClear(FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY);
        count++;
    }

    if ((FlagGet(FLAG_RYU_DS_JOY_PARTNERS) == TRUE) || ((VarGet(VAR_RYU_QUEST_NURSE) > 1) && (VarGet(VAR_RYU_QUEST_NURSE) < 12)))
    {
        FlagClear(FLAG_RYU_HIDE_JOY);
        count++;
    }

    if (FlagGet(FLAG_RYU_DS_MAY_PARTNERS) == TRUE)
    {
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            FlagClear(FLAG_RYU_DH_HIDE_MAY);
            count++;
        }    
        else
        {
            FlagClear(FLAG_RYU_DH_HIDE_MAY);
            count++;
        }    
    }

    FlagClear(FLAG_RYU_HIDE_MINNIE);
    count++;

    gSpecialVar_Result = count;
    
}

void RyuApplyWarEffects(void)
{
    int i;
    for (i = 0;i < 6;i++)
    {
        u16 newHp = (GetMonData(&gPlayerParty[i], MON_DATA_HP));
        if (newHp == 0)
            newHp = 0;
        else
            newHp /=2;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, &newHp);
    }
    VarSet(VAR_RYU_HORSEMAN_ID, 1);
}

void RyuApplyFamineEffects(void)
{
    int i, k;
    for (i = 0;i < 6;i++)
    {
        u16 newPp = 4;
        for (k = 0; k < 4; k++)
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + k, &newPp);
    }
    VarSet(VAR_RYU_HORSEMAN_ID, 4);
}

void RyuApplyDeathEffects(void)
{
    int i;
    for (i = 0;i < 6;i++)
    {
        u16 newHp = 0;
        i++;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, &newHp);
    }
    VarSet(VAR_RYU_HORSEMAN_ID, 3);
}

void RyuApplyPlagueEffects(void)
{
    int i;
    u8 one = (1 << 3);
    for (i = 0;i < 6;i++)
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, &one);
    VarSet(VAR_RYU_HORSEMAN_ID, 2);
}

void RyuTestDynamicObjectContents(void)
{
    u32 i;
    u8 objectsCount = 0;
    mgba_open();
    for (i=0;i<4;i++)
        if (gSaveBlock1Ptr->DynamicObjects[i].active == TRUE)
            objectsCount++;
    ConvertIntToDecimalStringN(gStringVar1, objectsCount, 0, 1);
    mgba_printf(LOGINFO, "There are %d active dynamic objects.", objectsCount);
    for (i=0;i<4;i++)
        if (gSaveBlock1Ptr->DynamicObjects[i].active == TRUE)
        {
            mgba_printf(LOGINFO, "\nobject # %d:\nObject gfx ID: %d\nMap is %d:%d\ncoords are %d,%d,%d\nMovement type: %d\nlocalid: %d\nscript pointer: %d", i, gSaveBlock1Ptr->DynamicObjects[i].gfxId, gSaveBlock1Ptr->DynamicObjects[i].mapGroup, gSaveBlock1Ptr->DynamicObjects[i].mapNum, gSaveBlock1Ptr->DynamicObjects[i].x, gSaveBlock1Ptr->DynamicObjects[i].y, gSaveBlock1Ptr->DynamicObjects[i].z, gSaveBlock1Ptr->DynamicObjects[i].movement, gSaveBlock1Ptr->DynamicObjects[i].localId, gSaveBlock1Ptr->DynamicObjects[i].scriptPtr);
        }
    mgba_close();
}

void RyuCallStatAssistUI(void)
{
    StatAssist_Init(CB2_ReturnToField);
}


void RyuSetupMiningRichness(void)
{
    u16 skill = (VarGet(VAR_RYU_PLAYER_MINING_SKILL));
    u16 rdmcp = (Random() % 5);
    rdmcp += skill;
    if ((Random() % 100) > 40)
        rdmcp = 0xFFFF; //60% chance the map isn't mineable at all.
    VarSet(VAR_RYU_MINING_RICHNESS, rdmcp);
}

#include "dexnav.h"
#include "wild_encounter.h"
//it is recommended to Disable BGM when running these tests, they take minutes and up to an hour.
//disabled bgm is a nontrivial decrease to that time.
//run this with callnative.
//If you wnt to test dexnav rates, set searchLevels[species] to 100 for each entry in the array,
//dexnav chain to 100, and set the flag FLAG_SYS_DEXNAV_SEARCH.
//if you want to test base shiny rate, clear that flag and remvoe any shiny charm you have in inventory.
//you can test with shiny charm and dexnav.
//ORIGINAL RESULTS after 1000 shinies:
//max dexnav + shiny charm: 1/437
//shiny charm only: 1/1350
//base rate: 1/3824
void RyuTestShinyRoll(void)
{
    int i;
    int rolls = 0;
    int shinycount = 0;
    int average = 0;
    int temp = 0;
    mgba_open();
    for (i = 0;i < 1000;i++)//roll 100 shinies
    {
        do {
            ZeroMonData(&gEnemyParty[0]);
            CreateWildMon(SPECIES_RALTS, 20);
            rolls++;
        } while (IsMonShiny(&gEnemyParty[0]) == FALSE);//not shiny, delete and try again
        shinycount++;
        temp = (shinycount / 10);
        mgba_printf(LOGINFO, "Shiny after %d rolls. %d pct total progress.", rolls, temp);
        average += rolls;//shiny found, add rolls to average to be calculated later
        rolls = 0;
    }//1000 shines found, time to calculate average
    average /= 1000;
    mgba_printf(LOGINFO, "After 1000 shinies at modified shiny rate,\nthe average encounters was %d", average);
}

void RyuFixLegendHP(void)
{
    int i;
    for (i = 0;i < PARTY_SIZE; i++)
    {
        CalculateMonStats(&gPlayerParty[i]);
    }
}

void ryuBufferSTChosenStat()
{
    switch(gSpecialVar_0x8002)
    {
        case 0:
            StringCopy(gStringVar2, ((const u8[])_("HP")));
            break;
        case 1:
            StringCopy(gStringVar2, ((const u8[])_("Attack")));
            break;
        case 2:
            StringCopy(gStringVar2, ((const u8[])_("Defense")));
            break;
        case 3:
            StringCopy(gStringVar2, ((const u8[])_("Speed")));
            break;
        case 4:
            StringCopy(gStringVar2, ((const u8[])_("Special Attack")));
            break;
        case 5:
            StringCopy(gStringVar2, ((const u8[])_("Special Defense")));
            break;
    }
}