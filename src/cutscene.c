#include "global.h"
#include "bg.h"
#include "cutscene.h"
#include "menu_helpers.h"
#include "palette.h"
#include "constants/rgb.h"
#include "constants/vars.h"

static const u8 sDawnCutsceneBgTiles[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/tiles.8bpp");
static const u8 sDawnCutsceneBgMap[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/map.bin");
static const u8 sDawnCutsceneBgPalette[] = INCBIN_U8("graphics/cutscene/fscutscene/dawn/tiles.gbapal");

static const struct CutsceneBG gCutsceneBgTable[] =
{
    [SCENEBGDAWN] = 
    {
		.mode = 2,
		.scrollMode = 0,
        .tiles = sDawnCutsceneBgTiles,
		.tileSize = sizeof(sDawnCutsceneBgTiles),
        .map = sDawnCutsceneBgMap,
		.mapSize = sizeof(sDawnCutsceneBgMap),
        .palette = sDawnCutsceneBgPalette,
		.palIdxCnt = 240
    }
};

static const struct BgTemplate sCutsceneBackground8bpp = {
	.bg = 1,
	.charBaseIndex = 0,
	.mapBaseIndex = 20,
	.screenSize = 0,
	.paletteMode = 1,
	.priority = 0,
	.baseTile = 0
};

static const struct BgTemplate sCutsceneBackground4bpp = {
	.bg = 1,
	.charBaseIndex = 0,
	.mapBaseIndex = 20,
	.screenSize = 0,
	.paletteMode = 0,
	.priority = 0,
	.baseTile = 0
};


EWRAM_DATA struct BGPanState gBgPanState = {0};
EWRAM_DATA u16 gMapBuffer[32][32] = {0};

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
	u32 i, j, k = 0;
	for(i = 0; i < 21; i++)
	{
		for(j = 0; j < 30; j++)
		{
			gMapBuffer[i][j] = k++;
		}
	}
	LoadBgTilemap(1, gMapBuffer, sizeof(gMapBuffer), 0);	
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
	if(gCutsceneBgTable[id].mode > 1)
		InitBgFromTemplate(&sCutsceneBackground8bpp);
	else
		InitBgFromTemplate(&sCutsceneBackground4bpp);
	ResetAllBgsCoordinates();
    ShowBg(0);
    ShowBg(1);
	switch(gCutsceneBgTable[id].mode)
	{
		case 0:
			LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
			LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
			break;
		case 1:
			if(gCutsceneBgTable[id].scrollMode == 0)
			{
				LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
				StartBackgroundPan(gCutsceneBgTable[id].map, 4, gCutsceneBgTable[id].scrollMode);
			}
			else
			{
				InitDefaultTilemap();
				StartBackgroundPan(gCutsceneBgTable[id].tiles, 4, gCutsceneBgTable[id].scrollMode);
			}
			break;
		case 2:
			LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
			LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
			break;
		case 3:
			if(gCutsceneBgTable[id].scrollMode == 0)
			{
				LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
				StartBackgroundPan(gCutsceneBgTable[id].map, 8, gCutsceneBgTable[id].scrollMode);
			}
			else
			{
				InitDefaultTilemap();
				StartBackgroundPan(gCutsceneBgTable[id].tiles, 8, gCutsceneBgTable[id].scrollMode);
			}
			break;
		default:
			break;
	}
	//Unused_LoadBgPalette(1, gCutsceneBgTable[id].palette, gCutsceneBgTable[id].palIdxCnt * 2, 0);
	LoadPalettePidgey(gCutsceneBgTable[id].palette, gCutsceneBgTable[id].palIdxCnt);
	StartPaletteFadePidgey(0, gCutsceneBgTable[id].palIdxCnt, 16, 0, RGB_BLACK);
}