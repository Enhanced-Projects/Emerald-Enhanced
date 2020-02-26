FallarborTown_PokemonCenter_1F_MapScripts:: @ 8200BCD
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition: @ 8200BD8
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
FallarborTown_PokemonCenter_1F_EventScript_Nurse:: @ 8200BE1
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl:: @ 8200BEF
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8200BF8
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette:: @ 8200C01
	call_if_set FLAG_RYU_PLAYER_HELPING_DEVON, FT_CheckOtherQuestActive
	lock
	faceplayer
	msgbox FT_LanetteNormalIntro, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth:: @ 8200C28
	applymovement 4, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FT_LanetteRelChoice
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest:: @ 8200C38
	applymovement 4, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FT_LanetteRelChoice
	end

FT_LanetteRelChoice:: @ 8200C48
	playse SE_JIDO_DOA
	removeobject 4
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	goto_if_set FLAG_RYU_LEAF_ALTERNATE_LINE, ryu_end
	msgbox FT_LanetteRomOption MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FT_LanetteRomanceBegin
	setflag FLAG_RYU_DS_LANETTE_ACQ
	release
	end

FT_LanetteRomanceBegin::
	msgbox FT_PlayerStartsFollowing
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, FT_FollowLanette
	waitmovement EVENT_OBJ_ID_PLAYER
	setvar VAR_RYU_LANETTE_VAR, 101
	playse SE_JIDO_DOA
	warpsilent MAP_ROUTE114_LANETTES_HOUSE, 255, 5, 5
	release
	end

FT_CheckOtherQuestActive::
	goto_if_unset FLAG_RYU_DEVON_LINE_FINISHED, ryu_return
	goto FT_QuestIsActive
	
FT_CheckOtherQuestActive2::
	goto_if_unset FLAG_RYU_DEVON_LINE_FINISHED, FT_QuestIsActive
	return

FT_QuestIsActive:
	msgbox FT_CurrentlyBusy
	closemessage
	release
	end
	
FT_CurrentlyBusy:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}(You must complete the main\n"
	.string "Devon quest before starting\l"
	.string "this one.)$"

FT_LanetteRomOption:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She seems a little preoccupied)\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Would you like to follow her?$"

FT_PlayerStartsFollowing:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You start following the nerdy\n"
    .string " girl.)$"

FT_FollowLanette:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited:: @ 8200C48
	playse SE_JIDO_DOA
	removeobject 4
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth: @ 8200C53
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest: @ 8200C60
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FT_LanetteNormalIntro: @ 8200C6B
	.string "Oh, hello.\n"
	.string "I can see that you're a trainer.\p"
	.string "So that means you use the pokémon\n"
	.string "Storage System I developed.\p"
	.string "How I arrived at that conclusion is\n"
	.string "a simple deductive process.\p"
	.string "You spoke to me because you wanted\n"
	.string "to access something on this PC.\p"
	.string "Oh, I'm sorry. I'm {COLOR LIGHT_RED}{SHADOW RED}Lanette{COLOR DARK_GREY}{SHADOW LIGHT_GREY}.\p"
	.string "Honestly, I'm glad to meet you--it's\n"
	.string "great you're using the Storage System.\p"
	.string "If you could, please visit me at home.\n"
	.string "My house is on Route 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown: @ 8200E22
	.string "I wonder what Pokémon looked like\n"
	.string "long, long ago?\p"
	.string "Maybe the FOSSIL MANIAC at the edge\n"
	.string "of town will know.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees: @ 8200E8B
	.string "In the fields of FALLARBOR, we plant\n"
	.string "seedlings of hardy trees that thrive\l"
	.string "even in volcanic ash.$"

