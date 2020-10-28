MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	.byte 0
	
MF_SetStage::
	setvar VAR_TEMP_A, 20
	goto_if_set FLAG_MET_ARCHIE_METEOR_FALLS, ryu_end
	goto_if_set FLAG_RYU_PLAYER_HELPING_DEVON, MF_SS_Devon
	goto_if_set FLAG_RYU_DEVON_M1C, ryu_end
	compare VAR_RYU_AQUA, 60 @Player should be doing meteor falls now
	goto_if_eq MF_SetAquaStage
	release
	end

MF_SetAquaStage::
	clearflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	clearflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	end
	
MF_SS_Devon::
	lock
	goto_if_set FLAG_MET_ARCHIE_METEOR_FALLS, ryu_end
	clearflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	clearflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setvar VAR_METEOR_FALLS_STATE, 2
	special DrawWholeMapView
	release
	end
	
MF_Event1start::
	setvar VAR_TEMP_A, 20
	setvar VAR_TEMP_B, 20
	setvar VAR_TEMP_8, 1
	compare VAR_RYU_AQUA, 60
	goto_if_eq MF_StartAqua
	goto MF_MainEvent
	
MF_Event2start::
	setvar VAR_TEMP_A, 10
	setvar VAR_TEMP_B, 10
	compare VAR_RYU_AQUA, 60
	goto_if_eq MF_StartAqua
	setvar VAR_TEMP_8, 2
	goto MF_MainEvent
	
MF_MainEvent::
	goto_if_set FLAG_RYU_PLAYER_HELPING_DEVON, MF_DevonEventNorth
	release
	end

	
MH_cameraPanDown:
	walk_diag_southwest
	walk_diag_southwest
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
MH_CamerPanUp:
	walk_diag_northeast
	walk_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
MH_PlayerDownIntoScene:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

	
MF_DevonEventNorth::
    compare VAR_TEMP_8, 1
	goto_if_eq MF_DevonEventSouth
	special SpawnCameraObject
	playbgm MUS_MGM0, 0
	delay 20
	applymovement OBJ_EVENT_ID_CAMERA, MH_cameraPanDown
	delay 30
    applymovement 5, MF_Magma2Down
	applymovement 6, MF_Magma1Down
	msgbox MF_MagmaMsg2 MSGBOX_DEFAULT
	closemessage
	playbgm MUS_GOTOWN, 0
	msgbox MF_PlayerStepsIn MSGBOX_DEFAULT
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MH_PlayerDownIntoScene
	applymovement 5, Common_Movement_FaceUp
	applymovement 6, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	special RemoveCameraObject
	msgbox MF_PlayerAttacksMagma MSGBOX_DEFAULT
	cleartrainerflag TRAINER_GRUNT_16
	savebgm MUS_GOTOWN
	trainerbattle_single TRAINER_GRUNT_16, MF_MagmaFightIntro, MF_ellipsis, MF_DevonContd
	
MF_DevonEventSouth::
	playbgm MUS_MGM0, 0
    applymovement 5, MF_Magma2Down
	applymovement 6, MF_Magma1Down
	msgbox MF_MagmaMsg2 MSGBOX_DEFAULT
	closemessage
	playbgm MUS_GOTOWN, 0
	msgbox MF_PlayerStepsIn MSGBOX_DEFAULT
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 5
	msgbox MF_PlayerAttacksMagma MSGBOX_DEFAULT
	cleartrainerflag TRAINER_GRUNT_16
	savebgm MUS_GOTOWN
	trainerbattle_single TRAINER_GRUNT_16, MF_MagmaFightIntro, MF_ellipsis, MF_DevonContd
	
MF_DevonContd::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	bufferpartymonnick 0, 0
	msgbox MF_PlayerWonVsMagma MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_8, 1
	goto_if_eq MF_continue_magma_south
	goto MF_continue_magma_north

MH_camera2Move:
	walk_fast_up
	walk_fast_up
	step_end
	
MF_continue_magma_south:
	applymovement 5, MF_MagmaEscape
	applymovement 6, MF_MagmaEscape2
	waitmovement 6
	removeobject 6
	removeobject 5
	playbgm MUS_AQA_0, 0
	applymovement 8, MF_AquaRight @(6 right)
	applymovement 7, MF_AquaRight
	goto MF_continue_devon_south
	
MF_continue_magma_north:
	applymovement OBJ_EVENT_ID_PLAYER, MF_PlayerStepLeft
	waitmovement 0
	applymovement 5, MF_MagmaEscape
	applymovement 6, MF_MagmaEscape2
	waitmovement 6
	removeobject 6
	removeobject 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MH_camera2Move
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	delay 20
	playbgm MUS_AQA_0, 0
	applymovement 8, MF_AquaRight @(6 right)
	applymovement 7, MF_AquaRight
	goto MF_continue_devon_north
	
MF_continue_devon_south::
	applymovement 7, MF_ArchieMeetPlayerSouth
	waitmovement 7
	applymovement 7, Common_Movement_FaceDown
	waitmovement 7
	msgbox MF_Archie2 MSGBOX_DEFAULT
	msgbox MF_ArchieWarned MSGBOX_DEFAULT
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 8
	closemessage
	applymovement 8, MF_GruntToPlayerSouth
	waitmovement 0
	cleartrainerflag TRAINER_GRUNT_15
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	trainerbattle_single TRAINER_GRUNT_15, MF_GruntAttacks, MF_ellipsis, MF_PlayerDevonContdSouth
	release
	end
	
MF_continue_devon_north::
	applymovement 7, MF_ArchieMeetPlayerNorth
	waitmovement 7
	msgbox MF_ArchieWarned MSGBOX_DEFAULT
	closemessage
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 8
	applymovement 8, MF_GruntToPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	cleartrainerflag TRAINER_GRUNT_15
	savebgm MUS_GOTOWN
	trainerbattle_single TRAINER_GRUNT_15, MF_GruntAttacks, MF_ellipsis, MF_PlayerDevonContdNorth
	release
	end
	
MF_PlayerDevonContdNorth::
	msgbox MF_GruntLost MSGBOX_DEFAULT
	closemessage
	applymovement 8, MF_AquaLeavesNorth
	applymovement 7, MF_ArchieLeavesNorth
	waitmovement 7
	removeobject 8
	removeobject 7
	setflag FLAG_RYU_DEVON_M1C
	clearflag FLAG_RYU_DEVON_MISSION1START
	setvar VAR_METEOR_FALLS_STATE, 1
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	applymovement 9, MF_CozmoToPlayerNorth
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_FaceRight
	msgbox MF_DM1_Cozmo MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	savebgm MUS_DAN03
	applymovement 9, MF_CozmoLeavesNorth
	waitmovement 9
	removeobject 9
	fadedefaultbgm
	release
	end
	
MF_PlayerDevonContdSouth::
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MF_GruntLost MSGBOX_DEFAULT
	closemessage
	applymovement 8, MF_AquaLeavesSouth
	applymovement 7, MF_ArchieLeavesSouth
	waitmovement 7
	removeobject 8
	removeobject 7
	setflag FLAG_RYU_DEVON_M1C
	clearflag FLAG_RYU_DEVON_MISSION1START
	setvar VAR_METEOR_FALLS_STATE, 1
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	applymovement 9, MF_CozmoToPlayerSouth
	waitmovement 9
	msgbox MF_DM1_Cozmo MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DAN03
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	applymovement 9, MF_CozmoLeavesSouth
	waitmovement 9
	removeobject 9
	fadedefaultbgm
	release
	end

MeteorFalls_1F_1R_EventScript_22BF25:: @ 822BF25
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COSMO, MeteorFalls_1F_1R_EventScript_22BF3D
	setflag FLAG_MET_PROF_COSMO
	msgbox MF_AquaCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_22BF3D:: @ 822BF3D
	msgbox MF_AfterEventCozmo MSGBOX_DEFAULT
	release
	end	
	
MF_Magma2Down:
	walk_down
	walk_down
	step_end
	
MF_Magma1Down:
	walk_down
	step_end
	
MF_AquaRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MF_MagmaBackUp:
	walk_right
	walk_in_place_left
	step_end
	
MF_FaceOther:
	walk_in_place_right
	delay_16
	delay_8
	walk_in_place_left
	step_end
	
MF_FaceOther2:
	walk_in_place_left
	delay_16
	delay_8
	walk_in_place_right
	step_end
	
MF_MagmaEscape:
	delay_16
	delay_16
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end
	
MF_MagmaEscape2:
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end
	
MF_ArchieMeetPlayerSouth:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end
	
MF_ArchieLeavesSouth:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MF_AquaLeaves:
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
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
	walk_fast_right
	step_end

MF_ArchieMeetPlayerNorth:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end
	
MF_ArchieLeavesNorth:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

MF_PlayerStepLeft:
	walk_left
	walk_in_place_right
	step_end

MF_GruntToPlayerSouth:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_in_place_down
	step_end
	
MF_GruntToPlayerNorth:
	walk_right
	walk_in_place_down
	step_end
	
MF_AquaLeavesNorth:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MF_AquaLeavesSouth:
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MF_CozmoToPlayerNorth:
	walk_up
	walk_up
	walk_left
	step_end
	
MF_CozmoLeavesNorth:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MF_CozmoToPlayerSouth:
	walk_left
	walk_in_place_down
	step_end
	
MF_CozmoLeavesSouth:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MF_MagmaMsg2:
    .string "Magma Grunt: Thanks for the rock,\n"
    .string "old man. This will help us compl-\l"
    .string "ete our goals for Hoenn. Now\p"
    .string "I've got to silence you. Can't have\n"
    .string "you blabbing to everyone now, can\l"
    .string "we!$"
	
MF_PlayerStepsIn:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE} HOLD IT!$"
	
MF_PlayerAttacksMagma:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}What the hell do you think you're\n"
    .string "doing? You degenerates should\p"
    .string "at least have the decency to treat\n"
    .string "your elders better than this.\p"
    .string "I am going to grind you both into\n"
    .string "a fine powder and sprinkle you on\l"
    .string "your Leader's grave.$"
	
MF_MagmaFightIntro:
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Magma Grunt: I'll use my Leader's\n"
    .string "most generously lent, extremely\l"
    .string "powerful pokémon to crush you!$"

MF_PlayerWonVsMagma:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE} I should have known you\n"
    .string "wouldn't put on much of a fight.\p"
    .string "You avoid people your own size\n"
    .string "because you Know you will get\p"
    .string "destroyed. Get out of here before\n"
    .string "I have my {STR_VAR_1} turn you\l"
    .string "into a fine red mist.\p"
    .string "... ... ...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Magma Grunt: I can't believe it...\n"
    .string "The Leader's prized Charizard...\p"
    .string "Okay! You win! We'll be leaving\l"
    .string "now!$"
	
MF_Archie2:
	.string "Archie: Well, {PLAYER}, I see you\p"
    .string "made it here before us, and\n"
    .string "interfered with our plans again.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE} Yes, Well they were\n"
    .string "picking on this nice gentleman\p"
    .string "over here. If you have the same\n"
    .string "intent, I will cream you like I\l"
    .string "did those Magma twats.$"
	
MF_ellipsis:
	.string "...$"
	
MF_GruntLost:
	.string "Grunt: Sorry, boss...\pArchie: You useless knave.\nYour pay will be docked.\pAs for you, {PLAYER}, I will\nfind a way to make you suffer...$"

MF_ArchieWarned: 
	.string "{PLAYER}, Didn't I warn you not to \ninterfere with us again? Maybe it\lis time I teach you a lesson.\p... ... ... ... ... ...\pYou there, Grunt, Take out this\nannoying trainer.$"
	
MF_GruntAttacks:
	.string "Grunt: Sorry, I got to\nwipe you out.\pIt's nothing personal. Just busi-\nness. Here we go!$"

	
MF_AquaGruntWarnsChaseMagma:
    .string "Grunt: Boss, We really need to\n"
    .string "give chase. We need to know what\l"
    .string "they are up to at Mt. Chimney!\p"
	.string "Archie: Yes, indeed, let's go.$"

	
MF_MagmaMsg1:
    .string "Magma Grunt: Thanks for the meteor,\n"
    .string "professor. We'll have to silence\p"
    .string "you now, though. We can't have\n"
    .string "anyone knowing our plans, can we?$"

MF_Archie1:
    .string "Archie: Not so fast, Magma Scum!\p"
    .string "Resorting to picking on gullible\n"
    .string "old men now, are we?$"
	
MF_MagmaRetreat:
    .string "Magma Grunt: What?! How did you\n"
    .string "know we were here? Who tipped you\p"
    .string "off?\n"
    .string "Archie: No one, it was easy to\l"
    .string "predict your movements, you swine!$"

MF_MagmaRetreat1:
    .string "Magma Grunt: Hmph, it's too much\n"
    .string "work to deal with you now. We'll\l"
    .string "be on our way...$"
	
MF_ArchieRecognizesPlayer:
	.string "Archie: Wait... I know you...$"
	
PlayerisAqua:
	.string "If you could direct your attention at\n"
	.string "Magma, that'd be great. We need\p" 
	.string "all the help we can get to wipe out\n"
	.string "those fanatics. I have my own\p" 
	.string "dreams to realize, and they're going\n"
	.string "to ruin it completely.$"
	
MF_ArchiKnowsPlayer:
	.string "Oh you're the new recruit that\n"
	.string "Shelly hired in. She's been saying\p"
	.string "great things about you, I hope you\n"
	.string "can live up to my expectations,\p"
	.string "at the very least.$"

	
MF_PlayerAqua2:
	.string "Archie: {PLAYER}, I'm glad you're with us.\n"
	.string "We've got to give chase.\p" 
	.string "Shelly sees promise in you, so I'll trust\n"
    .string	"her judgement.\p"
	.string "Report back to Shelly. We're done here.\p"
	.string "Waves be with you, {PLAYER}!$"

MF_AquaCozmo:
    .string "Cozmo: Those goons took my prized\n"
    .string "meteorite... How am I to finish my\l"
    .string "research now?$"
	
MF_AfterEventCozmo:
    .string "Cozmo: Where am I going to find\n"
    .string "another meteorite? ... ... ...$"
	
MF_DM1_Cozmo:
    .string "Cozmo: Wow, you really showed them\p"
    .string "what for. Unfortunately they still\n"
    .string "got away with my Meteorite.\p"
    .string "Thanks anyways, though. There's no\n"
    .string "telling what they would have done\p"
    .string "to me if you weren't here.\n"
    .string "You've made a couple of powerful\l"
    .string "enemies, haven't you?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE} Yeah, but they're really\n"
    .string "weak, so I'm not particularly\l"
    .string "concerned.\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Cozmo: Well anyways, meet me at my\n"
    .string "house in Fallarbor. I'll have a\l"
    .string "reward for you there.$"

@==================================================================================================Aqua

MF_StartAqua::
	setvar VAR_RYU_AQUA, 65 @start Meteor Falls Event
	playbgm MUS_MGM0, 0
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	compare VAR_TEMP_4, 18
	goto_if_gt MF_AquaSouth
	goto MF_AquaNorth

MF_AquaSouth::
    applymovement 5, MF_Magma2Down
	applymovement 6, MF_Magma1Down
	msgbox MF_ThanksForMeteor
	closemessage
	addobject 7
	addobject 8
	applymovement 8, MF_AquaToCozmo
	applymovement 7, MF_AquaToCozmo
	waitmovement 7
	msgbox MF_NotSoFast
	closemessage
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 6
	msgbox MF_ResortingTo
	closemessage
	applymovement 5, Common_Movement_FaceRight
	waitmovement 5
	msgbox MF_TheLeaderOf
	closemessage
	applymovement 5, Common_Movement_FaceDown
	waitmovement 5
	msgbox MF_AndWithThis
	closemessage
	applymovement 6, Common_Movement_FaceLeft
	waitmovement 6
	msgbox MF_TimeToMake
	closemessage
	applymovement 5, MF_MagmaEscape
	applymovement 6, MF_MagmaEscape2
	waitmovement 6
	removeobject 5
	removeobject 6
	goto MF_AquaSouthContd

MF_AquaSouthContd::
	applymovement 7, MF_ArchieToPlayer
	waitmovement 7
	msgbox MF_WhoMightYouBe
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MF_HahaIJest
	closemessage
	applymovement 8, MF_MattToPlayer
	waitmovement 8
	msgbox MF_BossWeReally
	closemessage
	applymovement 7, Common_Movement_FaceLeft
	waitmovement 7
	msgbox MF_YoureRight
	closemessage
	applymovement 7, Common_Movement_FaceDown
	msgbox MF_HowAboutIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MF_PlayerChoseNoRomance
	msgbox MF_OkayLetsGo
	closemessage
	applymovement 7, MF_ArchieLeavesNorthAqua
	applymovement 8, MF_MattLeavesNorth
	waitmovement 8
	removeobject 7
	removeobject 8
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	setvar VAR_RYU_AQUA, 70 @Player is doing the romance line for aqua. Go to Mt Chihmney.
	release
	end
	
MF_AquaNorth: @This is basically a copy of the event above, but it was a logistical nightmare to make everything dynamic, so... :shrug:
	special SpawnCameraObject
	playbgm MUS_AQA_0
	delay 20
	applymovement OBJ_EVENT_ID_CAMERA, MH_cameraPanDown
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 30
	special RemoveCameraObject
    applymovement 5, MF_Magma2Down
	applymovement 6, MF_Magma1Down
	msgbox MF_ThanksForMeteor
	closemessage
	addobject 7
	addobject 8
	applymovement 8, MF_AquaToCozmo
	applymovement 7, MF_AquaToCozmo
	waitmovement 7
	msgbox MF_NotSoFast
	closemessage
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 6
	msgbox MF_ResortingTo
	closemessage
	applymovement 5, Common_Movement_FaceRight
	waitmovement 5
	msgbox MF_TheLeaderOf
	closemessage
	goto AquaNorthContd

AquaNorthContd::
	applymovement 5, Common_Movement_FaceDown
	waitmovement 5
	msgbox MF_AndWithThis
	closemessage
	applymovement 6, Common_Movement_FaceLeft
	waitmovement 6
	msgbox MF_TimeToMake
	closemessage
	applymovement 5, MF_MagmaEscapeNorth
	applymovement 6, MF_MagmaEscape2North
	waitmovement 6
	applymovement 7, MF_ArchieToPlayerNorth
	waitmovement 7
	msgbox MF_WhoMightYouBe
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MF_HahaIJest
	closemessage
	applymovement 8, MF_MattToPlayerNorth
	waitmovement 8
	msgbox MF_BossWeReally
	closemessage
	applymovement 7, Common_Movement_FaceLeft
	waitmovement 7
	msgbox MF_YoureRight
	closemessage
	applymovement 7, Common_Movement_FaceUp
	waitmovement 7
	msgbox MF_HowAboutIt, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, NO
	goto_if_eq MF_PlayerChoseNoRomanceNorth
	msgbox MF_OkayLetsGo
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MF_AquaReturnCameraToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 7, MF_ArchieLeavesSouthAqua
	applymovement 8, MF_MattLeavesSouth
	waitmovement 8
	removeobject 7
	removeobject 8
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	setvar VAR_RYU_AQUA, 70 @Player is doing the romance line for aqua. Go to Mt Chihmney.
	release
	end
	
MF_PlayerChoseNoRomance::
	setvar VAR_RYU_AQUA, 72 @Player chose the non-romance aqua line, report back to shelly.
	applymovement 7, MF_ArchieLeavesNorthAqua
	applymovement 8, MF_MattLeavesNorth
	waitmovement 8
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	msgbox  MF_OkayReturnToShelly
	release
	end
	
MF_PlayerChoseNoRomanceNorth::
	setvar VAR_RYU_AQUA, 72 @Player chose the non-romance aqua line, report back to shelly.
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MF_AquaReturnCameraToPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 7, MF_ArchieLeavesSouthAqua
	applymovement 8, MF_MattLeavesSouth
	waitmovement 8
	removeobject 7
	removeobject 8
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	msgbox  MF_OkayReturnToShelly
	release
	end
	
	
MF_ThanksForMeteor:
	.string "Thanks for the meteor, Professor.\n"
	.string "We'll have to silence you now...can't\l"
	.string "have anyone knowing our plans.$"

MF_NotSoFast:
	.string "Not so fast, Magma scum!$"
	
MF_ResortingTo:
	.string "Resorting to picking on gullible old\n"
	.string "men now?$"

MF_TheLeaderOf:
	.string "The leader of Team Aqua, here!?$"
	
MF_AndWithThis:
	.string "And with this stranger blocking our\n"
	.string "way, there's no other choice.$"

MF_TimeToMake:
	.string "Time to make a strategic retreat...$"
	
MF_WhoMightYouBe:
	.string "And who might you be?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ... ...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Ah, so you're the new member of our\n"
    .string "crew!\p"
    .string "Nice timing, mate!\n"
    .string "We ousted Team Magma much easier\p"
    .string "with your help.\p"
    .string "I've heard interesting things about\n"
    .string "you from Shelly...that you're a bit\p"
    .string "of a daredevil.$"

MF_HahaIJest:
	.string "Haha I jest!\p"
    .string "Anyways, she's seen much promise in\n"
    .string "you, so I'm glad you're with us.$"

MF_BossWeReally:
	.string "Boss, we really need to chase after\n"
    .string "them.\p"
    .string "Who knows what they might be doing\n"
    .string "at Mt. Chimney...$"

MF_YoureRight:
	.string "You're right, Matt.\n"
    .string "Let's go.$"

MF_HowAboutIt:
	.string "How about it, {PLAYER}?\n"
    .string "Would you like to join us?$"

MF_OkayLetsGo:
	.string "Okay, We'll meet you there!\nHurry along!$"
	
MF_OkayReturnToShelly:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}All right, then.\pTime to return to Shelly.\nShe probably has more work.$"
	
MF_AquaReturnCameraToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_diag_northeast
	walk_diag_northeast
	step_end
	
MF_MagmaEscapeNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MF_MagmaEscape2North:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MF_ArchieToPlayerNorth:
	walk_right
	walk_right
	walk_right
	face_up
	step_end
	
MF_MattToPlayerNorth:
	walk_right
	walk_right
	face_up
	step_end

MF_AquaToCozmo:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

MF_ArchieToPlayer:
	walk_right
	walk_down
	walk_down
	step_end
	
MF_MattToPlayer:
	walk_down
	face_right
	step_end

MF_ArchieLeavesNorthAqua:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MF_MattLeavesNorth:
	delay_16
	walk_right
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
	
MF_ArchieLeavesSouthAqua:
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
	
MF_MattLeavesSouth:
	walk_right
	walk_up
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











