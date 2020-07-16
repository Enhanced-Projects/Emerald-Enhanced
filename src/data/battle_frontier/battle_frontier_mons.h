const struct FacilityMon gBattleFrontierMons[NUM_FRONTIER_MONS] =
{
    [FRONTIER_MON_LEAFEON_3] = { // Leafeon-Sun
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_SECRET_POWER, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_YACHE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_AZUMARILL_4] = { // Azumarill-BandSuperpower
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_LIQUIDATION, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ILLUMISE_3] = { // Illumise-BulkyQuiverDance
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_HIDDEN_POWER, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_VOLBEAT_3] = { // Volbeat-Band
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_WILD_CHARGE, MOVE_U_TURN, MOVE_ICE_PUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAPION_3] = { // Drapion-SD
        .species = SPECIES_DRAPION,
        .moves = {MOVE_KNOCK_OFF, MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHUCA_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GALLADE_3] = { // Gallade-ShellBellSD
        .species = SPECIES_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_3] = { // Gyarados-ShellBellDD
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILOTIC_3] = { // Milotic-OffensiveHPgrass
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_METAPOD] = { // Unused
        .species = SPECIES_METAPOD,
        .moves = {MOVE_BUG_BITE, MOVE_TACKLE, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KAKUNA] = { // Unused
        .species = SPECIES_KAKUNA,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_3] = { // Togedemaru-BandReversal
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_REVERSAL, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SILCOON] = { // Unused
        .species = SPECIES_SILCOON,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CASCOON] = { // Unused
        .species = SPECIES_CASCOON,
        .moves = {MOVE_BUG_BITE, MOVE_POISON_STING, MOVE_IRON_DEFENSE, MOVE_STRING_SHOT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_3] = { // Whimsicott-Defensive
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_STUN_SPORE, MOVE_ENCORE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUAGSIRE_3] = { // Quagsire-PhysicalWall
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_SCALD, MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONTOP_3] = { // Hitmontop-AV
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH, MOVE_U_TURN},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HAXORUS_3] = { // Haxorus-SteelDD
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LOPUNNY_3] = { // Lopunny-SilkScarfPlayRough
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_STORM_THROW, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOGOAT_3] = { // Gogoat-GrassPeltJumpKick
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_JUMP_KICK, MOVE_GRASSY_TERRAIN, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUDICOLO_3] = { // Ludicolo-RainShellBell
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIGHTYENA_3] = { // Mightyena-BulkySD
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_BODY_SLAM, MOVE_SWORDS_DANCE, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHEDINJA] = { // Shedinja-ReflectType
        .species = SPECIES_SHEDINJA,
        .moves = {MOVE_SHADOW_SNEAK, MOVE_REFLECT_TYPE, MOVE_WILL_O_WISP, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_LONELY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCRAFTY_3] = { // Scrafty-PoisonDD
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON2_3] = { // Porygon2-PhysDefWall
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_FOUL_PLAY, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LINOONE_3] = { // Linoone-GrassGround
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SEED_BOMB, MOVE_STOMPING_TANTRUM, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CROBAT_3] = { // Crobat-Band
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_SECRET_POWER, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_SMEARGLE_1] = { // Smeargle-GeoPass
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_SPORE, MOVE_GEOMANCY, MOVE_BOOMBURST, MOVE_BATON_PASS},
        .heldItem = ITEM_POWER_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HERACROSS_3] = { // Heracross-SD
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AZUMARILL_3] = { // Azumarill-AssaultVest
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_LIQUIDATION, MOVE_KNOCK_OFF},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_4] = { // Sceptile-SniperShellBell
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGMORTAR_3] = { // Magmortar-AV
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_FLAME_CHARGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAMOSWINE_3] = { // Mamoswine-NeverMelt
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_ICICLE_CRASH, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SMEARGLE_2] = { // Smeargle-SmashPass
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_SPORE, MOVE_SHELL_SMASH, MOVE_BOOMBURST, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLISCOR_3] = { // Gliscor-Stall
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_ROOST},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RATICATE_3] = { // Raticate-GutsSD
        .species = SPECIES_RATICATE,
        .moves = {MOVE_FACADE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WOBBUFFET_3] = { // Wobuffet-SpDef
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DELCATTY_3] = { // Delcatty-BulkyCM
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_HYPER_VOICE, MOVE_CALM_MIND, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NOIVERN_3] = { // Noivern-Scarf
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_3] = { // Archeops-PhysicalUturn
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_ACROBATICS, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_YANMEGA_2] = { // Yanmega-SpeedBoost
        .species = SPECIES_YANMEGA,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_HIDDEN_POWER, MOVE_EE_PROTECT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_3] = { // Scyther-SDpass
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_SWORDS_DANCE, MOVE_ROOST, MOVE_BATON_PASS},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCIZOR_3] = { // Scizor-SD
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_ACROBATICS, MOVE_SUPERPOWER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLISOPOD_3] = { // Golisopod-ShellBell
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SKARMORY_3] = { // Skarmory-DrillPeckStealthRock
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_DRILL_PECK, MOVE_STEALTH_ROCK, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_3] = { // Swellow-Guts
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FACADE, MOVE_BRAVE_BIRD, MOVE_U_TURN, MOVE_SECRET_POWER},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 29,
        .ability = 0   
    },
    [FRONTIER_MON_PIDGEOT_3] = { // Pidgeot-Offensive
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SECRET_POWER, MOVE_EXTREME_SPEED, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_3] = { // Nidoking-Scarf
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOQUEEN_3] = { // Nidoqueen-Defensive
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES, MOVE_ROAR},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SYLVEON_3] = { // Sylveon-BulkyProtect
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_CALM_MIND, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUXRAY_3] = { // Luxray-BulkyExBelt
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_3] = { // Audino-ShadowBall
        .species = SPECIES_AUDINO,
        .moves = {MOVE_HYPER_VOICE, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLAKING_3] = { // Slaking-Band
        .species = SPECIES_SLAKING,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALVANTULA_3] = { // Galvantula-LifeOrbVoltSwitch
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_VOLT_SWITCH, MOVE_STICKY_WEB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARBOK_3] = { // Arbok-CoilSucker
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DITTO] = { // Ditto-Scarf
        .species = SPECIES_DITTO,
        .moves = {MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WHISCASH_3] = { // Whiscash-SubDD
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_SUBSTITUTE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PERSIAN_3] = { // Persian-Band
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_RETURN, MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FORRETRESS_3] = { // Forretress-DualHazardsVoltSwitch
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_GYRO_BALL, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHUCKLE_3] = { // Shuckle-Infestation
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_INFESTATION},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VANILLUXE_3] = { // Vanilluxe-HPfireMild
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MILD,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_MANTINE_3] = { // Mantine-DampRockRain
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DURANT_3] = { // Durant-ExBelt
        .species = SPECIES_DURANT,
        .moves = {MOVE_BUG_BITE, MOVE_THUNDER_FANG, MOVE_ICE_FANG, MOVE_SUPERPOWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIMIKYU_3] = { // Mimikyu-SpellTagSD
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SPELL_TAG,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUSKNOIR_3] = { // Dusknoir-SneakWisp
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_WILL_O_WISP},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VIKAVOLT_3] = { // Vikavolt-Bulky
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_ROOST},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINETALES_3] = { // Ninetales-FastSub
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ROTOM_FROST_3] = { // Rotom_Frost-Specs
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_SANDSLASH_3] = { // Sandslash-Defensive
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_STEALTH_ROCK, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_POLIWRATH_3] = { // Poliwrath-ToxicProtect
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_CIRCLE_THROW, MOVE_SCALD, MOVE_TOXIC, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MASQUERAIN_3] = { // Masquerain-FastQD
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_SCALD, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RHYPERIOR_3] = { // Rhyperior-WP
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WAILORD_4] = { // Wailord-Specs
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BOOMBURST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_Z_3] = { // Porygon_Z-HyperBeam
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_ICE_BEAM, MOVE_HYPER_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_3] = { // Octillery-TR
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_SLUDGE_BOMB, MOVE_ENERGY_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARCHOMP_5] = { // Garchomp-BulkyTankChomp
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_DRAGON_TAIL, MOVE_TOXIC},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLAYDOL_3] = { // Claydol-CM
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AURORUS_3] = { // Aurorus-NeverMelt
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_AURORA_VEIL},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_5] = { // Salamence-Scarf
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_AEROBLAST, MOVE_BLAST_OFF, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_3] = { // Zangoose-Protect
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EE_PROTECT},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SEVIPER_3] = { // Seviper-NP
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENOMOTH_3] = { // Venomoth-SleepPowderQD
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PRIMEAPE_3] = { // Primeape-BlackBelt
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMBOAR_3] = { // Emboar-Band
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_3] = { // Cloyster-LifeOrb
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_JYNX_3] = { // Jynx-LovelyKissNP
        .species = SPECIES_JYNX,
        .moves = {MOVE_FROST_BREATH, MOVE_FOCUS_BLAST, MOVE_LOVELY_KISS, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CAMERUPT_3] = { // Camerupt-Defensive
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_LAVA_PLUME, MOVE_EARTH_POWER, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_3] = { // Sharpedo-Sash
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CRAWDAUNT_3] = { // Crawdaunt-SD
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CHARIZARD_3] = { // Charizard-3attacksRoost
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_AIR_SLASH, MOVE_FOCUS_BLAST, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DELPHOX_3] = { // Delphox-Scarf
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_GRASS_KNOT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ALAKAZAM_3] = { // Alakazam-Counter
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_COUNTER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DODRIO_3] = { // Dodrio-TangledFeet
        .species = SPECIES_DODRIO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_THRASH, MOVE_JUMP_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_3] = { // Scolipede-LifeOrbSD
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HAWLUCHA_3] = { // Hawlucha-DrainPunch
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ACROBATICS, MOVE_DRAIN_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_3] = { // Sceptile-SniperWideLens
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TALONFLAME_3] = { // Talonflame-BU
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_ACROBATICS, MOVE_WILL_O_WISP, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_3] = { // Wailord-BulkyRestTalk
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SCALD, MOVE_BOOMBURST, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLASTOISE_3] = { // Blastoise-Scarf
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_3] = { // Feraligatr-SD
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_LIQUIDATION, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_3] = { // Slowbro-PhysDefWall
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_THUNDER_WAVE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TORTERRA_3] = { // Torterra-BulkySD
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_SWORDS_DANCE, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_3] = { // Meganium-3attacks
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_HIDDEN_POWER, MOVE_GIGA_DRAIN, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_VILEPLUME_3] = { // Vileplume-Sun
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_TENTACRUEL_3] = { // Tentacruel-Balanced
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAROWAK_3] = { // Marowak-3attacksSD
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_FIRE_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEAKING_3] = { // Seaking-Offensive
        .species = SPECIES_SEAKING,
        .moves = {MOVE_DIVE, MOVE_MEGAHORN, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_3] = { // Tropius-BulkySD
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLEFABLE_3] = { // Clefable-1attackCM
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_THUNDER_WAVE, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGNEZONE_3] = { // Magnezone-Specs
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_MIRROR_SHOT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DEWGONG_3] = { // Dewgong-HailIceShard
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_DRILL_RUN, MOVE_HAIL},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOXICROAK_3] = { // Toxicroak-NP
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_3] = { // Kingler-4attacks
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_ROCK_SLIDE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXEGGUTOR_3] = { // Exeggutor-SubSeed
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_LEECH_SEED, MOVE_SUBSTITUTE},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOUCANNON_3] = { // Toucannon-SD
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BRAVE_BIRD, MOVE_BULLET_SEED, MOVE_FLAME_CHARGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CINCCINO_3] = { // Cinccino-LifeOrb
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_ARM_THRUST, MOVE_ROCK_BLAST, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FAN_3] = { // Rotom_Fan-RainHPground
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_RAIN_DANCE, MOVE_HURRICANE, MOVE_THUNDER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_3] = { // Eelektross-AV
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_THUNDERBOLT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PELIPPER_3] = { // Pelipper-Scarf
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ICE_BEAM, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DELIBIRD] = { // Delibird-Band
        .species = SPECIES_DELIBIRD,
        .moves = {MOVE_PRESENT, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_3] = { // Rotom_Heat-Scarf
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HIPPOWDON_3] = { // Hippowdon-Offensive
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROCK_SLIDE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GRUMPIG_3] = { // Grumpig-BulkyRecycle
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_RECYCLE, MOVE_CALM_MIND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYRANTRUM_3] = { // Tyrantrum-Band
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUVDISC] = { // Luvdisc-Rain
        .species = SPECIES_LUVDISC,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_3] = { // Toxapex-Spiky
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_SPIKY_SHIELD},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CACTURNE_3] = { // Cacturne-WP
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UNOWN] = { // Unown-StoredPower
        .species = SPECIES_UNOWN,
        .moves = {MOVE_COSMIC_POWER, MOVE_MOONLIGHT, MOVE_STORED_POWER, MOVE_DAZZLING_GLEAM},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGALGE_3] = { // Dragalge-AV
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PRIMARINA_4] = { // Primarina-AV
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_MOONBLAST, MOVE_SPARKLING_ARIA, MOVE_ICE_BEAM, MOVE_AQUA_JET},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LILLIGANT_3] = { // Lilligant-OffensiveQD
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_DAZZLING_GLEAM, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_MOW_3] = { // Rotom_Mow-Bulky
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLAWITZER_3] = { // Clawitzer-LifeOrb
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FLYGON_3] = { // Flygon-CompoundDD
        .species = SPECIES_FLYGON,
        .moves = {MOVE_DRAGON_RUSH, MOVE_IRON_TAIL, MOVE_FIRE_BLAST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MUDSDALE_3] = { // Mudsdale-RestTalk
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PRIMARINA_3] = { // Primarina-RestTalk
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_SCALD, MOVE_MOONBLAST, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARAPTOR_3] = { // Staraptor-AdamantBand
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_3] = { // Salazzle-Scarf
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SLUDGE_WAVE, MOVE_HIDDEN_POWER, MOVE_DRAGON_PULSE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_FARFETCHD] = { // Farfetchd-SD
        .species = SPECIES_FARFETCHD,
        .moves = {MOVE_ACROBATICS, MOVE_LEAF_BLADE, MOVE_SECRET_POWER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_3] = { // Omastar-Hazards
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_SCALD, MOVE_GRAVEL_STORM, MOVE_STEALTH_ROCK, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_3] = { // Kabutops-Scarf
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CRADILY_3] = { // Cradily-SpDefWall
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_LEECH_SEED, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_3] = { // Armaldo-Band
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_3] = { // Ambipom-LifeOrb
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_LOW_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_3] = { // Electivire-Band
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_BULLET_PUNCH, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXPLOUD_3] = { // Exploud-RestoBerry
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_WORK_UP, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPINDA] = { // Spinda-Contrary
        .species = SPECIES_SPINDA,
        .moves = {MOVE_PSYCHO_BOOST, MOVE_TRICK_ROOM, MOVE_HIDDEN_POWER, MOVE_BATON_PASS},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 27,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_3] = { // Zoroark-Mixed
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_LOW_KICK, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_4] = { // Zoroark-SD
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_RETURN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AMPHAROS_3] = { // Ampharos-BigRoot
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_SIGNAL_BEAM, MOVE_TAIL_GLOW},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLAREON_3] = { // Flareon-BU
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_BULK_UP, MOVE_MORNING_SUN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PROBOPASS] = { // Probopass-AV
        .species = SPECIES_PROBOPASS,
        .moves = {MOVE_POWER_GEM, MOVE_DISCHARGE, MOVE_EARTH_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CORSOLA] = { // Corsola-Band
        .species = SPECIES_CORSOLA,
        .moves = {MOVE_HEAD_SMASH, MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAWILE] = { // Mawile-ExBelt
        .species = SPECIES_MAWILE,
        .moves = {MOVE_PLAY_ROUGH, MOVE_ICE_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEEDRILL_1] = { // Beedrill-KnockOff
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEEDRILL_2] = { // Beedrill-Xscissor
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EMPOLEON_3] = { // Empoleon-MysticWater
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GRASS_KNOT, MOVE_RAIN_DANCE},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_3] = { // Steelix-SheerForce
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_ICE_FANG, MOVE_COIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BEAUTIFLY] = { // Beautifly-QD
        .species = SPECIES_BEAUTIFLY,
        .moves = {MOVE_BUG_BUZZ, MOVE_HIDDEN_POWER, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_DUSTOX] = { // Dustox-Bulky
        .species = SPECIES_DUSTOX,
        .moves = {MOVE_GUNK_SHOT, MOVE_LEECH_LIFE, MOVE_SECRET_POWER, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_LEDIAN] = { // Ledian-SD
        .species = SPECIES_LEDIAN,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARIADOS] = { // Ariados-Hazards
        .species = SPECIES_ARIADOS,
        .moves = {MOVE_STICKY_WEB, MOVE_TOXIC_SPIKES, MOVE_MEGAHORN, MOVE_TOXIC_THREAD},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_YANMEGA_1] = { // Yanmega-TintedLens
        .species = SPECIES_YANMEGA,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_GIGA_DRAIN, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    //Pokemon with originally 2 sets are below
    [FRONTIER_MON_DELCATTY_1] = { // Delcatty-ExBelt
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_HYPER_VOICE, MOVE_ENERGY_BALL, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SABLEYE_1] = { // Sableye-CM
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_DARK_PULSE, MOVE_WILL_O_WISP, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LICKILICKY_1] = { // Lickilicky-Defensive
        .species = SPECIES_LICKILICKY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FERROTHORN_3] = { // Ferrothorn-SpikesIngrain
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_SPIKES, MOVE_INGRAIN, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLEM_3] = { // Golem-PUP
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_POWER_UP_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHERRIM_1] = { // Cherrim-Special
        .species = SPECIES_CHERRIM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_DAZZLING_GLEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_1] = { // Audino-Toxic
        .species = SPECIES_AUDINO,
        .moves = {MOVE_HYPER_VOICE, MOVE_TOXIC, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DARMANITAN_ZEN_1] = { // Darmanitan_Zen-Flamethrower
        .species = SPECIES_DARMANITAN_ZEN,
        .moves = {MOVE_PSYCHIC, MOVE_GRAVEL_STORM, MOVE_FLAMETHROWER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_WASH_3] = { // Rotom_Wash-OffensiveWiki
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_THUNDERBOLT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_1] = { // Whimsicott-SpecsHurricane
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_ENERGY_BALL, MOVE_PSYCHIC, MOVE_HURRICANE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VOLBEAT_1] = { // Volbeat-TailGlowPass
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_THUNDERBOLT, MOVE_TAIL_GLOW, MOVE_BATON_PASS, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ILLUMISE_1] = { // Illumise-BulkyQuiverPass
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_BATON_PASS, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MARACTUS_1] = { // Maractus-ExBelt
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_ENERGY_BALL, MOVE_EARTH_POWER, MOVE_WEATHER_BALL, MOVE_SANDSTORM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_3] = { // Incineroar-Band
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SAMUROTT_3] = { // Samurott-Jolly
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_LIQUIDATION, MOVE_SACRED_SWORD, MOVE_KNOCK_OFF, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PARASECT_1] = { // Parasect-Bulky
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_LEECH_LIFE, MOVE_SEED_BOMB, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONLEE_3] = { // Hitmonlee-NormalGem
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_STONE_EDGE},
        .heldItem = ITEM_NORMAL_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AEGISLASH_3] = { // Aegislash-WP
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOGOAT_1] = { // Gogoat-MilkDrinkRockSlide
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_BULK_UP, MOVE_ROCK_SLIDE, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_3] = { // Typhlosion-SpecsBlastOff
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_BLAST_OFF, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_5] = { // Greninja-Scarf
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ROCK_SLIDE, MOVE_U_TURN, MOVE_ICE_BEAM, MOVE_LOW_KICK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAICHU_3] = { // Raichu-Band
        .species = SPECIES_RAICHU,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EXTREME_SPEED, MOVE_SECRET_POWER, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_3] = { // Noctowl-BulkyKeenEye
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_HYPNOSIS, MOVE_HURRICANE, MOVE_WHIRLWIND, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WOBBUFFET_1] = { // Wobuffet-PhysDefWiki
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PLUSLE_1] = { // Plusle-EncoreNP
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_GRASS_KNOT, MOVE_ENCORE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MINUN_1] = { // Minun-SubToxic
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_ENCORE, MOVE_TOXIC, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LURANTIS_1] = { // Lurantis-Mixed
        .species = SPECIES_LURANTIS,
        .moves = {MOVE_LEAF_STORM, MOVE_SUPERPOWER, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_INFERNAPE_3] = { // Infernape-SD
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_INFERNO, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SWAMPERT_3] = { // Swampert-Defensive
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_SCALD, MOVE_RAIN_DANCE, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_3] = { // Darmanitan-LifeOrb
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AZUMARILL_1] = { // Azumarill-BandKnockOff
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_LIQUIDATION, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUDOWOODO_1] = { // Sudowoodo-FastBand
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_HEAD_SMASH, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGCARGO_1] = { // Magcargo-WhiteHerb
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_FIRE_BLAST, MOVE_GRAVEL_STORM, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PANGORO_3] = { // Pangoro-Band
        .species = SPECIES_PANGORO,
        .moves = {MOVE_HAMMER_ARM, MOVE_SUCKER_PUNCH, MOVE_DRAIN_PUNCH, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WALREIN_3] = { // Walrein-Curse
        .species = SPECIES_WALREIN,
        .moves = {MOVE_AVALANCHE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RATICATE_1] = { // Raticate-HustleSD
        .species = SPECIES_RATICATE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MASQUERAIN_1] = { // Masquerain-OffensiveWeb
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_BUG_BUZZ, MOVE_STICKY_WEB, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_1] = { // Furret-CoilPass
        .species = SPECIES_FURRET,
        .moves = {MOVE_BODY_SLAM, MOVE_COIL, MOVE_REST, MOVE_BATON_PASS},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUNSPARCE_1] = { // Dunsparce-2attacks
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_BODY_SLAM, MOVE_ROCK_SLIDE, MOVE_COIL, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOODRA_5] = { // Goodra-RestTalk
        .species = SPECIES_GOODRA,
        .moves = {MOVE_OUTRAGE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIGHTYENA_1] = { // Mightyena-QuickFeetProtect
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_FACADE, MOVE_CRUNCH, MOVE_FIRE_FANG, MOVE_EE_PROTECT},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LINOONE_1] = { // Linoone-GhostGround
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SHADOW_CLAW, MOVE_STOMPING_TANTRUM, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CASTFORM_1] = { // Castform-ExBelt
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_FIRE_BLAST, MOVE_HYDRO_PUMP, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KOMMO_O_5] = { // Kommo_O-PhysicalScarf
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_OUTRAGE, MOVE_CLOSE_COMBAT, MOVE_POISON_JAB, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_5] = { // Metagross-ScarfPunches
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WIGGLYTUFF_1] = { // Wigglytuff-ExBelt
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT, MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUNFLORA_1] = { // Sunflora-Flamethrower
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_SOLAR_BEAM, MOVE_FLAMETHROWER, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BUTTERFREE_1] = { // Butterfree-Leftovers
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CONKELDURR_5] = { // Conkeldurr-BU
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QWILFISH_1] = { // Qwilfish-Tspikes
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_LIQUIDATION, MOVE_POISON_JAB, MOVE_TOXIC_SPIKES, MOVE_TAUNT},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JELLICENT_3] = { // Jellicent-Specs
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SHADOW_BALL, MOVE_WATER_SPOUT, MOVE_ICE_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PELIPPER_1] = { // Pelipper-Defensive
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_ROOST, MOVE_U_TURN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_1] = { // Swellow-BoomburstWorkUp
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_HIDDEN_POWER, MOVE_WORK_UP},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_3] = { // Lycanroc_Midnight-RestoBerry
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_POWER_TRIP, MOVE_REST, MOVE_BULK_UP, MOVE_ROCK_POLISH},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LILLIGANT_1] = { // Lilligant-Sun
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_DAZZLING_GLEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARBOK_1] = { // Arbok-CoilGlare
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_GLARE, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PERSIAN_1] = { // Persian-LifeOrb
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FAKE_OUT, MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_U_TURN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KINGDRA_3] = { // Kingdra-CritdraAgility
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_AGILITY, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KECLEON_1] = { // Kecleon-LifeOrb
        .species = SPECIES_KECLEON,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_RECOVER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCRAFTY_1] = { // Scrafty-SteelDD
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUNATONE_1] = { // Lunatone-WP
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_POWER_GEM, MOVE_PSYSHOCK, MOVE_EARTH_POWER, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_1] = { // Solrock-PhysDefWall
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_WILL_O_WISP, MOVE_MORNING_SUN, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_1] = { // Noctowl-StoredPower
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_AGILITY, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SANDSLASH_1] = { // Sandslash-BulkySand
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VENOMOTH_1] = { // Venomoth-QuiverPassWonderSkin
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_BATON_PASS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BLISSEY_1] = { // Blissey-SereneGrace
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEAKING_1] = { // Seaking-RestTalk
        .species = SPECIES_SEAKING,
        .moves = {MOVE_HORN_DRILL, MOVE_DIVE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JUMPLUFF_1] = { // Jumpluff-SeedBomb
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_SEED_BOMB, MOVE_SLEEP_POWDER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BASTIODON_1] = { // Bastiodon-DualHazards
        .species = SPECIES_BASTIODON,
        .moves = {MOVE_METAL_BURST, MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_SHORE_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LIEPARD_1] = { // Liepard-NP
        .species = SPECIES_LIEPARD,
        .moves = {MOVE_DARK_PULSE, MOVE_ENCORE, MOVE_NASTY_PLOT, MOVE_COPYCAT},
        .heldItem = ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PRIMEAPE_1] = { // Primeape-Band
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONLEE_1] = { // Hitmonlee-WhiteHerb
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_STONE_EDGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONCHAN_1] = { // Hitmonchan-DualSetup
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_AGILITY, MOVE_BULK_UP},
        .heldItem = ITEM_LUCKY_PUNCH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GIRAFARIG_1] = { // Girafarig-CM
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SUBSTITUTE, MOVE_BATON_PASS},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONTOP_1] = { // Hitmontop-TechniTopMachPunch
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_TRIPLE_KICK, MOVE_MACH_PUNCH, MOVE_BULLET_PUNCH, MOVE_STONE_EDGE},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_1] = { // Banette-Wisp
        .species = SPECIES_BANETTE,
        .moves = {MOVE_REAPING_BLOW, MOVE_GUNK_SHOT, MOVE_WILL_O_WISP, MOVE_SHADOW_SNEAK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINJASK_1] = { // Ninjask-Pass
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SONIC_BOOM, MOVE_DRILL_RUN, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEVIPER_1] = { // Seviper-ShedRest
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DARK_PULSE, MOVE_NASTY_PLOT, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_1] = { // Zangoose-QuickAttack
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CAMERUPT_1] = { // Camerupt-Specs
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_FLAMETHROWER, MOVE_OVERHEAT, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_1] = { // Sharpedo-LifeOrb
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_EE_PROTECT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_1] = { // Tropius-BulkyDD
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNEZONE_1] = { // Magnezone-MirrorCoatAV
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_MIRROR_SHOT, MOVE_HIDDEN_POWER, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANTINE_1] = { // Mantine-OffensiveRain
        .species = SPECIES_MANTINE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STANTLER_1] = { // Stantler-Band
        .species = SPECIES_STANTLER,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SUCKER_PUNCH, MOVE_JUMP_KICK, MOVE_MEGAHORN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ABSOL_1] = { // Absol-Band
        .species = SPECIES_ABSOL,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_SUPERPOWER, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SWALOT_1] = { // Swalot-2attacks
        .species = SPECIES_SWALOT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_ACUPRESSURE, MOVE_SLACK_OFF},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRAWDAUNT_1] = { // Crawdaunt-DD
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PIDGEOT_1] = { // Pidgeot-BulkySPground
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SECRET_POWER, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_GRUMPIG_1] = { // Grumpig-Specs
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TORKOAL_1] = { // Torkoal-ExBelt
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_1] = { // Kingler-Agility
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_ROCK_SLIDE, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CACTURNE_1] = { // Cacturne-Sash
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BELLOSSOM_1] = { // Bellossom-SleepPowderQD
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_1] = { // Octillery-SkillLink
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_BULLET_SEED, MOVE_ROCK_BLAST, MOVE_PIN_MISSILE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HUNTAIL_1] = { // Huntail-3attacks
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_SUCKER_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOREBYSS_1] = { // Gorebyss-3attacks
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_RELICANTH_1] = { // Relicanth-Band
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_HEAD_SMASH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_1] = { // Omastar-Sash
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GRAVEL_STORM, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_1] = { // Kabutops-Band
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLIWRATH_1] = { // Poliwrath-AV
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_FOCUS_BLAST, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_VACUUM_WAVE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_1] = { // Scyther-Scarf
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_U_TURN, MOVE_BRICK_BREAK, MOVE_BUG_BITE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PINSIR_1] = { // Pinsir-Scarf
        .species = SPECIES_PINSIR,
        .moves = {MOVE_X_SCISSOR, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLITOED_1] = { // Politoed-Scarf
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_1] = { // Cloyster-Sash
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DELCATTY_2] = { // Delcatty-CM
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_MOONBLAST, MOVE_HYPER_VOICE, MOVE_THUNDERBOLT, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SABLEYE_2] = { // Sableye-PhysDefWall
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_FOUL_PLAY, MOVE_WILL_O_WISP, MOVE_SEISMIC_TOSS, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LICKILICKY_2] = { // Lickilicky-Curse
        .species = SPECIES_LICKILICKY,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FERROTHORN_4] = { // Ferrothorn-DualHazards
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_4] = { // Golem-HeavySlam
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_HEAVY_SLAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHERRIM_2] = { // Cherrim-Physical
        .species = SPECIES_CHERRIM,
        .moves = {MOVE_PETAL_BLIZZARD, MOVE_SECRET_POWER, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_2] = { // Audino-BoltBeam
        .species = SPECIES_AUDINO,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DARMANITAN_ZEN_2] = { // Darmanitan_Zen-FocusBlast
        .species = SPECIES_DARMANITAN_ZEN,
        .moves = {MOVE_PSYCHIC, MOVE_GRAVEL_STORM, MOVE_FOCUS_BLAST, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_WASH_4] = { // Rotom_Wash-BulkyWiki
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_2] = { // Whimsicott-SpecsHPfire
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_ENERGY_BALL, MOVE_PSYCHIC, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_VOLBEAT_2] = { // Volbeat-3attacksRoost
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_WILD_CHARGE, MOVE_LUNGE, MOVE_ICE_PUNCH, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ILLUMISE_2] = { // Illumise-OffensiveQuiverDance
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MARACTUS_2] = { // Maractus-LifeOrb
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_GIGA_DRAIN, MOVE_EARTH_POWER, MOVE_WEATHER_BALL, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_4] = { // Incineroar-Guts
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_4] = { // Samurott-Timid
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PARASECT_2] = { // Parasect-SpDefWall
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_LEECH_LIFE, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONLEE_4] = { // Hitmonlee-Reversal
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_ENDURE, MOVE_REVERSAL, MOVE_KNOCK_OFF, MOVE_STONE_EDGE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_LONELY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AEGISLASH_4] = { // Aegislash-Band
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_IRON_HEAD, MOVE_SHADOW_SNEAK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOGOAT_2] = { // Gogoat-GrassPeltRockSlide
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_ROCK_SLIDE, MOVE_GRASSY_TERRAIN, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYPHLOSION_4] = { // Typhlosion-SpecsFireBlast
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_6] = { // Greninja-DualHazards
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_TAUNT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAICHU_4] = { // Raichu-NP
        .species = SPECIES_RAICHU,
        .moves = {MOVE_HYPER_VOICE, MOVE_SURF, MOVE_GRASS_KNOT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_4] = { // Noctowl-TintedLens
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WOBBUFFET_2] = { // Wobuffet-PhysDefSitrus
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PLUSLE_2] = { // Plusle-HPice
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_GRASS_KNOT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MINUN_2] = { // Minun-NP
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_NUZZLE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LURANTIS_2] = { // Lurantis-Physical
        .species = SPECIES_LURANTIS,
        .moves = {MOVE_SUPERPOWER, MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_INFERNAPE_4] = { // Infernape-Specs
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_GRASS_KNOT, MOVE_INFERNO},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_3] = { // Excadrill-SandSash
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SANDSTORM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_4] = { // Darmanitan-BandSuperpower
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AZUMARILL_2] = { // Azumarill-BD
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_KNOCK_OFF, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUDOWOODO_2] = { // Sudowoodo-BulkyBand
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_HEAD_SMASH, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGCARGO_2] = { // Magcargo-Sash
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_FIRE_BLAST, MOVE_GRAVEL_STORM, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PUPITAR] = { // Tyranitar-AV
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_PURSUIT, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_3] = { // Seismitoad-Special
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_HYDRO_PUMP, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RATICATE_2] = { // Raticate-Band
        .species = SPECIES_RATICATE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MASQUERAIN_2] = { // Masquerain-BulkyQD
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_SCALD, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_2] = { // Furret-CoilKnockOff
        .species = SPECIES_FURRET,
        .moves = {MOVE_RETURN, MOVE_KNOCK_OFF, MOVE_COIL, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUNSPARCE_2] = { // Dunsparce-Glare
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_HEADBUTT, MOVE_GLARE, MOVE_COIL, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOODRA_6] = { // Goodra-Hydration
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRAGON_PULSE, MOVE_MUDDY_WATER, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIGHTYENA_2] = { // Mightyena-QuickFeetSD
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_FACADE, MOVE_CRUNCH, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LINOONE_2] = { // Linoone-GhostGrass
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SEED_BOMB, MOVE_SHADOW_CLAW, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CASTFORM_2] = { // Castform-Rain
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_THUNDER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KOMMO_O_6] = { // Kommo_O-SteelDD
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_OUTRAGE, MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_6] = { // Metagross-IcePunchAV
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WIGGLYTUFF_2] = { // Wigglytuff-WishProtect
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUNFLORA_2] = { // Sunflora-WeatherBall
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BUTTERFREE_2] = { // Butterfree-WP
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_ROOST},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CONKELDURR_6] = { // Conkeldurr-GutsFacade
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_FACADE},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QWILFISH_2] = { // Qwilfish-Rain
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_LIQUIDATION, MOVE_POISON_JAB, MOVE_SWORDS_DANCE, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_JELLICENT_4] = { // Jellicent-TR
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SHADOW_BALL, MOVE_RECOVER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PELIPPER_2] = { // Pelipper-Specs
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ICE_BEAM, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_2] = { // Swellow-BoomburstSpecs
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_4] = { // Lycanroc_Midnight-SD
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_STONE_EDGE, MOVE_PSYCHIC_FANGS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LILLIGANT_2] = { // Lilligant-BulkyQD
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_SYNTHESIS, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_ARBOK_2] = { // Arbok-CoilIceFang
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PERSIAN_2] = { // Persian-SwagCat
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_THUNDER_WAVE, MOVE_SWAGGER, MOVE_FOUL_PLAY, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARAQUANID_3] = { // Araquanid-AV
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_SCALD, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KECLEON_2] = { // Kecleon-AV
        .species = SPECIES_KECLEON,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCRAFTY_2] = { // Scrafty-BU
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_BULK_UP, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUNATONE_2] = { // Lunatone-ScreensLead
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_STEALTH_ROCK, MOVE_MEMENTO},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_2] = { // Solrock-ScreensLead
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_STEALTH_ROCK, MOVE_EXPLOSION},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_2] = { // Noctowl-OffensiveKeenEye
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_HYPNOSIS, MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SANDSLASH_2] = { // Sandslash-FastSand
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VENOMOTH_2] = { // Venomoth-QuiverPassTintedLens
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_BATON_PASS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLISSEY_2] = { // Blissey-NaturalCure
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEAKING_2] = { // Seaking-AV
        .species = SPECIES_SEAKING,
        .moves = {MOVE_DIVE, MOVE_MEGAHORN, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JUMPLUFF_2] = { // Jumpluff-StrengthSap
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_STRENGTH_SAP, MOVE_SLEEP_POWDER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BASTIODON_2] = { // Bastiodon-Taunt
        .species = SPECIES_BASTIODON,
        .moves = {MOVE_METAL_BURST, MOVE_SPIKES, MOVE_TAUNT, MOVE_SHORE_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LIEPARD_2] = { // Liepard-Band
        .species = SPECIES_LIEPARD,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_GUNK_SHOT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMEAPE_2] = { // Primeape-Scarf
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONLEE_2] = { // Hitmonlee-LifeOrb
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_MACH_PUNCH, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONCHAN_2] = { // Hitmonchan-MachPunch
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_MACH_PUNCH, MOVE_BULK_UP},
        .heldItem = ITEM_LUCKY_PUNCH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GIRAFARIG_2] = { // Girafarig-Band
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_RETURN, MOVE_PSYCHIC_FANGS, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONTOP_2] = { // Hitmontop-TechniTopFakeOut
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_FAKE_OUT, MOVE_TRIPLE_KICK, MOVE_BULLET_PUNCH, MOVE_STONE_EDGE},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_2] = { // Banette-4attacks
        .species = SPECIES_BANETTE,
        .moves = {MOVE_REAPING_BLOW, MOVE_SHADOW_SNEAK, MOVE_SECRET_POWER, MOVE_GUNK_SHOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NINJASK_2] = { // Ninjask-Protect
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SONIC_BOOM, MOVE_DRILL_RUN, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEVIPER_2] = { // Seviper-ExBelt
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_2] = { // Zangoose-SwordsDance
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CAMERUPT_2] = { // Camerupt-PhysicalAV
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_STONE_EDGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SHARPEDO_2] = { // Sharpedo-ExBelt
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_2] = { // Tropius-DD
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNEZONE_2] = { // Magnezone-VoltSwitchAV
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_MIRROR_SHOT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MANTINE_2] = { // Mantine-SpDefWall
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SCALD, MOVE_HAZE, MOVE_TOXIC, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_STANTLER_2] = { // Stantler-LifeOrb
        .species = SPECIES_STANTLER,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SUCKER_PUNCH, MOVE_JUMP_KICK, MOVE_EARTHQUAKE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ABSOL_2] = { // Absol-SuperLuck
        .species = SPECIES_ABSOL,
        .moves = {MOVE_NIGHT_SLASH, MOVE_STONE_EDGE, MOVE_PSYCHO_CUT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWALOT_2] = { // Swalot-Stockpile
        .species = SPECIES_SWALOT,
        .moves = {MOVE_ACID, MOVE_ACUPRESSURE, MOVE_STOCKPILE, MOVE_SLACK_OFF},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRAWDAUNT_2] = { // Crawdaunt-Band
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_CRUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PIDGEOT_2] = { // Pidgeot-BulkyExtremeSpeed
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_EXTREME_SPEED, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GRUMPIG_2] = { // Grumpig-OffensiveRecycle
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_RECYCLE, MOVE_CALM_MIND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TORKOAL_2] = { // Torkoal-ShellSmash
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_2] = { // Kingler-SD
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CACTURNE_2] = { // Cacturne-LifeOrb
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BELLOSSOM_2] = { // Bellossom-MoonblastQD
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MOONBLAST, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_2] = { // Octillery-ExBelt
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HUNTAIL_2] = { // Huntail-SmashPass
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_BATON_PASS, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOREBYSS_2] = { // Gorebyss-SmashPass
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BATON_PASS, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RELICANTH_2] = { // Relicanth-RockPolish
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_HEAD_SMASH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_2] = { // Omastar-WhiteHerb
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GRAVEL_STORM, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_2] = { // Kabutops-Rain
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_STONE_EDGE, MOVE_AQUA_JET, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_POLIWRATH_2] = { // Poliwrath-RestTalk
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_CIRCLE_THROW, MOVE_SCALD, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_2] = { // Scyther-Band
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_U_TURN, MOVE_BRICK_BREAK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PINSIR_2] = { // Pinsir-SD
        .species = SPECIES_PINSIR,
        .moves = {MOVE_X_SCISSOR, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLITOED_2] = { // Politoed-Specs
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_2] = { // Cloyster-KingsRock
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
        .heldItem = ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    //Pokemon with originally 4+ sets are below
    [FRONTIER_MON_DUGTRIO_1] = { // Dugtrio-Screech
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_STONE_EDGE, MOVE_SCREECH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_1] = { // Medicham-Reversal
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_REVERSAL, MOVE_ZEN_HEADBUTT, MOVE_ENDURE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISMAGIUS_1] = { // Mismagius-ExBelt
        .species = SPECIES_MISMAGIUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_1] = { // Fearow-DualSetup
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_FOCUS_ENERGY, MOVE_AGILITY},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRANBULL_1] = { // Granbull-BU
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_BULK_UP, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_1] = { // Jynx-3attacksLovelyKiss
        .species = SPECIES_JYNX,
        .moves = {MOVE_FROST_BREATH, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_LOVELY_KISS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSKNOIR_1] = { // Dusknoir-WispTR
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_WILL_O_WISP, MOVE_TRICK_ROOM},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DODRIO_1] = { // Dodrio-Flail
        .species = SPECIES_DODRIO,
        .moves = {MOVE_FLAIL, MOVE_DRILL_PECK, MOVE_JUMP_KICK, MOVE_ENDURE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_1] = { // Mr_Mime-Scarf
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_1] = { // Lanturn-AV
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_DISCHARGE, MOVE_DAZZLING_GLEAM, MOVE_SIGNAL_BEAM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BRELOOM_1] = { // Breloom-SubSeed
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_SPORE, MOVE_SUBSTITUTE, MOVE_LEECH_SEED, MOVE_FOCUS_PUNCH},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FORRETRESS_1] = { // Forretress-DualHazardsRest
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_1] = { // Whiscash-DDhydration
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_DIVE, MOVE_RAIN_DANCE, MOVE_REST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_XATU_1] = { // Xatu-DualScreens
        .species = SPECIES_XATU,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_THUNDER_WAVE, MOVE_U_TURN},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SKARMORY_1] = { // Skarmory-SpikesToxic
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_TOXIC, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAROWAK_1] = { //  Marowak-3attacksSub
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE, MOVE_SUBSTITUTE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUAGSIRE_1] = { // Quagsire-CurseSpDef
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLEFABLE_1] = { // Clefable-2attacksCM
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_1] = { // Hariyama-RestTalk
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_REVENGE, MOVE_KNOCK_OFF, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_1] = { // Raichu-Physical
        .species = SPECIES_RAICHU,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_FLAIL, MOVE_SECRET_POWER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DEWGONG_1] = { // Dewgong-HailSD
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICICLE_CRASH, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE, MOVE_HAIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MANECTRIC_1] = { // Manectric-Specs
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_1] = { // Vileplume-BulkyAttacker
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_STRENGTH_SAP, MOVE_MOONBLAST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VICTREEBEL_1] = { // Victreebel-Offensive
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ELECTRODE_1] = { // Electrode-ScreensExplosion
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_EXPLOSION, MOVE_TAUNT},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXPLOUD_1] = { // Exploud-Scarf
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SHIFTRY_1] = { // Shiftry-ExBelt
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_LOW_KICK},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_1] = { // Glalie-Band
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_THUNDER_FANG, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUDICOLO_1] = { // Ludicolo-RainEnergyBall
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ENERGY_BALL, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_1] = { // Hypno-BD
        .species = SPECIES_HYPNO,
        .moves = {MOVE_ZEN_HEADBUTT, MOVE_DRAIN_PUNCH, MOVE_HYPNOSIS, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_1] = { // Golem-Sucker
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUCKER_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYPERIOR_1] = { // Rhyperior-SapSipper
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK, MOVE_ICE_FANG},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ALAKAZAM_1] = { // Alakazam-Encore
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_ENCORE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WEEZING_1] = { // Weezing-MixedWall
        .species = SPECIES_WEEZING,
        .moves = {MOVE_ACID, MOVE_WILL_O_WISP, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_1] = { // Kangaskhan-Sucker
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_1] = { // Electivire-LifeOrb
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_BULLET_PUNCH, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_1] = { // Tauros-Mixed
        .species = SPECIES_TAUROS,
        .moves = {MOVE_BODY_SLAM, MOVE_FIRE_BLAST, MOVE_EARTHQUAKE, MOVE_WORK_UP},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_1] = { // Slowbro-Nightmare
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_YAWN, MOVE_EE_PROTECT, MOVE_NIGHTMARE, MOVE_BLOCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWKING_1] = { // Slowking-CM
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILTANK_1] = { // Miltank-PhysDefWall
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_THUNDER_WAVE, MOVE_STEALTH_ROCK, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ALTARIA_1] = { // Altaria-DualSetup
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_COTTON_GUARD, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_1] = { // Nidoqueen-3attacks
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_1] = { // Nidoking-RockSlide
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGMORTAR_1] = { // Magmortar-Scarf
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_CRADILY_1] = { // Cradily-Defensive
        .species = SPECIES_CRADILY,
        .moves = {MOVE_STEALTH_ROCK, MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_1] = { // Armaldo-ShellBellSD
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLDUCK_1] = { // Golduck-Rain
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAPIDASH_1] = { // Rapidash-Band
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_JUMP_KICK, MOVE_WILD_CHARGE, MOVE_HIGH_HORSEPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUK_1] = { // Muk-AV
        .species = SPECIES_MUK,
        .moves = {MOVE_GUNK_SHOT, MOVE_SHADOW_SNEAK, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GENGAR_1] = { // Gengar-ExBelt
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_1] = { // Ampharos-DualSetup
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_AGILITY, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_1] = { // Scizor-Band
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_BUG_BITE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_1] = { // Heracross-Scarf
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_URSARING_1] = { // Ursaring-RestTalk
        .species = SPECIES_URSARING,
        .moves = {MOVE_BODY_SLAM, MOVE_BULK_UP, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HOUNDOOM_1] = { // Houndoom-Scarf
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_1] = { // Donphan-ExBelt
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_BULLDOZE, MOVE_ROCK_TOMB, MOVE_ICE_SHARD, MOVE_FLAME_WHEEL},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLAYDOL_1] = { // Claydol-Specs
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_1] = { // Wailord-OffensiveRestTalk
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SCALD, MOVE_BOOMBURST, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_1] = { // Ninetales-BulkyCM
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_1] = { // Machamp-Guts
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHUCKLE_1] = { // Shuckle-ShellSmashStall
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_SHELL_SMASH, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STEELIX_1] = { // Steelix-RestTalk
        .species = SPECIES_STEELIX,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TENTACRUEL_1] = { // Tentacruel-Defensive
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SCALD, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AERODACTYL_1] = { // Aerodactyl-LifeOrb
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_FLY, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON2_1] = { // Porygon2-TR
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_TRICK_ROOM, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARDEVOIR_1] = { // Gardevoir-OffensiveCM
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_MOONBLAST, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_1] = { // Exeggutor-OffensiveHarvest
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_TRICK_ROOM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_1] = { // Starmie-CosmicPower
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_COSMIC_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLYGON_1] = { // Flygon-DD
        .species = SPECIES_FLYGON,
        .moves = {MOVE_LEECH_LIFE, MOVE_DRAGON_CLAW, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_1] = { // Venusaur-Defensive
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_TOXIC, MOVE_INGRAIN},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VAPOREON_1] = { // Vaporeon-Hydration
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JOLTEON_1] = { // Jolteon-ElectroBall
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_ELECTRO_BALL, MOVE_EE_PROTECT, MOVE_SUBSTITUTE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FLAREON_1] = { // Flareon-3attacksMorningSun
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_PLAY_ROUGH, MOVE_MORNING_SUN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_1] = { // Meganium-2attacks
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_HIDDEN_POWER, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_ESPEON_1] = { // Espeon-CM
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_MORNING_SUN, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_UMBREON_1] = { // Umbreon-Nightmare
        .species = SPECIES_UMBREON,
        .moves = {MOVE_YAWN, MOVE_EE_PROTECT, MOVE_NIGHTMARE, MOVE_MEAN_LOOK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_1] = { // Blastoise-PhysDefWall
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SCALD, MOVE_ROAR, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_1] = { // Feraligatr-Special
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SCALD, MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AGGRON_1] = { // Aggron-RockPolish
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAVY_SLAM, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_METAL_COAT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_1] = { // Incineroar-WP
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_POWER_TRIP, MOVE_FLAME_CHARGE, MOVE_BULK_UP, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WALREIN_1] = { // Walrein-Defensive
        .species = SPECIES_WALREIN,
        .moves = {MOVE_FROST_BREATH, MOVE_EARTHQUAKE, MOVE_YAWN, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_1] = { // Sceptile-Band
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_1] = { // Charizard-DD
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_ACROBATICS, MOVE_EARTHQUAKE, MOVE_OVERHEAT, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_1] = { // Typhlosion-ExBelt
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FLARE_BLITZ, MOVE_EARTHQUAKE, MOVE_SUBMISSION, MOVE_WILD_CHARGE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_1] = { // Lapras-BulkyCM
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CROBAT_1] = { // Crobat-NP
        .species = SPECIES_CROBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEAT_WAVE, MOVE_GIGA_DRAIN, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SWAMPERT_1] = { // Swampert-AV
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_1] = { // Gyarados-LumDD
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_1] = { // Snorlax-FirePunch
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_FACADE, MOVE_CURSE, MOVE_FIRE_PUNCH, MOVE_RECYCLE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KINGDRA_1] = { // Kingdra-Rain
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_DRAGON_PULSE, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANSEY_1] = { // Chansey-DoubleTeam
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM, MOVE_SEISMIC_TOSS, MOVE_SOFT_BOILED},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MILOTIC_1] = { // Milotic-OffensiveToxic
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_1] = { // Arcanine-PhysDefWall
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_WILL_O_WISP, MOVE_FLARE_BLITZ, MOVE_MORNING_SUN, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_1] = { // Salamence-DDmixed
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_OUTRAGE, MOVE_AEROBLAST, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_1] = { // Metagross-ScarfExplosion
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLAKING_1] = { // Slaking-BU
        .species = SPECIES_SLAKING,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_BODY_SLAM, MOVE_BULK_UP, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLISCOR_1] = { // Gliscor-AcroBat
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_ACROBATICS, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAWLUCHA_1] = { // Hawlucha-Roost
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ACROBATICS, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RAMPARDOS_1] = { // Rampardos-AV
        .species = SPECIES_RAMPARDOS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_FIRE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GASTRODON_1] = { // Gastrodon-Offensive
        .species = SPECIES_GASTRODON,
        .moves = {MOVE_SCALD, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEAVILE_1] = { // Weavile-Band
        .species = SPECIES_WEAVILE,
        .moves = {MOVE_KNOCK_OFF, MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_LOW_KICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TALONFLAME_1] = { // Talonflame-1attackSD
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_ACROBATICS, MOVE_WILL_O_WISP, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_1] = { // Scolipede-SDpass
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FROSLASS_1] = { // Froslass-ExBelt
        .species = SPECIES_FROSLASS,
        .moves = {MOVE_FROST_BREATH, MOVE_SHADOW_BALL, MOVE_DRAINING_KISS, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AEGISLASH_1] = { // Aegislash-Leftovers
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SHADOW_SNEAK, MOVE_KINGS_SHIELD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOUCANNON_1] = { // Toucannon-SkillLink
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BOOMBURST, MOVE_BRAVE_BIRD, MOVE_OVERHEAT, MOVE_BULLET_SEED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_RASH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIMIKYU_1] = { // Mimikyu-OffensiveCurse
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_CURSE},
        .heldItem = ITEM_SPELL_TAG,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_FAN_1] = { // Rotom_Fan-RainWisp
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_RAIN_DANCE, MOVE_HURRICANE, MOVE_THUNDER, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PANGORO_1] = { // Pangoro-ChopleSD
        .species = SPECIES_PANGORO,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_CHOPLE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIKAVOLT_1] = { // Vikavolt-Specs
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STARAPTOR_1] = { // Staraptor-JollyBand
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAMOSWINE_1] = { // Mamoswine-Band
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_ICICLE_CRASH, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HONCHKROW_1] = { // Honchkrow-SuperLuck
        .species = SPECIES_HONCHKROW,
        .moves = {MOVE_DRILL_PECK, MOVE_NIGHT_SLASH, MOVE_SUPERPOWER, MOVE_ROOST},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AURORUS_1] = { // Aurorus-Leftovers
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_AURORA_VEIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIENSHAO_1] = { // Mienshao-SD
        .species = SPECIES_MIENSHAO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_ACROBATICS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMOLGA_1] = { // Emolga-Physical
        .species = SPECIES_EMOLGA,
        .moves = {MOVE_ACROBATICS, MOVE_WILD_CHARGE, MOVE_U_TURN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FROST_1] = { // Rotom_Frost-Bulky
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZEBSTRIKA_1] = { // Zebstrika-Band
        .species = SPECIES_ZEBSTRIKA,
        .moves = {MOVE_VOLT_TACKLE, MOVE_DOUBLE_EDGE, MOVE_FLARE_BLITZ, MOVE_JUMP_KICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TANGROWTH_1] = { // Tangrowth-AV
        .species = SPECIES_TANGROWTH,
        .moves = {MOVE_GIGA_DRAIN, MOVE_KNOCK_OFF, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROSERADE_1] = { // Roserade-Defensive
        .species = SPECIES_ROSERADE,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_TOXIC_SPIKES, MOVE_SYNTHESIS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_MOW_1] = { // Rotom_Mow-Specs
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_1] = { // Zoroark-Specs
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TREVENANT_1] = { // Trevenant-TR
        .species = SPECIES_TREVENANT,
        .moves = {MOVE_WOOD_HAMMER, MOVE_REAPING_BLOW, MOVE_EARTHQUAKE, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLACEON_1] = { // Glaceon-Specs
        .species = SPECIES_GLACEON,
        .moves = {MOVE_FROST_BREATH, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL, MOVE_SYNCHRONOISE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_LEAFEON_1] = { // Leafeon-Band
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_RETURN, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPIRITOMB_1] = { // Spiritomb-NightShade
        .species = SPECIES_SPIRITOMB,
        .moves = {MOVE_WILL_O_WISP, MOVE_NIGHT_SHADE, MOVE_STRENGTH_SAP, MOVE_PARTING_SHOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GIGALITH_1] = { // Gigalith-Curse
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_STONE_EDGE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_1] = { // Lycanroc-Sub
        .species = SPECIES_LYCANROC,
        .moves = {MOVE_STONE_EDGE, MOVE_DRILL_RUN, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALLADE_1] = { // Gallade-BU
        .species = SPECIES_GALLADE,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_KNOCK_OFF, MOVE_BULK_UP, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAPION_1] = {// Drapion-SniperFellStinger
        .species = SPECIES_DRAPION,
        .moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_AGILITY, MOVE_FELL_STINGER},
        .heldItem = ITEM_LANSAT_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEWEAR_1] = { // Bewear-Band
        .species = SPECIES_BEWEAR,
        .moves = {MOVE_RETURN, MOVE_SUPERPOWER, MOVE_SHADOW_CLAW, MOVE_FACADE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_1] = { // Eelektross-SubCoil
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_COIL, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LOPUNNY_1] = { // Lopunny-NormalGemCovet
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_COVET, MOVE_STORM_THROW, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_NORMAL_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_1] = { // Reuniclus-TR
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEHEEYEM_1] = { // Beheeyem-CM
        .species = SPECIES_BEHEEYEM,
        .moves = {MOVE_PSYCHIC, MOVE_FLASH_CANNON, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_PSYCHIC_SEED,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_Z_1] = { // Porygon_Z-DualSetup
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_AGILITY, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOIVERN_1] = { // Noivern-LifeOrb
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HIPPOWDON_1] = { // Hippowdon-MixedWall
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_WHIRLWIND, MOVE_SLACK_OFF, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KROOKODILE_1] = { // Krookodile-Scarf
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_STONE_EDGE, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLURK_1] = { // Golurk-Band
        .species = SPECIES_GOLURK,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERROTHORN_1] = { // Ferrothorn-PowerWhip
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_POWER_WHIP, MOVE_INGRAIN, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLISOPOD_1] = { // Golisopod-LifeOrb
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAWITZER_1] = { // Clawitzer-Specs
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_1] = { // Ambipom-SilkScarf
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_SLAM, MOVE_LOW_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXICROAK_1] = { // Toxicroak-Tspikes
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_CIRCLE_THROW, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_RED_CARD,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANDELURE_1] = { // Chandelure-SubCM
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_1] = { // Togedemaru-OffensiveFigy
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_FAKE_OUT, MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_U_TURN},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DURANT_1] = { // Durant-Band
        .species = SPECIES_DURANT,
        .moves = {MOVE_IRON_HEAD, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GALVANTULA_1] = { // Galvantula-Sash
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_STICKY_WEB},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_1] = { // Lucario-SashNP
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_1] = { // Lycanroc_Midnight-ExBelt
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_STONE_EDGE, MOVE_PSYCHIC_FANGS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUDSDALE_1] = { // Mudsdale-Band
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_HEAVY_SLAM, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PALOSSAND_1] = { // Palossand-1attack
        .species = SPECIES_PALOSSAND,
        .moves = {MOVE_EARTH_POWER, MOVE_TOXIC, MOVE_SHORE_UP, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PYUKUMUKU_1] = { // Pyukumuku-InnardsOut
        .species = SPECIES_PYUKUMUKU,
        .moves = {MOVE_PAIN_SPLIT, MOVE_TAUNT, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TURTONATOR_1] = { // Turtonator-Draco
        .species = SPECIES_TURTONATOR,
        .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_DRACO_METEOR, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CONKELDURR_1] = { // Conkeldurr-SubPunch
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_DUSK_1] = { // Lycanroc_Dusk-SD
        .species = SPECIES_LYCANROC_DUSK,
        .moves = {MOVE_STONE_EDGE, MOVE_ACCELEROCK, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_1] = { // Excadrill-SD
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JELLICENT_1] = { // Jellicent-DefensiveTaunt
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_SCALD, MOVE_TAUNT, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_1] = { // Archeops-PhysicalRoost
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_ACROBATICS, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CINCCINO_1] = { // Cinccino-Band
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_ARM_THRUST, MOVE_ROCK_BLAST, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SERPERIOR_1] = { // Serperior-Specs
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TSAREENA_1] = { // Tsareena-3attacks
        .species = SPECIES_TSAREENA,
        .moves = {MOVE_TROP_KICK, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_1] = { // Blaziken-Special
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_EE_PROTECT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAXORUS_1] = { // Haxorus-SD
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TORTERRA_1] = { // Torterra-OffensiveSD
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_1] = { // Seismitoad-Defensive
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUXRAY_1] = { // Luxray-Scarf
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_1] = { // Darmanitan-BandRockSlide
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHESNAUGHT_1] = { // Chesnaught-Endure
        .species = SPECIES_CHESNAUGHT,
        .moves = {MOVE_ENDURE, MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SYLVEON_1] = { // Sylveon-BulkyHPground
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_HIDDEN_POWER, MOVE_WISH, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_BISHARP_1] = { // Bisharp-StealthRock
        .species = SPECIES_BISHARP,
        .moves = {MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_STEALTH_ROCK, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMPOLEON_1] = { // Empoleon-Defensive
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_STEALTH_ROCK, MOVE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_1] = { // Samurott-Modest
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANTRUM_1] = { // Tyrantrum-Scarf
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELPHOX_1] = { // Delphox-Defensive
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_MYSTICAL_FIRE, MOVE_WISH, MOVE_EE_PROTECT, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VANILLUXE_1] = { // Vanilluxe-Explosion
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_EXPLOSION},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DECIDUEYE_1] = { // Decidueye-NP
        .species = SPECIES_DECIDUEYE,
        .moves = {MOVE_SHADOW_BALL, MOVE_GIGA_DRAIN, MOVE_NASTY_PLOT, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_INFERNAPE_1] = { // Infernape-NP
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_FOCUS_BLAST, MOVE_INFERNO, MOVE_NASTY_PLOT, MOVE_VACUUM_WAVE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMBOAR_1] = { // Emboar-Scarf
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_HEAD_SMASH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_1] = { // Greninja-Mixed
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_GUNK_SHOT, MOVE_DARK_PULSE, MOVE_LOW_KICK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_1] = { // Salazzle-ToxicProtect
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FLAMETHROWER, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_SUBSTITUTE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMARINA_1] = { // Primarina-Specs
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_MOONBLAST, MOVE_SPARKLING_ARIA, MOVE_ICE_BEAM, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGALGE_1] = { // Dragalge-Tspikes
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_1] = { // Togekiss-NP
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_NASTY_PLOT, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARAQUANID_1] = { // Araquanid-Web
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_STICKY_WEB, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_1] = { // Toxapex-PhysDefWall
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_WASH_1] = { // Rotom_Wash-Scarf
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_1] = { // Rotom_Heat-Bulky
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_1] = { // Garchomp-FastTankChomp
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_DRAGON_TAIL, MOVE_TOXIC},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KOMMO_O_1] = { // Kommo_O-PoisonDD
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_OUTRAGE, MOVE_CLOSE_COMBAT, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIGIGAS_1] = { // Regigigas-Twave
        .species = SPECIES_REGIGIGAS,
        .moves = {MOVE_EARTHQUAKE, MOVE_CRUSH_GRIP, MOVE_KNOCK_OFF, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUGTRIO_2] = { // Dugtrio-HoneClaws
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_STONE_EDGE, MOVE_HONE_CLAWS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_2] = { // Medicham-SD
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISMAGIUS_2] = { // Mismagius-NP
        .species = SPECIES_MISMAGIUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_DAZZLING_GLEAM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_2] = { // Fearow-RoostSetup
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_FOCUS_ENERGY, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRANBULL_2] = { // Granbull-ExBelt
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_2] = { // Jynx-3attacksNP
        .species = SPECIES_JYNX,
        .moves = {MOVE_FROST_BREATH, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSKNOIR_2] = { // Dusknoir-SneakTR
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_TRICK_ROOM},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DODRIO_2] = { // Dodrio-Band
        .species = SPECIES_DODRIO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_RETURN, MOVE_JUMP_KICK, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_2] = { // Mr_Mime-NP
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYSHOCK, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_2] = { // Lanturn-Specs
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_DISCHARGE, MOVE_ICE_BEAM, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRELOOM_2] = { // Breloom-Technician
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_BULLET_SEED, MOVE_MACH_PUNCH, MOVE_ROCK_TOMB, MOVE_SPORE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FORRETRESS_2] = { // Forretress-TripleHazards
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_GYRO_BALL, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_2] = { // Whiscash-DDbounce
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_BOUNCE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_XATU_2] = { // Xatu-CMpass
        .species = SPECIES_XATU,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_ROOST, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SKARMORY_2] = { // Skarmory-SpikesStealthRock
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAROWAK_2] = { //  Marowak-4attacks
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE, MOVE_FIRE_PUNCH},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUAGSIRE_2] = { // Quagsire-CursePhysDef
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLEFABLE_2] = { // Clefable-Offensive
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_2] = { // Hariyama-AV
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM, MOVE_STONE_EDGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_2] = { // Raichu-FlailReversal
        .species = SPECIES_RAICHU,
        .moves = {MOVE_ENDURE, MOVE_FLAIL, MOVE_REVERSAL, MOVE_SECRET_POWER},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DEWGONG_2] = { // Dewgong-Hail3attacks
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICICLE_CRASH, MOVE_LIQUIDATION, MOVE_DRILL_RUN, MOVE_HAIL},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MANECTRIC_2] = { // Manectric-ExBelt
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLAMETHROWER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_2] = { // Vileplume-PhysDefWall
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_STRENGTH_SAP, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VICTREEBEL_2] = { // Victreebel-Sun
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRODE_3] = { // Electrode-ScreensVolt
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_VOLT_SWITCH, MOVE_TAUNT},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXPLOUD_2] = { // Exploud-Specs
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SHIFTRY_2] = { // Shiftry-Sun
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_SOLAR_BLADE, MOVE_KNOCK_OFF, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_2] = { // Glalie-Scarf
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_THUNDER_FANG, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUDICOLO_2] = { // Ludicolo-RainGigaDrain
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_2] = { // Hypno-NP
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_2] = { // Golem-Explosion
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_EXPLOSION, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYPERIOR_2] = { // Rhyperior-Band
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALAKAZAM_2] = { // Alakazam-4attacks
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_WEEZING_2] = { // Weezing-PhysDefWall
        .species = SPECIES_WEEZING,
        .moves = {MOVE_ACID, MOVE_WILL_O_WISP, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_2] = { // Kangaskhan-Crunch
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_2] = { // Electivire-ExBelt
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_2] = { // Tauros-Physical
        .species = SPECIES_TAUROS,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_2] = { // Slowbro-CM
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWKING_2] = { // Slowking-NP
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILTANK_2] = { // Miltank-Curse
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_HEAL_BELL, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALTARIA_2] = { // Altaria-DD
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_ROOST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_2] = { // Nidoqueen-4attacks
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_2] = { // Nidoking-ThunderFang
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGMORTAR_2] = { // Magmortar-Specs
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_CRADILY_2] = { // Cradily-BulkyAttacker
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_2] = { // Armaldo-LifeOrbSD
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLDUCK_2] = { // Golduck-4attacks
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_AQUA_JET},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAPIDASH_2] = { // Rapidash-ExBelt
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_JUMP_KICK, MOVE_WILD_CHARGE, MOVE_HIGH_HORSEPOWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUK_2] = { // Muk-Band
        .species = SPECIES_MUK,
        .moves = {MOVE_GUNK_SHOT, MOVE_SHADOW_SNEAK, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GENGAR_2] = { // Gengar-Scarf
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_2] = { // Ampharos-Leftovers
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_SIGNAL_BEAM, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCIZOR_2] = { // Scizor-BulkySD
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_QUICK_ATTACK, MOVE_ROOST, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_2] = { // Heracross-Reversal
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_REVERSAL, MOVE_KNOCK_OFF, MOVE_ENDURE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_URSARING_2] = { // Ursaring-Band
        .species = SPECIES_URSARING,
        .moves = {MOVE_RETURN, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HOUNDOOM_2] = { // Houndoom-NP
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_2] = { // Donphan-AV
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_BULLDOZE, MOVE_ROCK_TOMB, MOVE_ICE_SHARD, MOVE_FLAME_WHEEL},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLAYDOL_2] = { // Claydol-WP
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYSHOCK, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_2] = { // Wailord-MysticWater
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BOOMBURST},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_2] = { // Ninetales-FastCM
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_2] = { // Machamp-BU
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_BULK_UP, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUCKLE_2] = { // Shuckle-RestoBerry
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_2] = { // Steelix-RockHead
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_HEAD_SMASH, MOVE_COIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TENTACRUEL_2] = { // Tentacruel-Offensive
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AERODACTYL_2] = { // Aerodactyl-Band
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_STONE_EDGE, MOVE_ROCK_SLIDE, MOVE_FLY, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON2_2] = { // Porygon2-SpDefWall
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_RECOVER, MOVE_TOXIC, MOVE_ICE_BEAM},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARDEVOIR_2] = { // Gardevoir-Specs
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_2] = { // Exeggutor-WP
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STARMIE_2] = { // Starmie-LifeOrb
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FLYGON_2] = { // Flygon-QD
        .species = SPECIES_FLYGON,
        .moves = {MOVE_BOOMBURST, MOVE_DRAGON_PULSE, MOVE_ROOST, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_2] = { // Venusaur-Sun
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_VAPOREON_2] = { // Vaporeon-WishPass
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_WISH, MOVE_ACID_ARMOR, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JOLTEON_2] = { // Jolteon-Specs
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_SIGNAL_BEAM, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FLAREON_2] = { // Flareon-Agility
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_PLAY_ROUGH, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_2] = { // Meganium-SpDefWall
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_LEECH_SEED, MOVE_EE_PROTECT, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ESPEON_2] = { // Espeon-Specs
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_UMBREON_2] = { // Umbreon-SwagCat
        .species = SPECIES_UMBREON,
        .moves = {MOVE_FOUL_PLAY, MOVE_WISH, MOVE_SWAGGER, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_2] = { // Blastoise-BulkyAttacker
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_FLASH_CANNON, MOVE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_2] = { // Feraligatr-DD
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_LIQUIDATION, MOVE_ICE_FANG, MOVE_CRUNCH, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AGGRON_2] = { // Aggron-ThunderPunch
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAVY_SLAM, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_METAL_COAT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_2] = { // Incineroar-SD
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WALREIN_2] = { // Walrein-Bulky
        .species = SPECIES_WALREIN,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_HYDRO_PUMP, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_2] = { // Sceptile-SniperSash
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_2] = { // Charizard-SunnyDay
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_FOCUS_BLAST, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYPHLOSION_2] = { // Typhlosion-Scarf
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_BLAST_OFF, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_2] = { // Lapras-Specs
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CROBAT_2] = { // Crobat-StallBreaker
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SUPER_FANG, MOVE_TAUNT, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SWAMPERT_2] = { // Swampert-Band
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_DIVE, MOVE_ICE_PUNCH, MOVE_HAMMER_ARM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_2] = { // Gyarados-ScarfMoxie
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SNORLAX_2] = { // Snorlax-Band
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SELF_DESTRUCT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGDRA_2] = { // Kingdra-CritdraFlashCannon
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_FLASH_CANNON, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANSEY_2] = { // Chansey-MixedWall
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_SEISMIC_TOSS, MOVE_SOFT_BOILED},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MILOTIC_2] = { // Milotic-Defensive
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_DRAGON_TAIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_2] = { // Arcanine-Offensive
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_EXTREME_SPEED, MOVE_MORNING_SUN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_2] = { // Salamence-Specs
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_AEROBLAST, MOVE_DRAGON_PULSE, MOVE_BLAST_OFF, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_2] = { // Metagross-Agility
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_AGILITY},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SLAKING_2] = { // Slaking-BulkyAttacker
        .species = SPECIES_SLAKING,
        .moves = {MOVE_RETURN, MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLISCOR_2] = { // Gliscor-SD
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_FACADE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAWLUCHA_2] = { // Hawlucha-StoneEdge
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ACROBATICS, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEAVILE_2] = { // Weavile-SD
        .species = SPECIES_WEAVILE,
        .moves = {MOVE_KNOCK_OFF, MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TALONFLAME_2] = { // Talonflame-2attackSD
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_ACROBATICS, MOVE_FLARE_BLITZ, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_2] = { // Scolipede-SashSD
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FROSLASS_2] = { // Froslass-Hail
        .species = SPECIES_FROSLASS,
        .moves = {MOVE_HAIL, MOVE_FROST_BREATH, MOVE_SHADOW_BALL, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AEGISLASH_2] = { // Aegislash-SD
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SWORDS_DANCE, MOVE_KINGS_SHIELD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOUCANNON_2] = { // Toucannon-SheerForce
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BOOMBURST, MOVE_BRAVE_BIRD, MOVE_HEAT_WAVE, MOVE_FLASH_CANNON},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_RASH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MIMIKYU_2] = { // Mimikyu-LifeOrbSD
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_FAN_2] = { // Rotom_Fan-Scarf
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_HYPER_VOICE, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PANGORO_2] = { // Pangoro-LifeOrbSD
        .species = SPECIES_PANGORO,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIKAVOLT_2] = { // Vikavolt-ShellBell
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_ROOST},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAMOSWINE_2] = { // Mamoswine-LifeOrb
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_ICICLE_CRASH, MOVE_STONE_EDGE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HONCHKROW_2] = { // Honchkrow-Scarf
        .species = SPECIES_HONCHKROW,
        .moves = {MOVE_BRAVE_BIRD, MOVE_NIGHT_SLASH, MOVE_SUPERPOWER, MOVE_DRILL_PECK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARAPTOR_2] = { // Staraptor-Scarf
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAMPARDOS_2] = { // Rampardos-Reckless
        .species = SPECIES_RAMPARDOS,
        .moves = {MOVE_HEAD_SMASH, MOVE_AVALANCHE, MOVE_HAMMER_ARM, MOVE_ACROBATICS},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GASTRODON_2] = { // Gastrodon-Defensive
        .species = SPECIES_GASTRODON,
        .moves = {MOVE_SCALD, MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AURORUS_2] = { // Aurorus-LightClay
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_AURORA_VEIL},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIENSHAO_2] = { // Mienshao-Scarf
        .species = SPECIES_MIENSHAO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMOLGA_2] = { // Emolga-Special
        .species = SPECIES_EMOLGA,
        .moves = {MOVE_TAILWIND, MOVE_AIR_SLASH, MOVE_VOLT_SWITCH, MOVE_ENCORE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FROST_2] = { // Rotom_Frost-Scarf
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ZEBSTRIKA_2] = { // Zebstrika-LifeOrb
        .species = SPECIES_ZEBSTRIKA,
        .moves = {MOVE_VOLT_TACKLE, MOVE_DOUBLE_EDGE, MOVE_FLARE_BLITZ, MOVE_JUMP_KICK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TANGROWTH_2] = { // Tangrowth-PhysDefWall
        .species = SPECIES_TANGROWTH,
        .moves = {MOVE_GIGA_DRAIN, MOVE_KNOCK_OFF, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROSERADE_2] = { // Roserade-Offensive
        .species = SPECIES_ROSERADE,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_LEAF_STORM, MOVE_ACID, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_MOW_2] = { // Rotom_Mow-Scarf
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_2] = { // Zoroark-NP
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TREVENANT_2] = { // Trevenant-Band
        .species = SPECIES_TREVENANT,
        .moves = {MOVE_WOOD_HAMMER, MOVE_REAPING_BLOW, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLACEON_2] = { // Glaceon-Hail
        .species = SPECIES_GLACEON,
        .moves = {MOVE_BLIZZARD, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL, MOVE_HAIL},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_LEAFEON_2] = { // Leafeon-SD
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_RETURN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_YACHE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPIRITOMB_2] = { // Spiritomb-Curse
        .species = SPECIES_SPIRITOMB,
        .moves = {MOVE_WILL_O_WISP, MOVE_CURSE, MOVE_STRENGTH_SAP, MOVE_PARTING_SHOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GIGALITH_2] = { // Gigalith-Bulky
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_2] = { // Lycanroc-Accelerock
        .species = SPECIES_LYCANROC,
        .moves = {MOVE_STONE_EDGE, MOVE_DRILL_RUN, MOVE_ACCELEROCK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALLADE_2] = { // Gallade-LifeOrbSD
        .species = SPECIES_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAPION_2] = { // Drapion-SniperSubstitute
        .species = SPECIES_DRAPION,
        .moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_AGILITY, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LANSAT_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEWEAR_2] = { // Bewear-SD
        .species = SPECIES_BEWEAR,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_DRAIN_PUNCH, MOVE_SHADOW_CLAW, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_2] = { // Eelektross-ExBelt
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_THUNDERBOLT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FLAMETHROWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LOPUNNY_2] = { // Lopunny-SilkScarfBrutalSwing
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_STORM_THROW, MOVE_BRUTAL_SWING},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_2] = { // Reuniclus-CM
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEHEEYEM_2] = { // Beheeyem-TR
        .species = SPECIES_BEHEEYEM,
        .moves = {MOVE_PSYCHIC, MOVE_FLASH_CANNON, MOVE_SIGNAL_BEAM, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_Z_2] = { // Porygon_Z-Specs
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOIVERN_2] = { // Noivern-Specs
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HIPPOWDON_2] = { // Hippowdon-PhysDefWall
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_SLACK_OFF, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KROOKODILE_2] = { // Krookodile-Band
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_STONE_EDGE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLURK_2] = { // Golurk-ExBelt
        .species = SPECIES_GOLURK,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERROTHORN_2] = { // Ferrothorn-SpikesLeech
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLISOPOD_2] = { // Golisopod-SilverPowder
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_SILVER_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAWITZER_2] = { // Clawitzer-ExBelt
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_2] = { // Ambipom-NormalGem
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_COVET, MOVE_LOW_KICK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_NORMAL_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXICROAK_2] = { // Toxicroak-SD
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANDELURE_2] = { // Chandelure-Specs
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_2] = { // Togedemaru-BandZenHeadbutt
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DURANT_2] = { // Durant-LifeOrb
        .species = SPECIES_DURANT,
        .moves = {MOVE_BUG_BITE, MOVE_THUNDER_FANG, MOVE_ICE_FANG, MOVE_SUPERPOWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALVANTULA_2] = { // Galvantula-LifeOrbGigaDrain
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN, MOVE_STICKY_WEB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_2] = { // Lucario-CrunchSD
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_2] = { // Lycanroc_Midnight-WP
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_POWER_TRIP, MOVE_DRAIN_PUNCH, MOVE_BULK_UP, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUDSDALE_2] = { // Mudsdale-Defensive
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PALOSSAND_2] = { // Palossand-2attack
        .species = SPECIES_PALOSSAND,
        .moves = {MOVE_EARTH_POWER, MOVE_SHADOW_BALL, MOVE_SHORE_UP, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PYUKUMUKU_2] = { // Pyukumuku-PPstall
        .species = SPECIES_PYUKUMUKU,
        .moves = {MOVE_BLOCK, MOVE_RECOVER, MOVE_SPITE, MOVE_TAUNT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TURTONATOR_2] = { // Turtonator-Focus
        .species = SPECIES_TURTONATOR,
        .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_FOCUS_BLAST, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CONKELDURR_2] = { // Conkeldurr-SheerForce
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_DUSK_2] = { // Lycanroc_Dusk-4attacks
        .species = SPECIES_LYCANROC_DUSK,
        .moves = {MOVE_STONE_EDGE, MOVE_ACCELEROCK, MOVE_DRILL_RUN, MOVE_FIRE_FANG},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_2] = { // Excadrill-SandLifeOrb
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JELLICENT_2] = { // Jellicent-DefensiveHex
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_SCALD, MOVE_HEX, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_2] = { // Archeops-Mixed
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_EARTH_POWER, MOVE_HEAT_WAVE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CINCCINO_2] = { // Cinccino-KingsRock
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_ARM_THRUST, MOVE_ROCK_BLAST, MOVE_BULLET_SEED},
        .heldItem = ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SERPERIOR_2] = { // Serperior-GlareSeed
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_GLARE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_TSAREENA_2] = { // Tsareena-Band
        .species = SPECIES_TSAREENA,
        .moves = {MOVE_TROP_KICK, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_2] = { // Blaziken-Scarf
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_BLAST_OFF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAXORUS_2] = { // Haxorus-PoisonDD
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TORTERRA_2] = { // Torterra-RockPolish
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_ROCK_SLIDE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_2] = { // Seismitoad-Physical
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUXRAY_2] = { // Luxray-FastExBelt
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_2] = { // Darmanitan-Scarf
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHESNAUGHT_2] = { // Chesnaught-Spiky
        .species = SPECIES_CHESNAUGHT,
        .moves = {MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SYLVEON_2] = { // Sylveon-Specs
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_BISHARP_2] = { // Bisharp-SD
        .species = SPECIES_BISHARP,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_IRON_HEAD, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMPOLEON_2] = { // Empoleon-LifeOrb
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GRASS_KNOT, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_2] = { // Samurott-Adamant
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_LIQUIDATION, MOVE_SACRED_SWORD, MOVE_KNOCK_OFF, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANTRUM_2] = { // Tyrantrum-DD
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELPHOX_2] = { // Delphox-CM
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_GRASS_KNOT, MOVE_CALM_MIND},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VANILLUXE_2] = { // Vanilluxe-HPfireHasty
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_HASTY,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_DECIDUEYE_2] = { // Decidueye-Sniper
        .species = SPECIES_DECIDUEYE,
        .moves = {MOVE_LEAF_BLADE, MOVE_SPIRIT_SHACKLE, MOVE_SHADOW_SNEAK, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_INFERNAPE_2] = { // Infernape-ExBelt
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_INFERNO, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMBOAR_2] = { // Emboar-ExBelt
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_2] = { // Greninja-ExBelt
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_GRASS_KNOT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_2] = { // Salazzle-NP
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_PRIMARINA_2] = { // Primarina-ExBelt
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_MOONBLAST, MOVE_SPARKLING_ARIA, MOVE_ICE_BEAM, MOVE_ENERGY_BALL},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGALGE_2] = { // Dragalge-Specs
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SLUDGE_WAVE, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_2] = { // Togekiss-Twave
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_THUNDER_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARAQUANID_2] = { // Araquanid-Curse
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_2] = { // Toxapex-SpDefWall
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_WASH_2] = { // Rotom_Wash-BulkyLeftovers
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_2] = { // Rotom_Heat-Specs
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_2] = { // Garchomp-Scarf
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KOMMO_O_2] = { // Kommo_O-BD
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_THUNDER_PUNCH, MOVE_BELLY_DRUM, MOVE_SUBSTITUTE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIGIGAS_2] = { // Regigigas-PUP
        .species = SPECIES_REGIGIGAS,
        .moves = {MOVE_EARTHQUAKE, MOVE_CRUSH_GRIP, MOVE_KNOCK_OFF, MOVE_POWER_UP_PUNCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_1] = { // Cobalion-Bulky
        .species = SPECIES_COBALION,
        .moves = {MOVE_SACRED_SWORD, MOVE_STEALTH_ROCK, MOVE_THUNDER_WAVE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_1] = { // Terrakion-ExBelt
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_X_SCISSOR},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_1] = { // Virizion-ExBelt
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_1] = { // Raikou-Scarf
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_1] = { // Entei-Curse
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_1] = { // Suicune-RestTalk
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ROAR, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_1] = { // Regirock-PUP
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_POWER_UP_PUNCH, MOVE_RECOVER},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_1] = { // Regice-SpDefWallHaze
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_HAZE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_1] = { // Registeel-PhysDefRestTalk
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_TOXIC, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_1] = { // Latias-DualScreens
        .species = SPECIES_LATIAS,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_DRACO_METEOR, MOVE_HEALING_WISH},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_1] = { // Latios-DualScreens
        .species = SPECIES_LATIOS,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_DRACO_METEOR, MOVE_MEMENTO},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_2] = { // Cobalion-Band
        .species = SPECIES_COBALION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_2] = { // Terrakion-Scarf
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_2] = { // Virizion-Band
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_2] = { // Raikou-RestoBerry
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_2] = { // Entei-Charcoal
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLAME_CHARGE, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_CHARCOAL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_2] = { // Suicune-AV
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_MIRROR_COAT, MOVE_SHEER_COLD},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_2] = { // Regirock-Twave
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_THUNDER_WAVE, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_2] = { // Regice-ZoomLens
        .species = SPECIES_REGICE,
        .moves = {MOVE_BLIZZARD, MOVE_THUNDER, MOVE_FOCUS_BLAST, MOVE_RECOVER},
        .heldItem = ITEM_ZOOM_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_2] = { // Registeel-PhysDefWall
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_2] = { // Latias-SubRoost
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRAGON_PULSE, MOVE_SUBSTITUTE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_2] = { // Latios-4attacks
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_3] = { // Cobalion-3attacksCM
        .species = SPECIES_COBALION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 25,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_3] = { // Terrakion-DualSetup
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_ROCK_POLISH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_3] = { // Virizion-3attacksCM
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_ENERGY_BALL, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_3] = { // Raikou-AV
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_3] = { // Entei-FastAV
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLAME_CHARGE, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_3] = { // Suicune-SubCM
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_3] = { // Regirock-ExplosionWP
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_3] = { // Regice-ShellBell
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_3] = { // Registeel-RestoBerry
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_3] = { // Latias-Scarf
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_3] = { // Latios-DragonGem
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_DRAGON_GEM,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_4] = { // Cobalion-SubCM
        .species = SPECIES_COBALION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_4] = { // Terrakion-Band
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_4] = { // Virizion-SubCM
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_4] = { // Raikou-3attacksCM
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_4] = { // Entei-JollyBand
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_4] = { // Suicune-3attacksCM
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_4] = { // Regirock-Bulky
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAIN_PUNCH, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_4] = { // Regice-SpDefWallThunderbolt
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_4] = { // Registeel-SpDefRestTalk
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_TOXIC, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_4] = { // Latias-1attackCM
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_CHARM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_4] = { // Latios-Scarf
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_GENGAR_3] = { // Gengar-Hex
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEX, MOVE_FOCUS_BLAST, MOVE_WILL_O_WISP},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANDELURE_3] = { // Chandelure-TR
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GENGAR_4] = { // Gengar-Specs
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANDELURE_4] = { // Chandelure-Scarf
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_3] = { // Ursaring-Guts
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_3] = { // Lucario-LifeOrbNP
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_4] = { // Ursaring-QuickFeet
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUCARIO_4] = { // Lucario-MeteorMashSD
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MACHAMP_3] = { // Machamp-Band
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CONKELDURR_3] = { // Conkeldurr-GutsPoisonJab
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_POISON_JAB},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MACHAMP_4] = { // Machamp-AV
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CONKELDURR_4] = { // Conkeldurr-AV
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_POISON_JAB},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARDEVOIR_3] = { // Gardevoir-BulkyCM
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_DRAINING_KISS, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SERPERIOR_3] = { // Serperior-3attacks
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_DRAGON_PULSE, MOVE_GLARE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_GARDEVOIR_4] = { // Gardevoir-Scarf
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYSHOCK, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SERPERIOR_4] = { // Serperior-SubSeed
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_SUBSTITUTE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 25,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_3] = { // Starmie-Specs
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_3] = { // Blaziken-SashSD
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_BLAZE_KICK, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_4] = { // Starmie-ExBelt
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_4] = { // Blaziken-LifeOrbSD
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_FLARE_BLITZ, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_3] = { // Lapras-OHKO
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_3] = { // Greninja-SpecialSash
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_4] = { // Lapras-OffensiveCM
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_4] = { // Greninja-SpecialLifeOrb
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_SNORLAX_3] = { // Snorlax-RestTalk
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TOGEKISS_3] = { // Togekiss-Scarf
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_DAZZLING_GLEAM, MOVE_FLAMETHROWER, MOVE_AURA_SPHERE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNORLAX_4] = { // Snorlax-Earthquake
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_EARTHQUAKE, MOVE_RECYCLE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_4] = { // Togekiss-TwaveNP
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_NASTY_PLOT, MOVE_THUNDER_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SALAMENCE_3] = { // Salamence-DD
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FLY, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GARCHOMP_3] = { // Garchomp-LifeOrbSD
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAMENCE_4] = { // Salamence-3attacksRoost
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_AEROBLAST, MOVE_FIRE_BLAST, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_4] = { // Garchomp-LumSD
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_METAGROSS_3] = { // Metagross-Band
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KOMMO_O_3] = { // Kommo_O-Special
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_CLANGING_SCALES, MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_4] = { // Metagross-ThunderPunchAV
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KOMMO_O_4] = { // Kommo_O-SpecialScarf
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_CLANGING_SCALES, MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_5] = { // Regirock-StealthRock
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STEALTH_ROCK, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_6] = { // Regirock-DrainPunchWP
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_5] = { // Regice-Bulky
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_6] = { // Regice-ExBelt
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_5] = { // Registeel-SpDefWall
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_6] = { // Registeel-Curse
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_5] = { // Latias-BoltBeamCM
        .species = SPECIES_LATIAS,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_6] = { // Latias-Specs
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_7] = { // Latias-3attacksRoost
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_8] = { // Latias-StabCM
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_5] = { // Latios-2attacksCM
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_6] = { // Latios-3attacksCM
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_7] = { // Latios-Specs
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_8] = { // Latios-3attacksRoost
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_1] = { // Dragonite-Rain
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HURRICANE, MOVE_THUNDER, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_2] = { // Goodra-Scarf
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_3] = { // Dragonite-BulkyDD
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_FLY, MOVE_DRAGON_DANCE, MOVE_SUBSTITUTE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_4] = { // Goodra-Band
        .species = SPECIES_GOODRA,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POWER_WHIP, MOVE_IRON_TAIL},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_5] = { // Dragonite-Specs
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_6] = { // Goodra-Specs
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_7] = { // Volcarona-LifeOrbHPground
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_HIDDEN_POWER, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_8] = { // Volcarona-SashHPground
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_BUG_BUZZ, MOVE_HIDDEN_POWER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_9] = { // Dragonite-OffensiveDD
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_FLY, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_10] = { // Goodra-AV
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRAGON_PULSE, MOVE_FLAMETHROWER, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_1] = { // Tyranitar-Band
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_2] = { // Hydreigon-Specs
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_3] = { // Tyranitar-Curse
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_REST, MOVE_CURSE},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_4] = { // Hydreigon-4attacks
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_5] = { // Tyranitar-BulkyDD
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_DRAGON_DANCE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_6] = { // Hydreigon-3attacksRoost
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_7] = { // Volcarona-Bulky
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_ROOST, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_8] = { // Volcarona-LifeOrbBugBuzz
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_9] = { // Tyranitar-OffensiveDD
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_10] = { // Hydreigon-Scarf
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRAGON_PULSE, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_5] = { // Cobalion-SD
        .species = SPECIES_COBALION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARTICUNO_6] = { // Keldeo-Specs
        .species = SPECIES_KELDEO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_HYDRO_PUMP, MOVE_SECRET_SWORD, MOVE_SCALD},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_5] = { // Terrakion-SD
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZAPDOS_6] = { // Keldeo-SubCM
        .species = SPECIES_KELDEO,
        .moves = {MOVE_SCALD, MOVE_SECRET_SWORD, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_5] = { // Virizion-SD
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LEAF_BLADE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MOLTRES_6] = { // Keldeo-3attacksCM
        .species = SPECIES_KELDEO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_HYDRO_PUMP, MOVE_SECRET_SWORD, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_5] = { // Raikou-Specs
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_6] = { // Raikou-SubCM
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_5] = { // Entei-BulkyAV
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_EXTREME_SPEED, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_6] = { // Entei-AdamantBand
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_5] = { // Suicune-RestoBerry
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_6] = { // Suicune-CroCune
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_CALM_MIND, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    }
};
