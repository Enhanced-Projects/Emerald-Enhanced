#include "global.h"
#include "data.h"
#include "factions.h"
#include "script.h"
#include "string_util.h"
#include "event_data.h"


void RyuDebug_ViewFactionRelations(void)
{
    mgba_printf(LOGINFO, "faction 0 has %d standing", gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_POKEFANS]);
    mgba_printf(LOGINFO, "faction 1 has %d standing", gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NATURALISTS]);
    mgba_printf(LOGINFO, "faction 2 has %d standing", gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_ATHLETES]);
    mgba_printf(LOGINFO, "faction 3 has %d standing", gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NERDS]);
    mgba_printf(LOGINFO, "faction 4 has %d standing", gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_PROFESSIONALS]);
    mgba_printf(LOGINFO, "faction 5 has %d standing", gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_RICHKIDS]);
    mgba_printf(LOGINFO, "faction 6 has %d standing", gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_SCHOOLKIDS]);
    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_POKEFANS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NATURALISTS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_ATHLETES], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar1, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NERDS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar2, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_PROFESSIONALS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar3, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_RICHKIDS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar4, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_SCHOOLKIDS], STR_CONV_MODE_LEFT_ALIGN, 3);
}

bool8 ScrCmd_checkfaction(struct ScriptContext *ctx)
{
    u16 trainerToCheck = (VarGet(ScriptReadHalfword(ctx)));
    u8 targetTrainerFaction = gTrainers[trainerToCheck].trainerFaction;
    u8 currentStanding = gSaveBlock1Ptr->gNPCTrainerFactionRelations[targetTrainerFaction];

    gSpecialVar_Result = targetTrainerFaction;
    ConvertIntToDecimalStringN(gRyuStringVar4, targetTrainerFaction, STR_CONV_MODE_LEFT_ALIGN, 3);
}

void RyuAdjustFactionValueInternal(u8 id, u8 amount, bool8 negative)
{
    if (negative == TRUE)
    {
        gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] -= amount;
    }
    else
    {
        gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] += amount;
    }
}

void RyuAdjustOpposingFactionValues(u8 id, u8 amount, bool8 negative)
{
    switch (id)
    {
    case FACTION_NATURALISTS:
        {
            RyuAdjustFactionValueInternal(FACTION_RICHKIDS, amount, negative);
            break;
        }
    case FACTION_SCHOOLKIDS:
        {
            RyuAdjustFactionValueInternal(FACTION_NERDS, amount, negative);
            break;
        }
    case FACTION_RICHKIDS:
        {
            RyuAdjustFactionValueInternal(FACTION_NATURALISTS, amount, negative);
            break;
        }
    case FACTION_POKEFANS:
        {
            RyuAdjustFactionValueInternal(FACTION_ATHLETES, amount, negative);
            break;
        }
    case FACTION_NERDS:
        {
            RyuAdjustFactionValueInternal(FACTION_SCHOOLKIDS, amount, negative);
            break;
        }
    case FACTION_PROFESSIONALS:
        {
            RyuAdjustFactionValueInternal(FACTION_POKEFANS, amount, negative);
            break;
        }
    case FACTION_ATHLETES:
        {
            RyuAdjustFactionValueInternal(FACTION_POKEFANS, (amount / 2), negative);
            RyuAdjustFactionValueInternal(FACTION_RICHKIDS, (amount / 2), negative);
            break;
        }
    }
}

bool8 ScrCmd_changefactionstanding(struct ScriptContext *ctx)
{
    u8 factionId = ScriptReadByte(ctx);
    u8 amount = ScriptReadByte(ctx);
    bool8 negative = ScriptReadByte(ctx);

    RyuAdjustFactionValueInternal(factionId, amount, negative);
    RyuAdjustOpposingFactionValues(factionId, amount, !negative);
    return FALSE;
}

bool8 ScrCmd_checkfactionstanding(struct ScriptContext *ctx)
{
    u8 factionId = ScriptReadByte(ctx);
    s8 amount = (s8)ScriptReadByte(ctx); //cast to s8 so that i could check if a faction is lower than -20 for example.
    bool8 negative = ScriptReadByte(ctx);

    if (negative == FALSE)
    {
        if (gSaveBlock1Ptr->gNPCTrainerFactionRelations[factionId] >= amount)
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
    }
    else
    {
        if (gSaveBlock1Ptr->gNPCTrainerFactionRelations[factionId] <= amount)
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
    }
    return FALSE;
}
