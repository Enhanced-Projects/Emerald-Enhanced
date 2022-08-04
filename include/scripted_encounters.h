#ifndef _H_GUARD_SCRIPTED_ENCOUNTER_
#define _H_GUARD_SCRIPTED_ENCOUNTER_
#include "gba/types.h"
#include "gba/defines.h"
#include "main.h"

#define ENC_MESSAGE      0
#define ENC_CRY          1
#define ENC_BATTLE_START 2
#define ENC_BATTLE       3
#define ENC_BATTLE_END   4

#define ENCOUNTER_MAX_FLAG        4

#define ENCOUNTER_SCALE _clamp(CountBadges()*12, 20, 110)

#define encounterSpecies        data[1]
#define encounterEndFlag        data[2]
#define encounterOutcomeCheck   data[3]
#define encounterOutcomeFlag    data[4]

#define SET_DYNAMIC_ENCOUNTER(speciesId, msg) HatSetDynamicEncounter(speciesId, msg, 0, 0, 0)
#define SET_DYNAMIC_ENCOUNTER_W_END_FLAG(speciesId, msg, endFlag) HatSetDynamicEncounter(speciesId, msg, endFlag, 0, 0)
#define SET_DYNAMIC_ENCOUNTER_W_OUTCOME_FLAG(speciesId, msg, outcomeCheck, outcomeFlag) HatSetDynamicEncounter(speciesId, msg, 0, outcomeCheck, outcomeFlag)
#define SET_DYNAMIC_ENCOUNTER_W_END_FLAG_AND_OUTCOME_FLAG(speciesId, msg, endFlag, outcomeCheck, outcomeFlag) HatSetDynamicEncounter(speciesId, msg, endFlag, outcomeCheck, outcomeFlag)

#define SET_DYNAMIC_LEG_ENCOUNTER(speciesId, msg) HatSetDynamicLegendaryEncounter(speciesId, msg, 0, 0, 0)
#define SET_DYNAMIC_LEG_ENCOUNTER_W_END_FLAG(speciesId, msg, endFlag) HatSetDynamicLegendaryEncounter(speciesId, msg, endFlag, 0, 0)
#define SET_DYNAMIC_LEG_ENCOUNTER_W_OUTCOME_FLAG(speciesId, msg, outcomeCheck, outcomeFlag) HatSetDynamicLegendaryEncounter(speciesId, msg, 0, outcomeCheck, outcomeFlag)
#define SET_DYNAMIC_LEG_ENCOUNTER_W_END_FLAG_AND_OUTCOME_FLAG(speciesId, msg, endFlag, outcomeCheck, outcomeFlag) HatSetDynamicLegendaryEncounter(speciesId, msg, endFlag, outcomeCheck, outcomeFlag)

void Task_HatEncounter_SteppedOn(u8 taskId);
void Task_HatEncounter_Mimikyu(u8 taskId);
void Task_HatEncounter_Keldeo(u8 taskId);

void Task_HatEncounter_Generic(u8 taskId);
void Task_HatEncounter_Legendary(u8 taskId);
void Task_HatEncounter_UltraBeast(u8 taskId);

void HatSetDynamicEncounter(u16 speciesId, u8* msg, s16 endFlag, s16 outcomeCheck, s16 outcomeFlag);
void HatSetDynamicLegendaryEncounter(u16 speciesId, u8* msg, s16 endFlag, s16 outcomeCheck, s16 outcomeFlag);
void HatEncounterEndAdditiveCallback(void);

void HatEncounterEndCallback(void);
void HatEncounterEndWithFlagCallback(void);
void HatEncounterEndKeldeoCallback(void);
void HatEncounterEndUBCallback(void);


#endif