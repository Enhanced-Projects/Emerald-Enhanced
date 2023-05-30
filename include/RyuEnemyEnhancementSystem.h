#include "global.h"


extern s16 CalculatePlayerPartyStrength(void);
extern u32 RyuChooseLevel(u8 badges, bool8 maxScale, u8 scalingType, s16 playerPartyStrength);
extern u16 Autoevolve(u16 species, u16 level);
extern u16 RyuChooseEnemyProceduralMons(u16 trainerClass);
extern u16 RyuChooseAutoscaleIV(void);
extern u8 RyuChoosePartyCount(u16 trainer);
extern u8 RyuChooseAutoscaleEv(void);

extern const u16 gRyuProceduralTrainerMonLists[72][20];
extern const u16 sWildRange[9][2];
extern const u16 sGymRange[9][2];
extern const u16 sWildRange[9][2];
extern int CountBadges(void);

#define SCALING_TYPE_WILD      0
#define SCALING_TYPE_TRAINER   1
#define SCALING_TYPE_BOSS      2