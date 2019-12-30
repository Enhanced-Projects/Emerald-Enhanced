EverGrandeCity_Hall1_MapScripts:: @ 8229569
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall1_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RyuThroneRoomCheckFollower
	.byte 0

EverGrandeCity_Hall1_OnWarp: @ 822956F
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall1_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall1_EventScript_TurnPlayerNorth:: @ 8229579
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	setflag FLAG_RYU_WAYSTONE_DISABLED
	gfec
	setobjectxy EVENT_OBJ_ID_FOLLOWER, VAR_TEMP_1, VAR_TEMP_2
	end

