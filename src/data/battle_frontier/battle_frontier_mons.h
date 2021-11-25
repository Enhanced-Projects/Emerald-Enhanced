const struct FacilityMon gBattleFrontierMons[NUM_FRONTIER_MONS] =
{
    [FRONTIER_MON_IVYSAUR] = { // Ivysaur-Sun (ID: 0)
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PIKACHU] = { // Pikachu-Physical (ID: 1)
        .species = SPECIES_PIKACHU,
        .moves = {MOVE_VOLT_TACKLE, MOVE_EXTREME_SPEED, MOVE_FLY, MOVE_SECRET_POWER},
        .heldItem = ITEM_LIGHT_BALL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLEFAIRY] = { // Clefairy-CM (ID: 2)
        .species = SPECIES_CLEFAIRY,
        .moves = {MOVE_MOONBLAST, MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLBAT] = { // Golbat-StallBreaker (ID: 3)
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_POISON_FANG, MOVE_SUPER_FANG, MOVE_TAUNT, MOVE_ROOST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLOOM] = { // Gloom-Defensive (ID: 4)
        .species = SPECIES_GLOOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_SLEEP_POWDER, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KADABRA] = { // Kadabra-Offensive (ID: 5)
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_SIGNAL_BEAM, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 2
    },
    [FRONTIER_MON_MACHOKE] = { // Machoke-Guts (ID: 6)
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WEEPINBELL] = { // Weepinbell-Sun (ID: 7)
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNETON] = { // Magneton-Specs (ID: 8)
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_MIRROR_SHOT, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HAUNTER] = { // Haunter-Scarf (ID: 9)
        .species = SPECIES_HAUNTER,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_SHADOW_BALL, MOVE_DAZZLING_GLEAM, MOVE_ENERGY_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TANGELA] = { // Tangela-Offensive (ID: 10)
        .species = SPECIES_TANGELA,
        .moves = {MOVE_LEAF_STORM, MOVE_GIGA_DRAIN, MOVE_ANCIENT_POWER, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ELECTABUZZ] = { // Electabuzz-ExBelt (ID: 11)
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGMAR] = { // Magmar-Specs (ID: 12)
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_PSYCHIC, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_BAYLEEF] = { // Bayleef-Defensive (ID: 13)
        .species = SPECIES_BAYLEEF,
        .moves = {MOVE_MOONBLAST, MOVE_LEECH_SEED, MOVE_EE_PROTECT, MOVE_WISH},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUILAVA] = { // Quilava-Scarf (ID: 14)
        .species = SPECIES_QUILAVA,
        .moves = {MOVE_ERUPTION, MOVE_BLAST_OFF, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CROCONAW] = { // Croconaw-DD (ID: 15)
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGETIC] = { // Togetic-NP (ID: 16)
        .species = SPECIES_TOGETIC,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_FLAMETHROWER, MOVE_NASTY_PLOT, MOVE_ROOST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MARILL] = { // Marill-4attacks (ID: 17)
        .species = SPECIES_MARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_DIVE, MOVE_SUPERPOWER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MURKROW] = { // Murkrow-Mixed (ID: 18)
        .species = SPECIES_MURKROW,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SUCKER_PUNCH, MOVE_HEAT_WAVE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_SNEASEL] = { // Sneasel-Band (ID: 19)
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_KNOCK_OFF, MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_IRON_TAIL},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PILOSWINE] = { // Piloswine-StealthRock (ID: 20)
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_AVALANCHE, MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_COMBUSKEN] = { // Combusken-Special (ID: 21)
        .species = SPECIES_COMBUSKEN,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_EE_PROTECT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MARSHTOMP] = { // Marshtomp-Defensive (ID: 22)
        .species = SPECIES_MARSHTOMP,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_YAWN},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WINGULL] = { // Wingull-Sash (ID: 23)
        .species = SPECIES_WINGULL,
        .moves = {MOVE_HURRICANE, MOVE_SCALD, MOVE_BLIZZARD, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_VIBRAVA] = { // Vibrava-QD (ID: 24)
        .species = SPECIES_VIBRAVA,
        .moves = {MOVE_BOOMBURST, MOVE_DRAGON_PULSE, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEALEO] = { // Sealeo-Defensive (ID: 25)
        .species = SPECIES_SEALEO,
        .moves = {MOVE_FROST_BREATH, MOVE_SHEER_COLD, MOVE_TOXIC, MOVE_SLACK_OFF},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUSCLOPS] = { // Dusclops-CM (ID: 26)
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_HEX, MOVE_WILL_O_WISP, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROSELIA] = { // Roselia-Offensive (ID: 27)
        .species = SPECIES_ROSELIA,
        .moves = {MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LAIRON] = { // Lairon-StealthRock (ID: 28)
        .species = SPECIES_LAIRON,
        .moves = {MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LILEEP] = { // Lileep-Defensive (ID: 29)
        .species = SPECIES_LILEEP,
        .moves = {MOVE_EARTH_POWER, MOVE_TOXIC, MOVE_STEALTH_ROCK, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ANORITH] = { // Anorith-SD (ID: 30)
        .species = SPECIES_ANORITH,
        .moves = {MOVE_LEECH_LIFE, MOVE_DIVE, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHELGON] = { // Shelgon-RestTalk (ID: 31)
        .species = SPECIES_SHELGON,
        .moves = {MOVE_OUTRAGE, MOVE_DRAGON_DANCE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_METANG] = { // Metang-Offensive (ID: 32)
        .species = SPECIES_METANG,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MONFERNO] = { // Monferno-Mixed (ID: 33)
        .species = SPECIES_MONFERNO,
        .moves = {MOVE_INFERNO, MOVE_DYNAMIC_PUNCH, MOVE_GUNK_SHOT, MOVE_GRASS_KNOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRINPLUP] = { // Prinplup-Defensive (ID: 34)
        .species = SPECIES_PRINPLUP,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TOXIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STARAVIA] = { // Staravia-Scarf (ID: 35)
        .species = SPECIES_STARAVIA,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_FINAL_GAMBIT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUXIO] = { // Luxio-4attacks (ID: 36)
        .species = SPECIES_LUXIO,
        .moves = {MOVE_CRUNCH, MOVE_THUNDER_FANG, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRANIDOS] = { // Cranidos-LifeOrb (ID: 37)
        .species = SPECIES_CRANIDOS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_FIRE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SHIELDON] = { // Shieldon-Spikes (ID: 38)
        .species = SPECIES_SHIELDON,
        .moves = {MOVE_TOXIC, MOVE_SPIKES, MOVE_KINGS_SHIELD, MOVE_SHORE_UP},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GABITE] = { // Gabite-StealthRock (ID: 39)
        .species = SPECIES_GABITE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_FIRE_FANG, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MUNCHLAX] = { // Munchlax-RestTalk (ID: 40)
        .species = SPECIES_MUNCHLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RIOLU] = { // Riolu-Copycat (ID: 41)
        .species = SPECIES_RIOLU,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_COPYCAT, MOVE_SWORDS_DANCE, MOVE_EE_PROTECT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HIPPOPOTAS] = { // Hippopotas-Defensive (ID: 42)
        .species = SPECIES_HIPPOPOTAS,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_WHIRLWIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SERVINE] = { // Servine-Glare (ID: 43)
        .species = SPECIES_SERVINE,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_ACID, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 25,
        .ability = 2
    },
    [FRONTIER_MON_GURDURR] = { // Gurdurr-BU (ID: 44)
        .species = SPECIES_GURDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_BULK_UP},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PALPITOAD] = { // Palpitoad-Rain (ID: 45)
        .species = SPECIES_PALPITOAD,
        .moves = {MOVE_HYDRO_PUMP, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB, MOVE_RAIN_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIRLIPEDE] = { // Whirlipede-DualHazards (ID: 46)
        .species = SPECIES_WHIRLIPEDE,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_ENDEAVOR, MOVE_EE_PROTECT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KROKOROK] = { // Krokorok-Scarf (ID: 47)
        .species = SPECIES_KROKOROK,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_FIRE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEN] = { // Archen-Mixed (ID: 48)
        .species = SPECIES_ARCHEN,
        .moves = {MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_EARTH_POWER, MOVE_HEAT_WAVE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUOSION] = { // Duosion-CM (ID: 49)
        .species = SPECIES_DUOSION,
        .moves = {MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_ACID_ARMOR, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FERROSEED] = { // Ferroseed-Spikes (ID: 50)
        .species = SPECIES_FERROSEED,
        .moves = {MOVE_GYRO_BALL, MOVE_LEECH_SEED, MOVE_SPIKES, MOVE_EE_PROTECT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EELEKTRIK] = { // Eelektrik-Bulky (ID: 51)
        .species = SPECIES_EELEKTRIK,
        .moves = {MOVE_DIVE, MOVE_DISCHARGE, MOVE_ICE_BEAM, MOVE_KNOCK_OFF},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LAMPENT] = { // Lampent-Scarf (ID: 52)
        .species = SPECIES_LAMPENT,
        .moves = {MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FRAXURE] = { // Fraxure-DD (ID: 53)
        .species = SPECIES_FRAXURE,
        .moves = {MOVE_OUTRAGE, MOVE_SUPERPOWER, MOVE_IRON_TAIL, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIENFOO] = { // Mienfoo-Scarf (ID: 54)
        .species = SPECIES_MIENFOO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PAWNIARD] = { // Pawniard-SD (ID: 55)
        .species = SPECIES_PAWNIARD,
        .moves = {MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RUFFLET] = { // Rufflet-BU (ID: 56)
        .species = SPECIES_RUFFLET,
        .moves = {MOVE_AERIAL_ACE, MOVE_BULK_UP, MOVE_AGILITY, MOVE_ROOST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZWEILOUS] = { // Zweilous-Band (ID: 57)
        .species = SPECIES_ZWEILOUS,
        .moves = {MOVE_OUTRAGE, MOVE_CRUNCH, MOVE_SUPERPOWER, MOVE_HEAD_SMASH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QUILLADIN] = { // Quilladin-Spikes (ID: 58)
        .species = SPECIES_QUILLADIN,
        .moves = {MOVE_WOOD_HAMMER, MOVE_SPIKES, MOVE_ROAR, MOVE_SYNTHESIS},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FROGADIER] = { // Frogadier-Acrobatics (ID: 59)
        .species = SPECIES_FROGADIER,
        .moves = {MOVE_ACROBATICS, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_U_TURN},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FLETCHINDER] = { // Fletchinder-1attack (ID: 60)
        .species = SPECIES_FLETCHINDER,
        .moves = {MOVE_ACROBATICS, MOVE_WILL_O_WISP, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYRUNT] = { // Tyrunt-DD (ID: 61)
        .species = SPECIES_TYRUNT,
        .moves = {MOVE_OUTRAGE, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLIGGOO] = { // Sliggoo-Curse (ID: 62)
        .species = SPECIES_SLIGGOO,
        .moves = {MOVE_OUTRAGE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PUMPKABOO] = { // Pumpkaboo-Defensive (ID: 63)
        .species = SPECIES_PUMPKABOO,
        .moves = {MOVE_SHADOW_BALL, MOVE_LEECH_SEED, MOVE_WILL_O_WISP, MOVE_SYNTHESIS},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DARTRIX] = { // Dartrix-SD (ID: 64)
        .species = SPECIES_DARTRIX,
        .moves = {MOVE_BRAVE_BIRD, MOVE_LEAF_BLADE, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TORRACAT] = { // Torracat-Scarf (ID: 65)
        .species = SPECIES_TORRACAT,
        .moves = {MOVE_FLARE_BLITZ, MOVE_OUTRAGE, MOVE_SECRET_POWER, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_TRUMBEAK] = { // Trumbeak-Scarf (ID: 66)
        .species = SPECIES_TRUMBEAK,
        .moves = {MOVE_BRAVE_BIRD, MOVE_BULLET_SEED, MOVE_ROCK_BLAST, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CRABRAWLER] = { // Crabrawler-Scarf (ID: 67)
        .species = SPECIES_CRABRAWLER,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_EARTHQUAKE, MOVE_CRABHAMMER, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAREANIE] = { // Mareanie-Defensive (ID: 68)
        .species = SPECIES_MAREANIE,
        .moves = {MOVE_SCALD, MOVE_TOXIC, MOVE_HAZE, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MUDBRAY] = { // Mudbray-Band (ID: 69)
        .species = SPECIES_MUDBRAY,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CLOSE_COMBAT, MOVE_HEAVY_SLAM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DEWPIDER] = { // Dewpider-Web (ID: 70)
        .species = SPECIES_DEWPIDER,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_STICKY_WEB, MOVE_TOXIC},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HAKAMO_O] = { // Hakamo_o-DD (ID: 71)
        .species = SPECIES_HAKAMO_O,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_DRAGON_CLAW, MOVE_IRON_HEAD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUNSPARCE] = { // Dunsparce-ParaFlinch (ID: 72)
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_HEADBUTT, MOVE_GLARE, MOVE_COIL, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CORSOLA] = { // Corsola-Band (ID: 73)
        .species = SPECIES_CORSOLA,
        .moves = {MOVE_HEAD_SMASH, MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DELIBIRD] = { // Delibird-Band (ID: 74)
        .species = SPECIES_DELIBIRD,
        .moves = {MOVE_PRESENT, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SPINDA] = { // Spinda-Contrary (ID: 75)
        .species = SPECIES_SPINDA,
        .moves = {MOVE_PSYCHO_BOOST, MOVE_TRICK_ROOM, MOVE_HIDDEN_POWER, MOVE_BATON_PASS},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 27,
        .ability = 2
    },
    [FRONTIER_MON_LUVDISC] = { // Luvdisc-Rain (ID: 76)
        .species = SPECIES_LUVDISC,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_FARFETCHD] = { // Farfetchd-SD (ID: 77)
        .species = SPECIES_FARFETCHD,
        .moves = {MOVE_ACROBATICS, MOVE_LEAF_BLADE, MOVE_SECRET_POWER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_SMEARGLE] = { // Smeargle-SmashPass (ID: 78)
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_SPORE, MOVE_SHELL_SMASH, MOVE_POWER_TRIP, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DITTO] = { // Ditto-Scarf (ID: 79)
        .species = SPECIES_DITTO,
        .moves = {MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_UNOWN] = { // Unown-StoredPower (ID: 80)
        .species = SPECIES_UNOWN,
        .moves = {MOVE_COSMIC_POWER, MOVE_MOONLIGHT, MOVE_STORED_POWER, MOVE_DAZZLING_GLEAM},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BUTTERFREE_1] = { // Butterfree-Leftovers (ID: 81)
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BUTTERFREE_2] = { // Butterfree-WP (ID: 82)
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_BUG_BUZZ, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_ROOST},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BEEDRILL_1] = { // Beedrill-KnockOff (ID: 83)
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEEDRILL_2] = { // Beedrill-Xscissor (ID: 84)
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LEDIAN_1] = { // Ledian-Band (ID: 85)
        .species = SPECIES_LEDIAN,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_U_TURN, MOVE_MACH_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LEDIAN_2] = { // Ledian-SD (ID: 86)
        .species = SPECIES_LEDIAN,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARIADOS_1] = { // Ariados-Offensive (ID: 87)
        .species = SPECIES_ARIADOS,
        .moves = {MOVE_STICKY_WEB, MOVE_TOXIC_SPIKES, MOVE_MEGAHORN, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARIADOS_2] = { // Ariados-Bulky (ID: 88)
        .species = SPECIES_ARIADOS,
        .moves = {MOVE_STICKY_WEB, MOVE_TOXIC_SPIKES, MOVE_TOXIC_THREAD, MOVE_MEGAHORN},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BEAUTIFLY_1] = { // Beautifly-HPfighting (ID: 89)
        .species = SPECIES_BEAUTIFLY,
        .moves = {MOVE_BUG_BUZZ, MOVE_HIDDEN_POWER, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 1
    },
    [FRONTIER_MON_BEAUTIFLY_2] = { // Beautifly-HPground (ID: 90)
        .species = SPECIES_BEAUTIFLY,
        .moves = {MOVE_BUG_BUZZ, MOVE_HIDDEN_POWER, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_DUSTOX_1] = { // Dustox-QD (ID: 91)
        .species = SPECIES_DUSTOX,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSTOX_2] = { // Dustox-Bulky (ID: 92)
        .species = SPECIES_DUSTOX,
        .moves = {MOVE_GUNK_SHOT, MOVE_LEECH_LIFE, MOVE_SECRET_POWER, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_NINJASK_1] = { // Ninjask-Pass (ID: 93)
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SONIC_BOOM, MOVE_DRILL_RUN, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINJASK_2] = { // Ninjask-Protect (ID: 94)
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SONIC_BOOM, MOVE_DRILL_RUN, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHEDINJA_1] = { // Shedinja-Pass (ID: 95)
        .species = SPECIES_SHEDINJA,
        .moves = {MOVE_SHADOW_SNEAK, MOVE_REFLECT_TYPE, MOVE_SWORDS_DANCE, MOVE_BATON_PASS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_LONELY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHEDINJA_2] = { // Shedinja-Wisp (ID: 96)
        .species = SPECIES_SHEDINJA,
        .moves = {MOVE_SHADOW_SNEAK, MOVE_REFLECT_TYPE, MOVE_WILL_O_WISP, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_LONELY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAWILE_1] = { // Mawile-Defensive (ID: 97)
        .species = SPECIES_MAWILE,
        .moves = {MOVE_STEALTH_ROCK, MOVE_PLAY_ROUGH, MOVE_KNOCK_OFF, MOVE_TOXIC},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_YANMEGA_1] = { // Yanmega-TintedLens (ID: 98)
        .species = SPECIES_YANMEGA,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_GIGA_DRAIN, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PROBOPASS_1] = { // Probopass-Specs (ID: 99)
        .species = SPECIES_PROBOPASS,
        .moves = {MOVE_POWER_GEM, MOVE_DISCHARGE, MOVE_EARTH_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELCATTY_1] = { // Delcatty-ExBelt (ID: 100)
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_HYPER_VOICE, MOVE_ENERGY_BALL, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SABLEYE_1] = { // Sableye-CM (ID: 101)
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_DARK_PULSE, MOVE_WILL_O_WISP, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LICKILICKY_1] = { // Lickilicky-Defensive (ID: 102)
        .species = SPECIES_LICKILICKY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHERRIM_1] = { // Cherrim-Special (ID: 103)
        .species = SPECIES_CHERRIM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_DAZZLING_GLEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_1] = { // Audino-Toxic (ID: 104)
        .species = SPECIES_AUDINO,
        .moves = {MOVE_HYPER_VOICE, MOVE_TOXIC, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DARMANITAN_ZEN_1] = { // Darmanitan_Zen-Flamethrower (ID: 105)
        .species = SPECIES_DARMANITAN_ZEN,
        .moves = {MOVE_PSYCHIC, MOVE_GRAVEL_STORM, MOVE_FLAMETHROWER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_1] = { // Whimsicott-Defensive (ID: 106)
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_STUN_SPORE, MOVE_ENCORE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VOLBEAT_1] = { // Volbeat-TailGlowPass (ID: 107)
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_THUNDERBOLT, MOVE_TAIL_GLOW, MOVE_BATON_PASS, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ILLUMISE_1] = { // Illumise-QuiverPass (ID: 108)
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_BATON_PASS, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MARACTUS_1] = { // Maractus-ExBelt (ID: 109)
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_ENERGY_BALL, MOVE_EARTH_POWER, MOVE_WEATHER_BALL, MOVE_SANDSTORM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PARASECT_1] = { // Parasect-Bulky (ID: 110)
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_REAPING_BLOW, MOVE_BRICK_BREAK, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOGOAT_1] = { // Gogoat-MilkDrink (ID: 111)
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_BULK_UP, MOVE_ROCK_SLIDE, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WOBBUFFET_1] = { // Wobuffet-Wiki (ID: 112)
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PLUSLE_1] = { // Plusle-EncoreNP (ID: 113)
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_GRASS_KNOT, MOVE_ENCORE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MINUN_1] = { // Minun-SubToxic (ID: 114)
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_ENCORE, MOVE_TOXIC, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LURANTIS_1] = { // Lurantis-Mixed (ID: 115)
        .species = SPECIES_LURANTIS,
        .moves = {MOVE_LEAF_STORM, MOVE_SUPERPOWER, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AZUMARILL_1] = { // Azumarill-Band (ID: 116)
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_LIQUIDATION, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUDOWOODO_1] = { // Sudowoodo-FastBand (ID: 117)
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_HEAD_SMASH, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGCARGO_1] = { // Magcargo-WhiteHerb (ID: 118)
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_FIRE_BLAST, MOVE_GRAVEL_STORM, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RATICATE_1] = { // Raticate-SD (ID: 119)
        .species = SPECIES_RATICATE,
        .moves = {MOVE_FACADE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MASQUERAIN_1] = { // Masquerain-Web (ID: 120)
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_BUG_BUZZ, MOVE_STICKY_WEB, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_1] = { // Furret-CoilPass (ID: 121)
        .species = SPECIES_FURRET,
        .moves = {MOVE_BODY_SLAM, MOVE_COIL, MOVE_REST, MOVE_BATON_PASS},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIGHTYENA_1] = { // Mightyena-Protect (ID: 122)
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_FACADE, MOVE_CRUNCH, MOVE_FIRE_FANG, MOVE_EE_PROTECT},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LINOONE_1] = { // Linoone-StompingTantrum (ID: 123)
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SHADOW_CLAW, MOVE_STOMPING_TANTRUM, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CASTFORM_1] = { // Castform-ExBelt (ID: 124)
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_FIRE_BLAST, MOVE_HYDRO_PUMP, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WIGGLYTUFF_1] = { // Wigglytuff-ExBelt (ID: 125)
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT, MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUNFLORA_1] = { // Sunflora-Flamethrower (ID: 126)
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_SOLAR_BEAM, MOVE_FLAMETHROWER, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QWILFISH_1] = { // Qwilfish-Tspikes (ID: 127)
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_LIQUIDATION, MOVE_POISON_JAB, MOVE_TOXIC_SPIKES, MOVE_TAUNT},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PELIPPER_1] = { // Pelipper-Defensive (ID: 128)
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_ROOST, MOVE_U_TURN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_1] = { // Swellow-Guts (ID: 129)
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FACADE, MOVE_BRAVE_BIRD, MOVE_SECRET_POWER, MOVE_U_TURN},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 29,
        .ability = 0   
    },
    [FRONTIER_MON_LILLIGANT_1] = { // Lilligant-Sun (ID: 130)
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_DAZZLING_GLEAM, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARBOK_1] = { // Arbok-Glare (ID: 131)
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_GLARE, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PERSIAN_1] = { // Persian-Offensive (ID: 132)
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FAKE_OUT, MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_CUT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KECLEON_1] = { // Kecleon-1attack (ID: 133)
        .species = SPECIES_KECLEON,
        .moves = {MOVE_REVELATION_DANCE, MOVE_NASTY_PLOT, MOVE_RECOVER, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCRAFTY_1] = { // Scrafty-DD (ID: 134)
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUNATONE_1] = { // Lunatone-WP (ID: 135)
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_POWER_GEM, MOVE_PSYSHOCK, MOVE_EARTH_POWER, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_1] = { // Solrock-Defensive (ID: 136)
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_WILL_O_WISP, MOVE_MORNING_SUN, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_1] = { // Noctowl-StoredPower (ID: 137)
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_AGILITY, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SANDSLASH_1] = { // Sandslash-BulkySand (ID: 138)
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VENOMOTH_1] = { // Venomoth-QuiverPass (ID: 139)
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_BATON_PASS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLISSEY_1] = { // Blissey-BoltBeam (ID: 140)
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEAKING_1] = { // Seaking-RestTalk (ID: 141)
        .species = SPECIES_SEAKING,
        .moves = {MOVE_HORN_DRILL, MOVE_DIVE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JUMPLUFF_1] = { // Jumpluff-1attack (ID: 142)
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_SLEEP_POWDER, MOVE_SWORDS_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BASTIODON_1] = { // Bastiodon-DualHazards (ID: 143)
        .species = SPECIES_BASTIODON,
        .moves = {MOVE_METAL_BURST, MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_SHORE_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LIEPARD_1] = { // Liepard-NP (ID: 144)
        .species = SPECIES_LIEPARD,
        .moves = {MOVE_DARK_PULSE, MOVE_ENCORE, MOVE_NASTY_PLOT, MOVE_COPYCAT},
        .heldItem = ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PRIMEAPE_1] = { // Primeape-Band (ID: 145)
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONLEE_1] = { // Hitmonlee-WhiteHerb (ID: 146)
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONCHAN_1] = { // Hitmonchan-DualSetup (ID: 147)
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_AGILITY, MOVE_BULK_UP},
        .heldItem = ITEM_LUCKY_PUNCH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GIRAFARIG_1] = { // Girafarig-Band (ID: 148)
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_PSYCHIC_FANGS, MOVE_JUMP_KICK, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONTOP_1] = { // Hitmontop-TechniTopMachPunch (ID: 149)
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_TRIPLE_KICK, MOVE_MACH_PUNCH, MOVE_BULLET_PUNCH, MOVE_STONE_EDGE},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_1] = { // Banette-Bulky (ID: 150)
        .species = SPECIES_BANETTE,
        .moves = {MOVE_SHADOW_SNEAK, MOVE_KNOCK_OFF, MOVE_SNUGGLE, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEVIPER_1] = { // Seviper-NP (ID: 151)
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DARK_PULSE, MOVE_NASTY_PLOT, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_1] = { // Zangoose-QuickAttack (ID: 152)
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CAMERUPT_1] = { // Camerupt-Specs (ID: 153)
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_FLAMETHROWER, MOVE_OVERHEAT, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHARPEDO_1] = { // Sharpedo-LifeOrb (ID: 154)
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_EE_PROTECT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_1] = { // Tropius-BulkyDD (ID: 155)
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNEZONE_1] = { // Magnezone-MirrorCoatAV (ID: 156)
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_MIRROR_SHOT, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MANTINE_1] = { // Mantine-Rain (ID: 157)
        .species = SPECIES_MANTINE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ROOST, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STANTLER_1] = { // Stantler-Band (ID: 158)
        .species = SPECIES_STANTLER,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SUCKER_PUNCH, MOVE_JUMP_KICK, MOVE_MEGAHORN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ABSOL_1] = { // Absol-Band (ID: 159)
        .species = SPECIES_ABSOL,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_SUPERPOWER, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SWALOT_1] = { // Swalot-2attacks (ID: 160)
        .species = SPECIES_SWALOT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_ACUPRESSURE, MOVE_SLACK_OFF},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRAWDAUNT_1] = { // Crawdaunt-DD (ID: 161)
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PIDGEOT_1] = { // Pidgeot-Offensive (ID: 162)
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_EXTREME_SPEED, MOVE_SECRET_POWER, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_GRUMPIG_1] = { // Grumpig-Specs (ID: 163)
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TORKOAL_1] = { // Torkoal-ShellSmash (ID: 164)
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_1] = { // Kingler-Agility (ID: 165)
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_ROCK_SLIDE, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CACTURNE_1] = { // Cacturne-SD (ID: 166)
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_SUCKER_PUNCH, MOVE_DRAIN_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BELLOSSOM_1] = { // Bellossom-SleepPowderQD (ID: 167)
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_1] = { // Octillery-SkillLink (ID: 168)
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_BULLET_SEED, MOVE_ROCK_BLAST, MOVE_PIN_MISSILE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HUNTAIL_1] = { // Huntail-3attacks (ID: 169)
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_SUCKER_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOREBYSS_1] = { // Gorebyss-3attacks (ID: 170)
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_RELICANTH_1] = { // Relicanth-Band (ID: 171)
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_HEAD_SMASH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_1] = { // Omastar-Sash (ID: 172)
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GRAVEL_STORM, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_1] = { // Kabutops-Band (ID: 173)
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_ROCK_SLIDE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLIWRATH_1] = { // Poliwrath-AV (ID: 174)
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_FOCUS_BLAST, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_VACUUM_WAVE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_1] = { // Scyther-Scarf (ID: 175)
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_U_TURN, MOVE_BRICK_BREAK, MOVE_BUG_BITE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PINSIR_1] = { // Pinsir-Scarf (ID: 176)
        .species = SPECIES_PINSIR,
        .moves = {MOVE_X_SCISSOR, MOVE_ROCK_SLIDE, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLITOED_1] = { // Politoed-Scarf (ID: 177)
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_1] = { // Cloyster-Sash (ID: 178)
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ABOMASNOW_1] = { // Abomasnow-LifeOrb (ID: 179)
        .species = SPECIES_ABOMASNOW,
        .moves = {MOVE_BLIZZARD, MOVE_GIGA_DRAIN, MOVE_EARTHQUAKE, MOVE_ICE_SHARD},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AVALUGG_1] = { // Avalugg-Defensive (ID: 180)
        .species = SPECIES_AVALUGG,
        .moves = {MOVE_AVALANCHE, MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BEARTIC_1] = { // Beartic-Hail (ID: 181)
        .species = SPECIES_BEARTIC,
        .moves = {MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_SUPERPOWER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CARBINK_1] = { // Carbink-TR (ID: 182)
        .species = SPECIES_CARBINK,
        .moves = {MOVE_TRICK_ROOM, MOVE_STEALTH_ROCK, MOVE_EXPLOSION, MOVE_MAGIC_COAT},
        .heldItem = ITEM_RED_CARD,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CARRACOSTA_1] = { // Carracosta-SuperpowerSmash (ID: 183)
        .species = SPECIES_CARRACOSTA,
        .moves = {MOVE_ROCK_SLIDE, MOVE_WATERFALL, MOVE_SUPERPOWER, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRUSTLE_1] = { // Crustle-DualHazards (ID: 184)
        .species = SPECIES_CRUSTLE,
        .moves = {MOVE_ROCK_SLIDE, MOVE_STEALTH_ROCK, MOVE_SPIKES, MOVE_SHELL_SMASH},
        .heldItem = ITEM_CUSTAP_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRYOGONAL_1] = { // Cryogonal-WP (ID: 185)
        .species = SPECIES_CRYOGONAL,
        .moves = {MOVE_FROST_BREATH, MOVE_POWER_GEM, MOVE_FREEZE_DRY, MOVE_RECOVER},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CRABOMINABLE_1] = { // Crabominable-BoxingGlove (ID: 186)
        .species = SPECIES_CRABOMINABLE,
        .moves = {MOVE_HAMMER_ARM, MOVE_ICE_HAMMER, MOVE_MACH_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUMINEON_1] = { // Lumineon-StormDrain (ID: 187)
        .species = SPECIES_LUMINEON,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_SAWSBUCK_1] = { // Sawsbuck-Scarf (ID: 188)
        .species = SPECIES_SAWSBUCK,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_HORN_LEECH, MOVE_JUMP_KICK, MOVE_HEADBUTT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BASCULIN_1] = { // Basculin-LifeOrb (ID: 189)
        .species = SPECIES_BASCULIN,
        .moves = {MOVE_WATERFALL, MOVE_AQUA_JET, MOVE_ICE_FANG, MOVE_PSYCHIC_FANGS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CARNIVINE_1] = { // Carnivine-NaturalGift (ID: 190)
        .species = SPECIES_CARNIVINE,
        .moves = {MOVE_POWER_WHIP, MOVE_NATURAL_GIFT, MOVE_KNOCK_OFF, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_WATMEL_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STUNFISK_1] = { // Stunfisk-Offensive (ID: 191)
        .species = SPECIES_STUNFISK,
        .moves = {MOVE_DISCHARGE, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PHIONE_1] = { // Phione-WishCM (ID: 192)
        .species = SPECIES_PHIONE,
        .moves = {MOVE_DRAINING_KISS, MOVE_CALM_MIND, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLIGAR_1] = { // Gligar-Curse (ID: 193)
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_CURSE, MOVE_ROOST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VIGOROTH_1] = { // Vigoroth-FlailReversal (ID: 194)
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_FLAIL, MOVE_REVERSAL, MOVE_SHADOW_CLAW, MOVE_SUBSTITUTE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAWILE_2] = { // Mawile-ExBelt (ID: 195)
        .species = SPECIES_MAWILE,
        .moves = {MOVE_PLAY_ROUGH, MOVE_ICE_FANG, MOVE_FIRE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_YANMEGA_2] = { // Yanmega-SpeedBoost (ID: 196)
        .species = SPECIES_YANMEGA,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_HIDDEN_POWER, MOVE_EE_PROTECT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_PROBOPASS_2] = { // Probopass-AV (ID: 197)
        .species = SPECIES_PROBOPASS,
        .moves = {MOVE_POWER_GEM, MOVE_DISCHARGE, MOVE_EARTH_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELCATTY_2] = { // Delcatty-CM (ID: 198)
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_MOONBLAST, MOVE_HYPER_VOICE, MOVE_THUNDERBOLT, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SABLEYE_2] = { // Sableye-Defensive (ID: 199)
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_FOUL_PLAY, MOVE_WILL_O_WISP, MOVE_SEISMIC_TOSS, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LICKILICKY_2] = { // Lickilicky-Curse (ID: 200)
        .species = SPECIES_LICKILICKY,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHERRIM_2] = { // Cherrim-Physical (ID: 201)
        .species = SPECIES_CHERRIM,
        .moves = {MOVE_PETAL_BLIZZARD, MOVE_SECRET_POWER, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_AUDINO_2] = { // Audino-BoltBeam (ID: 202)
        .species = SPECIES_AUDINO,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DARMANITAN_ZEN_2] = { // Darmanitan_Zen-FocusBlast (ID: 203)
        .species = SPECIES_DARMANITAN_ZEN,
        .moves = {MOVE_PSYCHIC, MOVE_GRAVEL_STORM, MOVE_FOCUS_BLAST, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHIMSICOTT_2] = { // Whimsicott-Specs (ID: 204)
        .species = SPECIES_WHIMSICOTT,
        .moves = {MOVE_MOONBLAST, MOVE_ENERGY_BALL, MOVE_PSYCHIC, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_VOLBEAT_2] = { // Volbeat-3attacksRoost (ID: 205)
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_WILD_CHARGE, MOVE_LUNGE, MOVE_ICE_PUNCH, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ILLUMISE_2] = { // Illumise-QD (ID: 206)
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_MOONBLAST, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MARACTUS_2] = { // Maractus-LifeOrb (ID: 207)
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_GIGA_DRAIN, MOVE_EARTH_POWER, MOVE_WEATHER_BALL, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PARASECT_2] = { // Parasect-Nightmare (ID: 208)
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_NIGHTMARE, MOVE_SYNTHESIS, MOVE_REAPING_BLOW},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOGOAT_2] = { // Gogoat-GrassPelt (ID: 209)
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_ROCK_SLIDE, MOVE_GRASSY_TERRAIN, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WOBBUFFET_2] = { // Wobuffet-Sitrus (ID: 210)
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PLUSLE_2] = { // Plusle-HPice (ID: 211)
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_GRASS_KNOT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MINUN_2] = { // Minun-NP (ID: 212)
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_NUZZLE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LURANTIS_2] = { // Lurantis-Physical (ID: 213)
        .species = SPECIES_LURANTIS,
        .moves = {MOVE_SUPERPOWER, MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AZUMARILL_2] = { // Azumarill-BD (ID: 214)
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_AQUA_JET, MOVE_PLAY_ROUGH, MOVE_KNOCK_OFF, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUDOWOODO_2] = { // Sudowoodo-BulkyBand (ID: 215)
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_HEAD_SMASH, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MAGCARGO_2] = { // Magcargo-Sash (ID: 216)
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_FIRE_BLAST, MOVE_GRAVEL_STORM, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RATICATE_2] = { // Raticate-Band (ID: 217)
        .species = SPECIES_RATICATE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_STOMPING_TANTRUM, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MASQUERAIN_2] = { // Masquerain-QD (ID: 218)
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_SCALD, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FURRET_2] = { // Furret-CoilKnockOff (ID: 219)
        .species = SPECIES_FURRET,
        .moves = {MOVE_RETURN, MOVE_KNOCK_OFF, MOVE_COIL, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIGHTYENA_2] = { // Mightyena-SD (ID: 220)
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_FACADE, MOVE_CRUNCH, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LINOONE_2] = { // Linoone-SeedBomb (ID: 221)
        .species = SPECIES_LINOONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SEED_BOMB, MOVE_SHADOW_CLAW, MOVE_BELLY_DRUM},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_CASTFORM_2] = { // Castform-Rain (ID: 222)
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_THUNDER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WIGGLYTUFF_2] = { // Wigglytuff-WishProtect (ID: 223)
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SUNFLORA_2] = { // Sunflora-WeatherBall (ID: 224)
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_EARTH_POWER, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_QWILFISH_2] = { // Qwilfish-Rain (ID: 225)
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_WATERFALL, MOVE_POISON_JAB, MOVE_SWORDS_DANCE, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PELIPPER_2] = { // Pelipper-Specs (ID: 226)
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_ICE_BEAM, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWELLOW_2] = { // Swellow-Specs (ID: 227)
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 2
    },
    [FRONTIER_MON_LILLIGANT_2] = { // Lilligant-QD (ID: 228)
        .species = SPECIES_LILLIGANT,
        .moves = {MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_SYNTHESIS, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_ARBOK_2] = { // Arbok-IceFang (ID: 229)
        .species = SPECIES_ARBOK,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_COIL},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PERSIAN_2] = { // Persian-SwagCat (ID: 230)
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_THUNDER_WAVE, MOVE_SWAGGER, MOVE_FOUL_PLAY, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KECLEON_2] = { // Kecleon-2attacks (ID: 231)
        .species = SPECIES_KECLEON,
        .moves = {MOVE_REVELATION_DANCE, MOVE_ICE_BEAM, MOVE_NASTY_PLOT, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCRAFTY_2] = { // Scrafty-BU (ID: 232)
        .species = SPECIES_SCRAFTY,
        .moves = {MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_BULK_UP, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUNATONE_2] = { // Lunatone-ScreensLead (ID: 233)
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_STEALTH_ROCK, MOVE_MEMENTO},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SOLROCK_2] = { // Solrock-ScreensLead (ID: 234)
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_STEALTH_ROCK, MOVE_EXPLOSION},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOCTOWL_2] = { // Noctowl-OffensiveKeenEye (ID: 235)
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_HYPNOSIS, MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SANDSLASH_2] = { // Sandslash-FastSand (ID: 236)
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SANDSTORM},
        .heldItem = ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VENOMOTH_2] = { // Venomoth-OffensiveQD (ID: 237)
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BLISSEY_2] = { // Blissey-SereneGrace (ID: 238)
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_TRI_ATTACK, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEAKING_2] = { // Seaking-AV (ID: 239)
        .species = SPECIES_SEAKING,
        .moves = {MOVE_DIVE, MOVE_MEGAHORN, MOVE_DRILL_RUN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JUMPLUFF_2] = { // Jumpluff-2attacks (ID: 240)
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_ACROBATICS, MOVE_SECRET_POWER, MOVE_SWORDS_DANCE, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_BASTIODON_2] = { // Bastiodon-Taunt (ID: 241)
        .species = SPECIES_BASTIODON,
        .moves = {MOVE_METAL_BURST, MOVE_SPIKES, MOVE_TAUNT, MOVE_SHORE_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LIEPARD_2] = { // Liepard-Band (ID: 242)
        .species = SPECIES_LIEPARD,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_GUNK_SHOT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMEAPE_2] = { // Primeape-Scarf (ID: 243)
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HITMONLEE_2] = { // Hitmonlee-LifeOrb (ID: 244)
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_MACH_PUNCH, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HITMONCHAN_2] = { // Hitmonchan-MachPunch (ID: 245)
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_MACH_PUNCH, MOVE_BULK_UP},
        .heldItem = ITEM_LUCKY_PUNCH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GIRAFARIG_2] = { // Girafarig-NP (ID: 246)
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_TRI_ATTACK, MOVE_EXTRASENSORY, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HITMONTOP_2] = { // Hitmontop-TechniTopFakeOut (ID: 247)
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_FAKE_OUT, MOVE_TRIPLE_KICK, MOVE_BULLET_PUNCH, MOVE_STONE_EDGE},
        .heldItem = ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BANETTE_2] = { // Banette-4attacks (ID: 248)
        .species = SPECIES_BANETTE,
        .moves = {MOVE_SHADOW_SNEAK, MOVE_KNOCK_OFF, MOVE_SNUGGLE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SEVIPER_2] = { // Seviper-ExBelt (ID: 249)
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_2] = { // Zangoose-SwordsDance (ID: 250)
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CAMERUPT_2] = { // Camerupt-PhysicalAV (ID: 251)
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_STONE_EDGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SHARPEDO_2] = { // Sharpedo-ExBelt (ID: 252)
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TROPIUS_2] = { // Tropius-DD (ID: 253)
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_DRAGON_HAMMER, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAGNEZONE_2] = { // Magnezone-VoltSwitchAV (ID: 254)
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_MIRROR_SHOT, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MANTINE_2] = { // Mantine-Defensive (ID: 255)
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SCALD, MOVE_HAZE, MOVE_TOXIC, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_STANTLER_2] = { // Stantler-LifeOrb (ID: 256)
        .species = SPECIES_STANTLER,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SUCKER_PUNCH, MOVE_JUMP_KICK, MOVE_EARTHQUAKE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ABSOL_2] = { // Absol-SuperLuck (ID: 257)
        .species = SPECIES_ABSOL,
        .moves = {MOVE_NIGHT_SLASH, MOVE_STONE_EDGE, MOVE_PSYCHO_CUT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SWALOT_2] = { // Swalot-Stockpile (ID: 258)
        .species = SPECIES_SWALOT,
        .moves = {MOVE_ACID, MOVE_ACUPRESSURE, MOVE_STOCKPILE, MOVE_SLACK_OFF},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRAWDAUNT_2] = { // Crawdaunt-Band (ID: 259)
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_AQUA_JET, MOVE_CRUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PIDGEOT_2] = { // Pidgeot-Bulky (ID: 260)
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_SECRET_POWER, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_GRUMPIG_2] = { // Grumpig-CM (ID: 261)
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_RECYCLE, MOVE_CALM_MIND},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TORKOAL_2] = { // Torkoal-SunSetter (ID: 262)
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_BLAST_OFF, MOVE_STEALTH_ROCK, MOVE_WILL_O_WISP, MOVE_OVERHEAT},
        .heldItem = ITEM_HEAT_ROCK,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGLER_2] = { // Kingler-SD (ID: 263)
        .species = SPECIES_KINGLER,
        .moves = {MOVE_METEOR_MASH, MOVE_LIQUIDATION, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CACTURNE_2] = { // Cacturne-Sand (ID: 264)
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BELLOSSOM_2] = { // Bellossom-MoonblastQD (ID: 265)
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_MOONBLAST, MOVE_QUIVER_DANCE, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_OCTILLERY_2] = { // Octillery-ExBelt (ID: 266)
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HUNTAIL_2] = { // Huntail-SmashPass (ID: 267)
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_BATON_PASS, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOREBYSS_2] = { // Gorebyss-SmashPass (ID: 268)
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BATON_PASS, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RELICANTH_2] = { // Relicanth-RockPolish (ID: 269)
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_HEAD_SMASH, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_OMASTAR_2] = { // Omastar-WhiteHerb (ID: 270)
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GRAVEL_STORM, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KABUTOPS_2] = { // Kabutops-Rain (ID: 271)
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_LIQUIDATION, MOVE_ROCK_SLIDE, MOVE_AQUA_JET, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_POLIWRATH_2] = { // Poliwrath-RestTalk (ID: 272)
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_CIRCLE_THROW, MOVE_SCALD, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCYTHER_2] = { // Scyther-Band (ID: 273)
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_AERIAL_ACE, MOVE_U_TURN, MOVE_BRICK_BREAK, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PINSIR_2] = { // Pinsir-SD (ID: 274)
        .species = SPECIES_PINSIR,
        .moves = {MOVE_X_SCISSOR, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_POLITOED_2] = { // Politoed-Specs (ID: 275)
        .species = SPECIES_POLITOED,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FOCUS_BLAST, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLOYSTER_2] = { // Cloyster-KingsRock (ID: 276)
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_HYDRO_PUMP, MOVE_SHELL_SMASH},
        .heldItem = ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ABOMASNOW_2] = { // Abomasnow-Scarf (ID: 277)
        .species = SPECIES_ABOMASNOW,
        .moves = {MOVE_BLIZZARD, MOVE_GIGA_DRAIN, MOVE_FOCUS_BLAST, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AVALUGG_2] = { // Avalugg-Offensive (ID: 278)
        .species = SPECIES_AVALUGG,
        .moves = {MOVE_AVALANCHE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_RECOVER},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BEARTIC_2] = { // Beartic-BD (ID: 279)
        .species = SPECIES_BEARTIC,
        .moves = {MOVE_ICE_SHARD, MOVE_MACH_PUNCH, MOVE_AQUA_JET, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CARBINK_2] = { // Carbink-CM (ID: 280)
        .species = SPECIES_CARBINK,
        .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_RED_CARD,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CARRACOSTA_2] = { // Carracosta-EarthquakeSmash (ID: 281)
        .species = SPECIES_CARRACOSTA,
        .moves = {MOVE_ROCK_SLIDE, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRUSTLE_2] = { // Crustle-ShellSmash (ID: 282)
        .species = SPECIES_CRUSTLE,
        .moves = {MOVE_ROCK_SLIDE, MOVE_X_SCISSOR, MOVE_EARTHQUAKE, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CRYOGONAL_2] = { // Cryogonal-DryIce (ID: 283)
        .species = SPECIES_CRYOGONAL,
        .moves = {MOVE_FROST_BREATH, MOVE_POWER_GEM, MOVE_FREEZE_DRY, MOVE_RECOVER},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CRABOMINABLE_2] = { // Crabominable-AV (ID: 284)
        .species = SPECIES_CRABOMINABLE,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ICE_HAMMER, MOVE_MACH_PUNCH, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LUMINEON_2] = { // Lumineon-Illuminate (ID: 285)
        .species = SPECIES_LUMINEON,
        .moves = {MOVE_SURF, MOVE_DAZZLING_GLEAM, MOVE_SIGNAL_BEAM, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SAWSBUCK_2] = { // Sawsbuck-SD (ID: 286)
        .species = SPECIES_SAWSBUCK,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_HORN_LEECH, MOVE_JUMP_KICK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BASCULIN_2] = { // Basculin-Band (ID: 287)
        .species = SPECIES_BASCULIN,
        .moves = {MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_ICE_FANG, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CARNIVINE_2] = { // Carnivine-SD (ID: 288)
        .species = SPECIES_CARNIVINE,
        .moves = {MOVE_POWER_WHIP, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STUNFISK_2] = { // Stunfisk-Defensive (ID: 289)
        .species = SPECIES_STUNFISK,
        .moves = {MOVE_DISCHARGE, MOVE_EARTH_POWER, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PHIONE_2] = { // Phione-RainCM (ID: 290)
        .species = SPECIES_PHIONE,
        .moves = {MOVE_SCALD, MOVE_CALM_MIND, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLIGAR_2] = { // Gligar-Defensive (ID: 291)
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_STEALTH_ROCK, MOVE_ROOST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VIGOROTH_2] = { // Vigoroth-BU (ID: 292)
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_RETURN, MOVE_DRAIN_PUNCH, MOVE_BULK_UP, MOVE_SLACK_OFF},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BARBARACLE_1] = { // Barbaracle-Sash (ID: 293)
        .species = SPECIES_BARBARACLE,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_SHELL_SMASH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_COFAGRIGUS_1] = { // Cofagrigus-Defensive (ID: 294)
        .species = SPECIES_COFAGRIGUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PASSIMIAN_1] = { // Passimian-Band (ID: 295)
        .species = SPECIES_PASSIMIAN,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ORANGURU_1] = { // Oranguru-NP (ID: 296)
        .species = SPECIES_ORANGURU,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISDREAVUS_1] = { // Misdreavus-BulkyCM (ID: 297)
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_MOONLIGHT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DOUBLADE_1] = { // Doublade-RestTalk (ID: 298)
        .species = SPECIES_DOUBLADE,
        .moves = {MOVE_GYRO_BALL, MOVE_TOXIC, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUGTRIO_1] = { // Dugtrio-Screech (ID: 299)
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_ROCK_SLIDE, MOVE_SCREECH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_1] = { // Medicham-Reversal (ID: 402)
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_REVERSAL, MOVE_ZEN_HEADBUTT, MOVE_ENDURE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISMAGIUS_1] = { // Mismagius-ExBelt (ID: 301)
        .species = SPECIES_MISMAGIUS,
        .moves = {MOVE_MOONBLAST, MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_1] = { // Fearow-DualSetup (ID: 404)
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_FOCUS_ENERGY, MOVE_AGILITY},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRANBULL_1] = { // Granbull-Band (ID: 303)
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_1] = { // Jynx-3attacksLovelyKiss (ID: 406)
        .species = SPECIES_JYNX,
        .moves = {MOVE_FROST_BREATH, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_LOVELY_KISS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSKNOIR_1] = { // Dusknoir-WispTR (ID: 305)
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_WILL_O_WISP, MOVE_TRICK_ROOM},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DODRIO_1] = { // Dodrio-Flail (ID: 408)
        .species = SPECIES_DODRIO,
        .moves = {MOVE_FLAIL, MOVE_DRILL_PECK, MOVE_JUMP_KICK, MOVE_ENDURE},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_1] = { // Mr_Mime-Scarf (ID: 307)
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_1] = { // Lanturn-Specs (ID: 410)
        .species = SPECIES_LANTURN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_DAZZLING_GLEAM, MOVE_SIGNAL_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BRELOOM_1] = { // Breloom-SubSeed (ID: 309)
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_SPORE, MOVE_SUBSTITUTE, MOVE_LEECH_SEED, MOVE_FOCUS_PUNCH},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FORRETRESS_1] = { // Forretress-DualHazardsRest (ID: 412)
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_1] = { // Whiscash-DDhydration (ID: 311)
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_DIVE, MOVE_RAIN_DANCE, MOVE_REST, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_XATU_1] = { // Xatu-DualScreens (ID: 414)
        .species = SPECIES_XATU,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_THUNDER_WAVE, MOVE_U_TURN},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SKARMORY_1] = { // Skarmory-PhysDef (ID: 313)
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_TOXIC, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAROWAK_1] = { // Marowak-4attacks (ID: 416)
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_BONEMERANG, MOVE_STONE_EDGE, MOVE_FIRE_PUNCH, MOVE_BULLDOZE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_QUAGSIRE_1] = { // Quagsire-CurseSpDef (ID: 315)
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLEFABLE_1] = { // Clefable-2attacksCM (ID: 418)
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_1] = { // Hariyama-RestTalk (ID: 317)
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_REVENGE, MOVE_KNOCK_OFF, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_1] = { // Raichu-Physical (ID: 420)
        .species = SPECIES_RAICHU,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_FLAIL, MOVE_SECRET_POWER},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DEWGONG_1] = { // Dewgong-HailSD (ID: 319)
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICICLE_CRASH, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE, MOVE_HAIL},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MANECTRIC_1] = { // Manectric-Specs (ID: 422)
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_1] = { // Vileplume-Offensive (ID: 321)
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_STRENGTH_SAP, MOVE_MOONBLAST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VICTREEBEL_1] = { // Victreebel-Offensive (ID: 424)
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_STRENGTH_SAP},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ELECTRODE_1] = { // Electrode-ScreensExplosion (ID: 323)
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_EXPLOSION, MOVE_TAUNT},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXPLOUD_1] = { // Exploud-Scarf (ID: 426)
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHIFTRY_1] = { // Shiftry-ExBelt (ID: 325)
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_LOW_KICK},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_1] = { // Glalie-Band (ID: 428)
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_THUNDER_FANG, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUDICOLO_1] = { // Ludicolo-EnergyBall (ID: 327)
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ENERGY_BALL, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_1] = { // Hypno-BD (ID: 430)
        .species = SPECIES_HYPNO,
        .moves = {MOVE_ZEN_HEADBUTT, MOVE_DRAIN_PUNCH, MOVE_HYPNOSIS, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_1] = { // Golem-Sucker (ID: 329)
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SUCKER_PUNCH, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYPERIOR_1] = { // Rhyperior-SapSipper (ID: 432)
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK, MOVE_ICE_FANG},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ALAKAZAM_1] = { // Alakazam-Encore (ID: 331)
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_ENCORE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WEEZING_1] = { // Weezing-MixedDef (ID: 434)
        .species = SPECIES_WEEZING,
        .moves = {MOVE_ACID, MOVE_WILL_O_WISP, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_1] = { // Kangaskhan-Sucker (ID: 333)
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_1] = { // Electivire-ExBelt (ID: 436)
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_1] = { // Tauros-Mixed (ID: 335)
        .species = SPECIES_TAUROS,
        .moves = {MOVE_BODY_SLAM, MOVE_FIRE_BLAST, MOVE_EARTHQUAKE, MOVE_WORK_UP},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_1] = { // Slowbro-Nightmare (ID: 438)
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_YAWN, MOVE_EE_PROTECT, MOVE_NIGHTMARE, MOVE_BLOCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWKING_1] = { // Slowking-CM (ID: 337)
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILTANK_1] = { // Miltank-Defensive (ID: 440)
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_THUNDER_WAVE, MOVE_STEALTH_ROCK, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ALTARIA_1] = { // Altaria-Defensive (ID: 339)
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_FLAMETHROWER, MOVE_TOXIC, MOVE_ROOST, MOVE_HAZE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_1] = { // Nidoqueen-Defensive (ID: 442)
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES, MOVE_ROAR},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_1] = { // Nidoking-LifeOrb (ID: 341)
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGMORTAR_1] = { // Magmortar-Shuca (ID: 444)
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_SEARING_SHOT, MOVE_AURA_SPHERE, MOVE_THUNDERBOLT, MOVE_FLAME_CHARGE},
        .heldItem = ITEM_SHUCA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CRADILY_1] = { // Cradily-Defensive (ID: 343)
        .species = SPECIES_CRADILY,
        .moves = {MOVE_STEALTH_ROCK, MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_1] = { // Armaldo-ShellBellSD (ID: 446)
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLDUCK_1] = { // Golduck-Rain (ID: 345)
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAPIDASH_1] = { // Rapidash-Band (ID: 448)
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_JUMP_KICK, MOVE_WILD_CHARGE, MOVE_HIGH_HORSEPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUK_1] = { // Muk-Curse (ID: 347)
        .species = SPECIES_MUK,
        .moves = {MOVE_POISON_JAB, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GENGAR_1] = { // Gengar-ExBelt (ID: 450)
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_1] = { // Ampharos-DualSetup (ID: 349)
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_AGILITY, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_1] = { // Scizor-SD (ID: 452)
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_ACROBATICS, MOVE_SUPERPOWER, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_1] = { // Heracross-Scarf (ID: 351)
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ESPEON_1] = { // Espeon-DualScreens (ID: 454)
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_YAWN},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HOUNDOOM_1] = { // Houndoom-Scarf (ID: 353)
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_1] = { // Donphan-ExBelt (ID: 456)
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_BULLDOZE, MOVE_ROCK_TOMB, MOVE_ICE_SHARD, MOVE_FLAME_WHEEL},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLAYDOL_1] = { // Claydol-Specs (ID: 355)
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_1] = { // Wailord-OffensiveRestTalk (ID: 458)
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SCALD, MOVE_BOOMBURST, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_1] = { // Ninetales-BulkyCM (ID: 357)
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_1] = { // Machamp-Guts (ID: 460)
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SHUCKLE_1] = { // Shuckle-ShellSmashStall (ID: 359)
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_SHELL_SMASH, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STEELIX_1] = { // Steelix-RestTalk (ID: 462)
        .species = SPECIES_STEELIX,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TENTACRUEL_1] = { // Tentacruel-Defensive (ID: 361)
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SCALD, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AERODACTYL_1] = { // Aerodactyl-LifeOrb (ID: 464)
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_FLY, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON2_1] = { // Porygon2-TR (ID: 363)
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_TRICK_ROOM, MOVE_RECOVER},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARDEVOIR_1] = { // Gardevoir-OffensiveCM (ID: 466)
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_MOONBLAST, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_1] = { // Exeggutor-Harvest (ID: 365)
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_TRICK_ROOM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_1] = { // Starmie-CosmicPower (ID: 468)
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_COSMIC_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_FLYGON_1] = { // Flygon-DD (ID: 367)
        .species = SPECIES_FLYGON,
        .moves = {MOVE_LEECH_LIFE, MOVE_DRAGON_CLAW, MOVE_DRAGON_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_1] = { // Venusaur-Defensive (ID: 470)
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VAPOREON_1] = { // Vaporeon-Hydration (ID: 369)
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_REST},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JOLTEON_1] = { // Jolteon-ElectroBall (ID: 472)
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_ELECTRO_BALL, MOVE_EE_PROTECT, MOVE_SUBSTITUTE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FLAREON_1] = { // Flareon-3attacksMorningSun (ID: 371)
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_PLAY_ROUGH, MOVE_MORNING_SUN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_1] = { // Meganium-Offensive (ID: 474)
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_HIDDEN_POWER, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_URSARING_1] = { // Ursaring-QuickFeet (ID: 373)
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_CRUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UMBREON_1] = { // Umbreon-Nightmare (ID: 476)
        .species = SPECIES_UMBREON,
        .moves = {MOVE_YAWN, MOVE_EE_PROTECT, MOVE_NIGHTMARE, MOVE_MEAN_LOOK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_1] = { // Blastoise-Defensive (ID: 375)
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SCALD, MOVE_ROAR, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_1] = { // Feraligatr-Special (ID: 478)
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SCALD, MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AGGRON_1] = { // Aggron-RockPolish (ID: 377)
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAVY_SLAM, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_METAL_COAT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_1] = { // Incineroar-WP (ID: 480)
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_POWER_TRIP, MOVE_FLAME_CHARGE, MOVE_BULK_UP, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WALREIN_1] = { // Walrein-Defensive (ID: 379)
        .species = SPECIES_WALREIN,
        .moves = {MOVE_FROST_BREATH, MOVE_EARTHQUAKE, MOVE_YAWN, MOVE_SLACK_OFF},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_1] = { // Sceptile-Band (ID: 482)
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_STONE_EDGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_1] = { // Charizard-DD (ID: 381)
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_ACROBATICS, MOVE_EARTHQUAKE, MOVE_OVERHEAT, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_1] = { // Typhlosion-ExBelt (ID: 484)
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FLARE_BLITZ, MOVE_EARTHQUAKE, MOVE_SUBMISSION, MOVE_WILD_CHARGE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_1] = { // Lapras-BulkyCM (ID: 383)
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CROBAT_1] = { // Crobat-StallBreaker (ID: 486)
        .species = SPECIES_CROBAT,
        .moves = {MOVE_POISON_FANG, MOVE_SUPER_FANG, MOVE_TAUNT, MOVE_ROOST},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SWAMPERT_1] = { // Swampert-AV (ID: 385)
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_1] = { // Gyarados-BulkyDD (ID: 488)
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_DIVE, MOVE_OUTRAGE, MOVE_DRAGON_DANCE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_1] = { // Snorlax-FirePunch (ID: 387)
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_FACADE, MOVE_CURSE, MOVE_FIRE_PUNCH, MOVE_RECYCLE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KINGDRA_1] = { // Kingdra-Rain (ID: 490)
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_DRAGON_PULSE, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANSEY_1] = { // Chansey-DoubleTeam (ID: 389)
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM, MOVE_SEISMIC_TOSS, MOVE_SOFT_BOILED},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MILOTIC_1] = { // Milotic-Offensive (ID: 492)
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_DRAGON_PULSE, MOVE_ICE_BEAM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_1] = { // Arcanine-Defensive (ID: 391)
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_WILL_O_WISP, MOVE_FLARE_BLITZ, MOVE_MORNING_SUN, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_1] = { // Salamence-MixedDD (ID: 494)
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_OUTRAGE, MOVE_AEROBLAST, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_1] = { // Metagross-Scarf (ID: 393)
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REGIGIGAS_1] = { // Regigigas-Twave (ID: 394)
        .species = SPECIES_REGIGIGAS,
        .moves = {MOVE_EARTHQUAKE, MOVE_CRUSH_GRIP, MOVE_KNOCK_OFF, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRAVIARY_1] = { // Braviary-OffensiveBU (ID: 395)
        .species = SPECIES_BRAVIARY,
        .moves = {MOVE_BRAVE_BIRD, MOVE_REVENGE, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DIGGERSBY_1] = { // Diggersby-Scarf (ID: 396)
        .species = SPECIES_DIGGERSBY,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRIFBLIM_1] = { // Drifblim-AcroBlimp (ID: 397)
        .species = SPECIES_DRIFBLIM,
        .moves = {MOVE_ACROBATICS, MOVE_WILL_O_WISP, MOVE_DISABLE, MOVE_DESTINY_BOND},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOURGEIST_1] = { // Gourgeist-ExBelt (ID: 398)
        .species = SPECIES_GOURGEIST,
        .moves = {MOVE_SHADOW_BALL, MOVE_GIGA_DRAIN, MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TYPE_NULL_1] = { // Type_Null-DualSetup (ID: 399)
        .species = SPECIES_TYPE_NULL,
        .moves = {MOVE_RETURN, MOVE_SWORDS_DANCE, MOVE_IRON_DEFENSE, MOVE_REST},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RHYDON_1] = { // Rhydon-Bulky (ID: 400)
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLISCOR_1] = { // Gliscor-AcroBat (ID: 401)
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_ACROBATICS, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAWLUCHA_1] = { // Hawlucha-Roost (ID: 300)
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ACROBATICS, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RAMPARDOS_1] = { // Rampardos-AV (ID: 314)
        .species = SPECIES_RAMPARDOS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_FIRE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GASTRODON_1] = { // Gastrodon-Offensive (ID: 417)
        .species = SPECIES_GASTRODON,
        .moves = {MOVE_SCALD, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEAVILE_1] = { // Weavile-Band (ID: 403)
        .species = SPECIES_WEAVILE,
        .moves = {MOVE_KNOCK_OFF, MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_LOW_KICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TALONFLAME_1] = { // Talonflame-1attackSD (ID: 302)
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_ACROBATICS, MOVE_WILL_O_WISP, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_1] = { // Scolipede-SDpass (ID: 405)
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_BATON_PASS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FROSLASS_1] = { // Froslass-ExBelt (ID: 304)
        .species = SPECIES_FROSLASS,
        .moves = {MOVE_FROST_BREATH, MOVE_SHADOW_BALL, MOVE_DRAINING_KISS, MOVE_THUNDERBOLT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AEGISLASH_1] = { // Aegislash-3attacks (ID: 407)
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SHADOW_SNEAK, MOVE_KINGS_SHIELD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOUCANNON_1] = { // Toucannon-SD (ID: 306)
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BEAK_BLAST, MOVE_BULLET_SEED, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MIMIKYU_1] = { // Mimikyu-OffensiveCurse (ID: 409)
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_CURSE},
        .heldItem = ITEM_SPELL_TAG,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_FAN_1] = { // Rotom_Fan-Rain (ID: 308)
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_RAIN_DANCE, MOVE_HURRICANE, MOVE_THUNDER, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PANGORO_1] = { // Pangoro-Band (ID: 411)
        .species = SPECIES_PANGORO,
        .moves = {MOVE_HAMMER_ARM, MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_GUNK_SHOT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIKAVOLT_1] = { // Vikavolt-Specs (ID: 310)
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STARAPTOR_1] = { // Staraptor-Band (ID: 415)
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAMOSWINE_1] = { // Mamoswine-Band (ID: 413)
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_ICICLE_CRASH, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HONCHKROW_1] = { // Honchkrow-SuperLuck (ID: 312)
        .species = SPECIES_HONCHKROW,
        .moves = {MOVE_DRILL_PECK, MOVE_NIGHT_SLASH, MOVE_SUPERPOWER, MOVE_ROOST},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AURORUS_1] = { // Aurorus-RockPolish (ID: 316)
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_ROCK_POLISH},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIENSHAO_1] = { // Mienshao-SD (ID: 419)
        .species = SPECIES_MIENSHAO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_ACROBATICS, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMOLGA_1] = { // Emolga-Physical (ID: 318)
        .species = SPECIES_EMOLGA,
        .moves = {MOVE_ACROBATICS, MOVE_WILD_CHARGE, MOVE_U_TURN, MOVE_KNOCK_OFF},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FROST_1] = { // Rotom_Frost-Bulky (ID: 421)
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZEBSTRIKA_1] = { // Zebstrika-Band (ID: 320)
        .species = SPECIES_ZEBSTRIKA,
        .moves = {MOVE_VOLT_TACKLE, MOVE_DOUBLE_EDGE, MOVE_FLARE_BLITZ, MOVE_JUMP_KICK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TANGROWTH_1] = { // Tangrowth-AV (ID: 423)
        .species = SPECIES_TANGROWTH,
        .moves = {MOVE_GIGA_DRAIN, MOVE_KNOCK_OFF, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROSERADE_1] = { // Roserade-Defensive (ID: 322)
        .species = SPECIES_ROSERADE,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_TOXIC_SPIKES, MOVE_SYNTHESIS},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_MOW_1] = { // Rotom_Mow-Specs (ID: 425)
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_1] = { // Zoroark-Mixed (ID: 324)
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_LOW_KICK, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TREVENANT_1] = { // Trevenant-TR (ID: 427)
        .species = SPECIES_TREVENANT,
        .moves = {MOVE_WOOD_HAMMER, MOVE_REAPING_BLOW, MOVE_EARTHQUAKE, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLACEON_1] = { // Glaceon-Specs (ID: 326)
        .species = SPECIES_GLACEON,
        .moves = {MOVE_FROST_BREATH, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL, MOVE_SYNCHRONOISE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_LEAFEON_1] = { // Leafeon-Band (ID: 429)
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_RETURN, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPIRITOMB_1] = { // Spiritomb-NightShade (ID: 328)
        .species = SPECIES_SPIRITOMB,
        .moves = {MOVE_WILL_O_WISP, MOVE_NIGHT_SHADE, MOVE_STRENGTH_SAP, MOVE_PARTING_SHOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GIGALITH_1] = { // Gigalith-Curse (ID: 431)
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_STONE_EDGE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_1] = { // Lycanroc-Sub (ID: 330)
        .species = SPECIES_LYCANROC,
        .moves = {MOVE_STONE_EDGE, MOVE_DRILL_RUN, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALLADE_1] = { // Gallade-BU (ID: 433)
        .species = SPECIES_GALLADE,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_KNOCK_OFF, MOVE_BULK_UP, MOVE_WILL_O_WISP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAPION_1] = {// Drapion-SniperFellStinger (ID: 332)
        .species = SPECIES_DRAPION,
        .moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_AGILITY, MOVE_FELL_STINGER},
        .heldItem = ITEM_LANSAT_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEWEAR_1] = { // Bewear-Band (ID: 435)
        .species = SPECIES_BEWEAR,
        .moves = {MOVE_RETURN, MOVE_SUPERPOWER, MOVE_SHADOW_CLAW, MOVE_FACADE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_1] = { // Eelektross-SubCoil (ID: 334)
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_SUBSTITUTE, MOVE_COIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LOPUNNY_1] = { // Lopunny-3attacksHealingWish (ID: 437)
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_HI_JUMP_KICK, MOVE_HEALING_WISH},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_1] = { // Reuniclus-TR (ID: 336)
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEHEEYEM_1] = { // Beheeyem-CM (ID: 439)
        .species = SPECIES_BEHEEYEM,
        .moves = {MOVE_PSYCHIC, MOVE_FLASH_CANNON, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_PSYCHIC_SEED,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_Z_1] = { // Porygon_Z-Specs (ID: 338)
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TECHNO_BLAST, MOVE_DARK_PULSE, MOVE_SHADOW_BALL, MOVE_HYPER_BEAM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOIVERN_1] = { // Noivern-LifeOrb (ID: 441)
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_BOOMBURST, MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HIPPOWDON_1] = { // Hippowdon-Curse (ID: 340)
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KROOKODILE_1] = { // Krookodile-Scarf (ID: 443)
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GOLURK_1] = { // Golurk-Band (ID: 342)
        .species = SPECIES_GOLURK,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERROTHORN_1] = { // Ferrothorn-2attacks (ID: 445)
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_POWER_WHIP, MOVE_INGRAIN, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLISOPOD_1] = { // Golisopod-LifeOrb (ID: 344)
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAWITZER_1] = { // Clawitzer-Specs (ID: 447)
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_1] = { // Ambipom-GemCovet (ID: 346)
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_COVET, MOVE_STORM_THROW, MOVE_KNOCK_OFF},
        .heldItem = ITEM_NORMAL_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXICROAK_1] = { // Toxicroak-Tspikes (ID: 449)
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_TOXIC_SPIKES, MOVE_CIRCLE_THROW},
        .heldItem = ITEM_RED_CARD,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANDELURE_1] = { // Chandelure-SubCM (ID: 348)
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_1] = { // Togedemaru-Figy (ID: 451)
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_FAKE_OUT, MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_U_TURN},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DURANT_1] = { // Durant-Band (ID: 350)
        .species = SPECIES_DURANT,
        .moves = {MOVE_IRON_HEAD, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GALVANTULA_1] = { // Galvantula-Sash (ID: 453)
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_STICKY_WEB},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_1] = { // Lucario-LifeOrbNP (ID: 352)
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_1] = { // Lycanroc_Midnight-ExBelt (ID: 455)
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_STONE_EDGE, MOVE_PSYCHIC_FANGS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUDSDALE_1] = { // Mudsdale-Band (ID: 354)
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_HEAVY_SLAM, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PALOSSAND_1] = { // Palossand-1attack (ID: 457)
        .species = SPECIES_PALOSSAND,
        .moves = {MOVE_EARTH_POWER, MOVE_TOXIC, MOVE_SHORE_UP, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PYUKUMUKU_1] = { // Pyukumuku-InnardsOut (ID: 356)
        .species = SPECIES_PYUKUMUKU,
        .moves = {MOVE_PAIN_SPLIT, MOVE_TAUNT, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TURTONATOR_1] = { // Turtonator-Draco (ID: 459)
        .species = SPECIES_TURTONATOR,
        .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_DRACO_METEOR, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CONKELDURR_1] = { // Conkeldurr-SubPunch (ID: 358)
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_DUSK_1] = { // Lycanroc_Dusk-SD (ID: 461)
        .species = SPECIES_LYCANROC_DUSK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_ACCELEROCK, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_1] = { // Excadrill-SD (ID: 360)
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_JELLICENT_1] = { // Jellicent-DefensiveTaunt (ID: 463)
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_SCALD, MOVE_TAUNT, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_1] = { // Archeops-PhysicalRoost (ID: 362)
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CINCCINO_1] = { // Cinccino-Band (ID: 465)
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_ARM_THRUST, MOVE_ROCK_BLAST, MOVE_PLAY_ROUGH},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SERPERIOR_1] = { // Serperior-Specs (ID: 364)
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TSAREENA_1] = { // Tsareena-3attacks (ID: 467)
        .species = SPECIES_TSAREENA,
        .moves = {MOVE_TROP_KICK, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_1] = { // Blaziken-Special (ID: 366)
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_EE_PROTECT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAXORUS_1] = { // Haxorus-SD (ID: 469)
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TORTERRA_1] = { // Torterra-SD (ID: 368)
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_1] = { // Seismitoad-Defensive (ID: 471)
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUXRAY_1] = { // Luxray-Scarf (ID: 370)
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_1] = { // Darmanitan-Band (ID: 473)
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHESNAUGHT_1] = { // Chesnaught-Endure (ID: 372)
        .species = SPECIES_CHESNAUGHT,
        .moves = {MOVE_ENDURE, MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SYLVEON_1] = { // Sylveon-CM (ID: 475)
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_HIDDEN_POWER, MOVE_WISH, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_BISHARP_1] = { // Bisharp-StealthRock (ID: 374)
        .species = SPECIES_BISHARP,
        .moves = {MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_STEALTH_ROCK, MOVE_THUNDER_WAVE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMPOLEON_1] = { // Empoleon-Defensive (ID: 477)
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_STEALTH_ROCK, MOVE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_1] = { // Samurott-Special (ID: 376)
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_ICE_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANTRUM_1] = { // Tyrantrum-Scarf (ID: 479)
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELPHOX_1] = { // Delphox-Defensive (ID: 378)
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_MYSTICAL_FIRE, MOVE_TOXIC, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VANILLUXE_1] = { // Vanilluxe-Explosion (ID: 481)
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_EXPLOSION},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DECIDUEYE_1] = { // Decidueye-NP (ID: 380)
        .species = SPECIES_DECIDUEYE,
        .moves = {MOVE_SHADOW_BALL, MOVE_GIGA_DRAIN, MOVE_NASTY_PLOT, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_INFERNAPE_1] = { // Infernape-NP (ID: 483)
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_FOCUS_BLAST, MOVE_INFERNO, MOVE_NASTY_PLOT, MOVE_VACUUM_WAVE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMBOAR_1] = { // Emboar-Scarf (ID: 382)
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_HEAD_SMASH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_1] = { // Greninja-SpecialMixed (ID: 485)
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_GUNK_SHOT, MOVE_DARK_PULSE, MOVE_LOW_KICK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_1] = { // Salazzle-ToxicProtect (ID: 384)
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FLAMETHROWER, MOVE_TOXIC, MOVE_EE_PROTECT, MOVE_SUBSTITUTE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMARINA_1] = { // Primarina-RestTalk (ID: 487)
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_SCALD, MOVE_DRAINING_KISS, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRAGALGE_1] = { // Dragalge-Tspikes (ID: 386)
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SLUDGE_BOMB, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_1] = { // Togekiss-NP (ID: 489)
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_NASTY_PLOT, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARAQUANID_1] = { // Araquanid-Web (ID: 388)
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_STICKY_WEB, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_1] = { // Toxapex-PhysDef (ID: 491)
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_WASH_1] = { // Rotom_Wash-Scarf (ID: 390)
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_1] = { // Rotom_Heat-Bulky (ID: 493)
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_1] = { // Garchomp-FastTankChomp (ID: 392)
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_DRAGON_TAIL, MOVE_TOXIC},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KOMMO_O_1] = { // Kommo_o-DD (ID: 495)
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_OUTRAGE, MOVE_CLOSE_COMBAT, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKING_1] = { // Slaking-BU (ID: 496)
        .species = SPECIES_SLAKING,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_RETURN, MOVE_SUCKER_PUNCH, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BARBARACLE_2] = { // Barbaracle-WhiteHerb (ID: 497)
        .species = SPECIES_BARBARACLE,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_COFAGRIGUS_2] = { // Cofagrigus-TR (ID: 498)
        .species = SPECIES_COFAGRIGUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER, MOVE_TRICK_ROOM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_PASSIMIAN_2] = { // Passimian-Scarf (ID: 499)
        .species = SPECIES_PASSIMIAN,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_GUNK_SHOT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ORANGURU_2] = { // Oranguru-TR (ID: 500)
        .species = SPECIES_ORANGURU,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_TRICK_ROOM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISDREAVUS_2] = { // Misdreavus-FastCM (ID: 501)
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_SHADOW_BALL, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_MOONLIGHT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DOUBLADE_2] = { // Doublade-SD (ID: 502)
        .species = SPECIES_DOUBLADE,
        .moves = {MOVE_GYRO_BALL, MOVE_SHADOW_SNEAK, MOVE_SACRED_SWORD, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUGTRIO_2] = { // Dugtrio-HoneClaws (ID: 503)
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_ROCK_SLIDE, MOVE_HONE_CLAWS},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEDICHAM_2] = { // Medicham-SD (ID: 606)
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MISMAGIUS_2] = { // Mismagius-NP (ID: 505)
        .species = SPECIES_MISMAGIUS,
        .moves = {MOVE_MOONBLAST, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT, MOVE_MOONLIGHT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FEAROW_2] = { // Fearow-RoostSetup (ID: 608)
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_FOCUS_ENERGY, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRANBULL_2] = { // Granbull-BU (ID: 507)
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_BULK_UP, MOVE_MOONLIGHT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JYNX_2] = { // Jynx-3attacksNP (ID: 610)
        .species = SPECIES_JYNX,
        .moves = {MOVE_FROST_BREATH, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DUSKNOIR_2] = { // Dusknoir-SneakTR (ID: 509)
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_SHADOW_SNEAK, MOVE_TRICK_ROOM},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DODRIO_2] = { // Dodrio-Band (ID: 612)
        .species = SPECIES_DODRIO,
        .moves = {MOVE_BRAVE_BIRD, MOVE_RETURN, MOVE_JUMP_KICK, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MR_MIME_2] = { // Mr_Mime-NP (ID: 511)
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYSHOCK, MOVE_DAZZLING_GLEAM, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LANTURN_2] = { // Lanturn-AV (ID: 614)
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SCALD, MOVE_DISCHARGE, MOVE_ICE_BEAM, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_BRELOOM_2] = { // Breloom-Technician (ID: 513)
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_BULLET_SEED, MOVE_MACH_PUNCH, MOVE_ROCK_TOMB, MOVE_SPORE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FORRETRESS_2] = { // Forretress-TripleHazards (ID: 616)
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_GYRO_BALL, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WHISCASH_2] = { // Whiscash-DDbounce (ID: 515)
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_BOUNCE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_XATU_2] = { // Xatu-CMpass (ID: 618)
        .species = SPECIES_XATU,
        .moves = {MOVE_STORED_POWER, MOVE_CALM_MIND, MOVE_ROOST, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SKARMORY_2] = { // Skarmory-DualHazards (ID: 517)
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_WHIRLWIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAROWAK_2] = { // Marowak-SubSD (ID: 620)
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_BONEMERANG, MOVE_FIRE_PUNCH, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_QUAGSIRE_2] = { // Quagsire-CursePhysDef (ID: 519)
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CLEFABLE_2] = { // Clefable-Offensive (ID: 622)
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MOONBLAST, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SOFT_BOILED},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HARIYAMA_2] = { // Hariyama-AV (ID: 521)
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM, MOVE_STONE_EDGE},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAICHU_2] = { // Raichu-FlailReversal (ID: 624)
        .species = SPECIES_RAICHU,
        .moves = {MOVE_ENDURE, MOVE_FLAIL, MOVE_REVERSAL, MOVE_SECRET_POWER},
        .heldItem = ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DEWGONG_2] = { // Dewgong-Hail3attacks (ID: 523)
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICICLE_CRASH, MOVE_WATERFALL, MOVE_DRILL_RUN, MOVE_HAIL},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MANECTRIC_2] = { // Manectric-ExBelt (ID: 626)
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLAMETHROWER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VILEPLUME_2] = { // Vileplume-Defensive (ID: 525)
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_STRENGTH_SAP, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VICTREEBEL_2] = { // Victreebel-Sun (ID: 628)
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTRODE_2] = { // Electrode-ScreensVolt (ID: 527)
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_VOLT_SWITCH, MOVE_TAUNT},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EXPLOUD_2] = { // Exploud-Specs (ID: 630)
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHIFTRY_2] = { // Shiftry-Sun (ID: 529)
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_SOLAR_BLADE, MOVE_KNOCK_OFF, MOVE_SUNNY_DAY, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLALIE_2] = { // Glalie-Scarf (ID: 632)
        .species = SPECIES_GLALIE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_THUNDER_FANG, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUDICOLO_2] = { // Ludicolo-GigaDrain (ID: 531)
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYPNO_2] = { // Hypno-NP (ID: 634)
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLEM_2] = { // Golem-Explosion (ID: 533)
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_RHYPERIOR_2] = { // Rhyperior-Band (ID: 636)
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ICE_FANG},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALAKAZAM_2] = { // Alakazam-4attacks (ID: 535)
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_WEEZING_2] = { // Weezing-PhysDef (ID: 638)
        .species = SPECIES_WEEZING,
        .moves = {MOVE_ACID, MOVE_WILL_O_WISP, MOVE_TOXIC_SPIKES, MOVE_RECOVER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KANGASKHAN_2] = { // Kangaskhan-Crunch (ID: 537)
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ELECTIVIRE_2] = { // Electivire-BoxingGlove (ID: 640)
        .species = SPECIES_ELECTIVIRE,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_BULLET_PUNCH, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TAUROS_2] = { // Tauros-Physical (ID: 539)
        .species = SPECIES_TAUROS,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_ZEN_HEADBUTT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWBRO_2] = { // Slowbro-CM (ID: 642)
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLOWKING_2] = { // Slowking-NP (ID: 541)
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_TRICK_ROOM, MOVE_NASTY_PLOT},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MILTANK_2] = { // Miltank-Curse (ID: 644)
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_HEAL_BELL, MOVE_MILK_DRINK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ALTARIA_2] = { // Altaria-3attacksRoost (ID: 543)
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_HYPER_VOICE, MOVE_DRAGON_PULSE, MOVE_FLAMETHROWER, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NIDOQUEEN_2] = { // Nidoqueen-Offensive (ID: 646)
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_NIDOKING_2] = { // Nidoking-Scarf (ID: 545)
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGMORTAR_2] = { // Magmortar-ExBelt (ID: 648)
        .species = SPECIES_MAGMORTAR,
        .moves = {MOVE_SEARING_SHOT, MOVE_AURA_SPHERE, MOVE_THUNDERBOLT, MOVE_DRAGON_PULSE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CRADILY_2] = { // Cradily-BulkyAttacker (ID: 547)
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_GRAVEL_STORM, MOVE_EARTH_POWER, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ARMALDO_2] = { // Armaldo-LifeOrbSD (ID: 650)
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_LEECH_LIFE, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLDUCK_2] = { // Golduck-4attacks (ID: 549)
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_AQUA_JET},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAPIDASH_2] = { // Rapidash-ExBelt (ID: 652)
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLARE_BLITZ, MOVE_JUMP_KICK, MOVE_WILD_CHARGE, MOVE_HIGH_HORSEPOWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUK_2] = { // Muk-4attacks (ID: 551)
        .species = SPECIES_MUK,
        .moves = {MOVE_POISON_JAB, MOVE_HAMMER_ARM, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GENGAR_2] = { // Gengar-Scarf (ID: 654)
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMPHAROS_2] = { // Ampharos-Leftovers (ID: 553)
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_HIDDEN_POWER, MOVE_SIGNAL_BEAM, MOVE_TAIL_GLOW},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCIZOR_2] = { // Scizor-Band (ID: 656)
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_LUNGE, MOVE_KNOCK_OFF, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_HERACROSS_2] = { // Heracross-Reversal (ID: 555)
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_REVERSAL, MOVE_KNOCK_OFF, MOVE_ENDURE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ESPEON_2] = { // Espeon-StoredPower (ID: 658)
        .species = SPECIES_ESPEON,
        .moves = {MOVE_STORED_POWER, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_MORNING_SUN},
        .heldItem = ITEM_KEE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HOUNDOOM_2] = { // Houndoom-NP (ID: 557)
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DONPHAN_2] = { // Donphan-AV (ID: 660)
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_BULLDOZE, MOVE_ROCK_TOMB, MOVE_ICE_SHARD, MOVE_FLAME_WHEEL},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CLAYDOL_2] = { // Claydol-WP (ID: 559)
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYSHOCK, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_WAILORD_2] = { // Wailord-MysticWater (ID: 662)
        .species = SPECIES_WAILORD,
        .moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_BOOMBURST},
        .heldItem = ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_NINETALES_2] = { // Ninetales-FastCM (ID: 561)
        .species = SPECIES_NINETALES,
        .moves = {MOVE_DARK_VOID, MOVE_DREAM_EATER, MOVE_FLAMETHROWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MACHAMP_2] = { // Machamp-BU (ID: 664)
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_BULK_UP, MOVE_KNOCK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SHUCKLE_2] = { // Shuckle-ChestoResto (ID: 563)
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_STICKY_WEB, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STEELIX_2] = { // Steelix-RockHead (ID: 666)
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_HEAD_SMASH, MOVE_COIL},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TENTACRUEL_2] = { // Tentacruel-Offensive (ID: 565)
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AERODACTYL_2] = { // Aerodactyl-Band (ID: 668)
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_ROCK_SLIDE, MOVE_ROCK_SLIDE, MOVE_FLY, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PORYGON2_2] = { // Porygon2-Defensive (ID: 567)
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_RECOVER, MOVE_TOXIC, MOVE_ICE_BEAM},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARDEVOIR_2] = { // Gardevoir-Specs (ID: 670)
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXEGGUTOR_2] = { // Exeggutor-WP (ID: 569)
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STARMIE_2] = { // Starmie-LifeOrb (ID: 672)
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FLYGON_2] = { // Flygon-QD (ID: 571)
        .species = SPECIES_FLYGON,
        .moves = {MOVE_BOOMBURST, MOVE_DRAGON_PULSE, MOVE_QUIVER_DANCE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VENUSAUR_2] = { // Venusaur-Sun (ID: 674)
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VAPOREON_2] = { // Vaporeon-WishPass (ID: 573)
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SCALD, MOVE_WISH, MOVE_ACID_ARMOR, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JOLTEON_2] = { // Jolteon-Specs (ID: 676)
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_SIGNAL_BEAM, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FLAREON_2] = { // Flareon-Agility (ID: 575)
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_PLAY_ROUGH, MOVE_AGILITY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_2] = { // Meganium-Defensive (ID: 678)
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_LEECH_SEED, MOVE_EE_PROTECT, MOVE_WISH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_URSARING_2] = { // Ursaring-BD (ID: 577)
        .species = SPECIES_URSARING,
        .moves = {MOVE_QUICK_ATTACK, MOVE_DRAIN_PUNCH, MOVE_CRUNCH, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_UMBREON_2] = { // Umbreon-SwagCat (ID: 680)
        .species = SPECIES_UMBREON,
        .moves = {MOVE_FOUL_PLAY, MOVE_WISH, MOVE_SWAGGER, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLASTOISE_2] = { // Blastoise-BulkyAttacker (ID: 579)
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_FLASH_CANNON, MOVE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERALIGATR_2] = { // Feraligatr-DD (ID: 682)
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_LIQUIDATION, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AGGRON_2] = { // Aggron-ThunderPunch (ID: 581)
        .species = SPECIES_AGGRON,
        .moves = {MOVE_HEAVY_SLAM, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_METAL_COAT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_INCINEROAR_2] = { // Incineroar-SD (ID: 684)
        .species = SPECIES_INCINEROAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WALREIN_2] = { // Walrein-Bulky (ID: 583)
        .species = SPECIES_WALREIN,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_HYDRO_PUMP, MOVE_SLACK_OFF},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SCEPTILE_2] = { // Sceptile-Sniper (ID: 686)
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHARIZARD_2] = { // Charizard-Sun (ID: 585)
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_FOCUS_BLAST, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TYPHLOSION_2] = { // Typhlosion-Scarf (ID: 688)
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_BLAST_OFF, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_2] = { // Lapras-Specs (ID: 587)
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_SURF},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_CROBAT_2] = { // Crobat-Offensive (ID: 690)
        .species = SPECIES_CROBAT,
        .moves = {MOVE_BRAVE_BIRD, MOVE_POISON_FANG, MOVE_FIRE_FANG, MOVE_ICE_FANG},
        .heldItem = ITEM_BIG_ROOT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SWAMPERT_2] = { // Swampert-Band (ID: 589)
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_DIVE, MOVE_ICE_PUNCH, MOVE_HAMMER_ARM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GYARADOS_2] = { // Gyarados-OffensiveDD (ID: 692)
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SNORLAX_2] = { // Snorlax-Band (ID: 591)
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SELF_DESTRUCT},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KINGDRA_2] = { // Kingdra-Critdra (ID: 694)
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_FLASH_CANNON, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANSEY_2] = { // Chansey-MixedDef (ID: 593)
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_SEISMIC_TOSS, MOVE_SOFT_BOILED},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MILOTIC_2] = { // Milotic-Defensive (ID: 696)
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SCALD, MOVE_DRAGON_PULSE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCANINE_2] = { // Arcanine-Offensive (ID: 595)
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_FANG, MOVE_EXTREME_SPEED, MOVE_MORNING_SUN},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SALAMENCE_2] = { // Salamence-Specs (ID: 698)
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_AEROBLAST, MOVE_DRAGON_PULSE, MOVE_BLAST_OFF, MOVE_HYDRO_PUMP},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_2] = { // Metagross-Agility (ID: 597)
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_AGILITY},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REGIGIGAS_2] = { // Regigigas-PUP (ID: 598)
        .species = SPECIES_REGIGIGAS,
        .moves = {MOVE_EARTHQUAKE, MOVE_CRUSH_GRIP, MOVE_KNOCK_OFF, MOVE_POWER_UP_PUNCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BRAVIARY_2] = { // Braviary-BulkyBU (ID: 599)
        .species = SPECIES_BRAVIARY,
        .moves = {MOVE_BRAVE_BIRD, MOVE_REVENGE, MOVE_BULK_UP, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DIGGERSBY_2] = { // Diggersby-Band (ID: 600)
        .species = SPECIES_DIGGERSBY,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_QUICK_ATTACK, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DRIFBLIM_2] = { // Drifblim-FlareBoost (ID: 601)
        .species = SPECIES_DRIFBLIM,
        .moves = {MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER, MOVE_THUNDERBOLT, MOVE_EE_PROTECT},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 2
    },
    [FRONTIER_MON_GOURGEIST_2] = { // Gourgeist-Defensive (ID: 602)
        .species = SPECIES_GOURGEIST,
        .moves = {MOVE_SHADOW_BALL, MOVE_GIGA_DRAIN, MOVE_WILL_O_WISP, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TYPE_NULL_2] = { // Type_Null-SD (ID: 603)
        .species = SPECIES_TYPE_NULL,
        .moves = {MOVE_RETURN, MOVE_SWORDS_DANCE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RHYDON_2] = { // Rhydon-DualSetup (ID: 604)
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GLISCOR_2] = { // Gliscor-SD (ID: 605)
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_FACADE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAWLUCHA_2] = { // Hawlucha-RockSlide (ID: 504)
        .species = SPECIES_HAWLUCHA,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_WEAVILE_2] = { // Weavile-SD (ID: 607)
        .species = SPECIES_WEAVILE,
        .moves = {MOVE_KNOCK_OFF, MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TALONFLAME_2] = { // Talonflame-2attackSD (ID: 506)
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_ACROBATICS, MOVE_FLARE_BLITZ, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SCOLIPEDE_2] = { // Scolipede-OffensiveSD (ID: 609)
        .species = SPECIES_SCOLIPEDE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FROSLASS_2] = { // Froslass-Hail (ID: 508)
        .species = SPECIES_FROSLASS,
        .moves = {MOVE_HAIL, MOVE_FROST_BREATH, MOVE_SHADOW_BALL, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AEGISLASH_2] = { // Aegislash-SD (ID: 611)
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_REAPING_BLOW, MOVE_SACRED_SWORD, MOVE_SWORDS_DANCE, MOVE_KINGS_SHIELD},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOUCANNON_2] = { // Toucannon-Scarf (ID: 510)
        .species = SPECIES_TOUCANNON,
        .moves = {MOVE_BEAK_BLAST, MOVE_FLARE_BLITZ, MOVE_STEEL_WING, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MIMIKYU_2] = { // Mimikyu-SD (ID: 613)
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_REAPING_BLOW, MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_FAN_2] = { // Rotom_Fan-Scarf (ID: 512)
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_HYPER_VOICE, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_PANGORO_2] = { // Pangoro-SD (ID: 615)
        .species = SPECIES_PANGORO,
        .moves = {MOVE_HAMMER_ARM, MOVE_SUCKER_PUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIKAVOLT_2] = { // Vikavolt-ShellBell (ID: 514)
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_THUNDERBOLT, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_ROOST},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MAMOSWINE_2] = { // Mamoswine-LifeOrb (ID: 617)
        .species = SPECIES_MAMOSWINE,
        .moves = {MOVE_ICICLE_CRASH, MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HONCHKROW_2] = { // Honchkrow-Scarf (ID: 516)
        .species = SPECIES_HONCHKROW,
        .moves = {MOVE_BRAVE_BIRD, MOVE_NIGHT_SLASH, MOVE_SUPERPOWER, MOVE_DRILL_PECK},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARAPTOR_2] = { // Staraptor-Scarf (ID: 619)
        .species = SPECIES_STARAPTOR,
        .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAMPARDOS_2] = { // Rampardos-Reckless (ID: 518)
        .species = SPECIES_RAMPARDOS,
        .moves = {MOVE_HEAD_SMASH, MOVE_AVALANCHE, MOVE_HAMMER_ARM, MOVE_ACROBATICS},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GASTRODON_2] = { // Gastrodon-Defensive (ID: 621)
        .species = SPECIES_GASTRODON,
        .moves = {MOVE_SCALD, MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_AURORUS_2] = { // Aurorus-AuroraVeil (ID: 520)
        .species = SPECIES_AURORUS,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_AURORA_VEIL},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MIENSHAO_2] = { // Mienshao-Scarf (ID: 623)
        .species = SPECIES_MIENSHAO,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_EMOLGA_2] = { // Emolga-Special (ID: 522)
        .species = SPECIES_EMOLGA,
        .moves = {MOVE_TAILWIND, MOVE_AIR_SLASH, MOVE_VOLT_SWITCH, MOVE_ENCORE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_FROST_2] = { // Rotom_Frost-Scarf (ID: 625)
        .species = SPECIES_ROTOM_FROST,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_ZEBSTRIKA_2] = { // Zebstrika-LifeOrb (ID: 524)
        .species = SPECIES_ZEBSTRIKA,
        .moves = {MOVE_VOLT_TACKLE, MOVE_DOUBLE_EDGE, MOVE_FLARE_BLITZ, MOVE_JUMP_KICK},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TANGROWTH_2] = { // Tangrowth-PhysDef (ID: 627)
        .species = SPECIES_TANGROWTH,
        .moves = {MOVE_GIGA_DRAIN, MOVE_KNOCK_OFF, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROSERADE_2] = { // Roserade-Offensive (ID: 526)
        .species = SPECIES_ROSERADE,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_LEAF_STORM, MOVE_ACID, MOVE_TOXIC_SPIKES},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_MOW_2] = { // Rotom_Mow-Scarf (ID: 629)
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ZOROARK_2] = { // Zoroark-NP (ID: 528)
        .species = SPECIES_ZOROARK,
        .moves = {MOVE_DARK_PULSE, MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TREVENANT_2] = { // Trevenant-Band (ID: 631)
        .species = SPECIES_TREVENANT,
        .moves = {MOVE_WOOD_HAMMER, MOVE_REAPING_BLOW, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GLACEON_2] = { // Glaceon-Hail (ID: 530)
        .species = SPECIES_GLACEON,
        .moves = {MOVE_BLIZZARD, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL, MOVE_HAIL},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_LEAFEON_2] = { // Leafeon-SD (ID: 633)
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_KNOCK_OFF, MOVE_RETURN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_YACHE_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SPIRITOMB_2] = { // Spiritomb-Curse (ID: 532)
        .species = SPECIES_SPIRITOMB,
        .moves = {MOVE_WILL_O_WISP, MOVE_CURSE, MOVE_STRENGTH_SAP, MOVE_PARTING_SHOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GIGALITH_2] = { // Gigalith-Bulky (ID: 635)
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_LYCANROC_2] = { // Lycanroc-Accelerock (ID: 534)
        .species = SPECIES_LYCANROC,
        .moves = {MOVE_STONE_EDGE, MOVE_DRILL_RUN, MOVE_ACCELEROCK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALLADE_2] = { // Gallade-SD (ID: 637)
        .species = SPECIES_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAPION_2] = { // Drapion-SniperSubstitute (ID: 536)
        .species = SPECIES_DRAPION,
        .moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_AGILITY, MOVE_SUBSTITUTE},
        .heldItem = ITEM_LANSAT_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEWEAR_2] = { // Bewear-SD (ID: 639)
        .species = SPECIES_BEWEAR,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_DRAIN_PUNCH, MOVE_SHADOW_CLAW, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EELEKTROSS_2] = { // Eelektross-ExBelt (ID: 538)
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_THUNDERBOLT, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FLAMETHROWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LOPUNNY_2] = { // Lopunny-4attacks (ID: 641)
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_RETURN, MOVE_HI_JUMP_KICK, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_SACHET,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_REUNICLUS_2] = { // Reuniclus-CM (ID: 540)
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_BEHEEYEM_2] = { // Beheeyem-TR (ID: 643)
        .species = SPECIES_BEHEEYEM,
        .moves = {MOVE_PSYCHIC, MOVE_FLASH_CANNON, MOVE_SIGNAL_BEAM, MOVE_TRICK_ROOM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PORYGON_Z_2] = { // Porygon_Z-DualSetup (ID: 542)
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_TECHNO_BLAST, MOVE_DARK_PULSE, MOVE_AGILITY, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NOIVERN_2] = { // Noivern-Specs (ID: 645)
        .species = SPECIES_NOIVERN,
        .moves = {MOVE_BOOMBURST, MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HIPPOWDON_2] = { // Hippowdon-Defensive (ID: 544)
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_WHIRLWIND, MOVE_SLACK_OFF, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KROOKODILE_2] = { // Krookodile-Band (ID: 647)
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_SUPERPOWER},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GOLURK_2] = { // Golurk-BoxingGlove (ID: 546)
        .species = SPECIES_GOLURK,
        .moves = {MOVE_REAPING_BLOW, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_FERROTHORN_2] = { // Ferrothorn-Spikes (ID: 649)
        .species = SPECIES_FERROTHORN,
        .moves = {MOVE_GYRO_BALL, MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_CURSE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOLISOPOD_2] = { // Golisopod-SilverPowder (ID: 548)
        .species = SPECIES_GOLISOPOD,
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_LEECH_LIFE, MOVE_AQUA_JET},
        .heldItem = ITEM_SILVER_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CLAWITZER_2] = { // Clawitzer-ExBelt (ID: 651)
        .species = SPECIES_CLAWITZER,
        .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_DARK_PULSE},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_AMBIPOM_2] = { // Ambipom-DualPriority (ID: 550)
        .species = SPECIES_AMBIPOM,
        .moves = {MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_STORM_THROW, MOVE_KNOCK_OFF},
        .heldItem = ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXICROAK_2] = { // Toxicroak-SD (ID: 653)
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_POISON_JAB, MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CHANDELURE_2] = { // Chandelure-Specs (ID: 552)
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_2] = { // Togedemaru-Band (ID: 655)
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DURANT_2] = { // Durant-LifeOrb (ID: 554)
        .species = SPECIES_DURANT,
        .moves = {MOVE_BUG_BITE, MOVE_THUNDER_FANG, MOVE_ICE_FANG, MOVE_SUPERPOWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GALVANTULA_2] = { // Galvantula-LifeOrb (ID: 657)
        .species = SPECIES_GALVANTULA,
        .moves = {MOVE_THUNDER, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN, MOVE_STICKY_WEB},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUCARIO_2] = { // Lucario-SashNP (ID: 556)
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_VACUUM_WAVE, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LYCANROC_MIDNIGHT_2] = { // Lycanroc_Midnight-WP (ID: 659)
        .species = SPECIES_LYCANROC_MIDNIGHT,
        .moves = {MOVE_POWER_TRIP, MOVE_DRAIN_PUNCH, MOVE_BULK_UP, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MUDSDALE_2] = { // Mudsdale-Defensive (ID: 558)
        .species = SPECIES_MUDSDALE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_STEALTH_ROCK, MOVE_TOXIC},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_PALOSSAND_2] = { // Palossand-2attack (ID: 661)
        .species = SPECIES_PALOSSAND,
        .moves = {MOVE_EARTH_POWER, MOVE_SHADOW_BALL, MOVE_SHORE_UP, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PYUKUMUKU_2] = { // Pyukumuku-PPstall (ID: 560)
        .species = SPECIES_PYUKUMUKU,
        .moves = {MOVE_BLOCK, MOVE_RECOVER, MOVE_SPITE, MOVE_TAUNT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TURTONATOR_2] = { // Turtonator-Focus (ID: 663)
        .species = SPECIES_TURTONATOR,
        .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_FOCUS_BLAST, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CONKELDURR_2] = { // Conkeldurr-SheerForce (ID: 562)
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LYCANROC_DUSK_2] = { // Lycanroc_Dusk-4attacks (ID: 665)
        .species = SPECIES_LYCANROC_DUSK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_ACCELEROCK, MOVE_DRILL_RUN, MOVE_FIRE_FANG},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EXCADRILL_2] = { // Excadrill-Sand (ID: 564)
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SANDSTORM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_JELLICENT_2] = { // Jellicent-DefensiveHex (ID: 667)
        .species = SPECIES_JELLICENT,
        .moves = {MOVE_SCALD, MOVE_HEX, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARCHEOPS_2] = { // Archeops-Mixed (ID: 566)
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_EARTH_POWER, MOVE_HEAT_WAVE},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CINCCINO_2] = { // Cinccino-KingsRock (ID: 669)
        .species = SPECIES_CINCCINO,
        .moves = {MOVE_TAIL_SLAP, MOVE_ARM_THRUST, MOVE_ROCK_BLAST, MOVE_BULLET_SEED},
        .heldItem = ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SERPERIOR_2] = { // Serperior-GlareSeed (ID: 568)
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_GLARE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_TSAREENA_2] = { // Tsareena-Band (ID: 671)
        .species = SPECIES_TSAREENA,
        .moves = {MOVE_TROP_KICK, MOVE_HI_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_2] = { // Blaziken-Scarf (ID: 570)
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_BLAST_OFF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_HAXORUS_2] = { // Haxorus-DD (ID: 673)
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TORTERRA_2] = { // Torterra-RockPolish (ID: 572)
        .species = SPECIES_TORTERRA,
        .moves = {MOVE_WOOD_HAMMER, MOVE_LANDS_WRATH, MOVE_ROCK_SLIDE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SEISMITOAD_2] = { // Seismitoad-Rain (ID: 675)
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUXRAY_2] = { // Luxray-ExBelt (ID: 574)
        .species = SPECIES_LUXRAY,
        .moves = {MOVE_THUNDER_FANG, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_FIRE_FANG},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DARMANITAN_2] = { // Darmanitan-Scarf (ID: 677)
        .species = SPECIES_DARMANITAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHESNAUGHT_2] = { // Chesnaught-Spiky (ID: 576)
        .species = SPECIES_CHESNAUGHT,
        .moves = {MOVE_SPIKES, MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SYLVEON_2] = { // Sylveon-Specs (ID: 679)
        .species = SPECIES_SYLVEON,
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_BISHARP_2] = { // Bisharp-SD (ID: 578)
        .species = SPECIES_BISHARP,
        .moves = {MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH, MOVE_IRON_HEAD, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMPOLEON_2] = { // Empoleon-LifeOrb (ID: 681)
        .species = SPECIES_EMPOLEON,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GRASS_KNOT, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SAMUROTT_2] = { // Samurott-Physical (ID: 580)
        .species = SPECIES_SAMUROTT,
        .moves = {MOVE_SACRED_SWORD, MOVE_WATERFALL, MOVE_KNOCK_OFF, MOVE_SHELL_SMASH},
        .heldItem = ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANTRUM_2] = { // Tyrantrum-DD (ID: 683)
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELPHOX_2] = { // Delphox-CM (ID: 582)
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_GRASS_KNOT, MOVE_CALM_MIND},
        .heldItem = ITEM_COLBUR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VANILLUXE_2] = { // Vanilluxe-HPfire (ID: 685)
        .species = SPECIES_VANILLUXE,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_ICE_SHARD, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_HASTY,
        .ivs = 30,
        .ability = 1
    },
    [FRONTIER_MON_DECIDUEYE_2] = { // Decidueye-Sniper (ID: 584)
        .species = SPECIES_DECIDUEYE,
        .moves = {MOVE_LEAF_BLADE, MOVE_SPIRIT_SHACKLE, MOVE_SHADOW_SNEAK, MOVE_FOCUS_ENERGY},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_INFERNAPE_2] = { // Infernape-ExBelt (ID: 687)
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_INFERNO, MOVE_STONE_EDGE, MOVE_GUNK_SHOT},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_EMBOAR_2] = { // Emboar-ExBelt (ID: 586)
        .species = SPECIES_EMBOAR,
        .moves = {MOVE_FLARE_BLITZ, MOVE_SUBMISSION, MOVE_WILD_CHARGE, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_2] = { // Greninja-ExBelt (ID: 689)
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_GRASS_KNOT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_SALAZZLE_2] = { // Salazzle-NP (ID: 588)
        .species = SPECIES_SALAZZLE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_PRIMARINA_2] = { // Primarina-ExBelt (ID: 691)
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_MOONBLAST, MOVE_SPARKLING_ARIA, MOVE_ICE_BEAM, MOVE_ENERGY_BALL},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DRAGALGE_2] = { // Dragalge-Specs (ID: 590)
        .species = SPECIES_DRAGALGE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SLUDGE_WAVE, MOVE_ACID, MOVE_DRACO_METEOR},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_2] = { // Togekiss-Twave (ID: 693)
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_THUNDER_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ARAQUANID_2] = { // Araquanid-Curse (ID: 592)
        .species = SPECIES_ARAQUANID,
        .moves = {MOVE_LIQUIDATION, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_2] = { // Toxapex-SpDef (ID: 695)
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ROTOM_WASH_2] = { // Rotom_Wash-Bulky (ID: 594)
        .species = SPECIES_ROTOM_WASH,
        .moves = {MOVE_HYDRO_PUMP, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_HEAT_2] = { // Rotom_Heat-Specs (ID: 697)
        .species = SPECIES_ROTOM_HEAT,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_2] = { // Garchomp-Scarf (ID: 596)
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_POISON_JAB},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_KOMMO_O_2] = { // Kommo_o-BD (ID: 699)
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_THUNDER_PUNCH, MOVE_BELLY_DRUM, MOVE_SUBSTITUTE},
        .heldItem = ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKING_2] = { // Slaking-BulkyAttacker (ID: 700)
        .species = SPECIES_SLAKING,
        .moves = {MOVE_RETURN, MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_SLACK_OFF},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_COBALION_1] = { // Cobalion-Defensive (ID: 701)
        .species = SPECIES_COBALION,
        .moves = {MOVE_SACRED_SWORD, MOVE_STEALTH_ROCK, MOVE_THUNDER_WAVE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TERRAKION_1] = { // Terrakion-ExBelt (ID: 702)
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_X_SCISSOR},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIRIZION_1] = { // Virizion-ExBelt (ID: 703)
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_HORN_LEECH, MOVE_ROCK_SLIDE, MOVE_X_SCISSOR},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_1] = { // Raikou-Scarf (ID: 704)
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_1] = { // Entei-Curse (ID: 705)
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_1] = { // Suicune-RestTalk (ID: 706)
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ROAR, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HEATRAN_1] = { // Heatran-StallBreaker (ID: 707)
        .species = SPECIES_HEATRAN,
        .moves = {MOVE_MAGMA_STORM, MOVE_EARTH_POWER, MOVE_TAUNT, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_1] = { // Regirock-PUP (ID: 708)
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_POWER_UP_PUNCH, MOVE_RECOVER},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_1] = { // Regice-SpDefHaze (ID: 709)
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_HAZE, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_1] = { // Registeel-PhysDefRestTalk (ID: 710)
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_TOXIC, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_1] = { // Latias-DualScreens (ID: 711)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_DRACO_METEOR, MOVE_HEALING_WISH},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_1] = { // Latios-DualScreens (ID: 712)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_DRACO_METEOR, MOVE_MEMENTO},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_COBALION_2] = { // Cobalion-Band (ID: 713)
        .species = SPECIES_COBALION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TERRAKION_2] = { // Terrakion-Scarf (ID: 714)
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VIRIZION_2] = { // Virizion-Band (ID: 715)
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LEAF_BLADE, MOVE_ROCK_SLIDE, MOVE_X_SCISSOR},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_2] = { // Raikou-ChestoResto (ID: 716)
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_2] = { // Entei-Charcoal (ID: 717)
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLAME_CHARGE, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_CHARCOAL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_2] = { // Suicune-AV (ID: 718)
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_MIRROR_COAT, MOVE_SHEER_COLD},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HEATRAN_2] = { // Heatran-AirBalloon (ID: 719)
        .species = SPECIES_HEATRAN,
        .moves = {MOVE_FLAMETHROWER, MOVE_FLASH_CANNON, MOVE_EARTH_POWER, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_AIR_BALLOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_2] = { // Regirock-Twave (ID: 720)
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_THUNDER_WAVE, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_2] = { // Regice-ZoomLens (ID: 721)
        .species = SPECIES_REGICE,
        .moves = {MOVE_BLIZZARD, MOVE_THUNDER, MOVE_FOCUS_BLAST, MOVE_RECOVER},
        .heldItem = ITEM_ZOOM_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_2] = { // Registeel-PhysDef (ID: 722)
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_2] = { // Latias-SubRoost (ID: 723)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRAGON_PULSE, MOVE_SUBSTITUTE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_2] = { // Latios-4attacks (ID: 724)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_COBALION_3] = { // Cobalion-SubBU (ID: 725)
        .species = SPECIES_COBALION,
        .moves = {MOVE_SACRED_SWORD, MOVE_IRON_HEAD, MOVE_SUBSTITUTE, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TERRAKION_3] = { // Terrakion-DualSetup (ID: 726)
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ROCK_SLIDE, MOVE_ROCK_POLISH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VIRIZION_3] = { // Virizion-3attacksCM (ID: 727)
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_AURA_SPHERE, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_3] = { // Raikou-AV (ID: 728)
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_3] = { // Entei-FastAV (ID: 729)
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLAME_CHARGE, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_3] = { // Suicune-SubCM (ID: 730)
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HEATRAN_3] = { // Heatran-Specs (ID: 731)
        .species = SPECIES_HEATRAN,
        .moves = {MOVE_OVERHEAT, MOVE_FLASH_CANNON, MOVE_EARTH_POWER, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_3] = { // Regirock-ExplosionWP (ID: 732)
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_3] = { // Regice-ShellBell (ID: 733)
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_3] = { // Registeel-ChestoResto (ID: 734)
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_3] = { // Latias-Scarf (ID: 735)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_3] = { // Latios-DragonGem (ID: 736)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_DRAGON_GEM,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_COBALION_4] = { // Cobalion-SubCM (ID: 737)
        .species = SPECIES_COBALION,
        .moves = {MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TERRAKION_4] = { // Terrakion-Band (ID: 738)
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VIRIZION_4] = { // Virizion-SD (ID: 739)
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_HORN_LEECH, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_4] = { // Raikou-3attacksCM (ID: 740)
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_4] = { // Entei-JollyBand (ID: 741)
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_4] = { // Suicune-3attacksCM (ID: 742)
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_HEATRAN_4] = { // Heatran-Scarf (ID: 743)
        .species = SPECIES_HEATRAN,
        .moves = {MOVE_OVERHEAT, MOVE_FLASH_CANNON, MOVE_EARTH_POWER, MOVE_FLAMETHROWER},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_4] = { // Regirock-Bulky (ID: 744)
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAIN_PUNCH, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_4] = { // Regice-SpDefThunderbolt (ID: 745)
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_TOXIC, MOVE_RECOVER},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_4] = { // Registeel-SpDefRestTalk (ID: 746)
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_TOXIC, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_4] = { // Latias-1attackCM (ID: 747)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_CHARM, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_4] = { // Latios-Scarf (ID: 748)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_GENGAR_3] = { // Gengar-Hex (ID: 749)
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEX, MOVE_FOCUS_BLAST, MOVE_WILL_O_WISP},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANDELURE_3] = { // Chandelure-TR (ID: 750)
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_TRICK_ROOM},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GENGAR_4] = { // Gengar-Specs (ID: 751)
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_CHANDELURE_4] = { // Chandelure-Scarf (ID: 752)
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_OVERHEAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ESPEON_3] = { // Espeon-Specs (ID: 753)
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 2
    },
    [FRONTIER_MON_LUCARIO_3] = { // Lucario-BoxingGloveSD (ID: 754)
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_METEOR_MASH, MOVE_DRAIN_PUNCH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BOXING_GLOVE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_ESPEON_4] = { // Espeon-CM (ID: 755)
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_MORNING_SUN},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LUCARIO_4] = { // Lucario-LifeOrbSD (ID: 756)
        .species = SPECIES_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_BULLET_PUNCH, MOVE_EXTREME_SPEED, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MACHAMP_3] = { // Machamp-Band (ID: 757)
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_HEAVY_SLAM},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CONKELDURR_3] = { // Conkeldurr-Guts (ID: 758)
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_FACADE},
        .heldItem = ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MACHAMP_4] = { // Machamp-AV (ID: 759)
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_CONKELDURR_4] = { // Conkeldurr-AV (ID: 760)
        .species = SPECIES_CONKELDURR,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_POISON_JAB},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GARDEVOIR_3] = { // Gardevoir-BulkyCM (ID: 761)
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_DRAINING_KISS, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SERPERIOR_3] = { // Serperior-3attacks (ID: 762)
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_DRAGON_PULSE, MOVE_GLARE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_GARDEVOIR_4] = { // Gardevoir-Scarf (ID: 763)
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYSHOCK, MOVE_MOONBLAST, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SERPERIOR_4] = { // Serperior-SubSeed (ID: 764)
        .species = SPECIES_SERPERIOR,
        .moves = {MOVE_LEAF_STORM, MOVE_HIDDEN_POWER, MOVE_SUBSTITUTE, MOVE_LEECH_SEED},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 25,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_3] = { // Starmie-Specs (ID: 765)
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_3] = { // Blaziken-SashSD (ID: 766)
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_BLAZE_KICK, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_STARMIE_4] = { // Starmie-ExBelt (ID: 767)
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BLAZIKEN_4] = { // Blaziken-LifeOrbSD (ID: 768)
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_FLARE_BLITZ, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_3] = { // Lapras-OHKO (ID: 769)
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_3] = { // Greninja-PhysicalMixed (ID: 770)
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ACROBATICS, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_LOW_KICK},
        .heldItem = ITEM_FLYING_GEM,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_LAPRAS_4] = { // Lapras-OffensiveCM (ID: 771)
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GRENINJA_4] = { // Greninja-SpecialLifeOrb (ID: 772)
        .species = SPECIES_GRENINJA,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_SHURIKEN, MOVE_DARK_PULSE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_SNORLAX_3] = { // Snorlax-RestTalk (ID: 773)
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TOGEKISS_3] = { // Togekiss-Scarf (ID: 774)
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_DAZZLING_GLEAM, MOVE_FLAMETHROWER, MOVE_AURA_SPHERE},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SNORLAX_4] = { // Snorlax-Earthquake (ID: 775)
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_EARTHQUAKE, MOVE_RECYCLE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOGEKISS_4] = { // Togekiss-TwaveNP (ID: 776)
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_AIR_SLASH, MOVE_NASTY_PLOT, MOVE_THUNDER_WAVE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_SALAMENCE_3] = { // Salamence-DD (ID: 777)
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FLY, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GARCHOMP_3] = { // Garchomp-LifeOrbSD (ID: 778)
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SALAMENCE_4] = { // Salamence-3attacksRoost (ID: 779)
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_PULSE, MOVE_AEROBLAST, MOVE_FIRE_BLAST, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_GARCHOMP_4] = { // Garchomp-LumSD (ID: 780)
        .species = SPECIES_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_METAGROSS_3] = { // Metagross-Band (ID: 781)
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KOMMO_O_3] = { // Kommo_o-Special (ID: 782)
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_CLANGING_SCALES, MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_METAGROSS_4] = { // Metagross-AV (ID: 783)
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_KOMMO_O_4] = { // Kommo_o-SpecialScarf (ID: 784)
        .species = SPECIES_KOMMO_O,
        .moves = {MOVE_CLANGING_SCALES, MOVE_FOCUS_BLAST, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_5] = { // Regirock-StealthRock (ID: 785)
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_STEALTH_ROCK, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_RECOVER},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGIROCK_6] = { // Regirock-DrainPunchWP (ID: 786)
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_DRAIN_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_5] = { // Regice-Bulky (ID: 787)
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_RECOVER},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_6] = { // Regice-ExBelt (ID: 788)
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_ROCK_POLISH},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_5] = { // Registeel-SpDef (ID: 789)
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_BURST, MOVE_SEISMIC_TOSS, MOVE_TOXIC, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGISTEEL_6] = { // Registeel-Curse (ID: 790)
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_5] = { // Latias-BoltBeamCM (ID: 791)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_6] = { // Latias-Specs (ID: 792)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_7] = { // Latias-3attacksRoost (ID: 793)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIAS_8] = { // Latias-StabCM (ID: 794)
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 30,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_5] = { // Latios-2attacksCM (ID: 795)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRAGON_PULSE, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_6] = { // Latios-3attacksCM (ID: 796)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_7] = { // Latios-Specs (ID: 797)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_SURF, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_LATIOS_8] = { // Latios-3attacksRoost (ID: 798)
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_HIDDEN_POWER, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 27,
        .ability = 0
    },
    [FRONTIER_MON_DRAGONITE_1] = { // Dragonite-Parashuffler (ID: 799)
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_THUNDER_WAVE, MOVE_DRAGON_TAIL, MOVE_SUBSTITUTE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOODRA_1] = { // Goodra-Scarf (ID: 803)
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRACO_METEOR, MOVE_SLUDGE_BOMB, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_2] = { // Dragonite-BulkyDD (ID: 800)
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_FLY, MOVE_DRAGON_DANCE, MOVE_SUBSTITUTE, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOODRA_2] = { // Goodra-Defensive (ID: 804)
        .species = SPECIES_GOODRA,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DRAGONITE_3] = { // Dragonite-Band (ID: 801)
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_FLY, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOODRA_3] = { // Goodra-Specs (ID: 805)
        .species = SPECIES_GOODRA,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DRACO_METEOR, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_VOLCARONA_1] = { // Volcarona-LifeOrbHPground (ID: 807)
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_HIDDEN_POWER, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_VOLCARONA_2] = { // Volcarona-SashHPground (ID: 808)
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_BUG_BUZZ, MOVE_HIDDEN_POWER, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 29,
        .ability = 2
    },
    [FRONTIER_MON_DRAGONITE_4] = { // Dragonite-OffensiveDD (ID: 802)
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_FLY, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOODRA_4] = { // Goodra-AV (ID: 806)
        .species = SPECIES_GOODRA,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DRACO_METEOR, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_TYRANITAR_1] = { // Tyranitar-Band (ID: 815)
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYDREIGON_1] = { // Hydreigon-Specs (ID: 811)
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_2] = { // Tyranitar-Curse (ID: 816)
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_REST, MOVE_CURSE},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYDREIGON_2] = { // Hydreigon-4attacks (ID: 812)
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_3] = { // Tyranitar-BulkyDD (ID: 817)
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_DRAGON_DANCE, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYDREIGON_3] = { // Hydreigon-3attacksRoost (ID: 813)
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, MOVE_ROOST},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VOLCARONA_3] = { // Volcarona-Bulky (ID: 809)
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_ROOST, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VOLCARONA_4] = { // Volcarona-LifeOrbBugBuzz (ID: 810)
        .species = SPECIES_VOLCARONA,
        .moves = {MOVE_FIRE_BLAST, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYRANITAR_4] = { // Tyranitar-OffensiveDD (ID: 818)
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HYDREIGON_4] = { // Hydreigon-Scarf (ID: 814)
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRAGON_PULSE, MOVE_FLASH_CANNON, MOVE_FIRE_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_COBALION_5] = { // Cobalion-SD (ID: 819)
        .species = SPECIES_COBALION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KELDEO_1] = { // Keldeo-Specs (ID: 822)
        .species = SPECIES_KELDEO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_HYDRO_PUMP, MOVE_SECRET_SWORD, MOVE_SCALD},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TERRAKION_5] = { // Terrakion-SD (ID: 820)
        .species = SPECIES_TERRAKION,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KELDEO_3] = { // Keldeo-SubCM (ID: 824)
        .species = SPECIES_KELDEO,
        .moves = {MOVE_SCALD, MOVE_SECRET_SWORD, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VIRIZION_5] = { // Virizion-BU (ID: 821)
        .species = SPECIES_VIRIZION,
        .moves = {MOVE_SACRED_SWORD, MOVE_HORN_LEECH, MOVE_ROCK_SLIDE, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_KELDEO_2] = { // Keldeo-3attacksCM (ID: 823)
        .species = SPECIES_KELDEO,
        .moves = {MOVE_FOCUS_BLAST, MOVE_HYDRO_PUMP, MOVE_SECRET_SWORD, MOVE_CALM_MIND},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAIKOU_5] = { // Raikou-Specs (ID: 825)
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_AURA_SPHERE, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAIKOU_6] = { // Raikou-SubCM (ID: 826)
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_SUBSTITUTE, MOVE_CALM_MIND},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_5] = { // Entei-BulkyAV (ID: 827)
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_EXTREME_SPEED, MOVE_STOMPING_TANTRUM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ENTEI_6] = { // Entei-AdamantBand (ID: 828)
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_STONE_EDGE, MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_5] = { // Suicune-ChestoResto (ID: 829)
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .heldItem = ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SUICUNE_6] = { // Suicune-CroCune (ID: 830)
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_CALM_MIND, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HEATRAN_5] = { // Heatran-AV (ID: 831)
        .species = SPECIES_HEATRAN,
        .moves = {MOVE_LAVA_PLUME, MOVE_FLASH_CANNON, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_HEATRAN_6] = { // Heatran-Defensive (ID: 832)
        .species = SPECIES_HEATRAN,
        .moves = {MOVE_LAVA_PLUME, MOVE_EARTH_POWER, MOVE_TOXIC, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TRUBBISH] = { // Trubbish-Attract (ID: 833)
        .species = SPECIES_TRUBBISH,
        .moves = {MOVE_ATTRACT, MOVE_TOXIC_SPIKES, MOVE_SPIKES, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SLAKOTH_1] = { // Slakoth-Roar (ID: 834)
        .species = SPECIES_SLAKOTH,
        .moves = {MOVE_ROAR_OF_TIME, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLAKOTH_2] = { // Slakoth-Doom (ID: 835)
        .species = SPECIES_SLAKOTH,
        .moves = {MOVE_DOOM_DESIRE, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_VENUSAUR_1] = { // Mega_Venusaur-Defensive (ID: 836)
        .species = SPECIES_MEGA_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_VENUSAURITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_VENUSAUR_2] = { // Mega_Venusaur-Offensive (ID: 837)
        .species = SPECIES_MEGA_VENUSAUR,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_SYNTHESIS},
        .heldItem = ITEM_VENUSAURITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_CHARIZARD_X_1] = { // Mega_Charizard_X-DD (ID: 838)
        .species = SPECIES_MEGA_CHARIZARD_X,
        .moves = {MOVE_FLARE_BLITZ, MOVE_DRAGON_CLAW, MOVE_DRAGON_DANCE, MOVE_ROOST},
        .heldItem = ITEM_CHARIZARDITE_X,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_CHARIZARD_X_2] = { // Mega_Charizard_X-SD (ID: 839)
        .species = SPECIES_MEGA_CHARIZARD_X,
        .moves = {MOVE_FLARE_BLITZ, MOVE_DRAGON_CLAW, MOVE_FLAME_CHARGE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_CHARIZARDITE_X,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_CHARIZARD_Y_1] = { // Mega_Charizard_Y-3attacks (ID: 840)
        .species = SPECIES_MEGA_CHARIZARD_Y,
        .moves = {MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_FOCUS_BLAST, MOVE_ROOST},
        .heldItem = ITEM_CHARIZARDITE_Y,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_CHARIZARD_Y_2] = { // Mega_Charizard_Y-4attacks (ID: 841)
        .species = SPECIES_MEGA_CHARIZARD_Y,
        .moves = {MOVE_FLAMETHROWER, MOVE_BLAST_BURN, MOVE_SOLAR_BEAM, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHARIZARDITE_Y,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_BLASTOISE_1] = { // Mega_Blastoise-Defensive (ID: 842)
        .species = SPECIES_MEGA_BLASTOISE,
        .moves = {MOVE_FLASH_CANNON, MOVE_SCALD, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_BLASTOISINITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_BLASTOISE_2] = { // Mega_Blastoise-Offensive (ID: 843)
        .species = SPECIES_MEGA_BLASTOISE,
        .moves = {MOVE_FLASH_CANNON, MOVE_HYDRO_PUMP, MOVE_AURA_SPHERE, MOVE_HYDRO_CANNON},
        .heldItem = ITEM_BLASTOISINITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_BEEDRILL_1] = { // Mega_Beedrill-4attacks (ID: 844)
        .species = SPECIES_MEGA_BEEDRILL,
        .moves = {MOVE_U_TURN, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_X_SCISSOR},
        .heldItem = ITEM_BEEDRILLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_BEEDRILL_2] = { // Mega_Beedrill-SD (ID: 845)
        .species = SPECIES_MEGA_BEEDRILL,
        .moves = {MOVE_X_SCISSOR, MOVE_POISON_JAB, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BEEDRILLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_PIDGEOT_1] = { // Mega_Pidgeot-WorkUp (ID: 846)
        .species = SPECIES_MEGA_PIDGEOT,
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_ROOST, MOVE_WORK_UP},
        .heldItem = ITEM_PIDGEOTITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_PIDGEOT_2] = { // Mega_Pidgeot-HyperBeam (ID: 847)
        .species = SPECIES_MEGA_PIDGEOT,
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_ROOST, MOVE_HYPER_BEAM},
        .heldItem = ITEM_PIDGEOTITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_ALAKAZAM_1] = { // Mega_Alakazam-3attacks (ID: 848)
        .species = SPECIES_MEGA_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_RECOVER},
        .heldItem = ITEM_ALAKAZITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_ALAKAZAM_2] = { // Mega_Alakazam-CM (ID: 849)
        .species = SPECIES_MEGA_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_ALAKAZITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SLOWBRO_1] = { // Mega_Slowbro-CM (ID: 850)
        .species = SPECIES_MEGA_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_SLOWBRONITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SLOWBRO_2] = { // Mega_Slowbro-Offensive (ID: 851)
        .species = SPECIES_MEGA_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_RECOVER},
        .heldItem = ITEM_SLOWBRONITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_GENGAR_1] = { // Mega_Gengar-Offensive (ID: 852)
        .species = SPECIES_MEGA_GENGAR,
        .moves = {MOVE_SLUDGE_WAVE, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_DESTINY_BOND},
        .heldItem = ITEM_GENGARITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_GENGAR_2] = { // Mega_Gengar-PerishTrap (ID: 853)
        .species = SPECIES_MEGA_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_PERISH_SONG, MOVE_EE_PROTECT, MOVE_SUBSTITUTE},
        .heldItem = ITEM_GENGARITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_KANGASKHAN_1] = { // Mega_Kangaskhan-IcePunch (ID: 854)
        .species = SPECIES_MEGA_KANGASKHAN,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_KANGASKHANITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_KANGASKHAN_2] = { // Mega_Kangaskhan-SuckerPunch (ID: 855)
        .species = SPECIES_MEGA_KANGASKHAN,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_KANGASKHANITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_PINSIR_1] = { // Mega_Pinsir-CloseCombat (ID: 856)
        .species = SPECIES_MEGA_PINSIR,
        .moves = {MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_CLOSE_COMBAT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_PINSIRITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_PINSIR_2] = { // Mega_Pinsir-Earthquake (ID: 857)
        .species = SPECIES_MEGA_PINSIR,
        .moves = {MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_PINSIRITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_GYARADOS_1] = { // Mega_Gyarados-IceFang (ID: 858)
        .species = SPECIES_MEGA_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_GYARADOSITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_GYARADOS_2] = { // Mega_Gyarados-Crunch (ID: 859)
        .species = SPECIES_MEGA_GYARADOS,
        .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_GYARADOSITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_AERODACTYL_1] = { // Mega_Aerodactyl-4attacks (ID: 860)
        .species = SPECIES_MEGA_AERODACTYL,
        .moves = {MOVE_FLY, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_THUNDER_FANG},
        .heldItem = ITEM_AERODACTYLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_AERODACTYL_2] = { // Mega_Aerodactyl-3attacksRoost (ID: 861)
        .species = SPECIES_MEGA_AERODACTYL,
        .moves = {MOVE_FLY, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROOST},
        .heldItem = ITEM_AERODACTYLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_MEWTWO_X_1] = { // Mega_Mewtwo_X-4attacks (ID: 862)
        .species = SPECIES_MEGA_MEWTWO_X,
        .moves = {MOVE_LOW_KICK, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_MEWTWONITE_X,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_MEWTWO_X_2] = { // Mega_Mewtwo_X-BU (ID: 863)
        .species = SPECIES_MEGA_MEWTWO_X,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_BULK_UP, MOVE_RECOVER},
        .heldItem = ITEM_MEWTWONITE_X,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_MEWTWO_Y_1] = { // Mega_Mewtwo_Y-4attacks (ID: 864)
        .species = SPECIES_MEGA_MEWTWO_Y,
        .moves = {MOVE_PSYSTRIKE, MOVE_FOCUS_BLAST, MOVE_ICE_BEAM, MOVE_FIRE_BLAST},
        .heldItem = ITEM_MEWTWONITE_Y,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_MEWTWO_Y_2] = { // Mega_Mewtwo_Y-CM (ID: 865)
        .species = SPECIES_MEGA_MEWTWO_Y,
        .moves = {MOVE_PSYSTRIKE, MOVE_FOCUS_BLAST, MOVE_CALM_MIND, MOVE_RECOVER},
        .heldItem = ITEM_MEWTWONITE_Y,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_AMPHAROS_1] = { // Mega_Ampharos-TailGlow (ID: 866)
        .species = SPECIES_MEGA_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_DRAGON_PULSE, MOVE_FOCUS_BLAST, MOVE_TAIL_GLOW},
        .heldItem = ITEM_AMPHAROSITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_AMPHAROS_2] = { // Mega_Ampharos-DualSetup (ID: 867)
        .species = SPECIES_MEGA_AMPHAROS,
        .moves = {MOVE_PARABOLIC_CHARGE, MOVE_DRAGON_PULSE, MOVE_TAIL_GLOW, MOVE_AGILITY},
        .heldItem = ITEM_AMPHAROSITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_STEELIX_1] = { // Mega_Steelix-Curse3attacks (ID: 868)
        .species = SPECIES_MEGA_STEELIX,
        .moves = {MOVE_GYRO_BALL, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_CURSE},
        .heldItem = ITEM_STEELIXITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_STEELIX_2] = { // Mega_Steelix-CurseRestTalk (ID: 869)
        .species = SPECIES_MEGA_STEELIX,
        .moves = {MOVE_GYRO_BALL, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_STEELIXITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_SCIZOR_1] = { // Mega_Scizor-Curse (ID: 870)
        .species = SPECIES_MEGA_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_QUICK_ATTACK, MOVE_CURSE, MOVE_ROOST},
        .heldItem = ITEM_SCIZORITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SCIZOR_2] = { // Mega_Scizor-SD (ID: 871)
        .species = SPECIES_MEGA_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_SCIZORITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_HERACROSS_1] = { // Mega_Heracross-4attacks (ID: 872)
        .species = SPECIES_MEGA_HERACROSS,
        .moves = {MOVE_PIN_MISSILE, MOVE_CLOSE_COMBAT, MOVE_ROCK_BLAST, MOVE_BULLET_SEED},
        .heldItem = ITEM_HERACRONITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_HERACROSS_2] = { // Mega_Heracross-SD (ID: 873)
        .species = SPECIES_MEGA_HERACROSS,
        .moves = {MOVE_PIN_MISSILE, MOVE_CLOSE_COMBAT, MOVE_ROCK_BLAST, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_HERACRONITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_HOUNDOOM_1] = { // Mega_Houndoom-SludgeBombNP (ID: 874)
        .species = SPECIES_MEGA_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB, MOVE_NASTY_PLOT},
        .heldItem = ITEM_HOUNDOOMINITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_HOUNDOOM_2] = { // Mega_Houndoom-OverheatNP (ID: 875)
        .species = SPECIES_MEGA_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARK_PULSE, MOVE_OVERHEAT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_HOUNDOOMINITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_TYRANITAR_1] = { // Mega_Tyranitar-DD (ID: 876)
        .species = SPECIES_MEGA_TYRANITAR,
        .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_TYRANITAR_2] = { // Mega_Tyranitar-4attacks (ID: 877)
        .species = SPECIES_MEGA_TYRANITAR,
        .moves = {MOVE_STONE_EDGE, MOVE_CRUNCH, MOVE_ICE_PUNCH, MOVE_SUPERPOWER},
        .heldItem = ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_SCEPTILE_1] = { // Mega_Sceptile-EarthquakeSD (ID: 878)
        .species = SPECIES_MEGA_SCEPTILE,
        .moves = {MOVE_DUAL_CHOP, MOVE_BULLET_SEED, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCEPTILITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_SCEPTILE_2] = { // Mega_Sceptile-DoubleKickSD (ID: 879)
        .species = SPECIES_MEGA_SCEPTILE,
        .moves = {MOVE_DUAL_CHOP, MOVE_BULLET_SEED, MOVE_DOUBLE_KICK, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCEPTILITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_BLAZIKEN_1] = { // Mega_Blaziken-SD (ID: 880)
        .species = SPECIES_MEGA_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_FLARE_BLITZ, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_BLAZIKENITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_BLAZIKEN_2] = { // Mega_Blaziken-Mixed (ID: 881)
        .species = SPECIES_MEGA_BLAZIKEN,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_OVERHEAT, MOVE_ROCK_SLIDE, MOVE_EE_PROTECT},
        .heldItem = ITEM_BLAZIKENITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SWAMPERT_1] = { // Mega_Swampert-Rain (ID: 882)
        .species = SPECIES_MEGA_SWAMPERT,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_RAIN_DANCE},
        .heldItem = ITEM_SWAMPERTITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_SWAMPERT_2] = { // Mega_Swampert-RestTalk (ID: 883)
        .species = SPECIES_MEGA_SWAMPERT,
        .moves = {MOVE_DIVE, MOVE_EARTHQUAKE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_SWAMPERTITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_GARDEVOIR_1] = { // Mega_Gardevoir-CM (ID: 884)
        .species = SPECIES_MEGA_GARDEVOIR,
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_CALM_MIND},
        .heldItem = ITEM_GARDEVOIRITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_GARDEVOIR_2] = { // Mega_Gardevoir-4attacks (ID: 885)
        .species = SPECIES_MEGA_GARDEVOIR,
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_HYPER_BEAM},
        .heldItem = ITEM_GARDEVOIRITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_SABLEYE_1] = { // Mega_Sableye-Defensive (ID: 886)
        .species = SPECIES_MEGA_SABLEYE,
        .moves = {MOVE_KNOCK_OFF, MOVE_REAPING_BLOW, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_SABLENITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SABLEYE_2] = { // Mega_Sableye-CM (ID: 887)
        .species = SPECIES_MEGA_SABLEYE,
        .moves = {MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_WILL_O_WISP, MOVE_RECOVER},
        .heldItem = ITEM_SABLENITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_MAWILE_1] = { // Mega_Mawile-4attacks (ID: 888)
        .species = SPECIES_MEGA_MAWILE,
        .moves = {MOVE_PLAY_ROUGH, MOVE_FIRE_FANG, MOVE_STONE_EDGE, MOVE_IRON_HEAD},
        .heldItem = ITEM_MAWILITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_MAWILE_2] = { // Mega_Mawile-SubPunch (ID: 889)
        .species = SPECIES_MEGA_MAWILE,
        .moves = {MOVE_PLAY_ROUGH, MOVE_SECRET_POWER, MOVE_SUBSTITUTE, MOVE_FOCUS_PUNCH},
        .heldItem = ITEM_MAWILITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_AGGRON_1] = { // Mega_Aggron-RestTalk (ID: 890)
        .species = SPECIES_MEGA_AGGRON,
        .moves = {MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_AGGRONITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_AGGRON_2] = { // Mega_Aggron-Offensive (ID: 891)
        .species = SPECIES_MEGA_AGGRON,
        .moves = {MOVE_HEAVY_SLAM, MOVE_BULLET_PUNCH, MOVE_OUTRAGE, MOVE_EARTHQUAKE},
        .heldItem = ITEM_AGGRONITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_MEDICHAM_1] = { // Mega_Medicham-DualSTAB (ID: 892)
        .species = SPECIES_MEGA_MEDICHAM,
        .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_ICE_PUNCH},
        .heldItem = ITEM_MEDICHAMITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_MEDICHAM_2] = { // Mega_Medicham-DualPriority (ID: 893)
        .species = SPECIES_MEGA_MEDICHAM,
        .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_BULLET_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_MEDICHAMITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_MANECTRIC_1] = { // Mega_Manectric-Overheat (ID: 894)
        .species = SPECIES_MEGA_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_OVERHEAT, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_MANECTITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_MANECTRIC_2] = { // Mega_Manectric-Flamethrower (ID: 895)
        .species = SPECIES_MEGA_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_FLAMETHROWER, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_MANECTITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_SHARPEDO_1] = { // Mega_Sharpedo-DestinyBond (ID: 896)
        .species = SPECIES_MEGA_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_DESTINY_BOND, MOVE_EE_PROTECT},
        .heldItem = ITEM_SHARPEDONITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SHARPEDO_2] = { // Mega_Sharpedo-3attacks (ID: 897)
        .species = SPECIES_MEGA_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_PSYCHIC_FANGS, MOVE_POISON_FANG, MOVE_EE_PROTECT},
        .heldItem = ITEM_SHARPEDONITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_CAMERUPT_1] = { // Mega_Camerupt-4attacks (ID: 898)
        .species = SPECIES_MEGA_CAMERUPT,
        .moves = {MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_CAMERUPTITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 28,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_CAMERUPT_2] = { // Mega_Camerupt-RestTalk (ID: 899)
        .species = SPECIES_MEGA_CAMERUPT,
        .moves = {MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_CAMERUPTITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_ALTARIA_1] = { // Mega_Altaria-OffensiveDD (ID: 900)
        .species = SPECIES_MEGA_ALTARIA,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_ROOST},
        .heldItem = ITEM_ALTARIANITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_ALTARIA_2] = { // Mega_Altaria-BulkyDD (ID: 901)
        .species = SPECIES_MEGA_ALTARIA,
        .moves = {MOVE_RETURN, MOVE_DRAGON_DANCE, MOVE_COTTON_GUARD, MOVE_ROOST},
        .heldItem = ITEM_ALTARIANITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_BANETTE_1] = { // Mega_Banette-Offensive (ID: 902)
        .species = SPECIES_MEGA_BANETTE,
        .moves = {MOVE_REAPING_BLOW, MOVE_KNOCK_OFF, MOVE_SHADOW_SNEAK, MOVE_DESTINY_BOND},
        .heldItem = ITEM_BANETTITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_BANETTE_2] = { // Mega_Banette-Bulky (ID: 903)
        .species = SPECIES_MEGA_BANETTE,
        .moves = {MOVE_REAPING_BLOW, MOVE_KNOCK_OFF, MOVE_DESTINY_BOND, MOVE_WILL_O_WISP},
        .heldItem = ITEM_BANETTITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_ABSOL_1] = { // Mega_Absol-4attacks (ID: 904)
        .species = SPECIES_MEGA_ABSOL,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_SUCKER_PUNCH, MOVE_SUPERPOWER},
        .heldItem = ITEM_ABSOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_ABSOL_2] = { // Mega_Absol-SD (ID: 905)
        .species = SPECIES_MEGA_ABSOL,
        .moves = {MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_ABSOLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_GLALIE_1] = { // Mega_Glalie-IceShard (ID: 906)
        .species = SPECIES_MEGA_GLALIE,
        .moves = {MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_THUNDER_FANG, MOVE_ICE_SHARD},
        .heldItem = ITEM_GLALITITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_GLALIE_2] = { // Mega_Glalie-Earthquake (ID: 907)
        .species = SPECIES_MEGA_GLALIE,
        .moves = {MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_THUNDER_FANG, MOVE_EARTHQUAKE},
        .heldItem = ITEM_GLALITITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SALAMENCE_1] = { // Mega_Salamence-Special (ID: 908)
        .species = SPECIES_MEGA_SALAMENCE,
        .moves = {MOVE_AEROBLAST, MOVE_DRACO_METEOR, MOVE_BLAST_OFF, MOVE_ROOST},
        .heldItem = ITEM_SALAMENCITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_SALAMENCE_2] = { // Mega_Salamence-DD (ID: 909)
        .species = SPECIES_MEGA_SALAMENCE,
        .moves = {MOVE_FLY, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_ROOST},
        .heldItem = ITEM_SALAMENCITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_METAGROSS_1] = { // Mega_Metagross-4attacks (ID: 910)
        .species = SPECIES_MEGA_METAGROSS,
        .moves = {MOVE_HEAVY_SLAM, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_METAGROSSITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_METAGROSS_2] = { // Mega_Metagross-Agility (ID: 911)
        .species = SPECIES_MEGA_METAGROSS,
        .moves = {MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_POWER_UP_PUNCH, MOVE_AGILITY},
        .heldItem = ITEM_METAGROSSITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_LATIAS_1] = { // Mega_Latias-BulkyCM (ID: 912)
        .species = SPECIES_MEGA_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_SURF, MOVE_CALM_MIND, MOVE_ROOST},
        .heldItem = ITEM_LATIASITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_LATIAS_2] = { // Mega_Latias-OffensiveCM (ID: 913)
        .species = SPECIES_MEGA_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_SHADOW_BALL, MOVE_DRACO_METEOR, MOVE_CALM_MIND},
        .heldItem = ITEM_LATIASITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_LATIOS_1] = { // Mega_Latios-3attacksRoost (ID: 914)
        .species = SPECIES_MEGA_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_DRACO_METEOR, MOVE_EARTHQUAKE, MOVE_ROOST},
        .heldItem = ITEM_LATIOSITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_LATIOS_2] = { // Mega_Latios-CM (ID: 915)
        .species = SPECIES_MEGA_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_SHADOW_BALL, MOVE_DRACO_METEOR, MOVE_CALM_MIND},
        .heldItem = ITEM_LATIASITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMAL_GROUDON_1] = { // Primal_Groudon-DualSetup (ID: 916)
        .species = SPECIES_PRIMAL_GROUDON,
        .moves = {MOVE_PRECIPICE_BLADES, MOVE_FIRE_PUNCH, MOVE_SWORDS_DANCE, MOVE_ROCK_POLISH},
        .heldItem = ITEM_RED_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMAL_GROUDON_2] = { // Primal_Groudon-RestTalk (ID: 917)
        .species = SPECIES_PRIMAL_GROUDON,
        .moves = {MOVE_PRECIPICE_BLADES, MOVE_FIRE_PUNCH, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_RED_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMAL_KYOGRE_1] = { // Primal_Kyogre-CM (ID: 918)
        .species = SPECIES_PRIMAL_KYOGRE,
        .moves = {MOVE_ORIGIN_PULSE, MOVE_HURRICANE, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_BLUE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_PRIMAL_KYOGRE_2] = { // Primal_Kyogre-RestTalk (ID: 919)
        .species = SPECIES_PRIMAL_KYOGRE,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_BLUE_ORB,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_RAYQUAZA_1] = { // Mega_Rayquaza-DD (ID: 920)
        .species = SPECIES_MEGA_RAYQUAZA,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_RAYQUAZA_2] = { // Mega_Rayquaza-Band (ID: 921)
        .species = SPECIES_MEGA_RAYQUAZA,
        .moves = {MOVE_DRAGON_ASCENT, MOVE_V_CREATE, MOVE_EXTREME_SPEED, MOVE_EARTHQUAKE},
        .heldItem = ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_LOPUNNY_1] = { // Mega_Lopunny-4attacks (ID: 922)
        .species = SPECIES_MEGA_LOPUNNY,
        .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_PLAY_ROUGH, MOVE_SECRET_POWER},
        .heldItem = ITEM_LOPUNNITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_LOPUNNY_2] = { // Mega_Lopunny-HealingWish (ID: 923)
        .species = SPECIES_MEGA_LOPUNNY,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_PLAY_ROUGH, MOVE_SECRET_POWER, MOVE_HEALING_WISH},
        .heldItem = ITEM_LOPUNNITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 29,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_GARCHOMP_1] = { // Mega_Garchomp-SD (ID: 924)
        .species = SPECIES_MEGA_GARCHOMP,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SUBSTITUTE},
        .heldItem = ITEM_GARCHOMPITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_GARCHOMP_2] = { // Mega_Garchomp-Mixed (ID: 925)
        .species = SPECIES_MEGA_GARCHOMP,
        .moves = {MOVE_DRACO_METEOR, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST, MOVE_STONE_EDGE},
        .heldItem = ITEM_GARCHOMPITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_NAIVE,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_LUCARIO_1] = { // Mega_Lucario-SD (ID: 926)
        .species = SPECIES_MEGA_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LUCARIONITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_LUCARIO_2] = { // Mega_Lucario-4attacks (ID: 927)
        .species = SPECIES_MEGA_LUCARIO,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_ICE_PUNCH},
        .heldItem = ITEM_LUCARIONITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_ABOMASNOW_1] = { // Mega_Abomasnow-Mixed (ID: 928)
        .species = SPECIES_MEGA_ABOMASNOW,
        .moves = {MOVE_BLIZZARD, MOVE_ICE_SHARD, MOVE_GIGA_DRAIN, MOVE_EARTHQUAKE},
        .heldItem = ITEM_ABOMASITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_ABOMASNOW_2] = { // Mega_Abomasnow-SD (ID: 929)
        .species = SPECIES_MEGA_ABOMASNOW,
        .moves = {MOVE_WOOD_HAMMER, MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_ABOMASITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_GALLADE_1] = { // Mega_Gallade-SD (ID: 930)
        .species = SPECIES_MEGA_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_GALLADITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_GALLADE_2] = { // Mega_Gallade-BU (ID: 931)
        .species = SPECIES_MEGA_GALLADE,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_BULK_UP},
        .heldItem = ITEM_GALLADITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_AUDINO_1] = { // Mega_Audino-BulkyCM (ID: 932)
        .species = SPECIES_MEGA_AUDINO,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_REST, MOVE_SLEEP_TALK},
        .heldItem = ITEM_AUDINITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_AUDINO_2] = { // Mega_Audino-OffensiveCM (ID: 933)
        .species = SPECIES_MEGA_AUDINO,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_FIRE_BLAST, MOVE_SURF, MOVE_CALM_MIND},
        .heldItem = ITEM_AUDINITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_MEGA_DIANCIE_1] = { // Mega_Diancie-3attacksCM (ID: 934)
        .species = SPECIES_MEGA_DIANCIE,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_POWER_GEM, MOVE_EARTH_POWER, MOVE_CALM_MIND},
        .heldItem = ITEM_DIANCITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_DIANCIE_2] = { // Mega_Diancie-MagnetRiseCM (ID: 935)
        .species = SPECIES_MEGA_DIANCIE,
        .moves = {MOVE_DAZZLING_GLEAM, MOVE_EARTH_POWER, MOVE_CALM_MIND, MOVE_MAGNET_RISE},
        .heldItem = ITEM_DIANCITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ARIADOS_HYPER_OFFENSE] = { // (ID: 936)
        .species = SPECIES_ARIADOS,
        .moves = {MOVE_STICKY_WEB, MOVE_TOXIC_SPIKES, MOVE_MEGAHORN, MOVE_TOXIC_THREAD},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXICROAK_HYPER_OFFENSE] = { // (ID: 937)
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ZANGOOSE_HYPER_OFFENSE] = { // (ID: 938)
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_FACADE, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_EE_PROTECT},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_AURORUS_OFFENSE] = { // (ID: 939)
        .species = SPECIES_AURORUS,
        .moves = {MOVE_AURORA_VEIL, MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_EARTH_POWER},
        .heldItem = ITEM_LIGHT_CLAY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BEARTIC_OFFENSE] = { // (ID: 940)
        .species = SPECIES_BEARTIC,
        .moves = {MOVE_ICE_SHARD, MOVE_MACH_PUNCH, MOVE_AQUA_JET, MOVE_BELLY_DRUM},
        .heldItem = ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_GALLADE_OFFENSE] = { // (ID: 941)
        .species = SPECIES_GALLADE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_ICE_PUNCH, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_GALLADITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TYPHLOSION_BALANCE] = { // (ID: 942)
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_EARTH_POWER, MOVE_GRAVEL_STORM, MOVE_BLAST_OFF},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_FERALIGATR_BALANCE] = { // (ID: 943)
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_LIQUIDATION, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_DRAGON_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VENUSAUR_BALANCE] = { // (ID: 944)
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ACID, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 30,
        .ability = 2
    },
    [FRONTIER_MON_SWAMPERT_BULKY_OFFENSE] = { // (ID: 945)
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_DIVE, MOVE_AVALANCHE, MOVE_MIRROR_COAT},
        .heldItem = ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RHYDON_BULKY_OFFENSE] = { // (ID: 946)
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_DRAGON_TAIL, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGANIUM_BULKY_OFFENSE] = { // (ID: 947)
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_MOONBLAST, MOVE_WISH, MOVE_EE_PROTECT, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_REGICE_STALL] = { // (ID: 948)
        .species = SPECIES_REGICE,
        .moves = {MOVE_GLACIATE, MOVE_TOXIC, MOVE_HAZE, MOVE_RECOVER},
        .heldItem = ITEM_DRY_ICE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SLOWBRO_STALL] = { // (ID: 949)
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_SLACK_OFF, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GLISCOR_STALL] = { // (ID: 950)
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_EARTHQUAKE, MOVE_FACADE, MOVE_SWORDS_DANCE, MOVE_ROOST},
        .heldItem = ITEM_TOXIC_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_WALREIN_HAIL] = { // (ID: 957)
        .species = SPECIES_WALREIN,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_HYDRO_PUMP, MOVE_SLACK_OFF},
        .heldItem = ITEM_ICY_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DEWGONG_HAIL] = { // (ID: 958)
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICICLE_CRASH, MOVE_LIQUIDATION, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_RAIKOU_HAIL] = { // (ID: 959)
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_WEATHER_BALL, MOVE_AURA_SPHERE, MOVE_HIDDEN_POWER},
        .heldItem = ITEM_EXPERT_BELT,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_LAPRAS_RAIN] = { // (ID: 960)
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FROST_BREATH, MOVE_THUNDER, MOVE_CALM_MIND},
        .heldItem = ITEM_DAMP_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SEISMITOAD_RAIN] = { // (ID: 961)
        .species = SPECIES_SEISMITOAD,
        .moves = {MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_DRAIN_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ROTOM_FAN_RAIN] = { // (ID: 962)
        .species = SPECIES_ROTOM_FAN,
        .moves = {MOVE_THUNDER, MOVE_HURRICANE, MOVE_HIDDEN_POWER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 29,
        .ability = 0
    },
    [FRONTIER_MON_MAGCARGO_SUN] = { // (ID: 963)
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_FIRE_BLAST, MOVE_GRAVEL_STORM, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
        .heldItem = ITEM_HEAT_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_VICTREEBEL_SUN] = { // (ID: 964)
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_MEGA_HOUNDOOM_SUN] = { // (ID: 965)
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARK_PULSE, MOVE_OVERHEAT, MOVE_NASTY_PLOT},
        .heldItem = ITEM_HOUNDOOMINITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_GIGALITH_SANDSTORM] = { // (ID: 966)
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_EXPLOSION},
        .heldItem = ITEM_SMOOTH_ROCK,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_EXCADRILL_SANDSTORM] = { // (ID: 967)
        .species = SPECIES_EXCADRILL,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_STOUTLAND_SANDSTORM] = { // (ID: 968)
        .species = SPECIES_STOUTLAND,
        .moves = {MOVE_RETURN, MOVE_HIGH_HORSEPOWER, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_ROTOM_MOW_GRASSY_TERRAIN] = { // (ID: 969)
        .species = SPECIES_ROTOM_MOW,
        .moves = {MOVE_LEAF_STORM, MOVE_DISCHARGE, MOVE_VOLT_SWITCH, MOVE_WILL_O_WISP},
        .heldItem = ITEM_TERRAIN_EXTENDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_GOGOAT_GRASSY_TERRAIN] = { // (ID: 970)
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_HORN_LEECH, MOVE_HIGH_HORSEPOWER, MOVE_ROCK_SLIDE, MOVE_BULK_UP},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_SEVIPER_GRASSY_TERRAIN] = { // (ID: 971)
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_NASTY_PLOT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_BEHEEYEM_PSYCHIC_TERRAIN] = { // (ID: 972)
        .species = SPECIES_BEHEEYEM,
        .moves = {MOVE_PSYCHIC, MOVE_HIDDEN_POWER, MOVE_SHADOW_BALL, MOVE_NASTY_PLOT},
        .heldItem = ITEM_TERRAIN_EXTENDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 27,
        .ability = 1
    },
    [FRONTIER_MON_DELPHOX_PSYCHIC_TERRAIN] = { // (ID: 973)
        .species = SPECIES_DELPHOX,
        .moves = {MOVE_PSYCHIC, MOVE_PSYSHOCK, MOVE_FLAMETHROWER, MOVE_DAZZLING_GLEAM},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MEGA_SHARPEDO_PSYCHIC_TERRAIN] = { // (ID: 974)
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_PSYCHIC_FANGS, MOVE_BUG_BITE, MOVE_EE_PROTECT},
        .heldItem = ITEM_SHARPEDONITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_OCTILLERY_TRICK_ROOM] = { // (ID: 975)
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_ENERGY_BALL, MOVE_SLUDGE_BOMB, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WIKI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_DARMANITAN_ZEN_TRICK_ROOM] = { // (ID: 976)
        .species = SPECIES_DARMANITAN_ZEN,
        .moves = {MOVE_PSYCHIC, MOVE_GRAVEL_STORM, MOVE_FOCUS_BLAST, MOVE_TRICK_ROOM},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_RAMPARDOS_TRICK_ROOM] = { // (ID: 977)
        .species = SPECIES_RAMPARDOS,
        .moves = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_HAMMER_ARM, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_FIGY_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_JOLTEON_BATON_PASS] = { // (ID: 978)
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_EE_PROTECT, MOVE_SUBSTITUTE, MOVE_WORK_UP, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_VAPOREON_BATON_PASS] = { // (ID: 979)
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_ACID_ARMOR, MOVE_WORK_UP, MOVE_WISH, MOVE_BATON_PASS},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_ESPEON_BATON_PASS] = { // (ID: 980)
        .species = SPECIES_ESPEON,
        .moves = {MOVE_STORED_POWER, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND, MOVE_MORNING_SUN},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_TOXICROAK_GIMMICK] = { // (ID: 981)
        .species = SPECIES_TOXICROAK,
        .moves = {MOVE_GUNK_SHOT, MOVE_DRAIN_PUNCH, MOVE_TOXIC_SPIKES, MOVE_CIRCLE_THROW},
        .heldItem = ITEM_RED_CARD,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOXAPEX_GIMMICK] = { // (ID: 982)
        .species = SPECIES_TOXAPEX,
        .moves = {MOVE_TOXIC, MOVE_VENOSHOCK, MOVE_VENOM_DRENCH, MOVE_RECOVER},
        .heldItem = ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SKARMORY_GIMMICK] = { // (ID: 983)
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SKY_DROP, MOVE_WHIRLWIND, MOVE_ROOST, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_NINJASK_EGGTACTICAL] = { // (ID: 984)
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SONIC_BOOM, MOVE_DRILL_RUN, MOVE_EE_PROTECT, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_SCIZOR_EGGTACTICAL] = { // (ID: 985)
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_BULLET_PUNCH, MOVE_LUNGE, MOVE_ROOST, MOVE_SWORDS_DANCE},
        .heldItem = ITEM_SCIZORITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 1
    },
    [FRONTIER_MON_UMBREON_EGGTACTICAL] = { // (ID: 986)
        .species = SPECIES_UMBREON,
        .moves = {MOVE_TOXIC, MOVE_FOUL_PLAY, MOVE_WISH, MOVE_EE_PROTECT},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_DELIBIRD_MASOCHIST] = { // (ID: 987)
        .species = SPECIES_DELIBIRD,
        .moves = {MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_DRILL_PECK, MOVE_BRICK_BREAK},
        .heldItem = ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_DUNSPARCE_MASOCHIST] = { // (ID: 988)
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_HEADBUTT, MOVE_GLARE, MOVE_COIL, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_LUVDISC_MASOCHIST] = { // (ID: 989)
        .species = SPECIES_LUVDISC,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HIDDEN_POWER, MOVE_RAIN_DANCE},
        .heldItem = ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .ivs = 28,
        .ability = 0
    },
    [FRONTIER_MON_HIPPOWDON_FEAR] = { // (ID: 990)
        .species = SPECIES_HIPPOWDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROCK_SLIDE, MOVE_SLACK_OFF},
        .heldItem = ITEM_SMOOTH_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .ivs = 31,
        .ability = 0
    },
    [FRONTIER_MON_TOGEDEMARU_FEAR] = { // (ID: 991)
        .species = SPECIES_TOGEDEMARU,
        .moves = {MOVE_ENDEAVOR, MOVE_SPIKY_SHIELD, MOVE_TOXIC, MOVE_ENCORE},
        .heldItem = ITEM_SHELL_BELL,
        .evSpread = 0,
        .nature = NATURE_TIMID,
        .ivs = 31,
        .ability = 2
    },
    [FRONTIER_MON_MAGNEMITE_FEAR] = { // (ID: 992)
        .species = SPECIES_MAGNEMITE,
        .moves = {MOVE_THUNDER_WAVE, MOVE_SWAGGER, MOVE_RECYCLE, MOVE_MAGIC_COAT},
        .heldItem = ITEM_BERRY_JUICE,
        .evSpread = 0,
        .nature = NATURE_HASTY,
        .ivs = 31,
        .ability = 1
    }
};
