#ifndef GUARD_CONSTANTS_VARS_H
#define GUARD_CONSTANTS_VARS_H

#define VARS_START 0x4000
#define NUM_CONTEST_REWARDS 17

// temporary vars
// The first 0x10 vars are are temporary--they are cleared every time a map is loaded.
#define TEMP_VARS_START            0x4000
#define VAR_TEMP_0                 (TEMP_VARS_START + 0x0)
#define VAR_TEMP_1                 (TEMP_VARS_START + 0x1)
#define VAR_TEMP_2                 (TEMP_VARS_START + 0x2)
#define VAR_TEMP_3                 (TEMP_VARS_START + 0x3)
#define VAR_TEMP_4                 (TEMP_VARS_START + 0x4)
#define VAR_TEMP_5                 (TEMP_VARS_START + 0x5)
#define VAR_TEMP_6                 (TEMP_VARS_START + 0x6)
#define VAR_TEMP_7                 (TEMP_VARS_START + 0x7)
#define VAR_TEMP_8                 (TEMP_VARS_START + 0x8)
#define VAR_TEMP_9                 (TEMP_VARS_START + 0x9)
#define VAR_TEMP_A                 (TEMP_VARS_START + 0xA)
#define VAR_TEMP_B                 (TEMP_VARS_START + 0xB)
#define VAR_TEMP_C                 (TEMP_VARS_START + 0xC)
#define VAR_TEMP_D                 (TEMP_VARS_START + 0xD)
#define VAR_TEMP_E                 (TEMP_VARS_START + 0xE)
#define VAR_TEMP_F                 (TEMP_VARS_START + 0xF)
#define TEMP_VARS_END              VAR_TEMP_F

// object gfx id vars
// These 0x10 vars are used to dynamically control a map object's sprite.
// For example, the rival's sprite id is dynamically set based on the player's gender.
// See VarGetObjectEventGraphicsId().
#define VAR_OBJ_GFX_ID_0           0x4010
#define VAR_OBJ_GFX_ID_1           0x4011
#define VAR_OBJ_GFX_ID_2           0x4012
#define VAR_OBJ_GFX_ID_3           0x4013
#define VAR_OBJ_GFX_ID_4           0x4014
#define VAR_OBJ_GFX_ID_5           0x4015
#define VAR_OBJ_GFX_ID_6           0x4016
#define VAR_OBJ_GFX_ID_7           0x4017
#define VAR_OBJ_GFX_ID_8           0x4018
#define VAR_OBJ_GFX_ID_9           0x4019
#define VAR_OBJ_GFX_ID_A           0x401A
#define VAR_OBJ_GFX_ID_B           0x401B
#define VAR_OBJ_GFX_ID_C           0x401C
#define VAR_OBJ_GFX_ID_D           0x401D
#define VAR_OBJ_GFX_ID_E           0x401E
#define VAR_OBJ_GFX_ID_F           0x401F

// general purpose vars
#define VAR_RYU_SAVE_VIEWER_ENTRYPOINT       0x4020// the value of this variable is searched for by my save file viewer to let it know where saveblock vars start.
#define VAR_REPEL_STEP_COUNT                 0x4021
#define VAR_ICE_STEP_COUNT                   0x4022
#define VAR_STARTER_MON                      0x4023 // 0=Treecko, 1=Torchic, 2=Mudkip
#define VAR_MIRAGE_RND_H                     0x4024
#define VAR_MIRAGE_RND_L                     0x4025
#define VAR_SECRET_BASE_MAP                  0x4026
#define VAR_RYU_AUTOSCALE_MIN_LEVEL          0x4027
#define VAR_RYU_NGPLUS_COUNT                 0x4028
#define VAR_RYU_FOLLOWER_ELITE_MATCHES       0x4029 // Number of times e4 was challenged with a follower
#define VAR_HAPPINESS_STEP_COUNTER           0x402A
#define VAR_POISON_STEP_COUNTER              0x402B
#define VAR_RESET_RTC_ENABLE                 0x402C
#define VAR_ENIGMA_BERRY_AVAILABLE           0x402D
#define VAR_0x402E                           0x402E

#define VAR_FRONTIER_MANIAC_FACILITY         0x402F
#define VAR_FRONTIER_GAMBLER_CHALLENGE       0x4030
#define VAR_FRONTIER_GAMBLER_SET_CHALLENGE   0x4031
#define VAR_FRONTIER_GAMBLER_AMOUNT_BET      0x4032
#define VAR_FRONTIER_GAMBLER_STATE           0x4033

#define VAR_DEOXYS_ROCK_STEP_COUNT           0x4034
#define VAR_DEOXYS_ROCK_LEVEL                0x4035
#define VAR_PC_BOX_TO_SEND_MON               0x4036
#define VAR_ABNORMAL_WEATHER_LOCATION        0x4037
#define VAR_RYU_DAMAGED_HOUSE_ID             0x4038 //which property, if any, is damaged.
#define VAR_RYU_PROPERTY_DAMAGE_TYPE         0x4039 //what sort of damage needs repaired.
#define VAR_FARAWAY_ISLAND_STEP_COUNTER      0x403A
#define VAR_RYU_LAST_PICKUP_RARITY           0x403B//
#define VAR_RYU_LAST_PICKUP_ITEM             0x403C//Used for the new pickup ability @PIDGEY TODO: Revert these to VAR_UNUSED_X and find another way to buffer this information
#define VAR_RYU_LAST_PICKUP_SLOT             0x403D//from in battle to out of battle. Temp vars won't work, and i can't garuntee the text buffers will be free.
#define VAR_ALTERING_CAVE_WILD_SET           0x403E
#define VAR_DISTRIBUTE_EON_TICKET            0x403F // This var is read and written, but is always zero. The only way to obtain the Eon Ticket in Emerald is via Record Mixing
#define VAR_DAYS                             0x4040
#define VAR_FANCLUB_FAN_COUNTER              0x4041
#define VAR_FANCLUB_LOSE_FAN_TIMER           0x4042
#define VAR_DEPT_STORE_FLOOR                 0x4043
#define VAR_TRICK_HOUSE_LEVEL                0x4044
#define VAR_POKELOT_PRIZE_ITEM               0x4045
#define VAR_NATIONAL_DEX                     0x4046
#define VAR_SEEDOT_SIZE_RECORD               0x4047
#define VAR_ASH_GATHER_COUNT                 0x4048
#define VAR_BIRCH_STATE                      0x4049
#define VAR_CRUISE_STEP_COUNT                0x404A
#define VAR_POKELOT_RND1                     0x404B
#define VAR_POKELOT_RND2                     0x404C
#define VAR_POKELOT_PRIZE_PLACE              0x404D
#define VAR_RYU_THEME_NUMBER                 0x404E // Which theme is selected
#define VAR_LITTLEROOT_TOWN_STATE            0x4050
#define VAR_OLDALE_TOWN_STATE                0x4051
#define VAR_LAST_KNOWN_GAME_VERSION          0x4052 // current game version
#define VAR_LAVARIDGE_TOWN_STATE             0x4053
#define VAR_CURRENT_SECRET_BASE              0x4054 // was probably allocated for VAR_FALLARBOR_TOWN_STATE at one point
#define VAR_RYU_CONTEST_TYPE                 0x4055 //Contest type
#define VAR_RYU_TOTAL_FAINTS                 0x4056 // Number of KO's player has
#define VAR_PETALBURG_CITY_STATE             0x4057
#define VAR_SLATEPORT_CITY_STATE             0x4058
#define VAR_RYU_SPIRITOMB_FAINTS             0x4059 // Tracks up to 107 KO's for spiritomb diversion
#define VAR_RUSTBORO_CITY_STATE              0x405A
#define VAR_UNUSED_0x405B                    0x405B
#define VAR_RYU_LAST_ACH                     0x405C // stores the most recently given achievement if the player didn't have it previously.
#define VAR_MOSSDEEP_CITY_STATE              0x405D
#define VAR_SOOTOPOLIS_CITY_STATE            0x405E
#define VAR_RYU_PARTNER_COUNT                0x405F // Used to track how many partners the player has
#define VAR_ROUTE101_STATE                   0x4060
#define VAR_SAVE_FILE_CREATED_ON_VERSION     0x4061 // Unused Var
#define VAR_RYU_TIMES_STAYED_WITH_COMPANION  0x4062 // Unused Var
#define VAR_ROUTE104_STATE                   0x4063
#define VAR_RYU_GCMS_MOVE1                   0x4064 //GCMS
#define VAR_RYU_GCMS_MOVE2                   0x4065 // GCMS
#define VAR_RYU_GCMS_MOVE3                   0x4066 // GCMS
#define VAR_RYU_GCMS_MOVE4                   0x4067 // GCMS
#define VAR_RYU_GCMS_ABILITY                 0x4068 // GCMS
#define VAR_ROUTE110_STATE                   0x4069
#define VAR_RYU_TH_RNG_VALUE                 0x406A
#define VAR_RYU_TRAINER_HILL_MODE            0x406B
#define VAR_RYU_PLAYER_MINING_SKILL          0x406C
#define VAR_RYU_PLAYER_BOTANY_SKILL          0x406D
#define VAR_RYU_PLAYER_ALCHEMY_SKILL         0x406E
#define VAR_ROUTE116_STATE                   0x406F
#define VAR_RYU_PLAYER_MINING_SKILL_EXP            0x4070
#define VAR_ROUTE118_STATE                   0x4071
#define VAR_ROUTE119_STATE                   0x4072
#define VAR_RYU_PLAYER_BOTANY_SKILL_EXP      0x4073
#define VAR_RYU_PROPERTIES_REPAIRED                   0x4074 //How many times the player paid to repair an owned property
#define VAR_RYU_LEGENDARIES_CAUGHT           0x4075 // Number of legendaries caught.
#define VAR_ROUTE123_STATE                   0x4076 // Unused Var
#define VAR_RYU_AUTOLEVEL_MODIFIER           0x4077 // level modifier for autolevel
#define VAR_RYU_QUESTS_FINISHED                   0x4078 // Unused Var
#define VAR_ROUTE126_STATE                   0x4079 // Unused Var
#define VAR_ROUTE127_STATE                   0x407A // Unused Var
#define VAR_ROUTE128_STATE                   0x407B
#define VAR_ROUTE129_STATE                   0x407C // Unused Var
#define VAR_ROUTE130_STATE                   0x407D // Unused Var
#define VAR_RYU_DAILY_QUEST_TYPE             0x407E // Type of daily quest player is on
#define VAR_RYU_QUESTLINE_ID                 0x407F // Which main quest the player chose.
#define VAR_RYU_DAILY_QUEST_TARGET           0x4080 // ID or target value to complete daily quest.
#define VAR_RYU_DAILY_QUEST_DATA             0x4081 // Multi-Purpose component for daily quests.
#define VAR_RYU_PROPERTY_DAMAGE_DAYS         0x4082 
#define VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION 0x4083 // The faction that assigned the current daily quest.
#define VAR_BIRCH_LAB_STATE                  0x4084
#define VAR_PETALBURG_GYM_STATE              0x4085 // used to determine which petalburg doors are open.
#define VAR_CONTEST_HALL_STATE               0x4086
#define VAR_CABLE_CLUB_STATE                 0x4087
#define VAR_CONTEST_TYPE                     0x4088
#define VAR_SECRET_BASE_INITIALIZED          0x4089
#define VAR_CONTEST_PRIZE_PICKUP             0x408A
#define VAR_RYU_PLAYER_HOUSE_ID              0x408B // which house the player set as their home. Defaults to 0xFFFF for none.
#define VAR_LITTLEROOT_HOUSES_STATE_BRENDAN  0x408C
#define VAR_LITTLEROOT_RIVAL_STATE           0x408D
#define VAR_UNUSED_0x408E                    0x408E
#define VAR_DEVON_CORP_3F_STATE              0x408F
#define VAR_UNUSED_0x4090                    0x4090
#define VAR_RYU_QUEST_DEVON_SCIENTIST        0x4091 // Unused Var
#define VAR_LITTLEROOT_INTRO_STATE           0x4092
#define VAR_MAUVILLE_GYM_STATE               0x4093
#define VAR_LILYCOVE_MUSEUM_2F_STATE         0x4094
#define VAR_LILYCOVE_FAN_CLUB_STATE          0x4095
#define VAR_RYU_GAME_MODE                    0x4096
#define VAR_INIT_SECRET_BASE                 0x4097
#define VAR_PETALBURG_WOODS_STATE            0x4098
#define VAR_LILYCOVE_CONTEST_LOBBY_STATE     0x4099
#define VAR_RUSTURF_TUNNEL_STATE             0x409A
#define VAR_RYU_PC_USES                      0x409B
#define VAR_ELITE_4_STATE                    0x409C
#define VAR_RYU_EXP_MULTIPLIER               0x409D
#define VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE    0x409E
#define VAR_MOSSDEEP_SPACE_CENTER_STATE      0x409F
#define VAR_SLATEPORT_HARBOR_STATE           0x40A0
#define VAR_RYU_JUKEBOX                      0x40A1
#define VAR_SEAFLOOR_CAVERN_STATE            0x40A2
#define VAR_CABLE_CAR_STATION_STATE          0x40A3
#define VAR_SAFARI_ZONE_STATE                0x40A4  // 0: In or out of SZ, 1: Player exiting SZ, 2: Player entering SZ
#define VAR_TRICK_HOUSE_BEING_WATCHED_STATE  0x40A5
#define VAR_TRICK_HOUSE_FOUND_TRICK_MASTER   0x40A6
#define VAR_TRICK_HOUSE_ENTRANCE_STATE       0x40A7
#define VAR_RYU_TITLE_DEFENSE_WINS           0x40A8
#define VAR_RYU_DAYS_INTEREST_GAINED         0x40A9 // How many days the player earned interest.
#define VAR_SLATEPORT_MUSEUM_1F_STATE        0x40AA
#define VAR_TRICK_HOUSE_PUZZLE_1_STATE       0x40AB
#define VAR_TRICK_HOUSE_PUZZLE_2_STATE       0x40AC
#define VAR_TRICK_HOUSE_PUZZLE_3_STATE       0x40AD
#define VAR_TRICK_HOUSE_PUZZLE_4_STATE       0x40AE
#define VAR_TRICK_HOUSE_PUZZLE_5_STATE       0x40AF
#define VAR_TRICK_HOUSE_PUZZLE_6_STATE       0x40B0
#define VAR_TRICK_HOUSE_PUZZLE_7_STATE       0x40B1
#define VAR_TRICK_HOUSE_PUZZLE_8_STATE       0x40B2
#define VAR_WEATHER_INSTITUTE_STATE          0x40B3
#define VAR_SS_TIDAL_STATE                   0x40B4
#define VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR  0x40B5
#define VAR_RYU_UB_EVENT_TIMER               0x40B6 // Which UB rotation is currently active. Changes daily.
#define VAR_SLATEPORT_FAN_CLUB_STATE         0x40B7
#define VAR_RYU_SCRIPT_PTR                   0x40B8
#define VAR_OPTIONS_EXP_BAR_SPEED            0x40B9
#define VAR_NEW_MAUVILLE_STATE               0x40BA
#define VAR_RYU_CONTEST_REWARD               0x40BB
#define VAR_BRAVO_TRAINER_BATTLE_TOWER_ON    0x40BC
#define VAR_JAGGED_PASS_ASH_WEATHER          0x40BD
#define VAR_GLASS_WORKSHOP_STATE             0x40BE
#define VAR_OPTIONS_HP_BAR_SPEED             0x40BF
#define VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE  0x40C0
#define VAR_TRICK_HOUSE_PRIZE_PICKUP         0x40C1
#define VAR_PACIFIDLOG_TM_RECEIVED_DAY       0x40C2
#define VAR_VICTORY_ROAD_1F_STATE            0x40C3
#define VAR_FOSSIL_RESURRECTION_STATE        0x40C4
#define VAR_WHICH_FOSSIL_REVIVED             0x40C5
#define VAR_STEVENS_HOUSE_STATE              0x40C6
#define VAR_OLDALE_RIVAL_STATE               0x40C7
#define VAR_JAGGED_PASS_STATE                0x40C8
#define VAR_UNUSED_0x40C9                    0x40C9
#define VAR_SKY_PILLAR_STATE                 0x40CA
#define VAR_MIRAGE_TOWER_STATE               0x40CB
#define VAR_FOSSIL_MANIAC_STATE              0x40CC
#define VAR_CABLE_CLUB_TUTORIAL_STATE        0x40CD
#define VAR_FRONTIER_BATTLE_MODE             0x40CE
#define VAR_FRONTIER_FACILITY                0x40CF
#define VAR_RYU_QUEST_DEVON_CORPORATE        0x40D0 // devon main
#define VAR_UNUSED_0x40D1                    0x40D1
#define VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE   0x40D2
#define VAR_DEX_UPGRADE_JOHTO_STARTER_STATE  0x40D3
#define VAR_UNUSED_0x40D4                    0x40D4
#define VAR_ROAMER_POKEMON                   0x40D5 // 0 = Latias, 1 = Latios
#define VAR_TRAINER_HILL_IS_ACTIVE           0x40D6
#define VAR_SKY_PILLAR_RAQUAZA_CRY_DONE      0x40D7
#define VAR_SOOTOPOLIS_WALLACE_STATE         0x40D8
#define VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT 0x40D9
#define VAR_REGISTER_BIRCH_STATE             0x40DA
#define VAR_RYU_FOLLOWER_ID                  0x40DB
#define VAR_RYU_SAVED_BGM                    0x40DC
#define VAR_EVENT_PICHU_SLOT                 0x40DD
#define VAR_RYU_QUEST_LANETTE                  0x40DE
#define VAR_DEXNAV_SPECIES                   0x40DF // Var is written to, but never read
#define VAR_DEXNAV_STEP_COUNTER              0x40E0 // Var is written to, but never read
#define VAR_RYU_ALCHEMY_COPPER               0x40E1 // Player's copper dust count
#define VAR_RYU_ALCHEMY_SILVER               0x40E2 // Player's silver dust count
#define VAR_RYU_ALCHEMY_GOLD                 0x40E3 // Player's gold dust count
#define VAR_RYU_PLAYER_ALCHEMY_SKILL_EXP                  0x40E4 // var is written to, but never read
#define VAR_RYU_QUEST_AQUA                         0x40E5 // Aqua quest stages
#define VAR_DAILY_SLOTS                      0x40E6
#define VAR_DAILY_WILDS                      0x40E7
#define VAR_DAILY_BLENDER                    0x40E8
#define VAR_DAILY_PLANTED_BERRIES            0x40E9
#define VAR_DAILY_PICKED_BERRIES             0x40EA
#define VAR_DAILY_ROULETTE                   0x40EB
#define VAR_SECRET_BASE_STEP_COUNTER         0x40EC // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LAST_ITEM_USED       0x40ED // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LOW_TV_FLAGS         0x40EE // Used by Secret Base TV programs
#define VAR_SECRET_BASE_HIGH_TV_FLAGS        0x40EF // Used by Secret Base TV programs
#define VAR_SECRET_BASE_IS_NOT_LOCAL         0x40F0 // Set to TRUE while in another player's secret base.
#define VAR_DAILY_BP                         0x40F1
#define VAR_WALLY_CALL_STEP_COUNTER          0x40F2
#define VAR_UNUSED_0x40F3                    0x40F3
#define VAR_ROXANNE_CALL_STEP_COUNTER        0x40F4
#define VAR_RYU_QUEST_NURSE                  0x40F5
#define VAR_RYU_GYM_LEADERS_FOUGHT           0x40F6 //times player fought a gym leader
#define VAR_RYU_GCMS_SPECIES                 0x40F7
#define VAR_RYU_GCMS_VALUE                   0x40F8
#define VAR_RYU_FOLLOWER_BATTLES             0x40F9//battles fought with partners
#define VAR_RYU_QUEST_MAY                    0x40FA
#define VAR_RYU_CHALLENGE_WAYSTONE_USES      0x40FB
#define VAR_RYU_PRICE_MULTIPLIER             0x40FC
#define VAR_RYU_WEATHER                      0x40FD
#define VAR_RYU_QUEST_LANA                   0x40FE
#define VAR_RYU_QUEST_MAGMA                  0x40FF // Magma quest var
#define VAR_RYU_E41                          0x4100
#define VAR_RYU_E42                          0x4101
#define VAR_RYU_E43                          0x4102
#define VAR_RYU_E44                          0x4103
#define VAR_RYU_DELIVERY_5_GFX_ID            0x4104
#define VAR_RYU_DELIVERY_6_GFX_ID            0x4105
#define VAR_HOURS                            0x4106
//prize money
#define VAR_RYU_MONEY_BASE_RANDOM_COMPONENT  0x4107
#define VAR_RYU_MONEY_BASE_VALUE             0x4108
#define VAR_RYU_MONEY_BASE_COEFFICIENT       0x4109
#define VAR_RYU_SPECIAL_CHALLENGE_STATE      0x410A


//vars 4100 thru 417f are unused; total of 128.
#define VARS_END                             0x417F
#define VARS_COUNT                           (VARS_END - VARS_START + 1)

#define SPECIAL_VARS_START            0x8000
// special vars
// They are commonly used as parameters to commands, or return values from commands.
#define VAR_0x8000                    0x8000
#define VAR_0x8001                    0x8001
#define VAR_0x8002                    0x8002
#define VAR_0x8003                    0x8003
#define VAR_0x8004                    0x8004
#define VAR_0x8005                    0x8005
#define VAR_0x8006                    0x8006
#define VAR_0x8007                    0x8007
#define VAR_0x8008                    0x8008
#define VAR_0x8009                    0x8009
#define VAR_0x800A                    0x800A
#define VAR_0x800B                    0x800B
#define VAR_FACING                    0x800C
#define VAR_RESULT                    0x800D
#define VAR_ITEM_ID                   0x800E
#define VAR_LAST_TALKED               0x800F
#define VAR_CONTEST_RANK              0x8010
#define VAR_CONTEST_CATEGORY          0x8011
#define VAR_MON_BOX_ID                0x8012
#define VAR_MON_BOX_POS               0x8013
#define VAR_UNUSED_0x8014             0x8014
#define VAR_TRAINER_BATTLE_OPPONENT_A 0x8015 // Alias of gTrainerBattleOpponent_A

#define SPECIAL_VARS_END              0x8015


#endif // GUARD_CONSTANTS_VARS_H
