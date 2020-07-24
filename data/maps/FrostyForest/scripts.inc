FrostyForest_MapScripts::
	map_script ON_TRANSITION, FrostyForest_OnTransition
	.byte 0

FrostyForest_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 0, FrostyForest_EventScript_FallThroughIce
	.2byte 0

FrostyForest_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 0
	end

FrostyForest_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, FrostyForest_Movement_FallThroughIce
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	warphole MAP_FROSTY_FOREST_UNDERWATER
	waitstate
	end

FrostyForest_Movement_FallThroughIce:
	set_invisible
	step_end

FrostyForest_IceWarpTile::
  lockall
  getplayerxy VAR_TEMP_5, VAR_TEMP_6
  playse SE_RU_GASHIN
  waitse
  playse SE_RU_GASYAN
  waitse
  applymovement OBJ_EVENT_ID_PLAYER, FF_StepInPlace
  setmetatile VAR_TEMP_5, VAR_TEMP_6, 769, TRUE
  special DrawWholeMapView
  delay 30
  playse SE_RU_HYUU
  warphole MAP_FROSTY_FOREST_UNDERWATER
  release
  end

FF_StepInPlace:
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	step_end

FrostyForest_EnergyRoot::
	lockall
	goto_if_set FLAG_RYU_FROSTY_FOREST_ENERGY_ROOT, FrostyForestEnd
	giveitem ITEM_ENERGY_ROOT
	setflag FLAG_RYU_FROSTY_FOREST_ENERGY_ROOT
	release
	end

FrostyForest_Banettite::
	lockall
	goto_if_set FLAG_RYU_FROSTY_FOREST_BANETTITE, FrostyForestEnd
	giveitem ITEM_BANETTITE
	setflag FLAG_RYU_FROSTY_FOREST_BANETTITE
	release
	end

FrostyForest_DuskStone::
	lockall
	goto_if_set FLAG_RYU_FROSTY_FOREST_DUSK_STONE, FrostyForestEnd
	giveitem ITEM_DUSK_STONE
	setflag FLAG_RYU_FROSTY_FOREST_DUSK_STONE
	release
	end

FrostyForest_SpellTag::
	lockall
	goto_if_set FLAG_RYU_FROSTY_FOREST_SPELL_TAG, FrostyForestEnd
	giveitem ITEM_SPELL_TAG
	setflag FLAG_RYU_FROSTY_FOREST_SPELL_TAG
	release
	end

FrostyForestEnd::
	release
	end
