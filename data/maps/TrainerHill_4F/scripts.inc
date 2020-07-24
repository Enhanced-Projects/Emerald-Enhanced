TrainerHill_4F_MapScripts:: @ 8268F9C
	map_script ON_RESUME, TrainerHill_OnResume
	map_script ON_FRAME, TrainerHill_OnFrame
	.byte 0

TrainerHill_4F_EventScript_Heal::
	msgbox TrainerHill_4F_Text_HealingPokemon
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox TrainerHill_4F_Text_GiveItYourAll
	closemessage
	end

TrainerHill_4F_Text_HealingPokemon:
	.string "Healing Pokemon...$"

TrainerHill_4F_Text_GiveItYourAll:
	.string "Give it your all!$"
