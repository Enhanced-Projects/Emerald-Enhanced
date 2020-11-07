GraniteCave_StevensRoom_MapScripts:: @ 822DC7A
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven:: @ 822DC7B
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setvar VAR_RYU_DEVON, 16 @Player delivered letter, go to the oceanic museum to meet stern.
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	additem ITEM_TM47
	compare VAR_RESULT, FALSE
	call_if_eq GraniteCave_StevensRoom_EventScript_BagFull
	playfanfare MUS_ME_TORE_EYE
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitNorth
	compare VAR_FACING, DIR_SOUTH
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	compare VAR_FACING, DIR_EAST
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_KAIDAN
	setflag FLAG_HIDE_GRANITE_CAVE_STEVEN
	removeobject 1
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth:: @ 822DD0D
	applymovement 1, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast:: @ 822DD18
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement 1, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth:: @ 822DD2A
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement 1, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull:: @ 822DD3C
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit: @ 822DD45
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit: @ 822DD4C
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth: @ 822DD51
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe: @ 822DD5A
	.string "My name is Steven.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A letter for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis: @ 822DDBD
	.string "Steven: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "Steel Wing.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister: @ 822DE6B
	.string "Steven: Your Pokémon appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the Champion of the Pokémon\l"
	.string "League one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our Pokénavs.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven: @ 822DF6A
	.string "Registered Steven\n"
	.string "in the Pokénav.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong: @ 822DF8C
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_OhBagIsFull: @ 822DFAA
	.string "Oh, your Pack is full…\n"
	.string "That's too bad, then.$"

GC_JIRACHI_ENC::
    goto_if_unset FLAG_SYS_GAME_CLEAR, GC1_NOTWORTHY
    goto_if_set FLAG_RYU_JIRACHI, GC1_RYUSCR2
	msgbox GC1_RYUMSG_TOUCHQ, MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_ne GC1_RYUSCR3
	msgbox GC1_RYUMSG_TOUCHED
	playmoncry SPECIES_JIRACHI, 0
	closemessage
	delay 10
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 40, ITEM_SACHET
	setflag FLAG_RYU_JIRACHI
	special BattleSetup_StartLegendaryBattle
	waitstate
	releaseall
	end
	
GC1_NOTWORTHY::
	msgbox GC1_NotAvailable MSGBOX_DEFAULT
	release
	end

GC1_NotAvailable:
    .string "The wall sparkles strangely.$"

GC1_RYUSCR2::
    msgbox GC1_RYUMSG_DEAD MSGBOX_DEFAULT
	closemessage
	releaseall
	end

GC1_RYUSCR3::
    msgbox GC1_RYUMSG_NOTOUCH MSGBOX_DEFAULT
	closemessage
	releaseall
	end

GC1_RYUMSG_TOUCHQ:
    .string "This wall sparkles beautifully, as if\n"
	.string "it was touched by a sky spirit.\p"
	.string "Touch the wall?$"

GC1_RYUMSG_DEAD:
    .string "The wall shows ancient text.$"

GC1_RYUMSG_NOTOUCH:
    .string "Seems too creepy.$"

GC1_RYUMSG_TOUCHED:
    .string "{PLAYER} touched the wall.\p"
	.string "You hear the sound of stardust falling.$"

