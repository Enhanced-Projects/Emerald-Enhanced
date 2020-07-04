#include "global.h"
#include "event_data.h"
#include "sprite.h"
#include "script.h"


static EWRAM_DATA u8 cutsceneSpriteId1 = 0;
static EWRAM_DATA u8 cutsceneSpriteId2 = 0;

static const u32 dawnSceneGfx[] = INCBIN_U32("graphics/cutscene/dawnHeadshot.4bpp");
static const u16 dawnScenePal[] = INCBIN_U16("graphics/cutscene/dawnHeadshotPalette.gbapal");
static const u32 leafSceneGfx[] = INCBIN_U32("graphics/cutscene/leafHeadshot.4bpp");
static const u16 leafScenePal[] = INCBIN_U16("graphics/cutscene/leafHeadshotPalette.gbapal");
static const u32 garySceneGfx[] = INCBIN_U32("graphics/cutscene/garyHeadshot.4bpp");
static const u16 garyScenePal[] = INCBIN_U16("graphics/cutscene/garyHeadshotPalette.gbapal");
static const u32 brendanSceneGfx[] = INCBIN_U32("graphics/cutscene/brendanHeadshot.4bpp");
static const u16 brendanScenePal[] = INCBIN_U16("graphics/cutscene/brendanHeadshotPalette.gbapal");
static const u32 lanetteSceneGfx[] = INCBIN_U32("graphics/cutscene/lanetteHeadshot.4bpp");
static const u16 lanetteScenePal[] = INCBIN_U16("graphics/cutscene/lanetteHeadshotPalette.gbapal");
//Dawn

const struct SpriteSheet dawnHeadshotSpriteSheet =
{
    .data = dawnSceneGfx,
    .size = sizeof(dawnSceneGfx),
    .tag = 1201
};

const struct SpritePalette dawnScenePalette =
{
    .data = dawnScenePal, 
	.tag = 1201
};

static const struct OamData dawnSceneOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 0
};

const struct SpriteTemplate dawnSceneSpriteTemplate =
{
    .tileTag = 1201,
    .paletteTag = 1201,
    .oam = &dawnSceneOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

//Leaf
const struct SpriteSheet leafHeadshotSpriteSheet =
{
    .data = leafSceneGfx,
    .size = sizeof(leafSceneGfx),
    .tag = 1302
};

const struct SpritePalette leafScenePalette =
{
    .data = leafScenePal, 
	.tag = 1302
};

static const struct OamData leafSceneOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 0
};

const struct SpriteTemplate leafSceneSpriteTemplate =
{
    .tileTag = 1302,
    .paletteTag = 1302,
    .oam = &leafSceneOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

//Gary

const struct SpriteSheet garyHeadshotSpriteSheet =
{
    .data = garySceneGfx,
    .size = sizeof(garySceneGfx),
    .tag = 1403
};

const struct SpritePalette garyScenePalette =
{
    .data = garyScenePal, 
	.tag = 1403
};

static const struct OamData garySceneOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 0
};

const struct SpriteTemplate garySceneSpriteTemplate =
{
    .tileTag = 1403,
    .paletteTag = 1403,
    .oam = &garySceneOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

//Brendan

const struct SpriteSheet brendanHeadshotSpriteSheet =
{
    .data = brendanSceneGfx,
    .size = sizeof(brendanSceneGfx),
    .tag = 1403
};

const struct SpritePalette brendanScenePalette =
{
    .data = brendanScenePal, 
	.tag = 1403
};

static const struct OamData brendanSceneOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 0
};

const struct SpriteTemplate brendanSceneSpriteTemplate =
{
    .tileTag = 1403,
    .paletteTag = 1403,
    .oam = &brendanSceneOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

//Lanette

const struct SpriteSheet lanetteHeadshotSpriteSheet =
{
    .data = lanetteSceneGfx,
    .size = sizeof(lanetteSceneGfx),
    .tag = 1407
};

const struct SpritePalette lanetteScenePalette =
{
    .data = lanetteScenePal, 
	.tag = 1407
};

static const struct OamData lanetteSceneOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 0
};

const struct SpriteTemplate lanetteSceneSpriteTemplate =
{
    .tileTag = 1407,
    .paletteTag = 1407,
    .oam = &lanetteSceneOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

bool8 ScrCmd_drawheadshot(struct ScriptContext *ctx)
{
    u8 image = ScriptReadByte(ctx);

    switch (image)
    {
        case 1:
            {
                LoadSpriteSheet(&dawnHeadshotSpriteSheet);
                LoadSpritePalette(&dawnScenePalette);
                cutsceneSpriteId1 = (CreateSprite(&dawnSceneSpriteTemplate, 220, 83, 1));
                return FALSE;
            }
        case 2:
            {
                LoadSpriteSheet(&brendanHeadshotSpriteSheet);
                LoadSpritePalette(&brendanScenePalette);
                cutsceneSpriteId1 = (CreateSprite(&brendanSceneSpriteTemplate, 220, 83, 1));
                return FALSE;
            }
        case 3:
            {
                LoadSpriteSheet(&leafHeadshotSpriteSheet);
                LoadSpritePalette(&leafScenePalette);
                cutsceneSpriteId1 = 1;
                cutsceneSpriteId1 = (CreateSprite(&leafSceneSpriteTemplate, 220, 83, 1));
                return FALSE;
            }
        case 4:
            {
                LoadSpriteSheet(&garyHeadshotSpriteSheet);
                LoadSpritePalette(&garyScenePalette);
                cutsceneSpriteId1 = (CreateSprite(&garySceneSpriteTemplate, 220, 83, 1));
                return FALSE;
            }
        case 5:
            {
                LoadSpriteSheet(&lanetteHeadshotSpriteSheet);
                LoadSpritePalette(&lanetteScenePalette);
                cutsceneSpriteId1 = (CreateSprite(&lanetteSceneSpriteTemplate, 220, 83, 1));
                return FALSE;
            }
        default:
            {
                return FALSE;
            }
    }
}
