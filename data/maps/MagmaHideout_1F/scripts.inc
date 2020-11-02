MagmaHideout_1F_MapScripts:: @ 8239880
	map_script ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition: @ 8239886
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1:: @ 823988C
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2:: @ 82398A3
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	call MH_CheckPlayerIsMagma
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro: @ 82398BA
	.string "When Team Magma has roll call, we get\n"
	.string "important guarding assignments in\l"
	.string "the order that we line up.\p"
	.string "That's why I'm stuck off in this corner.\n"
	.string "I'm always late to roll call!$"

MagmaHideout_1F_Text_Grunt1Defeat: @ 8239964
	.string "I'm always late for training sessions,\n"
	.string "too!\p"
	.string "I hate to say it, but I'm wimpy…$"

MagmaHideout_1F_Text_Grunt1PostBattle: @ 82399B1
	.string "Okay, I'll try to put a little more\n"
	.string "effort into things from now on…$"

MagmaHideout_1F_Text_Grunt2Intro: @ 82399F5
	.string "Our leader told us to dig into\n"
	.string "MT. Chimney, so we dug and dug.\p"
	.string "And in the course of digging, we came\n"
	.string "across something that blew our minds!\p"
	.string "What did we find?\p"
	.string "Fuhahaha!\n"
	.string "I'll tell you if you beat me!$"

MagmaHideout_1F_Text_Grunt2Defeat: @ 8239ABA
	.string "Arrgh!\n"
	.string "Taken down!$"

MagmaHideout_1F_Text_Grunt2PostBattle: @ 8239ACD
	.string "I won't tell you after all.\n"
	.string "You'll find out when you get there!\p"
	.string "It'd be better if you saved surprises\n"
	.string "to the end, don't you think?$"

@==================================================================================================Aqua scripts
MH_Shortcut::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	warpsilent MAP_MAGMA_HIDEOUT_4F, 0, 46, 7
	release
	end
	
MH_ShellyArrival::
	setvar VAR_RYU_AQUA, 95 @Player met up with shelly in magma hideout 1f
	lock
	addobject 7
	fadenewbgm 441
	applymovement 7, MH_ShellyWalk
	waitmovement 0
	msgbox MH_ShellyIntro
	closemessage
	msgbox MH_ShellyRelQuery
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	msgbox MH_ShellyPreparing
	closemessage
	msgbox MH_observation
	closemessage
	setflag FLAG_RYU_DS_SHELLY_CLOSEFRIENDS
	removeobject 7
	createfollower OBJ_EVENT_GFX_AQUA_MEMBER_F, MH_FollowerShellyScript, DIR_NORTH
	setflag FLAG_RYU_WAYSTONE_DISABLED
	clearflag FLAG_RYU_AQUA_HIDE_MH4_COURTNEY_BOSS
	setflag FLAG_RYU_MH_COURTNEY_SOLOMODE
	setflag FLAG_HIDE_AQUAHQ_SHELLY
	release
	end

MH_FollowerShellyScript::
	compare VAR_RYU_AQUA, 105
	goto_if_eq MH_FollowerShellyPostBoss
	msgbox ShellyOfferHeal MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MH_ShellyHeal
	msgbox MH_ShellyChatter
	closemessage
	end

MH_FollowerShellyPostBoss::
	msgbox MH_ShellyReturnToOffice
	closemessage
	release
	end

MH_ShellyReturnToOffice:
	.string "We really need to get back\nto the office.$"

MH_ShellyHeal::
	special HealPlayerParty
	msgbox MH_ShellyAllBetter
	closemessage
	end

MH_ExitPrevention::
	compare VAR_RYU_MAGMA, 315
	goto_if_eq MH_CheckMagmaExit
	goto_if_set FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, ryu_end
	goto_if_unset FLAG_RYU_DS_SHELLY_CLOSEFRIENDS, ryu_end
	lock
	msgbox MH_Cantleavenotdone
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

	MH_Cantleavenotdone:
	.string "You're not done here yet.$"


MH_ShellyAllBetter:
	.string "{COLOR LIGHT_RED}{SHADOW RED}There. All better.$"

ShellyOfferHeal:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Need a pick-me-up?$"

MH_ShellyChatter:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Man, it's so dry here.\pThis is wreaking havok\non my hair!$"
	
	
MH_ShellyWalk:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
MH_ShellyLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MH_ShellyNoRel:
	.string "Shelly: Good luck. There doesn't\n"
	.string "seem to be any suprises you\p"
	.string "won't be able to handle here.\n"
	.string "Report to me when you've\p"
	.string "finished the job.$"
	
MH_observation:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You notice that she's wearing\n"
	.string " the necklace you gave her. She\p"
	.string " is fiddling with it)\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'll save my strength for when\nwe take on Maxie and his crone.$"
	
MH_Declined::
	.string "Oh... okay.\p"
	.string "Well, I'll leave it in your capable\n"
	.string "hands.....\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She seems a little disappointed.)$"
	
MH_ShellyIntro:
	.string "I see you made it, {PLAYER}.\n"
	.string "I've done some pre-emptive\p"
	.string "scouting. It goes pretty deep\n"
	.string "into the mountain. Maxie is at\p"
	.string "the center, most likely.$"
	
MH_ShellyRelQuery:
	.string "{COLOR LIGHT_RED}{SHADOW RED}So, how about we take down the\n"
	.string "management together? It'll be fun.$"
	
MH_ShellyPreparing:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I'll take the back seat and watch\n"
    .string "you work, then. It really turns\p"
    .string "me on, the way you wreck these\n"
    .string "Magma scrubs.$"
	
@==================================================================================================Magma Scripts

MH_CheckPlayerIsMagma::
	compare VAR_RYU_MAGMA, 301
	goto_if_ge MH_RandomGruntSpeak
	return

MH_CheckMagmaExit::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox MH_Courtney_NotDoneYet
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
MH_CortneyConfirmsDone:
	.string "{COLOR LIGHT_RED}{SHADOW RED}...Task Finished...\p"
	.string "... ... ... \p"
	.string "...fun\p"
	.string "{PLAYER}... not useless...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You see a flicker of a confused\n"
	.string " look on her normally\l"
	.string " expressionless face...)$"

MH_Courtney_NotDoneYet:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Orders incomplete...Return...$"
