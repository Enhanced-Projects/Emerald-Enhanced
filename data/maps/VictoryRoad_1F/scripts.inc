VictoryRoad_1F_MapScripts::
	map_script ON_FRAME, VR1_CloseMewTwoDoor
	.byte 0

VR1_CloseMewTwoDoor::
	map_script_2 VAR_TEMP_7, 0, VR1_CloseDoor
	.2byte 0
	
VR1_CloseDoor::
	setvar VAR_TEMP_7, 1
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 107
	goto_if_eq ryu_end
	setmetatile  9, 19, 537, 1
	setmetatile 10, 19, 537, 1
	setmetatile 11, 19, 537, 1
	setmetatile  9, 20, 537, 1
	setmetatile 10, 20, 537, 1
	setmetatile 11, 20, 537, 1
	end

VictoryRoad_1F_EventScript_Edgar:: @ 8235E73
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert:: @ 8235E8A
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope:: @ 8235EA1
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy:: @ 8235EB8
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn:: @ 8235ECF
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore: @ 8235EE6
	.string "WALLY: Hi! {PLAYER}!\p"
	.string "I bet you're surprised to see me here!\p"
	.string "I made it all the way here, and it's\n"
	.string "all thanks to you!\p"
	.string "{PLAYER}, losing to you that time\n"
	.string "made me stronger!\p"
	.string "But I'm not going to lose anymore!\p"
	.string "I'm going to win! For the Pokémon who\n"
	.string "gave me courage and strength!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_WallyEntranceDefeat: @ 8235FFC
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle: @ 8236020
	.string "WALLY: I couldn't beat you today,\n"
	.string "{PLAYER}, but one of these days, I'll\l"
	.string "catch up to you!$"

VictoryRoad_1F_Text_WallyIntro: @ 8236073
	.string "WALLY: Hi! {PLAYER}!\p"
	.string "I've gotten stronger since that last\n"
	.string "time! I wanted to show you, {PLAYER}!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_WallyDefeat: @ 82360DA
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_WallyPostBattle: @ 82360FE
	.string "WALLY: I couldn't beat you this time,\n"
	.string "too… But one of these days, {PLAYER},\l"
	.string "I'm going to catch up to you…\p"
	.string "And challenge the Pokémon League!$"

VictoryRoad_1F_Text_EdgarIntro: @ 8236184
	.string "I've made it this far a couple times,\n"
	.string "but the last stretch is so long…$"

VictoryRoad_1F_Text_EdgarDefeat: @ 82361CB
	.string "My dream ends here again…$"

VictoryRoad_1F_Text_EdgarPostBattle: @ 82361E5
	.string "You've made it this far. Keep the\n"
	.string "momentum going and become the\l"
	.string "Champion! If anyone can, it's you!$"

VictoryRoad_1F_Text_AlbertIntro: @ 8236248
	.string "I didn't come all this way to lose now.\n"
	.string "That possibility doesn't exist!$"

VictoryRoad_1F_Text_AlbertDefeat: @ 8236290
	.string "Impossible…\n"
	.string "I lost?$"

VictoryRoad_1F_Text_AlbertPostBattle: @ 82362A4
	.string "I lost here…\p"
	.string "That means I lack the qualifications\n"
	.string "to become the Champion…$"

VictoryRoad_1F_Text_HopeIntro: @ 82362EE
	.string "This seemingly infinite and harsh road\n"
	.string "lives up to its name of VICTORY.$"

VictoryRoad_1F_Text_HopeDefeat: @ 8236336
	.string "Your battle style is fantastic…$"

VictoryRoad_1F_Text_HopePostBattle: @ 8236356
	.string "You seem to have the potential for\n"
	.string "becoming the Champion.$"

VictoryRoad_1F_Text_QuincyIntro: @ 8236390
	.string "What is the VICTORY ROAD?\n"
	.string "I'll tell you if you win!$"

VictoryRoad_1F_Text_QuincyDefeat: @ 82363C4
	.string "Okay!\n"
	.string "Well done!$"

VictoryRoad_1F_Text_QuincyPostBattle: @ 82363D5
	.string "Getting through here safely--that's\n"
	.string "the final test for any Trainer aiming\l"
	.string "to become the Pokémon Champion.\p"
	.string "That's why it's called the VICTORY\n"
	.string "ROAD.$"

VictoryRoad_1F_Text_KatelynnIntro: @ 8236468
	.string "I have nothing to say to anyone\n"
	.string "that's come this far. Come on!$"

VictoryRoad_1F_Text_KatelynnDefeat: @ 82364A7
	.string "This is a disgrace…$"

VictoryRoad_1F_Text_KatelynnPostBattle: @ 82364BB
	.string "Humph, go right on ahead.\n"
	.string "See if I care.$"
@==================================================================================================

VR1_Moltres::
	goto_if_set FLAG_RYU_MOLTRES, RyuLegendary_Stoneisdull
	msgbox NewMauville_Moltres_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox NewMauville_Moltres_TouchedStone
	playmoncry SPECIES_MOLTRES, 0
	closemessage
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	waitmoncry
	setwildbattle SPECIES_MOLTRES, VAR_RESULT, ITEM_CHARCOAL
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_MOLTRES
	release
	end

NewMauville_Moltres_TouchedStone:
	.string "{PLAYER} touched the stone.\p"
	.string "{PLAYER} OH SH-!$"

NewMauville_Moltres_TouchQuery:
	.string "This stone looks like it was\n"
	.string "torched!\p"
	.string "Touch the stone?$"


