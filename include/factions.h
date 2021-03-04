#ifndef GUARD_FACTIONS_H
#define GUARD_FACTIONS_H

#include "global.h"
#include "data.h"
#include "factions.h"
#include "script.h"
#include "string_util.h"
#include "event_data.h"

void RyuFactions_ResetAllStanding(void);
bool8 ScrCmd_checkfaction(struct ScriptContext *ctx);
u8 GetFactionStanding(u16 trainerId);
void RyuAdjustFactionValueInternal(u8 id, u8 amount, bool8 negative);
void RyuAdjustOpposingFactionValues(u8 id, u8 amount, bool8 negative);
bool8 ScrCmd_changefactionstanding(struct ScriptContext *ctx);
bool8 ScrCmd_checkfactionstanding(struct ScriptContext *ctx);
void RyuDebug_ViewFactionRelations(void);

#endif //GUARD_FACTIONS_H