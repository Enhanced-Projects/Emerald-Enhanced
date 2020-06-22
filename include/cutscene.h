#ifndef GUARD_CUTSCENE_H
#define GUARD_CUTSCENE_H

struct BGPanState 
{
	const u8 * ptr;
	bool8 active;
	u8 bgLineOfs;
	u8 vofsVal;
	u8 mode;
	u8 bpp;
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
    const u8 *tiles;
	u32 tileSize;
    const u8 *map;
	u32 mapSize;
    const u8 *palette;
	u32 palIdxCnt;
	u8 mode;
	u8 scrollMode;
};

#define CUTSCENE_4BPP_NO_SCROLL 0x0
#define CUTSCENE_4BPP_SCROLL 0x1
#define CUTSCENE_4BPP_MODE_MASK (CUTSCENE_4BPP_NO_SCROLL | CUTSCENE_4BPP_SCROLL)
#define CUTSCENE_8BPP_NO_SCROLL 0x2
#define CUTSCENE_8BPP_SCROLL 0x4
#define CUTSCENE_8BPP_MODE_MASK (CUTSCENE_8BPP_NO_SCROLL | CUTSCENE_8BPP_SCROLL)

#define CUTSCENE_SCROLL_MAP 0
#define CUTSCENE_SCROLL_TILE 1
#define CUTSCENE_SCROLL_NONE 0xFF

void UpdatePidgeyPaletteFade(void);
void StartPaletteFadePidgey(u16 offset, u8 numEntries, u8 startCoeff, u8 endCoeff, u16 color);
void LoadPalettePidgey(const void * pal, u8 numEntries);
void UpdateBgPan(void);
void StartBGCutscene(u8 id);

#endif//GUARD_CUTSCENE_H
