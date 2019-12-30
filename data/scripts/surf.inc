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
	msgbox ES_YouHaveFollowerCantSurf
	releaseall
	end

ES_YouHaveFollowerCantSurf:
	.string "You have a follower.\nYou can't swim.$"
