const struct FacilityMon gBattleFrontierMons[NUM_FRONTIER_MONS] =
{
    [FRONTIER_MON_SUNKERN] = {
        .species = SPECIES_SUNKERN,
        .moves = {MOVE_ENDEAVOR, MOVE_LEECH_SEED, MOVE_SEED_BOMB, MOVE_TOXIC},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AZURILL] = {
        .species = SPECIES_AZURILL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_KNOCK_OFF, MOVE_WATERFALL, MOVE_RETURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CATERPIE] = {
        .species = SPECIES_CATERPIE,
        .moves = {MOVE_BUG_BITE, MOVE_TACKLE, MOVE_ELECTROWEB, MOVE_STRING_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WEEDLE] = {
        .species = SPECIES_WEEDLE,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_ELECTROWEB, MOVE_STRING_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WURMPLE] = {
        .species = SPECIES_WURMPLE,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_TACKLE, MOVE_STRING_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RALTS] = {
        .species = SPECIES_RALTS,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_DISABLE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGIKARP] = {
        .species = SPECIES_MAGIKARP,
        .moves = {MOVE_SPLASH, MOVE_SPLASH, MOVE_SPLASH, MOVE_SPLASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FEEBAS] = {
        .species = SPECIES_FEEBAS,
        .moves = {MOVE_MIRROR_COAT, MOVE_FLAIL, MOVE_LIGHT_SCREEN, MOVE_TOXIC},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAPOD] = {
        .species = SPECIES_METAPOD,
        .moves = {MOVE_BUG_BITE, MOVE_TACKLE, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KAKUNA] = {
        .species = SPECIES_KAKUNA,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PICHU] = {
        .species = SPECIES_PICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_GRASS_KNOT, MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SILCOON] = {
        .species = SPECIES_SILCOON,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_TACKLE, MOVE_STRING_SHOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CASCOON] = {
        .species = SPECIES_CASCOON,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_TACKLE, MOVE_STRING_SHOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_IGGLYBUFF] = {
        .species = SPECIES_IGGLYBUFF,
        .moves = {MOVE_HYPER_VOICE, MOVE_DAZZLING_GLEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WOOPER] = {
        .species = SPECIES_WOOPER,
        .moves = {MOVE_DIVE, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TYROGUE] = {
        .species = SPECIES_TYROGUE,
        .moves = {MOVE_FAKE_OUT, MOVE_MACH_PUNCH, MOVE_HI_JUMP_KICK, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SENTRET] = {
        .species = SPECIES_SENTRET,
        .moves = {MOVE_HYPER_VOICE, MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLEFFA] = {
        .species = SPECIES_CLEFFA,
        .moves = {MOVE_MOONBLAST, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEEDOT] = {
        .species = SPECIES_SEEDOT,
        .moves = {MOVE_SOLAR_BEAM, MOVE_HIDDEN_POWER, MOVE_GROWTH, MOVE_SUNNY_DAY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LOTAD] = {
        .species = SPECIES_LOTAD,
        .moves = {MOVE_SURF, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_POOCHYENA] = {
        .species = SPECIES_POOCHYENA,
        .moves = {MOVE_CRUNCH, MOVE_PLAY_ROUGH, MOVE_POISON_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHEDINJA] = {
        .species = SPECIES_SHEDINJA,
        .moves = {MOVE_X_SCISSOR, MOVE_SHADOW_SNEAK, MOVE_TOXIC, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAKUHITA] = {
        .species = SPECIES_MAKUHITA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISMUR] = {
        .species = SPECIES_WHISMUR,
        .moves = {MOVE_HYPER_VOICE, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ZIGZAGOON] = {
        .species = SPECIES_ZIGZAGOON,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SEED_BOMB, MOVE_SUBSTITUTE, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ZUBAT] = {
        .species = SPECIES_ZUBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_PURSUIT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TOGEPI] = {
        .species = SPECIES_TOGEPI,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_FIRE_BLAST, MOVE_SOFT_BOILED, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SPINARAK] = {
        .species = SPECIES_SPINARAK,
        .moves = {MOVE_STICKY_WEB, MOVE_TOXIC_SPIKES, MOVE_MEGAHORN, MOVE_TOXIC_THREAD},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MARILL] = {
        .species = SPECIES_MARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_KNOCK_OFF, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HOPPIP] = {
        .species = SPECIES_HOPPIP,
        .moves = {MOVE_SLEEP_POWDER, MOVE_STRENGTH_SAP, MOVE_LEECH_SEED, MOVE_SUBSTITUTE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLUGMA] = {
        .species = SPECIES_SLUGMA,
        .moves = {MOVE_FIRE_BLAST, MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWINUB] = {
        .species = SPECIES_SWINUB,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_SUPERPOWER, MOVE_AVALANCHE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SMEARGLE] = {
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SPORE, MOVE_BATON_PASS, MOVE_BELLY_DRUM},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PIDGEY] = {
        .species = SPECIES_PIDGEY,
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_UPROAR, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RATTATA] = {
        .species = SPECIES_RATTATA,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_FLAME_WHEEL, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WYNAUT] = {
        .species = SPECIES_WYNAUT,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_SAFEGUARD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SKITTY] = {
        .species = SPECIES_SKITTY,
        .moves = {MOVE_HYPER_VOICE, MOVE_MOONBLAST, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SPEAROW] = {
        .species = SPECIES_SPEAROW,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HOOTHOOT] = {
        .species = SPECIES_HOOTHOOT,
        .moves = {MOVE_HURRICANE, MOVE_HYPER_VOICE, MOVE_HEAT_WAVE, MOVE_AIR_SLASH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DIGLETT] = {
        .species = SPECIES_DIGLETT,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_ROCK_SLIDE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LEDYBA] = {
        .species = SPECIES_LEDYBA,
        .moves = {MOVE_ENCORE, MOVE_SWORDS_DANCE, MOVE_AGILITY, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINCADA] = {
        .species = SPECIES_NINCADA,
        .moves = {MOVE_LEECH_LIFE, MOVE_DIG, MOVE_TOXIC, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SURSKIT] = {
        .species = SPECIES_SURSKIT,
        .moves = {MOVE_STICKY_WEB, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JIGGLYPUFF] = {
        .species = SPECIES_JIGGLYPUFF,
        .moves = {MOVE_HYPER_VOICE, MOVE_DAZZLING_GLEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAILLOW] = {
        .species = SPECIES_TAILLOW,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1    
    },
    [FRONTIER_MON_WINGULL] = {
        .species = SPECIES_WINGULL,
        .moves = {MOVE_HURRICANE, MOVE_SCALD, MOVE_HIDDEN_POWER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1,
    },
    [FRONTIER_MON_NIDORAN_M] = {
        .species = SPECIES_NIDORAN_M,
        .moves = {MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_HORN_DRILL, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NIDORAN_F] = {
        .species = SPECIES_NIDORAN_F,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KIRLIA] = {
        .species = SPECIES_KIRLIA,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_DISABLE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAREEP] = {
        .species = SPECIES_MAREEP,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AGILITY, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEDITITE] = {
        .species = SPECIES_MEDITITE,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKOTH] = {
        .species = SPECIES_SLAKOTH,
        .moves = {MOVE_ROAR_OF_TIME, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PARAS] = {
        .species = SPECIES_PARAS,
        .moves = {MOVE_SPORE, MOVE_LEECH_LIFE, MOVE_SEED_BOMB, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EKANS] = {
        .species = SPECIES_EKANS,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_GLARE, MOVE_COIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DITTO] = {
        .species = SPECIES_DITTO,
        .moves = {MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BARBOACH] = {
        .species = SPECIES_BARBOACH,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_BOUNCE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEOWTH] = {
        .species = SPECIES_MEOWTH,
        .moves = {MOVE_FAKE_OUT, MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_U_TURN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PINECO] = {
        .species = SPECIES_PINECO,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_REFLECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TRAPINCH] = {
        .species = SPECIES_TRAPINCH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SUPERPOWER, MOVE_CRUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SPHEAL] = {
        .species = SPECIES_SPHEAL,
        .moves = {MOVE_SHEER_COLD, MOVE_FISSURE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HORSEA] = {
        .species = SPECIES_HORSEA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_SHROOMISH] = {
        .species = SPECIES_SHROOMISH,
        .moves = {MOVE_SPORE, MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUPPET] = {
        .species = SPECIES_SHUPPET,
        .moves = {MOVE_KNOCK_OFF, MOVE_SHADOW_SNEAK, MOVE_CURSE, MOVE_TRICK_ROOM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSKULL] = {
        .species = SPECIES_DUSKULL,
        .moves = {MOVE_TOXIC, MOVE_DISABLE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRIKE] = {
        .species = SPECIES_ELECTRIKE,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLAMETHROWER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VULPIX] = {
        .species = SPECIES_VULPIX,
        .moves = {MOVE_FLAMETHROWER, MOVE_OVERHEAT, MOVE_ENERGY_BALL, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PIKACHU] = {
        .species = SPECIES_PIKACHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_GRASS_KNOT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIGHT_BALL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SANDSHREW] = {
        .species = SPECIES_SANDSHREW,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_POLIWAG] = {
        .species = SPECIES_POLIWAG,
        .moves = {MOVE_WATERFALL, MOVE_RETURN, MOVE_BELLY_DRUM, MOVE_HYPNOSIS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BELLSPROUT] = {
        .species = SPECIES_BELLSPROUT,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GEODUDE] = {
        .species = SPECIES_GEODUDE,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRATINI] = {
        .species = SPECIES_DRATINI,
        .moves = {MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNUBBULL] = {
        .species = SPECIES_SNUBBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REMORAID] = {
        .species = SPECIES_REMORAID,
        .moves = {MOVE_WATER_SPOUT, MOVE_ICE_BEAM, MOVE_SEED_BOMB, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LARVITAR] = {
        .species = SPECIES_LARVITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SUPERPOWER, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BALTOY] = {
        .species = SPECIES_BALTOY,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORUNT] = {
        .species = SPECIES_SNORUNT,
        .moves = {MOVE_ICE_SHARD, MOVE_CRUNCH, MOVE_BODY_SLAM, MOVE_AVALANCHE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BAGON] = {
        .species = SPECIES_BAGON,
        .moves = {MOVE_DRAGON_RUSH, MOVE_FIRE_FANG, MOVE_THUNDER_FANG, MOVE_HONE_CLAWS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BELDUM] = {
        .species = SPECIES_BELDUM,
        .moves = {MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT, MOVE_TAKE_DOWN, MOVE_IRON_DEFENSE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GULPIN] = {
        .species = SPECIES_GULPIN,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_TOXIC, MOVE_SLUDGE_BOMB, MOVE_STOCKPILE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENONAT] = {
        .species = SPECIES_VENONAT,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SLEEP_POWDER, MOVE_LEECH_LIFE, MOVE_MORNING_SUN},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MANKEY] = {
        .species = SPECIES_MANKEY,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHOP] = {
        .species = SPECIES_MACHOP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHELLDER] = {
        .species = SPECIES_SHELLDER,
        .moves = {MOVE_LIQUIDATION, MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SMOOCHUM] = {
        .species = SPECIES_SMOOCHUM,
        .moves = {MOVE_ICE_BEAM, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NUMEL] = {
        .species = SPECIES_NUMEL,
        .moves = {MOVE_ERUPTION, MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CARVANHA] = {
        .species = SPECIES_CARVANHA,
        .moves = {MOVE_CRUNCH, MOVE_AQUA_JET, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CORPHISH] = {
        .species = SPECIES_CORPHISH,
        .moves = {MOVE_AQUA_JET, MOVE_KNOCK_OFF, MOVE_GUILLOTINE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHARMANDER] = {
        .species = SPECIES_CHARMANDER,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_PUNCH, MOVE_FLAME_CHARGE, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CYNDAQUIL] = {
        .species = SPECIES_CYNDAQUIL,
        .moves = {MOVE_ERUPTION, MOVE_FLAMETHROWER, MOVE_EXTRASENSORY, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_ABRA] = {
        .species = SPECIES_ABRA,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_COUNTER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DODUO] = {
        .species = SPECIES_DODUO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_RETURN, MOVE_JUMP_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GASTLY] = {
        .species = SPECIES_GASTLY,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_DAZZLING_GLEAM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SWABLU] = {
        .species = SPECIES_SWABLU,
        .moves = {MOVE_HYPER_VOICE, MOVE_HEAT_WAVE, MOVE_COTTON_GUARD, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TREECKO] = {
        .species = SPECIES_TREECKO,
        .moves = {MOVE_SEED_BOMB, MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TORCHIC] = {
        .species = SPECIES_TORCHIC,
        .moves = {MOVE_FLAME_CHARGE, MOVE_SWORDS_DANCE, MOVE_EE_PROTECT, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MUDKIP] = {
        .species = SPECIES_MUDKIP,
        .moves = {MOVE_DIVE, MOVE_AVALANCHE, MOVE_SUPERPOWER, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SQUIRTLE] = {
        .species = SPECIES_SQUIRTLE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_AURA_SPHERE, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOTODILE] = {
        .species = SPECIES_TOTODILE,
        .moves = {MOVE_AQUA_JET, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLOWPOKE] = {
        .species = SPECIES_SLOWPOKE,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BULBASAUR] = {
        .species = SPECIES_BULBASAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_CHIKORITA] = {
        .species = SPECIES_CHIKORITA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_AROMATHERAPY, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ODDISH] = {
        .species = SPECIES_ODDISH,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_PSYDUCK] = {
        .species = SPECIES_PSYDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CUBONE] = {
        .species = SPECIES_CUBONE,
        .moves = {MOVE_BONEMERANG, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_FIRE_PUNCH},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLDEEN] = {
        .species = SPECIES_GOLDEEN,
        .moves = {MOVE_HORN_DRILL, MOVE_DIVE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NATU] = {
        .species = SPECIES_NATU,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_ROOST, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLEFAIRY] = {
        .species = SPECIES_CLEFAIRY,
        .moves = {MOVE_MOONBLAST, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGNEMITE] = {
        .species = SPECIES_MAGNEMITE,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEEL] = {
        .species = SPECIES_SEEL,
        .moves = {MOVE_HORN_DRILL, MOVE_SHEER_COLD, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GRIMER] = {
        .species = SPECIES_GRIMER,
        .moves = {MOVE_POISON_JAB, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KRABBY] = {
        .species = SPECIES_KRABBY,
        .moves = {MOVE_GUILLOTINE, MOVE_KNOCK_OFF, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGCUTE] = {
        .species = SPECIES_EXEGGCUTE,
        .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_EEVEE] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_BITE, MOVE_DIG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DROWZEE] = {
        .species = SPECIES_DROWZEE,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VOLTORB] = {
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH, MOVE_SIGNAL_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHINCHOU] = {
        .species = SPECIES_CHINCHOU,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TEDDIURSA] = {
        .species = SPECIES_TEDDIURSA,
        .moves = {MOVE_RETURN, MOVE_CRUNCH, MOVE_CLOSE_COMBAT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DELIBIRD] = {
        .species = SPECIES_DELIBIRD,
        .moves = {MOVE_AERIAL_ACE, MOVE_ICE_SHARD, MOVE_BRICK_BREAK, MOVE_SEED_BOMB},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HOUNDOUR] = {
        .species = SPECIES_HOUNDOUR,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_COUNTER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PHANPY] = {
        .species = SPECIES_PHANPY,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_ROCK_TOMB, MOVE_FISSURE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SPOINK] = {
        .species = SPECIES_SPOINK,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_GRASS_KNOT, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARON] = {
        .species = SPECIES_ARON,
        .moves = {MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUVDISC] = {
        .species = SPECIES_LUVDISC,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_TENTACOOL] = {
        .species = SPECIES_TENTACOOL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CACNEA] = {
        .species = SPECIES_CACNEA,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UNOWN] = {
        .species = SPECIES_UNOWN,
        .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 17,
        .ability = 0
    },
    [FRONTIER_MON_KOFFING] = {
        .species = SPECIES_KOFFING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STARYU] = {
        .species = SPECIES_STARYU,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_POWER_GEM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SKIPLOOM] = {
        .species = SPECIES_SKIPLOOM,
        .moves = {MOVE_SLEEP_POWDER, MOVE_STRENGTH_SAP, MOVE_LEECH_SEED, MOVE_SUBSTITUTE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NUZLEAF] = {
        .species = SPECIES_NUZLEAF,
        .moves = {MOVE_SOLAR_BEAM, MOVE_DARK_PULSE, MOVE_SUNNY_DAY, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LOMBRE] = {
        .species = SPECIES_LOMBRE,
        .moves = {MOVE_SURF, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIBRAVA] = {
        .species = SPECIES_VIBRAVA,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_U_TURN, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RHYHORN] = {
        .species = SPECIES_RHYHORN,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAMPERL] = {
        .species = SPECIES_CLAMPERL,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_BRINE},
        .heldItem = ITEM_DEEP_SEA_TOOTH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_PIDGEOTTO] = {
        .species = SPECIES_PIDGEOTTO,
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_UPROAR, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GROWLITHE] = {
        .species = SPECIES_GROWLITHE,
        .moves = {MOVE_FLARE_BLITZ, MOVE_WILD_CHARGE, MOVE_FLAME_CHARGE, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FARFETCHD] = {
        .species = SPECIES_FARFETCHD,
        .moves = {MOVE_SLASH, MOVE_LEAF_BLADE, MOVE_NIGHT_SLASH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_STICK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMANYTE] = {
        .species = SPECIES_OMANYTE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_MUD_BOMB, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KABUTO] = {
        .species = SPECIES_KABUTO,
        .moves = {MOVE_AQUA_JET, MOVE_ROCK_SLIDE, MOVE_KNOCK_OFF, MOVE_DIG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LILEEP] = {
        .species = SPECIES_LILEEP,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ANORITH] = {
        .species = SPECIES_ANORITH,
        .moves = {MOVE_X_SCISSOR, MOVE_ROCK_SLIDE, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AIPOM] = {
        .species = SPECIES_AIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_BRICK_BREAK, MOVE_SHADOW_CLAW},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ELEKID] = {
        .species = SPECIES_ELEKID,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH, MOVE_CROSS_CHOP},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LOUDRED] = {
        .species = SPECIES_LOUDRED,
        .moves = {MOVE_RETURN, MOVE_HAMMER_ARM, MOVE_SHADOW_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SPINDA] = {
        .species = SPECIES_SPINDA,
        .moves = {MOVE_SUPERPOWER, MOVE_RETURN, MOVE_SUCKER_PUNCH, MOVE_BATON_PASS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NIDORINA] = {
        .species = SPECIES_NIDORINA,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDORINO] = {
        .species = SPECIES_NIDORINO,
        .moves = {MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_HORN_DRILL, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLAAFFY] = {
        .species = SPECIES_FLAAFFY,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AGILITY, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGBY] = {
        .species = SPECIES_MAGBY,
        .moves = {MOVE_FIRE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_MACH_PUNCH, MOVE_BELLY_DRUM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NOSEPASS] = {
        .species = SPECIES_NOSEPASS,
        .moves = {MOVE_STONE_EDGE, MOVE_FIRE_PUNCH, MOVE_THUNDER_WAVE, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CORSOLA] = {
        .species = SPECIES_CORSOLA,
        .moves = {MOVE_HEAD_SMASH, MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAWILE] = {
        .species = SPECIES_MAWILE,
        .moves = {MOVE_ICE_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG, MOVE_CRUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BUTTERFREE] = {
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEEDRILL] = {
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_POLIWHIRL] = {
        .species = SPECIES_POLIWHIRL,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_BELLY_DRUM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ONIX] = {
        .species = SPECIES_ONIX,
        .moves = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_SUBSTITUTE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BEAUTIFLY] = {
        .species = SPECIES_BEAUTIFLY,
        .moves = {MOVE_BUG_BUZZ, MOVE_HIDDEN_POWER, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_DUSTOX] = {
        .species = SPECIES_DUSTOX,
        .moves = {MOVE_GUNK_SHOT, MOVE_LEECH_LIFE, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LEDIAN] = {
        .species = SPECIES_LEDIAN,
        .moves = {MOVE_ENCORE, MOVE_SWORDS_DANCE, MOVE_AGILITY, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARIADOS] = {
        .species = SPECIES_ARIADOS,
        .moves = {MOVE_STICKY_WEB, MOVE_TOXIC_SPIKES, MOVE_MEGAHORN, MOVE_TOXIC_THREAD},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_YANMA] = {
        .species = SPECIES_YANMA,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_GIGA_DRAIN, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DELCATTY_1] = {
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_HYPER_VOICE, MOVE_ENERGY_BALL, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SABLEYE_1] = {
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_DARK_PULSE, MOVE_EE_PROTECT, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LICKITUNG_1] = {
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_WRING_OUT, MOVE_FIRE_BLAST, MOVE_ICE_BEAM, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WEEPINBELL_1] = {
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GRAVELER_1] = {
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_EXPLOSION, MOVE_AUTOTOMIZE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GLOOM_1] = {
        .species = SPECIES_GLOOM,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_1] = {
        .species = SPECIES_PORYGON,
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KADABRA_1] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_COUNTER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILMER_1] = {
        .species = SPECIES_WAILMER,
        .moves = {MOVE_SCALD, MOVE_ROAR, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ROSELIA_1] = {
        .species = SPECIES_ROSELIA,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VOLBEAT_1] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_BUG_BUZZ, MOVE_THUNDERBOLT, MOVE_TAIL_GLOW, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ILLUMISE_1] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_BUG_BUZZ, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_DAZZLING_GLEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_IVYSAUR_1] = {
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_EARTH_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_CHARMELEON_1] = {
        .species = SPECIES_CHARMELEON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_PUNCH, MOVE_FLAME_CHARGE, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WARTORTLE_1] = {
        .species = SPECIES_WARTORTLE,
        .moves = {MOVE_AQUA_JET, MOVE_ICE_PUNCH, MOVE_POWER_UP_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PARASECT_1] = {
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_LEECH_LIFE, MOVE_SEED_BOMB, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHOKE_1] = {
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HAUNTER_1] = {
        .species = SPECIES_HAUNTER,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_DAZZLING_GLEAM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BAYLEEF_1] = {
        .species = SPECIES_BAYLEEF,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_AROMATHERAPY, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUILAVA_1] = {
        .species = SPECIES_QUILAVA,
        .moves = {MOVE_ERUPTION, MOVE_FLAMETHROWER, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_CROCONAW_1] = {
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_AQUA_JET, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TOGETIC_1] = {
        .species = SPECIES_TOGETIC,
        .moves = {MOVE_AIR_SLASH, MOVE_THUNDER_WAVE, MOVE_ROOST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MURKROW_1] = {
        .species = SPECIES_MURKROW,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SUCKER_PUNCH, MOVE_SUPERPOWER, MOVE_PURSUIT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WOBBUFFET_1] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_SAFEGUARD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PLUSLE_1] = {
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_GRASS_KNOT, MOVE_ENCORE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MINUN_1] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_ENCORE, MOVE_TOXIC, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GROVYLE_1] = {
        .species = SPECIES_GROVYLE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_COMBUSKEN_1] = {
        .species = SPECIES_COMBUSKEN,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER, MOVE_HIDDEN_POWER, MOVE_OVERHEAT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MARSHTOMP_1] = {
        .species = SPECIES_MARSHTOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_DIVE, MOVE_ICE_PUNCH, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PONYTA_1] = {
        .species = SPECIES_PONYTA,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HIGH_HORSEPOWER, MOVE_WILD_CHARGE, MOVE_LOW_KICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AZUMARILL_1] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_KNOCK_OFF, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUDOWOODO_1] = {
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_HEAD_SMASH, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGCARGO_1] = {
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_FIRE_BLAST, MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PUPITAR_1] = {
        .species = SPECIES_PUPITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUBSTITUTE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEALEO_1] = {
        .species = SPECIES_SEALEO,
        .moves = {MOVE_ICE_BEAM, MOVE_SHEER_COLD, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RATICATE_1] = {
        .species = SPECIES_RATICATE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MASQUERAIN_1] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_BUG_BUZZ, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_1] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_COIL, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUNSPARCE_1] = {
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_BODY_SLAM, MOVE_ROCK_SLIDE, MOVE_COIL, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONAIR_1] = {
        .species = SPECIES_DRAGONAIR,
        .moves = {MOVE_OUTRAGE, MOVE_DRAGON_DANCE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIGHTYENA_1] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LINOONE_1] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SHADOW_CLAW, MOVE_SUBSTITUTE, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CASTFORM_1] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_FIRE_BLAST, MOVE_HYDRO_PUMP, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHELGON_1] = {
        .species = SPECIES_SHELGON,
        .moves = {MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_CRUNCH, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_METANG_1] = {
        .species = SPECIES_METANG,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WIGGLYTUFF_1] = {
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT, MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUNFLORA_1] = {
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_SOLAR_BEAM, MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KADABRA_3] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLIGAR_1] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_GUILLOTINE, MOVE_EARTHQUAKE, MOVE_THUNDER_FANG, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_QWILFISH_1] = {
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_LIQUIDATION, MOVE_POISON_JAB, MOVE_TOXIC_SPIKES, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNEASEL_1] = {
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_ICE_SHARD, MOVE_KNOCK_OFF, MOVE_LOW_KICK, MOVE_PURSUIT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PELIPPER_1] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_SURF, MOVE_HURRICANE, MOVE_ICE_BEAM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_1] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_WORK_UP},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LAIRON_1] = {
        .species = SPECIES_LAIRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TANGELA_1] = {
        .species = SPECIES_TANGELA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_MORNING_SUN, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ARBOK_1] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_GLARE, MOVE_COIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PERSIAN_1] = {
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FAKE_OUT, MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_U_TURN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEADRA_1] = {
        .species = SPECIES_SEADRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_KECLEON_1] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_RECOVER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VIGOROTH_1] = {
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_FLAIL, MOVE_REVERSAL, MOVE_SHADOW_CLAW, MOVE_ENDURE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUNATONE_1] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_PSYCHIC, MOVE_POWER_GEM, MOVE_EARTH_POWER, MOVE_ROCK_POLISH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_1] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_1] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_HURRICANE, MOVE_HYPER_VOICE, MOVE_HEAT_WAVE, MOVE_AIR_SLASH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SANDSLASH_1] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VENOMOTH_1] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_ROOST, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANSEY_1] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEAKING_1] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_HORN_DRILL, MOVE_DIVE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JUMPLUFF_1] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_SEED_BOMB, MOVE_SLEEP_POWDER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PILOSWINE_1] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLBAT_1] = {
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_PURSUIT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PRIMEAPE_1] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONLEE_1] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_STONE_EDGE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONCHAN_1] = {
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GIRAFARIG_1] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SUBSTITUTE, MOVE_BATON_PASS},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HITMONTOP_1] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_FAKE_OUT, MOVE_MACH_PUNCH, MOVE_BULLET_PUNCH, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_1] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_SHADOW_FORCE, MOVE_GUNK_SHOT, MOVE_WILL_O_WISP, MOVE_SHADOW_SNEAK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINJASK_1] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_LEECH_LIFE, MOVE_AERIAL_ACE, MOVE_SWORDS_DANCE, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEVIPER_1] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DARK_PULSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_1] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_RETURN, MOVE_CLOSE_COMBAT, MOVE_SHADOW_CLAW, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CAMERUPT_1] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_ERUPTION, MOVE_OVERHEAT, MOVE_EARTH_POWER, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_1] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_AQUA_JET, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TROPIUS_1] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_FLY, MOVE_EARTHQUAKE, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNETON_1] = {
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANTINE_1] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_HURRICANE, MOVE_HYDRO_PUMP, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STANTLER_1] = {
        .species = SPECIES_STANTLER,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SUCKER_PUNCH, MOVE_JUMP_KICK, MOVE_MEGAHORN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ABSOL_1] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_SUPERPOWER, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWALOT_1] = {
        .species = SPECIES_SWALOT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CRAWDAUNT_1] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_GUILLOTINE, MOVE_KNOCK_OFF, MOVE_CRABHAMMER, MOVE_AQUA_JET},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PIDGEOT_1] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_HYPER_BEAM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GRUMPIG_1] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TORKOAL_1] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_1] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_CRABHAMMER, MOVE_METEOR_MASH, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CACTURNE_1] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BELLOSSOM_1] = {
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MOONBLAST, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_1] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_SURF, MOVE_FIRE_BLAST, MOVE_ICE_BEAM, MOVE_ENERGY_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HUNTAIL_1] = {
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_SUCKER_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOREBYSS_1] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_RELICANTH_1] = {
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_HEAD_SMASH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_1] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_MUD_BOMB, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KABUTOPS_1] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_AQUA_JET, MOVE_STONE_EDGE, MOVE_RAIN_DANCE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_POLIWRATH_1] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_FOCUS_BLAST, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_VACUUM_WAVE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_1] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_U_TURN, MOVE_BRICK_BREAK, MOVE_BUG_BITE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PINSIR_1] = {
        .species = SPECIES_PINSIR,
        .moves = {MOVE_GUILLOTINE, MOVE_X_SCISSOR, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_POLITOED_1] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLOYSTER_1] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_HYDRO_PUMP, MOVE_ROCK_BLAST, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DELCATTY_2] = {
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_MOONBLAST, MOVE_HYPER_VOICE, MOVE_THUNDERBOLT, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SABLEYE_2] = {
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_FOUL_PLAY, MOVE_WILL_O_WISP, MOVE_SEISMIC_TOSS, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LICKITUNG_2] = {
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WEEPINBELL_2] = {
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_SOLAR_BLADE, MOVE_POISON_JAB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GRAVELER_2] = {
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GLOOM_2] = {
        .species = SPECIES_GLOOM,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_STRENGTH_SAP, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_2] = {
        .species = SPECIES_PORYGON,
        .moves = {MOVE_ICE_BEAM, MOVE_DISCHARGE, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KADABRA_2] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILMER_2] = {
        .species = SPECIES_WAILMER,
        .moves = {MOVE_WATER_SPOUT, MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_ROSELIA_2] = {
        .species = SPECIES_ROSELIA,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SLUDGE_BOMB, MOVE_LEAF_STORM, MOVE_SYNTHESIS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VOLBEAT_2] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_TAIL_GLOW, MOVE_BATON_PASS, MOVE_SUBSTITUTE, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ILLUMISE_2] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_THUNDER_WAVE, MOVE_ENCORE, MOVE_ROOST, MOVE_BUG_BUZZ},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_IVYSAUR_2] = {
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_CHARMELEON_2] = {
        .species = SPECIES_CHARMELEON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_PUNCH, MOVE_FLAME_CHARGE, MOVE_BELLY_DRUM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WARTORTLE_2] = {
        .species = SPECIES_WARTORTLE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_AURA_SPHERE, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PARASECT_2] = {
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_LEECH_LIFE, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHOKE_2] = {
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HAUNTER_2] = {
        .species = SPECIES_HAUNTER,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_DAZZLING_GLEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BAYLEEF_2] = {
        .species = SPECIES_BAYLEEF,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_AROMATHERAPY, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUILAVA_2] = {
        .species = SPECIES_QUILAVA,
        .moves = {MOVE_ERUPTION, MOVE_FLAMETHROWER, MOVE_EXTRASENSORY, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_CROCONAW_2] = {
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_LIQUIDATION, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TOGETIC_2] = {
        .species = SPECIES_TOGETIC,
        .moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_FLAMETHROWER, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MURKROW_2] = {
        .species = SPECIES_MURKROW,
        .moves = {MOVE_BRAVE_BIRD, MOVE_NIGHT_SLASH, MOVE_SUPERPOWER, MOVE_DRILL_PECK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WOBBUFFET_2] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_SAFEGUARD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PLUSLE_2] = {
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_GRASS_KNOT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MINUN_2] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_NUZZLE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GROVYLE_2] = {
        .species = SPECIES_GROVYLE,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_ENERGY_BALL, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_COMBUSKEN_2] = {
        .species = SPECIES_COMBUSKEN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SKY_UPPERCUT, MOVE_THUNDER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MARSHTOMP_2] = {
        .species = SPECIES_MARSHTOMP,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PONYTA_2] = {
        .species = SPECIES_PONYTA,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HIGH_HORSEPOWER, MOVE_WILD_CHARGE, MOVE_FLAME_CHARGE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AZUMARILL_2] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUDOWOODO_2] = {
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_HEAD_SMASH, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGCARGO_2] = {
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_FIRE_BLAST, MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PUPITAR_2] = {
        .species = SPECIES_PUPITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUPERPOWER, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEALEO_2] = {
        .species = SPECIES_SEALEO,
        .moves = {MOVE_SURF, MOVE_FREEZE_DRY, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RATICATE_2] = {
        .species = SPECIES_RATICATE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MASQUERAIN_2] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_BUG_BUZZ, MOVE_HYDRO_PUMP, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_2] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_RETURN, MOVE_DYNAMIC_PUNCH, MOVE_COIL, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUNSPARCE_2] = {
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_HEADBUTT, MOVE_GLARE, MOVE_COIL, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONAIR_2] = {
        .species = SPECIES_DRAGONAIR,
        .moves = {MOVE_OUTRAGE, MOVE_EXTREME_SPEED, MOVE_AQUA_JET, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIGHTYENA_2] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_PLAY_ROUGH, MOVE_POISON_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LINOONE_2] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SEED_BOMB, MOVE_SHADOW_CLAW, MOVE_BELLY_DRUM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CASTFORM_2] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_WEATHER_BALL, MOVE_HURRICANE, MOVE_THUNDER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHELGON_2] = {
        .species = SPECIES_SHELGON,
        .moves = {MOVE_OUTRAGE, MOVE_DRAGON_CLAW, MOVE_FIRE_FANG, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_METANG_2] = {
        .species = SPECIES_METANG,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WIGGLYTUFF_2] = {
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_HYPER_VOICE, MOVE_DAZZLING_GLEAM, MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUNFLORA_2] = {
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [314] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_COUNTER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLIGAR_2] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_THUNDER_FANG, MOVE_ROOST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QWILFISH_2] = {
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_LIQUIDATION, MOVE_POISON_JAB, MOVE_SWORDS_DANCE, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNEASEL_2] = {
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_ICE_BEAM, MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PELIPPER_2] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_SURF, MOVE_HURRICANE, MOVE_ICE_BEAM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_2] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LAIRON_2] = {
        .species = SPECIES_LAIRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_AUTOTOMIZE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TANGELA_2] = {
        .species = SPECIES_TANGELA,
        .moves = {MOVE_SOLAR_BEAM, MOVE_HIDDEN_POWER, MOVE_MORNING_SUN, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ARBOK_2] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_COIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PERSIAN_2] = {
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_THUNDER_WAVE, MOVE_SWAGGER, MOVE_FOUL_PLAY, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEADRA_2] = {
        .species = SPECIES_SEADRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_KECLEON_2] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VIGOROTH_2] = {
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_BULK_UP, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUNATONE_2] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_PSYCHIC, MOVE_POWER_GEM, MOVE_EARTH_POWER, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_2] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_MORNING_SUN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_2] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_HURRICANE, MOVE_HYPER_VOICE, MOVE_HEAT_WAVE, MOVE_AIR_SLASH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SANDSLASH_2] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VENOMOTH_2] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BUG_BUZZ, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANSEY_2] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_AROMATHERAPY, MOVE_SOFT_BOILED, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEAKING_2] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_DIVE, MOVE_MEGAHORN, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JUMPLUFF_2] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_SLEEP_POWDER, MOVE_SWORDS_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PILOSWINE_2] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_AVALANCHE, MOVE_EARTHQUAKE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLBAT_2] = {
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMEAPE_2] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONLEE_2] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_MACH_PUNCH, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONCHAN_2] = {
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GIRAFARIG_2] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_RETURN, MOVE_PSYCHIC_FANGS, MOVE_EARTHQUAKE, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HITMONTOP_2] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_FAKE_OUT, MOVE_MACH_PUNCH, MOVE_BULLET_PUNCH, MOVE_REVENGE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_2] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_SHADOW_FORCE, MOVE_SHADOW_SNEAK, MOVE_WAKE_UP_SLAP, MOVE_HYPNOSIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINJASK_2] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_U_TURN, MOVE_AERIAL_ACE, MOVE_LEECH_LIFE, MOVE_NIGHT_SLASH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEVIPER_2] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_2] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_RETURN, MOVE_CLOSE_COMBAT, MOVE_SHADOW_CLAW, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CAMERUPT_2] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_ERUPTION, MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_2] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_AQUA_JET, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TROPIUS_2] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_SOLAR_BEAM, MOVE_AIR_SLASH, MOVE_SYNTHESIS, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGNETON_2] = {
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANTINE_2] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SCALD, MOVE_AIR_SLASH, MOVE_TOXIC, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_STANTLER_2] = {
        .species = SPECIES_STANTLER,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SUCKER_PUNCH, MOVE_JUMP_KICK, MOVE_EARTHQUAKE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ABSOL_2] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_NIGHT_SLASH, MOVE_STONE_EDGE, MOVE_PSYCHO_CUT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWALOT_2] = {
        .species = SPECIES_SWALOT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CRAWDAUNT_2] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_AQUA_JET, MOVE_KNOCK_OFF, MOVE_GUILLOTINE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PIDGEOT_2] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_HYPER_BEAM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GRUMPIG_2] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TORKOAL_2] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_FLAMETHROWER, MOVE_SOLAR_BEAM, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_2] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_KNOCK_OFF, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CACTURNE_2] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BELLOSSOM_2] = {
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_2] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_SURF, MOVE_FIRE_BLAST, MOVE_ICE_BEAM, MOVE_ENERGY_BALL},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HUNTAIL_2] = {
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_BATON_PASS, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOREBYSS_2] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_RELICANTH_2] = {
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_HEAD_SMASH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_2] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_MUD_BOMB, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KABUTOPS_2] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_POLIWRATH_2] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_CIRCLE_THROW, MOVE_SCALD, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_2] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_U_TURN, MOVE_BRICK_BREAK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PINSIR_2] = {
        .species = SPECIES_PINSIR,
        .moves = {MOVE_X_SCISSOR, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_POLITOED_2] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLOYSTER_2] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_LIQUIDATION, MOVE_ROCK_BLAST, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUGTRIO_1] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_1] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_REVERSAL, MOVE_ZEN_HEADBUTT, MOVE_ENDURE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISDREAVUS_1] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_DAZZLING_GLEAM, MOVE_ENERGY_BALL},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_1] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_RETURN, MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GRANBULL_1] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_BULK_UP, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_1] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT, MOVE_LOVELY_KISS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSCLOPS_1] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_SHADOW_SNEAK, MOVE_POWER_UP_PUNCH, MOVE_WILL_O_WISP, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DODRIO_1] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_FLAIL, MOVE_DRILL_PECK, MOVE_JUMP_KICK, MOVE_ENDURE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_1] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_HEALING_WISH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_1] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_VOLT_SWITCH, MOVE_ICE_BEAM, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRELOOM_1] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_BULLET_SEED, MOVE_FORCE_PALM, MOVE_ROCK_TOMB, MOVE_SPORE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FORRETRESS_1] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_GYRO_BALL, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_1] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_STONE_EDGE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_XATU_1] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_PSYCHIC, MOVE_HEAT_WAVE, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SKARMORY_1] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [387] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_QUAGSIRE_1] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_EARTHQUAKE, MOVE_DIVE, MOVE_ICE_PUNCH, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLEFABLE_1] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_1] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_REVENGE, MOVE_KNOCK_OFF, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RAICHU_1] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DEWGONG_1] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_PERISH_SONG, MOVE_WHIRLPOOL, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANECTRIC_1] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_1] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_PETAL_BLIZZARD, MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VICTREEBEL_1] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_SOLAR_BLADE, MOVE_POISON_JAB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRODE_1] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_EXPLOSION, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXPLOUD_1] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SURF},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHIFTRY_1] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEAF_STORM, MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_HURRICANE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_1] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUDICOLO_1] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_SCALD, MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HYPNO_1] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_ZEN_HEADBUTT, MOVE_DRAIN_PUNCH, MOVE_HYPNOSIS, MOVE_BELLY_DRUM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_1] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYDON_1] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ALAKAZAM_1] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_WEEZING_1] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_1] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_RETURN, MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_FAKE_OUT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ELECTABUZZ_1] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_1] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLOWBRO_1] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_CALM_MIND, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLOWKING_1] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_DIVE, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILTANK_1] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_BRICK_BREAK, MOVE_CURSE, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALTARIA_1] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_REST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_1] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NIDOKING_1] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_EARTHQUAKE, MOVE_POISON_FANG, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGMAR_1] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_CRADILY_1] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARMALDO_1] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLDUCK_1] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAPIDASH_1] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_HIGH_HORSEPOWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MUK_1] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_GUNK_SHOT, MOVE_SHADOW_SNEAK, MOVE_FIRE_PUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GENGAR_1] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_HEX, MOVE_FOCUS_BLAST, MOVE_WILL_O_WISP},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_1] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_DISCHARGE, MOVE_HIDDEN_POWER, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_1] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_BUG_BITE, MOVE_BRICK_BREAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_1] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_STONE_EDGE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_URSARING_1] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HOUNDOOM_1] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_CRUNCH, MOVE_FIRE_FANG, MOVE_THUNDER_FANG, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_1] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAYDOL_1] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT, MOVE_STONE_EDGE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_1] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_1] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_HYPNOSIS, MOVE_MORNING_SUN, MOVE_HEX, MOVE_FLAMETHROWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_1] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_STONE_EDGE, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUCKLE_1] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_ROLLOUT, MOVE_DEFENSE_CURL, MOVE_STICKY_WEB, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_1] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TENTACRUEL_1] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_WATERFALL, MOVE_POISON_JAB, MOVE_TOXIC_SPIKES, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AERODACTYL_1] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_HEAD_SMASH, MOVE_BRAVE_BIRD, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PORYGON2_1] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_NASTY_PLOT, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARDEVOIR_1] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_MOONBLAST, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_1] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_SOLAR_BEAM, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_STARMIE_1] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLYGON_1] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_RUSH, MOVE_IRON_TAIL, MOVE_HONE_CLAWS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_1] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_EARTH_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_VAPOREON_1] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_WISH, MOVE_TOXIC, MOVE_ACID_ARMOR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JOLTEON_1] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_BATON_PASS, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLAREON_1] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_1] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_AROMATHERAPY, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ESPEON_1] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_BATON_PASS, MOVE_MORNING_SUN, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UMBREON_1] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_FOUL_PLAY, MOVE_WISH, MOVE_DOUBLE_TEAM, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_1] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_AQUA_JET, MOVE_AVALANCHE, MOVE_EARTHQUAKE, MOVE_DRAGON_TAIL},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_1] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AGGRON_1] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_IRON_TAIL, MOVE_EARTHQUAKE, MOVE_HONE_CLAWS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLAZIKEN_1] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER, MOVE_BATON_PASS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WALREIN_1] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_ICE_SHARD, MOVE_DIVE, MOVE_BELLY_DRUM, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCEPTILE_1] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_1] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_EMBER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TYPHLOSION_1] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FLAMETHROWER, MOVE_EARTH_POWER, MOVE_SUNNY_DAY, MOVE_SUBSTITUTE},
        .heldItem = ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LAPRAS_1] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_WATERFALL, MOVE_ICE_SHARD, MOVE_SHEER_COLD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CROBAT_1] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_TAUNT, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWAMPERT_1] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GYARADOS_1] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_1] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SELF_DESTRUCT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGDRA_1] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_DRAGON_PULSE, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLISSEY_1] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_AROMATHERAPY, MOVE_WISH, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MILOTIC_1] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_MIRROR_COAT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_1] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_EXTREME_SPEED, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_1] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_OUTRAGE, MOVE_THUNDER_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [466] = {
        .species = SPECIES_MAWILE,
        .moves = {MOVE_PLAY_ROUGH, MOVE_SUCKER_PUNCH, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKING_1] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_PLAY_ROUGH, MOVE_SHADOW_CLAW},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUGTRIO_2] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_STONE_EDGE, MOVE_GIGA_IMPACT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_2] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAROWAK_2] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_QUAGSIRE_2] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MISDREAVUS_2] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_HEX, MOVE_WILL_O_WISP, MOVE_TAUNT, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_2] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_RETURN, MOVE_DRILL_RUN, MOVE_AGILITY, MOVE_BATON_PASS},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GRANBULL_2] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_2] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSCLOPS_2] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_WILL_O_WISP, MOVE_FOUL_PLAY, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DODRIO_2] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_RETURN, MOVE_JUMP_KICK, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_2] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_2] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_DISCHARGE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRELOOM_2] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_BULLET_SEED, MOVE_LOW_SWEEP, MOVE_MACH_PUNCH, MOVE_ROCK_TOMB},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FORRETRESS_2] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SKARMORY_2] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_TOXIC, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WHISCASH_2] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_SCALD, MOVE_FISSURE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_XATU_2] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_PSYCHIC, MOVE_AIR_SLASH, MOVE_HEAT_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [485] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_HYPER_VOICE, MOVE_MYSTICAL_FIRE, MOVE_CALM_MIND, MOVE_MOONLIGHT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_2] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FAKE_OUT, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_2] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [488] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_BLIZZARD, MOVE_HIDDEN_POWER, MOVE_REST, MOVE_HAIL},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_MANECTRIC_2] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_2] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_STRENGTH_SAP, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VICTREEBEL_2] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRODE_2] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_EXPLOSION, MOVE_TAUNT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXPLOUD_2] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHIFTRY_2] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_SOLAR_BEAM, MOVE_DARK_PULSE, MOVE_SUNNY_DAY, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [495] = {
        .species = SPECIES_SWINUB,
        .moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_HAIL},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUDICOLO_2] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_DIVE, MOVE_SEED_BOMB, MOVE_ICE_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_2] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_BATON_PASS, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_2] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYDON_2] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_ICE_FANG, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ALAKAZAM_2] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_CALM_MIND},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WEEZING_2] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_2] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_TOXIC, MOVE_SUBSTITUTE, MOVE_RETURN, MOVE_POWER_UP_PUNCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ELECTABUZZ_2] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_2] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLOWBRO_2] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLOWKING_2] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_SLACK_OFF},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILTANK_2] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALTARIA_2] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_COTTON_GUARD, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_2] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NIDOKING_2] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_EARTHQUAKE, MOVE_POISON_FANG, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGMAR_2] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_CRADILY_2] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARMALDO_2] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_STONE_EDGE, MOVE_AQUA_JET, MOVE_SWORDS_DANCE, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLDUCK_2] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_AQUA_JET, MOVE_CROSS_CHOP, MOVE_ZEN_HEADBUTT, MOVE_HONE_CLAWS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAPIDASH_2] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 25,
        .ability = 1
    },
    [FRONTIER_MON_MUK_2] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_GUNK_SHOT, MOVE_SHADOW_SNEAK, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GENGAR_2] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_2] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_REST, MOVE_TAIL_GLOW},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_2] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_BATON_PASS, MOVE_AGILITY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_2] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_URSARING_2] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FRUSTRATION, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HOUNDOOM_2] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_2] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAYDOL_2] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_2] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SCALD, MOVE_ROAR, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_2] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MACHAMP_2] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_BULK_UP, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUCKLE_2] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_INFESTATION, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_2] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_CURSE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TENTACRUEL_2] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_WATERFALL, MOVE_POISON_JAB, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AERODACTYL_2] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_HEAD_SMASH, MOVE_BRAVE_BIRD, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PORYGON2_2] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [533] = {
        .species = SPECIES_KIRLIA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_2] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_LEAF_STORM, MOVE_PSYCHIC, MOVE_HIDDEN_POWER, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_STARMIE_2] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLYGON_2] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_U_TURN, MOVE_DRAGON_CLAW},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_2] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VAPOREON_2] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_WISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_JOLTEON_2] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLAREON_2] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [541] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_DOUBLE_EDGE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ESPEON_2] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_DAZZLING_GLEAM, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UMBREON_2] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_WISH, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_2] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_WATER_SPOUT, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_2] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_AQUA_JET, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AGGRON_2] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_AQUA_TAIL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLAZIKEN_2] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_FIRE_PUNCH, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WALREIN_2] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_AVALANCHE, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_2] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_2] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_BELLY_DRUM, MOVE_ACROBATICS, MOVE_OVERHEAT, MOVE_SUBSTITUTE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_2] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FLAMETHROWER, MOVE_SOLAR_BEAM, MOVE_FOCUS_BLAST, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LAPRAS_2] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_ICE_SHARD, MOVE_AQUA_JET, MOVE_CURSE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CROBAT_2] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWAMPERT_2] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_AVALANCHE, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_2] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_AQUA_TAIL, MOVE_DRAGON_RUSH, MOVE_COIL, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNORLAX_2] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_BELLY_DRUM, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGDRA_2] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_SURF, MOVE_SUBSTITUTE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLISSEY_2] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_AROMATHERAPY, MOVE_SOFT_BOILED, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MILOTIC_2] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_DRAGON_TAIL, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARCANINE_2] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_WILL_O_WISP, MOVE_FLARE_BLITZ, MOVE_MORNING_SUN, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_2] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_DRACO_METEOR, MOVE_FLAMETHROWER, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_2] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKING_2] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_HYPER_VOICE, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUGTRIO_3] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_STONE_EDGE, MOVE_SCREECH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_3] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISDREAVUS_3] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_HEX, MOVE_POWER_GEM, MOVE_WILL_O_WISP, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_3] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GRANBULL_3] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_3] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_ICE_BEAM, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_LOVELY_KISS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSCLOPS_3] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_SNEAK, MOVE_POWER_UP_PUNCH, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DODRIO_3] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_RETURN, MOVE_JUMP_KICK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_3] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_3] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRELOOM_3] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_BULLET_SEED, MOVE_MACH_PUNCH, MOVE_SWORDS_DANCE, MOVE_SPORE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FORRETRESS_3] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_3] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 26,
        .ability = 1
    },
    [FRONTIER_MON_XATU_3] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_STORED_POWER, MOVE_HEAT_WAVE, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SKARMORY_3] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_BRAVE_BIRD, MOVE_TOXIC, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [579] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_QUAGSIRE_3] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SCALD, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLEFABLE_3] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_3] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM, MOVE_STONE_EDGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_3] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DEWGONG_3] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_HORN_DRILL, MOVE_SHEER_COLD, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANECTRIC_3] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_3] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_VICTREEBEL_3] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_SOLAR_BLADE, MOVE_POISON_JAB, MOVE_KNOCK_OFF, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRODE_3] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH, MOVE_SIGNAL_BEAM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXPLOUD_3] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHIFTRY_3] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_LOW_KICK},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_3] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUDICOLO_3] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ENERGY_BALL, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_3] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_BATON_PASS, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_3] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_EXPLOSION, MOVE_AUTOTOMIZE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYDON_3] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_ICE_FANG, MOVE_METAL_BURST},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ALAKAZAM_3] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_CALM_MIND, MOVE_ENCORE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEEZING_3] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_3] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ELECTABUZZ_3] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_3] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLOWBRO_3] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLOWKING_3] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILTANK_3] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_HEAL_BELL, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALTARIA_3] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_ROOST, MOVE_TAILWIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [605] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_GUILLOTINE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [606] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROOST, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGMAR_3] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_CRADILY_3] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARMALDO_3] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_AQUA_JET, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLDUCK_3] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAPIDASH_3] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HIGH_HORSEPOWER, MOVE_WILD_CHARGE, MOVE_MEGAHORN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MUK_3] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_GUNK_SHOT, MOVE_SHADOW_SNEAK, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GENGAR_3] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_3] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AGILITY, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_3] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_BUG_BITE, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_3] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_URSARING_3] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FRUSTRATION, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HOUNDOOM_3] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_3] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAYDOL_3] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_3] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_FISSURE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_3] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_HEX, MOVE_ENERGY_BALL, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MACHAMP_3] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUCKLE_3] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_3] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEAVY_SLAM, MOVE_THUNDER_FANG, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TENTACRUEL_3] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SCALD, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AERODACTYL_3] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON2_3] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_GARDEVOIR_3] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_3] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_LEAF_STORM, MOVE_SLEEP_POWDER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_STARMIE_3] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLYGON_3] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_SUBSTITUTE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_3] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_POWER_WHIP, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VAPOREON_3] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_WISH, MOVE_ACID_ARMOR, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JOLTEON_3] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_SUBSTITUTE, MOVE_BATON_PASS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLAREON_3] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUPERPOWER, MOVE_FLAME_CHARGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_3] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_DRAGON_TAIL, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ESPEON_3] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_UMBREON_3] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_FOUL_PLAY, MOVE_WISH, MOVE_HEAL_BELL, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_3] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_3] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_AQUA_JET, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AGGRON_3] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLAZIKEN_3] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HI_JUMP_KICK, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WALREIN_3] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_BLIZZARD, MOVE_SURF, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_3] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_3] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_AIR_SLASH, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_3] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_LAPRAS_3] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CROBAT_3] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEAT_WAVE, MOVE_GIGA_DRAIN, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWAMPERT_3] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_DIVE, MOVE_ICE_PUNCH, MOVE_HAMMER_ARM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GYARADOS_3] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_3] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGDRA_3] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_SURF, MOVE_AGILITY, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLISSEY_3] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_EE_PROTECT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILOTIC_3] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_AQUA_TAIL, MOVE_COIL, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARCANINE_3] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_WILL_O_WISP, MOVE_FLARE_BLITZ, MOVE_MORNING_SUN, MOVE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_3] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_OUTRAGE, MOVE_THUNDER_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_METAGROSS_3] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_AGILITY},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKING_3] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_PLAY_ROUGH, MOVE_SHADOW_CLAW},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUGTRIO_4] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_STONE_EDGE, MOVE_HONE_CLAWS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_4] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISDREAVUS_4] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_DAZZLING_GLEAM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_4] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_RETURN, MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GRANBULL_4] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_4] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_ICE_BEAM, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSCLOPS_4] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_SNEAK, MOVE_ICE_PUNCH, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DODRIO_4] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_RETURN, MOVE_JUMP_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_4] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYSHOCK, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_4] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRELOOM_4] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_BULLET_SEED, MOVE_MACH_PUNCH, MOVE_ROCK_TOMB, MOVE_SPORE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FORRETRESS_4] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_GYRO_BALL, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_4] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_BOUNCE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_XATU_4] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_ROOST, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SKARMORY_4] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_BRAVE_BIRD, MOVE_TOXIC, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAROWAK_4] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_BONEMERANG, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_QUAGSIRE_4] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [677] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_MYSTICAL_FIRE, MOVE_HYPER_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_4] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_REVENGE, MOVE_KNOCK_OFF, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_4] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [680] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_BLIZZARD, MOVE_HIDDEN_POWER, MOVE_FREEZE_DRY, MOVE_HAIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_MANECTRIC_4] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_4] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_STRENGTH_SAP, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VICTREEBEL_4] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRODE_4] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH, MOVE_SIGNAL_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXPLOUD_4] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHIFTRY_4] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_SOLAR_BLADE, MOVE_KNOCK_OFF, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [687] = {
        .species = SPECIES_SWINUB,
        .moves = {MOVE_BLIZZARD, MOVE_HEX, MOVE_WILL_O_WISP, MOVE_HAIL},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUDICOLO_4] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_SURF, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_4] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_BATON_PASS, MOVE_SUBSTITUTE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_4] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYDON_4] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ROCK_WRECKER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ALAKAZAM_4] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEEZING_4] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_WILL_O_WISP, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_4] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ELECTABUZZ_4] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_4] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLOWBRO_4] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_THUNDER_WAVE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLOWKING_4] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_FUTURE_SIGHT, MOVE_NASTY_PLOT, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILTANK_4] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALTARIA_4] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_4] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NIDOKING_4] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_EARTHQUAKE, MOVE_POISON_FANG, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGMAR_4] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER, MOVE_OVERHEAT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_CRADILY_4] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MUD_BOMB, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARMALDO_4] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_X_SCISSOR, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLDUCK_4] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_AQUA_JET, MOVE_CROSS_CHOP, MOVE_ZEN_HEADBUTT, MOVE_HONE_CLAWS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAPIDASH_4] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HIGH_HORSEPOWER, MOVE_WILD_CHARGE, MOVE_MEGAHORN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MUK_4] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_POISON_JAB, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GENGAR_4] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_4] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_FOCUS_BLAST, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_4] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_U_TURN, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_4] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_REVERSAL, MOVE_KNOCK_OFF, MOVE_ENDURE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_URSARING_4] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_BODY_SLAM, MOVE_BULK_UP, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HOUNDOOM_4] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_COUNTER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_4] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAYDOL_4] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_4] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_4] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_MORNING_SUN, MOVE_HEX, MOVE_HYPNOSIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_4] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUCKLE_4] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_4] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEAVY_SLAM, MOVE_HEAD_SMASH, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TENTACRUEL_4] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AERODACTYL_4] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_HEAD_SMASH, MOVE_BRAVE_BIRD, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PORYGON2_4] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_ICE_BEAM, MOVE_DISCHARGE, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [725] = {
        .species = SPECIES_KIRLIA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_4] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_STARMIE_4] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLYGON_4] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_U_TURN, MOVE_DRAGON_CLAW},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_4] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_VAPOREON_4] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_WISH, MOVE_TOXIC, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JOLTEON_4] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_SIGNAL_BEAM, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLAREON_4] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [733] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DOUBLE_EDGE, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ESPEON_4] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_MORNING_SUN, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UMBREON_4] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_FOUL_PLAY, MOVE_WISH, MOVE_HEAL_BELL, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_4] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_4] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_LIQUIDATION, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AGGRON_4] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_AQUA_TAIL},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLAZIKEN_4] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HI_JUMP_KICK, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WALREIN_4] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_ICE_BEAM, MOVE_SHEER_COLD, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_4] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_4] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_FOCUS_BLAST, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TYPHLOSION_4] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_LAPRAS_4] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_FREEZE_DRY, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CROBAT_4] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_PURSUIT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWAMPERT_4] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GYARADOS_4] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_4] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGDRA_4] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_DRACO_METEOR, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLISSEY_4] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILOTIC_4] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_DRAGON_TAIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_4] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_EXTREME_SPEED, MOVE_MORNING_SUN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_4] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_METAGROSS_4] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKING_4] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_PLAY_ROUGH, MOVE_SHADOW_CLAW},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_1] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_HURRICANE, MOVE_ROAR, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_1] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_ZAP_CANNON, MOVE_HIDDEN_POWER, MOVE_EE_PROTECT, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_1] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FIRE_BLAST, MOVE_HURRICANE, MOVE_HIDDEN_POWER, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_1] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_1] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_1] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_1] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REGICE_1] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_1] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_1] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_PSYSHOCK, MOVE_SURF, MOVE_HEALING_WISH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_1] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_PSYCHIC, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_2] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_HURRICANE, MOVE_HIDDEN_POWER, MOVE_AGILITY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_2] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_ZAP_CANNON, MOVE_HEAT_WAVE, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_2] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_HURRICANE, MOVE_U_TURN, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_2] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_AURA_SPHERE, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_2] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLAME_CHARGE, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_2] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_2] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STEALTH_ROCK, MOVE_STONE_EDGE, MOVE_HAMMER_ARM, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REGICE_2] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_CHARGE_BEAM, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_2] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_IRON_HEAD, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_2] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_CHARM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_2] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SURF, MOVE_ROOST, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_3] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_HURRICANE, MOVE_U_TURN, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_3] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_ZAP_CANNON, MOVE_HIDDEN_POWER, MOVE_HEAT_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_3] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FIRE_BLAST, MOVE_HURRICANE, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_CHARCOAL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_3] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_3] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_3] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_SLEEP_TALK, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_3] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_3] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_3] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK, MOVE_COUNTER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_3] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_3] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRACO_METEOR, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_4] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_HURRICANE, MOVE_ROAR, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_4] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_ZAP_CANNON, MOVE_HIDDEN_POWER, MOVE_EE_PROTECT, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_4] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FIRE_BLAST, MOVE_HURRICANE, MOVE_HIDDEN_POWER, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_4] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_4] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_4] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_4] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REGICE_4] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_4] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_4] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_PSYSHOCK, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_4] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GENGAR_5] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_HEX, MOVE_FOCUS_BLAST, MOVE_HYPNOSIS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GENGAR_6] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GENGAR_7] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GENGAR_8] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_5] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_6] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FRUSTRATION, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_7] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FRUSTRATION, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_8] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_BODY_SLAM, MOVE_BULK_UP, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_5] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_STONE_EDGE, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_6] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_BULK_UP, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_7] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_8] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [812] = {
        .species = SPECIES_KIRLIA,
        .moves = {MOVE_PSYCHO_CUT, MOVE_NIGHT_SLASH, MOVE_LEAF_BLADE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARDEVOIR_6] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_MOONBLAST, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [814] = {
        .species = SPECIES_KIRLIA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARDEVOIR_8] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_STARMIE_5] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_STARMIE_6] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_STARMIE_7] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_STARMIE_8] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LAPRAS_5] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_WATERFALL, MOVE_ICE_SHARD, MOVE_SHEER_COLD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LAPRAS_6] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_ICE_SHARD, MOVE_AQUA_JET, MOVE_CURSE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LAPRAS_7] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LAPRAS_8] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_FREEZE_DRY, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_5] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SELF_DESTRUCT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNORLAX_6] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_BELLY_DRUM, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNORLAX_7] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNORLAX_8] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SALAMENCE_5] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_OUTRAGE, MOVE_THUNDER_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SALAMENCE_6] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_DRACO_METEOR, MOVE_FLAMETHROWER, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_7] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_OUTRAGE, MOVE_THUNDER_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SALAMENCE_8] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_METAGROSS_5] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_6] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_7] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_AGILITY},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_8] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_5] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STEALTH_ROCK, MOVE_STONE_EDGE, MOVE_HAMMER_ARM, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REGIROCK_6] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_5] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_CHARGE_BEAM, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_6] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_5] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_IRON_HEAD, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_6] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK, MOVE_COUNTER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_5] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_PSYSHOCK, MOVE_SURF, MOVE_HEALING_WISH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_6] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_CHARM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_7] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_8] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_PSYSHOCK, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_5] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_PSYCHIC, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_6] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SURF, MOVE_ROOST, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_7] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRACO_METEOR, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_8] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_TRICK},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_1] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_TAIL, MOVE_ROOST, MOVE_SUBSTITUTE, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_2] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HURRICANE, MOVE_THUNDER, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_3] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_FLY, MOVE_DRAGON_DANCE, MOVE_SUBSTITUTE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_4] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HORN_DRILL, MOVE_BARRIER, MOVE_EE_PROTECT, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_5] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_AQUA_JET, MOVE_ROOST, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_6] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_7] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_DRAGON_ASCENT, MOVE_EARTHQUAKE, MOVE_AQUA_JET},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_8] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_FLY, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_9] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HURRICANE, MOVE_THUNDER, MOVE_SURF, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_10] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_DRAGON_ASCENT, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TYRANITAR_1] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_BRICK_BREAK, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_2] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_ROCK_SLIDE, MOVE_REVENGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_3] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_4] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_DARK_PULSE, MOVE_MUD_BOMB, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_5] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_6] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_7] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_REST, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_8] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_DRAGON_DANCE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_9] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STEALTH_ROCK, MOVE_STONE_EDGE, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_10] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_5] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_HURRICANE, MOVE_HIDDEN_POWER, MOVE_AGILITY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_6] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_HURRICANE, MOVE_U_TURN, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_5] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_ZAP_CANNON, MOVE_HEAT_WAVE, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_6] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_ZAP_CANNON, MOVE_HIDDEN_POWER, MOVE_HEAT_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_5] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_HURRICANE, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_6] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FIRE_BLAST, MOVE_HURRICANE, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_CHARCOAL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_5] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_AURA_SPHERE, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_6] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_5] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLAME_CHARGE, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_6] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_5] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_6] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_SLEEP_TALK, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    }
};
