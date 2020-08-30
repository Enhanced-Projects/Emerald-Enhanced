FrostbiteField_House_MapScripts::
	.byte 0

FrostbiteField_House_EventScript_Woman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FROSTBITE_FIELD_RECEIVED_FERTILIZER, FrostbiteField_House_EventScript_ReceivedFertilizer
	msgbox FrostbiteField_House_Text_TakeSome, MSGBOX_DEFAULT
	giveitem ITEM_FERTILIZER
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FROSTBITE_FIELD_RECEIVED_FERTILIZER
	end

FrostbiteField_House_EventScript_ReceivedFertilizer::
	msgbox FrostbiteField_House_Text_IllMakeMore, MSGBOX_DEFAULT
	release
	end

FrostbiteField_House_Text_TakeSome:
	.string "Here, take some Fertilizer.\n"
	.string "It makes your berries grow fast.$"

FrostbiteField_House_Text_IllMakeMore:
	.string "I'll make more Fertilizer tomorrow.$"
