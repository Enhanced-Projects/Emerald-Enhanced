#include "global.h"
#include "constants/general.h"
#include "field_message_box.h"

extern int RyuTryGetScheduledPokenavCall(void);
extern void DoScheduledNavCallCheck(void);
extern void SchedulePokenavCallInternal(u8 index, u16 delay);


extern const u8 * const RyuPokenavCallMessages[];
