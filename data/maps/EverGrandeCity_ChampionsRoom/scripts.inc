EverGrandeCity_ChampionsRoom_MapScripts:: @ 82289EF
	map_script ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script ON_FRAME, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition: @ 82289FF
	end

EGC_SetBrendan::
	setvar OBJ_EVENT_GFX_VAR_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

EGC_SetDawn::
	setvar OBJ_EVENT_GFX_VAR_0, OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL
	return

EverGrandeCity_ChampionsRoom_OnWarp: @ 8228A05
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth:: @ 8228A0F
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame: @ 8228A14
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom:: @ 8228A1E
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	applymovement OBJ_EVENT_ID_FOLLOWER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
    releaseall
    end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace: @ 8228A42
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace:: @ 8228A45
	playbgm MUS_DAIGO, 0
	msgbox EverGrandeCity_ChampionsRoom_Text_PreBattleSpeech, MSGBOX_DEFAULT
	setflag FLAG_RYU_DO_NOT_AUTOSCALE
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_AltWallaceFollower
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EGC_FollowerMinnieFlagSet::
	setflag FLAG_RYU_MINNIE_GAME_CLEAR
	return

EGC_AltWallaceFollower::
	call RyuFollowerAllySelector
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_TWIN
	call_if_eq EGC_FollowerMinnieFlagSet
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq EGC_CR_ChooseValidMons
	multi_2_vs_1 TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat, VAR_0x8006, VAR_0x8009
	waitstate
	special LoadPlayerParty
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	clearflag FLAG_RYU_DO_NOT_AUTOSCALE
	clearflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end
	
EGC_CR_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto EGC_AltWallaceFollower


EverGrandeCity_ChampionsRoom_EventScript_Defeated:: @ 8228A61
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, 0
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	compare VAR_RESULT, FEMALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic:: @ 8228ABC
	addobject 3
	playbgm MUS_GIRL_SUP, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic:: @ 8228AC1
	addobject 4
	playbgm MUS_BOY_SUP, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice:: @ 8228AC6
	msgbox EGC_DawnIntro, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EGC_DawnIntro2, MSGBOX_DEFAULT
	closemessage
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice:: @ 8228AFB
	msgbox EGC_NormalBrendanIntro, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF:: @ 8228B30
	closemessage
	addobject 2
	applymovement 2, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	goto_if_set FLAG_RYU_HAS_FOLLOWER, EGC_PlayerAndChampionExit
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement 1, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement OBJ_EVENT_ID_FOLLOWER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	applymovement 3, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	closemessage
	call_if_set FLAG_RYU_DS_BRENDAN_FRIENDS, EGC_BRENDANFZ_QUERY
	call_if_set FLAG_RYU_DS_DAWN_FRIENDS, EGC_DAWNFZ_QUERY
	closemessage
	goto EGC_PlayerAndChampionExit


EGC_PlayerAndChampionExit::
	call Ryu_CheckForPartnerReward
	applymovement 1, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	applymovement OBJ_EVENT_ID_FOLLOWER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 255, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations:: @ 8228BEB
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations:: @ 8228BF4
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer:: @ 8228BFD
	applymovement 3, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth:: @ 8228C12
	applymovement 3, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart: @ 8228C1D
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit: @ 8228C20
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer: @ 8228C26
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_fastest_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth: @ 8228C2F
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows: @ 8228C38
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart: @ 8228C3B
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit: @ 8228C3F
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives: @ 8228C43
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_fastest_left
	step_end

EGC_NormalBrendanIntro:
	.string "{PLAYER}! Some advice before you fight\nthe champion... He uses-$"
	
EGC_BrendanWantedToGoInHOF:
	.string "Aww, but I wanted to go in and see\nthe crowning ceremony!$"
	
EGC_BrendanAlreadyBeatChampion:
	.string "Wait, WHAT? You already won!\nImpressive! You didn't even\lneed me!$"

EverGrandeCity_ChampionsRoom_Text_PreBattleSpeech: @ 8228C4C
	.string "We Trainers raise Pokémon by giving\n"
	.string "them items and by teaching them new\l"
	.string "techniques for battle.\p"
	.string "But we ourselves also learn many\n"
	.string "things from Pokémon.\p"
	.string "And this is where your achievements\n"
	.string "are put to the test against what\l"
	.string "others like you have achieved.\p"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their Pokémon in Hoenn?\p"
	.string "Show me right here and now!$"

EverGrandeCity_ChampionsRoom_Text_Defeat: @ 8228EAC
	.string "I, the Champion, fall in defeat…\p"
	.string "That was wonderful work.\n"
	.string "You were elegant, infuriatingly so.\l"
	.string "And yet it was utterly glorious!\p"
	.string "Kudos to you, {PLAYER}!\p"
	.string "You are a truly noble Pokémon\n"
	.string "trainer!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech: @ 8228F66
	.string "Wallace: The Pokémon you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "It was with light, yet surefooted,\n"
	.string "elegance that you led your Pokémon.\p"
	.string "Even I felt bedazzled by your\n"
	.string "masterful performance!\p"
	.string "You now stand at the glorious peak\n"
	.string "of the Pokémon League.\p"
	.string "I now proclaim you to be the new\n"
	.string "Hoenn region…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice: @ 82290CA
	.string "Dawn: {PLAYER}!\p"
	.string "Here's some advice before you challenge\n"
	.string "the Champion…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver: @ 822910B
	.string "Dawn: Huh?\n"
	.string "What, what, what?\p"
	.string "{PLAYER}…\n"
	.string "Could it be that…\l"
	.string "It's already over?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice: @ 8229152
	.string "BRENDAN: {PLAYER}!\p"
	.string "How would you like some advice before\n"
	.string "you challenge the Champion?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon: @ 82291A2
	.string "BRENDAN: {PLAYER}…\p"
	.string "Are you trying to tell me…\n"
	.string "You've beaten the Champion?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex: @ 82291E6
	.string "Prof. Birch: See?\n"
	.string "What did I tell you, {RIVAL}?\p"
	.string "Didn't I tell you that you don't need\n"
	.string "to worry about {PLAYER}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}, you've finally done it.\p"
	.string "When I heard that you defeated your\n"
	.string "own father at the PETALBURG Gym,\l"
	.string "I thought perhaps you had a chance…\p"
	.string "But to think you've actually become\n"
	.string "the Champion!\p"
	.string "Ah, yes!\p"
	.string "What became of your Pokédex?\n"
	.string "Here, let me see.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations: @ 822934D
	.string "Prof. Birch: Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe: @ 8229399
	.string "Wallace: {PLAYER}…\p"
	.string "No, let me rephrase that properly.\p"
	.string "The new Champion!\p"
	.string "Come with me.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside: @ 82293EB
	.string "Wallace: I'm sorry, but…\p"
	.string "From here on, only those Trainers who\n"
	.string "have become ChampionS may enter.\p"
	.string "You'll have to wait outside with\n"
	.string "Prof. Birch.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations: @ 8229479
	.string "Dawn: Groan…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "I'm just joking! That's okay!\n"
	.string "That's the rule!\p"
	.string "{PLAYER}!\n"
	.string "Honestly, congratulations!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations: @ 82294F5
	.string "BRENDAN: Whaaaat?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "It can't be helped if that's the rule.\p"
	.string "{PLAYER}, way to go!\n"
	.string "Congratulations!$"


@==================================================================================================Relationship stuffs

EGC_DAWNREL_QUERY::
	nop
    msgbox EGC_DS_LoversToPartners MSGBOX_YESNO
    compare VAR_RESULT 1
	goto_if_eq EGC_DAWNREL_YES
	goto_if_ne EGC_DAWNREL_NO
	return

EGC_DAWNFZ_QUERY::
	goto_if_set FLAG_RYU_DS_DAWN_PARTNERS, EGC_MAXDSRANK_DAWN
	goto_if_set FLAG_RYU_DS_DAWN_LOVERS, EGC_DAWNREL_QUERY
	nop
    msgbox EGC_DAWN_QUERY, MSGBOX_YESNO
    compare VAR_RESULT 1
	goto_if_eq EGC_DAWNFZ_YES
	goto_if_ne EGC_DAWNFZ_NO
	return
	
EGC_BRENDANREL_QUERY::
    msgbox EGC_DS_LoversToPartnersFemalePlayer MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_eq EGC_BRENDANREL_YES
	goto_if_ne EGC_BRENDANREL_NO
	return
	
EGC_BRENDANFZ_QUERY::
	goto_if_set FLAG_RYU_DS_BRENDAN_PARTNERS, EGC_MAXDSRANK_BRENDAN
	goto_if_set FLAG_RYU_DS_BRENDAN_LOVERS, EGC_BRENDANREL_QUERY
    msgbox EGC_BRENDAN_QUERY, MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_eq EGC_BRENDANFZ_YES
	goto_if_ne EGC_BRENDANFZ_NO
	return

EGC_MAXDSRANK_BRENDAN::
	msgbox EGC_MAXDS_MALE_MSG
	closemessage
	return

EGC_MAXDS_MALE_MSG:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{RIVAL}: I'll see you outside!$"

EGC_MAXDSRANK_DAWN::
	msgbox EGC_MAXDS_FEMALE_MSG
	closemessage
	return

EGC_MAXDS_FEMALE_MSG:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{RIVAL}:I'll wait for you at the door!$"

EGC_DAWNREL_NO::
    msgbox EGC_DAWNREL_TEXT_NO
	return

EGC_DAWNREL_YES::
    applymovement OBJ_EVENT_ID_PLAYER egc_heart
	waitmovement 0
    msgbox EGC_DAWNREL_TEXT_YES
	setflag FLAG_RYU_DS_DAWN_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	applymovement 2 egc_heart
	waitmovement 0
	return
	
EGC_BRENDANREL_YES::
	applymovement OBJ_EVENT_ID_PLAYER egc_heart
	waitmovement 0
    msgbox EGC_BRENDANREL_TEXT_YES
	setflag FLAG_RYU_DS_BRENDAN_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	applymovement 2 egc_heart
	waitmovement 0
	return
	
EGC_BRENDANREL_NO::
	msgbox EGC_BRENDANREL_TEXT_NO
	return

EGC_DAWNFZ_YES::
    msgbox EGC_DAWNFZ_TEXT_YES MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_DAWN_FRIENDS
	clearflag FLAG_RYU_DS_DAWN_ACQ
	applymovement OBJ_EVENT_ID_PLAYER egc_heart
	applymovement 2 egc_heart
	return

EGC_DAWNFZ_NO::
    msgbox EGC_DAWNFZ_TEXT_NO MSGBOX_DEFAULT
	applymovement 2, EGC_DAWN_LEAVE
	waitmovement 0
	return
	
EGC_BRENDANFZ_YES::
    msgbox EGC_BRENDANFZ_TEXT_YES MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_BRENDAN_FRIENDS
	clearflag FLAG_RYU_DS_BRENDAN_ACQ
	applymovement OBJ_EVENT_ID_PLAYER egc_heart
	applymovement 2 egc_heart
	return

EGC_BRENDANFZ_NO::
    msgbox EGC_BRENDANFZ_TEXT_NO MSGBOX_DEFAULT
	applymovement 2, EGC_DAWN_LEAVE
	waitmovement 0
	return

EGC_DAWN_LEAVE:
    walk_fastest_down
    walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end

EGC_DAWN_SUPPORT:
    walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	step_end

egc_heart:
    emote_heart
	step_end

EGC_GoingToHallOfFame:: 
	msgbox EGC_DawnDeniedEntry, MSGBOX_DEFAULT
	goto_if_set FLAG_RYU_DS_DAWN_LOVERS, EGC_DAWNREL_QUERY
	goto_if_set FLAG_RYU_DS_DAWN_FRIENDS, EGC_DAWNFZ_QUERY
	setflag FLAG_RYU_DS_DAWN_FRIENDS
	return
	
EGC_GoingToHallOfFameFemale::
	msgbox EGC_BrendanDeniedEntry, MSGBOX_DEFAULT
	goto_if_set FLAG_RYU_DS_BRENDAN_LOVERS, EGC_BRENDANREL_QUERY
	goto_if_set FLAG_RYU_DS_BRENDAN_FRIENDS, EGC_BRENDANFZ_QUERY
	setflag FLAG_RYU_DS_BRENDAN_FRIENDS
	return
	
EGC_FaceLeft:
    face_left
	step_end
	
EGC_FaceRight:
	face_right
	step_end
	
EGC_FaceUp:
	face_up
	step_end
	
EGC_RivalGiftMsg::
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She kisses you on the cheek and\n"
	.string " gives you a warm smile.)$"

EGC_MaleRivalGiftMsg:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(He kisses you on the cheek and\n"
	.string " gives you a goofy grin.)$"
	
EGC_DAWN_QUERY:
    .string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} So, player, after you get done,\n"
	.string "would you like to ride home together?$"

EGC_DS_LoversToPartners:
    .string "{RIVAL}{COLOR LIGHT_RED}{SHADOW RED}: So, we're going home together\n"
	.string "after this, right? I've been preparing.$"
	
EGC_BRENDAN_QUERY:
    .string "{RIVAL}:{COLOR LIGHT_BLUE}{SHADOW BLUE} So, {PLAYER},\pI was thinking...\nwould you like to\lgo home together?$"

EGC_DS_LoversToPartnersFemalePlayer:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{RIVAL}: So, you wanna head home\nafter this? I've got something\lspecial for you.$"

EGC_DAWNREL_TEXT_NO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Okay, well, I'll be home if you\n"
	.string "want to visit!\p"
	.string "  {COLOR LIGHT_GREEN}{SHADOW GREEN}(she looks a little sad)$"

EGC_DAWNREL_TEXT_YES:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Okay! I'll wait for you outside!\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She gives you a loving glance\n"
	.string " and smiles gleefully)$"

EGC_DAWNFZ_TEXT_YES:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Oh, good! I was hoping you'd say that.\n"
	.string "I wasn't sure you would want to, since\l"
	.string "I embarassed myself in front of you\l"
	.string "earlier.$"

EGC_DAWNFZ_TEXT_NO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}... I'm sorry for asking... I'll just head\n"
	.string "home now, then...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You see a familiar look of hurt and sadness\l"
	.string " in her eyes)$"
	.string "Prof Birch: Now, now, {RIVAL}, there's plenty\n"
	.string "of other Trainers out there you can befriend.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The Prof. shoots you an angry look as {RIVAL}\n"
	.string " runs back out the door...)$"
	
EGC_BRENDANREL_TEXT_NO:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh, alright. Well I'll be home\nif you want to stop by!\l {COLOR LIGHT_GREEN}{SHADOW GREEN}(He looks a little sad.)$"

EGC_BRENDANREL_TEXT_YES:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Cool, I'll be right outside!\p {COLOR LIGHT_GREEN}{SHADOW GREEN}(He shows you the most genuine\nsmile, leaving with a pep in his\lstep.)$" 


EGC_BRENDANFZ_TEXT_YES:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh, great! I didn't know if\nyou would really want to\lsince..nevermind.$"


EGC_BRENDANFZ_TEXT_NO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}...Sorry about all this...I\n"
	.string "just wanted to...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(A familiar look of sadness and\n"
	.string "hurt is plastered on his face)\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Prof Birch: Come now, {RIVAL}, this isn't\n"
	.string "the end. There are plenty other\l"
	.string "trainers out there you can get\l"
	.string "to know.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The Prof. gives you the glare\n"
	.string " of a Seviper as {RIVAL} runs out…)$" 

	
EGC_DawnIntro: @ 82290CA
	.string " {PLAYER}!\p"
	.string "I'm here to cheer you on!\n"
	.string "Go {PLAYER}! Wait...$"

EGC_DawnIntro2: @ 822910B
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh! you didn't even need me\n"
	.string "to cheer you on. You're so strong,\l"
	.string "{PLAYER}. I'm so glad you made it!$"
	
EGC_DawnDeniedEntry: @ 8229479
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: Groan… I really wanted to be\p"
	.string "with {PLAYER} for his crowning.\n"
	.string "Well, {PLAYER}, I'm sorry I can't\l"
	.string "come with... Enjoy Your moment!$"
	
EGC_BrendanDeniedEntry:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Wha-… and I really\n"
	.string "wanted to be there for your big\l"
	.string "day… \p"
	.string "Can't be helped, I guess.\p"
	.string "Them's the rules, right?\n"
	.string "That's awesome, {PLAYER}, congratulations!$"
	
EGC_BirchIntro: @ 82291E6
	.string "Prof. Birch: {RIVAL}, you can't\n"
	.string "go in there while they're battling!\l"
	.string "It's very dangerous- oh it's already\l"
	.string "over.\n"
	.string "Well while I'm here, why don't I\n"
	.string "check your pokedex?$"


