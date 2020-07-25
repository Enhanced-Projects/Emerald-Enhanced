Route111_MapScripts:: @ 81F0CA7
	map_script ON_LOAD , Route111_OnLoad
	map_script ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script ON_FRAME, Route111_OnFrame
	.byte 0

Route111_OnLoad: @ 81F0CBC
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
	compare VAR_MIRAGE_TOWER_STATE, 1
	call_if_eq Route111_EventScript_ShowTemporaryMirageTower
	end

Route111_EventScript_CloseDesertRuins:: @ 81F0CD1
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, 1
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, 1
	return

@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
Route111_EventScript_ShowTemporaryMirageTower:: @ 81F0CE4
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, 0
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, 0
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, 0
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, 0
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, 0
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, 0
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, 0
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, 0
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, 0
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, 0
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, 0
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, 0
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, 0
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, 0
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, 0
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, 0
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, 0
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, 0
	return

Route111_OnTransition: @ 81F0D87
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special SetMirageTowerVisibility
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
	compare VAR_MIRAGE_TOWER_STATE, 1
	call_if_eq Route111_EventScript_SetFallingPlayerGfx
	compare VAR_MIRAGE_TOWER_STATE, 2
	call_if_eq Route111_EventScript_SetMirageTowerGone
	call Route111_EventScript_CheckSetSandstorm
	call GabbyAndTy_EventScript_UpdateLocation
	checktrainerflag TRAINER_VICKY
	goto_if_lt Route111_EventScript_SetWinstratesNotDefeated
	call_if_set FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA2, R111_FixTabitha
	end

R111_FixTabitha::
	setobjectxy 45, 31, 28
	return

Route111_EventScript_SetFallingPlayerGfx:: @ 81F0DC2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route111_EventScript_SetFallingPlayerGfxMale
	compare VAR_RESULT, FEMALE
	goto_if_eq Route111_EventScript_SetFallingPlayerGfxFemale
	return

Route111_EventScript_SetFallingPlayerGfxMale:: @ 81F0DDA
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

Route111_EventScript_SetFallingPlayerGfxFemale:: @ 81F0DE0
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL
	return

Route111_EventScript_CheckSetSandstorm:: @ 81F0DE6
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 34
	goto_if_lt Route111_EventScript_EndCheckSetSandstorm
	compare VAR_TEMP_1, 107
	goto_if_gt Route111_EventScript_EndCheckSetSandstorm
	compare VAR_TEMP_1, 72
	goto_if_gt Route111_EventScript_SetSandstorm
	compare VAR_TEMP_0, 2000
	goto_if_gt Route111_EventScript_EndCheckSetSandstorm
	compare VAR_TEMP_0, 8
	goto_if_lt Route111_EventScript_EndCheckSetSandstorm
Route111_EventScript_SetSandstorm:: @ 81F0E22
	setweather WEATHER_SANDSTORM
Route111_EventScript_EndCheckSetSandstorm:: @ 81F0E25
	return

Route111_EventScript_SetWinstratesNotDefeated:: @ 81F0E26
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VIVI
	end

Route111_EventScript_SetLayoutNoMirageTower:: @ 81F0E3C
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
	return

Route111_EventScript_SetMirageTowerGone:: @ 81F0E40
	setvar VAR_MIRAGE_TOWER_STATE, 3
	return

Route111_OnWarp: @ 81F0E46
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
	.2byte 0

Route111_EventScript_HidePlayerForMirageTower:: @ 81F0E50
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	end

Route111_OnFrame: @ 81F0E56
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
	map_script_2 VAR_RYU_MAGMA, 150, R111_ResumeMagmaScene
	.2byte 0

Route111_EventScript_MirageTowerDisappear:: @ 81F0E60
	lockall
	special StartMirageTowerShake
	waitstate
	delay 24
	playse SE_RU_HYUU
	addobject 45
	special StartPlayerDescendMirageTower
	waitstate
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	removeobject 45
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 16
	special StartMirageTowerDisintegration
	waitstate
	special StartMirageTowerFossilFallAndSink
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 2
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_RootFossilDisappeared:: @ 81F0EA7
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

@ Unused
Route111_Movement_PlayerFall:: @ 81F0EB1
	store_lock_anim
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route111_EventScript_Girl:: @ 81F0EB9
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
	giveitem ITEM_RAZZ_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
	special GetPlayerBigGuyGirlString
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ReceivedBerry:: @ 81F0EF4
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
	release
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerUp:: @ 81F0EFE
	lockall
	setvar VAR_0x8004, 0
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerDown:: @ 81F0F0A
	lockall
	setvar VAR_0x8004, 1
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerLeft:: @ 81F0F16
	lockall
	setvar VAR_0x8004, 2
	goto Route111_EventScript_ViciousSandstormTrigger
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerRight:: @ 81F0F22
	lockall
	setvar VAR_0x8004, 3
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTrigger:: @ 81F0F2E
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route111_EventScript_PreventRouteAccess
	setvar VAR_TEMP_3, 1
	releaseall
	end

Route111_EventScript_PreventRouteAccess:: @ 81F0F45
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8004, 0
	call_if_eq Route111_EventScript_PushUpFromRoute
	compare VAR_0x8004, 1
	call_if_eq Route111_EventScript_PushDownFromRoute
	compare VAR_0x8004, 2
	call_if_eq Route111_EventScript_PushLeftFromRoute
	compare VAR_0x8004, 3
	call_if_eq Route111_EventScript_PushRightFromRoute
	releaseall
	end

Route111_EventScript_PushUpFromRoute:: @ 81F0F7C
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
	waitmovement 0
	return

Route111_EventScript_PushDownFromRoute:: @ 81F0F87
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
	waitmovement 0
	return

Route111_EventScript_PushLeftFromRoute:: @ 81F0F92
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
	waitmovement 0
	return

Route111_EventScript_PushRightFromRoute:: @ 81F0F9D
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
	waitmovement 0
	return

Route111_Movement_PushUpFromRoute: @ 81F0FA8
	walk_up
	step_end

Route111_Movement_PushDownFromRoute: @ 81F0FAA
	walk_down
	step_end

Route111_Movement_PushLeftFromRoute: @ 81F0FAC
	walk_left
	step_end

Route111_Movement_PushRightFromRoute: @ 81F0FAE
	walk_right
	step_end

Route111_EventScript_SunTrigger:: @ 81F0FB0
	setweather WEATHER_SUNNY
	fadenewbgm MUS_DOORO_X1
	doweather
	setvar VAR_TEMP_3, 0
	end

Route111_EventScript_SandstormTrigger:: @ 81F0FBD
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_ASHROAD
	doweather
	end

Route111_EventScript_Victor:: @ 81F0FC5
	lock
	faceplayer
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_EventScript_BattleWinstrates
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_BattleWinstrates:: @ 81F0FE7
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject 1
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject 2
	applymovement 2, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject 2
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject 3
	applymovement 3, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
	applymovement 3, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject 3
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject 4
	applymovement 4, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	applymovement 4, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject 4
	call Route111_EventScript_CloseWinstrateDoor
	release
	end

Route111_EventScript_OpenWinstrateDoor:: @ 81F113C
	opendoor 13, 113
	waitdooranim
	return

Route111_EventScript_CloseWinstrateDoor:: @ 81F1143
	closedoor 13, 113
	waitdooranim
	return

Route111_Movement_WinstrateEnterHouse: @ 81F114A
	walk_in_place_fastest_up
	walk_up
	step_end

Route111_Movement_WinstrateExitHouse: @ 81F114D
	walk_down
	step_end

Route111_Movement_WaitForNextWinstrate: @ 81F114F
	delay_16
	delay_16
	delay_16
	step_end

Route111_EventScript_RouteSignMauville:: @ 81F1153
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route111_EventScript_WinstrateHouseSign:: @ 81F115C
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign112:: @ 81F1165
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign113:: @ 81F116E
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
	end

Route111_EventScript_OldLadysRestStopSign:: @ 81F1177
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
	end

Route111_EventScript_TrainerTipsSpAtkSpDef:: @ 81F1180
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
	end

Route111_EventScript_Man1:: @ 81F1189
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
	end

Route111_EventScript_Man2:: @ 81F1192
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
	end

Route111_EventScript_Hiker:: @ 81F119B
	lock
	faceplayer
	compare VAR_MIRAGE_TOWER_STATE, 3
	goto_if_eq Route111_EventScript_HikerMirageTowerGone
	compare VAR_MIRAGE_TOWER_STATE, 2
	goto_if_eq Route111_EventScript_HikerMirageTowerDisintegrated
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerGone:: @ 81F11C6
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerDisintegrated:: @ 81F11D0
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerVisible:: @ 81F11DA
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RockSmashTipFatMan:: @ 81F11E4
	lockall
	applymovement 46, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
	closemessage
	applymovement 46, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route111_EventScript_Drew:: @ 81F1204
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Heidi:: @ 81F121B
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Beau:: @ 81F1232
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Becky:: @ 81F1249
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Dusty:: @ 81F1260
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_RematchDusty
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterDusty:: @ 81F128C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
	@nop Trainer_DUSTY_1
	release
	end

Route111_EventScript_RematchDusty:: @ 81F12AB
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Travis:: @ 81F12C2
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Irene:: @ 81F12D9
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Daisuke:: @ 81F12F0
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Wilton:: @ 81F1307
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_RematchWilton
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterWilton:: @ 81F1333
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
	@nop Trainer_WILTON_1
	release
	end

Route111_EventScript_RematchWilton:: @ 81F1352
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Brooke:: @ 81F1369
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_RematchBrooke
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterBrooke:: @ 81F1395
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
	@nop Trainer_BROOKE_1
	release
	end

Route111_EventScript_RematchBrooke:: @ 81F13B4
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Hayden:: @ 81F13CB
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bianca:: @ 81F13E2
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Tyron:: @ 81F13F9
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celina:: @ 81F1410
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celia:: @ 81F1427
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bryan:: @ 81F143E
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Branden:: @ 81F1455
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_TrainerHillSign:: @ 81F146C
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
	end

Route111_Text_BattleOurFamily: @ 81F1475
	.string "Hello! I take it you're a traveler.\p"
	.string "How's this? What do you say to taking\n"
	.string "on our family of four in a series of\l"
	.string "Pokémon battles?$"

Route111_Text_IsThatSo: @ 81F14F5
	.string "Is that so?\n"
	.string "Drop in, if you change your mind!$"

Route111_Text_VictorIntro: @ 81F1523
	.string "That's the spirit! I like you!$"

Route111_Text_VictorDefeat: @ 81F1542
	.string "Aiyah!\n"
	.string "You're a lot tougher than I expected!$"

Route111_Text_VictorPostBattle: @ 81F156F
	.string "Hey, all!\n"
	.string "I've found a pretty strong Trainer!$"

Route111_Text_VictoriaIntro: @ 81F159D
	.string "Oh, my goodness! Aren't you young?\p"
	.string "You must be quite the Trainer to beat\n"
	.string "my husband, though.\p"
	.string "It's my turn to battle now!$"

Route111_Text_VictoriaDefeat: @ 81F1616
	.string "Oh, gosh!\n"
	.string "I can't get over how strong you are!$"

Route111_Text_VictoriaPostBattle: @ 81F1645
	.string "There's a strong Trainer here!\n"
	.string "This one's really strong!$"

Route111_Text_ViviIntro: @ 81F167E
	.string "You're stronger than Mommy? Wow!\p"
	.string "But I'm strong, too!\n"
	.string "Really! Honestly!$"

Route111_Text_ViviDefeat: @ 81F16C6
	.string "Huh? Did I just lose?$"

Route111_Text_ViviPostBattle: @ 81F16DC
	.string "This stinks…\p"
	.string "…Snivel… Grandma!$"

Route111_Text_VickyIntro: @ 81F16FB
	.string "How dare you make my granddaughter\n"
	.string "cry!\p"
	.string "For that, I'm going to smack you!\n"
	.string "Prepare to lose!$"

Route111_Text_VickyDefeat: @ 81F1756
	.string "Kwah! You are strong…\n"
	.string "My granddaughter was right…$"

Route111_Text_VickyPostBattle: @ 81F1788
	.string "If you're not in any hurry,\n"
	.string "visit with us awhile.$"

Route111_Text_ToughToKeepWinningUpTheRanks: @ 81F17BA
	.string "If you don't raise your Pokémon some\n"
	.string "more, it could be tough to keep winning\l"
	.string "up through the ranks.\p"
	.string "I've heard the Pokémon League's\n"
	.string "ELITE FOUR are far stronger than\l"
	.string "any Gym Leader.$"

Route111_Text_WinstrateFamilyDestroyedMe: @ 81F186E
	.string "I challenged the WINSTRATE family,\n"
	.string "but four matches in a row is tough\l"
	.string "going… They destroyed me.$"

Route111_Text_RouteSignMauville: @ 81F18CE
	.string "ROUTE 111\n"
	.string "{DOWN_ARROW} MAUVILLE CITY$"

Route111_Text_WinstrateHouseSign: @ 81F18E8
	.string "“Our family's hearts beat as one!”\n"
	.string "THE WINSTRATE's HOUSE$"

Route111_Text_RouteSign112: @ 81F1921
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 112$"

Route111_Text_RouteSign113: @ 81F1937
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 113$"

Route111_Text_OldLadysRestStopSign: @ 81F194D
	.string "OLD LADY's REST STOP\n"
	.string "“Come in and rest your tired bones.”$"

Route111_Text_TrainerTipsSpAtkSpDef: @ 81F1987
	.string "Trainer TIPS\p"
	.string "One of the indicators of a Pokémon's\n"
	.string "powerfulness is SP. ATK. It stands for\l"
	.string "“SPECIAL ATTACK.”\p"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
	.string "DEFENSE.”$"

Route111_Text_ShouldBeMirageTowerAroundHere: @ 81F1A22
	.string "There should be a tower made of sand\n"
	.string "around here somewhere.\p"
	.string "But for some reason, it can be seen\n"
	.string "sometimes, and sometimes not.\p"
	.string "That's why I call it the MIRAGE TOWER.$"

Route111_Text_MirageTowerClearlyVisible: @ 81F1AC7
	.string "I see it!\n"
	.string "The tower of sand!\p"
	.string "The sand tower they called a mirage\n"
	.string "is clearly visible!\p"
	.string "But it looks so fragile…\n"
	.string "It could crumble away anytime…\p"
	.string "I want to go inside it, but I can't\n"
	.string "get my courage up for it…$"

Route111_Text_ThatWasShockingSandRainedDown: @ 81F1B92
	.string "Whoa…\n"
	.string "That was shocking.\p"
	.string "Sand rained down in chunks all of\n"
	.string "a sudden.\p"
	.string "What was it like inside?\n"
	.string "Were there sandy ghosts and such?$"

Route111_Text_MirageTowerHasntBeenSeenSince: @ 81F1C12
	.string "Since I spoke to you, the tower of sand\n"
	.string "hasn't been seen.\p"
	.string "Perhaps it really was\n"
	.string "the MIRAGE TOWER…$"

Route111_Text_ClawFossilDisappeared: @ 81F1C74
	.string "The CLAW FOSSIL disappeared into\n"
	.string "the sand…$"

Route111_Text_RootFossilDisappeared: @ 81F1C9F
	.string "The ROOT FOSSIL disappeared into\n"
	.string "the sand…$"

Route111_Text_MauvilleUncleToldMeToTakeRockSmash: @ 81F1CCA
	.string "Oh, no!\p"
	.string "My uncle in MAUVILLE told me to take\n"
	.string "ROCK SMASH with me if I was going to\l"
	.string "ROUTE 111!\p"
	.string "My uncle? He lives across from\n"
	.string "the bike shop in MAUVILLE.$"

Route111_Text_TrainerHillSign: @ 81F1D61
	.string "{RIGHT_ARROW} Trainer HILL ENTRANCE\p"
	.string "“Scale the heights, you hot-blooded\n"
	.string "Trainers!”$"

@==================================================================================================nuzlocke/hardcore
r111_TrainerHillBlockEntry::
	goto_if_set FLAG_RYU_NUZLOCKEMODE, r111_blockEntry
	goto_if_set FLAG_RYU_HARDCORE_MODE, r111_blockEntry
	release
	end
	
r111_blockEntry::
	lock
	msgbox r111_trainerHill_cantEnter
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_FOLLOWER
	release
	end
	
r111_trainerHill_cantEnter:
	.string "{COLOR LIGHT_RED}{SHADOW LIGHT_GREY}You can't enter here due to being\non a restrictive difficulty setting.$"
	

@==================================================================================================scientist

r111_ScientistCastformEvent::
	lock
	setvar VAR_TEMP_7, SPECIES_CASTFORM
	setvar VAR_TEMP_8, 2
	setvar VAR_TEMP_9, 208
	setvar VAR_TEMP_A, 94
	drawcustompic 2, SPECIES_CASTFORM, 208, 104
	msgbox r111_ThisSeemsToBe
	closemessage
	playmoncry SPECIES_CASTFORM, 0
	waitmoncry
	msgbox r111_Sandstorm
	closemessage
	fadescreen 1
	msgbox r111_timePassage
	closemessage
	delay 40
	msgbox r111_CastformTired
	playmoncry SPECIES_CASTFORM, 5
	fadescreen 0
	msgbox r111_IKnewItWouldnt
	closemessage
	setvar VAR_RYU_DEVON_SCIENTIST_STAGE, 104
	release
	end
	
r111_ThisSeemsToBe:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}This seems to be the place. \p"
	.string "Ready, Castform?$"

r111_Sandstorm:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE} Use Sandstorm!$"

r111_timePassage:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} and Castform work for about an\n"
	.string "hour...$"

r111_CastformTired:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Castform is looking really tired.$"

r111_IKnewItWouldnt:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (Hm...I knew it wouldn't be easy,\n"
	.string " but we've been out here for some\p"
	.string " time, and Castform's starting to\n"
	.string " get exhausted. It won't have\p"
	.string " enough strength to transform at\n"
	.string " this point. I better head back to\l"
	.string " the Institute and report this.)$"
	
@==================================================================================================Magma Events

R111_MagmaMeeting::
	setvar VAR_RYU_MAGMA, 135@player started route 111 magma meeting
	applymovement 45, Common_Movement_FaceUp
	waitmovement 45
	msgbox R111_SoYouveArrived
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, R11_PlayerFallInLine@3 left, 1 down, face right
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 45, Common_Movement_FaceLeft
	waitmovement 45
	msgbox R111_OurLeaderCurrently
	closemessage
	delay 20
	msgbox R111_WeveRecentlyBeen
	closemessage
	delay 40
	msgbox R111_ImGivingYou
	closemessage
	delay 20
	msgbox R111_HmmWell
	closemessage
	delay 20
	applymovement 45, R111_TabithaToPlayer
	waitmovement 45
	msgbox R111_YouGotSomething
	closemessage
	applymovement 42, Common_Movement_FaceUp
	waitmovement 42
	msgbox R111_AndHowDo
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox R111_EasyTakeALook
	closemessage
	setflag FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA1
	clearflag FLAG_RYU_HIDE_111_MAGMA_MEETING_TABITHA2
	setflag FLAG_HIDE_MAP_NAME_POPUP
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, R111_cam1
    waitmovement OBJ_EVENT_ID_CAMERA
	msgbox R111_TheVolcanicAsh
	setvar VAR_RYU_MAGMA, 140@camera is panning to route 113
	closemessage
	end
	
R111_ResumeMagmaScene::
	setvar VAR_RYU_MAGMA, 155@camera finished and has returned to 111
	special RemoveCameraObject
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement 46, R111_BlaiseToTabitha
	waitmovement 46
	msgbox R111_SoundsLikeAPlan
	playse SE_PIN
	applymovement 47, Common_Movement_ExclamationMark
	waitmovement 47
	applymovement 47, Common_Movement_FaceDown
	waitmovement 47
	msgbox R111_DontYouDare
	closemessage
	applymovement 47, Common_Movement_FaceLeft
	waitmovement 47
	msgbox R111_InOrder
	msgbox R111_HeyImThe
	closemessage
	applymovement 47, Common_Movement_FaceDown
	waitmovement 47
	msgbox R111_WhatDidI
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_RYU_HIDE_111_MAGMA_MEETING
	removeobject 42
	removeobject 43
	removeobject 44
	removeobject 45
	removeobject 47
	fadescreen FADE_FROM_BLACK
	setvar VAR_RYU_MAGMA, 160@Blaise is now waiting for player to collect all the ash
	releaseall
	end
	
R111_BlaiseWaitingForAsh::
	lock
	faceplayer
	compare VAR_RYU_MAGMA, 160
	goto_if_ne ryu_end
	compare VAR_ASH_GATHER_COUNT, 8000
	goto_if_lt R111_Blaise_NotEnough
	msgbox R111_NiceWork
	setvar VAR_RYU_MAGMA, 165@player gathered the required ash.
	clearflag FLAG_RYU_MAGMA_LILYCOVE
	setflag FLAG_RYU_ROUTE_111_MAGMA_MEETING_BLAISE
	applymovement 46, R111_BlaiseExit
	waitmovement 46
	removeobject 46
	release
	end
	
R111_Blaise_NotEnough::
	buffernumberstring 0, VAR_ASH_GATHER_COUNT
	msgbox R111_GetToIt
	release
	end
	
R111_SoYouveArrived:
	.string "So you've arrived, fall in line!$"
	
R111_OurLeaderCurrently:
	.string "Our Leader currently has neither the\n"
    .string "time nor the patience to inform you\p"
    .string "of what has occurred, so I'm here in\n"
    .string "his stead...$"

R111_WeveRecentlyBeen:
	.string "We've recently been made aware of a\n"
    .string "raid Team Aqua had made on the\p"
    .string "Oceanic Museum in Slateport, and\n"
    .string "voiced their demands to Capt. Stern.\p"
    .string "They have begun to make their move,\n"
    .string "and to Team Magma, that is definitely\p"
    .string "unacceptable! We need to slow their\n"
    .string "progress, if not halt it completely!$"

R111_ImGivingYou:
	.string "I'm giving you this one and only\n"
    .string "opportunity to prove yourselves, so\p"
    .string "speak up!$"

R111_HmmWell:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Hmm...well...$"
	
R111_YouGotSomething:
	.string "You got something to say, grunt?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}How about we take the fight to them?\n"
    .string "Team Aqua's all about the sea, so\p"
    .string "what if we poisoned the water around\n"
    .string "their home turf?$"

R111_AndHowDo:
	.string "And how do you propose we even go\n"
    .string "about doing that, huh?$"

R111_EasyTakeALook:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Easy, take a look at the next route.$"
	
R111_TheVolcanicAsh:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}The volcanic ash from Mt. Chimney\n"
    .string "would be detrimental to any water\p"
    .string "supply, and there are copious amounts\n"
    .string "of it.$"

R111_SoundsLikeAPlan:
	.string "Sounds like a plan to me. What do you\n"
    .string "think, Tabby?$"

R111_DontYouDare:
	.string "Don't you dare call me that again!$"

R111_InOrder:
	.string "In order to carry out something like\n"
    .string "that, you'll need to gather a lot\p"
    .string "of ash, which can only be carried\n"
    .string "in a Soot Sack.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I'll handle that part. The rest can\n"
    .string "figure out at which points to pour\p"
    .string "the ash.$"

R111_HeyImThe:
	.string "Hey, I'm the Admin here, not you!\p"
    .string "Oh give it a rest, Tabby, and let's\n"
    .string "get this done!$"

R111_WhatDidI:
	.string "What did I just say!?$"
	
R111_NiceWork:
	.string "Nice work! Meet us in Lilycove,\n"
	.string "and let the sabotage commence!$"
	
R111_GetToIt:
	.string "{STR_VAR_1} isn't enough. Go get more!$"

	
R11_PlayerFallInLine:@3 left, 1 down, face right
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	step_end
	
R111_TabithaToPlayer:
	walk_up
	walk_left
	walk_left
	step_end
	
R111_BlaiseToTabitha:
	walk_left
	walk_left
	face_up
	step_end
	
R111_BlaiseExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
R111_cam1:@up 18, left 53
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	step_end
	
R111_cam2:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	step_end
	
@==================================================================================================Second Magma Meeting

R111_MagmaMeeting2TriggerRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	goto R111_MagmaMeeting2Trigger

R111_MagmaMeeting2Trigger::
	lock
	setvar VAR_RYU_MAGMA, 205@Player started second meeting with magma
	addobject 49
	applymovement 49, R111_TabithaToPlayer2@right 7
	waitmovement 49
	addobject 50
	applymovement 50, R111_BlaiseToPlayer@right 9
	waitmovement 50
	addobject 48
	applymovement 48, R111_MaxieToPlayer@right8
	waitmovement 48
	msgbox R111_SoYouveArrived2
	closemessage
	msgbox R111_IveBeenLedTo
	closemessage
	applymovement 48, Common_Movement_FaceDown
	waitmovement 48
	msgbox R111_YouNeedNot
	playse SE_PIN
	applymovement 49, Common_Movement_ExclamationMark
	waitmovement 49
	msgbox R111_HowDareYou
	closemessage
	delay 40
	applymovement 48, Common_Movement_FaceUp
	waitmovement 48
	msgbox R111_AreYouReady
	closemessage
	delay 40
	msgbox R111_PlayerGivesMaxie
	closemessage
	applymovement 48, Common_Movement_StepUp
	waitmovement 48
	playfanfare MUS_FANFA1
	msgbox R111_PlayerIsNow
	closemessage
	applymovement 50, Common_Movement_StepUp
	waitmovement 50
	msgbox R111_WillYouLook
	closemessage
	playse SE_PIN
	applymovement 49, Common_Movement_ExclamationMark
	waitmovement 49
	applymovement 49, Common_Movement_StepUp
	waitmovement 49
	msgbox R111_MaxieSir
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 48
	removeobject 49
	removeobject 50
	setvar VAR_RYU_MAGMA, 210@second meeting with magma finished
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RYU_PLAYER_BANNED_FROM_LILYCOVE
	release
	end
	
R111_SoYouveArrived2:
	.string "So you've arrived.$"
	
R111_IveBeenLedTo:
	.string "I've been made aware of the incident\n"
    .string "in Lilycove. I'm led to believe that\p"
    .string "you practically spearheaded the\n"
    .string "operation, correct?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Yes, sir, at the direction of-$"

R111_YouNeedNot:
	.string "You need not say any more. It only\n"
    .string "wastes time.\p"
    .string "I will have you know, however, that\n"
    .string "this little escapade of yours has\p"
    .string "brought undue attention to ourselves\n"
    .string "and thus makes it all the more\p"
    .string "difficult to get our jobs done. Do\n"
    .string "you understand?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I...suppose I do.$"

R111_HowDareYou:
	.string "How dare you-!\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}The plan was to stop Aqua from\n"
    .string "progressing by causing a problem\p"
    .string "on their home turf that they cannot\n"
    .string "ignore, giving Team Magma the lead\p"
    .string "in our own plans, whatever that is.\n"
    .string "We succeeded in doing so. It should\p"
    .string "count for something.$"

R111_AreYouReady:
	.string "Are you ready to take responsibility\n"
    .string "for your actions?$"

R111_PlayerGivesMaxie:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} gives Maxie a stern nod.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Hmph, say no more.$"

R111_PlayerIsNow:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} is now an Agent!$"
	
R111_WillYouLook:
	.string "Will you look at that...$"
	
R111_MaxieSir:
    .string "M-Maxie, sir!\p"
    .string "Your actions do indeed have some\n"
    .string "merit. Well done, Agent {PLAYER}.\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Thank you, sir.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}All I require from you at the moment\n"
    .string "is to gain strength. You shall be\p"
    .string "contacted again when the time is\n"
    .string "right.\p"
    .string "Magma, move out.$"


R111_TabithaToPlayer2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
R111_BlaiseToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
R111_MaxieToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
