EventScript_RepelWoreOff:: @ 82A4B2A
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	msgbox Text_UseAnotherRepel, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq EventScript_ChooseAnotherRepel
	closemessage
	end

RyuRepel_AppliedAlchemicalRepel::
	buffernumberstring 0, VAR_REPEL_STEP_COUNT
	msgbox RA_RepelMsg
	closemessage
	return

RA_RepelMsg:
	.string "You applied your potent repelling\nsolution. It will last for {STR_VAR_1} steps.$"

EventScript_ChooseAnotherRepel::
	special RyuBufferRepelItemCounts
	multichoicedefault 10, 4, MULTI_OW_REPEL_DLG, 0, 1
	switch VAR_RESULT
	case 0, EventScriptChoseRepel
	case 1, EventScriptChoseSuperRepel
	case 2, EventScriptChoseMaxRepel
	case 3, EventScriptNoChoice
	goto EventScriptNoChoice

EventScriptChoseRepel::
	checkitem ITEM_REPEL, 1
	compare VAR_RESULT, 0
	goto_if_eq EventScriptNoItemInInventory
	removeitem ITEM_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 100
	playse SE_TU_SAA
	waitse
	msgbox EventScript_UsedTheRepel
	release
	end

EventScriptChoseSuperRepel::
	checkitem ITEM_SUPER_REPEL, 1
	compare VAR_RESULT, 0
	goto_if_eq EventScriptNoItemInInventory
	removeitem ITEM_SUPER_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 200
	playse SE_TU_SAA
	waitse
	msgbox EventScript_UsedTheRepel
	release
	end

EventScriptChoseMaxRepel::
	checkitem ITEM_MAX_REPEL, 1
	compare VAR_RESULT, 0
	goto_if_eq EventScriptNoItemInInventory
	removeitem ITEM_MAX_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 250
	playse SE_TU_SAA
	waitse
	msgbox EventScript_UsedTheRepel
	release
	end

EventScriptNoChoice::
	msgbox Text_RepelWasntUsed
	closemessage
	release
	end

EventScript_UsedTheRepel::
	.string "{PLAYER} applied the repellent.$"

EventScriptNoItemInInventory::
	msgbox Text_YouDontHaveAny
	closemessage
	goto EventScript_ChooseAnotherRepel

Text_YouDontHaveAny:
	.string "You don't have any of these.$"

Text_RepelWoreOff: @ 82A4B33
	.string "The repellent's effect wore off…$"

Text_UseAnotherRepel:
	.string "Would you like to use another\nrepellent?$"

Text_RepelWasntUsed:
	.string "{PLAYER} isn't using another repel.$"
