@@This is the main fertilizer script file


RyuFert_FertilizerStart::@@put this script on the npc/object you want to activate the script.
    lockall
    msgbox Ryu_FertilizerIntro
    closemessage
    goto RyuFert_SelectFirstBerry

RyuFert_SelectFirstBerry::
    special Bag_ChooseBerry
	waitstate
	compare VAR_ITEM_ID, 0
	goto_if_eq RyuFert_FirstItemNotSelected
	copyvar VAR_TEMP_A, VAR_ITEM_ID
	goto RyuFert_SelectSecondBerry

RyuFert_SelectSecondBerry::
    special Bag_ChooseBerry
	waitstate
	compare VAR_ITEM_ID, 0
	goto_if_eq RyuFert_SecondItemNotSelected
	copyvar VAR_TEMP_B, VAR_ITEM_ID
	goto RyuFert_SelectThirdBerry

RyuFert_SelectThirdBerry::
    special Bag_ChooseBerry
	waitstate
	compare VAR_ITEM_ID, 0
	goto_if_eq RyuFert_ThirdItemNotSelected
	copyvar VAR_TEMP_C, VAR_ITEM_ID
	goto RyuFert_ConfirmSelection

RyuFert_ConfirmSelection::
    call RyuFert_CheckQuantities
    bufferitemname 0, VAR_TEMP_A
    bufferitemname 1, VAR_TEMP_B
    bufferitemname 2, VAR_TEMP_C
    msgbox RyuFert_YouSelected, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq RyuFert_TakeBerriesGiveFert
    goto RyuFert_ExchangeCancelled

RyuFert_CheckQuantities::
    compare_var_to_var VAR_TEMP_A, VAR_TEMP_B
    call_if_eq RyuFert_CheckQuantityOfBerryAandB
    compare_var_to_var VAR_TEMP_B, VAR_TEMP_C
    call_if_eq RyuFert_CheckQuantityOfBerryBandC
    compare_var_to_var VAR_TEMP_A, VAR_TEMP_B
    call_if_eq RyuFert_CheckQuantityOfBerryAandC
    return

RyuFert_CheckQuantityOfBerryAandB::
    checkitem VAR_TEMP_A, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RyuFert_NotEnoughAandB
    return

RyuFert_CheckQuantityOfBerryBandC::
    checkitem VAR_TEMP_B, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RyuFert_NotEnoughBandC
    return

RyuFert_CheckQuantityOfBerryAandC::
    checkitem VAR_TEMP_C, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RyuFert_NotEnoughAandC
    return

RyuFert_TakeBerriesGiveFert::
    removeitem VAR_TEMP_A, 1
    removeitem VAR_TEMP_B, 1
    removeitem VAR_TEMP_C, 1
    giveitem ITEM_FERTILIZER, 1
    goto RyuFert_CheckExchangeAnother

RyuFert_CheckExchangeAnother::
    msgbox RyuFert_CreateAnotherFertilizerQuery, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq RyuFert_SelectFirstBerry
    goto RyuFert_End


RyuFert_NotEnoughAandB::
    bufferitemnameplural 0, VAR_TEMP_A, 2
    msgbox RyuFert_NotEnoughABMessage
    release
    end

RyuFert_NotEnoughBandC::
    bufferitemnameplural 0, VAR_TEMP_B, 2
    msgbox RyuFert_NotEnoughBCMessage
    release
    end

RyuFert_NotEnoughAandC::
    bufferitemnameplural 0, VAR_TEMP_C, 2
    msgbox RyuFert_NotEnoughACMessage
    release
    end

RyuFert_FirstItemNotSelected::
    msgbox RyuFert_NoFirstSelected, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne RyuFert_SelectFirstBerry
    release
    end

RyuFert_SecondItemNotSelected::
    msgbox RyuFert_NoSecondSelected, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne RyuFert_SelectSecondBerry
    release
    end

RyuFert_ThirdItemNotSelected::
    msgbox RyuFert_NoThirdSelected, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne RyuFert_SelectThirdBerry
    release
    end

RyuFert_ExchangeCancelled::
    msgbox RyuFert_PlsReturnWithMore
    closemessage
    release
    end

RyuFert_End::
    releaseall
    end

RyuFert_CreateAnotherFertilizerQuery:
    .string "Would you like to compost\nsome more berries?$"
    
RyuFert_NoFirstSelected:
    .string "You didn't select the first berry.\nCancel?$"

RyuFert_NoSecondSelected:
    .string "You didn't select the second berry.\nCancel?$"

RyuFert_NoThirdSelected:
    .string "You didn't select the third berry.\nCancel?$"

RyuFert_NotEnoughABMessage:
    .string "You don't have enough {STR_VAR_1}.$"

RyuFert_NotEnoughBCMessage:
    .string "You don't have enough {STR_VAR_2}.$"

RyuFert_NotEnoughACMessage:
    .string "You don't have enough {STR_VAR_3}.$"

Ryu_FertilizerIntro:
    .string "Would you like to recycle three\nberries into a Fertilizer?$"

RyuFert_PlsReturnWithMore:
    .string "Come back when you want to\ncompost more berries!$"

RyuFert_YouSelected:
    .string "You selected {STR_VAR_1}, {STR_VAR_2},\nand {STR_VAR_3}.\pWould you like to recycle these\nberries for a fertilizer?$"

