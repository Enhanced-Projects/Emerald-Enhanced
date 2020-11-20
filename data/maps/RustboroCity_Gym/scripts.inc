RustboroCity_Gym_MapScripts:: @ 8212F30
	.byte 0

RustboroCity_Gym_EventScript_Roxanne:: @ 8212F31
	lock
	faceplayer
	setflag FLAG_RYU_BOSS_SCALE
	special checkbadgecount
    switch VAR_RESULT
	case 0, ROXANNE1
	case 1, ROXANNE1
	case 2, ROXANNE1
	case 3, ROXANNE2
	case 4, ROXANNE2
	case 5, ROXANNE3
	case 6, ROXANNE3
	case 7, ROXANNE4
	case 8, ROXANNE4
	end

RG_Reset::
	setvar VAR_TEMP_8, 1
	special checkbadgecount
	compare VAR_RESULT, 8
	call_if_eq RyuTier8GymMegaStoneReward
	cleartrainerflag TRAINER_ROXANNE_1
	cleartrainerflag TRAINER_ROXANNE_2
	cleartrainerflag TRAINER_ROXANNE_3
	cleartrainerflag TRAINER_ROXANNE_4
	clearflag FLAG_RYU_BOSS_SCALE
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	msgbox RustboroCity_Gym_Text_RoxannePostBattle
	closemessage
	goto_if_set FLAG_RYU_HARDCORE_MODE, RyuScripts_HardcoreGymReward
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuHealedGym
	call_if_unset FLAG_RYU_GYM1HANDOUT, RyuGymItemReward1
	release
	end

ROXANNE1::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreBattle, RustboroCity_Gym_Text_RoxanneDefeat, RG_Reset
	release
	end

ROXANNE2::
	trainerbattle_single TRAINER_ROXANNE_2, RustboroCity_Gym_Text_RoxannePreBattle, RustboroCity_Gym_Text_RoxanneDefeat, RG_Reset
	release
	end

ROXANNE3::
	trainerbattle_single TRAINER_ROXANNE_3, RustboroCity_Gym_Text_RoxannePreBattle, RustboroCity_Gym_Text_RoxanneDefeat, RG_Reset
	release
	end

ROXANNE4::
	goto_if_set FLAG_RYU_HAS_FOLLOWER, RG_FollowerMatch
	call_if_set FLAG_RYU_DS_HAS_PARTNER, RG_PartnerQuery
	trainerbattle_single TRAINER_ROXANNE_4, RustboroCity_Gym_Text_RoxannePreBattle, RustboroCity_Gym_Text_RoxanneDefeat, RG_Reset
	release
	end
	
RG_PartnerQuery::
    msgbox RyuPartnerMultiText MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RG_RelDialog
	goto RG_NoRelGymBattle
	return
	
	
RG_RelDialog::
	call RyuPartnerBattleMultichoice
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq RG_GymBattleIntroShelly
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq RG_GymBattleIntroDawn
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq RG_GymBattleIntroBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq RG_GymBattleIntroLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq RG_GymBattleIntroLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq RG_GymBattleIntroCourtney
	compare VAR_0x8008, TRAINER_REL_NURSE
	goto_if_eq RG_GymBattleIntroJoy
	goto RG_NoRelGymBattle
	
RG_NoRelGymBattle::
	trainerbattle_single TRAINER_ROXANNE_4, RustboroCity_Gym_Text_RoxannePreBattle, RustboroCity_Gym_Text_RoxanneDefeat, RG_Reset
	release
	end

RG_FollowerMatch::
	msgbox RustboroCity_Gym_Text_RoxannePreBattle
	closemessage
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq RG_ChooseValidMons
	multi_2_vs_1 TRAINER_ROXANNE_4, RustboroCity_Gym_Text_RoxanneDefeat, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto RG_Reset
	end

RG_NoRelationship1::
	msgbox Ryu_NOREL MSGBOX_DEFAULT
	closemessage
	goto RG_RelDialog
	
RG_GymBattleIntroShelly::
	msgbox Ryu_PlayerCalledShelly MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, RG_NoRelationship1
	addobject 7
	playse SE_DOOR
	applymovement 7, RG_PartnerEnter
	waitmovement 0
	msgbox RG_SHELLY_INTRO MSGBOX_DEFAULT
	goto RG_AltGymBattle
	
RG_GymBattleIntroDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, RG_NoRelationship1
	msgbox Ryu_PlayerCalledDawn MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 6
	playse SE_DOOR
	applymovement 6, RG_PartnerEnter
	waitmovement 0
	msgbox RG_DAWN_INTRO MSGBOX_DEFAULT
	goto RG_AltGymBattle
	
RG_GymBattleIntroBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, RG_NoRelationship1
	msgbox Ryu_PlayerCalledBrendan MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 8
	playse SE_DOOR
	applymovement 8, RG_PartnerEnter
	waitmovement 0
	msgbox RG_BRENDAN_INTRO MSGBOX_DEFAULT
	goto RG_AltGymBattle
	
RG_GymBattleIntroLana::
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, RG_NoRelationship1
	msgbox Ryu_PlayerCalledLana MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 9
	playse SE_DOOR
	applymovement 9, RG_PartnerEnter
	waitmovement 9
	msgbox RG_LANA_INTRO MSGBOX_DEFAULT
	goto RG_AltGymBattle
	
RG_GymBattleIntroLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, RG_NoRelationship1
	msgbox Ryu_PlayerCalledLanette MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 10
	playse SE_DOOR
	applymovement 10, RG_PartnerEnter
	waitmovement 10
	msgbox RG_LANETTE_INTRO MSGBOX_DEFAULT
	goto RG_AltGymBattle

RG_GymBattleIntroCourtney::
	goto_if_unset FLAG_RYU_DS_COURTNEY_PARTNERS, RG_NoRelationship1
	msgbox Ryu_PlayerCalledCourtney MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 11
	playse SE_DOOR
	applymovement 11, RG_PartnerEnter
	waitmovement 0
	msgbox RG_COURTNEY_INTRO MSGBOX_DEFAULT
	goto RG_AltGymBattle

RG_GymBattleIntroJoy::
	goto_if_unset FLAG_RYU_DS_JOY_PARTNERS, RG_NoRelationship1
	msgbox Ryu_PlayerCalledJoy MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 12
	playse SE_DOOR
	applymovement 12, RG_PartnerEnter
	waitmovement 0
	msgbox RG_JOY_INTRO MSGBOX_DEFAULT
	goto RG_AltGymBattle
	
RG_AltGymBattle::
	msgbox RG_PreBattleText MSGBOX_DEFAULT
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq LG_ChooseValidMons
	multi_2_vs_1 TRAINER_ROXANNE_4, RG_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	delay 10
	goto RG_GymBattleEnd
	
RG_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto_if_set FLAG_RYU_HAS_FOLLOWER, RG_FollowerMatch
	goto RG_AltGymBattle
	
RG_GymBattleEnd::
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq RG_GymBattleEndDawn
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq RG_GymBattleEndShelly
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq RG_GymBattleEndBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq RG_GymBattleEndLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq RG_GymBattleEndLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq RG_GymBattleEndCourtney
	release
	end
	
RG_GymBattleEndShelly::
	msgbox RG_ShellyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 7, RG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 7
	goto RG_Reset
	release
	end
	
RG_GymBattleEndDawn::
	msgbox RG_DawnGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 6, RG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 6
	goto RG_Reset
	release
	end
	
RG_GymBattleEndBrendan::
	msgbox RG_BrendanGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 8, RG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 8
	goto RG_Reset
	release
	end
	
RG_GymBattleEndLana::
	msgbox RG_LanaGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 9, RG_PartnerExit
	waitmovement 9
	playse SE_DOOR
	removeobject 9
	goto RG_Reset
	release
	end
	
RG_GymBattleEndLanette::
	msgbox RG_LanetteGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 10, RG_PartnerExit
	waitmovement 10
	playse SE_DOOR
	removeobject 10
	goto RG_Reset
	release
	end

RG_GymBattleEndCourtney::
	msgbox RG_CourtneyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 11, RG_PartnerExit
	waitmovement 11
	playse SE_DOOR
	removeobject 11
	goto RG_Reset
	release
	end

RG_GymBattleEndJoy::
	msgbox RG_JoyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 12, RG_PartnerExit
	waitmovement 12
	playse SE_DOOR
	removeobject 12
	goto RG_Reset
	release
	end
	
RG_SHELLY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hey, {PLAYER}, I'm glad you\ngot me out of the office for a while.\pLets show her our combined power!$"
	
RG_DAWN_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}! I flew in as soon as you called!\pLet's Show her how much we've\lgrown!!$"
	
RG_LANA_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I love smashing rocks.\n"
    .string "It's practically therapeutic!$"
	
RG_BRENDAN_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}! I flew in as soon as you called!\pLet's pound some novices!$"
	
RG_LANETTE_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I'm... not very good\n"
    .string "against rock types... But I love a\l"
    .string "challenge!$"

RG_COURTNEY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}An excellent opportunity for Mightyena\nto sharpen his teeth.$"

RG_JOY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED} Oh, dear, everything's pointy\nhere. It's dangerous!$"
	
RG_DefeatText:
	.string "Roxanne: Maybe I should have\nrecorded that for the students...$"
	
RG_ShellyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Right, well that was fun.\pI'm headed back to the office\nCall me if you want my help again!$"
	
RG_DawnGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I feel a little bad for this...\nOh well, It was fun.\lHave a nice day!$"
	
RG_BrendanGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Yeah, that's right,\nwe're unstoppable!\pSee you later, {PLAYER}$"
	
RG_LanaGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I feel much better now.\n"
    .string "I might go smash some more rocks\l"
    .string "around Hoenn just for fun!$"
	
RG_LanetteGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}That was pretty tough.\n"
    .string "You saved me again, {PLAYER}!$"

RG_CourtneyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Not exactly optimal, but not really\nproblematic either.$"

RG_JoyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED} I hope your Pokémon are okay...$"

RG_PreBattleText:
    .string "Roxanne: Nice to see you guys back.\n"
    .string "I can tell you've grown...\p"
    .string "Allow me to test your progress!$"

	
RG_PartnerEnter:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_up
	step_end

RG_PartnerExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

RustboroCity_Gym_EventScript_RoxanneDefeated:: @ 8212F66
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb:: @ 8212FA4
	additem ITEM_TM39
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch:: @ 8212FC8
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh:: @ 8212FE3
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshPreBattle, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy:: @ 8212FFA
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyPreBattle, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc:: @ 8213011
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcPreBattle, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide:: @ 8213028
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory:: @ 821303D
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue:: @ 8213047
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue:: @ 8213057
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified:: @ 8213067
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue:: @ 8213071
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne:: @ 821307B
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice: @ 821309D
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the Champion?\p"
	.string "I'm no Trainer, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "Pokémon Championship together!\p"
	.string "It's your job as a Trainer to collect\n"
	.string "Gym Badges, am I right?\p"
	.string "But Gym Leaders aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "Roxanne, the Gym Leader, is a user\n"
	.string "of ROCK-type Pokémon.\p"
	.string "The Rock type is very durable, but\n"
	.string "it can't stand WATER-type and\l"
	.string "GRASS-type moves.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the Gym Leader.\p"
	.string "Well, go for it!$"

RustboroCity_Gym_Text_GymGuidePostVictory: @ 82132E2
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "Check your Trainer Card.\p"
	.string "The Stone badge you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the Championship!\p"
	.string "That's got to feel awesome!$"

RustboroCity_Gym_Text_JoshPreBattle: @ 82133E9
	.string "Don't take us Gym Trainers lightly!\n"
	.string "I'll show you why we're better!$"

RustboroCity_Gym_Text_JoshDefeat: @ 821342D
	.string "You were too good for me…$"

RustboroCity_Gym_Text_JoshPostBattle: @ 8213447
	.string "You haven't seen anything of the Rock\n"
	.string "type's terrifying power!$"

RustboroCity_Gym_Text_TommyPreBattle: @ 8213486
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against Roxanne!$"

RustboroCity_Gym_Text_TommyDefeat: @ 82134C6
	.string "Wow! You've got some potential!$"

RustboroCity_Gym_Text_TommyPostBattle: @ 82134E6
	.string "Roxanne is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"

RustboroCity_Gym_Text_MarcPreBattle: @ 8213533
	.string "We might be in the middle of town,\n"
	.string "but so what?\p"
	.string "My Rock Pokémon need room to\n"
	.string "rampage!$"

RustboroCity_Gym_Text_MarcDefeat: @ 8213589
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"

RustboroCity_Gym_Text_MarcPostBattle: @ 82135C0
	.string "I have to hand it to our Leader.\p"
	.string "It took smarts and sense for her to\n"
	.string "pick the Rock type at her young age.$"

RustboroCity_Gym_Text_RoxannePreBattle: @ 821362A
	.string "Hello, I am Roxanne, the Rustboro\n"
	.string "Pokémon Gym Leader.\p"
	.string "I became a Gym Leader so that I might\n"
	.string "apply what I learned at the Pokémon\l"
	.string "Trainer's School in battle.\p"
	.string "Would you kindly demonstrate how you\n"
	.string "battle, and with which Pokémon?$"

RustboroCity_Gym_Text_RoxanneDefeat: @ 821370B
	.string "So…\n"
	.string "I lost…\p"
	.string "It seems that I still have much more\n"
	.string "to learn…\p"
	.string "I understand...$"

RustboroCity_Gym_Text_ReceivedStoneBadge: @ 82137EC
	.string "{PLAYER} received the STONE badge\n"
	.string "from Roxanne.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis: @ 8213816
	.string "The Stone badge heightens the Attack\n"
	.string "power of your Pokémon.\p"
	.string "It also enables them to use the HM move\n"
	.string "Cut outside of battle.\p"
	.string "Please take this with you, too.$"

RustboroCity_Gym_Text_ExplainRockTomb: @ 82138B1
	.string "That Technical Machine, TM39,\n"
	.string "contains Rock Tomb.\p"
	.string "It not only inflicts damage by dropping\n"
	.string "rocks, it also lowers Speed.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a Pokémon.\p"
	.string "Remember, a TM can be used only once,\n"
	.string "so think before you use it.$"

RustboroCity_Gym_Text_RoxannePostBattle: @ 82139A7
	.string "Since you are so strong, you should\n"
	.string "challenge other Gym Leaders.\p"
	.string "By battling many Trainers, you should\n"
	.string "learn many things.$"

RustboroCity_Gym_Text_GymStatue: @ 8213A21
	.string "Rustboro City Pokémon Gym$"

RustboroCity_Gym_Text_GymStatueCertified: @ 8213A3B
	.string "Rustboro City Pokémon Gym\p"
	.string "Roxanne's Certified Trainers:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall: @ 8213A76
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Roxanne: Oh, hello, {PLAYER}?\n"
	.string "This is Roxanne of Rustboro City.\p"
	.string "I heard from Brawly that you're\n"
	.string "moving up through the ranks of\l"
	.string "Trainers at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my Gym\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne: @ 8213C01
	.string "Registered Gym Leader Roxanne\n"
	.string "in the Pokénav.$"

RustboroCity_Gym_Text_RoxannePreRematch: @ 8213C2F
	.string "Roxanne: I'm so glad to see you again.\n"
	.string "I'm Roxanne, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat: @ 8213CF9
	.string "Grr…\n"
	.string "Again, I have lost…$"

RustboroCity_Gym_Text_RoxannePostRematch: @ 8213D12
	.string "Roxanne: I still have much to learn\n"
	.string "when it comes to battling Pokémon.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons: @ 8213D93
	.string "Roxanne: I'm so glad to see you again.\n"
	.string "I'm Roxanne, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one Pokémon with you?\p"
	.string "Please return with at least one more\n"
	.string "Pokémon.$"
