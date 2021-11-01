#include "global.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/event_objects.h"
#include "random.h"
#include "string_util.h"
#include "region_map.h"


#define NUM_DELIVERY_TARGETS 10

struct DeliveryTarget {
  u16 gfxId;
  u16 mapsec;
  u16 jobId;
};

const u8 sName_Reginald[] = _("Reginald");
const u8 sName_Miia[] = _("Miia");
const u8 sName_Jason[] = _("Jason");
const u8 sName_Sandra[] = _("Sandra");
const u8 sName_Michael[] = _("Michael");
const u8 sName_Linda[] = _("Linda");
const u8 sName_Gerald[] = _("Gerald");
const u8 sName_Miranda[] = _("Miranda");
const u8 sName_Donovan[] = _("Donovan");
const u8 sName_Eleanor[] = _("Eleanor");

u8 * const sStringVars[] =
{
    gStringVar1,
    gStringVar2,
    gStringVar3,
    gRyuStringVar1,
    gRyuStringVar2,
    gRyuStringVar3
};

void RyuCopyDeliveryTargetNameToString2(u32 index)
{
    switch (index) {
        case OBJ_EVENT_GFX_CONTEST_JUDGE:
            StringAppend(sStringVars[index], sName_Reginald);
            break;
        case OBJ_EVENT_GFX_POKEFAN_F:
            StringAppend(sStringVars[index], sName_Miia);
            break;
        case OBJ_EVENT_GFX_MAN_4:
            StringAppend(sStringVars[index], sName_Jason);
            break;
        case OBJ_EVENT_GFX_AQUA_MEMBER_F:
            StringAppend(sStringVars[index], sName_Sandra);
            break;
        case OBJ_EVENT_GFX_MAGMA_MEMBER_M:
            StringAppend(sStringVars[index], sName_Michael);
            break;
        case OBJ_EVENT_GFX_EXPERT_F:
            StringAppend(sStringVars[index], sName_Linda);
            break;
        case OBJ_EVENT_GFX_MAN_1:
            StringAppend(sStringVars[index], sName_Gerald);
            break;
        case OBJ_EVENT_GFX_WOMAN_5:
            StringAppend(sStringVars[index], sName_Miranda);
            break;
        case OBJ_EVENT_GFX_SCIENTIST_1:
            StringAppend(sStringVars[index], sName_Donovan);
            break;
        case OBJ_EVENT_GFX_WOMAN_4:
            StringAppend(sStringVars[index], sName_Eleanor);
            break;
    }
}

const u8 sTargetString[] = _("No. ");
const u8 sColonString[] = _(": (");
const u8 sEndBracketString[] = _(": )");
const u8 sSpaceText[] = _(" ");


struct DeliveryTarget gDeliveryTargets[NUM_DELIVERY_TARGETS] = {
    {
        OBJ_EVENT_GFX_CONTEST_JUDGE,
        MAPSEC_RUSTBORO_CITY,
        0
    },
    {
        OBJ_EVENT_GFX_POKEFAN_F,
        MAPSEC_MAUVILLE_CITY,
        1
    },
    {
        OBJ_EVENT_GFX_MAN_4,
        MAPSEC_DEWFORD_TOWN,
        2
    },
    {
        OBJ_EVENT_GFX_AQUA_MEMBER_F,
        MAPSEC_LILYCOVE_CITY,
        3
    },
    {
        OBJ_EVENT_GFX_MAGMA_MEMBER_M,
        MAPSEC_MOSSDEEP_CITY,
        4
    },
    {
        OBJ_EVENT_GFX_EXPERT_F,
        MAPSEC_FORTREE_CITY,
        5
    },
    {
        OBJ_EVENT_GFX_MAN_1,
        MAPSEC_PACIFIDLOG_TOWN,
        6
    },
    {
        OBJ_EVENT_GFX_WOMAN_5,
        MAPSEC_OLDALE_TOWN,
        7
    },
    {
        OBJ_EVENT_GFX_SCIENTIST_1,
        MAPSEC_LAVARIDGE_TOWN,
        8
    },
    {
        OBJ_EVENT_GFX_WOMAN_4,
        MAPSEC_VERDANTURF_TOWN,
        9
    },
};

bool32 CheckDuplicateDeliveryTargets(u8 NumToCheck)
{
    u32 i;
    for (i = 0; i < 6; i++)
    {
        if (gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[NumToCheck].jobId == gDeliveryTargets[NumToCheck].jobId)
            return TRUE;
    }
    return FALSE;
}

void RyuBufferJobIntoStringVar(void)
{
    u32 i;
    u8 buffer1[] = ("");
    u8 buffer2[] = ("");
    for (i = 0; i < gSaveBlock2Ptr->totalCurrentDeliveryTargets; i++)
    {
        u16 mapSec = gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].targetMapSec;
        StringCopy(buffer1, gRegionMapEntries[mapSec].name); //Location string
        StringCopy(sStringVars[i], sTargetString);
        ConvertIntToDecimalStringN(buffer2, i, STR_CONV_MODE_LEFT_ALIGN, 1); //which iteration/job we're on
        StringAppend(sStringVars[i], buffer2);
        StringAppend(sStringVars[i], sColonString);
        RyuCopyDeliveryTargetNameToString2(i); //puts target name in gRyuStringVar4
        StringAppend(sStringVars[i], gStringVar4);
        StringAppend(sStringVars[i], sSpaceText);
        StringAppend(sStringVars[i], buffer1);
        StringAppend(sStringVars[i], sEndBracketString);
    }
}

void RyuSetUpDynamicDeliveryRoute(u8 NumTargets)
{
    u32 i;
    for (i = 0; i < (NumTargets + 1); i++)
    {
        u32 rnd = (Random() % NUM_DELIVERY_TARGETS);
        do {
            rnd = (Random() % NUM_DELIVERY_TARGETS);
        } while (CheckDuplicateDeliveryTargets(rnd) == TRUE);


        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].targetGfxId = gDeliveryTargets[rnd].gfxId;
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].targetMapSec = gDeliveryTargets[rnd].mapsec;
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].completed = FALSE;
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].targetVisibilityFlag = (FLAG_RYU_HIDE_DELIVERY_NPC_1 + i);
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].jobId = gDeliveryTargets[rnd].jobId;
    }
    gSaveBlock2Ptr->totalCurrentDeliveryTargets = NumTargets;
}

void RyuClearDynamicDeliveryRoute(void)
{
    u32 i;
    for (i = 0; i > gSaveBlock2Ptr->totalCurrentDeliveryTargets; i++)
    {
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].targetGfxId = 0;
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].targetMapSec = 0;
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].completed = FALSE;
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].targetVisibilityFlag = 0;
        gSaveBlock2Ptr->PlayerCurrentDeliveryManifest[i].jobId = 255;
        gSaveBlock2Ptr->totalCurrentDeliveryTargets = 6;
    }
}

void DoDeliveryRouteSetup(void)
{
    u16 numJobs = (VarGet(VAR_TEMP_4));
    RyuSetUpDynamicDeliveryRoute(numJobs);
}


void RyuDebug_CheckDeliveryStatus(void)
{
}

const u8 sText_emptyBuffer[] = _(" ");
void RyuFillTextBuffers(void)
{
    if (gRyuStringVar3 == NULL) {
        StringCopy(gRyuStringVar3, sText_emptyBuffer);
    }
    if (gRyuStringVar2 == NULL) {
        StringCopy(gRyuStringVar2, sText_emptyBuffer);
    }
    if (gRyuStringVar1 == NULL) {
        StringCopy(gRyuStringVar1, sText_emptyBuffer);
    }
    if (gStringVar3 == NULL) {
        StringCopy(gStringVar1, sText_emptyBuffer);
    }
    if (gStringVar2 == NULL) {
        StringCopy(gStringVar2, sText_emptyBuffer);
    }
    if (gStringVar3 == NULL) {
        StringCopy(gStringVar3, sText_emptyBuffer);
    }
    
}

