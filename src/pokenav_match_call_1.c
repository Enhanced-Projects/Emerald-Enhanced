#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "gym_leader_rematch.h"
#include "international_string_util.h"
#include "main.h"
#include "match_call.h"
#include "overworld.h"
#include "pokemon.h"
#include "pokenav.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "constants/songs.h"

struct Pokenav3Struct
{
    u16 optionCursorPos;
    u16 maxOptionId;
    const u8 *matchCallOptions;
    u16 headerId;
    u16 numRegistered;
    u16 unkC;
    u32 unk10;
    u32 unk14;
    u32 (*callback)(struct Pokenav3Struct*);
    struct PokenavMatchCallEntries matchCallEntries[MAX_REMATCH_ENTRIES];
};

static u32 CB2_HandleMatchCallInput(struct Pokenav3Struct *);
static u32 GetExitMatchCallMenuId(struct Pokenav3Struct *);
static u32 CB2_HandleMatchCallOptionsInput(struct Pokenav3Struct *);
static u32 CB2_HandleCheckPageInput(struct Pokenav3Struct *);
static u32 CB2_HandleCallInput(struct Pokenav3Struct *);
static u32 sub_81CAD20(s32);
static bool32 sub_81CB1D0(void);

#include "data/text/match_call_messages.h"

static const u8 sMatchCallOptionsNoCheckPage[] = 
{
    MATCH_CALL_OPTION_CALL, 
    MATCH_CALL_OPTION_CANCEL
};

static const u8 sMatchCallOptionsHasCheckPage[] = 
{
    MATCH_CALL_OPTION_CALL, 
    MATCH_CALL_OPTION_CHECK, 
    MATCH_CALL_OPTION_CANCEL
};

bool32 PokenavCallback_Init_MatchCall(void)
{
    struct Pokenav3Struct *state = AllocSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN, sizeof(struct Pokenav3Struct));
    if (!state)
        return FALSE;

    state->callback = CB2_HandleMatchCallInput;
    state->headerId = 0;
    state->unk10 = 0;
    state->unk14 = CreateLoopedTask(sub_81CAD20, 1);
    return TRUE;
}

u32 GetMatchCallCallback(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->callback(state);
}

void FreeMatchCallSubstruct1(void)
{
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
}

static u32 CB2_HandleMatchCallInput(struct Pokenav3Struct *state)
{
    int selection;

    if (JOY_REPEAT(DPAD_UP))
        return POKENAV_MC_FUNC_UP;
    if (JOY_REPEAT(DPAD_DOWN))
        return POKENAV_MC_FUNC_DOWN;
    if (JOY_REPEAT(DPAD_LEFT))
        return POKENAV_MC_FUNC_PG_UP;
    if (JOY_REPEAT(DPAD_RIGHT))
        return POKENAV_MC_FUNC_PG_DOWN;

    if (JOY_NEW(A_BUTTON))
    {
        state->callback = CB2_HandleMatchCallOptionsInput;
        state->optionCursorPos = 0;
        selection = GetSelectedPokenavListIndex();

        if (!state->matchCallEntries[selection].isSpecialTrainer || MatchCall_HasCheckPage(state->matchCallEntries[selection].headerId))
        {
            state->matchCallOptions = sMatchCallOptionsHasCheckPage;
            state->maxOptionId = ARRAY_COUNT(sMatchCallOptionsHasCheckPage) - 1;
        }
        else
        {
            state->matchCallOptions = sMatchCallOptionsNoCheckPage;
            state->maxOptionId = ARRAY_COUNT(sMatchCallOptionsNoCheckPage) - 1;
        }

        return POKENAV_MC_FUNC_SELECT;
    }

    if (JOY_NEW(B_BUTTON))
    {
        if (GetPokenavMode() != POKENAV_MODE_FORCE_CALL_READY)
        {
            state->callback = GetExitMatchCallMenuId;
            return POKENAV_MC_FUNC_EXIT;
        }
        else
        {
            // Cant exit Match Call menu before calling Mr Stone during tutorial
            PlaySE(SE_FAILURE);
        }
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 GetExitMatchCallMenuId(struct Pokenav3Struct *state)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_MATCH_CALL;
}

static u32 CB2_HandleMatchCallOptionsInput(struct Pokenav3Struct *state)
{
    if ((JOY_NEW(DPAD_UP)) && state->optionCursorPos)
    {
        state->optionCursorPos--;
        return POKENAV_MC_FUNC_MOVE_OPTIONS_CURSOR;
    }

    if ((JOY_NEW(DPAD_DOWN)) && state->optionCursorPos < state->maxOptionId)
    {
        state->optionCursorPos++;
        return POKENAV_MC_FUNC_MOVE_OPTIONS_CURSOR;
    }

    if (JOY_NEW(A_BUTTON))
    {
        switch (state->matchCallOptions[state->optionCursorPos])
        {
        case MATCH_CALL_OPTION_CANCEL:
            state->callback = CB2_HandleMatchCallInput;
            return POKENAV_MC_FUNC_CANCEL;
        case MATCH_CALL_OPTION_CALL:
            if (GetPokenavMode() == POKENAV_MODE_FORCE_CALL_READY)
                SetPokenavMode(POKENAV_MODE_FORCE_CALL_EXIT);

            state->callback = CB2_HandleCallInput;
            if (sub_81CB1D0())
                return POKENAV_MC_FUNC_NEARBY_MSG;

            return POKENAV_MC_FUNC_CALL_MSG;
        case MATCH_CALL_OPTION_CHECK:
            state->callback = CB2_HandleCheckPageInput;
            return POKENAV_MC_FUNC_SHOW_CHECK_PAGE;
        }
    }

    if (JOY_NEW(B_BUTTON))
    {
        state->callback = CB2_HandleMatchCallInput;
        return POKENAV_MC_FUNC_CANCEL;
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 CB2_HandleCheckPageInput(struct Pokenav3Struct *state)
{
    if (JOY_REPEAT(DPAD_UP))
        return POKENAV_MC_FUNC_CHECK_PAGE_UP;
    if (JOY_REPEAT(DPAD_DOWN))
        return POKENAV_MC_FUNC_CHECK_PAGE_DOWN;

    if (JOY_NEW(B_BUTTON))
    {
        state->callback = CB2_HandleMatchCallInput;
        return POKENAV_MC_FUNC_EXIT_CHECK_PAGE;
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 CB2_HandleCallInput(struct Pokenav3Struct *state)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        state->callback = CB2_HandleMatchCallInput;
        return POKENAV_MC_FUNC_10;
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 sub_81CAD20(s32 taskState)
{
    int i, j;
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    switch (taskState)
    {
    case 0:
        state->headerId = 0;
        state->numRegistered = 0;
        return LT_INC_AND_CONTINUE;
    case 1:
        for (i = 0, j = state->headerId; i < 30; i++, j++)
        {
            if (MatchCall_GetEnabled(j))
            {
                state->matchCallEntries[state->numRegistered].headerId = j;
                state->matchCallEntries[state->numRegistered].isSpecialTrainer = TRUE;
                state->matchCallEntries[state->numRegistered].mapSec = MatchCall_GetMapSec(j);
                state->numRegistered++;
            }

            if (++state->headerId >= MC_HEADER_COUNT)
            {
                state->unkC = state->headerId;
                state->headerId = 0;
                return LT_INC_AND_CONTINUE;
            }
        }

        return LT_CONTINUE;
    case 2:
        for (i = 0, j = state->headerId; i < 30; i++, j++)
        {
            if (!MatchCall_HasRematchId(state->headerId))
            {
                state->matchCallEntries[state->numRegistered].headerId = state->headerId;
                state->matchCallEntries[state->numRegistered].isSpecialTrainer = FALSE;
                state->matchCallEntries[state->numRegistered].mapSec = 0;
                state->numRegistered++;
            }

            if (++state->headerId == 0)
                return LT_INC_AND_CONTINUE;
        }

        return LT_CONTINUE;
    case 3:
        state->unk10 = 1;
        break;
    }

    return LT_FINISH;
}

int sub_81CAE28(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->unk10;
}

int GetNumberRegistered(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->numRegistered;
}

int sub_81CAE48(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->unkC;
}

int unref_sub_81CAE58(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->numRegistered - state->unkC;
}

int unref_sub_81CAE6C(int arg0)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    arg0 += state->unkC;
    if (arg0 >= state->numRegistered)
        return REMATCH_TABLE_ENTRIES;

    return state->matchCallEntries[arg0].headerId;
}

struct PokenavMatchCallEntries *sub_81CAE94(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->matchCallEntries;
}

u16 GetMatchCallMapSec(int index)
{
    return 0;
}

int GetMatchCallTrainerPic(int index)
{
    return 0;
}

const u8 *GetMatchCallMessageText(int index, u8 *arg1)
{
    return 0;
}

const u8 *GetMatchCallFlavorText(int index, int checkPageEntry)
{
    return 0;
}

u16 GetMatchCallOptionCursorPos(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->optionCursorPos;
}

u16 GetMatchCallOptionId(int optionId)
{

}

void BufferMatchCallNameAndDesc(struct PokenavMatchCallEntries *matchCallEntry, u8 *str)
{

}

int GetIndexDeltaOfNextCheckPageDown(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    int count = 1;
    while (++index < state->numRegistered)
    {
        if (!state->matchCallEntries[index].isSpecialTrainer)
            return count;
        if (MatchCall_HasCheckPage(state->matchCallEntries[index].headerId))
            return count;

        count++;
    }

    return 0;
}

int GetIndexDeltaOfNextCheckPageUp(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    int count = -1;
    while (--index >= 0)
    {
        if (!state->matchCallEntries[index].isSpecialTrainer)
            return count;
        if (MatchCall_HasCheckPage(state->matchCallEntries[index].headerId))
            return count;

        count--;
    }

    return 0;
}

bool32 unref_sub_81CB16C(void)
{
    return FALSE;
}

static bool32 sub_81CB1D0(void)
{
    return FALSE;
}
