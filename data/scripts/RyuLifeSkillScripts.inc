@@Life Skills scripts

@@ Mining item refinement (add these scripts to the proper NPC's when the cave town is done.)

@@Shard ore refining===============================================================================

Ryu_RefineShardOre::@add this to the shard ore refiner npc
    lockall
    faceplayer
    msgbox Ryu_ShardOreIntro
    closemessage
    checkitemspace ITEM_RARE_CANDY, 1  @@arbitrarily checks if there's space in the item pocket.
    compare VAR_RESULT, FALSE
    goto_if_eq Ryu_NotEnoughSpace
    specialvar VAR_TEMP_C, RyuShardReward
    switch VAR_TEMP_C
    case 0, Ryu_NoShardOreToRefine
    case 1, Ryu_ShardOreFailed
    removeitem ITEM_SHARD_ORE, 1
    additem VAR_TEMP_C, 1
    bufferitemname 3, VAR_TEMP_C
    msgbox RyuShardRewardExiting
    release
    end

Ryu_NoShardOreToRefine::
    msgbox Ryu_NoShardOres
    release
    end

Ryu_ShardOreFailed::
    msgbox Ryu_ShardRefineFailure
    release
    end

Ryu_ShardRefineFailure:
    .string "Bad news! I failed to refine\nanything of use. The ore was\ltoo damaged. Sorry!$"

Ryu_ShardOreIntro:
    .string "Welcome! I'll refine any Shard\nores you have, at no charge!\pLet's see what you got...$"

RyuShardRewardExiting:
    .string "Ooh, I got something from it!\pHere's your {RYU_STR_1}!\nBe sure to make good use of it!$"

Ryu_NoShardOres:
    .string "You must have at least one\nShard ore for me to refine!$"

@@gem ore refining=================================================================================
Ryu_MiningGemstoneOreRefiner::@Add this to the gemstone refiner
    lockall
    faceplayer
    msgbox Ryu_GemRefiningIntro
    closemessage
    msgbox RyuPlsChoosOre
    special RyuCountGemOres
    delay 10
    call Ryu_MiningGemstoneRefinerMenuPositionCheck
    multichoicedefault 0, 3, MULTI_RLS_GEMSTONEQUALITYMENU, VAR_TEMP_4, 1
    switch VAR_RESULT
    case 0, Ryu_RefineCommonOre
    case 1, Ryu_RefineUncommonOre
    case 2, Ryu_RefineRareOre
    case 3, Ryu_ExitRefinery
    goto Ryu_ExitRefinery

Ryu_RefineCommonOre::
    checkitemspace ITEM_RARE_CANDY, 1  @@arbitrarily checks if there's space in the item pocket.
    compare VAR_RESULT, FALSE
    goto_if_eq Ryu_NotEnoughSpace
    checkitem ITEM_COMMON_GEM_ORE, 1
    compare VAR_RESULT, 0
    goto_if_eq Ryu_NoItem
    removeitem ITEM_COMMON_GEM_ORE, 1
    setvar VAR_TEMP_A, 1
    special RyuChooseFromGemList
    additem VAR_TEMP_B, 1
	bufferitemname 3, VAR_TEMP_B
    msgbox Ryu_RefineSuccessful
    setflag FLAG_TEMP_3
    release
    end

Ryu_RefineUncommonOre::
    checkitemspace ITEM_RARE_CANDY, 1  @@arbitrarily checks if there's space in the item pocket.
    compare VAR_RESULT, FALSE
    goto_if_eq Ryu_NotEnoughSpace
    checkitem ITEM_UNCOMMON_GEM_ORE, 1
    compare VAR_RESULT, 0
    goto_if_eq Ryu_NoItem
    removeitem ITEM_UNCOMMON_GEM_ORE, 1
    setvar VAR_TEMP_A, 2
    special RyuChooseFromGemList
    additem VAR_TEMP_B, 1
	bufferitemname 3, VAR_TEMP_B
    msgbox Ryu_RefineSuccessful
    setflag FLAG_TEMP_4
    release
    end

Ryu_RefineRareOre::
    checkitemspace ITEM_RARE_CANDY, 1  @@arbitrarily checks if there's space in the item pocket.
    compare VAR_RESULT, FALSE
    goto_if_eq Ryu_NotEnoughSpace
    checkitem ITEM_RARE_GEM_ORE, 1
    compare VAR_RESULT, 0
    goto_if_eq Ryu_NoItem
    removeitem ITEM_RARE_GEM_ORE, 1
    setvar VAR_TEMP_A, 3
    special RyuChooseFromGemList
    additem VAR_TEMP_B, 1
	bufferitemname 3, VAR_TEMP_B
    msgbox Ryu_RefineSuccessful
    setflag FLAG_TEMP_5
    closemessage
    release
    end

Ryu_MiningGemstoneRefinerMenuPositionCheck::
    goto_if_set FLAG_TEMP_3, Ryu_MGRMP1
    goto_if_set FLAG_TEMP_4, Ryu_MGRMP2
    goto_if_set FLAG_TEMP_5, Ryu_MGRMP3
    setvar VAR_TEMP_4, 0
    return

Ryu_MGRMP1::
    setvar VAR_TEMP_4, 0
    return

Ryu_MGRMP2::
    setvar VAR_TEMP_4, 1
    return

Ryu_MGRMP3::
    setvar VAR_TEMP_4, 2
    return

Ryu_ExitRefinery::
    setvar VAR_TEMP_4, 3
    msgbox Ryu_PlsComeBackLater
    release
    end

Ryu_NoItem:
    msgbox Ryu_YouDontHaveAnyGemOres
    release
    end

Ryu_GemRefiningIntro:
	.string "Welcome to my Gem Ore refinery!\p"
	.string "If you have any Gem Ore, I'll refine\n"
	.string "it for you, no cost!$"

RyuPlsChoosOre:
	.string "Please choose an ore to refine.$"
	
Ryu_RefineSuccessful:
	.string "The process is done.\nIt was a {RYU_STR_1}!$"
	
Ryu_PlsComeBackLater:
	.string "Feel free to return when you need\nme to refine something.$"
	
Ryu_YouDontHaveAnyGemOres:
	.string "You don't have any of that ore.$"

@@Fossil Ore Refiner===============================================================================
Ryu_RefineFossilOre::@Add this to the fossil ore refiner
    lockall
    faceplayer
    msgbox Ryu_FossilOreIntro
    closemessage
    specialvar VAR_TEMP_C, RyuFossilReward
    checkitemspace VAR_TEMP_C, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Ryu_NotEnoughSpace
    switch VAR_TEMP_C
    case 0, Ryu_NoFossilOreToRefine
    case 1, Ryu_FossilOreFailed
    removeitem ITEM_FOSSIL_ORE, 1
    additem VAR_TEMP_C, 1
    bufferitemname 3, VAR_TEMP_C
    msgbox RyuFossilRewardExiting
    release
    end

Ryu_NoFossilOreToRefine::
    msgbox Ryu_NoFossilOres
    release
    end

Ryu_FossilOreFailed::
    msgbox Ryu_FossilRefineFailure
    release
    end

Ryu_FossilRefineFailure:
    .string "Bad news! I failed to refine\nanything of use.\pThe ore was too damaged. Sorry!$"

Ryu_FossilOreIntro:
	.string "This machine is our Fossil Ore Refiner.\p"
	.string "If you have any Fossil Ore, I'll refine\n"
	.string "it for you, no cost!$"

RyuFossilRewardExiting:
    .string "Success, I got something from it!\pHere's your {RYU_STR_1}!\nBe sure to make good use of it!$"

Ryu_NoFossilOres:
    .string "You must have at least one\nfossil ore for me to refine.$"

@@Shard exchange menu

Ryu_ShardExchange:: @@this goes on the shard exchange dudes
    msgbox Ryu_ShardExchangeIntro
    multichoicegrid 4, 0, MULTI_SHARD_EXCHANGE, 2, 0
    switch VAR_RESULT
    case 0, Ryu_ShardExchangeRed
    case 1, Ryu_ShardExchangeBlue
    case 2, Ryu_ShardExchangeYellow
    case 3, Ryu_ShardExchangeGreen
    case 4, Ryu_ShardExchangeDark
    case 5, Ryu_ShardExchangeLight
    case 6, Ryu_ShardExchangeCyan
    case 7, Ryu_ShardExchangeGlossy
    case 8, Ryu_ShardExchangeGold
    case 9, Ryu_ShardExchangeGray
    case 10, Ryu_ShardExchangeExit
    case 11, Ryu_ShardExchangeExit
    goto Ryu_ShardExchangeExit

Ryu_ShardExchangeRed::
    setvar VAR_TEMP_B, ITEM_RED_SHARD
    setvar VAR_TEMP_C, ITEM_FIRE_STONE
    goto Ryu_CheckShardCount

Ryu_ShardExchangeBlue::
    setvar VAR_TEMP_B, ITEM_BLUE_SHARD
    setvar VAR_TEMP_C, ITEM_WATER_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeYellow::
    setvar VAR_TEMP_B, ITEM_YELLOW_SHARD
    setvar VAR_TEMP_C, ITEM_THUNDER_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeGreen::
    setvar VAR_TEMP_B, ITEM_GREEN_SHARD
    setvar VAR_TEMP_C, ITEM_LEAF_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeDark::
    setvar VAR_TEMP_B, ITEM_DARK_SHARD
    setvar VAR_TEMP_C, ITEM_DUSK_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeLight::
    setvar VAR_TEMP_B, ITEM_LIGHT_SHARD
    setvar VAR_TEMP_C, ITEM_DAWN_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeCyan::
    setvar VAR_TEMP_B, ITEM_CYAN_SHARD
    setvar VAR_TEMP_C, ITEM_ICE_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeGlossy::
    setvar VAR_TEMP_B, ITEM_GLOSSY_SHARD
    setvar VAR_TEMP_C, ITEM_SHINY_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeGold::
    setvar VAR_TEMP_B, ITEM_GOLD_SHARD
    setvar VAR_TEMP_C, ITEM_SUN_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeGray::
    setvar VAR_TEMP_B, ITEM_GRAY_SHARD
    setvar VAR_TEMP_C, ITEM_MOON_STONE
    goto Ryu_CheckShardCount
    
Ryu_ShardExchangeExit::
    msgbox Ryu_ExchangeLeaveMsg
    closemessage
    release
    end
    
Ryu_CheckShardCount::
    checkitem VAR_TEMP_B, 1
    compare VAR_RESULT, 0
    goto_if_eq Ryu_DontHaveEnoughShard
    checkitemspace VAR_TEMP_C, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Ryu_NotEnoughSpace
    removeitem VAR_TEMP_B, 1
    additem VAR_TEMP_C, 1
    bufferitemname 3, VAR_TEMP_C
    msgbox Ryu_ExchangeSuccess
    closemessage
    release
    end

Ryu_NotEnoughSpace::
    msgbox Ryu_NoSpaceMessage2
    release
    end

Ryu_NoSpaceMessage2:
    .string "You don't have enough space\nto receive this item!\pMake space and come back!$"

Ryu_ShardExchangeIntro:
    .string "Hello! I'll take your shards\nand exchange them for stones!\pPlease pick a shard type.$"

Ryu_ExchangeLeaveMsg:
    .string "Come back when you have more\nshards!$"

Ryu_DontHaveEnoughShard:
    msgbox Ryu_YouDontHaveEnough
    release
    end

Ryu_YouDontHaveEnough:
    .string "I need at least one for the\nexchange.$"

Ryu_ExchangeSuccess:
    .string "Here you go!\nOne {RYU_STR_1}!$"

@@Mining General===================================================================================

Ryu_MineRock:: @@The special code function determines if you are inside or outside by map header.
    call RyuCheckMiningSkill
    playse SE_W088
    waitse
    playse SE_W088
    waitse
    playse SE_W088
    delay 20
    dominingcheck
    compare VAR_TEMP_B, 0
    goto_if_eq Ryu_MineFailed
    checkitemspace ITEM_RARE_CANDY, 1  @@arbitrarily checks if there's space in the item pocket.
    compare VAR_RESULT, FALSE
    goto_if_eq MiningNotEnoughSpace
    addvar VAR_RYU_PLAYER_MINING_EXP, 1
    additem VAR_TEMP_B, VAR_TEMP_C
    bufferitemname 1, VAR_TEMP_B
    buffernumberstring 0, VAR_TEMP_C
    playfanfare MUS_FANFA1
    msgbox Ryu_YouMinedA
    call Ryu_CheckForMiningLevelUp
    waitfanfare
    return

MiningNotEnoughSpace:
    msgbox Ryu_NoSpaceMessage
    release
    end

Ryu_NoSpaceMessage:
    .string "You didn't have space\nfor the item...$"

Ryu_CheckForMiningLevelUp::
    switch VAR_RYU_PLAYER_MINING_SKILL
    case 0, ryu_return
    case 1, Ryu_CheckLevel1
    case 2, Ryu_CheckLevel2
    case 3, ryu_return
    goto ryu_return

Ryu_CheckLevel1::
    compare VAR_RYU_PLAYER_MINING_EXP, 75
    goto_if_lt ryu_return
    compare VAR_RYU_PLAYER_MINING_SKILL, 1
    goto_if_ne ryu_return
    playfanfare MUS_FANFA4
    waitfanfare
    msgbox Ryu_Level2Mining
    closemessage
    addvar VAR_RYU_PLAYER_MINING_SKILL, 1
    return

Ryu_CheckLevel2::
    compare VAR_RYU_PLAYER_MINING_EXP, 180
    goto_if_lt ryu_return
    compare VAR_RYU_PLAYER_MINING_SKILL, 2
    goto_if_ne ryu_return
    playfanfare MUS_FANFA5
    msgbox Ryu_Level3Mining
    waitfanfare
    closemessage
    addvar VAR_RYU_PLAYER_MINING_SKILL, 1
    return

Ryu_MineFailed::
    msgbox Ryu_FailedToMine
    release
    end

Ryu_NoOresHere::
    msgbox Ryu_NothingHere
    release
    end

RyuCheckMiningSkill::
    compare VAR_RYU_PLAYER_MINING_SKILL, 0
    goto_if_eq ryu_end
    return

Ryu_FailedToMine:
    .string "You failed to mine anything.$"

Ryu_YouMinedA:
    .string "{PLAYER} mined {STR_VAR_1} {STR_VAR_2}(s)\nfrom the rock!$"

Ryu_NothingHere:
    .string "There doesn't seem to be\nanything of interest here.$"

Ryu_Level2Mining:
    .string "You feel yourself attuning to\nthe earth a little more.$"

Ryu_Level3Mining:
    .string "The earth now speaks to you,\nletting you see ores more clearly.$"

@overworld mining scripts==========================================================================

MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

MiningRock5::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end

MiningRock6::
    goto_if_set FLAG_TEMP_6, Ryu_NoOresHere
    setflag FLAG_TEMP_6
    call Ryu_MineRock
    release
    end


MiningRock7::
    goto_if_set FLAG_TEMP_7, Ryu_NoOresHere
    setflag FLAG_TEMP_7
    call Ryu_MineRock
    release
    end

MiningRock8::
    goto_if_set FLAG_TEMP_8, Ryu_NoOresHere
    setflag FLAG_TEMP_8
    call Ryu_MineRock
    release
    end

MiningRock9::
    @goto_if_set FLAG_TEMP_9, Ryu_NoOresHere
    setflag FLAG_TEMP_9
    call Ryu_MineRock
    release
    end

MiningRock10::
    goto_if_set FLAG_TEMP_A, Ryu_NoOresHere
    setflag FLAG_TEMP_A
    call Ryu_MineRock
    release
    end

@alchemy related

Ryu_ReagentPouchScript::
    msgbox RA_ShowPowderCounts
    closemessage
    release
    end

RA_ShowPowderCounts:
    .string "Metal Dust Counts:\nCopper: {STR_VAR_1}, Silver: {STR_VAR_2}, Gold: {STR_VAR_3}$"

Ryu_RefineMetalDust::
    switch VAR_ITEM_ID
    case ITEM_SILVER_ORE, RyuAlchemy_RefineMetalDustSilver
    case ITEM_COPPER_ORE, RyuAlchemy_RefineMetalDustCopper
    case ITEM_GOLD_ORE, RyuAlchemy_RefineMetalDustGold
    goto ryu_end

RyuAlchemy_RefineMetalDustSilver::
    checkitem ITEM_SILVER_ORE, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RyuAlchemy_NotEnoughOre
    msgbox RyuAlchemy_RefineOreQuery, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne ryu_end
    removeitem ITEM_SILVER_ORE, 2
    addvar VAR_RYU_ALCHEMY_SILVER, 200
    msgbox RyuAlchemy_OreRefined, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq RA_BufferShowPowderCounts    
    release
    end

RyuAlchemy_RefineMetalDustGold::
    checkitem ITEM_GOLD_ORE, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RyuAlchemy_NotEnoughOre
    msgbox RyuAlchemy_RefineOreQuery, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne ryu_end
    removeitem ITEM_GOLD_ORE, 2
    addvar VAR_RYU_ALCHEMY_GOLD, 200
    msgbox RyuAlchemy_OreRefined, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq RA_BufferShowPowderCounts
    release
    end

RyuAlchemy_RefineMetalDustCopper::
    checkitem ITEM_COPPER_ORE, 2
    compare VAR_RESULT, TRUE
    goto_if_ne RyuAlchemy_NotEnoughOre
    msgbox RyuAlchemy_RefineOreQuery, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne ryu_end
    removeitem ITEM_COPPER_ORE, 2
    addvar VAR_RYU_ALCHEMY_COPPER, 200
    msgbox RyuAlchemy_OreRefined, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq RA_BufferShowPowderCounts
    release
    end

RA_BufferShowPowderCounts::
    buffernumberstring 0, VAR_RYU_ALCHEMY_COPPER
    buffernumberstring 1, VAR_RYU_ALCHEMY_SILVER
    buffernumberstring 2, VAR_RYU_ALCHEMY_GOLD
    goto Ryu_ReagentPouchScript

RyuAlchemy_NotEnoughOre::
    msgbox RA_NotEnoughOreWarning
    closemessage
    release
    end

RA_NotEnoughOreWarning::
    .string "You don't have enough of the ore\nto refine into dust.$"

RyuAlchemy_OreRefined:
    .string "The ores have been refined.\pWould you like to view counts?$"

RyuAlchemy_RefineOreQuery:
    .string "Would you like to turn 2 ores\ninto dust?$"

@actual alchemy check

RyuAlchemy_AttemptCreateEffect::
    scrollingmultichoice SCROLLINGMULTICHOICE_RYUALCHEMYMENU, 0, 0, 6, 1
    compare VAR_RESULT, 127
    goto_if_eq ryu_end
    copyvar VAR_TEMP_A, VAR_RESULT
    specialvar VAR_RESULT, RyuAlchemy_TryCraftingItem
    switch VAR_RESULT
    case 1000, RA_NotEnoughMetalDust
    case 2000, RA_LevelNotHighEnough
    case 4100, RA_Ingredient1Missing
    case 4200, RA_Ingredient2Missing
    case 4300, RA_Ingredient3Missing
    compare VAR_RESULT, ALCHEMY_ITEM_RECIPE_STARDUST
    goto_if_ge RA_CreateItem
    callnative RyuBufferEffectName
    buffernumberstring 1, VAR_TEMP_A
    msgbox AlchemyEffectSuccessful
    release
    end

RA_CreateItem::
    giveitem VAR_RESULT, 1
    bufferitemname 0, VAR_RESULT
    msgbox RA_AlchemyItemSuccessful
    release
    end

AlchemyEffectSuccessful:
    .string "The effect was successfully created!$" @@\n{STR_VAR_2} with {STR_VAR_1} charges available.$"
    @@ Pidgey or Kageru, this script activates when effect creation was successful
    @@ See your names in RyuNatives and lifeskill.h

RA_AlchemyItemSuccessful:
    .string "The {STR_VAR_1} was created\nsuccessfully!$"
