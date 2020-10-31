MtPyre_Exterior_MapScripts:: @ 8231FCC
	map_script ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition: @ 8231FD2
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit:: @ 8231FD8
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 12
	goto_if_lt MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit:: @ 8231FE9
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger:: @ 8231FED
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger:: @ 8231FF2
	setweather WEATHER_SUNNY
	doweather
	end

@+=================================================================================================Aqua

MPE_AquaEvent::
	setvar VAR_RYU_AQUA, 84 @Event on mtpyre exterior started
	lockall
	msgbox MPE_AlrightCrew
	closemessage
	applymovement 10, Common_Movement_FaceLeft
	waitmovement 10
	msgbox MPE_WereToStorm
	closemessage
	applymovement 10, Common_Movement_FaceDown
	waitmovement 10
	msgbox MPE_IsEveryoneReady
	closemessage
	delay 30
	msgbox MPE_LetsGo
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_RYU_HIDE_AQUA_MTPYRE_EXT
	call MPE_RemoveAqua
	fadescreen FADE_FROM_BLACK
	setvar VAR_RYU_AQUA, 88 @Player attended meeting at mtpyre exterior, is headed into summit
	clearflag FLAG_RYU_HIDE_NPCS_MTPYRE_SUMMIT
	release
	end
	
MPE_RemoveAqua::
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	removeobject 10
	return
	
	
MPE_AlrightCrew:
	.string "Alright crew, here are the orders\n"
    .string "from our Captain!$"

MPE_WereToStorm:
	.string "We're to storm the top of this\n"
    .string "mountain and clear out all the Magma\l"
    .string "goons!\p"
    .string "We cannot allow them to take the Red\n"
    .string "Orb!$"

MPE_IsEveryoneReady:
	.string "Is everyone ready?$"
	
MPE_LetsGo:
	.string "Then let's go!$"
