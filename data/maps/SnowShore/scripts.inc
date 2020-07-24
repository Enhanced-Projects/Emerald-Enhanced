SnowShore_MapScripts::
	map_script ON_TRANSITION, SnowShore_OnTransition
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

Snowshore_EventScript_CraggyCoastSign::
	msgbox SnowShore_Text_CraggyCoastSign, MSGBOX_SIGN
	end

SnowShore_Text_CraggyCoastSign:
	.string "{LEFT_ARROW} Craggy Coast$"

Snowshore_EventScript_MrFrigusSign::
	msgbox SnowShore_Text_MrFrigusSign, MSGBOX_SIGN
	end

SnowShore_Text_MrFrigusSign:
	.string "Mr Frigus's house\n"
	.string "“Learn about the island's past”$"

Snowshore_BigPearl::
	lockall
	goto_if_set FLAG_HIDDEN_SNOWSHORE_BIG_PEARL, FrostyForestEnd
	giveitem ITEM_BIG_PEARL
	setflag FLAG_HIDDEN_SNOWSHORE_BIG_PEARL
	release
	end

Snowshore_HeartScale::
	lockall
	goto_if_set FLAG_HIDDEN_SNOWSHORE_HEART_SCALE, FrostyForestEnd
	giveitem ITEM_HEART_SCALE
	setflag FLAG_HIDDEN_SNOWSHORE_HEART_SCALE
	release
	end

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
