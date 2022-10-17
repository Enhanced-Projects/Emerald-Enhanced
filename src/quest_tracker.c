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
#include "RyuDynDeliveries.h"

#include "data/quest_stages.h"

// these are all u16 because apparently it breaks otherwise... wonder if it's alignment bullshit

static const u16 sQuestTrackerBGMap[] = INCBIN_U16("graphics/quest_tracker/quest_tracker_map.bin");
static const u16 sQuestTrackerBGTiles[] = INCBIN_U16("graphics/quest_tracker/quest_tracker.4bpp");
static const u16 sQuestTrackerBGPalette[] = INCBIN_U16("graphics/quest_tracker/quest_tracker.gbapal");
const u8 sText_NA[] = _("N/A");

static void Task_InitQuestTracker(u8 taskId);
static void Task_QuestMain(u8 taskId);
extern void RyuBuildDailyQuestInfoString(void);

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
static u8 sText_DeliverySystem[] = _("Delivery System");
static u8 sText_Daily[] = _("Faction Daily Quest");
static u8 sText_DailyNaturalistss[] = _("Naturalists Daily");
static u8 sText_DailyStudents[] = _("Students Daily");
static u8 sText_DailyNobles[] = _("Nobles Daily");
static u8 sText_DailyPokefans[] = _("Pokéfans Daily");
static u8 sText_DailyOutcasts[] = _("Outcasts Daily");
static u8 sText_DailyProfessionals[] = _("Professionals Daily");

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
    {gMayQuestStages, sTextMay, VAR_RYU_QUEST_MAY},
    {gDeliverySystemQuestStages, sText_DeliverySystem, VAR_RYU_DELIVERY_SYSTEM_DATA},
    {gDailyQuestStages, sText_Daily, VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION},
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

//FULL_COLOR
static bool8 IntializeQuest(u8 taskId)
{
    u16 buf[32];
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
        switch (VarGet(VAR_RYU_THEME_NUMBER)) 
        {
            case THEME_COLOR_LIGHT:
                CpuCopy16(sQuestTrackerBGPalette, buf, 0x20);
                buf[1] = COLOR_LIGHT_THEME_TEXT;       // 1 = text color
                buf[2] = COLOR_NEON_BORDER_2;       // 2 = text shadow & window highlight
                buf[3] = COLOR_LIGHT_THEME_BG_DARK;       // 3 = window border
                buf[4] = COLOR_LIGHT_THEME_BG_LIGHT;               // 4 = bg
                buf[5] = COLOR_NEON_BORDER_2;           //pixel border before last color in the window [[  ]]
                buf[6] = COLOR_LIGHT_THEME_TEXT_SHADOW;           //title shadow
                LoadPalette(buf, 0, 0x20);
                break;
            case THEME_COLOR_DARK:
                LoadPalette(sQuestTrackerBGPalette, 0, 0x20);
                break;
            case THEME_COLOR_USER:
                CpuCopy16(sQuestTrackerBGPalette, buf, 0x20);
                buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];       // 1 = text color
                buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // 2 = text shadow & window highlight
                buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];       // 3 = window border
                buf[4] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];       // 4 = bg
                buf[5] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // 1 = text color
                buf[6] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];       // 1 = text color

                LoadPalette(buf, 0, 0x20);
                break;
            case THEME_COLOR_VANILLA:
                //FULL_COLOR TODO impl vanilla pal
                LoadPalette(gMessageBox_Pal, 0, 0x20);
                break;
        }
        /*if (VarGet(VAR_RYU_THEME_NUMBER) == 2) {
            CpuCopy16(sQuestTrackerBGPalette, buf, 0x20);
            buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[2];       // 1 = text color
            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[14];       // 2 = text shadow & window highlight
            buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[13];       // 3 = window border
            buf[4] = gSaveBlock2Ptr->userInterfaceTextboxPalette[1];       // 4 = bg
            LoadPalette(buf, 0, 0x20);
        } else
            LoadPalette(sQuestTrackerBGPalette, 0, 0x20);*/
        InitWindows(sQuestWindowTemplate);
        InitTextBoxGfxAndPrinters();
        switch (VarGet(VAR_RYU_THEME_NUMBER)) 
        {
            case THEME_COLOR_LIGHT:
                LoadPalette(gHatLightTheme_Pal, 0xF0, 0x20);
                break;
            case THEME_COLOR_DARK:
                LoadPalette(gRyuDarkTheme_Pal, 0xF0, 0x20);
                break;
            case THEME_COLOR_USER:
                CpuCopy16(gRyuDarkTheme_Pal, buf, 0x20);
                buf[1] = COLOR_CREATE_LIGHT_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG]);         // L R button background
                buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];             //actual text
                buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];       //actual text shadow
                LoadPalette(buf, 0xF0, 0x20);
                break;
            case THEME_COLOR_VANILLA:
                LoadPalette(gMessageBox_Pal, 0xF0, 0x20);
                break;
        }
        /*if (VarGet(VAR_RYU_THEME_NUMBER) != 2)
            LoadPalette(gRyuDarkTheme_Pal, 0xF0, 0x20);
        else {
            CpuCopy16(gRyuDarkTheme_Pal, buf, 0x20);
            buf[1] = COLOR_CREATE_LIGHT_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG]);         // L R button background
            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];             //actual text
            buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];       //actual text shadow
            LoadPalette(buf, 0xF0, 0x20);
        }*/
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
#define QUEST_ACTION_OPTIONAL (1 << 6)

// This is a pretty bad excuse for a function 
// since i wanted to do something more useful but failed 
static u32 InputToQuestAction(void) 
{
    u32 finalAction = QUEST_ACTION_NONE;
    switch(gMain.newKeys & (DPAD_UP | DPAD_DOWN | R_BUTTON | L_BUTTON | SELECT_BUTTON))
    {
        case DPAD_UP:
            return QUEST_ACTION_UP;
        case DPAD_DOWN:
            return QUEST_ACTION_DOWN;
        case SELECT_BUTTON:
            return QUEST_ACTION_OPTIONAL;
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
            HatBuildDeliveryInfoString();
            RyuBuildDailyQuestInfoString();
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
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_CloseQuestTracker;
            break;
        }
        case QUEST_ACTION_OPTIONAL:
        {
            FlagSet(FLAG_RYU_OPTIONAL_QT_ACTION);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_CloseQuestTracker;
            break;
        }

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