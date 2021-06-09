#ifndef GUARD_CONSTANTS_FLAGS_H
#define GUARD_CONSTANTS_FLAGS_H

#include "constants/opponents.h"

// Temporary Flags
// These temporary flags are are cleared every time a map is loaded. They are used
// for things like shortening an NPCs introduction text if the player already spoke
// to them once.
#define TEMP_FLAGS_START 0x0
#define FLAG_TEMP_1      (TEMP_FLAGS_START + 0x1)
#define FLAG_TEMP_2      (TEMP_FLAGS_START + 0x2)
#define FLAG_TEMP_3      (TEMP_FLAGS_START + 0x3)
#define FLAG_TEMP_4      (TEMP_FLAGS_START + 0x4)
#define FLAG_TEMP_5      (TEMP_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_TEMP_6      (TEMP_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_TEMP_7      (TEMP_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_TEMP_8      (TEMP_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_TEMP_9      (TEMP_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_TEMP_A      (TEMP_FLAGS_START + 0xA)  // Unused Flag
#define FLAG_TEMP_B      (TEMP_FLAGS_START + 0xB)  // Unused Flag
#define FLAG_TEMP_C      (TEMP_FLAGS_START + 0xC)  // Unused Flag
#define FLAG_TEMP_D      (TEMP_FLAGS_START + 0xD)  // Unused Flag
#define FLAG_TEMP_E      (TEMP_FLAGS_START + 0xE)  // Unused Flag
#define FLAG_TEMP_F      (TEMP_FLAGS_START + 0xF)  // Unused Flag
#define FLAG_TEMP_10     (TEMP_FLAGS_START + 0x10) // Unused Flag
#define FLAG_TEMP_11     (TEMP_FLAGS_START + 0x11)
#define FLAG_TEMP_12     (TEMP_FLAGS_START + 0x12)
#define FLAG_TEMP_13     (TEMP_FLAGS_START + 0x13)
#define FLAG_TEMP_14     (TEMP_FLAGS_START + 0x14)
#define FLAG_TEMP_15     (TEMP_FLAGS_START + 0x15)
#define FLAG_TEMP_16     (TEMP_FLAGS_START + 0x16)
#define FLAG_TEMP_17     (TEMP_FLAGS_START + 0x17)
#define FLAG_TEMP_18     (TEMP_FLAGS_START + 0x18)
#define FLAG_TEMP_19     (TEMP_FLAGS_START + 0x19)
#define FLAG_TEMP_1A     (TEMP_FLAGS_START + 0x1A)
#define FLAG_TEMP_1B     (TEMP_FLAGS_START + 0x1B)
#define FLAG_TEMP_1C     (TEMP_FLAGS_START + 0x1C)
#define FLAG_TEMP_1D     (TEMP_FLAGS_START + 0x1D)
#define FLAG_TEMP_1E     (TEMP_FLAGS_START + 0x1E)
#define FLAG_TEMP_1F     (TEMP_FLAGS_START + 0x1F)
#define TEMP_FLAGS_END   FLAG_TEMP_1F

#define FLAG_RYU_LT_RIVAL2                   0x20
#define FLAG_RYU_LT_RIVAL                    0x21
#define FLAG_HIDE_CHAMPIONS_ROOM_STEVEN      0x22
#define FLAG_RYU_STARTER_CHOSEN              0x23
#define FLAG_RYU_AQUA_HIDE_MH4_COURTNEY_BOSS 0x24
#define FLAG_RYU_MH_COURTNEY_SOLOMODE        0x25
#define FLAG_HIDE_BRENDANS_HOUSE_BRENDAN     0x26
#define FLAG_RYU_HAS_WAYSTONE                0x27
#define FLAG_HIDE_DAWNS_HOUSE_DAWN           0x28
#define FLAG_RYU_KYOGRE                      0x29
#define FLAG_HIDE_103_TEST_TRAINER           0x2A
#define FLAG_RYU_SCIENTIST_DONE              0x2B
#define FLAG_RYU_RANDOMIZE_MUSIC             0x2C
#define FLAG_RYU_HIDE_R120_LANA_AND_HIKER    0x2D
#define FLAG_RYU_HIDE_REL_OBJECTS            0x2E
#define FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE3 0x2F
#define FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE 0x30
#define FLAG_RYU_DEVON_CORPORATE_HIDE_SCIENTIST 0x31
#define FLAG_RYU_DEVON_CORPORATE_HIDE_MSITO  0x32
#define FLAG_RYU_WAYSTONE_DISABLED           0x33
#define FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE4 0x34
#define FLAG_RYU_DEFEATED_SS                 0x35
#define FLAG_RYU_HIDE_LANETTE_BASEMENT       0x36
#define FLAG_RYU_TEMPTP                      0x37
#define FLAG_RYU_HAS_FOLLOWER                0x38
#define FLAG_RYU_DEV_MODE                    0x39
#define FLAG_RYU_AQUA_THIEF_SEEN             0x3A
#define FLAG_RYU_PLAYER_HELPING_DEVON        0x3B
#define FLAG_OPTIONS_INSTANT_TRANSITION      0x3C
#define FLAG_RYU_PLAYER_CLEARED_PBG_DOORS    0x3D
#define FLAG_RYU_HIDE_HOLIDAY_NPC            0x3E
#define FLAG_RYU_CAN_DO_NURSE_QUEST          0x3F
#define FLAG_RYU_PLAYER_HELPING_AQUA         0x40
#define FLAG_RYU_TC_EXP_DISABLED             0x41
#define FLAG_RYU_HAS_OVAL_CHARM              0x42
#define FLAG_RYU_DG_REWARD_RECEIVED          0x43
#define FLAG_RYU_HAS_SHINY_CHARM             0x44
#define FLAG_RYU_HAS_MEGA_BRACELET           0x45
#define FLAG_RYU_DEVON_STERN_EVENT_DONE      0x46
#define FLAG_RYU_GAME_OVER                   0x47 //set when player loses a story fight.
#define FLAG_RYU_DEVON_CORPORATE             0x48
#define FLAG_RYU_ULTRA_BEASTS_ESCAPED        0x49
#define FLAG_RYU_MOLTRES                     0x4A
#define FLAG_RYU_HIDE_MTPYRE_HEXER           0x4B
#define FLAG_RYU_HEXER_FACTION_QUEST_ACTIVE  0x4C
#define FLAG_RYU_PLAYER_RECEIVED_STANDING_FROM_MIMIS_GRAVE    0x4D
#define FLAG_RYU_OUTCASTS_SPECIAL_STARTED    0x4E
#define FLAG_RYU_FINISHED_LORWYNS_TEST       0x4F

// Scripts
#define FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT  0x50
#define FLAG_SET_WALL_CLOCK                  0x51
#define FLAG_RESCUED_BIRCH                   0x52
#define FLAG_TOBY_TRAINER_SIGHT              0x53

#define FLAG_RYU_JUKEBOX_ENABLED             0x54
#define FLAG_RYU_BOSS_SCALE                  0x55 // Autoscale enemies to higher levels.

#define FLAG_HIDE_CONTEST_POKE_BALL          0x56 // Always set after new game, object it hides is added directly
#define FLAG_MET_RIVAL_MOM                   0x57
#define FLAG_BIRCH_AIDE_MET                  0x58
#define FLAG_DECLINED_BIKE                   0x59
#define FLAG_RECEIVED_BIKE                   0x5A
#define FLAG_RYU_DT_BRINEY_BATTLE            0x5B // Prevents briney from approaching player in route 105 after he has been defeated.
#define FLAG_COLLECTED_ALL_SILVER_SYMBOLS    0x5C
#define FLAG_RYU_LIMBO                       0x5D
#define FLAG_RECEIVED_WAILMER_PAIL           0x5E
#define FLAG_RECEIVED_POKEBLOCK_CASE         0x5F
#define FLAG_RECEIVED_SECRET_POWER           0x60
#define FLAG_MET_TEAM_AQUA_HARBOR            0x61
#define FLAG_TV_EXPLAINED                    0x62
#define FLAG_MAUVILLE_GYM_BARRIERS_STATE     0x63
#define FLAG_RYU_RECRUITED_TIANA             0x64
#define FLAG_RYU_HELPED_POKEFAN_PIKACHU      0x65
#define FLAG_RYU_DID_NOT_HELP_POKEFAN        0x66
#define FLAG_RYU_REWARDED_FOR_HELPING_POKEFAN    0x67

#define FLAG_UNUSED_0x68                     0x68

#define FLAG_OCEANIC_MUSEUM_MET_REPORTER     0x69
#define FLAG_RECEIVED_TM54                   0x6A
#define FLAG_RECEIVED_TM56                   0x6B
#define FLAG_UNUSED_0x6C                     0x6C
#define FLAG_RECEIVED_TM55                   0x6D
#define FLAG_RECEIVED_TM52                   0x6E
#define FLAG_UNUSED_0x6F                     0x6F
#define FLAG_UNUSED_0x70                     0x70
#define FLAG_RYU_IN_MOSSDEEP_GYM             0x71
#define FLAG_UNUSED_0x72                     0x72
#define FLAG_RECEIVED_METEORITE              0x73
#define FLAG_ADVENTURE_STARTED               0x74 // RECEIVED Pokédex.
#define FLAG_DEFEATED_MAGMA_SPACE_CENTER     0x75 // Set when Team Magma is defeated at Mossdeep's Space Center.
#define FLAG_MET_HIDDEN_POWER_GIVER          0x76

#define FLAG_CANCEL_BATTLE_ROOM_CHALLENGE    0x77

#define FLAG_LANDMARK_MIRAGE_TOWER           0x78
#define FLAG_RECEIVED_TM31                   0x79
#define FLAG_RECEIVED_TM53                   0x7A
#define FLAG_RECEIVED_TM58                   0x7B
#define FLAG_REGISTER_RIVAL_POKENAV          0x7C
#define FLAG_DEFEATED_RIVAL_ROUTE_104        0x7D
#define FLAG_HIDDEN_CRAGGY_COAST_HEART_SCALE 0x7E
#define FLAG_MET_PRETTY_PETAL_SHOP_OWNER     0x7F
#define FLAG_UNUSED_0x80                     0x80
#define FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN  0x81
#define FLAG_DEFEATED_RIVAL_ROUTE103         0x82
#define FLAG_RECEIVED_DOLL_LANETTE           0x83
#define FLAG_RECEIVED_GREAT_BALL_OLDALE      0x84
#define FLAG_RECEIVED_AMULET_COIN            0x85
#define FLAG_PENDING_DAYCARE_EGG             0x86
#define FLAG_ITEM_ROUTE_106_RARE_CANDY       0x87
#define FLAG_ITEM_DEWFORD_ENERGY_ROOT        0x88
#define FLAG_RECEIVED_TM51                   0x89
#define FLAG_ITEM_SLAKOTHGARDEN_REVIVAL_HERB 0x8A
#define FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY   0x8B
#define FLAG_RECEIVED_6_SODA_POP             0x8C
#define FLAG_DEFEATED_SEASHORE_HOUSE         0x8D
#define FLAG_DEVON_GOODS_STOLEN              0x8E
#define FLAG_RECOVERED_DEVON_GOODS           0x8F
#define FLAG_RETURNED_DEVON_GOODS            0x90
#define FLAG_CAUGHT_LUGIA                    0x91
#define FLAG_CAUGHT_HO_OH                    0x92
#define FLAG_UNUSED_0x93                     0x93
#define FLAG_UNUSED_0x94                     0x94
#define FLAG_UNUSED_0x95                     0x95
#define FLAG_DEWFORD_NPC_TRADE_COMPLETED     0x96
#define FLAG_RECEIVED_CASTFORM               0x97
#define FLAG_RECEIVED_SUPER_ROD              0x98
#define FLAG_RUSTBORO_NPC_TRADE_COMPLETED    0x99
#define FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED  0x9A
#define FLAG_FORTREE_NPC_TRADE_COMPLETED     0x9B
#define FLAG_BATTLE_FRONTIER_TRADE_DONE      0x9C
#define FLAG_UNUSED_0x9D                     0x9D
#define FLAG_UNUSED_0x9E                     0x9E
#define FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN 0x9F
#define FLAG_COOL_PAINTING_MADE              0xA0
#define FLAG_BEAUTY_PAINTING_MADE            0xA1
#define FLAG_CUTE_PAINTING_MADE              0xA2
#define FLAG_SMART_PAINTING_MADE             0xA3
#define FLAG_TOUGH_PAINTING_MADE             0xA4
#define FLAG_RECEIVED_TM39                   0xA5
#define FLAG_RECEIVED_TM08                   0xA6
#define FLAG_RECEIVED_TM34                   0xA7
#define FLAG_RECEIVED_TM50                   0xA8
#define FLAG_RECEIVED_TM42                   0xA9
#define FLAG_RECEIVED_TM40                   0xAA
#define FLAG_RECEIVED_TM04                   0xAB
#define FLAG_RECEIVED_TM03                   0xAC
#define FLAG_DECORATION_0                    0xAD
#define FLAG_DECORATION_1                    0xAE
#define FLAG_DECORATION_2                    0xAF
#define FLAG_DECORATION_3                    0xB0
#define FLAG_DECORATION_4                    0xB1
#define FLAG_DECORATION_5                    0xB2
#define FLAG_DECORATION_6                    0xB3
#define FLAG_DECORATION_7                    0xB4
#define FLAG_DECORATION_8                    0xB5
#define FLAG_DECORATION_9                    0xB6
#define FLAG_DECORATION_10                   0xB7
#define FLAG_DECORATION_11                   0xB8
#define FLAG_DECORATION_12                   0xB9
#define FLAG_DECORATION_13                   0xBA
#define FLAG_DECORATION_14                   0xBB
#define FLAG_RECEIVED_POKENAV                0xBC
#define FLAG_DELIVERED_STEVEN_LETTER         0xBD
#define FLAG_ITEM_MT_CHIMNEY_FLAME_ORB       0xBE
#define FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F  0xBF
#define FLAG_RECEIVED_SUN_STONE_MOSSDEEP     0xC0
#define FLAG_WALLY_SPEECH                    0xC1 // EE-Unused
#define FLAG_RYU_MAGMA_ALT_LINE              0xC2 // used by start menu to determine which magma icon to draw. C for Main, T for Alt.
#define FLAG_UNUSED_0xC3                     0xC3 //
#define FLAG_UNUSED_0xC4                     0xC4 //
#define FLAG_UNUSED_0xC5                     0xC5 //
#define FLAG_UNUSED_0xC6                     0xC6 //
#define FLAG_RUSTURF_TUNNEL_OPENED           0xC7
#define FLAG_RECEIVED_RED_SCARF              0xC8
#define FLAG_RECEIVED_BLUE_SCARF             0xC9
#define FLAG_RECEIVED_PINK_SCARF             0xCA
#define FLAG_RECEIVED_GREEN_SCARF            0xCB
#define FLAG_RECEIVED_YELLOW_SCARF           0xCC
#define FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER 0xCD
#define FLAG_ENCOUNTERED_LATIAS_OR_LATIOS    0xCE
#define FLAG_MET_ARCHIE_METEOR_FALLS         0xCF
#define FLAG_GOT_BASEMENT_KEY_FROM_WATTSON   0xD0
#define FLAG_GOT_TM24_FROM_WATTSON           0xD1
#define FLAG_FAN_CLUB_STRENGTH_SHARED        0xD2 // Set when you rate the strength of another trainer in Lilycove's Trainer Fan Club.
#define FLAG_DEFEATED_RIVAL_RUSTBORO         0xD3
#define FLAG_RECEIVED_RED_OR_BLUE_ORB        0xD4
#define FLAG_RECEIVED_PREMIER_BALL_RUSTBORO  0xD5
#define FLAG_ITEM_IGLOO2_GOLD_ORE_1          0xD6
#define FLAG_ITEM_IGLOO2_GOLD_ORE_2          0xD7
#define FLAG_ITEM_IGLOO2_GOLD_ORE_3          0xD8
#define FLAG_MET_DIVING_TREASURE_HUNTER      0xD9
#define FLAG_MET_WAILMER_TRAINER             0xDA // EE-Unused
#define FLAG_EVIL_LEADER_PLEASE_STOP         0xDB // EE-Unused?
#define FLAG_RYU_TITLE_DEFENSE               0xDC
#define FLAG_RECEIVED_GO_GOGGLES             0xDD // EE-Unused
#define FLAG_WINGULL_SENT_ON_ERRAND          0xDE
#define FLAG_RECEIVED_MENTAL_HERB            0xDF
#define FLAG_WINGULL_DELIVERED_MAIL          0xE0
#define FLAG_RECEIVED_20_COINS               0xE1
#define FLAG_RECEIVED_STARTER_DOLL           0xE2
#define FLAG_RECEIVED_GOOD_ROD               0xE3
#define FLAG_REGI_DOORS_OPENED               0xE4
#define FLAG_RECEIVED_TM27                   0xE5
#define FLAG_RECEIVED_TM36                   0xE6
#define FLAG_RECEIVED_TM05                   0xE7
#define FLAG_RECEIVED_TM19                   0xE8
#define FLAG_RECEIVED_TM61                   0xE9
#define FLAG_RECEIVED_TM44                   0xEA
#define FLAG_RECEIVED_TM45                   0xEB
#define FLAG_RECEIVED_GLASS_ORNAMENT         0xEC
#define FLAG_RECEIVED_SILVER_SHIELD          0xED
#define FLAG_RECEIVED_GOLD_SHIELD            0xEE
#define FLAG_USED_STORAGE_KEY                0xEF
#define FLAG_USED_ROOM_1_KEY                 0xF0
#define FLAG_USED_ROOM_2_KEY                 0xF1
#define FLAG_USED_ROOM_4_KEY                 0xF2
#define FLAG_USED_ROOM_6_KEY                 0xF3
#define FLAG_MET_PROF_COZMO                  0xF4
#define FLAG_RECEIVED_WAILMER_DOLL           0xF5
#define FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104 0xF6
#define FLAG_DEFEATED_SS_TIDAL_TRAINERS      0xF7
#define FLAG_RECEIVED_SPELON_BERRY           0xF8
#define FLAG_RECEIVED_PAMTRE_BERRY           0xF9
#define FLAG_RECEIVED_WATMEL_BERRY           0xFA
#define FLAG_RECEIVED_DURIN_BERRY            0xFB
#define FLAG_RECEIVED_BELUE_BERRY            0xFC
#define FLAG_ENABLE_RIVAL_MATCH_CALL         0xFD // EE-Unused
#define FLAG_RECEIVED_CHARCOAL               0xFE
#define FLAG_LATIOS_OR_LATIAS_ROAMING        0xFF
#define FLAG_RECEIVED_REPEAT_BALL            0x100
#define FLAG_RECEIVED_OLD_ROD                0x101
#define FLAG_RECEIVED_COIN_CASE              0x102
#define FLAG_RETURNED_RED_OR_BLUE_ORB        0x103
#define FLAG_RECEIVED_TM49                   0x104
#define FLAG_RECEIVED_TM28                   0x105
#define FLAG_RECEIVED_TM09                   0x106
#define FLAG_ENTERED_ELITE_FOUR              0x107
#define FLAG_RECEIVED_TM10                   0x108
#define FLAG_RECEIVED_TM41                   0x109
#define FLAG_RECEIVED_LAVARIDGE_EGG          0x10A
#define FLAG_RECEIVED_REVIVED_FOSSIL_MON     0x10B
#define FLAG_SECRET_BASE_REGISTRY_ENABLED    0x10C
#define FLAG_RECEIVED_TM46                   0x10D
#define FLAG_RYU_PLAYER_AQUA_ADMIN           0x10E
#define FLAG_RYU_HIDE_MOSSDEEP_MATT          0x10F // Hides matt in mossdeep
#define FLAG_UNUSED_0x110                    0x110
#define FLAG_POKERUS_EXPLAINED               0x111
#define FLAG_UNUSED_0x112                    0x112
#define FLAG_RECEIVED_QUICK_CLAW             0x113
#define FLAG_RECEIVED_KINGS_ROCK             0x114
#define FLAG_RECEIVED_MACHO_BRACE            0x115
#define FLAG_RECEIVED_SOOTHE_BELL            0x116
#define FLAG_RECEIVED_WHITE_HERB             0x117
#define FLAG_RECEIVED_SOFT_SAND              0x118
#define FLAG_RYU_HIDE_CHIMNEY_GROUDON        0x119 // groudon sprite in chimney for aqua cutscene
#define FLAG_RECEIVED_CLEANSE_TAG            0x11A
#define FLAG_RECEIVED_FOCUS_BAND             0x11B
#define FLAG_MT_FREEZE_OPENED                0x11C
#define FLAG_RECEIVED_DEVON_SCOPE            0x11D
#define FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE  0x11E
#define FLAG_MET_DEVON_EMPLOYEE              0x11F
#define FLAG_MET_RIVAL_RUSTBORO              0x120
#define FLAG_RECEIVED_SILK_SCARF             0x121
#define FLAG_NOT_READY_FOR_BATTLE_ROUTE_120  0x122
#define FLAG_RECEIVED_SS_TICKET              0x123
#define FLAG_MET_RIVAL_LILYCOVE              0x124
#define FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE 0x125
#define FLAG_RYU_HIDE_AQUA_OFFICE_AQUA       0x126 // Hides aqua in their office if the player did the no-romance line.
#define FLAG_UNUSED_0x127                    0x127
#define FLAG_RYU_AQUA_ALT_LINE               0x128 // Player's doing the Shelly line for aqua.
#define FLAG_RECEIVED_MIRACLE_SEED           0x129
#define FLAG_RECEIVED_BELDUM                 0x12A
#define FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK   0x12B // EE-Unused
#define FLAG_MET_FANCLUB_YOUNGER_BROTHER     0x12C
#define FLAG_RIVAL_LEFT_FOR_ROUTE103         0x12D
#define FLAG_RYU_HIDE_SHIPYARD_DEVON_EMPLOYEES    0x12E // Hides the devon enforcers in the shipyard during the aqua quest shelly line
#define FLAG_RYU_RECEIVED_MEGA_BRACELET      0x12F
#define FLAG_RYU_AQUA_4_NOTIFY               0x130 // Player received the pokenav call from the stage 4(romance) aqua quest.
#define FLAG_REGISTERED_STEVEN_POKENAV       0x131 // EE-Unused
#define FLAG_ENABLE_NORMAN_MATCH_CALL        0x132 // EE-Unused
#define FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN 0x133 // EE-Unused
#define FLAG_MET_ARCHIE_SOOTOPOLIS           0x134 // EE-Unused
#define FLAG_MET_MAXIE_SOOTOPOLIS            0x135 // EE-Unused
#define FLAG_MET_SCOTT_RUSTBORO              0x136
#define FLAG_WALLACE_GOES_TO_SKY_PILLAR      0x137 // EE-Unused
#define FLAG_RECEIVED_TM57                   0x138
#define FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS    0x139
#define FLAG_RECEIVED_AURORA_TICKET          0x13A
#define FLAG_RECEIVED_MYSTIC_TICKET          0x13B
#define FLAG_RECEIVED_OLD_SEA_MAP            0x13C 
#define FLAG_RYU_DS_SHELLY_ACQ               0x13D
#define FLAG_RYU_DS_SHELLY_FRIENDS           0x13E
#define FLAG_RYU_DS_SHELLY_CLOSEFRIENDS      0x13F
#define FLAG_RYU_DS_SHELLY_LOVERS            0x140
#define FLAG_RYU_DS_SHELLY_PARTNERS          0x141
#define FLAG_RYU_DS_DAWN_ACQ                 0x142
#define FLAG_RYU_DS_DAWN_FRIENDS             0x143
#define FLAG_RYU_DS_DAWN_CLOSEFRIENDS        0x144
#define FLAG_RYU_DS_DAWN_LOVERS              0x145
#define FLAG_RYU_DS_DAWN_PARTNERS            0x146
#define FLAG_RYU_DS_BRENDAN_ACQ              0x147
#define FLAG_RYU_DS_BRENDAN_FRIENDS          0x148
#define FLAG_RYU_DS_BRENDAN_CLOSEFRIENDS     0x149
#define FLAG_RYU_DS_BRENDAN_LOVERS           0x14A
#define FLAG_RYU_DS_BRENDAN_PARTNERS         0x14B
#define FLAG_RYU_AQUA_BAD_END           0x14C
#define FLAG_RYU_DS_SHELLY_SCENE             0x14D

#define FLAG_NOTIFIED_FF_TEXT                0x14E //player was warned that instant text speed can cause skipped dialogues.
#define FLAG_HIDE_AQUAHQ_SHELLY              0x14F // hides shelly in the aqua hq when she becomes a follower.
#define FLAG_FRIGUS_QUEST_ACCEPTED           0x150
#define FLAG_RECEIVED_POWDER_JAR             0x151

#define FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER 0x152

#define FLAG_MET_BATTLE_FRONTIER_BREEDER     0x153
#define FLAG_MET_BATTLE_FRONTIER_MANIAC      0x154
#define FLAG_ENTERED_CONTEST                 0x155
#define FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN  0x156
#define FLAG_MET_BATTLE_FRONTIER_GAMBLER     0x157
#define FLAG_ENABLE_MR_STONE_POKENAV         0x158 // EE-Unused?
#define FLAG_NURSE_MENTIONS_GOLD_CARD        0x159
#define FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR  0x15A
#define FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR 0x15B

// Trainer Rematch Flags
#define FLAG_ITEM_POLAR_PILLAR_ABOMASITE     0x15C
#define FLAG_RYU_HIDE_BRINEY_GUARD           0x15D
#define FLAG_FRIGUS_QUEST_COMPLETED          0x15E
#define FLAG_ITEM_ROUTE_111_PP_MAX           0x15F
#define FLAG_REMATCH_LOLA                    0x160 // EE-Unused
#define FLAG_RYU_COURTNEY_MEGA_REWARD        0x161 // Courtney mega stone reward.
#define FLAG_RYU_DS_JOY_ACQ                  0x162
#define FLAG_RYU_DS_JOY_FRIENDS              0x163
#define FLAG_RYU_DS_JOY_CLOSEFRIENDS         0x164
#define FLAG_RYU_DS_JOY_LOVERS               0x165
#define FLAG_RYU_DS_JOY_PARTNERS             0x166
#define FLAG_RYU_HIDE_JOY                    0x167
#define FLAG_ITEM_MIRAGE_CAVE_RARE_BONE_1    0x168
#define FLAG_ITEM_MIRAGE_CAVE_DOME_FOSSIL    0x169
#define FLAG_ITEM_MIRAGE_CAVE_THICK_CLUB     0x16A
#define FLAG_ITEM_MIRAGE_CAVE_RARE_BONE_2    0x16B
#define FLAG_ITEM_MIRAGE_CAVE_HELIX_FOSSIL   0x16C
#define FLAG_ITEM_MIRAGE_CAVE_ROSE_INCENSE   0x16D
#define FLAG_NIGILEGO_ESCAPED                0x16E
#define FLAG_BUZZWOLE_ESCAPED                0x16F
#define FLAG_PHEROMOSA_ESCAPED               0x170
#define FLAG_XURKITREE_ESCAPED               0x171
#define FLAG_CELESTEELA_ESCAPED              0x172
#define FLAG_KARTANA_ESCAPED                 0x173
#define FLAG_GUZZLORD_ESCAPED                0x174
#define FLAG_STAKATAKA_ESCAPED               0x175
#define FLAG_RYU_AQUA_LINE_DONE              0x176 // finished aqua. Checked for battle music scenarios.
#define FLAG_RYU_AQUA_1_NOTIFY               0x177 // First aqua notification given
#define FLAG_RYU_AQUA_2_NOTIFY               0x178 // Second aqua notification given
#define FLAG_RYU_AQUA_3_NOTIFY               0x179 // Third aqua notification given
#define FLAG_RYU_HIDE_AQUA_MTPYRE_EXT        0x17A // Group of aqua goons on mtpyre
#define FLAG_RYU_HIDE_NPCS_MTPYRE_SUMMIT     0x17B // Aqua and Magma goons in the mountaintop
#define FLAG_REMATCH_MIGUEL                  0x17C // EE-Unused
#define FLAG_REMATCH_TIMOTHY                 0x17D // EE-Unused
#define FLAG_REMATCH_SHELBY                  0x17E // EE-Unused
#define FLAG_REMATCH_CALVIN                  0x17F // EE-Unused
#define FLAG_REMATCH_ELLIOT                  0x180 // EE-Unused
#define FLAG_REMATCH_ISAIAH                  0x181 // EE-Unused
#define FLAG_REMATCH_MARIA                   0x182 // EE-Unused
#define FLAG_REMATCH_ABIGAIL                 0x183 // EE-Unused
#define FLAG_REMATCH_DYLAN                   0x184 // EE-Unused
#define FLAG_REMATCH_KATELYN                 0x185 // EE-Unused
#define FLAG_REMATCH_BENJAMIN                0x186 // EE-Unused
#define FLAG_REMATCH_PABLO                   0x187 // EE-Unused
#define FLAG_REMATCH_NICOLAS                 0x188 // EE-Unused
#define FLAG_REMATCH_ROBERT                  0x189 // EE-Unused
#define FLAG_REMATCH_LAO                     0x18A // EE-Unused
#define FLAG_REMATCH_CYNDY                   0x18B // EE-Unused
#define FLAG_REMATCH_MADELINE                0x18C // EE-Unused
#define FLAG_REMATCH_JENNY                   0x18D // EE-Unused
#define FLAG_REMATCH_DIANA                   0x18E // EE-Unused
#define FLAG_REMATCH_AMY_AND_LIV             0x18F // EE-Unused
#define FLAG_REMATCH_ERNEST                  0x190 // EE-Unused
#define FLAG_REMATCH_CORY                    0x191 // EE-Unused
#define FLAG_REMATCH_EDWIN                   0x192 // EE-Unused
#define FLAG_REMATCH_LYDIA                   0x193 // EE-Unused
#define FLAG_REMATCH_ISAAC                   0x194 // EE-Unused
#define FLAG_REMATCH_GABRIELLE               0x195 // EE-Unused
#define FLAG_REMATCH_CATHERINE               0x196 // EE-Unused
#define FLAG_REMATCH_JACKSON                 0x197 // EE-Unused
#define FLAG_REMATCH_HALEY                   0x198 // EE-Unused
#define FLAG_REMATCH_JAMES                   0x199 // EE-Unused
#define FLAG_REMATCH_TRENT                   0x19A // EE-Unused
#define FLAG_REMATCH_SAWYER                  0x19B // EE-Unused
#define FLAG_REMATCH_KIRA_AND_DAN            0x19C // EE-Unused
#define FLAG_REMATCH_WALLY                   0x19D // EE-Unused
#define FLAG_REMATCH_ROXANNE                 0x19E // EE-Unused
#define FLAG_REMATCH_BRAWLY                  0x19F // EE-Unused
#define FLAG_REMATCH_WATTSON                 0x1A0 // EE-Unused
#define FLAG_REMATCH_FLANNERY                0x1A1 // EE-Unused
#define FLAG_REMATCH_NORMAN                  0x1A2 // EE-Unused
#define FLAG_REMATCH_WINONA                  0x1A3 // EE-Unused
#define FLAG_REMATCH_TATE_AND_LIZA           0x1A4 // EE-Unused
// Note: FLAG_REMATCH_JUAN is handled by FLAG_ENABLE_JUAN_MATCH_CALL instead.
#define FLAG_REMATCH_SIDNEY                  0x1A5
#define FLAG_REMATCH_PHOEBE                  0x1A6
#define FLAG_REMATCH_GLACIA                  0x1A7
#define FLAG_REMATCH_DRAKE                   0x1A8
#define FLAG_REMATCH_WALLACE                 0x1A9 // EE-Unused?

#define FLAG_RYU_AFTERSHELLYSTORY            0x1AA
#define FLAG_RYU_DS_HAS_PARTNER              0x1AB

#define FLAG_DEFEATED_DEOXYS                 0x1AC
#define FLAG_BATTLED_DEOXYS                  0x1AD
#define FLAG_SHOWN_EON_TICKET                0x1AE
#define FLAG_SHOWN_AURORA_TICKET             0x1AF
#define FLAG_SHOWN_OLD_SEA_MAP               0x1B0
#define FLAG_ITEM_ROUTE_66_DAWN_STONE        0x1B1
#define FLAG_ITEM_ROUTE_66_LEAF_STONE        0x1B2
#define FLAG_RYU_ROUTE_66_ABSORB_BULB        0x1B3
#define FLAG_ITEM_LITTLEROOT_TOWN_POTION     0x1B4
#define FLAG_ITEM_FROSTY_FOREST_DARK_GEM     0x1B5
#define FLAG_ITEM_FROSTY_FOREST_EVERSTONE    0x1B6
#define FLAG_ITEM_FROSTY_FOREST_DUSK_STONE   0x1B7
#define FLAG_ITEM_FROSTY_FOREST_STARDUST     0x1B8
#define FLAG_ITEM_POLAR_PILLAR_ICE_GEM_1     0x1B9
#define FLAG_ITEM_POLAR_PILLAR_ICE_GEM_2     0x1BA
#define FLAG_DEFEATED_REGIROCK               0x1BB
#define FLAG_DEFEATED_REGICE                 0x1BC
#define FLAG_DEFEATED_REGISTEEL              0x1BD
#define FLAG_DEFEATED_KYOGRE                 0x1BE
#define FLAG_DEFEATED_GROUDON                0x1BF
#define FLAG_DEFEATED_RAYQUAZA               0x1C0
#define FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE 0x1C1
#define FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE 0x1C2
#define FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE 0x1C3
#define FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT 0x1C4
#define FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT 0x1C5
#define FLAG_DEFEATED_SUDOWOODO              0x1C6
#define FLAG_DEFEATED_MEW                    0x1C7
#define FLAG_DEFEATED_LATIAS_OR_LATIOS       0x1C8
#define FLAG_CAUGHT_LATIAS_OR_LATIOS         0x1C9
#define FLAG_CAUGHT_MEW                      0x1CA
#define FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE 0x1CB
#define FLAG_MET_SCOTT_IN_VERDANTURF         0x1CC
#define FLAG_MET_SCOTT_IN_FALLARBOR          0x1CD
#define FLAG_MET_SCOTT_IN_LILYCOVE           0x1CE
#define FLAG_MET_SCOTT_IN_EVERGRANDE         0x1CF
#define FLAG_MET_SCOTT_ON_SS_TIDAL           0x1D0
#define FLAG_SCOTT_GIVES_BATTLE_POINTS       0x1D1
#define FLAG_COLLECTED_ALL_GOLD_SYMBOLS      0x1D2
#define FLAG_ENABLE_ROXANNE_MATCH_CALL       0x1D3 // EE-Unused
#define FLAG_ENABLE_BRAWLY_MATCH_CALL        0x1D4 // EE-Unused
#define FLAG_ENABLE_WATTSON_MATCH_CALL       0x1D5 // EE-Unused
#define FLAG_ENABLE_FLANNERY_MATCH_CALL      0x1D6 // EE-Unused
#define FLAG_ENABLE_WINONA_MATCH_CALL        0x1D7 // EE-Unused
#define FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL 0x1D8 // EE-Unused
#define FLAG_ENABLE_JUAN_MATCH_CALL          0x1D9 // EE-Unused

#define FLAG_RYU_SCI_MEWTWO1                 0x1DA

#define FLAG_SHOWN_MYSTIC_TICKET             0x1DB
#define FLAG_DEFEATED_HO_OH                  0x1DC
#define FLAG_DEFEATED_LUGIA                  0x1DD

#define FLAG_LEAF_PC                         0x1DE
#define FLAG_RYU_DS_LEAF_ACQ                 0x1DF
#define FLAG_RYU_DS_LEAF_FRIENDS             0x1E0
#define FLAG_RYU_DS_LEAF_CLOSEFRIENDS        0x1E1
#define FLAG_RYU_DS_LEAF_LOVERS              0x1E2
#define FLAG_RYU_DS_LEAF_PARTNERS            0x1E3

// These unused flags are cleared seperately from the other flags, so when used, the flag also has to be replaced in  event_data.c: Ln117
#define FLAG_RYU_MAGMA_LINE_DONE             0x1E4
#define FLAG_HIDE_MAGMA_ADMIN_OFFICE_MAXIE   0x1E5
#define FLAG_HIDE_MAGMA_ADMIN_OFFICE_BLAISE  0x1E6
#define FLAG_HIDE_114_MAXIE                  0x1E7
#define FLAG_RYU_MAGMA_INTENSE_SUN_ENABLED   0x1E8
#define FLAG_UNUSED_5                        0x1E9 // EE-Unused
#define FLAG_UNUSED_6                        0x1EA // EE-Unused
#define FLAG_UNUSED_7                        0x1EB // EE-Unused
#define FLAG_UNUSED_8                        0x1EC // EE-Unused
#define FLAG_UNUSED_9                        0x1ED // EE-Unused
#define FLAG_UNUSED_10                       0x1EE // EE-Unused
#define FLAG_UNUSED_11                       0x1EF // EE-Unused
#define FLAG_UNUSED_12                       0x1F0 // EE-Unused
#define FLAG_UNUSED_13                       0x1F1 // EE-Unused
#define FLAG_UNUSED_14                       0x1F2 // EE-Unused
#define FLAG_UNUSED_15                       0x1F3 // EE-Unused

// Hidden Items -- sorted by location
#define FLAG_HIDDEN_ITEMS_START                                                         0x1F4
#define FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET                  (FLAG_HIDDEN_ITEMS_START + 0x01)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CARBOS               (FLAG_HIDDEN_ITEMS_START + 0x08)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_GREEN_SHARD          (FLAG_HIDDEN_ITEMS_START + 0x09)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x0A)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x0B)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_1        (FLAG_HIDDEN_ITEMS_START + 0x0D)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CALCIUM              (FLAG_HIDDEN_ITEMS_START + 0x24)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_2        (FLAG_HIDDEN_ITEMS_START + 0x26)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_HEART_SCALE          (FLAG_HIDDEN_ITEMS_START + 0x0E)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL           (FLAG_HIDDEN_ITEMS_START + 0x0F)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_STARDUST             (FLAG_HIDDEN_ITEMS_START + 0x10)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x11)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_IRON                 (FLAG_HIDDEN_ITEMS_START + 0x13)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_YELLOW_SHARD         (FLAG_HIDDEN_ITEMS_START + 0x12)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x14)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BLUE_SHARD           (FLAG_HIDDEN_ITEMS_START + 0x0C)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_STAR_PIECE           (FLAG_HIDDEN_ITEMS_START + 0x15)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HP_UP                (FLAG_HIDDEN_ITEMS_START + 0x16)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HEART_SCALE          (FLAG_HIDDEN_ITEMS_START + 0x17)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_RED_SHARD            (FLAG_HIDDEN_ITEMS_START + 0x18)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PROTEIN              (FLAG_HIDDEN_ITEMS_START + 0x19)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x1A)
#define FLAG_HIDDEN_ITEM_FALLARBOR_TOWN_NUGGET               (FLAG_HIDDEN_ITEMS_START + 0x1C)
#define FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ICE_HEAL             (FLAG_HIDDEN_ITEMS_START + 0x00)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY             (FLAG_HIDDEN_ITEMS_START + 0x1F)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY             (FLAG_HIDDEN_ITEMS_START + 0x20)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY             (FLAG_HIDDEN_ITEMS_START + 0x21)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY             (FLAG_HIDDEN_ITEMS_START + 0x22)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_CALCIUM            (FLAG_HIDDEN_ITEMS_START + 0x65)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_ZINC               (FLAG_HIDDEN_ITEMS_START + 0x66)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_PROTEIN            (FLAG_HIDDEN_ITEMS_START + 0x67)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_IRON               (FLAG_HIDDEN_ITEMS_START + 0x68)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_1        (FLAG_HIDDEN_ITEMS_START + 0x30)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_2        (FLAG_HIDDEN_ITEMS_START + 0x31)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_GREAT_BALL              (FLAG_HIDDEN_ITEMS_START + 0x4C)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_FULL_HEAL               (FLAG_HIDDEN_ITEMS_START + 0x4D)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_HEART_SCALE           (FLAG_HIDDEN_ITEMS_START + 0x1B)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_PP_UP                 (FLAG_HIDDEN_ITEMS_START + 0x2B)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_POKE_BALL             (FLAG_HIDDEN_ITEMS_START + 0x4B)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_ULTRA_BALL         (FLAG_HIDDEN_ITEMS_START + 0x1D)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_MAX_ETHER          (FLAG_HIDDEN_ITEMS_START + 0x4E)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_ZINC                 (FLAG_HIDDEN_ITEMS_START + 0x4F)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x50)
#define FLAG_HIDDEN_ITEM_NAVEL_ROCK_TOP_SACRED_ASH           (FLAG_HIDDEN_ITEMS_START + 0x6D)
#define FLAG_HIDDEN_ITEM_PETALBURG_CITY_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x5F)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POTION              (FLAG_HIDDEN_ITEMS_START + 0x3A)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_1     (FLAG_HIDDEN_ITEMS_START + 0x3B)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_2     (FLAG_HIDDEN_ITEMS_START + 0x3C)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POKE_BALL           (FLAG_HIDDEN_ITEMS_START + 0x3D)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_ELIXIR             (FLAG_HIDDEN_ITEMS_START + 0x52)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_MAX_REPEL          (FLAG_HIDDEN_ITEMS_START + 0x53)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_RARE_CANDY   (FLAG_HIDDEN_ITEMS_START + 0x6A)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_ZINC         (FLAG_HIDDEN_ITEMS_START + 0x6B)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_PP_UP        (FLAG_HIDDEN_ITEMS_START + 0x6C)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE (FLAG_HIDDEN_ITEMS_START + 0x69)
#define FLAG_HIDDEN_ITEM_SS_TIDAL_LOWER_DECK_LEFTOVERS       (FLAG_HIDDEN_ITEMS_START + 0x23)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_ULTRA_BALL          (FLAG_HIDDEN_ITEMS_START + 0x51)
#define FLAG_HIDDEN_ITEM_ROUTE_104_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2C)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3E)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POTION                    (FLAG_HIDDEN_ITEMS_START + 0x25)
#define FLAG_HIDDEN_ITEM_ROUTE_104_ANTIDOTE                  (FLAG_HIDDEN_ITEMS_START + 0x55)
#define FLAG_HIDDEN_ITEM_ROUTE_104_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x58)
#define FLAG_HIDDEN_ITEM_ROUTE_105_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x59)
#define FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL                 (FLAG_HIDDEN_ITEMS_START + 0x6F)
#define FLAG_HIDDEN_ITEM_ROUTE_106_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3F)
#define FLAG_HIDDEN_ITEM_ROUTE_106_STARDUST                  (FLAG_HIDDEN_ITEMS_START + 0x2E)
#define FLAG_HIDDEN_ITEM_ROUTE_106_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x2F)
#define FLAG_HIDDEN_ITEM_ROUTE_108_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x56)
#define FLAG_HIDDEN_ITEM_ROUTE_109_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x32)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_1             (FLAG_HIDDEN_ITEMS_START + 0x34)
#define FLAG_HIDDEN_ITEM_ROUTE_109_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x33)
#define FLAG_HIDDEN_ITEM_ROUTE_109_ETHER                     (FLAG_HIDDEN_ITEMS_START + 0x40)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_2             (FLAG_HIDDEN_ITEMS_START + 0x5A)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_3             (FLAG_HIDDEN_ITEMS_START + 0x5B)
#define FLAG_HIDDEN_ITEM_ROUTE_110_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x36)
#define FLAG_HIDDEN_ITEM_ROUTE_110_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x35)
#define FLAG_HIDDEN_ITEM_ROUTE_110_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x41)
#define FLAG_HIDDEN_ITEM_ROUTE_110_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x37)
#define FLAG_HIDDEN_ITEM_ROUTE_111_STARDUST                  (FLAG_HIDDEN_ITEMS_START + 0x02)
#define FLAG_HIDDEN_ITEM_ROUTE_111_PROTEIN                   (FLAG_HIDDEN_ITEMS_START + 0x38)
#define FLAG_HIDDEN_ITEM_ROUTE_111_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x39)
#define FLAG_HIDDEN_ITEM_ROUTE_113_ETHER                     (FLAG_HIDDEN_ITEMS_START + 0x03)
#define FLAG_HIDDEN_ITEM_ROUTE_113_TM_32                     (FLAG_HIDDEN_ITEMS_START + 0x1E)
#define FLAG_HIDDEN_ITEM_ROUTE_113_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x62)
#define FLAG_HIDDEN_ITEM_ROUTE_114_CARBOS                    (FLAG_HIDDEN_ITEMS_START + 0x04)
#define FLAG_HIDDEN_ITEM_ROUTE_113_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x2A)
#define FLAG_HIDDEN_ITEM_ROUTE_115_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x61)
#define FLAG_HIDDEN_ITEM_ROUTE_116_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2D)
#define FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES             (FLAG_HIDDEN_ITEMS_START + 0x60)
#define FLAG_HIDDEN_ITEM_ROUTE_117_REPEL                     (FLAG_HIDDEN_ITEMS_START + 0x48)
#define FLAG_HIDDEN_ITEM_ROUTE_118_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x42)
#define FLAG_HIDDEN_ITEM_ROUTE_118_IRON                      (FLAG_HIDDEN_ITEMS_START + 0x43)
#define FLAG_HIDDEN_ITEM_ROUTE_119_CALCIUM                   (FLAG_HIDDEN_ITEMS_START + 0x05)
#define FLAG_HIDDEN_ITEM_ROUTE_119_ULTRA_BALL                (FLAG_HIDDEN_ITEMS_START + 0x06)
#define FLAG_HIDDEN_ITEM_ROUTE_119_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x44)
#define FLAG_HIDDEN_ITEM_ROUTE_119_MAX_ETHER                 (FLAG_HIDDEN_ITEMS_START + 0x57)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_1              (FLAG_HIDDEN_ITEMS_START + 0x47)
#define FLAG_HIDDEN_ITEM_ROUTE_120_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x54)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_2              (FLAG_HIDDEN_ITEMS_START + 0x45)
#define FLAG_HIDDEN_ITEM_ROUTE_120_ZINC                      (FLAG_HIDDEN_ITEMS_START + 0x46)
#define FLAG_HIDDEN_ITEM_ROUTE_121_HP_UP                     (FLAG_HIDDEN_ITEMS_START + 0x27)
#define FLAG_HIDDEN_ITEM_ROUTE_121_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x28)
#define FLAG_HIDDEN_ITEM_ROUTE_121_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x49)
#define FLAG_HIDDEN_ITEM_ROUTE_121_MAX_REVIVE                (FLAG_HIDDEN_ITEMS_START + 0x64)
#define FLAG_HIDDEN_ITEM_ROUTE_123_SUPER_REPEL               (FLAG_HIDDEN_ITEMS_START + 0x07)
#define FLAG_HIDDEN_ITEM_ROUTE_123_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x29)
#define FLAG_HIDDEN_ITEM_ROUTE_123_HYPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x4A)
#define FLAG_HIDDEN_ITEM_ROUTE_123_PP_UP                     (FLAG_HIDDEN_ITEMS_START + 0x63)
#define FLAG_HIDDEN_ITEM_ROUTE_123_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x6E)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_1             (FLAG_HIDDEN_ITEMS_START + 0x5C)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_2             (FLAG_HIDDEN_ITEMS_START + 0x5D)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_3             (FLAG_HIDDEN_ITEMS_START + 0x5E)

#define FLAG_HIDE_NM_LANA                                           0x264
#define FLAG_HIDE_TRICK_HOUSE_LANA                                  0x265
#define FLAG_LANA_EVENT3_DONE                                       0x266
#define FLAG_HIDE_PCF_TOWN_LANA                                     0x267 // removed from lana AbnShipEvt
#define FLAG_HIDE_SCH_LANA                                          0x268
#define FLAG_HIDE_DR_LANA                                           0x269
#define FLAG_HIDE_R110_LANA                                         0x26A
#define FLAG_HIDE_AT1_LEAF                                          0x26B
#define FLAG_RYU_ZAPDOS                                             0x26C
#define FLAG_HIDE_IC_LANA                                           0x26D
#define FLAG_RYU_BRENDAN_GIFTPOKE_RECEIVED                          0x26E
#define FLAG_RYU_RIVAL_POKEMON_REWARD_1_GIVEN                       0x26F
#define FLAG_RYU_RIVAL_POKEMON_REWARD_2_GIVEN                       0x270
#define FLAG_RYU_NIGHT                                              0x271
#define FLAG_RYU_LEAF_ALTERNATE_LINE                                0x272
#define FLAG_RYU_LEAF_MTPYRE                                        0x273
#define FLAG_RYU_DAYCARE_LEAFEVENTPC                                0x274
#define FLAG_RYU_LANA_ALTEVENT3                                     0x275
#define FLAG_RYU_HIDE_LCC_DEPT_ROOF_NPC                             0x276
#define FLAG_RYU_LEAF_LCC_EVENT_DONE                                0x277
#define FLAG_LH_EVENT                                               0x278
#define FLAG_HIDE_ABN_SHIP_LANA                                     0x279
#define FLAG_NO_LONGER_USED_1                                       0x27A
#define FLAG_RYU_DS_FEMALE_MOM_MET                                  0x27B
#define FLAG_RYU_LANA_ALTEVENT2                                     0x27C
#define FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO                          0x27D
#define FLAG_RYU_DS_LEAF_LINE_CANCELLED                             0x27E
#define FLAG_LEAF_EVENT_0                                           0x27F
#define FLAG_RYU_DAWN_GIFTPOKE_RECEIVED                             0x280
#define FLAG_RYU_DS_LANETTE_ACQ                                     0x281
#define FLAG_RYU_DS_LANETTE_FRIENDS                                 0x282
#define FLAG_RYU_DS_LANETTE_CLOSEFRIENDS                            0x283
#define FLAG_RYU_DS_LANETTE_LOVERS                                  0x284
#define FLAG_RYU_DS_LANETTE_PARTNERS                                0x285
#define FLAG_RYU_GYM1HANDOUT                                        0x286
#define FLAG_RYU_GYM2HANDOUT                                        0x287
#define FLAG_RYU_GYM3HANDOUT                                        0x288
#define FLAG_RYU_GYM4HANDOUT                                        0x289
#define FLAG_RYU_GYM5HANDOUT                                        0x28A
#define FLAG_RYU_GYM6HANDOUT                                        0x28B
#define FLAG_RYU_GYM7HANDOUT                                        0x28C
#define FLAG_RYU_GYM8HANDOUT                                        0x28D
#define FLAG_RYU_USED_WIRELESSPC                                    0x28E
#define FLAG_RYU_HAS_WIRELESSPC                                     0x28F
#define FLAG_RYU_RANDOMBATTLE                                       0x290
#define FLAG_RYU_LANETTE_EVENT1                                     0x291
#define FLAG_RYU_LANETTE_INTRO                                      0x292
#define FLAG_RYU_LANETTE_EVENT_0                                    0x293
#define FLAG_RYU_DS_MALE_MOM_MET                                    0x294
#define FLAG_RYU_COLLISION_OFF                                      0x295
#define FLAG_RYU_MINNIE_GAME_CLEAR                                  0x296
#define FLAG_RYU_MAX_SCALE                                          0x297
#define FLAG_RYU_R119_RIVAL                                         0x298
#define FLAG_RYU_INTERACTED_RIVAL_R110                              0x299
#define FLAG_RYU_INTERACTED_LAVARIDGE                               0x29A
#define FLAG_RYU_TC_ENTERED                                         0x29B
#define FLAG_HAS_ENTERED_BATTLE_FRONTIER                            0x29C
#define FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE2                      0x29D
#define FLAG_RYU_DEVON_LINE_FINISHED                                0x29E
#define FLAG_RYU_DEVON_SCIENTIST                                    0x29F
#define FLAG_RYU_PLAYER_NOOB                                        0x2A0
#define FLAG_RYU_MEWTWO_OBTAINED                                    0x2A1
#define FLAG_RYU_GROUDON_ENCOUNTERED                                0x2A2
#define FLAG_RYU_LANA_EVENT14                                       0x2A3
#define FLAG_RYU_RECIEVED_ROTOM                                     0x2A4
#define FLAG_RYU_STAYED_2_NIGHTS_AT_LANETTE                         0x2A5
#define FLAG_RYU_ROXANNE_MEGA_REWARD                                0x2A6
#define FLAG_RYU_BRAWLY_MEGA_REWARD                                 0x2A7
#define FLAG_RYU_WATTSON_MEGA_REWARD                                0x2A8
#define FLAG_RYU_FLANNERY_MEGA_REWARD                               0x2A9
#define FLAG_RYU_NORMAN_MEGA_REWARD                                 0x2AA
#define FLAG_RYU_WINONA_MEGA_REWARD                                 0x2AB
#define FLAG_RYU_TAL_MEGA_REWARD                                    0x2AC
#define FLAG_RYU_JUAN_MEGA_REWARD                                   0x2AD
#define FLAG_RYU_SIDNEY_MEGA                                        0x2AE
#define FLAG_RYU_PHOEBE_MEGA                                        0x2AF
#define FLAG_RYU_GLACIA_MEGA                                        0x2B0
#define FLAG_RYU_DRAKE_MEGA                                         0x2B1
#define FLAG_RYU_AURORATICKET                                       0x2B2
#define FLAG_RYU_DEFEATED_OVERLORD                                  0x2B3
#define FLAG_RYU_MOM_AMULET_COIN                                    0x2B4
#define FLAG_RYU_MOM_LOPUNNITE                                      0x2B5
#define FLAG_RYU_MOM_EXP_SHARE                                      0x2B6
#define FLAG_RYU_HIDE_MINNIE                                        0x2B7
#define FLAG_RYU_PERSISTENT_WEATHER                                 0x2B8
#define FLAG_RYU_MINNIE_POKEMON_SCHOOL                              0x2B9
#define FLAG_JAGGED_PASS_TM54                                       0x2BA
#define FLAG_RYU_PREVENT_ACH_POPUP                                  0x2BB // EE-Unused?

// Event Flags
#define FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG                      0x2BC
#define FLAG_HIDE_APPRENTICE                                        0x2BD
#define FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN                0x2BE
#define FLAG_HIDE_UNION_ROOM_PLAYER_1                               0x2BF // EE-Unused
#define FLAG_HIDE_UNION_ROOM_PLAYER_2                               0x2C0 // EE-Unused
#define FLAG_HIDE_UNION_ROOM_PLAYER_3                               0x2C1 // EE-Unused
#define FLAG_HIDE_UNION_ROOM_PLAYER_4                               0x2C2 // EE-Unused
#define FLAG_HIDE_UNION_ROOM_PLAYER_5                               0x2C3 // EE-Unused
#define FLAG_HIDE_UNION_ROOM_PLAYER_6                               0x2C4 // EE-Unused
#define FLAG_HIDE_UNION_ROOM_PLAYER_7                               0x2C5 // EE-Unused
#define FLAG_HIDE_UNION_ROOM_PLAYER_8                               0x2C6 // EE-Unused
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1               0x2C7
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2               0x2C8
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3               0x2C9
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4               0x2CA
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5               0x2CB
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6               0x2CC
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS            0x2CD
#define FLAG_HIDE_MEW                                               0x2CE
#define FLAG_HIDE_ROUTE_104_RIVAL                                   0x2CF
#define FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE                  0x2D0
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH                  0x2D1
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_BEDROOM         0x2D2
#define FLAG_HIDE_ROUTE_103_RIVAL                                   0x2D3
#define FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE                    0x2D4
#define FLAG_HIDE_PETALBURG_WOODS_AQUA_GRUNT                        0x2D5
#define FLAG_HIDE_PETALBURG_CITY_WALLY                              0x2D6 // EE-Unused
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY   0x2D7
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_AUNT                        0x2D8 // EE-Unused

#define FLAG_RYU_PASSCODE_FRONTIER_MON_DEV                          0x2D9

#define FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER                     0x2DA
#define FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT                          0x2DB
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1                    0x2DC
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_2                   0x2DD
#define FLAG_HIDE_PLAYERS_HOUSE_DAD                                 0x2DE
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING      0x2DF
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_SIBLING         0x2E0
#define FLAG_SYS_DEXNAV_GET                                         0x2E1
#define FLAG_HIDE_ROUTE_104_MR_BRINEY                               0x2E2 // EE-Unused?
#define FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY                           0x2E3 // EE-Unused?
#define FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN                            0x2E4 // EE-Unused?
#define FLAG_HIDE_ROUTE_109_MR_BRINEY                               0x2E5 // EE-Unused?
#define FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT                          0x2E6 // EE-Unused?
#define FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN                       0x2E7 // EE-Unused?
#define FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT                          0x2E8 // EE-Unused?
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN            0x2E9
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_DAWN                  0x2EA
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION                  0x2EB
#define FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER                0x2EC
#define FLAG_HIDE_SLATEPORT_CITY_SCOTT                              0x2ED
#define FLAG_HIDE_ROUTE_101_ZIGZAGOON                               0x2EE
#define FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY                           0x2EF // EE-Unused
#define FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE                       0x2F0
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN              0x2F1
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1          0x2F2 // EE-Unused
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2          0x2F3 // EE-Unused
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA          0x2F4
#define FLAG_HIDE_LITTLE_ROOT_TOWN_PLAYERS_BEDROOM_MOM              0x2F5
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM                0x2F6
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_MOM                   0x2F7
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM      0x2F8
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK              0x2F9 // EE-Unused
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_TRUCK                 0x2FA // EE-Unused
#define FLAG_HIDE_DEOXYS                                            0x2FB
#define FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE                      0x2FC
#define FLAG_HIDE_MAUVILLE_CITY_SCOTT                               0x2FD // EE-Unused
#define FLAG_HIDE_VERDANTURF_TOWN_SCOTT                             0x2FE
#define FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT                  0x2FF
#define FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE                        0x300
#define FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE                      0x301
#define FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE                          0x302
#define FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE                         0x303
#define FLAG_HIDE_PETALBURG_GYM_NORMAN                              0x304 // EE-Unused
#define FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_2                         0x305
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_1         0x306
#define FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR                           0x307
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1                          0x308
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2                          0x309
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3                          0x30A
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4                          0x30B
#define FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS                          0x30C
#define FLAG_HIDE_PETALBURG_GYM_GREETER                             0x30D
#define FLAG_HIDE_MARINE_CAVE_KYOGRE                                0x30E
#define FLAG_HIDE_TERRA_CAVE_GROUDON                                0x30F
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM          0x310
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_MOM             0x311
#define FLAG_HIDE_ROUTE_119_SCOTT                                   0x312
#define FLAG_HIDE_LILCOVE_MOTEL_SCOTT                               0x313
#define FLAG_HIDE_MOSSDEEP_CITY_SCOTT                               0x314
#define FLAG_HIDE_FANCLUB_OLD_LADY                                  0x315
#define FLAG_HIDE_FANCLUB_BOY                                       0x316
#define FLAG_HIDE_FANCLUB_LITTLE_BOY                                0x317
#define FLAG_HIDE_FANCLUB_LADY                                      0x318
#define FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT               0x319
#define FLAG_HIDE_LITTLEROOT_TOWN_RIVAL                             0x31A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCH                             0x31B
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1                          0x31C
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1                          0x31D
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1                          0x31E
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3                          0x31F
#define FLAG_HIDE_LUGIA                                             0x320
#define FLAG_HIDE_HO_OH                                             0x321
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER                    0x322
#define FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER                   0x323
#define FLAG_ITEM_MT_FREEZE_CHILL_BALL                              0x324
#define FLAG_ITEM_MT_FREEZE_B1F_CALCIUM                             0x325
#define FLAG_ITEM_MT_FREEZE_B1F_PROTEIN                             0x326
#define FLAG_ITEM_MT_FREEZE_B1F_SUN_STONE                           0x327
#define FLAG_ITEM_MT_FREEZE_B1F_FIRE_STONE                          0x328
#define FLAG_ITEM_MT_FREEZE_B1F_FLAME_ORB                           0x329
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_SCOTT                           0x32A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL     0x32B
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE      0x32C
#define FLAG_HIDE_ROUTE_116_DROPPED_GLASSES_MAN                     0x32D
#define FLAG_HIDE_RUSTBORO_CITY_RIVAL                               0x32E
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL     0x32F
#define FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE                           0x330 // EE-Unused
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL       0x331
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_2F_POKE_BALL          0x332
#define FLAG_HIDE_ROUTE_112_TEAM_MAGMA                              0x333
#define FLAG_UNUSED_0x334                                           0x334
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE         0x335
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE         0x336
#define FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA                          0x337
#define FLAG_ITEM_CRAGGY_COAST_DIVE_BALL                            0x338
#define FLAG_ITEM_CRAGGY_COAST_PP_MAX                               0x339
#define FLAG_ITEM_CRAGGY_COAST_WAVE_INCENSE                         0x33A
#define FLAG_ITEM_CRAGGY_COAST_BIG_PEARL                            0x33B
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE                     0x33C
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE                      0x33D
#define FLAG_RYU_PLAYER_SENT_TO_JP_BY_SHELLY                        0x33E
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS               0x33F
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER                0x340
#define FLAG_HIDE_GRANITE_CAVE_STEVEN                               0x341
#define FLAG_RYU_HIDE_101_TIANA                                     0x342
#define FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY                       0x343
#define FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT              0x344
#define FLAG_HIDE_ROUTE_110_BIRCH                                   0x345
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA     0x346
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1                             0x347
#define FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN                      0x348
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN               0x349
#define FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO                         0x34A
#define FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY                      0x34B
#define FLAG_HIDE_RUSTBORO_CITY_SCIENTIST                           0x34C
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT                  0x34D
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE                      0x34E
#define FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD                           0x34F
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW            0x350
#define FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_2F_SLAKOTH_DOLL       0x351
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_2                        0x352
#define FLAG_HIDE_ROUTE_119_RIVAL                                   0x353
#define FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS                         0x354
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_1                        0x355
#define FLAG_UNUSED_0x356                                           0x356
#define FLAG_UNUSED_0x357                                           0x357
#define FLAG_UNUSED_0x358                                           0x358
#define FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS                              0x359
#define FLAG_UNUSED_0x35A                                           0x35A
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_1                   0x35B
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL                    0x35C
#define FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL                           0x35D
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA          0x35E
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN              0x35F
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1           0x360
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2           0x361
#define FLAG_UNUSED_0x362                                           0x362
#define FLAG_UNUSED_0x363                                           0x363
#define FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN                           0x364
#define FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY          0x365
#define FLAG_HIDE_LANETTES_HOUSE_LANETTE                            0x366
#define FLAG_HIDE_FALLORBOR_POKEMON_CENTER_LANETTE                  0x367
#define FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN                          0x368
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT    0x369
#define FLAG_UNUSED_0x36A                                           0x36A
#define FLAG_UNUSED_0x36B                                           0x36B
#define FLAG_UNUSED_0x36C                                           0x36C
#define FLAG_HIDE_MT_CHIMNEY_TRAINERS                               0x36D
#define FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT                         0x36E
#define FLAG_UNUSED_0x36F                                           0x36F
#define FLAG_UNUSED_0x370                                           0x370
#define FLAG_UNUSED_0x371                                           0x371
#define FLAG_UNUSED_0x372                                           0x372
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS         0x373
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1     0x374
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2     0x375
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE           0x376
#define FLAG_UNUSED_0x377                                           0x377
#define FLAG_HIDE_BATTLE_TOWER_OPPONENT                             0x378
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL                  0x379
#define FLAG_HIDE_ROUTE_119_TEAM_AQUA                               0x37A
#define FLAG_UNUSED_0x37B                                           0x37B
#define FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS                      0x37C
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS                      0x37D
#define FLAG_UNUSED_0x37E                                           0x37E
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2         0x37F
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380          0x380
#define FLAG_HIDE_ROUTE_101_BIRCH                                   0x381
#define FLAG_HIDE_ROUTE_103_BIRCH                                   0x382
#define FLAG_HIDE_TRICK_HOUSE_END_MAN                               0x383
#define FLAG_HIDE_ROUTE_110_TEAM_AQUA                               0x384
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2                          0x385
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2                          0x386
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2                          0x387
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3                          0x388
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS                     0x389
#define FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST                      0x38A
#define FLAG_HIDE_FALLARBOR_AZURILL                                 0x38B
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT                   0x38C
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR                      0x38D
#define FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE                         0x38E
#define FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON              0x38F
#define FLAG_HIDE_MAUVILLE_CITY_WATTSON                             0x390
#define FLAG_HIDE_MAUVILLE_GYM_WATTSON                              0x391
#define FLAG_UNUSED_0x392                                           0x392
#define FLAG_UNUSED_0x393                                           0x393
#define FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE                             0x394
#define FLAG_UNUSED_0x395                                           0x395
#define FLAG_HIDE_BATTLE_TOWER_REPORTER                             0x396
#define FLAG_HIDE_ROUTE_110_RIVAL                                   0x397
#define FLAG_HIDE_CHAMPIONS_ROOM_RIVAL                              0x398
#define FLAG_HIDE_CHAMPIONS_ROOM_BIRCH                              0x399
#define FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE                           0x39A
#define FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE                           0x39B
#define FLAG_HIDE_AQUA_HIDEOUT_GRUNTS                               0x39C
#define FLAG_HIDE_LILCOVE_MOTEL_GAME_DESIGNERS                      0x39D
#define FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA                              0x39E
#define FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA                             0x39F
#define FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO                      0x3A0
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL                              0x3A1
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE                      0x3A2
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1                             0x3A3
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2                             0x3A4
#define FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL                      0x3A5
#define FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL                     0x3A6
#define FLAG_HIDE_REGIROCK                                          0x3A7
#define FLAG_HIDE_REGICE                                            0x3A8
#define FLAG_HIDE_REGISTEEL                                         0x3A9
#define FLAG_HIDE_METEOR_FALLS_TEAM_AQUA                            0x3AA
#define FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA                           0x3AB
#define FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN                      0x3AC // EE-Unused
#define FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT               0x3AD // EE-Unused?
#define FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO                          0x3AE
#define FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW                 0x3AF // EE-Unused?
#define FLAG_ITEM_MT_FREEZE_2F_RARE_CANDY_1                         0x3B0
#define FLAG_ITEM_MT_FREEZE_2F_RARE_CANDY_2                         0x3B1
#define FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS                       0x3B2 // EE-Unused?
#define FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE                          0x3B3 // EE-Unused
#define FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN                        0x3B4
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE              0x3B5
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY                       0x3B6
#define FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER                       0x3B7
#define FLAG_RECEIVED_SHOAL_SALT_1                                  0x3B8
#define FLAG_RECEIVED_SHOAL_SALT_2                                  0x3B9
#define FLAG_RECEIVED_SHOAL_SALT_3                                  0x3BA
#define FLAG_RECEIVED_SHOAL_SALT_4                                  0x3BB
#define FLAG_RECEIVED_SHOAL_SHELL_1                                 0x3BC
#define FLAG_RECEIVED_SHOAL_SHELL_2                                 0x3BD
#define FLAG_RECEIVED_SHOAL_SHELL_3                                 0x3BE
#define FLAG_RECEIVED_SHOAL_SHELL_4                                 0x3BF
#define FLAG_HIDE_ROUTE_111_SECRET_POWER_MAN                        0x3C0
#define FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION                       0x3C1
#define FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN      0x3C2
#define FLAG_SYS_DEXNAV_SEARCH                                      0x3C3
#define FLAG_SYS_DETECTOR_MODE                                      0x3C4
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT 0x3C5
#define FLAG_HIDE_ROUTE_118_STEVEN                                  0x3C6
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN                0x3C7
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL       0x3C8
#define FLAG_HIDE_ALL_KECLEON_OWS                                   0x3C9
#define FLAG_UNUSED_0x3CA                                           0x3CA
#define FLAG_HIDE_LILYCOVE_CITY_RIVAL                               0x3CB
#define FLAG_HIDE_ROUTE_120_STEVEN                                  0x3CC
#define FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN                            0x3CD // EE-Unused
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1                            0x3CE
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2                            0x3CF
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3                            0x3D0
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1                      0x3D1
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2                      0x3D2
#define FLAG_HIDE_OLDALE_TOWN_RIVAL                                 0x3D3
#define FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE      0x3D4 // EE-Unused?
#define FLAG_UNUSED_0x3D5                                           0x3D5
#define FLAG_UNUSED_0x3D6                                           0x3D6
#define FLAG_RYU_HOOPA                                              0x3D7
#define FLAG_RYU_HOOPA_RAN                                          0x3D8
#define FLAG_UNUSED_0x3D9                                           0x3D9
#define FLAG_UNUSED_0x3DA                                           0x3DA
#define FLAG_UNUSED_0x3DB                                           0x3DB
#define FLAG_UNUSED_0x3DC                                           0x3DC
#define FLAG_UNUSED_0x3DD                                           0x3DD
#define FLAG_UNUSED_0x3DE                                           0x3DE
#define FLAG_HIDE_ROUTE_101_BOY                                     0x3DF
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M                 0x3E0
#define FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON          0x3E1
#define FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY                       0x3E2
#define FLAG_HIDE_PETALBURG_CITY_SCOTT                              0x3E3
#define FLAG_ITEM_SNOWY_SHORE_DARK_WORLD_FIRE_STONE                          0x3E4 // EE-Unused
#define FLAG_ITEM_SNOWY_SHORE_DARK_WORLD_                            0x3E5 // EE-Unused
#define FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON                           0x3E6 // EE-Unused
#define FLAG_UNUSED_0x3E7                                           0x3E7

// Item Ball Flags
#define FLAG_ITEM_ROUTE_102_POTION                                  0x3E8
#define FLAG_ITEM_ROUTE_116_X_SPECIAL                               0x3E9
#define FLAG_ITEM_ROUTE_104_PP_UP                                   0x3EA
#define FLAG_ITEM_ROUTE_105_IRON                                    0x3EB
#define FLAG_ITEM_ROUTE_105_PROTEIN                                 0x3EC
#define FLAG_ITEM_ROUTE_109_PP_UP                                   0x3ED
#define FLAG_ITEM_ROUTE_109_RARE_CANDY                              0x3EE
#define FLAG_ITEM_ROUTE_110_DIRE_HIT                                0x3EF
#define FLAG_ITEM_ROUTE_111_TM_37                                   0x3F0
#define FLAG_ITEM_ROUTE_111_STARDUST                                0x3F1
#define FLAG_ITEM_ROUTE_111_HP_UP                                   0x3F2
#define FLAG_ITEM_ROUTE_112_NUGGET                                  0x3F3
#define FLAG_ITEM_ROUTE_113_MAX_ETHER                               0x3F4
#define FLAG_ITEM_ROUTE_113_SUPER_REPEL                             0x3F5
#define FLAG_ITEM_ROUTE_114_RARE_CANDY                              0x3F6
#define FLAG_ITEM_ROUTE_114_PROTEIN                                 0x3F7
#define FLAG_ITEM_ROUTE_115_SUPER_POTION                            0x3F8
#define FLAG_ITEM_ROUTE_115_TM_01                                   0x3F9
#define FLAG_ITEM_ROUTE_115_IRON                                    0x3FA
#define FLAG_ITEM_ROUTE_116_ETHER                                   0x3FB
#define FLAG_ITEM_ROUTE_116_REPEL                                   0x3FC
#define FLAG_ITEM_ROUTE_116_HP_UP                                   0x3FD
#define FLAG_ITEM_ROUTE_117_GREAT_BALL                              0x3FE
#define FLAG_ITEM_ROUTE_117_REVIVE                                  0x3FF
#define FLAG_ITEM_ROUTE_119_SUPER_REPEL                             0x400
#define FLAG_ITEM_ROUTE_119_ZINC                                    0x401
#define FLAG_ITEM_ROUTE_119_ELIXIR_1                                0x402
#define FLAG_ITEM_ROUTE_119_LEAF_STONE                              0x403
#define FLAG_ITEM_ROUTE_119_RARE_CANDY                              0x404
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_1                          0x405
#define FLAG_ITEM_ROUTE_120_NUGGET                                  0x406
#define FLAG_ITEM_ROUTE_120_FULL_HEAL                               0x407
#define FLAG_ITEM_ROUTE_123_CALCIUM                                 0x408

#define FLAG_ITEM_BALL_AMPHAROSITE                                  0x409

#define FLAG_ITEM_ROUTE_127_ZINC                                    0x40A
#define FLAG_ITEM_ROUTE_127_CARBOS                                  0x40B
#define FLAG_ITEM_ROUTE_132_RARE_CANDY                              0x40C
#define FLAG_ITEM_ROUTE_133_BIG_PEARL                               0x40D
#define FLAG_ITEM_ROUTE_133_STAR_PIECE                              0x40E
#define FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE                         0x40F
#define FLAG_ITEM_PETALBURG_CITY_ETHER                              0x410
#define FLAG_ITEM_RUSTBORO_CITY_X_DEFEND                            0x411
#define FLAG_ITEM_LILYCOVE_CITY_MAX_REPEL                           0x412
#define FLAG_ITEM_MOSSDEEP_CITY_NET_BALL                            0x413
#define FLAG_ITEM_METEOR_FALLS_1F_1R_TM_23                          0x414
#define FLAG_ITEM_METEOR_FALLS_1F_1R_FULL_HEAL                      0x415
#define FLAG_ITEM_METEOR_FALLS_1F_1R_MOON_STONE                     0x416
#define FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP                          0x417
#define FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL                          0x418
#define FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER                          0x419
#define FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE                       0x41A
#define FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL                        0x41B
#define FLAG_ITEM_MT_PYRE_5F_LAX_INCENSE                            0x41C
#define FLAG_ITEM_GRANITE_CAVE_B2F_REPEL                            0x41D
#define FLAG_ITEM_GRANITE_CAVE_B2F_RARE_CANDY                       0x41E
#define FLAG_ITEM_PETALBURG_WOODS_X_ATTACK                          0x41F
#define FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL                        0x420
#define FLAG_ITEM_ROUTE_104_POKE_BALL                               0x421
#define FLAG_ITEM_PETALBURG_WOODS_ETHER                             0x422
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_3R_ECAPE_ROPE                    0x423
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL                  0x424
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL                  0x425
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL                    0x426
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL                  0x427
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL                    0x428
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL                    0x429
#define FLAG_ITEM_ROUTE_124_YELLOW_SHARD                            0x42A
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL                 0x42B
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL                  0x42C
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL                    0x42D
#define FLAG_ITEM_JAGGED_PASS_BURN_HEAL                             0x42E
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR                       0x42F
#define FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL                        0x430
#define FLAG_ITEM_MT_PYRE_EXTERIOR_MAX_POTION                       0x431
#define FLAG_ITEM_MT_PYRE_EXTERIOR_TM_48                            0x432
#define FLAG_ITEM_NEW_MAUVILLE_ULTRA_BALL                           0x433
#define FLAG_ITEM_NEW_MAUVILLE_ESCAPE_ROPE                          0x434
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL    0x435
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER        0x436
#define FLAG_ITEM_SCORCHED_SLAB_TM_11                               0x437
#define FLAG_ITEM_METEOR_FALLS_B1F_2R_TM_02                         0x438
#define FLAG_ITEM_SHOAL_CAVE_ENTRANCE_BIG_PEARL                     0x439
#define FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY                  0x43A
#define FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_ICE_HEAL                   0x43B
#define FLAG_ITEM_VICTORY_ROAD_1F_MAX_ELIXIR                        0x43C
#define FLAG_ITEM_VICTORY_ROAD_1F_PP_UP                             0x43D
#define FLAG_ITEM_VICTORY_ROAD_B1F_TM_29                            0x43E
#define FLAG_ITEM_VICTORY_ROAD_B1F_FULL_RESTORE                     0x43F
#define FLAG_ITEM_VICTORY_ROAD_B2F_FULL_HEAL                        0x440
#define FLAG_ITEM_MT_PYRE_6F_TM_30                                  0x441
#define FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_TM_26                      0x442
#define FLAG_ITEM_FIERY_PATH_TM06                                   0x443 
#define FLAG_ITEM_ROUTE_124_RED_SHARD                               0x444 
#define FLAG_ITEM_ROUTE_124_BLUE_SHARD                              0x445 
#define FLAG_ITEM_SAFARI_ZONE_NORTH_WEST_TM_22                      0x446 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_HARBOR_MAIL               0x447 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_ESCAPE_ROPE              0x448 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_DIVE_BALL              0x449 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM_13                    0x44A 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE                  0x44B 
#define FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY        0x44C 
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_WATER_STONE    0x44D 
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM_18          0x44E 
#define FLAG_ITEM_ROUTE_121_CARBOS                                  0x44F
#define FLAG_ITEM_ROUTE_123_ULTRA_BALL                              0x450
#define FLAG_ITEM_ROUTE_126_GREEN_SHARD                             0x451
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_2                          0x452
#define FLAG_ITEM_ROUTE_120_HYPER_POTION                            0x453
#define FLAG_ITEM_ROUTE_120_NEST_BALL                               0x454
#define FLAG_ITEM_ROUTE_123_ELIXIR                                  0x455
#define FLAG_ITEM_NEW_MAUVILLE_THUNDER_STONE                        0x456
#define FLAG_ITEM_FIERY_PATH_FIRE_STONE                             0x457
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_TM_07                         0x458
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE                0x459
#define FLAG_ITEM_ROUTE_103_GUARD_SPEC                              0x45A
#define FLAG_ITEM_ROUTE_104_X_ACCURACY                              0x45B
#define FLAG_ITEM_MAUVILLE_CITY_X_SPEED                             0x45C
#define FLAG_ITEM_PETALBURD_WOODS_PARALYZE_HEAL                     0x45D
#define FLAG_ITEM_ROUTE_115_GREAT_BALL                              0x45E
#define FLAG_ITEM_SAFARI_ZONE_NORTH_CALCIUM                         0x45F
#define FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL                            0x460
#define FLAG_ITEM_ROUTE_118_HYPER_POTION                            0x461
#define FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL                            0x462
#define FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL                        0x463
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL                      0x464

#define FLAG_RYU_MET_RIVAL_LITTLEROOT                               0x465
#define FLAG_RYU_FRONTIER_MODE                                      0x466
#define FLAG_RYU_NUZLOCKEMODE                                       0x467
#define FLAG_RYU_HARDCORE_MODE                                      0x468

#define FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL                             0x469
#define FLAG_ITEM_MT_PYRE_4F_SEA_INCENSE                            0x46A
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE                 0x46B
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET                           0x46C
#define FLAG_RYU_EXP_DRIVE_DISABLE_EARNING                          0x46D
#define FLAG_ITEM_ROUTE_119_NUGGET                                  0x46E
#define FLAG_ITEM_ROUTE_104_POTION                                  0x46F
#define FLAG_RYU_NUZLOCKEFAILED                                     0x470
#define FLAG_ITEM_ROUTE_103_PP_UP                                   0x471
#define FLAG_RYU_DEVELOPER_ITEM_MENU                                0x472
#define FLAG_ITEM_ROUTE_108_STAR_PIECE                              0x473
#define FLAG_ITEM_ROUTE_109_POTION                                  0x474
#define FLAG_ITEM_ROUTE_110_ELIXIR                                  0x475
#define FLAG_ITEM_ROUTE_111_ELIXIR                                  0x476
#define FLAG_ITEM_ROUTE_113_HYPER_POTION                            0x477
#define FLAG_ITEM_ROUTE_115_HEAL_POWDER                             0x478

#define FLAG_RYU_DEVELOPER_POKEMON_MENU                             0x479

#define FLAG_ITEM_ROUTE_116_POTION                                  0x47A
#define FLAG_ITEM_ROUTE_119_ELIXIR_2                                0x47B
#define FLAG_ITEM_ROUTE_120_REVIVE                                  0x47C
#define FLAG_ITEM_ROUTE_121_REVIVE                                  0x47D
#define FLAG_ITEM_ROUTE_121_ZINC                                    0x47E
#define FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY                       0x47F
#define FLAG_ITEM_ROUTE_123_PP_UP                                   0x480
#define FLAG_ITEM_ROUTE_123_REVIVAL_HERB                            0x481
#define FLAG_ITEM_ROUTE_125_BIG_PEARL                               0x482
#define FLAG_ITEM_ROUTE_127_RARE_CANDY                              0x483
#define FLAG_ITEM_ROUTE_132_PROTEIN                                 0x484
#define FLAG_ITEM_ROUTE_133_MAX_REVIVE                              0x485
#define FLAG_ITEM_ROUTE_134_CARBOS                                  0x486
#define FLAG_ITEM_ROUTE_134_STAR_PIECE                              0x487
#define FLAG_ITEM_ROUTE_114_ENERGY_POWDER                           0x488
#define FLAG_ITEM_ROUTE_115_PP_UP                                   0x489
#define FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP                            0x48A
#define FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS                            0x48B
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR                    0x48C
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE                  0x48D
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET                        0x48E
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX                        0x48F
#define FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE                       0x490
#define FLAG_ITEM_SAFARI_ZONE_NORTH_EAST_NUGGET                     0x491
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_EAST_BIG_PEARL                  0x492

#define FLAG_RYU_PASSCODE_MASTERBALL                                0x493
#define FLAG_RYU_PASSCODE_TUTORVOUCHER                              0x494
#define FLAG_RYU_PASSCODE_KOUTA                                     0x495
#define FLAG_RYU_PASSCODE_GCMS_GIFT                                 0x496
#define FLAG_RYU_DEV_DISENC                                         0x497
#define FLAG_RYU_LANDMARK_MH                                        0x498
#define FLAG_RYU_LANDMARK_LCCDEPTSTORE                              0x499
// In case we ever run out of unused flags,
// this flag can be freed by replacing all IsSet() checks
// with greater than zero comparisons on VAR_RYU_NGPLUS_COUNT
#define FLAG_RYU_ISNGPLUS                                           0x49A
#define FLAG_RYU_HAS_IMPRINTER                                      0x49B
#define FLAG_RYU_INTRO_COMPLETE                                     0x49C
#define FLAG_RYU_ON_DATE                                            0x49D
#define FLAG_RYU_ON_DATE_2                                          0x49E
#define FLAG_RYU_FORECASTER                                         0x49F
#define FLAG_RYU_HAS_FORECASTER                                     0x4A0
#define FLAG_LANDMARK_AQUA_OFFICE                                   0x4A1
#define FLAG_RYU_HAS_EXP_DRIVE                                      0x4A2
#define FLAG_RYU_NM8_HARDSTONE                                      0x4A3
#define FLAG_RYU_NM8_MAXREPEL                                       0x4A4
#define FLAG_RYU_NM8_LUXBALL                                        0x4A5
#define FLAG_RYU_NM8_EQ                                             0x4A6
#define FLAG_RYU_NM8_PPMAX                                          0x4A7
#define FLAG_RYU_NM8_MAXREV                                         0x4A8
#define FLAG_RYU_NM8_MAXELIX                                        0x4A9
#define FLAG_RYU_NM8_BIGPEARL                                       0x4AA
#define FLAG_RYU_HIDE_CRYSTALONIX_OW                                0x4AB
#define FLAG_RYU_AQUA_MISSION3COMPLETE                              0x4AC
#define FLAG_RYU_AQUA_INTRO                                         0x4AD
#define FLAG_RYU_PLAYER_ARCHIE_ACQ                                  0x4AE
#define FLAG_RYU_AQUA_MISSION1COMPLETE                              0x4AF
#define FLAG_RYU_DS_LANETTE_BADEND                                  0x4B0
#define FLAG_MET_PROF_COSMO                                         0x4B1
#define FLAG_CHALLENGER_STEVEN_AGGRONITE                            0x4B2
#define FLAG_RYU_HAS_EXPSHARE                                       0x4B3
#define FLAG_RYU_DEVON_HIDE_MATT_SUB                                0x4B4
#define FLAG_RYU_CHAR_Y_MEGA                                        0x4B5
#define FLAG_RYU_GOT_AUDINITE                                       0x4B6
#define FLAG_RYU_SST_CHDX                                           0x4B7
#define FLAG_RYU_CHEATS_USED                                        0x4B8
#define FLAG_RYU_BETA_MENU_USED                                     0x4B9
#define FLAG_RYU_OBTAINED_GARDEVOIRITE                              0x4BA
#define FLAG_RYU_OBTAINED_SCEPTILITE                                0x4BB
#define FLAG_RYU_OBTAINED_GARCHOMPITE                               0x4BC
#define FLAG_RYU_OBTAINED_GALLADITE                                 0x4BD
#define FLAG_RYU_OBTAINED_DIANCITE                                  0x4BE
#define FLAG_RYU_OBTAINED_GENGARITE                                 0x4BF
#define FLAG_RYU_OBTAINED_HOUNDOOMINITE                             0x4C0
#define FLAG_RYU_CLEARED_COOL                                       0x4C1
#define FLAG_RYU_CLEARED_BEAUTY                                     0x4C2
#define FLAG_RYU_CLEARED_TOUGH                                      0x4C3
#define FLAG_RYU_CLEARED_SMART                                      0x4C4
#define FLAG_RYU_CLEARED_CUTE                                       0x4C5
#define FLAG_RYU_GIVEN_DIANCIE                                      0x4C6
#define FLAG_HIDE_MTPYRE_BANNETITE                                  0x4C7
#define FLAG_RYU_ARTICUNO                                           0x4C8
#define FLAG_RYU_CELEBI                                             0x4C9
#define FLAG_RYU_RAIKOU                                             0x4CA
#define FLAG_RYU_SUICUNE                                            0x4CB
#define FLAG_RYU_JIRACHI                                            0x4CC
#define FLAG_RYU_ENTEI                                              0x4CD
#define FLAG_RYU_CAPTURED_MELOETTA                                  0x4CE
#define FLAG_RYU_FIRST_MELOETTA_MSG                                 0x4CF
#define FLAG_RYU_SECOND_MELOETTA_MSG                                0x4D0
#define FLAG_RYU_REGIGIGAS                                          0x4D1
#define FLAG_HAS_ACRO_BIKE                                          0x4D2
#define FLAG_HAS_MACH_BIKE                                          0x4D3
#define FLAG_RYU_SUB_ROOM_SHELLY                                    0x4D4
#define FLAG_RYU_TYRANITARITE                                       0x4D5
#define FLAG_RYU_DTC_STEELIXITE                                     0x4D6
#define FLAG_RYU_FORCE_TUCKER                                       0x4D7
#define FLAG_RYU_LANA_SLATEPORT                                     0x4D8
#define FLAG_RYU_SC_PC_LANA_INTRO_EVENT                             0x4D9
#define FLAG_RYU_SPIRITOMB_IN_PROGRESS                              0x4DA
#define FLAG_RYU_FINISHED_SPIRITOMB_SIDEQUEST                       0x4DB
#define FLAG_RYU_HIDE_HAREM_EVENT_NPCS                              0x4DC
#define FLAG_RYU_FIRST_GAME_CLEAR                                   0x4DD
#define FLAG_RYU_HAREM_EVENT_COMPLETED                              0x4DE
#define FLAG_RYU_HIDE_HAREM_EVENT_BRENDAN                           0x4DF
#define FLAG_RYU_HIDE_HAREM_EVENT_DAWN                              0x4E0
#define FLAG_RYU_RECRUITED_MINNIE                                   0x4E1
#define FLAG_RYU_GYARADOSITE                                        0x4E2
#define FLAG_RYU_PINSIRITE                                          0x4E3
#define FLAG_RYU_HERACRONITE                                        0x4E4
#define FLAG_RYU_BEEDRILLITE                                        0x4E5
#define FLAG_RYU_BLASTOISINITE                                      0x4E6
#define FLAG_HILL_REWARD_RECIEVED                                   0x4E7
#define FLAG_RYU_MANAPHY                                            0x4E8
#define FLAG_RYU_RECEIVED_PHIONE_EGG                                0x4E9
#define FLAG_RYU_HIDE_MANAPHY                                       0x4EA
#define FLAG_ITEM_RUSTBORO_CITY_REVIVE                              0x4EB
#define FLAG_RYU_NECROZMA                                           0x4EC
#define FLAG_RYU_TYPENULL                                           0x4ED
#define FLAG_RYU_COMPENSATION_REWARD                                0x4EE
#define FLAG_LANDMARK_SNOWY_SHORE                                   0x4EF

#define FLAG_DEFEATED_RUSTBORO_GYM                                  0x4F0
#define FLAG_DEFEATED_DEWFORD_GYM                                   0x4F1
#define FLAG_DEFEATED_MAUVILLE_GYM                                  0x4F2
#define FLAG_DEFEATED_LAVARIDGE_GYM                                 0x4F3
#define FLAG_DEFEATED_PETALBURG_GYM                                 0x4F4
#define FLAG_DEFEATED_FORTREE_GYM                                   0x4F5
#define FLAG_DEFEATED_MOSSDEEP_GYM                                  0x4F6
#define FLAG_DEFEATED_SOOTOPOLIS_GYM                                0x4F7
#define FLAG_DEFEATED_METEOR_FALLS_STEVEN                           0x4F8 // EE-Unused (currently)

#define FLAG_RYU_CHOOSING_FRONTIER_STARTER                          0x4F9 // Tells the code for frontier mon giver that you're picking a starter
#define FLAG_RYU_PLAYER_HELPING_MAGMA                               0x4FA

#define FLAG_DEFEATED_ELITE_4_SIDNEY                                0x4FB
#define FLAG_DEFEATED_ELITE_4_PHOEBE                                0x4FC
#define FLAG_DEFEATED_ELITE_4_GLACIA                                0x4FD
#define FLAG_DEFEATED_ELITE_4_DRAKE                                 0x4FE

#define FLAG_DO_NOT_USE                                             0x4FF // Bugged flag, randomly sets itself for no reason. DOn't use/

// Trainer Flags
// Trainer flags occupy 0x500 - 0x85F, the last 9 of which are unused
// See constants/opponents.h. The values there + FLAG_TRAINER_FLAG_START are the flag IDs

#define TRAINER_FLAGS_START                                         0x500
#define TRAINER_FLAGS_END                                           (TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1) // 0x85F

// System Flags

#define SYSTEM_FLAGS                                   (TRAINER_FLAGS_END + 1) // 0x860

#define FLAG_SYS_POKEMON_GET                         (SYSTEM_FLAGS + 0x0) // FLAG_0x860
#define FLAG_SYS_POKEDEX_GET                         (SYSTEM_FLAGS + 0x1)
#define FLAG_SYS_POKENAV_GET                         (SYSTEM_FLAGS + 0x2)
#define FLAG_RYU_HIDE_COTTAGE_MAGMA                  (SYSTEM_FLAGS + 0x3)
#define FLAG_SYS_GAME_CLEAR                          (SYSTEM_FLAGS + 0x4)
#define FLAG_SYS_CHAT_USED                           (SYSTEM_FLAGS + 0x5)
#define FLAG_SYS_HIPSTER_MEET                        (SYSTEM_FLAGS + 0x6)

// Badges
#define FLAG_BADGE01_GET                             (SYSTEM_FLAGS + 0x7)
#define FLAG_BADGE02_GET                             (SYSTEM_FLAGS + 0x8)
#define FLAG_BADGE03_GET                             (SYSTEM_FLAGS + 0x9)
#define FLAG_BADGE04_GET                             (SYSTEM_FLAGS + 0xA)
#define FLAG_BADGE05_GET                             (SYSTEM_FLAGS + 0xB)
#define FLAG_BADGE06_GET                             (SYSTEM_FLAGS + 0xC)
#define FLAG_BADGE07_GET                             (SYSTEM_FLAGS + 0xD)
#define FLAG_BADGE08_GET                             (SYSTEM_FLAGS + 0xE)
#define NUM_BADGES                                   (1 + FLAG_BADGE08_GET - FLAG_BADGE01_GET)

// Towns and Cities
#define FLAG_VISITED_LITTLEROOT_TOWN                (SYSTEM_FLAGS + 0xF)
#define FLAG_VISITED_OLDALE_TOWN                    (SYSTEM_FLAGS + 0x10)
#define FLAG_VISITED_DEWFORD_TOWN                   (SYSTEM_FLAGS + 0x11)
#define FLAG_VISITED_LAVARIDGE_TOWN                 (SYSTEM_FLAGS + 0x12)
#define FLAG_VISITED_FALLARBOR_TOWN                 (SYSTEM_FLAGS + 0x13)
#define FLAG_VISITED_VERDANTURF_TOWN                (SYSTEM_FLAGS + 0x14)
#define FLAG_VISITED_PACIFIDLOG_TOWN                (SYSTEM_FLAGS + 0x15)
#define FLAG_VISITED_PETALBURG_CITY                 (SYSTEM_FLAGS + 0x16)
#define FLAG_VISITED_SLATEPORT_CITY                 (SYSTEM_FLAGS + 0x17)
#define FLAG_VISITED_MAUVILLE_CITY                  (SYSTEM_FLAGS + 0x18)
#define FLAG_VISITED_RUSTBORO_CITY                  (SYSTEM_FLAGS + 0x19)
#define FLAG_VISITED_FORTREE_CITY                   (SYSTEM_FLAGS + 0x1A)
#define FLAG_VISITED_LILYCOVE_CITY                  (SYSTEM_FLAGS + 0x1B)
#define FLAG_VISITED_MOSSDEEP_CITY                  (SYSTEM_FLAGS + 0x1C)
#define FLAG_VISITED_SOOTOPOLIS_CITY                (SYSTEM_FLAGS + 0x1D)
#define FLAG_VISITED_EVER_GRANDE_CITY               (SYSTEM_FLAGS + 0x1E)

#define FLAG_IS_CHAMPION                            (SYSTEM_FLAGS + 0x1F) // Seems to be related to linking.
#define FLAG_NURSE_UNION_ROOM_REMINDER              (SYSTEM_FLAGS + 0x20) // EE-Unused

#define FLAG_RYU_BOSS_WILD                          (SYSTEM_FLAGS + 0x21) 
#define FLAG_RYU_SHELLY_MEGA_REWARD                 (SYSTEM_FLAGS + 0x22) 
#define FLAG_RYU_DAWN_MEGA_REWARD                   (SYSTEM_FLAGS + 0x23) 
#define FLAG_RYU_BRENDAN_MEGA_REWARD                (SYSTEM_FLAGS + 0x24) 
#define FLAG_RYU_LEAF_MEGA_REWARD                   (SYSTEM_FLAGS + 0x25) 
#define FLAG_RYU_HIDE_GC_BLAISE                     (SYSTEM_FLAGS + 0x26) 
#define FLAG_RYU_PLAYER_MAGMA_MEMBER                (SYSTEM_FLAGS + 0x27)

#define FLAG_SYS_USE_FLASH                          (SYSTEM_FLAGS + 0x28) // EE-Unused
#define FLAG_SYS_USE_STRENGTH                       (SYSTEM_FLAGS + 0x29)
#define FLAG_SYS_WEATHER_CTRL                       (SYSTEM_FLAGS + 0x2A)
#define FLAG_RYU_HEATRAN                            (SYSTEM_FLAGS + 0x2B)
#define FLAG_RYU_HEATRAN_RAN                        (SYSTEM_FLAGS + 0x2C)
#define FLAG_SYS_CRUISE_MODE                        (SYSTEM_FLAGS + 0x2D)

#define FLAG_RYU_MAGMA_4_NOTIFY                     (SYSTEM_FLAGS + 0x2E)
#define FLAG_RYU_HIDE_111_MAGMA_MEETING             (SYSTEM_FLAGS + 0x2F)

#define FLAG_SYS_TV_HOME                            (SYSTEM_FLAGS + 0x30)
#define FLAG_SYS_TV_WATCH                           (SYSTEM_FLAGS + 0x31)
#define FLAG_SYS_TV_START                           (SYSTEM_FLAGS + 0x32)
#define FLAG_SYS_POPWORD_INPUT                      (SYSTEM_FLAGS + 0x33)
#define FLAG_SYS_MIX_RECORD                         (SYSTEM_FLAGS + 0x34)
#define FLAG_SYS_CLOCK_SET                          (SYSTEM_FLAGS + 0x35)
#define FLAG_SYS_NATIONAL_DEX                       (SYSTEM_FLAGS + 0x36)
#define FLAG_SYS_CAVE_SHIP                          (SYSTEM_FLAGS + 0x37) // Unused Flag, leftover from R/S debug, presumably used by Emerald's debug too
#define FLAG_SYS_CAVE_WONDER                        (SYSTEM_FLAGS + 0x38) // Unused Flag, same as above
#define FLAG_RYU_IGNORE_CAP                         (SYSTEM_FLAGS + 0x39)
#define FLAG_SYS_SHOAL_TIDE                         (SYSTEM_FLAGS + 0x3A)
#define FLAG_SYS_RIBBON_GET                         (SYSTEM_FLAGS + 0x3B)

#define FLAG_LANDMARK_FLOWER_SHOP                   (SYSTEM_FLAGS + 0x3C)
#define FLAG_LANDMARK_MR_BRINEY_HOUSE               (SYSTEM_FLAGS + 0x3D)
#define FLAG_LANDMARK_ABANDONED_SHIP                (SYSTEM_FLAGS + 0x3E)
#define FLAG_LANDMARK_SEASHORE_HOUSE                (SYSTEM_FLAGS + 0x3F)
#define FLAG_LANDMARK_NEW_MAUVILLE                  (SYSTEM_FLAGS + 0x40)
#define FLAG_LANDMARK_OLD_LADY_REST_SHOP            (SYSTEM_FLAGS + 0x41)
#define FLAG_LANDMARK_TRICK_HOUSE                   (SYSTEM_FLAGS + 0x42)
#define FLAG_LANDMARK_WINSTRATE_FAMILY              (SYSTEM_FLAGS + 0x43)
#define FLAG_LANDMARK_GLASS_WORKSHOP                (SYSTEM_FLAGS + 0x44)
#define FLAG_LANDMARK_LANETTES_HOUSE                (SYSTEM_FLAGS + 0x45)
#define FLAG_LANDMARK_POKEMON_DAYCARE               (SYSTEM_FLAGS + 0x46)
#define FLAG_LANDMARK_SEAFLOOR_CAVERN               (SYSTEM_FLAGS + 0x47)
#define FLAG_LANDMARK_BATTLE_FRONTIER               (SYSTEM_FLAGS + 0x48)
#define FLAG_LANDMARK_SOUTHERN_ISLAND               (SYSTEM_FLAGS + 0x49)
#define FLAG_LANDMARK_FIERY_PATH                    (SYSTEM_FLAGS + 0x4A)

#define FLAG_SYS_PC_LANETTE                         (SYSTEM_FLAGS + 0x4B)
#define FLAG_SYS_MYSTERY_EVENT_ENABLE               (SYSTEM_FLAGS + 0x4C)
#define FLAG_SYS_ENC_UP_ITEM                        (SYSTEM_FLAGS + 0x4D)
#define FLAG_SYS_ENC_DOWN_ITEM                      (SYSTEM_FLAGS + 0x4E)
#define FLAG_SYS_BRAILLE_DIG                        (SYSTEM_FLAGS + 0x4F)
#define FLAG_SYS_REGIROCK_PUZZLE_COMPLETED          (SYSTEM_FLAGS + 0x50)
#define FLAG_SYS_BRAILLE_REGICE_COMPLETED           (SYSTEM_FLAGS + 0x51)
#define FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED         (SYSTEM_FLAGS + 0x52)
#define FLAG_ENABLE_SHIP_SOUTHERN_ISLAND            (SYSTEM_FLAGS + 0x53)

#define FLAG_LANDMARK_POKEMON_LEAGUE                (SYSTEM_FLAGS + 0x54)
#define FLAG_LANDMARK_ISLAND_CAVE                   (SYSTEM_FLAGS + 0x55)
#define FLAG_LANDMARK_DESERT_RUINS                  (SYSTEM_FLAGS + 0x56)
#define FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE          (SYSTEM_FLAGS + 0x57)
#define FLAG_LANDMARK_SCORCHED_SLAB                 (SYSTEM_FLAGS + 0x58)
#define FLAG_LANDMARK_ANCIENT_TOMB                  (SYSTEM_FLAGS + 0x59)
#define FLAG_LANDMARK_TUNNELERS_REST_HOUSE          (SYSTEM_FLAGS + 0x5A)
#define FLAG_LANDMARK_HUNTERS_HOUSE                 (SYSTEM_FLAGS + 0x5B)
#define FLAG_LANDMARK_SEALED_CHAMBER                (SYSTEM_FLAGS + 0x5C)

#define FLAG_SYS_TV_LATIAS_LATIOS                   (SYSTEM_FLAGS + 0x5D) // EE-Unused?

#define FLAG_LANDMARK_SKY_PILLAR                    (SYSTEM_FLAGS + 0x5E)

#define FLAG_SYS_SHOAL_ITEM                         (SYSTEM_FLAGS + 0x5F)
#define FLAG_SYS_B_DASH                             (SYSTEM_FLAGS + 0x60) // RECEIVED Running Shoes. EE-Unused? At least unnecessary.
#define FLAG_SYS_CTRL_OBJ_DELETE                    (SYSTEM_FLAGS + 0x61)
#define FLAG_SYS_RESET_RTC_ENABLE                   (SYSTEM_FLAGS + 0x62)

#define FLAG_LANDMARK_BERRY_MASTERS_HOUSE           (SYSTEM_FLAGS + 0x63)

#define FLAG_SYS_TOWER_SILVER                       (SYSTEM_FLAGS + 0x64)
#define FLAG_SYS_TOWER_GOLD                         (SYSTEM_FLAGS + 0x65)
#define FLAG_SYS_DOME_SILVER                        (SYSTEM_FLAGS + 0x66)
#define FLAG_SYS_DOME_GOLD                          (SYSTEM_FLAGS + 0x67)
#define FLAG_SYS_PALACE_SILVER                      (SYSTEM_FLAGS + 0x68)
#define FLAG_SYS_PALACE_GOLD                        (SYSTEM_FLAGS + 0x69)
#define FLAG_SYS_ARENA_SILVER                       (SYSTEM_FLAGS + 0x6A)
#define FLAG_SYS_ARENA_GOLD                         (SYSTEM_FLAGS + 0x6B)
#define FLAG_SYS_FACTORY_SILVER                     (SYSTEM_FLAGS + 0x6C)
#define FLAG_SYS_FACTORY_GOLD                       (SYSTEM_FLAGS + 0x6D)
#define FLAG_SYS_PIKE_SILVER                        (SYSTEM_FLAGS + 0x6E)
#define FLAG_SYS_PIKE_GOLD                          (SYSTEM_FLAGS + 0x6F)
#define FLAG_SYS_PYRAMID_SILVER                     (SYSTEM_FLAGS + 0x70)
#define FLAG_SYS_PYRAMID_GOLD                       (SYSTEM_FLAGS + 0x71)
#define FLAG_SYS_FRONTIER_PASS                      (SYSTEM_FLAGS + 0x72)

#define FLAG_MAP_SCRIPT_CHECKED_DEOXYS              (SYSTEM_FLAGS + 0x73)
#define FLAG_DEOXYS_ROCK_COMPLETE                   (SYSTEM_FLAGS + 0x74)
#define FLAG_ENABLE_SHIP_BIRTH_ISLAND               (SYSTEM_FLAGS + 0x75)
#define FLAG_ENABLE_SHIP_FARAWAY_ISLAND             (SYSTEM_FLAGS + 0x76)

#define FLAG_SHOWN_BOX_WAS_FULL_MESSAGE             (SYSTEM_FLAGS + 0x77)

#define FLAG_ARRIVED_ON_FARAWAY_ISLAND              (SYSTEM_FLAGS + 0x78)
#define FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT     (SYSTEM_FLAGS + 0x79)
#define FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE         (SYSTEM_FLAGS + 0x7A)

#define FLAG_SYS_MYSTERY_GIFT_ENABLE                (SYSTEM_FLAGS + 0x7B) // EE-Unused

#define FLAG_ENTERED_MIRAGE_TOWER                   (SYSTEM_FLAGS + 0x7C)
#define FLAG_LANDMARK_ALTERING_CAVE                 (SYSTEM_FLAGS + 0x7D)
#define FLAG_LANDMARK_DESERT_UNDERPASS              (SYSTEM_FLAGS + 0x7E)
#define FLAG_LANDMARK_ARTISAN_CAVE                  (SYSTEM_FLAGS + 0x7F)
#define FLAG_ENABLE_SHIP_NAVEL_ROCK                 (SYSTEM_FLAGS + 0x80)
#define FLAG_ARRIVED_AT_NAVEL_ROCK                  (SYSTEM_FLAGS + 0x81)
#define FLAG_LANDMARK_TRAINER_HILL                  (SYSTEM_FLAGS + 0x82)

#define FLAG_RYU_AQUA_IN_MAGMA_HIDEOUT_GRUNTS       (SYSTEM_FLAGS + 0x83)

#define FLAG_RECEIVED_POKEDEX_FROM_BIRCH            (SYSTEM_FLAGS + 0x84)

#define FLAG_RYU_FROSTY_FOREST_ENERGY_ROOT          (SYSTEM_FLAGS + 0x85)
#define FLAG_RYU_FROSTY_FOREST_BANETTITE            (SYSTEM_FLAGS + 0x86)
#define FLAG_RYU_FROSTY_FOREST_DUSK_STONE           (SYSTEM_FLAGS + 0x87)
#define FLAG_RYU_FROSTY_FOREST_SPELL_TAG            (SYSTEM_FLAGS + 0x88)

// From here, put all the flags for ledendaries you want to reset on champion
#define FLAG_RYU_ZAPDOS_RAN                         (SYSTEM_FLAGS + 0x89)
#define FLAG_RYU_MOLTRES_RAN                        (SYSTEM_FLAGS + 0x8A)
#define FLAG_RYU_ARTICUNO_RAN                       (SYSTEM_FLAGS + 0x8B)
#define FLAG_RYU_ENTEI_RAN                          (SYSTEM_FLAGS + 0x8C)
#define FLAG_RYU_SUICUNE_RAN                        (SYSTEM_FLAGS + 0x8D)
#define FLAG_RYU_RAIKOU_RAN                         (SYSTEM_FLAGS + 0x8E)
#define FLAG_RYU_CELEBI_RAN                         (SYSTEM_FLAGS + 0x8F)
#define FLAG_RYU_REGIGIGAS_RAN                      (SYSTEM_FLAGS + 0x90)
#define FLAG_RYU_MANAPHY_RAN                        (SYSTEM_FLAGS + 0x91)
#define FLAG_RYU_NECROZMA_RAN                       (SYSTEM_FLAGS + 0x92)
#define FLAG_RYU_KYOGRE_RAN                         (SYSTEM_FLAGS + 0x93)
#define FLAG_UNUSED_SF094                           (SYSTEM_FLAGS + 0x94)
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_MAXIE (SYSTEM_FLAGS + 0x95)
#define FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA1    (SYSTEM_FLAGS + 0x96)
#define FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA2    (SYSTEM_FLAGS + 0x97)
#define FLAG_RYU_ROUTE_111_MAGMA_MEETING_BLAISE     (SYSTEM_FLAGS + 0x98)
#define LCC_MAGMA_HARBOR_REPORTERS                  (SYSTEM_FLAGS + 0x99)
#define FLAG_RYU_MAGMA_LILYCOVE                     (SYSTEM_FLAGS + 0x9A)
#define FLAG_RYU_PLAYER_BANNED_FROM_LILYCOVE        (SYSTEM_FLAGS + 0x9B)
#define FLAG_RYU_MAGMA_6_NOTIFY                     (SYSTEM_FLAGS + 0x9C)
#define FLAG_RYU_HIDE_103_MAGMA_MEETING             (SYSTEM_FLAGS + 0x9D)
#define FLAG_RYU_BANNED_FROM_OLDALE                 (SYSTEM_FLAGS + 0x9E)
#define FLAG_RYU_HIDE_MAGMA_HIDEOUT_MAXIE           (SYSTEM_FLAGS + 0x9F)
#define FLAG_RYU_RUSTURF_CLEARING_MAGMA             (SYSTEM_FLAGS + 0xA0)
#define FLAG_RYU_BANNED_FROM_MARTS                  (SYSTEM_FLAGS + 0xA1)
#define FLAG_RYU_HIDE_R112_BLAISE                   (SYSTEM_FLAGS + 0xA2)
#define FLAG_HIDE_MAGMA_ARMY                        (SYSTEM_FLAGS + 0xA3)
#define FLAG_RYU_SELLING_TO_FENCE                   (SYSTEM_FLAGS + 0xA4) // Set when the player is banned from marts and selling to the magma Fence.
#define FLAG_RYU_MAGMA_8_NOTIFY                     (SYSTEM_FLAGS + 0xA5)
#define FLAG_RYU_COURTNEY_FIERY_PATH                (SYSTEM_FLAGS + 0xA6)
#define FLAG_HIDE_MAGMA_ADMIN_OFFICE_COURTNEY       (SYSTEM_FLAGS + 0xA7)
#define FLAG_RYU_HIDE_114_MAXIE                     (SYSTEM_FLAGS + 0xA8)
#define FLAG_ARTEFACT_1                             (SYSTEM_FLAGS + 0xA9)
#define FLAG_ARTEFACT_2                             (SYSTEM_FLAGS + 0xAA)
#define FLAG_ARTEFACT_3                             (SYSTEM_FLAGS + 0xAB)
#define FLAG_OVAL_CHARM_RECIEVED                    (SYSTEM_FLAGS + 0xAC)
#define FLAG_ITEM_FROSTBITE_FIELD_PP_UP             (SYSTEM_FLAGS + 0xAD)
#define FLAG_ITEM_FROSTBITE_FIELD_REPEL             (SYSTEM_FLAGS + 0xAE)
#define FLAG_ITEM_FROSTBITE_FIELD_PP_MAX            (SYSTEM_FLAGS + 0xAF)
#define FLAG_ITEM_FROSTBITE_FIELD_SUPER_REPEL       (SYSTEM_FLAGS + 0xB0)
#define FLAG_HIDDEN_FROSTBITE_FIELD_ICE_HEAL        (SYSTEM_FLAGS + 0xB1)
#define FLAG_HIDDEN_SNOWY_SHORE_BIG_PEARL           (SYSTEM_FLAGS + 0xB2)
#define FLAG_HIDDEN_SNOWY_SHORE_HEART_SCALE         (SYSTEM_FLAGS + 0xB3)
#define FLAG_HIDDEN_CRAGGY_COAST_REPEL              (SYSTEM_FLAGS + 0xB4)
#define FLAG_HIDDEN_CRAGGY_COAST_RARE_BONE          (SYSTEM_FLAGS + 0xB5)
#define FLAG_HIDDEN_CRAGGY_COAST_GREAT_BALL         (SYSTEM_FLAGS + 0xB6)
#define FLAG_HIDDEN_CRAGGY_COAST_DIVE_BALL          (SYSTEM_FLAGS + 0xB7)
#define FLAG_HIDDEN_CRAGGY_COAST_HARD_STONE         (SYSTEM_FLAGS + 0xB8)
#define FLAG_HIDDEN_CRAGGY_COAST_NET_BALL           (SYSTEM_FLAGS + 0xB9)
#define FLAG_RYU_PLAYER_FAILED_TO_CAPTURE_GROUDON   (SYSTEM_FLAGS + 0xBA)
#define FLAG_RYU_DS_COURTNEY_FRIENDS                (SYSTEM_FLAGS + 0xBB)
#define FLAG_RYU_DS_COURTNEY_CLOSEFRIENDS           (SYSTEM_FLAGS + 0xBC)
#define FLAG_RYU_DS_COURTNEY_LOVERS                 (SYSTEM_FLAGS + 0xBD)
#define FLAG_RYU_DS_COURTNEY_PARTNERS               (SYSTEM_FLAGS + 0xBE)
#define FLAG_RYU_MAXIE_END_EVENT                    (SYSTEM_FLAGS + 0xBF)

// Daily Flags
// These flags are cleared once per day
// The start and end are byte-aligned because the flags are cleared in byte increments
#define DAILY_FLAGS_START                              (FLAG_RYU_MAXIE_END_EVENT + (8 - FLAG_RYU_MAXIE_END_EVENT % 8))
#define FLAG_HIDE_SCME_GROUDON                         (DAILY_FLAGS_START + 0x0) // this will get reset daily, but it doesn't matter as the player isn't likely to spend much time here.
#define FLAG_DAILY_CONTEST_LOBBY_RECEIVED_BERRY        (DAILY_FLAGS_START + 0x1)
#define FLAG_DAILY_SECRET_BASE                         (DAILY_FLAGS_START + 0x2)
#define FLAG_HIDE_SCME_KYOGRE                          (DAILY_FLAGS_START + 0x3)
#define FLAG_RYU_TEMP_HIDE_FOLLOWER_COURTNEY           (DAILY_FLAGS_START + 0x4) // hack for follower courtney quest
#define FLAG_DAILY_SNOWY_SHORE_RECEIVED_BERRY          (DAILY_FLAGS_START + 0x5)
#define FLAG_DAILY_FROSTBITE_FIELD_RECEIVED_FERTILIZER (DAILY_FLAGS_START + 0x6)
#define FLAG_DAILY_SLAKOTH_BANANA_GARDEN_BANANAS       (DAILY_FLAGS_START + 0x7)
#define FLAG_UNUSED_0x928                              (DAILY_FLAGS_START + 0x8) // Unused Flag
#define FLAG_UNUSED_0x929                              (DAILY_FLAGS_START + 0x9) // Unused Flag
#define FLAG_DAILY_PICKED_LOTO_TICKET                  (DAILY_FLAGS_START + 0xA)
#define FLAG_DAILY_ROUTE_114_RECEIVED_BERRY            (DAILY_FLAGS_START + 0xB)
#define FLAG_DAILY_ROUTE_111_RECEIVED_BERRY            (DAILY_FLAGS_START + 0xC)
#define FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xD)
#define FLAG_DAILY_ROUTE_120_RECEIVED_BERRY            (DAILY_FLAGS_START + 0xE)
#define FLAG_DAILY_LILYCOVE_RECEIVED_BERRY             (DAILY_FLAGS_START + 0xF)
#define FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY          (DAILY_FLAGS_START + 0x10)
#define FLAG_DAILY_BERRY_MASTERS_WIFE                  (DAILY_FLAGS_START + 0x11)
#define FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY           (DAILY_FLAGS_START + 0x12)
#define FLAG_UNUSED_0x933                              (DAILY_FLAGS_START + 0x13) // Unused Flag
#define FLAG_DAILY_APPRENTICE_LEAVES                   (DAILY_FLAGS_START + 0x14)
#define FLAG_HIDDEN_MT_FREEZE_2F_PEARL_1               (DAILY_FLAGS_START + 0x15)
#define FLAG_HIDDEN_MT_FREEZE_2F_PEARL_2               (DAILY_FLAGS_START + 0x16)
#define FLAG_HIDDEN_MT_FREEZE_2F_PEARL_3               (DAILY_FLAGS_START + 0x17)
#define FLAG_HIDDEN_MT_FREEZE_2F_PEARL_4               (DAILY_FLAGS_START + 0x18)
#define FLAG_HIDDEN_MT_FREEZE_2F_PEARL_5               (DAILY_FLAGS_START + 0x19)
#define FLAG_HIDDEN_MT_FREEZE_3F_PEARL_1               (DAILY_FLAGS_START + 0x1A)
#define FLAG_HIDDEN_MT_FREEZE_3F_PEARL_2               (DAILY_FLAGS_START + 0x1B)
#define FLAG_FINISHED_NATURALIST_DAILY                    (DAILY_FLAGS_START + 0x1C) // Unused Flag
#define FLAG_FINISHED_STUDENT_DAILY                       (DAILY_FLAGS_START + 0x1D) // Unused Flag
#define FLAG_FINISHED_NOBLE_DAILY                         (DAILY_FLAGS_START + 0x1E) // Unused Flag
#define FLAG_FINISHED_POKEFAN_DAILY                       (DAILY_FLAGS_START + 0x1F) // Unused Flag
#define FLAG_FINISHED_OUTCAST_DAILY                       (DAILY_FLAGS_START + 0x20) // Unused Flag
#define FLAG_FINISHED_PROFESSIONAL_DAILY                  (DAILY_FLAGS_START + 0x21) // Unused Flag
#define FLAG_FINISHED_ATHLETE_DAILY                       (DAILY_FLAGS_START + 0x22) // Unused Flag
#define FLAG_DAILY_QUEST_ACTIVE                        (DAILY_FLAGS_START + 0x23) // Unused Flag
#define FLAG_UNUSED_0x944                              (DAILY_FLAGS_START + 0x24) // Unused Flag
#define FLAG_UNUSED_0x945                              (DAILY_FLAGS_START + 0x25) // Unused Flag
#define FLAG_UNUSED_0x946                              (DAILY_FLAGS_START + 0x26) // Unused Flag
#define FLAG_UNUSED_0x947                              (DAILY_FLAGS_START + 0x27) // Unused Flag
#define FLAG_UNUSED_0x948                              (DAILY_FLAGS_START + 0x28) // Unused Flag
#define FLAG_UNUSED_0x949                              (DAILY_FLAGS_START + 0x29) // Unused Flag
#define FLAG_UNUSED_0x94A                              (DAILY_FLAGS_START + 0x2A) // Unused Flag
#define FLAG_UNUSED_0x94B                              (DAILY_FLAGS_START + 0x2B) // Unused Flag
#define FLAG_UNUSED_0x94C                              (DAILY_FLAGS_START + 0x2C) // Unused Flag
#define FLAG_UNUSED_0x94D                              (DAILY_FLAGS_START + 0x2D) // Unused Flag
#define FLAG_UNUSED_0x94E                              (DAILY_FLAGS_START + 0x2E) // Unused Flag
#define FLAG_UNUSED_0x94F                              (DAILY_FLAGS_START + 0x2F) // Unused Flag
#define FLAG_UNUSED_0x950                              (DAILY_FLAGS_START + 0x30) // Unused Flag
#define FLAG_UNUSED_0x951                              (DAILY_FLAGS_START + 0x31) // Unused Flag
#define FLAG_UNUSED_0x952                              (DAILY_FLAGS_START + 0x32) // Unused Flag
#define FLAG_UNUSED_0x953                              (DAILY_FLAGS_START + 0x33) // Unused Flag
#define FLAG_UNUSED_0x954                              (DAILY_FLAGS_START + 0x34) // Unused Flag
#define FLAG_UNUSED_0x955                              (DAILY_FLAGS_START + 0x35) // Unused Flag
#define FLAG_UNUSED_0x956                              (DAILY_FLAGS_START + 0x36) // Unused Flag
#define FLAG_UNUSED_0x957                              (DAILY_FLAGS_START + 0x37) // Unused Flag
#define FLAG_UNUSED_0x958                              (DAILY_FLAGS_START + 0x38) // Unused Flag
#define FLAG_UNUSED_0x959                              (DAILY_FLAGS_START + 0x39) // Unused Flag
#define FLAG_UNUSED_0x95A                              (DAILY_FLAGS_START + 0x3A) // Unused Flag
#define FLAG_UNUSED_0x95B                              (DAILY_FLAGS_START + 0x3B) // Unused Flag
#define FLAG_UNUSED_0x95C                              (DAILY_FLAGS_START + 0x3C) // Unused Flag
#define FLAG_UNUSED_0x95D                              (DAILY_FLAGS_START + 0x3D) // Unused Flag
#define FLAG_UNUSED_0x95E                              (DAILY_FLAGS_START + 0x3E) // Unused Flag
#define FLAG_UNUSED_0x95F                              (DAILY_FLAGS_START + 0x3F) // Unused Flag
#define DAILY_FLAGS_END                                (FLAG_UNUSED_0x95F + (7 - FLAG_UNUSED_0x95F % 8))

#define FLAGS_COUNT (DAILY_FLAGS_END + 1)
#define ACH_FLAGS_COUNT 256
#define AP_FLAGS_COUNT 32

// Special Flags (Stored in EWRAM (gSpecialFlags), not in the SaveBlock)
#define SPECIAL_FLAGS_START                     0x4000
#define FLAG_HIDE_MAP_NAME_POPUP                (SPECIAL_FLAGS_START + 0x0)
#define FLAG_DONT_TRANSITION_MUSIC              (SPECIAL_FLAGS_START + 0x1)
#define FLAG_ENABLE_MULTI_CORRIDOR_DOOR         (SPECIAL_FLAGS_START + 0x2)
#define FLAG_SPECIAL_FLAG_UNUSED_0x4003         (SPECIAL_FLAGS_START + 0x3) // Unused Flag
#define FLAG_STORING_ITEMS_IN_PYRAMID_BAG       (SPECIAL_FLAGS_START + 0x4)
#define FLAG_BOTANY_HAS_HYPER_CUTTER            (SPECIAL_FLAGS_START + 0x5)
#define FLAG_ONLY_GIVE_ACHIEVEMENT_ONCE         (SPECIAL_FLAGS_START + 0x6)
#define FLAG_IS_FIGHTING_RYU                    (SPECIAL_FLAGS_START + 0x7)
#define FLAG_RYU_GLITCH_MSG_SENT                (SPECIAL_FLAGS_START + 0x8)
#define FLAG_RYU_FACING_FACTION_BOSS            (SPECIAL_FLAGS_START + 0x9)
#define FLAG_RYU_DISPLAY_BOTANY_INGREDIENTS     (SPECIAL_FLAGS_START + 0xA)
#define FLAG_RYU_DISPLAY_ALCHEMY_INGREDIENTS    (SPECIAL_FLAGS_START + 0xB)
// FLAG_SPECIAL_FLAG_0x4005 - 0x407F also exist and are unused
#define SPECIAL_FLAGS_END                       (SPECIAL_FLAGS_START + 0x7F)

//Achievement Power related

// AP tiers 
#define AP_TIER_PLATINUM 0
#define AP_TIER_GOLD 1
#define AP_TIER_SILVER 2
#define AP_TIER_COPPER 3

//PLATINUM AP's (You can only use one at a time)
#define AP_SPRINT_BOOST 0//lets player move faster
#define AP_GLOBAL_REPEL 1//lets player have dev repel
#define AP_TRAINER_REPEL 2//lets player have dev phasing without the noclip
#define AP_EV_BOOST 3//doubles final EV gain
#define AP_PLATINUM_COUNT 4

//GOLD AP's (you can use up to 2 of these)
#define AP_MOBILE_STAT_CHECKER 4//lets player use a mobile ev/iv checker while active
#define AP_PDA 5//lets player access a mart remotely
#define AP_ALPHA_AURA 10 //10% increased boss chance
#define AP_BIOHAZARD 12 //double pokerus chance
#define AP_GOLD_COUNT 4

//SILVER AP's (you can use up to 3 of these at a time)
#define AP_WINNINGS_BOOST 6 //Gives the player 10% more winnings after battle
#define AP_STRONGER_WILDS 8 //Wild pokemon use autolevel
#define AP_BREEDER 11 //Doubles final hatch progress gain per step after other modifiers.
#define AP_SILVER_COUNT 3

//COPPER AP's (you can use many of these at the same time)
#define AP_CAPTURE_BOOST 7 //Gives the player 5% boost to capture rate
#define AP_NATURAL_TALENT 9 //Lets the player open secret bases without the move.
#define AP_LUCKY_LOOT 13 //Wild pokemon held item chance is collectively increased by 25% of their base value.
#define AP_COPPER_COUNT 3

// total number of achivement powers available
#define TOTAL_AP_COUNT 14

//the total number of achievements that can be owned, this is what will be used for the ap percentage check.
#define TOTAL_OBTAINABLE_ACHIEVEMENTS 53

//Achievement related. Achievements are stored in Save Block 2, 256 total.
#define ACH_FLAGS_START 0x0

#define ACH_WHOLE_NEW_WORLD   0
#define ACH_ENHANCED_BATTLE   1
#define ACH_NEW_REGION_WHO_DIS   2
#define ACH_ADVENTURE_TIME   3
#define ACH_TRUE_LOVE   4
#define ACH_SILENT_STRONG_TYPE   5
#define ACH_CHILDHOOD_FRIEND   6
#define ACH_FIERY_PASSION   7
#define ACH_NERD_LOVE   8
#define ACH_FWB  9
#define ACH_WET_N_WILD  10
#define ACH_TRUE_ENDING  11
#define ACH_ETERNAL_DAMNATION  12
#define ACH_HUNTING_TRIP  13
#define ACH_THROUGH_THE_FIRE  14
#define ACH_HEATED_ARGUMENT  15
#define ACH_EYE_OF_STORM  16
#define ACH_WATER_LOGGED  17
#define ACH_ASTRONOMICAL  18
#define ACH_CORPORATE_SHILL  19
#define ACH_DEJA_VU  20
#define ACH_NTMO  21
#define ACH_POKEMON_MASTER  22
#define ACH_MASTER_BREEDER  23
#define ACH_ASCENDED  24
#define ACH_EVIL_INCARNATE  25
#define ACH_1337  26
#define ACH_YOU_DIED  27
#define ACH_WASTED  28
#define ACH_FITNESS_GURU  29
#define ACH_GREEN_THUMB  30
#define ACH_HOENN_CHAMPION  31
#define ACH_LEAVE_NO_STONE_UNTURNED  32
#define ACH_NO_KILL_LIKE_OVERKILL  33
#define ACH_ADDITIVE  34
#define ACH_MULTIPLICATIVE  35
#define ACH_EXPONENTIAL  36
#define ACH_WELL_TRAVELLED  37
#define ACH_MENTOR  38
#define ACH_UNDERTAKER 39
#define ACH_FIELD_MEDIC  40
#define ACH_PLOT_ARMOR  41
#define ACH_THE_EXPLORER  42
#define ACH_THE_PROTEGE  43
#define ACH_THE_EMPEROR  44
#define ACH_THE_GUARDIAN  45
#define ACH_THE_MAGICIAN  46
#define ACH_THE_TRADESMAN  47
#define ACH_THE_WARRIOR  48
#define ACH_THE_UNIVERSALIST  49 //GOLD Achievment, VERY HARD TO GET.
#define ACH_LOREMASTER  50 //GOLD Achievement, VERY HARD TO GET.
#define ACH_TOURIST  51 //GOLD ACHIEVEMENT, VERY HARD TO GET.
#define ACH_CRITCAP  52
#define ACH_UNUSED_54  53
#define ACH_UNUSED_55  54
#define ACH_UNUSED_56  55
#define ACH_UNUSED_57  56
#define ACH_UNUSED_58  57
#define ACH_UNUSED_59  58
#define ACH_UNUSED_60  59
#define ACH_UNUSED_61  60
#define ACH_UNUSED_62  61
#define ACH_UNUSED_63  62
#define ACH_UNUSED_64  63
#define ACH_UNUSED_65  64
#define ACH_UNUSED_66  65
#define ACH_UNUSED_67  66
#define ACH_UNUSED_68  67
#define ACH_UNUSED_69  68
#define ACH_UNUSED_70  69
#define ACH_UNUSED_71  70
#define ACH_UNUSED_72  71
#define ACH_UNUSED_73  72
#define ACH_UNUSED_74  73
#define ACH_UNUSED_75  74
#define ACH_UNUSED_76  75
#define ACH_UNUSED_77  76
#define ACH_UNUSED_78  77
#define ACH_UNUSED_79  78
#define ACH_UNUSED_80  79
#define ACH_UNUSED_81  80
#define ACH_UNUSED_82  81
#define ACH_UNUSED_83  82
#define ACH_UNUSED_84  83
#define ACH_UNUSED_85  84
#define ACH_UNUSED_86  85
#define ACH_UNUSED_87  86
#define ACH_UNUSED_88  87
#define ACH_UNUSED_89  88
#define ACH_UNUSED_90  89
#define ACH_UNUSED_91  90
#define ACH_UNUSED_92  91
#define ACH_UNUSED_93  92
#define ACH_UNUSED_94  93
#define ACH_UNUSED_95  94
#define ACH_UNUSED_96  95
#define ACH_UNUSED_97  96
#define ACH_UNUSED_98  97
#define ACH_UNUSED_99  98
#define ACH_UNUSED_100 99 
#define ACH_UNUSED_101 100 
#define ACH_UNUSED_102 101 
#define ACH_UNUSED_103 102 
#define ACH_UNUSED_104 103 
#define ACH_UNUSED_105 104 
#define ACH_UNUSED_106 105 
#define ACH_UNUSED_107 106 
#define ACH_UNUSED_108 107 
#define ACH_UNUSED_109 108 
#define ACH_UNUSED_110 109 
#define ACH_UNUSED_111 110 
#define ACH_UNUSED_112 111 
#define ACH_UNUSED_113 112 
#define ACH_UNUSED_114 113 
#define ACH_UNUSED_115 114 
#define ACH_UNUSED_116 115 
#define ACH_UNUSED_117 116 
#define ACH_UNUSED_118 117 
#define ACH_UNUSED_119 118 
#define ACH_UNUSED_120 119 
#define ACH_UNUSED_121 120 
#define ACH_UNUSED_122 121 
#define ACH_UNUSED_123 122 
#define ACH_UNUSED_124 123 
#define ACH_UNUSED_125 124 
#define ACH_UNUSED_126 125 
#define ACH_UNUSED_127 126 
#define ACH_UNUSED_128 127 
#define ACH_UNUSED_129 128 
#define ACH_UNUSED_130 129 
#define ACH_UNUSED_131 130 
#define ACH_UNUSED_132 131 
#define ACH_UNUSED_133 132 
#define ACH_UNUSED_134 133 
#define ACH_UNUSED_135 134 
#define ACH_UNUSED_136 135 
#define ACH_UNUSED_137 136 
#define ACH_UNUSED_138 137 
#define ACH_UNUSED_139 138 
#define ACH_UNUSED_140 139 
#define ACH_UNUSED_141 140 
#define ACH_UNUSED_142 141 
#define ACH_UNUSED_143 142 
#define ACH_UNUSED_144 143 
#define ACH_UNUSED_145 144 
#define ACH_UNUSED_146 145 
#define ACH_UNUSED_147 146 
#define ACH_UNUSED_148 147 
#define ACH_UNUSED_149 148 
#define ACH_UNUSED_150 149 
#define ACH_UNUSED_151 150 
#define ACH_UNUSED_152 151 
#define ACH_UNUSED_153 152 
#define ACH_UNUSED_154 153 
#define ACH_UNUSED_155 154 
#define ACH_UNUSED_156 155 
#define ACH_UNUSED_157 156 
#define ACH_UNUSED_158 157 
#define ACH_UNUSED_159 158 
#define ACH_UNUSED_160 159 
#define ACH_UNUSED_161 160 
#define ACH_UNUSED_162 161 
#define ACH_UNUSED_163 162 
#define ACH_UNUSED_164 163 
#define ACH_UNUSED_165 164 
#define ACH_UNUSED_166 165 
#define ACH_UNUSED_167 166 
#define ACH_UNUSED_168 167 
#define ACH_UNUSED_169 168 
#define ACH_UNUSED_170 169 
#define ACH_UNUSED_171 170 
#define ACH_UNUSED_172 171 
#define ACH_UNUSED_173 172 
#define ACH_UNUSED_174 173 
#define ACH_UNUSED_175 174 
#define ACH_UNUSED_176 175 
#define ACH_UNUSED_177 176 
#define ACH_UNUSED_178 177 
#define ACH_UNUSED_179 178 
#define ACH_UNUSED_180 179 
#define ACH_UNUSED_181 180 
#define ACH_UNUSED_182 181 
#define ACH_UNUSED_183 182 
#define ACH_UNUSED_184 183 
#define ACH_UNUSED_185 184 
#define ACH_UNUSED_186 185 
#define ACH_UNUSED_187 186 
#define ACH_UNUSED_188 187 
#define ACH_UNUSED_189 188 
#define ACH_UNUSED_190 189 
#define ACH_UNUSED_191 190 
#define ACH_UNUSED_192 191 
#define ACH_UNUSED_193 192 
#define ACH_UNUSED_194 193 
#define ACH_UNUSED_195 194 
#define ACH_UNUSED_196 195 
#define ACH_UNUSED_197 196 
#define ACH_UNUSED_198 197 
#define ACH_UNUSED_199 198 
#define ACH_UNUSED_200 199 
#define ACH_UNUSED_201 200 
#define ACH_UNUSED_202 201 
#define ACH_UNUSED_203 202 
#define ACH_UNUSED_204 203 
#define ACH_UNUSED_205 204 
#define ACH_UNUSED_206 205 
#define ACH_UNUSED_207 206 
#define ACH_UNUSED_208 207 
#define ACH_UNUSED_209 208 
#define ACH_UNUSED_210 209 
#define ACH_UNUSED_211 210 
#define ACH_UNUSED_212 211 
#define ACH_UNUSED_213 212 
#define ACH_UNUSED_214 213 
#define ACH_UNUSED_215 214 
#define ACH_UNUSED_216 215 
#define ACH_UNUSED_217 216 
#define ACH_UNUSED_218 217 
#define ACH_UNUSED_219 218 
#define ACH_UNUSED_220 219 
#define ACH_UNUSED_221 220 
#define ACH_UNUSED_222 221 
#define ACH_UNUSED_223 222 
#define ACH_UNUSED_224 223 
#define ACH_UNUSED_225 224 
#define ACH_UNUSED_226 225 
#define ACH_UNUSED_227 226 
#define ACH_UNUSED_228 227 
#define ACH_UNUSED_229 228 
#define ACH_UNUSED_230 229 
#define ACH_UNUSED_231 230 
#define ACH_UNUSED_232 231 
#define ACH_UNUSED_233 232 
#define ACH_UNUSED_234 233 
#define ACH_UNUSED_235 234 
#define ACH_UNUSED_236 235 
#define ACH_UNUSED_237 236 
#define ACH_UNUSED_238 237 
#define ACH_UNUSED_239 238 
#define ACH_UNUSED_240 239 
#define ACH_UNUSED_241 240 
#define ACH_UNUSED_242 241 
#define ACH_UNUSED_243 242 
#define ACH_UNUSED_244 243 
#define ACH_UNUSED_245 244 
#define ACH_UNUSED_246 245 
#define ACH_UNUSED_247 246 
#define ACH_UNUSED_248 247 
#define ACH_UNUSED_249 248 
#define ACH_UNUSED_250 249 
#define ACH_UNUSED_251 250 
#define ACH_UNUSED_252 251 
#define ACH_UNUSED_253 252 
#define ACH_UNUSED_254 253 
#define ACH_UNUSED_255 254 
#define ACH_UNUSED_256 255 


//Alchemy related defines

#define ALCHEMY_EFFECT_NONE                0 // gSaveBlock2Ptr->alchemyEffect set to this when there is no effect, or current effect wears out.
#define ALCHEMY_EFFECT_DAMAGE_BOOST_T1     1 // for five battles, deal 10% more damage
#define ALCHEMY_EFFECT_DAMAGE_BOOST_T2     2 // for five battles, deal 25% more damage
#define ALCHEMY_EFFECT_DAMAGE_BOOST_T3     3 // for five battles, deal 50% more damage
#define ALCHEMY_EFFECT_DEFENSE_BOOST_T1    4 // for five battles, take 10% less damage
#define ALCHEMY_EFFECT_DEFENSE_BOOST_T2    5 // for five battles, take 25% less damage
#define ALCHEMY_EFFECT_DEFENSE_BOOST_T3    6 // for five battles, take 50% less damage
#define ALCHEMY_EFFECT_EXP_BOOST_T1        7 // for ten battles, your experience is increased by 20%
#define ALCHEMY_EFFECT_EXP_BOOST_T2        8 // for ten battles, your experience is increased by 50%
#define ALCHEMY_EFFECT_EXP_BOOST_T3        9 // for ten battles, your experience is increased by 100%
#define ALCHEMY_EFFECT_REPEL_T1            10 // adds 500 to repel step counter
#define ALCHEMY_EFFECT_REPEL_T2            11 // adds 1000 to repel step counter
#define ALCHEMY_EFFECT_SUPER_CAPTURE       12 // for one battle, you have a 25% chance of a capture succeeding regardless of ball used.
#define ALCHEMY_EFFECT_ULTRA_CAPTURE       13 // for one battle, you have a 50% chance of a capture succeeding regardless of ball used.
#define ALCHEMY_EFFECT_MASTER_CAPTURE      14 // For one battle, you are garunteed to capture regardelss of ball used.
#define ALCHEMY_EFFECT_HEALING_FACTOR      15 // for five battles, you regain 10% health per turn. 
#define ALCHEMY_ITEM_RECIPE_STARDUST       16 // creates Stardust from Soft Sand and Gem Powder
#define ALCHEMY_ITEM_RECIPE_FRESH_WATER    17 // creates Fresh Water from Snowball and Fire Stone
#define ALCHEMY_ITEM_RECIPE_TONIC_WATER    18 // creates Tonic Water from Charcoal and Fresh Water
#define ALCHEMY_ITEM_RECIPE_MINERAL_WATER  19 // creates Mineral Water from Soft Sand, Shoal Salt, and Tonic Water
#define ALCHEMY_ITEM_RECIPE_RARE_CANDY     20 // creates Rare Candy from Lemonade, Mineral Water, and Smart Powder
#define ALCHEMY_ITEM_RECIPE_GOLD_NUGGET    21 // Creates Gold Nugget from 600 Gold Powder
#define NUM_ALCHEMY_EFFECTS                22



#endif // GUARD_CONSTANTS_FLAGS_H
