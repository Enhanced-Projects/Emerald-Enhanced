#include "global.h"
#include "dexnav.h"
#include "pokemon.h"
#include "sprite.h"
#include "event_data.h"
#include "window.h"
#include "bg.h"
#include "text.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "palette.h"
#include "random.h"
#include "main.h"
#include "overworld.h"
#include "task.h"
#include "malloc.h"
#include "fieldmap.h"
#include "pokemon_icon.h"
#include "gpu_regs.h"
#include "string_util.h"
#include "field_player_avatar.h"
#include "script.h"
#include "battle_main.h"
#include "wild_encounter.h"
#include "metatile_behavior.h"
#include "daycare.h"
#include "constants/map_types.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/field_effects.h"
#include "constants/items.h"

// Defines
#define IS_NEWER_UNOWN_LETTER(species) (species >= SPECIES_UNOWN_B && species <= SPECIES_UNOWN_QUESTION)

// RAM
EWRAM_DATA static u8 sDexNavSearchLevels[NUM_SPECIES] = {0};    // to be moved to saveblock!!!!
EWRAM_DATA static struct DexnavHudData *sDNavState = {NULL};  //#define sDNavState (*((struct DexnavHudData**) 0x203E038))

//// Const Data
extern const struct OamData gEventObjectBaseOam_16x16;
extern const struct SpriteSheet sSpriteSheet_HeldItem;
extern const struct SpritePalette sSpritePalette_HeldItem;
extern const union AnimCmd *const gFieldEffectObjectImageAnimTable_Ripple[];
extern const union AnimCmd *const gFieldEffectObjectImageAnimTable_Unknown20[];

// image data
static const u32 sDexnavBarTiles[] = INCBIN_U32("graphics/dexnav/bar.4bpp.lz");
static const u32 sDexnavBarPal[] = INCBIN_U32("graphics/dexnav/bar.gbapal.lz");

static const u32 sDexnavGuiTiles[] = INCBIN_U32("graphics/dexnav/dexnav_gui_tiles.4bpp.lz");
static const u32 sDexnavGuiTilemap[] = INCBIN_U32("graphics/dexnav/dexnav_gui_tilemap.bin.lz");
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

static const u8 sDexnavStarsTiles[] = INCBIN_U8("graphics/dexnav/stars.4bpp");
static const u8 sDexnavStarsPal[] = INCBIN_U8("graphics/dexnav/stars.gbapal");

static const u8 gInterfaceGfx_selectionCursorTiles[] = INCBIN_U8("graphics/dexnav/cursor.4bpp");
static const u8 gInterfaceGfx_selectionCursorPal[] = INCBIN_U8("graphics/dexnav/cursor.gbapal");

static const u8 gInterfaceGfx_emptyTiles[] = INCBIN_U8("graphics/dexnav/empty.4bpp.lz");
static const u8 gInterfaceGfx_emptyPal[] = INCBIN_U8("graphics/dexnav/empty.gbapal");

static const u32 gInterfaceGfx_CapturedAllPokemonTiles[] = INCBIN_U32("graphics/dexnav/captured_all.4bpp.lz");
static const u32 gInterfaceGfx_CapturedAllPokemonPal[] = INCBIN_U32("graphics/dexnav/captured_all.gbapal.lz");

static const u8 gInterfaceGfx_caveSmokeTiles[] = INCBIN_U8("graphics/dexnav/cave_smoke.4bpp");
static const u8 gInterfaceGfx_caveSmokePal[] = INCBIN_U8("graphics/dexnav/cave_smoke.gbapal");

static const u8 gInterfaceGfx_SparklesTiles[] = INCBIN_U8("graphics/dexnav/sparkles.4bpp");
static const u8 gInterfaceGfx_SparklesPal[] = INCBIN_U8("graphics/dexnav/sparkles.gbapal");

static const u8 gInterfaceGfx_LavaBubblesTiles[] = INCBIN_U8("graphics/dexnav/lava_bubbles.4bpp");
static const u8 gInterfaceGfx_LavaBubblesPal[] = INCBIN_U8("graphics/dexnav/lava_bubbles.gbapal");

static const u32 sDexNavNoDataSymbolTiles[] = INCBIN_U32("graphics/dexnav/no_data.4bpp.lz");

// strings
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

static const struct BgTemplate BgConfigDexNavGUI[4] =
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
    },
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

enum
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

    [WINDOW_COUNT] =
    {
        .bg = 0xFF, // marks the end of the tb array
    },
};


//const struct Frame (**nullframe)[] = (const struct Frame (**)[])0x8231CF0;
//const struct AffineAnimCmd (**nullrsf)[] = (const struct AffineAnimCmd (**)[])0x8231CFC;

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

static const struct SpriteTemplate BulbTemp =
{
    .tileTag = 0x3139,
    .paletteTag = 0x3139,
    .oam = &PIconOAM,
    .anims =  gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 MenuTextBlack[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};
static const u8 DexNav_BlackText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};
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
    .paletteTag = 0x8472,
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

static const struct SpriteTemplate sSpriteTemplateLavaBubbles =
{
    .tileTag = 0xFFFF,
    .paletteTag = SMOKE_TAG,
    .oam = &gEventObjectBaseOam_16x16,
    .anims = gFieldEffectObjectImageAnimTable_Ripple,
    .images = sFieldEffectObjectPicTable_LavaBubbles,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpritePalette sLavaBubblesPalTemplate =
{
    .data = gInterfaceGfx_LavaBubblesPal,
    .tag = SMOKE_TAG,
};

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

static struct CompressedSpriteSheet sIconTiles = 
{
    .data = sDexNavNoDataSymbolTiles,
    .size = 32 * 32,
    .tag = ICON_GFX_TAG
};

/*
static const struct SpriteSheet sCaveGfx[4] =
{
    {
        .data = (const u8*)gInterfaceGfx_caveSmokeTiles[128 * 0],
        .size = 0x80,
        .tag = 0xFFFF,
    },
    {
        .data = (const u8*)gInterfaceGfx_caveSmokeTiles[128 * 1],
        .size = 0x80,
        .tag = 0xFFFF,
    },
    {
        .data = (const u8*)gInterfaceGfx_caveSmokeTiles[128 * 2],
        .size = 0x80,
        .tag = 0xFFFF,
    },
    {
        .data = (const u8*)gInterfaceGfx_caveSmokeTiles[128 * 3],
        .size = 0x80,
        .tag = 0xFFFF,
    },
};
*/
static const struct SpriteSheet sCaveGfx[] =
{
    {
        .data = gInterfaceGfx_caveSmokeTiles,
        .size = 0x80 * 4,
        .tag = 0xFFFF,
    },
};

static const struct SpriteTemplate ObjtCave =
{
    .tileTag = 0xFFFF,
    .paletteTag = SMOKE_TAG,
    .oam = &gEventObjectBaseOam_16x16,
    .anims = gFieldEffectObjectImageAnimTable_Unknown20,        //gFieldEffectObjectImageAnimTable_Unknown ????
    .images = sCaveGfx,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = WaitFieldEffectSpriteAnim,
};

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
    .oam = &gEventObjectBaseOam_16x16,
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

// create empty object of size 64x32 to draw icons on
static const struct CompressedSpriteSheet sightTiles = {(const u8*)(&gInterfaceGfx_emptyTiles), 0x800, 0x5424};
static const struct SpriteTemplate fontTempSight =
{
    .tileTag = 0x5424,
    .paletteTag = 0x8472,
    .oam = FontOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// create empty object of size 64x32 to draw font on
static const struct CompressedSpriteSheet FontSpriteAbility = {gInterfaceGfx_emptyTiles, 0x800, 0x1EE7}
static const struct SpriteTemplate FontTempAbility =
{
    .tileTag = 0x1EE7,
    .paletteTag = 0x8472,
    .oam = FontOAM,
    .anims = gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// create empty object of size 64x32 to draw font on
static const struct CompressedSpriteSheet FontSpriteMove = {gInterfaceGfx_emptyTiles, 0x800, 0x4736};
static const struct SpriteTemplate FontTempMove =
{
    .tileTag = 0x4736,
    .paletteTag = 0x8472,
    .oam = FontOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

//19 tiles per row, stars are on the 4th row. 1 tile is 32 bytes. Hence 19 * 4 *32
static const struct SpriteSheet StarIconLit = 
{
    .data = &sDexnavStarsTiles[19 * 4 * 32],
    .size = 64,
    .tag = 0x61
};

static const struct SpriteSheet StarIconOff = 
{
    .data = sDexnavStarsTiles[((19 * 4) + 1) * 32],
    .size = 64,
    .tag = 0x2613
};

static const struct SpriteTemplate StarLitTemp =
{
    .tileTag = 0x61,
    .paletteTag = 0x8472,
    .oam = HeldOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate StarOffTemp =
{
    .tileTag = 0x2613,
    .paletteTag = 0x8472,
    .oam = HeldOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate HeldTemp =
{
    .tileTag = 0x8472,
    .paletteTag = 0x8472,
    .oam = HeldOAM,
    .anims =  gDummySpriteAnimTable,
    .images = 0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet CursorGFX = {gInterfaceGfx_selectionCursorTiles, 32 * 32, SELECTION_CURSOR_TAG};
static const struct SpritePalette CursorPal = {gInterfaceGfx_selectionCursorPal, SELECTION_CURSOR_TAG};
static const struct SpriteTemplate CursorTemp =
{
    .tileTag = SELECTION_CURSOR_TAG,
    .paletteTag = SELECTION_CURSOR_TAG,
    .oam = CursorOAM,
    .anims =  gDummySpriteAnimTable,
    .images = CursorGFX,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct FieldEffectScript FieldEffectScript_CaveDust[] =
{
    FLDEFF_CALLASM, FieldEff_CaveDust,
    FLDEFF_END,
};

static const struct FieldEffectScript FieldEffectScript_Sparkles[] =
{
    FLDEFF_CALLASM, FieldEff_Sparkles,
    FLDEFF_END,
};

static const struct FieldEffectScript FieldEffectScript_LavaBubbles[] =
{
    FLDEFF_CALLASM, FieldEff_LavaBubbles,
    FLDEFF_END,
};

// Function Declarations
static void DestroyTaskCompletedTextbox(u8 tId);
static void MsgNormal(const u8* str);
static void VblackCallbackSeq(void);
static void ClearHandlers(void);
static void DexNavGUICallback2(void);
static void ResetPalSettings(void);
static void ResetBgSettings(void);
static void Setup(void);
static bool8 SpeciesInArray(u16 species, u8 indexCount, u8 unownLetter);
static void DexNavGetMon(u16 species, u8 potential, u8 level, u8 abilityNum, u16* moves);
static u8 FindHeaderIndexWithLetter(u16 species, u8 letter);
static u8 GetPlayerDistance(s16 x, s16 y);
static u8 PickTileScreen(u8 targetBehaviour, u8 areaX, u8 areaY, s16 *xBuff, s16 *yBuff, u8 smallScan);
static u8 DexNavPickTile(u8 environment, u8 xSize, u8 ySize, bool8 smallScan);
static u8 ShakingGrass(u8 environment, u8 xSize, u8 ySize, bool8 smallScan);
static void DexNavProximityUpdate(void);
static void NullSubHBlank(void);
static void DexNavFreeHUD(void);
static void DexNavShowMessage(u8 id);
static void OutlinedFontDraw(u8 objId, u8 tileNum, u16 size);
static void DexNavSightUpdate(u8 sight);
static void DexNavIconsVisionUpdate(u8 proximity, u8 searchLevel);
static void DexNavManageHUD(u8 taskId);
static u8 GetEncounterLevel(u16 species, u8 environment);
static u8 DexNavGenerateMonLevel(u16 species, u8 searchLevel, u8 environment);
static u16 DexNavGenerateHeldItem(u16 species, u8 searchLevel);
static u8 DexNavGenerateHiddenAbility(u16 species, u8 searchLevel);
static u8 DexNavGeneratePotential(u8 searchLevel);
static void DexNavGenerateMoveset(u16 species, u8 searchLevel, u8 encounterLevel, u16* moveLoc);
static void DexNavDrawBlackBars(u8* objidAddr);
static void DexNavDrawSight(u8 sight_lvl, u8* objidAddr);
static void DexNavDrawAbility(u8 ability, u8* objidAddr);
static void DexNavDrawMove(u16 move, u8 searchLevel, u8* objidAddr);
static void DexNavDrawPotential(u8 potential, u8* objidAddr);
static void DexNavHudDrawSpeciesIcon(u16 species, u8* objIdAddr);
static void DexNavDrawHeldItem(u8* objidAddr);
static void DexNavDrawIcons(void);
static void ExecDexNavHUD(void);
static void DexNavGuiSetup(void);
static void DexNavLoadPokeIcons(void);
static void CreateNoDataIcon(s16 x, s16 y);
static void UpdateCursorPosition(void);
static void SpawnPointerArrow(void);
static void DexNavLoadAreaNames(void);
static void DexNavLoadNames(u8 status);
static void DexNavLoadCapturedAllSymbol(void);
static void CallbackDexNavOW(void);
static void DexNavGuiExitSearch(void);
static void DexNavGuiExitNoSearch(void);
static void DexNavPopulateEncounterList(void);
static void DexNavGuiHandler(void);
static void PrintDexNavError(void);
static void FieldEff_CaveDust(void);
static void FieldEff_Sparkles(void);
static bool8 InTanobyRuins(void);

//// Functions
static void DestroyTaskCompletedTextbox(u8 tId)
{
    if (*gBoxStatusAndType != 1)
    {
        HideFieldMessageBox();
        DestroyTask(tId);
        ScriptContext2_Disable();
    }
}

static void MsgNormal(const u8* str)
{
   TextboxFdecodeAutoAndCreateTask(str);
   *gBoxStatusAndType = 1;
   SetTextboxSignpostDesign();
   CreateTask(DestroyTaskCompletedTextbox, 0x1);
   ScriptContext2_Enable();
   return;
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

static void ClearHandlers(void)
{
    SetVBlankCallback((void*) 0);
    SetHBlankCallback((void*) 0);
    SetMainCallback1((void*) 0);
    SetMainCallback2((void*) 0);
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
    FadeBgPalAndFillBlack();
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
    ClearHandlers();    // callbacks
    ResetBgSettings();    // BGs
    ResetPalSettings();    // pals
    ResetSpriteData();    // objs
    FreeSpriteTileRanges();
    u32 set = 0;
    CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET));     // VRAM clear
    InitHeap((void*) 0x2000000, 0x1C000);
    ResetTasks();
}

static bool8 SpeciesInArray(u16 species, u8 indexCount, u8 unownLetter)
{
    u16 dexNum = SpeciesToNationalPokedexNum(species);

    //Disallow species not seen
    if (!GetSetPokedexFlag(dexNum, FLAG_GET_SEEN))
    {
        for (int i = 0; i < NUM_LAND_MONS; ++i)
        {
            if (species == SPECIES_UNOWN && InTanobyRuins())
            {
                if (sDNavState->unownForms[i] == unownLetter) //Already in array
                    return TRUE;
            }
            else if (sDNavState->hiddenSpecies[i] == SPECIES_TABLES_TERMIN)
            {
                sDNavState->hiddenSpecies[i] = dexNum;
                sDNavState->hiddenSpecies[i + 1] = SPECIES_TABLES_TERMIN;
                break;
            }
            else if (sDNavState->hiddenSpecies[i] == dexNum) //Already in array
            {
                return TRUE;
            }
        }

        if (indexCount == NUM_LAND_MONS)
            sDNavState->numHiddenLandMons++; //Increase how many question marks to print
        else
            sDNavState->numHiddenWaterMons++;

        return TRUE;
    }

    for (u8 i = 0; i < indexCount; ++i)
    {
        if (indexCount == NUM_LAND_MONS)
        {
            if (species == SPECIES_UNOWN && InTanobyRuins()) //This Unown code is copied from above b/c either
            {                                                 //all Unown are seen, or none at all
                if (sDNavState->unownForms[i] == unownLetter) //Already in array
                    return TRUE;
            }
            else if (SpeciesToNationalPokedexNum(sDNavState->grassSpecies[i]) == dexNum)
            {
                return TRUE;
            }
        }
        else
        {
            if (SpeciesToNationalPokedexNum(sDNavState->waterSpecies[i]) == dexNum)
                return TRUE;
        }
    }

    return FALSE;
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
    CreateWildMon(species, level, FindHeaderIndexWithLetter(species, sDNavState->unownLetter - 1), TRUE);

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
    for (i = 0; i < MAX_MON_MOVES; ++i)
    {
        gSpecialVar_0x8006 = sDNavState->moveId[i];
        mon->moves[i] = gSpecialVar_0x8006;
        mon->pp[i] = gBattleMoves[moves[i]].pp;
    }

    CalculateMonStats(mon);
}


static u8 FindHeaderIndexWithLetter(u16 species, u8 letter)
{
    u8 i;
    
    if (!InTanobyRuins())
        return 0;

    for (i = 0; i < NUM_LAND_MONS; ++i)
    {
        if (PickUnownLetter(species, i) == letter + 1)
            return i;
    }

    return 0;
}

// ===== Pokemon Field Tile ===== //
static u8 GetPlayerDistance(s16 x, s16 y)
{
    u16 deltaX = abs(x - (gSaveBlock1->pos.x + 7));
    u16 deltaY = abs(y - (gSaveBlock1->pos.y + 7));
    return deltaX + deltaY;
}

static bool8 PickTileScreen(u8 targetBehaviour, u8 areaX, u8 areaY, s16 *xBuff, s16 *yBuff, u8 smallScan)
{
    // area of map to cover starting from camera position {-7, -7}
    s16 topX = gSaveBlock1->pos.x - SCANSTART_X + (smallScan * 5);
    s16 topY = gSaveBlock1->pos.y - SCANSTART_Y + (smallScan * 5);
    s16 botX = topX + areaX;
    s16 botY = topY + areaY;

    // loop through every tile in area and evaluate
    while (topY < botY)
    {
        while (topX < botX)
        {
            u32 tileBehaviour = MapGridGetMetatileField(topX, topY, 0xFF);
            u8 blockProperties = MetatileBehavior_GetLowerBytes(tileBehaviour, 4);

            gSpecialVar_0x8005 = tileBehaviour;    //020370c2

            //Check NPCs on tile
            bool8 goNext = FALSE;
            for (u8 i = 0; i < MAX_NPCS; ++i)
            {
                if (gEventObjects[i].currentCoords.x == topX && gEventObjects[i].currentCoords.y == topY)
                {
                    goNext = TRUE;
                    break;
                }
            }
            if (goNext)
            {
                topX += 1;
                continue;
            }

            //Tile must be target behaviour (wild tile) and must be passable
            if (blockProperties & targetBehaviour)
            {
                //Caves and water need to have their encounter values scaled higher
                u8 weight = 0;
                if (targetBehaviour == TILE_FLAG_SURFABLE)
                {
                    //Water
                    u8 scale = 320 - (smallScan * 200) - (GetPlayerDistance(topX, topY) / 2);
                    u8 elevDiff = (IsZCoordMismatchAt((gEventObjects[gPlayerAvatar->spriteId].elevation << 4
                        | gEventObjects[gPlayerAvatar->spriteId].currentElevation), topX, topY));

                    weight = (Random() % scale <= 1) && elevDiff && !MapGridIsImpassableAt(topX, topY);
                }
                else if (!IsMapTypeOutdoors(GetCurrentMapType()))
                {
                    //Cave basically needs another check to see if the tile is passable
                    u8 scale = 440 - (smallScan * 200) - (GetPlayerDistance(topX, topY) / 2)  - (2 * (topX + topY));
                    gSpecialVar_0x8002 = scale;
                    weight = ((Random() % scale) < 1) && !MapGridIsImpassableAt(topX, topY);
                }
                else //Grass land
                {
                    u8 scale = 100 - (GetPlayerDistance(topX, topY) * 2);
                    weight = (Random() % scale <= 5) && !MapGridIsImpassableAt(topX, topY);
                }

                if (weight > 0)
                {
                    *xBuff = topX;
                    *yBuff = topY;
                    return TRUE;
                }
            }
            topX += 1;
        }
        topY += 1;
        topX = gSaveBlock1->pos.x - SCANSTART_X + (smallScan * 5);
    }

    return FALSE;
}


static bool8 DexNavPickTile(u8 environment, u8 xSize, u8 ySize, bool8 smallScan)
{
    //Pick a specific tile based on environment
    u8 targetBehaviour = 0;
    switch (environment)
    {
        case ENCOUNTER_TYPE_LAND:
            targetBehaviour = TILE_FLAG_ENCOUNTER_TILE; // grass
            break;
        default:
            targetBehaviour = TILE_FLAG_SURFABLE; // cave, water
            break;
    }
    //Tile pick chance is 5% + 1/5 search level

    //u8 searchLevel = sDNavState->searchLevel / 5;
    //u8 chance = searchLevel + 1;
    return PickTileScreen(targetBehaviour, xSize, ySize, &(sDNavState->tileX), &(sDNavState->tileY), smallScan);
}


static bool8 ShakingGrass(u8 environment, u8 xSize, u8 ySize, bool8 smallScan)
{
    if (DexNavPickTile(environment, xSize, ySize, smallScan))
    {
        u8 metatileBehaviour = MapGridGetMetatileField(sDNavState->tileX, sDNavState->tileY, 0xFF);
        gFieldEffectArguments[0] = sDNavState->tileX;
        gFieldEffectArguments[1] = sDNavState->tileY;
        gFieldEffectArguments[2] = 0xFF; // height.
        switch (environment)
        {
            case ENCOUNTER_TYPE_LAND:
                {
                    if (!IsMapTypeOutdoors(GetCurrentMapType()))
                    {
                        if (MetatileBehavior_IsTallGrass(metatileBehaviour)) //Grass in cave
                            FieldEffectStart(FLDEFF_SHAKING_GRASS);
                        else if (MetatileBehavior_IsLongGrass(metatileBehaviour)) //Really tall grass
                            FieldEffectStart(FLDEFF_SHAKING_LONG_GRASS);
                        else if (MetatileBehavior_IsSandOrDeepSand(metatileBehaviour))
                            FieldEffectStart(FLDEFF_SAND_HOLE);
                        else
                            FieldEffectStart(FLDEFF_CAVE_DUST); //Default in caves is dust
                    }
                    else
                    {
                        if (MetatileBehavior_IsTallGrass(metatileBehaviour)) //Regular grass
                            FieldEffectStart(FLDEFF_SHAKING_GRASS);
                        else if (MetatileBehavior_IsLongGrass(metatileBehaviour)) //Really tall grass
                            FieldEffectStart(FLDEFF_SHAKING_LONG_GRASS);
                        else if (MetatileBehavior_IsSandOrDeepSand(metatileBehaviour)) //Desert Sand
                            FieldEffectStart(FLDEFF_SAND_HOLE);
                        else if (MetatileBehavior_IsMountain(metatileBehaviour)) //Rough Terrain
                            FieldEffectStart(FLDEFF_CAVE_DUST);
                        else //Flowers, etc.
                            FieldEffectStart(FLDEFF_REPEATING_SPARKLES); //Default on land is sparkles
                    }
                    break;
                }
            case ENCOUNTER_TYPE_WATER:
                if (IsCurrentAreaVolcano())
                    FieldEffectStart(FLDEFF_LAVA_BUBBLES);
                else
                    FieldEffectStart(FLDEFF_SPLASHING_WATER);
                break;
            default:
                FieldEffectStart(FLDEFF_REPEATING_SPARKLES); //So the game doesn't crash on something useless
                break;
        }

        //Get objid of shaking grass
        for (u32 i = 0; i < MAX_SPRITES; ++i)
        {
            if (gSprites[i].callback == 0x080DCD1D)
            {
                sDNavState->objIdShakingGrass = i;
                return TRUE;
            }
        }

        return TRUE;
    }

    return FALSE;
}

/* //Causes the game to lag due to interference from DNS :(
static void DexHUDHBlank(void)
{
    if (REG_VCOUNT > (160 - 19)) //Fill 19 pixels
    {
        REG_BLDY = 0xC;
        REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ | WIN_BLD,  WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ | WIN_BLD);
        REG_BLDCNT = (BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_DARKEN);
    }
    else //Default values from overworld
    {
        REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
        REG_BLDCNT = BLDALPHA_BLEND(BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ, 0);
    }
}
*/

static void DexNavProximityUpdate(void)
{
    sDNavState->proximity = GetPlayerDistance(sDNavState->tileX, sDNavState->tileY);
}


static void NullSubHBlank(void)
{
}


#define sSpriteTileAllocBitmap ((u8*) 0x2021B48)
#define FREE_SPRITE_TILE(n) (sSpriteTileAllocBitmap[(n) / 8] &= ~(1 << ((n) % 8)))

static void DexNavFreeHUD(void)
{
    switch (sDNavState->environment)
    {
        case 0:
            if (!IsMapTypeOutdoors(GetCurrentMapType()))
                FieldEffectStop(&gSprites[sDNavState->objIdShakingGrass], 0x1A); //cave
            else
                FieldEffectStop(&gSprites[sDNavState->objIdShakingGrass], 0x13);
            break;
        case 1:
            FieldEffectStop(&gSprites[sDNavState->objIdShakingGrass], 0x13);
            break;
    }

    //Clear mon icon sprite
    SafeFreeMonIconPalette(sDNavState->species);
    u16 tile = gSprites[sDNavState->objIdSpecies].oam.tileNum;
    u8* tiles = (u8*)((tile * TILE_SIZE_4BPP) + OBJ_VRAM0);
    Memset(tiles, 0, 0x200);

    for (int i = tile; i < tile + 16; ++i)
        FREE_SPRITE_TILE(i);

    ResetSprite(&gSprites[sDNavState->objIdSpecies]);

    //Clear black bars
    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdBlackBar[0]]);
    ResetSprite(&gSprites[sDNavState->objIdBlackBar[0]]);
    ResetSprite(&gSprites[sDNavState->objIdBlackBar[1]]);
    ResetSprite(&gSprites[sDNavState->objIdBlackBar[2]]);
    ResetSprite(&gSprites[sDNavState->objIdBlackBar[3]]);

    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdSight]);
    ResetSprite(&gSprites[sDNavState->objIdSight]);

    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdAbility]);
    ResetSprite(&gSprites[sDNavState->objIdAbility]);

    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdMove]);
    ResetSprite(&gSprites[sDNavState->objIdMove]);

    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdItem]);
    ResetSprite(&gSprites[sDNavState->objIdItem]);

    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdPotential[0]]);
    ResetSprite(&gSprites[sDNavState->objIdPotential[0]]);

    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdPotential[1]]);
    ResetSprite(&gSprites[sDNavState->objIdPotential[1]]);

    FieldEffectFreeGraphicsResources(&gSprites[sDNavState->objIdPotential[2]]);
    ResetSprite(&gSprites[sDNavState->objIdPotential[2]]);

    //FreeSpriteTilesByTag(0x4736);
    FreeSpriteTilesByTag(0x61);
    FreeSpriteTilesByTag(0x2613);
    FreeSpriteTilesByTag(0x5424);
    FreeSpriteTilesByTag(0x8472);
    FreeSpriteTilesByTag(0x1EE7); //Font Sprite
    FreeSpriteTilesByTag(0xFDF1); //Black Bars
    FreeSpriteTilesByTag(0x3039);
    FreeSpritePaletteByTag(0x8472);
    FreeSpritePaletteByTag(0x3039);

    ResetSprite(&gSprites[sDNavState->objIdMove]);

    Free(sDNavState);
    DisableInterrupts(2);
    SetHBlankCallback(NullSubHBlank);

/*
    // WRITE_REG_WININ(0x1F1F);
    REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 |
                            WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
    //WRITE_REG_BLDCNT(0x401E);
    REG_BLDCNT = BLDALPHA_BLEND(BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ, 0);


    // WRITE_REG_WININ(0x1F1F);
    REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 |
        WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
    //WRITE_REG_BLDCNT(0x401E);
    REG_BLDCNT = BLDALPHA_BLEND(BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ, 0);*/
}


static void DexNavShowMessage(u8 id)
{
    switch(id)
    {
        case 0:
            MsgNormal(sText_GotAway);
            break;
        case 1:
            MsgNormal(sText_LostSignal);
            break;
        case 2:
            MsgNormal(sText_GotAwayShouldSneak);
            break;
    }
    return;
}


static void OutlinedFontDraw(u8 objId, u8 tileNum, u16 size)
{
    //return;

    u8 tile = gSprites[objId].oam.tileNum + tileNum;
    u8* toWrite = (u8*)((tile * TILE_SIZE_4BPP) + OBJ_VRAM0);
    //u8* dst = (u8*)Malloc(size + TILE_SIZE_4BPP);
    //u8* dst = &gEnemyParty[0];

    u8* originalDst, *dst;
    originalDst = dst = Calloc(size + TILE_SIZE_4BPP);
    u8* strPtr = gStringVar4;

    u8 counter = 1;
    u16 index = 320;
    u16 prevIndex;

    //u8 element = *gStringVar4;

    u8 element = *strPtr;
    //u8 i = 0;

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
            }
            index = (symbolId + 9) * TILE_SIZE_4BPP;
        }

        // TODO: Use macros here //

        if ((counter == 0) || (*(strPtr + 1) == 0xFF))
        {
            // first or last pcharacters don't need pixel merging
            Memcpy(dst, &sDexnavStarsTiles[index], TILE_SIZE_4BPP);
        }
        else if ((element == 0x0))
        {
            Memcpy(dst, &sDexnavStarsTiles[index], TILE_SIZE_4BPP);
            u8 *prevLetter = (u8*)(&sDexnavStarsTiles[prevIndex]);
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
            Memcpy((void*)dst, &sDexnavStarsTiles[index], TILE_SIZE_4BPP);
            u8 *prevLetter = (u8*)(&sDexnavStarsTiles[prevIndex]);
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
        //gStringVar4++;
        //element = *gStringVar4;
        //i++;
        strPtr++;
        element = *strPtr;
    }

    Memcpy((void*) toWrite, originalDst, size);
    Free(originalDst);
}


static void DexNavSightUpdate(u8 sight)
{
    u8 objId = sDNavState->objIdSight;
    // draw sight eye on first tile, takes up two tiles
    u8 tileid = gSprites[objId].oam.tileNum;
    u8* toWrite = (u8*)((tileid * 32) + (OBJ_VRAM0));
    Memcpy(toWrite, &sDexnavStarsTiles[((19 * 4) + (7 - (2 * sight))) * 32], 64);

    // draw the B button tile
    Memcpy(toWrite + 128, &sDexnavStarsTiles[((19 * 4) + 2) *32], 64);

    // draw info text on the 5th tile
    //pchar back[] = _(" Back  ");
    StringCopy((u8*) gStringVar4, (u8*) &sText_DexNavBack[0]);
    OutlinedFontDraw(objId, 5, 32 * 8);
}


static void DexNavIconsVisionUpdate(u8 proximity, u8 searchLevel)
{
    // The sight eye and species icon are always drawn in the HUD
    //     At search level 2, first move is drawn
    //     At search level 3, Ability and Held item are drawn
    //     At search level 5, Potential is drawn

    // species and sight/info are always shown, regardless of proximity
    gSprites[sDNavState->objIdSpecies].oam.affineMode = 0;
    gSprites[sDNavState->objIdSight].oam.affineMode = 0;

    // hide everything at the start, and recalc what needs to be shown
    gSprites[sDNavState->objIdMove].oam.affineMode = 2;
    gSprites[sDNavState->objIdAbility].oam.affineMode = 2;
    gSprites[sDNavState->objIdItem].oam.affineMode = 2;
    gSprites[sDNavState->objIdPotential[0]].oam.affineMode = 2;
    gSprites[sDNavState->objIdPotential[1]].oam.affineMode = 2;
    gSprites[sDNavState->objIdPotential[2]].oam.affineMode = 2;

    if (proximity < 3)
    {
        // at proximity 5, the sight should start to show and indicate sneaking is required
        DexNavSightUpdate(0); // alert level TODO: Update in a better way utiliting sight_level
        if (searchLevel > 1)
        {
            // show move, hide others
            gSprites[sDNavState->objIdMove].oam.affineMode = 0;
        }
        if (searchLevel > 2)
        {
            // show ability, move, hide others
            gSprites[sDNavState->objIdAbility].oam.affineMode = 0;
            if (sDNavState->heldItem)
            {
                // toggle item view
                gSprites[sDNavState->objIdItem].oam.affineMode = 0;
            }
        }
        if (searchLevel > 4)
        {
            gSprites[sDNavState->objIdPotential[0]].oam.affineMode = 0;
            gSprites[sDNavState->objIdPotential[1]].oam.affineMode = 0;
            gSprites[sDNavState->objIdPotential[2]].oam.affineMode = 0;
        }

    }
    else if (proximity <= SNEAKING_PROXIMITY)
        DexNavSightUpdate(1); // Sneaking is required flag
    else
        DexNavSightUpdate(2); // Sneaking is not required
}

#define PLAYER_AVATAR_FLAG_BIKE PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE
static void DexNavManageHUD(u8 taskId)
{
    // check for out of range
    if (sDNavState->proximity > 20)
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

    if (sDNavState->proximity <= SNEAKING_PROXIMITY && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_BIKE)) //If player is close and running then the Pokemon should flee
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
    if ((sDNavState->environment == ENCOUNTER_TYPE_WATER || !IsMapTypeOutdoors(GetCurrentMapType()))
    && sDNavState->proximity < 2
    && sDNavState->movementTimes < 2)
    {
        switch(sDNavState->environment)
        {
            case ENCOUNTER_TYPE_LAND:
                FieldEffectStop(&gSprites[sDNavState->objIdShakingGrass], FLDEFF_CAVE_DUST); // 1a
                break;
            case ENCOUNTER_TYPE_WATER:
                FieldEffectStop(&gSprites[sDNavState->objIdShakingGrass], FLDEFF_SPLASHING_WATER);
                break;
            default:
                break;
        }


        while(!ShakingGrass(sDNavState->environment, 8, 8, 1))
            __asm__("mov r8, r8");

        sDNavState->movementTimes += 1;
    }

    // check for encounter start
    if (sDNavState-> proximity < 1)
    {
        DexNavGetMon(sDNavState->species, sDNavState->potential, sDNavState->pokemonLevel,
        sDNavState->abilityNum, sDNavState->moveId);
        DestroyTask(taskId);

        // increment the search level
        u16 dexNum = SpeciesToNationalPokedexNum(sDNavState->species);
        if (sDexNavSearchLevels[dexNum] < 100)
            sDexNavSearchLevels[dexNum] += 1;

        // Freeing only the state, objects and hblank cleared on battle start.
        Free(sDNavState);

        ScriptContext1_SetupScript(SystemScript_StartDexNavBattle);
/*
        // exclamation point animation over the player
        PlaySE(SE_EXCLAIM);
        MakeExclamationMark(gEventObjects, &gSprites[gPlayerAvatar->spriteId]);
        FieldEffectStart(0x0);

        // do battle
        DoStandardWildBattle();*/
    }

    // HUD needs updating iff player has moved
    DexNavProximityUpdate();
    if (!(gTasks[taskId].data[0] == sDNavState->proximity))
    {
        DexNavIconsVisionUpdate(sDNavState->proximity, sDNavState->searchLevel);
        gTasks[taskId].data[0] = sDNavState->proximity;
    }
}


// ===================================== //
// ================ HUD ================ //
// ===================================== //
static u8 GetEncounterLevel(u16 species, u8 environment)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

    u8 min = 100;
    u8 max = 0;

    switch (environment)
    {
        case 0:    // grass
            if (landMonsInfo == NULL)
                return 22; //Hidden pokemon should only appear on walkable tiles or surf tiles

            for (u8 i = 0; i < NUM_LAND_MONS; ++i)
            {
                struct WildPokemon monData = landMonsInfo->wildPokemon[i];
                if (monData.species == species)
                {
                    min = (min < monData.minLevel) ? min : monData.minLevel;
                    max = (max > monData.maxLevel) ? max : monData.maxLevel;
                }
            }
            break;

        case 1:    //water
            if (waterMonsInfo == NULL)
                return 22; //Hidden pokemon should only appear on walkable tiles or surf tiles

            for (u8 i = 0; i < NUM_WATER_MONS; ++i)
            {
                struct WildPokemon monData = waterMonsInfo->wildPokemon[i];
                if (monData.species == species)
                {
                    min = (min < monData.minLevel) ? min : monData.minLevel;
                    max = (max > monData.maxLevel) ? max : monData.maxLevel;
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
        sDNavState->ability = gBaseStats[species].abilityHidden;
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
        
        sDNavState->ability = gBaseStats[species].abilities[abilityNum];
        
        /*
        u8 ability;
        if (gBaseStats[species].ability2 != ABILITY_NONE)
            ability = (randVal & 1) == 0 ? gBaseStats[species].ability1 : gBaseStats[species].ability2;
        else
            ability = gBaseStats[species].ability1;

        return ability;
        */
    }
}

//#pragma GCC diagnostic ignored "-Wtype-limits"
static u8 DexNavGeneratePotential(u8 searchLevel)
{
    u8 genChance = 0;
    u16 randVal = Random() % 100;
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
    // No potential
    return 0;
}


static void DexNavGenerateMoveset(u16 species, u8 searchLevel, u8 encounterLevel, u16* moveLoc)
{
    bool8 genMove = FALSE;
    u16 randVal = Random() % 100;
    u16 i;

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
    CreateWildMon(species, encounterLevel, sDNavState->selectedIndex / 2, TRUE);


    //Store generated mon moves into Dex Nav Struct
    for (i = 0; i < MAX_MON_MOVES; ++i)
    {
        moveLoc[i] = gEnemyParty[0].moves[i];
    }

    // set first move slot to a random egg move if search level is good enough
    if (genMove == TRUE)
    {
        u16 eggMoveBuffer[EGG_MOVES_ARRAY_COUNT];
        u8 numEggMoves = GetEggMoves(&gEnemyParty[0], &eggMoveBuffer);
        if (numEggMoves != 0)
        {
            u8 index = RandRange(0, numEggMoves);
            moveLoc[0] = eggMoveBuffer[index];
        }
    }
}

static void DexNavDrawBlackBars(u8 objidAddr[4])
{
    LoadSpritePalette(&sSpritePalette_HeldItem);
    LoadCompressedSpriteSheetUsingHeap(&sBlackBarTiles);
    objidAddr[0] = CreateSprite(&sBlackBarTemplate, ICONX + 16, ICONY - 2, 0x0);
    objidAddr[1] = CreateSprite(&sBlackBarTemplate, ICONX + 16 + 64, ICONY - 2, 0x0);
    objidAddr[2] = CreateSprite(&sBlackBarTemplate, ICONX + 16 + 64 + 64, ICONY - 2, 0x0);
    objidAddr[3] = CreateSprite(&sBlackBarTemplate, ICONX + 16 + 64 + 64 + 64, ICONY - 2, 0x0);
}

static void DexNavDrawSight(u8 sight_lvl, u8* objidAddr)
{
    LoadSpritePalette(&sSpritePalette_HeldItem);
    LoadCompressedSpriteSheetUsingHeap(&sightTiles);
    u8 objId = CreateSprite(&fontTempSight, ICONX + 192, ICONY + 0x12, 0x0);
    *objidAddr = objId;
    gSprites[objId].oam.affineMode = 2;
    DexNavSightUpdate(sight_lvl);
    gSprites[objId].oam.objMode = 1;
}

static void DexNavDrawAbility(u8 ability, u8* objidAddr)
{
    u8 objId = CreateSprite(&FontTempAbility, ICONX + 80, ICONY + 0x12, 0x0);
    u8 len;
    
    LoadSpritePalette(&sSpritePalette_HeldItem);
    LoadCompressedSpriteSheetUsingHeap(&FontSpriteAbility);
    *objidAddr = objId;
    gSprites[objId].oam.affineMode = 2;

    // ability name beside move name
    len = sDNavState->moveNameLength;
    gSprites[objId].pos1.x += ((8 * (len/2)) + (4 * (len % 2)));

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
    OutlinedFontDraw(objId, 0, 32 * 8);
    gSprites[objId].oam.objMode = 1;
    return;
}

static void DexNavDrawMove(u16 move, u8 searchLevel, u8* objidAddr)
{
    LoadSpritePalette(&sSpritePalette_HeldItem);
    LoadCompressedSpriteSheetUsingHeap(&FontSpriteMove);
    u8 objId = CreateSprite(&FontTempMove, ICONX + 80, ICONY + 0x12, 0x0);
    *objidAddr = objId;
    gSprites[objId].oam.affineMode = 2;

    // Copy move string from table using state id, add '/' character to the end of it
    u8* ptr = StringCopy(gStringVar4, gMoveNames[move]);
    u8 len = StringLength(gStringVar4);

    if (searchLevel > 2)
    {
        *ptr = 0xBA;
        len += 1;
    }

    // record length of move with slash for ability name to be placed beside it
    sDNavState->moveNameLength = len;

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
    OutlinedFontDraw(objId, 0, 32 * 8);
    gSprites[objId].oam.objMode = 1;
}

static void DexNavDrawPotential(u8 potential, u8* objidAddr)
{
    // allocate both the lit and unlit star to VRAM
    LoadSpriteSheet(&StarIconLit);
    LoadSpriteSheet(&StarIconOff);
    LoadSpritePalette(&sSpritePalette_HeldItem);

    // create star objects and space them according to potential 0 - 3
    u8 objId;
    u8 i;
    for (i = 0; i < 3; ++i)
    {
        if (potential > i)
            objId = CreateSprite(&StarLitTemp, ICONX + 23 + (i * 8), ICONY + 0x5, 0x0);
        else
            objId = CreateSprite(&StarOffTemp, ICONX + 23 + (i * 8), ICONY + 0x5, 0x0);

        objidAddr[i] = objId;
        gSprites[objId].oam.affineMode = 2;
        gSprites[objId].oam.objMode = 1;
    }
}


void DexNavHudDrawSpeciesIcon(u16 species, u8* objIdAddr)
{
    u32 pid = 0xFFFFFFFF;
    if (species == SPECIES_UNOWN)
        pid = GenerateUnownPersonality(sDNavState->unownLetter - 1);

    //Load which palette the species icon uses
    LoadMonIconPalette(species);

    //Create the icon
    u8 objId = CreateMonIcon(species, SpriteCB_PokeIcon, ICONX, ICONY, 0, pid, FALSE);
    *objIdAddr = objId;

    gSprites[objId].oam.affineMode = 2;
    gSprites[objId].oam.objMode = 1;
}

void DexNavDrawHeldItem(u8* objidAddr)
{
    // create object for held item icon
    u8 objId;

    LoadSpriteSheet(sSpriteSheet_HeldItem);
    LoadSpritePalette(sSpritePalette_HeldItem);
    objId = CreateSprite(HeldTemp, ICONX + 0x8, ICONY + 0xC, 0x0);
    *objidAddr = objId;
    gSprites[objId].oam.affineMode = 2;
    gSprites[objId].oam.objMode = 1;
}

static void DexNavDrawIcons(void)
{
    u8 searchLevel = sDNavState->searchLevel;
    
    DexNavDrawBlackBars(sDNavState->objIdBlackBar);
    DexNavDrawSight(sDNavState->proximity, &sDNavState->objIdSight);
    DexNavDrawMove(sDNavState->moveId[0], searchLevel, &sDNavState->objIdMove);
    DexNavDrawHeldItem(&sDNavState->objIdItem);
    DexNavDrawAbility(sDNavState->ability, &sDNavState->objIdAbility);
    DexNavDrawPotential(sDNavState->potential, &sDNavState->objIdPotential[0]);
    DexNavHudDrawSpeciesIcon(sDNavState->species, &sDNavState->objIdSpecies);
}


void InitDexNavHUD(u16 species, u8 environment)
{
    u8 searchLevel;
    u8 taskId;
    
    sDNavState = Calloc(sizeof(struct DexnavHudData));
    // assign non-objects to struct
    sDNavState->species = species;

    if (IS_NEWER_UNOWN_LETTER(species))
    {
        sDNavState->unownLetter = species - SPECIES_UNOWN_B + 2; //Because B is 1
        sDNavState->species = species = SPECIES_UNOWN;
    }
    else //UNOWN A
    {
        sDNavState->unownLetter = 1;
    }
    
    sDNavState->environment = environment;
    searchLevel = sDexNavSearchLevels[SpeciesToNationalPokedexNum(species)];
    sDNavState->searchLevel = searchLevel;
    sDNavState->pokemonLevel = DexNavGenerateMonLevel(species, searchLevel, environment);

    if (sDNavState->pokemonLevel < 1)
    {
        Free(sDNavState);
        MsgNormal(sText_CannotBeFound);
        return;
    }

    // draw shaking grass
    if (!ShakingGrass(environment, 12, 12, 0))
    {
        Free(sDNavState);
        MsgNormal(sText_NotFoundNearby);
        return;
    }

    //Populate sDNavState objects
    DexNavGenerateMoveset(species, searchLevel, sDNavState->pokemonLevel, &sDNavState->moveId[0]);
    sDNavState->heldItem = DexNavGenerateHeldItem(species, searchLevel);
    sDNavState->abilityNum = DexNavGenerateHiddenAbility(species, searchLevel);
    sDNavState->potential = DexNavGeneratePotential(searchLevel);
    DexNavProximityUpdate();

    //Draw icons
    DexNavDrawIcons();

    //Hide icons based on proximity and search level
    DexNavIconsVisionUpdate(sDNavState->proximity, searchLevel);

    //Enable Hblank interrupt
    //EnableInterrupts(2);
    //SetHBlankCallback(DexHUDHBlank);

    // task update HUD
    taskId = CreateTask(DexNavManageHUD, 0x1);
    gTasks[taskId].data[0] = gSprites[gPlayerAvatar->spriteId].pos1.x;
}


// This is called via a c1 from the GUI, while waiting to return to the OW
static void ExecDexNavHUD(void)
{
    if (!gPaletteFade->active && !ScriptContext2_IsEnabled() && gMain.callback2 == CB2_Overworld)
    {
        SetMainCallback1(CB1_Overworld);
        InitDexNavHUD(gSpecialVar_0x8000, gSpecialVar_0x8001);
    }
}

u8 ExecDexNav(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0x0000);
    SetMainCallback1(DexNavGuiHandler);
    gMain.state = 0;
    return TRUE;
}

// gfx clean
static void DexNavGuiSetup(void)
{
    Setup();
    FreeAllWindowBuffers();
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, (struct BgTemplate *)&BgConfigDexNavGUI, 4);
    u32 set = 0;
    CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET));
    HideBg(1);
    HideBg(0);
    SetMainCallback2(DexNavGUICallback2);
    SetVBlankCallback(VblackCallbackSeq);
}

static void DexNavLoadPokeIcons(void)
{
    s16 x, y;
    u8 i;
    u8 letter;
    u32 pid = 0xFFFFFFFF;
    u8 hiddenLandMons = sDNavState->numHiddenLandMons;
    u8 hiddenWaterMons = sDNavState->numHiddenWaterMons;

    LoadMonIconPalettes();

    for (i = 0; i < NUM_LAND_MONS; ++i)
    {
        u16 species = sDNavState->grassSpecies[i];
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

        letter = sDNavState->unownFormsByDNavIndices[i];
        if (letter > 0)
            pid = GenerateUnownPersonality(sDNavState->unownFormsByDNavIndices[i] - 1);

        CreateMonIcon(species, SpriteCB_PokeIcon, x, y, 0, pid, 0);
    }

    for (i = 0; i < NUM_WATER_MONS; ++i)
    {
        u16 species = sDNavState->waterSpecies[i];
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

        letter = PickUnownLetter(species, i);
        if (letter > 0)
            pid = GenerateUnownPersonality(letter - 1);

        CreateMonIcon(species, SpriteCB_PokeIcon, x, y, 0, pid, 0);
    }
}

static void CreateNoDataIcon(s16 x, s16 y)
{
    LoadCompressedSpriteSheetUsingHeap(&sIconTiles);
    struct SpriteTemplate IconTemplate =
    {
        .tileTag = ICON_GFX_TAG,
        .paletteTag = ICON_PAL_TAG,
        .oam = IconOAM,
        .anims =  gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    }

    CreateSprite(&IconTemplate, x, y, 0);
}

static void UpdateCursorPosition(void)
{
    // update cursor position
    if (sDNavState->selectedArr)
    {
        // water
        gSprites[sDNavState->cursorId].pos1.x = CursorPositions2[sDNavState->selectedIndex];
        gSprites[sDNavState->cursorId].pos1.y = CursorPositions2[sDNavState->selectedIndex + 1];
    }
    else
    {
        // grass
        gSprites[sDNavState->cursorId].pos1.x = CursorPositions1[sDNavState->selectedIndex];
        gSprites[sDNavState->cursorId].pos1.y = CursorPositions1[sDNavState->selectedIndex + 1];
    }
}

static void SpawnPointerArrow(void)
{
    // uncompressed
    LoadSpriteSheet(&CursorGFX);
    LoadSpritePalette(&CursorPal);
    sDNavState->cursorId = CreateSprite(&CursorTemp, 30, 48, 0);
    UpdateCursorPosition();
}


#define MAP_IS(map) (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(map) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(map))
static void DexNavLoadAreaNames(void)
{
    const u8* landText;
    const u8* waterText;

    /*
    #ifdef UNBOUND
    if (MAP_IS(FLOWER_PARADISE_A))
    {
        landText = sText_PinkFlowers;
        waterText = sText_YellowFlowers;
    }
    else if (MAP_IS(FLOWER_PARADISE_B))
    {
        landText = sText_RedFlowers;
        waterText = sText_BlueFlowers;
    }
    else if (MAP_IS(FLOWER_PARADISE_C))
    {
        landText = sText_PinkAndPurpleFlowers;
        waterText = sText_BlueAndYellowFlowers;
    }
    else if (IsCurrentAreaVolcano())
    {
        landText = sText_DexNavLand;
        waterText = sText_Magma;
    }
    else
    #endif
    {
        landText = sText_DexNavLand;
        waterText = sText_DexNavWater;
    }
    */
    landText = sText_DexNavLand;
    waterText = sText_DexNavWater;

    AddTextPrinterParameterized3(WINDOW_WATER, 1, 4, 6, &DexNav_WhiteText, 0, waterText);
    AddTextPrinterParameterized3(WINDOW_LAND, 1, 5, 6, &DexNav_WhiteText, 0, landText);
}

static void DexNavLoadNames(u8 status)
{
    u8 searchLevelBonus;
    u8 i;
    u16 species;
    u16 dexNum;
    
    // clean boxes
    for (i = 0; i < WINDOW_COUNT; ++i)
        FillWindowPixelBuffer(i, 0);

    //Print species name
    species = sDNavState->selectedArr == ROW_WATER ? sDNavState->waterSpecies[sDNavState->selectedIndex >> 1] : sDNavState->grassSpecies[sDNavState->selectedIndex>>1];
    dexNum = SpeciesToNationalPokedexNum(species);

    if (species != SPECIES_NONE)
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
        AddTextPrinterParameterized3(WINDOW_LEVEL_BONUS, 0, 0, 4, &DexNav_BlackText, 0, sText_DexNav_NoInfo);
    else
        AddTextPrinterParameterized3(WINDOW_LEVEL_BONUS, 0, 0, 4, &DexNav_BlackText, 0, gStringVar4);

    //Print hidden ability name
    if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT) || species == SPECIES_NONE)
    {
        if (gBaseStats[species].abilityHidden != ABILITY_NONE) //Only display hidden ability is Pokemon has been caught
            AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, &DexNav_BlackText, 0, GetAbilityName(gBaseStats[species].abilityHidden));
        else
            AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, &DexNav_BlackText, 0, sText_DexNav_NoInfo);
    }
    else
        AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, &DexNav_BlackText, 0, sText_DexNav_CaptureToSee);

    //Print status message bar
    switch(status)
    {
        case 0:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, sText_DexNav_Invalid);
            break;
        case 1:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, sText_DexNav_ChooseMon);
            break;
        case 2:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, sText_DexNav_Locked);
            break;
        case 3:
            AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, sText_DexNav_NoDataForSlot);
            break;
    }

    //Load area names
    DexNavLoadAreaNames();

    //Load map name
    GetMapName(gStringVar4, GetCurrentRegionMapSectionId(), 0);
    AddTextPrinterParameterized3(WINDOW_MAP_NAME, 1, 2, 0, &DexNav_WhiteText, 0, gStringVar4);

    // display committed gfx
    for (i = 0; i < WINDOW_COUNT; ++i)
    {
        CopyWindowToVram(i, 3);
        PutWindowTilemap(i);
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
        for (i = 0; i < NUM_LAND_MONS; ++i)
        {
            species = landMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE)
            {
                ++num;
                if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                    break;
            }
        }

        if (i >= NUM_LAND_MONS && num > 0) //All land mons caught and there were land mons to catch
            CreateSprite(sCapturedAllPokemonSymbolTemplate,  154, 77, 0);
    }

    num = 0;
    if (waterMonsInfo != NULL)
    {
        for (i = 0; i < NUM_WATER_MONS; ++i)
        {
            species = waterMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE)
            {
                ++num;
                if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                    break;
            }
        }

        if (i >= NUM_WATER_MONS && num > 0) //All water mons caught and there were water mons to catch
            CreateSprite(sCapturedAllPokemonSymbolTemplate,  140, 29, 0);
    }
}

static void CallbackDexNavOW(void)
{
    ExecDexNavHUD();
}


static void DexNavGuiExitSearch(void)
{
    switch (gMain.state)
    {
        case 0:
            BeginNormalPaletteFade(~0, 0, 0x0, 0x10, 0);
            PlaySE(SE_POKENAV_SEARCHING);
            gMain.state += 1;
            break;
        case 1:
            if (!gPaletteFade->active)
            {
                Free(sDNavState->backBuffer);
                gMain.state += 1;
            }
            break;
        case 2:
            m4aMPlayVolumeControl(gMPlay_BGM, 0xFFFF, 256);
            SetMainCallback1(CallbackDexNavOW);
            SetMainCallback2(CB2_ReturnToFieldContinueScript);
            break;
    }
}


static void DexNavGuiExitNoSearch(void)
{
    switch (gMain.state)
    {
        case 0:
            BeginNormalPaletteFade(~0, 0, 0x0, 0x10, 0);
            gMain.state += 1;
            break;
        case 1:
            if (!gPaletteFade->active)
            {
                Free(sDNavState->backBuffer);
                Free(sDNavState);
                gMain.state += 1;
            }
            break;
        case 2:
            m4aMPlayVolumeControl(gMPlay_BGM, 0xFFFF, 256);
            SetMainCallback1(CB1_Overworld);

            //#ifdef FLAG_POKETOOLS_MENU
            //    FlagSet(FLAG_POKETOOLS_MENU);
            //#endif
            SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
            break;
    }
}


static void DexNavPopulateEncounterList(void)
{
    // populate unique wild grass encounters
    u8 grassIndex = 0;
    u8 waterIndex = 0;
    u16 species;
    int i;
    u16 headerId = GetCurrentMapWildMonHeaderId();
    
    // nop struct data
    Memset(sDNavState->grassSpecies, 0, sizeof(sDNavState->grassSpecies)
                                      + sizeof(sDNavState->waterSpecies)
                                      + sizeof(sDNavState->hiddenSpecies)
                                      + sizeof(sDNavState->unownForms)
                                      + sizeof(sDNavState->unownFormsByDNavIndices));

    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

    sDNavState->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;

    if (landMonsInfo != NULL)
    {
        for (i = 0; i < NUM_LAND_MONS; ++i)
        {
            species = landMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, NUM_LAND_MONS, PickUnownLetter(species, i)))
            {
                sDNavState->grassSpecies[grassIndex++] = landMonsInfo->wildPokemon[i].species;

                if (InTanobyRuins())
                {
                    sDNavState->unownForms[i] = PickUnownLetter(species, i);
                    sDNavState->unownFormsByDNavIndices[grassIndex - 1] = PickUnownLetter(species, i);
                }
            }
        }
    }

    sDNavState->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;

    if (waterMonsInfo != NULL)
    {
        for (int i = 0; i < NUM_WATER_MONS; ++i)
        {
            species = waterMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, NUM_WATER_MONS, PickUnownLetter(species, i)))
            {
                sDNavState->waterSpecies[waterIndex++] = waterMonsInfo->wildPokemon[i].species;
            }
        }
    }

    if (InTanobyRuins() && !GetSetPokedexFlag(NATIONAL_DEX_UNOWN, FLAG_GET_SEEN))
    { //This is so the right amount of ? appear for Unown in the different chambers
        u16 unowns[NUM_LAND_MONS + 1];
        unowns[0] = SPECIES_TABLES_TERMIN;

        sDNavState->numHiddenLandMons = 0;
        for (int i = 0; i < NUM_LAND_MONS; ++i)
        {
            u8 letter = PickUnownLetter(SPECIES_UNOWN, i);
            if (!CheckTableForSpecies(letter, unowns)) //Table with Unown letters treated like a species table
            {
                unowns[sDNavState->numHiddenLandMons++] = letter;
                unowns[sDNavState->numHiddenLandMons] = SPECIES_TABLES_TERMIN; //Shift end down 1
            }
        }
    }

    sDNavState->numGrassMons = grassIndex;
    sDNavState->numWaterMons = waterIndex;
}

#define LAND_ROW_LENGTH (6 * 2)
#define LAND_FIRST_ROW_LAST_INDEX (5 * 2)
#define LAND_SECOND_ROW_LAST_INDEX (LAND_FIRST_ROW_LAST_INDEX + LAND_ROW_LENGTH)
#define LAND_SECOND_ROW_FIRST_INDEX (6 * 2)
#define WATER_ROW_LAST_INDEX (4 * 2)
#define ROW_MON_LENGTH 2
static void DexNavGuiHandler(void)
{
    switch(gMain.state)
    {
        case 0:
            if (!gPaletteFade->active)
            {
                DexNavGuiSetup();
                SetMainCallback1(DexNavGuiHandler);
                // allocate dexnav struct
                sDNavState = Calloc(sizeof(struct DexnavHudData));
                gMain.state += 1;
            }
            break;
        case 1: ;
            //Load BG assets
            void* DexNav_gbackBuffer = Malloc(0x800);
            sDNavState->backBuffer = DexNav_gbackBuffer;
            LoadPalette(&DexNavTextPal, 15 * 16, 32);
            const u8* palette;

            if (IsMapTypeIndoors(GetCurrentMapType()))
                palette = sDexNavGuiIndoorPal;
            /*
            else if (IsCurrentAreaVolcano()) //Load special palette for volcanos
                palette = sDexNavGuiVolcanoPal;
            #ifdef UNBOUND
            else if (MAP_IS(FLOWER_PARADISE_A))
                palette = sDexNavGuiFlowerParadiseAPal;
            else if (MAP_IS(FLOWER_PARADISE_B))
                palette = sDexNavGuiFlowerParadiseBPal;
            else if (MAP_IS(FLOWER_PARADISE_C))
                palette = sDexNavGuiFlowerParadiseCPal;
            #endif
            */
            else if (IsCurrentAreaDarkerCave())
                palette = sDexNavGuiDarkerCavePal;
            else if (GetCurrentMapType() == MAP_TYPE_UNDERGROUND)
                palette = sDexNavGuiCavePal;
            else if (IsCurrentAreaAutumn())
                palette = sDexNavGuiAutumnPal;
            else if (IsCurrentAreaWinter())
                palette = sDexNavGuiWinterPal;
            else
                palette = sDexnavGuiPal;

            LoadCompressedPalette(palette, 0, 32);

            LZ77UnCompWram(sDexnavGuiTilemap, DexNav_gbackBuffer);
            LZ77UnCompVram(sDexnavGuiTiles, (void*) 0x06000000);
            SetBgTilemapBuffer(1, DexNav_gbackBuffer);
            BgIdMarkForSync(1);
            BgIdMarkForSync(0);
            gMain.state += 1;
            break;

        case 2:
            InitWindows(sDexNavWindows);
            DexNavPopulateEncounterList();
            DexNavLoadNames(1);
            gMain.state += 1;
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
            sDNavState->selectedArr = 0;
            sDNavState->selectedIndex = 0;
            gMain.state += 1;
            break;

        case 4:
            if (!gPaletteFade->active)
            {
                switch (gMain.newAndRepeatedKeys &
                    (A_BUTTON | B_BUTTON | DPAD_DOWN | DPAD_UP | DPAD_LEFT | DPAD_RIGHT | R_BUTTON))
                {
                    case A_BUTTON: ;
                        // check selection is valid. Play sound if invalid
                        u16 species = sDNavState->selectedArr == ROW_WATER ? sDNavState->waterSpecies[sDNavState->selectedIndex / 2] : sDNavState->grassSpecies[sDNavState->selectedIndex / 2];
                        // if species is MISSINGNO then error
                        if (species != SPECIES_NONE)
                        {
                            if (species == SPECIES_UNOWN)
                            {
                                u8 letter = sDNavState->unownFormsByDNavIndices[sDNavState->selectedIndex / 2] - 1;
                                if (letter > 0)
                                    species = SPECIES_UNOWN_B + letter - 1;
                            }

                            //Species was valid, save and enter OW HUD mode
                            gSpecialVar_0x8000 = species;
                            gSpecialVar_0x8001 = sDNavState->selectedArr;
                            SetMainCallback1(DexNavGuiExitSearch);
                            gMain.state = 0;
                            return;
                        }
                        else
                        {
                            PrintDexNavError();
                        }
                        break;

                    case B_BUTTON:
                        // exit to start menu
                        SetMainCallback1(DexNavGuiExitNoSearch);
                        gMain.state = 0;
                        return;
                    case DPAD_DOWN:
                        if (sDNavState->selectedArr == ROW_LAND)
                        {
                            if (sDNavState->selectedIndex >= LAND_SECOND_ROW_FIRST_INDEX)
                            {
                                sDNavState->selectedIndex = MathMin(sDNavState->selectedIndex - LAND_ROW_LENGTH, WATER_ROW_LAST_INDEX);
                                sDNavState->selectedArr = ROW_WATER;
                            }
                            else
                            {
                                sDNavState->selectedIndex += LAND_ROW_LENGTH; //Move to second row of land
                            }
                        }
                        else //ROW_WATER
                        {
                            sDNavState->selectedArr = ROW_LAND; //Keep index the same
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_POKENAV_ONE_BEEP);
                        break;

                    case DPAD_UP:
                        if (sDNavState->selectedArr == ROW_LAND)
                        {
                            if (sDNavState->selectedIndex >= LAND_SECOND_ROW_FIRST_INDEX)
                            {
                                sDNavState->selectedIndex -= LAND_ROW_LENGTH; //Move to first row of land
                            }
                            else
                            {
                                sDNavState->selectedIndex = MathMin(sDNavState->selectedIndex, WATER_ROW_LAST_INDEX);
                                sDNavState->selectedArr = ROW_WATER;
                            }
                        }
                        else //ROW_WATER
                        {
                            sDNavState->selectedArr = ROW_LAND;
                            sDNavState->selectedIndex += LAND_ROW_LENGTH; //So be on the second row
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_POKENAV_ONE_BEEP);
                        break;

                    case DPAD_LEFT:
                        // wrap cursor around
                        if (sDNavState->selectedArr == ROW_WATER)
                            sDNavState->selectedIndex = (sDNavState->selectedIndex == 0) ? WATER_ROW_LAST_INDEX : sDNavState->selectedIndex - ROW_MON_LENGTH;
                        else //ROW_LAND
                        {
                            if (sDNavState->selectedIndex == 0 || sDNavState->selectedIndex == LAND_SECOND_ROW_FIRST_INDEX)
                                sDNavState->selectedIndex += LAND_FIRST_ROW_LAST_INDEX; //Wrap around
                            else
                                sDNavState->selectedIndex -= ROW_MON_LENGTH;
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_POKENAV_ONE_BEEP);
                        break;
                    case DPAD_RIGHT:
                        if (sDNavState->selectedArr == ROW_WATER)
                            sDNavState->selectedIndex = (sDNavState->selectedIndex == WATER_ROW_LAST_INDEX) ? 0 : sDNavState->selectedIndex + ROW_MON_LENGTH;
                        else //ROW_LAND
                        {
                            if (sDNavState->selectedIndex == LAND_FIRST_ROW_LAST_INDEX || sDNavState->selectedIndex == LAND_SECOND_ROW_LAST_INDEX)
                                sDNavState->selectedIndex -= LAND_FIRST_ROW_LAST_INDEX; //Wrap around
                            else
                                sDNavState->selectedIndex += ROW_MON_LENGTH;
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_POKENAV_ONE_BEEP);
                        break;
                    case R_BUTTON:
                    {
                        // check selection is valid. Play sound if invalid
                        u16 species = sDNavState->selectedArr ? sDNavState->waterSpecies[sDNavState->selectedIndex / 2] : sDNavState->grassSpecies[sDNavState->selectedIndex / 2];
                        // if species is MISSINGNO then error
                        if (species != SPECIES_NONE)
                        {
                            if (species == SPECIES_UNOWN)
                            {
                                u8 letter = sDNavState->unownFormsByDNavIndices[sDNavState->selectedIndex / 2] - 1;
                                if (letter > 0)
                                    species = SPECIES_UNOWN_B + letter - 1;
                            }

                            // species was valid
                            DexNavLoadNames(2);
                            PlaySE(SE_POKENAV_SEARCHING);
                            // create value to store in a var
                            u16 varStore = (sDNavState->selectedArr << 15) | species;
                            VarSet(VAR_DEXNAV, varStore);
                        }
                        else
                        {
                            // beep and update
                            DexNavLoadNames(0);
                            PlaySE(SE_ERROR);
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

static void PrintDexNavError(void)
{
    if (sDNavState->selectedArr == ROW_WATER
    &&  sDNavState->selectedIndex >> 1 >= sDNavState->numWaterMons + sDNavState->numHiddenWaterMons)
    {
        //Print Pokemon can't be searched yet
        DexNavLoadNames(3);
        PlaySE(SE_ERROR);
    }
    else if (sDNavState->selectedArr == ROW_LAND
    &&  sDNavState->selectedIndex >> 1 >= sDNavState->numGrassMons + sDNavState->numHiddenLandMons)
    {
        //Print Pokemon can't be searched yet
        DexNavLoadNames(3);
        PlaySE(SE_ERROR);
    }
    else //Selected unidentified Pokemon
    {
        //Print invalid Pokemon
        DexNavLoadNames(0);
        PlaySE(SE_ERROR);
    }
}

// =================================== //
// ===== Overworld Field Effects ===== //
// =================================== //
static void FieldEff_CaveDust(void)
{
    LoadSpritePalette(&sCaveSmokePalTemplate);
    LoadPalette(gInterfaceGfx_caveSmokePal, 29 * 16, 32);
    LogCoordsCameraRelative(&gFieldEffectArguments[0], &gFieldEffectArguments[1], 8, 8);

    u8 objId = CreateSpriteAtEnd(ObjtCave, gFieldEffectArguments[0], gFieldEffectArguments[1], 0xFF);
    if (objId != MAX_SPRITES)
    {
        gSprites[objId].coordOffsetEnabled = 1;
        gSprites[objId].data[0] = 22;
    }
}

static void FieldEff_Sparkles(void)
{
    LoadSpritePalette(&sSparklesPalTemplate);
    LoadPalette(gInterfaceGfx_SparklesPal, 29 * 16, 32);
    LogCoordsCameraRelative(&gFieldEffectArguments[0], &gFieldEffectArguments[1], 8, 8);

    u8 objId = CreateSpriteAtEnd(&sSpriteTemplateSparkles, gFieldEffectArguments[0], gFieldEffectArguments[1], 0xFF);
    if (objId != MAX_SPRITES)
    {
        gSprites[objId].coordOffsetEnabled = 1;
        gSprites[objId].data[0] = 22;
    }
}

static void FieldEff_LavaBubbles(void)
{
    LoadSpritePalette(&sLavaBubblesPalTemplate);
    LoadPalette(gInterfaceGfx_LavaBubblesPal, 29 * 16, 32);
    LogCoordsCameraRelative(&gFieldEffectArguments[0], &gFieldEffectArguments[1], 8, 8);

    u8 objId = CreateSpriteAtEnd(&sSpriteTemplateLavaBubbles, gFieldEffectArguments[0], gFieldEffectArguments[1], 0xFF);
    if (objId != MAX_SPRITES)
    {
        gSprites[objId].coordOffsetEnabled = 1;
        gSprites[objId].data[0] = 22;
    }
}

// ========================================== //
// ======== Check Select in Overworld ======= //
// ========================================== //
/*
u8 SelectHookRestore(void)
{
    ScriptContext1_SetupScript((void*) 0x81A77A0); // script that lets you know you can register item via select
    return 0;
}
*/

/*Replaced with R-Button
u8 CheckRegisteredSelect(void)
{
    u16 varVal = VarGet(VAR_DEXNAV);
    if (varVal)
    {
        if ()
            return 0;    // don't redo the search...
        InitDexNavHUD(varVal & 0x7FFF, varVal >> 15);
        return 0;
    }
    return 1;
}
*/

bool8 IsDexNavHudActive(void)
{
    return FuncIsActiveTask(DexNavManageHUD);
}

// ============================== //
// ========= POKETOOLS ========== //
// ============================== //
#define priv0 gTasks[taskId].data[0]
void __attribute__((long_call)) StartMenuPokedexFunc(void);
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
            WindowOutline(boxId, 1, 0x214, 0xE);
            AddTextPrinterParameterized3(boxId, 1, 8, 2, &MenuTextBlack, 0, &sText_DexNavText[0]);
            ChoiceSetupSimple(boxId, 2, 0, 1, 16, POKETOOLS_COUNT, 0);
            CopyWindowToVram(boxId, 3);
            PutWindowTilemap(boxId);
            gTasks[taskId].data[1] = boxId;
            priv0++;
            break;
        }
        case 2:
        {
            s8 choice = RboxChoiceUpdate();
            if (choice == 0)
            {
                //pokedex
                StartMenuPokedexFunc();
                DestroyTask(taskId);
            }
            else if (choice == 1)
            {
                // dexnav
                ExecDexNav();
                DestroyTask(taskId);
            }
            else if (choice == -1)
            {
                // b pressed, exit
                RboxIdClean(gTasks[taskId].data[1], 1);
                RemoveWindow(gTasks[taskId].data[1]);
                ScriptContext2_Disable();
                DestroyTask(taskId);
            }
            break;
        }
    }
}

// up to the user to include this feature
static bool8 InTanobyRuins(void)
{
    return FALSE;
}
