ProfBirch_EventScript_UpdateLocation:: @ 82720AD
	goto_if_set FLAG_SYS_GAME_CLEAR, ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 0
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 1
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 2
	call_if_eq ProfBirch_EventScript_MoveToRoute101
	compare VAR_BIRCH_STATE, 3
	call_if_eq ProfBirch_EventScript_MoveToRoute101
	return

ProfBirch_EventScript_MoveToLab:: @ 827211A
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute101:: @ 8272127
	return

ProfBirch_EventScript_MoveToRoute103:: @ 8272134
	return

ProfBirch_EventScript_RatePokedexOrRegister:: @ 8272141
	lock
	faceplayer
	goto ProfBirch_EventScript_AskRatePokedex

ProfBirch_EventScript_AskRatePokedex:: @ 8272155
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ProfBirch_EventScript_DeclineRating
	call ProfBirch_EventScript_RatePokedex
	release
	end

ProfBirch_EventScript_DeclineRating:: @ 827216F
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_ShowRatingMessage:: @ 8272179
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfBirch_EventScript_RatePokedex:: @ 8272184
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring 0, VAR_0x8008  @ Num National seen
	buffernumberstring 1, VAR_0x8009  @ Num National caught
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	compare VAR_0x8006, 151
	call_if_ge RyuMewtwoMegaGift
	compare VAR_0x8006, 211
	call_if_ge RyuCheckForMayQuest
	return
