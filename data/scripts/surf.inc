EventScript_UseSurf:: @ 8271EA0
	lockall
	goto_if_set FLAG_RYU_HAS_FOLLOWER, ES_SurfHasFollower
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf:: @ 8271ED5
	releaseall
EventScript_EndUseSurf:: @ 8271ED6
	end

ES_SurfHasFollower::
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_MAGMA_MEMBER_F
	goto_if_eq ES_TandemSurf
	msgbox ES_YouHaveFollowerCantSurf
	releaseall
	end

ES_TandemSurf::
	msgbox ES_PlayerAndCourtneySurf
	destroyfollower
	setflag FLAG_RYU_TEMP_HIDE_FOLLOWER_COURTNEY
	removeobject OBJ_EVENT_ID_FOLLOWER
	dofieldeffect FLDEFF_USE_SURF
	releaseall
	end


ES_YouHaveFollowerCantSurf:
	.string "You have a follower.\nYou can't swim.$"

ES_PlayerAndCourtneySurf:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Courtney hopped on {PLAYER}'s back.$"
