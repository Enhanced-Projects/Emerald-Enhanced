Route103_MapScripts:: @ 81EC38E
	map_script ON_TRANSITION, Route103_OnTransition
	map_script ON_LOAD , Route103_OnLoad
	.byte 0

Route103_OnTransition: @ 81EC399
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad: @ 81EC3A4
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave:: @ 81EC3AE
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, 1
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, 0
	return

Route103_EventScript_Rival:: @ 81EC3C1
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_RivalMay
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_RivalBrendan
	end

Route103_EventScript_RivalMay:: @ 81EC3DA
	msgbox r103_femaleRivalTalkSelf, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_GIRL_SUP, 1
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox r103_femaleRivalIntro, MSGBOX_DEFAULT
	closemessage
	goto r103_femaleRivalBattle
	end

Route103_EventScript_RivalBrendan:: @ 81EC434
	msgbox r103_maleRivalTalkSelf, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BOY_SUP, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0	
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGBRENDAN
	msgbox r103_maleRivalIntro, MSGBOX_DEFAULT
	closemessage
	clearfullscreenimage
	fadescreen FADE_TO_BLACK
	goto r103_maleRivalBattle
	end

r103_femaleRivalBattle:: @ 81EC48E
	trainerbattle_no_intro TRAINER_DAWN_1, r103_femaleRivalDefeat
	goto Route103_EventScript_AfterMayBattle
	end

r103_maleRivalBattle:: @ 81EC49E
	trainerbattle_no_intro TRAINER_BRENDAN_1, r103_maleRivalDefeatText
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle:: @ 81EC4EE
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	msgbox r103_femaleRivalChat, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	closemessage
	end

Route103_EventScript_AfterBrendanBattle:: @ 81EC4FC	
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGBRENDAN
	msgbox r103_maleRivalChat, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit:: @ 81EC50A
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth:: @ 81EC53D
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement 2, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	applymovement 2, Route103_EventScript_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest:: @ 81EC561
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement 2, Route103_Movement_RivalExit1
	waitmovement 0
	applymovement 2, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth:: @ 81EC585
	applymovement 2, Route103_Movement_RivalExit1
	waitmovement 0
	applymovement 2, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd:: @ 81EC5A2
	removeobject 2
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1: @ 81EC5BE
	walk_left
	walk_down
	step_end

Route103_EventScript_RivalExitFacingNorth2: @ 81EC5C1
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth: @ 81EC5C8
	delay_16
	delay_4
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_Movement_RivalExit1: @ 81EC5CE
	walk_down
	step_end

Route103_Movement_RivalExit2: @ 81EC5D0
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest: @ 81EC5D6
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_EventScript_Boy:: @ 81EC5D9
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man:: @ 81EC5E2
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign:: @ 81EC5EB
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy:: @ 81EC5F4
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy:: @ 81EC60B
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle:: @ 81EC63A
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	@nop Trainer_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch:: @ 81EC653
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv:: @ 81EC66E
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle:: @ 81EC69D
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	@nop Trainer_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch:: @ 81EC6B6
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew:: @ 81EC6D1
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel:: @ 81EC6E8
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle:: @ 81EC714
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	@nop Trainer_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch:: @ 81EC733
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos:: @ 81EC74A
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett:: @ 81EC761
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete:: @ 81EC778
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle:: @ 81EC78F
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

r103_femaleRivalTalkSelf: @ 81EC7A6
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: Let's see… The Pokémon found\n"
	.string "on Route 103 include…$"

r103_femaleRivalIntro: @ 81EC7DE
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh, hi, {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}!\p"
	.string "It seems like you decided to become\n"
	.string "a Pokémon Trainer. That's awesome.\l"
	.string "I didn't have any friends, so it's\l"
	.string "nice to have someone who's doing\l"
	.string "the same thing as me.\l"
	.string "Let's have a battle for fun!$"

r103_femaleRivalDefeat: @ 81EC881
	.string "Wow! It's like you were born to be\n"
	.string "a trainer. I think we're going to\l"
	.string "be great friends.$"

r103_femaleRivalChat: @ 81EC8AE
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: I think I know why your\n"
	.string "Pokémon likes you already. It tried\l"
	.string "really hard for you. I hope you\l"
	.string "continue to grow with your Pokémon.\l"
	.string "Let's head back to the lab!$"

r103_maleRivalTalkSelf: @ 81EC989
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: Okay, so it's this one and\n"
	.string "that one that live on Route 103…$"

r103_maleRivalIntro: @ 81EC9CE
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: Hey there, {PLAYER}!\p{COLOR LIGHT_BLUE}{SHADOW BLUE}…Oh, yeah?\nSo Dad gave you a Pokémon.\pWell since we're here, how about\na little battle?\pI'll teach you what being a trainer's\nall about!$"

r103_maleRivalDefeatText: @ 81ECA59
	.string "Huh, {PLAYER}, you're not too shabby.$"

r103_maleRivalChat: @ 81ECA79
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your Pokémon already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}, I get the feeling that you\n"
	.string "could befriend any Pokémon with ease.\p"
	.string "We should head back to the lab.$"

Route103_Text_ShouldHaveBroughtPotion: @ 81ECB73
	.string "My Pokémon is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale: @ 81ECBB5
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign: @ 81ECC1A
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"


@==================================================================================================DEBUG

r103_SpecialBattleTest::
	choose_mons
	multi_2_vs_2 TRAINER_WALLACE, Text1, TRAINER_SIDNEY, Text2, TRAINER_REL_MINNIE, TRAINER_BACK_PIC_MINNIE
	releaseall
	end

Text1:
	.string "testing multi 2v2$"

Text2:
	.string "You win$"


dawnhi:
	.string "$"
	
@-=================================================================================================Magma meeting 3

r103_MagmaMeeting3_TopRight::
	compare VAR_RYU_MAGMA, 225
	goto_if_ge ryu_end
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	goto R103_MagmaMeeting3Main

r103_MagmaMeeting3_Top::
	compare VAR_RYU_MAGMA, 225
	goto_if_ge ryu_end
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	goto R103_MagmaMeeting3Main

r103_MagmaMeeting3_Bottom::
	compare VAR_RYU_MAGMA, 225
	goto_if_ge ryu_end
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	goto R103_MagmaMeeting3Main

r103_MagmaMeeting3_BottomRight::
	compare VAR_RYU_MAGMA, 225
	goto_if_ge ryu_end
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	goto R103_MagmaMeeting3Main
	
R103_MagmaMeeting3Main::
	setvar VAR_RYU_MAGMA, 220@Third Meeting prior to heist completed
	applymovement 25, Common_Movement_FaceRight
	waitmovement 25
	msgbox R103_YouYoureAgent
	closemessage
	applymovement 25, Common_Movement_FaceUp
	waitmovement 25
	msgbox R103_SoHeresThe
	closemessage
	applymovement 25, Common_Movement_FaceRight
	waitmovement 25
	msgbox R103_ThatsWhereYou
	closemessage
	applymovement 22, Common_Movement_FaceRight
	waitmovement 22
	msgbox R103_WhereDoWe
	closemessage
	applymovement 25, Common_Movement_FaceUp
	applymovement 24, Common_Movement_FaceLeft
	waitmovement 24
	msgbox R103_OurOnlyOption
	closemessage
	applymovement 25, Common_Movement_FaceRight
	waitmovement 25
	msgbox R103_AllSetPlayer
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_RYU_HIDE_103_MAGMA_MEETING
	removeobject 22
	removeobject 23
	removeobject 24
	removeobject 25
	fadescreen FADE_FROM_BLACK
	setvar VAR_RYU_MAGMA, 225@Heist Initialized
	setflag FLAG_RYU_BANNED_FROM_OLDALE
	applymovement OBJ_EVENT_ID_PLAYER, OT_MoveIntoPlace
	waitmovement OBJ_EVENT_ID_PLAYER
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	release
	end
	
OT_NotDone:
	.string "You haven't finished your task.\nYou can't leave.$"
	
R103_YouYoureAgent:
	.string "You...you're Agent {PLAYER}, right?\n"
    .string "Thought you were too much of a\p"
    .string "hotshot to join us grunts...seems I\n"
    .string "was wrong. Security's been tight\p"
    .string "nowadays, so we could use the help.$"

R103_SoHeresThe:
	.string "So, here's the plan: Our target's\n"
    .string "Oldale Town's Mart. Having the store\p"
    .string "owner give up the goods is a walk in\n"
    .string "the park. The issue is the guard\p"
    .string "they've recently employed out front\n"
    .string "an effort to combat the surge in\p"
    .string "crime. The pokémon they have are\n"
    .string "fairly strong. Us grunts can't handle\p"
    .string "them at our current level and rank.$"

R103_ThatsWhereYou:
	.string "That's where you come in, {PLAYER}.\n"
    .string "You subdue the guard, while we go in\p"
    .string "and grab the goods. And don't worry,\n"
    .string "you'll get your share of the profits.$"

R103_WhereDoWe:
	.string "Where do we go once we got what we\n"
    .string "came for? Up here's a dead end.$"

R103_OurOnlyOption:
    .string "Our only option is to head west thru\n"
    .string "Petalburg...it's a risk for sure, but\p"
    .string "if we can make it to the Sea Cottage,\n"
    .string "we all can hitch a ride on the boat\p"
    .string "there and sail away from danger.$"

R103_AllSetPlayer:
	.string "All set, {PLAYER}? Go ahead and do\n"
    .string "your thing. We'll make our move once\p"
    .string "you get rid of the guard.$"
	
OT_MoveIntoPlace:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
