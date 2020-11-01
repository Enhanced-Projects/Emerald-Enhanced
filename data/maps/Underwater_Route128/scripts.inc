Underwater_Route128_MapScripts:: @ 81F7730
	map_script ON_FRAME, R128U_OnFrameScript
	.byte 0

R128U_OnFrameScript::
	map_script_2 VAR_RYU_AQUA, 145, R128U_MovePlayerToKyogre
	map_script_2 VAR_TEMP_5, 0, R128U_CheckKyogreInteraction
	.2byte 0

R128U_MovePlayerToKyogre::
	setvar VAR_RYU_AQUA, 147 @Player is facing Kyogre
	applymovement OBJ_EVENT_ID_PLAYER, R128U_ToKyogre
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject 1
	applymovement OBJ_EVENT_ID_PLAYER, R128U_ToKyogre2
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

R128U_CheckKyogreInteraction::
	setvar VAR_TEMP_5, 40
	goto_if_set FLAG_TEMP_A, ryu_end
	setflag FLAG_TEMP_A
	goto R128U_AddKyogre

R128U_AddKyogre::
	goto_if_set FLAG_RYU_KYOGRE, ryu_end
	goto_if_set FLAG_RYU_KYOGRE_RAN, ryu_end
	addobject 1
	end

R128U_Kyogre::
	goto_if_unset FLAG_RYU_PLAYER_HELPING_AQUA, ryu_end
	goto_if_set FLAG_RYU_KYOGRE, ryu_end
	goto_if_set FLAG_RYU_KYOGRE_RAN, ryu_end
	msgbox RyuLegendary_IntroKyogre128
	setvar VAR_TEMP_5, SPECIES_KYOGRE
	setvar VAR_TEMP_9, ITEM_MYSTIC_WATER
	call RyuLegendary_GeneralLegendEncounter
	compare VAR_RESULT,  B_OUTCOME_CAUGHT
	goto_if_eq RyuLegendary_CaughtKyogre128
	removeobject 1
	setflag FLAG_RYU_KYOGRE_RAN
	release
	end

RyuLegendary_CaughtKyogre128::
	setflag FLAG_RYU_KYOGRE
	removeobject 1
	setvar VAR_RYU_AQUA, 149@Player got Kyogre.
	@Do end scenes here.
	release
	end

RyuLegendary_IntroKyogre128:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(It looks like it may eat\n you at any point.)$"

R128U_ToKyogre:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end
	
R128U_ToKyogre2:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
