#include "global.h"
#include "constants/general.h"
#include "field_message_box.h"

extern int RyuTryGetScheduledPokenavCall(void);
extern void DoScheduledNavCallCheck(void);
extern void SchedulePokenavCallInternal(u8 index, u16 delay);


extern const u8 * const RyuPokenavCallMessages[];

#define NAVCALL_GENESECTLANETTEFALLARBOR 0
#define NAVCALL_GENESECTLANETTE114 1
#define NAVCALL_DUSKULLAFTERLIFE 2
#define NAVCALL_FAILEDRYUCHALLENGE 3
#define NAVCALL_COMPLETEDRYUCHALLENGE 4
#define NAVCALL_DEXNAV 5
#define NAVCALL_MAGMASTAGE130 6
#define NAVCALL_MAGMASTAGE210 7
#define NAVCALL_AQUASTAGE10 8
#define NAVCALL_AQUASTAGE55 9
#define NAVCALL_AQUASTAGE80 10
#define NAVCALL_AQUASTAGE91 11
#define NAVCALL_AQUASTAGE123 12