Route129_MapScripts:: @ 81F7284
	.byte 0

Route129_EventScript_Chase:: @ 81F72EC
	trainerbattle_single TRAINER_CHASE, Route129_Text_ChaseIntro, Route129_Text_ChaseDefeat
	msgbox Route129_Text_ChasePostBattle, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_Allison:: @ 81F7303
	trainerbattle_single TRAINER_ALLISON, Route129_Text_AllisonIntro, Route129_Text_AllisonDefeat
	msgbox Route129_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_Reed:: @ 81F731A
	trainerbattle_single TRAINER_REED, Route129_Text_ReedIntro, Route129_Text_ReedDefeat
	msgbox Route129_Text_ReedPostBattle, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_Tisha:: @ 81F7331
	trainerbattle_single TRAINER_TISHA, Route129_Text_TishaIntro, Route129_Text_TishaDefeat
	msgbox Route129_Text_TishaPostBattle, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_Clarence:: @ 81F7348
	trainerbattle_single TRAINER_CLARENCE, Route129_Text_ClarenceIntro, Route129_Text_ClarenceDefeat
	msgbox Route129_Text_ClarencePostBattle, MSGBOX_AUTOCLOSE
	end

