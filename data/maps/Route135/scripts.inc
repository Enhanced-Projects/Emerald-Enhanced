Route135_MapScripts::
	.byte 0

Route135_EventScript_EggMan::
	lock
	faceplayer
	goto_if_set FLAG_RYU_RECEIVED_PHIONE_EGG, Route135_EventScript_ReceivedEgg
	msgbox Route135_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route135_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route135_EventScript_NoRoomForEgg
	msgbox Route135_Text_HopeYoullReturnEgg, MSGBOX_DEFAULT
	setflag FLAG_RYU_RECEIVED_PHIONE_EGG
	clearflag FLAG_RYU_HIDE_MANAPHY
	playfanfare MUS_FANFA4
	message Route135_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_PHIONE
	release
	end

Route135_EventScript_ReceivedEgg::
	msgbox Route135_Text_Sinkhole, MSGBOX_DEFAULT
	release
	end

Route135_EventScript_NoRoomForEgg::
	msgbox Route135_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

Route135_EventScript_DeclineEgg::
	msgbox Route135_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

Route135_EventScript_Fisherman::
	msgbox Route135_Text_RarePokemon, MSGBOX_NPC
	end

Route135_EventScript_Pooka::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox Route135_Text_Pooka, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
Route135_EventScript_Pokee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox Route135_Text_Pokee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route135_Text_HaveEggWillYouTakeIt:
	.string "Despite my old age, I still dive often.\p"
	.string "Recently, while diving in the sinkhole on\n"
	.string "this route, I found an egg.\p"
	.string "It seemed to be getting washed away to\n"
	.string "the surface.\p"
	.string "I wish to take it back to its mother,\n"
	.string "But I can't dive that deep anymore.\p"
	.string "So, could you return it for me?\n"
	.string "Will you take this egg to the bottom?$"

Route135_Text_HopeYoullReturnEgg:
	.string "Good! I hope you'll find its mother!\p"
	.string "If you do, could you tell me?\n"
	.string "I'd like to know what comes of it.$"

Route135_Text_ReceivedTheEgg:
	.string "{PLAYER} received the egg.$"

Route135_Text_NoRoomForThisEgg:
	.string "Oh? You've too many Pokémon.\n"
	.string "There's no room for this egg…$"

Route135_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "returning this egg, I will be here.$"

Route135_Text_Sinkhole:
	.string "Nobody knows how the sinkhole came\n"
	.string "to be.\p"
	.string "Some say it was caused by Groudon.\p"
	.string "Others think it was a meteor of sorts.\p"
	.string "Me? I think it was the work of a\n"
	.string "creature hidden in the depths.$"

Route135_Text_RarePokemon:
	.string "Me and my Wingull are fishing for a\n"
	.string "rare Pokemon.\p"
	.string "My uncle Briney once sighted a strange\n"
	.string "blue creature with a small body here.\p"
	.string "I wonder if I will hook it one day...$"

Route135_Text_Pooka:
	.string "Pooka: Pii piihyoro!$"

Route135_Text_Pokee:
	.string "Pokee: Piho pii piiho!$"

