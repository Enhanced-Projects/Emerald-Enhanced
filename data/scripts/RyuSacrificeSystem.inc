@+=================================================================================================Ryu Genetic Perfection



GCMS_Intro::
	lock
	msgbox GCMS_IntroMsg
	multichoicedefault  0, 0, 140, 5, 1
	switch VAR_RESULT
	case 0, GCMS_Tutorial
	case 1, GCMS_Consignment
	case 2, GCMS_CreateMon
	case 3, GCMS_Status
	case 4, GCMS_AbilitySwap
	case 5, GCMS_ExitMenu
	release
	end
	
GCMS_ExitMenu::
	msgbox GCMS_Exiting
	release
	end

GCMS_AbilitySwap::
	bufferpartymonnick 0, 0
	msgbox swapMsg MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq GCMS_CancelAbilitySwap
	checkitem ITEM_BIG_PEARL, 1
	compare VAR_RESULT, 1
	goto_if_lt GCMS_SwapCancelledNoCurrency
	specialvar VAR_RESULT RyuSwapAbility
	compare VAR_RESULT, FALSE
	goto_if_eq GCMS_AlreadyHasHiddenAbility
	removeitem ITEM_BIG_PEARL, 1
	msgbox swapSuccess
	release
	end

GCMS_AlreadyHasHiddenAbility::
	msgbox GCMS_CantSwapHasHiddenMsg
	goto GCMS_Intro
	end

GCMS_SwapCancelledNoCurrency::
	msgbox GCMS_NotEnoughPearl
	release
	end

GCMS_CancelAbilitySwap::
	msgbox SwapCancelled
	release
	end

GCMS_CantSwapHasHiddenMsg:
	.string "The mon has its hidden ability.\nIt cannot be changed.$"

GCMS_NotEnoughPearl:
	.string "You do not have enough\nBig Pearls to perform the swap.$"

swapMsg:
	.string "Would you like to swap the\nability of your {STR_VAR_1}?\lIt will cost 1 Big Pearl.$"

swapSuccess:
	.string "Success! The ability has been\nswapped!$"

SwapCancelled:
	.string "Abilities will not be swapped.\nGoodbye!$"
	
GCMS_Tutorial::
	closemessage
	drawinfobox INFOBOXGCMS1
	msgbox GCMS_Page1
	closemessage
	removeinfobox
	drawinfobox INFOBOXGCMS2
	msgbox GCMS_Page2
	closemessage
	removeinfobox
	drawinfobox INFOBOXGCMS3
	msgbox GCMS_TutOutro
	closemessage
	removeinfobox
	goto GCMS_Intro

GCMS_Page1:
	.string "Tutorial page 1$"

GCMS_Page2:
	.string "Tutorial page 2$"

GCMS_TutOutro:
	.string "The egg will have the species,\nability, and moves of the first\lPokemon you consigned.\p         \pReturning to main menu.$"
	
GCMS_Status::
	bufferspeciesname 0, VAR_RYU_GCMS_SPECIES
	buffernumberstring 1, VAR_RYU_GCMS_VALUE
	msgbox GCMS_Summary
	closemessage
	msgbox GCMS_ReturningToMain
	goto GCMS_Intro
	release
	end
	
GCMS_CreateMon::
	checkitem ITEM_SHINY_CHARM, 1
	compare VAR_RESULT, TRUE
	goto_if_eq GCMS_ShinyCharmPresent
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq GCMS_NoSpace
	compare VAR_RYU_GCMS_SPECIES, 0
	goto_if_eq GCMS_NotMapping
	copyvar VAR_TEMP_8, VAR_RESULT
	bufferspeciesname 0, VAR_RYU_GCMS_SPECIES
	msgbox GCMS_CreateConfirm MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne GCMS_CancelCreate
	goto GCMS_NatureMenu

GCMS_NotMapping:
	msgbox GCMS_NoMonInGCMS
	closemessage
	goto GCMS_Intro
	
GCMS_ShinyCharmPresent::
	msgbox GCMS_ShinyCharmWarningMsg
	release
	end

GCMS_ShinyCharmWarningMsg:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}WARNING!\n"
	.string "You have a Shiny Charm with you.\p"
	.string "Creating a mon has been cancelled\n"
	.string "because the shiny charm rerolls\l"
	.string "your stats and ability.\p"
	.string "Go deposit your Shiny Charm before\n"
	.string "attempting to create your mon.$"

GCMS_NatureMenu::
	goto_if_set FLAG_RYU_DISABLE_NATURE_SELECTION_IN_GCMS, GCMS_GiveModdedMon
	msgbox GCMS_ChooseNatureMsg
	closemessage
	multichoicegrid 0, 0, 139, 4, 1
	copyvar VAR_TEMP_C, VAR_RESULT
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_CancelCreate:
	msgbox GCMS_CreationCancelled
	closemessage
	msgbox GCMS_ReturningToMain
	goto GCMS_Intro
	end
	
GCMS_NoSpace::
	msgbox GCMS_FreeUpASlot
	closemessage
	release
	end

GCMS_GiveModdedMon::
	special GivePlayerModdedMon
	bufferspeciesname 0, VAR_RYU_GCMS_SPECIES
	setvar VAR_RYU_GCMS_VALUE, 0
	setvar VAR_RYU_GCMS_SPECIES, 0
	msgbox GCMS_Successful
	clearflag FLAG_RYU_DISABLE_NATURE_SELECTION_IN_GCMS
	closemessage
	release
	end

GCMS_DevModeMonGive::
	msgbox DevModeMaxScaleQuery, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq GCMSDev_SetVarForMaxScale
	special PasscodeGiveMonWithNature
	bufferspeciesname 0, VAR_TEMP_4
	msgbox GCMS_DMPG_Ability
	multichoicedefault 0, 6, MULTI_DEV_GIVE_MON_ABILITY, 0, 1
	switch VAR_RESULT
	case 0, DevModeMonAbility1
	case 1, DevModeMonAbility2
	case 2, DevModeMonAbility3
	goto ryu_return

GCMSDev_SetVarForMaxScale::
	setvar VAR_TEMP_9, 69
	return

DevModeMaxScaleQuery:
	.string "Would you like the mon to be\nat maximum scale level?$"

GCMS_DMPG_Ability:
	.string "Please choose an Ability.$"

DevModeMonAbility1::
	setvar VAR_TEMP_7, 0
	special SetMonAbility 
	goto DevModeMonGender

DevModeMonAbility2::
	setvar VAR_TEMP_7, 1
	special SetMonAbility 
	goto DevModeMonGender

DevModeMonAbility3::
	setvar VAR_TEMP_7, 2
	special SetMonAbility 
	goto DevModeMonGender

DevModeMonGender::
	msgbox GCMS_DMPG_GENDER
	multichoicedefault 0, 6, MULTI_DEV_GIVE_MON_GENDER, 0, 1
	switch VAR_RESULT
	case 0, DevModeMonGender1
	case 1, DevModeMonGender2
	case 2, DevModeMonGender3
	goto ryu_return

DevModeMonGender1::
	setvar VAR_TEMP_9, 255
	goto DevModeMonShiny

DevModeMonGender2::
	setvar VAR_TEMP_9, 0
	goto DevModeMonShiny

DevModeMonGender3::
	setvar VAR_TEMP_9, 254
	goto DevModeMonShiny

GCMS_DMPG_GENDER:
	.string "Please choose a Gender.$"

DevModeMonShiny::
	msgbox GCMS_DMPG_SHINY
	multichoicedefault 0, 6, MULTI_DEV_GIVE_MON_SHINY, 0, 1
	switch VAR_RESULT
	case 0, DevModeMonPid
	case 1, DevModeMonPidShiny
	goto ryu_return

GCMS_DMPG_SHINY:
	.string "Please choose shiny status.$"

DevModeMonPidShiny::
	special SetMonShinyPid
	goto ryu_return

DevModeMonPid::
	special SetMonPid
	goto ryu_return

GCMS_ConsignmentQuery::
	msgbox GCMS_ConsignAgainQuery, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GCMS_Consignment
	release
	end

GCMS_ConsignAgainQuery:
	.string "Would you like to consign another\nPokémon?$"

GCMS_Consignment::
	getpartysize
	compare VAR_RESULT, 1
	goto_if_eq GCMS_NotEnoughPartyMons
	compare VAR_RYU_GCMS_SPECIES, 0
	goto_if_eq GCMS_ChooseInitialSpecies
	goto_if_unset FLAG_RYU_DISABLE_NATURE_SELECTION_IN_GCMS, GCMS_SetGCV
	buffernumberstring 1, VAR_RYU_GCMS_VALUE
	msgbox GCMS_PickSlot
	call RyuBufferPartyMonNames
	multichoice 10, 0, MULTI_DYNAMIC_6, 0
	specialvar VAR_TEMP_A, CheckIfSelectedSlotIsValid
	compare VAR_TEMP_A, FALSE
	goto_if_eq GCMS_CancelPartySlot
	switch VAR_RESULT
	case 0, GCMS_Slot1Selected
	case 1, GCMS_Slot2Selected
	case 2, GCMS_Slot3Selected
	case 3, GCMS_Slot4Selected
	case 4, GCMS_Slot5Selected
	case 5, GCMS_Slot6Selected
	goto GCMS_CancelPartySlot
	releaseall
	end

GCMS_SetGCV::
	msgbox GCMS_NoSacrifice
	numberentry 0, 9, 2
	compare VAR_RESULT, 31
	call_if_gt GCMS_SetMaxIV
	copyvar VAR_RYU_GCMS_VALUE, VAR_RESULT
	goto GCMS_CreateMon

GCMS_NoSacrifice::
	.string "Since you are generating a new mon,\nyou can simply choose the desired\lIV value.$"

GCMS_SetMaxIV::
	setvar VAR_RYU_GCMS_VALUE, 31
	return
	
GCMS_ChooseInitialSpecies:
	getpartysize
	compare VAR_RESULT, 1
	goto_if_eq GCMS_NotEnoughPartyMons
	setflag FLAG_TEMP_5
	msgbox GCMS_PickInitialSpecies
	call RyuBufferPartyMonNames
	multichoice 10, 0, MULTI_DYNAMIC_6, 0
	specialvar VAR_TEMP_A, CheckIfSelectedSlotIsValid
	compare VAR_TEMP_A, FALSE
	goto_if_eq GCMS_CancelPartySlot
	copyvar VAR_0x8000, VAR_RESULT
	msgbox GCMS_PersonalitySaveQuery
	bufferdynamicmulti GCMS_Personalityquery1, GCMS_Personalityquery2
	multichoice 0, 100, MULTI_DYNAMIC_2, 1
	compare VAR_RESULT, 0
	call_if_eq GCMS_DisableNatureSelect
	switch VAR_0x8000
	case 0, GCMS_Slot1Selected
	case 1, GCMS_Slot2Selected
	case 2, GCMS_Slot3Selected
	case 3, GCMS_Slot4Selected
	case 4, GCMS_Slot5Selected
	case 5, GCMS_Slot6Selected
	goto GCMS_CancelPartySlot

GCMS_DisableNatureSelect:
	msgbox GCMS_NatureDisabled
	closemessage
	setflag FLAG_RYU_DISABLE_NATURE_SELECTION_IN_GCMS
	return

GCMS_NatureDisabled:
	.string "When you create the result Pokémon,\nIt will have the source mon's\ldata with new IV's.\pYou will not be able to select a\nnature at that time.$"

GCMS_PersonalitySaveQuery:
	.string "Keeping personality will also\nkeep Gender, Nature, Level, EV's,\lNickname, and shinyness.\pKeep or Discard personality?$"

GCMS_Personalityquery1:
	.string "Keep Personality$"

GCMS_Personalityquery2:
	.string "Discard Personality$"
	
	
GCMS_Slot1Selected::
	setvar VAR_TEMP_9, 0
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	case 4, GCMS_EGG
	
GCMS_Slot2Selected::
	setvar VAR_TEMP_9, 1
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	case 4, GCMS_EGG
	
GCMS_Slot3Selected::
	setvar VAR_TEMP_9, 2
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	case 4, GCMS_EGG
	
GCMS_Slot4Selected::
	setvar VAR_TEMP_9, 3
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	case 4, GCMS_EGG
	
GCMS_Slot5Selected::
	setvar VAR_TEMP_9, 4
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	case 4, GCMS_EGG
	
GCMS_Slot6Selected::
	setvar VAR_TEMP_9, 5
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	case 4, GCMS_EGG

GCMS_Confirm::
	compare VAR_RYU_GCMS_VALUE, 31
	goto_if_ge GCMS_MaxReached
	addvar VAR_RYU_GCMS_VALUE, 1
	addvar VAR_TEMP_9, 1
	buffernumberstring 0, VAR_TEMP_9
	msgbox GCMS_ConsignSuccess
	closemessage
	goto GCMS_ConsignmentQuery
	end

GCMS_Legendary::
	msgbox GCMS_CantConsignLegendaries
	closemessage
	goto GCMS_Consignment

GCMS_EGG::
	msgbox GCMS_CantConsignEggs
	closemessage
	goto GCMS_Consignment

GCMS_MaxReached::
	msgbox GCMS_YouHaveReached
	goto GCMS_Intro
	
GCMS_CancelPartySlot:
	msgbox GCMS_ReturnWithSpecimen
	closemessage
	release
	end
	
GCMS_SpeciesNotCorrect::
	bufferspeciesname 0, VAR_RYU_GCMS_SPECIES
	msgbox GCMS_SpeciesNotMatched
	closemessage
	msgbox GCMS_ReturningToMain
	closemessage
	goto GCMS_Intro
	end
	
GCMS_NotEnoughPartyMons::
	msgbox GCMS_PartyCantBeEmpty
	release
	end

GCMS_CantConsignEggs::
	.string "You cannot put an egg into the\nGCMS.\pYou must insert a non-legendary\nPokemon to start the process.$"

GCMS_NoMonInGCMS::
	.string "You are not currently mapping\ngenes for any species.\pPlease return to main menu and\nconsign a mon to start the process.$"

GCMS_CantConsignLegendaries:
	.string "You cannot consign legendaries\nor mythicals.$"
	
GCMS_YouHaveReached:
	.string "You have reached the maximum\nachievable GCV. No more mons may\lbe consigned.$"
	
GCMS_IntroMsg:
	.string "Welcome to the\n{COLOR LIGHT_GREEN}{SHADOW GREEN}Genetic Code Mapping System.\p{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Please make a selection.$"
	
GCMS_ReturningToMain:
	.string "Returning to Main Menu.$"
	
GCMS_Exiting:
	.string "Now exiting the {COLOR LIGHT_GREEN}{SHADOW GREEN}GCMS{COLOR DARK_GREY}{SHADOW LIGHT_GREY}...$"
	
GCMS_TutQuery:
    .string "Would you like a rundown of how\n"
    .string "the {COLOR LIGHT_GREEN}{SHADOW GREEN}GCMS{COLOR DARK_GREY}{SHADOW LIGHT_GREY}works?$"
	
GCMS_ReturnWithSpecimen:
    .string "Please return when you have a\n"
    .string "specimen to consign to research.$"

GCMS_ConsignQuery:
    .string "Would you like to consign a\n"
    .string "Pokémon to be researched?$"

GCMS_CreateMonMsg:
    .string "Would you like to create a Pokémon\n"
    .string "using the genetic code mapping\l"
    .string "you have so far?$"

GCMS_Summary:
    .string "You are currently mapping genes\n"
    .string "for the species: {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_1}\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}You have mapped{COLOR LIGHT_BLUE}{SHADOW BLUE} {STR_VAR_2} {COLOR DARK_GREY}{SHADOW LIGHT_GREY}sequences.$"

GCMS_CreateConfirm:
    .string "Are you sure you want to create\n"
    .string "a {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY} with the codes you\l"
    .string "have mapped?$"
	
GCMS_FreeUpASlot:
    .string "You do not have enough space in\n"
    .string "your party to take the created\l"
    .string "specimen.\p"
    .string "Please return when you have space.$"

GCMS_ChooseNatureMsg:
	.string "Please choose a temperament...$"
	
GCMS_Successful:
    .string "Success! A {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_1} {COLOR DARK_GREY}{SHADOW LIGHT_GREY}has\n"
    .string "been made!$"
	
GCMS_PickSlot:
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}You have mapped{COLOR LIGHT_BLUE}{SHADOW BLUE} {STR_VAR_2} {COLOR DARK_GREY}{SHADOW LIGHT_GREY}sequences.\n"
    .string "Choose which species to Consign.$"
	
GCMS_PickInitialSpecies:
    .string "You are not currently mapping\n"
    .string "genes for any species.\p"
	.string "Please pick one to initialize the\n"
	.string "system.$"
	
GCMS_SpeciesNotMatched:;
    .string "The specimen you selected does not\n"
    .string "match the species you're currently\l"
    .string "mapping.\p"
    .string "Please pick a {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}.$"

GCMS_PartyCantBeEmpty:
    .string "You can't consign your last\n"
    .string "party mon. Please return with more.$"
	
GCMS_ConsignSuccess:
    .string "You have consigned the Pokémon in\n"
    .string "slot number {STR_VAR_1}.$"
	
GCMS_CreationCancelled:
    .string "The genetic map will be preserved.$"

GCMS_Tutorial1:
    .string "This PC program allows you to\n"
    .string "have much more control over the\l"
    .string "genetic viability of your Pokémon.\p"
    .string "The first part is where you store\n"
    .string "the species you want to work on.\p"
    .string "The second part is where you\n"
    .string "consign specimens to the research\l"
    .string "system, so their genes can be\l"
    .string "sampled.$"
	
GCMS_Tutorial2:
    .string "When you've reached the gene\n"
    .string "viability value you want, for ex-\l"
    .string "ample... 31, you may then have\p"
    .string "the system create a new pokemon.\n"
    .string "Pick this mon up to raise as per\l"
    .string "normal.\p"
	.string "This then resets your stored\n"
	.string "genetic code value, and species.$"









