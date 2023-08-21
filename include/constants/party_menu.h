#ifndef GUARD_CONSTANTS_PARTY_MENU_H
#define GUARD_CONSTANTS_PARTY_MENU_H

#define AILMENT_NONE  0
#define AILMENT_PSN   1
#define AILMENT_PRZ   2
#define AILMENT_SLP   3
#define AILMENT_FRZ   4
#define AILMENT_BRN   5
#define AILMENT_PKRS  6
#define AILMENT_FNT   7

#define TUTOR_MOVE_PAIN_SPLIT           0
#define TUTOR_MOVE_BOUNCE               1
#define TUTOR_MOVE_RECYCLE              2
#define TUTOR_MOVE_BODY_SLAM            3
#define TUTOR_MOVE_DOUBLE_EDGE          4
#define TUTOR_MOVE_MAGIC_COAT           5
#define TUTOR_MOVE_SEISMIC_TOSS         6
#define TUTOR_MOVE_TRICK                7
#define TUTOR_MOVE_METRONOME            8
#define TUTOR_MOVE_LIQUIDATION          9
#define TUTOR_MOVE_ZEN_HEADBUTT         10
#define TUTOR_MOVE_HEAL_BELL            11
#define TUTOR_MOVE_EXPLOSION            12
#define TUTOR_MOVE_LOW_KICK             13
#define TUTOR_MOVE_TAILWIND             14
#define TUTOR_MOVE_DRAIN_PUNCH          15
#define TUTOR_MOVE_STOMPING_TANTRUM     16
#define TUTOR_MOVE_FOUL_PLAY            17
#define TUTOR_MOVE_HEAT_WAVE            18
#define TUTOR_MOVE_HELPING_HAND         19
#define TUTOR_MOVE_ENDURE               20
#define TUTOR_MOVE_GUNK_SHOT            21
#define TUTOR_MOVE_ICE_PUNCH            22
#define TUTOR_MOVE_HYPER_VOICE          23
#define TUTOR_MOVE_DRACO_METEOR         24
#define TUTOR_MOVE_SYNTHESIS            25
#define TUTOR_MOVE_OUTRAGE              26
#define TUTOR_MOVE_THUNDER_PUNCH        27
#define TUTOR_MOVE_FIRE_PUNCH           28
#define TUTOR_MOVE_SIGNAL_BEAM          29
#define TUTOR_MOVE_SHADOW_SLAM          30
#define TUTOR_MOVE_CUT                  31
#define TUTOR_MOVE_COUNT                32

#define PARTY_LAYOUT_SINGLE          0
#define PARTY_LAYOUT_DOUBLE          1
#define PARTY_LAYOUT_MULTI           2
#define PARTY_LAYOUT_MULTI_SHOWCASE  3  // The layout during the screen that appears just before a multi battle
#define PARTY_LAYOUT_COUNT           4
#define KEEP_PARTY_LAYOUT            0xFF

#define PARTY_MENU_TYPE_FIELD                     0 
#define PARTY_MENU_TYPE_IN_BATTLE                 1 
#define PARTY_MENU_TYPE_CONTEST                   2 
#define PARTY_MENU_TYPE_CHOOSE_MON                3 
#define PARTY_MENU_TYPE_CHOOSE_HALF               4  // multi battles, eReader battles, and some battle facilities
#define PARTY_MENU_TYPE_MULTI_SHOWCASE            5
#define PARTY_MENU_TYPE_DAYCARE                   6 
#define PARTY_MENU_TYPE_MOVE_RELEARNER            7 
#define PARTY_MENU_TYPE_UNION_ROOM_REGISTER       8  // trading board
#define PARTY_MENU_TYPE_UNION_ROOM_TRADE          9  // trading board
#define PARTY_MENU_TYPE_SPIN_TRADE                10 // Unused beta for Gen IV's Spin Trade
#define PARTY_MENU_TYPE_MINIGAME                  11
#define PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS  12

#define PARTY_ACTION_CHOOSE_MON         0
#define PARTY_ACTION_SEND_OUT           1
#define PARTY_ACTION_CANT_SWITCH        2
#define PARTY_ACTION_USE_ITEM           3
#define PARTY_ACTION_ABILITY_PREVENTS   4
#define PARTY_ACTION_GIVE_ITEM          5  
#define PARTY_ACTION_GIVE_PC_ITEM       6   // Unused. Not possible to give non-mail items directly from PC
#define PARTY_ACTION_GIVE_MAILBOX_MAIL  7
#define PARTY_ACTION_SWITCH             8
#define PARTY_ACTION_SWITCHING          9
#define PARTY_ACTION_SOFTBOILED         10
#define PARTY_ACTION_CHOOSE_AND_CLOSE   11
#define PARTY_ACTION_MOVE_TUTOR         12
#define PARTY_ACTION_MINIGAME           13
#define PARTY_ACTION_REUSABLE_ITEM      14  // Unused. The only reusable items are handled separately

// IDs for DisplayPartyMenuStdMessage, to display the message at the bottom of the party menu
#define PARTY_MSG_CHOOSE_MON                0
#define PARTY_MSG_CHOOSE_MON_OR_CANCEL      1
#define PARTY_MSG_CHOOSE_MON_AND_CONFIRM    2
#define PARTY_MSG_MOVE_TO_WHERE             3 
#define PARTY_MSG_TEACH_WHICH_MON           4
#define PARTY_MSG_USE_ON_WHICH_MON          5
#define PARTY_MSG_GIVE_TO_WHICH_MON         6
#define PARTY_MSG_NOTHING_TO_CUT            7
#define PARTY_MSG_CANT_SURF_HERE            8
#define PARTY_MSG_ALREADY_SURFING           9
#define PARTY_MSG_CURRENT_TOO_FAST          10
#define PARTY_MSG_ENJOY_CYCLING             11
#define PARTY_MSG_ALREADY_IN_USE            12
#define PARTY_MSG_CANT_USE_HERE             13
#define PARTY_MSG_NO_MON_FOR_BATTLE         14
#define PARTY_MSG_CHOOSE_MON_2              15
#define PARTY_MSG_NOT_ENOUGH_HP             16
#define PARTY_MSG_X_MONS_ARE_NEEDED         17
#define PARTY_MSG_MONS_CANT_BE_SAME         18
#define PARTY_MSG_NO_SAME_HOLD_ITEMS        19
#define PARTY_MSG_UNUSED                    20
#define PARTY_MSG_DO_WHAT_WITH_MON          21
#define PARTY_MSG_RESTORE_WHICH_MOVE        22
#define PARTY_MSG_BOOST_PP_WHICH_MOVE       23
#define PARTY_MSG_DO_WHAT_WITH_ITEM         24
#define PARTY_MSG_DO_WHAT_WITH_MAIL         25
#define PARTY_MSG_ALREADY_HOLDING_ONE       26
#define PARTY_MSG_NONE                      127

// IDs for DisplayPartyPokemonDescriptionText, to display a message in the party pokemon's box
#define PARTYBOX_DESC_NO_USE      0
#define PARTYBOX_DESC_ABLE_3      1
#define PARTYBOX_DESC_FIRST       2
#define PARTYBOX_DESC_SECOND      3
#define PARTYBOX_DESC_THIRD       4
#define PARTYBOX_DESC_FOURTH      5
#define PARTYBOX_DESC_FIFTH       6
#define PARTYBOX_DESC_SIXTH       7
#define PARTYBOX_DESC_ABLE        8
#define PARTYBOX_DESC_NOT_ABLE    9
#define PARTYBOX_DESC_ABLE_2      10
#define PARTYBOX_DESC_NOT_ABLE_2  11
#define PARTYBOX_DESC_LEARNED     12
#define PARTYBOX_DESC_HAVE        13
#define PARTYBOX_DESC_DONT_HAVE   14

#define SELECTWINDOW_ACTIONS  0
#define SELECTWINDOW_ITEM     1
#define SELECTWINDOW_MAIL     2
#define SELECTWINDOW_MOVES    3

#endif // GUARD_CONSTANTS_PARTY_MENU_H
