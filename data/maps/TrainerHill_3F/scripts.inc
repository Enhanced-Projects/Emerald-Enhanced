TrainerHill_3F_MapScripts:: @ 8268F91
	map_script ON_RESUME, TrainerHill_OnResume
	map_script ON_FRAME, TrainerHill_OnFrame
	.byte 0

TrainerHill_3F_EventScript_Heal::
	msgbox TrainerHill_3F_Text_HealingPokemon
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox TrainerHill_3F_Text_GiveItYourAll
	closemessage
	end

TrainerHill_3F_Text_HealingPokemon:
	.string "Healing Pokemon...$"

TrainerHill_3F_Text_GiveItYourAll:
	.string "Give it your all!$"
