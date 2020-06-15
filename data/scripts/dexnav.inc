EventScript_StartDexNavBattle::
	lock
	playse 0x15
	applymovement OBJ_EVENT_ID_PLAYER PlayerExclaim
	waitmovement 0
	waitse
	dowildbattle    
	release
	end
PlayerExclaim:
    emote_exclamation_mark
    step_end

