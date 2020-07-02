LilycoveCity_AquaCorporateOffice_MapScripts::
	.byte 0

LC_AH_Security1::
	goto_if_set FLAG_RYU_AQUA_BAD_END, LC_AH_BADEND
	goto_if_set FLAG_RYU_STARTING_M4, LC_AH_SecurityStop3
	goto_if_set FLAG_RYU_STARTING_M3, LC_AH_SecurityStop2
    goto_if_set FLAG_RYU_PLAYER_HELPING_DEVON, LC_AH_SecurityStop
	goto_if_set FLAG_RYU_PLAYER_HELPING_AQUA, ryu_end
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, LC_AH_SecurityStop
	goto_if_unset FLAG_RECOVERED_DEVON_GOODS, LC_AH_SecurityStop
	setflag FLAG_LANDMARK_AQUA_OFFICE
	msgbox AH_WorkForAqua MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne AH_LEAVING_NOSTART
	msgbox LC_AH_Welcome MSGBOX_DEFAULT
	waitmessage
	addobject 7
	applymovement 7 LC_AH_Shelly_move
	waitmovement 0
	msgbox LC_AH_ShellyQuery MSGBOX_YESNO
	compare VAR_RESULT 0
	goto_if_eq LC_AH_Leave
	removeitem ITEM_DEVON_GOODS 1
	msgbox LC_AH_TS_Given MSGBOX_DEFAULT
	waitmessage
	msgbox LC_AH_Shelly_Welcome MSGBOX_DEFAULT
	additem ITEM_EXPERT_BELT
	playfanfare MUS_FANFA4
	call RyuGivePokenav
	givemoney 50000
	msgbox LC_AH_Pokenav_get MSGBOX_DEFAULT
	closemessage
	msgbox LC_AH_JobOffer MSGBOX_DEFAULT
	closemessage
	msgbox LC_AH_JoinQuery
	closemessage
	msgbox LC_AH_Shelly_desc MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RYU_PLAYER_HELPING_AQUA
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	applymovement 7 LC_AH_Shelly_leave
	waitmovement 0
	removeobject 7
	release
	end

LC_AH_BADEND::
	applymovement 5, ForcePlayerOut
	applymovement OBJ_EVENT_ID_PLAYER, ForcedOut
	msgbox forciblyThrownOut
	closemessage
	warpsilent MAP_LILYCOVE_CITY, 15, 49, 8
	release
	end

forciblyThrownOut:
	.string "You were banned from this\npremises by our administrator.\pDo Not Return!$"

ForcePlayerOut:
	delay_8
	walk_right
	face_down
	walk_down
	walk_down
	step_end

ForcedOut:
	face_down
	walk_down
	walk_down
	step_end


AH_WorkForAqua:
	.string "Are you sure you want to\nstart this line?\pYou won't be able to complete\nany other line if you do!$"

AH_LEAVING_NOSTART::
	warpsilent MAP_LILYCOVE_CITY, 255, 49, 9
	release
	end
	
LC_AH_Guard::
	lockall
	faceplayer
	getplayerxy VAR_TEMP_9, VAR_TEMP_8
	compare VAR_TEMP_9, 15
	goto_if_gt LC_MoveGuard
	msgbox LCGuard MSGBOX_DEFAULT
	release
	end

LC_MoveGuard::
	applymovement 3, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	msgbox LC_Guard_Exit
	closemessage
	applymovement 3, LC_GuardMoves
	waitmovement 3
	applymovement OBJ_EVENT_ID_PLAYER, LC_ExitAroundGuard
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 3, LC_GuardReturns
	waitmovement 3
	release
	end

	
LCGuard:
	.string "Guard: This area is off limits.\p"
	.string "You can't come through.$"

LC_Guard_Exit::
	.string "You're so lucky... I could never\n"
	.string "get her to even notice me...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The guard grumbles some more...)$"

LC_GuardMoves:
	walk_left
	walk_left
	face_right
	step_end

LC_ExitAroundGuard:
	walk_left
	walk_left
	walk_down
	walk_down
	face_up
	step_end

LC_GuardReturns:
	walk_right
	walk_right
	face_left
	step_end
	
LC_AH_SecurityStop3::
	msgbox LC_AH_OnWay4 MSGBOX_DEFAULT
	setvar VAR_MT_PYRE_STATE, 2
    settrainerflag TRAINER_GRUNT_MT_PYRE_1
    settrainerflag TRAINER_GRUNT_MT_PYRE_2
    settrainerflag TRAINER_GRUNT_MT_PYRE_3
    settrainerflag TRAINER_GRUNT_MT_PYRE_4
	cleartrainerflag TRAINER_MAXIE_3
	cleartrainerflag TRAINER_COURTNEY_3
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_PlayerLeave
	waitmovement 0
	release
	end
	
LC_AH_SecurityStop2::
	call_if_set FLAG_RYU_STARTING_M3, LC_AH_SETUPM3
	msgbox LC_AH_OnWayM3 MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_PlayerLeave
	waitmovement 0
	release
	end

LC_AH_SETUPM3::
	goto_if_set FLAG_RYU_AQUA_MISSION3COMPLETE, ryu_return
	setvar VAR_JAGGED_PASS_STATE, 1
	return
	
LC_AH_SecurityStop::
	msgbox LC_AH_KickedOut MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_PlayerLeave
	waitmovement 0
	release
	end
	
LC_AH_Shelly::
	goto_if_set FLAG_RYU_AQUA_LINE_DONE, LC_AH_AfterStoryNoRel
	goto_if_set FLAG_RYU_MISSION4COMPLETE, LC_AH_NoRelConclusion
	goto_if_set FLAG_RYU_AQUA_MISSION3COMPLETE, LC_AH_Mission4
	goto_if_set FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, LC_AH_Mission3Done
	goto_if_set FLAG_RYU_AQUA_MISSION2REWARDED, LC_AH_mission3
	goto_if_set FLAG_RYU_AQUA_MISSION2COMPLETE, LC_AH_Mission2Complete
	goto_if_set FLAG_RYU_AQUA_MISSION1REWARDED, LC_AH_Mission2
	goto_if_set FLAG_RYU_AQUA_MISSION1COMPLETE, LC_AH_Shelly_FinishedMission1
	goto_if_set FLAG_RYU_AQUA_INTRO, LC_AH_ShellyIntroDoneFirstMission
	goto_if_set FLAG_RYU_PLAYER_ARCHIE_ACQ, LC_AH_ArchieRecruitIntro
	settrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_1
	settrainerflag TRAINER_GRUNT_2
	settrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_3
	settrainerflag TRAINER_GRUNT_21
	settrainerflag TRAINER_GRUNT_25
	settrainerflag TRAINER_GRUNT_4
	settrainerflag TRAINER_GRUNT_22
	settrainerflag TRAINER_GRUNT_26
	msgbox LC_AH_mission1Shelly MSGBOX_DEFAULT
	clearflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_RYU_AQUA_INTRO
	clearflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	setvar VAR_METEOR_FALLS_STATE, 2
	release
	end
	
LC_AH_ArchieRecruitIntro:
    msgbox LC_AH_mission1 MSGBOX_DEFAULT
	clearflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_RYU_AQUA_INTRO
	clearflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	setvar VAR_METEOR_FALLS_STATE, 2

LC_AH_ShellyIntroDoneFirstMission:
	msgbox LC_AH_MissionRemindMsg MSGBOX_DEFAULT
	release
	end

LC_AH_Leave::
	msgbox LC_AH_NoReward MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_PlayerLeave
	waitmovement 0
	release
	end
	
LC_AH_Declined::
	msgbox LC_AH_NoJoin MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_PlayerLeave
	waitmovement 0
	release
	end
	
LC_AH_AfterStoryNoRel::
	goto_if_set FLAG_RYU_DS_SHELLY_PARTNERS, LC_AH_ShellyRelScene
	msgbox LC_AH_AfterStoryNoRelMsg MSGBOX_DEFAULT
	release
	end
	
LC_AH_PlayerLeave:
	walk_down
	step_end
	
LC_AH_Shelly_move:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
	
LC_AH_Shelly_leave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
LC_AH_MissionRemindMsg:
    .string "You should be heading to Meteor\n"
    .string "Falls by now. Hop to it, recruit!$"
	
LC_AH_AfterStoryNoRelMsg:
	.string "Shelly: We've achieved our goal\nfor eternal rain, soon\lthe world will be overrun by\nwater!\pIt's time to celebrate!$"
	
LC_AH_mission1Shelly:
	.string "Anyways, your first mission will\nbe at Meteor Falls.\pI just need you to go there and\nprovide some assistance to our operatives\lin the field.$"
	
LC_AH_Welcome:
	.string "Welcome to the Aqueus Corporation.\p"
	.string "What brings you here?\n"
	.string "... ... ... ...\p"
    .string " {PLAYER} showed the Devon package.\n"
	.string "One moment.\p"
	.string "The administrator is on her way.$"
	
LC_AH_ShellyQuery:
	.string "Shelly: Where'd you get that?\p"
	.string "... ... ... ...\n"
	.string "Figures. Soldiers being useless as ever.\p"
	.string "Well since you brought it here, do you\n"
	.string "want to trade it in for a reward?$"
	
LC_AH_TS_Given:
	.string "Good choice. This LIDAR system will make\p"
	.string "our underwater expeditions a breeze!\n"
	.string "Here's your reward for supporting\p"
	.string "our cause.$"
	
LC_AH_Shelly_Welcome:
	.string "Shelly: You should probably avoid Devon\p"
	.string "Corp. They'll likely send thugs after you\n"
    .string "for taking their trade secret.$"
	
LC_AH_Pokenav_get:
	.string "I just gave you a Pokenav.\p"
	.string "you'll need it to stay in contact\n"
	.string "with us and others.$"
	
LC_AH_JobOffer:
    .string "We'll keep you on retainer for work here,\n"
	.string "with a sign on bonus of ¥50000.$"
	
LC_AH_JoinQuery:
	.string "Let's create a little chaos.$"
	
LC_AH_Shelly_desc:
	.string "Welcome to Team Aqua. You'll\p"
	.string "report directly to me. Perform well,\n"
	.string "and there's more rewards in it for you.$"
	
LC_AH_KickedOut:
	.string "You can't be here. You're not an employee.$"
	
LC_AH_NoReward:
	.string "I hope you change your mind.\p"
	.string "The reward is a unique Item\n"
	.string "that could give you an edge in all battles.$"
	
LC_AH_NoJoin:
	.string "That's too bad, I think we'd have\p"
	.string "made a good team.$"

@==================================================================================================Mission Scripts

	
 LC_AH_Shelly_FinishedMission1::
	msgbox LC_AH_M1CompleteMsg MSGBOX_DEFAULT
	givemoney 10000
	msgbox LC_AH_M1RewardMsg MSGBOX_DEFAULT
	setflag FLAG_RYU_AQUA_MISSION1REWARDED
	release
	end
	
LC_AH_Mission2::
	msgbox LC_AH_Shelly_mission2msg MSGBOX_DEFAULT
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	clearflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	release
	end
	
LC_AH_Mission2Complete::
	msgbox LC_AH_Mcomplete2 MSGBOX_DEFAULT
	closemessage
	applymovement 1, LC_AH_AroundDesk
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_FaceUp
	waitmovement 0
	additem ITEM_RARE_CANDY, 10
	msgbox LC_AH_m2Reward MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RYU_AQUA_MISSION2REWARDED
	goto_if_set FLAG_RYU_PLAYER_AQUA_NECKLACE, LC_AH_ShellyGiftQuery
	applymovement 1, LC_AH_ShellyReturnToDesk
	waitmovement 0
	release
	end
	
LC_AH_mission3::
	msgbox LC_AH_M3Desc MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RYU_STARTING_M3
	applymovement OBJ_EVENT_ID_PLAYER, LH_M3Exit
	waitmovement 0
	setvar VAR_JAGGED_PASS_STATE, 1
	warpsilent MAP_LILYCOVE_CITY, 15, 49, 8
	release
	end
	
LC_AH_Mission3Done::
	msgbox LC_AH_M3DoneMsg MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL, 1
	msgbox LC_AH_M3DoneMsg2 MSGBOX_DEFAULT
	setflag FLAG_RYU_AQUA_MISSION3COMPLETE
	release
	end

LC_AH_Mission4::
	goto_if_set FLAG_RYU_DS_SHELLY_CLOSEFRIENDS, LC_AH_M4Reldesc
	msgbox LC_AH_M4DescMsg MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LH_M3Exit
	waitmovement 0
	setvar VAR_MT_PYRE_STATE, 2
    settrainerflag TRAINER_GRUNT_MT_PYRE_1
    settrainerflag TRAINER_GRUNT_MT_PYRE_2
    settrainerflag TRAINER_GRUNT_MT_PYRE_3
    settrainerflag TRAINER_GRUNT_MT_PYRE_4
	cleartrainerflag TRAINER_MAXIE_3
	cleartrainerflag TRAINER_COURTNEY_3
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	release
	end
	
LC_AH_NoRelConclusion::
	goto_if_set FLAG_RYU_DS_SHELLY_PARTNERS, LC_AH_ShellyRelScene
	applymovement 1, LC_AH_AroundDesk
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_FaceUp
	waitmovement 0
	additem ITEM_CARD_KEY, 1
	msgbox LC_AH_ShellyGivesCardKey MSGBOX_DEFAULT
	msgbox LC_AH_ArchieWasSuccessful MSGBOX_DEFAULT
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	setflag FLAG_RYU_AQUA_LINE_DONE
	setflag FLAG_RYU_ARCHIE_SUCCESSFUL
	setflag FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW
	clearflag FLAG_RYU_KYOGRE
	release
	end
	
LC_AH_ShellyGivesCardKey:
	.string "Shelly: I was instructed by Archie\nto give this to you.\pIt names you as commander of\nAqua's Hideout, and entitles you to\lanything you want, inside.$"
	
LC_AH_ArchieWasSuccessful:
	.string "Since Archie successfully got Kyogre\nto call the long rain, You can have\lit.\pKyogre's purpose has been served, so\nnow it's yours.\pYou will find it also in the Aqua hideout.$"
	
LC_AH_mission1:
    .string "Shelly: Hey there, new recruit.\p"
    .string "I understand you have a package for\n"
    .string "me? I'll take that now.\p"
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} handed the package over.)\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}All right. So...\p"
	.string "Your first mission is to go to\n" 
	.string "Meteor Falls and assist Archie's\p"
	.string "investigation. We can't have team\n"
	.string "Magma mucking about.$"
	
LC_AH_M1CompleteMsg:
	.string "Shelly: What were they up to over there?\n"
	.string "... ... ... ... ... ...\p"
	.string "I see. Well, I'm glad you stopped them. It\n"
	.string "sounds like they're trying to awaken the\p"
	.string "legendary Groudon to accomplish their\n"
	.string "goals. This isn't good. Nice work, soldier.$"
	
LC_AH_M1RewardMsg:
	.string "Here's your payment for completing the\n"
	.string "job.\p"
	.string "p10,000.  This should be sufficient.$"
	
LC_AH_Shelly_mission2msg:
	.string "Okay, your next mission is to meet \n"
	.string "Archie at Mt Chimney, and help stop\p"
	.string "what Magma's getting into there.\p"
	.string "They are definetely up to no good.$"

LC_AH_Mcomplete2:
	.string "Hello, Lt. {PLAYER}. Welcome back.\n"
	.string "It appears we're equals now. $"
	
LC_AH_m2Reward:
	.string "Here's the payout for the last mission.\p"
	.string "I'm researching some important info\n"
	.string "about Kyogre, right now. \p"
	.string "I'll see if there's anything you can do\n"
	.string "in the meantime.$"
	
LC_AH_M3Desc:
	.string "All right, so we've discovered what\n"
	.string "Magma is up to. It's bad. Really bad.\p"
	.string "We need to go to Magma's hideout\n"
	.string "in Jagged Pass, and stop them. I'll\p"
	.string "meet you there.$"
	
LC_AH_M4DescMsg:
	.string "Archie is currently at Mt.Pyre\n"
	.string "working on getting the blue orb.\l"
	.string "I need you to go there and deal\l"
	.string "with Maxie when he shows up. No\l"
	.string "doubt he'll also have his pet\l"
	.string "Courtney with him.\l"
	.string "You might have to fight them\l"
	.string "both.\l"
	.string "It'll be a hard fight but I think\l"
	.string "you'll manage. Once you get done\l"
	.string "with them, talk to Archie to see\l"
	.string "if he has anything else for you\l"
	.string "to do.$"
	
LC_AH_M3DoneMsg:
	.string "Shelly: We barely averted the\ndisaster that would have been if\lGroudon was awakened by the wrong\lperson.\lYou might be able to\lcontrol it, actually. You should\lgive it a try sometime.$"
	
LC_AH_M3DoneMsg2:
	.string "I found this hiding in their base\p"
	.string "while I was scouting it out. You\n"
	.string "can probably put it to better use\l"
	.string "than us.$"
	
LC_AH_OnWayM3:
	.string "Our administrator asked to not be\n"
	.string "bothered while she's preparing to\p"
	.string "go to Jagged Pass.$"
	
LC_AH_OnWay4:
	.string "Our administrator asked to not be\n"
	.string "bothered while she's preparing to\p"
	.string "go to Mt.Pyre$"
	
LH_M3Exit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

LC_AH_AroundDesk:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_down
	face_down
	step_end

LC_AH_ShellyReturnToDesk:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	face_left
	step_end

LC_AH_FaceUp:
	walk_in_place_up
	step_end
	
LC_faceright:
	walk_in_place_right
	step_end

@==================================================================================================Relationship Scripts

ShellyRelCheck1::
	goto_if_set FLAG_RYU_PLAYER_AQUA_NECKLACE, LC_AH_ShellyGiftQuery
	goto_if_set FLAG_RYU_DS_SHELLY_ACQ, LC_AH_NoGift
	return


LC_AH_ShellyGiftQuery::
	goto_if_set FLAG_RYU_DS_SHELLY_FRIENDS, ryu_end
	msgbox LC_AH_M1RelGiftDialog MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LC_AH_NoGift
	msgbox LC_AH_GiftGiven MSGBOX_DEFAULT
	applymovement 1, egc_heart
	waitmovement 0
	msgbox LC_AH_ShellyThanks MSGBOX_DEFAULT
	applymovement 1, LC_AH_ShellyReturnToDesk
	waitmovement 0
	setflag FLAG_RYU_DS_SHELLY_FRIENDS
	clearflag FLAG_RYU_PLAYER_AQUA_NECKLACE
	release
	end
	
LC_AH_NoGift::
	goto_if_set FLAG_RYU_DS_SHELLY_ACQ, LC_AH_mission3
	msgbox LC_AH_NoGiftMsg MSGBOX_DEFAULT
	setflag FLAG_RYU_DS_SHELLY_ACQ
	clearflag FLAG_RYU_PLAYER_AQUA_NECKLACE
	release
	end

LC_AH_DeclinedShelly::
	msgbox LC_AH_ShellyDispt MSGBOX_DEFAULT
	msgbox LC_AH_ShellyDispt2 MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LH_M3Exit
	waitmovement 0
	msgbox LC_AH_BadEndMsg MSGBOX_DEFAULT
	setflag FLAG_RYU_AQUA_BAD_END
	warpsilent MAP_LILYCOVE_CITY, 15, 49, 8
	release
	end

LC_AH_M4Reldesc::
	msgbox LC_AH_Mission4Msg MSGBOX_DEFAULT
	msgbox LC_AH_RelDecision MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LC_AH_DeclinedShelly
	setflag FLAG_RYU_DS_SHELLY_LOVERS
	msgbox LC_AH_ShellyRelMission1Msg MSGBOX_DEFAULT
	setflag FLAG_RYU_STARTING_M4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LH_M3Exit
	waitmovement 0
	cleartrainerflag TRAINER_ARCHIE
	cleartrainerflag TRAINER_MATT
	setvar VAR_MT_PYRE_STATE, 2
    settrainerflag TRAINER_GRUNT_MT_PYRE_1
    settrainerflag TRAINER_GRUNT_MT_PYRE_2
    settrainerflag TRAINER_GRUNT_MT_PYRE_3
    settrainerflag TRAINER_GRUNT_MT_PYRE_4
	cleartrainerflag TRAINER_MAXIE_3
	cleartrainerflag TRAINER_COURTNEY_3
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	release
	end
	
LC_AH_ShellyRelScene::
	goto_if_unset FLAG_RYU_DS_SHELLY_LOVERS, LC_AH_ShellyNeutral
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	goto_if_set FLAG_RYU_DS_SHELLY_SCENE, LC_AH_Shelly_Afterstory
	lock
	msgbox LC_AH_FirstNight MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_FaceUp
	applymovement 1, LC_AH_AroundDesk
	waitmovement 0
	msgbox LC_AH_GoToQuarters MSGBOX_DEFAULT
	closemessage
	applymovement 1, LC_AH_TOQUARTERS
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_TOQUARTERS2
	waitmovement 0
	applymovement 3, LC_AH_MoveAway
	waitmovement 0
	applymovement 1, LC_AH_TOQUARTERS3
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_TOQUARTERS4
	waitmovement 0
	applymovement 1, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	msgbox LC_AH_QuartersScene MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	fadeoutbgm 2
	applymovement OBJ_EVENT_ID_CAMERA, LC_AH_CameraPan
	msgbox LC_AH_QuartersScene2 MSGBOX_DEFAULT
	applymovement 1, LC_AH_ShellySLide
	msgbox LC_AH_CONCLUSION MSGBOX_AUTOCLOSE
	fadescreenspeed 1, 10
	msgbox LC_AH_CONCLUSION2 MSGBOX_DEFAULT
	closemessage
	delay 40
	removeobject 1
	addobject 1
	applymovement OBJ_EVENT_ID_CAMERA, LC_AH_CameraPan2
	waitmovement 0
	special RemoveCameraObject
	msgbox LC_AH_TRANSITION MSGBOX_DEFAULT
	fadescreenspeed 0, 10
	playbgm MUS_HIGHTOWN, 0
	setflag FLAG_RYU_DS_SHELLY_SCENE
	setflag FLAG_RYU_DS_SHELLY_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	setflag FLAG_RYU_AQUA_LINE_DONE
	special DrawWholeMapView
	releaseall
	end
	
LC_AH_ShellyNeutral::
	msgbox LC_AH_ShellyNeutralmsg MSGBOX_DEFAULT
	release
	end
	
LC_AH_Shelly_Afterstory:
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	call_if_unset FLAG_RYU_AFTERSHELLYSTORY, LC_AH_Shelly_Afterstory_Note
	lock
	msgbox LC_AH_AfterStoryIntro MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LC_AH_FaceUp
	applymovement 1, LC_AH_AroundDesk
	waitmovement 0
	applymovement 1, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	msgbox LC_AH_ShellyFollowerQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LC_AH_ShellySetUpFollower
	msgbox LC_AH_AfterStoryMsg MSGBOX_DEFAULT
	closemessage
	applymovement 1, LC_AH_ShellyReturnToDesk
	waitmovement 0
	setvar VAR_RYU_SHELLY_STATUS, 5
	release
	end

LC_AH_ShellySetUpFollower::
	createfollower OBJ_EVENT_GFX_AQUA_MEMBER_F, RyuFollowerSelectNPCScript, 1
	setflag FLAG_RYU_HAS_FOLLOWER
	setvar VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_AQUA_MEMBER_F
	release
	end
	
LC_AH_Shelly_Afterstory_Note::
	msgbox LC_AH_RelShellyGivesCardKey MSGBOX_DEFAULT
	additem ITEM_CARD_KEY, 1
	msgbox LC_AH_RelShellyAfterStoryCardKeyMsg MSGBOX_DEFAULT
	setflag FLAG_RYU_AFTERSHELLYSTORY
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_SEAFLOOR_CAVERN_STATE, 16
	goto LC_AH_ShellyTeleportQuery
	release
	end
	
LC_AH_ShellyTeleportQuery::
	msgbox LC_AH_ShellyTeleportQueryMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LC_AH_ShellyNoTeleport
	msgbox LC_AH_ShellyTeleporting MSGBOX_DEFAULT
	setvar VAR_SEAFLOOR_CAVERN_STATE, 10
	setflag FLAG_RYU_AQUA_LINE_DONE
	clearflag FLAG_RYU_KYOGRE
	warpteleport MAP_SEAFLOOR_CAVERN_ENTRANCE, 255, 10, 4
	release
	end
	
LC_AH_ShellyNoTeleport::
	msgbox LC_AH_ShellyNoTeleportMsg MSGBOX_DEFAULT
	closemessage
	goto LC_AH_Shelly_Afterstory

LC_AH_ShellyFollowerQuery:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Want me to tag along\nwith you for a while?$"

LC_AH_ShellyTeleportQueryMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: I know where Kyogre is.\pI think you will be able to control\nKyogre and use it for good deeds.\pWould you like me to teleport\nyou to where Kyogre is resting?$"
	
LC_AH_ShellyNoTeleportMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Well, You can find it underwater\non route 128.\pSo anyways...$"
	
LC_AH_ShellyTeleporting:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Just note that this is a one-way\nteleport.\pYou will need to find your own way\nback out of the cavern.$"

LC_AH_RelShellyGivesCardKey:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: So, Archie was going to pass\ncommand of the hideout to me, but\lI think it'd be more fitting for you.\pSo take this note, It gives you\nfull control of the hideout and all\lthe items inside.\p$"
	
LC_AH_RelShellyAfterStoryCardKeyMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Now that that is sorted...$"
	
LC_AH_AfterStoryIntro:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Welcome back, {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}!\nAqua's doing great. It's all\lthanks to you!$"
	
LC_AH_AfterStoryMsg:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Shelly gives you a light kiss)\n... ... ... ... ... ...\l{COLOR LIGHT_RED}{SHADOW RED}Shelly: How are things going for\lyou? Are you the champion yet?\lYou can call me if you want help\lwith any hard fights, you know!$"
	
LC_AH_ShellySLide:
	walk_slow_left
	step_end

LC_AH_FaceDown:
	walk_in_place_down
	step_end
	
LC_AH_CameraPan:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end
	
LC_AH_CameraPan2:	
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end

LC_AH_MoveAway:
	emote_exclamation_mark
	delay_8
	walk_left
	walk_left
	walk_in_place_down
	step_end
	
LC_AH_TOQUARTERS:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
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
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
	
LC_AH_TOQUARTERS2:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
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
	walk_right
	walk_right
	walk_up
	step_end
	
LC_AH_TOQUARTERS3:
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
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_left
	step_end

LC_AH_TOQUARTERS4:
	delay_16
	delay_16
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
	walk_down
	walk_right
	walk_right
	walk_up
	walk_in_place_Right
	step_end	
	
LC_AH_FirstNight:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: There you are, {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}.\n"
	.string "I was wondering when you would\p"
	.string "turn up. Everything's going well\n"
	.string "on my front. Most of Team Aqua's\p"
	.string "members were okay with the\n"
	.string "transition. Some even say they\p"
	.string "prefer it. Doesn't seem like there\n"
	.string "will be any issues from here out.\p"
	.string "I think we're going to start doing\n"
	.string "legitimate business. Probably\p"
	.string "seafloor tours, since we have that\n"
	.string "submarine with the LIDAR on it.$"

LC_AH_GoToQuarters:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: I was hoping we could spend\n"
	.string "a night together... and {COLOR LIGHT_BLUE}really{COLOR LIGHT_RED}{SHADOW RED}\p"
	.string "get to know each other. You've\n"
	.string "made me a better person, and I\l"
	.string "love you for it.\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: I love you, too.\n"
	.string "A night sounds good,\l"
	.string "I could use some rest.\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Let's go, then.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Shelly grabs your hand.)$"
	
LC_AH_QuartersScene:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: You know, before I met you\n"
	.string "I failed to see any of the signs\p"
	.string "that archie wasn't thinking about\n"
	.string "what was best for all the innocent\p"
	.string "people. He was only thinking about\n"
	.string "himself. You lifted the wool from\p"
	.string "my eyes with your kindness, and\n"
	.string "opened me up to a new world of\p"
	.string "opportunities. Ever since you\n"
	.string "started coming around, I've been\p"
	.string "in a better mood than I've ever\n"
	.string "been. You didn't just save the\p"
	.string "lives of countless innocents. You\n"
	.string "also saved me from a world of\p"
	.string "darkness. I love you so much,\n"
	.string "{PLAYER}{COLOR LIGHT_RED}{SHADOW RED}. I'm so glad we're\l"
	.string "together.$"

LC_AH_QuartersScene2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Speaking of which...\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(Shelly slides over and\n"
	.string " leans against your chest...)$"
	
LC_AH_CONCLUSION:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} and Shelly snuggle\n"
	.string " closely and cover up.)$"
	
LC_AH_CONCLUSION2:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER}{COLOR LIGHT_GREEN}{SHADOW GREEN} and Shelly fall into a\n"
	.string " peaceful sleep as the humid ocean\p"
	.string " air slightly jostles the curtains\n"
	.string " in the window.)\p"
	.string "... ... ... ... ... \p"
	.string " (You hear a distant\n"
	.string " ship blowing its horn, signaling\p"
	.string " that it's coming into the pier.)$"
	
LC_AH_ShellyNeutralmsg:
	.string "Hi, {PLAYER}, how are you?\p"
	.string "... ... ... ... ... ...\p"
	.string "That's nice to hear. Well, at\n"
	.string "least Team Aqua is back on its\p"
	.string "feet. Our touring business is\n"
	.string "picking up speed!$"
	
	
LC_AH_TRANSITION:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You awaken to a few voices\n"
	.string " chattering in the main room.\p"
	.string " There's a nice breeze coming\n"
	.string " through the window, and you don't\l"
	.string " want to get up.$)"

LC_AH_ShellyThanks:
	.string "{COLOR LIGHT_RED}{SHADOW RED}You're quite the bold one, you are.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Shelly giggles.)\p"
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: A few people here have been\n"
	.string "staring at me in wierd ways, you're the\p"
	.string "first one to step up. I appreciate that.\n"
	.string "I love the necklace!\p"
	.string "It compliments my eyes!$"
	
LC_AH_M1RelGiftDialog:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You have the custom necklace with\n"
	.string " you. Give it to Shelly?)$"
	
LC_AH_GiftGiven:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: I had this made\n" 
	.string "for you. I thought a beautiful woman\p"
	.string "like you could use a beautiful\n"
	.string "necklace like this one...$"
	
LC_AH_NoGiftMsg:
	.string "Shelly: Was there something else?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: No, sorry.$"

LC_AH_RelDecision:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, you're with me right?\n"
	.string "Will you help me take down\p"
	.string "Archie?$"
	
LC_AH_ShellyDispt:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She looks heartbroken.\p"
	.string " It may be best to leave and not\n"
	.string " come back.)$"
	
LC_AH_ShellyDispt2:
	.string "{PLAYER}... \p"
	.string "I thought we really had something...\n"
	.string "I'm sorry.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(She poises her self proudly. You\n"
	.string " can still see her eyes watering)\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}I've got to go handle this mess,\n"
	.string "now. Please leave.$"
	
LC_AH_BadEndMsg:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You got a pretty strong sense\p"
	.string "of finality in the way Shelly asked\n"
	.string "you to leave.)$"
	
LC_AH_Mission4Msg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}{COLOR LIGHT_RED}{SHADOW RED}! Bad news! We thought\n"
	.string "Maxie was bad, because he was\p"
	.string "trying to erupt a volcano.\p"
	.string "Well, Archie isn't any better!\n"
	.string "He's trying to flood Hoenn!\p"
	.string "He plans to do so by using Kyogre's\n"
	.string "power to induce eternal rain. I\p"
	.string "love team Aqua, but this cannot\n"
	.string "be allowed to happen!$"
	
LC_AH_ShellyRelMission1Msg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: We have to stop Archie\n"
	.string "at Mt Pyre. He's trying to steal\l"
	.string "the Blue Orb to use to awaken\l"
	.string "Kyogre.\l"
	.string "I'll go there undercover,\l"
	.string "and when you get to Archie, I'll\l"
	.string "join you in battle. Matt is\l"
	.string "devoted, so he will likely join\l"
	.string "Archie in battle.\l"
	.string "It'll be us vs them.$"
