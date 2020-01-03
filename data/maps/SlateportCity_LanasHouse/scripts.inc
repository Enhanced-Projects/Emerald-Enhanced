SlateportCity_LanasHouse_MapScripts::
	.byte 0

LeafHouse_brother::
	lock
	msgbox LH_bro_chat MSGBOX_NPC
	release
	end
	
LH_AltLeafStoryTrigger::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	setflag FLAG_DEFEATED_REGICE
	setflag FLAG_DEFEATED_REGISTEEL
	setflag FLAG_DEFEATED_REGIROCK

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
	drawheadshot HEAD_LANA
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
	removecutscenesprites
	release
	end

LH_Afterstory::
	goto_if_set FLAG_RECEIVED_MYSTIC_TICKET, LH_StayTheNight
	msgbox LH_Lana_MysticTicketGift
	closemessage
	giveitem_std ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	msgbox LH_GIFT_GIVEN
	removecutscenesprites
	release
	end
	
LH_alreadytalked::
	goto_if_set FLAG_SYS_GAME_CLEAR, LH_EventStart
	msgbox LH_finished MSGBOX_SIGN
	closemessage
	removecutscenesprites
	applymovement 2, LH_read
	waitmovement 0
	release
	end
	
LH_EventStart::
	call_if_set FLAG_RYU_PLAYER_HELPING_AQUA, LH_AquaMember
	msgbox LH_BeginQuest MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	applymovement EVENT_OBJ_ID_PLAYER, LH_PlayerShoved
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
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
	msgbox LH_Dispt MSGBOX_DEFAULT
	release
	end
	
LH_LeafNight:
	msgbox LH_LeafNightMsg1 MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LH_PlayerToBed
	applymovement 2, LH_LeafToBed
	waitmovement 2
	fadenewbgm MUS_DUMMY
	fadescreen 1
	msgbox LH_LeafNightSceneMsg MSGBOX_DEFAULT
	delay 40
	closemessage
	fadedefaultbgm
	fadescreen 0
	drawheadshot HEAD_LANA
	msgbox LH_LeafNightSceneMsg2 MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	applymovement EVENT_OBJ_ID_PLAYER, LH_RelSceneEnd
	waitmovement EVENT_OBJ_ID_PLAYER
	release
	end
	
LH_NightQuery:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Hey, {PLAYER}. Did you...want to\n"
  	.string "spend the night?$"

LH_Dispt:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She looks a little disappointed.)$"

LH_LeafNightMsg1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hehe, I knew you couldn't resist.$"

LH_LeafNightSceneMsg:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana and {PLAYER} blissfully\n"
    .string " enjoyed their time together in\p"
    .string " each other's loving embrace as\n"
    .string " they rested for the night.)$"


LH_LeafNightSceneMsg2:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lana: That was wonderful...I never\n"
    .string "thought I'd experience something\l"
    .string "like this...thank you, {PLAYER}.$"

LH_LeafBadEndMsgAqua:
    .string " (She sees the Aqua emblem on your\n"
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
	step_end
	
LH_read:
	face_right
	step_end
	
LH_Step:
	walk_in_place_up
	step_end
	
LH_BeginQuest:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: Hm? What is it?\p  {COLOR LIGHT_GREEN}{SHADOW GREEN}(She points to your pokénav.)\p{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh, you want it? Here.\p{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ...\n"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She takes it only for a moment\p before handing it back to you.)$"

LH_QuestStarted:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Hey, wait!\p{COLOR DARK_GREY}{SHADOW GREEN} Hmm...this mark on the map...\n it seems to be the house just\l north of town. Is that where she's\l headed?$"

	
LH_Bro_intro:
	.string "I think my sister {COLOR LIGHT_RED}{SHADOW RED}Lana{COLOR DARK_GREY}{SHADOW LIGHT_GREY} is waiting\n"
	.string "for you in her room. Just a fair\p"
	.string "warning... she hasn't talked in\n"
	.string "a long time.$"
	
LH_bro_chat:
	.string "Our family recently moved here\n"
	.string "from Kanto. Our parents are out\p"
	.string "working most of the time, so it's\n"
	.string "just me and {COLOR LIGHT_RED}{SHADOW RED}Lana{COLOR DARK_GREY}{SHADOW LIGHT_GREY} here, usually.$"
	
LH_finished:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana looks up and smiles\n"
	.string " at you, then resumes reading.)$"
	
LH_End:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}({COLOR LIGHT_RED}{SHADOW RED}Lana{COLOR LIGHT_GREEN}{SHADOW GREEN} sits down and starts\n"
	.string " reading a magazine with a rare\p"
	.string " pokémon on the cover. Guess\n"
	.string " she's done talking.)$"
	
LH_chat1:
	.string "{PLAYER}:{COLOR LIGHT_BLUE}{SHADOW BLUE} Umm... hi. I'm {PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}.\n"
	.string "Is your name... Lana?\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She nods.)\n"
	.string "{COLOR LIGHT_RED}{SHADOW RED}... ... ... \p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Well... I took care of that goon for\n"
	.string "you. She was tough for an Aqua\p"
	.string "soldier.\n"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana smiles. She seems to be\p"
	.string "  thinking about something.)\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} Lana leans towards you.$"
	
LH_chat2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lana: Thanks.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She leans back and puts a finger\n"
	.string " on your mouth, signifying you to\p"
	.string " not tell anyone she spoke. You\n"
	.string " feel some slight pressure in your\p"
	.string " chest. You're starting to like this\n"
	.string " girl)$"
