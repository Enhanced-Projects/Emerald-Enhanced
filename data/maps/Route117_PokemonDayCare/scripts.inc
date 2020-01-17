Route117_PokemonDayCare_MapScripts:: @ 822BBB1
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition: @ 822BBB7
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

DC_LanaTrigger::
	goto_if_unset FLAG_RYU_LEAF_MTPYRE, ryu_end
	goto_if_set FLAG_RYU_LANA_ALTEVENT2, ryu_end
	lock
	applymovement 2, DC_NpcToPlayer
	waitmovement 2
	msgbox DC_LanaStoppedBy MSGBOX_DEFAULT
	msgbox DC_LanaStory2 MSGBOX_DEFAULT
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, DC_Camera1
	waitmovement EVENT_OBJ_ID_CAMERA
	special RemoveCameraObject
	closemessage
	msgbox DC_LanaStory3 MSGBOX_DEFAULT
	applymovement 2, DC_NpcBack
	waitmovement 2
	setflag FLAG_RYU_LANA_ALTEVENT2
	release
	end
	
DC_NormalNPC::
	lock
	msgbox DC_NoStory MSGBOX_DEFAULT
	closemessage
	release
	end
	
DC_PcTrigger::
	goto_if_unset FLAG_RYU_LANA_ALTEVENT2, ryu_end
	goto_if_set FLAG_RYU_DAYCARE_LEAFEVENTPC, ryu_end
	msgbox DC_PCMSG MSGBOX_DEFAULT
	setflag FLAG_RYU_DAYCARE_LEAFEVENTPC
	closemessage
	release
	end
	
DC_Camera1:
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	delay_16
	delay_16
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	step_end
	
DC_NpcToPlayer:
	walk_right
	walk_down
	walk_right
	walk_down
	step_end
	
DC_NpcBack:
	walk_left
	walk_up
	walk_up
	walk_left
	walk_in_place_right
	step_end
	
DC_LanaStoppedBy:
	.string "I don't know what to make of it...\pA female trainer recently stopped\nby, and tried to drop all her\lpokémon off.\pWe told her that was simply not\npossible...she didn't say a word\lbut definitely seemed frustrated.$"
	
DC_NoStory:
	.string "Drop off your pokémon here and if\nthey're compatible,\l they might make an egg!$"
	
DC_LanaStory2:
	.string "She then used the computer over\nthere before taking off!$"
	
DC_LanaStory3:
	.string "It was the oddest thing...\pYou're a friend of hers? You might\nwanna go check on her...$"
	
DC_PCMSG:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Search Criteria: Pokémon Storage,\pHoenn...\pResults: Brigette's younger sister\pFallarbor Town...$"

