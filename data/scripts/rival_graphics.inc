Common_EventScript_SetupRivalGfxId:: @ 8271ED7
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EventScript_SetupRivalGfxIdFemale
	compare VAR_RESULT, FEMALE
	goto_if_eq EventScript_SetupRivalGfxIdMale
	end

EventScript_SetupRivalGfxIdFemale:: @ 8271EEF
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL
	return

EventScript_SetupRivalGfxIdMale:: @ 8271EF5
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

Common_EventScript_SetupRivalOnBikeGfxId:: @ 8271EFB
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EventScript_SetupRivalOnBikeGfxIdFemale
	compare VAR_RESULT, FEMALE
	goto_if_eq EventScript_SetupRivalOnBikeGfxIdMale
	end

EventScript_SetupRivalOnBikeGfxIdFemale:: @ 8271F13
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL
	return

EventScript_SetupRivalOnBikeGfxIdMale:: @ 8271F19
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

EventScript_SetupRivalGfxIdMale2:: @ 8271F37
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

EventScript_SetupRivalGfxIdFemale2:: @ 8271F3D
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL
	return
