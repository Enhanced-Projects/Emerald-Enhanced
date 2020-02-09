ScorchedSlab_MapScripts:: @ 8239291
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	.byte 0

ScorchedSlab_OnTransition: @ 8239297
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	end
	
SS_CHY::
	lock
	finditem ITEM_CHARIZARDITE_Y, 1
	setflag FLAG_RYU_CHAR_Y_MEGA
	removeobject 2
	release
	end

