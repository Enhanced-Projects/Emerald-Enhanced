#include "global.h"
#include "bg.h"
#include "cutscene.h"
#include "menu_helpers.h"
#include "palette.h"
#include "constants/rgb.h"
#include "constants/vars.h"

static const u8 sDefaultCutsceneTilemap[] = INCBIN_U8("graphics/cutscene/fscutscene/default_tilemap.bin");

static const u8 sDawnCutsceneBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/tiles.8bpp");
static const u8 sDawnCutsceneBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/map.bin");
static const u8 sDawnCutsceneBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/tiles.gbapal");

static const u8 sDawnCutsceneBgNightTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/night_tiles.8bpp");
static const u8 sDawnCutsceneBgNightMap[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/night_map.bin");
static const u8 sDawnCutsceneBgNightPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/night_tiles.gbapal");

static const u8 sSunsetBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/sunset/sunset_tiles.4bpp");
static const u8 sSunsetBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/sunset/sunset_map.bin");
static const u8 sSunsetBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/sunset/sunset_palette.gbapal");

static const u8 sMinnieBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/minnie/minnie_tiles.8bpp");
static const u8 sMinnieBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/minnie/minnie_map.bin");
static const u8 sMinnieBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/minnie/minnie_palette.gbapal");

static const u8 sMeloettaBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/meloetta/meloetta_tiles.4bpp");
static const u8 sMeloettaBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/meloetta/meloetta_map.bin");
static const u8 sMeloettaBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/meloetta/meloetta_palette.gbapal");

static const u8 sShellyBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/shelly/shelly_tiles.8bpp");
static const u8 sShellyBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/shelly/shelly_map.bin");
static const u8 sShellyBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/shelly/shelly_palette.gbapal");

static const u8 sMawileBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/mawile/mawile.8bpp");
static const u8 sMawileBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/mawile/mawile_tiles.bin");
static const u8 sMawileBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/mawile/mawile.gbapal");


static const u8 sBrendanBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/brendan/brendan_tiles.8bpp");
static const u8 sBrendanBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/brendan/brendan_map.bin");
static const u8 sBrendanBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/brendan/brendan_palette.gbapal");


static const u8 sBrendanNightBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/brendan/brendan_night_tiles.8bpp");
static const u8 sBrendanNightBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/brendan/brendan_night_map.bin");
static const u8 sBrendanNightBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/brendan/brendan_night_palette.gbapal");

static const u8 sLeafBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/leaf/leaf_tiles.8bpp");
static const u8 sLeafBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/leaf/leaf_map.bin");
static const u8 sLeafBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/leaf/leaf_palette.gbapal");

static const u8 sMiningMapBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/maps/mining_map_tiles.4bpp");
static const u8 sMiningMapBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/maps/mining_map.bin");
static const u8 sMiningMapBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/maps/mining_map_palette.gbapal");

static const u8 sCourtneyBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/courtney/courtney_tiles.8bpp");
static const u8 sCourtneyBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/courtney/courtney_map.bin");
static const u8 sCourtneyBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/courtney/courtney.gbapal");

static const u8 sHeatranBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/heatran/heatran_tiles.8bpp");
static const u8 sHeatranBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/heatran/heatran_map.bin");
static const u8 sHeatranBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/heatran/heatran.gbapal");

static const u8 sNurseBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/nurse/nurse_tiles.8bpp");
static const u8 sNurseBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/nurse/nurse_map.bin");
static const u8 sNurseBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/nurse/nurse_palette.gbapal");

static const u8 sNurseNightBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/nurse/night_tiles.8bpp");
static const u8 sNurseNightBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/nurse/night_map.bin");
static const u8 sNurseNightBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/nurse/night_palette.gbapal");

static const u8 sPidgeyScreenshotTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/pidgey_scrsht/pidgey_pc.4bpp");
static const u8 sPidgeyScreenshotMap[] = INCBIN_U8("graphics/cutscene/fscutscene/pidgey_scrsht/pidgey_pc.bin");
static const u8 sPidgeyScreenshotPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/pidgey_scrsht/pidgey_pc.gbapal");

static const u8 sGameOverBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/gameover/gameover_tiles.8bpp");
static const u8 sGameOverBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/gameover/gameover_map.bin");
static const u8 sGameOverBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/gameover/gameover_palette.gbapal");


static const struct CutsceneBG gCutsceneBgTable[] =
{
    [SCENEBGDAWN] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sDawnCutsceneBgTiles,
		.tileSize = sizeof(sDawnCutsceneBgTiles),
        .map = sDawnCutsceneBgMap,
		.mapSize = sizeof(sDawnCutsceneBgMap),
        .palette = sDawnCutsceneBgPalette,
		.palIdxCnt = 240
    },
	[SCENEBGNIGHTDAWN] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sDawnCutsceneBgNightTiles,
		.tileSize = sizeof(sDawnCutsceneBgNightTiles),
        .map = sDawnCutsceneBgNightMap,
		.mapSize = sizeof(sDawnCutsceneBgNightMap),
        .palette = sDawnCutsceneBgNightPalette,
		.palIdxCnt = 240
    },
	[SCENEBGSUNSET] = 
    {
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sSunsetBgTiles,
		.tileSize = sizeof(sSunsetBgTiles),
        .map = sSunsetBgMap,
		.mapSize = sizeof(sSunsetBgMap),
        .palette = sSunsetBgPalette,
		.palIdxCnt = 16
    },
	[SCENEBGMINNIE] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sMinnieBgTiles,
		.tileSize = sizeof(sMinnieBgTiles),
        .map = sMinnieBgMap,
		.mapSize = sizeof(sMinnieBgMap),
        .palette = sMinnieBgPalette,
		.palIdxCnt = 36
    },
	[SCENEBGMELOETTA] = 
    {
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sMeloettaBgTiles,
		.tileSize = sizeof(sMeloettaBgTiles),
        .map = sMeloettaBgMap,
		.mapSize = sizeof(sMeloettaBgMap),
        .palette = sMeloettaBgPalette,
		.palIdxCnt = 16
    },
	[SCENEBGSHELLY] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sShellyBgTiles,
		.tileSize = sizeof(sShellyBgTiles),
        .map = sShellyBgMap,
		.mapSize = sizeof(sShellyBgMap),
        .palette = sShellyBgPalette,
		.palIdxCnt = 240
    },
	[SCENEBGMAWILE] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sMawileBgTiles,
		.tileSize = sizeof(sMawileBgTiles),
        .map = sMawileBgMap,
		.mapSize = sizeof(sMawileBgMap),
        .palette = sMawileBgPalette,
		.palIdxCnt = 240
    },
	
	[SCENEBGBRENDAN] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sBrendanBgTiles,
		.tileSize = sizeof(sBrendanBgTiles),
        .map = sBrendanBgMap,
		.mapSize = sizeof(sBrendanBgMap),
        .palette = sBrendanBgPalette,
		.palIdxCnt = 240
	},
	[SCENEBGBRENDANNIGHT] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sBrendanNightBgTiles,
		.tileSize = sizeof(sBrendanNightBgTiles),
        .map = sBrendanNightBgMap,
		.mapSize = sizeof(sBrendanNightBgMap),
        .palette = sBrendanNightBgPalette,
		.palIdxCnt = 240
	},
	[SCENEBGMININGMAP] = 
    {
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sMiningMapBgTiles,
		.tileSize = sizeof(sMiningMapBgTiles),
        .map = sMiningMapBgMap,
		.mapSize = sizeof(sMiningMapBgMap),
        .palette = sMiningMapBgPalette,
		.palIdxCnt = 16
	},
	[SCENEBGLEAFNORMAL] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sLeafBgTiles,
		.tileSize = sizeof(sLeafBgTiles),
        .map = sLeafBgMap,
		.mapSize = sizeof(sLeafBgMap),
        .palette = sLeafBgPalette,
		.palIdxCnt = 240
	},
	[SCENEBGCOURTNEY] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sCourtneyBgTiles,
		.tileSize = sizeof(sCourtneyBgTiles),
        .map = sCourtneyBgMap,
		.mapSize = sizeof(sCourtneyBgMap),
        .palette = sCourtneyBgPalette,
		.palIdxCnt = 240
	},
	[SCENEBGHEATRAN] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sHeatranBgTiles,
		.tileSize = sizeof(sHeatranBgTiles),
        .map = sHeatranBgMap,
		.mapSize = sizeof(sHeatranBgMap),
        .palette = sHeatranBgPalette,
		.palIdxCnt = 224
	},
	[SCENEBGNURSE] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sNurseBgTiles,
		.tileSize = sizeof(sNurseBgTiles),
        .map = sNurseBgMap,
		.mapSize = sizeof(sNurseBgMap),
        .palette = sNurseBgPalette,
		.palIdxCnt = 224
	},
	[SCENEBGNURSENIGHT] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sNurseNightBgTiles,
		.tileSize = sizeof(sNurseNightBgTiles),
        .map = sNurseNightBgMap,
		.mapSize = sizeof(sNurseNightBgMap),
        .palette = sNurseNightBgPalette,
		.palIdxCnt = 48
	},
	[SCENEBGPIDGEYSCREENSHOT] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sPidgeyScreenshotTiles,
		.tileSize = sizeof(sPidgeyScreenshotTiles),
        .map = sPidgeyScreenshotMap,
		.mapSize = sizeof(sPidgeyScreenshotMap),
        .palette = sPidgeyScreenshotPalette,
		.palIdxCnt = 16
	},
	[SCENEBGGAMEOVER] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sGameOverBgTiles,
		.tileSize = sizeof(sGameOverBgTiles),
        .map = sGameOverBgMap,
		.mapSize = sizeof(sGameOverBgMap),
        .palette = sGameOverBgPalette,
		.palIdxCnt = 240
	},
};

static const struct BgTemplate sCutsceneBackground8bpp = {
	.bg = 1,
	.charBaseIndex = 0,
	.mapBaseIndex = 26,
	.screenSize = 0,
	.paletteMode = 1,
	.priority = 0,
	.baseTile = 0
};

static const struct BgTemplate sCutsceneBackground4bpp = {
	.bg = 1,
	.charBaseIndex = 0,
	.mapBaseIndex = 26,
	.screenSize = 0,
	.paletteMode = 0,
	.priority = 0,
	.baseTile = 0
};


EWRAM_DATA struct BGPanState gBgPanState = {0};

ALIGNED(4) EWRAM_DATA u16 gUnfadedPalette[0x100] = {0};
ALIGNED(4) EWRAM_DATA u16 gFadedPalette[0x100] = {0};
EWRAM_DATA struct PidgeyPaletteFade gPPlttFade = {0};

static void BlendPaletteDevPidgey(u16 palOffset, u16 numEntries, u8 coeff, u16 blendColor)
{
    u16 i;
    for (i = 0; i < numEntries; i++)
    {
        u16 index = i + palOffset;
        struct PlttData *data1 = (struct PlttData *)&gUnfadedPalette[index];
        s8 r = data1->r;
        s8 g = data1->g;
        s8 b = data1->b;
        struct PlttData *data2 = (struct PlttData *)&blendColor;
        gFadedPalette[index] = ((r + (((data2->r - r) * coeff) >> 4)) << 0)
                                | ((g + (((data2->g - g) * coeff) >> 4)) << 5)
                                | ((b + (((data2->b - b) * coeff) >> 4)) << 10);
    }
}

void UpdatePidgeyPaletteFade(void)
{
	if(gPPlttFade.active)
	{
		BlendPaletteDevPidgey(gPPlttFade.palOffset, gPPlttFade.numEntries, gPPlttFade.currentCoeff, RGB_BLACK);
		CpuCopy16(gFadedPalette, (u16 *)PLTT, gPPlttFade.numEntries * sizeof(u16));
		if(gPPlttFade.currentCoeff == gPPlttFade.endCoeff)
		{
			gPPlttFade.active = FALSE;
			return;
		}
		if(gPPlttFade.startCoeff > gPPlttFade.endCoeff)
		{
			gPPlttFade.currentCoeff--;
		}
		else if(gPPlttFade.startCoeff < gPPlttFade.endCoeff)
		{
			gPPlttFade.currentCoeff++;
		}
	} 
}

void StartPaletteFadePidgey(u16 offset, u8 numEntries, u8 startCoeff, u8 endCoeff, u16 color)
{
	if(!gPPlttFade.active)
	{
		gPPlttFade.startCoeff = startCoeff;
		gPPlttFade.endCoeff = endCoeff;
		gPPlttFade.currentCoeff = startCoeff;
		gPPlttFade.numEntries = numEntries;
		gPPlttFade.palOffset = offset;
		gPPlttFade.color = color;
		gPPlttFade.active = TRUE;
	}
	CpuCopy16(&gPlttBufferUnfaded[0x1E0/2], (u16 *)(PLTT + 0x1E0), 0x20); // HACK!! due to changing the VBlankCallback for cutscenes the normal palettes 
																		  // that have been loaded won't get sent to palette ram so we do for the msgbox ourselves
}

void LoadPalettePidgey(const void * pal, u8 numEntries)
{
	CpuCopy16(pal, gUnfadedPalette, numEntries * sizeof(u16));
}

static void InitDefaultTilemap(void)
{
	LoadBgTilemap(1, sDefaultCutsceneTilemap, sizeof(sDefaultCutsceneTilemap), 0);
}

static void StartBackgroundPan(const u8 * ptr, u8 bpp, u8 mode)
{
	gBgPanState.bgLineOfs = 0;
	gBgPanState.ptr = ptr;
	gBgPanState.bpp = bpp;
	gBgPanState.mode = mode;
	gBgPanState.bgLineOfs = 19; // expects a '{width} x 40' image
	gBgPanState.active = TRUE;
}

void UpdateBgPan(void)
{
	if(gBgPanState.active)
	{
		if(gBgPanState.bgLineOfs != 0 && gBgPanState.vofsVal == 0)
		{
			if(gBgPanState.mode == 0)
				LoadBgTilemap(1, &gBgPanState.ptr[gBgPanState.bgLineOfs * 0x2 * 32], 0x2 * 32 * 21, 0);
			else
				LoadBgTiles(1, &gBgPanState.ptr[gBgPanState.bgLineOfs * gBgPanState.bpp * 0x8 * 30], gBgPanState.bpp * 0x8 * 30 * 21, 0);
			gBgPanState.bgLineOfs--;
			gBgPanState.vofsVal = 8;
		}
		if(gBgPanState.vofsVal > 0)
		{
			gBgPanState.vofsVal--;
			REG_BG1VOFS = gBgPanState.vofsVal;
		}
		else if(gBgPanState.bgLineOfs == 0)
		{
			gBgPanState.active = FALSE;
		}
	}
}

void StartBGCutscene(u8 id)
{
	if(gCutsceneBgTable[id].mode & CUTSCENE_8BPP_MODE_MASK)
		InitBgFromTemplate(&sCutsceneBackground8bpp);
	else
		InitBgFromTemplate(&sCutsceneBackground4bpp);
	ResetAllBgsCoordinates();
    ShowBg(0);
    ShowBg(1);
	switch(gCutsceneBgTable[id].mode)
	{
		case CUTSCENE_4BPP_NO_SCROLL:
		case CUTSCENE_8BPP_NO_SCROLL:
			if(gCutsceneBgTable[id].map == NULL)
				InitDefaultTilemap();
			else
				LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
			LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
			break;
		case CUTSCENE_4BPP_SCROLL:
			switch(gCutsceneBgTable[id].scrollMode)
			{
				case CUTSCENE_SCROLL_MAP:
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					StartBackgroundPan(gCutsceneBgTable[id].map, 4, gCutsceneBgTable[id].scrollMode);
					break;
				case CUTSCENE_SCROLL_TILE:
					InitDefaultTilemap();
					StartBackgroundPan(gCutsceneBgTable[id].tiles, 4, gCutsceneBgTable[id].scrollMode);
					break;
				default:
					if(gCutsceneBgTable[id].map == NULL)
						InitDefaultTilemap();
					else
						LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					break;
			}
			break;
		case CUTSCENE_8BPP_SCROLL:
			switch(gCutsceneBgTable[id].scrollMode)
			{
				case CUTSCENE_SCROLL_MAP:
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					StartBackgroundPan(gCutsceneBgTable[id].map, 8, gCutsceneBgTable[id].scrollMode);
					break;
				case CUTSCENE_SCROLL_TILE:
					InitDefaultTilemap();
					StartBackgroundPan(gCutsceneBgTable[id].tiles, 8, gCutsceneBgTable[id].scrollMode);
					break;
				default:
					if(gCutsceneBgTable[id].map == NULL)
						InitDefaultTilemap();
					else
						LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					break;
			}
			break;
		default:
			break;
	}
	//Unused_LoadBgPalette(1, gCutsceneBgTable[id].palette, gCutsceneBgTable[id].palIdxCnt * 2, 0);
	LoadPalettePidgey(gCutsceneBgTable[id].palette, gCutsceneBgTable[id].palIdxCnt);
	StartPaletteFadePidgey(0, gCutsceneBgTable[id].palIdxCnt, 16, 0, RGB_BLACK);
}