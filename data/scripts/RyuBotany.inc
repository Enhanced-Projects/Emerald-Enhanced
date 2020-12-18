@Scripts for the botany skill

@The main script called when using cut on grass
RyuScript_FieldCut::
    setvar VAR_TEMP_5, 1
    compare VAR_RESULT, TRUE
    call_if_eq RyuBotany_DoubleRewardHC
    delay 60
    switch VAR_RYU_PLAYER_BOTANY_SKILL
    case 1, RyuBotanyGrass_GiveOneItem
    case 3, RyuBotanyGrass_TryGive2Items
    case 5, RyuBotanyGrass_TryGive3Items
    goto ryu_end
    end

RyuBotanyGiveTreeRewardItem::
    switch VAR_RYU_PLAYER_BOTANY_SKILL
    case 1, RyuBotanyTree_GiveOneItem
    case 3, RyuBotanyTree_TryGive2Items
    case 5, RyuBotanyTree_TryGive3Items
    goto ryu_end


@the script called when cutting trees
RyuBotany_CheckTreeRewardItem::
    random 4
    compare VAR_RESULT, 2 @25% chance to get nothing from trees
    goto_if_le RyuBotanyGiveTreeRewardItem
    release
    end

RyuBotany_DoubleRewardHC::
    random 2
    compare VAR_RESULT, 1
    goto_if_eq ryu_return
    setvar VAR_TEMP_5, 2
    return

RyuBotanyTree_GiveOneItem::
    callnative BotanyTreeChop
    giveitem VAR_TEMP_0, 1
    closemessage
    return

RyuBotanyGrass_GiveOneItem::
    callnative BotanyCheck
    setvar VAR_TEMP_5, 1
    call_if_set FLAG_BOTANY_HAS_HYPER_CUTTER, RyuBotany_DoubleRewardHC
    additem VAR_TEMP_0, VAR_TEMP_5
    bufferitemname 0, VAR_TEMP_0
    buffernumberstring 1, VAR_TEMP_5
    msgbox RyuBotany_RewardMessage
    closemessage
    return

RyuBotany_RewardMessage:
    .string "Obtained {STR_VAR_2} {STR_VAR_1}(s)$"

RyuBotanyTree_TryGive2Items::
    call RyuBotanyTree_GiveOneItem
    random 2
    compare VAR_RESULT, 1 @50% chance to get one bonus roll at rank 3
    call_if_eq RyuBotanyTree_GiveOneItem
    release
    end

RyuBotanyTree_TryGive3Items::
    call RyuBotanyGrass_GiveOneItem
    random 2
    compare VAR_RESULT, 1
    call_if_eq RyuBotanyGrass_GiveOneItem
    random 4
    compare VAR_RESULT, 1 @25% chance to get a 3rd bonus roll at rank 5.
    call_if_eq RyuBotanyGrass_GiveOneItem
    release
    end

RyuBotanyGrass_TryGive2Items::
    call RyuBotanyGrass_GiveOneItem
    random 2
    compare VAR_RESULT, 1 @50% chance to get one bonus roll at rank 3
    call_if_eq RyuBotanyGrass_GiveOneItem
    release
    end

RyuBotanyGrass_TryGive3Items::
    call RyuBotanyGrass_GiveOneItem
    random 2
    compare VAR_RESULT, 1
    call_if_eq RyuBotanyGrass_GiveOneItem
    random 4
    compare VAR_RESULT, 1 @25% chance to get a 3rd bonus roll.
    call_if_eq RyuBotanyGrass_GiveOneItem
    release
    end

RyuBotany_LevelOne::
    additem VAR_TEMP_0, VAR_TEMP_5
    bufferitemname 0, VAR_TEMP_0
    msgbox RyuBotany_Obtained1Item
    closemessage
    addvars VAR_RYU_PLAYER_BOTANY_SKILL_EXP, VAR_RYU_PLAYER_BOTANY_SKILL@Player gains 1 exp per level of botany per botany check.
    call RyuBotany_CheckLevelUp
    release
    end

RyuBotany_LevelThree::
    additem VAR_TEMP_0, VAR_TEMP_5
    additem VAR_TEMP_1, VAR_TEMP_5
    additem VAR_TEMP_2, VAR_TEMP_5
    bufferitemname 0, VAR_TEMP_0
    bufferitemname 1, VAR_TEMP_1
    bufferitemname 2, VAR_TEMP_2
    msgbox RyuBotany_Obtained3Items
    closemessage
    addvars VAR_RYU_PLAYER_BOTANY_SKILL_EXP, VAR_RYU_PLAYER_BOTANY_SKILL@Player gains 1 exp per level of botany per botany check.
    call RyuBotany_CheckLevelUp
    release
    end

RyuBotany_LevelFive::
    additem VAR_TEMP_0, VAR_TEMP_5
    bufferitemname 0, VAR_TEMP_0
    msgbox RyuBotany_Obtained5Items
    closemessage
    addvars VAR_RYU_PLAYER_BOTANY_SKILL_EXP, VAR_RYU_PLAYER_BOTANY_SKILL@Player gains 1 exp per level of botany per botany check.
    call RyuBotany_CheckLevelUp
    release
    end

RyuBotany_CheckLevelUp::
    switch VAR_RYU_PLAYER_BOTANY_SKILL
    case 0, ryu_end
    case 1, RyuBotany_CheckLevel1Progress
    case 2, RyuBotany_CheckLevel2Progress
    case 3, RyuBotany_CheckLevel3Progress
    case 4, RyuBotany_CheckLevel4Progress
    case 5, ryu_end
    goto ryu_end

RyuBotany_CheckLevel1Progress::
    compare VAR_RYU_PLAYER_BOTANY_SKILL_EXP, 50
    goto_if_lt ryu_end
    addvar VAR_RYU_PLAYER_BOTANY_SKILL, 1
    release
    end

RyuBotany_CheckLevel2Progress::
    compare VAR_RYU_PLAYER_BOTANY_SKILL_EXP, 150
    goto_if_lt ryu_end
    addvar VAR_RYU_PLAYER_BOTANY_SKILL, 1
    release
    end

RyuBotany_CheckLevel3Progress::
    compare VAR_RYU_PLAYER_BOTANY_SKILL_EXP, 320
    goto_if_lt ryu_end
    addvar VAR_RYU_PLAYER_BOTANY_SKILL, 1
    release
    end

RyuBotany_CheckLevel4Progress::
    compare VAR_RYU_PLAYER_BOTANY_SKILL_EXP, 500
    goto_if_lt ryu_end
    addvar VAR_RYU_PLAYER_BOTANY_SKILL, 1
    release
    end

RyuBotanyRecipeBookScript::
    lock
    msgbox RB_WhichChapter
    multichoice 18, 4, MULTI_BOTANY_CHAPTER_SELECT, 0
    switch VAR_RESULT
    case 0, RB_ShowConsumablesChapter
    case 1, RB_ShowMedicinesChapter
    case 2, RB_ShowEvolutionChapter
    goto ryu_end

RB_DB_MSG1:
    .string "Resulting item is {STR_VAR_1}.$"

RB_ShowConsumablesChapter::
    msgbox RB_WhichRecipe
    scrollingmultichoice SCROLLINGMULTICHOICE_BOTANYCONSUMABLECHAPTER, 0, 2, 5, 1
    trycraftingrecipe VAR_RESULT
    goto RB_CheckCraftingResult

RB_ShowMedicinesChapter::
    msgbox RB_WhichRecipe
    scrollingmultichoice SCROLLINGMULTICHOICE_BOTANYMEDICINECHAPTER, 0, 2, 5, 1
    addvar VAR_RESULT, NUM_CONSUMABLE_RECIPES
    trycraftingrecipe VAR_RESULT
    goto RB_CheckCraftingResult

RB_ShowEvolutionChapter::
    msgbox RB_WhichRecipe
    scrollingmultichoice SCROLLINGMULTICHOICE_BOTANYEVOLUTIONCHAPTER, 0, 2, 5, 1
    addvar VAR_RESULT, NUM_CONSUMABLE_RECIPES
    addvar VAR_RESULT, NUM_MEDICINE_RECIPES
    trycraftingrecipe VAR_RESULT
    goto RB_CheckCraftingResult

RB_CheckCraftingResult::
    buffernumberstring 0, VAR_TEMP_C
    scriptdebug RB_DB_MSG1
    switch VAR_TEMP_C
    case 0, RB_RecipeFailed
    case 2000, RB_NotEnoughSpaceForResult
    case 4000, RB_MissingSomething
    case 8000, RB_NeedMoreOfSomething
    additem VAR_TEMP_C, 1
    bufferitemname 0, VAR_TEMP_C
    playfanfare MUS_FANFA1
    msgbox RB_Success
    release
    end

RB_RecipeFailed::
    msgbox RB_Error
    closemessage
    release
    end

RB_MissingSomething::
    msgbox RB_SeemToBeMissingSomething
    closemessage
    release
    end

RB_NeedMoreOfSomething::
    msgbox RB_SeemToNeedMoreOfSomething
    closemessage
    release
    end

RB_NotEnoughSpaceForResult::
    msgbox RB_NeedMoreSpace
    closemessage
    release
    end

RB_Error:
    .string "{COLOR LIGHT_RED}{SHADOW RED}There was an error crafting this recipe.$"

RB_NeedMoreSpace::
    .string "You don't have enough space for\nthe item you're trying to craft.$"

RB_SeemToBeMissingSomething:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} You seem to be missing something...$"

RB_SeemToNeedMoreOfSomething:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}The mixture appears to be right,\nbut you seem to need more of\lsomething...$"

RB_WhichChapter:
    .string "Open which chapter?$"

RB_Success:
    .string "You successfully crafted one\n{STR_VAR_1}!$"

RB_YouSelected:
    .string "You selected option number {STR_VAR_1}.$"

RB_WhichRecipe:
    .string "Which recipe would you like to\ncraft?$"

RyuBotany_Obtained1Item:
    .string "You obtained a {STR_VAR_1}.$"

RyuBotany_Obtained2Items:
    .string "You obtained {STR_VAR_1} and {STR_VAR_2}.$"

RyuBotany_Obtained3Items:
    .string "You obtained these items:\n{STR_VAR_1}, {STR_VAR_2}, and {STR_VAR_3}.$"

RyuBotany_Obtained4Items:
    .string "You obtained these items:\n{STR_VAR_1}, {STR_VAR_2},\n{STR_VAR_3}, and {RYU_STR_1}.$"

RyuBotany_Obtained5Items:
    .string "You obtained the following items:\p{STR_VAR_1}, {STR_VAR_2}, {STR_VAR_3},\n {RYU_STR_1}, {RYU_STR_2}.$"


@Apricorn ball maker

RyuBotany_ApricornBallCrafter::  @Add this script to the npc you want to craft balls out of apricorns
    msgbox RB_SeeApricornMenuQuery, MSGBOX_YESNO
    compare VAR_RESULT, YES
    call_if_eq RB_BallMenu
    msgbox RB_RefineApricornIntro
    closemessage
    setvar VAR_TEMP_B, 1000
    checkmoney VAR_TEMP_B
    compare VAR_RESULT, FALSE
    goto_if_eq RB_CantAfford
    callnative RyuBufferNumApricornsForMenu
    multichoicedefault 0, 0, MULTI_BOTANY_APRICORN_MENU, 7, 0
    switch VAR_RESULT
    case 0, RB_RefineRedApcn
    case 1, RB_RefineBlueApcn
    case 2, RB_RefineYellowApcn
    case 3, RB_RefineGreenApcn
    case 4, RB_RefinePinkApcn
    case 5, RB_RefineWhiteApcn
    case 6, RB_RefineBlackApcn
    goto RB_CancelRefineApcn

RB_BallMenu::
    drawinfobox INFOBOXAPCNBALLMENU
    msgbox RB_PressBToReturn
    closemessage
    removeinfobox
    return

RB_RefineRedApcn::
    checkitem ITEM_RED_APRICORN, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RB_NotEnoughApricorns
    removeitem ITEM_RED_APRICORN, 2
    additem ITEM_LEVEL_BALL, 1
    bufferitemname 0, ITEM_LEVEL_BALL
    goto RB_FinishRefining

RB_RefineBlueApcn::
    checkitem ITEM_BLUE_APRICORN, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RB_NotEnoughApricorns
    removeitem ITEM_BLUE_APRICORN, 2
    additem ITEM_LURE_BALL, 1
    bufferitemname 0, ITEM_LURE_BALL
    goto RB_FinishRefining

RB_RefineYellowApcn::
    checkitem ITEM_YELLOW_APRICORN, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RB_NotEnoughApricorns
    removeitem ITEM_YELLOW_APRICORN, 2
    additem ITEM_MOON_BALL, 1
    bufferitemname 0, ITEM_MOON_BALL
    goto RB_FinishRefining

RB_RefineGreenApcn::
    checkitem ITEM_GREEN_APRICORN, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RB_NotEnoughApricorns
    removeitem ITEM_GREEN_APRICORN, 2
    additem ITEM_FRIEND_BALL, 1
    bufferitemname 0, ITEM_FRIEND_BALL
    goto RB_FinishRefining

RB_RefinePinkApcn::
    checkitem ITEM_PINK_APRICORN, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RB_NotEnoughApricorns
    removeitem ITEM_PINK_APRICORN, 2
    additem ITEM_LOVE_BALL, 1
    bufferitemname 0, ITEM_LOVE_BALL
    goto RB_FinishRefining

RB_RefineWhiteApcn::
    checkitem ITEM_WHITE_APRICORN, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RB_NotEnoughApricorns
    removeitem ITEM_WHITE_APRICORN, 2
    additem ITEM_FAST_BALL, 1
    bufferitemname 0, ITEM_FAST_BALL
    goto RB_FinishRefining

RB_RefineBlackApcn::
    checkitem ITEM_BLACK_APRICORN, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RB_NotEnoughApricorns
    removeitem ITEM_BLACK_APRICORN, 2
    additem ITEM_HEAVY_BALL, 1
    bufferitemname 0, ITEM_HEAVY_BALL
    goto RB_FinishRefining

RB_FinishRefining::
    msgbox RB_ThanksForRefining
    closemessage
    release
    end

RB_NotEnoughApricorns::
    msgbox RB_NotEnoughApcnMsg
    closemessage
    release
    end

RB_CantAfford::
    msgbox RB_CantAffordMsg
    closemessage
    release
    end

RB_CancelRefineApcn::
    msgbox RB_ComeAgain
    closemessage
    release
    end

RB_RefineApricornIntro:
    .string "Welcome! I'm Kurt.\pI'll turn your harvested apricorns\ninto balls you can use on\lyour journey for ¥1000.$"
    
RB_WhichApricorn:
    .string "Which apricorns should I use?$"

RB_CantAffordMsg:
    .string "Time is money, kid.\pI need money for my time!$"

RB_NotEnoughApcnMsg:
    .string "I need at least two of a kind\nof apricorn to create a ball.$"

RB_ThanksForRefining:
    .string "Here's your {STR_VAR_1}.\nThanks for your business!$"

RB_PressBToReturn:
    .string "Here's what balls I can make.\p {COLOR LIGHT_GREEN}{SHADOW GREEN}(Press B to return)$"

RB_ComeAgain:
    .string "Return when you want me to make\na ball for you!$"

RB_SeeApricornMenuQuery:
    .string "Would you like to see the\nlist of balls that can be made?$"


