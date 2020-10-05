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
#include "mevent.h"
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
#include "data/lifeskill.h"
#include "rtc.h"
#include "constants/region_map_sections.h"
#include "field_specials.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "strings.h"

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

void RyuGiveExpUnloadBattery(void)
{
    s32 ExpBatteryVar = (VarGet(VAR_RYU_EXP_BATTERY));
    u8 MonSlotData = (VarGet(VAR_TEMP_F));
    s32 MonCurrExp = GetMonData(&gPlayerParty[VarGet(VAR_TEMP_F)], MON_DATA_EXP);

    ConvertIntToDecimalStringN(gStringVar1, ExpBatteryVar, STR_CONV_MODE_LEFT_ALIGN, 5);
    ExpBatteryVar = MonCurrExp + ExpBatteryVar;
    SetMonData(&gPlayerParty[MonSlotData], MON_DATA_EXP, &ExpBatteryVar);
    ApplyDaycareExperience(&gPlayerParty[MonSlotData]);
    CalculateMonStats(&gPlayerParty[MonSlotData]);
}

void GivePlayerModdedMon(void)
{
    u16 species = (VarGet(VAR_RYU_GCMS_SPECIES));
    u8 nature = (VarGet(VAR_TEMP_C));
    u8 fixedIv = (VarGet(VAR_RYU_GCMS_VALUE));
    u8 level = 5;
    bool8 isEgg = TRUE;
    u8 slot = (VarGet(VAR_TEMP_8));
    u8 ball = ITEM_LUXURY_BALL;
    u16 move1 =  (VarGet(VAR_RYU_GCMS_MOVE1));
    u16 move2 =  (VarGet(VAR_RYU_GCMS_MOVE2));
    u16 move3 =  (VarGet(VAR_RYU_GCMS_MOVE3));
    u16 move4 =  (VarGet(VAR_RYU_GCMS_MOVE4));
    u8 ability = (VarGet(VAR_RYU_GCMS_ABILITY));

    if (fixedIv > 31)
        fixedIv = 31;

    CreateMonWithNature(&gPlayerParty[slot], species, level, fixedIv, nature);
    SetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG, &isEgg);
    SetMonData(&gPlayerParty[slot], MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
    SetMonData(&gPlayerParty[slot], MON_DATA_POKEBALL, &ball);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE1, &move1);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE2, &move2);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE3, &move3);
    SetMonData(&gPlayerParty[slot], MON_DATA_MOVE4, &move4);
    SetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM, &ability);
    CalculateMonStats(&gPlayerParty[slot]);
}

void PasscodeGiveMonWithNature(void)
{
    u8 slot = (VarGet(VAR_TEMP_8));
    u16 species = (VarGet(VAR_TEMP_4));
    u8 nature = (VarGet(VAR_TEMP_C));
    u8 fixedIv = 31;
    u8 level = 100;

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
    // Give the player a modest mewtwo and max out its atk and spatk
    // (why max out atk when it’s modest and therefore -10% atk?)
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
            CompactPartySlots();
            PlaySE(SE_POKE_DEAD);
        }
    }
}

bool8 RyuSacrificeMon(void)
{
    u8 slot = (VarGet(VAR_TEMP_9));
    u16 species = 0;
    u16 move1 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE1);
    u16 move2 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE2);
    u16 move3 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE3);
    u16 move4 = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE4);
    u8 ability = GetMonData(&gPlayerParty[slot], MON_DATA_ABILITY_NUM);

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
        return TRUE;
    }
    else if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES2, NULL) == (VarGet(VAR_RYU_GCMS_SPECIES)))
    {
        ZeroMonData(&gPlayerParty[slot]);
        CompactPartySlots();
        return TRUE;
    }
    return FALSE;
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

u8 WhatStageIsGiftPoke(void)
{//returns between 1 and 3 based on state of the snorunt
    u8 i;
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)//i is starting point, partyCount is ending point, i++ steps up
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_SNORUNT)// if the mon's species is x
            {
                    return 1;//unevolved
            }
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_GLALIE)
            {
                    return 2;//default evo
            }
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_FROSLASS)
            {
                    return 3;//special evo
            }
    }
    return 0;
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
    if (FlagGet(FLAG_RYU_DEV_MODE) == 1)
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

void RyuSetEVHP(void)
{
    u8 value = VarGet(VAR_TEMP_1);
    u8 slot = VarGet(VAR_TEMP_2);
    SetMonData(&gPlayerParty[slot], MON_DATA_HP_EV, &value);
    CalculateMonStats(&gPlayerParty[slot]);
}

void RyuSetEVATK(void)
{
    u8 value = VarGet(VAR_TEMP_1);
    u8 slot = VarGet(VAR_TEMP_2);
    SetMonData(&gPlayerParty[slot], MON_DATA_ATK_EV, &value);
    CalculateMonStats(&gPlayerParty[slot]);
}

void RyuSetEVDEF(void)
{
    u8 value = VarGet(VAR_TEMP_1);
    u8 slot = VarGet(VAR_TEMP_2);
    SetMonData(&gPlayerParty[slot], MON_DATA_DEF_EV, &value);
    CalculateMonStats(&gPlayerParty[slot]);
}

void RyuSetEVSPATK(void)
{
    u8 value = VarGet(VAR_TEMP_1);
    u8 slot = VarGet(VAR_TEMP_2);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPATK_EV, &value);
    CalculateMonStats(&gPlayerParty[slot]);
}

void RyuSetEVSPDEF(void)
{
    u8 value = VarGet(VAR_TEMP_1);
    u8 slot = VarGet(VAR_TEMP_2);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPDEF_EV, &value);
    CalculateMonStats(&gPlayerParty[slot]);
}

void RyuSetEVSPE(void)
{
    u8 value = VarGet(VAR_TEMP_1);
    u8 slot = VarGet(VAR_TEMP_2);
    SetMonData(&gPlayerParty[slot], MON_DATA_SPEED_EV, &value);
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

int RyuCalculateCurrentExpCoefficient(void)
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

void RyuGenerateReward(void)
{
    u8 v1 = VarGet(VAR_TEMP_1);
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

void RyuSetIVs(void)
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

void RyuWarp()
{
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

void RyuCheckTempVars(void)
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
    //ConvertIntToDecimalStringN(gStringVar1, 0, STR_CONV_MODE_LEFT_ALIGN, 1);

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

void RyuGetCaughtMonsFromPCForDex(void)
{
    u16 i, j;
    u16 natDexNum;
    u16 species = SPECIES_NONE;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            species = GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SPECIES);
            if (species != SPECIES_NONE && !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_IS_EGG))
            {
                natDexNum = SpeciesToNationalPokedexNum(species);
                GetSetPokedexFlag(natDexNum, FLAG_SET_CAUGHT);
                GetSetPokedexFlag(natDexNum, FLAG_SET_SEEN);
            }
        }
    }
}

//Ball changer

void RyuChangeUsedPokeball(void)
{
    u8 newBall = (VarGet(VAR_TEMP_4));
    SetMonData(&gPlayerParty[0], MON_DATA_POKEBALL, &newBall);
}

void SwapPlayerGender(void)
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

bool8 RyuSwapAbility(void)
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
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int RyuNumberOfFullBoxes(void)
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

int RyuSwapRotomForm(void)
{
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

void CheckSaveFileSize(void)
{
    u32 size = (sizeof(struct SaveBlock1));
    u32 size2 = (sizeof(struct SaveBlock2));
    ConvertIntToDecimalStringN(gStringVar1, size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar2, size2, STR_CONV_MODE_LEFT_ALIGN, 6);
}

void ForceSoftReset(void)
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
                VarSet(VAR_TEMP_9, i);
                VarSet(VAR_TEMP_A, SPECIES_MELOETTA_PIROUETTE);
                return 2;
            }

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_MELOETTA_PIROUETTE)
            {
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &m1);
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

void VBCB_FullscreenCutscene(void) 
{
	UpdatePidgeyPaletteFade();
	UpdateBgPan();
}

bool8 ScrCmd_drawfullscreenimage(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);
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

bool8 ScrCmd_checkspecies(struct ScriptContext *ctx)
{
    u16 speciesId = VarGet(ScriptReadHalfword(ctx));
    u8 i;

    for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == speciesId)
        {
            gSpecialVar_Result = TRUE;
            VarSet(VAR_TEMP_F, i);
            return TRUE
        }
    }
    return TRUE;
}

static EWRAM_DATA u8 specialCutsceneSprite = 0;

bool8 ScrCmd_drawcustompic(struct ScriptContext *ctx)
{
    u8 mode = ScriptReadByte(ctx);
    u16 id = VarGet(ScriptReadHalfword(ctx));
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    if (mode == 1)
    {
        specialCutsceneSprite = (CreateTrainerSprite(FacilityClassToPicIndex(id), x, y, 0, &gDecompressionBuffer[0x800]));
        return FALSE;
    }

    if (mode == 2)
    {
        VarSet(VAR_TEMP_7, id);
        VarSet(VAR_TEMP_8, 2);
        specialCutsceneSprite = CreateMonSpriteFromNationalDexNumber(id, x, y, 15);
        return FALSE;
    }

    if (mode == 3)
    {
        CreateMonSprite_PicBox(id, x, y, 0);
    }
}

bool8 ScrCmd_addmonhappiness(struct ScriptContext *ctx)
{
    u16 index = VarGet(ScriptReadHalfword(ctx));
    u16 value = VarGet(ScriptReadByte(ctx));
    u16 current = GetMonData(&gPlayerParty[index], MON_DATA_FRIENDSHIP);

    value = value + current;

    if (value > 255)
        value = 255;

    SetMonData(&gPlayerParty[index], MON_DATA_FRIENDSHIP, &value);
    return FALSE;
}

//Follower related

bool8 RyuFollowerToTrainerID(void)//this function fills in the necessary temporary variables for setting up partner multibattles
{
    if (FlagGet(FLAG_RYU_HAS_FOLLOWER) == 1)
    {
        switch (VarGet(VAR_RYU_FOLLOWER_ID))
        {
        case OBJ_EVENT_GFX_TWIN:
            gSpecialVar_0x8008 = TRAINER_REL_MINNIE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_MINNIE;
            return TRUE;
            break;
        case OBJ_EVENT_GFX_WOMAN_2:
            gSpecialVar_0x8008 = TRAINER_REL_LANETTE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LANETTE; 
            return TRUE;
            break;
        case OBJ_EVENT_GFX_AQUA_MEMBER_F:
            gSpecialVar_0x8008 = TRAINER_REL_SHELLY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_SHELLY;
            return TRUE;
            break;
        case OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL:
            gSpecialVar_0x8008 = TRAINER_REL_DAWN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_DAWN;
            return TRUE;
            break;
        case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL:
            gSpecialVar_0x8008 = TRAINER_REL_BRENDAN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_BRENDAN;
            return TRUE;
            break;
        case OBJ_EVENT_GFX_LEAF:
            gSpecialVar_0x8008 = TRAINER_REL_LANA;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LEAF;
            return TRUE;
            break;
        case OBJ_EVENT_GFX_MAGMA_MEMBER_F:
            gSpecialVar_0x8008 = TRAINER_REL_COURTNEY_2;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_COURTNEY;
            return TRUE;
            break;
        case OBJ_EVENT_GFX_NURSE:
            gSpecialVar_0x8008 = TRAINER_REL_NURSE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_NURSE;
            return TRUE;
            break;
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

bool8 ChangeDarmanitanForm(void)
{
    u8 i;
    u16 darmi = SPECIES_DARMANITAN_ZEN;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_DARMANITAN)
        {
            SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &darmi);
            CalculateMonStats(&gPlayerParty[i]);
            return TRUE;
        }
    }
    return FALSE;
}

bool8 ScrCmd_dominingcheck(struct ScriptContext *ctx)
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

    switch (VarGet(VAR_RYU_PLAYER_MINING_SKILL))
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

void RyuCountGemOres(void)
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

void RyuChooseFromGemList(void)
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

int RyuFossilReward(void)
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

int RyuShardReward(void)
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

int Ryu_GiveRevivedFossilEgg(void)
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
    }while (((rnd1 != rnd2) && (rnd2 != rnd3) && (rnd3 != rnd1)) == FALSE);

    CreateMon(&gPlayerParty[slot], species, level, fixedIV, 0, 0, OT_ID_PLAYER_ID, 0);

    switch (rnd1)
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

int RyuCheckRelMegaReward(void)
{
    u16 partnerId = (VarGet(VAR_RYU_FOLLOWER_ID));

    switch (partnerId)
    {
        case OBJ_EVENT_GFX_AQUA_MEMBER_F:
        {
            if (FlagGet(FLAG_RYU_SHELLY_MEGA_REWARD) == 0)
                {
                    FlagSet(FLAG_RYU_SHELLY_MEGA_REWARD);
                    return ITEM_SHARPEDONITE;
                }
        }
        case OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL:
        {
            if (FlagGet(FLAG_RYU_DAWN_MEGA_REWARD) == 0)
                {
                    FlagSet(FLAG_RYU_DAWN_MEGA_REWARD);
                    return ITEM_ALTARIANITE;
                }
        }
        case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL:
        {
            if (FlagGet(FLAG_RYU_BRENDAN_MEGA_REWARD) == 0)
                {
                    FlagSet(FLAG_RYU_BRENDAN_MEGA_REWARD);
                    return ITEM_LUCARIONITE;
                }
        }
        case OBJ_EVENT_GFX_LEAF:
            {
                if (FlagGet(FLAG_RYU_LEAF_MEGA_REWARD) == 0)
                {
                    FlagSet(FLAG_RYU_LEAF_MEGA_REWARD);
                    return ITEM_VENUSAURITE;
                }
            }
        case OBJ_EVENT_GFX_MAGMA_MEMBER_F:
        {
            if (FlagGet(FLAG_RYU_COURTNEY_MEGA_REWARD) == 0)
            {
                FlagSet(FLAG_RYU_COURTNEY_MEGA_REWARD);
                return ITEM_CAMERUPTITE;
            }
        }
        default:
        {
            return 0;
        }
    }
};

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

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey);
    StringAppend(gTextBuffer1, gText_RyuStatsHP);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[0], MON_DATA_HP, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[0], MON_DATA_HP_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[0], MON_DATA_HP_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gStringVar1, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsAtk);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[0], MON_DATA_ATK, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[0], MON_DATA_ATK_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[0], MON_DATA_ATK_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gStringVar2, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsDef);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[0], MON_DATA_DEF, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[0], MON_DATA_DEF_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[0], MON_DATA_DEF_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gStringVar3, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsSpAtk);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[0], MON_DATA_SPATK, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[0], MON_DATA_SPATK_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[0], MON_DATA_SPATK_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gRyuStringVar1, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsSpDef);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[0], MON_DATA_SPDEF, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[0], MON_DATA_SPDEF_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[0], MON_DATA_SPDEF_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gRyuStringVar2, gTextBuffer1);

    StringCopy(gTextBuffer1, gText_ColorDarkGreyShadowLightGrey); 
    StringAppend(gTextBuffer1, gText_RyuStatsSpeed);
    ConvertIntToDecimalStringN(gTextBuffer2, (GetMonData(&gPlayerParty[0], MON_DATA_SPEED, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer2);
    StringAppend(gTextBuffer1, gText_RyuStatsIv);
    ConvertIntToDecimalStringN(gTextBuffer3, (GetMonData(&gPlayerParty[0], MON_DATA_SPEED_IV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer3);
    StringAppend(gTextBuffer1, gText_RyuStatsEv);
    ConvertIntToDecimalStringN(gTextBuffer4, (GetMonData(&gPlayerParty[0], MON_DATA_SPEED_EV, NULL)), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gTextBuffer1, gTextBuffer4);
    StringCopy(gRyuStringVar3, gTextBuffer1);

    return TRUE;
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

void RyuBufferQuestVars(void)
{
    ConvertIntToDecimalStringN(gStringVar1, (VarGet(VAR_RYU_MAGMA)), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, (VarGet(VAR_RYU_DEVON_MAIN_QUEST_VAR)), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, (VarGet(VAR_RYU_DEVON_SCIENTIST_STAGE)), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar1, (VarGet(VAR_RYU_DS_LANA_STAGE)), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar2, (VarGet(VAR_RYU_LANETTE_VAR)), STR_CONV_MODE_LEFT_ALIGN, 3);
}


int CheckRivalGiftMonStatus(void)//well this saved a bunch of lines.
{
    u8 gender = gSaveBlock2Ptr->playerGender;
    u8 i;
    u8 ret = 0;

    if (gender == MALE)
    {
        for (i = 0; i < CalculatePlayerPartyCount(); i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_SNEASEL)
                ret = 1;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_WEAVILE)
                ret = 2;
        }
    }
    else
    {
        for (i = 0; i < CalculatePlayerPartyCount(); i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_SNORUNT)
                ret = 1;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_FROSLASS)
                ret = 2;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_GLALIE)
                ret = 3;
        }
    }

    if (GetMonData(&gPlayerParty[i], MON_DATA_CHAMPION_RIBBON, NULL) == TRUE)
        ret = 5;

    return ret;
}

int RyuGetTimeOfDay(void)
{
    u8 hour;
    RtcCalcLocalTime();
    hour = gLocalTime.hours;

    if (hour >= 5 && hour < 10)
        return RTC_TIME_MORNING;

    if (hour >= 10 && hour < 18)
        return RTC_TIME_DAY;

    if (hour == 18)
        return RTC_TIME_EVENING;

    // The rest: either before 5:00 or after 18:59
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
    u16 reward1, reward2, reward3, reward4, reward5;

    switch (currentMapGroup)
    {
    case BOTANY_MAP_CATEGORY_JUNGLE:
            reward1 = gBotanyJungleTable[(Random() % ARRAY_COUNT(gBotanyJungleTable))];//I'd like to compress this but i don't know how @kageru
            reward2 = gBotanyJungleTable[(Random() % ARRAY_COUNT(gBotanyJungleTable))];//Ideally, it would only generate a reward for each level in the skill
            reward3 = gBotanyJungleTable[(Random() % ARRAY_COUNT(gBotanyJungleTable))];//so for now, it just rolls the max and then only
            reward4 = gBotanyJungleTable[(Random() % ARRAY_COUNT(gBotanyJungleTable))];//rewards the player items for the levels they've earned.
            reward5 = gBotanyJungleTable[(Random() % ARRAY_COUNT(gBotanyJungleTable))];
            break;
    case BOTANY_MAP_CATEGORY_COLD:
            reward1 = gBotanyColdTable[(Random() % ARRAY_COUNT(gBotanyColdTable))];
            reward2 = gBotanyColdTable[(Random() % ARRAY_COUNT(gBotanyColdTable))];
            reward3 = gBotanyColdTable[(Random() % ARRAY_COUNT(gBotanyColdTable))];
            reward4 = gBotanyColdTable[(Random() % ARRAY_COUNT(gBotanyColdTable))];
            reward5 = gBotanyColdTable[(Random() % ARRAY_COUNT(gBotanyColdTable))];
            break;
    case BOTANY_MAP_CATEGORY_VOLCANIC:
            reward1 = gBotanyVolcanicTable[(Random() % ARRAY_COUNT(gBotanyVolcanicTable))];
            reward2 = gBotanyVolcanicTable[(Random() % ARRAY_COUNT(gBotanyVolcanicTable))];
            reward3 = gBotanyVolcanicTable[(Random() % ARRAY_COUNT(gBotanyVolcanicTable))];
            reward4 = gBotanyVolcanicTable[(Random() % ARRAY_COUNT(gBotanyVolcanicTable))];
            reward5 = gBotanyVolcanicTable[(Random() % ARRAY_COUNT(gBotanyVolcanicTable))];
            break;
    case BOTANY_MAP_CATEGORY_SEASIDE:
            reward1 = gBotanySeasideTable[(Random() % ARRAY_COUNT(gBotanySeasideTable))];
            reward2 = gBotanySeasideTable[(Random() % ARRAY_COUNT(gBotanySeasideTable))];
            reward3 = gBotanySeasideTable[(Random() % ARRAY_COUNT(gBotanySeasideTable))];
            reward4 = gBotanySeasideTable[(Random() % ARRAY_COUNT(gBotanySeasideTable))];
            reward5 = gBotanySeasideTable[(Random() % ARRAY_COUNT(gBotanySeasideTable))];
            break;
    case BOTANY_MAP_CATEGORY_GENERAL:
            reward1 = gBotanySeasideTable[(Random() % ARRAY_COUNT(gBotanyGeneralTable))];
            reward2 = gBotanyGeneralTable[(Random() % ARRAY_COUNT(gBotanyGeneralTable))];
            reward3 = gBotanyGeneralTable[(Random() % ARRAY_COUNT(gBotanyGeneralTable))];
            reward4 = gBotanyGeneralTable[(Random() % ARRAY_COUNT(gBotanyGeneralTable))];
            reward5 = gBotanyGeneralTable[(Random() % ARRAY_COUNT(gBotanyGeneralTable))];
            break;
    }

    VarSet(VAR_TEMP_0, reward1);
    VarSet(VAR_TEMP_1, reward2);
    VarSet(VAR_TEMP_2, reward3);
    VarSet(VAR_TEMP_3, reward4);
    VarSet(VAR_TEMP_4, reward5);
}