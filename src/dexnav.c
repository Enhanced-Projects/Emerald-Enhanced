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
#include "international_string_util.h"
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
#include "pokemon_summary_screen.h"
#include "random.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_pokemon_util.h"
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
#include "constants/region_map_sections.h"
#include "gba/m4a_internal.h"

/*
to do
    -hidden pokemon
        -3 per map max
        -how to distinguish in water vs. grass?
    -VAR_DEXNAV_SPECIES should be reset on map change. or check map data on map when R pressed
    -write data to search window
*/

// Defines
enum WindowIds
{
    WINDOW_INFO,
    WINDOW_REGISTERED,
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

#define IS_NEWER_UNOWN_LETTER(species) (species >= SPECIES_UNOWN_B && species <= SPECIES_UNOWN_QMARK)

struct DexNavSearch
{
    u16 species;
    u16 moves[MAX_MON_MOVES];
    u16 heldItem;
    u8 abilityNum;
    u8 potential;
    u8 searchLevel;
    u8 monLevel;
    u8 moveNameLength;
    u8 proximity;
    u8 environment;
    //u8 unownLetter;
    s16 tileX; // position of shaking grass
    s16 tileY;
    u8 fldEffSpriteId;
    u8 fldEffId;
    u8 movementCount;
    u8 windowId;
    u8 iconSpriteId;
    u8 eyeSpriteId;
    u8 itemSpriteId;
    u8 starSpriteIds[3];
};

struct DexNavGUI
{
    MainCallback savedCallback;
    u8 state;
    u8 cursorSpriteId;
    u16 landSpecies[LAND_WILD_COUNT];
    u16 waterSpecies[WATER_WILD_COUNT];
    u16 hiddenSpecies[HIDDEN_WILD_COUNT];
    u8 cursorRow;
    u8 cursorCol;
    u8 environment;
    u8 potential;
    u8 typeIconSpriteIds[2];
    u8 starSpriteIds[3];
};

// RAM

EWRAM_DATA static struct DexNavSearch *sDexNavSearchDataPtr = NULL;
EWRAM_DATA static struct DexNavGUI *sDexNavUiDataPtr = NULL;
EWRAM_DATA static u8 *sBg1TilemapBuffer = NULL;
EWRAM_DATA u8 gCurrentDexNavChain = 0;
EWRAM_DATA bool8 gDexnavBattle = FALSE;

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
static u8 DexNavGenerateMonLevel(u16 species, u8 environment);
static u8 GetEncounterLevel(u16 species, u8 environment);
static void CreateDexNavWildMon(u16 species, u8 potential, u8 level, u8 abilityNum, u16* moves);
static u8 GetPlayerDistance(s16 x, s16 y);
static u8 PickTileScreen(u8 targetBehaviour, u8 areaX, u8 areaY, s16 *xBuff, s16 *yBuff, u8 smallScan);
static u8 DexNavPickTile(u8 environment, u8 xSize, u8 ySize, bool8 smallScan);
static void DexNavProximityUpdate(void);
static void DexNavDrawIcons(void);
static void DexNavIconsVisionUpdate(u8 proximity, u8 searchLevel);
static void DexNavSightUpdate(u8 index);
static void Task_DexNavSearch(u8 taskId);

//// Const Data
// image data
static const u32 sDexNavGuiTiles[] = INCBIN_U32("graphics/dexnav/gui_tiles.4bpp.lz");
static const u32 sDexNavGuiTilemap[] = INCBIN_U32("graphics/dexnav/gui_tilemap.bin.lz");
static const u32 sDexNavGuiPal[] = INCBIN_U32("graphics/dexnav/gui.gbapal");

static const u32 sSelectionCursorGfx[] = INCBIN_U32("graphics/dexnav/cursor.4bpp.lz");
static const u16 sSelectionCursorPal[] = INCBIN_U16("graphics/dexnav/cursor.gbapal");

static const u32 sCapturedAllMonsTiles[] = INCBIN_U32("graphics/dexnav/captured_all.4bpp.lz");
static const u32 sCapturedAllMonsPal[] = INCBIN_U32("graphics/dexnav/captured_all.gbapal.lz");

static const u32 sNoDataGfx[] = INCBIN_U32("graphics/dexnav/no_data.4bpp.lz");
static const u8 sPotentialStarsGfx[] = INCBIN_U8("graphics/dexnav/stars.4bpp");
static const u32 sEyeGfx[] = INCBIN_U32("graphics/dexnav/vision.4bpp.lz");


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
//static const u8 sText_DexNav_Searchable[] = _("{STR_VAR_1} searchable via R-button!");
static const u8 sText_DexNav_PressRToRegister[] = _("R TO REGISTER!");
static const u8 sText_DexNav_SearchForRegisteredSpecies[] = _("Search {STR_VAR_1}");
static const u8 sText_DexNav_NotFoundHere[] = _("This Pokémon cannot be found here!");

static const struct WindowTemplate sDexNavGuiWindowTemplates[] =
{
    [WINDOW_INFO] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 5,
        .width = 9,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WINDOW_REGISTERED] =
    {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 0,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 200,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sFontColor_Black[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};
static const u8 sFontColor_White[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY};

//// functions
///////////////////////
//// DEXNAV SEARCH ////
///////////////////////
static s16 GetSearchWindowY(void)
{
    return (GetWindowAttribute(sDexNavSearchDataPtr->windowId, WINDOW_TILEMAP_TOP) * 8);
}

#define SPECIES_ICON_X 26
static void DrawDexNavSearchMonIcon(u16 species, u8 *dst)
{
    u8 spriteId;

    LoadMonIconPalette(species);
    spriteId = CreateMonIcon(species, SpriteCB_MonIcon, SPECIES_ICON_X - 6, GetSearchWindowY() + 8, 0, 0xFFFFFFFF, 0);
    gSprites[spriteId].oam.priority = 0;
    *dst = spriteId;
}

static const u8 sSearchFontColor[3] = {0, 15, 13};
static const u8 sText_Test[] = _("{STR_VAR_1}");
void DrawSearchWindow(u16 species, u8 potential)
{
    struct WindowTemplate template;
    u16 y = 16;
    
    if (sDexNavSearchDataPtr->tileY > (gSaveBlock1Ptr->pos.y + 7))
        y = 1;  //draw at top if chosen tile is below

    LoadDexNavWindowGfx(sDexNavSearchDataPtr->windowId, 0x1d5, 14 * 16);
    
    SetWindowTemplateFields(&template, 0, 1, y, 28, 3, 14, 8);
    
    sDexNavSearchDataPtr->windowId = AddWindow(&template);
    FillWindowPixelBuffer(sDexNavSearchDataPtr->windowId, PIXEL_FILL(15));
    PutWindowTilemap(sDexNavSearchDataPtr->windowId);
    CopyWindowToVram(sDexNavSearchDataPtr->windowId, 3);
    
    DrawStdFrameWithCustomTileAndPalette(sDexNavSearchDataPtr->windowId, TRUE, 0x214, 14);
    
    //species name
    StringCopy(gStringVar1, gSpeciesNames[species]);
    StringExpandPlaceholders(gStringVar4, sText_Test);
    AddTextPrinterParameterized3(sDexNavSearchDataPtr->windowId, 0, SPECIES_ICON_X + 4, 0, sSearchFontColor, TEXT_SPEED_FF, gStringVar4);
    
    // move name
    
    
    // ability name
    
    // item name
    
    CopyWindowToVram(sDexNavSearchDataPtr->windowId, 2);
}

void RemoveHeaderBox(void)
{
    u32 i;
    
    if (sDexNavSearchDataPtr->iconSpriteId != MAX_SPRITES)
        DestroySpriteAndFreeResources(&gSprites[sDexNavSearchDataPtr->iconSpriteId]);
    
    if (sDexNavSearchDataPtr->itemSpriteId != MAX_SPRITES)
        DestroySpriteAndFreeResources(&gSprites[sDexNavSearchDataPtr->itemSpriteId]);

    if (sDexNavSearchDataPtr->eyeSpriteId != MAX_SPRITES)
        DestroySpriteAndFreeResources(&gSprites[sDexNavSearchDataPtr->eyeSpriteId]);
    
    for (i = 0; i < NELEMS(sDexNavSearchDataPtr->starSpriteIds); i++)
    {
        if (sDexNavSearchDataPtr->starSpriteIds[i] != MAX_SPRITES)
            DestroySprite(&gSprites[sDexNavSearchDataPtr->starSpriteIds[i]]);
    }

    ClearStdWindowAndFrameToTransparent(sDexNavSearchDataPtr->windowId, FALSE);
    CopyWindowToVram(sDexNavSearchDataPtr->windowId, 3);
    RemoveWindow(sDexNavSearchDataPtr->windowId);
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
#define tSpecies            data[2]
#define tEnvironment        data[3]
static void Task_InitDexNavSearch(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u16 species = task->tSpecies;
    u8 environment = task->tEnvironment;
    u8 searchLevel;
    
    sDexNavSearchDataPtr = AllocZeroed(sizeof(struct DexNavSearch));
    // assign non-objects to struct
    sDexNavSearchDataPtr->species = species;
    
    if (Overworld_GetFlashLevel() > 0)
    {
        Free(sDexNavSearchDataPtr);
        FreeMonIconPalettes();
        ScriptContext1_SetupScript(EventScript_TooDark);
        DestroyTask(taskId);
        return;
    }
    
    sDexNavSearchDataPtr->environment = environment;
    searchLevel = gSaveBlock1Ptr->dexNavSearchLevels[SpeciesToNationalPokedexNum(species)];
    sDexNavSearchDataPtr->searchLevel = searchLevel;
    sDexNavSearchDataPtr->monLevel = DexNavGenerateMonLevel(species, environment);
    
    DexNavGenerateMoveset(species, searchLevel, sDexNavSearchDataPtr->monLevel, &sDexNavSearchDataPtr->moves[0]);
    sDexNavSearchDataPtr->heldItem = DexNavGenerateHeldItem(species, searchLevel);
    sDexNavSearchDataPtr->abilityNum = DexNavGetAbilityNum(species, searchLevel);
    sDexNavSearchDataPtr->potential = DexNavGeneratePotential(searchLevel);
    
    if (!ShakingGrass(environment, 12, 12, 0))
    {
        Free(sDexNavSearchDataPtr);
        FreeMonIconPalettes();
        ScriptContext1_SetupScript(EventScript_NotFoundNearby);
        DestroyTask(taskId);
        return;
    }
    
    DexNavDrawIcons();
    DexNavProximityUpdate();
    DexNavIconsVisionUpdate(sDexNavSearchDataPtr->proximity, searchLevel);
    FlagSet(FLAG_SYS_DEXNAV_SEARCH);
    gPlayerAvatar.creeping = TRUE;  //initialize as true in case mon appears beside you
    gTasks[taskId].tProximity = gSprites[gPlayerAvatar.spriteId].pos1.x;
    gTasks[taskId].tFrameCount = 0;
    gTasks[taskId].func = Task_DexNavSearch;
    IncrementGameStat(GAME_STAT_DEXNAV_SCANNED);
}

static const struct OamData sHeldItemOam =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .priority = 0,
};
static const struct SpriteTemplate sHeldItemTemplate =
{
    .tileTag = HELD_ITEM_TAG,
    .paletteTag = HELD_ITEM_TAG,
    .oam = &sHeldItemOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static void DrawDexNavSearchHeldItem(u8* dst)
{
    LoadHeldItemIcons();
    *dst = CreateSprite(&sHeldItemTemplate, SPECIES_ICON_X + 6, GetSearchWindowY() + 18, 0);
    if (*dst != MAX_SPRITES)
        gSprites[*dst].invisible = TRUE;
}

static const struct SpriteSheet sStarLitSpriteSheet = {&sPotentialStarsGfx[0], (8 * 8) / 2, LIT_STAR_TILE_TAG};
static const struct SpriteSheet sStarDullSpriteSheet = {&sPotentialStarsGfx[32], (8 * 8) / 2, DULL_STAR_TILE_TAG};
static const struct SpriteTemplate sStarLitTemplate =
{
	.tileTag = LIT_STAR_TILE_TAG,
	.paletteTag = HELD_ITEM_TAG,
	.oam = &sHeldItemOam,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sStarDullTemplate =
{
	.tileTag = DULL_STAR_TILE_TAG,
	.paletteTag = HELD_ITEM_TAG,
	.oam = &sHeldItemOam,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCallbackDummy,
};
static void DexNavDrawPotentialStars(u8 potential, u8* dst)
{
    u8 spriteId;
    u32 i;
    
    LoadSpriteSheet(&sStarLitSpriteSheet);
    LoadSpriteSheet(&sStarDullSpriteSheet);
    //LoadSpritePalette(&sHeldItemSpritePalette);   //already loaded

    for (i = 0; i < NELEMS(sDexNavSearchDataPtr->starSpriteIds); i++)
    {
        if (potential > i)
            spriteId = CreateSprite(&sStarLitTemplate, SPECIES_ICON_X + 23 + (i * 8), GetSearchWindowY() + 5, 0);
        else
            spriteId = CreateSprite(&sStarDullTemplate, SPECIES_ICON_X + 23 + (i * 8), GetSearchWindowY() + 5, 0);

        dst[i] = spriteId;
        gSprites[spriteId].invisible = TRUE;
    }
}

static const struct OamData sSightOam =
{
	.affineMode = ST_OAM_AFFINE_OFF,
	.objMode = ST_OAM_OBJ_NORMAL,
	.shape = SPRITE_SHAPE(16x8),
	.size = SPRITE_SIZE(16x8),
	.priority = 0,
};
static const union AnimCmd sAnimCmdSight0[] =
{
	ANIMCMD_FRAME(0, 1),
	ANIMCMD_END
};
static const union AnimCmd sAnimCmdSight1[] =
{
	ANIMCMD_FRAME(2, 1),
	ANIMCMD_END
};
static const union AnimCmd sAnimCmdSight2[] =
{
	ANIMCMD_FRAME(4, 1),
	ANIMCMD_END
};
static const union AnimCmd *const sAnimCmdTable_Sight[] =
{
	sAnimCmdSight0,
	sAnimCmdSight1,
	sAnimCmdSight2,
};
static const struct CompressedSpriteSheet sSightSpriteSheet = {sEyeGfx, (16 * 8 * 3) / 2, SIGHT_TAG};
static const struct SpriteTemplate sSightTemplate =
{
	.tileTag = SIGHT_TAG,
	.paletteTag = HELD_ITEM_TAG,
	.oam = &sSightOam,
	.anims = sAnimCmdTable_Sight,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCallbackDummy,
};
static void DexNavDrawSight(u8 sightLevel, u8* dst)
{
	LoadCompressedSpriteSheetUsingHeap(&sSightSpriteSheet);
	//LoadSpritePalette(&sHeldItemSpritePalette);
	*dst = CreateSprite(&sSightTemplate, 176 + (16 / 2), GetSearchWindowY() + 18, 0);
	if (*dst != MAX_SPRITES)
		DexNavSightUpdate(sightLevel);
};

static void DexNavDrawIcons(void)
{
    u8 searchLevel = sDexNavSearchDataPtr->searchLevel;
    u16 species = sDexNavSearchDataPtr->species;
    
    // init sprite ids
    /*sDexNavSearchDataPtr->iconSpriteId = 0xFF;
    sDexNavSearchDataPtr->itemSpriteId = 0xFF;
    for (i = 0; i < NELEMS(sDexNavSearchDataPtr->starSpriteIds); i++)
        sDexNavSearchDataPtr->starSpriteIds[i] = 0xFF;*/
    
    DrawSearchWindow(species, sDexNavSearchDataPtr->potential);
    DrawDexNavSearchMonIcon(species, &sDexNavSearchDataPtr->iconSpriteId);
    DrawDexNavSearchHeldItem(&sDexNavSearchDataPtr->itemSpriteId);
    DexNavDrawSight(sDexNavSearchDataPtr->proximity, &sDexNavSearchDataPtr->eyeSpriteId);
    DexNavDrawPotentialStars(sDexNavSearchDataPtr->potential, &sDexNavSearchDataPtr->starSpriteIds[0]);
}

/////////////////////
//// SEARCH TASK ////
/////////////////////
void EndDexNavSearch(u8 taskId)
{
    FlagClear(FLAG_SYS_DEXNAV_SEARCH);
    DestroyTask(taskId);
    RemoveHeaderBox();
    FieldEffectStop(&gSprites[sDexNavSearchDataPtr->fldEffSpriteId], sDexNavSearchDataPtr->fldEffId);
    Free(sDexNavSearchDataPtr);
    FreeMonIconPalettes();
}

static void EndDexNavSearchSetupScript(const u8 *script, u8 taskId)
{
    gCurrentDexNavChain = 0;   //reset chain
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

static void Task_DexNavSearch(u8 taskId)
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
        //gCurrentDexNavChain = 0;  //issue with reusable repels
        EndDexNavSearch(taskId);
        return;
    }
    
    if (JOY_NEW(B_BUTTON | START_BUTTON))
    { //player manually canceled
        gCurrentDexNavChain = 0;
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
        FlagClear(FLAG_SYS_DEXNAV_SEARCH);
        CreateDexNavWildMon(sDexNavSearchDataPtr->species, sDexNavSearchDataPtr->potential, sDexNavSearchDataPtr->monLevel, 
          sDexNavSearchDataPtr->abilityNum, sDexNavSearchDataPtr->moves);
                
        gDexnavBattle = TRUE;
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

        // find new 
        while (1) {
            if (ShakingGrass(sDexNavSearchDataPtr->environment, 8, 8, 1))
                break;
        }
        
        sDexNavSearchDataPtr->movementCount++;
    }

    DexNavProximityUpdate();
    if (task->tProximity != sDexNavSearchDataPtr->proximity)
    {
        DexNavIconsVisionUpdate(sDexNavSearchDataPtr->proximity, sDexNavSearchDataPtr->searchLevel);
        task->tProximity = sDexNavSearchDataPtr->proximity;
    }
    
    task->tFrameCount++;
}

static void DexNavSightUpdate(u8 index)
{
	u8 spriteId = sDexNavSearchDataPtr->eyeSpriteId;
    
	if (spriteId != MAX_SPRITES)
		StartSpriteAnim(&gSprites[spriteId], index);
}

static void DexNavIconsVisionUpdate(u8 proximity, u8 searchLevel)
{
    // The sight eye and species icon are always drawn in the window
    //     At search level 2, first move is drawn
    //     At search level 3, Ability and Held item are drawn
    //     At search level 5, Potential is drawn
    u32 i;
    
    if (proximity < 3)
    {
        // at proximity 5, the sight should start to show and indicate sneaking is required
        DexNavSightUpdate(0);
        if (searchLevel > 1)
        {
            //// show move, hide others
            //if (sDexNavSearchDataPtr->spriteIdMove != MAX_SPRITES)
                //gSprites[sDexNavSearchDataPtr->spriteIdMove].invisible = FALSE;
        }
        if (searchLevel > 2)
        {
            // show ability, move, hide others
            //if (sDexNavSearchDataPtr->spriteIdAbility != MAX_SPRITES)
                //gSprites[sDexNavSearchDataPtr->spriteIdAbility].invisible = FALSE;
            if (sDexNavSearchDataPtr->heldItem)
            {
                // toggle item view
                if (sDexNavSearchDataPtr->itemSpriteId != MAX_SPRITES)
                    gSprites[sDexNavSearchDataPtr->itemSpriteId].invisible = FALSE;
            }
        }
        if (searchLevel > 4)
        {
            if (sDexNavSearchDataPtr->starSpriteIds[0] != MAX_SPRITES)
                gSprites[sDexNavSearchDataPtr->starSpriteIds[0]].invisible = FALSE;

            if (sDexNavSearchDataPtr->starSpriteIds[1] != MAX_SPRITES)
                gSprites[sDexNavSearchDataPtr->starSpriteIds[1]].invisible = FALSE;

            if (sDexNavSearchDataPtr->starSpriteIds[2] != MAX_SPRITES)
                gSprites[sDexNavSearchDataPtr->starSpriteIds[2]].invisible = FALSE;
        }
    }
    else if (proximity <= SNEAKING_PROXIMITY)
    {
        DexNavSightUpdate(1); // Sneaking is required flag
    }
    else
    {
        DexNavSightUpdate(2); // Sneaking is not required
    }
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
    u8 charmBonus, randBonus, chainBonus;
    u8 numChecks = 0;
    
    // get num shiny rolls
    #ifdef ITEM_SHINY_CHARM
    charmBonus = (CheckBagHasItem(ITEM_SHINY_CHARM, 1) > 0) ? 2 : 0;
    #else
    charmBonus = 0;
    #endif
    chainBonus = (gCurrentDexNavChain == 50) ? 5 : (gCurrentDexNavChain == 100) ? 10 : 0;
    randBonus = (Random() % 100 < 4 ? 4 : 0);
    numChecks = 1 + charmBonus + chainBonus + randBonus;
    
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

static u8 DexNavGenerateMonLevel(u16 species, u8 environment)
{
    u8 levelBase;
    u8 levelBonus;

    levelBase = GetEncounterLevel(species, environment);
    if (levelBase > MAX_LEVEL)
        return 0;

    levelBonus = gCurrentDexNavChain / 5;

    if (Random() % 100 < 4) //4% chance of having a +10 level
        levelBonus += 10;

    if (levelBase + levelBonus > MAX_LEVEL)
        return MAX_LEVEL;
    else
        return levelBase + levelBonus;
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
    //CreateWildMon(species, encounterLevel);

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
    if (genAbility && gBaseStats[species].abilityHidden != ABILITY_NONE && GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        abilityNum = 2;
    }
    else
    {
        //Pick a normal ability of that Pokemon
        if (gBaseStats[species].abilities[1] != ABILITY_NONE)
            abilityNum = Random() & 1;
        else
            abilityNum = 0;   // ability1
        
        sDexNavSearchDataPtr->abilityNum = abilityNum;
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

        for (i = 0; i < LAND_WILD_COUNT; i++)
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

        for (i = 0; i < WATER_WILD_COUNT; i++)
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

bool8 TryStartDexnavSearch(void)
{
    u8 taskId;
    u16 val = VarGet(VAR_DEXNAV_SPECIES);
    
    if (FlagGet(FLAG_SYS_DEXNAV_SEARCH) || (val & 0x7FFF) == SPECIES_NONE)
        return FALSE;
    
    taskId = CreateTask(Task_InitDexNavSearch, 0);
    gTasks[taskId].tSpecies = val & 0x7FFF;
    gTasks[taskId].tEnvironment = val >> 15;
    PlaySE(SE_DEX_SEARCH);
    return FALSE;   //we dont actually want to enable the script context
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
    switch (sDexNavUiDataPtr->state)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sDexNavGuiTiles, 0, 0, 0);
        sDexNavUiDataPtr->state++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sDexNavGuiTilemap, sBg1TilemapBuffer);
            sDexNavUiDataPtr->state++;
        }
        break;
    case 2:
        LoadPalette(sDexNavGuiPal, 0, 32);
        sDexNavUiDataPtr->state++;
        break;
    default:
        sDexNavUiDataPtr->state = 0;
        return TRUE;
    }
    
    return FALSE;
}

static void UpdateCursorPosition(void)
{
    u16 x, y;
    
    switch (sDexNavUiDataPtr->cursorRow)
    {
    case ROW_WATER:
        x = ROW_WATER_ICON_X + (24 * sDexNavUiDataPtr->cursorCol);
        y = ROW_WATER_ICON_Y;
        break;
    case ROW_LAND_TOP: //land 1
        x = ROW_LAND_ICON_X + (24 * sDexNavUiDataPtr->cursorCol);
        y = ROW_LAND_TOP_ICON_Y;
        break;
    case ROW_LAND_BOT: //land 2
        x = ROW_LAND_ICON_X + (24 * sDexNavUiDataPtr->cursorCol);
        y = ROW_LAND_BOT_ICON_Y;
        break;
    case ROW_HIDDEN:
        x = ROW_HIDDEN_ICON_X + (24 * sDexNavUiDataPtr->cursorCol);
        y = ROW_HIDDEN_ICON_Y;
        break;
    default:
        return;
    }
    
    gSprites[sDexNavUiDataPtr->cursorSpriteId].pos1.x = x;
    gSprites[sDexNavUiDataPtr->cursorSpriteId].pos1.y = y;
    
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
    .paletteNum = 12,
    .affineParam = 0
};
static const struct SpriteTemplate sSelectionCursorSpriteTemplate =
{
    .tileTag = SELECTION_CURSOR_TAG,
    .paletteTag = 0xFFFF,
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
    //gSprites[spriteId].data[1] = -1;
    
    sDexNavUiDataPtr->cursorSpriteId = spriteId;
    UpdateCursorPosition();
}

static const struct OamData sNoDataIconOam =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};
static const struct SpriteTemplate sNoDataIconTemplate =
{
    .tileTag = ICON_GFX_TAG,
    .paletteTag = ICON_PAL_TAG,
    .oam = &sNoDataIconOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct CompressedSpriteSheet sNoDataIconSpriteSheet = {sNoDataGfx, (32 * 32) / 2, ICON_GFX_TAG};
static void CreateNoDataIcon(s16 x, s16 y)
{
    CreateSprite(&sNoDataIconTemplate, x, y, 0);
}

static bool8 CapturedAllLandMons(u8 headerId)
{
    u16 i, species;
    int count = 0;
    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
        
    if (landMonsInfo != NULL)
    {        
        for (i = 0; i < LAND_WILD_COUNT; ++i)
        {
            species = landMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE)
            {
                if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                    break;
                
                count++;
            }
        }

        if (i >= LAND_WILD_COUNT && count > 0) //All land mons caught
            return TRUE;
    }
    else
    {
        return TRUE;    //technically, no mon data means you caught them all
    }

    return FALSE;
}

//Checks if all Pokemon that can be encountered while surfing have been capture
static bool8 CapturedAllWaterMons(u8 headerId)
{
    u32 i;
    u16 species;
    u8 count = 0;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

    if (waterMonsInfo != NULL)
    {
        for (i = 0; i < WATER_WILD_COUNT; ++i)
        {
            species = waterMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE)
            {
                count++;
                if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                    break;
            }
        }

        if (i >= WATER_WILD_COUNT && count > 0)
            return TRUE;
    }
    else
    {
        return TRUE;    //technically, no mon data means you caught them all
    }

    return FALSE;
}

static bool8 CapturedAllHiddenMons(u8 headerId)
{
    u32 i;
    u16 species;
    u8 count = 0;
    const struct WildPokemonInfo* hiddenMonsInfo = gWildMonHeaders[headerId].hiddenMonsInfo;
    
    if (hiddenMonsInfo != NULL)
    {
        for (i = 0; i < WATER_WILD_COUNT; ++i)
        {
            species = hiddenMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE)
            {
                count++;
                if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                    break;
            }
        }

        if (i >= WATER_WILD_COUNT && count > 0)
            return TRUE;
    }
    else
    {
        return TRUE;    //technically, no mon data means you caught them all
    }

    return FALSE;
}

static const struct CompressedSpriteSheet sCapturedAllPokemonSpriteSheet = {sCapturedAllMonsTiles, (8 * 8) / 2, CAPTURED_ALL_TAG};
static const struct OamData sCapturedAllOam =
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
    .paletteNum = 12,
    .affineParam = 0,
};
static const struct SpriteTemplate sCaptureAllMonsSpriteTemplate =
{
    .tileTag = CAPTURED_ALL_TAG,
    .paletteTag = 0xFFFF,
    .oam = &sCapturedAllOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static void DexNavLoadCapturedAllSymbols(void)
{
    u8 headerId = GetCurrentMapWildMonHeaderId();
    
    LoadCompressedSpriteSheetUsingHeap(&sCapturedAllPokemonSpriteSheet);

    if (CapturedAllLandMons(headerId))
        CreateSprite(&sCaptureAllMonsSpriteTemplate, 152, 58, 0);

    if (CapturedAllWaterMons(headerId))
        CreateSprite(&sCaptureAllMonsSpriteTemplate, 139, 17, 0);
    
    if (CapturedAllHiddenMons(headerId))
        CreateSprite(&sCaptureAllMonsSpriteTemplate, 114, 123, 0);
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
    Free(sDexNavUiDataPtr);
    Free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}

static void CB1_InitDexNavSearch(void)
{
    u8 taskId;
    
    if (!gPaletteFade.active && !ScriptContext2_IsEnabled() && gMain.callback2 == CB2_Overworld)
    {
        SetMainCallback1(CB1_Overworld);
        taskId = CreateTask(Task_InitDexNavSearch, 0);
        gTasks[taskId].tSpecies = gSpecialVar_0x8000;
        gTasks[taskId].tEnvironment = gSpecialVar_0x8001;
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
        SetMainCallback2(sDexNavUiDataPtr->savedCallback);
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

static bool8 SpeciesInArray(u16 species, u8 section)
{
    u32 i;
    u16 dexNum = SpeciesToNationalPokedexNum(species);
    
    switch (section)
    {
    case 0: //land
        for (i = 0; i < LAND_WILD_COUNT; i++)
        {
            if (SpeciesToNationalPokedexNum(sDexNavUiDataPtr->landSpecies[i]) == dexNum)
                return TRUE;
        }
        break;
    case 1: //water
        for (i = 0; i < WATER_WILD_COUNT; i++)
        {
            if (SpeciesToNationalPokedexNum(sDexNavUiDataPtr->waterSpecies[i]) == dexNum)
                return TRUE;
        }
        break;
    case 2: //hidden
        for (i = 0; i < HIDDEN_WILD_COUNT; i++)
        {
            if (SpeciesToNationalPokedexNum(sDexNavUiDataPtr->hiddenSpecies[i]) == dexNum)
                return TRUE;
        }
        break;
    default:
        break;
    }
    
    return FALSE;
}

// get unique wild encounters on current map
static void DexNavLoadEncounterData(void)
{
    u8 grassIndex = 0;
    u8 waterIndex = 0;
    u8 hiddenIndex = 0;
    u16 species;
    u32 i;
    u16 headerId = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    const struct WildPokemonInfo* hiddenMonsInfo = gWildMonHeaders[headerId].hiddenMonsInfo;
    
    // nop struct data
    memset(sDexNavUiDataPtr->landSpecies, 0, sizeof(sDexNavUiDataPtr->landSpecies));
    memset(sDexNavUiDataPtr->waterSpecies, 0, sizeof(sDexNavUiDataPtr->waterSpecies));
    memset(sDexNavUiDataPtr->hiddenSpecies, 0, sizeof(sDexNavUiDataPtr->hiddenSpecies));
    
    // land mons
    if (landMonsInfo != NULL)
    {
        for (i = 0; i < LAND_WILD_COUNT; i++)
        {
            species = landMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, 0))
                sDexNavUiDataPtr->landSpecies[grassIndex++] = landMonsInfo->wildPokemon[i].species;
        }
    }

    // water mons
    if (waterMonsInfo != NULL)
    {
        for (i = 0; i < WATER_WILD_COUNT; i++)
        {
            species = waterMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, 1))
                sDexNavUiDataPtr->waterSpecies[waterIndex++] = waterMonsInfo->wildPokemon[i].species;
        }
    }
    
    // hidden mons
    if (hiddenMonsInfo != NULL)
    {
        for (i = 0; i < HIDDEN_WILD_COUNT; i++)
        {
            species = hiddenMonsInfo->wildPokemon[i].species;
            if (species != SPECIES_NONE && !SpeciesInArray(species, 2))
                sDexNavUiDataPtr->hiddenSpecies[hiddenIndex++] = hiddenMonsInfo->wildPokemon[i].species;
        }
    }
}

static void TryDrawIconInSlot(u16 species, s16 x, s16 y)
{
    if (species == SPECIES_NONE)
        CreateNoDataIcon(x, y);   //'X' in slot
    else if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_SEEN))
        CreateMonIcon(SPECIES_NONE, SpriteCB_MonIcon, x, y, 0, 0xFFFFFFFF, 0); //question mark
    else
        CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, 0xFFFFFFFF, 0);
}

static void DrawSpeciesIcons(void)
{
    s16 x, y;
    u32 i;
    u16 species;
    
    LoadCompressedSpriteSheetUsingHeap(&sNoDataIconSpriteSheet);
    for (i = 0; i < LAND_WILD_COUNT; i++)
    {
        species = sDexNavUiDataPtr->landSpecies[i];
        x = 20 + (24 * (i % 6));
        y = ROW_LAND_TOP_ICON_Y + (i > 5 ? 28 : 0);
        TryDrawIconInSlot(species, x, y);
    }
    
    for (i = 0; i < WATER_WILD_COUNT; i++)
    {
        species = sDexNavUiDataPtr->waterSpecies[i];
        x = 30 + 24 * i;
        y = ROW_WATER_ICON_Y;
        TryDrawIconInSlot(species, x, y);
    }
    
    for (i = 0; i < HIDDEN_WILD_COUNT; i++)
    {
        species = sDexNavUiDataPtr->hiddenSpecies[i];
        x = ROW_HIDDEN_ICON_X + 24 * i;
        y = ROW_HIDDEN_ICON_Y;
        TryDrawIconInSlot(species, x, y);
    }
}

static u16 DexNavGetSpecies(void)
{
    u16 species;
    
    switch (sDexNavUiDataPtr->cursorRow)
    {
    case ROW_WATER:
        species = sDexNavUiDataPtr->waterSpecies[sDexNavUiDataPtr->cursorCol];
        break;
    case ROW_LAND_TOP:
        species = sDexNavUiDataPtr->landSpecies[sDexNavUiDataPtr->cursorCol];
        break;
    case ROW_LAND_BOT:
        species = sDexNavUiDataPtr->landSpecies[sDexNavUiDataPtr->cursorCol + COL_LAND_COUNT];
        break;
    case ROW_HIDDEN:
        species = sDexNavUiDataPtr->hiddenSpecies[sDexNavUiDataPtr->cursorCol];
        break;
    default:
        return SPECIES_NONE;
    }
    
    if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_SEEN))
        return SPECIES_NONE;
    
    return species;
}

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sDexNavUiDataPtr->typeIconSpriteIds[spriteArrayId]].invisible = invisible;
}

// different from pokemon_summary_screen
#define TYPE_ICON_PAL_NUM_0     13
#define TYPE_ICON_PAL_NUM_1     14
#define TYPE_ICON_PAL_NUM_2     15
static const u8 sMoveTypeToOamPaletteNum[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NORMAL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FIGHTING] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FLYING] = TYPE_ICON_PAL_NUM_1,
    [TYPE_POISON] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GROUND] = TYPE_ICON_PAL_NUM_0,
    [TYPE_ROCK] = TYPE_ICON_PAL_NUM_0,
    [TYPE_BUG] = TYPE_ICON_PAL_NUM_2,
    [TYPE_GHOST] = TYPE_ICON_PAL_NUM_1,
    [TYPE_STEEL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_MYSTERY] = TYPE_ICON_PAL_NUM_2,
    [TYPE_FIRE] = TYPE_ICON_PAL_NUM_0,
    [TYPE_WATER] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GRASS] = TYPE_ICON_PAL_NUM_2,
    [TYPE_ELECTRIC] = TYPE_ICON_PAL_NUM_0,
    [TYPE_PSYCHIC] = TYPE_ICON_PAL_NUM_1,
    [TYPE_ICE] = TYPE_ICON_PAL_NUM_1,
    [TYPE_DRAGON] = TYPE_ICON_PAL_NUM_2,
    [TYPE_DARK] = TYPE_ICON_PAL_NUM_0,
};
static void SetTypeIconPosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite;
        
    sprite = &gSprites[sDexNavUiDataPtr->typeIconSpriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[typeId];
    sprite->pos1.x = x + 16;
    sprite->pos1.y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}

static void PrintCurrentSpeciesInfo(void)
{
    u8 searchLevelBonus = 0;
    u16 species = DexNavGetSpecies();
    u32 i;
    u16 dexNum = SpeciesToNationalPokedexNum(species);
    u8 type1, type2;
    
    if (!GetSetPokedexFlag(dexNum, FLAG_GET_SEEN))
        species = SPECIES_NONE;

    // clear windows
    FillWindowPixelBuffer(WINDOW_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    
    //species name
    if (species == SPECIES_NONE)
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, SPECIES_INFO_Y, sFontColor_Black, 0, sText_DexNav_NoInfo);
    else
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, SPECIES_INFO_Y, sFontColor_Black, 0, gSpeciesNames[species]);
    
    //type icon(s)
    type1 = gBaseStats[species].type1;
    type2 = gBaseStats[species].type2;
    if (species == SPECIES_NONE)
        type1 = type2 = TYPE_MYSTERY;
    
    if (type1 == type2)
    {
        SetTypeIconPosAndPal(type1, 186, 69, 0);
        SetSpriteInvisibility(1, TRUE);
    }
    else
    {
        SetTypeIconPosAndPal(type1, 168, 69, 0);
        SetTypeIconPosAndPal(type2, 168 + 33, 69, 1);
    }
    
    //search level
    if (species == SPECIES_NONE)
    {
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, SEARCH_LEVEL_Y, sFontColor_Black, 0, sText_DexNav_NoInfo);
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar4, gSaveBlock1Ptr->dexNavSearchLevels[dexNum], 0, 4);
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, SEARCH_LEVEL_Y, sFontColor_Black, 0, gStringVar4);
    }
    
    // search bonus
    if ((gSaveBlock1Ptr->dexNavSearchLevels[dexNum] >> 2) > 20)
        searchLevelBonus = 20;
    else
        searchLevelBonus = (gSaveBlock1Ptr->dexNavSearchLevels[dexNum] >> 2);
    
    ConvertIntToDecimalStringN(gStringVar4, searchLevelBonus, 0, 4);
    if (species == SPECIES_NONE)
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, LEVEL_BONUS_Y, sFontColor_Black, 0, sText_DexNav_NoInfo);
    else
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, LEVEL_BONUS_Y, sFontColor_Black, 0, gStringVar4);
    
    //hidden ability
    if (species == SPECIES_NONE)
    {
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, HA_INFO_Y, sFontColor_Black, 0, sText_DexNav_NoInfo);
    }
    else if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT))
    {
        if (gBaseStats[species].abilityHidden != ABILITY_NONE)
            AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, HA_INFO_Y, sFontColor_Black, 0, gAbilityNames[gBaseStats[species].abilityHidden]);
        else
            AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, HA_INFO_Y, sFontColor_Black, 0, gText_None);
    }
    else
    {
        AddTextPrinterParameterized3(WINDOW_INFO, 0, 0, HA_INFO_Y, sFontColor_Black, 0, sText_DexNav_CaptureToSee);
    }
    
    CopyWindowToVram(WINDOW_INFO, 3);
    PutWindowTilemap(WINDOW_INFO);
}

static void PrintMapName(void)
{
    GetMapName(gStringVar3, GetCurrentRegionMapSectionId(), 0);
    AddTextPrinterParameterized3(WINDOW_REGISTERED, 2, 108 +
      GetStringRightAlignXOffset(2, gStringVar3, MAP_NAME_LENGTH * GetFontAttribute(2, FONTATTR_MAX_LETTER_WIDTH)), 0, sFontColor_White, 0, gStringVar3);
    CopyWindowToVram(WINDOW_REGISTERED, 3);
}

static void PrintSearchableSpecies(u16 species)
{
    FillWindowPixelBuffer(WINDOW_REGISTERED, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_REGISTERED);
    if (species == SPECIES_NONE)
    {
        AddTextPrinterParameterized3(WINDOW_REGISTERED, 2, 0, 0, sFontColor_White, TEXT_SPEED_FF, sText_DexNav_PressRToRegister);
    }
    else
    {
        StringCopy(gStringVar1, gSpeciesNames[species]);
        StringExpandPlaceholders(gStringVar4, sText_DexNav_SearchForRegisteredSpecies);
        AddTextPrinterParameterized3(WINDOW_REGISTERED, 2, 0, 0, sFontColor_White, TEXT_SPEED_FF, gStringVar4);
    }
    
    PrintMapName();
}

static void CreateTypeIconSprites(void)
{
    u8 i;

    LoadCompressedSpriteSheet(&gSpriteSheet_MoveTypes);
    LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
    for (i = 0; i < 2; i++)
    {
        if (sDexNavUiDataPtr->typeIconSpriteIds[i] == 0xFF)
            sDexNavUiDataPtr->typeIconSpriteIds[i] = CreateSprite(&gSpriteTemplate_MoveTypes, 10, 10, 2);    
    
        SetSpriteInvisibility(i, TRUE);
    }
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
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 4:
        if (DexNav_InitBgs())
        {
            sDexNavUiDataPtr->state = 0;
            gMain.state++;
        }
        else
        {
            DexNavFadeAndExit();
            return TRUE;
        }
        break;
    case 5:
        if (DexNav_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 6:
        DexNav_InitWindows();
        sDexNavUiDataPtr->cursorRow = ROW_LAND_TOP;
        sDexNavUiDataPtr->cursorCol = 0;
        sDexNavUiDataPtr->environment = ENCOUNTER_TYPE_LAND;
        gMain.state++;
        break;
    case 7:
        PrintSearchableSpecies(VarGet(VAR_DEXNAV_SPECIES));
        DexNavLoadEncounterData();
        gMain.state++;
        break;
    case 8:
        taskId = CreateTask(Task_DexNavWaitFadeIn, 0);
        gTasks[taskId].tSpecies = 0;
        gTasks[taskId].tEnvironment = sDexNavUiDataPtr->environment;
        gMain.state++;
        break;
    case 9:
        sDexNavUiDataPtr->typeIconSpriteIds[0] = 0xFF;
        sDexNavUiDataPtr->typeIconSpriteIds[1] = 0xFF;
        CreateTypeIconSprites();
        gMain.state++;
        break;
    case 10:
        LoadMonIconPalettes();
        DrawSpeciesIcons();
        CreateSelectionCursor();
        DexNavLoadCapturedAllSymbols();
        gMain.state++;
        break;
    case 11:
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 12:
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
    if ((sDexNavUiDataPtr = AllocZeroed(sizeof(struct DexNavGUI))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    sDexNavUiDataPtr->state = 0;
    sDexNavUiDataPtr->savedCallback = callback;
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
        if (sDexNavUiDataPtr->cursorRow == ROW_WATER)
        {
            sDexNavUiDataPtr->cursorRow = ROW_HIDDEN;
            sDexNavUiDataPtr->environment = ENCOUNTER_TYPE_HIDDEN;
            if (sDexNavUiDataPtr->cursorCol >= COL_HIDDEN_COUNT)
                sDexNavUiDataPtr->cursorCol = COL_HIDDEN_MAX;
        }
        else
        {
            if (sDexNavUiDataPtr->cursorRow == ROW_LAND_TOP && sDexNavUiDataPtr->cursorCol == COL_LAND_MAX)
                sDexNavUiDataPtr->cursorCol = COL_WATER_MAX;
            
            sDexNavUiDataPtr->cursorRow--;
        }
        
        PlaySE(SE_RG_BAG_CURSOR);
        UpdateCursorPosition();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sDexNavUiDataPtr->cursorRow == ROW_HIDDEN)
        {
            sDexNavUiDataPtr->cursorRow = ROW_WATER;
            sDexNavUiDataPtr->environment = ENCOUNTER_TYPE_WATER;
        }
        else if (sDexNavUiDataPtr->cursorRow == ROW_LAND_BOT)
        {
            if (sDexNavUiDataPtr->cursorCol >= COL_HIDDEN_COUNT)
                sDexNavUiDataPtr->cursorCol = COL_HIDDEN_MAX;
            
            sDexNavUiDataPtr->environment = ENCOUNTER_TYPE_HIDDEN;
            sDexNavUiDataPtr->cursorRow++;
        }
        else
        {
            sDexNavUiDataPtr->cursorRow++;
        }
        
        PlaySE(SE_RG_BAG_CURSOR);
        UpdateCursorPosition();
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (sDexNavUiDataPtr->cursorCol == 0)
        {
            switch (sDexNavUiDataPtr->cursorRow)
            {
            case ROW_WATER:
                sDexNavUiDataPtr->cursorCol = COL_WATER_MAX;
                break;
            case ROW_HIDDEN:
                sDexNavUiDataPtr->cursorCol = COL_HIDDEN_MAX;
                break;
            default:
                sDexNavUiDataPtr->cursorCol = COL_LAND_MAX;
                break;
            }
        }
        else
        {
            sDexNavUiDataPtr->cursorCol--;
        }
        
        PlaySE(SE_RG_BAG_CURSOR);
        UpdateCursorPosition();
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        switch (sDexNavUiDataPtr->cursorRow)
        {
        case ROW_WATER:
            if (sDexNavUiDataPtr->cursorCol == COL_WATER_MAX)
                sDexNavUiDataPtr->cursorCol = 0;
            else
                sDexNavUiDataPtr->cursorCol++;
            break;
        case ROW_HIDDEN:
            if (sDexNavUiDataPtr->cursorCol == COL_HIDDEN_MAX)
                sDexNavUiDataPtr->cursorCol = 0;
            else
                sDexNavUiDataPtr->cursorCol++;
            break;
        default:
            if (sDexNavUiDataPtr->cursorCol == COL_LAND_MAX)
                sDexNavUiDataPtr->cursorCol = 0;
            else
                sDexNavUiDataPtr->cursorCol++;
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
            PrintSearchableSpecies(species);
            //PlaySE(SE_DEX_SEARCH);
            PlayCry5(species, 0);
            
            // create value to store in a var
            VarSet(VAR_DEXNAV_SPECIES, ((species & 0x7FFF) | sDexNavUiDataPtr->environment << 15));
        }
        else
        {
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
            gSpecialVar_0x8000 = species;
            gSpecialVar_0x8001 = sDexNavUiDataPtr->environment;
            PlaySE(SE_DEX_SEARCH);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            task->func = Task_DexNavExitAndSearch;
        }
    }
}


/////////////////////////
//// GENERAL UTILITY ////
/////////////////////////
void TryIncrementSpeciesSearchLevel(u16 dexNum)
{
    if (gMapHeader.regionMapSectionId != MAPSEC_BATTLE_FRONTIER && gSaveBlock1Ptr->dexNavSearchLevels[dexNum] < 255)
        gSaveBlock1Ptr->dexNavSearchLevels[dexNum]++;
}

bool8 TryFindHiddenPokemon(void)
{
    // to do
    u16 *stepPtr = GetVarPointer(VAR_DEXNAV_STEP_COUNTER);
    
    (*stepPtr)++;
    (*stepPtr) %= HIDDEN_POKEMON_STEP_COUNT;
    
    /*if ((*stepPtr) == 0 && (Random() % 100 < HIDDEN_POKEMON_RATE))
    {
        // hidden pokemon
        const struct WildPokemonInfo* info;
        u8 headerId = GetCurrentMapWildMonHeaderId();
        u8 index = Random() % (LAND_WILD_COUNT + WATER_WILD_COUNT + HIDDEN_WILD_COUNT);
        
        switch (gWildMonHeaders[headerId].encounterRate)        %encounter rate signifies surfing or land mons!
        
        if (index < LAND_WILD_COUNT)
            info = WildPokemonInfo* = gWildMonHeaders[headerId].
        else if (index < (LAND_WILD_COUNT + WATER_WILD_COUNT))
    }*/
    
    return FALSE;
}

void ResetDexNavSearch(void)
{
    gCurrentDexNavChain = 0;    //reset dex nav chaining on new map
    VarSet(VAR_DEXNAV_STEP_COUNTER, 0); //reset hidden pokemon step counter
    if (FlagGet(FLAG_SYS_DEXNAV_SEARCH))
        EndDexNavSearch(FindTaskIdByFunc(Task_DexNavSearch));   //moving to new map ends dexnav search
}

void DebugDexNav(void)
{
    u32 i;
    
    /*EnableNationalPokedex();
    
    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        GetSetPokedexFlag(i, FLAG_SET_SEEN);
        GetSetPokedexFlag(i, FLAG_GET_CAUGHT);
    }*/
}

