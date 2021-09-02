@@Made this its own file cuz it's pretty long.

SlakothVendingMachine::
    lockall
	message SVM_WhichSnackWouldYouLike
	waitmessage
	showmoneybox 0, 0, 0
	goto SVM_ChooseSnack
	end

SVM_ChooseSnack::
	multichoicegrid 0, 4, MULTI_SLAKOTH_VENDING_MACHINE, 2, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SVM_SweetHeart
	case 1, SVM_BerryJuice
	case 2, SVM_MoomooMilk
	case 3, SVM_OldGateau
	case 4, SVM_BigMalasada
	case 5, SVM_BlackTea
	case 6, SVM_LavaCookie
    hidemoneybox
	goto SVM_ExitVendingMachine
	end

SVM_SweetHeart::
    call SVMCommon_CheckSpaceAndMoney
    removemoney 4000
    setvar VAR_TEMP_C, ITEM_SWEET_HEART
    bufferitemname 0, ITEM_SWEET_HEART
    goto SVMCommon_GiveItem

SVM_BerryJuice::  @@I reduced the space this takes by quite a bit.
    call SVMCommon_CheckSpaceAndMoney
    removemoney 1000
    setvar VAR_TEMP_C, ITEM_BERRY_JUICE
    bufferitemname 0, ITEM_BERRY_JUICE  @@I find it less buggy to just buffer the actual items than a variable containing them.
    goto SVMCommon_GiveItem

SVM_MoomooMilk::
    call SVMCommon_CheckSpaceAndMoney
    removemoney 750
    setvar VAR_TEMP_C, ITEM_MOOMOO_MILK
    bufferitemname 0, ITEM_MOOMOO_MILK 
    goto SVMCommon_GiveItem

SVM_OldGateau::
    call SVMCommon_CheckSpaceAndMoney
    removemoney 4000
    setvar VAR_TEMP_C, ITEM_OLD_GATEAU
    bufferitemname 0, ITEM_OLD_GATEAU
    goto SVMCommon_GiveItem

SVM_BigMalasada::
    call SVMCommon_CheckSpaceAndMoney
    removemoney 2000
    setvar VAR_TEMP_C, ITEM_BIG_MALASADA
    bufferitemname 0, ITEM_BIG_MALASADA
    goto SVMCommon_GiveItem

SVM_BlackTea::
    call SVMCommon_CheckSpaceAndMoney
    removemoney 2000
    setvar VAR_TEMP_C, ITEM_TEA
    bufferitemname 0, ITEM_TEA
    goto SVMCommon_GiveItem

SVM_LavaCookie::
    call SVMCommon_CheckSpaceAndMoney
    removemoney 500
    setvar VAR_TEMP_C, ITEM_LAVA_COOKIE
    bufferitemname 0, ITEM_LAVA_COOKIE
    goto SVMCommon_GiveItem

SVMCommon_CheckSpaceAndMoney::
    checkitemspace VAR_TEMP_C, 3
    compare VAR_RESULT, FALSE
    goto_if_eq SVMCommon_NotEnoughPackSpace
    checkmoney 4000
    compare VAR_RESULT, FALSE
    goto_if_eq SVMCommon_CantAfford
    return

SVMCommon_GiveItem::
    additem VAR_TEMP_C, 1
    msgbox SVMCommon_SnackDroppedDown
    random 63
    compare VAR_RESULT, 40 @@1/64 chance (zero indexed) to give a bonus item
    call_if_eq SVM_AdditionalItemDropped
    random 63
    compare VAR_RESULT, 20 @@Further 1/64 chance to give an additional bonus item.
    call_if_eq SVM_AdditionalItemDropped
    hidemoneybox
    goto SVM_ExitVendingMachine

SVM_AdditionalItemDropped::
    msgbox SVM_BonusItemMsg
    closemessage
    additem VAR_TEMP_C, 1
    return

SVMCommon_NotEnoughPackSpace::
    hidemoneybox
    msgbox SVM_NotEnoughSpaceMsg
    closemessage
    release
    end

SVMCommon_CantAfford::
    hidemoneybox
    msgbox SVM_NotEnoughMoneyMsg
    closemessage
    release
    end

SVM_ExitVendingMachine::
    hidemoneybox
    msgbox SVM_ExitedMsg
    closemessage
    release
    end

SVM_NoSelection::
    hidemoneybox
    msgbox SVM_NoSelectionMsg
    closemessage
    release
    end

SVMCommon_SnackDroppedDown:
    .string "Clang!\p"
    .string "{STR_VAR_1} dropped down!$"

SVM_ExitedMsg::
    .string "Finished with the vending machine.$"

SVM_WhichSnackWouldYouLike:
	.string "It's a Vending Machine.\n"
	.string "Which snack would you like?$"

SVM_BonusItemMsg::
    .string "Clang!\p"
	.string "Score! An extra {STR_VAR_1}\n"
	.string "dropped down!$"

SVM_NoSelectionMsg::
    .string "Decided against buying a snack...$"

SVM_NotEnoughMoneyMsg::
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I can't afford it...$"

SVM_NotEnoughSpaceMsg::
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}There's not enough space in the\npack...$"
