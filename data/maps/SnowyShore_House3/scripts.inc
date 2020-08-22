SnowyShore_House3_MapScripts::
	.byte 0

SnowyShore_House3_EventScript_Man::
	lock
	faceplayer
	msgbox SnowyShore_House3_Text_NotFan, MSGBOX_DEFAULT
	release
	end

SnowyShore_House3_Text_NotFan:
	.string "I am not a big fan of the cold.\p"
	.string "I don't even have hair on top of my\n"
	.string "head to keep me warm…$"
