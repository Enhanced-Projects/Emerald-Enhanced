SlateportCity_PokemonFanClub_EventScript_SwaggerTutor:: @ 82C7F16
	lock
	faceplayer
	checkitem ITEM_BIG_PEARL, 1
	compare VAR_RESULT, 1
	goto_if_ne SC_MT_Hypervoice_nopearl
	setvar VAR_TEMP_5, ITEM_BIG_PEARL
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_HYPER_VOICE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	removeitem ITEM_BIG_PEARL, 1
	goto MoveTutor_EventScript_SwaggerTaught
	end

SC_MT_Hypervoice_nopearl::
	msgbox nopearlmsg
	release
	end

nopearlmsg:
    .string "Hey! You got to give me a Big Pearl\n"
    .string "before I'll show you a good time...$"


MoveTutor_EventScript_SwaggerDeclined:: @ 82C7F6A
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught:: @ 82C7F74
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor:: @ 82C7F7E
	lock
	faceplayer
	checkitem ITEM_BIG_MALASADA, 1
	compare VAR_RESULT, 1
	goto_if_ne MC_MT_Declined_nomalasada
	setvar VAR_TEMP_5, ITEM_BIG_MALASADA
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_STOMPING_TANTRUM
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	removeitem ITEM_BIG_MALASADA, 1
	goto MoveTutor_EventScript_RolloutTaught
	end

MC_MT_Declined_nomalasada::
	msgbox YouDontHaveMalasada
	release
	end

YouDontHaveMalasada::
    .string "I'm hungry!\n"
    .string "I need a Big Malasada for motivation.$"

MoveTutor_EventScript_RolloutDeclined:: @ 82C7FD2
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught:: @ 82C7FDC
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor:: @ 82C7FE6
	lock
	faceplayer
	checkitem ITEM_BERRY_JUICE, 1
	compare VAR_RESULT, 1
	goto_if_ne VT_Tutor_cost_declined
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SIGNAL_BEAM
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	removeitem ITEM_BERRY_JUICE, 1
	goto MoveTutor_EventScript_FuryCutterTaught
	end

VT_Tutor_cost_declined::
	msgbox NoBerryJuice
	release
	end

NoBerryJuice::
	.string "I'm wickedly thirsty, I need some Berry\n"
	.string "Juice to slake my thirst!$"

MoveTutor_EventScript_FuryCutterDeclined:: @ 82C803A
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught:: @ 82C8044
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_MimicTutor:: @ 82C804E
	lock
	faceplayer
	checkitem ITEM_BERRY_JUICE, 1
	compare VAR_RESULT, 1
	goto_if_ne LT_MT_NoBerryJuice
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_TRICK
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	removeitem ITEM_BERRY_JUICE, 1
	goto MoveTutor_EventScript_MimicTaught
	end

LT_MT_NoBerryJuice::
	msgbox LT_MT_NoBerryJuiceMsg
	release
	end

LT_MT_NoBerryJuiceMsg:
	.string "I need Berry Juice to\n"
	.string "maintain my guise. Please\l"
	.string "return with it!$"

MoveTutor_EventScript_MimicDeclined:: @ 82C80A2
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MimicTaught:: @ 82C80AC
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor:: @ 82C80B6
	lock
	faceplayer
	checkitem ITEM_BIG_PEARL, 1
	compare VAR_RESULT, 1
	goto_if_ne FT_MT_NoPearl
	setvar VAR_TEMP_5, ITEM_BIG_PEARL
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	removeitem ITEM_BIG_PEARL, 1
	goto MoveTutor_EventScript_MetronomeTaught
	end

FT_MT_NoPearl::
	msgbox FT_MT_NoPearlMsg
	release
	end

FT_MT_NoPearlMsg::
	.string "I need a Big Pearl to gaze\n"
	.string "into while teaching. Come back\l"
	.string "with one!$"

MoveTutor_EventScript_MetronomeDeclined:: @ 82C810A
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeTaught:: @ 82C8114
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor:: @ 82C811E
	lock
	faceplayer
	checkitem ITEM_PP_UP, 1
	compare VAR_RESULT, 1
	goto_if_ne FC_MT_NoDragonScale 
	setvar VAR_TEMP_5, ITEM_PP_UP
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DRACO_METEOR
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	removeitem ITEM_PP_UP, 1
	goto MoveTutor_EventScript_SleepTalkTaught
	end

FC_MT_NoDragonScale::
	msgbox FC_MT_NoDragonScaleMsg
	release
	end

FC_MT_NoDragonScaleMsg:
	.string "PP Ups give pokemon more\n"
	.string "stamina in battle. But, did\p"
	.string "you know that it can do things\n"
	.string "for people, too?\p"
	.string "My wife loves it when I take\n"
	.string "PP Up to improve my own stamina\l"
	.string "in bed.\p"
	.string "Bring me some PP Up and we can\n"
	.string "make a deal.$"

MoveTutor_EventScript_SleepTalkDeclined:: @ 82C8172
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkTaught:: @ 82C817C
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor:: @ 82C8186
	lock
	faceplayer
	checkitem ITEM_QUICK_CLAW, 1
	compare VAR_RESULT, 1
	goto_if_ne LCC_MT_Sub_noqc
	setvar VAR_TEMP_5, ITEM_QUICK_CLAW
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_TAILWIND
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	removeitem ITEM_QUICK_CLAW, 1
	goto MoveTutor_EventScript_SubstituteTaught
	end

LCC_MT_Sub_noqc::
	msgbox noquickclaw
	release
	end

noquickclaw:
    .string "I need a Quick Claw in order to teach\n"
    .string "the move Tailwind. Please return\l"
    .string "with one...$"


MoveTutor_EventScript_SubstituteDeclined:: @ 82C81DA
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteTaught:: @ 82C81E4
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor:: @ 82C81EE
	lock
	faceplayer
	checkitem ITEM_EXPERT_BELT, 1
	compare VAR_RESULT, 1
	goto_if_ne MD_MT_NoExpertBelt
	setvar VAR_TEMP_5, ITEM_EXPERT_BELT
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DRAIN_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	removeitem ITEM_EXPERT_BELT, 1
	goto MoveTutor_EventScript_DynamicPunchTaught
	end

MD_MT_NoExpertBelt::
	msgbox noExpertBelt
	release
	end

noExpertBelt:
	.string "Maybe if I had an Expert Belt,\n"
	.string "I would have a better chance at\l"
	.string "beating the twins...$"

MoveTutor_EventScript_DynamicPunchDeclined:: @ 82C8242
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchTaught:: @ 82C824C
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor:: @ 82C8256
	lock
	faceplayer
	checkitem ITEM_LIFE_ORB, 1
	compare VAR_RESULT, 1
	goto_if_ne SC1_PC_MT_NoLifeOrb
	setvar VAR_TEMP_5, ITEM_LIFE_ORB
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	removeitem ITEM_LIFE_ORB, 1
	goto MoveTutor_EventScript_DoubleEdgeTaught
	end

SC1_PC_MT_NoLifeOrb::
	msgbox SC1nolifeorb
	release 
	end

SC1nolifeorb:
	.string "I'm feeling really edgy, I need\n"
	.string "a Life Orb. That item is also\l"
	.string "sort of double-edged, too, huh?$"

MoveTutor_EventScript_DoubleEdgeDeclined:: @ 82C82AA
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeTaught:: @ 82C82B4
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor:: @ 82C82BE
	lock
	faceplayer
	checkitem ITEM_LIFE_ORB, 1
	compare VAR_RESULT, 1
	goto_if_ne PT_MT_NoLifeOrb
	setvar VAR_TEMP_5, ITEM_LIFE_ORB
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	removeitem ITEM_LIFE_ORB, 1
	goto MoveTutor_EventScript_ExplosionTaught
	end

PT_MT_NoLifeOrb::
	msgbox PT1nolifeorb
	release
	end

PT1nolifeorb::
	.string "Life Orb is something I require\n"
	.string "to become popular. Please bring me\l"
	.string "one!$"


MoveTutor_EventScript_ExplosionDeclined:: @ 82C8312
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught:: @ 82C831C
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu:: @ 82C8326
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce:: @ 82C832D
	bufferitemname 0, VAR_TEMP_5
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return

BotanyMaster_CutTutor::
	lock
	msgbox BotanyMaster_CutTutorMsg, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BotanyMaster_CutTutorDeclined
	msgbox BotanyMaster_CutTotorWhichMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_CUT
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq BotanyMaster_CutTutorDeclined
	goto BotanyMaster_CutTutorTaught
	end

BotanyMaster_CutTutorDeclined::
	msgbox BotanyMaster_CutDeclinedMsg, MSGBOX_DEFAULT
	release
	end

BotanyMaster_CutTutorTaught::
	msgbox BotanyMaster_CutTutorTaughtMsg, MSGBOX_DEFAULT
	release
	end

BotanyMaster_CutTutorMsg:
	.string "Do you need Cut tutoring?$"

BotanyMaster_CutTotorWhichMove:
	.string "Which pokemon should learn Cut?$"

BotanyMaster_CutDeclinedMsg:
	.string "Come back if you change your mind!$"

BotanyMaster_CutTutorTaughtMsg:
	.string "Your pokemon has learned to\nCut herbs!$"
