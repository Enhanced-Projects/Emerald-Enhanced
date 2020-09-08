SlateportCity_LanasHouse_MapScripts::
	.byte 0

LeafHouse_brother::
	lock
	msgbox LH_bro_chat MSGBOX_NPC
	release
	end
	
LH_AltLeafStoryTrigger::
	end

LH_Intro::
	lock
	compare VAR_RYU_DS_LANA_STAGE, 2
	goto_if_ge ryu_end
	setvar VAR_RYU_DS_LANA_STAGE, 1
	applymovement 1, LH_bro_move
	waitmovement 0
	msgbox LH_Bro_intro MSGBOX_NPC
	waitmessage
	setvar VAR_RYU_DS_LANA_STAGE, 2
	release
	end
	
LH_bro_move:
	walk_down
	step_end

LH_Leaf_Home_chat::
	lock
	faceplayer
	compare VAR_RYU_DS_LANA_STAGE, 4
	goto_if_eq LH_alreadytalked
	call_if_set FLAG_RYU_DS_LEAF_PARTNERS, LH_Afterstory
	goto_if_set FLAG_RYU_DS_LEAF_LINE_CANCELLED, LH_LeafBadEnd
	goto_if_set FLAG_RYU_DS_LEAF_LOVERS, LH_StayTheNight
	msgbox LH_chat1 MSGBOX_DEFAULT
	applymovement 2, LH_Step
	waitmovement 0
	msgbox LH_chat2 MSGBOX_DEFAULT
	msgbox LH_End MSGBOX_SIGN
	setvar VAR_RYU_DS_LANA_STAGE, 4
	applymovement 2, LH_read
	waitmovement 0
	release
	end

LH_Afterstory::
	goto_if_set FLAG_RECEIVED_MYSTIC_TICKET, LH_StayTheNight
	msgbox LH_Lana_MysticTicketGift
	closemessage
	additem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	msgbox LH_GIFT_GIVEN
	release
	end
	
LH_alreadytalked::
	goto_if_set FLAG_SYS_GAME_CLEAR, LH_EventStart
	msgbox LH_finished MSGBOX_SIGN
	closemessage
	applymovement 2, LH_read
	waitmovement 0
	release
	end
	
LH_EventStart::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	call_if_set FLAG_RYU_PLAYER_HELPING_AQUA, LH_AquaMember
	call_if_set FLAG_RYU_PLAYER_HELPING_MAGMA, LH_MagmaMember
	msgbox LH_BeginQuest MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LH_PlayerShoved
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 2, LH_LanaLeaves
	waitmovement 2
	playse SE_DOOR
	setflag FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO
	removeobject 2
	special DrawWholeMapView
	msgbox LH_QuestStarted MSGBOX_DEFAULT
	closemessage
	setvar VAR_RYU_DS_LANA_STAGE, 10
	release
	end
	
LH_AquaMember::
	goto_if_set FLAG_RYU_ARCHIE_SUCCESSFUL, LH_LeafBadEnd
	return

LH_MagmaMember::
	setflag FLAG_RYU_DS_LEAF_LINE_CANCELLED
	msgbox LH_LeafBadEndMsgMagma MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	setvar VAR_RYU_DS_LANA_STAGE, 666
	release
	end

	
LH_LeafBadEnd::
	setflag FLAG_RYU_DS_LEAF_LINE_CANCELLED
	msgbox LH_LeafBadEndMsgAqua MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	setvar VAR_RYU_DS_LANA_STAGE, 666
	release
	end
	
LH_StayTheNight::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	msgbox LH_NightQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LH_LeafNight
	msgbox LH_FollowerLanaQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FollowerLeafSetup
	msgbox LH_Dispt MSGBOX_DEFAULT
	release
	end
	
LH_LeafNight:
	msgbox LH_LeafNightMsg1 MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LH_PlayerToBed
	applymovement 2, LH_LeafToBed
	waitmovement 2
	fadenewbgm MUS_DUMMY
	fadescreen 1
	msgbox LH_LeafNightSceneMsg MSGBOX_DEFAULT
	delay 40
	closemessage
	fadedefaultbgm
	fadescreen 0
	msgbox LH_LeafNightSceneMsg2 MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_HeartEmote
	waitmovement 2
	applymovement OBJ_EVENT_ID_PLAYER, LH_RelSceneEnd
	waitmovement OBJ_EVENT_ID_PLAYER
	call_if_set FLAG_RYU_DS_COURTNEY_LOVERS, LH_CourtneyCaughtPlayer
	release
	end
	
LH_CourtneyCaughtPlayer::
	playse SE_DOOR
	waitse
	addobject 3
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 3, LH_CourtneyToPlayer
	waitmovement 3
	msgbox LH_CourtneyCaughtMsg
	closemessage
	playse SE_DOOR
	waitse
	applymovement 3, LH_CourtneyLeave
	waitmovement 3
	removeobject 3
	setflag FLAG_RYU_DS_LEAF_LINE_CANCELLED
	setvar VAR_RYU_DS_LANA_STAGE, 666
	applymovement OBJ_EVENT_ID_PLAYER, LH_PlayerExitHouse
	waitmovement OBJ_EVENT_ID_PLAYER
	warpsilent MAP_SLATEPORT_CITY, 255, 14, 19
	waitstate

	
LH_PlayerExitHouse:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end
	
LH_CourtneyToPlayer:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end
	
LH_CourtneyLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

LH_CourtneyCaughtMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Ohohoho what is this?\nCaught red-handed!\pIf I catch you here again,\nI'll send her packing myself!$"

LH_FollowerLanaQuery:
    .string "Lana: {COLOR LIGHT_RED}{SHADOW RED}It's been a while since I've\n"
    .string "been out with someone.\p"
    .string "Can I come with you, please?$"
	
LH_NightQuery:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Hey, {PLAYER}. Did you...want to\n"
  	.string "spend the night with me?$"

LH_Dispt:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She looks a little disappointed.)$"

LH_LeafNightMsg1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hehe, I knew you couldn't resist.$"

LH_LeafNightSceneMsg:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana and {PLAYER} climb into the\n"
	.string " together and hold one another\l"
	.string " in their arms.)\p"
	.string " (Lana holds you tightly and\l"
	.string " kisses you on the forehead.)$"

LH_LeafNightSceneMsg2:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lana: You're so warm and cuddly...\n"
    .string "Like a big teddy.\p"
    .string "Thanks for staying, {PLAYER}.$"

LH_LeafBadEndMsgAqua:
    .string " (She sees the Aqua emblem on your\n"
    .string " chest and huffs. She then gives\p"
    .string " you a very disapproving\n"
    .string " look. It would appear she's not\l"
    .string " happy with your choice of work.)$"

LH_LeafBadEndMsgMagma:
	.string " (She sees the Magma emblem on your\n"
    .string " chest and huffs. She then gives\p"
    .string " you a very disapproving\n"
    .string " look. It would appear she's not\l"
    .string " happy with your choice of work.)$"

LH_Lana_MysticTicketGift:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lana: Hey, {PLAYER}, I have a\n"
    .string "present for you. It was sent to me\p"
    .string "from my parents in Kanto. I want\n"
    .string "you to have it.\p"
    .string "It's a ticket that will grant you\n"
    .string "passage to a mystical place.$"

LH_GIFT_GIVEN:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I think you will like it there.\n"
    .string "I've visted there once or twice,\l"
    .string "You will meet some amazing creatures!$"
	
LH_PlayerToBed:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walK_in_place_down
	step_end
	
LH_LeafToBed:
	delay_16
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walK_slow_up
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walK_in_place_down
	step_end
	
	
LH_PlayerShoved:
	walk_fastest_right
	walk_in_place_left
	step_end

LH_LanaLeaves:
	delay_16
	delay_8
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_down
	step_end
	
LH_RelSceneEnd:
	walk_left
	walk_left
	walk_left
	walk_in_place_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
LH_read:
	face_right
	step_end
	
LH_Step:
	walk_in_place_up
	step_end
	
LH_BeginQuest:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE} Hm? What is it?\p  {COLOR LIGHT_GREEN}{SHADOW GREEN}(She points to your pokénav.)\p{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh, you want it? Here.\p{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ...\n"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She takes it only for a moment\p before handing it back to you.)$"

LH_QuestStarted:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Hey, wait!\p{COLOR DARK_GREY}{SHADOW GREEN} Hmm...this mark on the map...\n it seems to be the house just\l north of town. Is that where she's\l headed?$"

	
LH_Bro_intro:
    .string "Who are you, and why are you here?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I'm {PLAYER}. I saw a girl\n"
    .string "come in here, and I wanted to meet\l"
    .string "her. She seemed new to the area.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Guy: Oh, you're talking about my\n"
    .string "sister. Uh... She doesn't \p"
    .string "really speak anymore, She's not much\n"
    .string "of a conversationalist. You can try\l"
    .string "though. Good luck!$"

	
LH_bro_chat:
	.string "Our family recently moved here\n"
	.string "from Kanto. Our parents are out\p"
	.string "working most of the time, so it's\n"
	.string "just me and Lana here, usually.$"
	
LH_finished:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana looks up and smiles\n"
	.string " at you, then resumes reading.)$"
	
LH_End:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana sits down and starts\n"
	.string " reading a magazine with a rare\p"
	.string " Pokémon on the cover. Guess\n"
	.string " she's done talking.)$"
	
LH_chat1:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE} Umm... hi. I'm {PLAYER}.\n"
	.string "Is your name... Lana?\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She nods.)\n"
	.string "{COLOR LIGHT_RED}{SHADOW RED}... ... ... \p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Well... I saw you exiting the\p"
	.string "PokeCenter. I really like your\n"
	.string "perfume. It's nice.\p"
    .string "My name is {PLAYER}. Are you new\n"
    .string "to Slateport, or Hoenn as a whole?\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (She nods)\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}... ... ...\n"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER} Well, Welcome. I'd like to\p"
    .string "be your friend. Would you like a\n"
    .string "tour? I'd be happy to show you\l"
    .string "around.\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (She shakes her head. She seems to\n"
    .string " be very shy.)\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE} Well if you change your\n"
    .string "mind, here's my number...\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (She nods once more and then pulls\n"
    .string " a magazine out of her bag and starts\p"
    .string " looking at it. Guess you should leave\n"
    .string " her to it.)$"

LH_chat2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Thanks.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She leans back and puts a finger\n"
	.string " up to her mouth)\p"
	.string " (there's something about this girl\n"
    .string " that feels very welcoming, and sad\l"
    .string " at the same time. You're feeling some\p"
	.string " slight pressure in your chest...)$"

