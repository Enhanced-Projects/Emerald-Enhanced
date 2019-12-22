Littleroot_Town_Rival_HouseQuest_MapScripts::
	map_script ON_FRAME, LRT_DateFinish
	.byte 0


LRT_DateFinish::
    map_script_2 VAR_TEMP_1, 0, LRT_date1end 
	.2byte 0

LRT_date1end::
	applymovement EVENT_OBJ_ID_PLAYER, lrtmh_faceright
	fadescreenspeed 2, 5
    addobject 1
	applymovement 1, Common_Movement_HeartEmote
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	msgbox LRT_DATEEND, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LRT_EXITDATE
	waitmovement 0
	clearflag FLAG_RYU_ON_DATE
	clearflag FLAG_RYU_ON_DATE_2
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	warp MAP_LITTLEROOT_TOWN, 0, 20, 20
	releaseall
	end
	
lrtmh_faceright:
	face_right
	step_end

LRT_DATEEND:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} groggily wakes up after\n"
	.string " a comfy rest with Dawn by his side.)\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: Good morning, sleepyhead.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She lovingly pokes you in the forehead)\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You kiss her once more, and get ready\n"
	.string " for the day ahead.)$"

LRT_EXITDATE:
	walk_left
	walk_left
	face_right
	delay_16
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	step_end
