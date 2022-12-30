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
                DebugPrint(((const u8[]) _("Lana: -10% damage from FIR/WTR/GRS")), 0);
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
bool8 RyuFollowerToTrainerID(void)
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
        }
        return FALSE;
    }
}
