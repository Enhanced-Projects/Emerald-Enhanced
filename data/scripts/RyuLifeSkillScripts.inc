@@Life Skills scripts

@@ Mining item refinement (add these scripts to the proper NPC's when the cave town is done.)

Ryu_MiningGemstoneOreRefiner::
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
	.string "Welcome to my refining shop!\nHere, I will refine your gem\lores for free!$"
	
RyuPlsChoosOre:
	.string "Please choose an ore to refine.$"
	
Ryu_RefineSuccessful:
	.string "All finished!\nIt was a {STR_VAR_1}!$"
	
Ryu_PlsComeBackLater:
	.string "Please return when you need\nme to refine something!$"
	
Ryu_YouDontHaveAnyGemOres:
	.string "You don't have any of that ore!$"

@@Fossil Ore Refiner
Ryu_RefineFossilOre::
    msgbox Ryu_FossilOreIntro
    closemessage
    specialvar VAR_RESULT, RyuFossilReward
    compare VAR_RESULT, 0
    goto_if_eq Ryu_NoFossilOreToRefine
    compare VAR_RESULT, 1
    goto_if_eq Ryu_FossilOreFailed
    removeitem ITEM_FOSSIL_ORE, 1
    additem VAR_RESULT, 1
    bufferitemname 4, VAR_RESULT
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
    .string "Bad news! I failed to refine\nanything of use. The ore was\ltoo damaged. Sorry!$"

Ryu_FossilOreIntro:
    .string "Welcome! I'll refine any fossil\nores you have, at no charge!\pLet's see what you got...$"

RyuFossilRewardExiting:
    .string "Ooh, I got something from it!\pHere's your {RYU_STR_1}!\nBe sure to make good use of it!$"

@@Mining General

Ryu_MineOutsideRock::
    playse SE_W088
    waitse
    playse SE_W088
    waitse
    playse SE_W088
    delay 20
    dominingcheck
    compare VAR_TEMP_B, 0
    goto_if_eq Ryu_MineFailed
    additem VAR_TEMP_B, VAR_TEMP_C
    bufferitemname 1, VAR_TEMP_B
    buffernumberstring 0, VAR_TEMP_C
    return

Ryu_MineFailed::
    msgbox Ryu_FailedToMine
    release
    end

Ryu_NoOresHere::
    msgbox Ryu_NothingHere
    release
    end

Ryu_FailedToMine:
    .string "You failed to mine anything.$"

Ryu_YouMinedA:
    .string "{PLAYER} mined {STR_VAR_1} {STR_VAR_2}(s)\nfrom the rock!$"

Ryu_NothingHere:
    .string "There doesn't seem to be\nanything of interest here.$"

@overworld mining scripts

r101_MiningRock1::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineOutsideRock
    playfanfare MUS_FANFA1
    msgbox Ryu_YouMinedA
    waitfanfare
    release
    end

r101_MiningRock2::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineOutsideRock
    playfanfare MUS_FANFA1
    msgbox Ryu_YouMinedA
    waitfanfare
    release
    end

