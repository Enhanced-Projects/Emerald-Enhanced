DewfordTown_PokemonCenter_2F_MapScripts:: @ 81FC615
	map_script ON_FRAME, CableClub_OnFrame
	map_script ON_WARP, CableClub_OnWarp
	map_script ON_LOAD, CableClub_OnLoad
	map_script ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
DewfordTown_PokemonCenter_2F_EventScript_Colosseum:: @ 81FC62A
	call CableClub_EventScript_Colosseum
	end

DewfordTown_PokemonCenter_2F_EventScript_TradeCenter:: @ 81FC630
	call CableClub_EventScript_TradeCenter
	end

DewfordTown_PokemonCenter_2F_EventScript_RecordCorner:: @ 81FC636
	call CableClub_EventScript_RecordCorner
	end

