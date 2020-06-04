TrainerHill_3F_MapScripts:: @ 8268F91
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	.byte 0

TrainerHill_3F_EventScript_Heal::
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox TrainerHill_2F_Text_HealedUpReadyToGo
	closemessage
	end

TrainerHill_3F_Text_HealedUpReadyToGo:
	.string "Healed up and ready to go!\n"
	.string "Give it your all!$"
