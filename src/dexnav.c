#include "global.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "dexnav.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "random.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/map_types.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/field_effects.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/abilities.h"
#include "constants/rgb.h"
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
#define WINDOW_COUNT_SPECIES_INFO   (WINDOW_HIDDEN_ABILITY + 1)

enum Statuses
{
    STATUS_INVALID_SEARCH,
    STATUS_CHOOSE_MON,
    STATUS_LOCKED,
    STATUS_NO_DATA,
    STATUS_INCORRECT_AREA,
};

#define IS_NEWER_UNOWN_LETTER(species) (species >= SPECIES_UNOWN_B && species <= SPECIES_UNOWN_QMARK)

struct DexNavSearch
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 moves[MAX_MON_MOVES];
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
             u8 fldEffId;
    /*0x22*/ u8 spriteIdPotential[3];
    /*0x25*/ u8 movementCount;
             u8 abilityNum;
};

struct DexNavGUI
{
    MainCallback savedCallback;
    u8 state;
    u8 cursorSpriteId;
    u16 grassSpecies[NUM_LAND_MONS];
    u16 waterSpecies[NUM_WATER_MONS];
	u16 hiddenSpecies[NUM_LAND_MONS + 1];
	u8 unownForms[NUM_LAND_MONS];
	u8 unownFormsByDNavIndices[NUM_LAND_MONS];
	u8 numGrassMons;
	u8 numWaterMons;
	u8 numHiddenLandMons;
	u8 numHiddenWaterMons;
    u8 cursorRow;
    u8 cursorCol;
    u8 environment;
};

// RAM

EWRAM_DATA static u8 sDexNavSearchLevels[NUM_SPECIES] = {0};    // to be moved to saveblock!!!!
EWRAM_DATA static struct DexNavSearch *sDexNavSearchDataPtr = NULL;  //#define sDexNavSearchDataPtr (*((struct DexNavSearch**) 0x203E038))
EWRAM_DATA static struct DexNavGUI *sDexNavStateDataPtr = NULL;
EWRAM_DATA static u8 *sBg1TilemapBuffer = NULL;
EWRAM_DATA u16 gDexNavSpecies = 0;
EWRAM_DATA u8 gDexNavEnvironment = 0;
EWRAM_DATA u8 sDexNavWindowId = 0;
EWRAM_DATA u8 sDexNavSearchSpriteId = 0;

//// Function Declarations
//GUI
static void Task_DexNavWaitFadeIn(u8 taskId);
static void Task_DexNavMain(u8 taskId);
static void PrintCurrentSpeciesInfo(void);
// SEARCH
static bool8 ShakingGrass(u8 environment, u8 xSize, u8 ySize, bool8 smallScan);
static void DexNavGenerateMoveset(u16 species, u8 searchLevel, u8 encounterLevel, u16* moveLoc);
static u16 DexNavGenerateHeldItem(u16 species, u8 searchLevel);
static u8 DexNavGetAbilityNum(u16 species, u8 searchLevel);
static u8 DexNavGeneratePotential(u8 searchLevel);
static void DexNavDrawHeldItem(u8* spriteIdAddr);
static u8 DexNavGenerateMonLevel(u16 species, u8 searchLevel, u8 environment);
static u8 GetEncounterLevel(u16 species, u8 environment);
static void CreateDexNavWildMon(u16 species, u8 potential, u8 level, u8 abilityNum, u16* moves);
static u8 GetPlayerDistance(s16 x, s16 y);
static u8 PickTileScreen(u8 targetBehaviour, u8 areaX, u8 areaY, s16 *xBuff, s16 *yBuff, u8 smallScan);
static u8 DexNavPickTile(u8 environment, u8 xSize, u8 ySize, bool8 smallScan);
static void DexNavProximityUpdate(void);

//// Const Data
// image data
static const u32 sDexNavGuiTiles[] = INCBIN_U32("graphics/dexnav/dexnav_gui_tiles.4bpp.lz");
static const u32 sDexNavGuiTilemap[] = INCBIN_U32("graphics/dexnav/dexnav_gui_tilemap.bin");
static const u32 sDexNavGuiPal[] = INCBIN_U32("graphics/dexnav/dexnav_gui.gbapal");

//static const u16 sDexNavStarsTiles[] = INCBIN_U16("graphics/dexnav/stars.4bpp");
static const u8 sDexNavStarsTiles[] = INCBIN_U8("graphics/dexnav/stars.4bpp");
static const u8 sDexNavStarsPal[] = INCBIN_U8("graphics/dexnav/stars.gbapal");

static const u32 sSelectionCursorGfx[] = INCBIN_U32("graphics/dexnav/cursor.4bpp.lz");
static const u16 sSelectionCursorPal[] = INCBIN_U16("graphics/dexnav/cursor.gbapal");

static const u32 gInterfaceGfx_emptyTiles[] = INCBIN_U32("graphics/dexnav/empty.4bpp.lz");
static const u16 gInterfaceGfx_emptyPal[] = INCBIN_U16("graphics/dexnav/empty.gbapal");

static const u32 gInterfaceGfx_CapturedAllPokemonTiles[] = INCBIN_U32("graphics/dexnav/captured_all.4bpp.lz");
static const u32 gInterfaceGfx_CapturedAllPokemonPal[] = INCBIN_U32("graphics/dexnav/captured_all.gbapal.lz");

static const u32 gInterfaceGfx_SparklesTiles[] = INCBIN_U32("graphics/dexnav/sparkles.4bpp");
static const u16 gInterfaceGfx_SparklesPal[] = INCBIN_U16("graphics/dexnav/sparkles.gbapal");

static const u32 gInterfaceGfx_LavaBubblesTiles[] = INCBIN_U32("graphics/dexnav/lava_bubbles.4bpp");
static const u16 gInterfaceGfx_LavaBubblesPal[] = INCBIN_U16("graphics/dexnav/lava_bubbles.gbapal");

static const u32 sDexNavNoDataSymbolTiles[] = INCBIN_U32("graphics/dexnav/no_data.4bpp.lz");

static const struct SpritePalette sSpritePalette_Stars =
{
    (const u16 *)sDexNavStarsPal, 0x2710
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
//static const u8 sText_GotAway[] = _("The Pokémon got away!\p");
//static const u8 sText_LostSignal[] = _("There is no reaction.\nThe signal was lost!\p");
static const u8 sText_GotAwayShouldSneak[] = _("The Pokémon got away!\nTry moving more slowly.\p");
static const u8 sText_CannotBeFound[] = _("This Pokémon cannot be found here.\p");
//static const u8 sText_NotFoundNearby[] = _("It couldn't be found nearby.\nTry looking in a different area!\p");
static const u8 sText_DexNavBack[] = _(" Back  ");
static const u8 sText_DexNav_NoInfo[] = _("--------");
static const u8 sText_DexNav_CaptureToSee[] = _("Capture first!");
static const u8 sText_DexNav_ChooseMon[] = _("Choose a Pokémon.");
static const u8 sText_DexNav_Invalid[] = _("That Pokémon can't be searched yet!");
static const u8 sText_DexNav_NoDataForSlot[] = _("There's no data for that Pokémon…");
static const u8 sText_DexNav_Searchable[] = _("{STR_VAR_1} searchable via R-button!");
static const u8 sText_DexNav_NotFoundHere[] = _("This Pokémon cannot be found here!");

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

static const struct WindowTemplate sDexNavGuiWindowTemplates[] =
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

static const u8 sFontColor_Black[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};
static const u8 sFontColor_White[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY};

/*
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

*/



#define ITEM_ICON_X 26
#define ITEM_ICON_Y (16 * 8)
static void ShowMonIconInHeaderBox(u16 species)
{
    u8 spriteId;
    u8 yPos;
    
    yPos = (GetWindowAttribute(sDexNavWindowId, WINDOW_TILEMAP_TOP) * 8) + 8;
    LoadMonIconPalette(species);
    spriteId = CreateMonIcon(species, SpriteCB_MonIcon, ITEM_ICON_X - 6, yPos, 0, 0xFFFFFFFF, 0);
    gSprites[spriteId].oam.priority = 0;
    sDexNavSearchSpriteId = spriteId;
}

static const u8 sFontColor[3] = {0, 15, 13};
//static const u8 sText_Test[] = _("{STR_VAR_1}       Ability        Level\nSpecial Move     IVs      Shiny");
//static const u8 sText_Test[] = _("x: {STR_VAR_1}     y: {STR_VAR_2}\n   proximity: {STR_VAR_3}");
static const u8 sText_Test[] = _("{STR_VAR_1}\n     x: {STR_VAR_2}  y: {STR_VAR_3}");
void DrawHeaderBox(u16 species)
{
    struct WindowTemplate template;
    u16 y = 16;
    
    if (sDexNavSearchDataPtr->tileY > (gSaveBlock1Ptr->pos.y + 7))
        y = 1;  //draw at top if chosen tile is below

    LoadDexNavWindowGfx(sDexNavWindowId, 0x1d5, 14 * 16);
    
    SetWindowTemplateFields(&template, 0, 1, y, 28, 3, 14, 8);
    
    sDexNavWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sDexNavWindowId, PIXEL_FILL(15));
    PutWindowTilemap(sDexNavWindowId);
    CopyWindowToVram(sDexNavWindowId, 3);
    
    DrawStdFrameWithCustomTileAndPalette(sDexNavWindowId, TRUE, 0x214, 14);
    
    StringCopy(gStringVar1, gSpeciesNames[species]);
    
    ConvertIntToDecimalStringN(gStringVar2, sDexNavSearchDataPtr->tileX - 7, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, sDexNavSearchDataPtr->tileY - 7, STR_CONV_MODE_RIGHT_ALIGN, 2);
    
    StringExpandPlaceholders(gStringVar4, sText_Test);
    AddTextPrinterParameterized3(sDexNavWindowId, 0, ITEM_ICON_X + 4, 0, sFontColor, TEXT_SPEED_FF, gStringVar4);
    CopyWindowToVram(sDexNavWindowId, 2);
    
    ShowMonIconInHeaderBox(species);
}

void RemoveHeaderBox(void)
{
    DestroySpriteAndFreeResources(&gSprites[sDexNavSearchSpriteId]);
    ClearStdWindowAndFrameToTransparent(sDexNavWindowId, FALSE);
    CopyWindowToVram(sDexNavWindowId, 3);
    RemoveWindow(sDexNavWindowId);
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
    sDexNavSearchDataPtr->proximity = GetPlayerDistance(sDexNavSearchDataPtr->tileX, sDexNavSearchDataPtr->tileY);
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
    u8 scale = 0;
    u8 weight = 0;
    u8 currMapType = GetCurrentMapType();
    u8 tileBehaviour;
    
    // loop through every tile in area and evaluate
    // to do - random tile checks instead of sequential?
    while (topY < botY)
    {
        while (topX < botX)
        {
            tileBehaviour = MapGridGetMetatileBehaviorAt(topX, topY);
            
            //gSpecialVar_0x8005 = tileBehaviour;
            
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
            
            if (MetatileBehavior_IsEncounterTile(tileBehaviour))
            {                
                switch (environment)
                {
                case ENCOUNTER_TYPE_LAND:
                    if (currMapType == MAP_TYPE_UNDERGROUND)
                    { // inside (cave)
                        if (IsZCoordMismatchAt(gObjectEvents[gPlayerAvatar.spriteId].currentElevation, topX, topY))
                            break; //occurs at same z coord
                        
                        scale = 440 - (smallScan * 200) - (GetPlayerDistance(topX, topY) / 2)  - (2 * (topX + topY));
                        weight = ((Random() % scale) < 1) && !MapGridIsImpassableAt(topX, topY);
                    }
                    else
                    { // outdoors: grass
                        scale = 100 - (GetPlayerDistance(topX, topY) * 2);
                        weight = (Random() % scale <= 5) && !MapGridIsImpassableAt(topX, topY);
                    }
                    break;
                case ENCOUNTER_TYPE_WATER:
                    if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehaviour))
                    {
                        u8 scale = 320 - (smallScan * 200) - (GetPlayerDistance(topX, topY) / 2);
                        if (IsZCoordMismatchAt(gObjectEvents[gPlayerAvatar.spriteId].currentElevation, topX, topY))
                            break;

                        weight = (Random() % scale <= 1) && !MapGridIsImpassableAt(topX, topY);
                    }
                    break;
                default:
                    break;
                }
            }
            
            //gSpecialVar_0x8002 = scale;
            if (weight > 0)
            {
                sDexNavSearchDataPtr->tileX = topX;
                sDexNavSearchDataPtr->tileY = topY;
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
    u8 currMapType = GetCurrentMapType();
    u8 fldEffId = 0;
    
    if (DexNavPickTile(environment, xSize, ySize, smallScan))
    {
        u8 metatileBehaviour = MapGridGetMetatileBehaviorAt(sDexNavSearchDataPtr->tileX, sDexNavSearchDataPtr->tileY);
        
        gFieldEffectArguments[0] = sDexNavSearchDataPtr->tileX;
        gFieldEffectArguments[1] = sDexNavSearchDataPtr->tileY;
        gFieldEffectArguments[2] = 0xFF; // height.
        
        switch (environment)
        {
        case ENCOUNTER_TYPE_LAND:
            if (currMapType == MAP_TYPE_UNDERGROUND)
            {
                fldEffId = FLDEFF_CAVE_DUST;
            }
            else if (IsMapTypeIndoors(currMapType))
            {
                if (MetatileBehavior_IsTallGrass(metatileBehaviour)) //Grass in cave
                    fldEffId = FLDEFF_SHAKING_GRASS;
                else if (MetatileBehavior_IsLongGrass(metatileBehaviour)) //Really tall grass
                    fldEffId = FLDEFF_SHAKING_LONG_GRASS;
                else if (MetatileBehavior_IsSandOrDeepSand(metatileBehaviour))
                    fldEffId = FLDEFF_SAND_HOLE;
                else
                    fldEffId = FLDEFF_CAVE_DUST;
            }
            else //outdoor, underwater
            {
                if (MetatileBehavior_IsTallGrass(metatileBehaviour)) //Regular grass
                    fldEffId = FLDEFF_SHAKING_GRASS;
                else if (MetatileBehavior_IsLongGrass(metatileBehaviour)) //Really tall grass
                    fldEffId = FLDEFF_SHAKING_LONG_GRASS;
                else if (MetatileBehavior_IsSandOrDeepSand(metatileBehaviour)) //Desert Sand
                    fldEffId = FLDEFF_SAND_HOLE;
                else if (MetatileBehavior_IsMountain(metatileBehaviour)) //Rough Terrain
                    fldEffId = FLDEFF_CAVE_DUST;
                else
                    fldEffId = FLDEFF_SPARKLE; //default
            }
            break;
        case ENCOUNTER_TYPE_WATER:
            fldEffId = FLDEFF_WATER_SURFACING;
            break;
        default:
            //we found a good tile, but somehow ended up here. default effect
            fldEffId = FLDEFF_SPARKLE;
            break;
        }
        
        if (fldEffId != 0)
        {
            sDexNavSearchDataPtr->fldEffSpriteId = FieldEffectStart(fldEffId);
            if (sDexNavSearchDataPtr->fldEffSpriteId == MAX_SPRITES)
                return FALSE;
            
            sDexNavSearchDataPtr->fldEffId = fldEffId;
            return TRUE;
        }
    }

    return FALSE;
}

#define tProximity          data[0]
#define tFrameCount         data[1]
static void Task_InitDexNavSearch(u8 taskId)
{
    u16 species = gDexNavSpecies;   //testing
    u8 environment = 0; //testing
    u8 searchLevel;
    
    sDexNavSearchDataPtr = AllocZeroed(sizeof(struct DexNavSearch));
    // assign non-objects to struct
    sDexNavSearchDataPtr->species = species;

    /*if (IS_NEWER_UNOWN_LETTER(species))
    {
        sDexNavSearchDataPtr->unownLetter = species - SPECIES_UNOWN_B + 2; //Because B is 1
        sDexNavSearchDataPtr->species = species = SPECIES_UNOWN;
    }
    else //UNOWN A
    {
        sDexNavSearchDataPtr->unownLetter = 1;
    }*/
    
    sDexNavSearchDataPtr->environment = environment;
    searchLevel = 10;   //sDexNavSearchLevels[SpeciesToNationalPokedexNum(species)];
    sDexNavSearchDataPtr->searchLevel = searchLevel;
    sDexNavSearchDataPtr->monLevel = 10;   //to do: DexNavGenerateMonLevel(species, searchLevel, environment);
    
    //DexNavGenerateMoveset(species, searchLevel, sDexNavSearchDataPtr->monLevel, &sDexNavSearchDataPtr->moves[0]);
    sDexNavSearchDataPtr->heldItem = 0; //DexNavGenerateHeldItem(species, searchLevel);
    sDexNavSearchDataPtr->abilityNum = 0;   //DexNavGetAbilityNum(species, searchLevel);
    sDexNavSearchDataPtr->potential = DexNavGeneratePotential(searchLevel);
    
    //taskId = CreateTask(Task_DexNavSearch, 1);
    //gTasks[taskId].tFrameCount = 0;
    if (!ShakingGrass(environment, 12, 12, 0))
    {
        Free(sDexNavSearchDataPtr);
        FreeMonIconPalettes();
        ScriptContext1_SetupScript(EventScript_NotFoundNearby);
        DestroyTask(taskId);
        return;
    }
    
    DexNavProximityUpdate();
    FlagSet(FLAG_SYS_DEXNAV_ACTIVE);
    gPlayerAvatar.creeping = TRUE;  //initialize as true in case mon appears beside you
    DrawHeaderBox(species);
    gTasks[taskId].tProximity = gSprites[gPlayerAvatar.spriteId].pos1.x;
    gTasks[taskId].tFrameCount = 0;
    gTasks[taskId].func = Task_DexNavSearch;
}


/////////////////////
//// SEARCH TASK ////
/////////////////////
void EndDexNavSearch(u8 taskId)
{
    FlagClear(FLAG_SYS_DEXNAV_ACTIVE);
    DestroyTask(taskId);
    RemoveHeaderBox();
    FieldEffectStop(&gSprites[sDexNavSearchDataPtr->fldEffSpriteId], sDexNavSearchDataPtr->fldEffId);
    Free(sDexNavSearchDataPtr);
    FreeMonIconPalettes();
}

static void EndDexNavSearchSetupScript(const u8 *script, u8 taskId)
{
    EndDexNavSearch(taskId);
    ScriptContext1_SetupScript(script);
}

static u8 GetMovementProximityBySearchLevel(void)
{
    if (sDexNavSearchDataPtr->searchLevel < 20)
        return 2;
    else if (sDexNavSearchDataPtr->searchLevel < 50)
        return 3;
    else
        return 4;
}

#include "script_pokemon_util.h"
void Task_DexNavSearch(u8 taskId)
{
    u16 species;
    s16 x, y;
    struct Task *task = &gTasks[taskId];
    
    if (sDexNavSearchDataPtr->proximity > MAX_PROXIMITY)
    { // out of range
        EndDexNavSearchSetupScript(EventScript_LostSignal, taskId);
        return;
    }
    
    if (sDexNavSearchDataPtr->proximity <= CREEPING_PROXIMITY && !gPlayerAvatar.creeping && task->tFrameCount > 60)
    { //should be creeping but player walks normally
        EndDexNavSearchSetupScript(EventScript_PokemonGotAway, taskId);
        return;
    }
    
    if (sDexNavSearchDataPtr->proximity <= SNEAKING_PROXIMITY && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_BIKE)) 
    { // running/biking too close
        EndDexNavSearchSetupScript(EventScript_PokemonGotAway, taskId);
        return;
    }
    
    if (ScriptContext2_IsEnabled() == TRUE)
    { // check if script just executed
        EndDexNavSearch(taskId);
        return;
    }
    
    if (JOY_NEW(B_BUTTON | START_BUTTON))
    { //player manually canceled
        EndDexNavSearch(taskId);
        PlaySE(SE_POKENAV_OFF);
        return;
    }
    
    if (gTasks[taskId].tFrameCount > DEXNAV_TIMEOUT * 60)
    { // player took too long
        EndDexNavSearchSetupScript(EventScript_PokemonGotAway, taskId);
        return;
    }
    
    if (sDexNavSearchDataPtr->proximity < 1)
    {
        FlagClear(FLAG_SYS_DEXNAV_ACTIVE);
        CreateDexNavWildMon(sDexNavSearchDataPtr->species, sDexNavSearchDataPtr->potential, sDexNavSearchDataPtr->monLevel, 
          sDexNavSearchDataPtr->abilityNum, sDexNavSearchDataPtr->moves);
        
        if (sDexNavSearchLevels[species] < 100)
            sDexNavSearchLevels[species]++;
        
        ScriptContext1_SetupScript(EventScript_StartDexNavBattle);
        Free(sDexNavSearchDataPtr);
        DestroyTask(taskId);
        return;
    }

    //Caves and water the pokemon moves around
    if ((sDexNavSearchDataPtr->environment == ENCOUNTER_TYPE_WATER || GetCurrentMapType() == MAP_TYPE_UNDERGROUND)
        && sDexNavSearchDataPtr->proximity < GetMovementProximityBySearchLevel() && sDexNavSearchDataPtr->movementCount < 2)
    {
        bool8 ret;
        
        switch (sDexNavSearchDataPtr->environment)
        {
        case ENCOUNTER_TYPE_LAND:
            FieldEffectStop(&gSprites[sDexNavSearchDataPtr->fldEffSpriteId], FLDEFF_CAVE_DUST);
            break;
        case ENCOUNTER_TYPE_WATER:
            FieldEffectStop(&gSprites[sDexNavSearchDataPtr->fldEffSpriteId], FLDEFF_WATER_SURFACING);
            break;
        default:
            break;
        }

        while (1) {
            if (ShakingGrass(sDexNavSearchDataPtr->environment, 8, 8, 1))
                break;
        }
        
        sDexNavSearchDataPtr->movementCount++;
    }

    DexNavProximityUpdate();
    if (task->tProximity != sDexNavSearchDataPtr->proximity)
    {
        //to do: DexNavIconsVisionUpdate(sDexNavSearchDataPtr->proximity, sDexNavSearchDataPtr->searchLevel);
        task->tProximity = sDexNavSearchDataPtr->proximity;
    }
    
    task->tFrameCount++;
}

//////////////////////////////
//// DEXNAV MON GENERATOR ////
//////////////////////////////
static void CreateDexNavWildMon(u16 species, u8 potential, u8 level, u8 abilityNum, u16* moves)
{
    struct Pokemon* mon = &gEnemyParty[0];
    u8 iv[3];
    u8 i;
    u8 perfectIv = 31;
    
    // to do - updated shiny rate?
    
    CreateWildMon(species, level);
    
    //Pick potential ivs to set to 31
    iv[0] = Random() % 6;
    iv[1] = Random() % 6;
    iv[2] = Random() % 6;
    if ((iv[0] != iv[1]) && (iv[0] != iv[2]) && (iv[1] != iv[2]))
    {
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
        SetMonData(mon, MON_DATA_MOVE1 + i, &moves[i]);
        SetMonData(mon, MON_DATA_PP1 + i, &gBattleMoves[moves[i]].pp);
    }

    CalculateMonStats(mon);
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
    //CreateWildMon(species, encounterLevel, sDexNavSearchDataPtr->selectedIndex / 2, TRUE);
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

static u8 DexNavGetAbilityNum(u16 species, u8 searchLevel)
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
    if (genAbility && gBaseStats[species].abilityHidden != ABILITY_NONE && GetSetPokedexFlag(species, FLAG_GET_CAUGHT))
    {
        sDexNavSearchDataPtr->ability = gBaseStats[species].abilityHidden;
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
        
        sDexNavSearchDataPtr->ability = gBaseStats[species].abilities[abilityNum];
    }
}

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

    return RandRange(min, max);
}


///////////
/// GUI ///
///////////
static const struct BgTemplate sDexNavMenuBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    }, 
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 1
    }
};

static void DexNav_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void DexNav_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static bool8 DexNav_InitBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    
    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sDexNavMenuBgTemplates, NELEMS(sDexNavMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT , 0);
    ShowBg(0);
    ShowBg(1);
    return TRUE;
}

static bool8 DexNav_LoadGraphics(void)
{
    switch (sDexNavStateDataPtr->state)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sDexNavGuiTiles, 0, 0, 0);
        sDexNavStateDataPtr->state++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sDexNavGuiTilemap, sBg1TilemapBuffer);
            sDexNavStateDataPtr->state++;
        }
        break;
    case 2:
        LoadPalette(sDexNavGuiPal, 0, 32);
        sDexNavStateDataPtr->state++;
        break;
    default:
        sDexNavStateDataPtr->state = 0;
        return TRUE;
    }
    
    return FALSE;
}

static void UpdateCursorPosition(void)
{
    u16 x, y;
    
    switch (sDexNavStateDataPtr->cursorRow)
    {
    case ROW_WATER:
        x = 30 + (24 * sDexNavStateDataPtr->cursorCol);
        y = 48;
        break;
    case ROW_LAND_TOP: //land 1
        x = 20 + (24 * sDexNavStateDataPtr->cursorCol);
        y = 92;
        break;
    case ROW_LAND_BOT: //land 2
        x = 20 + (24 * sDexNavStateDataPtr->cursorCol);
        y = 92 + 28;
        break;
    }
    
    gSprites[sDexNavStateDataPtr->cursorSpriteId].pos1.x = x;
    gSprites[sDexNavStateDataPtr->cursorSpriteId].pos1.y = y;
    
    PrintCurrentSpeciesInfo();
}

static const struct OamData sSelectionCursorOam =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0, // above BG layers
    .paletteNum = 15,
    .affineParam = 0
};
static const struct SpriteTemplate sSelectionCursorSpriteTemplate =
{
    .tileTag = SELECTION_CURSOR_TAG,
    .paletteTag = 5,
    .oam = &sSelectionCursorOam,
    .anims =  gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static void CreateSelectionCursor(void)
{
    u8 spriteId;
    struct CompressedSpriteSheet spriteSheet;
    
    spriteSheet.data = sSelectionCursorGfx;
    spriteSheet.size = 0x200;
    spriteSheet.tag = SELECTION_CURSOR_TAG;
    LoadCompressedSpriteSheet(&spriteSheet);
    
    LoadPalette(sSelectionCursorPal, (16 * sSelectionCursorOam.paletteNum) + 0x100, 32);
    
    spriteId = CreateSprite(&sSelectionCursorSpriteTemplate, 12, 32, 0);  
    gSprites[spriteId].data[1] = -1;
    
    sDexNavStateDataPtr->cursorSpriteId = spriteId;
    UpdateCursorPosition();
}

//#define WIN_DETAILS_TILE        0x3a3
static void DexNav_InitWindows(void)
{
    InitWindows(sDexNavGuiWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
}

static void DexNavGuiFreeResources(void)
{
    Free(sDexNavStateDataPtr);
    Free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}

static void CB1_InitDexNavSearch(void)
{
    if (!gPaletteFade.active && !ScriptContext2_IsEnabled() && gMain.callback2 == CB2_Overworld)
    {
        SetMainCallback1(CB1_Overworld);
        CreateTask(Task_InitDexNavSearch, 0);
    }
}

static void CB1_DexNavSearchCallback(void)
{
    CB1_InitDexNavSearch();
}

static void Task_DexNavExitAndSearch(u8 taskId)
{
    DexNavGuiFreeResources();
    DestroyTask(taskId);
    SetMainCallback1(CB1_DexNavSearchCallback);
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_DexNavFadeAndExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sDexNavStateDataPtr->savedCallback);
        DexNavGuiFreeResources();
        DestroyTask(taskId);
    }
}

static void DexNavFadeAndExit(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_DexNavFadeAndExit, 0);
    SetVBlankCallback(DexNav_VBlankCB);
    SetMainCallback2(DexNav_MainCB);
}

static bool8 SpeciesInArray(u16 species, u8 indexCount)
{
    u32 i;
    
	//check if species is unique
	if (!GetSetPokedexFlag(species, FLAG_GET_SEEN))
	{
		for (i = 0; i < NUM_LAND_MONS; i++)
		{
			if (sDexNavStateDataPtr->hiddenSpecies[i] == SPECIES_TABLES_TERMIN)
			{
				sDexNavStateDataPtr->hiddenSpecies[i] = species;
				sDexNavStateDataPtr->hiddenSpecies[i + 1] = SPECIES_TABLES_TERMIN;
				break;
			}
			else if (sDexNavStateDataPtr->hiddenSpecies[i] == species) //Already in array
            {
				return TRUE;
            }
        }
		
        if (indexCount == NUM_LAND_MONS)
			sDexNavStateDataPtr->numHiddenLandMons++; //Increase how many question marks to print
		else
			sDexNavStateDataPtr->numHiddenWaterMons++;
        
		return TRUE;
	}
    
	for (i = 0; i < indexCount; i++)
	{
		if (indexCount == NUM_LAND_MONS)
		{
			if (sDexNavStateDataPtr->grassSpecies[i] == species)
				return TRUE;
		}
		else
		{
			if (sDexNavStateDataPtr->waterSpecies[i] == species)
				return TRUE;
		}
	}
    
	return FALSE;
}

// get unique wild encounters on current map
static void DexNavLoadEncounterData(void)
{
    u8 grassIndex = 0;
    u8 waterIndex = 0;
    u16 species, letter;
    u32 i;
    u16 headerId = GetCurrentMapWildMonHeaderId();
    //u16 unowns[NUM_LAND_MONS + 1];
    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    
    // nop struct data
    memset(sDexNavStateDataPtr->grassSpecies, 0, sizeof(sDexNavStateDataPtr->grassSpecies));
    memset(sDexNavStateDataPtr->waterSpecies, 0, sizeof(sDexNavStateDataPtr->waterSpecies));
    memset(sDexNavStateDataPtr->hiddenSpecies, 0, sizeof(sDexNavStateDataPtr->hiddenSpecies));
    //memset(sDexNavStateDataPtr->unownForms, 0, sizeof(sDexNavStateDataPtr->unownForms));
    memset(sDexNavStateDataPtr->unownFormsByDNavIndices, 0, sizeof(sDexNavStateDataPtr->unownFormsByDNavIndices));
    sDexNavStateDataPtr->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;
    if (landMonsInfo != NULL)
    {
        for (i = 0; i < NUM_LAND_MONS; i++)
        {
            species = landMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, NUM_LAND_MONS))
                sDexNavStateDataPtr->grassSpecies[grassIndex++] = landMonsInfo->wildPokemon[i].species;
        }
    }
    
    sDexNavStateDataPtr->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;
    if (waterMonsInfo != NULL)
    {
        for (i = 0; i < NUM_WATER_MONS; i++)
        {
            species = waterMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, NUM_WATER_MONS))
            {
            //if (species != SPECIES_NONE)
                sDexNavStateDataPtr->waterSpecies[waterIndex++] = waterMonsInfo->wildPokemon[i].species;
            }
        }
    }
    
    sDexNavStateDataPtr->numGrassMons = grassIndex;
    sDexNavStateDataPtr->numWaterMons = waterIndex;
}

static void DrawSpeciesIcons(void)
{
    s16 x, y;
    //u8 letter;
    u32 pid = 0xFFFFFFFF;
    u8 hiddenLandMons = sDexNavStateDataPtr->numHiddenLandMons;
    u8 hiddenWaterMons = sDexNavStateDataPtr->numHiddenWaterMons;
	u32 i;
	u16 species;
    
    for (i = 0; i < NUM_LAND_MONS; i++)
    {
        species = sDexNavStateDataPtr->grassSpecies[i];
        x = 20 + (24 * (i % 6));
        y = 92 + (i > 5 ? 28 : 0);
        if (species == SPECIES_NONE)
        {
            if (hiddenLandMons == 0)
            {
                //CreateNoDataIcon(x, y);   //'X' in slot
                //CreateMonIcon(SPECIES_NONE, NULL, x, y, 0, pid, 0); //temp
                continue;
            }
            else
            {
                hiddenLandMons--;
            }
        }
        
        //letter = sDexNavStateDataPtr->unownFormsByDNavIndices[i];
        //if (letter > 0)
        //    pid = GenerateUnownPersonality(sDexNavStateDataPtr->unownFormsByDNavIndices[i] - 1);
        CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, pid, 0);
    }
    
    for (i = 0; i < NUM_WATER_MONS; i++)
    {
        species = sDexNavStateDataPtr->waterSpecies[i];
        x = 30 + 24 * i;
        y = 48;
        if (species == SPECIES_NONE)
        {
            if (hiddenWaterMons == 0)
            {
                //CreateNoDataIcon(x, y);   //'X' in slot
                //CreateMonIcon(SPECIES_NONE, NULL, x, y, 0, pid, 0); //temp
                continue;
            }
            else
            {
                hiddenWaterMons--;
            }
        }
        
        //letter = PickUnownLetter(species, i);
        //if (letter > 0)
        //    pid = GenerateUnownPersonality(letter - 1);
        CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, pid, 0);
    }
}

static void DexNavPrintAreaNames(void)
{
    FillWindowPixelBuffer(WINDOW_WATER,  PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WINDOW_LAND,  PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_LAND);
    PutWindowTilemap(WINDOW_WATER);
    AddTextPrinterParameterized3(WINDOW_WATER, 2, 4, 6, sFontColor_White, 0, sText_DexNavWater);
    AddTextPrinterParameterized3(WINDOW_LAND, 2, 5, 6, sFontColor_White, 0, sText_DexNavLand);
    CopyWindowToVram(WINDOW_LAND, 3);
    CopyWindowToVram(WINDOW_WATER, 3);
}

static void PrintDexNavMessage(const u8 *str)
{
    PutWindowTilemap(WINDOW_REPLY_TEXT);
    FillWindowPixelBuffer(WINDOW_REPLY_TEXT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 2, 2, 8, sFontColor_White, TEXT_SPEED_FF, str);
    CopyWindowToVram(WINDOW_REPLY_TEXT, 3);
}

static u16 DexNavGetSpecies(void)
{
    switch (sDexNavStateDataPtr->cursorRow)
    {
    case ROW_WATER:
        return sDexNavStateDataPtr->waterSpecies[sDexNavStateDataPtr->cursorCol];
    case ROW_LAND_TOP:
        return sDexNavStateDataPtr->grassSpecies[sDexNavStateDataPtr->cursorCol];
    case ROW_LAND_BOT:
        return sDexNavStateDataPtr->grassSpecies[sDexNavStateDataPtr->cursorCol + COL_LAND_MAX];
    default:
        return SPECIES_NONE;
    }
}

static void PrintCurrentSpeciesInfo(void)
{
    u8 searchLevelBonus = 0;
    u16 species = DexNavGetSpecies();
    u32 i;
    
    // clear windows
    for (i = 0; i < WINDOW_COUNT_SPECIES_INFO; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    
    //name
    if (species == SPECIES_NONE)
        AddTextPrinterParameterized3(WINDOW_SPECIES, 0, 0, 4, sFontColor_Black, 0, sText_DexNav_NoInfo);
    else
        AddTextPrinterParameterized3(WINDOW_SPECIES, 0, 0, 4, sFontColor_Black, 0, gSpeciesNames[species]);
        
    //search level
    if (species == SPECIES_NONE)
    {
        AddTextPrinterParameterized3(WINDOW_SEARCH_LEVEL, 0, 0, 4, sFontColor_Black, 0, sText_DexNav_NoInfo);
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar4, sDexNavSearchLevels[species], 0, 4);
        AddTextPrinterParameterized3(WINDOW_SEARCH_LEVEL, 0, 0, 4, sFontColor_Black, 0, gStringVar4);
    }
    
    //search level bonus
    if ((sDexNavSearchLevels[species] >> 2) > 20)
        searchLevelBonus = 20;
    else
        searchLevelBonus = (sDexNavSearchLevels[species] >> 2);
    
    ConvertIntToDecimalStringN(gStringVar4, searchLevelBonus, 0, 4);
    if (species == SPECIES_NONE)
        AddTextPrinterParameterized3(WINDOW_LEVEL_BONUS, 0, 0, 4, sFontColor_Black, 0, sText_DexNav_NoInfo);
    else
        AddTextPrinterParameterized3(WINDOW_LEVEL_BONUS, 0, 0, 4, sFontColor_Black, 0, gStringVar4);
    
    //hidden ability
    if (species == SPECIES_NONE)
    {
        AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, sFontColor_Black, 0, sText_DexNav_NoInfo);
    }
    else if (GetSetPokedexFlag(species, FLAG_GET_CAUGHT))
    {
        if (gBaseStats[species].abilityHidden != ABILITY_NONE)
            AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, sFontColor_Black, 0, gAbilityNames[gBaseStats[species].abilityHidden]);
        else
            AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, sFontColor_Black, 0, gText_None);
    }
    else
    {
        AddTextPrinterParameterized3(WINDOW_HIDDEN_ABILITY, 0, 0, 4, sFontColor_Black, 0, sText_DexNav_CaptureToSee);
    }
    
    //Map name
    GetMapName(gStringVar4, GetCurrentRegionMapSectionId(), 0);
    AddTextPrinterParameterized3(WINDOW_MAP_NAME, 2, 2, 0, sFontColor_White, 0, gStringVar4);
    
    // update windows
    for (i = 0; i < WINDOW_COUNT_SPECIES_INFO; i++)
    {
        CopyWindowToVram(i, 3);
        PutWindowTilemap(i);
    }
}

static void PrintSearchableSpecies(u16 species)
{
    StringCopy(gStringVar1, gSpeciesNames[species]);
    StringExpandPlaceholders(gStringVar4, sText_DexNav_Searchable);
    PrintDexNavMessage((const u8 *)gStringVar4);
}

static bool8 DexNav_DoGfxSetup(void)
{
    u8 taskId;
    
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        DexNavPrintAreaNames();        
        gMain.state++;
        break;
    case 6:
        ResetTasks();
        gMain.state++;
        break;
    case 7:
        if (DexNav_InitBgs())
        {
            sDexNavStateDataPtr->state = 0;
            gMain.state++;
        }
        else
        {
            DexNavFadeAndExit();
            return TRUE;
        }
        break;
    case 8:
        if (DexNav_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 9:
        DexNav_InitWindows();
        sDexNavStateDataPtr->cursorRow = ROW_LAND_TOP;
        sDexNavStateDataPtr->cursorCol = 0;
        sDexNavStateDataPtr->environment = ENCOUNTER_TYPE_LAND;
        gMain.state++;
        break;
    case 10:
        DexNavLoadEncounterData();
        LoadMonIconPalettes();
        gMain.state++;
        break;
    case 11:
        taskId = CreateTask(Task_DexNavWaitFadeIn, 0);
        gMain.state++;
        break;
    case 12:
        DrawSpeciesIcons();
        CreateSelectionCursor();
        if (gSaveBlock1Ptr->dexnavRegisteredSpecies != SPECIES_NONE)
            PrintSearchableSpecies(gSaveBlock1Ptr->dexnavRegisteredSpecies);
        
        gMain.state++;
        break;
    case 13:
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 14:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(DexNav_VBlankCB);
        SetMainCallback2(DexNav_MainCB);
        return TRUE;
    }
    
    return FALSE;
}

static void DexNav_RunSetup(void)
{
    while (!DexNav_DoGfxSetup()) {}
}

static void DexNavGuiInit(MainCallback callback)
{
    if ((sDexNavStateDataPtr = AllocZeroed(sizeof(struct DexNavGUI))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    sDexNavStateDataPtr->state = 0;
    sDexNavStateDataPtr->savedCallback = callback;
    SetMainCallback2(DexNav_RunSetup);
}

void Task_OpenDexNavFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        DexNavGuiInit(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void Task_DexNavWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_DexNavMain;
}

static void Task_DexNavMain(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u16 species;
    
    if (IsSEPlaying())
        return;
    
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_POKENAV_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        task->func = Task_DexNavFadeAndExit;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sDexNavStateDataPtr->cursorRow == ROW_WATER)
        {
            sDexNavStateDataPtr->cursorRow = ROW_LAND_BOT;
            sDexNavStateDataPtr->environment = ENCOUNTER_TYPE_LAND;
        }
        else
        {
            if (sDexNavStateDataPtr->cursorRow == ROW_LAND_TOP && sDexNavStateDataPtr->cursorCol == COL_LAND_MAX)
                sDexNavStateDataPtr->cursorCol = COL_WATER_MAX;
            
            sDexNavStateDataPtr->cursorRow--;
        }
        
        PlaySE(SE_RG_BAG_CURSOR);
        UpdateCursorPosition();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sDexNavStateDataPtr->cursorRow == ROW_LAND_BOT)
        {
            sDexNavStateDataPtr->cursorRow = ROW_WATER;
            sDexNavStateDataPtr->environment = ENCOUNTER_TYPE_WATER;
            if (sDexNavStateDataPtr->cursorCol == COL_LAND_MAX)
                sDexNavStateDataPtr->cursorCol = COL_WATER_MAX;
        }
        else
        {
            sDexNavStateDataPtr->cursorRow++;
        }
        
        PlaySE(SE_RG_BAG_CURSOR);
        UpdateCursorPosition();
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (sDexNavStateDataPtr->cursorCol == 0)
        {
            switch (sDexNavStateDataPtr->cursorRow)
            {
            case ROW_WATER:
                sDexNavStateDataPtr->cursorCol = COL_WATER_COUNT - 1;
                break;
            default:
                sDexNavStateDataPtr->cursorCol = COL_LAND_COUNT - 1;
                break;
            }
        }
        else
        {
            sDexNavStateDataPtr->cursorCol--;
        }
        
        PlaySE(SE_RG_BAG_CURSOR);
        UpdateCursorPosition();
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        switch (sDexNavStateDataPtr->cursorRow)
        {
        case ROW_WATER:
            if (sDexNavStateDataPtr->cursorCol == COL_WATER_MAX)
                sDexNavStateDataPtr->cursorCol = 0;
            else
                sDexNavStateDataPtr->cursorCol++;
            break;
        default:
            if (sDexNavStateDataPtr->cursorCol == COL_LAND_MAX)
                sDexNavStateDataPtr->cursorCol = 0;
            else
                sDexNavStateDataPtr->cursorCol++;
            break;
        }
        
        PlaySE(SE_RG_BAG_CURSOR);
        UpdateCursorPosition();
    }
    else if (JOY_NEW(R_BUTTON))
    {
        // check selection is valid. Play sound if invalid
        species = DexNavGetSpecies();
        
        if (species != SPECIES_NONE)
        {
            /*if (species == SPECIES_UNOWN)
            {
                u8 letter = sDexNavStateDataPtr->unownFormsByDNavIndices[sDexNavStateDataPtr->selectedIndex / 2] - 1;
                if (letter > 0)
                    species = SPECIES_UNOWN_B + letter - 1;
            }*/
            
            PrintSearchableSpecies(species);
            PlaySE(SE_DEX_SEARCH);
            
            // create value to store in a var
            gSaveBlock1Ptr->dexnavRegisteredSpecies = (sDexNavStateDataPtr->environment << 15) | species;
        }
        else
        {
            // beep and update
            PrintDexNavMessage(sText_DexNav_NoDataForSlot);
            PlaySE(SE_FAILURE);
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        species = DexNavGetSpecies();
        if (species == SPECIES_NONE)
        {
            PlaySE(SE_FAILURE);
        }
        else
        {
            gDexNavSpecies = species;
            PlaySE(SE_DEX_SEARCH);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            task->func = Task_DexNavExitAndSearch;
        }
    }
}






void DebugDexNav(void)
{
    u32 i;
    
    EnableNationalPokedex();
    
    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        if (i >= SPECIES_OLD_UNOWN_B && i <= SPECIES_OLD_UNOWN_Z)
            continue;
        
        GetSetPokedexFlag(i, FLAG_SET_SEEN);
        GetSetPokedexFlag(i, FLAG_GET_CAUGHT);
    }
}


