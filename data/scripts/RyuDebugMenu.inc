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
	case 2, RyuDebug_SpawningMenu
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
	case 2, RyuDebug_SpawningMenu
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
	case 12, RyuDebug_EnableDexnav
	case 13, RDB_AlchemyInfo
	case 14, RDB_ToggleLevelCap
	case 15, RDB_EnableRealEstate
	case 16, RyuDebug_InitTimeSlide
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
	msgbox RDB_RTM1
	closemessage
	goto RyuDebug_menu_nodevcheck

RDB_RTM1::
	.string "Returning to main menu.$"

RDB_EnableRealEstate::
	callnative SetPlayerRealtorStatus
	release
	end

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
	addmoney 1000000000
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
	.string "Given ¥1b.$"

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
	callnative RyuDebugDoPickupTestRoll
	release
	end

RDB_DQT::
	.string "{PLAYER}, can you go check out\nRoute 103?\pI want to know specifically if\nthere's a good place to camp\lthere or not.$"

RDB_String1:
	.string "Your name is {PLAYER}.\nYour rival is {RIVAL}.$"

RDB_DoLittlerootLatiCheck::
	buffernumberstring 0, VAR_ROAMER_POKEMON
	buffernumberstring 1, VAR_LITTLEROOT_INTRO_STATE
	msgbox RDBLRT2
	closemessage
	release
	end

RDBTeleport:
	.string "Teleport?$"

RDBResult:
	.string "Result: {STR_VAR_1}$"

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
	msgbox MegaStonesQuery, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq RyuDebug_GiveMegaStones
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
	additem ITEM_FRESH_WATER, 200
	additem ITEM_TONIC_WATER, 200
	additem ITEM_MINERAL_WATER, 200
	additem ITEM_MUSCLE_POWDER, 200
	additem ITEM_SMART_POWDER, 200
	additem ITEM_STARDUST, 200
	additem ITEM_TOUGH_POWDER, 200
	additem ITEM_RAWST_BERRY, 200
	additem ITEM_BRIGHT_POWDER, 200
	additem ITEM_ORAN_BERRY, 200
	additem ITEM_CHARCOAL 200
	additem ITEM_FIRE_STONE 200
	additem ITEM_SOFT_SAND 200
	additem ITEM_SNOWBALL 200
	additem ITEM_GEM_POWDER 200
	setvar VAR_RYU_ALCHEMY_COPPER, 65500
	setvar VAR_RYU_ALCHEMY_SILVER, 65500
	setvar VAR_RYU_ALCHEMY_GOLD, 65500
	return

RyuDebug_GiveMegaStones::
	additem ITEM_ABOMASITE 1
	additem ITEM_ABSOLITE 1
	additem ITEM_AERODACTYLITE 1
	additem ITEM_AGGRONITE 1
	additem ITEM_ALAKAZITE 1
	additem ITEM_ALTARIANITE 1
	additem ITEM_AMPHAROSITE 1
	additem ITEM_AUDINITE 1
	additem ITEM_BANETTITE 1
	additem ITEM_BEEDRILLITE 1
	additem ITEM_BLASTOISINITE 1
	additem ITEM_BLAZIKENITE 1
	additem ITEM_CAMERUPTITE 1
	additem ITEM_CHARIZARDITE_X 1
	additem ITEM_CHARIZARDITE_Y 1
	additem ITEM_DIANCITE 1
	additem ITEM_GALLADITE 1
	additem ITEM_GARCHOMPITE 1
	additem ITEM_GARDEVOIRITE 1
	additem ITEM_GENGARITE 1
	additem ITEM_GLALITITE 1
	additem ITEM_GYARADOSITE 1
	additem ITEM_HERACRONITE 1
	additem ITEM_HOUNDOOMINITE 1
	additem ITEM_KANGASKHANITE 1
	additem ITEM_LATIASITE 1
	additem ITEM_LATIOSITE 1
	additem ITEM_LOPUNNITE 1
	additem ITEM_LUCARIONITE 1
	additem ITEM_MANECTITE 1
	additem ITEM_MAWILITE 1
	additem ITEM_MEDICHAMITE 1
	additem ITEM_METAGROSSITE 1
	additem ITEM_MEWTWONITE_X 1
	additem ITEM_MEWTWONITE_Y 1
	additem ITEM_PIDGEOTITE 1
	additem ITEM_PINSIRITE 1
	additem ITEM_SABLENITE 1
	additem ITEM_SALAMENCITE 1
	additem ITEM_SCEPTILITE 1
	additem ITEM_SCIZORITE 1
	additem ITEM_SHARPEDONITE 1
	additem ITEM_SLOWBRONITE 1
	additem ITEM_STEELIXITE 1
	additem ITEM_SWAMPERTITE 1
	additem ITEM_TYRANITARITE 1
	additem ITEM_VENUSAURITE 1
	return

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

MegaStonesQuery:
	.string "Would you like all Mega Stones?$"

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
	case 0, RD_MonDataView
	case 1, Ryu_ResetEVIV
	case 2, RyuSetEvDebugMenu
	case 3, RyuSetIvDebugMenu
	case 4, RyuSetFriendshipDebugMenu
	case 5, RyuAccessDevMoveRelearner
	case 6, RyuExitPokeEditMenu
	case 7, RyuExitPokeEditMenu
	goto RyuExitPokeEditMenu

RD_MonDataView::
	setvar VAR_0x8001, 0
    special RyuFillStatsBuffers
	delay 30
    drawinfobox INFOBOXPOKEMONDATA
	bufferpartymonnick 1, 0
	msgbox Ryu_Stats
	removeinfobox
	special HealPlayerParty
	goto RyuPokeEditMenu
	
RyuExitPokeEditMenu::
	release
	end

Ryu_ResetEVIV::
	bufferdynamicmulti RIVEV1, RIVEV2, RIVEV3
	multichoice 0, 6, MULTI_DYNAMIC_3, 0
	compare VAR_RESULT, 127
	goto_if_eq RyuPokeEditMenu
	copyvar VAR_TEMP_0, VAR_RESULT
	msgbox RyuEv_ChooseSlot
	call RyuBufferPartyMonNames
	multichoice 0, 0, MULTI_DYNAMIC_6, 1
	copyvar VAR_TEMP_2, VAR_RESULT
	specialvar VAR_TEMP_A, CheckIfSelectedSlotIsValid
	compare VAR_TEMP_A, FALSE
	goto_if_eq RyuPokeEditMenu
	msgbox ResetEVIVQuery, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RyuPokeEditMenu
	callnative RyuResetIVEvs
	addvar VAR_TEMP_2, 1
	buffernumberstring 0, VAR_TEMP_2
	msgbox ResetDone
	goto RyuPokeEditMenu

RIVEV1:
	.string "Reset IV's$"

RIVEV2:
	.string "Reset EV's$"

RIVEV3:
	.string "Return$"

ResetEVIVQuery:
	.string "Perform reset operation?$"

ResetDone:
	.string "Reset Iv's or Ev's for slot {STR_VAR_1}.$"

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

RyuSetIvDebugMenu::
	msgbox RyuEv_ChooseSlot
	call RyuBufferPartyMonNames
	multichoice 0, 0, MULTI_DYNAMIC_6, 1
	copyvar VAR_TEMP_2, VAR_RESULT @put slot number in early
	specialvar VAR_TEMP_A, CheckIfSelectedSlotIsValid
	compare VAR_TEMP_A, FALSE
	goto_if_eq RyuSetIvDebugMenu
	bufferdynamicmulti REV4, REV5, REV3
	multichoice 0, 6, MULTI_DYNAMIC_3, 0
	switch VAR_RESULT
	case 0, RyuIVMenuAdd
	case 1, RyuIVMenuSubtract
	case 2, RyuIvMenuExit
	case 127, RyuIvMenuExit
	release
	end

RyuIVMenuAdd::
	setvar VAR_TEMP_E, 1 //IV mode
	setvar VAR_TEMP_4, FALSE //Is IV amount going to be subtracted
	msgbox AddHowManyIV
	numberentry 0, 9, 2
	compare VAR_RESULT, 31
	call_if_ge RyuIV_SetToMax
	copyvar VAR_TEMP_1, VAR_RESULT @@put amount to change in TEMP 1
	msgbox RyuEV_SetWhichStat
	bufferdynamicmulti RyuEVHP, RyuEVAtk, RyuEVDef, RyuEVSpAtk, RyuEVSpDef, RyuEVSpeed
	multichoice 0, 0, MULTI_DYNAMIC_6, 0
	compare VAR_RESULT, 127
	goto_if_eq RyuIvMenuExit
	copyvar VAR_TEMP_3, VAR_RESULT //put stat number into TEMP 3
	special RyuSetSlotStatIVEV
	msgbox IvMenuDone
	goto RyuIvMenuExit
	release
	end

RyuIVMenuSubtract::
	setvar VAR_TEMP_E, 1 //IV mode
	setvar VAR_TEMP_4, TRUE //Is IV amount going to be subtracted
	msgbox SubHowManyIV
	numberentry 0, 9, 2
	compare VAR_RESULT, 31
	call_if_ge RyuEV_SetToMin
	copyvar VAR_TEMP_1, VAR_RESULT @@put amount to change in TEMP 1
	msgbox RyuEV_SetWhichStat
	bufferdynamicmulti RyuEVHP, RyuEVAtk, RyuEVDef, RyuEVSpAtk, RyuEVSpDef, RyuEVSpeed
	multichoice 0, 0, MULTI_DYNAMIC_6, 0
	compare VAR_RESULT, 127
	goto_if_eq RyuEvMenuExit
	copyvar VAR_TEMP_3, VAR_RESULT //put stat number into TEMP 3
	special RyuSetSlotStatIVEV
	msgbox IvMenuDone
	goto RyuIvMenuExit
	release
	end

IvMenuDone:
	.string "IV's Changed.$"

RyuSetEvDebugMenu::
	msgbox RyuEv_ChooseSlot
	call RyuBufferPartyMonNames
	multichoice 0, 0, MULTI_DYNAMIC_6, 1
	copyvar VAR_TEMP_2, VAR_RESULT @put slot number in early
	closemessage
	specialvar VAR_TEMP_A, CheckIfSelectedSlotIsValid
	compare VAR_TEMP_A, FALSE
	goto_if_eq RyuSetEvDebugMenu
	msgbox RIEV_SelectOP
	bufferdynamicmulti REV1, REV2, REV3
	multichoice 0, 6, MULTI_DYNAMIC_3, 0
	switch VAR_RESULT
	case 0, RyuEVMenuAdd
	case 1, RyuEVMenuSubtract
	case 2, RyuEvMenuExit
	case 127, RyuEvMenuExit
	release
	end

RIEV_SelectOP:
	.string "Select Operation.$"

RyuIV_SetToMax::
	setvar VAR_RESULT, 31
	return

REV1:
	.string "Add EV's$"

REV2:
	.string "Remove EV's$"

REV4:
	.string "Add IV's$"

REV5:
	.string "Remove IV's$"

REV3:
	.string "Exit$"

RyuEv_ChooseSlot:
	.string "Choose a party slot.$"

RyuEV_SetWhichStat:
	.string "Modify which stat?$"

RyuEvMenuQuery:
	.string "Modify more EV's?$"

RyuIvMenuQuery:
	.string "Modify more IV's?$"

RyuEvIntro:
	.string "Choose which value to set.$"

EvResetQuery:
	.string "Set all EV's to 0?$"
	
RyuEvMenuResetQuery::
	msgbox EvResetQuery, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ryu_return
	special RyuResetEvs
	msgbox RyuResetEvMessage
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

RyuIvMenuExit::
	msgbox RyuIvMenuQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RyuSetIvDebugMenu
	goto RyuPokeEditMenu
	release
	end

RyuEVMenuAdd::
	setvar VAR_TEMP_E, 0 //EV mode
	setvar VAR_TEMP_4, FALSE //Is EV amount going to be subtracted
	msgbox AddHowManyEV
	numberentry 0, 9, 3
	compare VAR_RESULT, 255
	call_if_ge RyuEV_SetToMax
	copyvar VAR_TEMP_1, VAR_RESULT @@put amount to change in TEMP 1
	msgbox RyuEV_SetWhichStat
	bufferdynamicmulti RyuEVHP, RyuEVAtk, RyuEVDef, RyuEVSpAtk, RyuEVSpDef, RyuEVSpeed
	multichoice 0, 0, MULTI_DYNAMIC_6, 0
	compare VAR_RESULT, 127
	goto_if_eq RyuEvMenuExit
	setvar VAR_TEMP_E, 0
	copyvar VAR_TEMP_3, VAR_RESULT //put stat number into TEMP 3
	special RyuSetSlotStatIVEV
	msgbox EvMenuDone
	call RyuEvMenuExit
	release
	end

RyuEVMenuSubtract::
	setvar VAR_TEMP_E, 0 //EV mode
	setvar VAR_TEMP_4, TRUE //Is EV amount going to be subtracted
	msgbox SubHowManyEV
	numberentry 0, 9, 3
	compare VAR_RESULT, 252
	call_if_ge RyuEV_SetToMin
	copyvar VAR_TEMP_1, VAR_RESULT @@put amount to change in TEMP 1
	msgbox RyuEV_SetWhichStat
	bufferdynamicmulti RyuEVHP, RyuEVAtk, RyuEVDef, RyuEVSpAtk, RyuEVSpDef, RyuEVSpeed
	multichoice 0, 0, MULTI_DYNAMIC_6, 0
	compare VAR_RESULT, 127
	goto_if_eq RyuEvMenuExit
	setvar VAR_TEMP_E, 0
	copyvar VAR_TEMP_3, VAR_RESULT //put stat number into TEMP 3
	special RyuSetSlotStatIVEV
	msgbox EvMenuDone
	call RyuEvMenuExit
	release
	end

SubHowManyEV:
	.string "Remove how many EV's?$"

SubHowManyIV:
	.string "Remove how many IV's?$"

EvMenuDone:
	.string "Finished.$"

AddHowManyEV:
	.string "Add how many EV's?$"

AddHowManyIV:
	.string "Add how many IV's?$"

RyuEVHP:
	.string "HP$"

RyuEVAtk:
	.string "Attack$"

RyuEVDef:
	.string "Defense$"

RyuEVSpAtk:
	.string "SpcAtk$"

RyuEVSpDef:
	.string "SpcDef$"

RyuEVSpeed:
	.string "Speed$"

RyuEV_SetToMax:
	setvar VAR_RESULT, 255
	return

RyuEV_SetToMin:
	setvar VAR_RESULT, 0
	return

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
	
RyuDebug_SpawningMenu::
	bufferdynamicmulti RDBSP_1, RDBSP_2, RDBSP_3, RDBSP_4, RDBSP_5, RDBSP_6
	multichoice 6, 4, MULTI_DYNAMIC_6, 1
	switch VAR_RESULT
	case 0, FrontierMonDev
	case 1, DevModeMonGive
	case 2, DevModeItemGive
	case 3, RDB_SpawnFollowerMultiMenu
	case 4, RDB_GiveMoneyMenu
	case 5, RyuDebug_menu_nodevcheck
	goto RyuDebug_menu_nodevcheck

RDBSP_1:
	.string "Spawn Frontier Mon...$"

RDBSP_2:
	.string "Spawn Species ID...$"

RDBSP_3:
	.string "Spawn Item ID...$"

RDBSP_4:
	.string "Spawn Follower...$"

RDBSP_5:
	.string "Give Money...$"

RDBSP_6:
	.string "Return$"

FrontierMonDev::
	msgbox DMFMG
	numberentry 0, 9, 3
	compare VAR_RESULT, FRONTIER_MON_BLANK1_BLANK3
	goto_if_ge RDB_CancelSpawn
	copyvar VAR_TEMP_6, VAR_RESULT
	setflag FLAG_RYU_PASSCODE_FRONTIER_MON_DEV
	special RyuGiveFrontierMon
	msgbox FMSpawnMenuSuccess
	clearflag FLAG_RYU_PASSCODE_FRONTIER_MON_DEV
	closemessage
	goto RyuDebug_SpawningMenu

FMSpawnMenuSuccess:
	.string "Succesfully spawned FID {RYU_STR_3}.$"

DevModeMonGive::
	msgbox DMMG
	numberentry 0, 9, 3
	compare VAR_RESULT, 0
	goto_if_eq RDB_CancelSpawn
	compare VAR_RESULT, NUM_SPECIES
	goto_if_gt RDB_CancelSpawn
	copyvar VAR_TEMP_4, VAR_RESULT
	bufferspeciesname 0, VAR_TEMP_4
	getpartysize
	copyvar VAR_TEMP_8, VAR_RESULT
	setflag FLAG_RYU_DEVELOPER_POKEMON_MENU
	call GCMS_NatureMenu
	clearflag FLAG_RYU_DEVELOPER_POKEMON_MENU
	msgbox SpawnMenuSuccess
	goto RyuDebug_SpawningMenu

DevModeItemGive::
	msgbox DMIG
	numberentry 0, 9, 3
	compare VAR_RESULT, 0
	goto_if_eq RDB_CancelSpawn
	compare VAR_RESULT, ITEMS_COUNT
	goto_if_ge RDB_CancelSpawn
	additem VAR_RESULT, 200
	msgbox SpawnMenuSuccess
	goto RyuDebug_SpawningMenu

RDB_GiveMoneyMenu::
	numberentry 0, 9, 9
	callnative RDB_DevModeGiveMoney
	msgbox RDB_GMM_Msg
	goto RyuDebug_menu_nodevcheck

RDB_CancelSpawn::
	msgbox RDB_SpawnCancelled
	closemessage
	goto RyuDebug_menu_nodevcheck

RDB_GMM_Msg:
	.string "Gave {PLAYER} ¥{STR_VAR_1}.$"

DMIG:
	.string "Enter Item ID.$"

DMMG:
	.string "Enter Species ID$"

DMFMG:
	.string "Enter Frontier Mon ID.$"

RDB_SpawnCancelled:
	.string "Invalid Entry.\nReturning to main menu$"

SpawnMenuSuccess:
	.string "Operation Finished.$"

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

