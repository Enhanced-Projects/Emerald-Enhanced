Route104_MrBrineysHouse_Story_MapScripts::
	map_script ON_FRAME, r104_ME_PlayerEnters
	.byte 0


r104_ME_PlayerEnters::
	map_script_2 VAR_RYU_MAGMA, 105, R104_ME_EventStart
	.2byte 0

	
R104_ME_EventStart::
	setvar VAR_RYU_MAGMA, 110 @player started event in cottage
	applymovement 8, Common_Movement_FaceUp
	waitmovement 8
	msgbox R104_ME_hehehe
	closemessage
	delay 30
	msgbox R104_ME_BringThemToMe
	applymovement OBJ_EVENT_ID_PLAYER, R104_ME_UpToMaxie
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 8, R104_ME_MoveTabitha
	waitmovement 8
	applymovement 1, Common_Movement_StepDown
	waitmovement 1
	msgbox R104_ME_SoYoureThe
	closemessage
	applymovement 8 Common_Movement_FaceDown
	waitmovement 8
	msgbox R104_ME_YoullSpeakOnly
	applymovement 8, Common_Movement_FaceRight
	waitmovement 8
	msgbox R104_ME_LeaderMaxie
	closemessage
	delay 20
	applymovement 1, Common_Movement_StepUp
	msgbox R104_ME_TheLowlyGrunt
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	msgbox R104_ME_GiveMeOne
	closemessage
	delay 20
	applymovement 8, Common_Movement_StepDown
	waitmovement 8
	applymovement 8, Common_Movement_StepRight
	waitmovement 8
	playse SE_W003
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0xFF
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0xFF
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0xFF
	addobject 10
	msgbox R104_ME_PlayerLosesItems
	closemessage
	applymovement 1, Common_Movement_StepDown
	waitmovement 1
	msgbox R104_ME_WellNowThis
	closemessage
	delay 20
	msgbox R104_ME_ItSeemsYou
	closemessage
	applymovement 1, Common_Movement_FaceRight
	removeobject 10
	applymovement 9, Common_Movement_FaceLeft
	waitmovement 9
	msgbox R104_ME_BlaiseImLeaving
	closemessage
	applymovement 9, Common_Movement_FaceLeft
	msgbox R104_ME_ComeAlong
	closemessage
	applymovement 1, R104_ME_MaxieExits
	applymovement OBJ_EVENT_ID_PLAYER R14_MovePlayerOutOfWay
	applymovement 8, Common_Movement_FaceRight
	msgbox R104_ME_HehYoureFortunate
	closemessage
	applymovement 8, Common_Movement_FaceDown
	msgbox R104_ME_MagmaMoveOut
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_RYU_HIDE_COTTAGE_MAGMA
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 10
	fadescreen FADE_FROM_BLACK
	applymovement 9, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox R104_ME_JustUsTwo
	closemessage
	applymovement 9, Common_Movement_StepLeft
	waitmovement 9
	applymovement 9, R104_ME_MaxieExits
	waitmovement 9
	removeobject 9
	setvar VAR_RYU_MAGMA, 115 @Player finished cottage event
	setflag FLAG_RYU_HIDE_BRINEY_GUARD
	clearflag FLAG_RYU_HIDE_GC_BLAISE
	release
	end
	
R104_ME_hehehe::
	.string "Hehehe, Leader Maxie, sir! The\n"
    .string "interloper has arrived.$"

R104_ME_BringThemToMe::
	.string "Bring them to me.$"
	
R104_ME_SoYoureThe::
	.string "So...you're the little deviant in my\n"
    .string "plans.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}'Deviant'?$"

R104_ME_YoullSpeakOnly::
	.string "You'll speak only when permitted!$"
	
R104_ME_LeaderMaxie::
	.string "Leader Maxie, sir, please continue.$"

R104_ME_TheLowlyGrunt::
	.string "The lowly grunt that was responsible\n"
    .string "for not only delaying the mission's\p"
    .string "completion, but to become so careless\n"
    .string "as to allow a speck like yourself\p"
    .string "into our Order has been taken care\n"
    .string "of...$"

R104_ME_GiveMeOne::
	.string "Give me one good reason why I\n"
    .string "shouldn't do the same to you here and\p"
    .string "now.$"
	
R104_ME_PlayerLosesItems::
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You feel a twinge of pain,\n"
    .string " as you are knocked to the\p"
    .string " ground by Tabitha, causing you\n"
    .string " to drop your Badge Case.)$"

R104_ME_WellNowThis::
	.string "Well now, this is...$"
	
R104_ME_ItSeemsYou::
	.string "It seems you do have some value\n"
    .string "after all. State your name.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ...\p"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Let me make something clear to you.\p"
    .string "When it comes to the assignments I\p"
    .string "give, all I require is success and\n"
    .string "efficiency. Those are the alpha and\p"
    .string "omega of Team Magma. Anything beyond\n"
    .string "that is a waste of my time, and shall\p"
    .string "be dealt with accordingly.$"

R104_ME_BlaiseImLeaving::
	.string "Blaise, I'm leaving you in charge of\n"
    .string "instructing this neophyte. If there\p"
    .string "are any further issues, dispose of\n"
    .string "them.\p"
    .string "Blaise: Roger that...\p"
    .string "Now then, there's work to be done.$"

R104_ME_ComeAlong::
	.string "Come along, Tabitha.$"
	
R104_ME_HehYoureFortunate::
	.string "Heh, you're fortunate to have gotten\n"
    .string "on Boss' good side today.$"

R104_ME_MagmaMoveOut::
	.string "Magma, move out!\p"
    .string "Sir!$"

R104_ME_JustUsTwo::
	.string "Just us two then.\n"
    .string "As you just heard from Boss, name's\p"
    .string "Blaise, one of the Three Fires of\n"
    .string "Team Magma, and as of right now,\l"
    .string "your teacher.\p"
    .string "As for your first assignment...how\n"
    .string "about a little navigation exercise?\p"
    .string "Meet me in Granite Cave...y'know,\n"
    .string "that cavern north of Dewford. Also,\p"
    .string "I suggest getting a bike that can\n"
    .string "quickly traverse over muddy slopes\l"
    .string "and cracked earth.\p"
    .string "Don't take too long now.$"
	
	
R104_ME_UpToMaxie:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

R104_ME_MaxieExits:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
R104_ME_MoveTabitha:
	walk_up
	walk_left
	face_right
	step_end
	
R14_MovePlayerOutOfWay:
	walk_right
	face_up
	delay_16
	face_left
	step_end
