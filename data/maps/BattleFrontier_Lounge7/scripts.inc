BattleFrontier_Lounge7_MapScripts:: @ 8265254
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor:: @ 8265255
	lock
	faceplayer
	checkitem ITEM_SWEET_HEART, 1
	compare VAR_RESULT, 1
	goto_if_ne OLRS_DontHaveSweetHeart
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

OLRS_DontHaveSweetHeart::
	msgbox CancellingTutorNoItemSweetHeart
	release
	end

CancellingTutorNoItemSweetHeart:
	.string "Darling, I need a Sweet Heart for\n"
	.string "my services. Please go get some.$"

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor:: @ 8265276
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove:: @ 8265284
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_TEMP_2, ITEM_SWEET_HEART
	copyvar VAR_TEMP_D, VAR_RESULT
	compare VAR_RESULT, 9
	goto_if_le BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	compare VAR_RESULT, 10
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove:: @ 826532F
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_TEMP_2, ITEM_SWEET_HEART
	copyvar VAR_TEMP_D, VAR_RESULT
	compare VAR_RESULT, 9
	goto_if_le BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	compare VAR_RESULT, 10
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor:: @ 8265445
	lock
	faceplayer
	checkitem ITEM_OLD_GATEAU, 1
	compare VAR_RESULT, 1
	goto_if_ne OLRS_DontHaveOldGateau 
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

OLRS_DontHaveOldGateau:
	msgbox CancellingTutorNoItemOldGateau
	release
	end

CancellingTutorNoItemOldGateau:
	.string "Dearie, I need an Old Gateau for\n"
	.string "my services. Please go get some.$"

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor:: @ 8265466
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove:: @ 8265474
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_TEMP_2, ITEM_OLD_GATEAU
	copyvar VAR_TEMP_D, VAR_RESULT
	compare VAR_RESULT, 9
	goto_if_le BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	compare VAR_RESULT, 10
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove:: @ 826551F
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_TEMP_2, ITEM_OLD_GATEAU
	copyvar VAR_TEMP_D, VAR_RESULT
	compare VAR_RESULT, 9
	goto_if_le BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	compare VAR_RESULT, 10
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect:: @ 8265635
	special CloseBattleFrontierTutorWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon:: @ 8265645
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_D is the move selection
@ VAR_TEMP_E is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection:: @ 826564F
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	copyvar VAR_0x8004, VAR_TEMP_C
	bufferitemname 2, VAR_TEMP_2
	msgbox MoveTutorListWillRequireX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge7_EventScript_ChooseNewMove
	goto BattleFrontier_Lounge7_EventScript_TeachTutorMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove:: @ 8265696
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	removeitem VAR_TEMP_2, 1
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove:: @ 82656CA
	compare VAR_TEMP_E, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor:: @ 82656DB
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman:: @ 82656E4
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro: @ 82656ED
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough Trainer.\p"
	.string "I had a reputation as the toughest\n"
	.string "BEAUTY around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your Pokémon some\p"
	.string "smart moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about exchanging a Sweet\l"
	.string "Heart or two?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack: @ 82658AB
	.string "Buhahaha!\p"
	.string "Are you back to learn strong\n"
	.string "Pokémon moves?$"

BattleFrontier_Lounge7_Text_TeachWhichMove: @ 82658EF
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

MoveTutorListWillRequireX: @ 8265921
	.string "The move {STR_VAR_1}, is it?\n"
	.string "I will need a {STR_VAR_3}\l"
	.string "in exchange. Is that okay?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon: @ 826595A
	.string "Fine, fine, now pick the Pokémon\n"
	.string "I should teach the move to.$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints: @ 82659C7
	.string "Do you see how skilled I am now?\n"
	.string "I'll take the {STR_VAR_3}, now.$"

BattleFrontier_Lounge7_Text_YouDontWantTo: @ 8265A0E
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

BattleFrontier_Lounge7_Text_RightTutorIntro: @ 8265A6C
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic Trainer.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your Pokémon strong and\l"
	.string "impactful moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about exchanging an Old\l"
	.string "Gateau or two?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack: @ 8265C2C
	.string "Ihihihi!\p"
	.string "Have you come to learn smart and\n"
	.string "impactful Pokémon moves?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong: @ 8265C6F
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful: @ 8265D17
	.string "When I was just a wee YOUNGSTER,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us Trainers.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their Pokémon moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"

BattleFrontier_Lounge7_Text_Liquidation:: @ 8265E30
	.string "Slams the foe\n"
	.string "with water. Can\n"
	.string "lower defense.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc:: @ 8265E5B
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"

BattleFrontier_Lounge7_Text_ZenHeadbutt:: @ 8265E8A
	.string "Focuses power\n"
	.string "and hits with a\n"
	.string "strong headbutt.$"

BattleFrontier_Lounge7_Text_PainSplit:: @ 8265EC0
	.string "Shares the pain\n"
	.string "with the foe$"

BattleFrontier_Lounge7_Text_Recycle:: @ 8265EED
	.string "Allows the user\n"
	.string "to re-use its\n"
	.string "held item.$"

BattleFrontier_Lounge7_Text_BodySlamDesc:: @ 8265F1C
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"

BattleFrontier_Lounge7_Text_LowKick:: @ 8265F47
	.string "Deals more dam-\n"
	.string "age to heavier\n"
	.string "foes.$"

BattleFrontier_Lounge7_Text_MagicCoat:: @ 8265F77
	.string "Reflects special\n"
	.string "effects back at\n"
	.string "the foe.$"

BattleFrontier_Lounge7_Text_HealBell:: @ 8265FAA
	.string "Chimes in a\n"
	.string "soothing way to\n"
	.string "clear statuses.$"

BattleFrontier_Lounge7_Text_Bounce:: @ 8265FDD
	.string "User jumps high up\n"
	.string "then crashes down\n"
	.string "on the foe. May Prz.$"

BattleFrontier_Lounge7_Text_Outrage:: @ 826600A
	.string "Rampages for 2-3\n"
	.string "turns then gets\n"
	.string "confused.$"

BattleFrontier_Lounge7_Text_HeatWave:: @ 826603E
	.string "A hot breath\n"
	.string "attack that may\n"
	.string "burn the foe.$"

BattleFrontier_Lounge7_Text_GunkShot:: @ 8266070
	.string "Hurls filthy trash\n"
	.string "at the foe for dmg.\n"
	.string "May poison.$"

BattleFrontier_Lounge7_Text_Synthesis:: @ 82660A6
	.string "Restores health.\n"
	.string "Amount varies by\n"
	.string "active weather.$"

BattleFrontier_Lounge7_Text_HelpingHand:: @ 82660D0
	.string "Boosts power of\n"
	.string "ally's moves.$"

BattleFrontier_Lounge7_Text_EndureDesc:: @ 82660FF
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"

BattleFrontier_Lounge7_Text_FoulPlay:: @ 826612D
	.string "Deals damage\n"
	.string "based on target's\n"
	.string "Attack boosts.$"

BattleFrontier_Lounge7_Text_IcePunchDesc:: @ 826615F
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc:: @ 8266185
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"

BattleFrontier_Lounge7_Text_FirePunchDesc:: @ 82661B5
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"
