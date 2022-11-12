@@This is a long script so i seperated it out.

Ryu_FossilReviverScript::
    lockall
    faceplayer
    compare VAR_RYU_PLAYER_MINING_SKILL, 0
    goto_if_eq Ryu_FossilReviverNoSkill @@Assures that players cannot use this reviver unless they have the mining skill.
    msgbox RyuFossilReviverIntro
    multichoicegrid 0, 0, MULTI_FOSSIL_REVIVER, 2, 0 @@menu for reviver
    switch VAR_RESULT
    case 0, RFR_Armor
    case 1, RFR_Skull
    case 2, RFR_Helix
    case 3, RFR_Dome
    case 4, RFR_Plume
    case 5, RFR_Jaw
    case 6, RFR_Sail
    case 7, RFR_Root
    case 8, RFR_Claw
    case 9, RFR_Amber
    case 10, RFR_Cover
    case 11, Ryu_FossilReviverCancel
    goto Ryu_FossilReviverCancel @@shouldn't be possible to get here, but just in case, this will prevent random crashes. 

RFR_Armor::
    checkitem ITEM_ARMOR_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_SHIELDON
    setvar VAR_TEMP_2, ITEM_ARMOR_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Skull::
    checkitem ITEM_SKULL_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_CRANIDOS
    setvar VAR_TEMP_2, ITEM_SKULL_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Helix::
    checkitem ITEM_HELIX_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_OMANYTE
    setvar VAR_TEMP_2, ITEM_HELIX_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Dome::
    checkitem ITEM_DOME_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_KABUTO
    setvar VAR_TEMP_2, ITEM_DOME_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Plume::
    checkitem ITEM_PLUME_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_ARCHEN
    setvar VAR_TEMP_2, ITEM_PLUME_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Jaw::
    checkitem ITEM_JAW_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_TYRUNT
    setvar VAR_TEMP_2, ITEM_JAW_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Sail::
    checkitem ITEM_SAIL_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_AMAURA
    setvar VAR_TEMP_2, ITEM_SAIL_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Root::
    checkitem ITEM_ROOT_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_LILEEP
    setvar VAR_TEMP_2, ITEM_ROOT_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Claw::
    checkitem ITEM_CLAW_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_ANORITH
    setvar VAR_TEMP_2, ITEM_CLAW_FOSSIL
    goto RFR_CheckPartyandGiveEgg

RFR_Amber::
    checkitem ITEM_OLD_AMBER, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_AERODACTYL
    setvar VAR_TEMP_2, ITEM_OLD_AMBER
    goto RFR_CheckPartyandGiveEgg

RFR_Cover::
    checkitem ITEM_COVER_FOSSIL, 1
    compare VAR_RESULT, 1
    goto_if_ne Ryu_DontHaveItem
    setvar VAR_TEMP_4, SPECIES_TIRTOUGA
    setvar VAR_TEMP_2, ITEM_COVER_FOSSIL
    goto RFR_CheckPartyandGiveEgg

Ryu_FossilReviverNoSkill::
    msgbox RFR_Nominingskillstring
    release
    end

RFR_CheckPartyandGiveEgg::
    specialvar VAR_RESULT, Ryu_GiveRevivedFossilEgg
    switch VAR_RESULT
    case 0, RFR_NoPartySlotFree
    case 1, RFR_GiveEggAndExit
    case 3, RFR_GiveEggAndBonusGhost
    goto ryu_end

Ryu_DontHaveItem::
    msgbox RFR_Noneofthisfossil
    release
    end

RFR_NoPartySlotFree::
    msgbox RFR_MakeSpaceInParty
    release
    end

RFR_GiveEggAndExit::
    removeitem VAR_TEMP_2, 1
    bufferspeciesname 3, VAR_TEMP_4
    msgbox RFR_Finish
    release
    end

Ryu_FossilReviverCancel::
    msgbox RFR_ComeBackLater
    release
    end

RFR_GiveEggAndBonusGhost:
    removeitem VAR_TEMP_2, 1
    bufferspeciesname 0, VAR_0x8003
    bufferspeciesname 1, VAR_0x8005
    msgbox RFR_GhostBonus
    closemessage
    release
    end

@@Strings==========================================================================================

RFR_GhostBonus:
    .string "Success!\nThe {STR_VAR_1} fossil was revived!\pWhoa! The {STR_VAR_1} fossil was\nhaunted by a {STR_VAR_2}!!!\pHere you go!$"

RyuFossilReviverIntro:
    .string "Hello, traveller!\pPlease pick from this list of fossils\nso I can resurrect one for you!$"

RFR_Nominingskillstring:
    .string "Hi! I'm still setting up\nmy lab, but you will eventually\lbe able to revive fossils here!$"

RFR_Noneofthisfossil:
    .string "You must give me the fossil\nfor me to revive it!$"

RFR_MakeSpaceInParty:
    .string "You don't have enough space in\nyour party for another mon!$"

RFR_ComeBackLater:
    .string "Come back later if you want\na fossil revived!$"

RFR_Finish:
    .string "Success! I have successfully\nrevived a {RYU_STR_1} from\lthe fossil!$"



