#ifndef GUARD_RYU_ENEMY_ENHANCEMENT_H
#define GUARD_RYU_ENEMY_ENHANCEMENT_H

#include "global.h"
#include "RyuEnemyEnhancementSystem.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/general.h"
#include "data.h"
#include "event_data.h"
#include "random.h"
#include "ach_atlas.h"

//autoscale data
const u16 sRange[9][2] = {//Trainer level ranges
    {9,13},
    {17,22},
    {23,28},
    {29,34},
    {35,40},
    {42,49},
    {50,57}, 
    {58,65},
    {66,72},
};

const u16 sGymRange[9][2] = {//Gym Leader level ranges
    {11,18},
    {20,24},
    {25,33},
    {34,39},
    {40,45},
    {50,54},
    {55,62}, 
    {69,76},
    {77,84},
};

const u16 sWildRange[9][2] = {//Wild level ranges
    {6,11},
    {10,20},
    {19,29},
    {28,35},
    {36,41},
    {40,45},
    {44,49},
    {48,53},
    {52,60},
};

// Final levels will be player party average + the adjustment here + Random() % 5
static const s16 sAutoscalingAdjustments[3] = {
    [SCALING_TYPE_WILD] = -8,
    [SCALING_TYPE_TRAINER] = -5,
    [SCALING_TYPE_BOSS] = 0, // E4, gym leaders, etc.
};

//functions

/*
 * Calculate the player’s relative party strength for enemy autoscaling.
 * This is defined as the average level of the three strongest Pokemon.
 */
s16 CalculatePlayerPartyStrength(void) {
    u8 partyCount = CalculatePlayerPartyCount();
    s16 highest = 0, second = 0, third = 0, average;
    u8 level, i;

    for (i = 0; i < partyCount; i++) {
        level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
        // shift the previous highest down by one
        if (level > highest) {
            third = second;
            second = highest;
            highest = level;
        } else if (level > second) {
            third = second;
            second = level;
        } else if (level > third) {
            third = level;
        }
    }
    average = (highest + second + third) / min(partyCount, 3);
    // in case people bring very weak mons to drag down the average
    return max(highest - 20, average);
}

u32 RyuChooseLevel(u8 badges, bool8 maxScale, u8 scalingType, s16 playerPartyStrength)
{
    u8 level = 0;
    // Allows overriding the autoscaling from scripts.
    // Usually, this will just be 2 to make sure we don’t generate level 0 or 1 mons.
    u8 minLevel = VarGet(VAR_RYU_AUTOSCALE_MIN_LEVEL);
    u8 maxLevel = MAX_LEVEL;

    if (maxScale)
        return maxLevel;

    // While we are in Ryu’s special challenge, all trainers should be scaled to 95% of the strongest player party member.
    // We therefore subtract at most 5% from the maxLevel (rounded down),
    // so a player with a level 10 party will encounter enemies at level 10,
    // level 20 party encounters level 19-20 enemies, level 40 party encounters level 38-40 enemies, etc.
    // Scaling of wild Pokemon is not affected by the challenge and handled further down with the usual logic.
    if (VarGet(VAR_RYU_SPECIAL_CHALLENGE_STATE) == 100 && scalingType != SCALING_TYPE_WILD) {
        u8 highest = 0, i, level;
        for (i = 0; i < CalculatePlayerPartyCount(); i++) {
            level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            if (level > highest) highest = level;
        }
        return max(minLevel, highest - Random() % (highest / 20 + 1));
    }

    // Wild pokemon should always use badge scaling, unless the AP is enabled,
    // in which case they always scale to slightly below team level, even before NG+.
    if ((FlagGet(FLAG_RYU_ISNGPLUS) && scalingType != SCALING_TYPE_WILD)
        || (CheckIfAutolevelWilds() && scalingType == SCALING_TYPE_WILD)) {
        // Vars are usually u16, but we need a signed number here.
        // Scripts might write negative numbers which wrap to 65535, but the cast to s16 converts that back to -1.
        s16 autolevelModifier = (s16) VarGet(VAR_RYU_AUTOLEVEL_MODIFIER);
        s16 level = playerPartyStrength
            + (Random() % 5)
            + sAutoscalingAdjustments[scalingType]
            + autolevelModifier;
        return min(max(minLevel, level), maxLevel);
    }

    switch (scalingType) {
        case SCALING_TYPE_BOSS: 
            level = Random() % (sGymRange[badges][1] - sGymRange[badges][0]) + sGymRange[badges][0];
            break;
        case SCALING_TYPE_TRAINER: 
            level = Random() % (sRange[badges][1] - sRange[badges][0]) + sRange[badges][0];
            break;
        case SCALING_TYPE_WILD:
            level = Random() % (sWildRange[badges][1] - sWildRange[badges][0]) + sWildRange[badges][0];
            break;
    }
    return max(level, minLevel);
}

// If either the required level is reached or the mon is level 30
// (at which point we can assume that any reasonable trainer would have found the evolution stone,
// done the necessary trade, etc. for the evolution), evolve the Pokemon.
// This is done so our autoscaled enemies don’t end up with level 200 Zigzagoons.
u16 Autoevolve(u16 species, u16 level) {
    if ((
            (gEvolutionTable[species][0].method == EVO_LEVEL && gEvolutionTable[species][0].param <= level)
            || (gEvolutionTable[species][0].method != EVO_MEGA_EVOLUTION && level >= 30)
        )
        // while there is an evolution available at all (the method is 0 if there isn’t)
        && gEvolutionTable[species][0].method != 0
        // and we’re not in a circular evolution (shouldn’t happen, but just in case)
        && species != gEvolutionTable[species][0].targetSpecies
    ) {
        return Autoevolve(gEvolutionTable[species][0].targetSpecies, level);
    }
    return species;
}
extern void RyuSetPartyFrontierMon(bool32 opponent, u16 id, u8 slot);

u16 RyuChooseEnemyProceduralMons(u16 trainerClass)
{
    u16 species = gRyuProceduralTrainerMonLists[trainerClass][(Random() % 20)];
    if ((species == SPECIES_NONE) || (species > SPECIES_MELMETAL))
    {
        species = SPECIES_BIDOOF;
        VarSet(VAR_RYU_AUTOFILL_ERROR_COUNT, (VarGet(VAR_RYU_AUTOFILL_ERROR_COUNT) + 1));
    }

    return species;
}

u16 RyuChooseAutoscaleIV(void)
{
    u16 diff = VarGet(VAR_RYU_DIFFICULTY);
    u16 prestige = VarGet(VAR_RYU_NGPLUS_COUNT);
    u16 iv = 0;
    if (prestige == 0)
        prestige = 1;

    switch (diff)
    {
    case DIFF_NORMAL:
        iv = (5 * prestige);
        if (iv > 31)
            iv = 31;
        return iv;
    case DIFF_HARD:
        iv = (7 * prestige);
        if (iv > 31)
            iv = 31;
        return iv;
    case DIFF_EASY:
        iv = (3 * prestige);
        if (iv > 31)
            iv = 31;
        return iv;
    case DIFF_HARDCORE:
        iv = (10 * prestige);
        if (iv > 31)
            iv = 31;
        return iv;
    }
    return 31;
}

u8 RyuChooseAutoscaleEv(void)
{
    u16 diff = (VarGet(VAR_RYU_DIFFICULTY));
    u16 prestige = (VarGet(VAR_RYU_NGPLUS_COUNT));
    u8 badges = (CountBadges());
    u8 ev = 16;
    badges *= 10;
    if (prestige == 0)
    prestige = 1;

    switch (diff)
    {
    case 1://autoscale
    case 10://autoscale NGP
        ev = (25 * prestige);
        if (ev > 252)
            ev = 252;
        return (ev + badges);
    case 2000://challenge mode
        ev = (50 * prestige);
        if (ev > 252)
            ev = 252;
        return (ev + badges);
    case 4000://easy mode
    case 8000://god mode
        ev = (10 * prestige);
        if (ev > 252)
            ev = 252;
        return (ev + badges);
    case 1000://hard/hardcore
        ev = (75 * prestige);
        if (ev > 252)
            ev = 252;
        return (ev + badges);
    }
    return 255;

}

u8 RyuChoosePartyCount(u16 trainer)
{
    u8 count = ((Random() % 4) + 1);

    if (VarGet(VAR_RYU_QUEST_MAGMA) == 315)
        count += 2;

    switch (VarGet(VAR_RYU_DIFFICULTY))
    {
        case DIFF_NORMAL:
            count += 1;
            break;
        case DIFF_HARD:
            count += 2;
            break;
        case DIFF_HARDCORE:
            count = 6;
            break;
    }
    if (count > 6)
        count = 6;
    if (count < 1)
        count = 2;
    if (gTrainers[trainer].doubleBattle == TRUE)
        if (count < 2)
            count = 2;
    if (FlagGet(FLAG_RYU_FORCE_FULL_AUTOFILL_PARTY) == TRUE) //used for autofilled bosses
            count = PARTY_SIZE;
    return count;
}

//procedural trainer mon table
const u16 gRyuProceduralTrainerMonLists[72][20] = {
[TRAINER_CLASS_AETHER_WORKER] =
{
        SPECIES_KADABRA,
        SPECIES_BRUXISH,
        SPECIES_DROWZEE,
        SPECIES_GIRAFARIG,
        SPECIES_NATU,
        SPECIES_RALTS,
        SPECIES_WOOBAT,
        SPECIES_SIGILYPH,
        SPECIES_SLOWBRO,
        SPECIES_EXEGGCUTE,
        SPECIES_INKAY,
        SPECIES_DARMANITAN,
        SPECIES_BELDUM,
        SPECIES_ELGYEM,
        SPECIES_SOLOSIS,
        SPECIES_ESPURR,
        SPECIES_GOTHITA,
        SPECIES_MUNNA,
        SPECIES_WYNAUT,
        SPECIES_SPOINK
},
[TRAINER_CLASS_AETHER_ADMIN] =
{
        SPECIES_ALAKAZAM,
        SPECIES_MINIOR,
        SPECIES_HYPNO,
        SPECIES_GIRAFARIG,
        SPECIES_XATU,
        SPECIES_GARDEVOIR,
        SPECIES_SWOOBAT,
        SPECIES_SIGILYPH,
        SPECIES_SLOWKING,
        SPECIES_EXEGGUTOR,
        SPECIES_GALLADE,
        SPECIES_DARMANITAN,
        SPECIES_BELDUM,
        SPECIES_ELGYEM,
        SPECIES_DUOSION,
        SPECIES_ESPURR,
        SPECIES_GOTHITELLE,
        SPECIES_WOBBUFFET,
        SPECIES_CLEFABLE,
        SPECIES_GRUMPIG
},
[TRAINER_CLASS_TEAM_AQUA] = 
    {
        SPECIES_CARVANHA, 
        SPECIES_POOCHYENA, 
        SPECIES_FRILLISH,
        SPECIES_LAPRAS,
        SPECIES_BRIONNE,
        SPECIES_TENTACOOL,
        SPECIES_GOREBYSS,
        SPECIES_KRABBY,
        SPECIES_CORPHISH,
        SPECIES_GYARADOS,
        SPECIES_WIMPOD,
        SPECIES_VAPOREON,
        SPECIES_FINNEON,
        SPECIES_FEEBAS,
        SPECIES_DEWOTT,
        SPECIES_BASCULIN,
        SPECIES_QWILFISH,
        SPECIES_SEADRA,
        SPECIES_SNEASEL,
        SPECIES_MARSHTOMP
    },
[TRAINER_CLASS_AQUA_ADMIN] = 
    {
        SPECIES_SHARPEDO, 
        SPECIES_VAPOREON, 
        SPECIES_FRILLISH,
        SPECIES_LAPRAS,
        SPECIES_BRIONNE,
        SPECIES_MILOTIC,
        SPECIES_GOREBYSS,
        SPECIES_KINGLER,
        SPECIES_CORPHISH,
        SPECIES_GYARADOS,
        SPECIES_WIMPOD,
        SPECIES_VAPOREON,
        SPECIES_FINNEON,
        SPECIES_BRIONNE,
        SPECIES_DEWOTT,
        SPECIES_BASCULIN,
        SPECIES_QWILFISH,
        SPECIES_SEADRA,
        SPECIES_SNEASEL,
        SPECIES_MARSHTOMP
    },
[TRAINER_CLASS_AQUA_LEADER] = 
    {
        SPECIES_SHARPEDO, 
        SPECIES_VAPOREON, 
        SPECIES_FRILLISH,
        SPECIES_LAPRAS,
        SPECIES_BRIONNE,
        SPECIES_MILOTIC,
        SPECIES_GOREBYSS,
        SPECIES_KINGLER,
        SPECIES_CORPHISH,
        SPECIES_GYARADOS,
        SPECIES_WIMPOD,
        SPECIES_VAPOREON,
        SPECIES_FINNEON,
        SPECIES_BRIONNE,
        SPECIES_DEWOTT,
        SPECIES_BASCULIN,
        SPECIES_QWILFISH,
        SPECIES_SEADRA,
        SPECIES_SNEASEL,
        SPECIES_MARSHTOMP
    },
[TRAINER_CLASS_AROMA_LADY] = 
    {
        SPECIES_BULBASAUR,
        SPECIES_ODDISH,
        SPECIES_CHIKORITA,
        SPECIES_SUNFLORA,
        SPECIES_SURSKIT,
        SPECIES_ILLUMISE,
        SPECIES_BUDEW,
        SPECIES_GROTLE,
        SPECIES_CHERUBI,
        SPECIES_VESPIQUEN,
        SPECIES_CARNIVINE,
        SPECIES_COTTONEE,
        SPECIES_PETILIL,
        SPECIES_MARACTUS,
        SPECIES_DEERLING,
        SPECIES_SKIDDO,
        SPECIES_FOMANTIS,
        SPECIES_BOUNSWEET,
        SPECIES_AROMATISSE,
        SPECIES_RIBOMBEE,
    },
[TRAINER_CLASS_RUIN_MANIAC] = 
    {
        SPECIES_SANDSHREW,
        SPECIES_NIDORAN_M,
        SPECIES_DUGTRIO,
        SPECIES_GEODUDE,
        SPECIES_OMANYTE,
        SPECIES_KABUTO,
        SPECIES_AERODACTYL,
        SPECIES_DUNSPARCE,
        SPECIES_SWINUB,
        SPECIES_CORSOLA,
        SPECIES_BALTOY,
        SPECIES_LILEEP,
        SPECIES_ANORITH,
        SPECIES_RELICANTH,
        SPECIES_CRANIDOS,
        SPECIES_SHIELDON,
        SPECIES_TIRTOUGA,
        SPECIES_ARCHEN,
        SPECIES_TYRUNT,
        SPECIES_CARBINK,
    },
[TRAINER_CLASS_INTERVIEWER] = 
    {
        SPECIES_CHARMANDER,
        SPECIES_SQUIRTLE,
        SPECIES_PICHU,
        SPECIES_GROWLITHE,
        SPECIES_VULPIX,
        SPECIES_MEOWTH,
        SPECIES_MAGNEMITE,
        SPECIES_LOUDRED,
        SPECIES_EEVEE,
        SPECIES_MUNCHLAX,
        SPECIES_MUDKIP,
        SPECIES_TRAPINCH,
        SPECIES_TURTWIG,
        SPECIES_CHIMCHAR,
        SPECIES_SHINX,
        SPECIES_RALTS,
        SPECIES_GIBLE,
        SPECIES_RIOLU,
        SPECIES_MIMIKYU,
        SPECIES_FROAKIE,
    },
[TRAINER_CLASS_COOLTRAINER_2] = 
    {
        SPECIES_MANECTRIC,
        SPECIES_SYLVEON,
        SPECIES_DRUDDIGON,
        SPECIES_LAPRAS,
        SPECIES_WEAVILE,
        SPECIES_DRAMPA,
        SPECIES_GOOMY,
        SPECIES_ABSOL,
        SPECIES_DOUBLADE,
        SPECIES_NINETALES,
        SPECIES_VULPIX,
        SPECIES_HAUNTER,
        SPECIES_BRAVIARY,
        SPECIES_RHYPERIOR,
        SPECIES_FROSLASS,
        SPECIES_LEAFEON,
        SPECIES_ROSERADE,
        SPECIES_SEVIPER,
        SPECIES_ZANGOOSE,
        SPECIES_STEELIX
    },
[TRAINER_CLASS_TUBER_F] = 
    {
        SPECIES_TENTACOOL,
        SPECIES_SEEL,
        SPECIES_SHELLDER,
        SPECIES_GOLDEEN,
        SPECIES_STARYU,
        SPECIES_LAPRAS,
        SPECIES_VAPOREON,
        SPECIES_CHINCHOU,
        SPECIES_AZURILL,
        SPECIES_SURSKIT,
        SPECIES_FEEBAS,
        SPECIES_SPHEAL,
        SPECIES_LUVDISC,
        SPECIES_PIPLUP,
        SPECIES_SHELLOS,
        SPECIES_FINNEON,
        SPECIES_MANTYKE,
        SPECIES_FRILLISH,
        SPECIES_POPPLIO,
        SPECIES_MAREANIE,
    },
[TRAINER_CLASS_TUBER_M] = 
    {
        SPECIES_HORSEA,
        SPECIES_TOTODILE,
        SPECIES_CHINCHOU,
        SPECIES_WOOPER,
        SPECIES_REMORAID,
        SPECIES_MUDKIP,
        SPECIES_WINGULL,
        SPECIES_AZURILL,
        SPECIES_CARVANHA,
        SPECIES_CLAMPERL,
        SPECIES_PIPLUP,
        SPECIES_SHELLOS,
        SPECIES_FINNEON,
        SPECIES_MANTYKE,
        SPECIES_TYMPOLE,
        SPECIES_TIRTOUGA,
        SPECIES_TYNAMO,
        SPECIES_FROAKIE,
        SPECIES_CLAUNCHER,
        SPECIES_WIMPOD,
    },
[TRAINER_CLASS_SIS_AND_BRO] = 
    {
        SPECIES_NIDORAN_M,
        SPECIES_NIDORAN_F,
        SPECIES_PSYDUCK,
        SPECIES_POLIWAG,
        SPECIES_TENTACOOL,
        SPECIES_SLOWBRO,
        SPECIES_SEEL,
        SPECIES_SHELLDER,
        SPECIES_HORSEA,
        SPECIES_GOLDEEN,
        SPECIES_GYARADOS,
        SPECIES_DRATINI,
        SPECIES_NATU,
        SPECIES_WINGULL,
        SPECIES_MARSHTOMP,
        SPECIES_SPINDA,
        SPECIES_LILEEP,
        SPECIES_DEWOTT,
        SPECIES_TIRTOUGA,
    },
[TRAINER_CLASS_COOLTRAINER] = 
    {
        SPECIES_GOLBAT,
        SPECIES_GROWLITHE,
        SPECIES_HAUNTER,
        SPECIES_ELECTABUZZ,
        SPECIES_MAGMAR,
        SPECIES_GYARADOS,
        SPECIES_SNORLAX,
        SPECIES_AERODACTYL,
        SPECIES_BLISSEY,
        SPECIES_DRATINI,
        SPECIES_LARVITAR,
        SPECIES_SLAKING,
        SPECIES_WALREIN,
        SPECIES_SALAMENCE,
        SPECIES_METANG,
        SPECIES_GABITE,
        SPECIES_INFERNAPE,
        SPECIES_LUCARIO,
        SPECIES_TERRAKION,
        SPECIES_GOODRA,
    },
[TRAINER_CLASS_HEX_MANIAC] = 
    {
        SPECIES_PARASECT,
        SPECIES_SLOWBRO,
        SPECIES_SLOWKING,
        SPECIES_GASTLY,
        SPECIES_DROWZEE,
        SPECIES_CUBONE,
        SPECIES_PORYGON_Z,
        SPECIES_MISDREAVUS,
        SPECIES_WOBBUFFET,
        SPECIES_SABLEYE,
        SPECIES_SPINDA,
        SPECIES_SHEDINJA,
        SPECIES_LUNATONE,
        SPECIES_DUSCLOPS,
        SPECIES_BANETTE,
        SPECIES_ROTOM,
        SPECIES_COFAGRIGUS,
        SPECIES_LAMPENT,
        SPECIES_PHANTUMP,
        SPECIES_MIMIKYU,
    },
[TRAINER_CLASS_LADY] = 
    {
        SPECIES_CHARMELEON,
        SPECIES_CLEFAIRY,
        SPECIES_PERSIAN,
        SPECIES_KANGASKHAN,
        SPECIES_POLITOED,
        SPECIES_LANTURN,
        SPECIES_MISDREAVUS,
        SPECIES_ZIGZAGOON,
        SPECIES_ROSELIA,
        SPECIES_SABLEYE,
        SPECIES_LOPUNNY,
        SPECIES_VESPIQUEN,
        SPECIES_WEAVILE,
        SPECIES_HEATMOR,
        SPECIES_ZOROARK,
        SPECIES_LAMPENT,
        SPECIES_HAXORUS,
        SPECIES_HYDREIGON,
        SPECIES_BRAIXEN,
        SPECIES_AURORUS,
    },
[TRAINER_CLASS_BEAUTY] = 
    {
        SPECIES_CLEFAIRY,
        SPECIES_NINETALES,
        SPECIES_BELLOSSOM,
        SPECIES_FLAAFFY,
        SPECIES_SNUBBULL,
        SPECIES_ESPEON,
        SPECIES_AZUMARILL,
        SPECIES_BEAUTIFLY,
        SPECIES_KIRLIA,
        SPECIES_LUVDISC,
        SPECIES_MILOTIC,
        SPECIES_BUNEARY,
        SPECIES_AUDINO,
        SPECIES_LEAVANNY,
        SPECIES_LILLIGANT,
        SPECIES_WHIMSICOTT,
        SPECIES_BRAIXEN,
        SPECIES_SYLVEON,
        SPECIES_VULPIX,
        SPECIES_PRIMARINA,
    },
[TRAINER_CLASS_RICH_BOY] = 
    {
        SPECIES_CHARMELEON,
        SPECIES_PERSIAN,
        SPECIES_WEAVILE,
        SPECIES_HEATMOR,
        SPECIES_ZOROARK,
        SPECIES_LAMPENT,
        SPECIES_HAXORUS,
        SPECIES_HYDREIGON,
        SPECIES_FROAKIE,
        SPECIES_ROCKRUFF,
        SPECIES_SIGILYPH,
        SPECIES_STOUTLAND,
        SPECIES_SAMUROTT,
        SPECIES_LICKILICKY,
        SPECIES_KINGDRA,
        SPECIES_DONPHAN,
        SPECIES_GABITE,
        SPECIES_LUXRAY,
        SPECIES_STARAPTOR,
        SPECIES_BRAVIARY,
    },
[TRAINER_CLASS_POKEMANIAC] = 
    {
        SPECIES_PRIMARINA,
        SPECIES_VESPIQUEN,
        SPECIES_BRONZONG,
        SPECIES_MUSHARNA,
        SPECIES_DARMANITAN,
        SPECIES_ZORUA,
        SPECIES_GOTHORITA,
        SPECIES_KLINKLANG,
        SPECIES_VIVILLON,
        SPECIES_PYROAR,
        SPECIES_FLOETTE,
        SPECIES_FLABEBE,
        SPECIES_FLORGES,
        SPECIES_MEOWSTIC,
        SPECIES_BINACLE,
        SPECIES_METANG,
        SPECIES_BALTOY,
        SPECIES_CARBINK,
        SPECIES_ORICORIO,
    },
[TRAINER_CLASS_SWIMMER_M] = 
    {
        SPECIES_PSYDUCK,
        SPECIES_POLIWAG,
        SPECIES_TENTACOOL,
        SPECIES_SLOWBRO,
        SPECIES_SEEL,
        SPECIES_KINGDRA,
        SPECIES_LOMBRE,
        SPECIES_WINGULL,
        SPECIES_MARSHTOMP,
        SPECIES_BUIZEL,
        SPECIES_FLOATZEL,
        SPECIES_FLOATZEL,
        SPECIES_FLOATZEL,
        SPECIES_PANPOUR,
        SPECIES_FRILLISH,
        SPECIES_PALPITOAD,
        SPECIES_TIRTOUGA,
        SPECIES_TYNAMO,
        SPECIES_STUNFISK,
        SPECIES_GOLISOPOD,
    },
[TRAINER_CLASS_BLACK_BELT] = 
    {
        SPECIES_HERACROSS,
        SPECIES_TOXICROAK,
        SPECIES_GABITE,
        SPECIES_GALLADE,
        SPECIES_TERRAKION,
        SPECIES_LARVITAR,
        SPECIES_VIGOROTH,
        SPECIES_COMBUSKEN,
        SPECIES_PINSIR,
        SPECIES_SAWK,
        SPECIES_SCYTHER,
        SPECIES_FRAXURE,
        SPECIES_RIOLU,
        SPECIES_CARVANHA,
        SPECIES_TIMBURR,
        SPECIES_MACHOKE,
        SPECIES_SCRAFTY,
        SPECIES_FLAREON,
        SPECIES_LEAFEON,
        SPECIES_BRELOOM,
    },
[TRAINER_CLASS_GUITARIST] = 
    {
        SPECIES_NINJASK,
        SPECIES_ELECTRODE,
        SPECIES_ACCELGOR,
        SPECIES_AERODACTYL,
        SPECIES_TEPIG,
        SPECIES_TREECKO,
        SPECIES_ELECTRIKE,
        SPECIES_JOLTEON,
        SPECIES_ZUBAT,
        SPECIES_NOIBAT,
        SPECIES_ELECTABUZZ,
        SPECIES_NOIBAT,
        SPECIES_WHISMUR,
        SPECIES_PIKACHU,
        SPECIES_HOUNDOUR,
        SPECIES_SWOOBAT,
        SPECIES_JOLTEON,
        SPECIES_KOFFING,
        SPECIES_GRIMER,
        SPECIES_MAGNEMITE,
    },
[TRAINER_CLASS_KINDLER] = 
    {
        SPECIES_SLUGMA,
        SPECIES_NUMEL,
        SPECIES_WINGULL,
        SPECIES_PONYTA,
        SPECIES_CHARMELEON,
        SPECIES_BRAIXEN,
        SPECIES_TORCHIC,
        SPECIES_FLETCHINDER,
        SPECIES_CYNDAQUIL,
        SPECIES_TEPIG,
        SPECIES_CHESPIN,
        SPECIES_PHANTUMP,
        SPECIES_SNOVER,
        SPECIES_TROPIUS,
        SPECIES_PUMPKABOO,
        SPECIES_LITTEN,
        SPECIES_TURTONATOR,
        SPECIES_HOUNDOUR,
        SPECIES_SUNFLORA,
        SPECIES_MAGBY,
    },
[TRAINER_CLASS_CAMPER] = 
    {
        SPECIES_CACNEA,
        SPECIES_GULPIN,
        SPECIES_GLOOM,
        SPECIES_SANDSHREW,
        SPECIES_SWABLU,
        SPECIES_WIGGLYTUFF,
        SPECIES_SHINX,
        SPECIES_NIDORAN_F,
        SPECIES_NIDORAN_M,
        SPECIES_PONYTA,
        SPECIES_SUNFLORA,
        SPECIES_SKIPLOOM,
        SPECIES_MAREEP,
        SPECIES_CUBONE,
        SPECIES_VULPIX,
        SPECIES_WHISMUR,
        SPECIES_BELLSPROUT,
        SPECIES_MUDBRAY,
        SPECIES_SPOINK,
        SPECIES_CLEFAIRY
    },
[TRAINER_CLASS_OLD_COUPLE] = 
    {
        SPECIES_HITMONLEE,
        SPECIES_HITMONCHAN,
        SPECIES_TIMBURR,
        SPECIES_MAKUHITA,
        SPECIES_HAWLUCHA,
        SPECIES_RIOLU,
        SPECIES_HERACROSS,
        SPECIES_ABSOL,
        SPECIES_MAWILE,
        SPECIES_MAWILE,
        SPECIES_COMBUSKEN,
        SPECIES_SWELLOW,
        SPECIES_HITMONTOP,
        SPECIES_GROVYLE,
        SPECIES_MARSHTOMP,
        SPECIES_BRELOOM,
        SPECIES_GALLADE,
        SPECIES_VIRIZION,
        SPECIES_TERRAKION,
        SPECIES_COBALION,
    },
[TRAINER_CLASS_BUG_MANIAC] = 
    {
        SPECIES_JOLTIK,
        SPECIES_VIKAVOLT,
        SPECIES_PINECO,
        SPECIES_BUTTERFREE,
        SPECIES_BEEDRILL,
        SPECIES_GRUBBIN,
        SPECIES_PINSIR,
        SPECIES_SCYTHER,
        SPECIES_YANMEGA,
        SPECIES_SPINARAK,
        SPECIES_SCIZOR,
        SPECIES_SHUCKLE,
        SPECIES_DUSTOX,
        SPECIES_BEAUTIFLY,
        SPECIES_TRAPINCH,
        SPECIES_VENIPEDE,
        SPECIES_DWEBBLE,
        SPECIES_LARVESTA,
        SPECIES_WIMPOD,
        SPECIES_HERACROSS
    },
[TRAINER_CLASS_PSYCHIC] = 
    {
        SPECIES_NATU,
        SPECIES_SIGILYPH,
        SPECIES_METANG,
        SPECIES_KADABRA,
        SPECIES_STARMIE,
        SPECIES_SOLOSIS,
        SPECIES_KIRLIA,
        SPECIES_GOLETT,
        SPECIES_ESPEON,
        SPECIES_SLOWKING,
        SPECIES_COFAGRIGUS,
        SPECIES_UNOWN,
        SPECIES_WYNAUT,
        SPECIES_GOLDUCK,
        SPECIES_ELGYEM,
        SPECIES_EXEGGUTOR,
        SPECIES_GIRAFARIG,
        SPECIES_MEDICHAM,
        SPECIES_SOLROCK,
        SPECIES_LUNATONE
    },
[TRAINER_CLASS_GENTLEMAN] = 
    {
        SPECIES_SABLEYE,
        SPECIES_SPEAROW,
        SPECIES_DUNSPARCE,
        SPECIES_JOLTEON,
        SPECIES_JOLTIK,
        SPECIES_MURKROW,
        SPECIES_PIKIPEK,
        SPECIES_UMBREON,
        SPECIES_ESPEON,
        SPECIES_SYLVEON,
        SPECIES_FLAREON,
        SPECIES_VAPOREON,
        SPECIES_MANECTRIC,
        SPECIES_BRAVIARY,
        SPECIES_FLYGON,
        SPECIES_FLAAFFY,
        SPECIES_SLOWKING,
        SPECIES_DURANT,
        SPECIES_DELCATTY,
        SPECIES_HERDIER
    },
[TRAINER_CLASS_SCHOOL_KID] = 
    {
        SPECIES_KIRLIA,
        SPECIES_LITWICK,
        SPECIES_BUTTERFREE,
        SPECIES_BEAUTIFLY,
        SPECIES_WINGULL,
        SPECIES_DEERLING,
        SPECIES_JIGGLYPUFF,
        SPECIES_EEVEE,
        SPECIES_BELLOSSOM,
        SPECIES_LUVDISC,
        SPECIES_DRIFLOON,
        SPECIES_BLITZLE,
        SPECIES_SWOOBAT,
        SPECIES_WURMPLE,
        SPECIES_STARLY,
        SPECIES_PIDGEY,
        SPECIES_BEEDRILL,
        SPECIES_SHROOMISH,
        SPECIES_PARAS,
        SPECIES_VANILLITE
    },
[TRAINER_CLASS_SR_AND_JR] = 
    {
        SPECIES_ZIGZAGOON,
        SPECIES_MANKEY,
        SPECIES_RATTATA,
        SPECIES_NIDORAN_F,
        SPECIES_NIDORAN_M,
        SPECIES_LINOONE,
        SPECIES_RATICATE,
        SPECIES_NIDORINA,
        SPECIES_NIDORINO,
        SPECIES_SLAKOTH,
        SPECIES_NUMEL,
        SPECIES_ROSELIA,
        SPECIES_ROSERADE,
        SPECIES_CAMERUPT,
        SPECIES_VIGOROTH,
        SPECIES_SPINDA,
        SPECIES_MARILL,
        SPECIES_PICHU,
        SPECIES_PIKACHU,   
        SPECIES_MEGANIUM,   
    },
[TRAINER_CLASS_POKEFAN] = 
    {
        SPECIES_DEDENNE,
        SPECIES_EMOLGA,
        SPECIES_TEDDIURSA,
        SPECIES_STUFFUL,
        SPECIES_SNUBBULL,
        SPECIES_FROSLASS,
        SPECIES_SYLVEON,
        SPECIES_BUNEARY,
        SPECIES_PIKACHU,
        SPECIES_CUBCHOO,
        SPECIES_CLEFAIRY,
        SPECIES_GLAMEOW,
        SPECIES_PURRLOIN,
        SPECIES_HOUNDOUR,
        SPECIES_SKITTY,
        SPECIES_POPPLIO,
        SPECIES_TURTWIG,
        SPECIES_SKITTY,
        SPECIES_SYLVEON,
        SPECIES_JIGGLYPUFF,

    },
[TRAINER_CLASS_EXPERT] = 
    {
        SPECIES_SAWK,
        SPECIES_THROH,
        SPECIES_TIMBURR,
        SPECIES_MAKUHITA,
        SPECIES_HAWLUCHA,
        SPECIES_RIOLU,
        SPECIES_HERACROSS,
        SPECIES_ABSOL,
        SPECIES_MAWILE,
        SPECIES_MAWILE,
        SPECIES_COMBUSKEN,
        SPECIES_SWELLOW,
        SPECIES_HITMONTOP,
        SPECIES_GROVYLE,
        SPECIES_MARSHTOMP,
        SPECIES_BRELOOM,
        SPECIES_GALLADE,
        SPECIES_VIRIZION,
        SPECIES_TERRAKION,
        SPECIES_COBALION,
    },
[TRAINER_CLASS_YOUNGSTER] = 
    {
        SPECIES_CHARJABUG,
        SPECIES_CATERPIE,
        SPECIES_WEEDLE,
        SPECIES_ROCKRUFF,
        SPECIES_INKAY,
        SPECIES_EMOLGA,
        SPECIES_TAUROS,
        SPECIES_RATTATA,
        SPECIES_RATTATA,
        SPECIES_RATTATA,
        SPECIES_EKANS,
        SPECIES_TRAPINCH,
        SPECIES_MACHOP,
        SPECIES_FURRET,
        SPECIES_HOOTHOOT,
        SPECIES_BUNEARY,
        SPECIES_PIDGEY,
        SPECIES_SPEAROW,
        SPECIES_NIDORAN_M,
        SPECIES_BUIZEL
    },
[TRAINER_CLASS_FISHERMAN] = 
    {
        SPECIES_BARBARACLE,
        SPECIES_TIRTOUGA,
        SPECIES_DRATINI,
        SPECIES_GYARADOS,
        SPECIES_FEEBAS,
        SPECIES_TENTACOOL,
        SPECIES_LANTURN,
        SPECIES_POLIWAG,
        SPECIES_GOLDEEN,
        SPECIES_TYNAMO,
        SPECIES_EELEKTRIK,
        SPECIES_WAILMER,
        SPECIES_REMORAID,
        SPECIES_CARVANHA,
        SPECIES_WHISCASH,
        SPECIES_LUVDISC,
        SPECIES_FINNEON,
        SPECIES_SEADRA,
        SPECIES_STARYU,
        SPECIES_SHELLDER
    },
[TRAINER_CLASS_TRIATHLETE] = 
    {
        SPECIES_VOLTORB,
        SPECIES_MAGNEMITE,
        SPECIES_KLANG,
        SPECIES_WAILMER,
        SPECIES_SEADRA,
        SPECIES_MARILL,
        SPECIES_DODUO,
        SPECIES_FEAROW,
        SPECIES_GROWLITHE,
        SPECIES_MACHOP,
        SPECIES_STARYU,
        SPECIES_TENTACOOL,
        SPECIES_PSYDUCK,
        SPECIES_SPHEAL,
        SPECIES_CROCONAW,
        SPECIES_REMORAID,
        SPECIES_EELEKTRIK,
        SPECIES_ROTOM,
        SPECIES_DEWOTT,
        SPECIES_TYNAMO
    },
[TRAINER_CLASS_DRAGON_TAMER] = 
    {
        SPECIES_GIBLE,
        SPECIES_GYARADOS,
        SPECIES_VIBRAVA,
        SPECIES_DRAGONAIR,
        SPECIES_SEADRA,
        SPECIES_BAGON,
        SPECIES_NOIBAT,
        SPECIES_AXEW,
        SPECIES_GOOMY,
        SPECIES_DEINO,
        SPECIES_TYRUNT,
        SPECIES_DRAMPA,
        SPECIES_TURTONATOR,
        SPECIES_CHARIZARD,
        SPECIES_SKARMORY,
        SPECIES_KINGDRA,
        SPECIES_DRAGONAIR,
        SPECIES_NOIBAT,
        SPECIES_AXEW,
        SPECIES_GIBLE
    },
[TRAINER_CLASS_BIRD_KEEPER] = 
    {
        SPECIES_NATU,
        SPECIES_SIGILYPH,
        SPECIES_PIDGEY,
        SPECIES_SPEAROW,
        SPECIES_TAILLOW,
        SPECIES_SWABLU,
        SPECIES_TROPIUS,
        SPECIES_TOGETIC,
        SPECIES_MURKROW,
        SPECIES_HOOTHOOT,
        SPECIES_STARLY,
        SPECIES_SKARMORY,
        SPECIES_FLETCHLING,
        SPECIES_FARFETCHD,
        SPECIES_DELIBIRD,
        SPECIES_DUCKLETT,
        SPECIES_CHATOT,
        SPECIES_ORICORIO,
        SPECIES_MANTYKE,
        SPECIES_PIDOVE
    },
[TRAINER_CLASS_NINJA_BOY] = 
    {
        SPECIES_KOFFING,
        SPECIES_NINJASK,
        SPECIES_GOLBAT,
        SPECIES_VENONAT,
        SPECIES_MOTHIM,
        SPECIES_STUNKY,
        SPECIES_SKORUPI,
        SPECIES_SKARMORY,
        SPECIES_SEVIPER,
        SPECIES_ARBOK,
        SPECIES_MAREANIE,
        SPECIES_DUSTOX,
        SPECIES_BUTTERFREE,
        SPECIES_SCYTHER,
        SPECIES_BEEDRILL,
        SPECIES_CROAGUNK,
        SPECIES_GRIMER,
        SPECIES_SKRELP,
        SPECIES_GLOOM,
        SPECIES_GASTLY
    },
[TRAINER_CLASS_BATTLE_GIRL] = 
    {
        SPECIES_THROH,
        SPECIES_TIMBURR,
        SPECIES_MEDITITE,
        SPECIES_MIENFOO,
        SPECIES_HAWLUCHA,
        SPECIES_SAWK,
        SPECIES_SCRAFTY,
        SPECIES_RIOLU,
        SPECIES_HITMONTOP,
        SPECIES_MACHOP,
        SPECIES_POLIWHIRL,
        SPECIES_MANKEY,
        SPECIES_HITMONTOP,
        SPECIES_BUNNELBY,
        SPECIES_LOPUNNY,
        SPECIES_COMBUSKEN,
        SPECIES_PANCHAM,
        SPECIES_HERACROSS,
        SPECIES_CROAGUNK,
        SPECIES_PIGNITE
    },
[TRAINER_CLASS_PARASOL_LADY] = 
    {
        SPECIES_CASTFORM,
        SPECIES_STARYU,
        SPECIES_SPHEAL,
        SPECIES_SEEL,
        SPECIES_NUMEL,
        SPECIES_TYMPOLE,
        SPECIES_SURSKIT,
        SPECIES_ALOMOMOLA,
        SPECIES_HIPPOWDON,
        SPECIES_SEAKING,
        SPECIES_WOOPER,
        SPECIES_BUIZEL,
        SPECIES_SUNFLORA,
        SPECIES_SUNKERN,
        SPECIES_CACNEA,
        SPECIES_NUMEL,
        SPECIES_ZIGZAGOON,
        SPECIES_JIGGLYPUFF,
        SPECIES_ROSELIA,
        SPECIES_JYNX
    },
[TRAINER_CLASS_SWIMMER_F] = 
    {
        SPECIES_BRUXISH,
        SPECIES_SURSKIT,
        SPECIES_WINGULL,
        SPECIES_BASCULIN,
        SPECIES_PSYDUCK,
        SPECIES_CLAMPERL,
        SPECIES_TENTACOOL,
        SPECIES_REMORAID,
        SPECIES_MAREANIE,
        SPECIES_FINNEON,
        SPECIES_PYUKUMUKU,
        SPECIES_LUMINEON,
        SPECIES_GOLDEEN,
        SPECIES_GYARADOS,
        SPECIES_STARYU,
        SPECIES_CORSOLA,
        SPECIES_SHELLDER,
        SPECIES_CRABRAWLER,
        SPECIES_BARBARACLE,
        SPECIES_BARBOACH
    },
[TRAINER_CLASS_PICNICKER] = 
    {
        SPECIES_CACNEA,
        SPECIES_GULPIN,
        SPECIES_GLOOM,
        SPECIES_SANDSHREW,
        SPECIES_SWABLU,
        SPECIES_WIGGLYTUFF,
        SPECIES_SHINX,
        SPECIES_NIDORAN_F,
        SPECIES_NIDORAN_M,
        SPECIES_PONYTA,
        SPECIES_SUNFLORA,
        SPECIES_SKIPLOOM,
        SPECIES_MAREEP,
        SPECIES_EEVEE,
        SPECIES_VULPIX,
        SPECIES_WHISMUR,
        SPECIES_BELLSPROUT,
        SPECIES_CHERUBI,
        SPECIES_SPOINK,
        SPECIES_CLEFAIRY
    },
[TRAINER_CLASS_TWINS] = 
    {
        SPECIES_COTTONEE,
        SPECIES_PETILIL,
        SPECIES_CORSOLA,
        SPECIES_LUVDISC,
        SPECIES_IGGLYBUFF,
        SPECIES_MINUN,
        SPECIES_PLUSLE,
        SPECIES_LOTAD,
        SPECIES_SEEDOT,
        SPECIES_WURMPLE,
        SPECIES_AROMATISSE,
        SPECIES_SLURPUFF,
        SPECIES_SUNKERN,
        SPECIES_SWABLU,
        SPECIES_ELEKID,
        SPECIES_MARILL,
        SPECIES_PURRLOIN,
        SPECIES_SEWADDLE,
        SPECIES_PHANPY,
        SPECIES_MIMIKYU
    },
[TRAINER_CLASS_SAILOR] = 
    {
        SPECIES_WOOPER,
        SPECIES_WAILMER,
        SPECIES_WINGULL,
        SPECIES_MACHOP,
        SPECIES_MAKUHITA,
        SPECIES_MIENFOO,
        SPECIES_THROH,
        SPECIES_SAWK,
        SPECIES_HITMONTOP,
        SPECIES_TENTACOOL,
        SPECIES_FRILLISH,
        SPECIES_LAPRAS,
        SPECIES_KRABBY,
        SPECIES_HORSEA,
        SPECIES_SLOWPOKE,
        SPECIES_GYARADOS,
        SPECIES_POLIWAG,
        SPECIES_MANKEY,
        SPECIES_PSYDUCK,
        SPECIES_SEEL
    },
[TRAINER_CLASS_COLLECTOR] = 
    {
        SPECIES_LARVESTA,
        SPECIES_LARVITAR,
        SPECIES_FLABEBE,
        SPECIES_PASSIMIAN,
        SPECIES_DRAMPA,
        SPECIES_MUNCHLAX,
        SPECIES_BAGON,
        SPECIES_SEVIPER,
        SPECIES_ARBOK,
        SPECIES_ZANGOOSE,
        SPECIES_DURANT,
        SPECIES_HERACROSS,
        SPECIES_PORYGON,
        SPECIES_GABITE,
        SPECIES_JOLTEON,
        SPECIES_UMBREON,
        SPECIES_ESPEON,
        SPECIES_SKORUPI,
        SPECIES_TROPIUS,
        SPECIES_CROAGUNK
    },
[TRAINER_CLASS_PKMN_BREEDER] = 
    {
        SPECIES_WHISMUR,
        SPECIES_ZIGZAGOON,
        SPECIES_MAKUHITA,
        SPECIES_TAILLOW,
        SPECIES_ROSELIA,
        SPECIES_WINGULL,
        SPECIES_MORELULL,
        SPECIES_SHROOMISH,
        SPECIES_ARON,
        SPECIES_SKITTY,
        SPECIES_TOGEPI,
        SPECIES_MR_MIME,
        SPECIES_NIDORAN_F,
        SPECIES_NIDORAN_M,
        SPECIES_PIKACHU,
        SPECIES_STUNKY,
        SPECIES_MAGBY,
        SPECIES_ELEKID,
        SPECIES_SWABLU,
        SPECIES_DUCKLETT
    },
[TRAINER_CLASS_PKMN_RANGER] = 
    {
        SPECIES_SEEDOT,
        SPECIES_LOTAD,
        SPECIES_ROSELIA,
        SPECIES_GLOOM,
        SPECIES_BELLOSSOM,
        SPECIES_SHROOMISH,
        SPECIES_KECLEON,
        SPECIES_CACTURNE,
        SPECIES_SWABLU,
        SPECIES_MARACTUS,
        SPECIES_MAWILE,
        SPECIES_TANGELA,
        SPECIES_EXEGGCUTE,
        SPECIES_BELLSPROUT,
        SPECIES_SKARMORY,
        SPECIES_PHANPY,
        SPECIES_PHANTUMP,
        SPECIES_LICKITUNG,
        SPECIES_PRINPLUP,
        SPECIES_TRAPINCH
    },
[TRAINER_CLASS_TEAM_MAGMA] = 
    {
        SPECIES_POOCHYENA,
        SPECIES_NUMEL,
        SPECIES_SLUGMA,
        SPECIES_ZUBAT,
        SPECIES_NOIBAT,
        SPECIES_SIMISEAR,
        SPECIES_BALTOY,
        SPECIES_GASTLY,
        SPECIES_KOFFING,
        SPECIES_RATTATA,
        SPECIES_CHARMELEON,
        SPECIES_MAGMAR,
        SPECIES_FLAREON,
        SPECIES_QUILAVA,
        SPECIES_TORKOAL,
        SPECIES_TORRACAT,
        SPECIES_MONFERNO,
        SPECIES_FLETCHINDER,
        SPECIES_LITLEO,
        SPECIES_BRAIXEN
    },
[TRAINER_CLASS_MAGMA_ADMIN] = 
    {
        SPECIES_MIGHTYENA,
        SPECIES_INCINEROAR,
        SPECIES_MAGCARGO,
        SPECIES_CROBAT,
        SPECIES_NOIBAT,
        SPECIES_BRAIXEN,
        SPECIES_MIGHTYENA,
        SPECIES_HAUNTER,
        SPECIES_WEEZING,
        SPECIES_RATICATE,
        SPECIES_CHARMELEON,
        SPECIES_MAGMAR,
        SPECIES_FLAREON,
        SPECIES_QUILAVA,
        SPECIES_TORKOAL,
        SPECIES_TORRACAT,
        SPECIES_MONFERNO,
        SPECIES_FLETCHINDER,
        SPECIES_PYROAR,
        SPECIES_BRAIXEN
    },
[TRAINER_CLASS_MAGMA_LEADER] = 
    {
        SPECIES_MIGHTYENA,
        SPECIES_INCINEROAR,
        SPECIES_MAGCARGO,
        SPECIES_CROBAT,
        SPECIES_NOIBAT,
        SPECIES_BRAIXEN,
        SPECIES_MIGHTYENA,
        SPECIES_HAUNTER,
        SPECIES_WEEZING,
        SPECIES_RATICATE,
        SPECIES_CHARMELEON,
        SPECIES_MAGMAR,
        SPECIES_FLAREON,
        SPECIES_QUILAVA,
        SPECIES_TORKOAL,
        SPECIES_TORRACAT,
        SPECIES_MONFERNO,
        SPECIES_FLETCHINDER,
        SPECIES_PYROAR,
        SPECIES_BRAIXEN
    },
[TRAINER_CLASS_LASS] = 
    {
        SPECIES_LUVDISC,
        SPECIES_GOLDEEN,
        SPECIES_WAILMER,
        SPECIES_LOTAD,
        SPECIES_SHROOMISH,
        SPECIES_TAILLOW,
        SPECIES_SKITTY,
        SPECIES_MARILL,
        SPECIES_ODDISH,
        SPECIES_ZIGZAGOON,
        SPECIES_HOPPIP,
        SPECIES_RATTATA,
        SPECIES_CLEFAIRY,
        SPECIES_PIDGEY,
        SPECIES_BELLSPROUT,
        SPECIES_NIDORAN_F,
        SPECIES_JIGGLYPUFF,
        SPECIES_CHERUBI,
        SPECIES_PACHIRISU,
        SPECIES_MISDREAVUS
    },
[TRAINER_CLASS_BUG_CATCHER] = 
    {
        SPECIES_WEEDLE,
        SPECIES_WURMPLE,
        SPECIES_SURSKIT,
        SPECIES_CATERPIE,
        SPECIES_PINSIR,
        SPECIES_PINECO,
        SPECIES_VOLBEAT,
        SPECIES_ILLUMISE,
        SPECIES_KRICKETOT,
        SPECIES_BURMY,
        SPECIES_SPINARAK,
        SPECIES_SHEDINJA,
        SPECIES_SHELGON,
        SPECIES_NINCADA,
        SPECIES_SCATTERBUG,
        SPECIES_PARAS,
        SPECIES_SCYTHER,
        SPECIES_LEDYBA,
        SPECIES_SPINARAK,
        SPECIES_YANMA
    },
[TRAINER_CLASS_HIKER] = 
    {
        SPECIES_GEODUDE,
        SPECIES_ROGGENROLA,
        SPECIES_NOSEPASS,
        SPECIES_SUDOWOODO,
        SPECIES_ONIX,
        SPECIES_PHANPY,
        SPECIES_MUDBRAY,
        SPECIES_LARVITAR,
        SPECIES_GLIGAR,
        SPECIES_LILEEP,
        SPECIES_ANORITH,
        SPECIES_TERRAKION,
        SPECIES_RHYHORN,
        SPECIES_ARON,
        SPECIES_RELICANTH,
        SPECIES_SHUCKLE,
        SPECIES_DWEBBLE,
        SPECIES_TIRTOUGA,
        SPECIES_SANDSHREW,
        SPECIES_CUBONE
    },
[TRAINER_CLASS_YOUNG_COUPLE] = 
    {
        SPECIES_PLUSLE,
        SPECIES_MINUN,
        SPECIES_SKITTY,
        SPECIES_ROCKRUFF,
        SPECIES_MARILL,
        SPECIES_PICHU,
        SPECIES_VOLBEAT,
        SPECIES_ILLUMISE,
        SPECIES_LUVDISC,
        SPECIES_WEEDLE,
        SPECIES_WURMPLE,
        SPECIES_ELECTRIKE,
        SPECIES_MAREEP,
        SPECIES_HOOTHOOT,
        SPECIES_HOUNDOUR,
        SPECIES_BUNEARY,
        SPECIES_WOOPER,
        SPECIES_MUDKIP,
        SPECIES_TORCHIC,
        SPECIES_DIGLETT
    },
[TRAINER_CLASS_DEVON_ENFORCER] = 
    { 
        SPECIES_LILLIPUP,
        SPECIES_MEOWTH, 
        SPECIES_AIPOM, 
        SPECIES_GROWLITHE, 
        SPECIES_SNUBBULL, 
        SPECIES_MEOWSTIC, 
        SPECIES_PURRLOIN,
        SPECIES_PURRLOIN, 
        SPECIES_TAILLOW, 
        SPECIES_RATTATA, 
        SPECIES_CHANSEY, 
        SPECIES_SENTRET, 
        SPECIES_TEDDIURSA, 
        SPECIES_MILTANK, 
        SPECIES_ZIGZAGOON, 
        SPECIES_SKITTY,
        SPECIES_MINCCINO,
        SPECIES_CHIKORITA,
        SPECIES_SEEDOT,
        SPECIES_SHROOMISH
    },
};

#endif