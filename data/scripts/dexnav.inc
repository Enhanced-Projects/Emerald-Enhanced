EventScript_StartDexNavBattle::
	lock
	playse 0x15
	applymovement  EVENT_OBJ_ID_PLAYER PlayerExclaim
	waitmovement 0x0
	waitse
	dowildbattle    
	release
	end

PlayerExclaim:
    emote_exclamation_mark
    step_end

