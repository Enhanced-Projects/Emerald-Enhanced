#include "global.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "palette.h"
#include "bg.h"
#include "graphics.h"
#include "event_data.h"

// const rom data
const u8 gTextWindowFrame1_Gfx[] = INCBIN_U8("graphics/text_window/1.4bpp");
static const u8 sTextWindowFrame2_Gfx[] = INCBIN_U8("graphics/text_window/2.4bpp");
static const u8 sTextWindowFrame3_Gfx[] = INCBIN_U8("graphics/text_window/3.4bpp");
static const u8 sTextWindowFrame4_Gfx[] = INCBIN_U8("graphics/text_window/4.4bpp");
static const u8 sTextWindowFrame5_Gfx[] = INCBIN_U8("graphics/text_window/5.4bpp");
static const u8 sTextWindowFrame6_Gfx[] = INCBIN_U8("graphics/text_window/6.4bpp");
static const u8 sTextWindowFrame7_Gfx[] = INCBIN_U8("graphics/text_window/7.4bpp");
static const u8 sTextWindowFrame8_Gfx[] = INCBIN_U8("graphics/text_window/8.4bpp");
static const u8 sTextWindowFrame9_Gfx[] = INCBIN_U8("graphics/text_window/9.4bpp");
static const u8 sTextWindowFrame10_Gfx[] = INCBIN_U8("graphics/text_window/10.4bpp");
static const u8 sTextWindowFrame11_Gfx[] = INCBIN_U8("graphics/text_window/11.4bpp");
static const u8 sTextWindowFrame12_Gfx[] = INCBIN_U8("graphics/text_window/12.4bpp");
static const u8 sTextWindowFrame13_Gfx[] = INCBIN_U8("graphics/text_window/13.4bpp");
static const u8 sTextWindowFrame14_Gfx[] = INCBIN_U8("graphics/text_window/14.4bpp");
static const u8 sTextWindowFrame15_Gfx[] = INCBIN_U8("graphics/text_window/15.4bpp");
static const u8 sTextWindowFrame16_Gfx[] = INCBIN_U8("graphics/text_window/16.4bpp");
static const u8 sTextWindowFrame17_Gfx[] = INCBIN_U8("graphics/text_window/17.4bpp");
static const u8 sTextWindowFrame18_Gfx[] = INCBIN_U8("graphics/text_window/18.4bpp");
static const u8 sTextWindowFrame19_Gfx[] = INCBIN_U8("graphics/text_window/19.4bpp");
static const u8 sTextWindowFrame20_Gfx[] = INCBIN_U8("graphics/text_window/20.4bpp");

const u16 gTextWindowFrame1_Pal[] = INCBIN_U16("graphics/text_window/1.gbapal");
static const u16 sTextWindowFrame2_Pal[] = INCBIN_U16("graphics/text_window/2.gbapal");
static const u16 sTextWindowFrame3_Pal[] = INCBIN_U16("graphics/text_window/3.gbapal");
static const u16 sTextWindowFrame4_Pal[] = INCBIN_U16("graphics/text_window/4.gbapal");
static const u16 sTextWindowFrame5_Pal[] = INCBIN_U16("graphics/text_window/5.gbapal");
static const u16 sTextWindowFrame6_Pal[] = INCBIN_U16("graphics/text_window/6.gbapal");
static const u16 sTextWindowFrame7_Pal[] = INCBIN_U16("graphics/text_window/7.gbapal");
static const u16 sTextWindowFrame8_Pal[] = INCBIN_U16("graphics/text_window/8.gbapal");
static const u16 sTextWindowFrame9_Pal[] = INCBIN_U16("graphics/text_window/9.gbapal");
static const u16 sTextWindowFrame10_Pal[] = INCBIN_U16("graphics/text_window/10.gbapal");
static const u16 sTextWindowFrame11_Pal[] = INCBIN_U16("graphics/text_window/11.gbapal");
static const u16 sTextWindowFrame12_Pal[] = INCBIN_U16("graphics/text_window/12.gbapal");
static const u16 sTextWindowFrame13_Pal[] = INCBIN_U16("graphics/text_window/13.gbapal");
static const u16 sTextWindowFrame14_Pal[] = INCBIN_U16("graphics/text_window/14.gbapal");
static const u16 sTextWindowFrame15_Pal[] = INCBIN_U16("graphics/text_window/15.gbapal");
static const u16 sTextWindowFrame16_Pal[] = INCBIN_U16("graphics/text_window/16.gbapal");
static const u16 sTextWindowFrame17_Pal[] = INCBIN_U16("graphics/text_window/17.gbapal");
static const u16 sTextWindowFrame18_Pal[] = INCBIN_U16("graphics/text_window/18.gbapal");
static const u16 sTextWindowFrame19_Pal[] = INCBIN_U16("graphics/text_window/19.gbapal");
static const u16 sTextWindowFrame20_Pal[] = INCBIN_U16("graphics/text_window/20.gbapal");


//dark theme windowframes
static const u16 gTextWindowFrame1d_Pal[] = INCBIN_U16("graphics/text_window/13d.gbapal");
static const u16 sTextWindowFrame2d_Pal[] = INCBIN_U16("graphics/text_window/2d.gbapal");
static const u16 sTextWindowFrame3d_Pal[] = INCBIN_U16("graphics/text_window/3d.gbapal");
static const u16 sTextWindowFrame4d_Pal[] = INCBIN_U16("graphics/text_window/4d.gbapal");
static const u16 sTextWindowFrame5d_Pal[] = INCBIN_U16("graphics/text_window/5d.gbapal");
static const u16 sTextWindowFrame6d_Pal[] = INCBIN_U16("graphics/text_window/6d.gbapal");
static const u16 sTextWindowFrame7d_Pal[] = INCBIN_U16("graphics/text_window/7d.gbapal");
static const u16 sTextWindowFrame8d_Pal[] = INCBIN_U16("graphics/text_window/8d.gbapal");
static const u16 sTextWindowFrame9d_Pal[] = INCBIN_U16("graphics/text_window/9d.gbapal");
static const u16 sTextWindowFrame10d_Pal[] = INCBIN_U16("graphics/text_window/10d.gbapal");
static const u16 sTextWindowFrame11d_Pal[] = INCBIN_U16("graphics/text_window/11d.gbapal");
static const u16 sTextWindowFrame12d_Pal[] = INCBIN_U16("graphics/text_window/12d.gbapal");
static const u16 sTextWindowFrame13d_Pal[] = INCBIN_U16("graphics/text_window/1d.gbapal");
static const u16 sTextWindowFrame14d_Pal[] = INCBIN_U16("graphics/text_window/14d.gbapal");
static const u16 sTextWindowFrame15d_Pal[] = INCBIN_U16("graphics/text_window/15d.gbapal");
static const u16 sTextWindowFrame16d_Pal[] = INCBIN_U16("graphics/text_window/16d.gbapal");
static const u16 sTextWindowFrame17d_Pal[] = INCBIN_U16("graphics/text_window/17d.gbapal");
static const u16 sTextWindowFrame18d_Pal[] = INCBIN_U16("graphics/text_window/18d.gbapal");
static const u16 sTextWindowFrame19d_Pal[] = INCBIN_U16("graphics/text_window/19d.gbapal");
static const u16 sTextWindowFrame20d_Pal[] = INCBIN_U16("graphics/text_window/20d.gbapal");

static const u8 gTextWindowFrame1d_Gfx[] = INCBIN_U8("graphics/text_window/13d.4bpp");
static const u8 sTextWindowFrame2d_Gfx[] = INCBIN_U8("graphics/text_window/2d.4bpp");
static const u8 sTextWindowFrame3d_Gfx[] = INCBIN_U8("graphics/text_window/3d.4bpp");
static const u8 sTextWindowFrame4d_Gfx[] = INCBIN_U8("graphics/text_window/4d.4bpp");
static const u8 sTextWindowFrame5d_Gfx[] = INCBIN_U8("graphics/text_window/5d.4bpp");
static const u8 sTextWindowFrame6d_Gfx[] = INCBIN_U8("graphics/text_window/6d.4bpp");
static const u8 sTextWindowFrame7d_Gfx[] = INCBIN_U8("graphics/text_window/7d.4bpp");
static const u8 sTextWindowFrame8d_Gfx[] = INCBIN_U8("graphics/text_window/8d.4bpp");
static const u8 sTextWindowFrame9d_Gfx[] = INCBIN_U8("graphics/text_window/9d.4bpp");
static const u8 sTextWindowFrame10d_Gfx[] = INCBIN_U8("graphics/text_window/10d.4bpp");
static const u8 sTextWindowFrame11d_Gfx[] = INCBIN_U8("graphics/text_window/11d.4bpp");
static const u8 sTextWindowFrame12d_Gfx[] = INCBIN_U8("graphics/text_window/12d.4bpp");
static const u8 sTextWindowFrame13d_Gfx[] = INCBIN_U8("graphics/text_window/1d.4bpp");
static const u8 sTextWindowFrame14d_Gfx[] = INCBIN_U8("graphics/text_window/14d.4bpp");
static const u8 sTextWindowFrame15d_Gfx[] = INCBIN_U8("graphics/text_window/15d.4bpp");
static const u8 sTextWindowFrame16d_Gfx[] = INCBIN_U8("graphics/text_window/16d.4bpp");
static const u8 sTextWindowFrame17d_Gfx[] = INCBIN_U8("graphics/text_window/17d.4bpp");
static const u8 sTextWindowFrame18d_Gfx[] = INCBIN_U8("graphics/text_window/18d.4bpp");
static const u8 sTextWindowFrame19d_Gfx[] = INCBIN_U8("graphics/text_window/19d.4bpp");
static const u8 sTextWindowFrame20d_Gfx[] = INCBIN_U8("graphics/text_window/20d.4bpp");
static const u16 sTextWindowDexnavFrame[] = INCBIN_U16("graphics/text_window/dexnav_pal.gbapal");

static const u16 gTextWindowFrame1u_Pal[] = INCBIN_U16("graphics/text_window/1u.gbapal");
static const u16 sTextWindowFrame2u_Pal[] = INCBIN_U16("graphics/text_window/2u.gbapal");
static const u16 sTextWindowFrame3u_Pal[] = INCBIN_U16("graphics/text_window/3u.gbapal");
static const u16 sTextWindowFrame4u_Pal[] = INCBIN_U16("graphics/text_window/4u.gbapal");
static const u16 sTextWindowFrame5u_Pal[] = INCBIN_U16("graphics/text_window/5u.gbapal");
static const u16 sTextWindowFrame6u_Pal[] = INCBIN_U16("graphics/text_window/6u.gbapal");
static const u16 sTextWindowFrame7u_Pal[] = INCBIN_U16("graphics/text_window/7u.gbapal");
static const u16 sTextWindowFrame8u_Pal[] = INCBIN_U16("graphics/text_window/8u.gbapal");
static const u16 sTextWindowFrame9u_Pal[] = INCBIN_U16("graphics/text_window/9u.gbapal");
static const u16 sTextWindowFrame10u_Pal[] = INCBIN_U16("graphics/text_window/10u.gbapal");
static const u16 sTextWindowFrame11u_Pal[] = INCBIN_U16("graphics/text_window/11u.gbapal");
static const u16 sTextWindowFrame12u_Pal[] = INCBIN_U16("graphics/text_window/12u.gbapal");
static const u16 sTextWindowFrame13u_Pal[] = INCBIN_U16("graphics/text_window/13u.gbapal");
static const u16 sTextWindowFrame14u_Pal[] = INCBIN_U16("graphics/text_window/14u.gbapal");
static const u16 sTextWindowFrame15u_Pal[] = INCBIN_U16("graphics/text_window/15u.gbapal");
static const u16 sTextWindowFrame16u_Pal[] = INCBIN_U16("graphics/text_window/16u.gbapal");
static const u16 sTextWindowFrame17u_Pal[] = INCBIN_U16("graphics/text_window/17u.gbapal");
static const u16 sTextWindowFrame18u_Pal[] = INCBIN_U16("graphics/text_window/18u.gbapal");
static const u16 sTextWindowFrame19u_Pal[] = INCBIN_U16("graphics/text_window/19u.gbapal");
static const u16 sTextWindowFrame20u_Pal[] = INCBIN_U16("graphics/text_window/20u.gbapal");

static const u8 gTextWindowFrame1u_Gfx[] = INCBIN_U8("graphics/text_window/1u.4bpp");
static const u8 sTextWindowFrame2u_Gfx[] = INCBIN_U8("graphics/text_window/2u.4bpp");
static const u8 sTextWindowFrame3u_Gfx[] = INCBIN_U8("graphics/text_window/3u.4bpp");
static const u8 sTextWindowFrame4u_Gfx[] = INCBIN_U8("graphics/text_window/4u.4bpp");
static const u8 sTextWindowFrame5u_Gfx[] = INCBIN_U8("graphics/text_window/5u.4bpp");
static const u8 sTextWindowFrame6u_Gfx[] = INCBIN_U8("graphics/text_window/6u.4bpp");
static const u8 sTextWindowFrame7u_Gfx[] = INCBIN_U8("graphics/text_window/7u.4bpp");
static const u8 sTextWindowFrame8u_Gfx[] = INCBIN_U8("graphics/text_window/8u.4bpp");
static const u8 sTextWindowFrame9u_Gfx[] = INCBIN_U8("graphics/text_window/9u.4bpp");
static const u8 sTextWindowFrame10u_Gfx[] = INCBIN_U8("graphics/text_window/10u.4bpp");
static const u8 sTextWindowFrame11u_Gfx[] = INCBIN_U8("graphics/text_window/11u.4bpp");
static const u8 sTextWindowFrame12u_Gfx[] = INCBIN_U8("graphics/text_window/12u.4bpp");
static const u8 sTextWindowFrame13u_Gfx[] = INCBIN_U8("graphics/text_window/13u.4bpp");
static const u8 sTextWindowFrame14u_Gfx[] = INCBIN_U8("graphics/text_window/14u.4bpp");
static const u8 sTextWindowFrame15u_Gfx[] = INCBIN_U8("graphics/text_window/15u.4bpp");
static const u8 sTextWindowFrame16u_Gfx[] = INCBIN_U8("graphics/text_window/16u.4bpp");
static const u8 sTextWindowFrame17u_Gfx[] = INCBIN_U8("graphics/text_window/17u.4bpp");
static const u8 sTextWindowFrame18u_Gfx[] = INCBIN_U8("graphics/text_window/18u.4bpp");
static const u8 sTextWindowFrame19u_Gfx[] = INCBIN_U8("graphics/text_window/19u.4bpp");
static const u8 sTextWindowFrame20u_Gfx[] = INCBIN_U8("graphics/text_window/20u.4bpp");


static const u16 sTextWindowPalettes[][16] =
{
    INCBIN_U16("graphics/text_window/message_box.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal1.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal2.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal3.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal4.gbapal")
};

static const struct TilesPal sWindowFrames[WINDOW_FRAMES_COUNT] =
{
    {gTextWindowFrame1_Gfx, gTextWindowFrame1_Pal},
    {sTextWindowFrame2_Gfx, sTextWindowFrame2_Pal},
    {sTextWindowFrame3_Gfx, sTextWindowFrame3_Pal},
    {sTextWindowFrame4_Gfx, sTextWindowFrame4_Pal},
    {sTextWindowFrame5_Gfx, sTextWindowFrame5_Pal},
    {sTextWindowFrame6_Gfx, sTextWindowFrame6_Pal},
    {sTextWindowFrame7_Gfx, sTextWindowFrame7_Pal},
    {sTextWindowFrame8_Gfx, sTextWindowFrame8_Pal},
    {sTextWindowFrame9_Gfx, sTextWindowFrame9_Pal},
    {sTextWindowFrame10_Gfx, sTextWindowFrame10_Pal},
    {sTextWindowFrame11_Gfx, sTextWindowFrame11_Pal},
    {sTextWindowFrame12_Gfx, sTextWindowFrame12_Pal},
    {sTextWindowFrame13_Gfx, sTextWindowFrame13_Pal},
    {sTextWindowFrame14_Gfx, sTextWindowFrame14_Pal},
    {sTextWindowFrame15_Gfx, sTextWindowFrame15_Pal},
    {sTextWindowFrame16_Gfx, sTextWindowFrame16_Pal},
    {sTextWindowFrame17_Gfx, sTextWindowFrame17_Pal},
    {sTextWindowFrame18_Gfx, sTextWindowFrame18_Pal},
    {sTextWindowFrame19_Gfx, sTextWindowFrame19_Pal},
    {sTextWindowFrame20_Gfx, sTextWindowFrame20_Pal}
};

static const struct TilesPal sWindowFramesDark[WINDOW_FRAMES_COUNT] =
{
    {gTextWindowFrame1d_Gfx, gTextWindowFrame1d_Pal},
    {sTextWindowFrame2d_Gfx, sTextWindowFrame2d_Pal},
    {sTextWindowFrame3d_Gfx, sTextWindowFrame3d_Pal},
    {sTextWindowFrame4d_Gfx, sTextWindowFrame4d_Pal},
    {sTextWindowFrame5d_Gfx, sTextWindowFrame5d_Pal},
    {sTextWindowFrame6d_Gfx, sTextWindowFrame6d_Pal},
    {sTextWindowFrame7d_Gfx, sTextWindowFrame7d_Pal},
    {sTextWindowFrame8d_Gfx, sTextWindowFrame8d_Pal},
    {sTextWindowFrame9d_Gfx, sTextWindowFrame9d_Pal},
    {sTextWindowFrame10d_Gfx, sTextWindowFrame10d_Pal},
    {sTextWindowFrame11d_Gfx, sTextWindowFrame11d_Pal},
    {sTextWindowFrame12d_Gfx, sTextWindowFrame12d_Pal},
    {sTextWindowFrame13d_Gfx, sTextWindowFrame13d_Pal},
    {sTextWindowFrame14d_Gfx, sTextWindowFrame14d_Pal},
    {sTextWindowFrame15d_Gfx, sTextWindowFrame15d_Pal},
    {sTextWindowFrame16d_Gfx, sTextWindowFrame16d_Pal},
    {sTextWindowFrame17d_Gfx, sTextWindowFrame17d_Pal},
    {sTextWindowFrame18d_Gfx, sTextWindowFrame18d_Pal},
    {sTextWindowFrame19d_Gfx, sTextWindowFrame19d_Pal},
    {sTextWindowFrame20d_Gfx, sTextWindowFrame20d_Pal}
};


static const struct TilesPal sWindowFramesUser[WINDOW_FRAMES_COUNT] =
{
    {gTextWindowFrame1u_Gfx, gTextWindowFrame1u_Pal},
    {sTextWindowFrame2u_Gfx, sTextWindowFrame2u_Pal},
    {sTextWindowFrame3u_Gfx, sTextWindowFrame3u_Pal},
    {sTextWindowFrame4u_Gfx, sTextWindowFrame4u_Pal},
    {sTextWindowFrame5u_Gfx, sTextWindowFrame5u_Pal},
    {sTextWindowFrame6u_Gfx, sTextWindowFrame6u_Pal},
    {sTextWindowFrame7u_Gfx, sTextWindowFrame7u_Pal},
    {sTextWindowFrame8u_Gfx, sTextWindowFrame8u_Pal},
    {sTextWindowFrame9u_Gfx, sTextWindowFrame9u_Pal},
    {sTextWindowFrame10u_Gfx, sTextWindowFrame10u_Pal},
    {sTextWindowFrame11u_Gfx, sTextWindowFrame11u_Pal},
    {sTextWindowFrame12u_Gfx, sTextWindowFrame12u_Pal},
    {sTextWindowFrame13u_Gfx, sTextWindowFrame13u_Pal},
    {sTextWindowFrame14u_Gfx, sTextWindowFrame14u_Pal},
    {sTextWindowFrame15u_Gfx, sTextWindowFrame15u_Pal},
    {sTextWindowFrame16u_Gfx, sTextWindowFrame16u_Pal},
    {sTextWindowFrame17u_Gfx, sTextWindowFrame17u_Pal},
    {sTextWindowFrame18u_Gfx, sTextWindowFrame18u_Pal},
    {sTextWindowFrame19u_Gfx, sTextWindowFrame19u_Pal},
    {sTextWindowFrame20u_Gfx, sTextWindowFrame20u_Pal}
};


static const struct TilesPal sDexnavWindowFrame = {gTextWindowFrame1_Gfx, sTextWindowDexnavFrame};

// code
const struct TilesPal *GetWindowFrameTilesPal(u8 id)
{
    if (VarGet(VAR_RYU_THEME_NUMBER))
    {
        if (id >= WINDOW_FRAMES_COUNT)
        {
            return &sWindowFramesDark[0];
        }
        else
        {
            return &sWindowFramesDark[id];
        }
    }
    else
    {
        if (id >= WINDOW_FRAMES_COUNT)
        {
            return &sWindowFrames[0];
        }
        else
        {
            return &sWindowFrames[id];
        }
    }
    
}

const struct TilesPal *GetWindowFrameLightTilesPal(u8 id)
{
    if (id >= WINDOW_FRAMES_COUNT)
    {
        return &sWindowFrames[0];
    }
    else
    {
        return &sWindowFrames[id];
    }
}

const struct TilesPal *GetWindowFrameDarkTilesPal(u8 id)
{
    if (id >= WINDOW_FRAMES_COUNT)
    {
        return &sWindowFramesDark[0];
    }
    else
    {
        return &sWindowFramesDark[id];
    }
}

const struct TilesPal *GetWindowFrameUserTilesPal(u8 id)
{
    if (id >= WINDOW_FRAMES_COUNT)
    {
        return &sWindowFramesUser[0];
    }
    else
    {
        return &sWindowFramesUser[id];
    }
}

void LoadMessageBoxGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), gMessageBox_Gfx, 0x1C0, destOffset);
    LoadPalette(GetOverworldTextboxPalettePtr(), palOffset, 0x20);
}

void LoadUserWindowBorderGfx_(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadUserWindowBorderGfx(windowId, destOffset, palOffset);
}

//FULL_COLOR TODO - user frames
void LoadWindowGfx(u8 windowId, u8 frameId, u16 destOffset, u8 palOffset)
{
    u32 i;
    u16 buf[0x20];
    switch(VarGet(VAR_RYU_THEME_NUMBER)) {
        case THEME_COLOR_LIGHT:
            LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sWindowFrames[frameId].tiles, 0x120, destOffset);
            CpuCopy16(sWindowFrames[frameId].pal, buf, 0x20);
            buf [15] = COLOR_LIGHT_THEME_BG;
            LoadPalette(buf, palOffset, 0x20);
            break;
        case THEME_COLOR_DARK:
            LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sWindowFramesDark[frameId].tiles, 0x120, destOffset);
            LoadPalette(sWindowFramesDark[frameId].pal, palOffset, 0x20);
            break;
        case THEME_COLOR_USER:
            LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sWindowFramesUser[frameId].tiles, 0x120, destOffset);
            CpuCopy16(sWindowFramesUser[frameId].pal, buf, 0x20);
            buf[14] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BG];
            buf [15] = COLOR_AUTO_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT], THRESHOLD_DEFAULT);
            if (frameId == 0)
            {
                buf[3] = COLOR_AUTO_SHADE(gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER], THRESHOLD_DEFAULT);
                buf[5] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_HIGHLIGHT];
                buf[13] = gSaveBlock2Ptr->userInterfaceTextboxPalette[USER_COLOR_BORDER];
            }
            LoadPalette(buf, palOffset, 0x20);
            break;
        case THEME_COLOR_VANILLA:
            LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sWindowFrames[frameId].tiles, 0x120, destOffset);
            LoadPalette(sWindowFrames[frameId].pal, palOffset, 0x20);
            break;
    }
}

void LoadDarkWindowGfx(u8 windowId, u8 frameId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sWindowFramesDark[frameId].tiles, 0x120, destOffset);
    LoadPalette(sWindowFramesDark[frameId].pal, palOffset, 0x20);
}

void LoadUserWindowBorderGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadWindowGfx(windowId, gSaveBlock2Ptr->optionsWindowFrameType, destOffset, palOffset);
}

void LoadUserDarkWindowBorderGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadDarkWindowGfx(windowId, gSaveBlock2Ptr->optionsWindowFrameType, destOffset, palOffset);
}

void DrawTextBorderOuter(u8 windowId, u16 tileNum, u8 palNum)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, tileNum + 0, tilemapLeft - 1,      tilemapTop - 1,         1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 1, tilemapLeft,          tilemapTop - 1,         width,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 2, tilemapLeft + width,  tilemapTop - 1,         1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 3, tilemapLeft - 1,      tilemapTop,             1,      height, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 5, tilemapLeft + width,  tilemapTop,             1,      height, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 6, tilemapLeft - 1,      tilemapTop + height,    1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 7, tilemapLeft,          tilemapTop + height,    width,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 8, tilemapLeft + width,  tilemapTop + height,    1,      1,      palNum);
}

void DrawTextBorderInner(u8 windowId, u16 tileNum, u8 palNum)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, tileNum + 0, tilemapLeft,              tilemapTop,                 1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 1, tilemapLeft + 1,          tilemapTop,                 width - 2,  1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 2, tilemapLeft + width - 1,  tilemapTop,                 1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 3, tilemapLeft,              tilemapTop + 1,             1,          height - 2, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 5, tilemapLeft + width - 1,  tilemapTop + 1,             1,          height - 2, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 6, tilemapLeft,              tilemapTop + height - 1,    1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 7, tilemapLeft + 1,          tilemapTop + height - 1,    width -     2,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 8, tilemapLeft + width - 1,  tilemapTop + height - 1,    1,          1,          palNum);
}

void rbox_fill_rectangle(u8 windowId)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, 0x11);
}

const u16 *GetTextWindowPalette(u8 id)
{
    switch (id)
    {
    case 0:
        id = 0;
        break;
    case 1:
        id = 0x10;
        break;
    case 2:
        id = 0x20;
        break;
    case 3:
        id = 0x30;
        break;
    case 4:
    default:
        id = 0x40;
        break;
    }

    return (const u16 *)(sTextWindowPalettes) + id;
}

const u16 *GetOverworldTextboxPalettePtr(void)
{
    u32 palette = VarGet(VAR_RYU_THEME_NUMBER);

    switch (palette)
    {
        case 0:
            return gHatLightTheme_Pal;
        case 1:
            return gRyuDarkTheme_Pal;
        case 2:
            return gSaveBlock2Ptr->userInterfaceTextboxPalette;
        default:
            return gMessageBox_Pal;
    }
}

void sub_8098C6C(u8 bg, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(bg, sWindowFrames[gSaveBlock2Ptr->optionsWindowFrameType].tiles, 0x120, destOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, palOffset, 0x20);
}

void LoadDexNavWindowGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sDexnavWindowFrame.tiles, 0x120, destOffset);
    LoadPalette(sDexnavWindowFrame.pal, palOffset, 32);
}

