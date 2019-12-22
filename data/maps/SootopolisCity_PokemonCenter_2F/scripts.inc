SootopolisCity_PokemonCenter_2F_MapScripts:: @ 822676D
	map_script ON_FRAME, CableClub_OnFrame
	map_script ON_WARP, CableClub_OnWarp
	map_script ON_LOAD, CableClub_OnLoad
	map_script ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
SootopolisCity_PokemonCenter_2F_EventScript_Colosseum:: @ 8226782
	call CableClub_EventScript_Colosseum
	end

SootopolisCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 8226788
	call CableClub_EventScript_TradeCenter
	end

SootopolisCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 822678E
	call CableClub_EventScript_RecordCorner
	end

