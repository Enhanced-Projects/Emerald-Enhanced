MirageTower_4F_MapScripts:: @ 823AD47
	.byte 0

MirageTower_4F_EventScript_RootFossil:: @ 823AD48
	end

MirageTower_4F_EventScript_LeaveRootFossil:: @ 823AD7F
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ClawFossil:: @ 823AD89
	end

MirageTower_4F_EventScript_LeaveClawFossil:: @ 823ADC0
	end

MirageTower_4F_EventScript_CollapseMirageTower:: @ 823ADCA
	release
	end

MirageTower_4F_Text_TakeRootFossil: @ 823ADF9
	.string "You found the ROOT FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the ROOT FOSSIL anyway?$"

MirageTower_4F_Text_LeftRootFossilAlone: @ 823AE79
	.string "{PLAYER} left the ROOT FOSSIL alone.$"

MirageTower_4F_Text_TakeClawFossil: @ 823AE98
	.string "You found the CLAW FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the CLAW FOSSIL anyway?$"

MirageTower_4F_Text_LeaveClawFossilAlone: @ 823AF18
	.string "{PLAYER} left the CLAW FOSSIL alone.$"
	
MT_Shanti::
	trainerbattle_single TRAINER_SHANTI, MT_ShantiIntro, MT_ShantiDefeatedMsg, MT_ShantiFormChangeQuery
	goto MT_ShantiFormChangeQuery
	release
	end

MT_ShantiFormChangeQuery::
	msgbox MT_DarmanitanDeclined
	specialvar VAR_RESULT, CheckPlayerHasDarmanitan
	compare VAR_RESULT, TRUE
	goto_if_eq MT_PlayerhasDarmanitan
	msgbox MT_Shanti_DarmanitanDesc
	closemessage
	release
	end
	
MT_PlayerhasDarmanitan::
	msgbox TransformDarmanitanQuery, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq MT_PlayerDeclinedShanti
	fadescreen FADE_TO_BLACK
	closemessage
	fadenewbgm MUS_DUMMY
	delay 300
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	specialvar VAR_RESULT, ChangeDarmanitanForm
	delay 20
	compare VAR_RESULT, FALSE
	goto_if_eq MT_ChangeFailed
	msgbox MT_ChangeSuccessful
	release
	end
	
MT_ChangeFailed::
	msgbox MT_DontHaveDarmanitan
	release
	end
	
MT_DontHaveDarmanitan:
	.string "This meditation only works/nwith a base form Darmanitan!$"
	
MT_PlayerDeclinedShanti::
	msgbox MT_DarmanitanDeclined
	closemessage
	release
	end
	
MT_DarmanitanDeclined:
	.string "If you possess a Darmanitan, bring it\n"
	.string "to me and I shall enlighten its mind.$"
	
MT_ShantiIntro:
	.string "I am trying to meditate here!\n"
	.string "Don't come barging in!$"

MT_ShantiDefeatedMsg:
	.string "I was not focused enough...$"
	
MT_Shanti_DarmanitanDesc:
	.string "You seem to boast a wealth of focus.\p"
	.string "Since you have bested me, I shall do\n"
	.string "you a favor.\p"
	.string "If you possess a Darmanitan, bring it\n"
	.string "to me and I shall enlighten its mind.$"
	
TransformDarmanitanQuery:
	.string "Aha, you have brought one!\p"
	.string "Shall I calm it down and awaken\n"
	.string "its inner power through meditation?$"
	
MT_ChangeSuccessful:
	.string "Aha, the session was succesful!$"



