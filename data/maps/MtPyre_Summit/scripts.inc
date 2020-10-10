MtPyre_Summit_MapScripts:: @ 8231FF7
	.byte 0

MPS_Spiritomb::
	goto_if_set FLAG_RYU_FINISHED_SPIRITOMB_SIDEQUEST, ryu_end
	goto_if_set FLAG_RYU_SPIRITOMB_IN_PROGRESS, MPS_SpiritombContinue
	setflag FLAG_RYU_SPIRITOMB_IN_PROGRESS
	setvar VAR_RYU_SPIRITOMB_FAINTS, 0
	msgbox MPS_SpiritombIntro
	closemessage
	@insert special gfx effect here TODO: do
	msgbox MPS_SpiritombIntro2
	closemessage
	release
	end
	
MPS_SpiritombContinue::
	compare VAR_RYU_SPIRITOMB_FAINTS, 107
	goto_if_ge MPS_SpiritombFinish
	msgbox MPS_SpiritombNotFinishedYet
	release
	end
	
MPS_SpiritombFinish::
	msgbox MPS_SpiritombUnleashed
	playmoncry SPECIES_SPIRITOMB, 2
	waitmoncry
	closemessage
	msgbox MPS_SpiritombAttacks
	playmoncry SPECIES_SPIRITOMB, 2
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setflag FLAG_TEMP_D
	setwildbattle SPECIES_SPIRITOMB, VAR_RESULT, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	setflag FLAG_RYU_FINISHED_SPIRITOMB_SIDEQUEST
	release
	end

MPS_SpiritombIntro:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}...Hey…\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}...Did that stone just talk?\p"
	.string "{COLOR RED}{SHADOW LIGHT_GREY}...Hey you...\p"
	.string "I'm a spirit trapped here, kekeke.\p"
	.string "I have an offer you can't resist…..\n"
	.string "Kekeke, do you like Master Balls?\p"
	.string "If you slay 107 innocent pokemon,\n"
	.string "come back here… kekeke.\p"
	.string "I will grant you a Master Ball…$"
	
MPS_SpiritombIntro2:
	.string "({COLOR LIGHT_GREEN}{SHADOW GREEN}A Master Ball, huh?\n"
	.string " Just for fainting some pokemon?)\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}That… sounds like a good deal.\p"
	.string "{COLOR RED}{SHADOW LIGHT_GREY}Then you better get on it…\n"
	.string "Kekeke!$"

MPS_SpiritombAttacks:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Will you give me my Master Ball now?\p"
	.string "{COLOR RED}{SHADOW LIGHT_GREY}Kekeke!\p"
	.string "Kekeke!\p"
	.string "I have deceived you!\n"
	.string "You were merely a puppet!\p"
	.string "I just used you to gather souls!\n"
	.string "I have become powerful!\p"
	.string "Kekeke!\p"
	.string "Now we will destroy you!$"
	
MPS_SpiritombNotFinishedYet:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}Why are you still here?\n"
	.string "Gather more souls for me!$"
	
MPS_SpiritombUnleashed:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}So you have returned...\n"
	.string "I have enough souls!\p"
	.string "We have enough souls!$"

MP_Gengarite::
	finditem ITEM_GENGARITE, 1
	setflag FLAG_RYU_OBTAINED_GENGARITE
	removeobject 13
	release
	end

MtPyre_Summit_EventScript_OldMan:: @ 823213C
	lock
	faceplayer
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza:: @ 8232167
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManNewTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale:: @ 8232187
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale:: @ 8232190
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale:: @ 8232199
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady:: @ 82321A2
	lock
	faceplayer
	msgbox Normal_old_lady
	release
	end

Normal_old_lady:
	.string "Have you met our grandkids?\nThey run the gym in that eastern island.\pIf you see them, tell them to\nvisit us sometime!$"

MtPyre_Summit_EventScript_OldLadyOrbsReturned:: @ 82321CB
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake:: @ 82321D8
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned:: @ 82321E2
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis: @ 823290E
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken: @ 8232AD8
	.string "The Blue Orb and Red Orb taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"

MtPyre_Summit_Text_GroudonKyogreAwakened: @ 8232B4F
	.string "Oh, my goodness…\p"
	.string "You say that both Groudon and Kyogre\n"
	.string "have been awakened?\p"
	.string "It is said that the Blue Orb and\n"
	.string "the Red Orb quelled the rage of\l"
	.string "the two Pokémon…\p"
	.string "It is also said that the true owner\n"
	.string "of the Orbs still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the Orbs belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a Pokémon, but no one knows.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs: @ 8232CA6
	.string "The two men who took the Orbs came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs: @ 8232D1E
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient Pokémon…\p"
	.string "In the same way that we humans and\n"
	.string "Pokémon have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient Pokémon have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_WillYouHearOutMyTale: @ 8232E0C
	.string "Mt. Pyre is where we calm the spirits\n"
	.string "of Pokémon that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of Hoenn…\p"
	.string "The disembodied spirits of Pokémon\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the Hoenn region?$"

MtPyre_Summit_Text_GroudonKyogreTale: @ 8232F27
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The Blue Orb and the Red Orb brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two Orbs and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_WellThatTooIsFine: @ 8233162
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn: @ 82331A6
	.string "It is my role to pass on the legends\n"
	.string "of Hoenn to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "Sootopolis rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of Hoenn?$"

MtPyre_Summit_Text_HoennTrioTale: @ 823325D
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the Pokémon of\n"
	.string "the sky descended from a storm.\p"
	.string "The Pokémon, shining a vivid green,\n"
	.string "becalmed the two enraged Pokémon.\p"
	.string "Then, its duty done, the green Pokémon\n"
	.string "flew off into the wild blue yonder…$"

@==================================================================================================Special Scripts

MP_OldPeopleGiveEonTicket:
	.string "Hello, there, child. We were\ninstructed to give this to you.\p... ... ... ... ...\pWho instructed us?\nThe powers that be.  It's your fate.$"
