@Scripts for the botany skill

@The main script called when using cut on grass
RyuScript_FieldCut::
    special BotanyCheck
    delay 60
    switch VAR_RYU_PLAYER_BOTANY_SKILL
    case 0, ryu_end
    case 1, RyuBotany_LevelOne
    case 2, RyuBotany_LevelTwo
    case 3, RyuBotany_LevelThree
    case 4, RyuBotany_LevelFour
    case 5, RyuBotany_LevelFive
    end

RyuBotany_LevelOne::
    additem VAR_TEMP_0, 1
    bufferitemname 0, VAR_TEMP_0
    msgbox RyuBotany_Obtained1Item
    closemessage
    addvars VAR_RYU_PLAYER_BOTANY_SKILL_EXP, VAR_RYU_PLAYER_BOTANY_SKILL@Player gains 1 exp per level of botany per botany check.
    call RyuBotany_CheckLevelUp
    release
    end

RyuBotany_LevelTwo::
    additem VAR_TEMP_0, 1
    additem VAR_TEMP_1, 1
    bufferitemname 0, VAR_TEMP_0
    bufferitemname 1, VAR_TEMP_1
    msgbox RyuBotany_Obtained2Items
    closemessage
    addvars VAR_RYU_PLAYER_BOTANY_SKILL_EXP, VAR_RYU_PLAYER_BOTANY_SKILL@Player gains 1 exp per level of botany per botany check.
    call RyuBotany_CheckLevelUp
    release
    end

RyuBotany_LevelThree::
    additem VAR_TEMP_0, 1
    additem VAR_TEMP_1, 1
    additem VAR_TEMP_2, 1
    bufferitemname 0, VAR_TEMP_0
    bufferitemname 1, VAR_TEMP_1
    bufferitemname 2, VAR_TEMP_2
    msgbox RyuBotany_Obtained3Items
    closemessage
    addvars VAR_RYU_PLAYER_BOTANY_SKILL_EXP, VAR_RYU_PLAYER_BOTANY_SKILL@Player gains 1 exp per level of botany per botany check.
    call RyuBotany_CheckLevelUp
    release
    end

RyuBotany_LevelFour::
    additem VAR_TEMP_0, 1 
    additem VAR_TEMP_1, 1 
    additem VAR_TEMP_2, 1 
    additem VAR_TEMP_3, 1 
    bufferitemname 0, VAR_TEMP_0
    bufferitemname 1, VAR_TEMP_1
    bufferitemname 2, VAR_TEMP_2
    bufferitemname 3, VAR_TEMP_3
    msgbox RyuBotany_Obtained4Items
    closemessage
    addvars VAR_RYU_PLAYER_BOTANY_SKILL_EXP, VAR_RYU_PLAYER_BOTANY_SKILL@Player gains 1 exp per level of botany per botany check.
    call RyuBotany_CheckLevelUp
    release
    end

RyuBotany_LevelFive::
    additem VAR_TEMP_0, 1
    additem VAR_TEMP_1, 1
    additem VAR_TEMP_2, 1
    additem VAR_TEMP_3, 1
    additem VAR_TEMP_4, 1
    bufferitemname 0, VAR_TEMP_0
    bufferitemname 1, VAR_TEMP_1
    bufferitemname 2, VAR_TEMP_2
    bufferitemname 3, VAR_TEMP_3
    bufferitemname 4, VAR_TEMP_4
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
