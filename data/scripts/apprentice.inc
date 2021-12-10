.set LOCALID_APPRENTICE, 6

BattleFrontier_BattleTowerLobby_EventScript_Apprentice:: @ 82B688D
	end

Apprentice_EventScript_FirstMeeting: @ 82B6900
Apprentice_EventScript_WhichLvlMode: @ 82B6925
	end

@ Its impossible to fully reject an Apprentice, they just keep asking for you to teach them
Apprentice_EventScript_RejectTeach: @ 82B69BB
	apprentice_msg FALSE, APPRENTICE_MSG_REJECT
	goto Apprentice_EventScript_WhichLvlMode

Apprentice_EventScript_UseWhichMon: @ 82B69D3
	end

Apprentice_EventScript_ChoseFirstMon: @ 82B6ABA
	return

Apprentice_EventScript_ChoseSecondMon: @ 82B6AC0
	return

Apprentice_EventScript_LastMonSelected: @ 82B6AC6
	return

Apprentice_EventScript_UseWhatHeldItem: @ 82B6ACF
Apprentice_EventScript_ChooseHoldItem: @ 82B6B09
	end

Apprentice_EventScript_ConfirmHoldNothing: @ 82B6B81
Apprentice_EventScript_HoldNothing: @ 82B6BD4
	end

@ Because Battle Tower mons may not hold the same item, the player must suggest a
@ different item if theyve already told the Apprentice to use it for another mon
Apprentice_EventScript_AlreadySuggestedItem: @ 82B6C0C
	end

Apprentice_EventScript_UseWhichMove: @ 82B6C77
	end

Apprentice_EventScript_ChoseMove1: @ 82B6D50
	return

Apprentice_EventScript_ChoseMove2: @ 82B6D56
	return

Apprentice_EventScript_PutWhichMonFirst: @ 82B6D5
	end

@ Last question, after which the Apprentice leaves (and is saved) to be replaced by another
Apprentice_EventScript_PickWinSpeech: @ 82B6DD4
	end

Apprentice_EventScript_SetHideFlags: @ 82B6E4D
	return

Apprentice_EventScript_LeaveNorth: @ 82B6E54
	end

Apprentice_EventScript_Leave: @ 82B6E72
	end

Apprentice_EventScript_Gone: @ 82B6E90
	release
	end

Apprentice_EventScript_DontMove: @ 82B6E93
	end

Apprentice_Movement_LeaveNorth: @ 82B6E94
Apprentice_Movement_Leave: @ 82B6E95
	step_end
