TrainerHill_2F_MapScripts:: @ 8268F81
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrainerHill_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	.byte 0

TrainerHill_2F_EventScript_Heal::
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox TrainerHill_2F_Text_HealedUpReadyToGo
	closemessage
	end

TrainerHill_2F_Text_HealedUpReadyToGo:
	.string "Healed up and ready to go!\n"
	.string "Give it your all!$"
