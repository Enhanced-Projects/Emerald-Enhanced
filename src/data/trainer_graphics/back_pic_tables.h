const struct MonCoords gTrainerBackPicCoords[] =
{
    [TRAINER_BACK_PIC_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_DAWN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RED] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_LEAF] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_WALLY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_STEVEN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_SHELLY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_LANETTE] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_MINNIE] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_COURTNEY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_NURSE] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_GOLD] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_KRYSTAL] = {.size = 8, .y_offset = 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
#define TRAINER_BACK_SPRITE(trainerPic, sprite, size) [TRAINER_BACK_PIC_##trainerPic] = {(const u32 *)sprite, size, TRAINER_BACK_PIC_##trainerPic}

const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    TRAINER_BACK_SPRITE(BRENDAN, gTrainerBackPic_Brendan, 0x2000),
    TRAINER_BACK_SPRITE(DAWN, gTrainerBackPic_Dawn, 0x2000),
    TRAINER_BACK_SPRITE(RED, gTrainerBackPic_Red, 0x2800),
    TRAINER_BACK_SPRITE(LEAF, gTrainerBackPic_Leaf, 0x2800),
    TRAINER_BACK_SPRITE(RUBY_SAPPHIRE_BRENDAN, gTrainerBackPic_RubySapphireBrendan, 0x2000),
    TRAINER_BACK_SPRITE(RUBY_SAPPHIRE_MAY, gTrainerBackPic_RubySapphireMay, 0x2000),
    TRAINER_BACK_SPRITE(WALLY, gTrainerBackPic_Wally, 0x2000),
    TRAINER_BACK_SPRITE(STEVEN, gTrainerBackPic_Steven, 0x2000),
    TRAINER_BACK_SPRITE(SHELLY ,gTrainerBackPic_Shelly, 0x2000, ),
    TRAINER_BACK_SPRITE(LANETTE ,gTrainerBackPic_Lanette, 0x2000, ),
    TRAINER_BACK_SPRITE(MINNIE ,gTrainerBackPic_Minnie, 0x2000, ),
    TRAINER_BACK_SPRITE(COURTNEY ,gTrainerBackPic_Courtney, 0x2000, ),
    TRAINER_BACK_SPRITE(NURSE,gTrainerBackPic_Nurse, 0x2000, ),
    TRAINER_BACK_SPRITE(GOLD,gTrainerBackPic_Gold, 0x2000, ),
    TRAINER_BACK_SPRITE(KRYSTAL,gTrainerBackPic_Krystal, 0x2000, ),
};

#define TRAINER_BACK_PAL(trainerPic, pal) [TRAINER_BACK_PIC_##trainerPic] = {pal, TRAINER_BACK_PIC_##trainerPic}

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] =
{
    TRAINER_BACK_PAL(BRENDAN, gTrainerBackPicPal_Brendan),
    TRAINER_BACK_PAL(DAWN, gTrainerBackPicPal_Dawn),
    TRAINER_BACK_PAL(RED, gTrainerBackPicPalette_Red),
    TRAINER_BACK_PAL(LEAF, gTrainerBackPicPalette_Leaf),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_BRENDAN, gTrainerBackPicPal_RubySapphireBrendan),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_MAY, gTrainerBackPicPal_RubySapphireMay),
    TRAINER_BACK_PAL(WALLY, gTrainerBackPicPal_Wally),
    TRAINER_BACK_PAL(STEVEN, gTrainerBackPicPal_Steven),
    TRAINER_BACK_PAL(SHELLY, gTrainerBackPicPal_Shelly),
    TRAINER_BACK_PAL(LANETTE, gTrainerBackPicPal_Lanette),
    TRAINER_BACK_PAL(MINNIE, gTrainerBackPicPal_Minnie),
    TRAINER_BACK_PAL(COURTNEY, gTrainerBackPicPal_Courtney),
    TRAINER_BACK_PAL(NURSE, gTrainerBackPicPal_Nurse)
    TRAINER_BACK_PAL(GOLD, gTrainerBackPicPal_Gold),
    TRAINER_BACK_PAL(KRYSTAL, gTrainerBackPicPal_Krystal),
};
