#ifndef GUARD_FACTIONS_H
#define GUARD_FACTIONS_H

#include "global.h"
#include "data.h"
#include "factions.h"
#include "script.h"
#include "string_util.h"
#include "event_data.h"

bool8 ScrCmd_checkfaction(struct ScriptContext *ctx);
bool8 ScrCmd_changefactionstanding(struct ScriptContext *ctx);
bool8 ScrCmd_checkfactionstanding(struct ScriptContext *ctx);
u8 GetFactionStanding(u16 trainerId);
u8 GetFactionId(u16 trainerId);
void RyuFactions_ResetAllStanding(void);
void RyuAdjustFactionValueInternal(u8 id, u8 amount, bool8 negative);
void RyuAdjustOpposingFactionValues(u8 id, u8 amount, bool8 negative);
void RyuDebug_ViewFactionRelations(void);
void ClearDailyQuestData(void);//happens when daily events are done by rtc
const u8 *RyuGetFactionDailyQuestScriptPtr(u8 factionId);

extern const u8 gFactionNames[8][15];
extern const u8 gFactionDailyQuestTypeNames[4][8];

#endif //GUARD_FACTIONS_H