LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GameIntroSequenceCheck
	.byte 0
	
GameIntroSequenceCheck::
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, GameIntroSequencePart1
	map_script_2 VAR_RYU_DS_LANA_STAGE, 75, LRT_LeafEvent
	map_script_2 VAR_TEMP_0, 0, LRT_CheckIfRemoveRival
	map_script_2 VAR_RYU_PARTNER_COUNT, 4, LRT_BeginHaremSequence
	.2byte 0
	
LRT_CheckIfRemoveRival::
	goto_if_set FLAG_TEMP_4, ryu_end
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LRT_RemoveMaleClone
	goto LRT_RemoveFemaleClone
	
LRT_RemoveMaleClone::
	removeobject 2
	setflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_TEMP_4
	setvar VAR_TEMP_0, 99
	release
	end
	
LRT_RemoveFemaleClone::
	removeobject 4
	setflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	setflag FLAG_TEMP_4
	setvar VAR_TEMP_0, 99
	release
	end
	
LRT_BrendanAfterLilycoveScene::
	lock
	faceplayer
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_eq LRT_BrendanIntroductionScene
	goto_if_set FLAG_RYU_DS_BRENDAN_LOVERS, LRT_BrendanNight2
	goto_if_set FLAG_RYU_DS_BRENDAN_CLOSEFRIENDS, LRT_BrendanNIGHT
	goto_if_set FLAG_RYU_DS_BRENDAN_FRIENDS, LRT_BrendanRelationshipScene1
	goto_if_set FLAG_RYU_DS_BRENDAN_ACQ, LRT_BrendanFZ
	release
	end
	
LRT_BrendanRelationshipScene1::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	drawheadshot HEAD_BRENDAN
	msgbox LRT_BRENDAN_SORRYKISSED, MSGBOX_DEFAULT
	removecutscenesprites
	msgbox LRT_BRENDAN_KISS, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LRT_BrendanWONT_HAPPEN
    setflag	FLAG_RYU_DS_BRENDAN_CLOSEFRIENDS
	drawheadshot HEAD_BRENDAN
	msgbox LRT_BrendanHAPPY, MSGBOX_DEFAULT
	goto LRT_BrendanNIGHT
	release
	end
	
	
LRT_BrendanIntroductionScene::
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 0
	drawheadshot HEAD_BRENDAN
	msgbox GI_BrendanIntro MSGBOX_DEFAULT
	applymovement 2, GI_MaleLeavingForRoute103
	waitmovement 0
	playse SE_DOOR
	removeobject 2
	setflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	removecutscenesprites
	msgbox GI_BrendanMetMsg
	setflag FLAG_RECEIVED_RUNNING_SHOES
	additem ITEM_GO_GOGGLES, 1
	setflag FLAG_RECEIVED_GO_GOGGLES
	setflag FLAG_SYS_NATIONAL_DEX
	setflag FLAG_RYU_LT_RIVAL
	setflag FLAG_RYU_LT_RIVAL2
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	special EnableNationalPokedex
	setvar VAR_LITTLEROOT_INTRO_STATE, 8
	setflag FLAG_RYU_MET_RIVAL_LITTLEROOT
	release
	end
	
GI_BrendanIntro:
	.string "{RIVAL}: {COLOR LIGHT_BLUE}{SHADOW BLUE} Hey! I was wondering when I'd\n get to meet you.\pHow are ya?\nAdjusting to life in Littleroot well?\p"
	.string "So, do you need me to get you a\npokemon so you can start training?\lI'd be happy to help the new girl!\p ... ... ... ... \pOh! Shoot! I forgot!\n"
	.string "My father, Prof. Birch was expecting me\l to have a field report of Route 103\nbefore sunset!\pI gotta run, sorry!$"
	
GI_BrendanMetMsg:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN} (He seems like the outgoing sort.\p Not too pushy, either.\n You can see yourself being good\l friends with him.)$"
	
GI_MaleLeavingForRoute103:
	emote_exclamation_mark
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end
	
EventScript_PlayerPCMale::
	lockall
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_DawnsHouse_2F_EventScript_1F956C
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_DawnsHouse_2F_EventScript_1F9576
	end
	
BH_DeskBook::
	msgbox LRT_BH_DeskBookMsg MSGBOX_DEFAULT
	closemessage
	end
	
LRT_BH_Gamecube::
	msgbox LRT_BH_GamecubeMsg MSGBOX_DEFAULT
	closemessage
	end
	
LRT_BH_GamecubeMsg:
	.string "It's a Gamecube. It's really dusty.$"

LRT_BH_DeskBookMsg:
	.string "It's an adventure guide.$"
	
	
	
@==================================================================================================@After Lilycove
	
LRT_BrendanWONT_HAPPEN::
	setflag FLAG_RYU_BRENDAN_GIFTPOKE_RECEIVED @Makes it impossible to get the snorunt after this event.
    msgbox LRT_BrendanSORRY, MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_BRENDAN_ACQ @0x4A3
	clearflag FLAG_RYU_DS_BRENDAN_FRIENDS
	clearflag FLAG_RYU_DS_BRENDAN_CLOSEFRIENDS
	msgbox LRT_BrendanBADEND, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER LRT_BrendanTURN
	waitmovement 0
	release
	end

LRT_BrendanNIGHT::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	call LRT_BH_CheckTraining
	removecutscenesprites
    msgbox LRT_BrendanSTAY, MSGBOX_YESNO
	drawheadshot HEAD_BRENDAN
	compare VAR_RESULT, 1
	goto_if_ne LRT_BrendanCANCEL
	msgbox LRT_BrendanROMPre MSGBOX_DEFAULT
 	closemessage
	applymovement 2, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	applymovement 2 LRT_BrendanHEART2
	applymovement OBJ_EVENT_ID_PLAYER LRT_BrendanHEART
	removecutscenesprites
	delay 20
	fadescreen 1
	fadeoutbgm 1
	special HealPlayerParty
	delay 20
	msgbox LRT_BrendanROM, MSGBOX_DEFAULT
	fadescreen 0
	fadeinbgm 1
	drawheadshot HEAD_BRENDAN
	msgbox LRT_BRENDAN_THANKS, MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_BRENDAN_LOVERS
	closemessage
	removecutscenesprites
	applymovement OBJ_EVENT_ID_PLAYER LRT_BrendanHEART3
	waitmovement 0
	release
	end

LRT_BrendanNight2::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	call LRT_BH_CheckTraining
    msgbox LRT_BrendanSTAY2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	drawheadshot HEAD_BRENDAN
	goto_if_ne LRT_BrendanCANCEL
	msgbox LRT_BrendanROM2Pre MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	applymovement 2, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 2
	applymovement 2, LRT_BrendanHEART2
	applymovement OBJ_EVENT_ID_PLAYER, LRT_BrendanHEART
	delay 20
	fadescreen 1
	fadeoutbgm 1
	special HealPlayerParty
	delay 20
	msgbox LRT_BrendanROM2, MSGBOX_DEFAULT
	fadescreen 0
	setflag FLAG_RYU_DS_BRENDAN_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	playse SE_PIN
	fadeinbgm 1
	drawheadshot HEAD_BRENDAN
	msgbox LRT_BRENDAN_THANKS2 MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	applymovement OBJ_EVENT_ID_PLAYER LRT_BrendanHEART3
	waitmovement 0
	release
	end

LRT_BrendanCANCEL::
    msgbox LRT_BrendanDISPT MSGBOX_DEFAULT
	removecutscenesprites
	release
	end

LRT_BrendanFZ::
    msgbox LRT_DS_FZ_Brendan MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsSnoruntInParty
	compare VAR_RESULT, TRUE
	call_if_eq LRT_BH_CheckTraining
	release
	end
	
LRT_BH_CheckTraining::
	goto_if_set FLAG_RYU_BRENDAN_GIFT2, LRT_BH_RcvGift2
	msgbox LRT_BH_PullItOut
	specialvar VAR_RESULT WhatStageIsGiftPoke
	switch VAR_RESULT
	case 0, ryu_end
	case 1, LRT_BH_Untrained
	case 2, LRT_BH_Glalie
	case 3, LRT_BH_Froslass
	release
	end
	
LRT_BH_RcvGift2::
	msgbox LRT_BH_HopeItsDoingWell
	return
	
LRT_BH_HopeItsDoingWell:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I hope you and my Pokémon are doing\n"
    .string "well together!$"

	
LRT_BH_Untrained::
	playmoncry SPECIES_SNORUNT, 0
	showmonpic SPECIES_SNORUNT, 10, 3
	msgbox LRT_BH_YouShouldTrain
	return
	
LRT_BH_Glalie::
	playmoncry SPECIES_GLALIE, 0
	showmonpic SPECIES_GLALIE, 10, 3
	msgbox LRT_BH_WastedPotential
	specialvar VAR_RESULT, DoesBrendanSnoruntHaveChampionRibbon
	compare VAR_RESULT, TRUE
	goto_if_eq LRT_BH_SnoruntIsChampionGlalie
	msgbox LRT_BH_Thanks1
	goto_if_set FLAG_RYU_BRENDAN_GIFT1, LRT_BH_RcvGift1
	msgbox LRT_BH_Vouchers
	additem ITEM_RETRO_MAIL, 4
	setflag FLAG_RYU_BRENDAN_GIFT1
	hidemonpic
	return
	
LRT_BH_RcvGift1::
	msgbox LRT_BH_GiftRcvMsg
	hidemonpic
	return
	
LRT_BH_GiftRcvMsg:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}It seems like it's doing well!\n"
    .string "Bring it back and show me if it\l"
    .string "accomplishes anything else!$"

	
LRT_BH_Froslass::
	playmoncry SPECIES_FROSLASS, 0
	showmonpic SPECIES_FROSLASS, 10, 3
	msgbox LRT_BH_BeautifulPokemon
	specialvar VAR_RESULT, DoesBrendanSnoruntHaveChampionRibbon
	compare VAR_RESULT, TRUE
	goto_if_eq LRT_BH_SnoruntIsChampionFroslass
	msgbox LRT_BH_Thanks1
	closemessage
	goto_if_set FLAG_RYU_BRENDAN_GIFT1, LRT_BH_RcvGift1
	msgbox LRT_BH_Vouchers
	additem ITEM_RETRO_MAIL, 4
	setflag FLAG_RYU_BRENDAN_GIFT1
	hidemonpic
	return
	
LRT_BH_SnoruntIsChampionGlalie::
	msgbox LRT_BH_GlalieChampionMsg
	closemessage
	additem ITEM_SCOPE_LENS
	hidemonpic
	clearflag FLAG_RYU_DS_BRENDAN_ACQ
	setflag FLAG_RYU_DS_BRENDAN_CLOSEFRIENDS
	setflag FLAG_RYU_BRENDAN_GIFT2
	return
	
LRT_BH_SnoruntIsChampionFroslass::
	msgbox LRT_BH_FroslassChampionMsg
	closemessage
	additem ITEM_LIFE_ORB
	hidemonpic
	clearflag FLAG_RYU_DS_BRENDAN_ACQ
	setflag FLAG_RYU_DS_BRENDAN_CLOSEFRIENDS
	setflag FLAG_RYU_BRENDAN_GIFT2
	return
	
LRT_BH_PullItOut:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}If you have Snorunt with you, pull\n"
    .string "it out. I wanna see how its doing!$"

LRT_BH_YouShouldTrain:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: You should train it more.\p"
    .string "It has a lot of untapped potential.$"
	
LRT_BH_Thanks1:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Well, thanks for showing it to me.\pIt's nice to see it once in a while!$"
	
LRT_BH_Vouchers:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Here, take some tutor vouchers.\n"
    .string "They will probably be useful to you!$"

LRT_BH_WastedPotential:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I see you evolved it into Glalie.\p"
    .string "That's cool, but it doesn't have\n"
    .string "a good nature for that. Thanks for\p"
    .string "taking care of my Pokémon, anyways\n"
    .string "It looks quite happy!$"

LRT_BH_BeautifulPokemon:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: Oh, you evolved it into\p"
    .string "Froslass! That's Awesome!\n"
    .string "It's a beautiful Pokémon, befitting\l"
    .string "a beautiful Pokémon trainer!$"	
	
LRT_BH_FroslassChampionMsg:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh wow, It has the champion ribbon too!\n"
    .string "I bet it worked real hard for you\l"
    .string "to get that!\p"
	.string "Here, take this. From me!\n"
	.string "When holding this item, the Pokémon\p"
	.string "will do a lot more damage if it\n"
	.string "really likes you!$"
	
LRT_BH_GlalieChampionMsg:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh wow, It has the champion ribbon too!\n"
    .string "I bet it worked real hard for you\l"
    .string "to get that!\p"
	.string "Here, take this. It'll make its\n"
	.string "critical hits REALLY hurt!$"

LRT_BrendanBADEND:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (Sadness and disappointment are\n evident on his face as you turn\l away.)$"

LRT_BRENDAN_KISS:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}The time I kissed you...\pIt was the heat of the moment and\n... ... ...\pDid it upset you?$"
	
LRT_BrendanDISPT:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(He looks a little deflated.)$"

LRT_BrendanROMPre:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Sorry, my bed might be a little small...$"
	
LRT_BrendanROM:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{RIVAL} and {PLAYER} cuddled together,\nenjoying a long night's rest.$"
	
LRT_BrendanROM2Pre:
	.string "Whenever I snuggle with you, it's\nlike all of my troubles just\lmelt away.\pI wish it could be like that\nall the time.$"

LRT_BrendanROM2:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and {RIVAL}{COLOR LIGHT_GREEN}{SHADOW GREEN} deviously cuddle\n"
	.string " together for another night.)$"

LRT_DS_FZ_Brendan:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Dawn: Oh, hi, {PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}. What are you\n"
	.string "up to today?$"

LRT_BrendanHAPPY:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: YE-I mean, whew, that's\na relief! I thought you'd hate me\lafter that.$"

LRT_BrendanSTAY:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Did you want to spend the night\nwith me, {PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}?$"

LRT_BrendanSTAY2:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: Did you want to join\nme for another night?$"

LRT_BrendanSORRY:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Yeah, I thought as much…\psorry about that, {PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}.\nI won't do it again.$"

LRT_BRENDAN_SORRYKISSED:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Dawn: {PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}!\p"
	.string "I'm sorry I kissed you.$"

LRT_BRENDAN_THANKS:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: That was great.\pI can't remember the last time\nI slept so good.\pThanks for that.$"

LRT_BRENDAN_THANKS2:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Thanks for staying with me for another\n"
	.string "night. You might get me addicted...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(He gives a wide, toothy grin.)$"
	
LRT_BrendanHEART:
	walk_down
	walk_right
	walk_down
	walk_left
	step_end

LRT_BrendanHEART2:
	walk_down
	walk_down
	walk_right
	step_end

LRT_BrendanHEART3:
	walk_right
	walk_right
	face_right
	delay_16
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

LRT_BrendanTURN:
    walk_right
	step_end
	
@========================================================Leaf Events
	
LRT_LeafEvent::
	lock
	setvar VAR_RYU_DS_LANA_STAGE, 76
	msgbox LRT_Story1 MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox LRT_Story2 MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	drawheadshot HEAD_LANA
	msgbox LRT_Story3 MSGBOX_DEFAULT
	closemessage
	msgbox LRT_PlayerKiss MSGBOX_DEFAULT
	applymovement 3, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	msgbox LRT_Story4 MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox LRT_Story5 MSGBOX_DEFAULT
	closemessage 
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 3
	msgbox LRT_Story6 MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	applymovement 3 Common_Movement_HeartEmote
	waitmovement 3
	msgbox LRT_Story6_5 MSGBOX_DEFAULT
	closemessage
	fadescreenspeed 1, 5
	removeobject 3
	setflag FLAG_RYU_HIDE_REL_OBJECTS
	delay 80
	fadenewbgm MUS_DUMMY
	fadescreenspeed 0, 5
	msgbox LRT_Story7 MSGBOX_DEFAULT
	closemessage
	fadenewbgm MUS_MISHIRO
	setvar VAR_RYU_DS_LANA_STAGE, 80
	setflag FLAG_RYU_HIDE_REL_OBJECTS
	setflag FLAG_RYU_DS_LEAF_LOVERS
	clearflag FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO
	release
	end
	
LRT_Story1:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Ugh...\nWhere...am I?$"
	
LRT_Story2:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Huh? How'd I...?$"

LRT_Story3:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Lana...you brought me here?\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}... ... ... ...\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}C'mon, say something. What\n"
	.string "happened back there?\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}I...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Seeing her struggling to speak,\n"
	.string " {PLAYER} places his hand on hers.)\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Please Lana, you can talk to me. I\n"
	.string "want to understand you.\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Still...? Even after everything\n"
	.string "I've done? Why...?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Simple...to me, you're no nobody.\p"
	.string "You're somebody special...you're\n"
	.string "Lana.\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh {PLAYER}...\p"
	.string "... ... ... ...!\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Tears begin to stream down Lana's\n"
	.string " face...)\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}All I wanted...was to find myself.\p"
	.string "To actually be someone...\p"
	.string "I was raised in Kanto...grew up\n"
	.string "alongside a boy the same age as\l"
	.string "me.\p"
	.string "We used to be close, until one day\n"
	.string "we just...fell apart...the one\l"
	.string "person I spoke to and liked the\p"
	.string "most...completely shunned me...\p"
	.string "When we set out on our journey,\n"
	.string "we would on occasion cross paths,\l"
	.string "sometimes battling each other.\p"
	.string "I thought it would be the perfect\n"
	.string "opportunity for me to make things\l"
	.string "right...but every battle I won, I\p"
	.string "would see hatred in his eyes...\p"
	.string "I couldn't believe it...the one\n"
	.string "who was most important to me...\p"
	.string "despised my very existence!\p"
	.string "I never felt such anger and hate!\p"
	.string "It plagued my mind, and I was\n"
	.string "unable to cope or comprehend it.\p"
	.string "I soon left Kanto altogether.\p"
	.string "Even after coming to Hoenn, I\n"
	.string "didn't want to make contact with\l"
	.string "anyone...so when Mom would force\p"
	.string "me to go and socialize, I went to\n"
	.string "a place where few people visited.\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}The Museum...where you and I met.\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}I didn't expect anyone to care\n"
	.string "about me...but you did.\p"
	.string "You kept searching for me...you\p"
	.string "never grew tired of me or thought\n"
	.string "that I was a nuisance. I was\l"
	.string "conflicted...the emotions I felt\p"
	.string "from you betrayed how I felt\n"
	.string "about myself...but I wanted it to\p"
	.string "continue... I- $"

LRT_PlayerKiss:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} kisses Lana.)$"


LRT_Story4:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Eh? {PLAYER}...wha-?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Silly...you do too much. It would\n"
	.string "have been so much easier if you\l"
	.string "just said that you liked me.\p"
	.string "Instead, you take this roundabout\n"
	.string "way...$"
	
LRT_Story5:
	.string "$"

LRT_Story6:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}So, you're ditching me already?\p"
	.string "Some girlfriend you are...\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}No...I'm being the thoughtful one\p"
	.string "for letting my partner rest\n"
	.string "after trying to play hero. It\p"
	.string "really did a number on you...but\n"
	.string "don't worry, pretty soon, it'll be\p"
	.string "my chance to do a number on you!\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Ooh...any chance that number is\n"
	.string "one less than 70?\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana's face immediately reddens\n"
	.string " at the remark.)\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}H-Hey now, don't push it, mister!\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Perish the thought...\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Uh huh...$"
	
LRT_Story6_5:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lana kisses {PLAYER} back.)\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Sleep well, {PLAYER}.\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Yeah, see you soon.$"

	
LRT_Story7:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}That's right! We still have to\n"
	.string "give our report in to the\p"
	.string "Trickmaster! But first...I think\n"
	.string "it's time to finish what was\p"
	.string "started...at the Ancient Tomb.$"
	
@Harem Stuff=======================================================================================

LRT_BeginHaremSequence::
	goto HaremBegin
	end
	
HaremBegin:
	lockall
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	addobject 4
	playse SE_DOOR
	waitse
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 4, LRT_Harem_RivalMove
	waitmovement 4
	msgbox LRT_HaremBeginRivalMsg
	closemessage
	clearflag FLAG_RYU_HIDE_HAREM_EVENT_NPCS
	fadescreen FADE_TO_BLACK
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq HaremBeginFemale
	clearflag FLAG_RYU_HIDE_HAREM_EVENT_DAWN
	warpsilent MAP_LITTLEROOT_TOWN, 255, 9, 8
	release
	end
	
HaremBeginFemale::
	clearflag FLAG_RYU_HIDE_HAREM_EVENT_BRENDAN
	warpsilent MAP_LITTLEROOT_TOWN, 255, 10, 8
	release
	end
	
	
LRT_HaremBeginRivalMsg:
	.string "{RIVAL}: HEY! come outside!\p"
	.string "I have a suprise for you!$"
	
LRT_Harem_RivalMove:
	walk_down
	walk_down
	emote_heart
	step_end





