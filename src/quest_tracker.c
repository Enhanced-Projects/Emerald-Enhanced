#include "global.h"
#include "main.h"
#include "ach_atlas.h"
#include "task.h"
#include "m4a.h"
#include "bg.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "palette.h"
#include "scanline_effect.h"
#include "dma3.h"
#include "sprite.h"
#include "window.h"
#include "text.h"
#include "strings.h"
#include "menu.h"
#include "string_util.h"
#include "sound.h"
#include "overworld.h"
#include "event_data.h"
#include "script.h"
#include "random.h"
#include "graphics.h"
#include "mgba.h"
#include "item.h"
#include "money.h"
#include "new_game.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/items.h"

#include "data/quest_stages.h"

// these are all u16 because apparently it breaks otherwise... wonder if it's alignment bullshit

static const u16 sQuestTrackerBGMap[] = INCBIN_U16("graphics/quest_tracker/quest_tracker_map.bin");
static const u16 sQuestTrackerBGTiles[] = INCBIN_U16("graphics/quest_tracker/quest_tracker.4bpp");
static const u16 sQuestTrackerBGPalette[] = INCBIN_U16("graphics/quest_tracker/quest_tracker.gbapal");
const u8 sText_NA[] = _("N/A");

static void Task_InitQuestTracker(u8 taskId);
static void Task_QuestMain(u8 taskId);

enum
{
    WIN_QUEST_QUESTS,
    WIN_QUEST_QUEST_DATA,
    WIN_QUEST_QUEST_STAGE_DESC,
    WIN_QUEST_COUNT
};

static const struct WindowTemplate sQuestWindowTemplate[] =
{
    [WIN_QUEST_QUESTS] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 3,
        .width = 22,
        .height = 9,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_QUEST_QUEST_DATA] =
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 3,
        .width = 5,
        .height = 9,
        .paletteNum = 15,
        .baseBlock = 199,
    },
    [WIN_QUEST_QUEST_STAGE_DESC] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 28,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 244,
    },
    DUMMY_WIN_TEMPLATE
};

static u8 sTextDevon1[] = _("Devon Corporate");
static u8 sTextDevon2[] = _("Devon Scientist");
static u8 sTextMagma[] = _("Magma");
static u8 sTextLana[] = _("Lana");
static u8 sTextLanette[] = _("Lanette");
static u8 sTextAqua[] = _("Aqua");
static u8 sTextNurse[] = _("Nurse");
static u8 sTextMay[] = _("May");
static u8 sText_DailyNaturalistss[] = _("Naturalists Daily");
static u8 sText_DailyStudents[] = _("Students Daily");
static u8 sText_DailyNobles[] = _("Nobles Daily");
static u8 sText_DailyPokefans[] = _("Pokéfans Daily");
static u8 sText_DailyOutcasts[] = _("Outcasts Daily");
static u8 sText_DailyProfessionals[] = _("Professionals Daily");
static u8 sText_DailyAthletes[] = _("Athletes Daily");

struct QuestData {
    const struct QuestStageDesc * stageDescs;
    u8 * name;
    u16 var;
};

extern const u16 sEasyChatTriangleCursorPalette[];
extern const u32 sEasyChatTriangleCursorGfx[];

static const struct SpriteSheet sAPTierSelectTile = {
    .data = sEasyChatTriangleCursorGfx,
    .size = TILE_SIZE_4BPP,
    .tag = 0x7000
};
static const struct SpritePalette sAPTierSelectPal = {
    .data = sEasyChatTriangleCursorPalette,
    .tag = 0x7000
};

const static struct OamData sAPTierSelectOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

const static struct SpriteTemplate sAPTierSelectSpriteTemplate =
{
    .tileTag = 0x7000,
    .paletteTag = 0x7000,
    .oam = &sAPTierSelectOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sQuestTrackerBGTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static struct QuestData sQuests[] = {
    {gDevonCorporateQuestStages, sTextDevon1, VAR_RYU_QUEST_DEVON_CORPORATE},
    {gDevonScientistQuestStages, sTextDevon2, VAR_RYU_QUEST_DEVON_SCIENTIST},
    {gMagmaQuestStages, sTextMagma, VAR_RYU_QUEST_MAGMA},
    {gAquaQuestStages, sTextAqua, VAR_RYU_QUEST_AQUA},
    {gLanaQuestStages, sTextLana, VAR_RYU_QUEST_LANA},
    {gNurseQuestStages, sTextNurse, VAR_RYU_QUEST_NURSE},
    {gMayQuestStages, sTextMay, VAR_RYU_QUEST_MAY}
};

static u8 sColors[][3] = {
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY},
};


void CB2_QuestTracker(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_QuestTracker(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_OpenQuestTracker(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        DmaFill32(3, 0, (u8 *)VRAM, VRAM_SIZE);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        gMain.state = 1;
        break;
    case 1:
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 2;
        gMain.state++;
        break;
    case 2:
        CreateTask(Task_InitQuestTracker, 0);
        gMain.state++;
        break;
    case 3:
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB_QuestTracker);
        SetMainCallback2(CB2_QuestTracker);
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
        break;
    }
}

static bool8 IntializeQuest(u8 taskId);
static void Task_CloseQuestTracker(u8 taskId);
static void UpdateQuestSelections(u32 offset);
static const struct QuestStageDesc * FindQuestDescFromStage(u32 quest);

#define tQuestSpriteId data[7]

static void Task_InitQuestTracker(u8 taskId)
{
    if(IntializeQuest(taskId))
        gTasks[taskId].func = Task_QuestMain;
}

static bool8 IntializeQuest(u8 taskId)
{
    u32 i;
    switch (gMain.state)
    {
    case 0:
    default:
        if (gPaletteFade.active)
            return 0;
        SetVBlankCallback(NULL);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sQuestTrackerBGTemplates, ARRAY_COUNT(sQuestTrackerBGTemplates));
        SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
        DmaCopy16(3, sQuestTrackerBGTiles, BG_CHAR_ADDR(2), sizeof(sQuestTrackerBGTiles));
        DmaCopy16(3, sQuestTrackerBGMap, GetBgTilemapBuffer(1), sizeof(sQuestTrackerBGMap));
        LoadPalette(sQuestTrackerBGPalette, 0, 0x20);
        InitWindows(sQuestWindowTemplate);
        InitTextBoxGfxAndPrinters();
        LoadPalette(gRyuDarkTheme_Pal, 0xF0, 0x20);
        DeactivateAllTextPrinters();
        PutWindowTilemap(0);
        CopyWindowToVram(0, 3);
        gMain.state = 1;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 2;
        gMain.state++;
        break;
    case 2:
    {
         LoadSpritePalette(&sAPTierSelectPal);
        LoadSpriteSheet(&sAPTierSelectTile);
        // repurposed the cursorspriteid field for later use since we delete the cursor sprite anyways
        gTasks[taskId].tQuestSpriteId = CreateSprite(&sAPTierSelectSpriteTemplate, 12, 32, 0);
        
        gMain.state++;
        break;
    }
    case 3:
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_QuestTracker);
        gMain.state++;
        break;
    case 5:
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        // TODO: Will get rid of STD frames later i would imagine
        for(i = 0; i < WIN_QUEST_COUNT; i++)
        {
            PutWindowTilemap(i);
            //DrawStdWindowFrame(i, TRUE);
        }
        gMain.state++;
        break;
    case 6: // Print Quests + Stages
        UpdateQuestSelections(0);
        gMain.state++;
        break;
    case 7:
        if (!gPaletteFade.active)
        {
            /*const u8 testText[] = _("Aqua");
            const u8 testText2[] = _("005");
            AddTextPrinterParameterized3(WIN_QUEST_QUEST_STAGE_DESC, 0, 2, 3, color, 0, gAquaQuestStages[0].description);
            AddTextPrinterParameterized3(WIN_QUEST_QUESTS, 1, 2, 3, color, 0, testText);
            AddTextPrinterParameterized3(WIN_QUEST_QUEST_DATA, 1, 20 - GetStringWidth(1, testText2, 0)/2, 3, color, 0, testText2);
            */gMain.state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

#define QUEST_ACTION_NONE 0
#define QUEST_ACTION_BACK (1 << 0)
#define QUEST_ACTION_UP (1 << 1)
#define QUEST_ACTION_DOWN (1 << 2)
#define QUEST_ACTION_CHOOSE (1 << 3)
#define QUEST_ACTION_DBG_DECSTGVAR (1 << 4)
#define QUEST_ACTION_DBG_INCSTGVAR (1 << 5)

// This is a pretty bad excuse for a function 
// since i wanted to do something more useful but failed 
static u32 InputToQuestAction(void) 
{
    u32 finalAction = QUEST_ACTION_NONE;
    switch(gMain.newKeys & (DPAD_UP | DPAD_DOWN | R_BUTTON | L_BUTTON))
    {
        case DPAD_UP:
            return QUEST_ACTION_UP;
        case DPAD_DOWN:
            return QUEST_ACTION_DOWN;
        case R_BUTTON:
            if (FlagGet(FLAG_RYU_DEV_MODE) == 1)
                return QUEST_ACTION_DBG_INCSTGVAR;
            else
                return QUEST_ACTION_NONE;
        case L_BUTTON:
            if (FlagGet(FLAG_RYU_DEV_MODE) == 1)
                return QUEST_ACTION_DBG_DECSTGVAR;
            else
                return QUEST_ACTION_NONE;
    }
    if(gMain.newKeys & A_BUTTON) 
        finalAction = QUEST_ACTION_CHOOSE;
    else if(gMain.newKeys & B_BUTTON)
        finalAction = QUEST_ACTION_BACK;
    return finalAction;
}

/* Daily quest data
@PIDGEY here's the data for daily quests
Assignee faction is who gave the quest to the player. This data can be found here:
extern const u8 gFactionNames[8];
gStringVar1 = gFactionNames[VarGet(VAR_RYU_DAILY_QUEST_ASIGNEE_FACTION)];

Type of daily quest is one of 4 types, Fetch, Capture, Travel, or Hatch
extern void BufferDailyQuestType();
will buffer "None", "Fetch", "Capture", "Travel", "Hatch" to gStringVar2

Target of daily quest is the item player needs to get, the map id they need to go to, species they need to hatch, etc.
This can be buffered as a number string.
The value of this depends on the value of VAR_RYU_DAILY_QUEST_TYPE

For fetch types, it's an item ID, Capture types is a Species ID, travel is a map/group hash, Hatch type is also a Species ID.

Data is used for quantities of things
for Fetch type, it's quantity of items,  for capture and hatch, it's empty.
for fetch it can be buffered as a numberstring

for Travel types, it's used a a step counter in RyuDoDailyTravelQuestThings() and is usually amount of steps required in a map.
you want to get the group and map id from the variable and buffer the name of the map that way.

*/

static void UpdateQuestSelections(u32 offset)
{
    u32 i;
    offset = offset + 6 > NELEMS(sQuests) ? NELEMS(sQuests) - 6 : offset;
    FillWindowPixelBuffer(WIN_QUEST_QUESTS, 0);
    FillWindowPixelBuffer(WIN_QUEST_QUEST_DATA, 0);
    for(i = 0; i < 6; i++)
    {
        u8 * numStr = gStringVar1;
        if (VarGet(sQuests[offset + i].var) > 9999)
            StringCopy(numStr, sText_NA);
        else
            ConvertIntToDecimalStringN(numStr, VarGet(sQuests[offset + i].var), STR_CONV_MODE_LEFT_ALIGN, 4);
        AddTextPrinterParameterized3(WIN_QUEST_QUESTS, 0, 10, i * 12, sColors[0], 0xFF, sQuests[offset + i].name);
        AddTextPrinterParameterized3(WIN_QUEST_QUEST_DATA, 0, 20 - GetStringWidth(0, numStr, 0)/2, i * 12, sColors[0], 0xFF, numStr);
    }
    CopyWindowToVram(WIN_QUEST_QUESTS, 3);
    CopyWindowToVram(WIN_QUEST_QUEST_DATA, 3);
}

#define tOptionOffset data[0]
#define tSelectPos data[1]
#define tDbgQuestStgOffset data[2]

#define SELECTED_QUEST(taskId) (gTasks[taskId].tOptionOffset + gTasks[taskId].tSelectPos)

static void Task_QuestMain(u8 taskId)
{
    u32 action = InputToQuestAction();
    switch(action)
    {
        default:
        case QUEST_ACTION_NONE:
            return;
        case QUEST_ACTION_DOWN:
            if(++gTasks[taskId].tSelectPos > 5)
            {
                gTasks[taskId].tSelectPos = 5;
                if((++gTasks[taskId].tOptionOffset + 6) > NELEMS(sQuests))
                {
                    gTasks[taskId].tSelectPos = 0;
                    gTasks[taskId].tOptionOffset = 0;
                }
            }
            UpdateQuestSelections(gTasks[taskId].tOptionOffset);
            gTasks[taskId].tDbgQuestStgOffset = 0;
            FillWindowPixelBuffer(WIN_QUEST_QUEST_STAGE_DESC, 0);
            CopyWindowToVram(WIN_QUEST_QUEST_STAGE_DESC, 3);
            PlaySE(SE_SELECT);
            break;
        case QUEST_ACTION_UP:
            if(--gTasks[taskId].tSelectPos < 0)
            {
                gTasks[taskId].tSelectPos = 0;
                if(--gTasks[taskId].tOptionOffset < 0)
                {
                    gTasks[taskId].tSelectPos = 5;
                    gTasks[taskId].tOptionOffset = NELEMS(sQuests) - 6;
                }
            }
            UpdateQuestSelections(gTasks[taskId].tOptionOffset);
            gTasks[taskId].tDbgQuestStgOffset = 0;
            FillWindowPixelBuffer(WIN_QUEST_QUEST_STAGE_DESC, 0);
            CopyWindowToVram(WIN_QUEST_QUEST_STAGE_DESC, 3);
            PlaySE(SE_SELECT);
            break;
        case QUEST_ACTION_CHOOSE: 
        {
            const struct QuestStageDesc * questDesc = FindQuestDescFromStage(SELECTED_QUEST(taskId));
            FillWindowPixelBuffer(WIN_QUEST_QUEST_STAGE_DESC, 0);
            StringExpandPlaceholders(gStringVar4, questDesc->description);
            AddTextPrinterParameterized4(WIN_QUEST_QUEST_STAGE_DESC, 0, 2, 0, 0, -2, sColors[0], 0xFF, gStringVar4);
            CopyWindowToVram(WIN_QUEST_QUEST_STAGE_DESC, 3);
            gTasks[taskId].func = Task_QuestMain;
            //AddTextPrinterParameterized3(WIN_QUEST_QUEST_STAGE_DESC, 0, 2, 3, sColors[0], 0, questDesc->description);
            break;
        }
        case QUEST_ACTION_DBG_DECSTGVAR:
        {
            u32 stage = SELECTED_QUEST(taskId);
            const struct QuestStageDesc * questDesc;
            gTasks[taskId].tDbgQuestStgOffset--;
            VarSet(sQuests[stage].var, VarGet(sQuests[stage].var) + gTasks[taskId].tDbgQuestStgOffset); // hacky
            questDesc = FindQuestDescFromStage(stage);
            UpdateQuestSelections(gTasks[taskId].tOptionOffset); // also very hacky
            VarSet(sQuests[stage].var, VarGet(sQuests[stage].var) - gTasks[taskId].tDbgQuestStgOffset); // hacky
            FillWindowPixelBuffer(WIN_QUEST_QUEST_STAGE_DESC, 0);
            AddTextPrinterParameterized4(WIN_QUEST_QUEST_STAGE_DESC, 0, 2, 0, 0, -2, sColors[0], 0xFF, questDesc->description);
            CopyWindowToVram(WIN_QUEST_QUEST_STAGE_DESC, 3);
            break;
        }
        case QUEST_ACTION_DBG_INCSTGVAR:
        {
            u32 stage = SELECTED_QUEST(taskId);
            const struct QuestStageDesc * questDesc;
            gTasks[taskId].tDbgQuestStgOffset++;
            VarSet(sQuests[stage].var, VarGet(sQuests[stage].var) + gTasks[taskId].tDbgQuestStgOffset); // hacky
            questDesc = FindQuestDescFromStage(stage);
            UpdateQuestSelections(gTasks[taskId].tOptionOffset); // also very hacky
            VarSet(sQuests[stage].var, VarGet(sQuests[stage].var) - gTasks[taskId].tDbgQuestStgOffset); // hacky
            FillWindowPixelBuffer(WIN_QUEST_QUEST_STAGE_DESC, 0);
            AddTextPrinterParameterized4(WIN_QUEST_QUEST_STAGE_DESC, 0, 2, 0, 0, -2, sColors[0], 0xFF, questDesc->description);
            CopyWindowToVram(WIN_QUEST_QUEST_STAGE_DESC, 3);
            break;
        }
        case QUEST_ACTION_BACK:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_CloseQuestTracker;
            break;
    }
    gSprites[gTasks[taskId].tQuestSpriteId].pos1.y = 32 + 12 * gTasks[taskId].tSelectPos;
}

static const struct QuestStageDesc * FindQuestDescFromStage(u32 quest)
{
    const struct QuestStageDesc * stageDescs = sQuests[quest].stageDescs;
    const struct QuestStageDesc * foundDesc = NULL;
    u32 currentStage = VarGet(sQuests[quest].var);
    u32 temp = 0;
    while (stageDescs->questStage != 0xFFFF)
    {
        if(stageDescs->questStage >= temp && stageDescs->questStage <= currentStage)
        {
            foundDesc = stageDescs;
            temp = stageDescs->questStage;
            if(stageDescs->questStage == currentStage)
                break;
        }
        stageDescs++;
    }
    return foundDesc;
}

extern void CB2_OpenJournal(void);

static void Task_CloseQuestTracker(u8 taskId)
{
    u32 i;
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        for(i = 0; i < 4; i++)
        {
            Free(GetBgTilemapBuffer(i));
            UnsetBgTilemapBuffer(i);
        }
        for(i = 0; i < WIN_QUEST_COUNT; i++)
        {
            RemoveWindow(i);
        }
        DestroyTask(taskId);
        SetMainCallback2(CB2_OpenJournal);
        //SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    }
}