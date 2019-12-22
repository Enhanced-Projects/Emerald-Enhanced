FallarborTown_PokemonCenter_2F_MapScripts:: @ 8200EEB
	map_script ON_FRAME, CableClub_OnFrame
	map_script ON_WARP, CableClub_OnWarp
	map_script ON_LOAD, CableClub_OnLoad
	map_script ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
FallarborTown_PokemonCenter_2F_EventScript_Colosseum:: @ 8200F00
	call CableClub_EventScript_Colosseum
	end

FallarborTown_PokemonCenter_2F_EventScript_TradeCenter:: @ 8200F06
	call CableClub_EventScript_TradeCenter
	end

FallarborTown_PokemonCenter_2F_EventScript_RecordCorner:: @ 8200F0C
	call CableClub_EventScript_RecordCorner
	end

