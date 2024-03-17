#include "ryu_challenge_modifiers.h"
#include "event_data.h"


/////////////////////////////////////////////////////////////////General challenge mod functions

void SetModFlag(u32 id)
{
    if(id > 63)
        return;
    gSaveBlock1Ptr->challengeFlags[id / 8] |= 1 << (id % 8);
    if ((id == ADV_MONOTYPE_MOD) || (id == MONOTYPE_MOD)){
        gSaveBlock1Ptr->monotypeChallengeChoice = VarGet(VAR_RESULT);
    }
}

bool32 GetModFlag(u32 id)
{
    u32 ret = 69;
    if(id > 63)
        return FALSE;
    return !!((gSaveBlock1Ptr->challengeFlags[id / 8] >> (id % 8)) & 1);
}

void ClearModFlag(u32 id)
{
    if(id > 63)
        return;
    gSaveBlock1Ptr->challengeFlags[id / 8] &= ~(1 << (id % 8));
}

void ResetModFlags(void)
{
    memset(gSaveBlock1Ptr->challengeFlags, 0, NUM_CHALLENGE_FLAG_BYTES);
}


//////////////////////////////////////////////////////////////////Nuzlocke

void SetNuzlockeFlag(u32 id)
{
    if(id > MAPSEC_NONE)
        return;
    gSaveBlock1Ptr->nuzlockeMapsecs[id / 8] |= 1 << (id % 8);
    
}

bool32 GetNuzlockeFlag(u32 id)
{
    if(id > MAPSEC_NONE)
        return FALSE;

    return !!((gSaveBlock1Ptr->nuzlockeMapsecs[id / 8] >> (id % 8)) & 1);
}

void RemoveNuzlockeFlag(u32 id)
{
    if(id > MAPSEC_NONE)
        return;
        
    gSaveBlock1Ptr->nuzlockeMapsecs[id / 8] &= ~(1 << (id % 8));
}

void ResetNuzlockeFlags(void)
{
    memset(gSaveBlock1Ptr->nuzlockeMapsecs, 0, NUM_NUZLOCKE_MAPSEC_BYTES);
}

//////////////////////////////////////////////////////////////////End Nuzlocke