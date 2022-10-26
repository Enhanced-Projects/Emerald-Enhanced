#include "global.h"
#include "start_menu_helper.h"
#include "event_data.h"



const u32 DevonLogoGfx[] = INCBIN_U32("graphics/start_menu/devonLogo.4bpp");
const u16 DevonLogoPal[] = INCBIN_U16("graphics/start_menu/devonLogo.gbapal");
const u32 AquaLogoGfx[] = INCBIN_U32("graphics/start_menu/aquaLogo.4bpp");
const u16 AquaLogoPal[] = INCBIN_U16("graphics/start_menu/aquaLogo.gbapal");
const u32 MagmaLogoGfx[] = INCBIN_U32("graphics/start_menu/magmaLogo.4bpp");
const u16 MagmaLogoPal[] = INCBIN_U16("graphics/start_menu/magmaLogo.gbapal");
const u32 PokeballLogoGfx[] = INCBIN_U32("graphics/start_menu/pokeballLogo.4bpp");
const u16 PokeballLogoPal[] = INCBIN_U16("graphics/start_menu/pokeballLogo.gbapal");

EWRAM_DATA u8 MenuSpriteId1 = 0;

static const struct SpriteSheet DevonLogoSheet =
{
    .data = DevonLogoGfx,
    .size = sizeof(DevonLogoGfx),
    .tag = 2652
};

static const struct SpritePalette DevonLogoPalette =
{
    .data = DevonLogoPal, 
	.tag = 2652
};

static const struct OamData DevonLogoOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0
};

static const struct SpriteTemplate DevonLogoSpriteTemplate =
{
    .tileTag = 2652,
    .paletteTag = 2652,
    .oam = &DevonLogoOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};


static const struct SpriteSheet AquaLogoSheet =
{
    .data = AquaLogoGfx,
    .size = sizeof(AquaLogoGfx),
    .tag = 1254
};

static const struct SpritePalette AquaLogoPalette =
{
    .data = AquaLogoPal, 
	.tag = 1254
};

static const struct OamData AquaLogoOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0
};

static const struct SpriteTemplate AquaLogoSpriteTemplate =
{
    .tileTag = 1254,
    .paletteTag = 1254,
    .oam = &AquaLogoOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};


static const struct SpriteSheet MagmaLogoSheet =
{
    .data = MagmaLogoGfx,
    .size = sizeof(MagmaLogoGfx),
    .tag = 2659
};

static const struct SpritePalette MagmaLogoPalette =
{
    .data = MagmaLogoPal, 
	.tag = 2659
};

static const struct OamData MagmaLogoOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0
};

static const struct SpriteTemplate MagmaLogoSpriteTemplate =
{
    .tileTag = 2659,
    .paletteTag = 2659,
    .oam = &MagmaLogoOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet PokeballLogoSheet =
{
    .data = PokeballLogoGfx,
    .size = sizeof(PokeballLogoGfx),
    .tag = 2651
};

static const struct SpritePalette PokeballLogoPalette =
{
    .data = PokeballLogoPal, 
	.tag = 2651
};

static const struct OamData PokeballLogoOamData =
{
    .y = 0,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0
};

static const struct SpriteTemplate PokeballLogoSpriteTemplate =
{
    .tileTag = 2651,
    .paletteTag = 2651,
    .oam = &PokeballLogoOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};



void DrawTeamLogo(void)
{
    if (FlagGet(FLAG_RYU_PLAYER_HELPING_DEVON) == TRUE)
    {
        LoadSpriteSheet(&DevonLogoSheet);
        LoadSpritePalette(&DevonLogoPalette);
        MenuSpriteId1 = (CreateSprite(&DevonLogoSpriteTemplate, 224, 131, 0));
    }
    else if (FlagGet(FLAG_RYU_PLAYER_HELPING_AQUA) == TRUE)
    {
        LoadSpriteSheet(&AquaLogoSheet);
        LoadSpritePalette(&AquaLogoPalette);
        MenuSpriteId1 = (CreateSprite(&AquaLogoSpriteTemplate, 224, 132, 0));
    }
    else if (FlagGet(FLAG_RYU_PLAYER_HELPING_MAGMA)== TRUE)
    {
        LoadSpriteSheet(&MagmaLogoSheet);
        LoadSpritePalette(&MagmaLogoPalette);
        MenuSpriteId1 = (CreateSprite(&MagmaLogoSpriteTemplate, 224, 132, 0));
    }
    else
    {
        LoadSpriteSheet(&PokeballLogoSheet);
        LoadSpritePalette(&PokeballLogoPalette);
        MenuSpriteId1 = (CreateSprite(&PokeballLogoSpriteTemplate, 224, 132, 0));
    }

}