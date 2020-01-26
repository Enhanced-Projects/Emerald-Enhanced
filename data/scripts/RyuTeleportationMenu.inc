RyuTeleport::
	lock
	goto_if_set FLAG_RYU_WAYSTONE_DISABLED, RyuTeleportDisabled
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuTeleportUseCheck
	call_if_set FLAG_RYU_HARDCORE_MODE, RyuTeleportUseCheck
	setflag FLAG_RYU_TEMPTP
	msgbox MSG_Teleport MSGBOX_SIGN
	multichoicegrid 0, 0, 126, 3, 0
	switch VAR_RESULT
	case 0, RT_Home
	case 1, RT_Oldale
	case 2, RT_Petalburg
	case 3, RT_Rustboro
	case 4, RT_Verdanturf
	case 5, RT_Slateport
	case 6, RT_Dewford
	case 7, RT_Pacifidlog
	case 8, RT_Lavaridge
	case 9, RT_Fallarbor
	case 10, RT_Fortree
	case 11, RT_Mauville
	case 12, RT_Lilycove
	case 13, RT_Sootopolis
	case 14, RT_Mossdeep
	case 15, RT_Evergrande
	case 16, RT_Landmarks
	case 17, RT_Exit
	case 127, RT_Exit
	closemessage
	release
	end

RyuTeleportUseCheck:
	compare VAR_RYU_NUZLOCKE_WAYSTONE_USES, 0
	goto_if_eq RyuTeleportUseExceeded
	subvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 1
	return

RyuTeleportUseExceeded:
	msgbox RTDNMUEMsg
	release
	end

RyuTeleportDisabled:
	msgbox RTDMsg
	release
	end

RTDMsg:
	.string "{COLOR LIGHT_RED}{SHADOW LIGHT_GREY}The waystone has been disabled\ntemporarily.\pFinish whatever you're doing\nand it will be enabled again.$"

RTDNMUEMsg:
	.string "You've exceeded the use count\nfor the waystone.\pDefeat a new Gym!$"

MSG_Teleport:
	.string "Teleport to where?$"
	
	
RT_Home::
	warpteleport MAP_LITTLEROOT_TOWN, 255, 10, 10
	release
	end
	
RT_Oldale::
	goto_if_unset FLAG_VISITED_OLDALE_TOWN, RT_NoFlag
	warpteleport MAP_OLDALE_TOWN, 255, 10, 9
	release
	end
	
RT_Petalburg::
    goto_if_unset FLAG_VISITED_PETALBURG_CITY, RT_NoFlag
	warpteleport MAP_PETALBURG_CITY, 255, 16, 16
	release
	end
	
RT_Rustboro::
    goto_if_unset FLAG_VISITED_RUSTBORO_CITY, RT_NoFlag
	warpteleport MAP_RUSTBORO_CITY, 255, 20, 49
	release
	end
	
RT_Verdanturf::
    goto_if_unset FLAG_VISITED_VERDANTURF_TOWN, RT_NoFlag
	warpteleport MAP_VERDANTURF_TOWN, 255, 13, 6
	release
	end
	
RT_Slateport::
    goto_if_unset FLAG_VISITED_SLATEPORT_CITY, RT_NoFlag
	warpteleport MAP_SLATEPORT_CITY, 255, 17, 22
	release
	end
	
RT_Dewford::
    goto_if_unset FLAG_VISITED_DEWFORD_TOWN, RT_NoFlag
	warpteleport MAP_DEWFORD_TOWN, 255, 9, 10
	release
	end
	
RT_Pacifidlog::
    goto_if_unset FLAG_VISITED_PACIFIDLOG_TOWN, RT_NoFlag
	warpteleport MAP_PACIFIDLOG_TOWN, 255, 8, 16
	release
	end
	
RT_Lavaridge::
    goto_if_unset FLAG_VISITED_LAVARIDGE_TOWN, RT_NoFlag
	warpteleport MAP_LAVARIDGE_TOWN, 255, 12, 8
	release
	end
	
RT_Fallarbor::
    goto_if_unset FLAG_VISITED_FALLARBOR_TOWN, RT_NoFlag
	warpteleport MAP_FALLARBOR_TOWN, 255, 9, 11
	release
	end
	
RT_Fortree::
    goto_if_unset FLAG_VISITED_FORTREE_CITY, RT_NoFlag
	warpteleport MAP_FORTREE_CITY, 255, 5, 9
	release
	end
	
RT_Mauville::
    goto_if_unset FLAG_VISITED_MAUVILLE_CITY, RT_NoFlag
	warpteleport MAP_MAUVILLE_CITY, 255, 18, 7
	release
	end
	
RT_Lilycove::
    goto_if_unset FLAG_VISITED_LILYCOVE_CITY, RT_NoFlag
	warpteleport MAP_LILYCOVE_CITY, 255, 22, 17
	release
	end
	
RT_Sootopolis::
    goto_if_unset FLAG_VISITED_SOOTOPOLIS_CITY, RT_NoFlag
	warpteleport MAP_SOOTOPOLIS_CITY, 255, 42, 37
	release
	end
	
RT_Mossdeep::
    goto_if_unset FLAG_VISITED_MOSSDEEP_CITY, RT_NoFlag
	warpteleport MAP_MOSSDEEP_CITY, 255, 25, 17
	release
	end
	
RT_Evergrande::
	goto_if_set FLAG_LANDMARK_POKEMON_LEAGUE, RT_PokemonLeague
	goto_if_unset FLAG_VISITED_EVER_GRANDE_CITY, RT_NoFlag
	warpteleport MAP_EVER_GRANDE_CITY, 255, 27, 49
	release
	end
	
RT_Landmarks::
	multichoicedefault 3, 0, 128, 9, 0
	switch VAR_RESULT
	case 0, RT_BattleFrontier
	case 1, RT_MtPyre
	case 2, RT_LCCDEPT
	case 3, RT_LCAH
	case 4, RT_MCMH
	case 5, RT_BF_AS
	case 6, RT_BF_CB
	case 127, RyuTeleport
	release
	end
	
RT_BattleFrontier::
    goto_if_unset FLAG_LANDMARK_BATTLE_FRONTIER, RT_NoBfFlag
	multichoicedefault 3, 0, 127, 9, 0
	switch VAR_RESULT
	case 0, RT_BF_GATE
	case 1, RT_BF_BT@tower
	case 2, RT_BF_BP@pike
	case 3, RT_BF_BP2@palace
	case 4, RT_BF_BP3@pyramid
	case 5, RT_BF_BF@factory
	case 6, RT_BF_BA@arena
	case 7, RT_BF_BD@dome
	case 8, RT_BF_CB@go back to main teleport menu
	case 127, RyuTeleport@also go back to teleport menu
	release
	end

RT_MtPyre::
	goto_if_unset FLAG_RYU_LANDMARK_MTPYRE, RT_NoFlag
	warpteleport MAP_MT_PYRE_EXTERIOR, 255, 19, 14
	release
	end

RT_LCCDEPT::
    goto_if_unset FLAG_RYU_LANDMARK_LCCDEPTSTORE, RT_NoFlag
	warpteleport MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP, 255, 4, 5
	release
	end

RT_LCAH::
    goto_if_unset FLAG_RYU_PLAYER_HELPING_AQUA, RT_NoFlag
	@warpteleport MAP_NEW_MAP4, 255, 7, 14
	release
	end
	
RT_MCMH::
	msgbox RT_NYI MSGBOX_SIGN
	@goto_if_unset FLAG_RYU_PLAYER_HELPING_MAGMA, RT_NoFlag
	goto RT_Landmarks
	release
	end
	
RT_BF_GATE::
	warpteleport MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 26, 50
	release
	end
	
RT_BF_BT::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 12, 6
	release
	end
	
RT_BF_BP::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 7
	release
	end
	
RT_BF_BP2::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 12, 10
	release
	end
	
RT_BF_BP3::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 14
	release
	end
	
RT_BF_BF::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 255, 9, 10
	release
	end
	
RT_BF_BA::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 10
	release
	end
	
RT_BF_BD::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 11, 11
	release
	end

RT_BF_AS::
	goto_if_unset FLAG_LANDMARK_ABANDONED_SHIP, RT_NoFlag
	warpteleport MAP_ABANDONED_SHIP_DECK, 255, 11, 6
	release
	end
	
RT_BF_CB::
	goto RyuTeleport
	
RT_NYI:
	.string "That storyline hasn't been\nimplemented yet.$"

	
RT_NoBfFlag::
	msgbox MSG_RT_NOFLAGBT MSGBOX_DEFAULT
	closemessage
	goto RyuTeleport
	
RT_NoFlag::
	msgbox RT_NOFLAGMSG MSGBOX_DEFAULT
	goto RyuTeleport
	
MSG_RT_NOFLAGBT:
	.string "You haven't been to the Frontier yet.$"
	
RT_NOFLAGMSG:
	.string "You haven't been here yet.$"
	
RT_PokemonLeague::
	setvar VAR_ELITE_4_STATE, 0
	warpteleport MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F, 255, 9, 6
	release
	end
	
RT_Exit::
	closemessage
	release
	end