#include "global.h"
#include "constants/general.h"
#include "RyuPokenavScheduler.h"
#include "field_message_box.h"
#include "script.h"


const u8 sText_PokenavCallLanetteGenesectPokecenter[] = _("Hello? {PLAYER}?\pI heard that you found a\nmysterious drive.\pHow did I get your number?\pDon't worry about that.\pMore importantly, come find me at\nFallarbor Pokecenter!\pWe have something to discuss!");
const u8 sText_PokenavCallLanetteGenesectLanetteHome[] = _("Hello? {PLAYER}?\pI heard that you found a\nmysterious drive.\pHow did I get your number?\pDon't worry about that.\pMore importantly, come find me at\nmy house on Route 114!\pWe have something to discuss!");
const u8 sText_DuskullAfterlife[] = _("Hello. This is the Duskull afterlife\nservice calling.\pThis call is to notify you that\nyou will be escorted to the\lafterlife shortly.");
const u8 sText_DuskullAfterlifeNoMercy[] = _("Hello. This is the Duskull afterlife\nservice calling.\pOur sources say that you have failed\nthe NO MERCY challenge.\pYour game is over. See you soon!");
const u8 sText_FailedRyuChallenge[] =  _("You have failed Ryu's Challenge.\nYou can try again in another\lNew Game Plus.\pWe look forward to you trying\nagain!");
const u8 sText_CompletedRyuChallenge[] = _("You have completed\nRyu's Challenge.");
const u8 sText_NavCallDexNav[] = _("Hello Trainer!\pThe DexNav has been added to your\nStart Menu.\pPlease enjoy it!");
const u8 sText_MagmaStage130[] = _("Report to the Mountain Ridge\nnorth of the desert for further\linstructions.");
const u8 sText_MagmaStage210[] = _("Scheduled Heist at Oldale Town's\nPokéMart. Group meet north of town\pfor further briefing.");
const u8 sText_AquaStage10[] = _("This is Admin Shelly speaking.\nYou're to rendezvous with the rest of\lthe crew at Slateport Museum.\pYour objective is to detain and\ninterrogate Captain Stern.");
const u8 sText_AquaStage55[] = _("Admin Shelly speaking.\pI'm sending you to Meteor Falls to\nprovide some assistance to those\lalready in the area.\pDon't be a hero!");
const u8 sText_AquaStage80[] = _("This is an urgent message from Admin\nMatt!\pCalling all members to mobilize at\nthe peak of Mt. Pyre!\pI repeat: the peak of Mt. Pyre!");
const u8 sText_AquaStage91[] = _("{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, this is Shelly.\pWe've discovered what Magma is\nscheming, and it's far from good.\pWe were able to weaken their forces\nat Mt. Chimney, so now they're\ldesperate.\pIt's time to hit them while they're\nstill down!\pMeet me at their hideout located in\nJagged Pass.");
const u8 sText_AquaStage123[] = _("{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, it's time...meet us in the\nmain Team Aqua Headquarters.\pWe'll be waiting by the dock.");


const u8 * const RyuPokenavCallMessages[] = 
{
    [NAVCALL_GENESECTLANETTEFALLARBOR] = sText_PokenavCallLanetteGenesectPokecenter,
    [NAVCALL_GENESECTLANETTE114] = sText_PokenavCallLanetteGenesectLanetteHome,
    [NAVCALL_DUSKULLAFTERLIFE] = sText_DuskullAfterlife,
    [NAVCALL_FAILEDRYUCHALLENGE] = sText_FailedRyuChallenge,
    [NAVCALL_COMPLETEDRYUCHALLENGE] = sText_CompletedRyuChallenge,
    [NAVCALL_DEXNAV] = sText_NavCallDexNav,
    [NAVCALL_MAGMASTAGE130] = sText_MagmaStage130,
    [NAVCALL_MAGMASTAGE210] = sText_MagmaStage210,
    [NAVCALL_AQUASTAGE10] = sText_AquaStage10,
    [NAVCALL_AQUASTAGE55] = sText_AquaStage55,
    [NAVCALL_AQUASTAGE80] = sText_AquaStage80,
    [NAVCALL_AQUASTAGE91] = sText_AquaStage91,
    [NAVCALL_AQUASTAGE123] = sText_AquaStage123,
    [NAVCALL_NOMERCYOVER] = sText_DuskullAfterlifeNoMercy,
};

int RyuTryGetScheduledPokenavCall(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        if ((gSaveBlock2Ptr->RyuPokenavCallSystem[i].active == TRUE))
            return i;
    }
    return 0xFF;
}

void DoScheduledNavCallCheck(void)
{
    u8 index = RyuTryGetScheduledPokenavCall();
    if (index < 4)
    {
        if (gSaveBlock2Ptr->RyuPokenavCallSystem[index].delay == 0) //there's no delay, or delay has elapsed. Send call and clear slot.
        {
            gSaveBlock2Ptr->RyuPokenavCallSystem[index].active = FALSE;
            ShowPokenavFieldMessage(RyuPokenavCallMessages[gSaveBlock2Ptr->RyuPokenavCallSystem[index].messageindex]);
        }
        else //there's an active call, but it has a delay, decrement and return
        {
            gSaveBlock2Ptr->RyuPokenavCallSystem[index].delay--;
        }
    }
}

bool8 ScrCmd_schedulepokenavcall(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);
    u16 delay = ScriptReadHalfword(ctx);
    if (delay > 4)
        delay /= 4;
    SchedulePokenavCallInternal(index, delay);
    return FALSE;
}

void SchedulePokenavCallInternal(u8 index, u16 delay)
{
    u32 i;
    bool32 success = FALSE;
    for (i = 0;i < 4;i++)
    {
        if (gSaveBlock2Ptr->RyuPokenavCallSystem[i].active == FALSE)//puts the scheduled call entry at the first spot available. 
        {
            gSaveBlock2Ptr->RyuPokenavCallSystem[i].messageindex = index;
            gSaveBlock2Ptr->RyuPokenavCallSystem[i].active = TRUE;
            gSaveBlock2Ptr->RyuPokenavCallSystem[i].delay = delay;
            success = TRUE;
            break;
        }
    }
    if (success == FALSE)//all slots were full, replace the last one
    {
        gSaveBlock2Ptr->RyuPokenavCallSystem[i].messageindex = index;
        gSaveBlock2Ptr->RyuPokenavCallSystem[i].active = TRUE;
        gSaveBlock2Ptr->RyuPokenavCallSystem[i].delay = delay;
    }
}