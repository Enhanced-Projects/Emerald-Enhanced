//Follower related code
#include "global.h"
#include "strings.h"
#include "event_data.h"
#include "string_util.h"
#include "overworld_notif.h"
#include "constants/trainers.h"

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
                DebugPrint(((const u8[]) _("Minnie: 5% dmg reduction.")), 0);
                break;
            case FOLLOWER_LANETTE:
                DebugPrint(((const u8[]) _("Lanette: 5% capture boost.")), 0);
                break;
            case FOLLOWER_SHELLY:
                DebugPrint(((const u8[]) _("Shelly: 10% DRK/WTR dmg boost.")), 0);
                break;
            case FOLLOWER_DAWN:
                DebugPrint(((const u8[]) _("{RIVAL}: 15% money bonus.")), 0);
                break;
            case FOLLOWER_BRENDAN:
                DebugPrint(((const u8[]) _("{RIVAL}: 15% money bonus.")), 0);
                break;
            case FOLLOWER_LEAF:
                DebugPrint(((const u8[]) _("Leaf: -10% damage from FIR/WTR/GRS")), 0);
                break;
            case FOLLOWER_COURTNEY:
                DebugPrint(((const u8[]) _("Courtney: 10% DRK/FIR dmg boost.")), 0);
                break;
            case FOLLOWER_JOY:
                break;
            case FOLLOWER_MAY:
                DebugPrint(((const u8[]) _("May: 10% FRY/FIT dmg boost.")), 0);
                break;
            case FOLLOWER_LUCY:
                DebugPrint(((const u8[]) _("Lucy: 10% PSN/DRG dmg boost.")), 0);
                break;
            case FOLLOWER_MOM:
                DebugPrint(((const u8[]) _("Mom: Active heal in battle.")), 0);
                break;
        }
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
            return TRUE;
        case FOLLOWER_LANETTE:
            gSpecialVar_0x8008 = TRAINER_REL_LANETTE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LANETTE; 
            return TRUE;
        case FOLLOWER_SHELLY:
            gSpecialVar_0x8008 = TRAINER_REL_SHELLY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_SHELLY;
            return TRUE;
        case FOLLOWER_DAWN:
            gSpecialVar_0x8008 = TRAINER_REL_DAWN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_DAWN;
            return TRUE;
        case FOLLOWER_BRENDAN:
            gSpecialVar_0x8008 = TRAINER_REL_BRENDAN;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_BRENDAN;
            return TRUE;
        case FOLLOWER_LEAF:
            gSpecialVar_0x8008 = TRAINER_REL_LEAF;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LEAF;
            return TRUE;
        case FOLLOWER_COURTNEY:
            gSpecialVar_0x8008 = TRAINER_REL_COURTNEY_2;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_COURTNEY;
            return TRUE;
        case FOLLOWER_JOY:
            gSpecialVar_0x8008 = TRAINER_REL_NURSE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_NURSE;
            return TRUE;
        case FOLLOWER_MAY:
            gSpecialVar_0x8008 = TRAINER_REL_MAY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY;
            return TRUE;
        case FOLLOWER_LUCY:
            gSpecialVar_0x8008 = TRAINER_REL_LUCY;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LUCY;
            return TRUE;
        case FOLLOWER_MOM:
            gSpecialVar_0x8008 = TRAINER_REL_MOM;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_MOM;
            return TRUE;
        case FOLLOWER_GLADION:
            gSpecialVar_0x8008 = TRAINER_REL_GLADION;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_GLADION;
            return TRUE;
        case FOLLOWER_LILLIE:
            gSpecialVar_0x8008 = TRAINER_REL_LILLIE;
            gSpecialVar_0x8009 = TRAINER_BACK_PIC_LILLIE;
            return TRUE;
        }
        return FALSE;
    }
}

void RyuBufferCompanionParty(void)
{
    if ((gSaveBlock2Ptr->CompanionPartyMembers[0] == SPECIES_BIDOOF) &&
       (gSaveBlock2Ptr->CompanionPartyMembers[1] == SPECIES_BIDOOF) &&
       (gSaveBlock2Ptr->CompanionPartyMembers[2] == SPECIES_BIDOOF))
    {
     gSpecialVar_0x8002 = 777;
    }
    GetSpeciesName(gStringVar1, gSaveBlock2Ptr->CompanionPartyMembers[0]);    
    GetSpeciesName(gStringVar2, gSaveBlock2Ptr->CompanionPartyMembers[1]);    
    GetSpeciesName(gStringVar3, gSaveBlock2Ptr->CompanionPartyMembers[2]);    
}

const u16 gRyuCompanionPartyPools[][10] = 
{
    [FOLLOWER_MINNIE] = 
    {
        SPECIES_BEWEAR,
        SPECIES_ALTARIA,
        SPECIES_FLAREON,
        SPECIES_RAPIDASH,
        SPECIES_ARCANINE,
        SPECIES_PYROAR,
        SPECIES_LINOONE,
        SPECIES_URSARING,
        SPECIES_DRAMPA,
        SPECIES_MUDSDALE
    },
    [FOLLOWER_LANETTE] =
    {
        SPECIES_ROTOM,
        SPECIES_RAICHU,
        SPECIES_ZEBSTRIKA,
        SPECIES_PORYGON_Z,
        SPECIES_MAGNEZONE,
        SPECIES_METAGROSS,
        SPECIES_HELIOPTILE,
        SPECIES_AMPHAROS,
        SPECIES_LUXRAY,
        SPECIES_ELECTIVIRE
    },
    [FOLLOWER_SHELLY] =
    {
        SPECIES_PRIMARINA,
        SPECIES_JELLICENT,
        SPECIES_KINGLER,
        SPECIES_PALOSSAND,
        SPECIES_VAPOREON,
        SPECIES_FERALIGATR,
        SPECIES_CLAWITZER,
        SPECIES_AZUMARILL,
        SPECIES_OCTILLERY,
        SPECIES_CARRACOSTA
    },
    [FOLLOWER_DAWN] = 
    {
        SPECIES_SYLVEON,
        SPECIES_SWAMPERT,
        SPECIES_FROSLASS,
        SPECIES_TOGEKISS,
        SPECIES_MAWILE,
        SPECIES_GARDEVOIR,
        SPECIES_MIMIKYU,
        SPECIES_SHIINOTIC,
        SPECIES_MILOTIC,
        SPECIES_QUAGSIRE
    },
    [FOLLOWER_BRENDAN] =
    {
        SPECIES_GALLADE,
        SPECIES_LUCARIO,
        SPECIES_SCEPTILE,
        SPECIES_CRANIDOS,
        SPECIES_WEAVILE,
        SPECIES_HAXORUS,
        SPECIES_TYRANITAR,
        SPECIES_TYRANTRUM,
        SPECIES_HITMONCHAN,
        SPECIES_HITMONLEE

    },
    [FOLLOWER_LEAF] = 
    {
        SPECIES_VENUSAUR,
        SPECIES_ALAKAZAM,
        SPECIES_HERACROSS,
        SPECIES_LAPRAS,
        SPECIES_DRAGONITE,
        SPECIES_RHYHORN,
        SPECIES_BLASTOISE,
        SPECIES_CHARIZARD,
        SPECIES_RATICATE,
        SPECIES_BLISSEY
    },
    [FOLLOWER_COURTNEY] = 
    {
        SPECIES_MIGHTYENA,
        SPECIES_MIGHTYENA,
        SPECIES_CAMERUPT,
        SPECIES_DELPHOX,
        SPECIES_SALAZZLE,
        SPECIES_TYPHLOSION,
        SPECIES_VOLCARONA,
        SPECIES_TURTONATOR,
        SPECIES_HOUNDOOM,
        SPECIES_CHANDELURE
    },
    [FOLLOWER_JOY] = 
    {
        SPECIES_AUDINO,
        SPECIES_MUSHARNA,
        SPECIES_BLISSEY,
        SPECIES_ALOMOMOLA,
        SPECIES_CLEFABLE,
        SPECIES_LEAVANNY,
        SPECIES_EXEGGUTOR,
        SPECIES_WIGGLYTUFF,
        SPECIES_DELCATTY,
        SPECIES_PERSIAN
    },
    [FOLLOWER_MAY] = 
    {
        SPECIES_BLAZIKEN,
        SPECIES_SHEDINJA,
        SPECIES_MIENSHAO,
        SPECIES_BRELOOM,
        SPECIES_LOPUNNY,
        SPECIES_PELIPPER,
        SPECIES_MAGMORTAR,
        SPECIES_MAGCARGO,
        SPECIES_TROPIUS,
        SPECIES_LUDICOLO
    },
    [FOLLOWER_LUCY] = 
    {
        SPECIES_SEVIPER,
        SPECIES_CROAGUNK,
        SPECIES_CROBAT,
        SPECIES_SWALOT,
        SPECIES_ARBOK,
        SPECIES_SCOLIPEDE,
        SPECIES_LIEPARD,
        SPECIES_VENOMOTH,
        SPECIES_BEEDRILL,
        SPECIES_ROSERADE
    },
    [FOLLOWER_MOM] =
    {
        SPECIES_LOPUNNY,
        SPECIES_BELLOSSOM,
        SPECIES_PERSIAN,
        SPECIES_VICTREEBEL,
        SPECIES_TAUROS,
        SPECIES_MR_MIME,
        SPECIES_ABSOL,
        SPECIES_MEDICHAM,
        SPECIES_SNORLAX,
        SPECIES_MILTANK
    },
    [FOLLOWER_GLADION] =
    {
        SPECIES_TYPE_NULL,
        SPECIES_CROBAT,
        SPECIES_LUCARIO,
        SPECIES_WEAVILE,
        SPECIES_PORYGON_Z,
        SPECIES_SILVALLY,
        SPECIES_CROBAT,
        SPECIES_LUCARIO,
        SPECIES_WEAVILE,
        SPECIES_PORYGON_Z,
    },
    [FOLLOWER_LILLIE] =
    {
        SPECIES_COSMOG,
        SPECIES_RIBOMBEE,
        SPECIES_COMFEY,
        SPECIES_CLEFABLE,
        SPECIES_MANTINE,
        SPECIES_COSMOG,
        SPECIES_RIBOMBEE,
        SPECIES_COMFEY,
        SPECIES_EEVEE,
        SPECIES_WIGGLYTUFF
    }
};
