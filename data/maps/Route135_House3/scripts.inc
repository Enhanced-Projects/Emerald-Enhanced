Route135_House3_MapScripts::
	.byte 0

Route135_House3_EventScript_EggMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM58, Route135_House3_EventScript_ReceivedFlash
	msgbox Route135_House3_Text_ReunitedWithParent, MSGBOX_DEFAULT
	giveitem ITEM_TM58
	setflag FLAG_RECEIVED_TM58
	msgbox Route135_House3_Text_ExplainDive, MSGBOX_DEFAULT
	release
	end

Route135_House3_EventScript_ReceivedFlash::
	msgbox Route135_House3_Text_ExplainDive, MSGBOX_DEFAULT
	release
	end

Route135_House3_Text_ReunitedWithParent:
	.string "Hey, did you find anything?\p"
	.string "Ah, you reunited the egg with\n"
	.string "its parent.\p"
	.string "Thanks for helping me out, here\n"
	.string "is a gift!$"

Route135_House3_Text_ExplainDive:
	.string "Teach that move to a defensive\n"
	.string "Water pokemon, and spread some\l"
	.string "paralysis around!$"

