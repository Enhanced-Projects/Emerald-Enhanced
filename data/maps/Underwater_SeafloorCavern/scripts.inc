Underwater_SeafloorCavern_MapScripts:: @ 823433B
	map_script ON_RESUME, Underwater_SeafloorCavern_OnResume
	map_script ON_TRANSITION, Underwater_SeafloorCavern_OnTransition
	map_script ON_LOAD , Underwater_SeafloorCavern_OnLoad
	map_script ON_WARP, UW_OnWarpScript
	map_script ON_FRAME, UW_OnFrameScript
	.byte 0

Underwater_SeafloorCavern_OnTransition: @ 823434B
	setflag FLAG_LANDMARK_SEAFLOOR_CAVERN
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_HideSubmarine
	end

Underwater_SeafloorCavern_EventScript_HideSubmarine:: @ 8234358
	setflag FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE
	end

Underwater_SeafloorCavern_OnLoad: @ 823435C
	call_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles
	end

UW_OnFrameScript::
	map_script_2 VAR_RYU_AQUA, 129, UW_DoAquaScene
	.2byte 0

UW_DoAquaScene::
	delay 30
	setvar VAR_RYU_AQUA, 131 @Player watched the scene underwater from seafloor cavern
	clearflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	warpsilent MAP_SEAFLOOR_CAVERN_ENTRANCE, 255, 10, 6
	waitstate

UW_OnWarpScript::
	map_script_2 VAR_RYU_AQUA, 127, UW_HidePlayerForScene
	.2byte 0

UW_HidePlayerForScene::
	setvar VAR_RYU_AQUA, 129 @@player hidden for underwater scene
	applymovement OBJ_EVENT_ID_PLAYER, UW_SetInvisible
	end

UW_SetInvisible:
	set_invisible
	step_end

Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles:: @ 8234366
	setmetatile 5, 3, METATILE_Underwater_RockWall, 1
	setmetatile 6, 3, METATILE_Underwater_RockWall, 1
	setmetatile 7, 3, METATILE_Underwater_RockWall, 1
	setmetatile 8, 3, METATILE_Underwater_RockWall, 1
	setmetatile 5, 4, METATILE_Underwater_FloorShadow, 0
	setmetatile 6, 4, METATILE_Underwater_FloorShadow, 0
	setmetatile 7, 4, METATILE_Underwater_FloorShadow, 0
	setmetatile 8, 4, METATILE_Underwater_FloorShadow, 0
	setmetatile 5, 5, METATILE_Underwater_FloorShadow, 0
	setmetatile 6, 5, METATILE_Underwater_FloorShadow, 0
	setmetatile 7, 5, METATILE_Underwater_FloorShadow, 0
	setmetatile 8, 5, METATILE_Underwater_FloorShadow, 0
	return

Underwater_SeafloorCavern_OnResume: @ 82343D3
	setdivewarp MAP_SEAFLOOR_CAVERN_ENTRANCE, 255, 10, 17
	end

Underwater_SeafloorCavern_EventScript_CheckStolenSub:: @ 82343DC
	msgbox Underwater_SeafloorCavern_Text_SubExplorer1, MSGBOX_SIGN
	end

Underwater_SeafloorCavern_Text_SubExplorer1: @ 82343E5
	.string "“SUBMARINE Explorer 1” is painted\n"
	.string "on the hull.\p"
	.string "This is the submarine Team Aqua\n"
	.string "stole in Slateport!\p"
	.string "Team Aqua must have gone\n"
	.string "ashore here.$"

