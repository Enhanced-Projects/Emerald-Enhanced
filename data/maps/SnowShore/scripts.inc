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
	
SnowShore_EskimoFight::
    cleartrainerflag TRAINER_ESKIMO_1
    trainerbattle_single TRAINER_ESKIMO_1, SS_EF_Intro, SS_EF_Defeat
    msgbox EskimoFightFinished
	release
	end
	
SS_EF_Intro:
	.string "Harr Harr, It's cold$"
	
SS_EF_Defeat:
	.string "Too cold for me$"
	
EskimoFightFinished:
	.string "You should get a coat.$"
