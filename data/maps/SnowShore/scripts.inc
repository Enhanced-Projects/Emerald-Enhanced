SnowShore_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SnowShore_OnTransition
	.byte 0

SnowShore_OnTransition:
	setflag FLAG_LANDMARK_SNOWSHORE
	end

Snowshore_EventScript_TownSign::
	msgbox SnowShore_Text_TownSign, MSGBOX_SIGN
	end

SnowShore_Text_TownSign:
	.string "Snowshore\n"
	.string "“Come ashore this winter wonderland”$"
