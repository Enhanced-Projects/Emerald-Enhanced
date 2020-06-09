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

@@Fossil Ore Refiner
Ryu_RefineFossilOre::
    msgbox Ryu_FossilOreIntro
    closemessage
    specialvar VAR_TEMP_C, RyuFossilReward
    switch VAR_RESULT
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

@@Mining General

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

RyuCheckMiningSkill:
    compare VAR_RYU_PLAYER_MINING_SKILL, 0
    goto_if_eq ryu_end
    return

Ryu_FailedToMine:
    .string "You failed to mine anything.$"

Ryu_YouMinedA:
    .string "{PLAYER} mined {STR_VAR_1} {STR_VAR_2}(s)\nfrom the rock!$"

Ryu_NothingHere:
    .string "There doesn't seem to be\nanything of interest here.$"

@overworld mining scripts

//Desert Underpass

DU_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

DU_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

DU_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

DU_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end
    
DU_MiningRock5::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end
    
DU_MiningRock6::
    goto_if_set FLAG_TEMP_6, Ryu_NoOresHere
    setflag FLAG_TEMP_6
    call Ryu_MineRock
    release
    end
    
DU_MiningRock7::
    goto_if_set FLAG_TEMP_7, Ryu_NoOresHere
    setflag FLAG_TEMP_7
    call Ryu_MineRock
    release
    end
    
DU_MiningRock8::
    goto_if_set FLAG_TEMP_8, Ryu_NoOresHere
    setflag FLAG_TEMP_8
    call Ryu_MineRock
    release
    end
    
DU_MiningRock9::
    goto_if_set FLAG_TEMP_9, Ryu_NoOresHere
    setflag FLAG_TEMP_9
    call Ryu_MineRock
    release
    end

//Meteor Falls

MF_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

MF_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

MF_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

MF_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

MF_MiningRock5::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end

//Rusturf Tunnel

RT_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

RT_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

RT_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

//Granite Cave

GC_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

GC_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

GC_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

GC_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

GC_MiningRock5::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

GC_MiningRock6::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

GC_MiningRock7::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

GC_MiningRock8::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

GC_MiningRock9::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

GC_MiningRock10::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

GC_MiningRock11::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

//Jagged Pass

JP_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

JP_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

JP_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

//Fiery Path

FP_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

FP_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

FP_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

FP_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

FP_MiningRock5::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end

//Desert Tomb

DT_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

DT_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

DT_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

DT_MiningRock4::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

DT_MiningRock5::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

DT_MiningRock6::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

DT_MiningRock7::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

DT_MiningRock8::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end

DT_MiningRock9::
    goto_if_set FLAG_TEMP_6, Ryu_NoOresHere
    setflag FLAG_TEMP_6
    call Ryu_MineRock
    release
    end

DT_MiningRock10::
    goto_if_set FLAG_TEMP_7, Ryu_NoOresHere
    setflag FLAG_TEMP_7
    call Ryu_MineRock
    release
    end

DT_MiningRock11::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

DT_MiningRock12::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

DT_MiningRock13::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

DT_MiningRock14::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

DT_MiningRock15::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

//Altering Cave

AC_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

AC_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

AC_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

AC_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

//Artisan Cave

ArC_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

ArC_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

ArC_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

ArC_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

ArC_MiningRock5::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end

ArC_MiningRock6::
    goto_if_set FLAG_TEMP_6, Ryu_NoOresHere
    setflag FLAG_TEMP_6
    call Ryu_MineRock
    release
    end

//Scorched Slab

SS_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

SS_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

SS_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

//Shoal Cave

SC_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

SC_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

SC_MiningRock3::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

SC_MiningRock4::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

SC_MiningRock5::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

//Mt Pyre

MP_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

MP_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

MP_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

MP_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

//Victory Road

VR_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

VR_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

VR_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

VR_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

VR_MiningRock5::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

VR_MiningRock6::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

VR_MiningRock7::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

VR_MiningRock8::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

VR_MiningRock9::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

VR_MiningRock10::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

VR_MiningRock11::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

//Cave of Origin

CoO_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

CoO_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

CoO_MiningRock3::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

CoO_MiningRock4::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

CoO_MiningRock5::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

//Route 66

R66_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

R66_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

R66_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

//Route 114

R114_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

R114_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

R114_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

R114_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

R114_MiningRock5::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end

//Route 115

R115_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

R115_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

R115_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end

R115_MiningRock4::
    goto_if_set FLAG_TEMP_4, Ryu_NoOresHere
    setflag FLAG_TEMP_4
    call Ryu_MineRock
    release
    end

R115_MiningRock5::
    goto_if_set FLAG_TEMP_5, Ryu_NoOresHere
    setflag FLAG_TEMP_5
    call Ryu_MineRock
    release
    end

//Route 116

R116_MiningRock1::
    goto_if_set FLAG_TEMP_1, Ryu_NoOresHere
    setflag FLAG_TEMP_1
    call Ryu_MineRock
    release
    end

R116_MiningRock2::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineRock
    release
    end

R116_MiningRock3::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineRock
    release
    end
