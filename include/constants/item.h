#ifndef GUARD_ITEM_CONSTANTS_H
#define GUARD_ITEM_CONSTANTS_H

// These constants are used in gItems
#define POCKET_NONE          0
#define POCKET_ITEMS         1
#define POCKET_MEDICINE      2//new
#define POCKET_COLLECTIBLES  3
#define POCKET_POKE_BALLS    4
#define POCKET_TM_HM         5
#define POCKET_BERRIES       6
#define POCKET_KEY_ITEMS     7
#define POCKET_MEGASTONES    8

#define ITEMS_POCKET        0
#define MEDICINE_POCKET     1
#define COLLECTIBLES_POCKET 2
#define BALLS_POCKET        3
#define TMHM_POCKET         4
#define BERRIES_POCKET      5
#define KEYITEMS_POCKET     6
#define MEGASTONES_POCKET   7
#define POCKETS_COUNT       8

// The TM/HM pocket is the largest pocket, so the maximum amount of items
// in a pocket is its count + 1 for the cancel option
#define MAX_POCKET_ITEMS   (BAG_ITEMS_COUNT + 1)


#endif // GUARD_ITEM_CONSTANTS_H
