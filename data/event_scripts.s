#include "constants/global.h"
#include "constants/battle.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_setup.h"
#include "constants/battle_tent.h"
#include "constants/battle_tower.h"
#include "constants/berry.h"
#include "constants/cable_club.h"
#include "constants/coins.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_poison.h"
#include "constants/field_specials.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/mauville_old_man.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/roulette.h"
#include "constants/script_menu.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trade.h"
#include "constants/trainer_hill.h"
#include "constants/trainers.h"
#include "constants/tv.h"
#include "constants/union_room.h"
#include "constants/vars.h"
#include "constants/weather.h"
#include "constants/general.h"
#include "constants/region_map_sections.h"
#include "constants/event_object_movement.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

@ 81DB67C
	.include "data/script_cmd_table.inc"

gSpecialVars:: @ 81DBA0C
	.4byte gSpecialVar_0x8000
	.4byte gSpecialVar_0x8001
	.4byte gSpecialVar_0x8002
	.4byte gSpecialVar_0x8003
	.4byte gSpecialVar_0x8004
	.4byte gSpecialVar_0x8005
	.4byte gSpecialVar_0x8006
	.4byte gSpecialVar_0x8007
	.4byte gSpecialVar_0x8008
	.4byte gSpecialVar_0x8009
	.4byte gSpecialVar_0x800A
	.4byte gSpecialVar_0x800B
	.4byte gSpecialVar_Facing
	.4byte gSpecialVar_Result
	.4byte gSpecialVar_ItemId
	.4byte gSpecialVar_LastTalked
	.4byte gSpecialVar_ContestRank
	.4byte gSpecialVar_ContestCategory
	.4byte gSpecialVar_MonBoxId
	.4byte gSpecialVar_MonBoxPos
	.4byte gSpecialVar_Unused_0x8014
	.4byte gTrainerBattleOpponent_A

	.include "data/specials.inc"

gStdScripts:: @ 81DC2A0
	.4byte Std_ObtainItem              @ STD_OBTAIN_ITEM
	.4byte Std_FindItem                @ STD_FIND_ITEM
	.4byte Std_MsgboxNPC               @ MSGBOX_NPC
	.4byte Std_MsgboxSign              @ MSGBOX_SIGN
	.4byte Std_MsgboxDefault           @ MSGBOX_DEFAULT
	.4byte Std_MsgboxYesNo             @ MSGBOX_YESNO
	.4byte Std_MsgboxAutoclose         @ MSGBOX_AUTOCLOSE
	.4byte Std_ObtainDecoration        @ STD_OBTAIN_DECORATION
	.4byte Std_RegisteredInMatchCall   @ STD_REGISTER_MATCH_CALL
	.4byte Std_MsgboxGetPoints         @ MSGBOX_GETPOINTS
	.4byte Std_10
	.4byte Std_MsgboxOneLine
gStdScripts_End:: @ 81DC2CC

	.include "data/maps/PetalburgCity/scripts.inc"
	.include "data/maps/SlateportCity/scripts.inc"
	.include "data/maps/MauvilleCity/scripts.inc"
	.include "data/maps/RustboroCity/scripts.inc"
	.include "data/maps/FortreeCity/scripts.inc"
	.include "data/maps/LilycoveCity/scripts.inc"
	.include "data/maps/MossdeepCity/scripts.inc"
	.include "data/maps/SootopolisCity/scripts.inc"
	.include "data/maps/EverGrandeCity/scripts.inc"
	.include "data/maps/LittlerootTown/scripts.inc"
	.include "data/maps/OldaleTown/scripts.inc"
	.include "data/maps/DewfordTown/scripts.inc"
	.include "data/maps/LavaridgeTown/scripts.inc"
	.include "data/maps/FallarborTown/scripts.inc"
	.include "data/maps/VerdanturfTown/scripts.inc"
	.include "data/maps/PacifidlogTown/scripts.inc"
	.include "data/maps/Route101/scripts.inc"
	.include "data/maps/Route102/scripts.inc"
	.include "data/maps/Route103/scripts.inc"
	.include "data/maps/Route104/scripts.inc"
	.include "data/maps/Route105/scripts.inc"
	.include "data/maps/Route106/scripts.inc"
	.include "data/maps/Route107/scripts.inc"
	.include "data/maps/Route108/scripts.inc"
	.include "data/maps/Route109/scripts.inc"
	.include "data/maps/Route110/scripts.inc"
	.include "data/maps/Route111/scripts.inc"
	.include "data/maps/Route112/scripts.inc"
	.include "data/maps/Route113/scripts.inc"
	.include "data/maps/Route114/scripts.inc"
	.include "data/maps/Route115/scripts.inc"
	.include "data/maps/Route116/scripts.inc"
	.include "data/maps/Route117/scripts.inc"
	.include "data/maps/Route118/scripts.inc"
	.include "data/maps/Route119/scripts.inc"
	.include "data/maps/Route120/scripts.inc"
	.include "data/maps/Route121/scripts.inc"
	.include "data/maps/Route122/scripts.inc"
	.include "data/maps/Route123/scripts.inc"
	.include "data/maps/Route124/scripts.inc"
	.include "data/maps/Route125/scripts.inc"
	.include "data/maps/Route126/scripts.inc"
	.include "data/maps/Route127/scripts.inc"
	.include "data/maps/Route128/scripts.inc"
	.include "data/maps/Route129/scripts.inc"
	.include "data/maps/Route130/scripts.inc"
	.include "data/maps/Route131/scripts.inc"
	.include "data/maps/Route132/scripts.inc"
	.include "data/maps/Route133/scripts.inc"
	.include "data/maps/Route134/scripts.inc"
	.include "data/maps/Underwater_Route124/scripts.inc"
	.include "data/maps/Underwater_Route126/scripts.inc"
	.include "data/maps/Underwater_Route127/scripts.inc"
	.include "data/maps/Underwater_Route128/scripts.inc"
	.include "data/maps/Underwater_Route129/scripts.inc"
	.include "data/maps/Underwater_Route105/scripts.inc"
	.include "data/maps/Underwater_Route125/scripts.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_1F/scripts.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_2F/scripts.inc"
	.include "data/maps/LittlerootTown_DawnsHouse_1F/scripts.inc"
	.include "data/maps/LittlerootTown_DawnsHouse_2F/scripts.inc"
	.include "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc"
	.include "data/maps/OldaleTown_House1/scripts.inc"
	.include "data/maps/OldaleTown_House2/scripts.inc"
	.include "data/maps/OldaleTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/OldaleTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/OldaleTown_Mart/scripts.inc"
	.include "data/maps/DewfordTown_House1/scripts.inc"
	.include "data/maps/DewfordTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/DewfordTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/DewfordTown_Gym/scripts.inc"
	.include "data/maps/DewfordTown_Hall/scripts.inc"
	.include "data/maps/DewfordTown_House2/scripts.inc"
	.include "data/maps/LavaridgeTown_HerbShop/scripts.inc"
	.include "data/maps/LavaridgeTown_Gym_1F/scripts.inc"
	.include "data/maps/LavaridgeTown_Gym_B1F/scripts.inc"
	.include "data/maps/LavaridgeTown_House/scripts.inc"
	.include "data/maps/LavaridgeTown_Mart/scripts.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FallarborTown_Mart/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentLobby/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/FallarborTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/FallarborTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FallarborTown_CozmosHouse/scripts.inc"
	.include "data/maps/FallarborTown_MoveRelearnersHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentLobby/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/VerdanturfTown_Mart/scripts.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/VerdanturfTown_WandasHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_House/scripts.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/PacifidlogTown_House1/scripts.inc"
	.include "data/maps/PacifidlogTown_House2/scripts.inc"
	.include "data/maps/PacifidlogTown_House3/scripts.inc"
	.include "data/maps/PacifidlogTown_House4/scripts.inc"
	.include "data/maps/PacifidlogTown_House5/scripts.inc"
	.include "data/maps/PetalburgCity_WallysHouse/scripts.inc"
	.include "data/maps/PetalburgCity_Gym/scripts.inc"
	.include "data/maps/PetalburgCity_House1/scripts.inc"
	.include "data/maps/PetalburgCity_House2/scripts.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/PetalburgCity_Mart/scripts.inc"
	.include "data/maps/SlateportCity_SternsShipyard_1F/scripts.inc"
	.include "data/maps/SlateportCity_SternsShipyard_2F/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentLobby/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentCorridor/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/SlateportCity_NameRatersHouse/scripts.inc"
	.include "data/maps/SlateportCity_PokemonFanClub/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_2F/scripts.inc"
	.include "data/maps/SlateportCity_Harbor/scripts.inc"
	.include "data/maps/SlateportCity_House/scripts.inc"
	.include "data/maps/SlateportCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SlateportCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SlateportCity_Mart/scripts.inc"
	.include "data/maps/MauvilleCity_Gym/scripts.inc"
	.include "data/maps/MauvilleCity_BikeShop/scripts.inc"
	.include "data/maps/MauvilleCity_House1/scripts.inc"
	.include "data/maps/MauvilleCity_GameCorner/scripts.inc"
	.include "data/maps/MauvilleCity_House2/scripts.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/MauvilleCity_Mart/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_1F/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_2F/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_3F/scripts.inc"
	.include "data/maps/RustboroCity_Gym/scripts.inc"
	.include "data/maps/RustboroCity_PokemonSchool/scripts.inc"
	.include "data/maps/RustboroCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/RustboroCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/RustboroCity_Mart/scripts.inc"
	.include "data/maps/RustboroCity_Flat1_1F/scripts.inc"
	.include "data/maps/RustboroCity_Flat1_2F/scripts.inc"
	.include "data/maps/RustboroCity_House1/scripts.inc"
	.include "data/maps/RustboroCity_CuttersHouse/scripts.inc"
	.include "data/maps/RustboroCity_House2/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_1F/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_2F/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_3F/scripts.inc"
	.include "data/maps/RustboroCity_House3/scripts.inc"
	.include "data/maps/FortreeCity_House1/scripts.inc"
	.include "data/maps/FortreeCity_Gym/scripts.inc"
	.include "data/maps/FortreeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/FortreeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FortreeCity_Mart/scripts.inc"
	.include "data/maps/FortreeCity_House2/scripts.inc"
	.include "data/maps/FortreeCity_House3/scripts.inc"
	.include "data/maps/FortreeCity_House4/scripts.inc"
	.include "data/maps/FortreeCity_House5/scripts.inc"
	.include "data/maps/FortreeCity_DecorationShop/scripts.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.inc"
	.include "data/maps/LilycoveCity_ContestLobby/scripts.inc"
	.include "data/maps/LilycoveCity_ContestHall/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/LilycoveCity_UnusedMart/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.inc"
	.include "data/maps/LilycoveCity_Harbor/scripts.inc"
	.include "data/maps/LilycoveCity_MoveDeletersHouse/scripts.inc"
	.include "data/maps/LilycoveCity_House1/scripts.inc"
	.include "data/maps/LilycoveCity_House2/scripts.inc"
	.include "data/maps/LilycoveCity_House3/scripts.inc"
	.include "data/maps/LilycoveCity_House4/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_1F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_2F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_3F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_4F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_5F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.inc"
	.include "data/maps/MossdeepCity_Gym/scripts.inc"
	.include "data/maps/MossdeepCity_House1/scripts.inc"
	.include "data/maps/MossdeepCity_House2/scripts.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/MossdeepCity_Mart/scripts.inc"
	.include "data/maps/MossdeepCity_House3/scripts.inc"
	.include "data/maps/MossdeepCity_StevensHouse/scripts.inc"
	.include "data/maps/MossdeepCity_House4/scripts.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_1F/scripts.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_2F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_1F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_B1F/scripts.inc"
	.include "data/maps/SootopolisCity_Gym_1F/scripts.inc"
	.include "data/maps/SootopolisCity_Gym_B1F/scripts.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SootopolisCity_Mart/scripts.inc"
	.include "data/maps/SootopolisCity_House1/scripts.inc"
	.include "data/maps/SootopolisCity_House2/scripts.inc"
	.include "data/maps/SootopolisCity_House3/scripts.inc"
	.include "data/maps/SootopolisCity_House4/scripts.inc"
	.include "data/maps/SootopolisCity_House5/scripts.inc"
	.include "data/maps/SootopolisCity_House6/scripts.inc"
	.include "data/maps/SootopolisCity_House7/scripts.inc"
	.include "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.inc"
	.include "data/maps/EverGrandeCity_SidneysRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_PhoebesRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_GlaciasRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_DrakesRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_ChampionsRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall1/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall2/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall3/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall4/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall5/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.inc"
	.include "data/maps/EverGrandeCity_HallOfFame/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_2F/scripts.inc"
	.include "data/maps/Route104_MrBrineysHouse/scripts.inc"
	.include "data/maps/Route104_PrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/Route111_WinstrateFamilysHouse/scripts.inc"
	.include "data/maps/Route111_OldLadysRestStop/scripts.inc"
	.include "data/maps/Route112_CableCarStation/scripts.inc"
	.include "data/maps/MtChimney_CableCarStation/scripts.inc"
	.include "data/maps/Route114_FossilManiacsHouse/scripts.inc"
	.include "data/maps/Route114_FossilManiacsTunnel/scripts.inc"
	.include "data/maps/Route114_LanettesHouse/scripts.inc"
	.include "data/maps/Route116_TunnelersRestHouse/scripts.inc"
	.include "data/maps/Route117_PokemonDayCare/scripts.inc"
	.include "data/maps/Route121_SafariZoneEntrance/scripts.inc"
	.include "data/maps/MeteorFalls_1F_1R/scripts.inc"
	.include "data/maps/MeteorFalls_1F_2R/scripts.inc"
	.include "data/maps/MeteorFalls_B1F_1R/scripts.inc"
	.include "data/maps/MeteorFalls_B1F_2R/scripts.inc"
	.include "data/maps/RusturfTunnel/scripts.inc"
	.include "data/maps/Underwater_SootopolisCity/scripts.inc"
	.include "data/maps/DesertRuins/scripts.inc"
	.include "data/maps/GraniteCave_1F/scripts.inc"
	.include "data/maps/GraniteCave_B1F/scripts.inc"
	.include "data/maps/GraniteCave_B2F/scripts.inc"
	.include "data/maps/GraniteCave_StevensRoom/scripts.inc"
	.include "data/maps/PetalburgWoods/scripts.inc"
	.include "data/maps/MtChimney/scripts.inc"
	.include "data/maps/JaggedPass/scripts.inc"
	.include "data/maps/FieryPath/scripts.inc"
	.include "data/maps/MtPyre_1F/scripts.inc"
	.include "data/maps/MtPyre_2F/scripts.inc"
	.include "data/maps/MtPyre_3F/scripts.inc"
	.include "data/maps/MtPyre_4F/scripts.inc"
	.include "data/maps/MtPyre_5F/scripts.inc"
	.include "data/maps/MtPyre_6F/scripts.inc"
	.include "data/maps/MtPyre_Exterior/scripts.inc"
	.include "data/maps/MtPyre_Summit/scripts.inc"
	.include "data/maps/AquaHideout_1F/scripts.inc"
	.include "data/maps/AquaHideout_B1F/scripts.inc"
	.include "data/maps/AquaHideout_B2F/scripts.inc"
	.include "data/maps/Underwater_SeafloorCavern/scripts.inc"
	.include "data/maps/SeafloorCavern_Entrance/scripts.inc"
	.include "data/maps/SeafloorCavern_Room1/scripts.inc"
	.include "data/maps/SeafloorCavern_Room2/scripts.inc"
	.include "data/maps/SeafloorCavern_Room3/scripts.inc"
	.include "data/maps/SeafloorCavern_Room4/scripts.inc"
	.include "data/maps/SeafloorCavern_Room5/scripts.inc"
	.include "data/maps/SeafloorCavern_Room6/scripts.inc"
	.include "data/maps/SeafloorCavern_Room7/scripts.inc"
	.include "data/maps/SeafloorCavern_Room8/scripts.inc"
	.include "data/maps/SeafloorCavern_Room9/scripts.inc"
	.include "data/maps/CaveOfOrigin_Entrance/scripts.inc"
	.include "data/maps/CaveOfOrigin_1F/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.inc"
	.include "data/maps/CaveOfOrigin_B1F/scripts.inc"
	.include "data/maps/VictoryRoad_1F/scripts.inc"
	.include "data/maps/VictoryRoad_B1F/scripts.inc"
	.include "data/maps/VictoryRoad_B2F/scripts.inc"
	.include "data/maps/ShoalCave_LowTideEntranceRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideInnerRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideStairsRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideLowerRoom/scripts.inc"
	.include "data/maps/ShoalCave_HighTideEntranceRoom/scripts.inc"
	.include "data/maps/ShoalCave_HighTideInnerRoom/scripts.inc"
	.include "data/maps/NewMauville_Entrance/scripts.inc"
	.include "data/maps/NewMauville_Inside/scripts.inc"
	.include "data/maps/AbandonedShip_Deck/scripts.inc"
	.include "data/maps/AbandonedShip_Corridors_1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms_1F/scripts.inc"
	.include "data/maps/AbandonedShip_Corridors_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms2_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Underwater1/scripts.inc"
	.include "data/maps/AbandonedShip_Room_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms2_1F/scripts.inc"
	.include "data/maps/AbandonedShip_CaptainsOffice/scripts.inc"
	.include "data/maps/AbandonedShip_Underwater2/scripts.inc"
	.include "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.inc"
	.include "data/maps/AbandonedShip_HiddenFloorRooms/scripts.inc"
	.include "data/maps/IslandCave/scripts.inc"
	.include "data/maps/AncientTomb/scripts.inc"
	.include "data/maps/Underwater_Route134/scripts.inc"
	.include "data/maps/Underwater_SealedChamber/scripts.inc"
	.include "data/maps/SealedChamber_OuterRoom/scripts.inc"
	.include "data/maps/SealedChamber_InnerRoom/scripts.inc"
	.include "data/maps/ScorchedSlab/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap1/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap2/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap3/scripts.inc"
	.include "data/maps/SkyPillar_Entrance/scripts.inc"
	.include "data/maps/SkyPillar_Outside/scripts.inc"
	.include "data/maps/SkyPillar_1F/scripts.inc"
	.include "data/maps/SkyPillar_2F/scripts.inc"
	.include "data/maps/SkyPillar_3F/scripts.inc"
	.include "data/maps/SkyPillar_4F/scripts.inc"
	.include "data/maps/ShoalCave_LowTideIceRoom/scripts.inc"
	.include "data/maps/SkyPillar_5F/scripts.inc"
	.include "data/maps/SkyPillar_Top/scripts.inc"
	.include "data/maps/MagmaHideout_1F/scripts.inc"
	.include "data/maps/MagmaHideout_2F_1R/scripts.inc"
	.include "data/maps/MagmaHideout_2F_2R/scripts.inc"
	.include "data/maps/MagmaHideout_3F_1R/scripts.inc"
	.include "data/maps/MagmaHideout_3F_2R/scripts.inc"
	.include "data/maps/MagmaHideout_4F/scripts.inc"
	.include "data/maps/MagmaHideout_3F_3R/scripts.inc"
	.include "data/maps/MagmaHideout_2F_3R/scripts.inc"
	.include "data/maps/MirageTower_1F/scripts.inc"
	.include "data/maps/MirageTower_2F/scripts.inc"
	.include "data/maps/MirageTower_3F/scripts.inc"
	.include "data/maps/MirageTower_4F/scripts.inc"
	.include "data/maps/DesertUnderpass/scripts.inc"
	.include "data/maps/ArtisanCave_B1F/scripts.inc"
	.include "data/maps/ArtisanCave_1F/scripts.inc"
	.include "data/maps/Underwater_MarineCave/scripts.inc"
	.include "data/maps/MarineCave_Entrance/scripts.inc"
	.include "data/maps/MarineCave_End/scripts.inc"
	.include "data/maps/TerraCave_Entrance/scripts.inc"
	.include "data/maps/TerraCave_End/scripts.inc"
	.include "data/maps/AlteringCave/scripts.inc"
	.include "data/maps/MeteorFalls_StevensCave/scripts.inc"
	.include "data/scripts/shared_secret_base.inc"
	.include "data/maps/BattleColosseum_2P/scripts.inc"
	.include "data/maps/TradeCenter/scripts.inc"
	.include "data/maps/RecordCorner/scripts.inc"
	.include "data/maps/BattleColosseum_4P/scripts.inc"
	.include "data/maps/ContestHall/scripts.inc"
	.include "data/maps/InsideOfTruck/scripts.inc"
	.include "data/maps/SSTidalCorridor/scripts.inc"
	.include "data/maps/SSTidalLowerDeck/scripts.inc"
	.include "data/maps/SSTidalRooms/scripts.inc"
	.include "data/maps/BattlePyramidSquare01/scripts.inc"
	.include "data/maps/UnionRoom/scripts.inc"
	.include "data/maps/SafariZone_Northwest/scripts.inc"
	.include "data/maps/SafariZone_North/scripts.inc"
	.include "data/maps/SafariZone_Southwest/scripts.inc"
	.include "data/maps/SafariZone_South/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideWest/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerElevator/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.inc"
	.include "data/maps/SouthernIsland_Exterior/scripts.inc"
	.include "data/maps/SouthernIsland_Interior/scripts.inc"
	.include "data/maps/SafariZone_RestHouse/scripts.inc"
	.include "data/maps/SafariZone_Northeast/scripts.inc"
	.include "data/maps/SafariZone_Southeast/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideEast/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidTop/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.inc"
	.include "data/maps/BattleFrontier_RankingHall/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge1/scripts.inc"
	.include "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge2/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge3/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge4/scripts.inc"
	.include "data/maps/BattleFrontier_ScottsHouse/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge5/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge6/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge7/scripts.inc"
	.include "data/maps/BattleFrontier_ReceptionGate/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge8/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge9/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_1F/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_2F/scripts.inc"
	.include "data/maps/BattleFrontier_Mart/scripts.inc"
	.include "data/maps/FarawayIsland_Entrance/scripts.inc"
	.include "data/maps/FarawayIsland_Interior/scripts.inc"
	.include "data/maps/BirthIsland_Exterior/scripts.inc"
	.include "data/maps/BirthIsland_Harbor/scripts.inc"
	.include "data/maps/TrainerHill_Entrance/scripts.inc"
	.include "data/maps/TrainerHill_1F/scripts.inc"
	.include "data/maps/TrainerHill_2F/scripts.inc"
	.include "data/maps/TrainerHill_3F/scripts.inc"
	.include "data/maps/TrainerHill_4F/scripts.inc"
	.include "data/maps/TrainerHill_Roof/scripts.inc"
	.include "data/maps/NavelRock_Exterior/scripts.inc"
	.include "data/maps/NavelRock_Harbor/scripts.inc"
	.include "data/maps/NavelRock_Entrance/scripts.inc"
	.include "data/maps/NavelRock_B1F/scripts.inc"
	.include "data/maps/NavelRock_Fork/scripts.inc"
	.include "data/maps/NavelRock_Up1/scripts.inc"
	.include "data/maps/NavelRock_Up2/scripts.inc"
	.include "data/maps/NavelRock_Up3/scripts.inc"
	.include "data/maps/NavelRock_Up4/scripts.inc"
	.include "data/maps/NavelRock_Top/scripts.inc"
	.include "data/maps/NavelRock_Down01/scripts.inc"
	.include "data/maps/NavelRock_Down02/scripts.inc"
	.include "data/maps/NavelRock_Down03/scripts.inc"
	.include "data/maps/NavelRock_Down04/scripts.inc"
	.include "data/maps/NavelRock_Down05/scripts.inc"
	.include "data/maps/NavelRock_Down06/scripts.inc"
	.include "data/maps/NavelRock_Down07/scripts.inc"
	.include "data/maps/NavelRock_Down08/scripts.inc"
	.include "data/maps/NavelRock_Down09/scripts.inc"
	.include "data/maps/NavelRock_Down10/scripts.inc"
	.include "data/maps/NavelRock_Down11/scripts.inc"
	.include "data/maps/NavelRock_Bottom/scripts.inc"
	.include "data/maps/TrainerHill_Elevator/scripts.inc"
	.include "data/maps/Route104_Prototype/scripts.inc"
	.include "data/maps/Route104_PrototypePrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/Route109_SeashoreHouse/scripts.inc"
	.include "data/maps/Route110_TrickHouseEntrance/scripts.inc"
	.include "data/maps/Route110_TrickHouseEnd/scripts.inc"
	.include "data/maps/Route110_TrickHouseCorridor/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle1/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle2/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle3/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle4/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle5/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle6/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle7/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle8/scripts.inc"
	.include "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.inc"
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.inc"
	.include "data/maps/Route113_GlassWorkshop/scripts.inc"
	.include "data/maps/Route123_BerryMastersHouse/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_1F/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_2F/scripts.inc"
	.include "data/maps/Route119_House/scripts.inc"
	.include "data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc"
	.include "data/scripts/RyuSacrificeSystem.inc"
	.include "data/scripts/RyuDevonLine.inc"
	.include "data/scripts/RyuTeleportationMenu.inc"
	.include "data/scripts/RyuPasscodeMenu.inc"
	.include "data/scripts/RyuDebugMenu.inc"
	.include "data/scripts/std_msgbox.inc"
	.include "data/scripts/trainer_battle.inc"
	.include "data/scripts/new_game.inc"
	.include "data/scripts/hall_of_fame.inc"
	.include "data/scripts/RyuLifeSkillScripts.inc"
	.include "data/scripts/RyuFossilReviver.inc"
	.include "data/scripts/frontiermode.inc"
	.include "data/scripts/fertilizer.inc"
	.include "data/scripts/RyuRandomGruntChatterScripts.inc"
	.include "data/scripts/RyuAchievementPowerScripts.inc"
	.include "data/scripts/slakoth_vending_machine.inc"
	.include "data/scripts/_poryscripts/RyuDebug_BetaMenu.inc"
	.include "data/scripts/_poryscripts/RyuScripts.inc"
	.include "data/scripts/_poryscripts/FactionQuestsNaturalists.inc"
	.include "data/scripts/_poryscripts/FactionQuestsGeneral.inc"
	.include "data/scripts/_poryscripts/FactionQuestsProfessionals.inc"
	.include "data/scripts/_poryscripts/FactionQuestsOutcasts.inc"
	.include "data/scripts/_poryscripts/FactionQuestsPokefans.inc"
	.include "data/scripts/_poryscripts/FactionQuestsNobles.inc"
	.include "data/scripts/_poryscripts/FactionQuestsStudents.inc"
	.include "data/scripts/_poryscripts/RyuRealEstateScripts.inc"
	.include "data/scripts/_poryscripts/RyuBotany.inc"
	.include "data/scripts/_poryscripts/RyuBallChanger.inc"
	.include "data/scripts/_poryscripts/RyuFollowerSystem.inc"
	.include "data/scripts/_poryscripts/UserInterfaceCustomization.inc"
	.include "data/scripts/_poryscripts/RyuChampionRoom.inc"
	.include "data/scripts/_poryscripts/REHomeScripts.inc"
	.include "data/scripts/_poryscripts/DynamicDeliveryScripts.inc"
	.include "data/scripts/_poryscripts/RyuNatureSwap.inc"
	.include "data/scripts/_poryscripts/RyuHaremEndScripts.inc"
	.include "data/scripts/_poryscripts/RyuPokemonSalonScripts.inc"
	.include "data/scripts/_poryscripts/RyuIntroScripts.inc"
	.include "data/scripts/_poryscripts/movement.inc"
	.include "data/scripts/_poryscripts/Tutorials.inc"

EventScript_WhiteOut:: @ 8271857
	clearflag FLAG_RYU_TC_ENTERED
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
	end

EverGrandeCity_HallOfFame_EventScript_ResetEliteFour:: @ 82718CC
	clearflag FLAG_DEFEATED_ELITE_4_SIDNEY
	clearflag FLAG_DEFEATED_ELITE_4_PHOEBE
	clearflag FLAG_DEFEATED_ELITE_4_GLACIA
	clearflag FLAG_DEFEATED_ELITE_4_DRAKE
	setvar VAR_ELITE_4_STATE, 0
	return

	.include "data/scripts/pkmn_center_nurse.inc"
	.include "data/scripts/obtain_item.inc"
	.include "data/scripts/pc.inc"

@ scripts/notices.inc? signs.inc? See comment about text/notices.inc
Common_EventScript_ShowPokemartSign:: @ 8271E6A
	msgbox gText_PokemartSign, MSGBOX_SIGN
	end

Common_EventScript_ShowPokemonCenterSign:: @ 8271E73
	msgbox gText_PokemonCenterSign, MSGBOX_SIGN
	end

Common_ShowEasyChatScreen:: @ 8271E7C
	fadescreen FADE_TO_BLACK
	special ShowEasyChatScreen
	fadescreen FADE_FROM_BLACK
	return

Common_EventScript_ReadyPetalburgGymForBattle:: @ 8271E84
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	return

Common_EventScript_BufferTrendyPhrase:: @ 8271E8B
	dotimebasedevents
	setvar VAR_0x8004, 0
	special BufferTrendyPhraseString
	return

	.include "data/scripts/surf.inc"
	.include "data/scripts/rival_graphics.inc"

Common_EventScript_ShowBagIsFull:: @ 8272054
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull:: @ 827205E
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return

Common_EventScript_ShowNoRoomForDecor:: @ 8272067
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NoRoomForDecor:: @ 8272071
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	return

Common_EventScript_SetAbnormalWeather:: @ 827207A
	setweather WEATHER_ABNORMAL
	return

Common_EventScript_PlayGymBadgeFanfare:: @ 827207E
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

Common_EventScript_OutOfCenterPartyHeal:: @ 8272083
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

EventScript_RegionMap:: @ 827208F
	lockall
	msgbox Common_Text_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special FieldShowRegionMap
	waitstate
	releaseall
	end

Common_EventScript_PlayBrineysBoatMusic:: @ 82720A0
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, 0
	return

Common_EventScript_StopBrineysBoatMusic:: @ 82720A8
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	return

	.include "data/scripts/prof_birch.inc"

@ Below could be split as ferry.inc aside from the Rusturf tunnel script
Common_EventScript_FerryDepart:: @ 82721E2
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart: @ 82721F0
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_EventScript_SetRusturfTunnelOpen:: @ 8272216
	return

EventScript_UnusedBoardFerry:: @ 827222B
	delay 30
	applymovement PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	showobjectat PLAYER, 0
	delay 30
	applymovement PLAYER, Movement_UnusedBoardFerry
	waitmovement 0
	delay 30
	return

Movement_UnusedBoardFerry: @ 827224E
	walk_up
	step_end

Common_EventScript_FerryDepartIsland:: @ 8272250
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Ferry_EventScript_DepartIslandSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq Ferry_EventScript_DepartIslandWest
	delay 30
	hideobjectat PLAYER, 0
	call Common_EventScript_FerryDepart
	return

Common_EventScript_NameReceivedPartyMon:: @ 82723DD
	fadescreen FADE_TO_BLACK
	special ChangePokemonNickname
	waitstate
	return

Common_EventScript_PlayerHandedOverTheItem:: @ 82723E4
	bufferitemname 0, VAR_0x8004
	playfanfare MUS_OBTAIN_TMHM
	message gText_PlayerHandedOverTheItem
	waitmessage
	waitfanfare
	removeitem VAR_0x8004
	return

	.include "data/scripts/elite_four.inc"
	.include "data/scripts/check_furniture.inc"
	.include "data/text/record_mix.inc"
	.include "data/text/pc.inc"
	.include "data/text/pkmn_center_nurse.inc"
	.include "data/text/mart_clerk.inc"
	.include "data/text/obtain_item.inc"

@ The below and surf.inc could be split into some text/notices.inc
gText_PokemartSign:: @ 8272B6A
	.string "“Selected items for your convenience!”\n"
	.string "Pokémon MART$"

gText_PokemonCenterSign:: @ 8272B9E
	.string "“Rejuvenate your tired partners!”\n"
	.string "Pokémon CENTER$"

gText_MomOrDadMightLikeThisProgram:: @ 8272BCF
	.string "{STR_VAR_1} might like this program.\n"
	.string "… … … … … … … … … … … … … … … …\p"
	.string "Better get going!$"

gText_WhichFloorWouldYouLike:: @ 8272C1D
	.string "Welcome to LILYCOVE DEPARTMENT STORE.\p"
	.string "Which floor would you like?$"

gText_SandstormIsVicious:: @ 8272C5F
	.string "The sandstorm is vicious.\n"
	.string "It's impossible to keep going.$"

gText_SelectWithoutRegisteredItem:: @ 8272C98
	.string "An item in the BAG can be\n"
	.string "registered to SELECT for easy use.$"

gText_PokemonTrainerSchoolEmail:: @ 8272CD5
	.string "There's an e-mail from Pokémon TRAINER\n"
	.string "SCHOOL.\p"
	.string "… … … … … …\p"
	.string "A Pokémon may learn up to four moves.\p"
	.string "A TRAINER's expertise is tested on the\n"
	.string "move sets chosen for Pokémon.\p"
	.string "… … … … … …$"

gText_PlayerHouseBootPC:: @ 8272D87
	.string "{PLAYER} booted up the PC.$"

gText_PokeblockLinkCanceled:: @ 8272D9C
	.string "The link was canceled.$"

gText_UnusedNicknameReceivedPokemon:: @ 8272DB3
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_2} you received?$"

gText_PlayerWhitedOut:: @ 8272DE3
	.string "{PLAYER} is out of usable\n"
	.string "Pokémon!\p{PLAYER} passed out!$"

gText_RegisteredTrainerinPokeNav:: @ 8272E0F
	.string "Registered {STR_VAR_1} {STR_VAR_2}\n"
	.string "in the POKéNAV.$"

gText_ComeBackWithSecretPower:: @ 8272E30
	.string "Do you know the TM SECRET POWER?\p"
	.string "Our group, we love the TM SECRET\n"
	.string "POWER.\p"
	.string "One of our members will give it to you.\n"
	.string "Come back and show me if you get it.\p"
	.string "We'll accept you as a member and sell\n"
	.string "you good stuff in secrecy.$"

gText_PokerusExplanation:: @ 8272F07
	.string "Your Pokémon may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to Pokémon.\p"
	.string "While infected, Pokémon are said to\n"
	.string "grow exceptionally well.$"

	.include "data/text/surf.inc"

gText_DoorOpenedFarAway:: @ 827301B
	.string "It sounded as if a door opened\n"
	.string "somewhere far away.$"

gText_BigHoleInTheWall:: @ 827304E
	.string "There is a big hole in the wall.$"

gText_SorryWirelessClubAdjustments:: @ 827306F
	.string "I'm terribly sorry.\n"
	.string "The Pokémon WIRELESS CLUB is\l"
	.string "undergoing adjustments now.$"

gText_UndergoingAdjustments:: @ 82730BC
	.string "It appears to be undergoing\n"
	.string "adjustments…$"

gBallBlackMarket::
	.string "Psst... Hurry up!\pI don't want caught!$"

gText_PlayerHandedOverTheItem:: @ 8273161
	.string "{PLAYER} handed over the\n"
	.string "{STR_VAR_1}.$"

gText_ThankYouForAccessingMysteryGift:: @ 8273178
	.string "Thank you for accessing the\n"
	.string "MYSTERY GIFT System.$"

gText_PlayerFoundOneTMHM:: @ 82731A9
	.string "{PLAYER} found one {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_Sudowoodo_Attacked:: @ 82731BD
	.string "The weird tree doesn't like the\n"
	.string "WAILMER PAIL!\p"
	.string "The weird tree attacked!$"

gText_LegendaryFlewAway:: @ 8273204
	.string "The {STR_VAR_1} flew away!$"

	.include "data/text/pc_transfer.inc"
	.include "data/text/abnormal_weather.inc"

EventScript_SelectWithoutRegisteredItem:: @ 82736B3
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

Common_EventScript_NopReturn:: @ 827374E
	return

EventScript_CableClub_SetVarResult0:: @ 8273755
	setvar VAR_RESULT, 0
	return

Common_EventScript_UnionRoomAttendant:: @ 827375B
	call CableClub_EventScript_UnionRoomAttendant
	end

Common_EventScript_WirelessClubAttendant:: @ 8273761
	call CableClub_EventScript_WirelessClubAttendant
	end

Common_EventScript_DirectCornerAttendant:: @ 8273767
	call CableClub_EventScript_DirectCornerAttendant
	end

Common_EventScript_RemoveStaticPokemon:: @ 827376D
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Common_EventScript_LegendaryFlewAway:: @ 8273776
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

	.include "data/scripts/pc_transfer.inc"
	.include "data/scripts/abnormal_weather.inc"
	.include "data/scripts/trainer_script.inc"
	.include "data/scripts/berry_tree.inc"
	.include "data/scripts/secret_base.inc"
	.include "data/scripts/cable_club.inc"
	.include "data/text/cable_club.inc"
	.include "data/scripts/contest_hall.inc"
	.include "data/text/contest_strings.inc"
	.include "data/text/contest_link.inc"
	.include "data/text/contest_painting.inc"
	.include "data/text/trick_house_mechadolls.inc"
	.include "data/scripts/tv.inc"
	.include "data/text/tv.inc"
	.include "data/scripts/interview.inc"
	.include "data/scripts/gabby_and_ty.inc"
	.include "data/text/pokemon_news.inc"
	.include "data/scripts/mauville_man.inc"
	.include "data/scripts/field_move_scripts.inc"
	.include "data/scripts/item_ball_scripts.inc"
	.include "data/scripts/mystery_event_club.inc"
	.include "data/scripts/day_care.inc"
	.include "data/scripts/players_house.inc"
	.include "data/scripts/berry_blender.inc"
	.include "data/text/mauville_man.inc"
	.include "data/text/trainers.inc"
	.include "data/scripts/repel.inc"
	.include "data/scripts/safari_zone.inc"
	.include "data/scripts/roulette.inc"
	.include "data/text/pokedex_rating.inc"
	.include "data/text/lottery_corner.inc"
	.include "data/text/event_ticket_1.inc"
	.include "data/text/braille.inc"
	.include "data/text/berries.inc"
	.include "data/text/shoal_cave.inc"
	.include "data/text/check_furniture.inc"
	.include "data/scripts/cave_hole.inc"
	.include "data/scripts/lilycove_lady.inc"
	.include "data/text/battle_dome.inc"
	.include "data/scripts/battle_pike.inc"
	.include "data/text/blend_master.inc"
	.include "data/text/battle_tent.inc"
	.include "data/text/event_ticket_2.inc"
	.include "data/text/move_tutors.inc"
	.include "data/scripts/move_tutors.inc"
	.include "data/scripts/trainer_hill.inc"
	.include "data/scripts/test_signpost.inc"
	.include "data/text/frontier_brain.inc"
	.include "data/text/save.inc"
	.include "data/text/birch_speech.inc"

	.include "data/maps/Littleroot_Town_Rival_HouseQuest/scripts.inc"

	.include "data/maps/AncientTomb1F/scripts.inc"

	.include "data/maps/AncientTomb2F/scripts.inc"

	.include "data/maps/AncientTombCore/scripts.inc"

	.include "data/maps/DesertTomb1F/scripts.inc"

	.include "data/maps/DesertTomb2F/scripts.inc"

	.include "data/maps/DesertTombCore/scripts.inc"

	.include "data/maps/SlateportCity_LeafsHouse/scripts.inc"

	.include "data/maps/EverGrandeCity_ThroneRoom/scripts.inc"

	.include "data/maps/LilycoveCity_TrainingCenter/scripts.inc"

	.include "data/maps/LilycoveCity_AquaCorporateOffice/scripts.inc"

	.include "data/maps/RustburoCity_DevonCorp2fStoryMap/scripts.inc"

	.include "data/maps/RustburoCity_DevonCorp1fStoryMap/scripts.inc"

	.include "data/maps/VictoryRoad_Cove/scripts.inc"

	.include "data/maps/SafariZone_HiddenGrotto/scripts.inc"

	.include "data/maps/Route66/scripts.inc"

	.include "data/maps/Route114_LanettesHouse_Basement/scripts.inc"

	.include "data/maps/Route135/scripts.inc"

	.include "data/maps/Underwater_Route135_1/scripts.inc"

	.include "data/maps/Route135_House1/scripts.inc"

	.include "data/maps/Route135_House2/scripts.inc"

	.include "data/maps/Route135_House3/scripts.inc"

	.include "data/maps/Route135_ManaphyTemple/scripts.inc"

	.include "data/maps/Underwater_Route135_2/scripts.inc"

	.include "data/maps/Route114_SuicuneCave/scripts.inc"

	.include "data/maps/FallarborTown_CaveTown/scripts.inc"

	.include "data/maps/FallarborTown_Lab/scripts.inc"

	.include "data/maps/FallarborTown_GemRefiner/scripts.inc"

	.include "data/maps/FallarborTown_ShardRefiner/scripts.inc"

	.include "data/maps/FallarborTown_CaveMart/scripts.inc"

	.include "data/maps/FallarborTown_FossilMani/scripts.inc"

	.include "data/maps/FallarborTown_MiningMasterHouse/scripts.inc"

	.include "data/maps/MeteorFalls_2F/scripts.inc"

	.include "data/maps/MeteorFalls_1F_3R/scripts.inc"

	.include "data/maps/MeteorFalls_3F/scripts.inc"

	.include "data/maps/SnowyShore/scripts.inc"

	.include "data/maps/MtFreeze/scripts.inc"

	.include "data/maps/FrostyForest/scripts.inc"

	.include "data/maps/CraggyCoast/scripts.inc"

	.include "data/maps/FrostbiteField/scripts.inc"

	.include "data/maps/SnowyShoreUnderwater/scripts.inc"

	.include "data/maps/FrostyForestUnderwater/scripts.inc"

	.include "data/maps/CraggyCoastUnderwater/scripts.inc"

	.include "data/maps/CraggyCoastUnderwaterCave/scripts.inc"

	.include "data/maps/CraggyCoastUnderwater2/scripts.inc"

	.include "data/maps/PolarPillar_1F/scripts.inc"

	.include "data/maps/PolarPillar_2F/scripts.inc"

	.include "data/maps/PolarPillar_3F/scripts.inc"

	.include "data/maps/PolarPillar_4F/scripts.inc"

	.include "data/maps/Igloo1/scripts.inc"

	.include "data/maps/Igloo2/scripts.inc"

	.include "data/maps/Igloo3/scripts.inc"

	.include "data/maps/Igloo4/scripts.inc"

	.include "data/maps/Route104_MrBrineysHouse_Story/scripts.inc"

	.include "data/maps/LilycoveCity_Harbor_Story/scripts.inc"

	.include "data/maps/SnowyShore_Mart/scripts.inc"

	.include "data/maps/MagmaHideout_AdminQuarters/scripts.inc"

	.include "data/maps/Igloo2Basement/scripts.inc"

	.include "data/maps/SootopolisCity_MagmaEvent/scripts.inc"

	.include "data/maps/LRT_BirchLab_MagmaEvent/scripts.inc"

	.include "data/maps/TreasureHuntersHouse_MagmaEvent/scripts.inc"

	.include "data/maps/Route124_MaxieHideoutCave/scripts.inc"

	.include "data/maps/FrostyForestUnderwater2/scripts.inc"

	.include "data/maps/MtFreeze_B1F/scripts.inc"

	.include "data/maps/MtFreeze_1F/scripts.inc"

	.include "data/maps/MtFreeze_2F/scripts.inc"

	.include "data/maps/MtFreeze_3F/scripts.inc"

	.include "data/maps/SnowyShore_House1/scripts.inc"

	.include "data/maps/SnowyShore_House2/scripts.inc"

	.include "data/maps/SnowyShore_House3/scripts.inc"

	.include "data/maps/SnowyShore_MrFrigusHouse/scripts.inc"

	.include "data/maps/FrostyGrotto/scripts.inc"

	.include "data/maps/FrostyForest_House/scripts.inc"

	.include "data/maps/FrostbiteField_House/scripts.inc"

	.include "data/maps/DewfordTown_House3/scripts.inc"

	.include "data/maps/MirageCave/scripts.inc"

	.include "data/maps/MirageCave_Underwater1/scripts.inc"

	.include "data/maps/MirageCave_Underwater2/scripts.inc"

	.include "data/maps/MirageCave_LakeCave/scripts.inc"

	.include "data/maps/MirageCave_House1/scripts.inc"

	.include "data/maps/MirageCave_House2/scripts.inc"

	.include "data/maps/MirageCave_House3/scripts.inc"

	.include "data/maps/MirageCave_House4/scripts.inc"

	.include "data/maps/MirageCave_House5/scripts.inc"

	.include "data/maps/MirageCave_House6/scripts.inc"

	.include "data/maps/MirageCave_House7/scripts.inc"
    .include "data/scripts/dexnav.inc"
    

	.include "data/maps/DebugMap/scripts.inc"

	.include "data/maps/StoryMap_KyogreChase/scripts.inc"

	.include "data/maps/AquaSubmarine/scripts.inc"

	.include "data/maps/Route121_BananaSlakothGardenEntrance/scripts.inc"

	.include "data/maps/BananaSlakothGarden/scripts.inc"

	.include "data/maps/BananaSlakothGarden_South/scripts.inc"

	.include "data/maps/SnowyShore_DarkWorld/scripts.inc"

	.include "data/maps/RustboroCity_PidgeysCoop/scripts.inc"

	.include "data/maps/Route119_LorwynsHouse/scripts.inc"

	.include "data/maps/SnowyShore_DarkWorld_PriestessHouse/scripts.inc"

	.include "data/maps/Limbo/scripts.inc"

	.include "data/maps/FallarborTown_VolcanionCave/scripts.inc"

	.include "data/maps/MauvilleCity_Restaurant/scripts.inc"

	.include "data/maps/MauvilleCity_FrontierBank/scripts.inc"

	.include "data/maps/OldaleTown_Home/scripts.inc"

	.include "data/maps/DewfordTown_Home/scripts.inc"

	.include "data/maps/FallarborTown_Home/scripts.inc"

	.include "data/maps/LilycoveCity_Home/scripts.inc"

	.include "data/maps/MauvilleCity_Home/scripts.inc"

	.include "data/maps/Route119_Home/scripts.inc"

	.include "data/maps/RustboroCity_Home/scripts.inc"

	.include "data/maps/SlateportCity_Home/scripts.inc"

	.include "data/maps/SnowyShore_Home/scripts.inc"

	.include "data/maps/SootopolisCity_Home/scripts.inc"

	.include "data/maps/VerdanturfTown_Home/scripts.inc"

	.include "data/maps/MossdeepCity_Home/scripts.inc"

	.include "data/maps/MauvilleCity_AdrastiWarehouse/scripts.inc"

	.include "data/maps/Victini/scripts.inc"

	.include "data/maps/LittlerootTown_BrendansHouse_UpperHallway/scripts.inc"

	.include "data/maps/LittlerootTown_BrendansHouse_MayBedroom/scripts.inc"

	.include "data/maps/LittlerootTown_DawnsHouse_UpperHallway/scripts.inc"

	.include "data/maps/LittlerootTown_DawnsHouse_MayBedroom/scripts.inc"


	.include "data/maps/Underworld/scripts.inc"

	.include "data/maps/IntroRoom/scripts.inc"

	.include "data/maps/LilycoveCity_Salon/scripts.inc"

	.include "data/maps/RustboroCity_PokemonSchool_Hall/scripts.inc"

	.include "data/maps/RustboroCity_PokemonSchool_TrainingRoom/scripts.inc"
