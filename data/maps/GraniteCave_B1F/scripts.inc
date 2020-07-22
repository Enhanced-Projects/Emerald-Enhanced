GraniteCave_B1F_MapScripts:: @ 822DC5E
	map_script ON_FRAME, CaveHole_CheckFallDownHole
	map_script ON_TRANSITION, CaveHole_FixCrackedGround
	map_script ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp: @ 822DC6E
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F, 255, 0, 0
	end

