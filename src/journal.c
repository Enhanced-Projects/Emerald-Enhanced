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
#include "constants/battle_frontier.h"
#include "RyuRealEstate.h"
#include "pokedex.h"

static const u8 sJournalBGMap[] = INCBIN_U8("graphics/journal/journal_tiles.bin");
static const u8 sJournalBGTiles[] = INCBIN_U8("graphics/journal/journal_tiles.4bpp");
static const u16 sJournalBGPalette[] = INCBIN_U16("graphics/journal/journal_tiles.gbapal");

static const u8 sAchAtlasJournalIconTiles[] = INCBIN_U8("graphics/journal/ach_atlas_icon.4bpp");
static const u16 sAchAtlasJournalIconPalette[] = INCBIN_U16("graphics/journal/ach_atlas_icon.gbapal");

static const u8 sPowersJournalIconTiles[] = INCBIN_U8("graphics/journal/powers_icon.4bpp");
static const u16 sPowersJournalIconPalette[] = INCBIN_U16("graphics/journal/powers_icon.gbapal");

static const u8 sQuestsJournalIconTiles[] = INCBIN_U8("graphics/journal/quests_icon.4bpp");
static const u16 sQuestsJournalIconPalette[] = INCBIN_U16("graphics/journal/quests_icon.gbapal");

static const u8 sJournalIconTiles[] = INCBIN_U8("graphics/journal/journal_icon.4bpp");
static const u16 sJournalIconPalette[] = INCBIN_U16("graphics/journal/journal_icon.gbapal");

static const u8 sFactionsIconTiles[] = INCBIN_U8("graphics/journal/factions_icon.4bpp");
static const u16 sFactionsIconPalette[] = INCBIN_U16("graphics/journal/factions_icon.gbapal");

static const u8 sGymFrontierIconTiles[] = INCBIN_U8("graphics/journal/frontier_gym_badge_tiles.4bpp");
static const u16 sGymFrontierIconPalette[] = INCBIN_U16("graphics/journal/frontier_gym_badge_tiles.gbapal");

const u8 sTextRyuEasyMode[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Easy Mode");
const u8 sTextRyuNormalMode[] = _("Normal Mode");
const u8 sTextRyuChallengeMode[] = _("{COLOR LIGHT_RED}{SHADOW RED}Challenge Mode");
const u8 sTextRyuHardcoreMode[] = _("{COLOR LIGHT_RED}{SHADOW LIGHT_GREY}HARDCORE Mode");
const u8 sTextRyuFrontierMode[] = _("{COLOR LIGHT_GREEN}{SHADOW GREEN}Frontier Mode");
const u8 sTextRyuSpecialChallenge[] = _("NM/Ryu's Challenge");
extern const u8 sText_Colon[];
extern const u8 sText_Space[];

enum // much window, such complexity 
{
    WIN_JOURNAL_STATS,
    //WIN_JOURNAL_QUEST_STAGE,
    //WIN_JOURNAL_IMPORTANT_VALUES,
    WIN_JOURNAL_TRAINER_NAME,
    WIN_JOURNAL_TRAINER_ID,
    WIN_JOURNAL_TRAINER_MONEY,
    WIN_JOURNAL_PAGE_NAME,
    WIN_JOURNAL_GAME_MODE,
    COUNT_JOURNAL_WINDOWS
};

static const struct SpriteFrameImage sGymFrontierIconImages[] =
{
    {
        .data = sGymFrontierIconTiles+TILE_SIZE_4BPP,
        .size = TILE_SIZE_4BPP,
    },
    {
        .data = sGymFrontierIconTiles+TILE_SIZE_4BPP*2,
        .size = TILE_SIZE_4BPP,
    },
    {
        .data = sGymFrontierIconTiles+TILE_SIZE_4BPP*3,
        .size = TILE_SIZE_4BPP,
    },
};

static u8 sColors[][3] = {
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY},
};

static const struct WindowTemplate sJournalWindowTemplate[] =
{
    [WIN_JOURNAL_STATS] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 6,
        .width = 28,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    /*
    [WIN_JOURNAL_QUEST_STAGE] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 309,
    },
    [WIN_JOURNAL_IMPORTANT_VALUES] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 28,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 421,
    },
    */
   [WIN_JOURNAL_TRAINER_NAME] =
   {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 14,
        .width = 6,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 309,
   },
   [WIN_JOURNAL_TRAINER_ID] =
   {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 14,
        .width = 4,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 321,
   },
   [WIN_JOURNAL_TRAINER_MONEY] =
   {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 14,
        .width = 11,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 329,
   },
   [WIN_JOURNAL_PAGE_NAME] =
   {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 28,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 351,
   },
   [WIN_JOURNAL_GAME_MODE] =
   {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 16,
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 407,
   },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sJournalBGTemplates[] =
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

struct JournalEntryButtonData
{
    struct SpriteFrameImage spriteImages[2];
    const u16 * palette;
    void (*callback2)(void);
};

enum
{
    JOURNAL_OPTION_FACTIONS, // somehow this feels useless
    JOURNAL_OPTION_ACH_ATLAS,
    JOURNAL_OPTION_POWERS,
    JOURNAL_OPTION_QUESTS,
    JOURNAL_OPTION_COUNT,
    JOURNAL_OPTION_EXIT,  // should always be after JOURNAL_OPTION_COUNT and at the end
};

void Task_InitAtlas(u8 taskId);
void Task_OpenAPMenu(u8); // should probably change the AP menu to not be stupid
void Task_InitAPMenu(u8 taskId);

void CB2_OpenQuestTracker(void);
void CB2_OpenFactionUI(void);

static const struct JournalEntryButtonData sJounralButtons[JOURNAL_OPTION_COUNT] =
{
    [JOURNAL_OPTION_FACTIONS] = {
        .spriteImages = 
        {
            {
                .data = sFactionsIconTiles,
                .size = TILE_SIZE_4BPP*64,
            },
            {
                .data = sFactionsIconTiles+TILE_SIZE_4BPP*64,
                .size = TILE_SIZE_4BPP*64,
            },
        },
        .palette = sFactionsIconPalette,
        .callback2 = CB2_OpenFactionUI
    },
    [JOURNAL_OPTION_ACH_ATLAS] = {
        .spriteImages = 
        {
            {
                .data = sAchAtlasJournalIconTiles,
                .size = TILE_SIZE_4BPP*64,
            },
            {
                .data = sAchAtlasJournalIconTiles+TILE_SIZE_4BPP*64,
                .size = TILE_SIZE_4BPP*64,
            },
        },
        .palette = sAchAtlasJournalIconPalette,
        .callback2 = CB2_OpenAtlas,
    },
    [JOURNAL_OPTION_POWERS] = {
        .spriteImages = 
        {
            {
                .data = sPowersJournalIconTiles,
                .size = TILE_SIZE_4BPP*64,
            },
            {
                .data = sPowersJournalIconTiles+TILE_SIZE_4BPP*64,
                .size = TILE_SIZE_4BPP*64,
            },
        },
        .palette = sPowersJournalIconPalette,
        .callback2 = CB2_OpenAPMenu,
    },
    
    [JOURNAL_OPTION_QUESTS] = {
        .spriteImages = 
        {
            {
                .data = sQuestsJournalIconTiles,
                .size = TILE_SIZE_4BPP*64,
            },
            {
                .data = sQuestsJournalIconTiles+TILE_SIZE_4BPP*64,
                .size = TILE_SIZE_4BPP*64,
            },
        },
        .palette = sQuestsJournalIconPalette,
        .callback2 = CB2_OpenQuestTracker,
    },
    
    /*
    [JOURNAL_OPTION_EXIT] = {
        .callback2 = CB2_ReturnToFieldWithOpenMenu,
    },
    */
};

const struct OamData sJournalIconsOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

const struct OamData s8x8IconsOam =
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
    .paletteNum = 1,
};

static const union AnimCmd sButtonNormalAnimation[] = {
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sButtonGlowAnimation[] = {
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sButtonAnims[] =
{
    sButtonNormalAnimation,
    sButtonGlowAnimation
};

static const union AnimCmd sIconGymAnimation[] = {
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sIconFrontierSilverAnimation[] = {
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sIconFrontierGoldAnimation[] = {
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sIconAnims[] =
{
    sIconGymAnimation,
    sIconFrontierSilverAnimation,
    sIconFrontierGoldAnimation
};

static void ButtonSpriteCB(struct Sprite *sprite);

static const struct SpriteTemplate sButtonSpriteTemplate =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0xFFFF,
    .oam = &sJournalIconsOam,
    .anims = sButtonAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ButtonSpriteCB,
};

static const struct SpriteTemplate s8x8IconSpriteTemplate =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0xFFFF,
    .oam = &s8x8IconsOam,
    .anims = sIconAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

EWRAM_DATA static u8 sButtonSpriteIds[JOURNAL_OPTION_COUNT] = {0}; // TODO: fix array size

static void Task_InitJournal(u8 taskId);
static void Task_JournalMain(u8 taskId);

static bool8 IntializeJournal(void);

struct SpriteTemplate CreateButtonSpriteTemplate(u32 buttonId) // TODO: now useless don't use
{
    struct SpriteTemplate sprtTmplt;
    sprtTmplt.tileTag = 0xFFFF;
    sprtTmplt.tileTag = 0xFFFF;
    sprtTmplt.oam = &sJournalIconsOam;
    sprtTmplt.anims = sButtonAnims;
    sprtTmplt.images = sJounralButtons[buttonId].spriteImages;
    sprtTmplt.affineAnims = gDummySpriteAffineAnimTable;
    sprtTmplt.callback = SpriteCallbackDummy;
    return sprtTmplt;
}

void CB2_Journal(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Journal(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_OpenJournal(void)
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
        CreateTask(Task_InitJournal, 0);
        gMain.state++;
        break;
    case 3:
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB_Journal);
        SetMainCallback2(CB2_Journal);
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
        break;
    }
}

#define TOP_SPACING 17
#define LEFT_MIDDLE 112

enum
{
    JOURNALSTAT_GAME_STAT,
    JOURNALSTAT_VARIABLE,
    JOURNALSTAT_CUSTOM,
};

struct JournalStatData
{
    const u8 * statName;
    u8 * (*statValueStrFunc)(u8 * buffer);
    u16 statId;
    u8 numberCount;
    u8 flags;
};

#define JOURNAL_STAT(name, numStrFunc, statId, numberCount, flags) \
    {   \
        (u8[])_(name),   \
        numStrFunc,   \
        statId,   \
        numberCount,   \
        flags,   \
    }   \

#define JOURNAL_STAT_END JOURNAL_STAT("", NULL, 0xFFFF, 0, 0)
u8 * BufferStatNumberString(const struct JournalStatData * stat, u8 * buffer)
{
    u32 statType = stat->flags & 0xF;
    switch(statType)
    {
        case JOURNALSTAT_GAME_STAT:
            return ConvertIntToDecimalStringN(buffer, GetGameStat(stat->statId), STR_CONV_MODE_LEFT_ALIGN, stat->numberCount);
        case JOURNALSTAT_VARIABLE:
            return ConvertIntToDecimalStringN(buffer, VarGet(stat->statId), STR_CONV_MODE_LEFT_ALIGN, stat->numberCount);
        case JOURNALSTAT_CUSTOM:
            return stat->statValueStrFunc ? stat->statValueStrFunc(buffer) : NULL;
    }
    return NULL;
}

u8 * GetPlantedBerries(u8 * const buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_PLANTED_BERRIES), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetTotalBattles(u8 * const buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_TOTAL_BATTLES), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetPokeCaptures(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_POKEMON_CAPTURES), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetEggsHatched(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_HATCHED_EGGS), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetEvolvedPokemonStat(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_EVOLVED_POKEMON), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetTimesHealedStat(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_USED_POKECENTER), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetBattlesWon(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_BATTLES_WON), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetRibbonsReceived(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_RECEIVED_RIBBONS), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetPlayerContestsWon(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_WON_CONTEST), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetPlayerContestsEntered(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_ENTERED_CONTEST), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetPlayerBounty(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_PLAYER_BOUNTY), STR_CONV_MODE_LEFT_ALIGN, 10);
}

extern int RyuGetPartnerCount();
u8 * GetPartnerCount(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, RyuGetPartnerCount(), STR_CONV_MODE_LEFT_ALIGN, 1);
}

u8 * GetMiningSkill(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_PLAYER_MINING_SKILL), STR_CONV_MODE_LEFT_ALIGN, 1);
}

u8 * GetMiningExp(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_PLAYER_MINING_SKILL_EXP), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetBotanySkill(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_PLAYER_BOTANY_SKILL), STR_CONV_MODE_LEFT_ALIGN, 1);
}

u8 * GetBotanyExp(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_PLAYER_BOTANY_SKILL_EXP), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetAlchemySkill(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL), STR_CONV_MODE_LEFT_ALIGN, 1);
}

u8 * GetAlchemyExp(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP), STR_CONV_MODE_LEFT_ALIGN, 4);
}

u8 * GetTotalKOs(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_TOTAL_FAINTS), STR_CONV_MODE_LEFT_ALIGN, 5);
}

u8 * GetTitleDefenseWins(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, VarGet(VAR_RYU_TITLE_DEFENSE_WINS), STR_CONV_MODE_LEFT_ALIGN, 3);
}

u8 * GetAchivements(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, CountTakenAchievements(), STR_CONV_MODE_LEFT_ALIGN, 3);
}

u8 * GetBankBalance(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE), STR_CONV_MODE_LEFT_ALIGN, 10);
}

extern int RyuGetNumberOwnedProperties(void);
u8 * GetOwnedProperties(u8 * buffer)
{
    return ConvertIntToDecimalStringN(buffer, RyuGetNumberOwnedProperties(), STR_CONV_MODE_LEFT_ALIGN, 2);
}

u8 * GetNetWorth(u8 * buffer)
{
    u32 balance = (GetGameStat(GAME_STAT_FRONTIERBANK_BALANCE));
    u32 money = (GetMoney(&gSaveBlock1Ptr->money));
    u32 totalPropertyValue = 0;
    u8 id = 0;


    for (id=0; id < NUM_PROPERTIES; id++)
    {
        if (CheckOwnedProperty(id))
            totalPropertyValue += gRyuPropertyData[id][0];
    }
    if (totalPropertyValue + balance + money >= 1000000)
        GiveAchievement(ACH_MILLIONAIRE);

    if (totalPropertyValue + balance + money >= 100000000)
        GiveAchievement(ACH_MONEYBAGS);

    return ConvertUIntToDecimalStringN(buffer, balance + money + totalPropertyValue, STR_CONV_MODE_LEFT_ALIGN, 10);
}

u8 * GetPropertiesOwned(u8 * buffer)
{
    u8 propertiesOwned = (RyuGetNumberOwnedProperties());
    return ConvertIntToDecimalStringN(buffer, propertiesOwned, STR_CONV_MODE_LEFT_ALIGN, 2);
}

u8 * BufferPokedexSeenCountStr(u8 * buffer)
{
    u32 val = GetNationalPokedexCount(FLAG_GET_SEEN);
    return ConvertIntToDecimalStringN(buffer, val, STR_CONV_MODE_LEFT_ALIGN, 10);
}

u8 * BufferPokedexCaughtCountStr(u8 * buffer)
{
    u32 val = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    return ConvertIntToDecimalStringN(buffer, val, STR_CONV_MODE_LEFT_ALIGN, 10);

}

static const struct JournalStatData sJournalGeneralStatsPage[] =
{
    JOURNAL_STAT("Prestige Level", NULL, VAR_RYU_NGPLUS_COUNT, 3, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Achievements", GetAchivements, 0, 3, JOURNALSTAT_CUSTOM),
    JOURNAL_STAT("Dex Seen", BufferPokedexSeenCountStr, 0, 3, JOURNALSTAT_CUSTOM),
    JOURNAL_STAT("Dex Caught", BufferPokedexCaughtCountStr, 0, 3, JOURNALSTAT_CUSTOM),
    JOURNAL_STAT("Legendaries Caught", NULL, VAR_RYU_LEGENDARIES_CAUGHT, 2, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Steps Taken Alone", NULL, GAME_STAT_STEPS, 6, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Healed Party", NULL, GAME_STAT_USED_POKECENTER, 4, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Bounty", NULL, GAME_STAT_PLAYER_BOUNTY, 6, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT_END
};

static const struct JournalStatData sJournalLifeSkillsPage[] =
{
    JOURNAL_STAT("Botany Lv", NULL, VAR_RYU_PLAYER_BOTANY_SKILL, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Botany exp", NULL, VAR_RYU_PLAYER_BOTANY_SKILL_EXP, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Mining Lv", NULL, VAR_RYU_PLAYER_MINING_SKILL, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Mining exp", NULL, VAR_RYU_PLAYER_MINING_SKILL_EXP, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Alchemy Lv", NULL, VAR_RYU_PLAYER_ALCHEMY_SKILL, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Alchemy exp", NULL, VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT_END
};

static const struct JournalStatData sJournalBattleStatsPage[] =
{
    JOURNAL_STAT("Total Battles", NULL, GAME_STAT_TOTAL_BATTLES, 6, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Total Captures", NULL, GAME_STAT_POKEMON_CAPTURES, 6, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Battles Won", NULL, GAME_STAT_BATTLES_WON, 6, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Battles Lost", NULL, GAME_STAT_BATTLES_LOST, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Knockouts", NULL, VAR_RYU_TOTAL_FAINTS, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("EXP Drive", NULL, GAME_STAT_EXP_DRIVE, 8, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Title Defense Wins", NULL, VAR_RYU_TITLE_DEFENSE_WINS, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Gym Leaders Fought", NULL, VAR_RYU_GYM_LEADERS_FOUGHT, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT_END
};

static const struct JournalStatData sJournalTrainingStatsPage[] =
{
    JOURNAL_STAT("Contests Entered", NULL, GAME_STAT_ENTERED_CONTEST, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Contests Won", NULL, GAME_STAT_WON_CONTEST, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Pokemon Evolved", NULL, GAME_STAT_EVOLVED_POKEMON, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Eggs Hatched", NULL, GAME_STAT_HATCHED_EGGS, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Ribbons Received", NULL, GAME_STAT_RECEIVED_RIBBONS, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Total Captures", NULL, GAME_STAT_POKEMON_CAPTURES, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Pokeblocks Made", NULL, GAME_STAT_POKEBLOCKS, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Pokeblocks Used", NULL, GAME_STAT_POKEBLOCKS_FED, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT_END
};

static const struct JournalStatData sJournalFinancialStatsPage[] =
{
    JOURNAL_STAT("Bank Balance", NULL, GAME_STAT_FRONTIERBANK_BALANCE, 10, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT("Properties Owned",  GetOwnedProperties, 0, 2, JOURNALSTAT_CUSTOM),
    JOURNAL_STAT("Net Worth", GetNetWorth, 0, 10, JOURNALSTAT_CUSTOM), //why was this 5 digits? it can be up to 10!
    JOURNAL_STAT("Days Interest gained", NULL, VAR_RYU_DAYS_INTEREST_GAINED, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Property Repairs", NULL, VAR_RYU_PROPERTIES_REPAIRED, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Shipments Delivered", NULL, 0xFFFF, 5, JOURNALSTAT_VARIABLE), //will be added in a later update. Feature not available yet.
    JOURNAL_STAT_END
};

static const struct JournalStatData sJournalSocialStatsPage[] =
{
    JOURNAL_STAT("Num Companions", GetPartnerCount, 0, 2, JOURNALSTAT_CUSTOM),
    JOURNAL_STAT("Times Stayed Over", NULL, VAR_RYU_TIMES_STAYED_WITH_COMPANION, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Companion Fights", NULL, VAR_RYU_FOLLOWER_BATTLES, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Companion E4 Runs", NULL, VAR_RYU_FOLLOWER_ELITE_MATCHES, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Quests Done", NULL, VAR_RYU_QUESTS_FINISHED, 5, JOURNALSTAT_VARIABLE),
    JOURNAL_STAT("Steps w/ Friends", NULL, GAME_STAT_STEPS_FOLLOWER, 5, JOURNALSTAT_GAME_STAT),
    JOURNAL_STAT_END
};

static const struct JournalStatData * sJournalStatPages[] = 
{
    sJournalGeneralStatsPage,
    sJournalLifeSkillsPage,
    sJournalBattleStatsPage,
    sJournalTrainingStatsPage,
    sJournalFinancialStatsPage,
    sJournalSocialStatsPage
};

static const u8 * sJournalPageNames[]=
{
    (u8[])_("General Stats"),
    (u8[])_("Life Skills"),
    (u8[])_("Battle Stats"),
    (u8[])_("Training Stats"),
    (u8[])_("Financial Stats"),
    (u8[])_("Social Stats"),
};
/*
u32 CountStatArrayLength(const struct JournalStatData * journalData)
{
    u32 i;
    for(i = 0; journalData++->statValueStrFunc; i++);
    return i;
}
*/

extern int CountBadges(void);
static void DrawJournalStatPage(u32 pageNum)
{
    const struct JournalStatData * journalStat = sJournalStatPages[pageNum];
    u32 i;

    u32 top = 0, left = 1;
    for(i = 0; i < 8 && journalStat->statId != 0xFFFF; i++)
    {
        if(!BufferStatNumberString(journalStat, gStringVar4))
            continue;
        if(i != 0)
        {
            if(i & 1) left += LEFT_MIDDLE+1;
            else 
            {
                left = 1;
                top += TOP_SPACING;
            }
        }
        AddTextPrinterParameterized3(WIN_JOURNAL_STATS, 0, left, top, sColors[0], 0xFF, journalStat->statName); // TODO: speed 0xFF
        AddTextPrinterParameterized3(WIN_JOURNAL_STATS, 0, (left+LEFT_MIDDLE-3)-GetStringWidth(0, gStringVar4, 0), top, sColors[0], 0xFF, gStringVar4);
        journalStat++;
    }
    CopyWindowToVram(WIN_JOURNAL_STATS, 2);
    left = 1;
    top = 1;
    AddTextPrinterParameterized3(WIN_JOURNAL_PAGE_NAME, 0, left, top, sColors[0], 0xFF, (u8[])_("{LEFT_ARROW} {L_BUTTON}"));
    left = 224;
    left -= GetStringWidth(0, (u8[])_("{R_BUTTON} {RIGHT_ARROW}"), 0);
    AddTextPrinterParameterized3(WIN_JOURNAL_PAGE_NAME, 0, left, top, sColors[0], 0xFF, (u8[])_("{R_BUTTON} {RIGHT_ARROW}"));
    left = 112 - GetStringWidth(0, sJournalPageNames[pageNum], 0) / 2;
    AddTextPrinterParameterized3(WIN_JOURNAL_PAGE_NAME, 0, left, top, sColors[0], 0xFF, sJournalPageNames[pageNum]);
    CopyWindowToVram(WIN_JOURNAL_PAGE_NAME, 2);
}

static void DrawJournalStatText(void)
{
    u8 * textBuffer;
    u32 length = 0;

    DrawJournalStatPage(0);
    AddTextPrinterParameterized3(WIN_JOURNAL_TRAINER_NAME, 0, 0, 4, sColors[0], 0, gSaveBlock2Ptr->playerName);
    ConvertIntToDecimalStringN(gStringVar4, (u16)GetTrainerId(gSaveBlock2Ptr->playerTrainerId), STR_CONV_MODE_LEADING_ZEROS, 5);
    AddTextPrinterParameterized3(WIN_JOURNAL_TRAINER_ID, 0, 4, 4, sColors[0], 0, gStringVar4);
    textBuffer = StringCopy(gStringVar4, gText_TrainerCardMoney);
    *textBuffer++ = CHAR_SPACE;
    *textBuffer++ = CHAR_SPACE;
    ConvertIntToDecimalStringN(textBuffer, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_RIGHT_ALIGN, 10);
    AddTextPrinterParameterized3(WIN_JOURNAL_TRAINER_MONEY, 0, 4, 4, sColors[0], 0, gStringVar4);

    switch(VarGet(VAR_RYU_GAME_MODE))
    {
        case 0:
            StringCopy(gRyuStringVar1, sTextRyuEasyMode);
            break;
        case 1:
        {
            if (FlagGet(FLAG_RYU_DOING_RYU_CHALLENGE) == TRUE)
            {
                StringCopy(gRyuStringVar1, sTextRyuSpecialChallenge);
                break;
            }
            else
            {
                StringCopy(gRyuStringVar1, sTextRyuNormalMode);
                break;
            }
        }
        case 2:
            StringCopy(gRyuStringVar1, sTextRyuChallengeMode);
            break;
        case 3:
            StringCopy(gRyuStringVar1, sTextRyuHardcoreMode);
            break;
        case 4:
            StringCopy(gRyuStringVar1, sTextRyuFrontierMode);
            break;
    }
    AddTextPrinterParameterized3(WIN_JOURNAL_GAME_MODE, 0, 0, 4, sColors[0], 0, gRyuStringVar1);
}

static void Task_InitJournal(u8 taskId)
{
    if(IntializeJournal())
    {
        gTasks[taskId].func = Task_JournalMain;
        // TODO: i'll decide what to do with these later
        //gKeyRepeatContinueDelay = -1;
        //gKeyRepeatStartDelay = -1;
    }
}
//FULL_COLOR
static bool8 IntializeJournal(void)
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
        InitBgsFromTemplates(0, sJournalBGTemplates, ARRAY_COUNT(sJournalBGTemplates));
        SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
        DmaCopy16(3, sJournalBGTiles, BG_CHAR_ADDR(2), sizeof(sJournalBGTiles));
        DmaCopy16(3, sJournalBGMap, GetBgTilemapBuffer(1), sizeof(sJournalBGMap));
        switch (VarGet(VAR_RYU_THEME_NUMBER)) 
        {
            case THEME_COLOR_LIGHT:
                CpuCopy16(sJournalBGPalette, buf, 0x20);
                buf[6] = COLOR_NEON_BORDER_2;
                buf[10] = COLOR_LIGHT_THEME_BG_DARK;
                buf[14] = COLOR_LIGHT_THEME_BG_LIGHT;       // 14 = background
                buf[15] = COLOR_NEON_BORDER_2;       // 15 = pixel border before end color
                LoadPalette(buf, 0, 0x20);
                break;
            case THEME_COLOR_DARK:
                LoadPalette(sJournalBGPalette, 0, 0x20);
                break;
            case THEME_COLOR_USER:
                CpuCopy16(sJournalBGPalette, buf, 0x20);
                //Shifting r -> b, g -> r, b -> g   <==>   0.3 0.59 0.11 -> 0.59, 0.11, 0.3
                //So in the worst case 31, 15, 0 which is 9.3 + 8.85 + 0 = 18 turns into 15, 1, 31 which is 4.5 + 0 + 3.41 = 7 a reasonable gap for worst case
                buf[1] = COLOR_AUTO_SHADE_CONTRAST_INVERSE(COLOR_CHANGE_HUE_KEEP_GS(COLOR_CHANGE_HUE_KEEP_GS(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT])), gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], THRESHOLD_HIGH);        // 1 = text Name: Id:
                buf[6] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // 6 = window highlight
                //Shifting r -> b...
                //see comment above
                buf[8] = COLOR_AUTO_SHADE(COLOR_AUTO_SHADE_COND(COLOR_CHANGE_HUE_KEEP_GS(COLOR_CHANGE_HUE_KEEP_GS(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT])), COMPARE_SKIP_COLOR_1, COMPARE_SKIP_COLOR_2, COLOR_GET_AS_CONTRAST_INVERSE_ACTION(COLOR_CHANGE_HUE_KEEP_GS(COLOR_CHANGE_HUE_KEEP_GS(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT])), gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], THRESHOLD_DEFAULT), THRESHOLD_DEFAULT), THRESHOLD_DEFAULT);        // 8 = text shadow Name: Id: 
                buf[10] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];      // 10 = window border

                // Using conditional shading if background contrast with Red table color and Green table color
                buf[12] = COLOR_AUTO_SHADE_COND(buf[12], gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], GREYSCALE_TO_COLOR(10), SHADE_ACTION_LIGHT, THRESHOLD_DEFAULT);   // UI ELEMENT red table (p1-8)
                buf[13] = COLOR_AUTO_SHADE_COND(buf[13], gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], GREYSCALE_TO_COLOR(10), SHADE_ACTION_LIGHT, THRESHOLD_DEFAULT);   // UI ELEMENT green table (f1-7)

                buf[14] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];       // 14 = background
                buf[15] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // 15 = pixel border before end color
                LoadPalette(buf, 0, 0x20);
                break;
            case THEME_COLOR_VANILLA:
                //TODO impl vanilla colors
                LoadPalette(gMessageBox_Pal, 0, 0x20);
                break;

        }
        /*if (VarGet(VAR_RYU_THEME_NUMBER) != 2)
            LoadPalette(sJournalBGPalette, 0, 0x20);
        else {
            CpuCopy16(sJournalBGPalette, buf, 0x20);
            //Shifting r -> b, g -> r, b -> g   <==>   0.3 0.59 0.11 -> 0.59, 0.11, 0.3
            //So in the worst case 31, 15, 0 which is 9.3 + 8.85 + 0 = 18 turns into 15, 1, 31 which is 4.5 + 0 + 3.41 = 7 a reasonable gap for worst case
            buf[1] = COLOR_AUTO_SHADE_CONTRAST_INVERSE(COLOR_CHANGE_HUE_KEEP_GS(COLOR_CHANGE_HUE_KEEP_GS(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT])), gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], THRESHOLD_HIGH);        // 1 = text Name: Id:
            buf[6] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];       // 6 = window highlight
            
            //Shifting r -> b, g -> r, b -> g
            //see comment above
            buf[8] = COLOR_AUTO_SHADE(COLOR_AUTO_SHADE_COND(COLOR_CHANGE_HUE_KEEP_GS(COLOR_CHANGE_HUE_KEEP_GS(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT])), COMPARE_SKIP_COLOR_1, COMPARE_SKIP_COLOR_2, COLOR_GET_AS_CONTRAST_INVERSE_ACTION(COLOR_CHANGE_HUE_KEEP_GS(COLOR_CHANGE_HUE_KEEP_GS(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT])), gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], THRESHOLD_DEFAULT), THRESHOLD_DEFAULT), THRESHOLD_DEFAULT);        // 8 = text shadow Name: Id: 
            buf[10] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];      // 10 = window border
            
            // Using conditional shading if background contrast with Red table color and Green table color
            buf[12] = COLOR_AUTO_SHADE_COND(buf[12], gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], GREYSCALE_TO_COLOR(10), SHADE_ACTION_LIGHT, THRESHOLD_DEFAULT);   // fixed color UI ELEMENT green table (b1-8)
            buf[13] = COLOR_AUTO_SHADE_COND(buf[13], gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG], GREYSCALE_TO_COLOR(10), SHADE_ACTION_LIGHT, THRESHOLD_DEFAULT);   // fixed color UI ELEMENT red table (f1-7)
            
            buf[14] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];       // 14 = background
            
            LoadPalette(buf, 0, 0x20);
        }*/
        InitWindows(sJournalWindowTemplate);
        InitTextBoxGfxAndPrinters();
        LoadPalette(gMessageBox_Pal, 0xC0, 0x20);
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_LIGHT:
                LoadPalette(gHatLightTheme_Pal, 0xF0, 0x20);
                break;
            case THEME_COLOR_DARK:
                LoadPalette(gRyuDarkTheme_Pal, 0xF0, 0x20);
                break;
            case THEME_COLOR_USER:            
                CpuCopy16(gRyuDarkTheme_Pal, buf, 0x20);
                buf[1] = COLOR_CREATE_LIGHT_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG]);         
                buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];
                buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];
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
            buf[1] = COLOR_CREATE_LIGHT_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG]);         
            buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];
            buf[3] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];
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
        u32 i;
        struct SpriteTemplate spriteTemplate = sButtonSpriteTemplate;
        static const u8 buttonXPos[JOURNAL_OPTION_COUNT] = {8, 74, 140, 188}; //! EVIL hardcoding
        for(i = 0; i < JOURNAL_OPTION_COUNT; i++)
        {
            spriteTemplate.images = sJounralButtons[i].spriteImages;
            sButtonSpriteIds[i] = CreateSprite(&spriteTemplate, 32 + buttonXPos[i], 42, 0);
            gSprites[sButtonSpriteIds[i]].data[0] = !i;
        }
        
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_LIGHT:
                CpuCopy16(sJounralButtons[0].palette, buf, 0x20);
                //bg
                buf[1] = COLOR_LIGHT_THEME_BG_LIGHT;         
                //selected shadow
                buf[2] = COLOR_LIGHT_THEME_BG_DARK;
                //unselected shadow
                buf[3] = COLOR_LIGHT_THEME_TEXT_SHADOW;
                //text shadow
                buf[4] = COLOR_NEON_BORDER_2;
                //external border
                buf[5] = COLOR_NEON_BORDER_2;
                //text
                buf[6] = COLOR_LIGHT_THEME_TEXT;
                LoadPalette(buf, 0x100, 0x20);
                break;
            case THEME_COLOR_DARK:
                LoadPalette(sJounralButtons[0].palette, 0x100, 0x20);
                break;
            case THEME_COLOR_USER:
                CpuCopy16(sJounralButtons[0].palette, buf, 0x20);
                buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];         
                buf[2] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW];
                buf[3] = COLOR_AUTO_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT_SHADOW], THRESHOLD_DEFAULT);
                buf[4] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];
                buf[5] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT];
                buf[6] = COLOR_AUTO_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_TEXT], THRESHOLD_DEFAULT);
                LoadPalette(buf, 0x100, 0x20);
                break;
            case THEME_COLOR_VANILLA:
                LoadPalette(gMessageBox_Pal, 0x100, 0x20); //FULL_COLOR TODO impl vanilla pal
                break;
        }
        spriteTemplate = s8x8IconSpriteTemplate;
        spriteTemplate.images = sGymFrontierIconImages;
        for (i = 0; i < NUM_BADGES; i++)
        {
            if (FlagGet(FLAG_BADGE01_GET + i))
            {
                u32 spriteId;
                spriteId = CreateSprite(&spriteTemplate, 23 + (i&3)*9, 138 + i/4 * 9, 0);
                StartSpriteAnimIfDifferent(&gSprites[spriteId], 0);
            }
        }
        for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
        {
            u32 badgeType = 0;
            
            if (FlagGet(FLAG_SYS_TOWER_SILVER + 2 * i))
                badgeType = 1;
            if (FlagGet(FLAG_SYS_TOWER_GOLD + 2 * i))
                badgeType = 2;
            
            if(badgeType)
            {
                u32 spriteId;
                spriteId = CreateSprite(&spriteTemplate, 190 + (i&3)*9 + (i/4)*5, 138 + i/4 * 9, 0);
                StartSpriteAnimIfDifferent(&gSprites[spriteId], badgeType);
            }
        }
        
        CpuCopy16(sGymFrontierIconPalette, buf, 0x20);
        switch (VarGet(VAR_RYU_THEME_NUMBER)) {
            case THEME_COLOR_LIGHT:
            case THEME_COLOR_VANILLA:
                buf[1] = COLOR_LIGHT_THEME_BG_LIGHT;
                break;
            case THEME_COLOR_DARK:
                break;
            case THEME_COLOR_USER:
                buf[1] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];
                break;
        }
        LoadPalette(buf, 0x110, 0x20);
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
        SetVBlankCallback(VBlankCB_Journal);
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
        for(i = 0; i < COUNT_JOURNAL_WINDOWS; i++)
        {
            PutWindowTilemap(i);
            CopyWindowToVram(i, 3);
            //DrawStdWindowFrame(i, TRUE);
        }
        DrawJournalStatText();
        gMain.state++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            gMain.state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}
enum
{
    JOURNAL_ACTION_NONE,
    JOURNAL_ACTION_PAGE_RIGHT,
    JOURNAL_ACTION_PAGE_LEFT,
    JOURNAL_ACTION_RIGHT,
    JOURNAL_ACTION_LEFT,
    JOURNAL_ACTION_CHOOSE,
    JOURNAL_ACTION_EXIT,
};

static u32 InputToJournalAction(void)
{
    u32 finalAction = JOURNAL_ACTION_NONE;
    switch(gMain.newAndRepeatedKeys & (DPAD_LEFT | DPAD_RIGHT | R_BUTTON | L_BUTTON))
    {
        case DPAD_RIGHT:
            return JOURNAL_ACTION_RIGHT;
        case DPAD_LEFT:
            return JOURNAL_ACTION_LEFT;
        case R_BUTTON:
            return JOURNAL_ACTION_PAGE_RIGHT;
        case L_BUTTON:
            return JOURNAL_ACTION_PAGE_LEFT;
    }
    if(gMain.newKeys & A_BUTTON)
        finalAction = JOURNAL_ACTION_CHOOSE;
    else if(gMain.newKeys & B_BUTTON)
        finalAction = JOURNAL_ACTION_EXIT;
    return finalAction;
}

#define tCurrentButton data[0]
#define tCurrentPage data[1]

static void Task_ExitJournalTaskIntoNewUI(u8 taskId)
{
    u32 i;

    if(gPaletteFade.active)
        return;
    if(gTasks[taskId].tCurrentButton != JOURNAL_OPTION_EXIT && sJounralButtons[gTasks[taskId].tCurrentButton].callback2 == NULL)
    {
        return; // how did we end up here
    }   
    
    FreeAllWindowBuffers();
    for(i = 0; i < 4; i++)
    {
        Free(GetBgTilemapBuffer(i));
        UnsetBgTilemapBuffer(i);
    }
    RemoveWindow(WIN_JOURNAL_TRAINER_ID);
    RemoveWindow(WIN_JOURNAL_TRAINER_MONEY);
    RemoveWindow(WIN_JOURNAL_TRAINER_NAME);
    RemoveWindow(WIN_JOURNAL_STATS);
    RemoveWindow(WIN_JOURNAL_GAME_MODE);
    DmaFill32(3, 0, VRAM, VRAM_SIZE);
    DestroyTask(taskId);
    //gTasks[taskId].func = sJounralButtons[gTasks[taskId].tCurrentButton].callback2; //! SHOULD IDEALLY JUST GO TO PROPER CALLBACKS FOR THE UIs BUT I'M LAZY AND I HAD TO WORK ON EXISTING CODE WHICH GOT EDITED ANYWAYS
    if(gTasks[taskId].tCurrentButton == JOURNAL_OPTION_EXIT) 
    {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        //m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    }
    else
        SetMainCallback2(sJounralButtons[gTasks[taskId].tCurrentButton].callback2);
}

static void Task_JournalMain(u8 taskId)
{
    u32 action = InputToJournalAction();
    switch(action)
    {
        case JOURNAL_ACTION_LEFT:
        case JOURNAL_ACTION_RIGHT:
            gSprites[gTasks[taskId].tCurrentButton].data[0] = 0;
            if(action == JOURNAL_ACTION_RIGHT)
                gTasks[taskId].tCurrentButton++;
            else
                gTasks[taskId].tCurrentButton--;
            if(gTasks[taskId].tCurrentButton < 0) // task data is signed
                gTasks[taskId].tCurrentButton = JOURNAL_OPTION_COUNT-1;
            if(gTasks[taskId].tCurrentButton >= JOURNAL_OPTION_COUNT)
                gTasks[taskId].tCurrentButton = 0;
            gSprites[gTasks[taskId].tCurrentButton].data[0] = 1;
            break;
        case JOURNAL_ACTION_PAGE_RIGHT:
        case JOURNAL_ACTION_PAGE_LEFT:
            if(action == JOURNAL_ACTION_PAGE_RIGHT)
                gTasks[taskId].tCurrentPage++;
            else
                gTasks[taskId].tCurrentPage--;

            if(gTasks[taskId].tCurrentPage < 0) // task data is signed
                gTasks[taskId].tCurrentPage = ARRAY_COUNT(sJournalStatPages)-1;
            if(gTasks[taskId].tCurrentPage >= ARRAY_COUNT(sJournalStatPages))
                gTasks[taskId].tCurrentPage = 0;
            FillWindowPixelBuffer(WIN_JOURNAL_STATS, PIXEL_FILL(0));
            FillWindowPixelBuffer(WIN_JOURNAL_PAGE_NAME, PIXEL_FILL(0));
            DrawJournalStatPage(gTasks[taskId].tCurrentPage);
            break;
        case JOURNAL_ACTION_CHOOSE:
            if(sJounralButtons[gTasks[taskId].tCurrentButton].callback2 == NULL)
                return;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_ExitJournalTaskIntoNewUI;
            break;
        case JOURNAL_ACTION_EXIT:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].tCurrentButton = JOURNAL_OPTION_EXIT;
            gTasks[taskId].func = Task_ExitJournalTaskIntoNewUI;
    }
}

static void ButtonSpriteCB(struct Sprite *sprite)
{
    StartSpriteAnimIfDifferent(sprite, !!sprite->data[0]); // TODO: might need to support different frames
}
