MtFreeze_1F_MapScripts::
	.byte 0

MtFreeze_1F_EventScript_LadderSign::
	msgbox MtFreeze_1F_TextLadderSign, MSGBOX_SIGN
	end

MtFreeze_1F_TextLadderSign:
	.string "Warning: this long ladder leads to\n"
	.string "the heart of the volcano.\p"
	.string "Thermal protection is advised.$"
