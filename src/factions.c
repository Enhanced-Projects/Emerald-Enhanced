#include "global.h"
#include "data.h"
#include "factions.h"
#include "script.h"
#include "string_util.h"
#include "event_data.h"

extern const u8 RyuNaturalistsDailyQuest[];
extern const u8 RyuStudentsDailyQuest[];
extern const u8 RyuNoblesDailyQuest[];
extern const u8 RyuPokefansDailyQuest[];
extern const u8 RyuOutcastsDailyQuest[];
extern const u8 RyuProfessionalsDailyQuest[];
extern const u8 RyuAthletesDailyQuest[];

void RyuFactions_ResetAllStanding(void)
{
    u8 i = 0;
    for (i = 0; i < 7; i++)
        {
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[i] = 100;//new default/neutral standing is 100
        }
}


void RyuDebug_ViewFactionRelations(void)
{
    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_POKEFANS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NATURALISTS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_ATHLETES], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar1, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_OUTCASTS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar2, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_PROFESSIONALS], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar3, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_NOBLES], STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gRyuStringVar4, gSaveBlock1Ptr->gNPCTrainerFactionRelations[FACTION_STUDENTS], STR_CONV_MODE_LEFT_ALIGN, 3);
}

bool8 ScrCmd_checkfaction(struct ScriptContext *ctx)
{
    u16 trainerToCheck = (VarGet(ScriptReadHalfword(ctx)));
    u8 targetTrainerFaction = gTrainers[trainerToCheck].trainerFaction;
    u8 currentStanding = gSaveBlock1Ptr->gNPCTrainerFactionRelations[targetTrainerFaction];

    gSpecialVar_Result = targetTrainerFaction;
    ConvertIntToDecimalStringN(gRyuStringVar4, currentStanding, STR_CONV_MODE_LEFT_ALIGN, 3);
}

u8 GetFactionStanding(u16 trainerId) //this should return the value of player's standing in trainerId's faction
{
    return gSaveBlock1Ptr->gNPCTrainerFactionRelations[(gTrainers[trainerId].trainerFaction)];
}

void RyuAdjustFactionValueInternal(u8 id, u8 amount, bool8 negative)
{
    s16 currentStanding = gSaveBlock1Ptr->gNPCTrainerFactionRelations[id]; //i need this to be able to hold values larger than 255 and lower than 0, just in case.
    if (negative)
    {
        if (currentStanding - amount >= 0)//new minimum value is 0.
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] -= amount;
        else
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] = 0;
    }
    else
    {
        if (currentStanding + amount <= 200)//new maximum value is 200.
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] += amount;
        else
            gSaveBlock1Ptr->gNPCTrainerFactionRelations[id] = 200;
    }
}

// If/when there are more switches like this in the future, it might be worth making an array of opposites.
void RyuAdjustOpposingFactionValues(u8 id, u8 amount, bool8 negative)
{
    switch (id)
    {
    case FACTION_NATURALISTS:
        RyuAdjustFactionValueInternal(FACTION_NOBLES, amount, negative);
        break;
    case FACTION_STUDENTS:
        RyuAdjustFactionValueInternal(FACTION_OUTCASTS, amount, negative);
        break;
    case FACTION_NOBLES:
        RyuAdjustFactionValueInternal(FACTION_NATURALISTS, amount, negative);
        break;
    case FACTION_POKEFANS:
        RyuAdjustFactionValueInternal(FACTION_ATHLETES, amount, negative);
        break;
    case FACTION_OUTCASTS:
        RyuAdjustFactionValueInternal(FACTION_STUDENTS, amount, negative);
        break;
    case FACTION_PROFESSIONALS:
        RyuAdjustFactionValueInternal(FACTION_POKEFANS, amount, negative);
        break;
    case FACTION_ATHLETES:
        RyuAdjustFactionValueInternal(FACTION_POKEFANS, (amount / 2), negative);
        RyuAdjustFactionValueInternal(FACTION_NOBLES, (amount / 2), negative);
        break;
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
    u8 amount = ScriptReadByte(ctx); //no longer doing negatives, script logic doesn't like it.

    if (gSaveBlock1Ptr->gNPCTrainerFactionRelations[factionId] <= amount)//just see if factionid's standing is less than or equal to amount.
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;

    return FALSE;
}

const u8 *RyuGetFactionDailyQuestScriptPtr(u8 factionId)
{
    switch (factionId)
    {
        case FACTION_NATURALISTS:
            return RyuNaturalistsDailyQuest;
        case FACTION_STUDENTS:
            return RyuStudentsDailyQuest;
        case FACTION_NOBLES:
            return RyuNoblesDailyQuest;
        case FACTION_POKEFANS:
            return RyuPokefansDailyQuest;
        case FACTION_OUTCASTS:
            return RyuOutcastsDailyQuest;
        case FACTION_PROFESSIONALS:
            return RyuProfessionalsDailyQuest;
        case FACTION_ATHLETES:
            return RyuAthletesDailyQuest;
        case FACTION_OTHERS:
            return NULL;
    }
}
