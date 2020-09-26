SnowyShore_MrFrigusHouse_MapScripts::
	.byte 0

SnowyShore_MrFrigusHouse_EventScript_MrFrigus::
	lock
	faceplayer
	goto_if_set FLAG_FRIGUS_QUEST_COMPLETED, SnowyShore_MrFrigusHouse_CheckForSnowballs
	goto_if_set FLAG_FRIGUS_QUEST_ACCEPTED, SnowyShore_MrFrigusHouse_CheckForArtefacts
	msgbox SnowyShore_MrFrigusHouse_Text_Introduction, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SnowyShore_MrFrigusHouse_ExplainQuest
	compare VAR_RESULT, NO
	goto_if_eq SnowyShore_MrFrigusHouse_ComeBackIf
	end

SnowyShore_MrFrigusHouse_ExplainQuest::
	msgbox SnowyShore_MrFrigusHouse_Text_ExplainQuest MSGBOX_DEFAULT
	setflag FLAG_FRIGUS_QUEST_ACCEPTED
	release
	end

SnowyShore_MrFrigusHouse_ComeBackIf::
	msgbox SnowyShore_MrFrigusHouse_Text_ComeBackIf MSGBOX_DEFAULT
	release
	end

SnowyShore_MrFrigusHouse_CheckForArtefacts::
	checkitem ITEM_ARTEFACT_1, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SnowyShore_MrFrigusHouse_PlayerLacksArtefact
	checkitem ITEM_ARTEFACT_2, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SnowyShore_MrFrigusHouse_PlayerLacksArtefact
	checkitem ITEM_ARTEFACT_3, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SnowyShore_MrFrigusHouse_PlayerLacksArtefact
	goto SnowyShore_MrFrigusHouse_PlayerHasAllArtefacts
	end

SnowyShore_MrFrigusHouse_PlayerLacksArtefact::
	msgbox SnowyShore_MrFrigusHouse_Text_LooksLike MSGBOX_DEFAULT
	release
	end

SnowyShore_MrFrigusHouse_PlayerHasAllArtefacts::
	msgbox SnowyShore_MrFrigusHouse_Text_YouveDoneIt MSGBOX_DEFAULT
	removeitem ITEM_ARTEFACT_1, 1
	removeitem ITEM_ARTEFACT_2, 1
	removeitem ITEM_ARTEFACT_3, 1
	giveitem ITEM_OVAL_CHARM
	msgbox SnowyShore_MrFrigusHouse_Text_TakeThisToo MSGBOX_DEFAULT
	giveitem ITEM_DRY_ICE
	setflag FLAG_FRIGUS_QUEST_COMPLETED
	release
	end

SnowyShore_MrFrigusHouse_Text_Introduction:
	.string "Hello young man, I am Mr Frigus.\p"
	.string "You look very fit, would you be\n"
	.string "willing to help me with something?$"

SnowyShore_MrFrigusHouse_Text_ExplainQuest:
	.string "I am an archeologist. When I was\n"
	.string "younger, I traveled across snowy\l"
	.string "regions in search for treasure.\p"
	.string "But when I came here to look for\n"
	.string "the Three Artefacts, I got injured.\p"
	.string "That's why I've settled here.\p"
	.string "Now, are you capable of finding\n"
	.string "the Three Artefacts for me?\p"
	.string "I will reward you with something\n"
	.string "I found on one of my journeys.$"

SnowyShore_MrFrigusHouse_Text_ComeBackIf:
	.string "Okay, come back if you change your\n"
	.string "mind.$"

SnowyShore_MrFrigusHouse_Text_LooksLike:
	.string "Looks like you haven't found all the\n"
	.string "artefacts yet. Keep searching!$"

SnowyShore_MrFrigusHouse_Text_YouveDoneIt:
	.string "You've done it! All three of the\n"
	.string "ancient artefacts.\p"
	.string "I am very grateful, please take\n"
	.string "this Charm as reward.$"

SnowyShore_MrFrigusHouse_Text_TakeThisToo:
	.string "Here, take this too. It will boost\n"
	.string "your Ice type pokemon.$"

@=============================================================================================Dry Ice exchange

SnowyShore_MrFrigusHouse_CheckForSnowballs::
	checkitem ITEM_SNOWBALL, 5
	compare VAR_RESULT, FALSE
	goto_if_eq SnowyShore_MrFrigusHouse_OfferDryIce
	goto SnowyShore_MrFrigusHouse_WantDryIce
	end

SnowyShore_MrFrigusHouse_OfferDryIce::
	msgbox SnowyShore_MrFrigusHouse_Text_IfYouWantMoreDryIce MSGBOX_DEFAULT
	release
	end

SnowyShore_MrFrigusHouse_WantDryIce::
	msgbox SnowyShore_MrFrigusHouse_Text_WantToExchange, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SnowyShore_MrFrigusHouse_GiveDryIce
	compare VAR_RESULT, NO
	goto_if_eq SnowyShore_MrFrigusHouse_ComeBackIf
	end

SnowyShore_MrFrigusHouse_GiveDryIce::
	msgbox SnowyShore_MrFrigusHouse_Text_HereYouGoDryIce MSGBOX_DEFAULT
	removeitem ITEM_SNOWBALL, 5
	giveitem ITEM_DRY_ICE
	release
	end

SnowyShore_MrFrigusHouse_Text_IfYouWantMoreDryIce:
	.string "If you want more Dry Ice, I can\n"
	.string "make some for you.\p"
	.string "I need 5 Snowballs for one Dry Ice.\p"
	.string "All wild Ice type pokemon have a\n"
	.string "small chance to hold a Snowball.$"

SnowyShore_MrFrigusHouse_Text_WantToExchange:
	.string "Do you want to exchange your 5\n"
	.string "Snowballs for one Dry Ice?$"

SnowyShore_MrFrigusHouse_Text_HereYouGoDryIce:
	.string "Here you go, one Dry Ice.\n"
	.string "Use it to beef up your Ice pokemon!$"
