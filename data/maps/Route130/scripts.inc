Route130_MapScripts:: @ 81F735F
	map_script ON_TRANSITION, Route130_OnTransition
	map_script ON_FRAME, R130_OnFrame
	.byte 0

R130_OnFrame::
	map_script_2 VAR_TEMP_6, 0, R130_SetupAquaKyogreEvent
	.2byte 0

Route130_OnTransition: @ 81F7365
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_ge Route130_EventScript_CheckSetAbnormalWeather
	specialvar VAR_RESULT, IsMirageIslandPresent
	compare VAR_RESULT, TRUE
	goto_if_eq Route130_EventScript_SetMirageIslandLayout
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	end

Route130_EventScript_SetMirageIslandLayout:: @ 81F73B1
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	end

Route130_EventScript_CheckSetAbnormalWeather:: @ 81F73B5
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route130_EventScript_Rodney:: @ 81F73BF
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Katie:: @ 81F73D6
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Santiago:: @ 81F73ED
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
	end

R130_SetupAquaKyogreEvent::
	setvar VAR_TEMP_6, 20
	compare VAR_RYU_AQUA, 130
	goto_if_ne ryu_end
	goto_if_set FLAG_RYU_KYOGRE, ryu_end
	clearflag FLAG_RYU_HIDE_R130_KYOGRE
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	end

R130_Kyogre::
	goto_if_unset FLAG_RYU_PLAYER_HELPING_AQUA, ryu_end
	goto_if_set FLAG_RYU_KYOGRE, ryu_end
	goto_if_set FLAG_RYU_KYOGRE_RAN, ryu_end
	msgbox RyuLegendary_IntroKyogreRoute130
	setvar VAR_TEMP_5, SPECIES_KYOGRE
	setvar VAR_TEMP_9, ITEM_MYSTIC_WATER
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, RyuLegendary_CaughtKyogreRoute130 
	setflag FLAG_RYU_KYOGRE_RAN
	removeobject 4
	pokenavcall R130_Kyogre_ReturnToMossdeep
	waitmessage
	setvar VAR_RYU_AQUA, 150
	warpsilent MAP_MOSSDEEP_CITY, 255, 46, 8
	waitstate

	RyuLegendary_CaughtKyogreRoute130::
	setflag FLAG_RYU_KYOGRE
	removeobject 4 
	pokenavcall R130_Kyogre_ReturnToMossdeep
	waitmessage
	setvar VAR_RYU_AQUA, 150
	warpsilent MAP_MOSSDEEP_CITY, 255, 46, 8
	waitstate

RyuLegendary_IntroKyogreRoute130:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(It appears to be focused on\n keeping the rain active.)$"

R130_Kyogre_ReturnToMossdeep:
	.string "{PLAYER}? This is Matt, Return to Mossdeep!\nON THE DOUBLE!!$"

