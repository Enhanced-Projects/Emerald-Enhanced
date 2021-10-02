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
    u8 level = 1;
    u8 slot = (VarGet(VAR_TEMP_8));
    u8 ball = ITEM_LUXURY_BALL;
    u16 move1 =  (VarGet(VAR_RYU_GCMS_MOVE1));
    u16 move2 =  (VarGet(VAR_RYU_GCMS_MOVE2));
    u16 move3 =  (VarGet(VAR_RYU_GCMS_MOVE3));
    u16 move4 =  (VarGet(VAR_RYU_GCMS_MOVE4));
    bool8 isBoss = (FlagGet(FLAG_RYU_BOSS_IN_GCMS));
    u8 ability = (VarGet(VAR_RYU_GCMS_ABILITY));

    if (fixedIv > 31)
        fixedIv = 31;

    CreateMonWithNature(&gPlayerParty[slot], species, level, fixedIv, nature);
    SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
    SetMonData(&gPlayerParty[slot], MON_DATA_POKEBALL, &ball);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE1, &move1);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE2, &move2);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE3, &move3);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE4, &move4);
    SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);
    SetMonData(&gPlayerParty[slot], MON_DATA_GIFT_RIBBON_7, &isBoss);

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

    SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);
}

bool8 RyuGiveMewtwo(void)
{
    u8 ev = 252;
    u8 slot = CalculatePlayerPartyCount();
    // empty party (how?) or full party
    if (slot == 0 || slot > 5) {
      return FALSE;
    }

    CreateMonWithNature(&gPlayerParty[slot], SPECIES_MEWTWO, 95, 31, NATURE_MODEST);
    SetMonData(&gPlayerParty[slot], MON_DATA_ATK_EV, &ev);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_EV, &ev);
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
        FlagSet(FLAG_RYU_NUZLOCKEFAILED);
}

extern const u16 gFrontierBannedSpecies[27];


int RyuSacrificeMon(void)//eats the selected mon and saves certain values to be used by gcms.
{
    u8 slot = (VarGet(VAR_TEMP_9));
    u16 species = 0;
    u16 move1 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE1);
    u16 move2 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE2);
    u16 move3 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE3);
    u16 move4 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE4);
    u8 ability = GetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM);
    bool8 bossFlag = (GetMonData(&gPlayerParty[slot], MON_DATA_GIFT_RIBBON_7));
    u8 i;


    for (; gFrontierBannedSpecies[i] != 0xFFFF; i++)
        {
            if (gFrontierBannedSpecies[i] == (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES2)))
                return 2;
        }

    if (FlagGet(FLAG_TEMP_5) == 1)
    {
        species = (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES2, NULL));
        ZeroMonData(&gPlayerParty[slot]);
        CompactPartySlots();
        VarSet(VAR_RYU_GCMS_SPECIES, species);
        VarSet(VAR_RYU_GCMS_MOVE1, move1);
        VarSet(VAR_RYU_GCMS_MOVE2, move2);
        VarSet(VAR_RYU_GCMS_MOVE3, move3);
        VarSet(VAR_RYU_GCMS_MOVE4, move4);
        VarSet(VAR_RYU_GCMS_ABILITY, ability);
        FlagClear(FLAG_TEMP_5);
        if (bossFlag == TRUE)
            FlagSet(FLAG_RYU_BOSS_IN_GCMS);
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

    CreateMonWithGenderNatureLetter(&gPlayerParty[partycount], SPECIES_SNEASEL, 24, 31, MON_FEMALE, NATURE_ADAMANT, 0);
    SetMonData(&gPlayerParty[partycount], MON_DATA_ATK_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_SPEED_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_FRIENDSHIP, &friendship);
}

void RyuBrendanGiftPoke(void)
{
    u8 iv = 126;
    u8 partycount = (CalculatePlayerPartyCount());
    u8 friendship = 70;

    partycount = VarGet(gSpecialVar_Result);
    CreateMonWithGenderNatureLetter(&gPlayerParty[partycount], SPECIES_SNORUNT, 24, 31, MON_FEMALE, NATURE_MODEST, 0);
    SetMonData(&gPlayerParty[partycount], MON_DATA_SPATK_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_SPEED_EV, &iv);
    SetMonData(&gPlayerParty[partycount], MON_DATA_FRIENDSHIP, &friendship);
}

void RyuDevCheck(void)
{
    if ((JOY_HELD(L_BUTTON)) && (JOY_HELD(R_BUTTON)) && (JOY_HELD(B_BUTTON)))
        gSpecialVar_Result = 69;
}

int CountBadges(void)
{
    int count = 0, badge;
    for (badge = FLAG_BADGE01_GET; badge <= FLAG_BADGE08_GET; badge++)
        count += FlagGet(badge);
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
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_SPEED_EV
};

void RyuSetSlotStatEV(void)//This is super lewd, you don't even know
{
    u8 value = VarGet(VAR_TEMP_1);
    u8 slot = VarGet(VAR_TEMP_2);
    u8 stat = VarGet(VAR_TEMP_3);

    SetMonData(&gPlayerParty[slot], RyuValToEv[stat], &value);
    CalculateMonStats(&gPlayerParty[slot]);
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

void RyuResetEvs(void)
{
    u8 ev = 0;
    PlaySE(SE_EXPMAX);
    SetMonData(&gPlayerParty[0], MON_DATA_HP_EV, &ev);
    SetMonData(&gPlayerParty[0], MON_DATA_ATK_EV, &ev);
    SetMonData(&gPlayerParty[0], MON_DATA_DEF_EV, &ev);
    SetMonData(&gPlayerParty[0], MON_DATA_SPATK_EV, &ev);
    SetMonData(&gPlayerParty[0], MON_DATA_SPDEF_EV, &ev);
    SetMonData(&gPlayerParty[0], MON_DATA_SPEED_EV, &ev);
    CalculateMonStats(&gPlayerParty[0]);
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

void RyuSetIVs(void)//used in quickstart for devmons.
{
    u8 iv = 31;
    u8 ab = 0; 
    SetMonData(&gPlayerParty[0], MON_DATA_HP_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_ATK_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_DEF_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_SPATK_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_SPDEF_IV, &iv);
    SetMonData(&gPlayerParty[0], MON_DATA_SPEED_IV, &iv);
    SetMonData(&gPlayerParty[1], MON_DATA_HP_IV, &iv);
    SetMonData(&gPlayerParty[1], MON_DATA_ATK_IV, &iv);
    SetMonData(&gPlayerParty[1], MON_DATA_DEF_IV, &iv);
    SetMonData(&gPlayerParty[1], MON_DATA_SPATK_IV, &iv);
    SetMonData(&gPlayerParty[1], MON_DATA_SPDEF_IV, &iv);
    SetMonData(&gPlayerParty[1], MON_DATA_SPEED_IV, &iv);
    SetMonData(&gPlayerParty[1], MON_DATA_ABILITY_NUM, &ab);
    CalculateMonStats(&gPlayerParty[1]);
    CalculateMonStats(&gPlayerParty[0]);
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

void SwapPlayerGender(void)//only used by debug menu sometimes to check graphics.
{
    if (gSaveBlock2Ptr->playerGender == 1)
    {
        gSaveBlock2Ptr->playerGender = 0;
    }
    else
    {
        gSaveBlock2Ptr->playerGender = 1;
    }
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

void resetSoundGameStat(void)
{
    SetGameStat(GAME_STAT_USED_SOUND_MOVE, 200);
}

bool8 RyuCheckContestMastery(void)
{
    u8 i = 0;

    if (FlagGet(FLAG_RYU_CLEARED_COOL) == 1)
        i++;

    if (FlagGet(FLAG_RYU_CLEARED_BEAUTY) == 1)
        i++;

    if (FlagGet(FLAG_RYU_CLEARED_TOUGH) == 1)
        i++;

    if (FlagGet(FLAG_RYU_CLEARED_SMART) == 1)
        i++;

    if (FlagGet(FLAG_RYU_CLEARED_CUTE) == 1)
        i++;

    if (FlagGet(FLAG_RYU_GIVEN_DIANCIE) == 1)
        i += 10;

    if (i == 5)
        return TRUE;

    return FALSE;
}

int RyuNumberOfFullBoxes(void)//used by lanette to determine how many full boxes player has for her quest. She requires 4.
{
    u8 i;
    u8 fullBoxes = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        if (GetFirstFreeBoxSpot(i) == -1)
            fullBoxes++;
    }
    return fullBoxes;
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
    if (VarGet(VAR_RYU_TITLE_DEFENSE_WINS) >= 10 && (FlagGet(FLAG_RYU_DEFEATED_OVERLORD) == 1))
    {
        if ((Random() % 100) <= 25)
        {
            return 2;
        }
    }
    else if (VarGet(VAR_RYU_TITLE_DEFENSE_WINS) >= 10)
    {
        if ((Random() % 100) <= 10)
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void CheckSaveFileSize(void)//used in debug menu from time to time as a special to check saveblock space and buffer to strings for output.
{
    u32 size = (sizeof(struct SaveBlock1));
    u32 size2 = (sizeof(struct SaveBlock2));
    u32 size3 = (sizeof(struct BoxPokemon));
    ConvertIntToDecimalStringN(gStringVar1, size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar2, size2, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar3, size3, STR_CONV_MODE_LEFT_ALIGN, 6);
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
    SetMainCallback2(CB2_ReturnToFieldLocal);
    return TRUE;
}

bool8 ScrCmd_checkspecies(struct ScriptContext *ctx)//this lewd function checks if player has mon, and if so,
{                                                   //sets flag FLAG_TEMP_C, and slot number to VAR_TEMP_F
    u16 speciesId = VarGet(ScriptReadHalfword(ctx));//see the relevant script command in asm/macros/event.inc
    u8 i;

    for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == speciesId)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == FALSE)
            {
                FlagSet(FLAG_TEMP_C);
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

bool8 ScrCmd_addmonhappiness(struct ScriptContext *ctx) //can no longer set happiness above 200. Affection must be earned the hard way
{
    u16 index = VarGet(ScriptReadHalfword(ctx));
    u16 value = VarGet(ScriptReadByte(ctx));
    u16 current = GetMonData(&gPlayerParty[index], MON_DATA_FRIENDSHIP);

    value = value + current;

    if (value > 200)
        value = 200;

    SetMonData(&gPlayerParty[index], MON_DATA_FRIENDSHIP, &value);
    return FALSE;
}

//////////////////////
// Follower related //
//////////////////////

// This function fills in the necessary temporary variables for setting up partner multibattles
bool8 RyuFollowerToTrainerID(void)
{
    if (FlagGet(FLAG_RYU_HAS_FOLLOWER))
    {
        switch (VarGet(VAR_RYU_FOLLOWER_ID))
        {
        case OBJ_EVENT_GFX_TWIN:
            gSpecialVar_0x8008 = TRAINER_REL_MINNIE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_MINNIE;
            return TRUE;
        case OBJ_EVENT_GFX_WOMAN_2:
            gSpecialVar_0x8008 = TRAINER_REL_LANETTE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LANETTE; 
            return TRUE;
        case OBJ_EVENT_GFX_AQUA_MEMBER_F:
            gSpecialVar_0x8008 = TRAINER_REL_SHELLY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_SHELLY;
            return TRUE;
        case OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL:
            gSpecialVar_0x8008 = TRAINER_REL_DAWN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_DAWN;
            return TRUE;
        case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL:
            gSpecialVar_0x8008 = TRAINER_REL_BRENDAN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_BRENDAN;
            return TRUE;
        case OBJ_EVENT_GFX_LEAF:
            gSpecialVar_0x8008 = TRAINER_REL_LANA;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LEAF;
            return TRUE;
        case OBJ_EVENT_GFX_MAGMA_MEMBER_F:
            gSpecialVar_0x8008 = TRAINER_REL_COURTNEY_2;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_COURTNEY;
            return TRUE;
        case OBJ_EVENT_GFX_NURSE:
            gSpecialVar_0x8008 = TRAINER_REL_NURSE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_NURSE;
            return TRUE;
        }
        return FALSE;
    }
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

    for (i = 0; i < outsideCount; i++)
    {
        if (gMapHeader.regionMapSectionId == gOutsideMapSecs[i])
        {
            inside = FALSE;
        }
    }

    switch (VarGet(VAR_RYU_PLAYER_MINING_SKILL))//I feel like this could be made more efficient
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
            total1 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_UNCOMMON_GEM_ORE)
        {
            total2 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
        }

        if (gBagPockets[ITEMS_POCKET].itemSlots[i].itemId == ITEM_RARE_GEM_ORE)
        {
            total3 = RyuGetItemQuantity(&gBagPockets[ITEMS_POCKET].itemSlots[i].quantity);
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
                                                                                      //I wish there was a better way to do this
    switch (rnd1)//this sets the mon data rnd1 (which refers to the define of MON_DATA_STAT_IV where stat is the random one)
    {
        case 39:
            {
                SetMonData(&gPlayerParty[slot], rnd1, &iv);
                break;
            }
        case 40:
            {
                SetMonData(&gPlayerParty[slot], rnd1, &iv);
                break;
            }
        case 41:
            {
                SetMonData(&gPlayerParty[slot], rnd1, &iv);
                break;
            }
        case 42:
            {
                SetMonData(&gPlayerParty[slot], rnd1, &iv);
                break;
            }
        case 43:
            {
                SetMonData(&gPlayerParty[slot], rnd1, &iv);
                break;
            }
        case 44:
            {
                SetMonData(&gPlayerParty[slot], rnd1, &iv);
                break;
            }
    } 

    switch (rnd2)
    {
        case 39:
            {
                SetMonData(&gPlayerParty[slot], rnd1, &iv);
                break;
            }
        case 40:
            {
                SetMonData(&gPlayerParty[slot], rnd2, &iv);
                break;
            }
        case 41:
            {
                SetMonData(&gPlayerParty[slot], rnd2, &iv);
                break;
            }
        case 42:
            {
                SetMonData(&gPlayerParty[slot], rnd2, &iv);
                break;
            }
        case 43:
            {
                SetMonData(&gPlayerParty[slot], rnd2, &iv);
                break;
            }
        case 44:
            {
                SetMonData(&gPlayerParty[slot], rnd2, &iv);
                break;
            }
    }  

    switch (rnd3)
    {
        case 39:
            {
                SetMonData(&gPlayerParty[slot], rnd3, &iv);
                break;
            }
        case 40:
            {
                SetMonData(&gPlayerParty[slot], rnd3, &iv);
                break;
            }
        case 41:
            {
                SetMonData(&gPlayerParty[slot], rnd3, &iv);
                break;
            }
        case 42:
            {
                SetMonData(&gPlayerParty[slot], rnd3, &iv);
                break;
            }
        case 43:
            {
                SetMonData(&gPlayerParty[slot], rnd3, &iv);
                break;
            }
        case 44:
            {
                SetMonData(&gPlayerParty[slot], rnd3, &iv);
                break;
            }
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
    u8 slot = gSpecialVar_Result;
    if (FlagGet(FLAG_TEMP_F) == FALSE)
        slot = 0;

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

void RyuSetUpSaveBlockStuff(void)
{
    gSaveBlock1Ptr->registeredItem = ITEM_WAYSTONE;
    VarSet(VAR_RYU_THEME_NUMBER, 1);
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
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_SNEASEL)
                return hasChampionRibbon(i) ? 5 : 1;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_WEAVILE)
                return hasChampionRibbon(i) ? 5 : 2;
        }
    }
    else
    {
        for (i = 0; i < CalculatePlayerPartyCount(); i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_SNORUNT)
                return hasChampionRibbon(i) ? 5 : 1;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_FROSLASS)
                return hasChampionRibbon(i) ? 5 : 2;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_GLALIE)
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
    u16 treeTableSize = (sizeof(gBotanyTreeRewards));
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

    SetMonData(&gPlayerParty[slot], MON_DATA_GIFT_RIBBON_7, &ribbon);
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
    if ((gSaveBlock2Ptr->playTimeHours <= 13) && (gSaveBlock2Ptr->playTimeMinutes <= 37))
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
            if (GetMonData(&gPlayerParty[k], MON_DATA_HP_EV + i) == 252)
                maxEvStat++;
        }
    }
    
    if ((maxEvStat > 0) && (CheckAchievement(ACH_FITNESS_GURU) == FALSE))
        GiveAchievement(ACH_FITNESS_GURU);
}

void RyuDebug_Plant49Berries(void)
{
    u8 i;
    for (i = 0; i < 50; i++)
        IncrementGameStat(GAME_STAT_PLANTED_BERRIES);
}

void RyuClearAlchemyEffect(void)
{
    gSaveBlock2Ptr->alchemyCharges = 0;
    gSaveBlock2Ptr->alchemyEffect = 0;
    gSaveBlock2Ptr->hasAlchemyEffectActive = 0;
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
    u16 currentExp = (VarGet(VAR_RYU_ALCHEMY_EXP));
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
    VarSet(VAR_RYU_ALCHEMY_EXP, currentExp);
    if (recipe > ALCHEMY_EFFECT_HEALING_FACTOR)
        return RyuGetAlchemyItemId(recipe - 2);
    else
        return recipe;
}

void RyuDebug_CheckAlchemyStatus(void)
{
    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock2Ptr->alchemyEffect, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->hasAlchemyEffectActive, STR_CONV_MODE_LEFT_ALIGN, 1);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock2Ptr->alchemyCharges, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(gRyuStringVar1, VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL), STR_CONV_MODE_LEFT_ALIGN, 1);
    ConvertIntToDecimalStringN(gRyuStringVar2, VarGet(VAR_RYU_ALCHEMY_EXP), STR_CONV_MODE_LEFT_ALIGN, 5);
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

    if (FlagGet(FLAG_RYU_DS_JOY_PARTNERS) == 1)
    {
        partners++;
        GiveAchievement(ACH_FWB);
    }

    if ((partners == 5) && (FlagGet(FLAG_RYU_FIRST_GAME_CLEAR) == 1))
    {
        GiveAchievement(ACH_TRUE_ENDING);
        VarSet(VAR_RYU_PARTNER_COUNT, partners);
        VarSet(VAR_RYU_QUESTS_FINISHED, (VarGet(VAR_RYU_QUESTS_FINISHED) + 1));
    }

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

void RyuFixCorruptedBoxMons(void)
{
    ZeroBoxMonAt(2, 5);
    ZeroBoxMonAt(2, 6);
}

void RyuBufferSkillLevels(void)
{
    u16 alchExp = (VarGet(VAR_RYU_ALCHEMY_EXP));
    u16 alchLvl = (VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL));
    u16 botExp = (VarGet(VAR_RYU_PLAYER_BOTANY_SKILL_EXP));
    u16 botLvl = (VarGet(VAR_RYU_PLAYER_BOTANY_SKILL));
    u16 minExp = (VarGet(VAR_RYU_PLAYER_MINING_EXP));
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
    
    if (FlagGet(FLAG_RYU_LIMBO) == 1)//Player is in Limbo after failing nuzlocke or hardcore.
        return 120;

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
        gSaveBlock1Ptr->gNPCTrainerFactionRelations[i] = 200;
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
    u16 i = 0;
    u8 ev = 255;
    u8 iv = 31;
    u8 lv = TRUE_MAX_LEVEL;
    u8 what = 0;
    u8 ribbon = TRUE;


    CreateMonWithGenderNatureLetter(&gPlayerParty[slot], species, lv, iv, gender, nature, what); 
    for (i = 0; i < 6; i++)
        SetMonData(&gPlayerParty[slot], (MON_DATA_HP_EV + i), &ev); // set ev's loop

    SetMonData(&gPlayerParty[slot], MON_DATA_PP_BONUSES, &ev); //sets all pp to max bonus

    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE1, &move1);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE2, &move2);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE3, &move3);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE4, &move4);

    SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);

    SetMonData(&gPlayerParty[slot], MON_DATA_GIFT_RIBBON_7, &ribbon); //make it a boss because why not
}

bool32 ScrCmd_unusedscrcmd(struct ScriptContext *ctx)
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

void RyuCheckDataSize(void)//used to check the size of whatever struct i want to check, only need to change the 'data =' part
{
    u32 data = sizeof(struct FacilityMon);
    data *= 999;
    ConvertIntToDecimalStringN(gStringVar1, data, STR_CONV_MODE_LEFT_ALIGN, 10);
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

void RyuCheckHasFighterDogs(void)
{
    u8 k;

    for (k = 0; k < CalculatePlayerPartyCount(); k++)
    {
        if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES2) == SPECIES_TERRAKION)
            VarSet(VAR_TEMP_D, (VarGet(VAR_TEMP_D) + 100));
    }
    for (k = 0; k < CalculatePlayerPartyCount(); k++)
    {
        if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES2) == SPECIES_VIRIZION)
            VarSet(VAR_TEMP_D, (VarGet(VAR_TEMP_D) + 100));
    }
    for (k = 0; k < CalculatePlayerPartyCount(); k++)
    {
        if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES2) == SPECIES_COBALION)
            VarSet(VAR_TEMP_D, (VarGet(VAR_TEMP_D) + 100));
    }
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
    if (randomvalue == 0)
        FlagSet(FLAG_RYU_BOSS_WILD);
    else
        FlagClear(FLAG_RYU_BOSS_WILD);
}

bool32 CheckIfSelectedSlotIsValid(void)
{
    u8 selection = VarGet(VAR_RESULT);
    u8 partySize = CalculatePlayerPartyCount();
    if (selection > (partySize - 1))
        return FALSE;

    return TRUE;
}
