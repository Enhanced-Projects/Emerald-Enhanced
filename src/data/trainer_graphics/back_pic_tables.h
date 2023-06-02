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
    [TRAINER_BACK_PIC_LUCY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_MOM] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_GLADION] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_LILLIE] = {.size = 8, .y_offset = 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    (const u32 *)gTrainerBackPic_Brendan, 0x2000, TRAINER_BACK_PIC_BRENDAN,
    (const u32 *)gTrainerBackPic_Dawn, 0x2000, TRAINER_BACK_PIC_DAWN,
    (const u32 *)gTrainerBackPic_Red, 0x2800, TRAINER_BACK_PIC_RED,
    (const u32 *)gTrainerBackPic_Leaf, 0x2800, TRAINER_BACK_PIC_LEAF,
    (const u32 *)gTrainerBackPic_RubySapphireBrendan, 0x2000, TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
    (const u32 *)gTrainerBackPic_RubySapphireMay, 0x2000, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY,
    (const u32 *)gTrainerBackPic_Wally, 0x2000, TRAINER_BACK_PIC_WALLY,
    (const u32 *)gTrainerBackPic_Steven, 0x2000, TRAINER_BACK_PIC_STEVEN,
    (const u32 *)gTrainerBackPic_Shelly, 0x2000, TRAINER_BACK_PIC_SHELLY,
    (const u32 *)gTrainerBackPic_Lanette, 0x2000, TRAINER_BACK_PIC_LANETTE,
    (const u32 *)gTrainerBackPic_Minnie, 0x2000, TRAINER_BACK_PIC_MINNIE,
    (const u32 *)gTrainerBackPic_Courtney, 0x2000, TRAINER_BACK_PIC_COURTNEY,
    (const u32 *)gTrainerBackPic_Nurse, 0x2000, TRAINER_BACK_PIC_NURSE,
    (const u32 *)gTrainerBackPic_Gold, 0x2000, TRAINER_BACK_PIC_GOLD,
    (const u32 *)gTrainerBackPic_Krystal, 0x2000, TRAINER_BACK_PIC_KRYSTAL,
    (const u32 *)gTrainerBackPic_Lucy, 0x2000, TRAINER_BACK_PIC_LUCY,
    (const u32 *)gTrainerBackPic_Mom, 0x2000, TRAINER_BACK_PIC_MOM,
    (const u32 *)gTrainerBackPic_Gladion, 0x3000, TRAINER_BACK_PIC_GLADION,
    (const u32 *)gTrainerBackPic_Lillie, 0x2000, TRAINER_BACK_PIC_LILLIE,
};

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
    TRAINER_BACK_PAL(NURSE, gTrainerBackPicPal_Nurse),
    TRAINER_BACK_PAL(GOLD, gTrainerBackPicPal_Gold),
    TRAINER_BACK_PAL(KRYSTAL, gTrainerBackPicPal_Krystal),
    TRAINER_BACK_PAL(LUCY, gTrainerBackPicPal_Lucy),
    TRAINER_BACK_PAL(MOM, gTrainerBackPicPal_Mom),
    TRAINER_BACK_PAL(GLADION, gTrainerBackPicPal_Gladion),
    TRAINER_BACK_PAL(LILLIE, gTrainerBackPicPal_Lillie)
};
