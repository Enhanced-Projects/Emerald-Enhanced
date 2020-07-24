PacifidlogTown_House1_MapScripts:: @ 820365C
	.byte 0

PacifidlogTown_House1_EventScript_Man:: @ 820365D
	compare VAR_RYU_DS_LANA_STAGE, 30
	call_if_eq PT_Npc
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end
	
PT_Npc::
	msgbox PT_NpcChatter MSGBOX_DEFAULT
	return

PacifidlogTown_House1_EventScript_Woman:: @ 8203666
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory: @ 820366F
	.string "In the Hoenn region, there are three\n"
	.string "Pokémon that represent the power of\l"
	.string "rock, ice, and steel.\p"
	.string "Each of them is said to hide away deep\n"
	.string "inside caves.\p"
	.string "That's the story I heard when I was\n"
	.string "just a little kid.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors: @ 820373A
	.string "“Six dots open three doors.”\p"
	.string "Grandpa used to say that, but I don't\n"
	.string "know what he meant.$"
	
@Lana Events

PT_LanaEvent1::
	msgbox PT_LanaMsg MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceRight
	waitmovement 3
	applymovement 3, PT_LanaLeaves
	waitmovement 3
	playse SE_DOOR
	removeobject 3
	msgbox PT_PlayerMsg MSGBOX_DEFAULT
	setvar VAR_RYU_DS_LANA_STAGE, 30
	setflag FLAG_HIDE_PCF_TOWN_LANA
	setflag FLAG_SYS_BRAILLE_DIG
	release
	end

PT_NpcChatter:
	.string "That girl traded for my Relicanth...\pI'd say I got the\nbetter deal, but I can't shake the\lfeeling I've been outplayed...\pI mean, what's Relicanth useful\lfor anyway?\pBy the way...$"

	
PT_LanaMsg:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: Hey, Lana, what's going on?\pThese notes you've left behind are\ngetting me worried...\p{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ...\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You see her scribbling on a piece\n of paper before handing it to you...)$"
	
PT_PlayerMsg:
	.string "{PLAYER} looks at the note.\nThe note says:\p{COLOR LIGHT_RED}{SHADOW RED}Worried? Why can't you see?\nThere's no reason to be...\pFor someone like me...\nWe should go our separate ways...\pI wonder if you'll find me through\nthis underwater maze...$"
	
PT_LanaLeaves:
	walk_in_place_fast_right
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
