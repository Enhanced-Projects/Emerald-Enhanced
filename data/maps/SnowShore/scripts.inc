SnowShore_MapScripts::
	.byte 0
	
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
