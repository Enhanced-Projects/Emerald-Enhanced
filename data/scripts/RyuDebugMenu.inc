@@MAIN DEBUG MENU==================================================================================
.set PRIMARY_ABILITY, 0
.set SECONDARY_ABILITY, 1
.set HIDDEN_ABILITY, 2

RyuDevSwitch::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	setflag FLAG_RYU_DEV_MODE
	setflag FLAG_RYU_CHEATS_USED
	@clearflag FLAG_HIDE_103_TEST_TRAINER
	msgbox RyuNowDeveloper MSGBOX_SIGN
	end
	
RyuNowDeveloper:
	.string "{PLAYER} is now a developer.$"
	
RyuDebugMenuScript::
	msgbox RyuDebug_msg MSGBOX_SIGN
	multichoicedefault 0, 0, MULTI_DEV_MENU_MAIN, 8, 0
	switch VAR_RESULT
	case 0, RyuDebug_UtilitiesMenu
	case 1, RyuDebug_Utility1
	case 2, RyuDebug_PasscodeMenu
	case 3, RyuDebug_DevMonQuickStart
	case 4, RyuDebug_pokeedit
	case 5, RyuDebug_enableWaystone
	case 6, RyuDebug_DisableDebug
	case 7, RyuDebug_ShowBetaMenu
	case 8, RyuDebug_cancel
	goto RyuDebug_cancel
	
RyuDebug_menu_nodevcheck::
	msgbox RyuDebug_msg MSGBOX_SIGN
	multichoicedefault 0, 0, MULTI_DEV_MENU_MAIN, 8, 0
	switch VAR_RESULT
	case 0, RyuDebug_UtilitiesMenu
	case 1, RyuDebug_Utility1
	case 2, RyuDebug_PasscodeMenu
	case 3, RyuDebug_DevMonQuickStart
	case 4, RyuDebug_pokeedit
	case 5, RyuDebug_enableWaystone
	case 6, RyuDebug_DisableDebug
	case 7, RyuDebug_ShowBetaMenu
	case 8, RyuDebug_cancel
	goto RyuDebug_cancel

RyuDebug_ShowBetaMenu::
	msgbox RDB_OpeningBetaMenu
	closemessage
	goto RDB_BetaMenuStandalone

RDB_OpeningBetaMenu:
	.string "Opening beta menu.$"


RyuDebug_UtilitiesMenu:
	scrollingmultichoice SCROLLINGMULTICHOICE_DEBUGUTILITIES, 0, 0, 9, 1
	switch VAR_RESULT
	case 0, RyuDebug_Phasing
	case 1, RyuDebug_Encounters
	case 2, RyuDebug_ViewTempVars
	case 3, RyuDebug_setTime
	case 4, RyuDebug_BattleSim
	case 5, RyuSetExpMultMenu
	case 6, RyuDebug_giveAllBadges
	case 7, RyuDebug_HealParty
	case 8, RyuDebug_SaveFileDebug
	case 9, RyuDebug_FillTheDex
	case 10, RDB_GiveOrTakeAllAchievements
	case 11, RDB_GetCurrentAndMaxAP
	case 12, RDB_CheckFactionRelations
	case 13, RDB_AlchemyInfo
	case 14, RDB_ToggleLevelCap
	case 15, RDB_EnableRealEstate
	case 16, RDB_SpawnFollowerMultiMenu
	case 17, RyuDebug_menu_nodevcheck
	goto RyuDebug_menu_nodevcheck

RDB_SpawnFollowerMultiMenu::
	msgbox RDB_SpawnWhichFollower
	scrollingmultichoice SMC_RYUFOLLOWERDEBUGSUBMENU, 0, 0, 6, 1
	switch VAR_RESULT
	case 0, RDB_SpawnMinnie
	case 1, RDB_SpawnShelly
	case 2, RDB_SpawnLanette
	case 3, RDB_SpawnDawn
	case 4, RDB_SpawnBrendan
	case 5, RDB_SpawnLeaf
	case 6, RDB_SpawnCourtney
	case 7, RDB_SpawnJoy
	case 8, RDB_NONCOMBATFOLLOWER
	case 9, RDB_SpawnBlaise
	case 10, RDB_SpawnTiana
	case 11, RDB_SpawnHexer
	case 12, RDB_RETURNTOMAIN
	goto RDB_RETURNTOMAIN

RDB_SpawnWhichFollower:
	.string "Spawn which follower?$"

RDB_SpawnMinnie::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_TWIN, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end

RDB_SpawnShelly::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_AQUA_MEMBER_F, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end

RDB_SpawnLanette::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_WOMAN_2, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end
	
RDB_SpawnDawn::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end
	
RDB_SpawnBrendan::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end
	
RDB_SpawnLeaf::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_LEAF, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end
	
RDB_SpawnCourtney::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_F, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end
	
RDB_SpawnJoy::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_NURSE, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end

RDB_SpawnBlaise::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_MAGMA_MEMBER_M, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end

RDB_SpawnTiana::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_LASS, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end

RDB_SpawnHexer::
	call RyuForceCancelFollowerForQuest
	createfollower OBJ_EVENT_GFX_HEX_MANIAC, RyuFollowerSelectNPCScript, DIR_SOUTH
	goto RDB_ExplainSpawnFollower
	end

RDB_NONCOMBATFOLLOWER::
	goto RDB_SpawnFollowerMultiMenu

RDB_ExplainSpawnFollower::
	msgbox RDB_ExplainSpawnMsg
	closemessage
	goto RyuDebug_UtilitiesMenu

RDB_ExplainSpawnMsg:
	.string "You have spawned in a follower.\nNote that this skips all quest\pchecks and just directly applies\ntheir base script.\lBugs may appear when talked to.$"
	
RDB_RETURNTOMAIN::
	goto RyuDebug_UtilitiesMenu

RDB_EnableRealEstate::
	callnative SetPlayerRealtorStatus
	release
	end

RDB_CheckFactionRelations::
	callnative RyuDebug_ViewFactionRelations
	msgbox factiondebugmsg
	closemessage
	release
	end

factiondebugmsg:
	.string "Faction Relations Values:\p"
	.string "Pokefans: {STR_VAR_1}. Naturalists: {STR_VAR_2}.\n"
	.string "Athletes: {STR_VAR_3}. Outcasts: {RYU_STR_1}.\p"
	.string "Professionals: {RYU_STR_2}. Nobles: {RYU_STR_3}.\n"
	.string "Students: {RYU_STR_4}. Others: N/A.$"

RDB_GetCurrentAndMaxAP::
	callnative APDebugInfo
	buffernumberstring 0, VAR_TEMP_1
	buffernumberstring 1, VAR_TEMP_2
	msgbox RDB_APDebug
	closemessage
	goto RyuDebug_UtilitiesMenu

RDB_APDebug:
	.string "You currently have {STR_VAR_2}/{STR_VAR_1} AP active.$"

RyuDebug_giveAllBadges::
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	playse SE_EXPMAX
	goto RyuDebug_UtilitiesMenu

RyuDebug_FillTheDex::
	special FillTheDex
	msgbox RDB_FillDex
	goto RyuDebug_UtilitiesMenu

RDB_FillDex:
	.string "Dex pages filled in.$"

RyuDebug_HealParty::
	special HealPlayerParty
	playse SE_EXPMAX
	goto RyuDebug_UtilitiesMenu
	
RyuDebug_pokeedit::
	msgbox OpeningPokeEdit
	goto RyuPokeEditMenu
	release
	end

OpeningPokeEdit:
	.string "Opening Poke Edit...$"

RyuDebug_money::
	addmoney 250000
	msgbox RyuDebug_money_text MSGBOX_DEFAULT
	return

RyuDebug_Encounters::
	goto_if_set FLAG_RYU_DEV_DISENC, RyuDebug_EnENC
	setflag FLAG_RYU_DEV_DISENC
	msgbox RyuEncDisabled
	goto RyuDebug_UtilitiesMenu
	
RyuDebug_EnENC::
	clearflag FLAG_RYU_DEV_DISENC
	msgbox RyuEncEnabled
	goto RyuDebug_UtilitiesMenu
	
RyuEncDisabled:
	.string "Dev Repel on$"
	
RyuEncEnabled:
	.string "Dev Repel off$"

RyuDebug_money_text:
	.string "Given ¥250,000.$"

RyuDebug_DisableDebug::
	clearflag FLAG_RYU_DEV_MODE
	setflag FLAG_HIDE_103_TEST_TRAINER
	msgbox DevModeDisabled MSGBOX_DEFAULT
	releaseall
	end

Ryu_saveViewerEnabled:
	.string "First variable set to beacon the\nsave viewer.\pSave the game twice to make sure\nboth save banks are the same!$"

RyuDebug_Phasing::
	goto_if_set FLAG_RYU_COLLISION_OFF, Ryu_DisablePhasing
	setflag FLAG_RYU_COLLISION_OFF
	setflag FLAG_TOBY_TRAINER_SIGHT
	msgbox Ryu_CollisionOffMsg
	goto RyuDebug_UtilitiesMenu

Ryu_DisablePhasing::
	clearflag FLAG_RYU_COLLISION_OFF
	clearflag FLAG_TOBY_TRAINER_SIGHT
	msgbox Ryu_CollisionOnMsg
	goto RyuDebug_UtilitiesMenu

Ryu_CollisionOffMsg:
	.string "Entered the Ethereal plane.$"

Ryu_CollisionOnMsg:
	.string "Returned to Material plane.$"

DevModeDisabled:
	.string "{PLAYER} is no longer a developer.$"
	
EGC_CLEARGAMECLEARFLAG::
	clearflag FLAG_SYS_GAME_CLEAR
	end

RyuDebug_waystone::
	additem ITEM_WAYSTONE, 1
	goto RyuDebug_menu_nodevcheck
	releaseall
	end

RyuDebug_EnableDexnav::
	setflag FLAG_SYS_DEXNAV_GET
	release
	end

RDB_ToggleLevelCap::
	msgbox RDB_LevelCapToggled
	goto_if_set FLAG_RYU_IGNORE_CAP, RDB_EnableCap
	setflag FLAG_RYU_IGNORE_CAP
	goto RyuDebug_UtilitiesMenu

RDB_EnableCap::
	clearflag FLAG_RYU_IGNORE_CAP
	goto RyuDebug_UtilitiesMenu

RDB_LevelCapToggled:
	.string "Level Cap Toggled.$"

RyuDebug_enableWaystone::
	additem ITEM_WAYSTONE, 1
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	setflag FLAG_RYU_LANDMARK_MH
	setflag FLAG_RYU_LANDMARK_LCCDEPTSTORE
	setflag FLAG_LANDMARK_SNOWY_SHORE
	setflag FLAG_LANDMARK_AQUA_OFFICE
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	return

RyuDebug_ViewTempVars::
	special RyuCheckTempVars
	msgbox RDB_TempVarsViewMsg
	goto RyuDebug_UtilitiesMenu

RDB_TempVarsViewMsg:
	.string "{STR_VAR_1}$"

RyuDebug_Utility1::
	addmoney 1000000
	release
	end

RDB_DoLittlerootLatiCheck::
	buffernumberstring 0, VAR_ROAMER_POKEMON
	buffernumberstring 1, VAR_LITTLEROOT_INTRO_STATE
	msgbox RDBLRT2
	closemessage
	release
	end

RDBTeleport:
	.string "Teleport?$"

RDBLRT2:
	.string "Your roamer is {STR_VAR_1}\nYour Tutorial state is {STR_VAR_2}$"

RDB_LifeSkills:
	.string "Alchemy- EXP: {STR_VAR_1} Level: {STR_VAR_2}\n"
	.string "Botany- EXP: {STR_VAR_3} Level: {RYU_STR_1}\l"
	.string "Mining- EXP: {RYU_STR_2} Level: {RYU_STR_3}$"

RDB_AlchemyInfo::
	callnative RyuDebug_CheckAlchemyStatus
	msgbox RDB_AlchemyInfoMsg
	closemessage
	release
	end

RDB_AlchemyInfoMsg:
	.string "Has Alchemy effect active? {STR_VAR_1}\n"
	.string "Current effect is {STR_VAR_2},\l"
	.string "with {STR_VAR_3} charges left.\p"
	.string "Player's alchemy level is {RYU_STR_1}.\n"
	.string "Player's Alchemy exp is {RYU_STR_2}.$"

RDB_GiveOrTakeAllAchievements::
	msgbox RDB_GiveTakeAchMsg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RDB_GiveAllAch
	goto RDB_TakeAllAch

RDB_TakeAllAch::
	setvar VAR_TEMP_B, 0
	callnative Ryu_GiveOrTakeAllAchievments
	msgbox RDB_Finished
	release
	end

RDB_GiveAllAch::
	setvar VAR_TEMP_B, 69
	callnative Ryu_GiveOrTakeAllAchievments
	msgbox RDB_Finished
	release
	end

RDB_Finished:
	.string "Finished giving or taking ach's.$"

RDB_GiveTakeAchMsg::
	.string "Select yes to give\nor no to take all achievements.$"

RDB_Text:
	.string "Gained 4 badges.$"

RyuDebug_SaveFileDebug::
	special CheckSaveFileSize
	msgbox SaveFileStructMsg
	release
	end

SaveFileStructMsg:
	.string "SaveBlock1 size is {STR_VAR_1}/15872 bytes.\nSaveBlock2 size is {STR_VAR_2}/3968 bytes.$"

exampletext:
	.string "This is standard text.\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}This is a partner speaking.\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}This is player speaking\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(This is green narration text.\n"
	.string " There's a space at the beginning of\l"
	.string " newlines and new pages too.)$"

RDB_GiveRandomFrontierMons::
	compare VAR_TEMP_5, 0
	goto_if_eq GiveRandomFrontiermonsEnd
	subvar VAR_TEMP_5, 1
	goto RDB_GiveRandomFrontierMonsLoop

RDB_GiveRandomFrontierMonsLoop::
	random 735
	addvar VAR_RESULT, 97
	copyvar VAR_TEMP_6, VAR_RESULT 
	special RyuGiveFrontierMon
	goto RDB_GiveRandomFrontierMons

GiveRandomFrontiermonsEnd::
	msgbox RDB_GRFMD
	clearflag FLAG_RYU_PASSCODE_FRONTIER_MON_DEV
	closemessage
	release
	end

RDB_GRFMD:
	.string "Given 6 random frontier mons.$"

RDB_u1_EnableRandomize::
	setflag FLAG_RYU_RANDOMIZE_MUSIC
	release
	end

RDB_Readout:
	.string "It is currently: {STR_VAR_1}:{STR_VAR_2}::{STR_VAR_3}  $"

RyuDebug_setTime::
	gettime
	buffernumberstring 0, VAR_0x8000
	buffernumberstring 1, VAR_0x8001
	buffernumberstring 2, VAR_0x8002
	msgbox RDB_Readout
	closemessage
	msgbox settimequery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne ryu_end
	fadescreen 1
	special StartWallClock
	waitstate
	gettime
	buffernumberstring 0, VAR_0x8000
	buffernumberstring 1, VAR_0x8001
	buffernumberstring 2, VAR_0x8002
	msgbox RDB_Readout_2
	goto RyuDebug_UtilitiesMenu

settimequery:
	.string "Would you like to change the time?$"

RDB_Readout_2:
	.string "Time was changed to: {STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}  $"

RyuDebug_GiveItems::
	msgbox RDB_GiveTMsQuery MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq RyuDebug_Init_GiveAllTMs
	msgbox AlchemyKitQuery MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq RyuDebug_GiveAlchemyKit
	msgbox ItemsKitQuery MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq RyuDebug_GiveItemsKit
	msgbox RyuDebug_MoneyMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq RyuDebug_money
	msgbox KeyItemsKitQuery MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq RyuDebug_GiveKeyItemsKit
	goto RyuDebug_menu_nodevcheck

RyuDebug_Init_GiveAllTMs::
	setvar VAR_TEMP_2, 482
	msgbox RyuDebug_GiveAllTMsBeginMsg MSGBOX_DEFAULT
	closemessage
	goto RyuDebug_GiveAllTMs
	
RyuDebug_GiveAllTMs::
	additem VAR_TEMP_2, 1
	addvar VAR_TEMP_2, 1
	goto RyuDebug_ReturnCallTMs
	
RyuDebug_ReturnCallTMs::
	compare VAR_TEMP_2, 546
	goto_if_eq RyuDebugGiveTMsDone
	goto RyuDebug_GiveAllTMs
	
RyuDebugGiveTMsDone::
	goto ryu_return

RyuDebug_GiveAlchemyKit::
	setvar VAR_RYU_PLAYER_ALCHEMY_SKILL, 5
	setvar VAR_RYU_ALCHEMY_EXP, 5000
	additem ITEM_FRESH_WATER, 100
	additem ITEM_TONIC_WATER, 100
	additem ITEM_MINERAL_WATER, 100
	additem ITEM_MUSCLE_POWDER, 100
	additem ITEM_SMART_POWDER, 100
	additem ITEM_STARDUST, 100
	additem ITEM_TOUGH_POWDER, 100
	additem ITEM_RAWST_BERRY, 100
	additem ITEM_BRIGHT_POWDER, 100
	additem ITEM_ORAN_BERRY, 100
	setvar VAR_RYU_ALCHEMY_COPPER, 50000
	setvar VAR_RYU_ALCHEMY_SILVER, 50000
	setvar VAR_RYU_ALCHEMY_GOLD, 50000

RyuDebug_GiveItemsKit:
	additem ITEM_FULL_RESTORE, 100
	additem ITEM_MAX_ELIXIR, 100
	additem ITEM_MAX_REVIVE, 100
	additem ITEM_HEART_SCALE, 100
	additem ITEM_PP_MAX, 100
	additem ITEM_RARE_CANDY, 200
	additem ITEM_LUXURY_BALL, 100
	additem ITEM_MASTER_BALL, 100
	additem ITEM_MAX_REPEL, 100
	additem ITEM_BIG_PEARL, 100
	return

RyuDebug_GiveKeyItemsKit::
	additem ITEM_MEGA_BRACELET, 1
	additem ITEM_EXP_DRIVE, 1
	additem ITEM_FORECASTER, 1
	additem ITEM_IMPRINTER, 1
	additem ITEM_EXP_SHARE, 1
	additem ITEM_SOOT_SACK, 1
	additem ITEM_RECIPE_BOOK, 1
	additem ITEM_REAGENT_POUCH, 1
	return

RyuDebug_MoneyMsg:
	.string "Give Dev Mode money payout?$"

RDB_GiveTMsQuery:
	.string "Would you like all TMs?$"
	
RyuDebug_GiveAllTMsDoneMsg:
	.string "Finished giving starter kit.$"
	
RyuDebug_GiveAllTMsBeginMsg:
	.string "Giving all tms...$"

AlchemyKitQuery:
	.string "Do you want Alchemy items?$"

ItemsKitQuery:
	.string "Do you want adventuring items?$"

KeyItemsKitQuery:	
	.string "Do you want special Key Items?$"

RyuDebug_givemonsquery:
	.string "Would you like to be given\nall the Pokémon in the game?$"

RyuDebug_cancel::
	closemessage
	end

RyuDebug_msg:
	.string "What would you like to activate?$"
	
RyuDebug_Init_GiveAll::
	setvar VAR_TEMP_0, 1
	msgbox RyuDebug_GiveAllBeginMsg MSGBOX_DEFAULT
	goto RyuDebug_GiveAllMons
	
RyuDebug_GiveAllMons::
	givemon VAR_TEMP_0, 5, 0x0
	addvar VAR_TEMP_0, 1
	goto RyuDebug_ReturnCall
	
RyuDebug_ReturnCall::
	compare VAR_TEMP_0, 152
	goto_if_eq RyuDebugGivePokeDone
	goto RyuDebug_GiveAllMons
	
RyuDebugGivePokeDone::
	msgbox RyuDebug_GiveAllDoneMsg MSGBOX_DEFAULT
	release
	end
	
RyuDebug_GiveAllDoneMsg:
	.string "Finished Giving all mons.$"
	
RyuDebug_GiveAllBeginMsg:
	.string "The process will begin when you\nclose this message.\lIt will take 30 seconds to a minute\lto complete, and the game may appear\lto be frozen.\pIf music is still playing,\nit is not frozen. Enjoy!$"

RyuDebug_DevMonQuickStart::
	setflag FLAG_RYU_IGNORE_CAP @@why not just max lv
	setvar VAR_TEMP_A, NATURE_MODEST     
	setvar VAR_TEMP_B, SPECIES_PRIMARINA
	setvar VAR_TEMP_C, HIDDEN_ABILITY
	setvar VAR_TEMP_D, MON_FEMALE @@This is gender selection. Should be MON_FEMALE, MON_MALE, or MON_GENDERLESS.
	setvar VAR_TEMP_E, ITEM_EXPERT_BELT
	setvar VAR_TEMP_1, MOVE_PSYCHIC
	setvar VAR_TEMP_2, MOVE_MOONBLAST
	setvar VAR_TEMP_3, MOVE_SPARKLING_ARIA
	setvar VAR_TEMP_4, MOVE_THUNDERBOLT
	callnative RyuGiveDevMon
	@@
	@@
	@@(this is to make it easy to tell between which mon you are editing)
	@@
	@@
	setvar VAR_TEMP_A, NATURE_ADAMANT
	setvar VAR_TEMP_B, SPECIES_PHEROMOSA
	setvar VAR_TEMP_C, PRIMARY_ABILITY
	setvar VAR_TEMP_D, MON_FEMALE
	setvar VAR_TEMP_E, ITEM_EXPERT_BELT
	setvar VAR_TEMP_1, MOVE_HIGH_HORSEPOWER
	setvar VAR_TEMP_2, MOVE_TRIPLE_KICK
	setvar VAR_TEMP_3, MOVE_POISON_JAB
	setvar VAR_TEMP_4, MOVE_CRABHAMMER
	callnative RyuGiveDevMon
	@@ finished, go to next stage.
	special HealPlayerParty
	goto RyuDebug_QuickItemFlagStart


RyuDebug_QuickItemFlagStart::
	additem ITEM_WAYSTONE, 1
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	call RyuDebug_enableWaystone
	special RyuSetUpSaveBlockStuff
	msgbox RyuNewGameQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuDebug_SkipTutorial
	closemessage
	goto RyuDebug_menu_nodevcheck
	releaseall
	end

RyuDebug_SkipTutorial::
	goto_if_unset FLAG_RYU_DEV_MODE, ryu_end
	setvar VAR_LITTLEROOT_INTRO_STATE, 10
	setflag FLAG_RYU_MET_RIVAL_LITTLEROOT
	setflag FLAG_SYS_B_DASH
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	setflag FLAG_RYU_INTRO_COMPLETE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_GAME_CLEAR
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_NATIONAL_DEX
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	msgbox LRT_GameStartVariablesInfoMsg MSGBOX_DEFAULT
	closemessage
	msgbox RyuDebug_GiveItemQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq RyuDebug_GiveItems
	release
	end

LRT_GameStartVariablesInfoMsg:
	.string "New Game Flags and Variables Set.$"

RyuDebug_GiveItemQuery:
	.string "Show item options?$"

RyuNewGameQuery:
	.string "Would you like to activate the new\ngame scripts?$"

@@EV DEBUG MENU==================================================================================================================

RyuPokeEditMenu::
	multichoicedefault 1, 0, 122, 0, 0
	switch VAR_RESULT
	case 0, TC_EvIvCheckerScript@
	case 1, ryu_end@
	case 2, ryu_end@
	case 3, RyuAccessDevMoveRelearner@
	case 4, RyuSetEvDebugMenu@
	case 5, RyuSetIvDebugMenu@
	case 6, RyuSetFriendshipDebugMenu@
	case 7, RyuExitPokeEditMenu@
	goto RyuExitPokeEditMenu
	
RyuExitPokeEditMenu::
	release
	end

RyuAccessDevMoveRelearner::
	msgbox RyuActivateRelearner MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RyuPokeEditMenu
	additem ITEM_HEART_SCALE, 1
	setflag FLAG_TEMP_4
	call FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	goto RyuAskToUseTutorAgain

RyuAskToUseTutorAgain::
	msgbox retutor MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RyuPokeEditMenu
	goto RyuAccessDevMoveRelearner
	end

RyuActivateRelearner:
	.string "Activate the move relearner?$"

retutor:
	.string "Relearn another move?$"

RyuSetEvDebugMenu::
	msgbox RyuEv_ChooseSlot
	call RyuBufferPartyMonNames
	multichoicedefault 1, 1, MULTI_SELECT_PARTY_SLOT, 0, 0
	compare VAR_RESULT, 6
	goto_if_eq RyuPokeEditMenu
	copyvar VAR_TEMP_2, VAR_RESULT
	msgbox RyuEvIntro MSGBOX_SIGN
	multichoicegrid 1, 0, 116, 4, 0
	switch VAR_RESULT
	case 0, RyuEvMenuHP
	case 1, RyuEvMenuHP126
	case 2, RyuEvMenuAtk
	case 3, RyuEvMenuAtk126
	case 4, RyuEvMenuDef
	case 5, RyuEvMenuDef126
	case 6, RyuEvMenuSpAtk
	case 7, RyuEvMenuSpAtk126
	case 8, RyuEvMenuSpDef
	case 9, RyuEvMenuSpDef126
	case 10, RyuEvMenuSpe
	case 11, RyuEvMenuSpe126
	case 12, RyuEvMenuReset
	case 13, RyuEvMenuExit
	case 14, RyuEvMenuExit
	case 15, RyuEvMenuExit
	goto RyuEvMenuExit
	release
	end

RyuEv_ChooseSlot:
	.string "Choose a party slot.$"

RyuEvMenuQuery:
	.string "Modify more EV's?$"

RyuEvIntro:
	.string "Choose which value to set.\n"
	.string "Insert/Extract from pc to apply.$"
	
RyuEvMenuReset::
	special RyuResetEvs
	msgbox RyuResetEvMessage MSGBOX_DEFAULT
	goto RyuSetEvDebugMenu
	
RyuResetEvMessage:
	.string "Lead mon Evs have been reset.\n"
	.string "You can now choose new ones.$"

RyuEvMenuExit::
	msgbox RyuEvMenuQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuSetEvDebugMenu
	goto RyuPokeEditMenu
	release
	end

RyuEvMenuHP::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	setvar VAR_TEMP_3, 0 
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuHP126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	setvar VAR_TEMP_3, 0
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuAtk::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	setvar VAR_TEMP_3, 1
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuAtk126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	setvar VAR_TEMP_3, 1
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuDef::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	setvar VAR_TEMP_3, 2
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuDef126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	setvar VAR_TEMP_3, 2
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpAtk::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	setvar VAR_TEMP_3, 3
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpAtk126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	setvar VAR_TEMP_3, 3
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpDef::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	setvar VAR_TEMP_3, 4
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpDef126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	setvar VAR_TEMP_3, 4
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpe::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 252
	setvar VAR_TEMP_3, 5
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuSpe126::
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_1, 126
	setvar VAR_TEMP_3, 5
	special RyuSetSlotStatEV
	call RyuEvMenuExit
	release
	end

RyuEvMenuMsg:
	.string "Would you like to modify EV's?"
	
RyuSetFriendshipDebugMenu::
	addmonhappiness 0, 255
	msgbox RyuSetFriendshipMsg MSGBOX_DEFAULT
	closemessage
	goto RyuPokeEditMenu
	
RyuSetFriendshipMsg:
	.string "Lead mon loves you now.$"
	
RyuSetExpMultMenu::
	compare VAR_RYU_EXP_MULTIPLIER, 1
	goto_if_eq RyuSetExpMultMenu2
	buffernumberstring 0, VAR_RYU_EXP_MULTIPLIER
	msgbox RyuCurrentExpMult MSGBOX_DEFAULT
	multichoicedefault 5, 0, 124, 0, 0
	switch VAR_RESULT
	case 0, RyuSetExpMult1
	case 1, RyuSetExpMultAuto
	case 2, RyuSetExpMult2
	case 3, RyuSetExpMult4
	case 4, RyuSetExpMult8
	case 5, RyuExitExpMult
	goto RyuExitExpMult

RyuSetExpMultMenu2::
	waitse
	specialvar VAR_RESULT, RyuCalculateCurrentExpCoefficient
	buffernumberstring 0, VAR_RESULT
	buffernumberstring 1, VAR_RYU_EXP_MULTIPLIER
	msgbox RyuCurrentExpMult MSGBOX_DEFAULT
	multichoicedefault 5, 0, 124, 0, 0
	switch VAR_RESULT
	case 0, RyuSetExpMult1
	case 1, RyuSetExpMultAuto
	case 2, RyuSetExpMult2
	case 3, RyuSetExpMult4
	case 4, RyuSetExpMult8
	case 5, RyuExitExpMult
	goto RyuExitExpMult

RyuExitExpMult::
	msgbox ExpMultNoChange
	goto RyuDebug_UtilitiesMenu

ExpMultNoChange:
	.string "Exp mult not changed.$"

RyuCurrentExpMult:
	.string "The coefficient is currently {STR_VAR_1}.\n"
	.string "The base multiplier is {STR_VAR_2}.$"
	
RyuSetExpMult1::@@exp is vanilla
	setvar VAR_RYU_EXP_MULTIPLIER, 1000
	setvar VAR_RYU_PRICE_MULTIPLIER, 1000
	msgbox ExpMult1 MSGBOX_DEFAULT
	closemessage
	goto RyuDebugMenuScript
	
ExpMult1:
	.string "Exp Multiplier is now default.\n"
	.string "You gain exp at vanilla rate.$"
	
RyuSetExpMultAuto::@@exp is increased by 12.5% per gym badge
	msgbox ExpMultAuto MSGBOX_DEFAULT
	setvar VAR_RYU_EXP_MULTIPLIER, 1
	setvar VAR_RYU_PRICE_MULTIPLIER, 1000
	closemessage
	goto RyuDebug_UtilitiesMenu
	
ExpMultAuto:
	.string "Exp Multiplier is now Auto.\n"
	.string "You will gain additional exp per badge.$"
	
RyuSetExpMult2::@@exp is multiplied by 2
	setvar VAR_RYU_EXP_MULTIPLIER, 2000
	setvar VAR_RYU_PRICE_MULTIPLIER, 750
	msgbox ExpMult2 MSGBOX_DEFAULT
	closemessage
	goto RyuDebug_UtilitiesMenu
	
ExpMult2:
	.string "Exp Multiplier is now 2.0x.$"
	
RyuSetExpMult4::@@exp is multiplied by 4
	setvar VAR_RYU_EXP_MULTIPLIER, 4000
	setvar VAR_RYU_PRICE_MULTIPLIER, 500
	msgbox ExpMult4 MSGBOX_DEFAULT
	closemessage
	goto RyuDebug_UtilitiesMenu
	
ExpMult4:
	.string "Exp Multiplier is now 4.0x.$"
	
RyuSetExpMult8::@@exp is multiplied by 8
	setvar VAR_RYU_EXP_MULTIPLIER, 8000
	setvar VAR_RYU_PRICE_MULTIPLIER, 250
	msgbox ExpMult8 MSGBOX_DEFAULT
	closemessage
	goto RyuDebug_UtilitiesMenu
	
ExpMult8:
	.string "Exp Multiplier is now 8.0x.$"
	
RyuDebug_PasscodeMenu::
	playse SE_EXPMAX
	waitse
	setvar VAR_TEMP_0, 0
	goto MC_GC_MENU
	
RyuSetIvDebugMenu::
	special RyuIvSetter
	goto RyuPokeEditMenu

RyuDebug_BattleSim::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_ne RDB_BattleSimFemale
	trainerbattle_single TRAINER_DOPPELGANGER_M, BS_Intro, BS_Defeat
	waitstate
	release
	end

RDB_BattleSimFemale::
	trainerbattle_single TRAINER_DOPPELGANGER_F, BS_Intro, BS_Defeat
	waitstate
	release
	end

BS_Defeat:
	.string "Simualtion over.$"

BS_Intro:
	.string "Starting Simulation.$"

