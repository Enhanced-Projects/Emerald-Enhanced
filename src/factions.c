#include "global.h"
#include "data.h"
#include "factions.h"
#include "script.h"
#include "string_util.h"
#include "event_data.h"

void RyuFactions_ResetAllStanding(void)
{
    memset(gSaveBlock1Ptr->gNPCTrainerFactionRelations, 0, sizeof(gSaveBlock1Ptr->gNPCTrainerFactionRelations));
}


void RyuDebug_ViewFactionRelations(void)
{
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
    if (negative)
        gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] -= amount;
    else
        gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] += amount;
}

// If/when there are more switches like this in the future, it might be worth making an array of opposites.
void RyuAdjustOpposingFactionValues(u8 id, u8 amount, bool8 negative)
{
    switch (id)
    {
    case FACTION_NATURALISTS:
        RyuAdjustFactionValueInternal(FACTION_RICHKIDS, amount, negative);
        break;
    case FACTION_SCHOOLKIDS:
        RyuAdjustFactionValueInternal(FACTION_NERDS, amount, negative);
        break;
    case FACTION_RICHKIDS:
        RyuAdjustFactionValueInternal(FACTION_NATURALISTS, amount, negative);
        break;
    case FACTION_POKEFANS:
        RyuAdjustFactionValueInternal(FACTION_ATHLETES, amount, negative);
        break;
    case FACTION_NERDS:
        RyuAdjustFactionValueInternal(FACTION_SCHOOLKIDS, amount, negative);
        break;
    case FACTION_PROFESSIONALS:
        RyuAdjustFactionValueInternal(FACTION_POKEFANS, amount, negative);
        break;
    case FACTION_ATHLETES:
        RyuAdjustFactionValueInternal(FACTION_POKEFANS, (amount / 2), negative);
        RyuAdjustFactionValueInternal(FACTION_RICHKIDS, (amount / 2), negative);
        break;
    }
}

bool8 ScrCmd_changefactionstanding(struct ScriptContext *ctx)
{
    u8 factionId = ScriptReadByte(ctx);
    // could this just be s8? then we wouldn’t need negative and could get rid of some more branching
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

    gSpecialVar_Result = negative
      ? gSaveBlock1Ptr->gNPCTrainerFactionRelations[factionId] <= amount
      : gSaveBlock1Ptr->gNPCTrainerFactionRelations[factionId] >= amount;
    return FALSE;
}
