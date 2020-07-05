Route114_LanettesHouse_Basement_MapScripts::
	MAP_SCRIPT ON_FRAME, Ryu_LNH_RomScene
	.byte 0
	
Ryu_LNH_RomScene::
	map_script_2 VAR_RYU_LANETTE_VAR, 105, Ryu_LNH_RomSceneStart
	map_script_2 VAR_TEMP_7, 0, Ryu_LNH_CheckObjectXY
	.2byte 0
	
Ryu_LNH_CheckObjectXY::
	lock
	setvar VAR_TEMP_7, 20
	call_if_set FLAG_RYU_DS_LANETTE_PARTNERS, LNH_SetLanetteXY
	release
	end
	
LNH_SetLanetteXY:
	setobjectxy 1, 0, 5
	applymovement 1, Common_Movement_FaceRight
	return
	release
	end
	
Ryu_LNH_RomSceneStart::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	setvar VAR_RYU_LANETTE_VAR, 0
	setobjectxy 1, 10, 6
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	delay 10
	applymovement 1, Common_Movement_StepLeft
	waitmovement 1
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	msgbox LNH_StayingNightPartners
	closemessage
	fadescreen 1
	special HealPlayerParty
	clearflag FLAG_RYU_HIDE_LANETTE_BASEMENT
	setobjectxy 1, 0, 5
	applymovement 1, Common_Movement_FaceRight
	waitmovement 1
	delay 50
	msgbox LNH_OnceAgainCoffee
	closemessage
	fadescreen 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, LNH_ExitBed
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	msgbox LNH_SheLooksBusy
	closemessage
	setflag FLAG_RYU_DS_LANETTE_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	setflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	clearflag FLAG_RYU_HIDE_LANETTE_BASEMENT
	release
	end
	
LNH_AfterStory::
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, ryu_end
	lock
	msgbox LNH_StayingNightAfterStory
	closemessage
	applymovement 1, LNH_AS_LanetteToBed
	applymovement OBJ_EVENT_ID_PLAYER, LNH_AS_PlayerToBed
	waitmovement 1
	waitmovement OBJ_EVENT_ID_PLAYER
	fadescreen 1
	fadenewbgm MUS_DUMMY
	delay 5
	msgbox LNH_AS_InBedMsg
	closemessage
	delay 50
	special HealPlayerParty
	setobjectxy 1, 0, 5
	applymovement 1, Common_Movement_FaceRight
	waitmovement 1
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LNH_AS_YouWakeUp
	closemessage
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_PLAYER, LNH_ExitBed
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 1, LNH_MoveToPlayerFromPCDesk
	waitmovement 1
	setflag FLAG_RYU_HIDE_LANETTE_BASEMENT
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	goto_if_set FLAG_RYU_RECIEVED_ROTOM, LNH_WaitHowIsRotom
	msgbox LNH_Rotom
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LNH_GiveRotomFullParty
	closemessage
	givemon SPECIES_ROTOM, 21, ITEM_NONE
	playfanfare MUS_FANFA4
	msgbox LNH_ReceivedRotom
	waitfanfare
	setflag FLAG_RYU_STAYED_2_NIGHTS_AT_LANETTE
	setflag FLAG_RYU_RECIEVED_ROTOM
	release
	end

LNH_Rotom:
    .string "Lanette:{COLOR LIGHT_RED}{SHADOW RED} I have a gift for you!\p"
    .string "It's a special pokemon that can\n"
    .string "change forms!\p"
    .string "You can talk to me upstairs and I\n"
    .string "can change it's form for you.$"


LNH_ReceivedRotom:
	.string "{PLAYER} received a Rotom!$"

LNH_WaitHowIsRotom::
	msgbox LNH_HowIsRotomMsg
	setflag FLAG_RYU_HIDE_LANETTE_BASEMENT
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

LNH_HowIsRotomMsg:
	.string "Wait, how is Rotom doing?\pI see, well talk to me upstairs\lsometime to change its form!$"

LNH_GiveRotomFullParty::
	msgbox GiveRotomInPc
	givemon SPECIES_ROTOM, 21, ITEM_NONE
	playfanfare MUS_FANFA4
	setflag FLAG_RYU_DS_LANETTE_PARTNERS
	setflag FLAG_RYU_RECIEVED_ROTOM
	release
	end

GiveRotomInPc:
	.string "I've sent Rotom to your PC\nbecause your party is full!$"

LNH_MoveToPlayerFromPCDesk:
	emote_exclamation_mark
	walk_up
	walk_right
	walk_up
	step_end

RF_LanetteSetupFollower:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lanette: Can I roam around with\nyou, please?\lI'm bored!$"

LNH_Follower::
	createfollower OBJ_EVENT_GFX_WOMAN_2, RyuFollowerSelectNPCScript, DIR_NORTH
	setvar VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_WOMAN_2
	setflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	setflag FLAG_RYU_HIDE_LANETTE_BASEMENT
	setflag FLAG_RYU_HAS_FOLLOWER
	removeobject 1
	release
	end
	
LNH_BasementScene::
	goto_if_set FLAG_RYU_DS_LANETTE_ACQ, LNH_Acquaintance
	lock
	goto_if_set FLAG_RYU_LANETTE_EVENT1, LNH_Basement2
	goto_if_unset FLAG_RYU_LANETTE_EVENT_0, LNH_ShouldntBeHere
	addobject 1
	clearflag FLAG_RYU_HIDE_LANETTE_BASEMENT
	applymovement OBJ_EVENT_ID_PLAYER, LNH_ToLanetteBasement
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LNH_LanetteDialog2 MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LNH_HelpLanette
	goto LNH_WaitForLanette
	
LNH_Acquaintance::
	goto_if_set FLAG_TEMP_3, ryu_end
	msgbox LNH_Busy
	closemessage
	setflag FLAG_TEMP_3
	release
	end
	
LNH_ShouldntBeHere:
	msgbox LNH_ShouldntBeHereMsg
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
LNH_ShouldntBeHereMsg:
    .string "This seems like a private space.\n"
    .string "You should probably leave.$"
	
LNH_Busy:
	.string "Lanette: I'm very busy right now.\n"
	.string "Can you come back later?$"

	
LNH_Basement2::
	goto_if_set FLAG_RYU_DS_LANETTE_LOVERS, ryu_end
	release
	end
	
LNH_WaitForLanette::
	msgbox LNH_JustAMoment
	closemessage
	delay 60
	applymovement 1, LNH_ToPlayer
	waitmovement 1
	msgbox LNH_SorryFor
	closemessage
	msgbox LNH_JustChecking
	closemessage
	msgbox LNH_OkayHi
	closemessage
	applymovement 1, LNH_LanetteToDesk
	waitmovement 1
	setflag FLAG_RYU_DS_LANETTE_ACQ
	setflag FLAG_RYU_DS_LANETTE_BADEND
	release
	end
	
LNH_HelpLanette::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LNH_ToLanette
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LNH_HelpGetUp
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LNH_Help1
	applymovement 1, LNH_Help2
	waitmovement 1
	msgbox LNH_looksflushed
	setflag FLAG_RYU_DS_LANETTE_LOVERS
	closemessage
	applymovement 1, Common_Movement_FaceUp
	waitmovement 1
	applymovement 1, Common_Movement_FaceRight
	msgbox LNH_tryingToMakeBed
	closemessage
	applymovement 1, Common_Movement_FaceUp
	waitmovement 1
	msgbox LNH_tryingToMakeBed2
	closemessage
	applymovement 1, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 1, LNH_ToBed1
	applymovement OBJ_EVENT_ID_PLAYER, LNH_ToBed2
	waitmovement OBJ_EVENT_ID_PLAYER
	fadenewbgm MUS_DUMMY
	fadescreen 1
	delay 80
	msgbox LNH_YouFeelLanette
	closemessage
	special HealPlayerParty
	msgbox LNH_driftofftosleep
	closemessage
	delay 80
	fadenewbgm MUS_TONEKUSA
	removeobject 1
	msgbox LNH_AsYouWakeUp
	fadescreen 0
	closemessage
	setflag FLAG_RYU_LANETTE_EVENT1
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

LNH_StayingNightAfterStory:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lanette: Unfortunately, I don't\n"
    .string "have any new movies for us to\p"
    .string "watch, so I guess I will just\n"
    .string "have to entertain you, myself...\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: I like where this is\n"
    .string "going. I hope I can keep up...$"
	
LNH_AS_InBedMsg:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Lanette: I've been studying male\n"
    .string "anatomy. I think I know exactly\l"
    .string "which buttons to press and when.\p"
	.string "... ... ... ...\p"
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She does indeed. You feel like\n"
    .string " you're not going to get very much\l"
    .string " sleep tonight...)$"
	
LNH_AS_YouWakeUp:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Somehow, you wake up feeling\n"
    .string " more tired than when you came\l"
    .string " here last night.)$"


LNH_JustChecking:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: No, not really.\p"
	.string "I was just stopping by to say hi.$"
	
LNH_OkayHi:
	.string "Lanette:{COLOR LIGHT_RED}{SHADOW RED} Okay, Hi. But I'm in a\n"
	.string "time crunch right now, I don't\l"
	.string "really have time to talk.$"
	
LNH_OnceAgainCoffee:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You once again awake to the smell\n"
    .string " of fresh brewed hot coffee.)$"

LNH_SheLooksBusy:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She looks rather busy. You should\n"
    .string " probably leave her to her work.)$"

LNH_StayingNightPartners:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I doubt we'll get all the way\n"
    .string "through the movie, though.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She smiles as she unbuttons\n"
	.string " her dress)\p"
    .string " (Lanette changes into her\p"
    .string " favorite night shirt. You also get\n"
    .string " the feeling you won't be watching\l"
    .string " the tv.)$"
	
LNH_LanetteDialog2:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (It looks like Lanette is having\n"
    .string " a moment of clumsiness. She\l"
    .string " might prefer not to be bothered.)\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Run to her aid?$"
	
LNH_SorryFor:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh, Hi, sorry. I was a little\n"
    .string "pre-occupied. Is there something\l"
    .string "I can help you with?$"
	
LNH_JustAMoment:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You hear Lanette shout.)\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Lanette: {COLOR LIGHT_RED}{SHADOW RED}Is someone there?\n"
    .string "Please wait a moment, I'll be\l"
    .string "right with you!$"
	
LNH_HelpGetUp:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} ({PLAYER} grabs Lanette's hand\n"
    .string " and helps her get up.)$"
	
LNH_looksflushed:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She looks thoroughly flushed.)\p"
    .string " (Lanette isn't meeting your gaze\n"
    .string " and hasn't let go of your hand.)$"
	
LNH_tryingToMakeBed:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I... \p"
    .string "... ... ... ...\p"
    .string "...I was just trying to make my\n"
    .string "bed, and my foot got tangled in\p"
    .string "the sheet and I lost my balance\l"
    .string "and...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}{PLAYER}:{COLOR LIGHT_BLUE}{SHADOW BLUE} Don't worry about it.\p"
    .string "Are you okay?$"
	
LNH_tryingToMakeBed2:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} ({PLAYER} squeezes Lanette's\n"
    .string " hand.)\p"
    .string " (Lanette seems to visibly calm\n"
    .string " down.)\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Y... Yes, I'm okay.\p"
    .string "Thanks for helping me.\p"
    .string "I was just about to take a nap.\p"
    .string "Would.... you like to take a nap\n"
    .string "with me?\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}{PLAYER}: {COLOR LIGHT_BLUE}{SHADOW BLUE}Yeah, okay. I was getting\n"
    .string "sleepy from walking around all day\l"
    .string "anyways.\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (Her face flushes again.)\p"
    .string "{COLOR LIGHT_RED}{SHADOW RED}Oh... Okay, let's do it then!\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} ({PLAYER} and Lanette climb into\n"
    .string " the large bed.)$"
	
LNH_YouFeelLanette:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You feel Lanette slide closer\n"
    .string " to you on the bed. She's very\l"
    .string " warm)\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Lanette:{COLOR LIGHT_RED}{SHADOW RED} I'm sorry if I'm wierd.\n"
    .string "You see, I didn't really talk to\p"
    .string "many people. I'm an introvert,\n"
    .string "human contact in open spaces makes\p"
    .string "me really nervous, and I start\n"
    .string "to get anxious, and can't talk...\p"
	.string "and well...\p"
    .string "It's different with you. I always\n"
    .string "feel comfortable with you, I'm\l"
    .string "not sure why...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}{PLAYER}: {COLOR LIGHT_BLUE}{SHADOW BLUE}I'm okay with that.\n"
    .string "It just means I get to keep you\l"
    .string "all to myself.\p"
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (Lanette squeezes you tighter\n"
    .string " and your heart threatens to jump\l"
    .string " out of your throat.)$"


LNH_driftofftosleep:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and Lanette drift off\n"
    .string " into the sweet bliss of nothing-\l"
    .string " ness in each other's arms...)$"


LNH_AsYouWakeUp:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (As you come to consciousness,\n"
    .string " you smell the scent of coffee waft-\l"
    .string " ing over from the other room.)$"
	
LNH_AS_LanetteToBed:
	delay_16
	delay_16
	delay_8
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_right
	step_end
	
LNH_AS_PlayerToBed:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end
	
	
LNH_LanetteToDesk:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_right
	step_end
	
LNH_ExitBed:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_down
	step_end

LNH_ToPlayer:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
LNH_ToLanetteBasement:
	walk_in_place_right
	step_end
	
LNH_ToBed1:
	walk_left
	walk_left
	walk_in_place_down
	step_end
	
LNH_ToBed2:
	delay_8
	walk_down
	walk_left
	walk_in_place_down
	step_end
	
LNH_ToLanette:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fastest_down
	step_end
	
LNH_Help1:
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	step_end
	
LNH_Help2:
	delay_8
	delay_4
	face_left
	face_up
	walk_in_place_fast_up
	emote_heart
	step_end
	
	

