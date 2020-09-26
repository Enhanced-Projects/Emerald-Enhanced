#include "global.h"
#include "dexnav.h"
#include "data.h"
#include "pokemon.h"
#include "sprite.h"
#include "battle_setup.h"
#include "event_data.h"
#include "field_effect.h"
#include "window.h"
#include "party_menu.h"
#include "event_scripts.h"
#include "bg.h"
#include "text.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "palette.h"
#include "random.h"
#include "main.h"
#include "graphics.h"
#include "overworld.h"
#include "task.h"
#include "malloc.h"
#include "fieldmap.h"
#include "pokemon_icon.h"
#include "gpu_regs.h"
#include "string_util.h"
#include "field_player_avatar.h"
#include "field_effect_helpers.h"
#include "event_object_movement.h"
#include "script.h"
#include "start_menu.h"
#include "battle_main.h"
#include "wild_encounter.h"
#include "metatile_behavior.h"
#include "field_screen_effect.h"
#include "daycare.h"
#include "menu.h"
#include "m4a.h"
#include "sound.h"
#include "decompress.h"
#include "region_map.h"
#include "constants/map_types.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/field_effects.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/abilities.h"
#include "gba/m4a_internal.h"

// Defines
enum WindowIds
{
    WINDOW_SPECIES,
    WINDOW_SEARCH_LEVEL,
    WINDOW_LEVEL_BONUS,
    WINDOW_HIDDEN_ABILITY,
    WINDOW_REPLY_TEXT,
    WINDOW_WATER,
    WINDOW_LAND,
    WINDOW_MAP_NAME,
    WINDOW_COUNT,
};

enum Statuses
{
    STATUS_INVALID_SEARCH,
    STATUS_CHOOSE_MON,
    STATUS_LOCKED,
    STATUS_NO_DATA,
    STATUS_INCORRECT_AREA,
};

enum PokeToolsMenuItems
{
    POKETOOLS_ACTION_POKEDEX,
    POKETOOLS_ACTION_DEXNAV,
};

#define IS_NEWER_UNOWN_LETTER(species) (species >= SPECIES_UNOWN_B && species <= SPECIES_UNOWN_QMARK)

struct DexnavSearch
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 moveId[MAX_MON_MOVES];
    /*0x0A*/ u16 heldItem;
    /*0x0C*/ u8 ability;
    /*0x0D*/ u8 potential;
    /*0x0E*/ u8 searchLevel;
    /*0x0F*/ u8 monLevel;
    /*0x10*/ u8 moveNameLength;
    /*0x11*/ u8 proximity;
    /*0x12*/ u8 environment;
	/*0x13*/ u8 unownLetter;
    /*0x14*/ s16 tileX; // position of shaking grass
    /*0x16*/ s16 tileY;
    /*0x18*/ u8 spriteIdSpecies;
    /*0x19*/ u8 spriteIdBlackBar[4];
    /*0x1D*/ u8 spriteIdSight;
    /*0x1E*/ u8 spriteIdAbility;
    /*0x1F*/ u8 spriteIdMove;
    /*0x20*/ u8 spriteIdItem;
    /*0x21*/ u8 fldEffSpriteId;
    /*0x22*/ u8 spriteIdPotential[3];
    /*0x25*/ u8 movementTimes;
// GUI data
    /*0x26*/ u16 grassSpecies[NUM_LAND_MONS];
    /*0x3E*/ u16 waterSpecies[NUM_WATER_MONS];
	/*0x48*/ u16 hiddenSpecies[NUM_LAND_MONS + 1];
	/*0x62*/ u8 unownForms[NUM_LAND_MONS];
	/*0x6E*/ u8 unownFormsByDNavIndices[NUM_LAND_MONS];
	/*0x7A*/ u8 numGrassMons;
	/*0x7B*/ u8 numWaterMons;
	/*0x7C*/ u8 numHiddenLandMons;
	/*0x7D*/ u8 numHiddenWaterMons;
    /*0x7E*/ u8 cursorId;
    /*0x7F*/ u8 objids[17];
    /*0x90*/ u8 selectedIndex;
    /*0x91*/ u8 selectedArr;
    /*0x92*/ u8 abilityNum;
    /*0x93*/ u8 filler93;
    /*0x94*/ void* backBuffer;
}; /* size = 0x98 */

// RAM

EWRAM_DATA static u8 sDexNavSearchLevels[NUM_SPECIES] = {0};    // to be moved to saveblock!!!!
EWRAM_DATA static struct DexnavSearch *sDexnavSearchDataPtr = {NULL};  //#define sDexnavSearchDataPtr (*((struct DexnavSearch**) 0x203E038))
EWRAM_DATA u16 gDexnavSpecies = 0;
EWRAM_DATA u8 gDexnavEnvironment = 0;
EWRAM_DATA u8 sDexnavWindowId = 0;
EWRAM_DATA u8 sDexnavSearchSpriteId = 0;

// Function Declarations
static void VblackCallbackSeq(void);
static u8 ExecDexNav(void);
static void DexNavGuiHandler(void);
static void DexNavGuiSetup(void);
static void DexNavPopulateEncounterList(void);
static void DexNavLoadNames(u8 status);
static void DexNavLoadPokeIcons(void);
static void CreateNoDataIcon(s16 x, s16 y);
static void SpawnPointerArrow(void);
static void UpdateCursorPosition(void);
static void DexNavLoadCapturedAllSymbol(void);
static void DexNavGuiExitSearch(void);
static void CallbackDexNavOW(void);
static void ExecDexNavHUD(void);
static void PrintDexNavError(u8 caseId);
static void DexNavGuiExitNoSearch(void);
static void DexNavDrawIcons(void);
static void DexNavLoadAreaNames(void);
// HUD funcs
static void InitDexNavHUD(u16 species, u8 environment);
static void DexNavHudDrawSpeciesIcon(u16 species, u8* spriteIdAddr);
static void DexNavDrawBlackBars(u8* spriteIdAddr);
static void DexNavDrawSight(u8 sightLevel, u8* spriteIdAddr);
static void DexNavDrawAbility(u8 ability, u8* spriteIdAddr);
static void DexNavDrawMove(u16 move, u8 searchLevel, u8* spriteIdAddr);
static void DexNavDrawPotential(u8 potential, u8* spriteIdAddr);
static void DexNavIconsVisionUpdate(u8 proximity, u8 searchLevel);
static bool8 ShakingGrass(u8 environment, u8 xSize, u8 ySize, bool8 smallScan);
static void DexNavFreeHUD(void);

// Mon Generation Functions
static void DexNavGenerateMoveset(u16 species, u8 searchLevel, u8 encounterLevel, u16* moveLoc);
static u16 DexNavGenerateHeldItem(u16 species, u8 searchLevel);
static u8 DexNavGenerateHiddenAbility(u16 species, u8 searchLevel);
static u8 DexNavGeneratePotential(u8 searchLevel);
static void DexNavDrawHeldItem(u8* spriteIdAddr);
static u8 DexNavGenerateMonLevel(u16 species, u8 searchLevel, u8 environment);
static u8 GetEncounterLevel(u16 species, u8 environment);


//static void DestroyTaskCompletedTextbox(u8 tId);
//static void MsgNormal(const u8* str);
static void ClearHandlers(void);
static void DexNavGUICallback2(void);
static void ResetPalSettings(void);
static void ResetBgSettings(void);
static void Setup(void);
static bool8 SpeciesInArray(u16 species, u8 indexCount);
static void DexNavGetMon(u16 species, u8 potential, u8 level, u8 abilityNum, u16* moves);
//static u8 FindHeaderIndexWithLetter(u16 species, u8 letter);
static u8 GetPlayerDistance(s16 x, s16 y);
static u8 PickTileScreen(u8 targetBehaviour, u8 areaX, u8 areaY, s16 *xBuff, s16 *yBuff, u8 smallScan);
static u8 DexNavPickTile(u8 environment, u8 xSize, u8 ySize, bool8 smallScan);

static void DexNavProximityUpdate(void);
static void NullSubHBlank(void);

static void DexNavShowMessage(u8 id);
static void OutlinedFontDraw(u8 spriteId, u8 tileNum, u16 size);
static void DexNavSightUpdate(u8 sight);

static void Task_DexNavSearch(u8 taskId);








// customizabale locations (from cfru)
static bool8 IsCurrentAreaVolcano(void);
static bool8 IsCurrentAreaAutumn(void);
static bool8 IsCurrentAreaWinter(void);
static bool8 IsCurrentAreaDarkCave(void);
static bool8 InTanobyRuins(void);

//// Const Data
extern const struct OamData gObjectEventBaseOam_16x16;
extern const struct SpriteSheet sSpriteSheet_HeldItem;
extern const struct SpritePalette sSpritePalette_HeldItem;

//extern const union AnimCmd *const gFieldEffectObjectImageAnimTable_Ripple[];
//extern const union AnimCmd *const gFieldEffectObjectImageAnimTable_Unknown20[];

// image data
static const u32 sDexnavBarTiles[] = INCBIN_U32("graphics/dexnav/bar.4bpp.lz");
static const u32 sDexnavBarPal[] = INCBIN_U32("graphics/dexnav/bar.gbapal.lz");

static const u32 sDexnavGuiTiles[] = INCBIN_U32("graphics/dexnav/dexnav_gui_tiles.4bpp.lz");
static const u32 sDexnavGuiTilemap[] = INCBIN_U32("graphics/dexnav/dexnav_gui_tilemap.bin");
static const u32 sDexnavGuiPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/dexnav_gui.gbapal.lz");
static const u32 sDexNavGuiVolcanoPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/volcano.gbapal.lz");
static const u32 sDexNavGuiFlowerParadiseAPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/flower_paradise_A.gbapal.lz");
static const u32 sDexNavGuiFlowerParadiseBPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/flower_paradise_B.gbapal.lz");
static const u32 sDexNavGuiFlowerParadiseCPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/flower_paradise_C.gbapal.lz");
static const u32 sDexNavGuiAutumnPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/autumn.gbapal.lz");
static const u32 sDexNavGuiWinterPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/winter.gbapal.lz");
static const u32 sDexNavGuiCavePal[] = INCBIN_U32("graphics/dexnav/gui_palettes/cave.gbapal.lz");
static const u32 sDexNavGuiDarkerCavePal[] = INCBIN_U32("graphics/dexnav/gui_palettes/dark_cave.gbapal.lz");
static const u32 sDexNavGuiIndoorPal[] = INCBIN_U32("graphics/dexnav/gui_palettes/indoor.gbapal.lz");

//static const u16 sDexnavStarsTiles[] = INCBIN_U16("graphics/dexnav/stars.4bpp");
static const u8 sDexnavStarsTiles[] = INCBIN_U8("graphics/dexnav/stars.4bpp");
static const u8 sDexnavStarsPal[] = INCBIN_U8("graphics/dexnav/stars.gbapal");

static const u32 gInterfaceGfx_selectionCursorTiles[] = INCBIN_U32("graphics/dexnav/cursor.4bpp");
static const u16 gInterfaceGfx_selectionCursorPal[] = INCBIN_U16("graphics/dexnav/cursor.gbapal");

static const u32 gInterfaceGfx_emptyTiles[] = INCBIN_U32("graphics/dexnav/empty.4bpp.lz");
static const u16 gInterfaceGfx_emptyPal[] = INCBIN_U16("graphics/dexnav/empty.gbapal");

static const u32 gInterfaceGfx_CapturedAllPokemonTiles[] = INCBIN_U32("graphics/dexnav/captured_all.4bpp.lz");
static const u32 gInterfaceGfx_CapturedAllPokemonPal[] = INCBIN_U32("graphics/dexnav/captured_all.gbapal.lz");

static const u16 gInterfaceGfx_caveSmokeTiles[] = INCBIN_U16("graphics/dexnav/cave_smoke.4bpp");
static const u16 gInterfaceGfx_caveSmokePal[] = INCBIN_U16("graphics/dexnav/cave_smoke.gbapal");

static const u32 gInterfaceGfx_SparklesTiles[] = INCBIN_U32("graphics/dexnav/sparkles.4bpp");
static const u16 gInterfaceGfx_SparklesPal[] = INCBIN_U16("graphics/dexnav/sparkles.gbapal");

static const u32 gInterfaceGfx_LavaBubblesTiles[] = INCBIN_U32("graphics/dexnav/lava_bubbles.4bpp");
static const u16 gInterfaceGfx_LavaBubblesPal[] = INCBIN_U16("graphics/dexnav/lava_bubbles.gbapal");

static const u32 sDexNavNoDataSymbolTiles[] = INCBIN_U32("graphics/dexnav/no_data.4bpp.lz");

static const struct SpritePalette sSpritePalette_Stars =
{
    (const u16 *)sDexnavStarsPal, 0x2710
};

// strings
static const u8 sText_DexNavText[] = _("Pokédex\nDexNav");
static const u8 sText_DexNavWater[] = _("Water");
static const u8 sText_DexNavLand[] = _("Land");
static const u8 sText_PinkFlowers[] = _("Pink Flowers");
static const u8 sText_YellowFlowers[] = _("Yellow Flowers");
static const u8 sText_RedFlowers[] = _("Red Flowers");
static const u8 sText_BlueFlowers[] = _("Blue Flowers");
static const u8 sText_PinkAndPurpleFlowers[] = _("Pink-Purple Flowers");
static const u8 sText_BlueAndYellowFlowers[] = _("Blue-Yellow Flowers");
static const u8 sText_Magma[] = _("Magma");
static const u8 sText_GotAway[] = _("The Pokémon got away!\p");
static const u8 sText_LostSignal[] = _("There is no reaction.\nThe signal was lost!\p");
static const u8 sText_GotAwayShouldSneak[] = _("The Pokémon got away!\nTry moving more slowly.\p");
static const u8 sText_CannotBeFound[] = _("This Pokémon cannot be found here.\p");
static const u8 sText_NotFoundNearby[] = _("It couldn't be found nearby.\nTry looking in a different area!\p");
static const u8 sText_DexNavBack[] = _(" Back  ");
static const u8 sText_DexNav_NoInfo[] = _("--------");
static const u8 sText_DexNav_CaptureToSee[] = _("Capture first!");
static const u8 sText_DexNav_ChooseMon[] = _("Choose a Pokémon.");
static const u8 sText_DexNav_Invalid[] = _("That Pokémon can't be searched yet!");
static const u8 sText_DexNav_NoDataForSlot[] = _("There's no data for that Pokémon…");
static const u8 sText_DexNav_Locked[] = _("Pokémon searchable via R-button!");
static const u8 sText_DexNav_NotFoundHere[] = _("This Pokémon cannot be found here!");

static const struct BgTemplate BgConfigDexNavGUI[] =
{
    {
        .baseTile = 0,
        .priority = 2,
        .paletteMode = 0,
        .screenSize = 0,
        .mapBaseIndex = 29,
        .charBaseIndex = 1,
        .bg = 0,
    },
    {
        .baseTile = 0,
        .priority = 3,
        .paletteMode = 0,
        .screenSize = 0,
        .mapBaseIndex = 28,
        .charBaseIndex = 0,
        .bg = 1,
    },
    {
        .baseTile = 0,
        .priority = 3,
        .paletteMode = 0,
        .screenSize = 0,
        .mapBaseIndex = 30,
        .charBaseIndex = 2,
        .bg = 2,
    },
    {
        .baseTile = 0,
        .priority = 3,
        .paletteMode = 0,
        .screenSize = 1,
        .mapBaseIndex = 31,
        .charBaseIndex = 3,
        .bg = 3,
    }
};

static const struct OamData sCapturedAllPokemonSymbolOAM =
{
    .y = 0,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0, //Highest
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData IconOAM =
{
    .y = 0,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2, // 32x32 square
    .tileNum = 0,
    .priority = 2, //above the rest
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData CursorOAM =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2, //32x32
    .tileNum = 0,
    .priority = 0, // above BG layers
    .paletteNum = 0,
    .affineParam = 0
};

// cursor positions for water
static const u16 CursorPositions2[] =
{
    30 + 24 * 0, 48,
    30 + 24 * 1, 48,
    30 + 24 * 2, 48,
    30 + 24 * 3, 48,
    30 + 24 * 4, 48,
};

// positions for grass
static const u16 CursorPositions1[] =
{
    20 + 24 * 0, 92,
    20 + 24 * 1, 92,
    20 + 24 * 2, 92,
    20 + 24 * 3, 92,
    20 + 24 * 4, 92,
    20 + 24 * 5, 92,
    20 + 24 * 0, 92 + 28,
    20 + 24 * 1, 92 + 28,
    20 + 24 * 2, 92 + 28,
    20 + 24 * 3, 92 + 28,
    20 + 24 * 4, 92 + 28,
    20 + 24 * 5, 92 + 28,
};

// GUI Windows
#define rgb5(r, g, b) (u16)((r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10))
static const u16 DexNavTextPal[] =
{
    rgb5(255, 0, 255), rgb5(248, 248, 248), rgb5(112, 112, 112), rgb5(96, 96, 96),
    rgb5(208, 208, 208), rgb5(76, 154, 38), rgb5(102, 194, 66), rgb5(168, 75, 76),
    rgb5(224, 114, 75), rgb5(180, 124, 41), rgb5(241, 188, 60), rgb5(255, 0, 255),
    rgb5(255, 0, 255), rgb5(255, 0, 255), rgb5(255, 133, 200), rgb5(64, 200, 248)
};

static const struct WindowTemplate sDexNavWindows[] =
{
    [WINDOW_SPECIES] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 6,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WINDOW_SEARCH_LEVEL] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 19,
    },
    [WINDOW_LEVEL_BONUS] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 12,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 64,
    },
    [WINDOW_HIDDEN_ABILITY] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 15,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 91,
    },
    [WINDOW_REPLY_TEXT] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 17,
        .width = 26,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 127,
    },
    [WINDOW_WATER] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 19,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 205,
    },
    [WINDOW_LAND] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 8,
        .width = 19,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 262,
    },
    [WINDOW_MAP_NAME] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 319,
    },
    DUMMY_WIN_TEMPLATE
};

//64x32 oam with second highest priority
static const struct OamData sBlackBarOAM =
{
    .y = ICONY,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(64x32),
    .x = ICONX,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};


//64x32 oam with highest priority
static const struct OamData FontOAM =
{
    .y = ICONY,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(64x32),
    .x = ICONX,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// 8x8 oam with highest priority
static const struct OamData HeldOAM =
{
    .y = ICONY,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = ICONX,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// 32x32 object with priority 1, one less than held item which overlaps it
static const struct OamData PIconOAM =
{
    .y = ICONY,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = ICONX,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const u8 MenuTextBlack[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};
static const u8 DexNav_BlackText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_RED};
static const u8 DexNav_WhiteText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY};
static const u8 DexNav_RedText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
static const u8 DexNav_GreenText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN, TEXT_COLOR_LIGHT_GREEN};

static const struct WindowTemplate Tbox = 
{
    .bg = 0, 
    .tilemapLeft = 2,
    .tilemapTop = 2,
    .width = 10,
    .height = POKETOOLS_COUNT << 1,
    .paletteNum = 15,
    .baseBlock = 0x130
};

static const struct CompressedSpriteSheet sBlackBarTiles = 
{
    .data = sDexnavBarTiles,
    .size = 64 * 32 / 2,
    .tag = 0xFDF1
};

static const struct SpriteTemplate sBlackBarTemplate =
{
    .tileTag = 0xFDF1,
    .paletteTag = 0x2710,
    .oam = &sBlackBarOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteFrameImage sFieldEffectObjectPicTable_LavaBubbles[] =
{
    overworld_frame(gInterfaceGfx_LavaBubblesTiles, 2, 2, 0),
    overworld_frame(gInterfaceGfx_LavaBubblesTiles, 2, 2, 1),
    overworld_frame(gInterfaceGfx_LavaBubblesTiles, 2, 2, 2),
    overworld_frame(gInterfaceGfx_LavaBubblesTiles, 2, 2, 3),
};

/*
static const struct SpriteTemplate sSpriteTemplateLavaBubbles =
{
    .tileTag = 0xFFFF,
    .paletteTag = SMOKE_TAG,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = gFieldEffectObjectImageAnimTable_Ripple,
    .images = sFieldEffectObjectPicTable_LavaBubbles,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpritePalette sLavaBubblesPalTemplate =
{
    .data = gInterfaceGfx_LavaBubblesPal,
    .tag = SMOKE_TAG,
};*/

static const struct CompressedSpriteSheet sCapturedAllPokemonSpriteSheet = 
{
    .data = gInterfaceGfx_CapturedAllPokemonTiles,
    .size = 8 * 8 / 2,
    .tag = CAPTURED_ALL_TAG
};

static const struct SpriteTemplate sCapturedAllPokemonSymbolTemplate =
{
    .tileTag = CAPTURED_ALL_TAG,
    .paletteTag = SELECTION_CURSOR_TAG,
    .oam = &sCapturedAllPokemonSymbolOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sIconTiles = 
{
    .data = sDexNavNoDataSymbolTiles,
    .size = 32 * 32,
    .tag = ICON_GFX_TAG
};


static const struct SpriteFrameImage sCaveGfx[] =
{
    overworld_frame(gInterfaceGfx_caveSmokeTiles, 2, 2, 0),
    overworld_frame(gInterfaceGfx_caveSmokeTiles, 2, 2, 1),
    overworld_frame(gInterfaceGfx_caveSmokeTiles, 2, 2, 2),
    overworld_frame(gInterfaceGfx_caveSmokeTiles, 2, 2, 3),
};

/*
static const struct SpriteTemplate ObjtCave =
{
    .tileTag = 0xFFFF,
    .paletteTag = SMOKE_TAG,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = gFieldEffectObjectImageAnimTable_Unknown20,        //gFieldEffectObjectImageAnimTable_Unknown ????
    .images = sCaveGfx,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = WaitFieldEffectSpriteAnim,
};
*/

static const struct SpritePalette sCaveSmokePalTemplate =
{
    .data = gInterfaceGfx_caveSmokePal,
    .tag = SMOKE_TAG,
};

static const union AnimCmd sFieldEffectObjectImageAnim_Sparkles[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd* const sFieldEffectObjectImageAnimTable_Sparkles[] =
{
    sFieldEffectObjectImageAnim_Sparkles,
};

static const struct SpriteFrameImage sFieldEffectObjectPicTable_Sparkles[] =
{
    overworld_frame(gInterfaceGfx_SparklesTiles, 2, 2, 0),
    overworld_frame(gInterfaceGfx_SparklesTiles, 2, 2, 1),
    overworld_frame(gInterfaceGfx_SparklesTiles, 2, 2, 2),
    overworld_frame(gInterfaceGfx_SparklesTiles, 2, 2, 3),
    overworld_frame(gInterfaceGfx_SparklesTiles, 2, 2, 4),
    overworld_frame(gInterfaceGfx_SparklesTiles, 2, 2, 5),
};

static const struct SpriteTemplate sSpriteTemplateSparkles =
{
    .tileTag = 0xFFFF,
    .paletteTag = SMOKE_TAG,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sFieldEffectObjectImageAnimTable_Sparkles,
    .images = sFieldEffectObjectPicTable_Sparkles,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpritePalette sSparklesPalTemplate =
{
    .data = gInterfaceGfx_SparklesPal,
    .tag = SMOKE_TAG,
};

/*
// create empty object of size 64x32 to draw icons on
static const struct CompressedSpriteSheet sightTiles = 
{
    .data = gInterfaceGfx_emptyTiles,
    .size = 0x800,
    .tag = 0x5424
};

static const struct SpriteTemplate fontTempSight =
{
    .tileTag = 0x5424,
    .paletteTag = 0x2710,
    .oam = &FontOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// create empty object of size 64x32 to draw font on
static const struct CompressedSpriteSheet FontSpriteAbility = 
{
    .data = gInterfaceGfx_emptyTiles,
    .size = 0x800,
    .tag = 0x1EE7
};

static const struct SpriteTemplate FontTempAbility =
{
    .tileTag = 0x1EE7,
    .paletteTag = 0x2710,
    .oam = &FontOAM,
    .anims = gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// create empty object of size 64x32 to draw font on
static const struct CompressedSpriteSheet FontSpriteMove = 
{
    .data = gInterfaceGfx_emptyTiles,
    .size = 0x800,
    .tag = 0x4736
};

static const struct SpriteTemplate FontTempMove =
{
    .tileTag = 0x4736,
    .paletteTag = 0x2710,
    .oam = &FontOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

//19 tiles per row, stars are on the 4th row. 1 tile is 32 bytes. Hence 19 * 4 *32
static const struct SpriteSheet StarIconLit = 
{
    .data = (const u8 *)&sDexnavStarsTiles[19 * 4 * 32],
    .size = 64,
    .tag = 0x61
};

static const struct SpriteSheet StarIconOff = 
{
    .data = (const u8 *)&sDexnavStarsTiles[((19 * 4) + 1) * 32],
    .size = 32 * 2 * (19 * 4),
    .tag = 0x2613
};

static const struct SpriteTemplate StarLitTemp =
{
    .tileTag = 0x61,
    .paletteTag = 0x2710,
    .oam = &HeldOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate StarOffTemp =
{
    .tileTag = 0x2613,
    .paletteTag = 0x2710,
    .oam = &HeldOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate HeldTemp =
{
    .tileTag = 0x2710,
    .paletteTag = 0x2710,
    .oam = &HeldOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet CursorGFX = {(void*) gInterfaceGfx_selectionCursorTiles, 32 * 32, SELECTION_CURSOR_TAG};
static const struct SpritePalette CursorPal = {(void*) gInterfaceGfx_selectionCursorPal, SELECTION_CURSOR_TAG};

static const struct SpriteTemplate CursorTemp =
{
    .tileTag = SELECTION_CURSOR_TAG,
    .paletteTag = SELECTION_CURSOR_TAG,
    .oam = &CursorOAM,
    .anims =  gDummySpriteAnimTable,
    .images = (const struct SpriteFrameImage *) &CursorGFX,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sIconTemplate =
{
    .tileTag = ICON_GFX_TAG,
    .paletteTag = ICON_PAL_TAG,
    .oam = &IconOAM,
    .anims =  gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

//// Functions

u8 PickUnownLetter(u16 species, u8 headerIndex)
{
    return 0;
}

u32 MathMin(u32 num1, u32 num2)
{
    if (num1 < num2)
        return num1;

    return num2;
}

u16 RandRange(u16 min, u16 max)
{
    if (min == max)
        return min;
    return (Random() % (max - min)) + min;
}

static void VblackCallbackSeq(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ResetGPU(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BG3CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0VOFS, DISPCNT_MODE_0);
}

static void ClearHandlers(void)
{
    SetVBlankCallback(NULL);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetGPU();
}

static void DexNavGUICallback2(void)
{
    BuildOamBuffer();
    AnimateSprites();
    UpdatePaletteFade();
    RunTasks();
    do_scheduled_bg_tilemap_copies_to_vram();
    // merge textbox and text tile maps
    RunTextPrinters();
}

static void ResetPalSettings(void)
{
    ResetPaletteFade();
    FillPalBufferBlack();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 0;
}

static void ResetBgSettings(void)
{
    CleanupOverworldWindowsAndTilemaps();
    ResetBgsAndClearDma3BusyFlags(0);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

static void Setup(void)
{
    u32 set;
    
    ClearHandlers();    // callbacks
    ResetBgSettings();    // BGs
    ResetPalSettings();    // pals
    ResetSpriteData();    // objs
    FreeSpriteTileRanges();
    set = 0;
    CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET));     // VRAM clear
    InitHeap((void*) 0x2000000, 0x1C000);
    ResetTasks();
}


// ===================================== //
// ===== Dex Nav Pokemon Generator ===== //
// ===================================== //
void DexNavGetMon(u16 species, u8 potential, u8 level, u8 abilityNum, u16* moves)
{
    struct Pokemon* mon = &gEnemyParty[0];
    u8 iv[3];
    u8 i;
    
    //Create standard wild
    //CreateWildMon(species, level, FindHeaderIndexWithLetter(species, sDexnavSearchDataPtr->unownLetter - 1), TRUE);
    CreateWildMon(species, level);

    //Pick potential ivs to set to 31
    iv[0] = Random() % 6;
    iv[1] = Random() % 6;
    iv[2] = Random() % 6;
    if ((iv[0] != iv[1]) && (iv[0] != iv[2]) && (iv[1] != iv[2]))
    {
        u8 perfectIv = 0x1F;
        if (potential > 2)
            SetMonData(mon, MON_DATA_HP_IV + iv[2], &perfectIv);
        else if (potential > 1)
            SetMonData(mon, MON_DATA_HP_IV + iv[1], &perfectIv);
        else if (potential)
            SetMonData(mon, MON_DATA_HP_IV + iv[0], &perfectIv);
    }

    //Set ability
    SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);

    //Set moves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gSpecialVar_0x8006 = sDexnavSearchDataPtr->moveId[i];
        SetMonData(mon, MON_DATA_MOVE1 + i, &gSpecialVar_0x8006);
        SetMonData(mon, MON_DATA_PP1 + i, &gBattleMoves[moves[i]].pp);
    }

    CalculateMonStats(mon);
}



//Causes the game to lag due to interference from DNS :(
#define WIN_BG0 (1 << 0)
#define WIN_BG1 (1 << 1)
#define WIN_BG2 (1 << 2)
#define WIN_BG3 (1 << 3)
#define WIN_OBJ (1 << 4)
#define WIN_BLD (1 << 5)
static void DexHUDHBlank(void)
{
    if (REG_VCOUNT > (160 - 19)) //Fill 19 pixels
    {
        REG_BLDY = 0xC;
        REG_WININ = WIN_RANGE2(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ | WIN_BLD,  WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ | WIN_BLD);
        REG_BLDCNT = (BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_DARKEN);
    }
    else //Default values from overworld
    {
        REG_WININ = WIN_RANGE2(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
        REG_BLDCNT = BLDALPHA_BLEND(BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ, 0);
    }
}

static void OutlinedFontDraw(u8 spriteId, u8 tileNum, u16 size)
{
    u8 tile = gSprites[spriteId].oam.tileNum + tileNum;
    u8* toWrite = (u8*)((tile * TILE_SIZE_4BPP) + OBJ_VRAM0);
    u8* originalDst;
    u8* dst;
    u8* prevLetter;
    u8* strPtr = gStringVar4;
    u8 counter = 1;
    u16 index = 320;
    u16 prevIndex;
    u8 element = *strPtr;
    
    originalDst = dst = AllocZeroed(size + TILE_SIZE_4BPP);
    while (element != 0xFF)
    {
        prevIndex = index;
        if ((element <= 0xEE) && (element >= 0xD5))
        {
            // lower case letters
            index = (((element - 0xD5) * TILE_SIZE_4BPP) + 1600);
        }
        else if ((element <= 0xD4) && (element >= 0xBB))
        {
            // upper case letters
            index = (((element - 0xBB) * TILE_SIZE_4BPP) + 768);
        }
        else if ((element <= 0xAA) && (element >= 0xA1))
        {
            // numbers
            index = (element - 0xA1) * TILE_SIZE_4BPP;
        }
        else
        {
            // misc pchars
            u8 symbolId = 0;
            switch (element)
            {
                case 0xF0: // colon
                case 0x0: // space bar
                    symbolId = 1;
                    break;
                case 0x36: // semi colon used indication of str end
                    symbolId = 2;
                    break;
                case 0xAC: // question mark
                    symbolId = 3;
                    break;
                case 0xAE: // dash
                    symbolId = 4;
                    break;
                case 0xAD: // period
                    symbolId = 5;
                    break;
                case 0xBA: // slash
                    symbolId = 6;
                    break;
                case 0xB1: // open double quote
                    symbolId = 7;
                    break;
                case 0xB2: // close double quote
                    symbolId = 8;
                    break;
                case 0xB3: // open single quote
                    symbolId = 9;
                    break;
                case 0xB4: // close single quote
                    symbolId = 10;
                    break;
                case 0xB0: // elipsis ...
                    symbolId = 11;
                    break;
                case 0xB8: // comma
                    symbolId = 12;
                    break;
                case 0xB5: // male
                    symbolId = 13;
                    //dst =
                    break;
                case 0xB6: // f
                    symbolId = 14;
                    break;
                case 0xFF: // empty
                    symbolId = 1;
                    break;
            };
            index = (symbolId + 9) * TILE_SIZE_4BPP;
        }

        // TODO: Use macros here //

        if ((counter == 0) || (*(strPtr + 1) == 0xFF))
        {
            // first or last pcharacters don't need pixel merging
            memcpy(dst, &sDexnavStarsTiles[index], TILE_SIZE_4BPP);
        }
        else if ((element == 0x0))
        {
            memcpy(dst, &sDexnavStarsTiles[index], TILE_SIZE_4BPP);
            prevLetter = (u8*)(&sDexnavStarsTiles[prevIndex]);
            *(dst + 0) = *(prevLetter + 2);
            *(dst + 4) = *(prevLetter + 6);
            *(dst + 8) = *(prevLetter + 10);
            *(dst + 12) = *(prevLetter + 14);
            *(dst + 16) = *(prevLetter + 18);
            *(dst + 20) = *(prevLetter + 22);
            *(dst + 24) = *(prevLetter + 26);
            *(dst + 28) = *(prevLetter + 30);
        }
        else if ((*(strPtr + 1) != 0xFF))
        {
            // pcharacter in middle, if blank space fill blank with previous pcharacter's last pixel row IFF previous pchar's last pixel row non-empty
            memcpy((void*)dst, &sDexnavStarsTiles[index], TILE_SIZE_4BPP);
            prevLetter = (u8*)(&sDexnavStarsTiles[prevIndex]);
            *(dst) |= (((*(prevLetter + 0) & 0xF) == 0) ? (*(dst + 0) & 0xF) : (*(prevLetter + 0) & 0xF));
            *(dst + 4) |= (((*(prevLetter + 4) & 0xF) == 0) ? (*(dst + 4) & 0xF) : (*(prevLetter + 4) & 0xF));
            *(dst + 8) |= (((*(prevLetter + 8) & 0xF) == 0) ? (*(dst + 8) & 0xF) : (*(prevLetter + 8) & 0xF));
            *(dst + 12) |= (((*(prevLetter + 12) & 0xF) == 0) ? (*(dst + 12) & 0xF) : (*(prevLetter + 12) & 0xF));
            *(dst + 16) |= (((*(prevLetter + 16) & 0xF) == 0) ? (*(dst + 16) & 0xF) : (*(prevLetter + 16) & 0xF));
            *(dst + 20) |= (((*(prevLetter + 20) & 0xF) == 0) ? (*(dst + 20) & 0xF) : (*(prevLetter + 20) & 0xF));
            *(dst + 24) |= (((*(prevLetter + 24) & 0xF) == 0) ? (*(dst + 24) & 0xF) : (*(prevLetter + 24) & 0xF));
            *(dst + 28) |= (((*(prevLetter + 28) & 0xF) == 0) ? (*(dst + 28) & 0xF) : (*(prevLetter + 28) & 0xF));
        }

        if ((counter == 2) && (*(strPtr + 1) != 0xFF))
        {
            // every two pchars, we need to merge
            // 8x8px made of 4x8px from previous pchar and 4x8px of this pchar
            *(dst - 30) = (((*(dst - 30) & 0x0F) == 0) ? (*(dst) & 0xF) :(*(dst - 30) & 0x0F)) | (*(dst) & 0xF0);
            *(dst - 26) = (((*(dst - 26) & 0x0F) == 0) ? (*(dst + 4) & 0xF): (*(dst - 26) & 0x0F))  | (*(dst + 4) & 0xF0);
            *(dst - 22) = (((*(dst - 22) & 0x0F) == 0) ? (*(dst + 8) & 0xF): (*(dst - 22) & 0x0F)) | (*(dst + 8) & 0xF0);
            *(dst - 18) = (((*(dst - 18) & 0x0F) == 0) ? (*(dst + 12) & 0xF): (*(dst - 18) & 0x0F)) | (*(dst + 12) & 0xF0);
            *(dst - 14) = (((*(dst - 14) & 0x0F) == 0) ? (*(dst + 16) & 0xF): (*(dst - 14) & 0x0F)) | (*(dst + 16) & 0xF0);
            *(dst - 10) = (((*(dst - 10) & 0x0F) == 0) ? (*(dst + 20) & 0xF): (*(dst - 10) & 0x0F)) | (*(dst + 20) & 0xF0);
            *(dst - 6) = (((*(dst - 6) & 0x0F) == 0) ? (*(dst + 24) & 0xF): (*(dst - 6) & 0x0F)) | (*(dst + 24) & 0xF0);
            *(dst - 2) = (((*(dst - 2) & 0x0F) == 0) ? (*(dst + 28) & 0xF): (*(dst - 2) & 0x0F)) | (*(dst + 28) & 0xF0);

            // last two pixels unconditional
            *(dst - 29) |= *(dst + 1);
            *(dst - 25) |= *(dst + 5);
            *(dst - 21) |= *(dst + 9);
            *(dst - 17) |= *(dst + 13);
            *(dst - 13) |= *(dst + 17);
            *(dst - 9) |= *(dst + 21);
            *(dst - 5) |= *(dst + 25);
            *(dst - 1) |= *(dst + 29);

            dst -= TILE_SIZE_4BPP;
            counter = 0;
        }
        
        counter++;
        dst += TILE_SIZE_4BPP; // next tile
        strPtr++;
        element = *strPtr;
    }

    memcpy((void*) toWrite, originalDst, size);
    Free(originalDst);
}


#define MAP_IS(map) (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(map) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(map))
static void DexNavLoadAreaNames(void)
{
    

    AddTextPrinterParameterized3(WINDOW_WATER, 1, 4, 6, DexNav_WhiteText, 0, sText_DexNavWater);
    AddTextPrinterParameterized3(WINDOW_LAND, 1, 5, 6, DexNav_WhiteText, 0, sText_DexNavLand);
}

// =================================== //
// ===== Overworld Field Effects ===== //
// =================================== //
*/
void FieldEff_CaveDust(void)
{
    u8 spriteId;
    
    LoadSpritePalette(&sCaveSmokePalTemplate);
    LoadPalette(gInterfaceGfx_caveSmokePal, 29 * 16, 32);
    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    //spriteId = CreateSpriteAtEnd(&ObjtCave, gFieldEffectArguments[0], gFieldEffectArguments[1], 0xFF);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = 1;
        gSprites[spriteId].data[0] = 22;
    }
}

void FieldEff_Sparkles(void)
{
    u8 spriteId;
    
    LoadSpritePalette(&sSparklesPalTemplate);
    LoadPalette(gInterfaceGfx_SparklesPal, 29 * 16, 32);
    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(&sSpriteTemplateSparkles, gFieldEffectArguments[0], gFieldEffectArguments[1], 0xFF);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = 1;
        gSprites[spriteId].data[0] = 22;
    }
}

/*
// ========================================== //
// ======== Check Select in Overworld ======= //
// ========================================== //



// ============================== //
// ========= FUNCTIONS ========== //
// ============================== //
// customizable locations / gui palettes
static bool8 IsCurrentAreaVolcano(void)
{
    return FALSE;
}

static bool8 IsCurrentAreaAutumn(void)
{
    return FALSE;
}

static bool8 IsCurrentAreaWinter(void)
{
        return FALSE;
}

static bool8 IsCurrentAreaDarkCave(void)
{
    return FALSE;
}

static bool8 InTanobyRuins(void)
{
    return FALSE;
}

#define priv0 gTasks[taskId].data[0]
void ToolSelection(u8 taskId)
{
    switch (priv0)
    {
        case 0:
            if (!ScriptContext2_IsEnabled())
                priv0++;
            break;
        case 1:
        {
            u8 boxId = AddWindow(&Tbox);
            ScriptContext2_Enable();
            FillWindowPixelBuffer(boxId, 0x11);
            DrawStdFrameWithCustomTileAndPalette(boxId, 1, 0x214, 0xE);
            AddTextPrinterParameterized3(boxId, 1, 8, 2, MenuTextBlack, 0, sText_DexNavText);
            Menu_InitCursor(boxId, 2, 0, 1, 16, POKETOOLS_COUNT, 0);
            CopyWindowToVram(boxId, 3);
            PutWindowTilemap(boxId);
            gTasks[taskId].data[1] = boxId;
            priv0++;
            break;
        }
        case 2:
        {
            s8 choice = Menu_ProcessInputNoWrapAround_other();
            if (choice == POKETOOLS_ACTION_POKEDEX)
            {
                //pokedex
                StartMenuPokedexCallback();
                DestroyTask(taskId);
            }
            else if (choice == POKETOOLS_ACTION_DEXNAV)
            {
                // dexnav
                ExecDexNav();
                DestroyTask(taskId);
            }
            else if (choice == -1)
            {
                // b pressed, exit
                ClearStdWindowAndFrameToTransparent(gTasks[taskId].data[1], 1);
                RemoveWindow(gTasks[taskId].data[1]);
                ScriptContext2_Disable();
                DestroyTask(taskId);
            }
            break;
        }
    }
}

static u8 ExecDexNav(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0x0000);
    SetMainCallback1(DexNavGuiHandler);
    gMain.state = 0;
    return TRUE;
}

#define LAND_ROW_LENGTH (6 * 2)
#define LAND_FIRST_ROW_LAST_INDEX (5 * 2)
#define LAND_SECOND_ROW_LAST_INDEX (LAND_FIRST_ROW_LAST_INDEX + LAND_ROW_LENGTH)
#define LAND_SECOND_ROW_FIRST_INDEX (6 * 2)
#define WATER_ROW_LAST_INDEX (4 * 2)
#define ROW_MON_LENGTH 2
static void DexNavGuiHandler(void)
{
    u16 species;
    void* DexNav_gbackBuffer = malloc(0x800);
    
    switch(gMain.state)
    {
        case 0:
            if (!gPaletteFade.active)
            {
                DexNavGuiSetup();
                SetMainCallback1(DexNavGuiHandler);
                // allocate dexnav struct
                sDexnavSearchDataPtr = AllocZeroed(sizeof(struct DexnavSearch));
                gMain.state++;
            }
            break;
        case 1:
            //Load BG assets
            sDexnavSearchDataPtr->backBuffer = &DexNav_gbackBuffer;
            LoadPalette(&DexNavTextPal, 15 * 16, 32);
            
            if (IsMapTypeIndoors(GetCurrentMapType()))
                LoadCompressedPalette(sDexNavGuiIndoorPal, 0, 32);
            else if (IsCurrentAreaDarkCave())
                LoadCompressedPalette(sDexNavGuiDarkerCavePal, 0, 32);
            else if (GetCurrentMapType() == MAP_TYPE_UNDERGROUND)
                LoadCompressedPalette(sDexNavGuiCavePal, 0, 32);
            else if (IsCurrentAreaAutumn())
                LoadCompressedPalette(sDexNavGuiAutumnPal, 0, 32);
            else if (IsCurrentAreaWinter())
                LoadCompressedPalette(sDexNavGuiWinterPal, 0, 32);
            else
                LoadCompressedPalette(sDexnavGuiPal, 0, 32);
			
			LZ77UnCompWram(sDexnavGuiTilemap, DexNav_gbackBuffer);
            LZ77UnCompVram(sDexnavGuiTiles, (void *)VRAM);
            			
			SetBgTilemapBuffer(1, DexNav_gbackBuffer);
            ScheduleBgCopyTilemapToVram(1);
            ScheduleBgCopyTilemapToVram(0);
            gMain.state++;
            break;
        case 2:
            InitWindows(sDexNavWindows);
            DexNavPopulateEncounterList();
            DexNavLoadNames(1);
            gMain.state++;
            break;
        case 3:
           // REG_DISPCNT = 0x7F60;
            //REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 |
             //               WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
            //WRITE_REG_BLDCNT(0x401E);
            //REG_BLDCNT = BLDALPHA_BUILD(BLDCNT_BG1_SRC | BLDCNT_BG2_SRC | BLDCNT_BG3_SRC | BLDCNT_SPRITES_SRC, 0);

            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0x0000);
            ShowBg(0);
            ShowBg(1);
            DexNavLoadPokeIcons();
            SpawnPointerArrow();
            DexNavLoadCapturedAllSymbol();
            sDexnavSearchDataPtr->selectedArr = ROW_LAND;
            sDexnavSearchDataPtr->selectedIndex = 0;
            gMain.state++;
            break;
        case 4:
            if (!gPaletteFade.active)
            {
                switch (gMain.newAndRepeatedKeys & (A_BUTTON | B_BUTTON | DPAD_DOWN | DPAD_UP | DPAD_LEFT | DPAD_RIGHT | R_BUTTON))
                {
                    case A_BUTTON:
                        // check selection is valid. Play sound if invalid
                        species = sDexnavSearchDataPtr->selectedArr == ROW_WATER ? sDexnavSearchDataPtr->waterSpecies[sDexnavSearchDataPtr->selectedIndex / 2] : sDexnavSearchDataPtr->grassSpecies[sDexnavSearchDataPtr->selectedIndex / 2];
                        // if species is MISSINGNO then error
                        if (species != SPECIES_NONE)
                        {
                            
                            
                            
                            //Species was valid, save and enter OW HUD mode
                            gDexnavSpecies = species;
                            gDexnavEnvironment = sDexnavSearchDataPtr->selectedArr;   //selected environment
                            sDexnavSearchDataPtr->environment = sDexnavSearchDataPtr->selectedArr;
                            gMain.state = 0;
                            SetMainCallback1(DexNavGuiExitSearch);
                            return;
                        }
                        else
                        {
                            PrintDexNavError(STATUS_INVALID_SEARCH);
                        }
                        break;
                    case B_BUTTON:
                        // exit to start menu
                        SetMainCallback1(DexNavGuiExitNoSearch);
                        gMain.state = 0;
                        return;
                    case DPAD_DOWN:
                        if (sDexnavSearchDataPtr->selectedArr == ROW_LAND)
                        {
                            if (sDexnavSearchDataPtr->selectedIndex >= LAND_SECOND_ROW_FIRST_INDEX)
                            {
                                sDexnavSearchDataPtr->selectedIndex = MathMin(sDexnavSearchDataPtr->selectedIndex - LAND_ROW_LENGTH, WATER_ROW_LAST_INDEX);
                                sDexnavSearchDataPtr->selectedArr = ROW_WATER;
                            }
                            else
                            {
                                sDexnavSearchDataPtr->selectedIndex += LAND_ROW_LENGTH; //Move to second row of land
                            }
                        }
                        else //ROW_WATER
                        {
                            sDexnavSearchDataPtr->selectedArr = ROW_LAND; //Keep index the same
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_DEX_SCROLL);
                        break;

                    case DPAD_UP:
                        if (sDexnavSearchDataPtr->selectedArr == ROW_LAND)
                        {
                            if (sDexnavSearchDataPtr->selectedIndex >= LAND_SECOND_ROW_FIRST_INDEX)
                            {
                                sDexnavSearchDataPtr->selectedIndex -= LAND_ROW_LENGTH; //Move to first row of land
                            }
                            else
                            {
                                sDexnavSearchDataPtr->selectedIndex = MathMin(sDexnavSearchDataPtr->selectedIndex, WATER_ROW_LAST_INDEX);
                                sDexnavSearchDataPtr->selectedArr = ROW_WATER;
                            }
                        }
                        else //ROW_WATER
                        {
                            sDexnavSearchDataPtr->selectedArr = ROW_LAND;
                            sDexnavSearchDataPtr->selectedIndex += LAND_ROW_LENGTH; //So be on the second row
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_DEX_SCROLL);
                        break;

                    case DPAD_LEFT:
                        // wrap cursor around
                        if (sDexnavSearchDataPtr->selectedArr == ROW_WATER)
                            sDexnavSearchDataPtr->selectedIndex = (sDexnavSearchDataPtr->selectedIndex == 0) ? WATER_ROW_LAST_INDEX : sDexnavSearchDataPtr->selectedIndex - ROW_MON_LENGTH;
                        else //ROW_LAND
                        {
                            if (sDexnavSearchDataPtr->selectedIndex == 0 || sDexnavSearchDataPtr->selectedIndex == LAND_SECOND_ROW_FIRST_INDEX)
                                sDexnavSearchDataPtr->selectedIndex += LAND_FIRST_ROW_LAST_INDEX; //Wrap around
                            else
                                sDexnavSearchDataPtr->selectedIndex -= ROW_MON_LENGTH;
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_DEX_SCROLL);
                        break;
                    case DPAD_RIGHT:
                        if (sDexnavSearchDataPtr->selectedArr == ROW_WATER)
                            sDexnavSearchDataPtr->selectedIndex = (sDexnavSearchDataPtr->selectedIndex == WATER_ROW_LAST_INDEX) ? 0 : sDexnavSearchDataPtr->selectedIndex + ROW_MON_LENGTH;
                        else //ROW_LAND
                        {
                            if (sDexnavSearchDataPtr->selectedIndex == LAND_FIRST_ROW_LAST_INDEX || sDexnavSearchDataPtr->selectedIndex == LAND_SECOND_ROW_LAST_INDEX)
                                sDexnavSearchDataPtr->selectedIndex -= LAND_FIRST_ROW_LAST_INDEX; //Wrap around
                            else
                                sDexnavSearchDataPtr->selectedIndex += ROW_MON_LENGTH;
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_DEX_SCROLL);
                        break;
                    case R_BUTTON:
                    {
                        // check selection is valid. Play sound if invalid
                        u16 species = sDexnavSearchDataPtr->selectedArr ? sDexnavSearchDataPtr->waterSpecies[sDexnavSearchDataPtr->selectedIndex / 2] : sDexnavSearchDataPtr->grassSpecies[sDexnavSearchDataPtr->selectedIndex / 2];
                        // if species is MISSINGNO then error
                        if (species != SPECIES_NONE)
                        {
                            if (species == SPECIES_UNOWN)
                            {
                                u8 letter = sDexnavSearchDataPtr->unownFormsByDNavIndices[sDexnavSearchDataPtr->selectedIndex / 2] - 1;
                                if (letter > 0)
                                    species = SPECIES_UNOWN_B + letter - 1;
                            }

                            // species was valid
                            DexNavLoadNames(2);
                            PlaySE(SE_DEX_SEARCH);
                            // create value to store in a var
                            VarSet(VAR_DEXNAV, (sDexnavSearchDataPtr->selectedArr << 15) | species);
                        }
                        else
                        {
                            // beep and update
                            DexNavLoadNames(0);
                            PlaySE(SE_FAILURE);
                        }
                        break;
                    }
                    default:
                        return;
                }
                UpdateCursorPosition();
            }
            break;
    }
}

static void DexNavGuiSetup(void)
{
    u32 set;
    
    Setup();
    FreeAllWindowBuffers();
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, (struct BgTemplate *)&BgConfigDexNavGUI, 4);
    set = 0;
    CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET));
    HideBg(1);
    HideBg(0);
    SetMainCallback2(DexNavGUICallback2);
    SetVBlankCallback(VblackCallbackSeq);
}

static bool8 SpeciesInArray(u16 species, u8 indexCount)
{
	u16 dexNum = SpeciesToNationalPokedexNum(species);
    u8 i;

	//Disallow species not seen
	if (!GetSetPokedexFlag(dexNum, FLAG_GET_SEEN))
	{
		for (i = 0; i < NUM_LAND_MONS; ++i)
		{
			if (sDexnavSearchDataPtr->hiddenSpecies[i] == SPECIES_TABLES_TERMIN)
			{
				sDexnavSearchDataPtr->hiddenSpecies[i] = dexNum;
				sDexnavSearchDataPtr->hiddenSpecies[i + 1] = SPECIES_TABLES_TERMIN;
				break;
			}
			else if (sDexnavSearchDataPtr->hiddenSpecies[i] == dexNum) //Already in array
				return TRUE;
		}

		if (indexCount == NUM_LAND_MONS)
			sDexnavSearchDataPtr->numHiddenLandMons++; //Increase how many question marks to print
		else
			sDexnavSearchDataPtr->numHiddenWaterMons++;

		return TRUE;
	}

	for (i = 0; i < indexCount; ++i)
	{
		if (indexCount == NUM_LAND_MONS)
		{
			if (SpeciesToNationalPokedexNum(sDexnavSearchDataPtr->grassSpecies[i]) == dexNum)
				return TRUE;
		}
		else
		{
			if (SpeciesToNationalPokedexNum(sDexnavSearchDataPtr->waterSpecies[i]) == dexNum)
				return TRUE;
		}
	}

	return FALSE;
}

static void DexNavPopulateEncounterList(void)
{
    // populate unique wild grass encounters
    u8 grassIndex = 0;
    u8 waterIndex = 0;
    u16 species, letter;
    u16 i;
    u16 headerId = GetCurrentMapWildMonHeaderId();
    u16 unowns[NUM_LAND_MONS + 1];
    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    
    // nop struct data
    memset(sDexnavSearchDataPtr->grassSpecies, 0, sizeof(sDexnavSearchDataPtr->grassSpecies));
    memset(sDexnavSearchDataPtr->waterSpecies, 0, sizeof(sDexnavSearchDataPtr->waterSpecies));
    memset(sDexnavSearchDataPtr->hiddenSpecies, 0, sizeof(sDexnavSearchDataPtr->hiddenSpecies));
    memset(sDexnavSearchDataPtr->unownForms, 0, sizeof(sDexnavSearchDataPtr->unownForms));
    memset(sDexnavSearchDataPtr->unownFormsByDNavIndices, 0, sizeof(sDexnavSearchDataPtr->unownFormsByDNavIndices));

    sDexnavSearchDataPtr->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;

    if (landMonsInfo != NULL)
    {
        for (i = 0; i < NUM_LAND_MONS; i++)
        {
            species = landMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, NUM_LAND_MONS))
            {
            //if (species != SPECIES_NONE)
                //sDexnavSearchDataPtr->grassSpecies[grassIndex] = landMonsInfo->wildPokemon[i].species;
                //grassIndex++;
                sDexnavSearchDataPtr->grassSpecies[grassIndex++] = landMonsInfo->wildPokemon[i].species;
            }
        }
    }

    sDexnavSearchDataPtr->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;

    if (waterMonsInfo != NULL)
    {
        for (i = 0; i < NUM_WATER_MONS; i++)
        {
            species = waterMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, NUM_WATER_MONS))
            {
            //if (species != SPECIES_NONE)
                sDexnavSearchDataPtr->waterSpecies[waterIndex] = waterMonsInfo->wildPokemon[i].species;
                waterIndex++;
            }
        }
    }

    sDexnavSearchDataPtr->numGrassMons = grassIndex;
    sDexnavSearchDataPtr->numWaterMons = waterIndex;
}

static void DexNavLoadNames(u8 status)
{
    u8 searchLevelBonus;
    u8 i;
    u16 species;
    u16 dexNum;
    
    // clean boxes
    for (i = 0; i < WINDOW_COUNT; i++)
        FillWindowPixelBuffer(i, 0);

    //Print species name
    species = sDexnavSearchDataPtr->selectedArr == ROW_WATER ? sDexnavSearchDataPtr->waterSpecies[sDexnavSearchDataPtr->selectedIndex >> 1] : sDexnavSearchDataPtr->grassSpecies[sDexnavSearchDataPtr->selectedIndex >> 1];
    dexNum = SpeciesToNationalPokedexNum(species);

    if (species)
        AddTextPrinterParameterized3(WINDOW_SPECIES, 0, 0, 4, DexNav_BlackText, 0, gSpeciesNames[species]);
    else
        AddTextPrinterParameterized3(WINDOW_SPECIES, 0, 0, 4, DexNav_BlackText, 0, sText_DexNav_NoInfo);

    //Print search level
    ConvertIntToDecimalStringN(gStringVar4, sDexNavSearchLevels[dexNum], 0, 4);

    if (species == SPECIES_NONE)
        AddTextPrinterParameterized3(WINDOW_SEARCH_LEVEL, 0, 0, 4, DexNav_BlackText, 0, sText_DexNav_NoInfo);
    else
        AddTextPrinterParameterized3(WINDOW_SEARCH_LEVEL, 0, 0, 4, DexNav_BlackText, 0, gStringVar4);

    //Print level bonus
    searchLevelBonus = 0;
    if ((sDexNavSearchLevels[dexNum] >> 2) > 20)
        searchLevelBonus = 20;
    else
        searchLevelBonus = (sDexNavSearchLevels[dexNum] >> 2);

    ConvertIntToDecimalStringN(gStringVar4, searchLevelBonus, 0, 4);

    if (species == SPECIES_NONE)
        AddTextPrinterParameterized3(WINDOW_LEVEL_BONUS, 0, 0, 4, DexNav_BlackText, 0, sText_DexNav_NoInfo);
    else
        AddTextPrinterParameterized3(WINDOW_LEVEL_BONUS, 0, 0, 4, DexNav_BlackText, 0, gStringVar4);

    //Print hidden ability name
    if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT) || species == SPECIES_NONE)
    {
        if (gBaseStats[species].abilityHidden != ABILITY_NONE) //Only display hidden ability is Pokemon has been caught
            AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, DexNav_BlackText, 0, gAbilityNames[gBaseStats[species].abilityHidden]);
        else
            AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, DexNav_BlackText, 0, sText_DexNav_NoInfo);
    }
    else
        AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, DexNav_BlackText, 0, sText_DexNav_CaptureToSee);

    //Print status message bar
    switch(status)
    {
        default:
        case STATUS_INVALID_SEARCH:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, DexNav_WhiteText, 0, sText_DexNav_Invalid);
            break;
        case STATUS_CHOOSE_MON:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, DexNav_WhiteText, 0, sText_DexNav_ChooseMon);
            break;
        case STATUS_LOCKED:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, DexNav_WhiteText, 0, sText_DexNav_Locked);
            break;
        case STATUS_NO_DATA:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, DexNav_WhiteText, 0, sText_DexNav_NoDataForSlot);
            break;
        case STATUS_INCORRECT_AREA:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, DexNav_WhiteText, 0, sText_DexNav_NotFoundHere);
            break;
    }

    //Load area names
    DexNavLoadAreaNames();

    //Load map name
    GetMapName(gStringVar4, GetCurrentRegionMapSectionId(), 0);
    AddTextPrinterParameterized3(WINDOW_MAP_NAME, 1, 2, 0, DexNav_WhiteText, 0, gStringVar4);

    // display committed gfx
    for (i = 0; i < WINDOW_COUNT; i++)
    {
        CopyWindowToVram(i, 3);
        PutWindowTilemap(i);
    }
}

static void DexNavLoadPokeIcons(void)
{
    s16 x, y;
    //u8 letter;
    u32 pid = 0xFFFFFFFF;
    u8 hiddenLandMons = sDexnavSearchDataPtr->numHiddenLandMons;
    u8 hiddenWaterMons = sDexnavSearchDataPtr->numHiddenWaterMons;
	u8 i;
	u16 species;

    LoadMonIconPalettes();

    for (i = 0; i < NUM_LAND_MONS; ++i)
    {
        species = sDexnavSearchDataPtr->grassSpecies[i];
        x = 20 + (24 * (i % 6));
        y = 92 + (i > 5 ? 28 : 0);

        if (species == SPECIES_NONE)
        {
            if (hiddenLandMons == 0)
            {
                CreateNoDataIcon(x, y);
                continue;
            }
            else
                hiddenLandMons--;
        }

        //letter = sDexnavSearchDataPtr->unownFormsByDNavIndices[i];
        //if (letter > 0)
        //    pid = GenerateUnownPersonality(sDexnavSearchDataPtr->unownFormsByDNavIndices[i] - 1);

        CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, pid, 0);
    }

    for (i = 0; i < NUM_WATER_MONS; ++i)
    {
        species = sDexnavSearchDataPtr->waterSpecies[i];
        x = 30 + 24 * i;
        y = 48;

        if (species == SPECIES_NONE)
        {
            if (hiddenWaterMons == 0)
            {
                CreateNoDataIcon(x, y);
                continue;
            }
            else
                hiddenWaterMons--;
        }

        //letter = PickUnownLetter(species, i);
        //if (letter > 0)
        //    pid = GenerateUnownPersonality(letter - 1);

        CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, pid, 0);
    }
}

static void CreateNoDataIcon(s16 x, s16 y)
{
    LoadCompressedSpriteSheetUsingHeap(&sIconTiles);
    CreateSprite(&sIconTemplate, x, y, 0);
}

static void SpawnPointerArrow(void)
{
    // uncompressed
    LoadSpriteSheet(&CursorGFX);
    LoadSpritePalette(&CursorPal);
    sDexnavSearchDataPtr->cursorId = CreateSprite(&CursorTemp, 30, 48, 0);
    UpdateCursorPosition();
}

static void UpdateCursorPosition(void)
{
    // update cursor position
    if (sDexnavSearchDataPtr->selectedArr)
    {
        // water
        gSprites[sDexnavSearchDataPtr->cursorId].pos1.x = CursorPositions2[sDexnavSearchDataPtr->selectedIndex];
        gSprites[sDexnavSearchDataPtr->cursorId].pos1.y = CursorPositions2[sDexnavSearchDataPtr->selectedIndex + 1];
    }
    else
    {
        // grass
        gSprites[sDexnavSearchDataPtr->cursorId].pos1.x = CursorPositions1[sDexnavSearchDataPtr->selectedIndex];
        gSprites[sDexnavSearchDataPtr->cursorId].pos1.y = CursorPositions1[sDexnavSearchDataPtr->selectedIndex + 1];
    }
}

static void DexNavLoadCapturedAllSymbol(void)
{
    int i;
    u8 num = 0;
    u16 species;
    u16 headerId = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

    LoadCompressedSpriteSheetUsingHeap(&sCapturedAllPokemonSpriteSheet);

    if (landMonsInfo != NULL)
    {
        for (i = 0; i < NUM_LAND_MONS; i++)
        {
            species = landMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE)
            {
                num++;
                if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                    break;
            }
        }

        if (i >= NUM_LAND_MONS && num > 0) //All land mons caught and there were land mons to catch
            CreateSprite(&sCapturedAllPokemonSymbolTemplate,  154, 77, 0);
    }

    num = 0;
    if (waterMonsInfo != NULL)
    {
        for (i = 0; i < NUM_WATER_MONS; i++)
        {
            species = waterMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE)
            {
                num++;
                if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                    break;
            }
        }

        if (i >= NUM_WATER_MONS && num > 0) //All water mons caught and there were water mons to catch
            CreateSprite(&sCapturedAllPokemonSymbolTemplate,  140, 29, 0);
    }
}

static void DexNavGuiExitSearch(void)
{
    switch (gMain.state)
    {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x0, 0x10, 0);
            PlaySE(SE_DEX_SEARCH);
            gMain.state++;
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                Free(sDexnavSearchDataPtr->backBuffer);
                gMain.state++;
            }
            break;
        case 2:
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
            SetMainCallback1(CallbackDexNavOW);
            SetMainCallback2(CB2_ReturnToFieldContinueScript);
            break;
    }
}

static void CallbackDexNavOW(void)
{
    ExecDexNavHUD();
}

static void ExecDexNavHUD(void)
{
    if (!gPaletteFade.active && !ScriptContext2_IsEnabled() && gMain.callback2 == CB2_Overworld)
    {
        SetMainCallback1(CB1_Overworld);
        InitDexNavHUD(gDexnavSpecies, gDexnavEnvironment);
    }
}

static void PrintDexNavError(u8 caseId)
{
    switch (caseId)
    {
        default:
            DexNavLoadNames(caseId);
            PlaySE(SE_FAILURE);
            break;
        case 0:
            if (sDexnavSearchDataPtr->selectedArr == ROW_WATER && sDexnavSearchDataPtr->selectedIndex >> 1 >= sDexnavSearchDataPtr->numWaterMons + sDexnavSearchDataPtr->numHiddenWaterMons)
            {
                //Print Pokemon can't be searched yet
                DexNavLoadNames(3);
                PlaySE(SE_FAILURE);
            }
            else if (sDexnavSearchDataPtr->selectedArr == ROW_LAND && sDexnavSearchDataPtr->selectedIndex >> 1 >= sDexnavSearchDataPtr->numGrassMons + sDexnavSearchDataPtr->numHiddenLandMons)
            {
                //Print Pokemon can't be searched yet
                DexNavLoadNames(3);
                PlaySE(SE_FAILURE);
            }
            else //Selected unidentified Pokemon
            {
                //Print invalid Pokemon
                DexNavLoadNames(0);
                PlaySE(SE_FAILURE);
            }
            break;
    }
}

static void DexNavGuiExitNoSearch(void)
{
    switch (gMain.state)
    {
        case 0:
            BeginNormalPaletteFade(~0, 0, 0x0, 0x10, 0);
            gMain.state++;
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                Free(sDexnavSearchDataPtr->backBuffer);
                Free(sDexnavSearchDataPtr);
                gMain.state++;
            }
            break;
        case 2:
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
            SetMainCallback1(CB1_Overworld);

            //#ifdef FLAG_POKETOOLS_MENU
            //    FlagSet(FLAG_POKETOOLS_MENU);
            //#endif
            SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
            break;
    }
}

static u8 DexNavGenerateMonLevel(u16 species, u8 searchLevel, u8 environment)
{
    u8 levelBase = GetEncounterLevel(species, environment);
    u8 searchLevelBonus;
    
    if (levelBase > MAX_LEVEL)
        return 0;

    searchLevelBonus = 0;
    if (searchLevel >> 2 > 20)
        searchLevelBonus = 20;
    else
        searchLevelBonus = searchLevel >> 2;

    if (searchLevelBonus + levelBase > MAX_LEVEL)
        return MAX_LEVEL;
    else
        return searchLevelBonus + levelBase;
}

static void DexNavGenerateMoveset(u16 species, u8 searchLevel, u8 encounterLevel, u16* moveLoc)
{
    bool8 genMove = FALSE;
    u16 randVal = Random() % 100;
    u16 i;
    u16 eggMoveBuffer[EGG_MOVES_ARRAY_COUNT];

    //Evaluate if Pokemon should get an egg move in first slot
    if (searchLevel < 5)
    {
        #if (SEARCHLEVEL0_MOVECHANCE != 0)
        if (randVal < SEARCHLEVEL0_MOVECHANCE)
            genMove = TRUE;
        #endif
    }
    else if (searchLevel < 10)
    {
        #if (SEARCHLEVEL5_MOVECHANCE != 0)
        if (randVal < SEARCHLEVEL5_MOVECHANCE)
            genMove = TRUE;
        #endif
    }
    else if (searchLevel < 25)
    {
        #if (SEARCHLEVEL10_MOVECHANCE != 0)
        if (randVal < SEARCHLEVEL10_MOVECHANCE)
            genMove = TRUE;
        #endif
    }
    else if (searchLevel < 50)
    {
        #if (SEARCHLEVEL25_MOVECHANCE != 0)
        if (randVal < SEARCHLEVEL25_MOVECHANCE)
            genMove = TRUE;
        #endif
    }
    else if (searchLevel < 100)
    {
        #if (SEARCHLEVEL50_MOVECHANCE != 0)
        if (randVal < SEARCHLEVEL50_MOVECHANCE)
            genMove = TRUE;
        #endif
    }
    else
    {
        #if (SEARCHLEVEL100_MOVECHANCE != 0)
        if (randVal < SEARCHLEVEL100_MOVECHANCE)
            genMove = TRUE;
        #endif
    }

    //Generate a wild mon and copy moveset
    //CreateWildMon(species, encounterLevel, sDexnavSearchDataPtr->selectedIndex / 2, TRUE);
    CreateWildMon(species, encounterLevel);

    //Store generated mon moves into Dex Nav Struct
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        moveLoc[i] = GetMonData(&gEnemyParty[0], MON_DATA_MOVE1 + i, NULL);
    }

    // set first move slot to a random egg move if search level is good enough
    if (genMove == TRUE)
    {
        u8 numEggMoves = GetEggMoves(&gEnemyParty[0], eggMoveBuffer);
        if (numEggMoves != 0)
        {
            u8 index = RandRange(0, numEggMoves);
            moveLoc[0] = eggMoveBuffer[index];
        }
    }
}

static u16 DexNavGenerateHeldItem(u16 species, u8 searchLevel)
{
    u16 randVal = Random() % 100;
    u8 searchLevelInfluence = searchLevel >> 1;
    u16 item1 = gBaseStats[species].item1;
    u16 item2 = gBaseStats[species].item2;

    // if both are the same, 100% to hold
    if (item1 == item2)
        return item1;

    // if no items can be held, then yeah...no items
    if (item2 == ITEM_NONE && item1 == ITEM_NONE)
        return ITEM_NONE;

    // if only one entry, 50% chance
    if (item2 == ITEM_NONE && item1 != ITEM_NONE)
        return (randVal < 50) ? item1 : ITEM_NONE;

    // if both are distinct item1 = 50% + srclvl/2; item2 = 5% + srchlvl/2
    if (randVal < (50 + searchLevelInfluence + 5 + searchLevel))
        return (randVal > 5 + searchLevelInfluence) ? item1 : item2;
    else
        return ITEM_NONE;

    return ITEM_NONE;
}

static u8 DexNavGenerateHiddenAbility(u16 species, u8 searchLevel)
{
    bool8 genAbility = FALSE;
    u16 randVal = Random() % 100;
    u8 abilityNum;
    
    if (searchLevel < 5)
    {
        #if (SEARCHLEVEL0_ABILITYCHANCE != 0)
        if (randVal < SEARCHLEVEL0_ABILITYCHANCE)
            genAbility = TRUE;
        #endif
    }
    else if (searchLevel < 10)
    {
        #if (SEARCHLEVEL5_ABILITYCHANCE != 0)
        if (randVal < SEARCHLEVEL5_ABILITYCHANCE)
            genAbility = TRUE;
        #endif
    }
    else if (searchLevel < 25)
    {
        #if (SEARCHLEVEL10_ABILITYCHANCE != 0)
        if (randVal < SEARCHLEVEL10_ABILITYCHANCE)
            genAbility = TRUE;
        #endif
    }
    else if (searchLevel < 50)
    {
        #if (SEARCHLEVEL25_ABILITYCHANCE != 0)
        if (randVal < SEARCHLEVEL25_ABILITYCHANCE)
            genAbility = TRUE;
        #endif
    }
    else if (searchLevel < 100)
    {
        #if (SEARCHLEVEL50_ABILITYCHANCE != 0)
        if (randVal < SEARCHLEVEL50_ABILITYCHANCE)
            genAbility = TRUE;
        #endif
    }
    else
    {
        #if (SEARCHLEVEL100_ABILITYCHANCE != 0)
        if (randVal < SEARCHLEVEL100_ABILITYCHANCE)
            genAbility = TRUE;
        #endif
    }

    //Only give hidden ability if Pokemon has been caught before
    if (genAbility && gBaseStats[species].abilityHidden != ABILITY_NONE && GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        sDexnavSearchDataPtr->ability = gBaseStats[species].abilityHidden;
        abilityNum = 2;
        //return gBaseStats[species].abilityHidden, species;
    }
    else
    {
        //Pick a normal ability of that Pokemon
        if (gBaseStats[species].abilities[1] != ABILITY_NONE)
            abilityNum = Random() & 1;
        else
            abilityNum = 0;   // ability1
        
        sDexnavSearchDataPtr->ability = gBaseStats[species].abilities[abilityNum];
    }
}




//////////////////////////////
//////////// HUD /////////////
//////////////////////////////
static void InitDexNavHUD(u16 species, u8 environment)
{
    u8 searchLevel;
    u8 taskId;
    u8 mapType;
    
    sDexnavSearchDataPtr = AllocZeroed(sizeof(struct DexnavSearch));
    // assign non-objects to struct
    sDexnavSearchDataPtr->species = species;

    if (IS_NEWER_UNOWN_LETTER(species))
    {
        sDexnavSearchDataPtr->unownLetter = species - SPECIES_UNOWN_B + 2; //Because B is 1
        sDexnavSearchDataPtr->species = species = SPECIES_UNOWN;
    }
    else //UNOWN A
    {
        sDexnavSearchDataPtr->unownLetter = 1;
    }
    
    sDexnavSearchDataPtr->environment = environment;
    searchLevel = sDexNavSearchLevels[SpeciesToNationalPokedexNum(species)];
    sDexnavSearchDataPtr->searchLevel = searchLevel;
    sDexnavSearchDataPtr->monLevel = DexNavGenerateMonLevel(species, searchLevel, environment);

    
    if (sDexnavSearchDataPtr->monLevel < 1)
    {
        Free(sDexnavSearchDataPtr);
        ShowFieldMessage(sText_CannotBeFound);
        return;
    }
    
    // draw shaking grass
    if (!(ShakingGrass(environment, 12, 12, 0)))
    {
        Free(sDexnavSearchDataPtr);
        ShowFieldMessage(sText_NotFoundNearby);
        return;
    }
    
    //Populate sDexnavSearchDataPtr objects
    DexNavGenerateMoveset(species, searchLevel, sDexnavSearchDataPtr->monLevel, &sDexnavSearchDataPtr->moveId[0]);
    sDexnavSearchDataPtr->heldItem = DexNavGenerateHeldItem(species, searchLevel);
    sDexnavSearchDataPtr->abilityNum = DexNavGenerateHiddenAbility(species, searchLevel);
    sDexnavSearchDataPtr->potential = DexNavGeneratePotential(searchLevel);
    DexNavProximityUpdate();

    //Draw icons
    DexNavDrawIcons();
    DexNavHudDrawSpeciesIcon(sDexnavSearchDataPtr->species, &sDexnavSearchDataPtr->spriteIdSpecies);

    //Hide icons based on proximity and search level
    DexNavIconsVisionUpdate(sDexnavSearchDataPtr->proximity, searchLevel);

    //Enable Hblank interrupt
    //EnableInterrupts(2);
    //SetHBlankCallback(DexHUDHBlank);

    // task update HUD
    FlagSet(FLAG_SYS_DEXNAV_ACTIVE);
    //taskId = CreateTask(Task_DexNavSearch, 0x1);    //to do:
    gTasks[taskId].data[0] = gSprites[gPlayerAvatar.spriteId].pos1.x;
}

static void DexNavDrawIcons(void)
{
    u8 searchLevel = sDexnavSearchDataPtr->searchLevel;
    
    DexNavDrawBlackBars(&sDexnavSearchDataPtr->spriteIdBlackBar[0]);
    DexNavDrawSight(sDexnavSearchDataPtr->proximity, &sDexnavSearchDataPtr->spriteIdSight);
    DexNavDrawMove(sDexnavSearchDataPtr->moveId[0], searchLevel, &sDexnavSearchDataPtr->spriteIdMove);
    DexNavDrawHeldItem(&sDexnavSearchDataPtr->spriteIdItem);
    DexNavDrawAbility(sDexnavSearchDataPtr->ability, &sDexnavSearchDataPtr->spriteIdAbility);
    DexNavDrawPotential(sDexnavSearchDataPtr->potential, &sDexnavSearchDataPtr->spriteIdPotential[0]);
    DexNavHudDrawSpeciesIcon(sDexnavSearchDataPtr->species, &sDexnavSearchDataPtr->spriteIdSpecies);
}

static void DexNavDrawBlackBars(u8 *spriteIdAddr)
{
    LoadSpritePalette(&sSpritePalette_Stars);
    LoadCompressedSpriteSheetUsingHeap(&sBlackBarTiles);
    spriteIdAddr[0] = CreateSprite(&sBlackBarTemplate, ICONX + 16, ICONY - 2, 0x0);
    spriteIdAddr[1] = CreateSprite(&sBlackBarTemplate, ICONX + 16 + 64, ICONY - 2, 0x0);
    spriteIdAddr[2] = CreateSprite(&sBlackBarTemplate, ICONX + 16 + 64 + 64, ICONY - 2, 0x0);
    spriteIdAddr[3] = CreateSprite(&sBlackBarTemplate, ICONX + 16 + 64 + 64 + 64, ICONY - 2, 0x0);
}

static void DexNavDrawSight(u8 sightLevel, u8* spriteIdAddr)
{
    u8 spriteId;
  
	LoadSpritePalette(&sSpritePalette_Stars);
	LoadCompressedSpriteSheetUsingHeap(&sightTiles);
	spriteId = CreateSprite(&fontTempSight, ICONX + 192, ICONY + 0x12, 0x0);
	if (spriteId < MAX_SPRITES)
	{
		*spriteIdAddr = spriteId;
		DexNavSightUpdate(sightLevel);
	}
}

static void DexNavDrawAbility(u8 ability, u8* spriteIdAddr)
{
    u8 spriteId = CreateSprite(&FontTempAbility, ICONX + 80, ICONY + 0x12, 0x0);
    u8 len;
    
    LoadSpritePalette(&sSpritePalette_Stars);
    LoadCompressedSpriteSheetUsingHeap(&FontSpriteAbility);
    *spriteIdAddr = spriteId;
    gSprites[spriteId].oam.affineMode = 2;

    // ability name beside move name
    len = sDexnavSearchDataPtr->moveNameLength;
    gSprites[spriteId].pos1.x += ((8 * (len/2)) + (4 * (len % 2)));

    // Copy ability string from table using state id
    StringCopy(gStringVar4, gAbilityNames[ability]);

    // format string so it's even length or if it's odd ends in two spaces
    len = StringLength(gStringVar4);
    if (!(len % 2))
    {
        gStringVar4[len] = 0x0;
        gStringVar4[len + 1] = 0x0;
        gStringVar4[len + 2] = 0xFF;
    }

    // write name to object
    OutlinedFontDraw(spriteId, 0, 32 * 8);
    gSprites[spriteId].oam.objMode = 1;
    return;
}

static void DexNavDrawMove(u16 move, u8 searchLevel, u8* spriteIdAddr)
{
    u8 spriteId;
    u8* ptr;
    u8 len;
    
    LoadSpritePalette(&sSpritePalette_Stars);
    LoadCompressedSpriteSheetUsingHeap(&FontSpriteMove);
    spriteId = CreateSprite(&FontTempMove, ICONX + 80, ICONY + 0x12, 0x0);
    *spriteIdAddr = spriteId;
    gSprites[spriteId].oam.affineMode = 2;

    // Copy move string from table using state id, add '/' character to the end of it
    ptr = StringCopy(gStringVar4, gMoveNames[move]);
    len = StringLength(gStringVar4);

    if (searchLevel > 2)
    {
        *ptr = 0xBA;    // '/'
        len++;
    }

    // record length of move with slash for ability name to be placed beside it
    sDexnavSearchDataPtr->moveNameLength = len;

    // adjust string to be even chars, if odd end in two spaces
    if (!(len % 2))
    {
        gStringVar4[len] = 0x0;
        gStringVar4[len + 1] = 0x0;
        gStringVar4[len + 2] = 0xFF;
    }
    else
    {
        gStringVar4[len] = 0xFF;
    }

    // write name to object
    OutlinedFontDraw(spriteId, 0, 32 * 8);
    gSprites[spriteId].oam.objMode = 1;
}

void DexNavHudDrawSpeciesIcon(u16 species, u8 *spriteIdAddr)
{  
    u8 spriteId;
    u32 pid = 0xFFFFFFFF;
    
    //if (species == SPECIES_UNOWN)
    //    pid = GenerateUnownPersonality(sDexnavSearchDataPtr->unownLetter - 1);

    //Load which palette the species icon uses
    LoadMonIconPalette(species);
    spriteId = CreateMonIcon(species, SpriteCB_MonIcon, ICONX, ICONY, 0, pid, FALSE); //personality only useful for unown here

    //Create the icon
    //spriteId = CreateMonIcon(species, SpriteCB_MonIcon, ICONX, ICONY, 0, pid, FALSE);
    *spriteIdAddr = spriteId;

    gSprites[spriteId].oam.affineMode = 2;
    gSprites[spriteId].oam.objMode = 1;
    //gSprites[spriteId].oam.priority = 0;
}

void DexNavDrawHeldItem(u8* spriteIdAddr)
{
    // create object for held item icon
    u8 spriteId;

    LoadSpriteSheet(&sSpriteSheet_HeldItem);
    LoadSpritePalette(&sSpritePalette_HeldItem);
    spriteId = CreateSprite(&HeldTemp, ICONX + 0x8, ICONY + 0xC, 0x0);
    *spriteIdAddr = spriteId;
    gSprites[spriteId].oam.affineMode = 2;
    gSprites[spriteId].oam.objMode = 1;
}

static void DexNavDrawPotential(u8 potential, u8* spriteIdAddr)
{
    u8 spriteId;
    u8 i;
    
    // allocate both the lit and unlit star to VRAM
    LoadSpriteSheet(&StarIconLit);
    LoadSpriteSheet(&StarIconOff);
    LoadSpritePalette(&sSpritePalette_Stars);

    // create star objects and space them according to potential 0 - 3
    for (i = 0; i < 3; i++)
    {
        if (potential > i)
            spriteId = CreateSprite(&StarLitTemp, ICONX + 23 + (i * 8), ICONY + 0x5, 0x0);
        else
            spriteId = CreateSprite(&StarOffTemp, ICONX + 23 + (i * 8), ICONY + 0x5, 0x0);

        spriteIdAddr[i] = spriteId;
        gSprites[spriteId].oam.affineMode = 2;
        gSprites[spriteId].oam.objMode = 1;
    }
}

static void DexNavSightUpdate(u8 sight)
{
    u8 spriteId = sDexnavSearchDataPtr->spriteIdSight;
    // draw sight eye on first tile, takes up two tiles
    u8 tileid = gSprites[spriteId].oam.tileNum;
    u8* toWrite = (u8*)((tileid * 32) + (OBJ_VRAM0));
    
    memcpy(toWrite, &sDexnavStarsTiles[((19 * 4) + (7 - (2 * sight))) * 32], 64);

    // draw the B button tile
    memcpy(toWrite + 128, &sDexnavStarsTiles[((19 * 4) + 2) *32], 64);

    // draw info text on the 5th tile
    //pchar back[] = _(" Back  ");
    StringCopy(gStringVar4, sText_DexNavBack);
    OutlinedFontDraw(spriteId, 5, 32 * 8);
}


static void DexNavIconsVisionUpdate(u8 proximity, u8 searchLevel)
{
    // The sight eye and species icon are always drawn in the HUD
    //     At search level 2, first move is drawn
    //     At search level 3, Ability and Held item are drawn
    //     At search level 5, Potential is drawn

    // species and sight/info are always shown, regardless of proximity
    gSprites[sDexnavSearchDataPtr->spriteIdSpecies].oam.affineMode = 0;
    gSprites[sDexnavSearchDataPtr->spriteIdSight].oam.affineMode = 0;

    // hide everything at the start, and recalc what needs to be shown
    gSprites[sDexnavSearchDataPtr->spriteIdMove].oam.affineMode = 2;
    gSprites[sDexnavSearchDataPtr->spriteIdAbility].oam.affineMode = 2;
    gSprites[sDexnavSearchDataPtr->spriteIdItem].oam.affineMode = 2;
    gSprites[sDexnavSearchDataPtr->spriteIdPotential[0]].oam.affineMode = 2;
    gSprites[sDexnavSearchDataPtr->spriteIdPotential[1]].oam.affineMode = 2;
    gSprites[sDexnavSearchDataPtr->spriteIdPotential[2]].oam.affineMode = 2;

    if (proximity < 3)
    {
        // at proximity 5, the sight should start to show and indicate sneaking is required
        DexNavSightUpdate(0); // alert level TODO: Update in a better way utiliting sight_level
        if (searchLevel > 1)
        {
            // show move, hide others
            gSprites[sDexnavSearchDataPtr->spriteIdMove].oam.affineMode = 0;
        }
        if (searchLevel > 2)
        {
            // show ability, move, hide others
            gSprites[sDexnavSearchDataPtr->spriteIdAbility].oam.affineMode = 0;
            if (sDexnavSearchDataPtr->heldItem)
            {
                // toggle item view
                gSprites[sDexnavSearchDataPtr->spriteIdItem].oam.affineMode = 0;
            }
        }
        if (searchLevel > 4)
        {
            gSprites[sDexnavSearchDataPtr->spriteIdPotential[0]].oam.affineMode = 0;
            gSprites[sDexnavSearchDataPtr->spriteIdPotential[1]].oam.affineMode = 0;
            gSprites[sDexnavSearchDataPtr->spriteIdPotential[2]].oam.affineMode = 0;
        }

    }
    else if (proximity <= SNEAKING_PROXIMITY)
        DexNavSightUpdate(1); // Sneaking is required flag
    else
        DexNavSightUpdate(2); // Sneaking is not required
}

#define PLAYER_AVATAR_FLAG_BIKE PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE
static void Task_DexNavSearch(u8 taskId)
{
    u16 dexNum;
    
    // check for out of range
    if (sDexnavSearchDataPtr->proximity > MAX_PROXIMITY)
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        DexNavShowMessage(1);    //there is no reaction!\nThe signal was lost!
        return;
    }

    // check for timeout.
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] > DEXNAV_TIMEOUT * 60)
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        DexNavShowMessage(0);    //The pokemon got away!
        return;
    }

    if (sDexnavSearchDataPtr->proximity <= SNEAKING_PROXIMITY && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_BIKE)) //If player is close and running then the Pokemon should flee
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        DexNavShowMessage(2);    //The pokemon got away!\nTry moving more slowly.
        return;
    }

    // check if script just executed
    if (ScriptContext2_IsEnabled() == TRUE)
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        return;
    }

    if (JOY_NEW(B_BUTTON | START_BUTTON))
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        PlaySE(SE_POKENAV_OFF);
        return;
    }

    //Caves and water the pokemon moves around
    if ((sDexnavSearchDataPtr->environment == ENCOUNTER_TYPE_WATER || !IsMapTypeOutdoors(GetCurrentMapType())) && sDexnavSearchDataPtr->proximity < 2 && sDexnavSearchDataPtr->movementTimes < 2)
    {
        switch(sDexnavSearchDataPtr->environment)
        {
            case ENCOUNTER_TYPE_LAND:
                FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_CAVE_DUST);
                break;
            case ENCOUNTER_TYPE_WATER:
                FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_WATER_SURFACING);
                break;
            default:
                break;
        }
        
        while(!ShakingGrass(sDexnavSearchDataPtr->environment, 8, 8, 1))
            __asm__("mov r8, r8");

        sDexnavSearchDataPtr->movementTimes++;
    }

    // check for encounter start
    if (sDexnavSearchDataPtr-> proximity < 1)
    {
        DexNavGetMon(sDexnavSearchDataPtr->species, sDexnavSearchDataPtr->potential, sDexnavSearchDataPtr->monLevel,
        sDexnavSearchDataPtr->abilityNum, sDexnavSearchDataPtr->moveId);
        DestroyTask(taskId);

        // increment the search level
        dexNum = SpeciesToNationalPokedexNum(sDexnavSearchDataPtr->species);
        if (sDexNavSearchLevels[dexNum] < 100)
            sDexNavSearchLevels[dexNum]++;

        // Freeing only the state, objects and hblank cleared on battle start.
        Free(sDexnavSearchDataPtr);

        ScriptContext1_SetupScript(EventScript_StartDexNavBattle);
        
        // exclamation point animation over the player
        //PlaySE(SE_PIN);
        //MovementAction_EmoteExclamationMark_Step0(&gObjectEvents[EVENT_OBJ_ID_PLAYER], &gSprites[gPlayerAvatar.spriteId]);
        //FieldEffectStart();

        // do battle
        //DoStandardWildBattle();
    }

    // HUD needs updating iff player has moved
    DexNavProximityUpdate();
    if (!(gTasks[taskId].data[0] == sDexnavSearchDataPtr->proximity))
    {
        DexNavIconsVisionUpdate(sDexnavSearchDataPtr->proximity, sDexnavSearchDataPtr->searchLevel);
        gTasks[taskId].data[0] = sDexnavSearchDataPtr->proximity;
    }
}

// ===== Pokemon Field Tile ===== //

*/


/*

static u8 GetEncounterLevel(u16 species, u8 environment)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    u8 min = 100;
    u8 max = 0;
    u8 i;
    
    switch (environment)
    {
        case ENCOUNTER_TYPE_LAND:    // grass
            if (landMonsInfo == NULL)
                return 22; //Hidden pokemon should only appear on walkable tiles or surf tiles

            for (i = 0; i < NUM_LAND_MONS; i++)
            {
                if (landMonsInfo->wildPokemon[i].species == species)
                {
                    min = (min < landMonsInfo->wildPokemon[i].minLevel) ? min : landMonsInfo->wildPokemon[i].minLevel;
                    max = (max > landMonsInfo->wildPokemon[i].maxLevel) ? max : landMonsInfo->wildPokemon[i].maxLevel;
                }
            }
            break;

        case ENCOUNTER_TYPE_WATER:    //water
            if (waterMonsInfo == NULL)
                return 22; //Hidden pokemon should only appear on walkable tiles or surf tiles

            for (i = 0; i < NUM_WATER_MONS; i++)
            {
                if (waterMonsInfo->wildPokemon[i].species == species)
                {
                    min = (min < waterMonsInfo->wildPokemon[i].minLevel) ? min : waterMonsInfo->wildPokemon[i].minLevel;
                    max = (max > waterMonsInfo->wildPokemon[i].maxLevel) ? max : waterMonsInfo->wildPokemon[i].maxLevel;
                }
            }
            break;

        default:
            return 22;
    }

    if (max == 0)
        return 0xFF; //Free dexnav display message

    //Mod div by 0 edge case.
    if (min == max)
        return min;

    return (min + (Random() % (max - min)));
}

static void DexNavShowMessage(u8 id)
{
    //gFieldMessageBoxMode = 0;
    
    switch(id)
    {
        case 0:
            ShowFieldMessage(sText_GotAway);
            break;
        case 1:
            ShowFieldMessage(sText_LostSignal);
            break;
        case 2:
            ShowFieldMessage(sText_GotAwayShouldSneak);
            break;
    }
    return;
}



static void NullSubHBlank(void)
{
}

#define sSpriteTileAllocBitmap ((u8*) 0x2021B48)
#define FREE_SPRITE_TILE(n) (sSpriteTileAllocBitmap[(n) / 8] &= ~(1 << ((n) % 8)))
static void DexNavFreeHUD(void)
{
    u16 i, tile;
    u8 *tiles;
    
    switch (sDexnavSearchDataPtr->environment)
    {
        case ENCOUNTER_TYPE_LAND:
            if (!IsMapTypeOutdoors(GetCurrentMapType()))
                FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_CAVE_DUST); //cave
            else
                FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_SHAKING_GRASS);
            break;
        case ENCOUNTER_TYPE_WATER:
            FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_WATER_SURFACING);
            break;
    }

    //Clear mon icon sprite
    SafeFreeMonIconPalette(sDexnavSearchDataPtr->species);
    tile = gSprites[sDexnavSearchDataPtr->spriteIdSpecies].oam.tileNum;
    tiles = (u8*)((tile * TILE_SIZE_4BPP) + OBJ_VRAM0);
    memset(tiles, 0, 0x200);

    for (i = tile; i < tile + 16; i++)
        FREE_SPRITE_TILE(i);

    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdSpecies]);

    //Clear black bars
    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdBlackBar[0]]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdBlackBar[0]]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdBlackBar[1]]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdBlackBar[2]]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdBlackBar[3]]);

    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdSight]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdSight]);

    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdAbility]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdAbility]);

    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdMove]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdMove]);

    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdItem]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdItem]);

    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdPotential[0]]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdPotential[0]]);

    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdPotential[1]]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdPotential[1]]);

    FieldEffectFreeGraphicsResources(&gSprites[sDexnavSearchDataPtr->spriteIdPotential[2]]);
    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdPotential[2]]);

    //FreeSpriteTilesByTag(0x4736);
    FreeSpriteTilesByTag(0x61);
    FreeSpriteTilesByTag(0x2613);
    FreeSpriteTilesByTag(0x5424);
    FreeSpriteTilesByTag(0x2710);
    FreeSpriteTilesByTag(0x1EE7); //Font Sprite
    FreeSpriteTilesByTag(0xFDF1); //Black Bars
    FreeSpriteTilesByTag(0x3039);
    FreeSpritePaletteByTag(0x2710);
    FreeSpritePaletteByTag(0x3039);

    ResetSprite(&gSprites[sDexnavSearchDataPtr->spriteIdMove]);

    Free(sDexnavSearchDataPtr);
    DisableInterrupts(2);
    SetHBlankCallback(NullSubHBlank);

    // WRITE_REG_WININ(0x1F1F);
    REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 |
                            WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
    //WRITE_REG_BLDCNT(0x401E);
    REG_BLDCNT = BLDALPHA_BLEND(BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ, 0);


    // WRITE_REG_WININ(0x1F1F);
    REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 |
        WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
    //WRITE_REG_BLDCNT(0x401E);
    REG_BLDCNT = BLDALPHA_BLEND(BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ, 0);
}
*/


#include "text_window.h"


#define ITEM_ICON_X 26
#define ITEM_ICON_Y (16 * 8)


static void ShowMonIconInHeaderBox(u16 species)
{
    u8 spriteId;
    u8 yPos;
    
    yPos = ITEM_ICON_Y + 8;
    LoadMonIconPalette(species);
    spriteId = CreateMonIcon(species, SpriteCB_MonIcon, ITEM_ICON_X - 6, yPos, 0, 0xFFFFFFFF, 0);
    gSprites[spriteId].oam.priority = 0;
    sDexnavSearchSpriteId = spriteId;
}

static const u8 sFontColor[3] = {0, 15, 13};
static const u8 sText_Test[] = _("{STR_VAR_1}       Ability          Level\nSpecial Move        IVs          Shiny");
void DrawHeaderBox(void)
{
    struct WindowTemplate template;    
    u16 species = SPECIES_MUDKIP;
    
    LoadDexNavWindowGfx(sDexnavWindowId, 0xFC, 14 * 16);
    
    SetWindowTemplateFields(&template, 0, 1, 16, 28, 3, 14, 8);
    
    sDexnavWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sDexnavWindowId, PIXEL_FILL(15));
    PutWindowTilemap(sDexnavWindowId);
    CopyWindowToVram(sDexnavWindowId, 3);
    
    DrawStdFrameWithCustomTileAndPalette(sDexnavWindowId, FALSE, 0x214, 14);
    
    StringCopy(gStringVar1, gSpeciesNames[species]);
    StringExpandPlaceholders(gStringVar4, sText_Test);
    AddTextPrinterParameterized3(sDexnavWindowId, 0, ITEM_ICON_X + 4, 0, sFontColor, TEXT_SPEED_FF, gStringVar4);
    CopyWindowToVram(sDexnavWindowId, 2);
    
    ShowMonIconInHeaderBox(species);
}

void RemoveHeaderBox(void)
{
    DestroySpriteAndFreeResources(&gSprites[sDexnavSearchSpriteId]);
    ClearStdWindowAndFrameToTransparent(sDexnavWindowId, FALSE);
    CopyWindowToVram(sDexnavWindowId, 3);
    RemoveWindow(sDexnavWindowId);
}


//////////////////////
////DEXNAV SEARCH/////
//////////////////////
static u8 GetPlayerDistance(s16 x, s16 y)
{
    u16 deltaX = abs(x - (gSaveBlock1Ptr->pos.x + 7));
    u16 deltaY = abs(y - (gSaveBlock1Ptr->pos.y + 7));
    return deltaX + deltaY;
}

static void DexNavProximityUpdate(void)
{
    sDexnavSearchDataPtr->proximity = GetPlayerDistance(sDexnavSearchDataPtr->tileX, sDexnavSearchDataPtr->tileY);
}


static bool8 PickTileScreen(u8 targetBehaviour, u8 areaX, u8 areaY, s16 *xBuff, s16 *yBuff, u8 smallScan)
{
    
}
//Pick a specific tile based on environment
static bool8 DexNavPickTile(u8 environment, u8 areaX, u8 areaY, bool8 smallScan)
{    
    // area of map to cover starting from camera position {-7, -7}
    s16 topX = gSaveBlock1Ptr->pos.x - SCANSTART_X + (smallScan * 5);
    s16 topY = gSaveBlock1Ptr->pos.y - SCANSTART_Y + (smallScan * 5);
    s16 botX = topX + areaX;
    s16 botY = topY + areaY;
    u8 i;
    bool8 nextIter;
    u8 scale, weight;

    // loop through every tile in area and evaluate
    while (topY < botY)
    {
        while (topX < botX)
        {
            u8 tileBehaviour = MapGridGetMetatileBehaviorAt(topX, topY);
            
            gSpecialVar_0x8005 = tileBehaviour;
            
            //Check for objects
            nextIter = FALSE;
            for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
            {
                if (gObjectEvents[i].currentCoords.x == topX && gObjectEvents[i].currentCoords.y == topY)
                {
                    nextIter = TRUE;
                    break;
                }
            }
            
            if (nextIter)
            {
                topX++;
                continue;
            }
            
            weight = 0;
            scale = 0;
            //Tile must be target behaviour (wild tile) and must be passable
            switch (environment)
            {
            case ENCOUNTER_TYPE_LAND:
                if (IsMapTypeIndoors(GetCurrentMapType()) && MetatileBehavior_IsIndoorEncounter(tileBehaviour))
                { // inside (cave)
                    scale = 440 - (smallScan * 200) - (GetPlayerDistance(topX, topY) / 2)  - (2 * (topX + topY));
                    weight = ((Random() % scale) < 1) && !MapGridIsImpassableAt(topX, topY);
                }
                else if (MetatileBehavior_IsLandWildEncounter(tileBehaviour))
                { // grass
                    scale = 100 - (GetPlayerDistance(topX, topY) * 2);
                    weight = (Random() % scale <= 5) && !MapGridIsImpassableAt(topX, topY);
                }
                break;
            case ENCOUNTER_TYPE_WATER:
                if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehaviour))
                {
                    u8 scale = 320 - (smallScan * 200) - (GetPlayerDistance(topX, topY) / 2);
                    u8 elevDiff = IsZCoordMismatchAt(gObjectEvents[gPlayerAvatar.spriteId].currentElevation, topX, topY);

                    weight = (Random() % scale <= 1) && elevDiff && !MapGridIsImpassableAt(topX, topY);
                }
                break;
            }
            
            gSpecialVar_0x8002 = scale;
            if (weight > 0)
            {
                sDexnavSearchDataPtr->tileX = topX;
                sDexnavSearchDataPtr->tileY = topY;
                return TRUE;
            }
            
            topX++;
        }
        
        topY++;
        topX = gSaveBlock1Ptr->pos.x - SCANSTART_X + (smallScan * 5);
    }

    return FALSE;
}


static bool8 ShakingGrass(u8 environment, u8 xSize, u8 ySize, bool8 smallScan)
{
    u32 i;
    u8 fldeffSpriteId = MAX_SPRITES;
    
    if (DexNavPickTile(environment, xSize, ySize, smallScan))
    {
        u8 metatileBehaviour = MapGridGetMetatileBehaviorAt(sDexnavSearchDataPtr->tileX, sDexnavSearchDataPtr->tileY);
        
        gFieldEffectArguments[0] = sDexnavSearchDataPtr->tileX;
        gFieldEffectArguments[1] = sDexnavSearchDataPtr->tileY;
        gFieldEffectArguments[2] = 0xFF; // height.
        
        switch (environment)
        {
            case ENCOUNTER_TYPE_LAND:
                {
                    if (!IsMapTypeOutdoors(GetCurrentMapType()))
                    {
                        if (MetatileBehavior_IsTallGrass(metatileBehaviour)) //Grass in cave
                            fldeffSpriteId = FieldEffectStart(FLDEFF_SHAKING_GRASS);
                        else if (MetatileBehavior_IsLongGrass(metatileBehaviour)) //Really tall grass
                            fldeffSpriteId = FieldEffectStart(FLDEFF_SHAKING_LONG_GRASS);
                        else if (MetatileBehavior_IsSandOrDeepSand(metatileBehaviour))
                            fldeffSpriteId = FieldEffectStart(FLDEFF_SAND_HOLE);
                        else
                            fldeffSpriteId = FieldEffectStart(FLDEFF_CAVE_DUST); //Default in caves is dust
                    }
                    else
                    {
                        if (MetatileBehavior_IsTallGrass(metatileBehaviour)) //Regular grass
                            fldeffSpriteId = FieldEffectStart(FLDEFF_SHAKING_GRASS);
                        else if (MetatileBehavior_IsLongGrass(metatileBehaviour)) //Really tall grass
                            fldeffSpriteId = FieldEffectStart(FLDEFF_SHAKING_LONG_GRASS);
                        else if (MetatileBehavior_IsSandOrDeepSand(metatileBehaviour)) //Desert Sand
                            fldeffSpriteId = FieldEffectStart(FLDEFF_SAND_HOLE);
                        else if (MetatileBehavior_IsMountain(metatileBehaviour)) //Rough Terrain
                            fldeffSpriteId = FieldEffectStart(FLDEFF_CAVE_DUST);
                        else //Flowers, etc.
                            fldeffSpriteId = FieldEffectStart(FLDEFF_REPEATING_SPARKLES); //Default on land is sparkles
                    }
                    break;
                }
            case ENCOUNTER_TYPE_WATER:
                //if (IsCurrentAreaVolcano())
                //    FieldEffectStart(FLDEFF_LAVA_BUBBLES);
                //else
                //    FieldEffectStart(FLDEFF_WATER_SURFACING);
                fldeffSpriteId = FieldEffectStart(FLDEFF_WATER_SURFACING);
                break;
            default:
                fldeffSpriteId = FieldEffectStart(FLDEFF_REPEATING_SPARKLES); //So the game doesn't crash on something useless
                break;
        }

        /*//Get shaking grass spriteId
        for (i = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].callback == WaitFieldEffectSpriteAnim)
            {
                sDexnavSearchDataPtr->fldEffSpriteId = i;
                return TRUE;
            }
        }*/
        
        sDexnavSearchDataPtr->fldEffSpriteId = fldeffSpriteId; 
        return TRUE;
    }

    return FALSE;
}

#define tProximity          data[0]
void InitDexnavSearch(void)
{
    u16 species = gSpecialVar_0x8000;
    u8 environment = gSpecialVar_0x8001;
    u8 searchLevel;
    u8 taskId;
    
    sDexnavSearchDataPtr = AllocZeroed(sizeof(struct DexnavSearch));
    // assign non-objects to struct
    sDexnavSearchDataPtr->species = species;

    /*if (IS_NEWER_UNOWN_LETTER(species))
    {
        sDexnavSearchDataPtr->unownLetter = species - SPECIES_UNOWN_B + 2; //Because B is 1
        sDexnavSearchDataPtr->species = species = SPECIES_UNOWN;
    }
    else //UNOWN A
    {
        sDexnavSearchDataPtr->unownLetter = 1;
    }*/
    
    sDexnavSearchDataPtr->environment = environment;
    searchLevel = 10;   //sDexNavSearchLevels[SpeciesToNationalPokedexNum(species)];
    sDexnavSearchDataPtr->searchLevel = searchLevel;
    sDexnavSearchDataPtr->monLevel = 10;   //to do: DexNavGenerateMonLevel(species, searchLevel, environment);
    
    //DexNavGenerateMoveset(species, searchLevel, sDexnavSearchDataPtr->monLevel, &sDexnavSearchDataPtr->moveId[0]);
    sDexnavSearchDataPtr->heldItem = 0; //DexNavGenerateHeldItem(species, searchLevel);
    sDexnavSearchDataPtr->abilityNum = 0;   //DexNavGenerateHiddenAbility(species, searchLevel);
    sDexnavSearchDataPtr->potential = DexNavGeneratePotential(searchLevel);
    DexNavProximityUpdate();
    
    FlagSet(FLAG_SYS_DEXNAV_ACTIVE);
    taskId = CreateTask(Task_DexNavSearch, 0x1);
    
    // draw shaking grass
    /*gFieldEffectArguments[0] = gSaveBlock1Ptr->pos.x + 7;   //test
    gFieldEffectArguments[1] = gSaveBlock1Ptr->pos.y + 7 + 1;   //test
    gFieldEffectArguments[2] = 0xFF; // height.
    gTasks[taskId].tFieldEffSprite = FieldEffectStart(FLDEFF_SHAKING_GRASS);*/
    if (!ShakingGrass(environment, 12, 12, 0))
    {
        Free(sDexnavSearchDataPtr);
        ShowFieldMessage(sText_NotFoundNearby);
        DestroyTask(taskId);
        return;
    }
    
    DrawHeaderBox();
    gTasks[taskId].tProximity = gSprites[gPlayerAvatar.spriteId].pos1.x;
}






static void Task_EndDexnavSearch(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    
    DestroyTask(taskId);
    RemoveHeaderBox();
    FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_SHAKING_GRASS);
}


#include "script_pokemon_util.h"
static void Task_DexNavSearch(u8 taskId)
{
    u16 dexNum;
    s16 x, y;
    struct Task *task = &gTasks[taskId];
    
    /*// check for out of range
    if (sDexnavSearchDataPtr->proximity > MAX_PROXIMITY)
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        DexNavShowMessage(1);    //there is no reaction!\nThe signal was lost!
        return;
    }

    // check for timeout.
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] > DEXNAV_TIMEOUT * 60)
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        DexNavShowMessage(0);    //The pokemon got away!
        return;
    }

    if (sDexnavSearchDataPtr->proximity <= SNEAKING_PROXIMITY && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_BIKE)) //If player is close and running then the Pokemon should flee
    {
        DestroyTask(taskId);
        DexNavFreeHUD();
        DexNavShowMessage(2);    //The pokemon got away!\nTry moving more slowly.
        return;
    }*/

    // check if script just executed
    if (ScriptContext2_IsEnabled() == TRUE)
    {
        task->func = Task_EndDexnavSearch;
        //DestroyTask(taskId);
        //DexNavFreeHUD();
        return;
    }

    if (JOY_NEW(B_BUTTON | START_BUTTON))
    {
        //DestroyTask(taskId);
        //DexNavFreeHUD();
        task->func = Task_EndDexnavSearch;
        PlaySE(SE_POKENAV_OFF);
        return;
    }
    
    // to do: proximity check
    //if ((gSaveBlock1Ptr->pos.x) == 5 && (gSaveBlock1Ptr->pos.y) == 12)  //PURELY FOR TESTING YES I KNOW IT IS BAD 
    if (sDexnavSearchDataPtr->proximity < 1)
    {
        CreateScriptedWildMon(SPECIES_MUDKIP, 5, 0);
        ScriptContext1_SetupScript(EventScript_StartDexNavBattle);
        //task->func = Task_EndDexnavSearch;
        DestroyTask(taskId);
        return;
    }

    /*//Caves and water the pokemon moves around
    if ((sDexnavSearchDataPtr->environment == ENCOUNTER_TYPE_WATER || !IsMapTypeOutdoors(GetCurrentMapType())) && sDexnavSearchDataPtr->proximity < 2 && sDexnavSearchDataPtr->movementTimes < 2)
    {
        switch(sDexnavSearchDataPtr->environment)
        {
            case ENCOUNTER_TYPE_LAND:
                FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_CAVE_DUST);
                break;
            case ENCOUNTER_TYPE_WATER:
                FieldEffectStop(&gSprites[sDexnavSearchDataPtr->fldEffSpriteId], FLDEFF_WATER_SURFACING);
                break;
            default:
                break;
        }
        
        while(!ShakingGrass(sDexnavSearchDataPtr->environment, 8, 8, 1))
            __asm__("mov r8, r8");

        sDexnavSearchDataPtr->movementTimes++;
    }

    // check for encounter start
    if (sDexnavSearchDataPtr-> proximity < 1)
    {
        DexNavGetMon(sDexnavSearchDataPtr->species, sDexnavSearchDataPtr->potential, sDexnavSearchDataPtr->monLevel,
        sDexnavSearchDataPtr->abilityNum, sDexnavSearchDataPtr->moveId);
        DestroyTask(taskId);

        // increment the search level
        dexNum = SpeciesToNationalPokedexNum(sDexnavSearchDataPtr->species);
        if (sDexNavSearchLevels[dexNum] < 100)
            sDexNavSearchLevels[dexNum]++;

        // Freeing only the state, objects and hblank cleared on battle start.
        Free(sDexnavSearchDataPtr);

        ScriptContext1_SetupScript(EventScript_StartDexNavBattle);
        
        // exclamation point animation over the player
        //PlaySE(SE_PIN);
        //MovementAction_EmoteExclamationMark_Step0(&gObjectEvents[EVENT_OBJ_ID_PLAYER], &gSprites[gPlayerAvatar.spriteId]);
        //FieldEffectStart();

        // do battle
        //DoStandardWildBattle();
    }
    */

    DexNavProximityUpdate();
    if (task->tProximity != sDexnavSearchDataPtr->proximity)
    {
        //to do: DexNavIconsVisionUpdate(sDexnavSearchDataPtr->proximity, sDexnavSearchDataPtr->searchLevel);
        task->tProximity = sDexnavSearchDataPtr->proximity;
    }
    
    
}




///////////////////////////////
///// WILD MON SEARCH DATA ////
///////////////////////////////
static u8 DexNavGeneratePotential(u8 searchLevel)
{
    u8 genChance = 0;
    int randVal = Random() % 100;
    
    if (searchLevel < 5)
    {
        genChance = SEARCHLEVEL0_ONESTAR + SEARCHLEVEL0_TWOSTAR + SEARCHLEVEL0_THREESTAR;
        if (randVal < genChance)
        {
            // figure out which star it is
            if (randVal < SEARCHLEVEL0_ONESTAR)
                return 1;
            else if (randVal < (SEARCHLEVEL0_ONESTAR + SEARCHLEVEL0_TWOSTAR))
                return 2;
            else
                return 3;
        }
    }
    else if (searchLevel < 10)
    {
        genChance = SEARCHLEVEL5_ONESTAR + SEARCHLEVEL5_TWOSTAR + SEARCHLEVEL5_THREESTAR;
        if (randVal < genChance)
        {
            // figure out which star it is
            if (randVal < SEARCHLEVEL5_ONESTAR)
                return 1;
            else if (randVal < (SEARCHLEVEL5_ONESTAR + SEARCHLEVEL5_TWOSTAR))
                return 2;
            else
                return 3;
        }
    }
    else if (searchLevel < 25)
    {
        genChance = SEARCHLEVEL10_ONESTAR + SEARCHLEVEL10_TWOSTAR + SEARCHLEVEL10_THREESTAR;
        if (randVal < genChance)
        {
            // figure out which star it is
            if (randVal < SEARCHLEVEL10_ONESTAR)
                return 1;
            else if (randVal < (SEARCHLEVEL10_ONESTAR + SEARCHLEVEL10_TWOSTAR))
                return 2;
            else
                return 3;
        }
    }
    else if (searchLevel < 50)
    {
        genChance = SEARCHLEVEL25_ONESTAR + SEARCHLEVEL25_TWOSTAR + SEARCHLEVEL25_THREESTAR;
        if (randVal < genChance)
        {
            // figure out which star it is
            if (randVal < SEARCHLEVEL25_ONESTAR)
                return 1;
            else if (randVal < (SEARCHLEVEL25_ONESTAR + SEARCHLEVEL25_TWOSTAR))
                return 2;
            else
                return 3;
        }
    }
    else if (searchLevel < 100)
    {
        genChance = SEARCHLEVEL50_ONESTAR + SEARCHLEVEL50_TWOSTAR + SEARCHLEVEL50_THREESTAR;
        if (randVal < genChance)
        {
            // figure out which star it is
            if (randVal < SEARCHLEVEL50_ONESTAR)
                return 1;
            else if (randVal < (SEARCHLEVEL50_ONESTAR + SEARCHLEVEL50_TWOSTAR))
                return 2;
            else
                return 3;
        }
    }
    else
    {
        genChance = SEARCHLEVEL100_ONESTAR + SEARCHLEVEL100_TWOSTAR + SEARCHLEVEL100_THREESTAR;
        if (randVal < genChance)
        {
            // figure out which star it is
            if (randVal < SEARCHLEVEL100_ONESTAR)
                return 1;
            else if (randVal < (SEARCHLEVEL100_ONESTAR + SEARCHLEVEL100_TWOSTAR))
                return 2;
            else
                return 3;
        }
    }
    
    return 0;   // No potential
}



