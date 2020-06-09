@@Life Skills scripts

@@ Mining item refinement (add these scripts to the proper NPC's when the cave town is done.)

@@Shard ore refining===============================================================================

Ryu_RefineShardOre::@add this to the shard ore refiner npc
    msgbox Ryu_ShardOreIntro
    closemessage
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
    msgbox Ryu_GemRefiningIntro
    closemessage
    msgbox RyuPlsChoosOre, MSGBOX_ONELINE
    special RyuCountGemOres
    delay 10
    multichoicedefault 0, 5, MULTI_RLS_GEMSTONEQUALITYMENU, 0, 1
    switch VAR_RESULT
    case 0, Ryu_RefineCommonOre
    case 1, Ryu_RefineUncommonOre
    case 2, Ryu_RefineRareOre
    case 3, Ryu_ExitRefinery
    goto Ryu_ExitRefinery

Ryu_RefineCommonOre::
    checkitem ITEM_COMMON_GEM_ORE, 1
    compare VAR_RESULT, 0
    goto_if_eq Ryu_NoItem
    removeitem ITEM_COMMON_GEM_ORE, 1
    setvar VAR_TEMP_A, 1
    special RyuChooseFromGemList
    additem VAR_RESULT, 1
	bufferitemname 0, VAR_RESULT
    msgbox Ryu_RefineSuccessful
    release
    end

Ryu_RefineUncommonOre::
    checkitem ITEM_UNCOMMON_GEM_ORE, 1
    compare VAR_RESULT, 0
    goto_if_eq Ryu_NoItem
    removeitem ITEM_UNCOMMON_GEM_ORE, 1
    setvar VAR_TEMP_A, 2
    special RyuChooseFromGemList
    additem VAR_RESULT, 1
	bufferitemname 0, VAR_RESULT
    msgbox Ryu_RefineSuccessful
    release
    end

Ryu_RefineRareOre::
    checkitem ITEM_RARE_GEM_ORE, 1
    compare VAR_RESULT, 0
    goto_if_eq Ryu_NoItem
    removeitem ITEM_COMMON_GEM_ORE, 1
    setvar VAR_TEMP_A, 3
    special RyuChooseFromGemList
    additem VAR_RESULT, 1
	bufferitemname 0, VAR_RESULT
    msgbox Ryu_RefineSuccessful
    release
    end

Ryu_ExitRefinery::
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
	.string "The process is done.\nIt was a {STR_VAR_1}!$"
	
Ryu_PlsComeBackLater:
	.string "Feel free to return when you need\nme to refine something.$"
	
Ryu_YouDontHaveAnyGemOres:
	.string "You don't have any of that ore.$"

@@Fossil Ore Refiner===============================================================================
Ryu_RefineFossilOre::@Add this to the fossil ore refiner
    msgbox Ryu_FossilOreIntro
    closemessage
    specialvar VAR_TEMP_C, RyuFossilReward
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
    addvar VAR_RYU_PLAYER_MINING_EXP, 1
    additem VAR_TEMP_B, VAR_TEMP_C
    bufferitemname 1, VAR_TEMP_B
    buffernumberstring 0, VAR_TEMP_C
    playfanfare MUS_FANFA1
    msgbox Ryu_YouMinedA
    call Ryu_CheckForMiningLevelUp
    waitfanfare
    return

Ryu_CheckForMiningLevelUp::
    switch VAR_RYU_PLAYER_MINING_SKILL
    case 0, ryu_return
    case 1, Ryu_CheckLevel1
    case 2, Ryu_CheckLevel2
    case 3, ryu_return
    goto ryu_return

Ryu_CheckLevel1::
    compare VAR_RYU_PLAYER_MINING_EXP, 128
    goto_if_lt ryu_return
    compare VAR_RYU_PLAYER_MINING_SKILL, 1
    goto_if_ne ryu_return
    playfanfare MUS_FANFA2
    waitfanfare
    msgbox Ryu_Level2Mining
    closemessage
    addvar VAR_RYU_PLAYER_MINING_SKILL, 1
    return

Ryu_CheckLevel2::
    compare VAR_RYU_PLAYER_MINING_EXP, 356
    goto_if_lt ryu_return
    compare VAR_RYU_PLAYER_MINING_SKILL, 2
    goto_if_ne ryu_return
    playfanfare MUS_FANFA3
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
    goto_if_set FLAG_TEMP_9, Ryu_NoOresHere
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
