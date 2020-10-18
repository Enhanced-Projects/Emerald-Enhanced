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
    buffernumberstring 0, VAR_RESULT
    buffernumberstring 1, VAR_RYU_PLAYER_BOTANY_SKILL
    scriptdebug RBDB_BotanyDebug
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
    goto_if_eq, ryu_return
    setvar VAR_TEMP_5, 2
    return

RBDB_BotanyDebug::
    .string "Random result was {STR_VAR_1}, Skill is {STR_VAR_2}$"

RyuBotanyTree_GiveOneItem::
    callnative BotanyTreeChop
    giveitem VAR_TEMP_0, 1
    return

RyuBotanyGrass_GiveOneItem::
    callnative BotanyCheck
    setvar VAR_TEMP_5, 1
    call_if_set FLAG_BOTANY_HAS_HYPER_CUTTER, RyuBotany_DoubleRewardHC
    additem VAR_TEMP_0, VAR_TEMP_5
    bufferitemname 0, VAR_TEMP_0
    buffernumberstring 1, VAR_TEMP_5
    msgbox RyuBotany_RewardMessage
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
