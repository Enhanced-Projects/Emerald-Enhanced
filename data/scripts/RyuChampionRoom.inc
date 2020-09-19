@====map_script ON_FRAME, RyuThroneRoomCheckFollower
	@.byte 0


RyuThroneRoomCheckFollower::
	@map_script_2 VAR_TEMP_D, 0, RyuResetFollowerPosition
	.2byte 0

@Alternate champion room 

RyuChampionThrone::
	lock
	setflag FLAG_RYU_DO_NOT_AUTOSCALE
	applymovement OBJ_EVENT_ID_PLAYER, RCR_EnterThrone
	waitmovement OBJ_EVENT_ID_PLAYER
	specialvar VAR_RESULT, RyuFollowerToTrainerID
	compare VAR_RESULT, 1
	goto_if_ne RyuChampionThroneStart
	call RCR_FollowerIntroSetup
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	end

RCR_FollowerIntroSetup::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_FOLLOWER
	switch VAR_RYU_FOLLOWER_ID
	case OBJ_EVENT_GFX_TWIN, RCR_FollowerMinnieIntro
	case OBJ_EVENT_GFX_AQUA_MEMBER_F, RCR_FollowerShellyIntro
	case OBJ_EVENT_GFX_WOMAN_2, RCR_FollowerLanetteIntro
	case OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL, RCR_FollowerDawnIntro
	case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, RCR_FollowerBrendanIntro
	case OBJ_EVENT_GFX_LEAF, RCR_FollowerLeafIntro
	case OBJ_EVENT_GFX_MAGMA_MEMBER_F, RCR_FollowerCourtneyIntro
	case OBJ_EVENT_GFX_NURSE, RCR_FollowerJoyIntro
	return


RyuChampionThroneStart::
	goto_if_unset FLAG_RYU_DS_HAS_PARTNER, RCR_SoloChamp
	msgbox RCR_PlayerPartnerQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RCR_SoloChamp
	call RyuPartnerBattleMultichoice
	switch VAR_0x8008
	case TRAINER_REL_DAWN, RCR_Dawn
	case TRAINER_REL_SHELLY, RCR_Shelly
	case TRAINER_REL_BRENDAN, RCR_Brendan
	case TRAINER_REL_LANA, RCR_Lana
	case TRAINER_REL_LANETTE, RCR_Lanette
	case TRAINER_REL_COURTNEY_2, RCR_Courtney
	case TRAINER_REL_NURSE, RCR_Joy
	
RCR_SoloChamp::
	closemessage
	specialvar VAR_RESULT, checkForOverlordRyuEncounter
	switch VAR_RESULT
	case 1, RCR_OverlordRyuBossFight
	case 2, RCR_OverlordRyuRematch
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
	
RCR_OverlordRyuBossFight::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	playbgm MUS_REKKUU_KOURIN, 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_CAMERA
	addobject 15
	applymovement 15, RCR_ChallengerApproach
	waitmovement 15
	msgbox RCR_RYU_Intro
	closemessage
	setflag FLAG_RYU_MAX_SCALE
	clearflag FLAG_RYU_DO_NOT_AUTOSCALE
	trainerbattle_no_intro TRAINER_OVERLORD_RYU, RCR_RYU_DefeatText
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	clearflag FLAG_RYU_MAX_SCALE
	call_if_unset FLAG_RYU_DEFEATED_OVERLORD, MawileMegaReward
	goto RCR_OverlordRyuEndMatch

RCR_OverlordRyuRematch::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	playbgm MUS_REKKUU_KOURIN, 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_CAMERA
	addobject 15
	applymovement 15, RCR_ChallengerApproach
	waitmovement 15
	msgbox RCR_RYU_Intro
	closemessage
	setflag FLAG_TEMP_3
	setflag FLAG_RYU_MAX_SCALE
	clearflag FLAG_RYU_DO_NOT_AUTOSCALE
	trainerbattle_no_intro TRAINER_OVERLORD_RYU_REMATCH, RCR_RYU_DefeatText
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	clearflag FLAG_RYU_MAX_SCALE
	call_if_unset FLAG_RYU_DEFEATED_OVERLORD, MawileMegaReward
	goto RCR_OverlordRyuEndMatch
	
RCR_OverlordRyuEndMatch::
	clearflag FLAG_RYU_WAYSTONE_DISABLED
    goto AT1_Warp
	end


RCR_ChooseOpponent::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, RCR_CameraMove
	waitmovement OBJ_EVENT_ID_CAMERA
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
	msgbox RCR_Dawn_Intromsg
	closemessage
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	
RCR_Shelly::
	closemessage
	addobject 6
	applymovement 6, RCR_PartnerToPlayer
	waitmovement 6
	applymovement 6, Common_Movement_HeartEmote
	waitmovement 6
	@msgbox RCR_Shelly_Intromsg
	closemessage
	@call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	
RCR_Brendan::
	closemessage
	addobject 5
	applymovement 5, RCR_PartnerToPlayer
	waitmovement 5
	applymovement 5, Common_Movement_HeartEmote
	waitmovement 5
	msgbox RCR_Brendan_Intromsg
	closemessage
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle
	
RCR_Lana::
	closemessage
	addobject 4
	applymovement 4, RCR_PartnerToPlayer
	waitmovement 4
	applymovement 4, Common_Movement_HeartEmote
	waitmovement 4
	msgbox RCR_Lana_Intromsg
	closemessage
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle

RCR_Lanette::
	closemessage
	addobject 14
	applymovement 14, RCR_PartnerToPlayer
	waitmovement 14
	applymovement 14, Common_Movement_HeartEmote
	waitmovement 14
	msgbox RCR_Lanette_Intromsg
	closemessage
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle

RCR_Courtney::
	closemessage
	addobject 17
	applymovement 17, RCR_PartnerToPlayer
	waitmovement 17
	applymovement 17, Common_Movement_HeartEmote
	waitmovement 17
	msgbox RCR_Courtney_Intromsg
	closemessage
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle

RCR_Joy::
	closemessage
	addobject 18
	applymovement 18, RCR_PartnerToPlayer
	waitmovement 18
	applymovement 18, Common_Movement_HeartEmote
	waitmovement 18
	msgbox RCR_Joy_Intromsg
	closemessage
	call RCR_ChooseOpponent
	goto RCR_SetUpBattle

	
RCR_SetUpBattle::
	playse SE_DOOR
	addobject VAR_TEMP_5
	applymovement VAR_TEMP_5, RCR_ChallengerApproach
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
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

RCR_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	return
	
RCR_ChallengerSteven::
	msgbox RCR_Steven_Intro 
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_STEVEN, RCR_Steven_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge

RCR_ChallengerStevenAggroniteReward::
	msgbox RCR_StevenExplainAggronite
	additem ITEM_AGGRONITE
	setflag FLAG_CHALLENGER_STEVEN_AGGRONITE
	closemessage
	return

RCR_StevenExplainAggronite:
	.string "Steven: Nice work, {PLAYER}!\pI have a gift for you, it should\nbe good for you!\pIt's an Aggronite. Enjoy!$"
	
RCR_ChallengerNorman::
	msgbox RCR_Norman_Intro 
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_NORMAN, RCR_Norman_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge
	
RCR_ChallengerJohnatan::
	msgbox RCR_Johnatan_Intro
	closemessage
	special SavePlayerParty
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_JOHNATAN, RCR_Johnatan_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge
	
RCR_ChallengerRobert::
	msgbox RCR_Robert_Intro
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_ROBERT, RCR_Robert_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge
	
RCR_ChallengerLance::
	msgbox RCR_Lance_Intro
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_LANCE, RCR_Lance_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge
	
RCR_ChallengerZod::
	msgbox RCR_Zod_Intro
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_ZOD, RCR_Zod_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge
	
RCR_ChallengerGiovanni::
	msgbox RCR_Giovanni_Intro
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_GIOVANNI, RCR_Giovanni_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge

RCR_ChallengerSigma::
	msgbox RCR_Sigma_Intro
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_SIGMA, RCR_Sigma_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge

RCR_ChallengerJuan::
	msgbox RCR_Juan_Intro
	closemessage
	choose_mons
	compare VAR_RESULT, FALSE
	call_if_eq RCR_ChooseValidMons
	multi_2_vs_1 TRAINER_CHALLENGER_JUAN, RCR_Juan_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EGC_RYU_PLAYER_LOST
	goto RCR_FinishChallenge
	
RCR_ChallengerStevenSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Steven_Intro
	closemessage
	trainerbattle_no_intro TRAINER_STEVEN, RCR_Steven_DefeatText
	setflag FLAG_TEMP_B
	goto RCR_FinishChallenge
	
RCR_ChallengerNormanSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Norman_Intro
	closemessage
	trainerbattle_no_intro TRAINER_NORMAN_4, RCR_Norman_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerJohnatanSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Johnatan_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_JOHNATAN, RCR_Johnatan_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerRobertSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Robert_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_ROBERT, RCR_Robert_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerLanceSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Lance_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_LANCE, RCR_Lance_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerZodSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Zod_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_ZOD, RCR_Zod_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerGiovanniSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Giovanni_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_GIOVANNI, RCR_Giovanni_DefeatText
	goto RCR_FinishChallenge
	
RCR_ChallengerSigmaSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Sigma_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_SIGMA, RCR_Sigma_DefeatText
	goto RCR_FinishChallenge

RCR_ChallengerJuanSolo::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox RCR_Juan_Intro
	closemessage
	trainerbattle_no_intro TRAINER_CHALLENGER_JUAN, RCR_Juan_DefeatText
	goto RCR_FinishChallenge

RCR_BOSSMODE::
	applymovement OBJ_EVENT_ID_CAMERA, RCR_ReturnToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	goto RCR_FinishChallenge

MawileMegaReward::
	msgbox RyuGivesMawilite
	additem ITEM_MAWILITE
	setflag FLAG_RYU_DEFEATED_OVERLORD
	return
	
RCR_CheckStevenGift::
	call_if_unset FLAG_CHALLENGER_STEVEN_AGGRONITE, RCR_ChallengerStevenAggroniteReward
	return
	
RCR_FinishChallenge::
	msgbox RCR_PlayerRecordingInfo
	call_if_set FLAG_TEMP_B, RCR_CheckStevenGift
	addvar VAR_RYU_TITLE_DEFENSE_WINS, 1
	closemessage
	clearflag FLAG_RYU_DO_NOT_AUTOSCALE
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	call Ryu_CheckForPartnerReward
	applymovement OBJ_EVENT_ID_PLAYER, RCR_ToHOF
	applymovement OBJ_EVENT_ID_FOLLOWER, RCR_ToHOF
	waitmovement OBJ_EVENT_ID_PLAYER
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 255, 7, 16
	end

EGC_RYU_PLAYER_LOST::
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	playse SE_DOOR
	fadescreenspeed FADE_TO_BLACK, 12
	addobject 16
	setobjectxy 16, 10, 8
	applymovement 16, Common_Movement_FaceLeft
	waitmovement 16
	delay 10
	fadescreen FADE_FROM_BLACK
	applymovement 16, NurseTriage
	waitmovement 16
	delay 12
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	clearflag FLAG_RYU_MAX_SCALE
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	clearflag FLAG_RYU_DO_NOT_AUTOSCALE
	msgbox EGC_PlayerLostMsg
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq AT1_AltTeleport
	delay 5
	special RyuWarp
	release
	end

NurseTriage:
	walk_in_place_left
	walk_in_place_up
	walk_in_place_left
	emote_exclamation_mark
	step_end

EGC_PlayerLostMsg:
	.string " (The last thing you see is the\n nurse rushing to your aid before\l passing out...$"



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
	msgbox FMinnieMsg
	closemessage
	return

RCR_FollowerShellyIntro::
	msgbox FShellyMsg
	closemessage
	return

RCR_FollowerLanetteIntro::
	msgbox FLanetteMsg
	closemessage
	return

RCR_FollowerDawnIntro::
	msgbox FDawnMsg
	closemessage
	return

RCR_FollowerBrendanIntro::
	msgbox FBrendanMsg
	closemessage
	return

RCR_FollowerLeafIntro::
	msgbox FLeafMsg
	closemessage
	return

RCR_FollowerCourtneyIntro::
	msgbox FCourtneyMsg
	closemessage
	playmoncry SPECIES_MIGHTYENA, 0
	waitmoncry
	return

RCR_FollowerJoyIntro::
	msgbox FJoyMsg
	closemessage
	return


@==================challenger Text

RCR_RYU_Intro:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Ryu: I'd say your chances of winning\nare about one in 8192.\lTime for you to learn your place!$"

RyuGivesMawilite:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Ryu: Nice! I was cheating and\n"
	.string "you still won!\p"
	.string "Congratulations on beating the final\n"
	.string "boss of Emerald Enhanced.\p"
	.string "Here, take this mega stone, it's\n"
	.string "for my favorite pokemon!$"

RCR_RYU_DefeatText:
	.string "Even with my devhax...$"

RCR_PlayerRecordingInfo:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE} You have lost the match.\pI will now go put the data\ninto the system.\pPlease come challenge me again!$"

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
    .string "{COLOR LIGHT_RED}{SHADOW RED}Brendan: I can't let you have all\n"
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

RCR_Courtney_Intromsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'm glad you called. No Really...\n"
    .string "I was about to come find you again!\p"
    .string "But since I'm here, Let's hurt some\n"
    .string "people!$"

RCR_Joy_Intromsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Normally, I stand by just in case\n"
    .string "someone needs healing, but\p"
    .string "actually being in the battle\n"
    .string "is a differnet thing entirely!$"

RCR_PlayerPartnerQuery:
	.string "{COLOR DARK_GREY}{SHADOW RED}Would you like to have one of your\npartners help you defend your title?$"

@============================================Follower Texts

FMinnieMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, I'm not sure if\n"
    .string "I'm strong enough for this...\p"
    .string "B-but... I will try my hardest\n"
    .string "for you!$"

FShellyMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Man this journey has been\n"
    .string "refreshing. I got so tired of\p"
    .string "sitting at that desk.\n"
    .string "It's so nice to be able to stretch\l"
    .string "my legs again!$"

FLanetteMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I'm not much of a fighter\n"
    .string "but I'll follow you to the nine\p"
    .string "hells if you ask me to. I'll do\n"
    .string "what I can!$"

FDawnMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}It's been a long walk, but I'm\n"
    .string "glad that I can be here with you.\p"
    .string "It's so surreal, being here in the\n"
    .string "Hoenn Champion room...\p"
    .string "Well... Let'S GO!!$"

FBrendanMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Not gonna lie, I expected\n"
    .string "to get here before you, maybe after\p"
    .string "you, but I never thought we'd be\n"
    .string "doing this together. Here we go!$"

FLeafMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Oh, Wow, this room is HUGE!\n"
    .string "The Kanto one doesn't even compare.\p"
    .string "Well, I've already beaten the Kanto\n"
    .string "Champion, time to add Hoenn to my\l"
    .string "repertoire!$"

FCourtneyMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}You know, I didn't fancy mself a\n"
    .string "voyeur... But hurting people in\p"
    .string "such a public way really excites me.\p"
    .string "My pupper is hungry!$"

FJoyMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh, you brought me all the way to\n"
	.string "the Championship... I'm not really\p"
	.string "cut out for this, but I'm here\n"
	.string "to support you any way I can!$"



