@ Local IDs are the same for both players houses
.set LOCALID_MOM, 1
.set LOCALID_DAD, 5
.set LOCALID_MOM_2F, 14

PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet:: @ 82926FE
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

PlayersHouse_2F_EventScript_WallClock:: @ 8292799
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	releaseall
	end

PlayersHouse_2F_EventScript_CheckWallClock:: @ 829283F
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock:: @ 8292849
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return
