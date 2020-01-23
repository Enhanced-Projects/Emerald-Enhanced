Route119_MapScripts:: @ 81F4424
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume: @ 81F442F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon:: @ 81F4439
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition: @ 81F444D
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs:: @ 81F4466
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_CyclingTriathleteM:: @ 81F476B
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree:: @ 81F4774
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign:: @ 81F477D
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent:: @ 81F4786
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald:: @ 81F479D
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor:: @ 81F47B4
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug:: @ 81F47CB
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg:: @ 81F47E2
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent:: @ 81F47F9
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson:: @ 81F4810
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson:: @ 81F483C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	@nop Trainer_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson:: @ 81F485B
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine:: @ 81F4872
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine:: @ 81F489E
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	@nop Trainer_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine:: @ 81F48BD
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh:: @ 81F48D4
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil:: @ 81F48EB
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu:: @ 81F4902
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi:: @ 81F4919
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo:: @ 81F4930
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris:: @ 81F4947
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian:: @ 81F495E
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton:: @ 81F4975
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel:: @ 81F498C
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1:: @ 81F49A3
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2:: @ 81F49BA
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1:: @ 81F49D1
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2:: @ 81F49DA
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration:: @ 81F49E3
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall:: @ 81F49EC
	releaseall
	end

Route119_Text_StayAwayFromWeatherInstitute: @ 81F50EB
	.string "We're standing lookout here.\p"
	.string "Hey, you! Stay away from the WEATHER\n"
	.string "INSTITUTE. It's not safe.$"

Route119_Text_DontGoNearWeatherInstitute: @ 81F5147
	.string "Lookout duty is surprisingly boring.\p"
	.string "Hey, you! Please don't go near the\n"
	.string "WEATHER INSTITUTE.$"

Route119_Text_ThoughtFlyByCatchingBirdMons: @ 81F51A2
	.string "I thought you FLY by catching a whole\n"
	.string "flock of BIRD Pokémon, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's an HM move\n"
	.string "called FLY!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_Text_TallGrassSnaresBikeTires: @ 81F5261
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares BIKE tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_CanYourMonMakeSecretBase: @ 81F52B9
	.string "Can your Pokémon use its SECRET POWER\n"
	.string "on a big pile of grass and make a\l"
	.string "SECRET BASE?$"

Route119_Text_RouteSignFortree: @ 81F530E
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} FORTREE CITY$"

Route119_Text_WeatherInstitute: @ 81F5327
	.string "WEATHER INSTITUTE$"

Route119_Text_TrainerTipsDecoration: @ 81F5339
	.string "Trainer TIPS\p"
	.string "Up to sixteen decorations and\n"
	.string "furniture items can be placed in\l"
	.string "a SECRET BASE.\p"
	.string "Pick your favorite items and create\n"
	.string "your very own SECRET BASE exactly the\l"
	.string "way you want.$"

@==================================================================================================RIVAL ENCOUNTER

r119_RivalEncounterNorth::
	goto_if_set FLAG_RYU_R119_RIVAL, ryu_end
	lock
	setvar VAR_TEMP_5, 1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq r119_DawnEncounter
	goto r119_BrendanEncounter

r119_RivalEncounterSouth::
	goto_if_set FLAG_RYU_R119_RIVAL, ryu_end
	lock
	setvar VAR_TEMP_5, 2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq r119_DawnEncounter
	goto r119_BrendanEncounter
	
r119_DawnEncounter::
	lock
	playbgm MUS_GIRL_SUP, 0
	addobject 16
	compare VAR_TEMP_5, 1
	call_if_eq r119_DawnNorthMovement
	compare VAR_TEMP_5, 1
	call_if_ne r119_DawnSouthMovement
	goto r119_RivalInteractionFemale

r119_BrendanEncounter::
	lock
	playbgm MUS_BOY_SUP, 0
	addobject 16
	compare VAR_TEMP_5, 1
	call_if_eq r119_BrendanNorthMovement
	compare VAR_TEMP_5, 1
	call_if_ne r119_BrendanSouthMovement
	goto r119_RivalInteractionMale

r119_DawnNorthMovement:
	applymovement 16, r119_RivalNorthSteps
	waitmovement 16
	return

r119_DawnSouthMovement:
	setobjectxy 16, 28, 22
	applymovement 16, r119_RivalSouthSteps
	waitmovement 16
	return
	
r119_BrendanNorthMovement:
	applymovement 16, r119_RivalNorthSteps
	waitmovement 16
	return

r119_BrendanSouthMovement:
	setobjectxy 16, 28, 22
	applymovement 16, r119_RivalSouthSteps
	waitmovement 16
	return
	
r119_RivalNorthSteps:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	emote_exclamation_mark
	delay_8
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_up
	step_end
	
r119_RivalSouthSteps:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_down
	emote_exclamation_mark
	step_end

r119_RivalInteractionFemale:: @ 81F450B
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	msgbox R119_DawnIntroMsg, MSGBOX_DEFAULT
    goto r119_RivalBattleFemale
	end

r119_RivalBattleFemale:: @ Female Rival Battle #4
	trainerbattle_no_intro TRAINER_DAWN_4, r119_femaleRivalDefeated
	goto r119_femaleRivalOutro
	end

r119_femaleRivalOutro:: @ 81F456A
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	msgbox r119_FemaleDefeatText, MSGBOX_DEFAULT
	call r119_giveItemfinder
	msgbox R119_ExplainItemfinderFemale, MSGBOX_DEFAULT
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	closemessage
	call r119_DawnExit
	goto r119_scottEncounter
	end
	
r119_DawnExit::
	compare VAR_TEMP_5, 1
	call_if_eq r119_DawnExitNorth
	call_if_ne r119_DawnExitSouth

r119_DawnExitNorth::
	applymovement 16, r119_RivalExitStepsNorth
	waitmovement 16
	removeobject 16
	return
	
r119_DawnExitSouth::
	applymovement 16, r119_RivalExitStepsSouth
	waitmovement 16
	removeobject 16
	return
	
r119_RivalExitStepsSouth:
	walk_right
	walk_up
	walk_up
	walk_up
	step_end
	
r119_RivalExitStepsNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

r119_RivalInteractionMale:: @ 81F4585
	drawheadshot HEAD_BRENDAN
	msgbox r119_maleRivaIntro, MSGBOX_DEFAULT
    goto r119_RivalBattleMale
	end

r119_RivalBattleMale:: @ Male Rival battle #4
	trainerbattle_no_intro TRAINER_BRENDAN_4, r119_maleRivalDefeated
	goto r119_maleRivalOutro
	end

r119_maleRivalOutro:: @ 81F45E4
	drawheadshot HEAD_BRENDAN
	msgbox r119_maleRivalOutroText1, MSGBOX_DEFAULT
	call r119_giveItemfinder
	msgbox r119_maleRivalGivesItemfinder, MSGBOX_DEFAULT
	removecutscenesprites
	closemessage
	call r119_BrendanExit
	goto r119_scottEncounter
	end
	
r119_BrendanExit::
	compare VAR_TEMP_5, 1
	call_if_eq r119_BrendanExitNorth
	call_if_ne r119_BrendanExitSouth

r119_BrendanExitNorth::
	applymovement 16, r119_RivalExitStepsNorth
	waitmovement 16
	removeobject 16
	return
	
r119_BrendanExitSouth::
	applymovement 16, r119_RivalExitStepsSouth
	waitmovement 16
	removeobject 16
	return

r119_giveItemfinder:: @ 81F45FF
	giveitem ITEM_ITEMFINDER
	setflag FLAG_RECEIVED_HM02
	return

r119_scottEncounter:: @ 81F460F
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	addobject 41
	compare VAR_TEMP_5, 1
	call_if_eq R119_ScottEnterNorth
	call_if_ne R119_ScottEnterSouth
	checkplayergender
	compare VAR_RESULT, 1
	call_if_eq r119_malefinish
	call_if_ne r119_femalefinish
	closemessage
	applymovement 41, r119_ScottLeaves
	waitmovement 41
	removeobject 41
	setflag FLAG_RYU_R119_RIVAL
	releaseall
	end
	
R119_ScottEnterNorth:
	applymovement 41, r119_ScottEntersNorth
	waitmovement 41
	return
	
R119_ScottEnterSouth:
	applymovement 41, r119_ScottEntersSouth
	waitmovement 41
	return
	
r119_ScottEntersNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end
	
r119_ScottEntersSouth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_down
	step_end
	
r119_ScottLeaves:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

r119_malefinish::
msgbox r119_scottIntroFemalePlayer, MSGBOX_DEFAULT
return

r119_femalefinish::
msgbox r119_scottIntroMalePlayer, MSGBOX_DEFAULT
return

R119_DawnIntroMsg: @ 81F49FD
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: {PLAYER}!\n"
	.string "Where were you? I missed you!\p"
	.string "How have you been? \n"
	.string "...\p"
	.string "Wanna fight real quick?\n"
	.string "Of course you do! Go!$"

r119_femaleRivalDefeated: @ 81F4A98
	.string "Ow, I can barely stand!\n"
	.string "{PLAYER}, you're great!$"

r119_FemaleDefeatText: @ 81F4AF3
	.string "{COLOR LIGHT_RED}{SHADOW RED}I can't wait to see you crowned\n"
	.string "as Hoenn's Master.\pYou'll definetly\n"
	.string "succeed.\pHere, another gift for you!$"

R119_ExplainItemfinderFemale: @ 81F4B56
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: It's an Itemfinder!\n"
	.string "Use it to sense hidden items.\p"
	.string "Come visit me in Littleroot sometime!\n"
	.string "We'll have a fun night!\p"
	.string "See you later, {PLAYER}!$"

r119_maleRivaIntro: @ 81F4C9A
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: Yo, {PLAYER}{COLOR LIGHT_BLUE}{SHADOW BLUE}!\pI've been looking all over for ya!\nDoing good? You know I am!\pSay...since we're here, how about\na quick one?\pA battle, right here and now!\nAlright, here we go!$"

r119_maleRivalDefeated: @ 81F4D24
	.string "That was rough... \n"
	.string "I'm not used to being smashed.$"

r119_maleRivalOutroText1: @ 81F4D4B
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: It's a nice change. I'm\nwierdly turned on.\pYou...being strong enough to\ntopple the current Champion…\lThat'll be a day I'm definitely\llooking forward to seeing!\pHere, something else for you!$"

r119_maleRivalGivesItemfinder: @ 81F4DB5
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: This is an Itemfinder.\pIt'll scan and find hidden items.\pI'm gonna head back home soon.\nDrop by my place sometime!\lI'll make it worth your while!\pTake care, {PLAYER}!$"

r119_scottIntroFemalePlayer: @ 81F4E60
	.string "Scott: Hahahah!\n"
	.string "Way to go, {PLAYER}!\p"
	.string "I just spotted a Trainer going\n"
	.string "back to town at a speedy clip!\p"
	.string "You just beat that trainer, didn't you?\n"
	.string "It was pretty obvious that you did.\p"
	.string "He looked really upset with\n"
	.string "a face all red from embarassment.\p"
	.string "I sure seem to run into you often.\n"
	.string "Well, I'll be seeing you!$"

r119_scottIntroMalePlayer:	
    .string "Scott: Hahahah!\n"
	.string "Way to go, {PLAYER}!\p"
	.string "I just spotted a Trainer going\n"
	.string "back to town at a speedy clip!\p"
	.string "You're quite the lady-killer, eh?\n"
	.string "It was pretty obvious that you are.\p"
	.string "She looked really flushed.\n"
	.string "It's obvious that she likes you.\p"
	.string "I sure seem to run into you often.\n"
	.string "Well, I'll be seeing you!$"
