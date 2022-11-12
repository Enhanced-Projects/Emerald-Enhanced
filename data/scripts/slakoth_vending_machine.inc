@@Made this its own file cuz it's pretty long.

SlakothVendingMachine::
    lockall
    callnative Ryu_SVM_CheckDailyQuota
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
    setvar VAR_0x8002, 4000
    setvar VAR_TEMP_C, ITEM_SWEET_HEART
    call SVMCommon_ChooseQuantity
    call SVMCommon_CheckSpaceAndMoney
    bufferitemname 0, ITEM_SWEET_HEART
    goto SVMCommon_GiveItem

SVM_BerryJuice::
    setvar VAR_TEMP_C, ITEM_BERRY_JUICE
    setvar VAR_0x8002, 1000
    call SVMCommon_ChooseQuantity
    call SVMCommon_CheckSpaceAndMoney
    bufferitemname 0, ITEM_BERRY_JUICE
    goto SVMCommon_GiveItem

SVM_MoomooMilk::
    setvar VAR_0x8002, 750
    setvar VAR_TEMP_C, ITEM_MOOMOO_MILK
    call SVMCommon_ChooseQuantity
    call SVMCommon_CheckSpaceAndMoney
    bufferitemname 0, ITEM_MOOMOO_MILK 
    goto SVMCommon_GiveItem

SVM_OldGateau::
    setvar VAR_0x8002, 4000
    setvar VAR_TEMP_C, ITEM_OLD_GATEAU
    call SVMCommon_ChooseQuantity
    call SVMCommon_CheckSpaceAndMoney
    bufferitemname 0, ITEM_OLD_GATEAU
    goto SVMCommon_GiveItem

SVM_BigMalasada::
    setvar VAR_TEMP_C, ITEM_BIG_MALASADA
    setvar VAR_0x8002, 2000
    call SVMCommon_ChooseQuantity
    call SVMCommon_CheckSpaceAndMoney
    bufferitemname 0, ITEM_BIG_MALASADA
    goto SVMCommon_GiveItem

SVM_BlackTea:: 
    setvar VAR_TEMP_C, ITEM_TEA
    setvar VAR_0x8002, 2000
    call SVMCommon_ChooseQuantity
    call SVMCommon_CheckSpaceAndMoney
    bufferitemname 0, ITEM_TEA
    goto SVMCommon_GiveItem

SVM_LavaCookie::
    setvar VAR_0x8002, 500
    setvar VAR_TEMP_C, ITEM_LAVA_COOKIE
    call SVMCommon_ChooseQuantity
    call SVMCommon_CheckSpaceAndMoney
    bufferitemname 0, ITEM_LAVA_COOKIE
    goto SVMCommon_GiveItem

SVMCommon_CheckSpaceAndMoney::
    checkitemspace VAR_TEMP_C, VAR_0x8003
    compare VAR_RESULT, FALSE
    goto_if_eq SVMCommon_NotEnoughPackSpace
    callnative Ryu_SVM_CheckQuantityCost
    compare VAR_RESULT, FALSE
    goto_if_eq SVMCommon_CantAfford
    return

SVMCommon_ChooseQuantity::
    numberentry 0, 9, 2
    copyvar VAR_0x8003, VAR_RESULT
    compare VAR_0x8003, 20
    goto_if_gt SVMCommon_NotEnoughStock
    compare VAR_RYU_DAILY_VENDING_MACHINE_PURCHASES, 50
    goto_if_ge SVMCommon_QuotaReached
    callnative Ryu_SVM_CheckQuantityExceedsQuota
    compare VAR_0x8004, 666
    goto_if_eq SVMCommon_NotEnoughStockOfSelectedItem
    return

SVMCommon_GiveItem::
    buffernumberstring 0, VAR_0x8003 @quantity
    bufferitemname 1, VAR_TEMP_C @ item
    msgbox SVM_TransactionQuery, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SlakothVendingMachine
    additem VAR_TEMP_C, VAR_0x8003
    msgbox SVMCommon_SnackDroppedDown
    callnative Ryu_SVM_TakeMoney
    updatemoneybox 0, 0
    msgbox SVMCommonAnotherTransaction, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq SlakothVendingMachine
    goto SVM_ExitVendingMachine

SVMCommon_NotEnoughStockOfSelectedItem::
    msgbox SVM_NES1
    setvar VAR_0x8004, 0
    goto SlakothVendingMachine

SVMCommon_NotEnoughStock::
    hidemoneybox
    bufferitemname 1, VAR_TEMP_C
    msgbox SVM_NotEnoughStockMsg
    closemessage
    goto SlakothVendingMachine

SVMCommon_QuotaReached::
    hidemoneybox
    nop
    msgbox SVM_SoldOut
    goto ryu_end

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

SVM_NES1:
    .string "The machine doesn't have that many\nof the item.\pPlease Try Again.$"

SVM_TransactionQuery:
    .string "{STR_VAR_1} {STR_VAR_2}'s will cost {STR_VAR_3}.\nIs this transaction okay?$"

SVMCommon_SnackDroppedDown:
    .string "Clang!\p"
    .string "{STR_VAR_1} {STR_VAR_2}'s dropped down!$"

SVM_NotEnoughStockMsg:
    .string "The machine can't vend more than\n20 of an item at once.$"

SVM_ExitedMsg::
    .string "Finished with the vending machine.$"

SVM_SoldOut:
    .string "The vending machine is sold out...\pIt says to check tomorrow.$"

SVMCommonAnotherTransaction:
    .string "Buy more from the machine?$"

SVM_WhichSnackWouldYouLike:
	.string "The machine has {RYU_STR_1} items in stock.\n"
	.string "Choose an item.$"

SVM_NoSelectionMsg::
    .string "Decided against buying a snack...$"

SVM_NotEnoughMoneyMsg::
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I can't afford it...\p{COLOR LIGHT_GREEN}{SHADOW GREEN} (Total Cost: {STR_VAR_3})$"

SVM_NotEnoughSpaceMsg::
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}There's not enough space in the\npack...$"
