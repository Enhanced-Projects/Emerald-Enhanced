FallarborTown_CaveMart_MapScripts::
	.byte 0

FallarborTown_CaveMart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_CaveMart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_CaveMart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_NONE
	release
	end

FallarborTown_CaveMart_EventScript_Boy::
	msgbox FallarborTown_CaveMart_Text_SoMuchMerchandise, MSGBOX_NPC
	end

FallarborTown_CaveMart_EventScript_Girl::
	msgbox FallarborTown_CaveMart_Text_FoundRareBone, MSGBOX_NPC
	end

FallarborTown_CaveMart_EventScript_Azumarill1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox FallarborTown_CaveMart_Text_Azumarill1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_CaveMart_EventScript_Azumarill2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox FallarborTown_CaveMart_Text_Azumarill2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_CaveMart_Text_SoMuchMerchandise:
	.string "These shops sell so much pokemon\n"
	.string "merchandise!\p"
	.string "I want to buy this Slakoth plush\n"
	.string "for my little brother.$"

FallarborTown_CaveMart_Text_Azumarill1:
	.string "Azumarill: Marimari?$"

FallarborTown_CaveMart_Text_Azumarill2:
	.string "Azumarill: Mari mareeeee!$"

FallarborTown_CaveMart_Text_FoundRareBone:
	.string "My Azumarill found a Rare Bone in the\n"
	.string "mines, so I went here to sell it.\p"
	.string "The Rare Bone, that is.$"

