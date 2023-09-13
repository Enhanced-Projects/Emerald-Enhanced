#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "berry.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"
#include "tv.h"
#include "constants/items.h"
#include "constants/tv.h"
#include "constants/battle_frontier.h"
#include "ach_atlas.h"

static void CB2_ReturnFromChooseHalfParty(void);
static void CB2_ReturnFromChooseBattleFrontierParty(void);

extern void TryGiveFitnessGuruAch();

void HealPlayerParty(void)
{
    u8 i, j;
    u8 ppBonuses;
    u8 arg[4];

    // restore HP.
    for(i = 0; i < gPlayerPartyCount; i++)
    {
        u16 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, arg);
        ppBonuses = GetMonData(&gPlayerParty[i], MON_DATA_PP_BONUSES);

        // restore PP.
        for(j = 0; j < MAX_MON_MOVES; j++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j), ppBonuses, j);
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, arg);
        }

        // since status is u32, the four 0 assignments here are probably for safety to prevent undefined data from reaching SetMonData.
        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, arg);

        if (CheckAchievement(ACH_FITNESS_GURU) == FALSE)
            TryGiveFitnessGuruAch();
    }
    IncrementGameStat(GAME_STAT_RESTED_AT_HOME);
}

u8 ScriptGiveMon(u16 species, u8 level, u16 item)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;

    CreateMon(&mon, species, level, 32, 0, 0, OT_ID_PLAYER_ID, 0);
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(&mon);
    nationalDexNum = SpeciesToNationalPokedexNum(species);

    switch(sentToPc)
    {
    case 0:
    case 1:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    }
    return sentToPc;
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    return GiveMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

static bool8 CheckPartyMonHasHeldItem(u16 item)
{
    int i;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY), gStringVar1);

    return hasItem;
}

const u16 gRyuHorsemenMoves[4][4] = {
    [0] = {MOVE_STONE_EDGE, MOVE_SLASH, MOVE_BULLET_PUNCH, MOVE_BULLDOZE},//war
    [1] = {MOVE_VENOSHOCK, MOVE_INFESTATION, MOVE_GIGA_DRAIN, MOVE_WILL_O_WISP},//plague
    [2] = {MOVE_REAPING_BLOW, MOVE_SLUDGE_BOMB, MOVE_DARK_VOID, MOVE_DISABLE},//death
    [3] = {MOVE_SPITE, MOVE_FLAMETHROWER, MOVE_THIEF, MOVE_DYNAMIC_PUNCH},//famine
};

const u8 horsemanWarName[] = _("War");
const u8 horsemanPlagueName[] = _("Pestilence");
const u8 horsemanDeathName[] = _("Death");
const u8 horsemanFamineName[] = _("Famine");

void CreateScriptedWildMon(u16 species, u8 level, u16 item)
{
    u8 heldItem[2];

    ZeroEnemyPartyMons();
    if ((gSaveBlock1Ptr->location.mapGroup == 33) && (gSaveBlock1Ptr->location.mapNum = 4))
    {
        level = MAX_LEVEL;
    }
    CreateMon(&gEnemyParty[0], species, level, 32, 0, 0, OT_ID_PLAYER_ID, 0);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }

     if ((gSaveBlock1Ptr->location.mapGroup == 33) && (gSaveBlock1Ptr->location.mapNum = 4))
        {
            //VarSet(VAR_OPTIONS_HP_BAR_SPEED, 0xFFFF);
            if (FlagGet(FLAG_RYU_FACING_HORSEMAN) == TRUE)
            {
                u16 maxhp = 10000;
                u32 i, k;
                SetMonData(&gEnemyParty[0], MON_DATA_MAX_HP, &maxhp);
                SetMonData(&gEnemyParty[0], MON_DATA_HP, &maxhp);
                for (i = 0;i<4;i++)
                {
                    SetMonData(&gEnemyParty[0], (MON_DATA_MOVE1 + i), &gRyuHorsemenMoves[VarGet(VAR_RYU_HORSEMAN_ID) - 1][i]);
                }
                switch (VarGet(VAR_RYU_HORSEMAN_ID))
                {
                    case 1:
                        SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, horsemanWarName);
                        break;
                    case 2:
                        SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, horsemanPlagueName);
                        break;
                    case 3:
                        SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, horsemanDeathName);
                        break;
                    case 4:
                        SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, horsemanFamineName);
                        break;
                }
            }
            else if (FlagGet(FLAG_RYU_FACING_REAPER) == TRUE)
            {
                u16 maxhp = 60000;
                u16 maxdef = 1500;
                u16 m1 = 245;
                u16 m2 = 585;
                u16 m3 = 309;
                u16 m4 = 429;
                u8 maxiv = 31;
                bool8 yes = TRUE;
                const u8 nick[] = (const u8[])_("Reaper");
                SetMonData(&gEnemyParty[0], MON_DATA_MAX_HP, &maxhp);
                SetMonData(&gEnemyParty[0], MON_DATA_HP, &maxhp);
                SetMonData(&gEnemyParty[0], MON_DATA_DEF, &maxdef);
                SetMonData(&gEnemyParty[0], MON_DATA_SPDEF, &maxdef);
                SetMonData(&gEnemyParty[0], MON_DATA_SPEED, &maxdef);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &m1);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &m2);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &m3);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &m4);
                SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, &nick);
                SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_BOSS_STATUS, &yes);
            }
            else if (FlagGet(FLAG_RYU_FACING_GENESECT) == TRUE)
            {
                u16 maxhp = 1000;
                u16 m1 = MOVE_TECHNO_BLAST;
                u16 m2 = MOVE_ZAP_CANNON;
                u16 m3 = MOVE_SIMPLE_BEAM;
                u16 m4 = MOVE_BUG_BUZZ;
                u8 maxiv = 31;
                bool8 yes = TRUE;
                const u8 nick[] = (const u8[])_("Genesis");
                SetMonData(&gEnemyParty[0], MON_DATA_MAX_HP, &maxhp);
                SetMonData(&gEnemyParty[0], MON_DATA_HP, &maxhp);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &m1);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &m2);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &m3);
                SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &m4);
                SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, &nick);
                SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &maxiv);
                SetMonData(&gEnemyParty[0], MON_DATA_BOSS_STATUS, &yes);
            }
        }
}

void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot)
{
    if (monIndex > PARTY_SIZE)
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

// Note: When control returns to the event script, gSpecialVar_Result will be
// TRUE if the party selection was successful.
void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseHalfPartyForBattle(0);
}

static void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChoosePartyForBattleFrontier(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseBattleFrontierParty;
    InitChooseHalfPartyForBattle(gSpecialVar_0x8004 + 1);
}

static void CB2_ReturnFromChooseBattleFrontierParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[MAX_FRONTIER_PARTY_SIZE];
    int i;

    CpuFill32(0, party, sizeof party);

    // copy the selected pokemon according to the order.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 4 with the order copied to.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}
