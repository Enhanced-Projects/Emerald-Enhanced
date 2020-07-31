LilycoveCity_MapScripts:: @ 81E2B3C
	map_script ON_TRANSITION, LilycoveCity_OnTransition
	map_script ON_LOAD , LilycoveCity_OnLoad
	map_script ON_FRAME, LeafScene
	.byte 0

LeafScene::
    map_script_2 VAR_RYU_DS_LANA_STAGE, 1, LeafSceneResume
	map_script_2 VAR_TEMP_A, 0, LCC_SetUpMagma
	@map_script_2 VAR_TEMP_D, 0, RyuResetFollowerPosition
    .2byte 0
	
LCC_SetUpMagma::
	setvar VAR_TEMP_A, 100
	compare VAR_RYU_MAGMA, 165
	goto_if_ne ryu_end
	setobjectxy 21, 27, 0
	setobjectxy 22, 27, 0
	copyobjectxytoperm 21
	copyobjectxytoperm 22
	end
	
	
@================================================================================================== Follower Shelly interaction

LCC_ShellyFollowerInteraction::
	lockall
	setvar VAR_TEMP_0, 100
	goto_if_unset FLAG_RYU_HAS_FOLLOWER, ryu_end
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_AQUA_MEMBER_F
	goto_if_eq LCC_ShellyFollowerScene
	goto ryu_end

LCC_ShellyFollowerScene::
	applymovement OBJ_EVENT_ID_PLAYER, LCC_ToCoast
	applymovement OBJ_EVENT_ID_FOLLOWER, LCC_ToCoast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox LCC_ShellyWhenIWasLittle
	applymovement OBJ_EVENT_ID_FOLLOWER, LCC_FacePlayerSS
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_HeartEmote
	playse SE_W204
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LCC_ShellyThanksFor
	closemessage
	releaseall
	end
	
LCC_ShellyThanksFor:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Thanks for bringing me here.\n"
    .string "The ocean always makes me feel at\l"
    .string "home.$"

LCC_ToCoast:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_down
	step_end
	
LCC_FacePlayerSS::
	face_right
	walk_in_place_right
	step_end
	
LCC_ShellyWhenIWasLittle:
    .string "{COLOR LIGHT_RED}{SHADOW RED}When I was little, I used\n"
    .string "to stand here every day. I always\p"
    .string "loved the sea, and perhaps that's\n"
    .string "why I found my way into Team Aqua.\p"
    .string "I kept hearing stories of people\n"
    .string "and companies expanding things into\p"
    .string "the sea, and was always worried that\n"
    .string "it may disappear one day.\p"
    .string "I never realised just how vast the\n"
    .string "ocean really is. The Pokemon would\p"
    .string "take over and fix things before\n"
    .string "humans could completely overtake\p"
    .string "the sea. I see now, why Aqua's\n"
    .string "original vision was inherently\p"
    .string "wrong. I'm happy you helped me\n"
    .string "understand.$"

@================================================================================================== End

@==================================================================================================Leaf Scene

LeafSceneResume::
	call RyuResetFollowerPositionAR
    goto_if_unset FLAG_RYU_ON_DATE ryu_end
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	fadenewbgm MUS_THANKFOR
	msgbox LCL_Story1 MSGBOX_DEFAULT
	closemessage
	applymovement 23, Common_Movement_FaceRight
	waitmovement 23
	msgbox LCL_Story2 MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LCL_Story3 MSGBOX_DEFAULT
	closemessage
	applymovement 23, Common_Movement_FaceDown
	waitmovement 23
	msgbox LCL_Story4 MSGBOX_DEFAULT
	closemessage
	applymovement 23, Common_Movement_FaceRight
	waitmovement 23
	msgbox LCL_Story4_5 MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement 23, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 23
	msgbox LCL_Story5 MSGBOX_DEFAULT
	closemessage
	applymovement 23, Common_Movement_QuestionMark
	waitmovement 23
	msgbox LCL_Story6 MSGBOX_DEFAULT
	closemessage
	applymovement 23, Common_Movement_HeartEmote
	waitmovement 23
	msgbox LCL_Story7 MSGBOX_DEFAULT
	closemessage
	applymovement 23, LCL_LeafLeaving
	waitmovement 23
	removeobject 23
	fadedefaultbgm
	clearflag FLAG_RYU_ON_DATE
	setvar VAR_RYU_DS_LANA_STAGE, 80
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	setflag FLAG_RYU_LEAF_LCC_EVENT_DONE
	clearflag FLAG_RYU_HIDE_LCC_DEPT_ROOF_NPC
	setflag FLAG_RYU_LANA_EVENT14
	setflag FLAG_RYU_DS_LEAF_LOVERS
	clearflag FLAG_HIDE_LANAS_HOUSE_LANA_AND_BRO
	release
	end
	
LCL_LeafLeaving:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
@==================================================================================================LeafSceneEnd

LilycoveCity_OnTransition: @ 81E2B47
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad: @ 81E2B61
	end

LilycoveCity_EventScript_SetWailmerMetatiles:: @ 81E2B6B
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, 1
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, 1
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, 1
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, 1
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, 1
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, 1
	return

LilycoveCity_EventScript_BerryGentleman:: @ 81E2BD8
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry:: @ 81E2C18
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3:: @ 81E2C22
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl:: @ 81E2C2B
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone:: @ 81E2C40
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy:: @ 81E2C4A
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2:: @ 81E2C53
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone:: @ 81E2C68
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2:: @ 81E2C72
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone:: @ 81E2C87
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2:: @ 81E2C91
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1:: @ 81E2C9A
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF:: @ 81E2CA3
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2:: @ 81E2CAC
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone:: @ 81E2CC1
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1:: @ 81E2CCB
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan:: @ 81E2CD4
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1:: @ 81E2CDD
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement 20, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1:: @ 81E2CEE
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement 19, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign:: @ 81E2CFF
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign:: @ 81E2D08
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign:: @ 81E2D11
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign:: @ 81E2D1A
	lockall
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings:: @ 81E2D3A
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign:: @ 81E2D44
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady:: @ 81E2D58
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign:: @ 81E2D62
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign:: @ 81E2D6B
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign:: @ 81E2D74
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt:: @ 81E2D7D
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer:: @ 81E2DB0
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1:: @ 81E2DBA
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2:: @ 81E2DC3
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3:: @ 81E2DCC
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4:: @ 81E2DD5
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_SchoolKidM:: @ 81E302D
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq LilycoveCity_EventScript_KnowAboutBerryBlender
	compare VAR_RESULT, NO
	call_if_eq LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender:: @ 81E304F
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender:: @ 81E3058
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MovedLootIntoHideoutToday: @ 81E3B2C
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "HIDEOUT today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_ChanceToDoBigThings: @ 81E3B95
	.string "I'm just a GRUNT, so I don't know what\n"
	.string "the BOSS is thinking…\p"
	.string "But being on Team Aqua, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_DontGoNearCaveInCove: @ 81E3C46
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!\n"
	.string "I'm an adult, so you just listen to me!$"

LilycoveCity_Text_IfWorldBecomesOurs: @ 81E3CBE
	.string "If this whole wide world becomes ours,\n"
	.string "Team Aqua's, it will be a happier\l"
	.string "place for Pokémon, too.$"

LilycoveCity_Text_WailmerLeapOutOfWater: @ 81E3D1F
	.string "There! WAILMER!\n"
	.string "Leap out of the water now!$"

LilycoveCity_Text_GetLostMessingUpTraining: @ 81E3D4A
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"

LilycoveCity_Text_ContestHallInTown: @ 81E3D9E
	.string "There's a Pokémon Contest HALL\n"
	.string "right in this here town. \p"
	.string "That means well-raised Pokémon will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"

LilycoveCity_Text_StrangeCaveInCove: @ 81E3E3C
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs: @ 81E3E7D
	.string "I'm going to teach my Pokémon some new\n"
	.string "moves for entering a Contest.\p"
	.string "So, I'm going to see the MOVE DELETER\n"
	.string "and make it forget HM moves.$"

LilycoveCity_Text_ImFromKanto: @ 81E3F05
	.string "I came from KANTO.\p"
	.string "The Hoenn region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "Hunh? Wait a second…\p"
	.string "Could there be rare Pokémon that live\n"
	.string "only in this area?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer: @ 81E3FAB
	.string "Team Aqua's been training their\n"
	.string "WAILMER in the cove.\p"
	.string "We SAILORS can't get our boats out\n"
	.string "to sea with them in the way!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut: @ 81E4020
	.string "Ahoy, did you know?\p"
	.string "Someone punted Team Aqua out of\n"
	.string "the way for us!\p"
	.string "That got the WAILMER out of the cove,\n"
	.string "so we can get our boats out again.$"

LilycoveCity_Text_SomeoneStoleMyPokemon: @ 81E40AD
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my Pokémon!\p"
	.string "Who's the abductor?\n"
	.string "Team Aqua? Is it Team Aqua?$"

LilycoveCity_Text_MissingPokemonCameBack: @ 81E4145
	.string "My missing Pokémon…\n"
	.string "It came back without me noticing!$"

LilycoveCity_Text_ImArtDealer: @ 81E417B
	.string "I'm an ART DEALER.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the MUSEUM here has\n"
	.string "magnificent works on exhibit…$"

LilycoveCity_Text_SeaRemainsForeverYoung: @ 81E420B
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed: @ 81E4283
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern: @ 81E42FC
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that Team Aqua lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving Team Aqua”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"

LilycoveCity_Text_TeamAquaLotGoneForGood: @ 81E43FF
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That Team Aqua lot, they must\n"
	.string "have gone away for good.$"

LilycoveCity_Text_CitySign: @ 81E448B
	.string "LILYCOVE CITY\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"

LilycoveCity_Text_ContestHallSign: @ 81E44C3
	.string "Pokémon Contest HALL\n"
	.string "“The gathering place for Trainers!”$"

LilycoveCity_Text_MotelSign: @ 81E44FC
	.string "COVE LILY MOTEL\p"
	.string "“Remember us as COVE LILY of\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_MuseumSign: @ 81E4534
	.string "LILYCOVE MUSEUM\p"
	.string "“Pokémon Masterpiece Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit: @ 81E4571
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s Pokémon Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_HarborSignUnderConstruction: @ 81E45A7
	.string "LILYCOVE CITY HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in SLATEPORT CITY.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

LilycoveCity_Text_HarborSign: @ 81E4624
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign: @ 81E466E
	.string "Pokémon Trainer FAN CLUB\p"
	.string "The names of Trainers are scribbled\n"
	.string "all over the sign…$"

LilycoveCity_Text_DepartmentStoreSign: @ 81E46BE
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"

LilycoveCity_Text_MoveDeletersHouseSign: @ 81E473D
	.string "MOVE DELETER's HOUSE\p"
	.string "“Unwanted Pokémon moves deleted.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender: @ 81E4774
	.string "Do you know about the machine\n"
	.string "BERRY BLENDER?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks: @ 81E47A1
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}S you can get, I've heard.$"

LilycoveCity_Text_ExplainBerryBlender: @ 81E4824
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a Pokémon,\n"
	.string "its condition will improve by a lot.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar: @ 81E48A5
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the SKY PILLAR, I hear.$"

LilycoveCity_Text_SawTallTowerOnRoute131: @ 81E4902
	.string "I saw this tall tower somewhere\n"
	.string "around ROUTE 131.\p"
	.string "Could that possibly be…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon: @ 81E494D
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a DRAGON-type\n"
	.string "Pokémon flying way up in the sky.\p"
	.string "Do cool Pokémon like that live in\n"
	.string "the Hoenn region?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon: @ 81E49F4
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare Pokémon as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "Pokémon as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"

@==================================================================================================Rival Stuff
LilycoveCity_EventScript_Rival:: @ 81E2DDE
	lock
	faceplayer
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LCC_FemalRivalIntroScript
	compare VAR_RESULT, FEMALE
	goto_if_eq MaleRivalIntroScript
	end

LCC_FemalRivalIntroScript:: @ 81E2DF8
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	playbgm MUS_GIRL_SUP, 1
	msgbox lcc_femaleRivalBattleIntro, MSGBOX_DEFAULT
	goto LCC_FemalRivalStartBattle
	end

LilycoveCity_EventScript_1E2E48:: @ 81E2E48
	msgbox lcc_femaleRivalAskAgain, MSGBOX_YESNO
	nop
    return

LilycoveCity_EventScript_1E2E51:: @ 81E2E51
	msgbox lcc_femaleRivalIntro, MSGBOX_DEFAULT
	closemessage
	nop
    msgbox lcc_femaleRivalIntroQuery MSGBOX_YESNO
    return

LCC_FemalRivalBattleDeclined:: @ 81E2E5A
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox lcc_femaleRivalVictory, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

MaleRivalIntroScript:: @ 81E2E6B
	playbgm MUS_BOY_SUP, 1
	msgbox lcc_brendanBattleStarting, MSGBOX_DEFAULT
	goto LCC_MaleRivalStartBattle
	end

LilycoveCity_EventScript_1E2EBB:: @ 81E2EBB
	msgbox lcc_brendanAsksforBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2EC4:: @ 81E2EC4
	msgbox lcc_brendanPreBattleIntro MSGBOX_DEFAULT
	closemessage
	applymovement 17, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox lcc_brendanIntro, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2ECD:: @ 81E2ECD
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox lcc_declinedBrendanBattle, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LCC_FemalRivalStartBattle:: @ 81E2EFE
	trainerbattle_no_intro TRAINER_DAWN_5, lcc_femaleRivalBattleDefeat
	goto LCC_FemalRivalBattleFinished
	end

LCC_MaleRivalStartBattle:: @ 81E2F2E
	trainerbattle_no_intro TRAINER_BRENDAN_5, lcc_brendanLostBattle
	goto LCC_MaleRivalBattleFinished
	end

LCC_FemalRivalBattleFinished:: @ 81E2F3E
    fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGDAWN
	msgbox lcc_femaleRivalChat, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_DAWNS_HOUSE_2F_PICHU_DOLL
	goto lcc_femaleRivalRelChoice1
	end

LCC_MaleRivalBattleFinished:: @ 81E2FAA
	applymovement 17, lcc_brendanStepRight
	applymovement OBJ_EVENT_ID_PLAYER, lcc_playerStepRight
	waitmovement 0
	msgbox lcc_brendanOutro1, MSGBOX_DEFAULT
	closemessage
	applymovement 17 lcc_brendanStepLeft
	applymovement OBJ_EVENT_ID_PLAYER, lcc_playerLookUp
	waitmovement 0 
	msgbox lcc_brendanOutro2 MSGBOX_DEFAULT
	closemessage
	setfieldeffectargument 0, 1
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto lcc_maleRivalRelChoice1 
	release
	end
	
lcc_brendanStepRight:
	walk_right
	walk_in_place_right
	delay_8
	step_end
	
lcc_playerStepRight:
    delay_8
	walk_in_place_right
	step_end
	
lcc_brendanStepLeft:
	walk_left
	walk_in_place_down
	step_end
	
lcc_playerLookUp:
	walk_in_place_up
	step_end

lcc_femaleRivalRelChoice1:: @ 81E3006
	closemessage
	msgbox lcc_dawnRelQuery1 MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne lcc_dawn_declined
	setflag FLAG_RYU_DS_DAWN_CLOSEFRIENDS
	delay 50
	additem ITEM_TOWN_MAP
	msgbox LCC_Dawn_DS_TC_MEM MSGBOX_DEFAULT
	delay 60
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	setfieldeffectargument 0, 1
	applymovement 17, LCC_DAWN_KISS
	waitmovement 0
	delay 20
	msgbox LCC_DAWN_MSG MSGBOX_DEFAULT
	dofieldeffect 30
	delay 15
	removeobject 17
	waitfieldeffect 30
	setobjectxy 17, 0, 10 
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	clearflag FLAG_HIDE_DAWNS_HOUSE_DAWN
	closemessage
	release
	end
	
lcc_maleRivalRelChoice1::
	closemessage
	msgbox lcc_brendanRelQuery1 MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne lcc_brendan_declined
	setflag FLAG_RYU_DS_BRENDAN_FRIENDS
	delay 50
	additem ITEM_TOWN_MAP
	msgbox LCC_BRENDAN_DS_TC_MEM MSGBOX_DEFAULT
	msgbox lcc_brendan_scene MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadescreen 1
	msgbox LCC_BRENDAN_MSG MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, LCC_BrendanLeaves
	applymovement OBJ_EVENT_ID_PLAYER, lcc_playerFaceDown
	delay 40
	fadescreen 0
	delay 50
	waitmovement 17
	removeobject VAR_LAST_TALKED
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	clearflag FLAG_HIDE_BRENDANS_HOUSE_BRENDAN
	release
	end
	
lcc_brendan_declined::
	setflag FLAG_RYU_DS_BRENDAN_ACQ
    msgbox lcc_brendan_declined_msg MSGBOX_DEFAULT
	delay 20
	setfieldeffectargument 0, 1
	delay 20
	dofieldeffect 30
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect 30
	savebgm MUS_DUMMY
	fadedefaultbgm
	msgbox lcc_brendanLeave MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_LILYCOVE
	closemessage
	release
	end
	
LCC_BrendanLeaves:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	step_end
	
lcc_playerFaceDown:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end
	
lcc_brendan_scene:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}, I have another gift for you.\nClose your eyes for this one!$"
	
lcc_brendanRelQuery1:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Feel like getting some extra\ntraining in with me later?$"
	
LCC_BRENDAN_DS_TC_MEM:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Brendan: This is a guest card for my\n"
	.string "membership at the Training Center.\p"
	.string "They should give you a steep\n"
	.string "discount, Dad signed me up for the\p"
	.string "premium package.\p"
	.string "... ... ... ... ... ...\n"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Brendan seems nervous.)$"


LCC_Dawn_DS_TC_MEM:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn: This is a guest card for my\n"
	.string "membership at the Training Center.\p"
	.string "They should give you a steep\n"
	.string "discount, Dad signed me up for the\p"
	.string "premium package.\p"
	.string "... ... ... ... ... ... \n"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Dawn blushes a little.)$"
	
LCC_BRENDAN_MSG:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Brendan pecked you on the cheek!$"
	
lcc_brendan_declined_msg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Okay then... well, I've gotta get\n"
	.string "going, {PLAYER}. See ya around.$"
	
lcc_brendanLeave:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(That alarmed expression left on\n his face as he walked away… you\l wondered if he was expecting\l something else to happen…)$"

lcc_dawn_declined::
    setflag FLAG_RYU_DS_DAWN_ACQ
    msgbox lcc_dawn_declined_msg MSGBOX_DEFAULT
	closemessage
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	delay 20
	setfieldeffectargument 0, 1
	delay 20
	msgbox lcc_dawnLeave MSGBOX_DEFAULT
	dofieldeffect 30
	delay 15
	waitfieldeffect 30
	savebgm MUS_DUMMY
	fadedefaultbgm
	removeobject 17
	setflag FLAG_MET_RIVAL_LILYCOVE
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	closemessage
	release
	end

lcc_dawnRelQuery1:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Would you like to go train with me\n"
	.string "sometime?$"

lcc_dawnLeave:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(she left a little flustered, you\p"
	.string " can't help but wonder if she is\n"
	.string " disappointed in something...)$"

lcc_dawn_declined_msg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Oh, okay, I see. Well, I'm going to\n"
	.string "head out. Talk to you later, {PLAYER}.$"

LCC_DAWN_KISS:
    walk_in_place_down
    emote_heart
	step_end

LCC_DAWN_MSG:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Dawn suddenly kissed you!$"

lcc_femaleRivalIntro: @ 81E3061
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh, hey?\n"
	.string "{PLAYER}, are you shopping, too?\p"
	.string "I bought a whole bunch of dolls and\n"
	.string "posters. You should get one made of\p"
	.string "you, I'd pin it up front and center!\n"
	.string "Of course, I've also caught a lot of\p"
	.string "Pokémon, and I'm raising them\n"
	.string "properly, too.\p"
	.string "Actually, I'm more worried if you're\n"
	.string "raising Pokémon properly, {PLAYER}.$"
	
lcc_femaleRivalIntroQuery:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I'll battle with you, so you can show\n"
	.string "me your Pokémon, {PLAYER}.$"

lcc_femaleRivalVictory: @ 81E318D
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh, my... {PLAYER}, haven't you\n"
    .string "been training at all? I'm dissapointed.\l"
	.string "You'll never be able to win the Pokémon\l"
	.string "League if you can't best lil' ol me!$" 

lcc_femaleRivalAskAgain: @ 81E31F5
	.string "{COLOR LIGHT_RED}{SHADOW RED}Come on, battle with me, so I can\n"
	.string "check out your Pokémon!$"

lcc_femaleRivalBattleIntro: @ 81E3234
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh, hey?\n"
	.string "{PLAYER}, are you shopping, too?\p"
	.string "I bought a whole bunch of dolls and\n"
	.string "posters. You should get one made of\p"
	.string "you, I'd pin it up front and center!\n"
	.string "Of course, I've also caught a lot of\p"
	.string "Pokémon, and I'm raising them\n"
	.string "properly, too.\p"
	.string "Actually, I'm more worried if you're\n"
	.string "raising Pokémon properly, {PLAYER}.$"

lcc_femaleRivalBattleDefeat: @ 81E3275
	.string "Oooh, you really pounded me.$\p"

lcc_femaleRivalChat: @ 81E32FB
	.string "{COLOR LIGHT_RED}{SHADOW RED}I'm thinking of going back to\n"
	.string "Littleroot soon.\p"
	.string "I've caught a decent group of Pokémon,\n"
	.string "and my Pokédex is coming along, so\l"
	.string "I'm going home to show my dad.\p"
	.string "You {COLOR BLUE}should{COLOR DARK_GREY} come visit me at home,\n"
	.string "{PLAYER}, before you challenge the Master.$"

lcc_femaleRivalOutro: @ 81E3398
	.string "{COLOR LIGHT_RED}{SHADOW RED}I remember the first battle I had with\n"
	.string "you, {PLAYER}. It was special. I'm\l"
	.string "so glad I get to see you so often.\l"
	.string "It makes me really happy to be with you.\l"
	.string "{PLAYER}, what are you going to do?\p"
	.string "Collect all the Gym Badges and take\n"
	.string "the Pokémon League challenge?\p"
	.string "Well, while you're collecting Badges,\n"
	.string "{PLAYER}, I'm going to work on my\l"
	.string "Pokédex. I'll complete it before you!$"

LCC_FemalRivalConvoDoneNotChampion: @ 81E346D
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, what are you going to do?\p"
	.string "Are you taking the Pokémon League\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "Pokédex?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my Pokédex before you!$"

lcc_DawnOutroPlayerisChampion: @ 81E353A
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, what are you going to do?\p"
	.string "Are you taking the Battle Frontier\n"
	.string "challenge?\p"
	.string "Since you've beaten the Master, you\n"
	.string "can re-challenge him.\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my Pokédex before you!\p"
	.string "See you!$"

lcc_brendanIntro: @ 81E3608
	.string "{COLOR LIGHT_RED}{SHADOW RED}What? No, it's nothing like that!\p"
	.string "I'd rather get it for someone\n"
	.string "lik-uh... nevermind.\p"
	.string "Anyways, are you raising your\n"
	.string "Pokémon properly? Let me check.\p"
	.string "Yep, you know what time it is!\n{PLAYER}, I challenge you!$"

lcc_brendanPreBattleIntro:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}! You're a\n"
	.string "welcome sight!\p" 
	.string "Are you per chance stopping by\n"
	.string "to shop?\p... ... ...\p"
	.string "Me? Nah, I just came by to run an\n"
	.string "errand for my dad. You know how\l"
	.string "he is…\l... ... ... $"

lcc_declinedBrendanBattle: @ 81E36BF
	.string "{COLOR LIGHT_RED}{SHADOW RED}Aw c'mon, don't chicken\nout on me now!$"

lcc_brendanAsksforBattle: @ 81E36FA
	.string "{COLOR LIGHT_RED}{SHADOW RED}Want to battle to see who's\n"
	.string "been raising Pokémon better?$"

lcc_brendanBattleStarting: @ 81E373C
	.string "{{COLOR LIGHT_RED}{SHADOW RED}Now it's time to show\nyou what I'm made of!$"

lcc_brendanLostBattle: @ 81E3777
	.string "Eager to come out on top, are we?$"

lcc_brendanOutro1: @ 81E37D7
	.string "{COLOR LIGHT_RED}{SHADOW RED}I… I plan on going\n"
	.string "home to Littleroot.\p"
	.string "I'm still helping out my dad\n"
	.string "on his Pokédex, and it's coming\l"
	.string "together pretty well, so it's\l"
	.string "about time I show him.\p"
	.string "... ... ...$"
	
lcc_brendanOutro2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I know you'll take on the\n"
	.string "Pokémon League challenge,\p"
	.string "{PLAYER}, but {COLOR DARK_GREY}do{COLOR LIGHT_RED}{SHADOW RED} stop by my place\n"
	.string "before that time.$"

@==================================================================================================End rival stuff

@==================================================================================================Begin Magma Stuff


LCC_MiddleMagmaTrigger::
	compare VAR_RYU_MAGMA, 165
	goto_if_ne ryu_end
	lockall
	playbgm MUS_MGM0, 0
	playse SE_PIN
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 10
	applymovement 10, Common_Movement_FaceLeft
	waitmovement 10
	msgbox LCC_WhatThe
	applymovement 24, Common_Movement_StepDown
	waitmovement 24
	applymovement 24, Common_Movement_FaceUp
	waitmovement 24
	applymovement 10, LCC_AquaGruntRunsAway
	waitmovement 10
	removeobject 10
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	applymovement 24, Common_Movement_StepUp
	waitmovement 24
	applymovement 24, Common_Movement_StepUp
	waitmovement 24
	applymovement 24, Common_Movement_FaceLeft
	waitmovement 24
	msgbox LCC_ITakeIt
	subvar VAR_ASH_GATHER_COUNT, 2000
	closemessage
	msgbox LCC_ThisIsGoing
	applymovement 24 Common_Movement_FaceRight
	waitmovement 24
	closemessage
	call LCC_Magma_PoisonWater1
	setvar VAR_RYU_MAGMA, 170@Player poisoned the first portion of ocean
	fadenewbgm MUS_AJITO
	release
	end
	
LCC_TopMagmaGrunt::
	lock
	faceplayer
	compare VAR_RYU_MAGMA, 170
	goto_if_ne LCC_MagmaGruntNotReady
	msgbox LCC_ReadyWhenYouAre
	closemessage
	subvar VAR_ASH_GATHER_COUNT, 2000
	applymovement 25, Common_Movement_FaceRight
	waitmovement 25
	call LCC_Magma_PoisonWater2
	setvar VAR_RYU_MAGMA 175@Player poisoned 2 spots
	release
	end
	
LCC_BottomMagmaGrunt::
	lock
	faceplayer
	compare VAR_RYU_MAGMA, 175
	goto_if_ne LCC_MagmaGruntNotReady
	msgbox LCC_ThisShouldBe
	closemessage
	subvar VAR_ASH_GATHER_COUNT, 2000
	applymovement 26, Common_Movement_FaceRight
	waitmovement 26
	call LCC_Magma_PoisonWater3
	setvar VAR_RYU_MAGMA, 180@Player poisoned last spot of ocean
	msgbox LCC_GoFindBlaise
	closemessage
	release
	end
	
LCC_MagmaGruntNotReady:
	msgbox LCC_GoFindTheOther
	release
	end
	
LCC_DrawMapAndDelay::
	special DrawWholeMapView
	delay 20
	return
	
LCC_Magma_PoisonWater1::
	setmetatile 73, 14, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 74, 14, 369, 0
	setmetatile 72, 14, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 73, 13, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 75, 15, 369, 0
	setmetatile 75, 16, 369, 0
	setmetatile 75, 17, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 74, 14, 369, 0
	setmetatile 75, 14, 369, 0
	setmetatile 76, 14, 369, 0
	setmetatile 76, 15, 369, 0
	setmetatile 76, 16, 369, 0
	setmetatile 76, 17, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 72, 14, 369, 0
	setmetatile 71, 14, 369, 0
	setmetatile 70, 14, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 69, 14, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 68, 14, 369, 0
	setmetatile 68, 15, 369, 0
	setmetatile 69, 15, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 68, 13, 369, 0
	setmetatile 69, 13, 369, 0
	setmetatile 70, 13, 369, 0
	setmetatile 71, 13, 369, 0
	setmetatile 72, 13, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 73, 13, 369, 0
	setmetatile 74, 13, 369, 0
	setmetatile 75, 13, 369, 0
	setmetatile 76, 13, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 67, 13, 369, 0
	setmetatile 67, 12, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 66, 13, 369, 0
	setmetatile 66, 12, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 65, 13, 369, 0
	setmetatile 65, 12, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 65, 12, 369, 0
	setmetatile 66, 12, 369, 0
	setmetatile 67, 12, 369, 0
	setmetatile 68, 12, 369, 0
	setmetatile 69, 12, 369, 0
	setmetatile 70, 12, 369, 0
	setmetatile 71, 12, 369, 0
	setmetatile 72, 12, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 65, 11, 369, 0
	setmetatile 66, 11, 369, 0
	setmetatile 67, 11, 369, 0
	setmetatile 68, 11, 369, 0
	setmetatile 69, 11, 369, 0
	setmetatile 70, 11, 369, 0
	setmetatile 71, 11, 369, 0
	setmetatile 72, 11, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 77, 13, 369, 0
	setmetatile 77, 14, 369, 0
	setmetatile 77, 15, 369, 0
	setmetatile 77, 16, 369, 0
	setmetatile 77, 17, 369, 0
	setmetatile 77, 18, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 75, 18, 369, 0
	setmetatile 76, 18, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 65, 14, 369, 0
	setmetatile 66, 14, 369, 0
	call LCC_DrawMapAndDelay
	return
	
LCC_Magma_PoisonWater2::
	setmetatile 65, 13, 369, 0
	setmetatile 66, 14, 369, 0
	setmetatile 67, 14, 369, 0
	setmetatile 68, 14, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 67, 9, 369, 0
	setmetatile 68, 9, 369, 0
	setmetatile 69, 9, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 68, 8, 369, 0
	setmetatile 69, 8, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 68, 7, 369, 0
	setmetatile 69, 7, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 65, 10, 369, 0
	setmetatile 66, 10, 369, 0
	setmetatile 67, 10, 369, 0
	setmetatile 68, 10, 369, 0
	setmetatile 69, 10, 369, 0
	setmetatile 70, 10, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 63, 11, 369, 0
	setmetatile 64, 11, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 63, 12, 369, 0
	setmetatile 64, 12, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 63, 13, 369, 0
	setmetatile 64, 13, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 70, 6, 369, 0
	setmetatile 70, 7, 369, 0
	setmetatile 70, 8, 369, 0
	setmetatile 70, 9, 369, 0
	setmetatile 70, 10, 369, 0
	call LCC_DrawMapAndDelay
	return
	
LCC_Magma_PoisonWater3::
	setmetatile 66, 33, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 66, 32, 369, 0
	setmetatile 66, 34, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 66, 35, 369, 0
	setmetatile 66, 30, 369, 0
	setmetatile 66, 31, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 67, 30, 369, 0
	setmetatile 67, 31, 369, 0
	setmetatile 67, 32, 369, 0
	setmetatile 67, 33, 369, 0
	setmetatile 67, 34, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 68, 29, 369, 0
	setmetatile 68, 30, 369, 0
	setmetatile 68, 31, 369, 0
	setmetatile 68, 32, 369, 0
	setmetatile 68, 33, 369, 0
	setmetatile 68, 34, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 69, 28, 369, 0
	setmetatile 69, 29, 369, 0
	setmetatile 69, 30, 369, 0
	setmetatile 69, 31, 369, 0
	setmetatile 69, 32, 369, 0
	setmetatile 69, 33, 369, 0
	setmetatile 69, 34, 369, 0
	setmetatile 69, 35, 369, 0
	call LCC_DrawMapAndDelay
	setmetatile 70, 26, 369, 0
	setmetatile 70, 27, 369, 0
	setmetatile 70, 28, 369, 0
	setmetatile 70, 29, 369, 0
	setmetatile 70, 30, 369, 0
	setmetatile 70, 31, 369, 0
	setmetatile 70, 32, 369, 0
	setmetatile 70, 33, 369, 0
	setmetatile 70, 34, 369, 0
	setmetatile 70, 35, 369, 0
	call LCC_DrawMapAndDelay
	return
	
LCC_Blaise::
	msgbox LCC_AhThereYouAre
	closemessage
	applymovement 27 Common_Movement_StepUp
	waitmovement 27
	playse SE_DOOR
	waitse
	removeobject 27
	setflag FLAG_RYU_MAGMA_LILYCOVE
	setvar VAR_RYU_MAGMA, 185@player met with Blaise by harbor
	setflag LCC_MAGMA_HARBOR_REPORTERS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOOR
	warpsilent MAP_LILYCOVE_CITY_HARBOR_STORY, 0, 11, 14
	waitstate
	release
	end
	
LCC_WhatThe:
	.string "What the-! Why're Team Magma on our\n"
    .string "turf!?\p"
    .string "Grunt: You don't want to know,\n"
	.string "so beat it!$"

LCC_ITakeIt:
	.string "I take it you've got the stuff?\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} hands over 2000 grams\n"
    .string " of the ash.)$"

LCC_ThisIsGoing:
	.string "This is going to be sweet...by the\n"
    .string "way, there are 3 other spots to\p"
    .string "place ash in, 2 of which are just\n"
    .string "along the bank here. I didn't catch\p"
    .string "where the last location was, but it's\n"
    .string "gotta be connected to water somehow\p"
    .string "right?$"

LCC_ReadyWhenYouAre:
	.string "Ready when you are.\p"
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} hands over 2000 more\n grams of ash.)$"

LCC_ThisShouldBe:
	.string "This should be a good spot.\p"
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} gives up another 2000 grams\n of the ash.)$"
	
LCC_GoFindBlaise:
	.string "You should go find Blaise\nnow. He said something about\la dock.$"
	
LCC_AhThereYouAre:
	.string "Ah, there you are, come on in.$"
	
LCC_GoFindTheOther:
	.string "Go find the other grunt.\nWe should do this in order.$"
	
LCC_AquaGruntRunsAway:
	walk_down
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	step_end

	
	
	
	













