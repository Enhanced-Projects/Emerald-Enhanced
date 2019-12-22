EverGrandeCity_Hall5_MapScripts:: @ 82295BD
	map_script ON_WARP, EverGrandeCity_Hall5_OnWarp
	.byte 0

EverGrandeCity_Hall5_OnWarp: @ 82295C3
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall5_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall5_EventScript_TurnPlayerNorth:: @ 82295CD
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

