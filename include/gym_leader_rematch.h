#ifndef GUARD_TRAINER_REMATCH_H
#define GUARD_TRAINER_REMATCH_H

enum {
    REMATCH_TABLE_ENTRIES // The total number of rematch entries. Must be last in enum
};

#define REMATCH_SPECIAL_TRAINER_START   REMATCH_WALLY_3
#define REMATCH_ELITE_FOUR_ENTRIES      REMATCH_SIDNEY

void UpdateGymLeaderRematch(void);

#endif //GUARD_TRAINER_REMATCH_H
