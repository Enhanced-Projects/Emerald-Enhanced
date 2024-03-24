#include "global.h"
#include "bg.h"
#include "cutscene.h"
#include "menu_helpers.h"
#include "palette.h"
#include "constants/rgb.h"
#include "constants/vars.h"
#include "sprite.h"

static const u8 sDefaultCutsceneTilemap[] = INCBIN_U8("graphics/cutscene/default_tilemap.bin");

static const u8 sDawnCutsceneBgTiles[] = INCBIN_U8("graphics/cutscene/dawn/tiles.8bpp");
static const u8 sDawnCutsceneBgMap[] = INCBIN_U8("graphics/cutscene/dawn/map.bin");
static const u8 sDawnCutsceneBgPalette[] = INCBIN_U8("graphics/cutscene/dawn/tiles.gbapal");

static const u8 sDawnCutsceneBgNightTiles[] = INCBIN_U8("graphics/cutscene/dawn/night_tiles.8bpp");
static const u8 sDawnCutsceneBgNightMap[] = INCBIN_U8("graphics/cutscene/dawn/night_map.bin");
static const u8 sDawnCutsceneBgNightPalette[] = INCBIN_U8("graphics/cutscene/dawn/night_tiles.gbapal");

static const u8 sMinnieBgTiles[] = INCBIN_U8("graphics/cutscene/minnie/minnie_tiles.8bpp");
static const u8 sMinnieBgMap[] = INCBIN_U8("graphics/cutscene/minnie/minnie_map.bin");
static const u8 sMinnieBgPalette[] = INCBIN_U8("graphics/cutscene/minnie/minnie_palette.gbapal");

static const u8 sMeloettaBgTiles[] = INCBIN_U8("graphics/cutscene/meloetta/meloetta_tiles.4bpp");
static const u8 sMeloettaBgMap[] = INCBIN_U8("graphics/cutscene/meloetta/meloetta_map.bin");
static const u8 sMeloettaBgPalette[] = INCBIN_U8("graphics/cutscene/meloetta/meloetta_palette.gbapal");

static const u8 sBrendanBgTiles[] = INCBIN_U8("graphics/cutscene/brendan/brendan_tiles.8bpp");
static const u8 sBrendanBgMap[] = INCBIN_U8("graphics/cutscene/brendan/brendan_map.bin");
static const u8 sBrendanBgPalette[] = INCBIN_U8("graphics/cutscene/brendan/brendan_palette.gbapal");

static const u8 sBrendanNightBgTiles[] = INCBIN_U8("graphics/cutscene/brendan/brendan_night_tiles.8bpp");
static const u8 sBrendanNightBgMap[] = INCBIN_U8("graphics/cutscene/brendan/brendan_night_map.bin");
static const u8 sBrendanNightBgPalette[] = INCBIN_U8("graphics/cutscene/brendan/brendan_night_palette.gbapal");

static const u8 sCourtneyBgTiles[] = INCBIN_U8("graphics/cutscene/courtney/courtney_tiles.8bpp");
static const u8 sCourtneyBgMap[] = INCBIN_U8("graphics/cutscene/courtney/courtney_map.bin");
static const u8 sCourtneyBgPalette[] = INCBIN_U8("graphics/cutscene/courtney/courtney_palette.gbapal");

static const u8 sCourtneyNightBgTiles[] = INCBIN_U8("graphics/cutscene/courtney/courtney_night_tiles.8bpp");
static const u8 sCourtneyNightBgMap[] = INCBIN_U8("graphics/cutscene/courtney/courtney_night_map.bin");
static const u8 sCourtneyNightBgPalette[] = INCBIN_U8("graphics/cutscene/courtney/courtney_night_palette.gbapal");

static const u8 sCourtneyNeutralBgTiles[] = INCBIN_U8("graphics/cutscene/courtney/courtney_neutral_tiles.8bpp");
static const u8 sCourtneyNeutralBgMap[] = INCBIN_U8("graphics/cutscene/courtney/courtney_neutral_map.bin");
static const u8 sCourtneyNeutralBgPalette[] = INCBIN_U8("graphics/cutscene/courtney/courtney_neutral_palette.gbapal");

static const u8 sHeatranBgTiles[] = INCBIN_U8("graphics/cutscene/heatran/heatran_tiles.8bpp");
static const u8 sHeatranBgMap[] = INCBIN_U8("graphics/cutscene/heatran/heatran_map.bin");
static const u8 sHeatranBgPalette[] = INCBIN_U8("graphics/cutscene/heatran/heatran.gbapal");

static const u8 sNurseBgTiles[] = INCBIN_U8("graphics/cutscene/nurse/nurse_tiles.8bpp");
static const u8 sNurseBgMap[] = INCBIN_U8("graphics/cutscene/nurse/nurse_map.bin");
static const u8 sNurseBgPalette[] = INCBIN_U8("graphics/cutscene/nurse/nurse_palette.gbapal");

static const u8 sNurseNightBgTiles[] = INCBIN_U8("graphics/cutscene/nurse/night_tiles.8bpp");
static const u8 sNurseNightBgMap[] = INCBIN_U8("graphics/cutscene/nurse/night_map.bin");
static const u8 sNurseNightBgPalette[] = INCBIN_U8("graphics/cutscene/nurse/night_palette.gbapal");

static const u8 sPidgeyScreenshotTiles[] = INCBIN_U8("graphics/cutscene/pidgey_scrsht/pidgey_pc.4bpp");
static const u8 sPidgeyScreenshotMap[] = INCBIN_U8("graphics/cutscene/pidgey_scrsht/pidgey_pc.bin");
static const u8 sPidgeyScreenshotPalette[] = INCBIN_U8("graphics/cutscene/pidgey_scrsht/pidgey_pc.gbapal");

static const u8 sGameOverBgTiles[] = INCBIN_U8("graphics/cutscene/gameover/gameover_tiles.8bpp");
static const u8 sGameOverBgMap[] = INCBIN_U8("graphics/cutscene/gameover/gameover_map.bin");
static const u8 sGameOverBgPalette[] = INCBIN_U8("graphics/cutscene/gameover/gameover_palette.gbapal");

static const u8 sWarpBgTiles[] = INCBIN_U8("graphics/cutscene/warp/warp_tiles.4bpp");
static const u8 sWarpBgMap[] = INCBIN_U8("graphics/cutscene/warp/warp_map.bin");
static const u8 sWarpBgPalette[] = INCBIN_U8("graphics/cutscene/warp/warp_palette.gbapal");

static const u8 sShellyBgTiles[] =   INCBIN_U8("graphics/cutscene/shelly/shelly_tiles.8bpp");
static const u8 sShellyBgMap[] =     INCBIN_U8("graphics/cutscene/shelly/shelly_map.bin");
static const u8 sShellyBgPalette[] = INCBIN_U8("graphics/cutscene/shelly/shelly_tiles.gbapal");

static const u8 sShellyNightBgTiles[] =   INCBIN_U8("graphics/cutscene/shelly/shelly_night_tiles.8bpp");
static const u8 sShellyNightBgMap[] =     INCBIN_U8("graphics/cutscene/shelly/shelly_night_map.bin");
static const u8 sShellyNightBgPalette[] = INCBIN_U8("graphics/cutscene/shelly/shelly_night_tiles.gbapal");

static const u8 sMayBgTiles[] =   INCBIN_U8("graphics/cutscene/may/may_tiles.8bpp");
static const u8 sMayBgMap[] =     INCBIN_U8("graphics/cutscene/may/may_map.bin");
static const u8 sMayBgPalette[] = INCBIN_U8("graphics/cutscene/may/may_palette.gbapal");

static const u8 sLeafBgTiles[] =   INCBIN_U8("graphics/cutscene/leaf/leaf_tiles.8bpp");
static const u8 sLeafBgMap[] =     INCBIN_U8("graphics/cutscene/leaf/leaf_map.bin");
static const u8 sLeafBgPalette[] = INCBIN_U8("graphics/cutscene/leaf/leaf_tiles.gbapal");

static const u8 sFollowerTutorial1BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/followertutorial1.4bpp");
static const u8 sFollowerTutorial1BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/followertutorial1.bin");
static const u8 sFollowerTutorial1BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/followertutorial1.gbapal");

static const u8 sFollowerTutorial2BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/followertutorial2.4bpp");
static const u8 sFollowerTutorial2BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/followertutorial2.bin");
static const u8 sFollowerTutorial2BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/followertutorial2.gbapal");

static const u8 sFollowerTutorial3BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/followertutorial3.4bpp");
static const u8 sFollowerTutorial3BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/followertutorial3.bin");
static const u8 sFollowerTutorial3BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/followertutorial3.gbapal");

static const u8 sFollowerTutorial4BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/followertutorial4.4bpp");
static const u8 sFollowerTutorial4BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/followertutorial4.bin");
static const u8 sFollowerTutorial4BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/followertutorial4.gbapal");

static const u8 sRealEstateTutorial1BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial1.4bpp");
static const u8 sRealEstateTutorial1BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial1.bin");
static const u8 sRealEstateTutorial1BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial1.gbapal");

static const u8 sRealEstateTutorial2BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial2.4bpp");
static const u8 sRealEstateTutorial2BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial2.bin");
static const u8 sRealEstateTutorial2BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial2.gbapal");

static const u8 sRealEstateTutorial3BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial3.4bpp");
static const u8 sRealEstateTutorial3BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial3.bin");
static const u8 sRealEstateTutorial3BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial3.gbapal");

static const u8 sRealEstateTutorial4BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial4.4bpp");
static const u8 sRealEstateTutorial4BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial4.bin");
static const u8 sRealEstateTutorial4BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/realestatetutorial4.gbapal");

static const u8 sFactionsTutorial1BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/factionstutorial1.4bpp");
static const u8 sFactionsTutorial1BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/factionstutorial1.bin");
static const u8 sFactionsTutorial1BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/factionstutorial1.gbapal");

static const u8 sFactionsTutorial2BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/factionstutorial2.4bpp");
static const u8 sFactionsTutorial2BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/factionstutorial2.bin");
static const u8 sFactionsTutorial2BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/factionstutorial2.gbapal");

static const u8 sLucyBgTiles[] =   INCBIN_U8("graphics/cutscene/lucy/lucy_tiles.8bpp");
static const u8 sLucyBgMap[] =     INCBIN_U8("graphics/cutscene/lucy/lucy_map.bin");
static const u8 sLucyBgPalette[] = INCBIN_U8("graphics/cutscene/lucy/lucy_tiles.gbapal");

static const u8 sLanetteBgTiles[] =   INCBIN_U8("graphics/cutscene/lanette/lanette_tiles.8bpp");
static const u8 sLanetteBgMap[] =     INCBIN_U8("graphics/cutscene/lanette/lanette_map.bin");
static const u8 sLanetteBgPalette[] = INCBIN_U8("graphics/cutscene/lanette/lanette_tiles.gbapal");

static const u8 sMomBgTiles[] =   INCBIN_U8("graphics/cutscene/mom/mom_tiles.8bpp");
static const u8 sMomBgMap[] =     INCBIN_U8("graphics/cutscene/mom/mom_map.bin");
static const u8 sMomBgPalette[] = INCBIN_U8("graphics/cutscene/mom/mom_tiles.gbapal");

static const u8 sLucySceneSprite[] =    INCBIN_U8("graphics/cutscene/mugshotsprites/lucy_sprite.4bpp");
static const u8 sLucySceneSpritePal[] = INCBIN_U8("graphics/cutscene/mugshotsprites/lucy_sprite.gbapal");

static const u8 sOpenWorldTutorial1BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial1.4bpp");
static const u8 sOpenWorldTutorial1BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial1.bin");
static const u8 sOpenWorldTutorial1BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial1.gbapal");

static const u8 sOpenWorldTutorial2BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial2.4bpp");
static const u8 sOpenWorldTutorial2BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial2.bin");
static const u8 sOpenWorldTutorial2BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial2.gbapal");

static const u8 sOpenWorldTutorial3BgTiles[] =   INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial3.4bpp");
static const u8 sOpenWorldTutorial3BgMap[] =     INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial3.bin");
static const u8 sOpenWorldTutorial3BgPalette[] = INCBIN_U8("graphics/cutscene/tutorials/openworldtutorial3.gbapal");

static const u8 sBlankBgTiles[] =   INCBIN_U8("graphics/cutscene/blank.4bpp");
static const u8 sBlankBgMap[] =     INCBIN_U8("graphics/cutscene/blank.bin");
static const u8 sBlankBgPalette[] = INCBIN_U8("graphics/cutscene/blank.gbapal");


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
	[SCENEBGWARP] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sWarpBgTiles,
		.tileSize = sizeof(sWarpBgTiles),
        .map = sWarpBgMap,
		.mapSize = sizeof(sWarpBgMap),
        .palette = sWarpBgPalette,
		.palIdxCnt = 16
	},
	[SCENEBGCOURTNEYNIGHT] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sCourtneyNightBgTiles,
		.tileSize = sizeof(sCourtneyNightBgTiles),
        .map = sCourtneyNightBgMap,
		.mapSize = sizeof(sCourtneyNightBgMap),
        .palette = sCourtneyNightBgPalette,
		.palIdxCnt = 240
	},
	[SCENEBGCOURTNEYNEUTRAL] = 
    {
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sCourtneyNeutralBgTiles,
		.tileSize = sizeof(sCourtneyNeutralBgTiles),
        .map = sCourtneyNeutralBgMap,
		.mapSize = sizeof(sCourtneyNeutralBgMap),
        .palette = sCourtneyNeutralBgPalette,
		.palIdxCnt = 240
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
	[SCENEBGSHELLYNIGHT] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sShellyNightBgTiles,
		.tileSize = sizeof(sShellyNightBgTiles),
        .map = sShellyNightBgMap,
		.mapSize = sizeof(sShellyNightBgMap),
        .palette = sShellyNightBgPalette,
		.palIdxCnt = 224
	},
	[SCENEBGMAY] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sMayBgTiles,
		.tileSize = sizeof(sMayBgTiles),
        .map = sMayBgMap,
		.mapSize = sizeof(sMayBgMap),
        .palette = sMayBgPalette,
		.palIdxCnt = 224
	},
	[SCENEBGLUCY] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sLucyBgTiles,
		.tileSize = sizeof(sLucyBgTiles),
        .map = sLucyBgMap,
		.mapSize = sizeof(sLucyBgMap),
        .palette = sLucyBgPalette,
		.palIdxCnt = 48
	},
	[SCENEBGLANETTE] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sLanetteBgTiles,
		.tileSize = sizeof(sLanetteBgTiles),
        .map = sLanetteBgMap,
		.mapSize = sizeof(sLanetteBgMap),
        .palette = sLanetteBgPalette,
		.palIdxCnt = 224
	},
	[TUTORIALFOLLOWER1] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sFollowerTutorial1BgTiles,
		.tileSize = sizeof(sFollowerTutorial1BgTiles),
        .map = sFollowerTutorial1BgMap,
		.mapSize = sizeof(sFollowerTutorial1BgMap),
        .palette = sFollowerTutorial1BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIALFOLLOWER2] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sFollowerTutorial2BgTiles,
		.tileSize = sizeof(sFollowerTutorial2BgTiles),
        .map = sFollowerTutorial2BgMap,
		.mapSize = sizeof(sFollowerTutorial2BgMap),
        .palette = sFollowerTutorial2BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIALFOLLOWER3] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sFollowerTutorial3BgTiles,
		.tileSize = sizeof(sFollowerTutorial3BgTiles),
        .map = sFollowerTutorial3BgMap,
		.mapSize = sizeof(sFollowerTutorial3BgMap),
        .palette = sFollowerTutorial3BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIALFOLLOWER4] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sFollowerTutorial4BgTiles,
		.tileSize = sizeof(sFollowerTutorial4BgTiles),
        .map = sFollowerTutorial4BgMap,
		.mapSize = sizeof(sFollowerTutorial4BgMap),
        .palette = sFollowerTutorial4BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIAL_REALESTATE1] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sRealEstateTutorial1BgTiles,
		.tileSize = sizeof(sRealEstateTutorial1BgTiles),
        .map = sRealEstateTutorial1BgMap,
		.mapSize = sizeof(sRealEstateTutorial1BgMap),
        .palette = sRealEstateTutorial1BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIAL_REALESTATE2] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sRealEstateTutorial2BgTiles,
		.tileSize = sizeof(sRealEstateTutorial2BgTiles),
        .map = sRealEstateTutorial2BgMap,
		.mapSize = sizeof(sRealEstateTutorial2BgMap),
        .palette = sRealEstateTutorial2BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIAL_REALESTATE3] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sRealEstateTutorial3BgTiles,
		.tileSize = sizeof(sRealEstateTutorial3BgTiles),
        .map = sRealEstateTutorial3BgMap,
		.mapSize = sizeof(sRealEstateTutorial3BgMap),
        .palette = sRealEstateTutorial3BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIAL_REALESTATE4] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sRealEstateTutorial4BgTiles,
		.tileSize = sizeof(sRealEstateTutorial4BgTiles),
        .map = sRealEstateTutorial4BgMap,
		.mapSize = sizeof(sRealEstateTutorial4BgMap),
        .palette = sRealEstateTutorial4BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIAL_FACTIONS1] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sFactionsTutorial1BgTiles,
		.tileSize = sizeof(sFactionsTutorial1BgTiles),
        .map = sFactionsTutorial1BgMap,
		.mapSize = sizeof(sFactionsTutorial1BgMap),
        .palette = sFactionsTutorial1BgPalette,
		.palIdxCnt = 16
	},
	[TUTORIAL_FACTIONS2] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sFactionsTutorial2BgTiles,
		.tileSize = sizeof(sFactionsTutorial2BgTiles),
        .map = sFactionsTutorial2BgMap,
		.mapSize = sizeof(sFactionsTutorial2BgMap),
        .palette = sFactionsTutorial2BgPalette,
		.palIdxCnt = 16
	},
	[SCENEBGLEAF] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sLeafBgTiles,
		.tileSize = sizeof(sLeafBgTiles),
        .map = sLeafBgMap,
		.mapSize = sizeof(sLeafBgMap),
        .palette = sLeafBgPalette,
		.palIdxCnt = 224
	},
	[SCENEBGMOM] = 
	{
		.mode = CUTSCENE_8BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sMomBgTiles,
		.tileSize = sizeof(sMomBgTiles),
        .map = sMomBgMap,
		.mapSize = sizeof(sMomBgMap),
        .palette = sMomBgPalette,
		.palIdxCnt = 224
	},
	[SCENEBGOPENWORLDTUTORIAL1] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sOpenWorldTutorial1BgTiles,
		.tileSize = sizeof(sOpenWorldTutorial1BgTiles),
        .map = sOpenWorldTutorial1BgMap,
		.mapSize = sizeof(sOpenWorldTutorial1BgMap),
        .palette = sOpenWorldTutorial1BgPalette,
		.palIdxCnt = 16
	},
	[SCENEBGOPENWORLDTUTORIAL2] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sOpenWorldTutorial2BgTiles,
		.tileSize = sizeof(sOpenWorldTutorial2BgTiles),
        .map = sOpenWorldTutorial2BgMap,
		.mapSize = sizeof(sOpenWorldTutorial2BgMap),
        .palette = sOpenWorldTutorial2BgPalette,
		.palIdxCnt = 16
	},
	[SCENEBGOPENWORLDTUTORIAL3] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sOpenWorldTutorial3BgTiles,
		.tileSize = sizeof(sOpenWorldTutorial3BgTiles),
        .map = sOpenWorldTutorial3BgMap,
		.mapSize = sizeof(sOpenWorldTutorial3BgMap),
        .palette = sOpenWorldTutorial3BgPalette,
		.palIdxCnt = 16
	},
	[SCENEBGBLANK] = 
	{
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sBlankBgTiles,
		.tileSize = sizeof(sBlankBgTiles),
        .map = sBlankBgMap,
		.mapSize = sizeof(sBlankBgMap),
        .palette = sBlankBgPalette,
		.palIdxCnt = 16
	},
};

//spritescenes defined here

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
//ALIGNED(4) EWRAM_DATA u8 gCutsceneSpriteIDs[4] = {0};

//static void DrawCutsceneSpriteArrangement(u8 xStart, u8 yStart, u8 mugshotId)
//mugshot id here would be MUGSHOTLUCY for example, which has already been included.

//remove the mugshot arrangement
//(void)RyuRemoveCutsceneSpriteArrangement(void)
//{}

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
