//Follower related code
#include "global.h"
#include "strings.h"
#include "event_data.h"
#include "string_util.h"
#include "overworld_notif.h"

void RyuBufferAttendantName (void)
{
    u16 attendant = VarGet(VAR_RYU_ATTENDANT_ID);

    switch(attendant)
    {
            case FOLLOWER_LANETTE:
                StringCopy(gStringVar1, gText_RyuAttendantNameLanette);
                break;
	        case FOLLOWER_MINNIE:
                StringCopy(gStringVar1, gText_RyuAttendantNameMinnie);
                break;
	        case FOLLOWER_DAWN:
                StringCopy(gStringVar1, gText_RyuAttendantNameDawn);
                break;
	        case FOLLOWER_BRENDAN:
                StringCopy(gStringVar1, gText_RyuAttendantNameBrendan);
                break;
	        case FOLLOWER_LEAF:
                StringCopy(gStringVar1, gText_RyuAttendantNameLana);
                break;
	        case FOLLOWER_COURTNEY:
                StringCopy(gStringVar1, gText_RyuAttendantNameCourtney);
                break;
	        case FOLLOWER_SHELLY:
                StringCopy(gStringVar1, gText_RyuAttendantNameShelly);
                break;
	        case FOLLOWER_JOY:
                StringCopy(gStringVar1, gText_RyuAttendantNameJoy);
                break;
	        case FOLLOWER_MAY:
                StringCopy(gStringVar1, gText_RyuAttendantNameMay);
                break;
	        case 0xFFFF:
                StringCopy(gStringVar1, gText_RyuAttendantNameNone);
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
            gSpecialVar_0x8008 = TRAINER_REL_LANA;
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
        }
        return FALSE;
    }
}
