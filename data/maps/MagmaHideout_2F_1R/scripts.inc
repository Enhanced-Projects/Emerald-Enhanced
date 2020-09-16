MagmaHideout_2F_1R_MapScripts:: @ 8239B50
	map_script ON_FRAME, MH2_MagmaArmyMeetingCheck
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14:: @ 8239B51
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3:: @ 8239B68
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4:: @ 8239B7F
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5:: @ 8239B96
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro: @ 8239BAD
	.string "What, what, what?\p"
	.string "Only Team Magma members are supposed\n"
	.string "to be in here!\p"
	.string "But you're not dressed in Team Magma's\n"
	.string "uniform…\p"
	.string "You rouse my suspicion!\n"
	.string "Battle with me!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat: @ 8239C4B
	.string "Aiyiyi…\n"
	.string "My pride as a Team Magma member…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle: @ 8239C74
	.string "If you suffer from chills, you should\n"
	.string "join Team Magma.$"

MagmaHideout_2F_1R_Text_Grunt3Intro: @ 8239CAB
	.string "Hold it right there!\p"
	.string "You don't really expect me to keep\n"
	.string "my trap shut and let you waltz by me?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat: @ 8239D09
	.string "Ooh wow!\n"
	.string "I concede!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle: @ 8239D1D
	.string "Maybe it would've been better if I did\n"
	.string "just let you go unchallenged…$"

MagmaHideout_2F_1R_Text_Grunt4Intro: @ 8239D62
	.string "Ahah!\n"
	.string "An intruder!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat: @ 8239D75
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle: @ 8239D7D
	.string "I've already lost.\p"
	.string "Do I really need to keep running\n"
	.string "around in a circle?$"

MagmaHideout_2F_1R_Text_Grunt5Intro: @ 8239DC5
	.string "Oh, oh!\n"
	.string "An intruder!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat: @ 8239DDA
	.string "Mutter…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle: @ 8239DE2
	.string "Actually, I'm no expert at battling…$"
	
@==================================================================================================quest related

MH2_MagmaArmyMeetingCheck::
	map_script_2 VAR_RYU_MAGMA, 325, MH2_MagmaArmyMeetingScene
	.2byte 0
	
MH2_MagmaArmyMeetingScene::
	setvar VAR_RYU_MAGMA, 330
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MH2_Cam1
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MH2_EveryonThereIs
	closemessage
	delay 40
	msgbox MH2_AtopMtPyre
	closemessage
	applymovement 12, Common_Movement_FaceUp
	waitmovement 12
	msgbox MH2_YouSeeMaxie
	closemessage
	applymovement 10, Common_Movement_StepRight
	applymovement 12, Common_Movement_StepRight
	waitmovement 12
	applymovement 12, Common_Movement_StepUp
	applymovement 10, Common_Movement_FaceUp
	waitmovement 12
	applymovement 10 MH2_MaxieCourtneyExit@up 5
	applymovement 12, MH2_MaxieCourtneyExit
	applymovement 9, MH2_BlaiseFollowsMaxie@delay 16x2, up 5
	waitmovement 9
	applymovement 11, Common_Movement_StepRight
	waitmovement 11
	applymovement 11, Common_Movement_StepDown
	waitmovement 11
	msgbox MH2_OurLeaderHas
	closemessage
	fadescreen FADE_TO_BLACK
	call MH2_HideAllBut11
	fadescreen FADE_FROM_BLACK
	msgbox MH2_AndThatIs
	closemessage
	applymovement 11, Common_Movement_StepUp
	waitmovement 11
	applymovement 11, Common_Movement_StepUp
	applymovement OBJ_EVENT_ID_CAMERA, MH2_Cam2
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	msgbox MH2_HoldOnASec
	closemessage
	delay 40
	removeobject 11
	msgbox MH2_Elipsis
	closemessage
	setvar VAR_RYU_MAGMA, 350@Player finished magma and needs to get 7th badge to continue
	setflag FLAG_HIDE_MAGMA_ARMY
	clearflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	applymovement 17, Common_Movement_FaceDown
	waitmovement 17
	msgbox MH2_DontForgetYou
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MH2_Cam3
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox MH2_ItsJustThere
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, MH2_Cam4
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	applymovement 17, MH2_HelperGruntExits
	waitmovement 17
	removeobject 17
	release
	end
	
	
MH2_EveryonThereIs:
	.string "Everyone...there is much to discuss.\p"
    .string "Over the course of enacting our\n"
    .string "plans, there have been quite a number\l"
    .string "of setbacks...\p"
    .string "Regardless, our efforts have finally\n"
    .string "begun to bear fruit.\p"
    .string "We've successfully claimed this\n"
    .string "mountain as our own and fended off\l"
    .string "our sworn enemies...\p"
    .string "However, this is no time to relax!\n"
    .string "In fact, this is just the beginning.$"

MH2_AtopMtPyre:
	.string "Atop Mt. Pyre lies what we of Team\n"
    .string "Magma seek...the power to control\l"
    .string "Groudon, the Red Orb!\p"
    .string "We shall achieve everything we so\n"
    .string "desire!$"

MH2_YouSeeMaxie:	
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You see Maxie turn and say\n something to his admins...)$"
	
MH2_OurLeaderHas:
	.string "Our Leader has spoken, so listen up!\n"
    .string "Each of you will be given a task for\l"
    .string "this mission.\p"
    .string "Once you know what you'll be doing,\n"
    .string "you're to head to the site at once!$"

MH2_AndThatIs:
	.string "And that is all.$"
	
MH2_HoldOnASec:
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Hold on a sec, where's my assignment?$"
	
MH2_Elipsis:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ... ... ...\n"
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(No recognition...that'll change soon\l"
    .string " enough.)\p"
    .string " Time for me to hit the next Gym and\n"
    .string " become stronger.)$"

MH2_DontForgetYou:
	.string "Don't forget you can use the\nmachine to our left to heal\lor purchase items.$"
	
MH2_ItsJustThere:
	.string "It's just over there...$"


MH2_MaxieCourtneyExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MH2_BlaiseFollowsMaxie:
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
	
MH2_HideAllBut11::
	removeobject 9
	removeobject 10
	removeobject 12
	removeobject 13
	removeobject 14
	removeobject 15
	removeobject 16
	removeobject 18
	removeobject 19
	removeobject 20
	removeobject 21
	special DrawWholeMapView
	return
	
MH2_HelperGruntExits:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


MH2_Cam1:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
MH2_Cam2:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
MH2_Cam3:
	walk_diag_southwest
	walk_diag_southwest
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
MH2_Cam4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_diag_northeast
	walk_diag_northeast
	step_end
	
	
@==================================================================================================Magma heal/shop machine

MH2_Fence::
	compare VAR_RYU_MAGMA, 320
	goto_if_lt MH2_CantAccessFence
	setflag FLAG_RYU_SELLING_TO_FENCE
	setvar VAR_RYU_PRICE_MULTIPLIER, 250
	msgbox MH2_FenceIntro
	closemessage
	pokemart MH2_FenceMart
	msgbox MH2_FenceOutro
	clearflag FLAG_RYU_SELLING_TO_FENCE
	release
	end
	
	.align 2
MH2_FenceMart:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_NONE
	release
	end

MH2_CantAccessFence::
	msgbox MH2_Fence_AccessDenied
	release
	end

MH2_MagmaMultiUseMachine::
	compare VAR_RYU_MAGMA, 320
	goto_if_lt MH2_NoAccessToMachine
	msgbox MH2_WelcomeToMachine
	closemessage
	multichoicegrid 2, 110, MULTI_MAGMA_MACHINE, 2, 1
	switch VAR_RESULT
	case 0, MH2_Machine_HealParty
	case 1, MH2_Machine_KitShop
	goto MH2_Machine_HealParty
	
	
MH2_Machine_HealParty::
	fadescreen FADE_TO_BLACK
	delay 40
	special HealPlayerParty
	delay 20
	fadescreen FADE_FROM_BLACK
	msgbox MH2_MachineHealed
	release
	end
	
MH2_MachineHealed:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(Your team has been healed\nby the machine.)$"
	
MH2_Machine_KitShop::
	multichoice  0, 0, MULTI_MAGMA_MACHINE_KITS, 1
	switch VAR_RESULT
	case 0, MHM_BasicHealing
	case 1, MHM_BetterHealing
	case 2, MHM_PremiumHealing
	case 3, MHM_DeluxeHealing
	case 4, MHM_BasicCapture
	case 5, MHM_AdvancedCapture
	case 6, MHM_PerformanceBoost
	case 7, MHM_MasterKit
	case 8, MHM_Exit
	goto MHM_Exit
	
MHM_BasicHealing::
	msgbox BasicHealingKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 1500
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_POTION, 5
	additem ITEM_FULL_HEAL, 2
	takemoney 1500
	msgbox MHM_Success
	closemessage
	release
	end

MHM_BetterHealing::
	msgbox BetterHealingKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 3500
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_SUPER_POTION, 10
	additem ITEM_FULL_HEAL, 4
	additem ITEM_ETHER, 2
	additem ITEM_REVIVAL_HERB, 1
	takemoney 3500
	msgbox MHM_Success
	closemessage
	release
	end

MHM_PremiumHealing::
	msgbox PremiumHealingKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 6250
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_HYPER_POTION, 10
	additem ITEM_FULL_HEAL, 2
	additem ITEM_ELIXIR, 5
	additem ITEM_REVIVE, 2
	takemoney 6250
	msgbox MHM_Success
	closemessage
	release
	end
	
MHM_DeluxeHealing::
	msgbox DeluxeHealingKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_FULL_RESTORE, 12
	additem ITEM_MAX_ELIXIR, 10
	additem ITEM_MAX_REVIVE, 3
	msgbox MHM_Success
	takemoney 10000
	closemessage
	release
	end

MHM_BasicCapture::
	msgbox BasicCaptureKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 500
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_POKE_BALL, 10
	additem ITEM_PREMIER_BALL, 2
	takemoney 500
	msgbox MHM_Success
	closemessage
	release
	end
	
MHM_AdvancedCapture::
	msgbox AdvancedCaptureKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 2500
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_PREMIER_BALL, 20
	additem ITEM_ULTRA_BALL, 10
	takemoney 2500
	msgbox MHM_Success
	closemessage
	release
	end
	

MHM_PerformanceBoost::
	msgbox PerformanceBoostKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 25000
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_PROTEIN, 2
	additem ITEM_CALCIUM, 2
	additem ITEM_CARBOS, 2
	additem ITEM_ZINC, 2
	additem ITEM_HP_UP, 2
	additem ITEM_IRON, 2
	takemoney 25000
	msgbox MHM_Success
	closemessage
	release
	end
	
MHM_MasterKit::
	msgbox MasterKit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne ryu_end
	checkmoney 20000
	compare VAR_RESULT, 1
	goto_if_ne MHM_CantAfford
	additem ITEM_FULL_RESTORE, 5
	additem ITEM_PP_MAX, 4
	additem ITEM_RARE_CANDY, 10
	additem ITEM_LUXURY_BALL, 10
	additem ITEM_MAX_REVIVE, 10
	additem ITEM_HYPER_POTION, 4
	takemoney 20000
	msgbox MHM_Success
	closemessage
	release
	end
	
MHM_Exit::
	msgbox MHM_Exiting
	release
	end
	
MH2_NoAccessToMachine::
	msgbox MHM_AccessDenied
	release
	end
	
MH2_FenceIntro:
	.string "Hey! Sell your illicit goods\nhere to get clean money!$"
	
MH2_Fence_AccessDenied:
	.string "Hey! I'm running a legit\nbusiness here. Get lost!$"
	
MH2_FenceOutro:
	.string "Come back when you\ngot more goods!$"
	
MHM_AccessDenied:
	.string "User Identity unknown.\n"
	.string "{COLOR RED}{SHADOW LIGHT_GREY} ACCESS DENIED.$"
	
MH2_WelcomeToMachine:
	.string "Welcome to Magmatic Enterprises\n"
	.string "Please make a selection.$"
	
BasicHealingKit:
	.string "This kit contains 5 potions and\n2 Full Heals.\pDo you want this kit?$"
	
BetterHealingKit:
	.string "This kit has 10 Super Potions,\n"
	.string "4 Full Heals, 2 Ethers,\l"
	.string "and one Revival Herb.\p"
	.string "Do you want this kit?$"
	
PremiumHealingKit:
	.string "This kit has 10 Hyper Potions,\n"
	.string "2 Full Heals, 5 Elixirs,\l"
	.string "and two Revives.\p"
	.string "Do you want this kit?$"
	
DeluxeHealingKit:
	.string "This kit has 12 Full Restores,\n"
	.string "2 Max Elixir, and three\l"
	.string "Max Revives.\p"
	.string "Do you want this kit?$"
	
BasicCaptureKit:
	.string "This kit has 10 Poke Balls\n"
	.string "and two Premier Balls.\p"
	.string "Do you want this kit?$"
	
AdvancedCaptureKit:
	.string "This kit has 20 Premier Balls\n"
	.string "and 10 Ultra Balls.\p"
	.string "Do you want this kit?$"
	
PerformanceBoostKit:
	.string "This kit contains 2 each of\n"
	.string "each performance enhancing drug.\p"
	.string "Do you want this kit?$"
	
MasterKit:
	.string "The master kit is the VIP\n"
	.string "package. It contains:\p"
	.string "Full Restore: 5\n"
	.string "PP Max and Hyper Potion: 2\p"
	.string "Rare Candy, Luxury Ball,\n"
	.string "Max Revive: 10.\p"
	.string "Do you want this kit?$"
	
MHM_Success:
	.string "The purchase was successful.\n"
	.string "Exiting...$"
	
MHM_CantAfford:
	.string "The user does not have enough\n"
	.string "currency to purchase the chosen\l"
	.string "kit. Exiting...$"
	
MHM_Exiting:
	.string "Exiting the Magmatic Enterprises\n"
	.string "interface. $"
	




















