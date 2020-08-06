SnowShore_MapScripts::
	map_script ON_TRANSITION, SnowShore_OnTransition
	.byte 0

SnowShore_OnTransition:
	setflag FLAG_LANDMARK_SNOWSHORE
	end

Snowshore_EventScript_TownSign::
	msgbox SnowShore_Text_TownSign, MSGBOX_SIGN
	end

SnowShore_Text_TownSign:
	.string "Snowshore\n"
	.string "“Come ashore this winter wonderland”$"

Snowshore_EventScript_CraggyCoastSign::
	msgbox SnowShore_Text_CraggyCoastSign, MSGBOX_SIGN
	end

SnowShore_Text_CraggyCoastSign:
	.string "{LEFT_ARROW} Craggy Coast\n"
	.string "Snowshore {RIGHT_ARROW} $"

Snowshore_EventScript_MrFrigusSign::
	msgbox SnowShore_Text_MrFrigusSign, MSGBOX_SIGN
	end

SnowShore_Text_MrFrigusSign:
	.string "Mr Frigus's house\n"
	.string "“Learn about the island's past”$"

Snowshore_BigPearl::
	lockall
	goto_if_set FLAG_HIDDEN_SNOWSHORE_BIG_PEARL, FrostyForestEnd
	giveitem ITEM_BIG_PEARL
	setflag FLAG_HIDDEN_SNOWSHORE_BIG_PEARL
	release
	end

Snowshore_HeartScale::
	lockall
	goto_if_set FLAG_HIDDEN_SNOWSHORE_HEART_SCALE, FrostyForestEnd
	giveitem ITEM_HEART_SCALE
	setflag FLAG_HIDDEN_SNOWSHORE_HEART_SCALE
	release
	end

Snowshore_EventScript_Girl::
	lock
	faceplayer
	msgbox Snowshore_Text_MyGarden, MSGBOX_DEFAULT
	release
	end

Snowshore_Text_MyGarden:
	.string "Isn't my garden pretty? I take\n"
	.string "good care of it!$"

Snowshore_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox Snowshore_Text_SlidingOnIce, MSGBOX_DEFAULT
	release
	end

Snowshore_Text_SlidingOnIce:
	.string "I love sliding on ice!$"

Snowshore_EventScript_OldWoman::
	lock
	faceplayer
	msgbox Snowshore_Text_MtFreeze, MSGBOX_DEFAULT
	release
	end

Snowshore_Text_MtFreeze:
	.string "Further north along this path is\n"
	.string "Mt Freeze.\p"
	.string "Very, very long ago the mountain\n"
	.string "was a volcano.\p"
	.string "According to old folklore, a\n"
	.string "legendary bird lives on top, and\l"
	.string "it's the cause of the cold climate.$"

Snowshore_EventScript_Woman::
	lock
	faceplayer
	msgbox Snowshore_Text_Compost, MSGBOX_DEFAULT
	release
	end

Snowshore_Text_Compost:
	.string "Despite the cold climate, we are\n"
	.string "able to grow flowers with compost\l"
	.string "made from Aspear Berries.$"

Snowshore_EventScript_Man::
	lock
	faceplayer
	msgbox Snowshore_Text_ThickFat, MSGBOX_DEFAULT
	release
	end

Snowshore_Text_ThickFat:
	.string "My Azumarill doesn't care about the\n"
	.string "cold, it has Thick Fat!$"

Snowshore_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox Snowshore_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Snowshore_Text_Azumarill:
	.string "Azumarill: Mari mareeeeeeeeeeeeeee\n"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\p"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\p"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\p"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\p"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n"
	.string "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee!$"

Snowshore_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD, Snowshore_Text_HaroldIntro, Snowshore_Text_HaroldDefeated
	msgbox Snowshore_Text_HaroldPostBattle, MSGBOX_AUTOCLOSE
	end

Snowshore_EventScript_Tim::
	trainerbattle_single TRAINER_TIM, Snowshore_Text_TimIntro, Snowshore_Text_TimDefeated
	msgbox Snowshore_Text_TimPostBattle, MSGBOX_AUTOCLOSE
	end

Snowshore_EventScript_Jim::
	trainerbattle_single TRAINER_JIM, Snowshore_Text_JimIntro, Snowshore_Text_JimDefeated
	msgbox Snowshore_Text_JimPostBattle, MSGBOX_AUTOCLOSE
	end

Snowshore_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE, Snowshore_Text_JoyceIntro, Snowshore_Text_JoyceDefeated
	msgbox Snowshore_Text_JoycePostBattle, MSGBOX_AUTOCLOSE
	end

Snowshore_EventScript_Delton::
	trainerbattle_single TRAINER_DELTON, Snowshore_Text_DeltonIntro, Snowshore_Text_DeltonDefeated
	msgbox Snowshore_Text_DeltonPostBattle, MSGBOX_AUTOCLOSE
	end

Snowshore_EventScript_Marcus::
	trainerbattle_single TRAINER_MARCUS, Snowshore_Text_MarcusIntro, Snowshore_Text_MarcusDefeated
	msgbox Snowshore_Text_MarcusPostBattle, MSGBOX_AUTOCLOSE
	end

Snowshore_EventScript_Nick::
	trainerbattle_single TRAINER_NICK, Snowshore_Text_NickIntro, Snowshore_Text_NickDefeated
	msgbox Snowshore_Text_NickPostBattle, MSGBOX_AUTOCLOSE
	end
