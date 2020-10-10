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
	msgbox GCMS_ChooseNatureMsg
	closemessage
	multichoicegrid 0, 0, 139, 4, 1
	switch VAR_RESULT
	case 0, GCMS_ChooseNature0
	case 1, GCMS_ChooseNature1
	case 2, GCMS_ChooseNature2
	case 3, GCMS_ChooseNature3
	case 4, GCMS_ChooseNature4
	case 5, GCMS_ChooseNature5
	case 6, GCMS_ChooseNature6
	case 7, GCMS_ChooseNature7
	case 8, GCMS_ChooseNature8
	case 9, GCMS_ChooseNature9
	case 10, GCMS_ChooseNature10
	case 11, GCMS_ChooseNature11
	case 12, GCMS_ChooseNature12
	case 13, GCMS_ChooseNature13
	case 14, GCMS_ChooseNature14
	case 15, GCMS_ChooseNature15
	case 16, GCMS_ChooseNature16
	case 17, GCMS_ChooseNature17
	case 18, GCMS_ChooseNature18
	case 19, GCMS_ChooseNature19
	case 20, GCMS_ChooseNature20
	case 21, GCMS_ChooseNature21
	case 22, GCMS_ChooseNature22
	case 23, GCMS_ChooseNature23
	end
	
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
	
GCMS_ChooseNature0::
	setvar VAR_TEMP_C, 0
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature1::
	setvar VAR_TEMP_C, 1
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon

GCMS_ChooseNature2::
	setvar VAR_TEMP_C, 2
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature3::
	setvar VAR_TEMP_C, 3
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon

GCMS_ChooseNature4::
	setvar VAR_TEMP_C, 4
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature5::
	setvar VAR_TEMP_C, 5
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature6::
	setvar VAR_TEMP_C, 6
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature7::
	setvar VAR_TEMP_C, 7
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature8::
	setvar VAR_TEMP_C, 8
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature9::
	setvar VAR_TEMP_C, 9
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature10::
	setvar VAR_TEMP_C, 10
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature11::
	setvar VAR_TEMP_C, 11
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature12::
	setvar VAR_TEMP_C, 12
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature13::
	setvar VAR_TEMP_C, 13
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature14::
	setvar VAR_TEMP_C, 14
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature15::
	setvar VAR_TEMP_C, 15
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature16::
	setvar VAR_TEMP_C, 16
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature17:
	setvar VAR_TEMP_C, 17
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature18::
	setvar VAR_TEMP_C, 18
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature19::
	setvar VAR_TEMP_C, 19
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature20::
	setvar VAR_TEMP_C, 20
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature21::
	setvar VAR_TEMP_C, 21
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature22::
	setvar VAR_TEMP_C, 22
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature23::
	setvar VAR_TEMP_C, 23
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon
	
GCMS_ChooseNature24::
	setvar VAR_TEMP_C, 24
	goto_if_set FLAG_RYU_DEVELOPER_POKEMON_MENU, GCMS_DevModeMonGive
	goto GCMS_GiveModdedMon

GCMS_GiveModdedMon::
	special GivePlayerModdedMon
	bufferspeciesname 0, VAR_RYU_GCMS_SPECIES
	setvar VAR_RYU_GCMS_VALUE, 0
	setvar VAR_RYU_GCMS_SPECIES, 0
	msgbox GCMS_Successful
	closemessage
	release
	end

GCMS_DevModeMonGive::
	special PasscodeGiveMonWithNature
	bufferspeciesname 0, VAR_TEMP_4
	msgbox GCMS_DMPG_Ability
	multichoicedefault 0, 6, MULTI_DEV_GIVE_MON_ABILITY, 0, 1
	switch VAR_RESULT
	case 0, DevModeMonAbility1
	case 1, DevModeMonAbility2
	case 2, DevModeMonAbility3
	goto ryu_return

GCMS_DMPG_Ability:
	.string "Please choose an Ability.$"

DevModeMonAbility1::
	setvar VAR_TEMP_7, 0
	special SetMonAbility 
	goto ryu_return

DevModeMonAbility2::
	setvar VAR_TEMP_7, 1
	special SetMonAbility 
	goto ryu_return

DevModeMonAbility3::
	setvar VAR_TEMP_7, 2
	special SetMonAbility 
	goto ryu_return
	
GCMS_Consignment::
	getpartysize
	compare VAR_RESULT, 1
	goto_if_eq GCMS_NotEnoughPartyMons
	compare VAR_RYU_GCMS_SPECIES, 0
	goto_if_eq GCMS_ChooseInitialSpecies
	buffernumberstring 1, VAR_RYU_GCMS_VALUE
	msgbox GCMS_PickSlot
	call RyuBufferPartyMonNames
	multichoicedefault 0, 0, MULTI_SELECT_PARTY_SLOT, 6, 0
	switch VAR_RESULT
	case 0, GCMS_Slot1Selected
	case 1, GCMS_Slot2Selected
	case 2, GCMS_Slot3Selected
	case 3, GCMS_Slot4Selected
	case 4, GCMS_Slot5Selected
	case 5, GCMS_Slot6Selected
	case 6, GCMS_CancelPartySlot
	goto GCMS_CancelPartySlot
	releaseall
	end
	
GCMS_ChooseInitialSpecies:
	getpartysize
	compare VAR_RESULT, 1
	goto_if_eq GCMS_NotEnoughPartyMons
	setflag FLAG_TEMP_5
	msgbox GCMS_PickInitialSpecies
	closemessage
	call RyuBufferPartyMonNames
	multichoicedefault 0, 0, MULTI_SELECT_PARTY_SLOT, 6, 0
	switch VAR_RESULT
	case 0, GCMS_Slot1Selected
	case 1, GCMS_Slot2Selected
	case 2, GCMS_Slot3Selected
	case 3, GCMS_Slot4Selected
	case 4, GCMS_Slot5Selected
	case 5, GCMS_Slot6Selected
	case 6, GCMS_CancelPartySlot
	goto GCMS_CancelPartySlot
	
	
GCMS_Slot1Selected::
	setvar VAR_TEMP_9, 0
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	
GCMS_Slot2Selected::
	setvar VAR_TEMP_9, 1
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	
GCMS_Slot3Selected::
	setvar VAR_TEMP_9, 2
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	
GCMS_Slot4Selected::
	setvar VAR_TEMP_9, 3
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	
GCMS_Slot5Selected::
	setvar VAR_TEMP_9, 4
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary
	
GCMS_Slot6Selected::
	setvar VAR_TEMP_9, 5
	specialvar VAR_RESULT, RyuSacrificeMon
	switch VAR_RESULT
	case 0, GCMS_SpeciesNotCorrect
	case 1, GCMS_Confirm
	case 2, GCMS_Legendary

GCMS_Confirm::
	compare VAR_RYU_GCMS_VALUE, 31
	goto_if_ge GCMS_MaxReached
	addvar VAR_RYU_GCMS_VALUE, 1
	addvar VAR_TEMP_9, 1
	buffernumberstring 0, VAR_TEMP_9
	msgbox GCMS_ConsignSuccess
	closemessage
	goto GCMS_Consignment
	end

GCMS_Legendary::
	msgbox GCMS_CantConsignLegendaries
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
    .string "Success! A {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_1} {COLOR DARK_GREY}{SHADOW LIGHT_GREY}egg has\n"
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
    .string "the system create an egg for you\n"
    .string "to pick up and then raise as per\l"
    .string "normal.\p"
	.string "This then resets your stored\n"
	.string "genetic code value, and species.$"









