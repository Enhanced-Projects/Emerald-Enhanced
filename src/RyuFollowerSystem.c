//Follower related code
#include "global.h"
#include "strings.h"
#include "event_data.h"
#include "string_util.h"
#include "overworld_notif.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "random.h"
void RyuBufferAttendantName (void)
{
    u16 attendant = VarGet(VAR_RYU_ATTENDANT_ID);

    switch(attendant)
    {
            case FOLLOWER_LANETTE:
                StringCopy(gStringVar1, (const u8[])_("Lanette"));
                break;
	        case FOLLOWER_MINNIE:
                StringCopy(gStringVar1, (const u8[])_("Minnie"));
                break;
	        case FOLLOWER_DAWN:
                StringCopy(gStringVar1, (const u8[])_("Dawn"));
                break;
	        case FOLLOWER_BRENDAN:
                StringCopy(gStringVar1, (const u8[])_("Brendan"));
                break;
	        case FOLLOWER_LEAF:
                StringCopy(gStringVar1, (const u8[])_("Leaf"));
                break;
	        case FOLLOWER_COURTNEY:
                StringCopy(gStringVar1, (const u8[])_("Courtney"));
                break;
	        case FOLLOWER_SHELLY:
                StringCopy(gStringVar1, (const u8[])_("Shelly"));
                break;
	        case FOLLOWER_JOY:
                StringCopy(gStringVar1, (const u8[])_("Joy"));
                break;
	        case FOLLOWER_MAY:
                StringCopy(gStringVar1, (const u8[])_("May"));
                break;
	        case FOLLOWER_LUCY:
                StringCopy(gStringVar1, (const u8[])_("Lucy"));
                break;
	        case FOLLOWER_MOM:
                StringCopy(gStringVar1, (const u8[])_("Mom"));
                break;
	        case 0xFFFF:
                StringCopy(gStringVar1, (const u8[])_("None"));
                break;
    }

}

void RyuDebug_ShowActiveFollower (void)
{
    if (FlagGet(FLAG_RYU_HAS_FOLLOWER))
    {
        switch (VarGet(VAR_RYU_FOLLOWER_ID))
        {
            case FOLLOWER_MINNIE:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}Minnie{COLOR LIGHT_BLUE}{SHADOW RED}               all resist {UP_ARROW} 5%.")));
                return;
            case FOLLOWER_LANETTE:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}Lanette{COLOR LIGHT_BLUE}{SHADOW RED}                5% capture boost.")));
                return;
            case FOLLOWER_SHELLY:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}Shelly{COLOR LIGHT_BLUE}{SHADOW RED}                {TYPE_ICON_DARK}/{TYPE_ICON_WATE} dmg {UP_ARROW} 10%.")));
                return;
            case FOLLOWER_DAWN:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}{RIVAL}{COLOR LIGHT_BLUE}{SHADOW RED}                15% money bonus.")));
                return;
            case FOLLOWER_BRENDAN:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}{RIVAL}{COLOR LIGHT_BLUE}{SHADOW RED}                15% money bonus.")));
                return;
            case FOLLOWER_LEAF:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}Leaf{COLOR LIGHT_BLUE}{SHADOW RED}                {TYPE_ICON_FIRE}/{TYPE_ICON_WATE}/{TYPE_ICON_GRAS} resist {UP_ARROW} 10%.")));
                return;
            case FOLLOWER_COURTNEY:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}Courtney{COLOR LIGHT_BLUE}{SHADOW RED}                {TYPE_ICON_DARK}/{TYPE_ICON_FIRE} dmg {UP_ARROW} 10%.")));
                return;
            case FOLLOWER_JOY:
                StringCopy(gStringVar1, ((const u8[])_("          No in-battle bonus.")));
                return;
            case FOLLOWER_MAY:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}May{COLOR LIGHT_BLUE}{SHADOW RED}                {TYPE_ICON_FAIR}/{TYPE_ICON_FIGH} dmg {UP_ARROW} 10%.")));
                return;
            case FOLLOWER_LUCY:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}Lucy{COLOR LIGHT_BLUE}{SHADOW RED}                {TYPE_ICON_POIS}/{TYPE_ICON_DRAG} dmg {UP_ARROW} 10%.")));
                return;
            case FOLLOWER_MOM:
                StringCopy(gStringVar1, ((const u8[]) _("{COLOR LIGHT_RED}{SHADOW RED}Mom{COLOR LIGHT_BLUE}{SHADOW RED}                Active heal in battle.")));
                return;
        }
        StringCopy(gStringVar1, ((const u8[])_("                 No companion bonus.")));
        return;
    }
    else 
    {
        StringCopy(gStringVar1, ((const u8[]) _("No companion.")));
        return;
    }
}

void RyuBufferFollowerName (void) //This function buffers the current follower's name in STR_VAR_1
{
    u16 companion = VarGet(VAR_RYU_FOLLOWER_ID);

    switch(companion)
    {
            case FOLLOWER_LANETTE:
                StringCopy(gStringVar1, (const u8[])_("Lanette"));
                break;
	        case FOLLOWER_MINNIE:
                StringCopy(gStringVar1, (const u8[])_("Minnie"));
                break;
	        case FOLLOWER_DAWN:
                StringCopy(gStringVar1, (const u8[])_("Dawn"));
                break;
	        case FOLLOWER_BRENDAN:
                StringCopy(gStringVar1, (const u8[])_("Brendan"));
                break;
	        case FOLLOWER_LEAF:
                StringCopy(gStringVar1, (const u8[])_("Leaf"));
                break;
	        case FOLLOWER_COURTNEY:
                StringCopy(gStringVar1, (const u8[])_("Courtney"));
                break;
	        case FOLLOWER_SHELLY:
                StringCopy(gStringVar1, (const u8[])_("Shelly"));
                break;
	        case FOLLOWER_JOY:
                StringCopy(gStringVar1, (const u8[])_("Joy"));
                break;
	        case FOLLOWER_MAY:
                StringCopy(gStringVar1, (const u8[])_("May"));
                break;
	        case FOLLOWER_LUCY:
                StringCopy(gStringVar1, (const u8[])_("Lucy"));
                break;
	        case FOLLOWER_MOM:
                StringCopy(gStringVar1, (const u8[])_("Mom"));
                break;
	        case 0xFFFF:
                StringCopy(gStringVar1, (const u8[])_("None"));
                break;
    }

}

// This function fills in the necessary temporary variables for setting up partner multibattles
int RyuFollowerToTrainerID(void)
{
    if (FlagGet(FLAG_RYU_HAS_FOLLOWER))
    {
        switch (VarGet(VAR_RYU_FOLLOWER_ID))
        {
        case FOLLOWER_MINNIE:
            gSpecialVar_0x8008 = TRAINER_REL_MINNIE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_MINNIE;
            return 1;//loaded this follower into the necessary variables to start a follower battle
        case FOLLOWER_LANETTE:
            gSpecialVar_0x8008 = TRAINER_REL_LANETTE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LANETTE; 
            return 1;
        case FOLLOWER_SHELLY:
            gSpecialVar_0x8008 = TRAINER_REL_SHELLY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_SHELLY;
            return 1;
        case FOLLOWER_DAWN:
            gSpecialVar_0x8008 = TRAINER_REL_DAWN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_DAWN;
            return 1;
        case FOLLOWER_BRENDAN:
            gSpecialVar_0x8008 = TRAINER_REL_BRENDAN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_BRENDAN;
            return 1;
        case FOLLOWER_LEAF:
            gSpecialVar_0x8008 = TRAINER_REL_LEAF;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LEAF;
            return 1;
        case FOLLOWER_COURTNEY:
            gSpecialVar_0x8008 = TRAINER_REL_COURTNEY_2;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_COURTNEY;
            return 1;
        case FOLLOWER_JOY:
            gSpecialVar_0x8008 = TRAINER_REL_NURSE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_NURSE;
            return 1;
        case FOLLOWER_MAY:
            gSpecialVar_0x8008 = TRAINER_REL_MAY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY;
            return 1;
        case FOLLOWER_LUCY:
            gSpecialVar_0x8008 = TRAINER_REL_LUCY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LUCY;
            return 1;
        case FOLLOWER_MOM:
            gSpecialVar_0x8008 = TRAINER_REL_MOM;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_MOM;
            return 1;
        case FOLLOWER_GLADION:
            gSpecialVar_0x8008 = TRAINER_REL_GLADION;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_GLADION;
            return 1;
        case FOLLOWER_LILLIE:
            gSpecialVar_0x8008 = TRAINER_REL_LILLIE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LILLIE;
            return 1;
        }
        return 2; //follower wasn't in the above list, probably non combat
    }
    return 4; //follower flag was not set, but a multibattle was attempted anyway
}

void RyuBufferCompanionParty(void)
{
    if ((gSaveBlock2Ptr->CompanionParty[0].speciesId == SPECIES_BIDOOF) &&
        (gSaveBlock2Ptr->CompanionParty[1].speciesId == SPECIES_BIDOOF) &&
        (gSaveBlock2Ptr->CompanionParty[2].speciesId == SPECIES_BIDOOF))
    {
     gSpecialVar_0x8002 = 777;
    }
    GetSpeciesName(gStringVar1, gSaveBlock2Ptr->CompanionParty[0].speciesId);    
    GetSpeciesName(gStringVar2, gSaveBlock2Ptr->CompanionParty[1].speciesId);    
    GetSpeciesName(gStringVar3, gSaveBlock2Ptr->CompanionParty[2].speciesId);    
}


struct gRyuCompanionMon
{
    u16 speciesId;
    u16 heldItem;
    u16 moves[4];
    u8 abilityNum;
};


const struct gRyuCompanionMon FollowerMinnieMons[10] = 
{
    {
        .speciesId = SPECIES_BEWEAR,
        .moves = {MOVE_PLAY_ROUGH, MOVE_DOUBLE_KICK, MOVE_MEGA_KICK, MOVE_NONE},
        .heldItem = ITEM_SILK_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_ALTARIA,
        .moves = {MOVE_ROOST, MOVE_HYPER_VOICE, MOVE_DRAGON_BREATH, MOVE_THUNDERBOLT},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_DOUBLE_EDGE, MOVE_PLAY_ROUGH, MOVE_CHARM},
        .heldItem = ITEM_SITRUS_BERRY,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_RAPIDASH,
        .moves = {MOVE_JUMP_KICK, MOVE_HIGH_HORSEPOWER, MOVE_FLARE_BLITZ, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_ARCANINE,
        .moves = {MOVE_FLARE_BLITZ, MOVE_WILD_CHARGE, MOVE_PLAY_ROUGH, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_PYROAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_CHARM, MOVE_HYPER_VOICE, MOVE_NONE},
        .heldItem = ITEM_METRONOME,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_LINOONE,
        .moves = {MOVE_PLAY_ROUGH, MOVE_DOUBLE_EDGE, MOVE_COVET, MOVE_SLASH},
        .heldItem = ITEM_SILK_SCARF,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_URSARING,
        .moves = {MOVE_PLAY_ROUGH, MOVE_SLASH, MOVE_NIGHT_SLASH, MOVE_SHADOW_CLAW},
        .heldItem = ITEM_SITRUS_BERRY,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_DRAMPA,
        .moves = {MOVE_DRAGON_BREATH, MOVE_HYPER_VOICE, MOVE_HYPER_BEAM, MOVE_GLARE},
        .heldItem = ITEM_SILK_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_MUDSDALE,
        .moves = {MOVE_PLAY_ROUGH, MOVE_HIGH_HORSEPOWER, MOVE_ROCK_SLIDE, MOVE_STOMP},
        .heldItem = ITEM_CHOICE_BAND,
        .abilityNum = 1
    },

};

const struct gRyuCompanionMon FollowerLanetteMons[10] = 
{
    {
        .speciesId = SPECIES_ROTOM,
        .moves = {MOVE_DISCHARGE, MOVE_SHADOW_BALL, MOVE_VOLT_SWITCH, MOVE_UPROAR},
        .heldItem = ITEM_CHOICE_SPECS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_RAICHU,
        .moves = {MOVE_EXTREME_SPEED, MOVE_DISCHARGE, MOVE_SECRET_POWER, MOVE_FLY},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_ZEBSTRIKA,
        .moves = {MOVE_FLARE_BLITZ, MOVE_VOLT_TACKLE, MOVE_JUMP_KICK, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_PORYGON_Z,
        .moves = {MOVE_TECHNO_BLAST, MOVE_DARK_PULSE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_MAGNEZONE,
        .moves = {MOVE_DISCHARGE, MOVE_FLASH_CANNON, MOVE_LIGHT_SCREEN, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_HELIOLISK,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HYPER_VOICE, MOVE_NASTY_PLOT, MOVE_SIGNAL_BEAM},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_SIGNAL_BEAM, MOVE_CHARGE_BEAM, MOVE_CHARGE},
        .heldItem = ITEM_MAGNET,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_LUXRAY,
        .moves = {MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_OVERHEAT, MOVE_BULLET_PUNCH, MOVE_WORK_UP},
        .heldItem = ITEM_BOXING_GLOVE,
        .abilityNum = 1
    },
};

const struct gRyuCompanionMon FollowerShellyMons[10] = 
{
    {
        .speciesId = SPECIES_PRIMARINA,
        .moves = {MOVE_SPARKLING_ARIA, MOVE_MOONBLAST, MOVE_SCALD, MOVE_AQUA_RING},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_JELLICENT,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_HEX, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_CRABHAMMER, MOVE_AGILITY, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_SHELL_BELL,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_PALOSSAND,
        .moves = {MOVE_SHADOW_BALL, MOVE_EARTH_POWER, MOVE_SHORE_UP, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_VAPOREON,
        .moves = {MOVE_AQUA_RING, MOVE_SCALD, MOVE_PROTECT, MOVE_ICE_BEAM},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_FERALIGATR,
        .moves = {MOVE_DRAGON_DANCE, MOVE_CRUNCH, MOVE_WATERFALL, MOVE_HYDRO_CANNON},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_CLAWITZER,
        .moves = {MOVE_HYDRO_CANNON, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SPECS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_AZUMARILL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_SUPERPOWER, MOVE_LIQUIDATION, MOVE_AQUA_JET},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_OCTILLERY,
        .moves = {MOVE_BULLET_SEED, MOVE_OCTAZOOKA, MOVE_HYDRO_PUMP, MOVE_ROCK_BLAST},
        .heldItem = ITEM_KINGS_ROCK,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_CARRACOSTA,
        .moves = {MOVE_SHELL_SMASH, MOVE_ROCK_SLIDE, MOVE_WATERFALL, MOVE_AQUA_JET},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .abilityNum = 1
    },
};

const struct gRyuCompanionMon FollowerDawnMons[10] = 
{
    {
        .speciesId = SPECIES_SYLVEON,
        .moves = {MOVE_ATTRACT, MOVE_HYPER_VOICE, MOVE_PSYCHIC, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_SWAMPERT,
        .moves = {MOVE_STEALTH_ROCK, MOVE_HAMMER_ARM, MOVE_EARTHQUAKE, MOVE_LIQUIDATION},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_FROSLASS,
        .moves = {MOVE_SHADOW_BALL, MOVE_CAPTIVATE, MOVE_BLIZZARD, MOVE_HAIL},
        .heldItem = ITEM_BRIGHT_POWDER,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TOGEKISS,
        .moves = {MOVE_THUNDER_WAVE, MOVE_AURA_SPHERE, MOVE_AIR_SLASH, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_MAWILE,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE, MOVE_SUBSTITUTE, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_GARDEVOIR,
        .moves = {MOVE_ATTRACT, MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_MIMIKYU,
        .moves = {MOVE_SWORDS_DANCE, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_REAPING_BLOW},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_LEECH_SEED, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_SITRUS_BERRY,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_AQUA_RING, MOVE_ATTRACT, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_QUAGSIRE,
        .moves = {MOVE_CURSE, MOVE_SLACK_OFF, MOVE_EARTHQUAKE, MOVE_LIQUIDATION},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 2
    },
};

const struct gRyuCompanionMon FollowerBrendanMons[10] = 
{
    {
        .speciesId = SPECIES_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_MACH_PUNCH, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_BLACK_BELT,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_LUCARIO,
        .moves = {MOVE_METEOR_MASH, MOVE_CLOSE_COMBAT, MOVE_DRAIN_PUNCH, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_ACROBATICS, MOVE_EARTHQUAKE, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_FLYING_GEM,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_RAMPARDOS,
        .moves = {MOVE_HEAD_SMASH, MOVE_WILD_CHARGE, MOVE_FLARE_BLITZ, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_WEAVILE,
        .moves = {MOVE_ICE_SHARD, MOVE_ICICLE_CRASH, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_HAXORUS,
        .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_MEGAHORN},
        .heldItem = ITEM_LUM_BERRY,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TYRANITAR,
        .moves = {MOVE_DRAGON_DANCE, MOVE_TAUNT, MOVE_CRUNCH, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_CHOPLE_BERRY,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TYRANTRUM,
        .moves = {MOVE_DRAGON_DANCE, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_HEAD_SMASH},
        .heldItem = ITEM_LUM_BERRY,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_HITMONCHAN,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_SHELL_BELL,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_HITMONLEE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_MEGA_KICK, MOVE_POISON_JAB, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_WHITE_HERB,
        .abilityNum = 2
    },
};

const struct gRyuCompanionMon FollowerLeafMons[10] = 
{
    {
        .speciesId = SPECIES_VENUSAUR,
        .moves = {MOVE_FRENZY_PLANT, MOVE_LEECH_SEED, MOVE_PROTECT, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_HERACROSS,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_MEGAHORN, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_LAPRAS,
        .moves = {MOVE_SURF, MOVE_THUNDER, MOVE_FREEZE_DRY, MOVE_PSYCHIC},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_DANCE, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_RHYHORN,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH, MOVE_WILD_CHARGE},
        .heldItem = ITEM_EVIOLITE,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_BLASTOISE,
        .moves = {MOVE_HYDRO_CANNON, MOVE_FLASH_CANNON, MOVE_AURA_SPHERE, MOVE_RAPID_SPIN},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_CHARIZARD,
        .moves = {MOVE_BLAST_BURN, MOVE_ACROBATICS, MOVE_FOCUS_BLAST, MOVE_MEGA_PUNCH},
        .heldItem = ITEM_FLYING_GEM,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_RATICATE,
        .moves = {MOVE_FRENZY_FANG, MOVE_CRUNCH, MOVE_U_TURN, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_SILK_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_SOFT_BOILED, MOVE_THUNDERBOLT},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
};

const struct gRyuCompanionMon FollowerCourtneyMons[10] = 
{
    {
        .speciesId = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_SUCKER_PUNCH, MOVE_PLAY_ROUGH, MOVE_FISSURE},
        .heldItem = ITEM_BLACK_GLASSES,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_CAMERUPT,
        .moves = {MOVE_LAVA_PLUME, MOVE_EARTH_POWER, MOVE_BODY_SLAM, MOVE_YAWN},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_DELPHOX,
        .moves = {MOVE_BLAST_BURN, MOVE_PSYCHIC, MOVE_FLAMETHROWER, MOVE_GRASS_KNOT},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_SALAZZLE,
        .moves = {MOVE_FLAMETHROWER, MOVE_SLUDGE_BOMB, MOVE_HEAT_WAVE, MOVE_SHADOW_BALL},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM, MOVE_BLAST_OFF},
        .heldItem = ITEM_CHOICE_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_VOLCARONA,
        .moves = {MOVE_FIERY_DANCE, MOVE_QUIVER_DANCE, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TURTONATOR,
        .moves = {MOVE_SHELL_SMASH, MOVE_DRACO_METEOR, MOVE_OVERHEAT, MOVE_EXPLOSION},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_CHANDELURE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_SUCKER_PUNCH, MOVE_PLAY_ROUGH, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_BLACK_GLASSES,
        .abilityNum = 2
    },
};

const struct gRyuCompanionMon FollowerJoyMons[10] = 
{
    {
        .speciesId = SPECIES_AUDINO,
        .moves = {MOVE_HEAL_PULSE, MOVE_WISH, MOVE_SECRET_POWER, MOVE_HYPER_VOICE},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_MEGANIUM,
        .moves = {MOVE_HEAL_PULSE, MOVE_GIGA_DRAIN, MOVE_MOONBLAST, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_BLISSEY,
        .moves = {MOVE_SOFT_BOILED, MOVE_THUNDER_WAVE, MOVE_HEAL_PULSE, MOVE_TRI_ATTACK},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_CHANSEY,
        .moves = {MOVE_HEAL_PULSE, MOVE_SOFT_BOILED, MOVE_SEISMIC_TOSS, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_EVIOLITE,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_CLEFABLE,
        .moves = {MOVE_SOFT_BOILED, MOVE_CALM_MIND, MOVE_DRAINING_KISS, MOVE_SAFEGUARD},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_BELLOSSOM,
        .moves = {MOVE_MOONBLAST, MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_SITRUS_BERRY,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_EXEGGUTOR,
        .moves = {MOVE_SYNTHESIS, MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_PROTECT},
        .heldItem = ITEM_SITRUS_BERRY,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_WISH, MOVE_PROTECT, MOVE_MEGA_PUNCH, MOVE_SING},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_DELCATTY,
        .moves = {MOVE_MOONLIGHT, MOVE_FAKE_OUT, MOVE_HEAL_BELL, MOVE_HYPER_BEAM},
        .heldItem = ITEM_FLUFFY_TAIL,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_PERSIAN,
        .moves = {MOVE_FAKE_OUT, MOVE_THUNDER_WAVE, MOVE_FOUL_PLAY, MOVE_SAFEGUARD},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 1
    },
};

const struct gRyuCompanionMon FollowerMayMons[10] = 
{
    {
        .speciesId = SPECIES_BLAZIKEN,
        .moves = {MOVE_BLAZE_KICK, MOVE_HI_JUMP_KICK, MOVE_MEGA_KICK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_SHEDINJA,
        .moves = {MOVE_SHADOW_CLAW, MOVE_TOXIC, MOVE_BUG_BITE, MOVE_NONE},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_MIENSHAO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_DOUBLE_EDGE, MOVE_FAKE_OUT, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_BRELOOM,
        .moves = {MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_BULLET_SEED, MOVE_MACH_PUNCH},
        .heldItem = ITEM_MIRACLE_SEED,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_PLAY_ROUGH, MOVE_HI_JUMP_KICK},
        .heldItem = ITEM_ASSAULT_VEST,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_PELIPPER,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_BLIZZARD, MOVE_TAILWIND},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_MAGMORTAR,
        .moves = {MOVE_SEARING_SHOT, MOVE_DRAGON_PULSE, MOVE_DARK_PULSE, MOVE_THUNDERBOLT},
        .heldItem = ITEM_ASSAULT_VEST,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_MAGCARGO,
        .moves = {MOVE_SHELL_SMASH, MOVE_SOLAR_BEAM, MOVE_GRAVEL_STORM, MOVE_FIRE_BLAST},
        .heldItem = ITEM_HEAT_ROCK,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_DANCE, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_DRAGON_HAMMER},
        .heldItem = ITEM_SITRUS_BERRY,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_LUDICOLO,
        .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_ENERGY_BALL, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .abilityNum = 0
    },
};

const struct gRyuCompanionMon FollowerLucyMons[10] = 
{
    {
        .speciesId = SPECIES_SEVIPER,
        .moves = {MOVE_NASTY_PLOT, MOVE_GLARE, MOVE_DARK_PULSE, MOVE_SLUDGE_WAVE},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TOXICROAK,
        .moves = {MOVE_POISON_JAB, MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_BOXING_GLOVE,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_FIRE_FANG, MOVE_ICE_FANG},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_DRAPION,
        .moves = {MOVE_NIGHT_SLASH, MOVE_CROSS_POISON, MOVE_X_SCISSOR, MOVE_AGILITY},
        .heldItem = ITEM_SCOPE_LENS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_ARBOK,
        .moves = {MOVE_COIL, MOVE_STOCKPILE, MOVE_GUNK_SHOT, MOVE_GLARE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_LIEPARD,
        .moves = {MOVE_FAKE_OUT, MOVE_ATTRACT, MOVE_FOUL_PLAY, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_VENOMOTH,
        .moves = {MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE, MOVE_BUG_BUZZ, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_BLACK_SLUDGE,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_BEEDRILL,
        .moves = {MOVE_DRILL_RUN, MOVE_KNOCK_OFF, MOVE_U_TURN, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_BAND,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_ROSERADE,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_ENERGY_BALL, MOVE_DAZZLING_GLEAM, MOVE_EXTRASENSORY},
        .heldItem = ITEM_CHOICE_SPECS,
        .abilityNum = 0
    },
};

const struct gRyuCompanionMon FollowerMomMons[10] = 
{
    {
        .speciesId = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_QUICK_ATTACK, MOVE_ATTRACT},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_DAZZLING_GLEAM, MOVE_QUIVER_DANCE, MOVE_SUNNY_DAY},
        .heldItem = ITEM_MIRACLE_SEED,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_PERSIAN,
        .moves = {MOVE_FAKE_OUT, MOVE_PLAY_ROUGH, MOVE_SLASH, MOVE_NIGHT_SLASH},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_VICTREEBEL,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_GROWTH},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_TAUROS,
        .moves = {MOVE_BODY_SLAM, MOVE_HYPER_BEAM, MOVE_AGILITY, MOVE_BULK_UP},
        .heldItem = ITEM_SILK_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_MR_MIME,
        .moves = {MOVE_MIMIC, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_PSYCHIC},
        .heldItem = ITEM_LIGHT_CLAY,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_ABSOL,
        .moves = {MOVE_NIGHT_SLASH, MOVE_PLAY_ROUGH, MOVE_SLASH, MOVE_KNOCK_OFF},
        .heldItem = ITEM_SCOPE_LENS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_MEDICHAM,
        .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_SALAC_BERRY,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_SLACK_OFF, MOVE_ROLLOUT, MOVE_EARTHQUAKE},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_MILTANK,
        .moves = {MOVE_MILK_DRINK, MOVE_ATTRACT, MOVE_BODY_SLAM, MOVE_ROLLOUT},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
};

const struct gRyuCompanionMon FollowerGladionMons[10] = 
{
    {
        .speciesId = SPECIES_TYPE_NULL,
        .moves = {MOVE_REST, MOVE_DOUBLE_EDGE, MOVE_CURSE, MOVE_SACRED_SWORD},
        .heldItem = ITEM_EVIOLITE,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_THUNDER_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_LUCARIO,
        .moves = {MOVE_DRAGON_PULSE, MOVE_FLASH_CANNON, MOVE_AURA_SPHERE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_WEAVILE,
        .moves = {MOVE_ICE_SHARD, MOVE_ICICLE_CRASH, MOVE_KNOCK_OFF, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_BAND,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_PORYGON_Z,
        .moves = {MOVE_TECHNO_BLAST, MOVE_DARK_PULSE, MOVE_AGILITY, MOVE_NONE},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_SILVALLY,
        .moves = {MOVE_REST, MOVE_DOUBLE_EDGE, MOVE_CURSE, MOVE_SACRED_SWORD},
        .heldItem = ITEM_EVIOLITE,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_THUNDER_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_NONE,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_METEOR_MASH, MOVE_EXTREME_SPEED, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SALAC_BERRY,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_WEAVILE,
        .moves = {MOVE_ICE_SHARD, MOVE_ICICLE_CRASH, MOVE_KNOCK_OFF, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_BAND,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_PORYGON_Z,
        .moves = {MOVE_TECHNO_BLAST, MOVE_DARK_PULSE, MOVE_AGILITY, MOVE_NONE},
        .heldItem = ITEM_LIFE_ORB,
        .abilityNum = 0
    },
};

const struct gRyuCompanionMon FollowerLillieMons[10] = 
{
    {
        .speciesId = SPECIES_COSMOG,
        .moves = {MOVE_SPACIAL_REND, MOVE_BOOMBURST, MOVE_CLEAR_SMOG, MOVE_PSYCHO_BOOST},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_PSYSHOCK, MOVE_ROOST, MOVE_NONE},
        .heldItem = ITEM_SHELL_BELL,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_MEGANIUM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MOONBLAST, MOVE_LEECH_SEED, MOVE_ANCIENT_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_CLEFABLE,
        .moves = {MOVE_METRONOME, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_MANTINE,
        .moves = {MOVE_AIR_CUTTER, MOVE_SCALD, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_NONE,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_COSMOG,
       .moves = {MOVE_SPACIAL_REND, MOVE_BOOMBURST, MOVE_CLEAR_SMOG, MOVE_PSYCHO_BOOST},
        .heldItem = ITEM_FOCUS_SASH,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_SING},
        .heldItem = ITEM_LIGHT_CLAY,
        .abilityNum = 1
    },
    {
        .speciesId = SPECIES_BELLOSSOM,
        .moves = {MOVE_MOONBLAST, MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_SITRUS_BERRY,
        .abilityNum = 2
    },
    {
        .speciesId = SPECIES_EEVEE,
        .moves = {MOVE_CHARM, MOVE_COVET, MOVE_QUICK_ATTACK, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_SILK_SCARF,
        .abilityNum = 0
    },
    {
        .speciesId = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_SING, MOVE_DAZZLING_GLEAM, MOVE_BABY_DOLL_EYES, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 1
    },
};

void SetCompanionMons(const struct gRyuCompanionMon * CompanionMons)
{
    u16 rnd1 = (Random() % 10);
    u16 rnd2 = (Random() % 10);
    u16 rnd3 = (Random() % 10);
    do
    { //make sure there's no duplicates in the companion's party
        rnd1 = (Random() % 10);
        rnd2 = (Random() % 10);
        rnd3 = (Random() % 10);
    }while (((rnd1 != rnd2) && (rnd2 != rnd3) && (rnd3 != rnd1)) == FALSE);

    gSaveBlock2Ptr->CompanionParty[0].speciesId = CompanionMons[rnd1].speciesId;
    gSaveBlock2Ptr->CompanionParty[0].move1 = CompanionMons[rnd1].moves[0];
    gSaveBlock2Ptr->CompanionParty[0].move2 = CompanionMons[rnd1].moves[1];
    gSaveBlock2Ptr->CompanionParty[0].move3 = CompanionMons[rnd1].moves[2];
    gSaveBlock2Ptr->CompanionParty[0].move4 = CompanionMons[rnd1].moves[3];
    gSaveBlock2Ptr->CompanionParty[0].heldItem = CompanionMons[rnd1].heldItem;
    gSaveBlock2Ptr->CompanionParty[0].abilityNum = CompanionMons[rnd1].abilityNum;

    gSaveBlock2Ptr->CompanionParty[1].speciesId = CompanionMons[rnd2].speciesId;
    gSaveBlock2Ptr->CompanionParty[1].move1 = CompanionMons[rnd2].moves[0];
    gSaveBlock2Ptr->CompanionParty[1].move2 = CompanionMons[rnd2].moves[1];
    gSaveBlock2Ptr->CompanionParty[1].move3 = CompanionMons[rnd2].moves[2];
    gSaveBlock2Ptr->CompanionParty[1].move4 = CompanionMons[rnd2].moves[3];
    gSaveBlock2Ptr->CompanionParty[1].heldItem = CompanionMons[rnd2].heldItem;
    gSaveBlock2Ptr->CompanionParty[1].abilityNum = CompanionMons[rnd2].abilityNum;

    gSaveBlock2Ptr->CompanionParty[2].speciesId = CompanionMons[rnd3].speciesId;
    gSaveBlock2Ptr->CompanionParty[2].move1 = CompanionMons[rnd3].moves[0];
    gSaveBlock2Ptr->CompanionParty[2].move2 = CompanionMons[rnd3].moves[1];
    gSaveBlock2Ptr->CompanionParty[2].move3 = CompanionMons[rnd3].moves[2];
    gSaveBlock2Ptr->CompanionParty[2].move4 = CompanionMons[rnd3].moves[3];
    gSaveBlock2Ptr->CompanionParty[2].heldItem = CompanionMons[rnd3].heldItem;
    gSaveBlock2Ptr->CompanionParty[2].abilityNum = CompanionMons[rnd3].abilityNum;
}

void RyuCreateDynamicFollowerTeam(u16 imgId)
{

    switch (imgId)
    {
        case FOLLOWER_MINNIE:
            SetCompanionMons(FollowerMinnieMons);
            break;
        case FOLLOWER_LANETTE:
            SetCompanionMons(FollowerLanetteMons);
            break;
        case FOLLOWER_SHELLY:
            SetCompanionMons(FollowerShellyMons);
            break;
        case FOLLOWER_DAWN:
            SetCompanionMons(FollowerDawnMons);
            break;
        case FOLLOWER_COURTNEY:
            SetCompanionMons(FollowerCourtneyMons);
            break;
        case FOLLOWER_JOY:
            SetCompanionMons(FollowerJoyMons);
            break;
        case FOLLOWER_BRENDAN:
            SetCompanionMons(FollowerBrendanMons);
            break;
        case FOLLOWER_LEAF:
            SetCompanionMons(FollowerLeafMons);
            break;
        case FOLLOWER_MAY:
            SetCompanionMons(FollowerMayMons);
            break;
        case FOLLOWER_LUCY:
            SetCompanionMons(FollowerLucyMons);
            break;
        case FOLLOWER_MOM:
            SetCompanionMons(FollowerMomMons);
            break;
        case FOLLOWER_GLADION:
            SetCompanionMons(FollowerGladionMons);
            break;
        case FOLLOWER_LILLIE:
            SetCompanionMons(FollowerLillieMons);
            break;
    }

    /*if ((gSaveBlock2Ptr->CompanionParty[0].speciesId == 0) || (gSaveBlock2Ptr->CompanionParty[0].speciesId > SPECIES_MELMETAL))
        gSaveBlock2Ptr->CompanionParty[0].speciesId = SPECIES_BIDOOF;

    if ((gSaveBlock2Ptr->CompanionParty[1].speciesId == 0) || (gSaveBlock2Ptr->CompanionParty[0].speciesId > SPECIES_MELMETAL))
        gSaveBlock2Ptr->CompanionParty[1].speciesId = SPECIES_BIDOOF;

    if ((gSaveBlock2Ptr->CompanionParty[2].speciesId == 0) || (gSaveBlock2Ptr->CompanionParty[0].speciesId > SPECIES_MELMETAL))
        gSaveBlock2Ptr->CompanionParty[2].speciesId = SPECIES_BIDOOF;*/
}