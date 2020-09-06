PolarPillar_3F_MapScripts::
	map_script ON_FRAME, CaveHole_CheckFallDownHole
	map_script ON_TRANSITION, CaveHole_FixCrackedGround
	map_script ON_RESUME, PolarPillar_3F_SetHoleWarp
	.byte 0

PolarPillar_3F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_POLAR_PILLAR_2F, 255, 0, 0
	end
