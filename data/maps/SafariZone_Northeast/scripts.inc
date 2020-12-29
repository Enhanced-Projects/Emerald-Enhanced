SafariZone_Northeast_MapScripts:: @ 8242C02
	map_script ON_FRAME, SZ_CheckMewtwo
	.byte 0
	
SZ_CheckMewtwo::
	map_script_2 VAR_TEMP_6, 0, SZ_SetWall
	.2byte 0
	
	
SZ_SetWall::
	setvar VAR_TEMP_6, 10
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 108
	goto_if_eq ryu_end
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 110
	goto_if_eq ryu_end
	compare VAR_RYU_DEVON_SCIENTIST_STAGE, 111
	goto_if_eq ryu_end
	setmetatile 8, 5, 124, 1
	setmetatile 8, 6, 124, 1
	end
