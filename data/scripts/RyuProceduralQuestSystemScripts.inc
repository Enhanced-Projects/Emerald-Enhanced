RyuNaturalistsDailyQuest::
	goto_if_set FLAG_FINISHED_NATURALIST_DAILY, RyuNaturalistsDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuNaturalistsDailyQuest_10
RyuNaturalistsDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuNaturalistsDailyQuest_7
RyuNaturalistsDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuNaturalistsDailyQuest_14
	case 1, RyuNaturalistsDailyQuest_15
	return

RyuNaturalistsDailyQuest_2:
	msgbox RyuNaturalistsDailyQuest_Text_0
	release
	end

RyuNaturalistsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuNaturalistsDailyQuest_17
	case 2, RyuNaturalistsDailyQuest_18
	goto RyuNaturalistsDailyQuest_4

RyuNaturalistsDailyQuest_6:
	callnative RyuSummonOriginalNPCscript
	end

RyuNaturalistsDailyQuest_7:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NATURALISTS
	goto_if_ne RyuNaturalistsDailyQuest_6
	goto RyuNaturalistsDailyQuest_4

RyuNaturalistsDailyQuest_10:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NATURALISTS
	goto_if_eq RyuNaturalistsDailyQuest_5
	goto RyuNaturalistsDailyQuest_8

RyuNaturalistsDailyQuest_14:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_SITRUS_BERRY
	setvar VAR_RYU_DAILY_QUEST_DATA, 3
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NATURALISTS
	msgbox RyuNaturalistsDailyQuest_Text_2
	closemessage
	release
	end

RyuNaturalistsDailyQuest_15:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_PECHA_BERRY
	setvar VAR_RYU_DAILY_QUEST_DATA, 2
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NATURALISTS
	msgbox RyuNaturalistsDailyQuest_Text_3
	closemessage
	release
	end

RyuNaturalistsDailyQuest_17:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuNaturalistsDailyQuest_20
	case FALSE, RyuNaturalistsDailyQuest_21
	goto RyuNaturalistsDailyQuest_4

RyuNaturalistsDailyQuest_18:
	end

RyuNaturalistsDailyQuest_20:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonNaturalistRewardScript
	goto RyuNaturalistsDailyQuest_4

RyuNaturalistsDailyQuest_21:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuNaturalistsDailyQuest_Text_1
	release
	end


RyuStudentsDailyQuest::
	goto_if_set FLAG_FINISHED_STUDENT_DAILY, RyuStudentsDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuStudentsDailyQuest_10
RyuStudentsDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuStudentsDailyQuest_7
RyuStudentsDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuStudentsDailyQuest_14
	case 1, RyuStudentsDailyQuest_15
	return

RyuStudentsDailyQuest_2:
	msgbox RyuStudentsDailyQuest_Text_0
	release
	end

RyuStudentsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuStudentsDailyQuest_17
	case 2, RyuStudentsDailyQuest_18
	goto RyuStudentsDailyQuest_4

RyuStudentsDailyQuest_6:
	callnative RyuSummonOriginalNPCscript
	end

RyuStudentsDailyQuest_7:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_STUDENTS
	goto_if_ne RyuStudentsDailyQuest_6
	goto RyuStudentsDailyQuest_4

RyuStudentsDailyQuest_10:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_STUDENTS
	goto_if_eq RyuStudentsDailyQuest_5
	goto RyuStudentsDailyQuest_8

RyuStudentsDailyQuest_14:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_POTION
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_STUDENTS
	msgbox RyuStudentsDailyQuest_Text_2
	closemessage
	release
	end

RyuStudentsDailyQuest_15:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_POKE_BALL
	setvar VAR_RYU_DAILY_QUEST_DATA, 10
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_STUDENTS
	msgbox RyuStudentsDailyQuest_Text_3
	closemessage
	release
	end

RyuStudentsDailyQuest_17:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuStudentsDailyQuest_20
	case FALSE, RyuStudentsDailyQuest_21
	goto RyuStudentsDailyQuest_4

RyuStudentsDailyQuest_18:
	end

RyuStudentsDailyQuest_20:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonStudentRewardScript
	goto RyuStudentsDailyQuest_4

RyuStudentsDailyQuest_21:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuStudentsDailyQuest_Text_1
	release
	end


RyuNoblesDailyQuest::
	goto_if_set FLAG_FINISHED_NOBLE_DAILY, RyuNoblesDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuNoblesDailyQuest_10
RyuNoblesDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuNoblesDailyQuest_7
RyuNoblesDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuNoblesDailyQuest_14
	case 1, RyuNoblesDailyQuest_15
	return

RyuNoblesDailyQuest_2:
	msgbox RyuNoblesDailyQuest_Text_0
	release
	end

RyuNoblesDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuNoblesDailyQuest_17
	case 2, RyuNoblesDailyQuest_18
	goto RyuNoblesDailyQuest_4

RyuNoblesDailyQuest_6:
	callnative RyuSummonOriginalNPCscript
	end

RyuNoblesDailyQuest_7:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NOBLES
	goto_if_ne RyuNoblesDailyQuest_6
	goto RyuNoblesDailyQuest_4

RyuNoblesDailyQuest_10:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NOBLES
	goto_if_eq RyuNoblesDailyQuest_5
	goto RyuNoblesDailyQuest_8

RyuNoblesDailyQuest_14:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_TEA
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NOBLES
	msgbox RyuNoblesDailyQuest_Text_2
	closemessage
	release
	end

RyuNoblesDailyQuest_15:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_BIG_PEARL
	setvar VAR_RYU_DAILY_QUEST_DATA, 8
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NOBLES
	msgbox RyuNoblesDailyQuest_Text_3
	closemessage
	release
	end

RyuNoblesDailyQuest_17:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuNoblesDailyQuest_20
	case FALSE, RyuNoblesDailyQuest_21
	goto RyuNoblesDailyQuest_4

RyuNoblesDailyQuest_18:
	end

RyuNoblesDailyQuest_20:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonNobleRewardScript
	goto RyuNoblesDailyQuest_4

RyuNoblesDailyQuest_21:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuNoblesDailyQuest_Text_1
	release
	end


RyuPokefansDailyQuest::
	goto_if_set FLAG_FINISHED_POKEFAN_DAILY, RyuPokefansDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuPokefansDailyQuest_10
RyuPokefansDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuPokefansDailyQuest_7
RyuPokefansDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuPokefansDailyQuest_14
	case 1, RyuPokefansDailyQuest_15
	return

RyuPokefansDailyQuest_2:
	msgbox RyuPokefansDailyQuest_Text_0
	release
	end

RyuPokefansDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuPokefansDailyQuest_17
	case 2, RyuPokefansDailyQuest_18
	goto RyuPokefansDailyQuest_4

RyuPokefansDailyQuest_6:
	callnative RyuSummonOriginalNPCscript
	end

RyuPokefansDailyQuest_7:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_POKEFANS
	goto_if_ne RyuPokefansDailyQuest_6
	goto RyuPokefansDailyQuest_4

RyuPokefansDailyQuest_10:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_POKEFANS
	goto_if_eq RyuPokefansDailyQuest_5
	goto RyuPokefansDailyQuest_8

RyuPokefansDailyQuest_14:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_POKE_DOLL
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_POKEFANS
	msgbox RyuPokefansDailyQuest_Text_2
	closemessage
	release
	end

RyuPokefansDailyQuest_15:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_HEART_SCALE
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_POKEFANS
	msgbox RyuPokefansDailyQuest_Text_3
	closemessage
	release
	end

RyuPokefansDailyQuest_17:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuPokefansDailyQuest_20
	case FALSE, RyuPokefansDailyQuest_21
	goto RyuPokefansDailyQuest_4

RyuPokefansDailyQuest_18:
	end

RyuPokefansDailyQuest_20:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonPokefansRewardScript
	goto RyuPokefansDailyQuest_4

RyuPokefansDailyQuest_21:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuPokefansDailyQuest_Text_1
	release
	end


RyuOutcastsDailyQuest::
	goto_if_set FLAG_FINISHED_OUTCAST_DAILY, RyuOutcastsDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuOutcastsDailyQuest_10
RyuOutcastsDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuOutcastsDailyQuest_7
RyuOutcastsDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuOutcastsDailyQuest_14
	case 1, RyuOutcastsDailyQuest_15
	return

RyuOutcastsDailyQuest_2:
	msgbox RyuOutcastsDailyQuest_Text_0
	release
	end

RyuOutcastsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuOutcastsDailyQuest_17
	case 2, RyuOutcastsDailyQuest_18
	goto RyuOutcastsDailyQuest_4

RyuOutcastsDailyQuest_6:
	callnative RyuSummonOriginalNPCscript
	end

RyuOutcastsDailyQuest_7:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_OUTCASTS
	goto_if_ne RyuOutcastsDailyQuest_6
	goto RyuOutcastsDailyQuest_4

RyuOutcastsDailyQuest_10:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_OUTCASTS
	goto_if_eq RyuOutcastsDailyQuest_5
	goto RyuOutcastsDailyQuest_8

RyuOutcastsDailyQuest_14:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_ENERGY_POWDER
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_OUTCASTS
	msgbox RyuOutcastsDailyQuest_Text_2
	closemessage
	release
	end

RyuOutcastsDailyQuest_15:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_STARDUST
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_OUTCASTS
	msgbox RyuOutcastsDailyQuest_Text_3
	closemessage
	release
	end

RyuOutcastsDailyQuest_17:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuOutcastsDailyQuest_20
	case FALSE, RyuOutcastsDailyQuest_21
	goto RyuOutcastsDailyQuest_4

RyuOutcastsDailyQuest_18:
	end

RyuOutcastsDailyQuest_20:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonOutcastRewardScript
	goto RyuOutcastsDailyQuest_4

RyuOutcastsDailyQuest_21:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuOutcastsDailyQuest_Text_1
	release
	end


RyuProfessionalsDailyQuest::
	goto_if_set FLAG_FINISHED_PROFESSIONAL_DAILY, RyuProfessionalsDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuProfessionalsDailyQuest_10
RyuProfessionalsDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuProfessionalsDailyQuest_7
RyuProfessionalsDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuProfessionalsDailyQuest_14
	case 1, RyuProfessionalsDailyQuest_15
	return

RyuProfessionalsDailyQuest_2:
	msgbox RyuProfessionalsDailyQuest_Text_0
	release
	end

RyuProfessionalsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuProfessionalsDailyQuest_17
	case 2, RyuProfessionalsDailyQuest_18
	goto RyuProfessionalsDailyQuest_4

RyuProfessionalsDailyQuest_6:
	callnative RyuSummonOriginalNPCscript
	end

RyuProfessionalsDailyQuest_7:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_PROFESSIONALS
	goto_if_ne RyuProfessionalsDailyQuest_6
	goto RyuProfessionalsDailyQuest_4

RyuProfessionalsDailyQuest_10:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_PROFESSIONALS
	goto_if_eq RyuProfessionalsDailyQuest_5
	goto RyuProfessionalsDailyQuest_8

RyuProfessionalsDailyQuest_14:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_SODA_POP
	setvar VAR_RYU_DAILY_QUEST_DATA, 12
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_PROFESSIONALS
	msgbox RyuProfessionalsDailyQuest_Text_2
	closemessage
	release
	end

RyuProfessionalsDailyQuest_15:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_HYPER_POTION
	setvar VAR_RYU_DAILY_QUEST_DATA, 2
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_PROFESSIONALS
	msgbox RyuProfessionalsDailyQuest_Text_3
	closemessage
	release
	end

RyuProfessionalsDailyQuest_17:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuProfessionalsDailyQuest_20
	case FALSE, RyuProfessionalsDailyQuest_21
	goto RyuProfessionalsDailyQuest_4

RyuProfessionalsDailyQuest_18:
	end

RyuProfessionalsDailyQuest_20:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonProfessionalsRewardScript
	goto RyuProfessionalsDailyQuest_4

RyuProfessionalsDailyQuest_21:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuProfessionalsDailyQuest_Text_1
	release
	end


RyuAthletesDailyQuest::
	goto_if_set FLAG_FINISHED_ATHLETE_DAILY, RyuAthletesDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuAthletesDailyQuest_10
RyuAthletesDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuAthletesDailyQuest_7
RyuAthletesDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuAthletesDailyQuest_14
	case 1, RyuAthletesDailyQuest_15
	return

RyuAthletesDailyQuest_2:
	msgbox RyuAthletesDailyQuest_Text_0
	release
	end

RyuAthletesDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuAthletesDailyQuest_17
	case 2, RyuAthletesDailyQuest_18
	goto RyuAthletesDailyQuest_4

RyuAthletesDailyQuest_6:
	callnative RyuSummonOriginalNPCscript
	end

RyuAthletesDailyQuest_7:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_ATHLETES
	goto_if_ne RyuAthletesDailyQuest_6
	goto RyuAthletesDailyQuest_4

RyuAthletesDailyQuest_10:
	compare VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_ATHLETES
	goto_if_eq RyuAthletesDailyQuest_5
	goto RyuAthletesDailyQuest_8

RyuAthletesDailyQuest_14:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_PROTEIN
	setvar VAR_RYU_DAILY_QUEST_DATA, 2
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_ATHLETES
	msgbox RyuAthletesDailyQuest_Text_2
	closemessage
	release
	end

RyuAthletesDailyQuest_15:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_WAVE_MAIL
	setvar VAR_RYU_DAILY_QUEST_DATA, 10
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_ATHLETES
	msgbox RyuAthletesDailyQuest_Text_3
	closemessage
	release
	end

RyuAthletesDailyQuest_17:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuAthletesDailyQuest_20
	case FALSE, RyuAthletesDailyQuest_21
	goto RyuAthletesDailyQuest_4

RyuAthletesDailyQuest_18:
	end

RyuAthletesDailyQuest_20:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonAthletesRewardScript
	goto RyuAthletesDailyQuest_4

RyuAthletesDailyQuest_21:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuAthletesDailyQuest_Text_1
	release
	end


CommonNaturalistRewardScript::
	msgbox CommonNaturalistRewardScript_Text_0
	setflag FLAG_FINISHED_NATURALIST_DAILY
	clearflag FLAG_DAILY_QUEST_ACTIVE
	changefactionstanding FACTION_NATURALISTS, 25, FALSE
	setvar VAR_TEMP_B, 1000
	addmoney VAR_TEMP_B
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonNaturalistRewardScript_Text_1
	closemessage
	release
	end


CommonStudentRewardScript::
	msgbox CommonStudentRewardScript_Text_0
	setflag FLAG_FINISHED_STUDENT_DAILY
	clearflag FLAG_DAILY_QUEST_ACTIVE
	changefactionstanding FACTION_STUDENTS, 25, FALSE
	setvar VAR_TEMP_B, 3000
	addmoney VAR_TEMP_B
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonNaturalistRewardScript_Text_1
	closemessage
	release
	end


CommonNobleRewardScript::
	msgbox CommonNobleRewardScript_Text_0
	setflag FLAG_FINISHED_NOBLE_DAILY
	clearflag FLAG_DAILY_QUEST_ACTIVE
	changefactionstanding FACTION_NOBLES, 25, FALSE
	setvar VAR_TEMP_B, 10000
	addmoney VAR_TEMP_B
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonNaturalistRewardScript_Text_1
	closemessage
	release
	end


CommonPokefansRewardScript::
	msgbox CommonPokefansRewardScript_Text_0
	setflag FLAG_FINISHED_POKEFAN_DAILY
	clearflag FLAG_DAILY_QUEST_ACTIVE
	changefactionstanding FACTION_POKEFANS, 25, FALSE
	setvar VAR_TEMP_B, 2500
	addmoney VAR_TEMP_B
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonNaturalistRewardScript_Text_1
	closemessage
	release
	end


CommonOutcastRewardScript::
	msgbox CommonOutcastRewardScript_Text_0
	setflag FLAG_FINISHED_OUTCAST_DAILY
	clearflag FLAG_DAILY_QUEST_ACTIVE
	changefactionstanding FACTION_OUTCASTS, 25, FALSE
	setvar VAR_TEMP_B, 2000
	addmoney VAR_TEMP_B
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonNaturalistRewardScript_Text_1
	closemessage
	release
	end


CommonProfessionalsRewardScript::
	msgbox CommonNobleRewardScript_Text_0
	setflag FLAG_FINISHED_PROFESSIONAL_DAILY
	clearflag FLAG_DAILY_QUEST_ACTIVE
	changefactionstanding FACTION_PROFESSIONALS, 25, FALSE
	setvar VAR_TEMP_B, 4000
	addmoney VAR_TEMP_B
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonNaturalistRewardScript_Text_1
	closemessage
	release
	end


CommonAthletesRewardScript::
	msgbox CommonAthletesRewardScript_Text_0
	setflag FLAG_FINISHED_ATHLETE_DAILY
	clearflag FLAG_DAILY_QUEST_ACTIVE
	changefactionstanding FACTION_ATHLETES, 25, FALSE
	setvar VAR_TEMP_B, 1750
	addmoney VAR_TEMP_B
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonNaturalistRewardScript_Text_1
	closemessage
	release
	end


RyuNaturalistsDailyQuest_Text_0:
	.string "I don't have anything else\nfor you to do right now, sorry!$"

RyuNaturalistsDailyQuest_Text_1:
	.string "We still need {STR_VAR_1} {STR_VAR_2}.$"

RyuNaturalistsDailyQuest_Text_2:
	.string "Hi, {PLAYER}!\nCan you get some Sitrus Berries\lfor me?\pThree of them should do.$"

RyuNaturalistsDailyQuest_Text_3:
	.string "Hi, {PLAYER}!\nCan you get some Pecha Berries\lfor me?\pTwo of them should do.$"

RyuStudentsDailyQuest_Text_0:
	.string "We don't have any requests\nright now!$"

RyuStudentsDailyQuest_Text_1:
	.string "The student council still wants \n{STR_VAR_1} {STR_VAR_2}.$"

RyuStudentsDailyQuest_Text_2:
	.string "Sup {PLAYER}!\pThe student council wants some\npotions for new members.\pWe need a total of five.$"

RyuStudentsDailyQuest_Text_3:
	.string "Heya {PLAYER}!\pThe Council wants you to get some\npoke balls for our members.\pWe need a total of ten.$"

RyuNoblesDailyQuest_Text_0:
	.string "There are no outstanding contracts.$"

RyuNoblesDailyQuest_Text_1:
	.string "The Board is still looking to\nacquire {STR_VAR_1} {STR_VAR_2}.$"

RyuNoblesDailyQuest_Text_2:
	.string "The board of Directors would like\nsome Tea for their upcoming meeting.\pPlease acquire five servings.$"

RyuNoblesDailyQuest_Text_3:
	.string "The board is trying to expand it's\nportfolio of riches.\pPlease acquire some Big Pearls\nfor us to hold.\pWe need at least eight.$"

RyuPokefansDailyQuest_Text_0:
	.string "We're all happy with what we\nhave at the moment, thanks!$"

RyuPokefansDailyQuest_Text_1:
	.string "Hello, dear, we're still trying\nto get {STR_VAR_1} {STR_VAR_2}.$"

RyuPokefansDailyQuest_Text_2:
	.string "Hello, dear.\pWe're trying to find some dolls\nto give to our kids.\pPlease find us 5 Poke Dolls.$"

RyuPokefansDailyQuest_Text_3:
	.string "Hi, {PLAYER}!\nIs there a small chance you could\lfind us five Heart Scales?\pThey're beautiful collector's items\nand we want to reward them for\la talent contest!$"

RyuOutcastsDailyQuest_Text_0:
	.string "The rituals are going as intended.$"

RyuOutcastsDailyQuest_Text_1:
	.string "Yo... we still need {STR_VAR_1} {STR_VAR_2}.$"

RyuOutcastsDailyQuest_Text_2:
	.string "Greetings, familiar stranger.\pWe're trying to conduct a ritual\nthat will summon more rare\lpokemon.\pCan you bring us some Energy Powder?\nfive portions should do. $"

RyuOutcastsDailyQuest_Text_3:
	.string "Heya {PLAYER}.\pWe recently got word that some\nrare pokemon can be attracted\lby anointing stones with stardust.\pPlease bring us five pouches of it.$"

RyuProfessionalsDailyQuest_Text_0:
	.string "I'm currently working,\nPlease come back later.$"

RyuProfessionalsDailyQuest_Text_1:
	.string "Ahh, {PLAYER}!\nHave you brought the {STR_VAR_1} {STR_VAR_2} yet?$"

RyuProfessionalsDailyQuest_Text_2:
	.string "We're running low on energy.\pCan you bring us some Soda Pops?\pWe're in a crunch to meet\nsome deadlines, the caffeine will\lhelp.\p12 of them should be enough.$"

RyuProfessionalsDailyQuest_Text_3:
	.string "I'm too busy to travel to a\nPokemon Center.\pDo you happen to have a couple\nHyper Potions?\pI'll be able to continue my work.$"

RyuAthletesDailyQuest_Text_0:
	.string "Want to join me for some\nexercise?$"

RyuAthletesDailyQuest_Text_1:
	.string "Hey, I'm in a hurry.\pDo you have the {STR_VAR_1} {STR_VAR_2} yet?$"

RyuAthletesDailyQuest_Text_2:
	.string "We're almost out of protein powder.\pCan you bring us 2 bottles of Protein?\nIt's needed for all of us who are\nactively working out!$"

RyuAthletesDailyQuest_Text_3:
	.string "We need to do some imprinting at\nthe Training Center.\pCan you bring us ten imprints?\nThis will save us a lot of time.$"

CommonNaturalistRewardScript_Text_0:
	.string "Thanks for getting the stuff!$"

CommonNaturalistRewardScript_Text_1:
	.string "You earned ¥{STR_VAR_1}.$"

CommonStudentRewardScript_Text_0:
	.string "The new kids will need all the\nhelp they can get. \pThanks, {PLAYER}!$"

CommonNobleRewardScript_Text_0:
	.string "The Board should be pleased.\nYou are dismissed.$"

CommonPokefansRewardScript_Text_0:
	.string "Thanks, dear.\nWe really appreciate your work!$"

CommonOutcastRewardScript_Text_0:
	.string "The gods shine upon you\nthis day.\lMany thanks.$"

CommonAthletesRewardScript_Text_0:
	.string "Continue to be the best you\ncan be!$"
