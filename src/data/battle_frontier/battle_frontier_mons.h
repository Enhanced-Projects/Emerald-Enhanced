const struct FacilityMon gBattleFrontierMons[NUM_FRONTIER_MONS] =
{
    [FRONTIER_MON_LEAFEON_3] = {
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_SECRET_POWER, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_YACHE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_AZUMARILL_4] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_LIQUIDATION, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ILLUMISE_3] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_HIDDEN_POWER, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_VOLBEAT_3] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_WILD_CHARGE, MOVE_U_TURN, MOVE_ICE_PUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAPION_3] = {
        .species = SPECIES_DRAPION,
        .moves = {MOVE_KNOCK_OFF, MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHUCA_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GALLADE_3] = {
        .species = SPECIES_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_3] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILOTIC_3] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_METAPOD] = {//Unused
        .species = SPECIES_METAPOD,
        .moves = {MOVE_BUG_BITE, MOVE_TACKLE, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KAKUNA] = {//Unused
        .species = SPECIES_KAKUNA,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_3] = {
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_REVERSAL, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SILCOON] = {//Unused
        .species = SPECIES_SILCOON,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CASCOON] = {//Unused
        .species = SPECIES_CASCOON,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_3] = {
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_STUN_SPORE, MOVE_ENCORE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUAGSIRE_3] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_SCALD, MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 2
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
    [FRONTIER_MON_HAXORUS_3] = {
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LOPUNNY_3] = {
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_STORM_THROW, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOGOAT_3] = {
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_JUMP_KICK, MOVE_GRASSY_TERRAIN, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUDICOLO_3] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIGHTYENA_3] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_PLAY_ROUGH, MOVE_POISON_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHEDINJA] = {
        .species = SPECIES_SHEDINJA,
        .moves = {MOVE_SHADOW_SNEAK, MOVE_REFLECT_TYPE, MOVE_WILL_O_WISP, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_LONELY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCRAFTY_3] = {
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON2_3] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_FOUL_PLAY, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LINOONE_3] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SEED_BOMB, MOVE_STOMPING_TANTRUM, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CROBAT_3] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_SECRET_POWER, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_SMEARGLE_1] = {
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_SPORE, MOVE_GEOMANCY, MOVE_BOOMBURST, MOVE_BATON_PASS},
        .heldItem = ITEM_POWER_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HERACROSS_3] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AZUMARILL_3] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_LIQUIDATION, MOVE_KNOCK_OFF},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_4] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGMORTAR_3] = {
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_FLAME_CHARGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAMOSWINE_3] = {
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_ICICLE_CRASH, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SMEARGLE_2] = {
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_SPORE, MOVE_SHELL_SMASH, MOVE_BOOMBURST, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLISCOR_3] = {
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_ROOST},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RATICATE_3] = {
        .species = SPECIES_RATICATE,
        .moves = {MOVE_FACADE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WOBBUFFET_3] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DELCATTY_3] = {
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_HYPER_VOICE, MOVE_CALM_MIND, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NOIVERN_3] = {
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_3] = {
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_EARTH_POWER, MOVE_ROOST},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_YANMEGA_2] = {
        .species = SPECIES_YANMEGA,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_HIDDEN_POWER, MOVE_EE_PROTECT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_3] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_SWORDS_DANCE, MOVE_ROOST, MOVE_BATON_PASS},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCIZOR_3] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_QUICK_ATTACK, MOVE_ROOST, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLISOPOD_3] = {
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SKARMORY_3] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_DRILL_PECK, MOVE_STEALTH_ROCK, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_3] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FACADE, MOVE_BRAVE_BIRD, MOVE_U_TURN, MOVE_SECRET_POWER},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 29,
        .ability = 0   
    },
    [FRONTIER_MON_PIDGEOT_3] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SECRET_POWER, MOVE_EXTREME_SPEED, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_3] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOQUEEN_3] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES, MOVE_ROAR},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SYLVEON_3] = {
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_CALM_MIND, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUXRAY_3] = {
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_3] = {
        .species = SPECIES_AUDINO,
        .moves = {MOVE_HYPER_VOICE, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLAKING_5] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_RETURN, MOVE_SUPERPOWER, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALVANTULA_3] = {
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_VOLT_SWITCH, MOVE_STICKY_WEB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARBOK_3] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DITTO] = {
        .species = SPECIES_DITTO,
        .moves = {MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WHISCASH_3] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_DIVE, MOVE_RAIN_DANCE, MOVE_REST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PERSIAN_3] = {
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_RETURN, MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FORRETRESS_3] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_GYRO_BALL, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHUCKLE_3] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_INFESTATION},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VANILLUXE_3] = {
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MILD,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_MANTINE_3] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DURANT_3] = {
        .species = SPECIES_DURANT,
        .moves = {MOVE_BUG_BITE, MOVE_THUNDER_FANG, MOVE_ICE_FANG, MOVE_U_TURN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIMIKYU_3] = {
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SPELL_TAG,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUSKNOIR_3] = {
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_WILL_O_WISP},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VIKAVOLT_3] = {
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_ROOST},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINETALES_3] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ROTOM_FROST_3] = {
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_SANDSLASH_3] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLIWRATH_3] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_CIRCLE_THROW, MOVE_SCALD, MOVE_TOXIC, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MASQUERAIN_3] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_SCALD, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RHYPERIOR_3] = {
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WAILORD_4] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BOOMBURST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_Z_3] = {
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_ICE_BEAM, MOVE_HYPER_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_3] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_SLUDGE_BOMB, MOVE_ENERGY_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARCHOMP_5] = {
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_DRAGON_TAIL, MOVE_TOXIC},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLAYDOL_3] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AURORUS_3] = {
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_AURORA_VEIL},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_5] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_AEROBLAST, MOVE_BLAST_OFF, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_3] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EE_PROTECT},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SEVIPER_3] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENOMOTH_3] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PRIMEAPE_3] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMBOAR_3] = {
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_3] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_JYNX_3] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_FROST_BREATH, MOVE_FOCUS_BLAST, MOVE_LOVELY_KISS, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CAMERUPT_3] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_LAVA_PLUME, MOVE_EARTH_POWER, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_3] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CRAWDAUNT_3] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CHARIZARD_3] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_AIR_SLASH, MOVE_FOCUS_BLAST, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DELPHOX_3] = {
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_GRASS_KNOT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ALAKAZAM_3] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_COUNTER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DODRIO_3] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_THRASH, MOVE_JUMP_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_3] = {
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HAWLUCHA_3] = {
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_SKY_ATTACK, MOVE_ACROBATICS, MOVE_HI_JUMP_KICK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_POWER_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_3] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TALONFLAME_3] = {
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_BRAVE_BIRD, MOVE_WILL_O_WISP, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_3] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SCALD, MOVE_BOOMBURST, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLASTOISE_3] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_3] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_LIQUIDATION, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_3] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_THUNDER_WAVE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TORTERRA_3] = {
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_SWORDS_DANCE, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_3] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_HIDDEN_POWER, MOVE_GIGA_DRAIN, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_VILEPLUME_3] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_TENTACRUEL_3] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAROWAK_3] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_FIRE_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEAKING_3] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_DIVE, MOVE_MEGAHORN, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_3] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLEFABLE_3] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_THUNDER_WAVE, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGNEZONE_3] = {
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DEWGONG_3] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_SURF, MOVE_FROST_BREATH, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TOXICROAK_3] = {
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_3] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_ROCK_SLIDE, MOVE_BULLET_SEED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXEGGUTOR_3] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_LEAF_STORM, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_TOUCANNON_3] = {
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BRAVE_BIRD, MOVE_BULLET_SEED, MOVE_FLAME_CHARGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CINCCINO_3] = {
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_BULLET_SEED, MOVE_ROCK_BLAST, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FAN_3] = {
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_RAIN_DANCE, MOVE_HURRICANE, MOVE_THUNDER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_3] = {
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_GIGA_DRAIN, MOVE_SUPERPOWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_RASH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PELIPPER_3] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ICE_BEAM, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DELIBIRD] = {
        .species = SPECIES_DELIBIRD,
        .moves = {MOVE_PRESENT, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_3] = {
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HIPPOWDON_3] = {
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROCK_SLIDE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GRUMPIG_3] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_RECYCLE, MOVE_CALM_MIND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYRANTRUM_3] = {
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
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
    [FRONTIER_MON_TOXAPEX_3] = {
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_SPIKY_SHIELD},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CACTURNE_3] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UNOWN] = {
        .species = SPECIES_UNOWN,
        .moves = {MOVE_SECRET_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 17,
        .ability = 0
    },
    [FRONTIER_MON_DRAGALGE_3] = {
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PRIMARINA_4] = {
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_MOONBLAST, MOVE_SPARKLING_ARIA, MOVE_ICE_BEAM, MOVE_AQUA_JET},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LILLIGANT_3] = {
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_DAZZLING_GLEAM, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_MOW_3] = {
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLAWITZER_3] = {
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FLYGON_3] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_DRAGON_RUSH, MOVE_IRON_TAIL, MOVE_FIRE_BLAST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MUDSDALE_3] = {
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PRIMARINA_3] = {
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_SCALD, MOVE_MOONBLAST, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARAPTOR_3] = {
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_3] = {
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SLUDGE_WAVE, MOVE_HIDDEN_POWER, MOVE_DRAGON_PULSE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_FARFETCHD] = {
        .species = SPECIES_FARFETCHD,
        .moves = {MOVE_SLASH, MOVE_LEAF_BLADE, MOVE_NIGHT_SLASH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_STICK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_OMASTAR_3] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_3] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CRADILY_3] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_LEECH_SEED, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_3] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_3] = {
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_LOW_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_3] = {
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_BULLET_PUNCH, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXPLOUD_3] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPINDA] = {
        .species = SPECIES_SPINDA,
        .moves = {MOVE_SUPERPOWER, MOVE_RETURN, MOVE_SUCKER_PUNCH, MOVE_BATON_PASS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_3] = {
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_LOW_KICK, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZOROARK_4] = {
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_RETURN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_3] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_SIGNAL_BEAM, MOVE_TAIL_GLOW},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLAREON_3] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_BULK_UP, MOVE_MORNING_SUN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PROBOPASS] = {
        .species = SPECIES_PROBOPASS,
        .moves = {MOVE_POWER_GEM, MOVE_STEALTH_ROCK, MOVE_THUNDER_WAVE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
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
        .moves = {MOVE_PLAY_ROUGH, MOVE_ICE_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEEDRILL_1] = {
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEEDRILL_2] = {
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EMPOLEON_3] = {
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GRASS_KNOT, MOVE_RAIN_DANCE},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_3] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEAVY_SLAM, MOVE_HEAD_SMASH, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
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
        .moves = {MOVE_GUNK_SHOT, MOVE_LEECH_LIFE, MOVE_SECRET_POWER, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_LEDIAN] = {
        .species = SPECIES_LEDIAN,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
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
    [FRONTIER_MON_YANMEGA_1] = {
        .species = SPECIES_YANMEGA,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_GIGA_DRAIN, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    //Pokemon with originally 2 sets are below
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
        .moves = {MOVE_DARK_PULSE, MOVE_WILL_O_WISP, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LICKILICKY_1] = {
        .species = SPECIES_LICKILICKY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FERROTHORN_3] = {
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_SPIKES, MOVE_INGRAIN, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLEM_3] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHERRIM_1] = {
        .species = SPECIES_CHERRIM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_DAZZLING_GLEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_1] = {
        .species = SPECIES_AUDINO,
        .moves = {MOVE_HYPER_VOICE, MOVE_TOXIC, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_3] = {
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYSHOCK, MOVE_ACID_ARMOR, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ROTOM_WASH_3] = {
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_THUNDERBOLT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_1] = {
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_ENERGY_BALL, MOVE_PSYCHIC, MOVE_HURRICANE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VOLBEAT_1] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_THUNDERBOLT, MOVE_TAIL_GLOW, MOVE_BATON_PASS, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ILLUMISE_1] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_BATON_PASS, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MARACTUS_1] = {
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_GIGA_DRAIN, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM, MOVE_SANDSTORM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_3] = {
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SAMUROTT_3] = {
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_LIQUIDATION, MOVE_SACRED_SWORD, MOVE_KNOCK_OFF, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
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
    [FRONTIER_MON_HITMONLEE_3] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_STONE_EDGE},
        .heldItem = ITEM_NORMAL_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AEGISLASH_3] = {
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOGOAT_1] = {
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_BULK_UP, MOVE_ROCK_SLIDE, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_3] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_BLAST_OFF, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_5] = {
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ROCK_SLIDE, MOVE_U_TURN, MOVE_ICE_BEAM, MOVE_LOW_KICK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAICHU_3] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EXTREME_SPEED, MOVE_SECRET_POWER, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_3] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_HYPNOSIS, MOVE_HURRICANE, MOVE_WHIRLWIND, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WOBBUFFET_1] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
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
        .ability = 2
    },
    [FRONTIER_MON_MINUN_1] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_ENCORE, MOVE_TOXIC, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LURANTIS_1] = {
        .species = SPECIES_LURANTIS,
        .moves = {MOVE_LEAF_STORM, MOVE_SUPERPOWER, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_INFERNAPE_3] = {
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_INFERNO, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SWAMPERT_3] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_SCALD, MOVE_RAIN_DANCE, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_3] = {
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
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
        .moves = {MOVE_FIRE_BLAST, MOVE_GRAVEL_STORM, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PANGORO_3] = {
        .species = SPECIES_PANGORO,
        .moves = {MOVE_HAMMER_ARM, MOVE_SUCKER_PUNCH, MOVE_DRAIN_PUNCH, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WALREIN_3] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_BLIZZARD, MOVE_SURF, MOVE_FREEZE_DRY, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RATICATE_1] = {
        .species = SPECIES_RATICATE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MASQUERAIN_1] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_BUG_BUZZ, MOVE_STICKY_WEB, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_1] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_HYPER_VOICE, MOVE_FOCUS_BLAST, MOVE_BLIZZARD, MOVE_THUNDER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
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
    [FRONTIER_MON_GOODRA_5] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_OUTRAGE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIGHTYENA_1] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LINOONE_1] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SHADOW_CLAW, MOVE_STOMPING_TANTRUM, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CASTFORM_1] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_FIRE_BLAST, MOVE_HYDRO_PUMP, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KOMMO_O_5] = {
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_OUTRAGE, MOVE_CLOSE_COMBAT, MOVE_POISON_JAB, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_5] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
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
        .moves = {MOVE_SOLAR_BEAM, MOVE_FLAMETHROWER, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BUTTERFREE_1] = {
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CONKELDURR_5] = {
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QWILFISH_1] = {
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_LIQUIDATION, MOVE_POISON_JAB, MOVE_TOXIC_SPIKES, MOVE_TAUNT},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JELLICENT_3] = {
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SHADOW_BALL, MOVE_WATER_SPOUT, MOVE_ICE_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PELIPPER_1] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_ROOST, MOVE_U_TURN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
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
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_3] = {
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_POWER_TRIP, MOVE_REST, MOVE_BULK_UP, MOVE_ROCK_POLISH},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LILLIGANT_1] = {
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_DAZZLING_GLEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARBOK_1] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_GLARE, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
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
        .ability = 0
    },
    [FRONTIER_MON_KINGDRA_3] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_AGILITY, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KECLEON_1] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_RECOVER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCRAFTY_1] = {
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUNATONE_1] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_POWER_GEM, MOVE_PSYSHOCK, MOVE_EARTH_POWER, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_1] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_ROCK_POLISH, MOVE_WILL_O_WISP, MOVE_MORNING_SUN, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_1] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_AGILITY, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SANDSLASH_1] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VENOMOTH_1] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_BATON_PASS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BLISSEY_1] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEAKING_1] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_HORN_DRILL, MOVE_DIVE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JUMPLUFF_1] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_SEED_BOMB, MOVE_SLEEP_POWDER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BASTIODON_1] = {
        .species = SPECIES_BASTIODON,
        .moves = {MOVE_STEALTH_ROCK, MOVE_ROAR, MOVE_MAGIC_COAT, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LIEPARD_1] = {
        .species = SPECIES_LIEPARD,
        .moves = {MOVE_DARK_PULSE, MOVE_ENCORE, MOVE_NASTY_PLOT, MOVE_COPYCAT},
        .heldItem = ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PRIMEAPE_1] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONLEE_1] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_STONE_EDGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONCHAN_1] = {
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_AGILITY, MOVE_BULK_UP},
        .heldItem = ITEM_LUCKY_PUNCH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GIRAFARIG_1] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SUBSTITUTE, MOVE_BATON_PASS},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONTOP_1] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_TRIPLE_KICK, MOVE_MACH_PUNCH, MOVE_BULLET_PUNCH, MOVE_STONE_EDGE},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_1] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_REAPING_BLOW, MOVE_GUNK_SHOT, MOVE_WILL_O_WISP, MOVE_SHADOW_SNEAK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINJASK_1] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SONIC_BOOM, MOVE_DRILL_RUN, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEVIPER_1] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DARK_PULSE, MOVE_NASTY_PLOT, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_1] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CAMERUPT_1] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_FLAMETHROWER, MOVE_OVERHEAT, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_1] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_EE_PROTECT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_1] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNEZONE_1] = {
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_HIDDEN_POWER, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANTINE_1] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_DAMP_ROCK,
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
        .ability = 2
    },
    [FRONTIER_MON_SWALOT_1] = {
        .species = SPECIES_SWALOT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_ACUPRESSURE, MOVE_SLACK_OFF},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRAWDAUNT_1] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PIDGEOT_1] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SECRET_POWER, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_GRUMPIG_1] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TORKOAL_1] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_1] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_ROCK_SLIDE, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CACTURNE_1] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BELLOSSOM_1] = {
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_1] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_BULLET_SEED, MOVE_ROCK_BLAST, MOVE_PIN_MISSILE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HUNTAIL_1] = {
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_SUCKER_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOREBYSS_1] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_SHELL_SMASH},
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
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_1] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GRAVEL_STORM, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_1] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
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
        .moves = {MOVE_X_SCISSOR, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLITOED_1] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_1] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
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
        .ability = 2
    },
    [FRONTIER_MON_SABLEYE_2] = {
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_FOUL_PLAY, MOVE_WILL_O_WISP, MOVE_SEISMIC_TOSS, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LICKILICKY_2] = {
        .species = SPECIES_LICKILICKY,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FERROTHORN_4] = {
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_4] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_HEAVY_SLAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHERRIM_2] = {
        .species = SPECIES_CHERRIM,
        .moves = {MOVE_PETAL_BLIZZARD, MOVE_RETURN, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_2] = {
        .species = SPECIES_AUDINO,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_4] = {
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SIGNAL_BEAM, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ROTOM_WASH_4] = {
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_2] = {
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_ENERGY_BALL, MOVE_PSYCHIC, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_VOLBEAT_2] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_WILD_CHARGE, MOVE_LUNGE, MOVE_ICE_PUNCH, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ILLUMISE_2] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MARACTUS_2] = {
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_ENERGY_BALL, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM, MOVE_SANDSTORM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_4] = {
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_4] = {
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
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
    [FRONTIER_MON_HITMONLEE_4] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_CURSE, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_STONE_EDGE},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AEGISLASH_4] = {
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_IRON_HEAD, MOVE_SHADOW_SNEAK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOGOAT_2] = {
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_ROCK_SLIDE, MOVE_GRASSY_TERRAIN, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYPHLOSION_4] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_6] = {
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_TAUNT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAICHU_4] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_HYPER_VOICE, MOVE_SURF, MOVE_GRASS_KNOT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_4] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WOBBUFFET_2] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_SITRUS_BERRY,
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
        .ability = 2
    },
    [FRONTIER_MON_MINUN_2] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_NUZZLE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LURANTIS_2] = {
        .species = SPECIES_LURANTIS,
        .moves = {MOVE_SUPERPOWER, MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_INFERNAPE_4] = {
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_GRASS_KNOT, MOVE_INFERNO},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_3] = {
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SANDSTORM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_4] = {
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AZUMARILL_2] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_LIQUIDATION, MOVE_KNOCK_OFF},
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
        .moves = {MOVE_FIRE_BLAST, MOVE_GRAVEL_STORM, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PUPITAR] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_PURSUIT, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_3] = {
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_HYDRO_PUMP, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
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
        .ability = 2
    },
    [FRONTIER_MON_MASQUERAIN_2] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_SCALD, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_2] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_RETURN, MOVE_DYNAMIC_PUNCH, MOVE_KNOCK_OFF, MOVE_IRON_TAIL},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
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
    [FRONTIER_MON_GOODRA_6] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRAGON_PULSE, MOVE_MUDDY_WATER, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIGHTYENA_2] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_PLAY_ROUGH, MOVE_POISON_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LINOONE_2] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SEED_BOMB, MOVE_SHADOW_CLAW, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CASTFORM_2] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_THUNDER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KOMMO_O_6] = {
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_OUTRAGE, MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_6] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
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
    [FRONTIER_MON_BUTTERFREE_2] = {
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_ROOST},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CONKELDURR_6] = {
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_FACADE},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
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
    [FRONTIER_MON_JELLICENT_4] = {
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SHADOW_BALL, MOVE_RECOVER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PELIPPER_2] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ICE_BEAM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_2] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_4] = {
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_STONE_EDGE, MOVE_PSYCHIC_FANGS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LILLIGANT_2] = {
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_SYNTHESIS, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_ARBOK_2] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
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
    [FRONTIER_MON_ARAQUANID_3] = {
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_STICKY_WEB, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KECLEON_2] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCRAFTY_2] = {
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_BULK_UP, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUNATONE_2] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_STEALTH_ROCK, MOVE_MEMENTO},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_2] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_STEALTH_ROCK, MOVE_EXPLOSION},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_2] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_HYPNOSIS, MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SANDSLASH_2] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VENOMOTH_2] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_BATON_PASS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLISSEY_2] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
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
        .ability = 2
    },
    [FRONTIER_MON_JUMPLUFF_2] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_SLEEP_POWDER, MOVE_SWORDS_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BASTIODON_2] = {
        .species = SPECIES_BASTIODON,
        .moves = {MOVE_STEALTH_ROCK, MOVE_METAL_BURST, MOVE_ROAR, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LIEPARD_2] = {
        .species = SPECIES_LIEPARD,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_GUNK_SHOT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
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
        .ability = 2
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
        .moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_MACH_PUNCH, MOVE_BULK_UP},
        .heldItem = ITEM_LUCKY_PUNCH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GIRAFARIG_2] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_RETURN, MOVE_PSYCHIC_FANGS, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONTOP_2] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_FAKE_OUT, MOVE_TRIPLE_KICK, MOVE_BULLET_PUNCH, MOVE_STONE_EDGE},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_2] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_REAPING_BLOW, MOVE_SHADOW_SNEAK, MOVE_SECRET_POWER, MOVE_GUNK_SHOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NINJASK_2] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SONIC_BOOM, MOVE_DRILL_RUN, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
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
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CAMERUPT_2] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_2] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_2] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNEZONE_2] = {
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MANTINE_2] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SCALD, MOVE_HAZE, MOVE_TOXIC, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
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
        .moves = {MOVE_ACID, MOVE_ACUPRESSURE, MOVE_STOCKPILE, MOVE_SLACK_OFF},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRAWDAUNT_2] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_CRUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PIDGEOT_2] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_EXTREME_SPEED, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GRUMPIG_2] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_RECYCLE, MOVE_CALM_MIND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TORKOAL_2] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_2] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
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
        .moves = {MOVE_GIGA_DRAIN, MOVE_MOONBLAST, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_2] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
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
        .ability = 2
    },
    [FRONTIER_MON_GOREBYSS_2] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BATON_PASS, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
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
        .moves = {MOVE_HYDRO_PUMP, MOVE_GRAVEL_STORM, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_2] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_STONE_EDGE, MOVE_AQUA_JET, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_POLIWRATH_2] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_CIRCLE_THROW, MOVE_SCALD, MOVE_REST, MOVE_SLEEP_TALK},
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
        .ability = 2
    },
    [FRONTIER_MON_POLITOED_2] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_2] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
        .heldItem = ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    //Pokemon with originally 4+ sets are below
    [FRONTIER_MON_DUGTRIO_1] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_STONE_EDGE, MOVE_SCREECH},
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
    [FRONTIER_MON_MISMAGIUS_1] = {
        .species = SPECIES_MISMAGIUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_1] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_FOCUS_ENERGY, MOVE_AGILITY},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
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
        .moves = {MOVE_FROST_BREATH, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_LOVELY_KISS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSKNOIR_1] = {
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_WILL_O_WISP, MOVE_TRICK_ROOM},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
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
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_1] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_DISCHARGE, MOVE_DAZZLING_GLEAM, MOVE_SIGNAL_BEAM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BRELOOM_1] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_SPORE, MOVE_SUBSTITUTE, MOVE_LEECH_SEED, MOVE_FOCUS_PUNCH},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FORRETRESS_1] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_1] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_DIVE, MOVE_RAIN_DANCE, MOVE_REST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_XATU_1] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_THUNDER_WAVE, MOVE_U_TURN},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SKARMORY_1] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_TOXIC, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAROWAK_1] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE, MOVE_SUBSTITUTE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUAGSIRE_1] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLEFABLE_1] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_1] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_REVENGE, MOVE_KNOCK_OFF, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_1] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_FLAIL, MOVE_SECRET_POWER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DEWGONG_1] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_PERISH_SONG, MOVE_WHIRLPOOL, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANECTRIC_1] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_1] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_STRENGTH_SAP, MOVE_MOONBLAST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VICTREEBEL_1] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ELECTRODE_1] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_EXPLOSION, MOVE_TAUNT},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXPLOUD_1] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SHIFTRY_1] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_LOW_KICK},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_1] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUDICOLO_1] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ENERGY_BALL, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_1] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_ZEN_HEADBUTT, MOVE_DRAIN_PUNCH, MOVE_HYPNOSIS, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_1] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYPERIOR_1] = {
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK, MOVE_ICE_FANG},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALAKAZAM_1] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_ENCORE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WEEZING_1] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_ACID, MOVE_WILL_O_WISP, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_1] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_1] = {
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_BULLET_PUNCH, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_1] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_1] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_YAWN, MOVE_EE_PROTECT, MOVE_NIGHTMARE, MOVE_BLOCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWKING_1] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILTANK_1] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_THUNDER_WAVE, MOVE_STEALTH_ROCK, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ALTARIA_1] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_COTTON_GUARD, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_1] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_1] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGMORTAR_1] = {
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_CRADILY_1] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_STEALTH_ROCK, MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_1] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLDUCK_1] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAPIDASH_1] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HI_JUMP_KICK, MOVE_WILD_CHARGE, MOVE_HIGH_HORSEPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUK_1] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_GUNK_SHOT, MOVE_SHADOW_SNEAK, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GENGAR_1] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_1] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_AGILITY, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_1] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_BUG_BITE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_1] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_URSARING_1] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_BODY_SLAM, MOVE_BULK_UP, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HOUNDOOM_1] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_1] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAYDOL_1] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_1] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SCALD, MOVE_BOOMBURST, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_1] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_1] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHUCKLE_1] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_SHELL_SMASH, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STEELIX_1] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TENTACRUEL_1] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SCALD, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AERODACTYL_1] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_FLY, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON2_1] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_TRICK_ROOM, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
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
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_STARMIE_1] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_COSMIC_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLYGON_1] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_LEECH_LIFE, MOVE_DRAGON_CLAW, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_1] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_TOXIC, MOVE_INGRAIN},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VAPOREON_1] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JOLTEON_1] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_ELECTRO_BALL, MOVE_EE_PROTECT, MOVE_SUBSTITUTE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FLAREON_1] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_PLAY_ROUGH, MOVE_MORNING_SUN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_1] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_HIDDEN_POWER, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_ESPEON_1] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_MORNING_SUN, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_UMBREON_1] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_YAWN, MOVE_EE_PROTECT, MOVE_NIGHTMARE, MOVE_MEAN_LOOK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_1] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SCALD, MOVE_ROAR, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_1] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SCALD, MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AGGRON_1] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_AQUA_TAIL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_1] = {
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_POWER_TRIP, MOVE_FLAME_CHARGE, MOVE_BULK_UP, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WALREIN_1] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_FROST_BREATH, MOVE_SHEER_COLD, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_1] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_1] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_BELLY_DRUM, MOVE_ACROBATICS, MOVE_OVERHEAT, MOVE_SUBSTITUTE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_1] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FLARE_BLITZ, MOVE_EARTHQUAKE, MOVE_SUBMISSION, MOVE_WILD_CHARGE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_1] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CROBAT_1] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEAT_WAVE, MOVE_GIGA_DRAIN, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SWAMPERT_1] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_1] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_1] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_FACADE, MOVE_CURSE, MOVE_FIRE_PUNCH, MOVE_RECYCLE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
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
    [FRONTIER_MON_CHANSEY_1] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM, MOVE_SEISMIC_TOSS, MOVE_SOFT_BOILED},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILOTIC_1] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_1] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_WILL_O_WISP, MOVE_FLARE_BLITZ, MOVE_MORNING_SUN, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_1] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_OUTRAGE, MOVE_AEROBLAST, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_1] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLAKING_1] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_BODY_SLAM, MOVE_BULK_UP, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLISCOR_1] = {
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_FACADE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAWLUCHA_1] = {
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_SKY_ATTACK, MOVE_ACROBATICS, MOVE_HI_JUMP_KICK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_POWER_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RAMPARDOS_1] = {
        .species = SPECIES_RAMPARDOS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_FIRE_PUNCH, MOVE_SUPERPOWER, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GASTRODON_1] = {
        .species = SPECIES_GASTRODON,
        .moves = {MOVE_SCALD, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEAVILE_1] = {
        .species = SPECIES_WEAVILE,
        .moves = {MOVE_KNOCK_OFF, MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_LOW_KICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TALONFLAME_1] = {
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_ACROBATICS, MOVE_WILL_O_WISP, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_1] = {
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FROSLASS_1] = {
        .species = SPECIES_FROSLASS,
        .moves = {MOVE_FROST_BREATH, MOVE_SHADOW_BALL, MOVE_DRAINING_KISS, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AEGISLASH_1] = {
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SHADOW_SNEAK, MOVE_KINGS_SHIELD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOUCANNON_1] = {
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BOOMBURST, MOVE_BRAVE_BIRD, MOVE_OVERHEAT, MOVE_BULLET_SEED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_RASH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIMIKYU_1] = {
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_CURSE},
        .heldItem = ITEM_SPELL_TAG,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_FAN_1] = {
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_RAIN_DANCE, MOVE_HURRICANE, MOVE_THUNDER, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PANGORO_1] = {
        .species = SPECIES_PANGORO,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_CHOPLE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIKAVOLT_1] = {
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STARAPTOR_1] = {
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAMOSWINE_1] = {
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_ICICLE_CRASH, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HONCHKROW_1] = {
        .species = SPECIES_HONCHKROW,
        .moves = {MOVE_DRILL_PECK, MOVE_NIGHT_SLASH, MOVE_SUPERPOWER, MOVE_ROOST},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AURORUS_1] = {
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_AURORA_VEIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIENSHAO_1] = {
        .species = SPECIES_MIENSHAO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMOLGA_1] = {
        .species = SPECIES_EMOLGA,
        .moves = {MOVE_ACROBATICS, MOVE_WILD_CHARGE, MOVE_U_TURN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FROST_1] = {
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZEBSTRIKA_1] = {
        .species = SPECIES_ZEBSTRIKA,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TANGROWTH_1] = {
        .species = SPECIES_TANGROWTH,
        .moves = {MOVE_GIGA_DRAIN, MOVE_KNOCK_OFF, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROSERADE_1] = {
        .species = SPECIES_ROSERADE,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_TOXIC_SPIKES, MOVE_SYNTHESIS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_MOW_1] = {
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_1] = {
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TREVENANT_1] = {
        .species = SPECIES_TREVENANT,
        .moves = {MOVE_WOOD_HAMMER, MOVE_REAPING_BLOW, MOVE_EARTHQUAKE, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLACEON_1] = {
        .species = SPECIES_GLACEON,
        .moves = {MOVE_FROST_BREATH, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL, MOVE_SYNCHRONOISE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_LEAFEON_1] = {
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_RETURN, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPIRITOMB_1] = {
        .species = SPECIES_SPIRITOMB,
        .moves = {MOVE_WILL_O_WISP, MOVE_NIGHT_SHADE, MOVE_STRENGTH_SAP, MOVE_PARTING_SHOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GIGALITH_1] = {
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_STONE_EDGE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_1] = {
        .species = SPECIES_LYCANROC,
        .moves = {MOVE_STONE_EDGE, MOVE_DRILL_RUN, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALLADE_1] = {
        .species = SPECIES_GALLADE,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_KNOCK_OFF, MOVE_BULK_UP, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAPION_1] = {
        .species = SPECIES_DRAPION,
        .moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_AGILITY, MOVE_FELL_STINGER},
        .heldItem = ITEM_LANSAT_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEWEAR_1] = {
        .species = SPECIES_BEWEAR,
        .moves = {MOVE_RETURN, MOVE_SUPERPOWER, MOVE_SHADOW_CLAW, MOVE_FACADE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_1] = {
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_DRAIN_PUNCH, MOVE_COIL, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LOPUNNY_1] = {
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_COVET, MOVE_STORM_THROW, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_NORMAL_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_1] = {
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEHEEYEM_1] = {
        .species = SPECIES_BEHEEYEM,
        .moves = {MOVE_PSYCHIC, MOVE_SIGNAL_BEAM, MOVE_NASTY_PLOT, MOVE_TRICK_ROOM},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 27,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON_Z_1] = {
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_AGILITY, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOIVERN_1] = {
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HIPPOWDON_1] = {
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_WHIRLWIND, MOVE_SLACK_OFF, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KROOKODILE_1] = {
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_STONE_EDGE, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLURK_1] = {
        .species = SPECIES_GOLURK,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERROTHORN_1] = {
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_POWER_WHIP, MOVE_INGRAIN, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLISOPOD_1] = {
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAWITZER_1] = {
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_1] = {
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_LOW_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXICROAK_1] = {
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_CIRCLE_THROW, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CHANDELURE_1] = {
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_1] = {
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_FAKE_OUT, MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_U_TURN},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DURANT_1] = {
        .species = SPECIES_DURANT,
        .moves = {MOVE_IRON_HEAD, MOVE_X_SCISSOR, MOVE_SUPERPOWER, MOVE_HONE_CLAWS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GALVANTULA_1] = {
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_STICKY_WEB},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_1] = {
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_1] = {
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_STONE_EDGE, MOVE_PSYCHIC_FANGS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUDSDALE_1] = {
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_HEAVY_SLAM, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PALOSSAND_1] = {
        .species = SPECIES_PALOSSAND,
        .moves = {MOVE_EARTH_POWER, MOVE_TOXIC, MOVE_SHORE_UP, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PYUKUMUKU_1] = {
        .species = SPECIES_PYUKUMUKU,
        .moves = {MOVE_PAIN_SPLIT, MOVE_TAUNT, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TURTONATOR_1] = {
        .species = SPECIES_TURTONATOR,
        .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_DRACO_METEOR, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CONKELDURR_1] = {
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_DUSK_1] = {
        .species = SPECIES_LYCANROC_DUSK,
        .moves = {MOVE_STONE_EDGE, MOVE_ACCELEROCK, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_1] = {
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JELLICENT_1] = {
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_SCALD, MOVE_TAUNT, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_1] = {
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_NONE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CINCCINO_1] = {
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_BULLET_SEED, MOVE_ROCK_BLAST, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SERPERIOR_1] = {
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TSAREENA_1] = {
        .species = SPECIES_TSAREENA,
        .moves = {MOVE_POWER_WHIP, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_MIRACLE_SEED,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLAZIKEN_1] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_EE_PROTECT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAXORUS_1] = {
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TORTERRA_1] = {
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_1] = {
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUXRAY_1] = {
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_1] = {
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHESNAUGHT_1] = {
        .species = SPECIES_CHESNAUGHT,
        .moves = {MOVE_ENDURE, MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SYLVEON_1] = {
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_HIDDEN_POWER, MOVE_WISH, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_BISHARP_1] = {
        .species = SPECIES_BISHARP,
        .moves = {MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_STEALTH_ROCK, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMPOLEON_1] = {
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_STEALTH_ROCK, MOVE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_1] = {
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANTRUM_1] = {
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELPHOX_1] = {
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_MYSTICAL_FIRE, MOVE_WISH, MOVE_EE_PROTECT, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VANILLUXE_1] = {
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_EXPLOSION},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DECIDUEYE_1] = {
        .species = SPECIES_DECIDUEYE,
        .moves = {MOVE_SHADOW_BALL, MOVE_GIGA_DRAIN, MOVE_NASTY_PLOT, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_INFERNAPE_1] = {
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_FOCUS_BLAST, MOVE_INFERNO, MOVE_NASTY_PLOT, MOVE_VACUUM_WAVE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMBOAR_1] = {
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_HEAD_SMASH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_1] = {
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_GUNK_SHOT, MOVE_DARK_PULSE, MOVE_LOW_KICK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_1] = {
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FLAMETHROWER, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_SUBSTITUTE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMARINA_1] = {
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_MOONBLAST, MOVE_SPARKLING_ARIA, MOVE_ICE_BEAM, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGALGE_1] = {
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_1] = {
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_NASTY_PLOT, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARAQUANID_1] = {
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_STICKY_WEB, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_1] = {
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_WASH_1] = {
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_1] = {
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_1] = {
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_DRAGON_TAIL, MOVE_TOXIC},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KOMMO_O_1] = {
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_OUTRAGE, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIGIGAS_1] = {
        .species = SPECIES_REGIGIGAS,
        .moves = {MOVE_NATURE_POWER, MOVE_EARTH_POWER, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUGTRIO_2] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_STONE_EDGE, MOVE_HONE_CLAWS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_2] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISMAGIUS_2] = {
        .species = SPECIES_MISMAGIUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_DAZZLING_GLEAM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_2] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_FOCUS_ENERGY, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRANBULL_2] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_2] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_FROST_BREATH, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSKNOIR_2] = {
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_TRICK_ROOM},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
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
        .moves = {MOVE_PSYSHOCK, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_2] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_DISCHARGE, MOVE_ICE_BEAM, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRELOOM_2] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_BULLET_SEED, MOVE_MACH_PUNCH, MOVE_ROCK_TOMB, MOVE_SPORE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FORRETRESS_2] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_GYRO_BALL, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_2] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_BOUNCE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_XATU_2] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_ROOST, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SKARMORY_2] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAROWAK_2] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE, MOVE_FIRE_PUNCH},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUAGSIRE_2] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLEFABLE_2] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_2] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM, MOVE_STONE_EDGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_2] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_ENDURE, MOVE_FLAIL, MOVE_REVERSAL, MOVE_SECRET_POWER},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DEWGONG_2] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_HORN_DRILL, MOVE_SHEER_COLD, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANECTRIC_2] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLAMETHROWER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_2] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_STRENGTH_SAP, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VICTREEBEL_2] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRODE_3] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_VOLT_SWITCH, MOVE_TAUNT},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXPLOUD_2] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SHIFTRY_2] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_SOLAR_BLADE, MOVE_KNOCK_OFF, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_2] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUDICOLO_2] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_2] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_2] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_EXPLOSION, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYPERIOR_2] = {
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALAKAZAM_2] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_WEEZING_2] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_ACID, MOVE_WILL_O_WISP, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_2] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_2] = {
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_2] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_2] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWKING_2] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILTANK_2] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_HEAL_BELL, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALTARIA_2] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_2] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_2] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGMORTAR_2] = {
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_CRADILY_2] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_2] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLDUCK_2] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_AQUA_JET},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAPIDASH_2] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_HI_JUMP_KICK, MOVE_WILD_CHARGE, MOVE_HIGH_HORSEPOWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUK_2] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_GUNK_SHOT, MOVE_SHADOW_SNEAK, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GENGAR_2] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_2] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_SIGNAL_BEAM, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCIZOR_2] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_QUICK_ATTACK, MOVE_ROOST, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_2] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_REVERSAL, MOVE_KNOCK_OFF, MOVE_ENDURE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_URSARING_2] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_RETURN, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HOUNDOOM_2] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_2] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAYDOL_2] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYSHOCK, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_2] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BOOMBURST},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_2] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_2] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_BULK_UP, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUCKLE_2] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_2] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEAVY_SLAM, MOVE_HEAD_SMASH, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TENTACRUEL_2] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AERODACTYL_2] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_STONE_EDGE, MOVE_ROCK_SLIDE, MOVE_FLY, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON2_2] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_RECOVER, MOVE_TOXIC, MOVE_ICE_BEAM},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARDEVOIR_2] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_2] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_2] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FLYGON_2] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_BOOMBURST, MOVE_DRAGON_PULSE, MOVE_ROOST, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_2] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_VAPOREON_2] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_WISH, MOVE_ACID_ARMOR, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JOLTEON_2] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_SIGNAL_BEAM, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FLAREON_2] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_PLAY_ROUGH, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_2] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_LEECH_SEED, MOVE_EE_PROTECT, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ESPEON_2] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_UMBREON_2] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_FOUL_PLAY, MOVE_WISH, MOVE_SWAGGER, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_2] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_FLASH_CANNON, MOVE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_2] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_LIQUIDATION, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AGGRON_2] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_AQUA_TAIL},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_2] = {
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WALREIN_2] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_FROST_BREATH, MOVE_SURF, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_2] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_2] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_FOCUS_BLAST, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYPHLOSION_2] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_BLAST_OFF, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_2] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CROBAT_2] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SUPER_FANG, MOVE_TAUNT, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SWAMPERT_2] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_DIVE, MOVE_ICE_PUNCH, MOVE_HAMMER_ARM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_2] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SNORLAX_2] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SELF_DESTRUCT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGDRA_2] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_FLASH_CANNON, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANSEY_2] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_SEISMIC_TOSS, MOVE_SOFT_BOILED},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MILOTIC_2] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_DRAGON_TAIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_2] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_EXTREME_SPEED, MOVE_MORNING_SUN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_2] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_AEROBLAST, MOVE_BLAST_OFF, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_2] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_AGILITY},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLAKING_2] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_RETURN, MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLISCOR_2] = {
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_FACADE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAWLUCHA_2] = {
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ACROBATICS, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEAVILE_2] = {
        .species = SPECIES_WEAVILE,
        .moves = {MOVE_KNOCK_OFF, MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TALONFLAME_2] = {
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_BRAVE_BIRD, MOVE_FLARE_BLITZ, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_2] = {
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FROSLASS_2] = {
        .species = SPECIES_FROSLASS,
        .moves = {MOVE_HAIL, MOVE_FROST_BREATH, MOVE_SHADOW_BALL, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AEGISLASH_2] = {
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SWORDS_DANCE, MOVE_KINGS_SHIELD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOUCANNON_2] = {
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BOOMBURST, MOVE_BRAVE_BIRD, MOVE_HEAT_WAVE, MOVE_FLASH_CANNON},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_RASH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MIMIKYU_2] = {
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_FAN_2] = {
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_HYPER_VOICE, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PANGORO_2] = {
        .species = SPECIES_PANGORO,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIKAVOLT_2] = {
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_ROOST},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAMOSWINE_2] = {
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_ICICLE_CRASH, MOVE_STONE_EDGE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HONCHKROW_2] = {
        .species = SPECIES_HONCHKROW,
        .moves = {MOVE_BRAVE_BIRD, MOVE_NIGHT_SLASH, MOVE_SUPERPOWER, MOVE_DRILL_PECK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARAPTOR_2] = {
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAMPARDOS_2] = {
        .species = SPECIES_RAMPARDOS,
        .moves = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_SUPERPOWER, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GASTRODON_2] = {
        .species = SPECIES_GASTRODON,
        .moves = {MOVE_SCALD, MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AURORUS_2] = {
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_AURORA_VEIL},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIENSHAO_2] = {
        .species = SPECIES_MIENSHAO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_POISON_JAB, MOVE_U_TURN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMOLGA_2] = {
        .species = SPECIES_EMOLGA,
        .moves = {MOVE_TAILWIND, MOVE_AIR_SLASH, MOVE_VOLT_SWITCH, MOVE_NUZZLE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FROST_2] = {
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ZEBSTRIKA_2] = {
        .species = SPECIES_ZEBSTRIKA,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TANGROWTH_2] = {
        .species = SPECIES_TANGROWTH,
        .moves = {MOVE_GIGA_DRAIN, MOVE_KNOCK_OFF, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROSERADE_2] = {
        .species = SPECIES_ROSERADE,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_LEAF_STORM, MOVE_ACID, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_MOW_2] = {
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_2] = {
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TREVENANT_2] = {
        .species = SPECIES_TREVENANT,
        .moves = {MOVE_WOOD_HAMMER, MOVE_REAPING_BLOW, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLACEON_2] = {
        .species = SPECIES_GLACEON,
        .moves = {MOVE_FROST_BREATH, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL, MOVE_SYNCHRONOISE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_LEAFEON_2] = {
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_RETURN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_YACHE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPIRITOMB_2] = {
        .species = SPECIES_SPIRITOMB,
        .moves = {MOVE_WILL_O_WISP, MOVE_CURSE, MOVE_STRENGTH_SAP, MOVE_PARTING_SHOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GIGALITH_2] = {
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_2] = {
        .species = SPECIES_LYCANROC,
        .moves = {MOVE_STONE_EDGE, MOVE_DRILL_RUN, MOVE_ACCELEROCK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALLADE_2] = {
        .species = SPECIES_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAPION_2] = {
        .species = SPECIES_DRAPION,
        .moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_AGILITY, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LANSAT_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEWEAR_2] = {
        .species = SPECIES_BEWEAR,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_DRAIN_PUNCH, MOVE_SHADOW_CLAW, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_2] = {
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_VOLT_SWITCH, MOVE_FLAMETHROWER, MOVE_GIGA_DRAIN, MOVE_DRAGON_PULSE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LOPUNNY_2] = {
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_STORM_THROW, MOVE_BRUTAL_SWING},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_2] = {
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEHEEYEM_2] = {
        .species = SPECIES_BEHEEYEM,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 27,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON_Z_2] = {
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOIVERN_2] = {
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HIPPOWDON_2] = {
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_SLACK_OFF, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KROOKODILE_2] = {
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_STONE_EDGE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLURK_2] = {
        .species = SPECIES_GOLURK,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERROTHORN_2] = {
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLISOPOD_2] = {
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_SILVER_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAWITZER_2] = {
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_2] = {
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_COVET, MOVE_LOW_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_NORMAL_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXICROAK_2] = {
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANDELURE_2] = {
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_2] = {
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DURANT_2] = {
        .species = SPECIES_DURANT,
        .moves = {MOVE_BUG_BITE, MOVE_THUNDER_FANG, MOVE_ICE_FANG, MOVE_SUPERPOWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GALVANTULA_2] = {
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN, MOVE_STICKY_WEB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_2] = {
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_2] = {
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_POWER_TRIP, MOVE_DRAIN_PUNCH, MOVE_BULK_UP, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUDSDALE_2] = {
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PALOSSAND_2] = {
        .species = SPECIES_PALOSSAND,
        .moves = {MOVE_EARTH_POWER, MOVE_SHADOW_BALL, MOVE_SHORE_UP, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PYUKUMUKU_2] = {
        .species = SPECIES_PYUKUMUKU,
        .moves = {MOVE_BLOCK, MOVE_RECOVER, MOVE_SPITE, MOVE_TAUNT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TURTONATOR_2] = {
        .species = SPECIES_TURTONATOR,
        .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_FOCUS_BLAST, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CONKELDURR_2] = {
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_DUSK_2] = {
        .species = SPECIES_LYCANROC_DUSK,
        .moves = {MOVE_STONE_EDGE, MOVE_ACCELEROCK, MOVE_DRILL_RUN, MOVE_FIRE_FANG},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_2] = {
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JELLICENT_2] = {
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_SCALD, MOVE_HEX, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_2] = {
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_FLY, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CINCCINO_2] = {
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_BULLET_SEED, MOVE_ROCK_BLAST, MOVE_KNOCK_OFF},
        .heldItem = ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SERPERIOR_2] = {
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_GLARE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_TSAREENA_2] = {
        .species = SPECIES_TSAREENA,
        .moves = {MOVE_POWER_WHIP, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLAZIKEN_2] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_BLAST_OFF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAXORUS_2] = {
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TORTERRA_2] = {
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_ROCK_SLIDE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_2] = {
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUXRAY_2] = {
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_2] = {
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHESNAUGHT_2] = {
        .species = SPECIES_CHESNAUGHT,
        .moves = {MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SYLVEON_2] = {
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_BISHARP_2] = {
        .species = SPECIES_BISHARP,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_IRON_HEAD, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMPOLEON_2] = {
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GRASS_KNOT, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_2] = {
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_LIQUIDATION, MOVE_SACRED_SWORD, MOVE_KNOCK_OFF, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANTRUM_2] = {
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELPHOX_2] = {
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_GRASS_KNOT, MOVE_CALM_MIND},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VANILLUXE_2] = {
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_HASTY,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_DECIDUEYE_2] = {
        .species = SPECIES_DECIDUEYE,
        .moves = {MOVE_LEAF_BLADE, MOVE_SPIRIT_SHACKLE, MOVE_SHADOW_SNEAK, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_INFERNAPE_2] = {
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_INFERNO, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMBOAR_2] = {
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_2] = {
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_GRASS_KNOT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_2] = {
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_PRIMARINA_2] = {
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_MOONBLAST, MOVE_SPARKLING_ARIA, MOVE_ICE_BEAM, MOVE_ENERGY_BALL},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGALGE_2] = {
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SLUDGE_WAVE, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_2] = {
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_THUNDER_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARAQUANID_2] = {
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_2] = {
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_WASH_2] = {
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_2] = {
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_2] = {
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KOMMO_O_2] = {
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_THUNDER_PUNCH, MOVE_BELLY_DRUM, MOVE_SUBSTITUTE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIGIGAS_2] = {
        .species = SPECIES_REGIGIGAS,
        .moves = {MOVE_RETURN, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_1] = {
        .species = SPECIES_COBALION,
        .moves = {MOVE_SACRED_SWORD, MOVE_STEALTH_ROCK, MOVE_THUNDER_WAVE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_1] = {
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_X_SCISSOR},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_1] = {
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
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
        .moves = {MOVE_SACRED_FIRE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_1] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_1] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_POWER_UP_PUNCH, MOVE_RECOVER},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_1] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_HAZE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_1] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_TOXIC, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_1] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_MIST_BALL, MOVE_SURF, MOVE_HEALING_WISH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_1] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_LUSTER_PURGE, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_2] = {
        .species = SPECIES_COBALION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_2] = {
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_2] = {
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
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
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_2] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_THUNDER_WAVE, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_2] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_2] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
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
        .moves = {MOVE_DRAGON_PULSE, MOVE_LUSTER_PURGE, MOVE_ROOST, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_3] = {
        .species = SPECIES_COBALION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 25,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_3] = {
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_ROCK_POLISH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_3] = {
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_ENERGY_BALL, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
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
        .moves = {MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_3] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_3] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_3] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_THUNDERBOLT, MOVE_RECOVER, MOVE_CALM_MIND},
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
        .species = SPECIES_COBALION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_4] = {
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_4] = {
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
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
        .moves = {MOVE_SACRED_FIRE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_4] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_4] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAIN_PUNCH, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_4] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_4] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_TOXIC, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_4] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_MIST_BALL, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_4] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_GENGAR_3] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEX, MOVE_FOCUS_BLAST, MOVE_WILL_O_WISP},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANDELURE_3] = {
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
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
    [FRONTIER_MON_CHANDELURE_4] = {
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_3] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_3] = {
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_4] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUCARIO_4] = {
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MACHAMP_3] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CONKELDURR_3] = {
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_POISON_JAB},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MACHAMP_4] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CONKELDURR_4] = {
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_POISON_JAB},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARDEVOIR_3] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_DRAINING_KISS, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SERPERIOR_3] = {
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_DRAGON_PULSE, MOVE_GLARE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_GARDEVOIR_4] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYSHOCK, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SERPERIOR_4] = {
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_SUBSTITUTE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 25,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_3] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_3] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_BLAZE_KICK, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_4] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_4] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_FLARE_BLITZ, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_3] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_3] = {
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_4] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_4] = {
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_SNORLAX_3] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TOGEKISS_3] = {
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_DAZZLING_GLEAM, MOVE_FLAMETHROWER, MOVE_AURA_SPHERE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNORLAX_4] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_EARTHQUAKE, MOVE_RECYCLE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_4] = {
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_NASTY_PLOT, MOVE_THUNDER_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SALAMENCE_3] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FLY, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GARCHOMP_3] = {
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAMENCE_4] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_AEROBLAST, MOVE_FIRE_BLAST, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_4] = {
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_METAGROSS_3] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KOMMO_O_3] = {
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_CLANGING_SCALES, MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_4] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KOMMO_O_4] = {
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_CLANGING_SCALES, MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_5] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STEALTH_ROCK, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_6] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_5] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_6] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_5] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_6] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_5] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_MIST_BALL, MOVE_SURF, MOVE_HEALING_WISH},
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
        .moves = {MOVE_MIST_BALL, MOVE_THUNDERBOLT, MOVE_RECOVER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_8] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRACO_METEOR, MOVE_LUSTER_PURGE, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_5] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_LUSTER_PURGE, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_6] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_MIST_BALL, MOVE_ROOST, MOVE_CALM_MIND},
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
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_1] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HURRICANE, MOVE_THUNDER, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_2] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_3] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_FLY, MOVE_DRAGON_DANCE, MOVE_SUBSTITUTE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_4] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POWER_WHIP, MOVE_IRON_TAIL},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_5] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_6] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_7] = {
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_HIDDEN_POWER, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_8] = {
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_BUG_BUZZ, MOVE_HIDDEN_POWER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_9] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_FLY, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_10] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRAGON_PULSE, MOVE_FLAMETHROWER, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_1] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_2] = {
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_3] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_REST, MOVE_CURSE},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_4] = {
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_5] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_DRAGON_DANCE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_6] = {
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_U_TURN, MOVE_FIRE_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_7] = {
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_ROOST, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_8] = {
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_9] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_10] = {
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRAGON_PULSE, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_5] = {
        .species = SPECIES_COBALION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_6] = {
        .species = SPECIES_KELDEO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_HYDRO_PUMP, MOVE_SECRET_SWORD, MOVE_SCALD},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_5] = {
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_6] = {
        .species = SPECIES_KELDEO,
        .moves = {MOVE_SCALD, MOVE_SECRET_SWORD, MOVE_TAUNT, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_5] = {
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_6] = {
        .species = SPECIES_KELDEO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_HYDRO_PUMP, MOVE_SECRET_SWORD, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
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
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
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
