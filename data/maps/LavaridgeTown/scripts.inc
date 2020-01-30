LavaridgeTown_MapScripts:: @ 81EA4D3
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LT_CheckRivalGiftStatus
	.byte 0

LavaridgeTown_OnTransition: @ 81EA4DE
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_HideMapNamePopup
	end

LT_CheckRivalGiftStatus::
	map_script_2 VAR_TEMP_D, 0, LT_SetRivalPosForReGift
	.2byte 0

LT_SetRivalPosForReGift::
	setvar VAR_TEMP_D, 1
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_set FLAG_RYU_BRENDAN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_unset FLAG_RYU_INTERACTED_LAVARIDGE, ryu_end
	call Common_EventScript_SetupRivalGfxId
	setobjectxy 7, 9, 10
	end

LT_SetRivalFemale::
	setvar EVENT_OBJ_GFX_VAR_3, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

LT_SetRivalMale::
	setvar EVENT_OBJ_GFX_VAR_3, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut:: @ 81EA514
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos:: @ 81EA518
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers:: @ 81EA53F
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup:: @ 81EA543
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_EventScript_HotSpringsTrigger:: @ 81EA6FA
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings:: @ 81EA70B
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM:: @ 81EA70E
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan:: @ 81EA717
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin:: @ 81EA720
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1:: @ 81EA729
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2:: @ 81EA732
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF:: @ 81EA73B
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman:: @ 81EA744
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_FANFA4
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg:: @ 81EA787
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg:: @ 81EA791
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg:: @ 81EA79B
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign:: @ 81EA7A5
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign:: @ 81EA7AE
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign:: @ 81EA7B7
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_HaveEggWillYouTakeIt: @ 81EAB80
	.string "I have here an EGG.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with Pokémon and\l"
	.string "carried about.\p"
	.string "You are a Trainer, yes?\n"
	.string "And your Pokémon radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this EGG to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg: @ 81EACC0
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"

LavaridgeTown_Text_ReceivedTheEgg: @ 81EACF4
	.string "{PLAYER} received the EGG.$"

LavaridgeTown_Text_NoRoomForThisEgg: @ 81EAD09
	.string "Oh? You've too many Pokémon.\n"
	.string "There's no room for this EGG…$"

LavaridgeTown_Text_AsYouWishThen: @ 81EAD44
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare: @ 81EAD9E
	.string "Every so often, an EGG will be found at\n"
	.string "the Pokémon DAY CARE.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_HotSpringsNeverRunDry: @ 81EAE03
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_PokemonNippedBackside: @ 81EAEE1
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A Pokémon nipped my backside!$"

LavaridgeTown_Text_OhYouLikeHotSprings: @ 81EAF4E
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay: @ 81EAF9B
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "Gym Leader like Flannery.$"

LavaridgeTown_Text_IfPokemonInHotSprings: @ 81EB003
	.string "If people put Pokémon in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_HotSpringsClaims: @ 81EB092
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_TownSign: @ 81EB12B
	.string "LAVARIDGE TOWN\p"
	.string "“Pokémon CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_GymSign: @ 81EB178
	.string "LAVARIDGE TOWN Pokémon Gym\n"
	.string "LEADER: Flannery\l"
	.string "“One with a fiery passion that burns!”$"

LavaridgeTown_Text_HerbShopSign: @ 81EB1CB
	.string "Pokémon HERB SHOP\n"
	.string "“Bitter taste--better cure!”$"


@=============================================================================================RIVAL STUFF
LT_RivalEnter::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_set FLAG_RYU_BRENDAN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_unset FLAG_DEFEATED_LAVARIDGE_GYM , ryu_end
	goto_if_set FLAG_TEMP_A, ryu_end
	goto_if_set FLAG_RYU_INTERACTED_LAVARIDGE, LT_HasSpace
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq lrt_malerivalenter
	playbgm MUS_GIRL_SUP, 1
	lock
	playse SE_DOOR
	waitse
	addobject 7
	playse SE_PIN
	waitse
	applymovement 7, LT_RivalLeavingPC
	waitmovement 0
	goto LT_FemaleRivalInteraction
	
lrt_malerivalenter::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_set FLAG_RYU_BRENDAN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_unset FLAG_DEFEATED_LAVARIDGE_GYM , ryu_end
	goto_if_set FLAG_TEMP_A, ryu_end
	goto_if_set FLAG_RYU_INTERACTED_LAVARIDGE, LT_HasSpace
	playbgm MUS_BOY_SUP, 1
	lock
	playse SE_DOOR
	waitse
	addobject 7
	playse SE_PIN
	waitse
	applymovement 7, LT_RivalLeavingPC
	waitmovement 0
	goto LT_MaleRivalInteraction
	
LT_FemaleRivalInteraction:: @ 81EA5B5
	lockall
	faceplayer
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	msgbox LT_FemaleRivalIntro, MSGBOX_DEFAULT
	waitmessage
	closemessage
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LT_FemalRivalGiftPokeNoSpace
	special RyuDawnGiftPoke
	setflag FLAG_RYU_DAWN_GIFTPOKE_RECEIVED
	drawcustompic 2, SPECIES_SNEASEL, 10, 3
	playmoncry SPECIES_SNEASEL, 0
	waitmoncry
	playfanfare MUS_FANFA4
	waitfanfare
	hidemonpic
	msgbox LT_RECEIVEDPOKE, MSGBOX_SIGN
	msgbox LT_GivePokeExplanation, MSGBOX_DEFAULT
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	savebgm MUS_DUMMY
	fadedefaultbgm
	goto_if_unset FLAG_RYU_LT_RIVAL, LT_Rival2Leave
	applymovement 7, LT_RivalLeavesTown
	waitmovement 0
	removeobject 7
	release
	end
	
LT_MaleRivalInteraction:: @ 81EA5B5
	lockall
	faceplayer
	drawheadshot HEAD_BRENDAN
	msgbox LT_MaleRivalIntro, MSGBOX_DEFAULT
	waitmessage
	closemessage
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LT_MaleRivalGiftPokeNoSpace
	special RyuBrendanGiftPoke
	playse SE_EXPMAX
	waitse
	setflag FLAG_RYU_BRENDAN_GIFTPOKE_RECEIVED
	showmonpic SPECIES_SNORUNT, 10, 3
	playmoncry SPECIES_SNORUNT, 0
	waitmoncry
	playfanfare MUS_FANFA4
	waitfanfare
	hidemonpic
	msgbox LT_MaleRECEIVEDPOKE, MSGBOX_SIGN
	msgbox LT_MaleGivePokeExplanation, MSGBOX_DEFAULT
	waitmessage
	savebgm MUS_DUMMY
	removecutscenesprites
	fadedefaultbgm
	goto_if_unset FLAG_RYU_LT_RIVAL2, LT_maleRival2Leave
	applymovement 7, LT_RivalLeavesTown
	waitmovement 0
	removeobject 7
	special DrawWholeMapView
	release
	end

LT_RivalEnter2::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_unset FLAG_DEFEATED_LAVARIDGE_GYM , ryu_end
	goto_if_set FLAG_TEMP_A, ryu_end
	goto_if_set FLAG_RYU_INTERACTED_LAVARIDGE, LT_HasSpace
	applymovement EVENT_OBJ_ID_PLAYER, LT_stepright
	goto LT_RivalEnter
	
LT_MaleRivalEnter2::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_unset FLAG_DEFEATED_LAVARIDGE_GYM , ryu_end
	goto_if_set FLAG_TEMP_A, ryu_end
	goto_if_set FLAG_RYU_INTERACTED_LAVARIDGE, LT_HasSpace
	applymovement EVENT_OBJ_ID_PLAYER, LT_stepright
	goto LT_RivalEnter
	
LT_RivalEnter3::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_unset FLAG_DEFEATED_LAVARIDGE_GYM , ryu_end
	goto_if_set FLAG_TEMP_A, ryu_end
	goto_if_set FLAG_RYU_INTERACTED_LAVARIDGE, LT_HasSpace
	applymovement EVENT_OBJ_ID_PLAYER, LT_stepleft
	goto LT_RivalEnter
	
LT_MaleRivalEnter3::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	goto_if_unset FLAG_DEFEATED_LAVARIDGE_GYM , ryu_end
	goto_if_set FLAG_TEMP_A, ryu_end
	goto_if_set FLAG_RYU_INTERACTED_LAVARIDGE, LT_HasSpace
	applymovement EVENT_OBJ_ID_PLAYER, LT_stepleft
	goto LT_RivalEnter
	
LT_stepright:
	walk_right
	face_up
	step_end
	
LT_stepleft:
	walk_left
	face_up
	step_end
	
LT_HasSpace::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LT_HasSpace2
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LT_FemalRivalGiftPokeNoSpace
	setflag FLAG_RYU_LT_RIVAL
	goto LT_FemaleRivalInteraction
	
LT_HasSpace2::
	goto_if_set FLAG_RYU_DAWN_GIFTPOKE_RECEIVED, ryu_end
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq ryu_end
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LT_MaleRivalGiftPokeNoSpace
	setflag FLAG_RYU_LT_RIVAL2
	goto LT_MaleRivalInteraction
	
LT_RECEIVEDPOKE:
	.string "{PLAYER} received a Sneasel!$"
	
LT_MaleRECEIVEDPOKE:
	.string "{PLAYER} received a Snorunt!$"
	
LT_Rival2Leave::
	applymovement 7, LT_RivalLeavesTown
	waitmovement 0
	removeobject 7
	release
	end
	
LT_maleRival2Leave::
	applymovement 7, LT_RivalLeavesTown
	waitmovement 0
	removeobject 7
	release
	end

LT_FemalRivalGiftPokeNoSpace::
	setflag FLAG_TEMP_A
	msgbox LT_NoSpace MSGBOX_NPC
	removecutscenesprites
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_RYU_INTERACTED_LAVARIDGE
	clearflag FLAG_RYU_LT_RIVAL
	release
	end

LT_MaleRivalGiftPokeNoSpace::
	setflag FLAG_TEMP_A
	msgbox LT_MaleNoSpace MSGBOX_NPC
	savebgm MUS_DUMMY
	removecutscenesprites
	fadedefaultbgm
	setflag FLAG_RYU_INTERACTED_LAVARIDGE
	clearflag FLAG_RYU_LT_RIVAL2
	release
	end

LT_MaleNoSpace:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Yo! Come chat with me when you\n"
	.string "have space in your group!\p"
	.string "Trust me!$"

LT_NoSpace:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hey! Come back when you have space\n"
	.string "in your party... Just trust me!\p"
	.string "I'll wait here!$"

LT_FemaleRivalIntro: @ 81EA7C0
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}! Long time no see!\p"
	.string "Oh? I was in the hot springs.\n"
	.string "It's a shame you couldn't join me...\p"
    .string "You might have gotten a good show...\n"
	.string "Anyways, I want you to have this\p"
	.string "pokémon. It is a little too...\n"
	.string "facetious for my training methods.$"
	
LT_MaleRivalIntro: @ 81EA9A2
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: {PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "You look different... Did you change\p"
	.string "your hair? I like it!\n"
	.string "...\p"
	.string "Hey, so I caught this pokémon a while\n"
	.string "back, and I can't train it. It gets really\p"
	.string "shy, and doesn't like to train with the\n"
	.string "rest of my team. I think it needs a\p"
	.string "softer touch.$"

LT_GivePokeExplanation: @ 81EA897
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: It's a Sneasel! They're\n"
	.string "known to be little pranksters\p"
	.string "but extremely strong when trained\n"
	.string "for battle. This one is especially\p"
	.string "bull-headed. Probably has a nature\n"
	.string "well oriented for battle.\p"
	.string "If you're trying to impress me...\n"
	.string "It's working! I'm going to go\p"
	.string "challenge your father in Petalburg.\n"
	.string "Hope to see you and Sneasel soon!$"

LT_MaleGivePokeExplanation: @ 81EA897
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: It's a Snorunt! They're\n"
	.string "known to require patience and a\p"
	.string "light touch to evolve into a rare\n"
	.string "pokémon called Froslass.\p"
	.string "This one's kinda shy. I bet\n"
	.string "it can really cause some one\p"
	.string "a bad time in battle.\n"
	.string "I wish I could spend more time\p"
	.string "with you and Snorunt, but I have\n"
	.string "to help my dad. Honestly, he's so\p"
	.string "lost without me! Anyways, Nice\n"
	.string "chatting with you, hope to see\p"
	.string "you soon!$"
	
LT_RivalLeavingPC:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
LT_RivalLeavesTown:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

