AquaSubmarine_MapScripts::
	map_script ON_FRAME AS_OnFrameScript
	map_script ON_WARP, AS_OnWarpScript
	.byte 0

AS_OnFrameScript::
	map_script_2 VAR_RYU_AQUA, 139, AS_DoMainAquaScene
	map_script_2 VAR_RYU_AQUA, 143, AS_DoUpperFloorScene
	map_script_2 VAR_RYU_AQUA, 153, AS_DoFinalSubScene
	.2byte 0

AS_OnWarpScript:
	map_script_2 VAR_RYU_AQUA, 153, AS_MakePlayerInvisible
	.2byte 0

AS_MakePlayerInvisible:
	applymovement OBJ_EVENT_ID_PLAYER, SCH_SetInvisible
	end


AS_DoMainAquaScene::
	setvar VAR_RYU_AQUA, 141 @Player is at final part of aqua shelly scene
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox AS_Heheh
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	applymovement 1, Common_Movement_FaceRight
	waitmovement 3
	applymovement 3 Common_Movement_FaceRight
	waitmovement 3
	pokenavcall AS_ArchieThisIsMatt
	waitmessage
	applymovement 3, Common_Movement_FaceRight
	waitmovement 3
	msgbox AS_TheBlueOrb
	waitmessage
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox AS_DoYouSeeNow
	closemessage
	playmoncry SPECIES_KYOGRE, 0
	waitmoncry
	playse SE_W089
	fadescreen FADE_TO_BLACK
	delay 10
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_0x8004, 8  @ vertical pan
	setvar VAR_0x8005, 8  @ horizontal pan
	setvar VAR_0x8006, 3  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	delay 10
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	delay 10
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	delay 10
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	delay 10
	playse SE_PIN
	waitmovement 4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox AS_BossWeJust
	closemessage
	playbgm MUS_DUMMY, 0
	delay 10
	goto AS_DoMainAquaScenePt2
	
AS_DoMainAquaScenePt2::
	msgbox AS_WhatHaveIDone
	closemessage
	applymovement 3, Common_Movement_StepUp
	waitmovement 3
	msgbox AS_TheresNoOther
	closemessage
	delay 20
	msgbox AS_IPutAll
	closemessage
	applymovement 3, Common_Movement_StepDown
	waitmovement 3
	applymovement 3, Common_Movement_StepDown
	waitmovement 3
	applymovement OBJ_EVENT_ID_PLAYER, AS_PlayerToArchie @ down 2, right 2
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox AS_WaitIllDoIt
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox AS_No
	closemessage
	applymovement 1, Common_Movement_StepDown
	waitmovement 1
	applymovement 1, Common_Movement_FaceRight
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox AS_ImTheOnly
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 3, Common_Movement_FaceDown
	waitmovement 3
	giveitem ITEM_BLUE_ORB, 1
	giveitem ITEM_MASTER_BALL, 1
	msgbox AS_KyogreMustBe
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_RYU_AQUA, 143 @Player is getting ready to exit the submarine
	warp MAP_AQUA_SUBMARINE, 255, 5, 8 @Top floor
	waitstate
	
	
AS_DoUpperFloorScene::
	applymovement OBJ_EVENT_ID_PLAYER, AS_PlayerSubMovement1 
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOOR
	waitse
	addobject 5
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 5, AS_PlayerSubMovement1
	waitmovement 5
	msgbox AS_Wait
	closemessage
	msgbox AS_ICanAlready
	closemessage
	applymovement 5, Common_Movement_StepUp
	waitmovement 5
	playse SE_W204
	applymovement 5, Common_Movement_HeartEmote
	waitmovement 5
	delay 20
	applymovement 5, AS_SlideBack
	waitmovement 5
	msgbox AS_ComeBackAlive
	closemessage
	delay 30
	msgbox AS_IWill
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AS_PlayerExitSub
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_RYU_AQUA, 145
	setflag FLAG_RYU_PLAYER_HELPING_AQUA
	setvar VAR_RYU_QUESTLINE_ID, 1
	setflag FLAG_RYU_DS_SHELLY_LOVERS
	clearflag FLAG_RYU_KYOGRE_RAN
	clearflag FLAG_RYU_KYOGRE
	setflag FLAG_RYU_PLAYER_HELPING_AQUA
	setvar VAR_RYU_QUESTLINE_ID, 1
	warpsilent MAP_UNDERWATER_ROUTE128, 255, 71, 5
	waitstate

AS_DoFinalSubScene::
	setvar VAR_RYU_AQUA, 155 @Player needs to return to aqua headquarters
	pokenavcall AS_ArchiesCall
	waitmessage
	delay 30
	applymovement 3, Common_Movement_FaceLeft
	waitmovement 3
	msgbox AS_ArchiePlayer
	closemessage
	warpsilent MAP_UNDERWATER_ROUTE128, 255, 50, 15
	waitstate
	

AS_ArchiesCall:
	.string "... ... ... ...\pIt stopped you say?\n{PLAYER} must have done it then...$"

AS_ArchiePlayer:
	.string "{PLAYER}...$"
	
	

AS_Heheh:
	.string "Heheh...$"
	
AS_ArchieThisIsMatt:
	.string "Archie, this is Matt.\n"
    .string "How're things up on the surface?\p"
    .string "It's bad...it's very bad!\n"
    .string "Kyogre will destroy everything!$"

AS_TheBlueOrb:
	.string "The Blue Orb is in my possession!\n"
    .string "Kyogre should be able to-$"

AS_DoYouSeeNow:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Do you see now, Archie?\n"
    .string "Our precious utopia...that dream now\p"
    .string "lies at the bottom of the sea.$"

AS_BossWeJust:
	.string "Boss! We just took a massive hit!\n"
    .string "One more like that will end all of us\l"
    .string "here!$"

AS_WhatHaveIDone:
	.string "What have I done?\n"
    .string "... ... ...$"

AS_TheresNoOther:
	.string "There's no other choice...I must go\n"
    .string "and capture Kyogre.$"

AS_IPutAll:
	.string "I put all of you and Hoenn in danger.\n"
    .string "It's only fitting that I finish what\p"
    .string "I started and right my wrongs.$"

AS_WaitIllDoIt:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Wait, I'll do it.$"
	
AS_No:
	.string "{COLOR LIGHT_RED}{SHADOW RED}No!$"
	
AS_ImTheOnly:
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I'm the only one strong enough to\n"
    .string "face it.\p"
    .string "And besides, I was planning on\n"
    .string "stopping you anyway.\p"
    .string "In a sense, I would've become a\n"
    .string "traitor to Team Aqua.\p"
    .string "It's better if I take the fall.\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Didn't I tell you to stop trying to\n"
    .string "be a hero!?\p"
    .string "You can't-!\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Very well, {PLAYER}.\n"
	.string "You're walking the plank.\n"
	.string "Take These...$"

AS_KyogreMustBe:
	.string "Kyogre must be in fear of being\n"
    .string "controlled by the Blue Orb.\p"
    .string "It will focus all attention on you,\n"
    .string "letting us escape.\p"
    .string "Consider this your final mission as\n"
    .string "part of the crew.\p"
    .string "Do not fail.$"

AS_Wait:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Wait.$"
	
AS_ICanAlready:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I can already tell you're going to\n"
    .string "say no.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ... ...\n"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Well then, I have a final assignment\p"
    .string "for you too.$"

AS_ComeBackAlive:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Come back alive.$"

AS_IWill:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I will.$"

AS_PlayerToArchie: @ down 2, right 2
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

AS_PlayerSubMovement1: @ left 4, up 2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end
	
AS_SlideBack:
	slide_down
	face_up
	step_end
	
AS_PlayerExitSub:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
