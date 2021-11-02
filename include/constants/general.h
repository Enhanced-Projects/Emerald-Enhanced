#ifndef GUARD_GENERAL_H
#define GUARD_GENERAL_H

//This file will contain all EE-Specific constants, to reduce filesize of vars/flags.h

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
#define TOTAL_OBTAINABLE_ACHIEVEMENTS 60

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
#define ACH_POKEMON_TRAINER  53//player has 151 mons
#define ACH_REALTOR  54 //Finished the Nobles primary quest
#define ACH_MILLIONAIRE  55 //1m+ net worth
#define ACH_MONEYBAGS  56 //100m+ net worth
#define ACH_SLUM_LORD  57 ///own all properties
#define ACH_ULTRA_BEASTLY  58 //capture all ubs
#define ACH_WANTED  59
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
#define NUM_ALCHEMY_RECIPES                22//total craftable alchemy recipes
#define NUM_ALCHEMY_EFFECTS                14//number of effects to offset the resulting item ID by.
#define NUM_ALCHEMY_ITEM_RECIPES           6 //number of items that can be crafted by alchemy



#define TRAINER_HILL_REWARDS_PER_TABLE 20

#define EXP_DRIVE_MAX 15000000 //exp drive new max is 15 million

#define EXP_DRIVE_MODE_RESET 0
#define EXP_DRIVE_MODE_ADD 1
#define EXP_DRIVE_MODE_SUBTRACT 2
#define EXP_DRIVE_MODE_BUFFER 3
#define EXP_DRIVE_MODE_USE_ON_MON 4
#define EXP_DRIVE_MODE_SET_DEV_AMOUNT 5

//Contest type defines for code usage
#define COOL 0
#define BEAUTY 1
#define CUTE 2
#define SMART 3
#define TOUGH 4


//battle style defines
#define BS_SHIFT 0
#define BS_SET 1

//drawFullscreenImage defines
#define SCENEBGDAWN 0
#define SCENEBGNIGHTDAWN 1
#define SCENEBGMINNIE 2
#define SCENEBGMELOETTA 3
#define SCENEBGBRENDAN 4
#define SCENEBGBRENDANNIGHT 5
#define SCENEBGCOURTNEY 6
#define SCENEBGHEATRAN 7
#define SCENEBGNURSE 8
#define SCENEBGNURSENIGHT 9
#define SCENEBGPIDGEYSCREENSHOT 10
#define SCENEBGGAMEOVER 11
#define SCENEBGWARP 12

//InfoBox Defines
#define INFOBOXPOKEMONDATA 0
//Classic
#define INFOBOX_F_STARTER_HYPER_OFFENSE 1
#define INFOBOX_F_STARTER_OFFENSE 2
#define INFOBOX_F_STARTER_BALANCE 3
#define INFOBOX_F_STARTER_BULKY_OFFENSE 4
#define INFOBOX_F_STARTER_STALL 5
//Field Effects
#define INFOBOX_F_STARTER_HAIL 6
#define INFOBOX_F_STARTER_RAIN 7
#define INFOBOX_F_STARTER_SUN 8
#define INFOBOX_F_STARTER_SANDSTORM 9
#define INFOBOX_F_STARTER_GRASSY_TERRAIN 10
#define INFOBOX_F_STARTER_PSYCHIC_TERRAIN 11
#define INFOBOX_F_STARTER_TRICK_ROOM 12
//Special
#define INFOBOX_F_STARTER_BATON_PASS 13
#define INFOBOX_F_STARTER_GIMMICK 14
#define INFOBOX_F_STARTER_EGGTACTICAL 15
#define INFOBOX_F_STARTER_MASOCHIST 16
#define INFOBOX_F_STARTER_FEAR 17

//other infoboxes
#define INFOGRID_TESTDEXNAV 18
#define INFOBOXGCMS1 19
#define INFOBOXGCMS2 20
#define INFOBOXGCMS3 21
#define INFOBOXAPCNBALLMENU 22
#define INFOBOX_PROF_SPECIAL_DELIVERY_MANIFEST 23
#define INFOBOX_DYNAMIC 24

//Times
#define RTC_TIME_DAY 0
#define RTC_TIME_EVENING 1
#define RTC_TIME_NIGHT 2
#define RTC_TIME_MORNING 3


//Botany Defines
#define NUM_MAPS_PER_BOTANY_CATEGORY 5

#define BOTANY_MAP_CATEGORY_JUNGLE 0
#define BOTANY_MAP_CATEGORY_COLD 1
#define BOTANY_MAP_CATEGORY_VOLCANIC 2
#define BOTANY_MAP_CATEGORY_SEASIDE 3
#define BOTANY_MAP_CATEGORY_AQUATIC 4
#define BOTANY_MAP_CATEGORY_SAVANNA 5
#define BOTANY_MAP_CATEGORY_GENERAL 6
#define NUM_BOTANY_MAP_CATEGORIES 7

#define NUM_CONSUMABLE_RECIPES 12
#define NUM_MEDICINE_RECIPES 8
#define NUM_RECIPES (BR_ICE_STONE + 1)

//Hack to make it so I only need one script command to perform all functions. Yes, i know, constants should be capsed, but this is for my sanity since i'll be the
//one scripting in all the achievements.
#define give 0
#define take 1
#define query 2

//factions related
#define FACTION_NATURALISTS 0 //Trainers who like to be in nature, surrounded by nature, simple existence. Campers, picknickers, rangers.          Opposed: Richkids(x1) "Pokemon are fine as they are!"
#define FACTION_STUDENTS 1 //Trainers still in school and learning, aka the gossip girls. Lass, Youngster, Twins, Jr+Sr.                         Opposed: Nerds(x1) "The best pokemon are the easiest to train!"
#define FACTION_NOBLES 2 //The rich assholes that no one likes except the other rich people. Rich boy, Lady, Expert, Parasol Lady.               Opposed: Naturalists(x1) "Pokemon are status symbols!"
#define FACTION_POKEFANS 3 //The people who just like having their pokemon around. Love pokemon for what they are, companions or pets.             Opposed: Athletes(x1) "Pokemon aren't tools of war, they're friends!"
#define FACTION_OUTCASTS 4 //The intense people that are eccentric, shunned, or generally out of it. Hex maniacs, bug maniacs, pokemaniacs, etc.      Opposed: Schoolkids(x1) "The wierd pokemons are the coolest!"
#define FACTION_PROFESSIONALS 5 //people who chose a pokemon related career with specific paths, like kindlers, or guitarists.                     Opposed: Pokefans(x1) "Pokemon should be used to their strengths"
#define FACTION_ATHLETES 6 //bodybuilders, meatheads, jocks, those whose entire existence is self improvement. Martial artists, fighters, etc.     Opposed: Pokefans(x0.5) Richkids(x0.5)  "Pokemon are best when trained 
#define FACTION_OTHERS 7 //everything else unclassified like aqua, magma, leaders, etc.                                                                     to their potential, not left to rot and spoil!"

#define FACTION_STAND_INVALID 0
#define FACTION_STAND_WORST 1
#define FACTION_STAND_REALLYBAD 2
#define FACTION_STAND_BAD 3
#define FACTION_STAND_NEUTRAL 4
#define FACTION_STAND_GOOD 5
#define FACTION_STAND_HIGH 6
#define FACTION_STAND_BEST 7

//The questlines that have their own discrete quest stage tracking variable
#define QUEST_ID_DEVON_SCIENTIST 0
#define QUEST_ID_DEVON_CORPORATE 1
#define QUEST_ID_AQUA 2
#define QUEST_ID_MAGMA 3
#define QUEST_ID_LANA 4
#define QUEST_ID_NURSE 5

//Real Estate defines that need to be visible to scripts

#define NUM_PROPERTIES 12

#define PROPERTY_DEWFORD     0
#define PROPERTY_FALLARBOR   1
#define PROPERTY_LILYCOVE    2
#define PROPERTY_MAUVILLE    3
#define PROPERTY_OLDALE      4
#define PROPERTY_ROUTE119    5
#define PROPERTY_RUSTBURO    6
#define PROPERTY_SLATEPORT   7
#define PROPERTY_SNOWYSHORE  8
#define PROPERTY_SOOTOPOLIS  9
#define PROPERTY_VERDANTURF  10
#define PROPERTY_MOSSDEEP    11
//there are an additional 20 properties


//notification types

#define NOTIFY_ACHIEVEMENT 0
#define NOTIFY_INTEREST    1
#define NOTIFY_REAL_ESTATE 2
#define NOTIFY_PICKUP      3
#define NOTIFY_MISSION     4
#define NOTIFY_QUEST       5
#define NOTIFY_GENERAL     6

#define EE_GAME_VERSION 8006


#endif