SnowyShore_House2_MapScripts::
	.byte 0

SnowyShore_House2_EventScript_LeftGirl::
	lock
	faceplayer
	msgbox SnowyShore_House2_Text_IfYouMake, MSGBOX_DEFAULT
	release
	end

SnowyShore_House2_Text_IfYouMake:
	.string "If you make fertilizer with berries,\n"
	.string "you can make berry trees grow fast.\p"
	.string "It is very useful for berries that\n"
	.string "take a long time to grow.$"

SnowyShore_House2_EventScript_RightGirl::
	lock
	faceplayer
	@ composting script
	release
	end
