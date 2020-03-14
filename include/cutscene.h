#ifndef GUARD_CUTSCENE_H
#define GUARD_CUTSCENE_H

struct BGPanState {
	bool8 active;
	u8 bgLineOfs;
	u8 vofsVal;
	u8 mode;
	u8 bpp;
	const u8 * ptr;
};

struct PidgeyPaletteFade 
{
	bool32 active;
	u16 palOffset;
	u16 color;
	u8 startCoeff;
	u8 endCoeff;
	u8 currentCoeff;
	u8 numEntries;
};

struct CutsceneBG
{
	u8 mode; // 0 - 4bpp NS, 1 - 4bpp S, 2 - 8bpp NS, 3 - 8bpp S
	u8 scrollMode; // 0 - map, 1 - tile
    const u8 *tiles;
	u32 tileSize;
    const u8 *map;
	u32 mapSize;
    const u8 *palette;
	u32 palIdxCnt;
};

void UpdatePidgeyPaletteFade(void);
void StartPaletteFadePidgey(u16 offset, u8 numEntries, u8 startCoeff, u8 endCoeff, u16 color);
void LoadPalettePidgey(const void * pal, u8 numEntries);
void UpdateBgPan(void);
void StartBGCutscene(u8 id);

#endif//GUARD_CUTSCENE_H
