#include "ryu_challenge_modifiers.h"





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