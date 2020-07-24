MirageTower_2F_MapScripts:: @ 823AD11
	map_script ON_FRAME, CaveHole_CheckFallDownHole
	map_script ON_TRANSITION, CaveHole_FixCrackedGround
	map_script ON_RESUME, MirageTower_2F_SetHoleWarp
	.byte 0

MirageTower_2F_SetHoleWarp: @ 823AD21
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MIRAGE_TOWER_1F, 255, 0, 0
	end

