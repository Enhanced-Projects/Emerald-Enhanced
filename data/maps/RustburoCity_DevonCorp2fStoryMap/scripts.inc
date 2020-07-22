RustburoCity_DevonCorp2fStoryMap_MapScripts::
	map_script ON_FRAME, DC_MainDevonLineCheck
	.byte 0
	
DC_MainDevonLineCheck::
	map_script_2 VAR_RYU_DEVON_MAIN_QUEST_VAR, 4, DC_MainDevonLineContinued
	.2byte 0
	
DC_MainDevonLineContinued::
	lock
	setvar VAR_RYU_DEVON_MAIN_QUEST_VAR, 0
	msgbox DC_NewHire
	closemessage
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 1
	msgbox DC_MissingPeople
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	msgbox DC_ThisWay
	closemessage
	applymovement 1, DC_WalkToComputer1
	applymovement OBJ_EVENT_ID_PLAYER, DC_WalkToComputer2
	waitmovement 1
	msgbox DC_questions
	closemessage
	applymovement 1, DC_PrezExit
	waitmovement 1
	setflag FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE3
	removeobject 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject 6
	applymovement 6, DC_LateEmployee
	waitmovement 6
	msgbox DC_Madeit
	closemessage
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	msgbox DC_Forgot
	closemessage
	applymovement 6, Common_Movement_FaceLeft
	waitmovement 6
	applymovement 6, Common_Movement_QuestionMark
	waitmovement 6
	msgbox DC_WelcomeAboard
	closemessage
	applymovement 6 Common_Movement_FaceUp
	msgbox MF_ellipsis
	delay 50
	closemessage
	applymovement 6, Common_Movement_FaceLeft
	waitmovement 6
	msgbox DC_YouDontLook
	closemessage
	applymovement 6, Common_Movement_FaceUp
	waitmovement 6
	msgbox DC_EnoughChat
	closemessage
	applymovement 6, Common_Movement_FaceLeft
	waitmovement 6
	msgbox DC_WhatsThat
	closemessage
	setvar VAR_RYU_DEVON_MAIN_QUEST_VAR, 5
	release
	end
	
DC_ProgressCheck::
	lock
	call_if_unset FLAG_TEMP_5, DC_CantLeaveYet
	call_if_unset FLAG_TEMP_6, DC_CantLeaveYet
	call_if_unset FLAG_TEMP_7, DC_CantLeaveYet
	release
	end
	
DC_CantLeaveYet::
	msgbox DC_CantLeave
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
DC_QuestScientist1::
	msgbox DC_Alledgedly
	setflag FLAG_TEMP_5
	goto_if_set FLAG_TEMP_6, DC_CanLeaveNow
	goto_if_set FLAG_TEMP_7, DC_CanLeaveNow
	closemessage
	release
	end
	
DC_QuestScientist2::
	msgbox DC_Transfer
	setflag FLAG_TEMP_6
	goto_if_set FLAG_TEMP_5, DC_CanLeaveNow
	goto_if_set FLAG_TEMP_7, DC_CanLeaveNow
	closemessage
	release
	end

DC_QuestScientist3::
	msgbox DC_MoreThanItCanHandle
	setflag FLAG_TEMP_7
	goto_if_set FLAG_TEMP_6, DC_CanLeaveNow
	goto_if_set FLAG_TEMP_5, DC_CanLeaveNow
	closemessage
	release
	end
	
DC_CanLeaveNow::
	call_if_unset FLAG_TEMP_5, ryu_end
	call_if_unset FLAG_TEMP_6, ryu_end
	call_if_unset FLAG_TEMP_7, ryu_end
	msgbox DC_AllDone2F
	setvar VAR_RYU_DEVON_MAIN_QUEST_VAR, 15
	release
	end

DC_NewHire:
	.string "If I may have everyone's attention\n"
	.string "for a brief moment...\p"
	.string "We have a new hire within our\n"
	.string "company...{PLAYER}.\p"
	.string "I'm sure for some of you, this\n"
	.string "person is familiar, however\p"
	.string "please use this opportunity to\n"
	.string "offer a lending hand.$"

DC_MissingPeople:
	.string "We're missing quite a few people...\pNo matter, I'll have to fill them\nin at a later time.$"
	
DC_ThisWay:
	.string "This way, {PLAYER}.$"
	
DC_questions:
	.string "This will be your station for now.\nFamiliarize yourself with the\pstaff, and don't hesitate to ask\nquestions. Take care.$"
	
DC_Madeit:
	.string "Whew, made it by 0.2 seconds! That\nis the closest I've ever been to-$"
	
DC_Forgot:
	.string "Oh great, I forgot the-!$"
	
DC_WelcomeAboard:
	.string "Huh? Who're you?\p... ... ...\pI see, welcome aboard newbie.\nName's Tadaki.$"
	
DC_YouDontLook:
	.string "Honestly, you don't look like the\n"
	.string "corporate-type...\p"
	.string "Oh I see now! You're that\n"
	.string "guy that brought back the\p"
	.string "LIDAR system from Team Aqua.\n"
	.string "That little incident brought about\p"
	.string "a lotta hardship...and when the\n"
	.string "company suffers...their employees\p"
	.string "suffer much harder. That's big\n"
	.string "business for you.$"
	
DC_EnoughChat:
	.string "Anyways, enough chit-chat.\pI've got a schedule to keep. I'm\nalready 30 minutes behind!$"
	
DC_WhatsThat:
	.string "What's that? You want to know how\nbad it was? Just take a look\paround. Anyone here can tell you\nwhat a struggle it's been. Now,\lallow me to work in peace.$"
	
DC_CantLeave:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}I wonder if these scientists know\nmore than they're letting on...$"
	
DC_Alledgedly:
	.string "There is allegedly the existence\n"
	.string "of someone in another region who\p"
	.string "can, in fact, communicate with\n"
	.string "pokémon...\p"
	.string "Now it's time for the rest of the\n"
	.string "world to catch up. That's been my\p"
	.string "motivation while working here. And\n"
	.string "yet...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The employee trails off in\n"
	.string " thought before resuming his work.)$"
	
DC_Transfer:
	.string "Perhaps I should've taken the\n"
	.string "department transfer to Unova from\p"
	.string "that doctor after all. She seems\n"
	.string "to be making much better progress.\p"
	.string "But I've worked at Devon for many\n"
	.string "years. It was my first job, in\p"
	.string "fact. So there's a sense of\n"
	.string "loyalty to the company.\p"
	.string "With the state of affairs\n"
	.string "continuing as is, we'll be losing\p"
	.string "revenue, which means not enough\n"
	.string "people to pay, and inevitably a\l"
	.string "layoff of workers...\p"
	.string "Out of the group, I've been here\n"
	.string "the longest, so I have seniority\p"
	.string "on my side, and yet I'd be the\n"
	.string "first one to be given the\p"
	.string "pink slip. It'll come as soon as\n"
	.string "I'm close to retirement. There's\l"
	.string "no reward for loyalty nowadays...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(You can sense the increasing\n"
	.string " levels of anxiety in his voice\p"
	.string " before he shuts himself in...poor\n"
	.string " guy.)$"
	
DC_MoreThanItCanHandle:
	.string "To be honest, I think Devon is\n"
	.string "trying to take on more than it can\l"
	.string " handle...\p"
	.string "I mean, I know the motto is to\n"
	.string "'Strive for Success', but for us\p"
	.string "workers, it really feels like\n"
	.string "'Stress for Success' at this rate.\p"
	.string "Pouring countless hours in,\n"
	.string "getting little recognition out...\p"
	.string "Ultimately, the mechanics behind\n"
	.string "any job-related activity is based \p"
	.string "upon its' efficiency, and yet our \n"
	.string "lifestyle is far from it.\p"
	.string "... ... ...\p"
	.string "This isn't what I signed up for...\n"
	.string "perhaps I should just...\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(He never finishes his sentence,\n"
	.string " but you can see where the\l"
	.string " conversation was going.)$"
	
DC_AllDone2F:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(That seems to be everyone I can\ntalk to on this floor...time to\lhead downstairs.)$"
	
	
DC_WalkToComputer1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	delay_16
	delay_16
	walk_right
	step_end
	
DC_WalkToComputer2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_left
	step_end
	
DC_PrezExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
DC_LateEmployee:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_right
	walk_in_place_up
	step_end
	
	
	
	
	
	
	
@Main Devon Line Fin=========================================================================================================================


