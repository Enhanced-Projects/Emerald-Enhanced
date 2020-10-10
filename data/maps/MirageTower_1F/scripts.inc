MirageTower_1F_MapScripts:: @ 823AD01
	map_script ON_TRANSITION, MirageTower_1F_OnTransition
	.byte 0

MirageTower_1F_OnTransition: @ 823AD07
	setflag FLAG_ENTERED_MIRAGE_TOWER
	setflag FLAG_LANDMARK_MIRAGE_TOWER
	end

