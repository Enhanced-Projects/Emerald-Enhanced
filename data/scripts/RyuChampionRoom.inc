@====map_script ON_FRAME, RyuThroneRoomCheckFollower
	@.byte 0


RyuThroneRoomCheckFollower::
	map_script_2 VAR_TEMP_9, 0, RyuResetFollowerPosition
	.2byte 0

@Alternate champion room 

RyuChampionThrone::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, RCR_EnterThrone
	waitmovement EVENT_OBJ_ID_PLAYER
	specialvar VAR_RESULT, RyuFollowerToTrainerID
	compare VAR_RESULT, 1
	goto_if_ne RyuChampionThroneStart
	call RCR_FollowerIntroSetup
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	end

RCR_FollowerIntroSetup::
	switch VAR_RYU_FOLLOWER_ID
	case EVENT_OBJ_GFX_TWIN, RCR_FollowerMinnieIntro
	case EVENT_OBJ_GFX_AQUA_MEMBER_F, RCR_FollowerShellyIntro
	case EVENT_OBJ_GFX_WOMAN_2, RCR_FollowerLanetteIntro
	return


RyuChampionThroneStart::
	goto_if_unset FLAG_RYU_DS_HAS_PARTNER, RCR_SoloChamp
	msgbox RCR_PlayerPartnerQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RCR_SoloChamp
	call RyuParterBattleMultichoice
	switch VAR_0x8006
	case TRAINER_REL_MAY, RCR_Dawn
	case TRAINER_REL_SHELLY, RCR_Shelly
	case TRAINER_REL_BRENDAN, RCR_Brendan
	case TRAINER_REL_LANA, RCR_Lana
	case TRAINER_REL_LANETTE, RCR_Lanette
	
RCR_SoloChamp::
	closemessage
	call RCR_ChooseOpponent
	playse SE_DOOR
	addobject VAR_TEMP_5
	applymovement VAR_TEMP_5, RCR_ChallengerApproach
	waitmovement VAR_TEMP_5
	switch VAR_TEMP_5
	case 1, RCR_ChallengerStevenSolo
	case 2, RCR_ChallengerNormanSolo
	case 7, RCR_ChallengerJohnatanSolo
	case 8, RCR_ChallengerRobertSolo
	case 9, RCR_ChallengerLanceSolo
	case 10, RCR_ChallengerZodSolo
	case 11, RCR_ChallengerGiovanniSolo
	case 12, RCR_ChallengerSigmaSolo
	case 13, RCR_ChallengerJuanSolo

RCR_ChooseOpponent::
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, RCR_CameraMove
	waitmovement EVENT_OBJ_ID_CAMERA
	random 9
	switch VAR_RESULT
	case 0, RCR_Opponent1
	case 1, RCR_Opponent2
	case 2, RCR_Opponent3
	case 3, RCR_Opponent4
	case 4, RCR_Opponent5
	case 5, RCR_Opponent6
	case 6, RCR_Opponent7
	case 7, RCR_Opponent8
	case 8, RCR_Opponent9
	return
	
RCR_Opponent1::
	setvar VAR_TEMP_5, 1
	return
	
RCR_Opponent2::
	setvar VAR_TEMP_5, 2
	return
	
RCR_Opponent3::
	setvar VAR_TEMP_5, 7
	return
	
RCR_Opponent4::
	setvar VAR_TEMP_5, 8
	return	
	
RCR_Opponent5::
	setvar VAR_TEMP_5, 9
	return	
	
RCR_Opponent6::
	setvar VAR_TEMP_5, 10
	return	
	
RCR_Opponent7::
	setvar VAR_TEMP_5, 11
	return	
	
RCR_Opponent8::
	setvar VAR_TEMP_5, 12
	return	

RCR_Opponent9::
	setvar VAR_TEMP_5, 13
	return

RCR_Return::
	return

RCR_Dawn::
	closemessage
	addobject 3
	applymovement 3, RCR_PartnerToPlayer
	applymovement 3, Common_Movement_HeartEmote
	waitmovement 3
	drawheadshot HEAD_DAWN
	msgbox RCR_Dawn_Intromsg
	closemessage
	removecutscenesprites
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	
RCR_Shelly::
	closemessage
	addobject 6
	applymovement 6, RCR_PartnerToPlayer
	waitmovement 6
	applymovement 6, Common_Movement_HeartEmote
	waitmovement 6
	@drawheadshot HEAD_DAWN
	msgbox RCR_Shelly_Intromsg
	closemessage
	@removecutscenesprites
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	
RCR_Brendan::
	closemessage
	addobject 5
	applymovement 5, RCR_PartnerToPlayer
	waitmovement 5
	applymovement 5, Common_Movement_HeartEmote
	waitmovement 5
	drawheadshot HEAD_BRENDAN
	msgbox RCR_Brendan_Intromsg
	closemessage
	removecutscenesprites
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	
RCR_Lana::
	closemessage
	addobject 4
	applymovement 4, RCR_PartnerToPlayer
	waitmovement 4
	applymovement 4, Common_Movement_HeartEmote
	waitmovement 4
	drawheadshot HEAD_LANA
	msgbox RCR_Lana_Intromsg
	closemessage
	removecutscenesprites
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle

RCR_Lanette::
	closemessage
	addobject 14
	applymovement 14, RCR_PartnerToPlayer
	waitmovement 14
	applymovement 14, Common_Movement_HeartEmote
	waitmovement 14
	drawheadshot HEAD_LANETTE
	msgbox RCR_Lanette_Intromsg
	closemessage
	removecutscenesprites
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle

	
RCR_SetUpBattle::
	playse SE_DOOR
	addobject VAR_TEMP_5
	applymovement VAR_TEMP_5, RCR_ChallengerApproach
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	waitmovement VAR_TEMP_5
	switch VAR_TEMP_5
	case 1, RCR_ChallengerSteven
	case 2, RCR_ChallengerNorman
	case 7, RCR_ChallengerJohnatan
	case 8, RCR_ChallengerRobert
	case 9, RCR_ChallengerLance
	case 10, RCR_ChallengerZod
	case 11, RCR_ChallengerGiovanni
	case 12, RCR_ChallengerSigma
	case 13, RCR_ChallengerJuan
	
RCR_ChallengerSteven::
	msgbox RCR_Steven_Intro 
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_STEVEN, 0, NULL, RCR_Steven_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge
	
RCR_ChallengerNorman::
	msgbox RCR_Norman_Intro 
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_NORMAN_4, 0, NULL, RCR_Norman_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge
	
RCR_ChallengerJohnatan::
	msgbox RCR_Johnatan_Intro
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_CHALLENGER_JOHNATAN, 0, NULL, RCR_Johnatan_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge
	
RCR_ChallengerRobert::
	msgbox RCR_Robert_Intro
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_CHALLENGER_ROBERT, 0, NULL, RCR_Robert_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge
	
RCR_ChallengerLance::
	msgbox RCR_Lance_Intro
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_CHALLENGER_LANCE, 0, NULL, RCR_Lance_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge
	
RCR_ChallengerZod::
	msgbox RCR_Zod_Intro
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_CHALLENGER_ZOD, 0, NULL, RCR_Zod_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge
	
RCR_ChallengerGiovanni::
	msgbox RCR_Giovanni_Intro
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_CHALLENGER_GIOVANNI, 0, NULL, RCR_Giovanni_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge

RCR_ChallengerSigma::
	msgbox RCR_Sigma_Intro
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_CHALLENGER_SIGMA, 0, NULL, RCR_Sigma_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge

RCR_ChallengerJuan::
	msgbox RCR_Juan_Intro
	closemessage
	special SavePlayerParty
	trainerbattle 10 TRAINER_CHALLENGER_JUAN, 0, NULL, RCR_Juan_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	goto RCR_FinishChallenge

	
RCR_ChallengerStevenSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Steven_Intro
	closemessage
	trainerbattle_no_intro TRAINER_STEVEN, RCR_Steven_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerNormanSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Norman_Intro
	closemessage
	trainerbattle_no_intro TRAINER_NORMAN_4, RCR_Norman_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerJohnatanSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Johnatan_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_JOHNATAN, RCR_Johnatan_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerRobertSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Robert_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_ROBERT, RCR_Robert_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerLanceSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Lance_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_LANCE, RCR_Lance_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerZodSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Zod_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_ZOD, RCR_Zod_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerGiovanniSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Giovanni_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_GIOVANNI, RCR_Giovanni_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerSigmaSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Sigma_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_SIGMA, RCR_Sigma_DefeatText
	goto RCR_FinishChallenge

RCR_ChallengerJuanSolo::
	applymovement EVENT_OBJ_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement EVENT_OBJ_ID_CAMERA
	msgbox RCR_Juan_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_JUAN, RCR_Juan_DefeatText
	goto RCR_FinishChallenge
	
RCR_FinishChallenge::
	msgbox RCR_PlayerRecordingInfo
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, RCR_ToHOF
	applymovement EVENT_OBJ_ID_FOLLOWER, RCR_ToHOF
	waitmovement EVENT_OBJ_ID_PLAYER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 255, 7, 16
	end
@==================Movement

RCR_EnterThrone:
	walk_in_place_down
	emote_exclamation_mark
	step_end

RCR_CameraMove:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
RCR_ToHOF:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
RCR_ReturnToPlayer:
	delay_16
	delay_16
	delay_8
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
RCR_PartnerToPlayer:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_down
	step_end

RCR_ChallengerApproach:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_up
	step_end

RCR_FollowerMinnieIntro::
	applymovement EVENT_OBJ_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement EVENT_OBJ_ID_FOLLOWER
	msgbox FMinnieMsg
	closemessage
	return

RCR_FollowerShellyIntro::
	applymovement EVENT_OBJ_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement EVENT_OBJ_ID_FOLLOWER
	msgbox FShellyMsg
	closemessage
	return

RCR_FollowerLanetteIntro::
	applymovement EVENT_OBJ_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement EVENT_OBJ_ID_FOLLOWER
	msgbox FLanetteMsg
	closemessage
	return


@==================challenger Text
	
RCR_PlayerRecordingInfo:
	.string "{PLAYER}:{COLOR LIGHT_BLUE}{SHADOW BLUE} You have lost the match.\pI will now go put the data\ninto the system.\pPlease come challenge me again!$"

RCR_Steven_Intro:
    .string "Steven: Hi there, {PLAYER}!\p"
    .string "I thought I'd come up and see\n"
    .string "how the current champion is doing!\l"
    .string "I won't be pulling any punches!$"
	
RCR_Steven_DefeatText:
    .string "Ah. It would seem the potential I\n"
    .string "saw in you has been fully realized\l"
    .string "You win!$"
	
RCR_Norman_Intro:
    .string "Dad: I've come for our rematch!\p"
    .string "I can't let you be on top, I'm\n"
    .string "your father, You're supposed to be\l"
    .string "looking up to me!$"
	
RCR_Norman_DefeatText:
    .string "Unbelievable... Even now after all\n"
    .string "my training... I still can't beat\l"
    .string "{PLAYER}...$"
	
RCR_Johnatan_Intro:
	.string "Nice to meet you {PLAYER}.\nI will show you the might\lof Bug Pokemon.$"
	
RCR_Johnatan_DefeatText:
	.string "I should have done better…$"
	
RCR_Robert_Intro:
	.string "Hello, your emminence. I'm here to\n"
	.string "challenge you for the title of\l"
	.string "League Master.\p"
	.string "I use the power of the sun.\p"
	.string "Do you have UV Protection?$"
	
RCR_Robert_DefeatText:
    .string "Ah, you've taken to the shade.$"
	
RCR_Lance_Intro:
    .string "Greetings, {PLAYER}.\p"
    .string "I have come here all the way from\n"
    .string "the Kanto region to expand my\p"
    .string "dominance of the world. I've\n"
    .string "already been champion of Kanto and\l"
    .string "Johto.\p"
    .string "I will now also conquer the Hoenn\n"
    .string "League!$"

RCR_Lance_DefeatText:
    .string "Ah... Yes, I heard you were quite\n"
    .string "formidable... Till we meet again!$"
	
RCR_Zod_Intro:
    .string "zzz...\p"
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Zod Yawns)\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Let's get this over with...\n"
    .string "So sleepy...$"

RCR_Zod_DefeatText:
	.string "This is as I've foreseen...$"
	
RCR_Giovanni_Intro:
    .string "I was once a weak crime boss.\p"
	.string "In solitude, I've realized that\n"
	.string "strength doesn't rely on numbers\l"
	.string "alone.\p"
	.string "The bond between trainer and\n"
	.string "Pokemon, It's something I still\l"
	.string "don't fully understand.\p"
	.string "Perhaps you can teach me?\p"
	.string "If you don't give it your all,\n"
	.string "you'll be in a world of pain!$"

RCR_Giovanni_DefeatText:
    .string "So that's your full power... I'm\nimpressed. I hope we meet again,\l{PLAYER}.$"
	
RCR_Sigma_Intro:
	.string "Hello! I recently came from the\n"
	.string "Johto Region, and I am looking\p"
	.string "for some strong Trainers to battle!\p"
	.string "Hmm...you look tough!\n"
	.string "Can you show me your strength\l"
	.string "in battle?$" 
	
RCR_Sigma_DefeatText:
	.string "What strength!$"

RCR_Juan_Intro:
	.string "I'm here to avenge Wallace!$"
	
RCR_Juan_DefeatText:
	.string "Ahahaha, excellent!\n"
	.string "You truly are a remarkable trainer!$"
	
@========================================Partner Texts
RCR_Lana_Intromsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lana: Hi, {PLAYER}! I came to help\n"
    .string "you defend your title. You can\l"
    .string "count on me!$"
	
RCR_Brendan_Intromsg:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: I can't let you have all\n"
    .string "the fun, I want in on some super\l"
    .string "powered battles too!$"

RCR_Shelly_Intromsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Hey, babe. I'm here to\n"
    .string "support you. Let's smash some\l"
    .string "noobs!$"
	
RCR_Dawn_Intromsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: You know I got your back.\p"
    .string "And your front.\n"
    .string "And everything else.$"
	
RCR_Lanette_Intromsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lanette: I'm so happy you called.\p"
    .string "I was stuck on a certain bit of\n"
    .string "code that refused to work.\l"
	.string "This is just what I needed!$"
	
RCR_PlayerPartnerQuery:
	.string "{COLOR DARK_GREY}{SHADOW RED}Would you like to have one of your\npartners help you defend your title?$"

@============================================Follower Texts

FMinnieMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Minnie: {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, I'm not sure if\n"
    .string "I'm strong enough for this...\p"
    .string "B-but... I will try my hardest\n"
    .string "for you!$"

FShellyMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Man this journey has been\n"
    .string "refreshing. I got so tired of\p"
    .string "sitting at that desk.\n"
    .string "It's so nice to be able to stretch\l"
    .string "my legs again!$"

FLanetteMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lanette: I'm not much of a fighter\n"
    .string "but I'll follow you to the nine\p"
    .string "hells if you ask me to. I'll do\n"
    .string "what I can!$"
