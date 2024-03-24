#include "global.h"
#include "constants/general.h"

extern void SetNuzlockeFlag(u32 id);
extern bool32 GetNuzlockeFlag(u32 id);
extern void RemoveNuzlockeFlag(u32 id);
extern void ResetNuzlockeFlags(void);
extern void   SetModFlag(u32 id);
extern bool32 GetModFlag(u32 id);
extern void   ClearModFlag(u32 id);
extern void   ResetModFlags(void);
extern void TryRevelationModPenalties(void);

extern const u8 gRyuChallengeModifierNames[14][16];