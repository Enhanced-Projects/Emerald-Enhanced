EventScript_TV:: @ 827EE0B
	lockall
	call_if_unset FLAG_RYU_CAUGHT_ALL_UBS, checkUBnotification
	call_if_set FLAG_SYS_GAME_CLEAR, CheckMINotification
	incrementgamestat GAME_STAT_WATCHED_TV
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForBigMovieOrEmergencyNewsOnTV
	compare VAR_RESULT, 2
	goto_if_eq EventScript_PlayersHouseMovie
	goto_if_unset FLAG_SYS_TV_START, EventScript_MomDadMightLikeThis1
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_MomDadMightLikeThis1
	specialvar VAR_RESULT, IsTVShowInSearchOfTrainersAiring
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_DoInSearchOfTrainers
	goto EventScript_TryDoPokeNews
	end

checkUBnotification::
	call_if_set FLAG_RYU_ULTRA_BEASTS_ESCAPED, RyuScript_NotifyUltraBeasts
	return

CheckMINotification::
	call_if_unset FLAG_RYU_VIEWED_MIRAGE_ISLAND_NEWS_BULLETIN, RyuScript_NotifyMirageIsland
	return

EventScript_TryDoTVShow:: @ 827EE54
	specialvar VAR_0x8004, GetRandomActiveShowIdx
	compare VAR_0x8004, 255
	goto_if_eq EventScript_MomDadMightLikeThis2
	specialvar VAR_RESULT, GetNextActiveShowIfMassOutbreak
	compare VAR_RESULT, 255
	goto_if_eq EventScript_MomDadMightLikeThis2
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, GetSelectedTVShow
	compare VAR_RESULT, 0
	goto_if_ne EventScript_DoTVShow
	end

EventScript_MomDadMightLikeThis1:: @ 827EE8A
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_PlayersHouseMovie:: @ 827EE9A
	msgbox PlayersHouse_1F_Text_TheresAMovieOnTV, MSGBOX_DEFAULT
	releaseall
	end

EventScript_DoTVShow:: @ 827EEBA
	special DoTVShow
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 1
	goto_if_ne EventScript_DoTVShow
	goto EventScript_TurnOffTV
	end

EventScript_TurnOffTV:: @ 827EED0
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_MomDadMightLikeThis2:: @ 827EED8
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	goto EventScript_TurnOffTV
	end

EventScript_TryDoPokeNews:: @ 827EEE9
	special DoPokeNews
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_TryDoTVShow
	waitmessage
	waitbuttonpress
	goto EventScript_TurnOffTV
	end

EventScript_DoInSearchOfTrainers:: @ 827EEFF
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoInSearchOfTrainers
	goto EventScript_TurnOffTV
	end
