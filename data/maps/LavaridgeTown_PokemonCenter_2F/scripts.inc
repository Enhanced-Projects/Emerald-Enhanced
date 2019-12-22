LavaridgeTown_PokemonCenter_2F_MapScripts:: @ 81FFC97
	map_script ON_FRAME, CableClub_OnFrame
	map_script ON_WARP, CableClub_OnWarp
	map_script ON_LOAD, CableClub_OnLoad
	map_script ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
LavaridgeTown_PokemonCenter_2F_EventScript_Colosseum:: @ 81FFCAC
	call CableClub_EventScript_Colosseum
	end

LavaridgeTown_PokemonCenter_2F_EventScript_TradeCenter:: @ 81FFCB2
	call CableClub_EventScript_TradeCenter
	end

LavaridgeTown_PokemonCenter_2F_EventScript_RecordCorner:: @ 81FFCB8
	call CableClub_EventScript_RecordCorner
	end

