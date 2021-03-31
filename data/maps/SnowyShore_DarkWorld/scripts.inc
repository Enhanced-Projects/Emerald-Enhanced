SnowyShore_DarkWorld_MapScripts::
	.byte 0

SnowyShore_DarkWorld_EventScript_TownSign::
	msgbox SnowyShore_Text_TownSign, MSGBOX_SIGN
	end

SnowyShore_DarkWorld_Text_TownSign:
	.string "Basalt Burg\n"
	.string "“Treasure the treacherous”$"

SnowyShore_DarkWorld_EventScript_Beauty::
	lock
	faceplayer
	msgbox SnowyShore_DarkWorld_Text_MyGarden, MSGBOX_DEFAULT
	release
	end

SnowyShore_DarkWorld_Text_MyGarden:
	.string "I'm trying to take care of my garden,\n"
	.string "but these rocks keep showing up…$"

SnowyShore_DarkWorld_EventScript_OldWoman::
	lock
	faceplayer
	msgbox SnowyShore_DarkWorld_Text_LookPeculiar, MSGBOX_DEFAULT
	release
	end

SnowyShore_DarkWorld_Text_LookPeculiar:
	.string "Thou look peculiar, wearing such\n"
	.string "exotic apparel.$"

SnowyShore_DarkWorld_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox SnowyShore_DarkWorld_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SnowyShore_DarkWorld_Text_Zigzagoon:
	.string "Zigzagoon: Guguguuu!$"
