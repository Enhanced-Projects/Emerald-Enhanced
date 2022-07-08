#ifndef GUARD_RYUDYNDELIVERY_H
#define GUARD_RYUDYNDELIVERY_H

#include "global.h"
#include "constants/event_objects.h"
#include "constants/items.h"

extern bool32 RyuGetSafeMapCoordsToPlaceDynamicObject(void);
extern bool32 CheckRTCForDeliveryTime(void);
extern void StartNewDeliveryQueue(void);
extern void RyuClearDeliveryQueue(void);
extern void RyuCountActiveJobs(void);


#endif