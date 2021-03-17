RyuNaturalistsDailyQuest::
	goto_if_set FLAG_FINISHED_NATURALIST_DAILY, RyuNaturalistsDailyQuest_2
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuNaturalistsDailyQuest_10
RyuNaturalistsDailyQuest_8:
	goto_if_set FLAG_DAILY_QUEST_ACTIVE, RyuNaturalistsDailyQuest_7
RyuNaturalistsDailyQuest_4:
	random 2
	switch VAR_RESULT
	case 0, RyuNaturalistsDailyQuest_15
	case 1, RyuNaturalistsDailyQuest_16
RyuNaturalistsDailyQuest_13:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NATURALISTS
	closemessage
	release
	end

RyuNaturalistsDailyQuest_2:
	msgbox RyuNaturalistsDailyQuest_Text_0
	release
	end

RyuNaturalistsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuNaturalistsDailyQuest_18
	case 2, RyuNaturalistsDailyQuest_19
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

RyuNaturalistsDailyQuest_15:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_SITRUS_BERRY
	setvar VAR_RYU_DAILY_QUEST_DATA, 3
	msgbox RyuNaturalistsDailyQuest_Text_2
	goto RyuNaturalistsDailyQuest_13

RyuNaturalistsDailyQuest_16:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_PECHA_BERRY
	setvar VAR_RYU_DAILY_QUEST_DATA, 2
	msgbox RyuNaturalistsDailyQuest_Text_3
	goto RyuNaturalistsDailyQuest_13

RyuNaturalistsDailyQuest_18:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuNaturalistsDailyQuest_21
	case FALSE, RyuNaturalistsDailyQuest_22
	goto RyuNaturalistsDailyQuest_4

RyuNaturalistsDailyQuest_19:
	end

RyuNaturalistsDailyQuest_21:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonNaturalistRewardScript
	goto RyuNaturalistsDailyQuest_4

RyuNaturalistsDailyQuest_22:
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
	case 0, RyuStudentsDailyQuest_15
	case 1, RyuStudentsDailyQuest_16
RyuStudentsDailyQuest_13:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_STUDENTS
	closemessage
	release
	end

RyuStudentsDailyQuest_2:
	msgbox RyuStudentsDailyQuest_Text_0
	release
	end

RyuStudentsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuStudentsDailyQuest_18
	case 2, RyuStudentsDailyQuest_19
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

RyuStudentsDailyQuest_15:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_POTION
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	msgbox RyuStudentsDailyQuest_Text_2
	goto RyuStudentsDailyQuest_13

RyuStudentsDailyQuest_16:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_POKE_BALL
	setvar VAR_RYU_DAILY_QUEST_DATA, 10
	msgbox RyuStudentsDailyQuest_Text_3
	goto RyuStudentsDailyQuest_13

RyuStudentsDailyQuest_18:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuStudentsDailyQuest_21
	case FALSE, RyuStudentsDailyQuest_22
	goto RyuStudentsDailyQuest_4

RyuStudentsDailyQuest_19:
	end

RyuStudentsDailyQuest_21:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonStudentRewardScript
	goto RyuStudentsDailyQuest_4

RyuStudentsDailyQuest_22:
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
	case 0, RyuNoblesDailyQuest_15
	case 1, RyuNoblesDailyQuest_16
RyuNoblesDailyQuest_13:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_NOBLES
	closemessage
	release
	end

RyuNoblesDailyQuest_2:
	msgbox RyuNoblesDailyQuest_Text_0
	release
	end

RyuNoblesDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuNoblesDailyQuest_18
	case 2, RyuNoblesDailyQuest_19
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

RyuNoblesDailyQuest_15:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_TEA
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	msgbox RyuNoblesDailyQuest_Text_2
	goto RyuNoblesDailyQuest_13

RyuNoblesDailyQuest_16:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_BIG_PEARL
	setvar VAR_RYU_DAILY_QUEST_DATA, 8
	msgbox RyuNoblesDailyQuest_Text_3
	goto RyuNoblesDailyQuest_13

RyuNoblesDailyQuest_18:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuNoblesDailyQuest_21
	case FALSE, RyuNoblesDailyQuest_22
	goto RyuNoblesDailyQuest_4

RyuNoblesDailyQuest_19:
	end

RyuNoblesDailyQuest_21:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonNobleRewardScript
	goto RyuNoblesDailyQuest_4

RyuNoblesDailyQuest_22:
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
	case 0, RyuPokefansDailyQuest_15
	case 1, RyuPokefansDailyQuest_16
RyuPokefansDailyQuest_13:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_POKEFANS
	closemessage
	release
	end

RyuPokefansDailyQuest_2:
	msgbox RyuPokefansDailyQuest_Text_0
	release
	end

RyuPokefansDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuPokefansDailyQuest_18
	case 2, RyuPokefansDailyQuest_19
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

RyuPokefansDailyQuest_15:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_POKE_DOLL
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	msgbox RyuPokefansDailyQuest_Text_2
	goto RyuPokefansDailyQuest_13

RyuPokefansDailyQuest_16:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_HEART_SCALE
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	msgbox PokefansQuest2Desc
	goto RyuPokefansDailyQuest_13

RyuPokefansDailyQuest_18:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuPokefansDailyQuest_21
	case FALSE, RyuPokefansDailyQuest_22
	goto RyuPokefansDailyQuest_4

RyuPokefansDailyQuest_19:
	end

RyuPokefansDailyQuest_21:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonPokefansRewardScript
	goto RyuPokefansDailyQuest_4

RyuPokefansDailyQuest_22:
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
	case 0, RyuOutcastsDailyQuest_15
	case 1, RyuOutcastsDailyQuest_16
RyuOutcastsDailyQuest_13:
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_OUTCASTS
	setflag FLAG_DAILY_QUEST_ACTIVE
	closemessage
	release
	end

RyuOutcastsDailyQuest_2:
	msgbox RyuOutcastsDailyQuest_Text_0
	release
	end

RyuOutcastsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuOutcastsDailyQuest_18
	case 2, RyuOutcastsDailyQuest_19
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

RyuOutcastsDailyQuest_15:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_ENERGY_POWDER
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	msgbox OutcastsQuest1Desc
	goto RyuOutcastsDailyQuest_13

RyuOutcastsDailyQuest_16:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_STARDUST
	setvar VAR_RYU_DAILY_QUEST_DATA, 5
	msgbox RyuOutcastsDailyQuest_Text_2
	goto RyuOutcastsDailyQuest_13

RyuOutcastsDailyQuest_18:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuOutcastsDailyQuest_21
	case FALSE, RyuOutcastsDailyQuest_22
	goto RyuOutcastsDailyQuest_4

RyuOutcastsDailyQuest_19:
	end

RyuOutcastsDailyQuest_21:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonOutcastRewardScript
	goto RyuOutcastsDailyQuest_4

RyuOutcastsDailyQuest_22:
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
	case 0, RyuProfessionalsDailyQuest_15
	case 1, RyuProfessionalsDailyQuest_16
RyuProfessionalsDailyQuest_13:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_PROFESSIONALS
	closemessage
	release
	end

RyuProfessionalsDailyQuest_2:
	msgbox RyuProfessionalsDailyQuest_Text_0
	release
	end

RyuProfessionalsDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuProfessionalsDailyQuest_18
	case 2, RyuProfessionalsDailyQuest_19
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

RyuProfessionalsDailyQuest_15:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_SODA_POP
	setvar VAR_RYU_DAILY_QUEST_DATA, 12
	msgbox ProfessionalsQuestDesc1
	goto RyuProfessionalsDailyQuest_13

RyuProfessionalsDailyQuest_16:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_HYPER_POTION
	setvar VAR_RYU_DAILY_QUEST_DATA, 2
	msgbox RyuProfessionalsDailyQuest_Text_2
	goto RyuProfessionalsDailyQuest_13

RyuProfessionalsDailyQuest_18:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuProfessionalsDailyQuest_21
	case FALSE, RyuProfessionalsDailyQuest_22
	goto RyuProfessionalsDailyQuest_4

RyuProfessionalsDailyQuest_19:
	end

RyuProfessionalsDailyQuest_21:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonProfessionalsRewardScript
	goto RyuProfessionalsDailyQuest_4

RyuProfessionalsDailyQuest_22:
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
	case 0, RyuAthletesDailyQuest_15
	case 1, RyuAthletesDailyQuest_16
RyuAthletesDailyQuest_13:
	setflag FLAG_DAILY_QUEST_ACTIVE
	setvar VAR_RYU_DAILY_QUEST_ASSIGNEE_FACTION, FACTION_ATHLETES
	closemessage
	release
	end

RyuAthletesDailyQuest_2:
	msgbox RyuAthletesDailyQuest_Text_0
	release
	end

RyuAthletesDailyQuest_5:
	switch VAR_RYU_DAILY_QUEST_TYPE
	case 1, RyuAthletesDailyQuest_18
	case 2, RyuAthletesDailyQuest_19
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

RyuAthletesDailyQuest_15:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_PROTEIN
	setvar VAR_RYU_DAILY_QUEST_DATA, 2
	msgbox RyuAthletesDailyQuest_Text_2
	goto RyuAthletesDailyQuest_13

RyuAthletesDailyQuest_16:
	setvar VAR_RYU_DAILY_QUEST_TYPE, 1
	setvar VAR_RYU_DAILY_QUEST_TARGET, ITEM_WAVE_MAIL
	setvar VAR_RYU_DAILY_QUEST_DATA, 10
	msgbox RyuAthletesDailyQuest_Text_3
	goto RyuAthletesDailyQuest_13

RyuAthletesDailyQuest_18:
	checkitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	switch VAR_RESULT
	case TRUE, RyuAthletesDailyQuest_21
	case FALSE, RyuAthletesDailyQuest_22
	goto RyuAthletesDailyQuest_4

RyuAthletesDailyQuest_19:
	end

RyuAthletesDailyQuest_21:
	removeitem VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	goto CommonAthletesRewardScript
	goto RyuAthletesDailyQuest_4

RyuAthletesDailyQuest_22:
	buffernumberstring 0, VAR_RYU_DAILY_QUEST_DATA
	bufferitemnameplural 1, VAR_RYU_DAILY_QUEST_TARGET, VAR_RYU_DAILY_QUEST_DATA
	msgbox RyuAthletesDailyQuest_Text_1
	release
	end


CommonNaturalistRewardScript::
	msgbox CommonNaturalistRewardScript_Text_0
	setflag FLAG_FINISHED_NATURALIST_DAILY
	changefactionstanding FACTION_NATURALISTS, 25, FALSE
	setvar VAR_TEMP_B, 1000
	goto CommonDailyQuestEnd
	return


CommonStudentRewardScript::
	msgbox CommonStudentRewardScript_Text_0
	setflag FLAG_FINISHED_STUDENT_DAILY
	changefactionstanding FACTION_STUDENTS, 25, FALSE
	setvar VAR_TEMP_B, 3000
	goto CommonDailyQuestEnd
	return


CommonNobleRewardScript::
	msgbox CommonNobleRewardScript_Text_0
	setflag FLAG_FINISHED_NOBLE_DAILY
	changefactionstanding FACTION_NOBLES, 25, FALSE
	setvar VAR_TEMP_B, 10000
	goto CommonDailyQuestEnd
	return


CommonPokefansRewardScript::
	msgbox CommonPokefansRewardScript_Text_0
	setflag FLAG_FINISHED_POKEFAN_DAILY
	changefactionstanding FACTION_POKEFANS, 25, FALSE
	setvar VAR_TEMP_B, 2500
	goto CommonDailyQuestEnd
	return


CommonOutcastRewardScript::
	msgbox CommonOutcastRewardScript_Text_0
	setflag FLAG_FINISHED_OUTCAST_DAILY
	changefactionstanding FACTION_OUTCASTS, 25, FALSE
	setvar VAR_TEMP_B, 2000
	goto CommonDailyQuestEnd
	return


CommonProfessionalsRewardScript::
	msgbox CommonNobleRewardScript_Text_0
	setflag FLAG_FINISHED_PROFESSIONAL_DAILY
	changefactionstanding FACTION_PROFESSIONALS, 25, FALSE
	setvar VAR_TEMP_B, 4000
	goto CommonDailyQuestEnd
	return


CommonAthletesRewardScript::
	msgbox CommonAthletesRewardScript_Text_0
	setflag FLAG_FINISHED_ATHLETE_DAILY
	changefactionstanding FACTION_ATHLETES, 25, FALSE
	setvar VAR_TEMP_B, 1750
	goto CommonDailyQuestEnd
	return


CommonDailyQuestEnd::
	addmoney VAR_TEMP_B
	clearflag FLAG_DAILY_QUEST_ACTIVE
	buffernumberstring 0, VAR_TEMP_B
	msgbox CommonDailyQuestEnd_Text_0
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

RyuOutcastsDailyQuest_Text_0:
	.string "The rituals are going as intended.$"

RyuOutcastsDailyQuest_Text_1:
	.string "Yo... we still need {STR_VAR_1} {STR_VAR_2}.$"

RyuOutcastsDailyQuest_Text_2:
	.string "Heya {PLAYER}.\pWe recently got word that some\nrare pokemon can be attracted\lby anointing stones with stardust.\pPlease bring us five pouches of it.$"

RyuProfessionalsDailyQuest_Text_0:
	.string "I'm currently working,\nPlease come back later.$"

RyuProfessionalsDailyQuest_Text_1:
	.string "Ahh, {PLAYER}!\nHave you brought the {STR_VAR_1} {STR_VAR_2} yet?$"

RyuProfessionalsDailyQuest_Text_2:
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

CommonDailyQuestEnd_Text_0:
	.string "You earned ¥{STR_VAR_1}.$"

ProfessionalsQuestDesc1::
	.string "We're running low on energy.\p"
	.string "Can you bring us some Soda Pops?\p"
	.string "We're in a crunch to meet\n"
	.string "some deadlines, the caffeine will\l"
	.string "help.\p"
	.string "Twelve of them should be enough.$"

OutcastsQuest1Desc::
	.string "Greetings, familiar stranger.\p"
	.string "We're trying to conduct a ritual\n"
	.string "that will summon more rare\l"
	.string "pokemon.\p"
	.string "Can you bring us some Energy Powder?\n"
	.string "five portions should do.$"

PokefansQuest2Desc::
	.string "Hi, {PLAYER}!\n"
	.string "Is there a small chance you could\l"
	.string "find us five Heart Scales?\p"
	.string "They're beautiful collector's items\n"
	.string "and we want to reward them for\l"
	.string "a talent contest!$"
