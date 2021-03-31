RyuOutcastsSpecialQuestIntro::
	goto_if_set FLAG_RYU_OUTCASTS_SPECIAL_STARTED, RyuOutcastsSpecialAlreadyInProgress
	msgbox AlchemyIntroQuestMsg
	closemessage
	setflag FLAG_RYU_OUTCASTS_SPECIAL_STARTED
	return


RyuOutcastsSpecialAlreadyInProgress::
	return


RyuAlchemy_LorwynsDoor::
	checkfactionstanding FACTION_OUTCASTS, 175
	compare VAR_RESULT, FALSE
	goto_if_eq Route119_EventScript_DoorIsLocked
	goto_if_unset FLAG_RYU_OUTCASTS_SPECIAL_STARTED, Route119_EventScript_DoorIsLocked
	msgbox RyuAlchemy_LorwynsDoor_Text_0
	closemessage
	warpdoor MAP_ROUTE119_LORWYNS_HOUSE, 0, 3, 5
	waitstate
	return


RyuAlchemy_LadyLorwyn::
	lock
	faceplayer
	checkfactionstanding FACTION_OUTCASTS, 175
	compare VAR_RESULT, FALSE
	goto_if_eq RA_Lorwyn_NeedsFactionStanding
	compare VAR_RYU_PLAYER_MINING_SKILL, 2
	goto_if_lt RA_Lorwyn_NeedsMining
	compare VAR_RYU_PLAYER_BOTANY_SKILL, 3
	goto_if_lt RA_Lorwyn_NeedsBotany
	goto_if_set FLAG_RYU_FINISHED_LORWYNS_TEST, RA_Lorwyn_DoTeleport
	msgbox RyuAlchemy_LadyLorwyn_Text_0
	setflag FLAG_RYU_BOSS_SCALE
	setflag FLAG_RYU_FACING_FACTION_BOSS
	trainerbattle_single TRAINER_LORWYN, LorwynBattleIntro, LorwynFinishedBattle, RA_Lorwyn_DoTeleport
	waitstate
	return


RA_Lorwyn_NeedsFactionStanding::
	msgbox RA_Lorwyn_NeedsFactionStanding_Text_0
	closemessage
	release
	end


RA_Lorwyn_NeedsMining::
	msgbox RA_Lorwyn_NeedsMining_Text_0
	closemessage
	release
	end


RA_Lorwyn_NeedsBotany::
	msgbox RA_Lorwyn_NeedsBotany_Text_0
	closemessage
	release
	end


RA_Lorwyn_DoTeleport::
	setflag FLAG_RYU_FINISHED_LORWYNS_TEST
	msgbox RA_Lorwyn_DoTeleport_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq RA_Lorwyn_ExplainVillage
	msgbox RA_Lorwyn_DoTeleport_Text_1
	closemessage
	drawfullscreenimage SCENEBGWARP
	delay 60
	clearfullscreenimage
	warpteleport MAP_LITTLEROOT_TOWN, 255, 13, 13
	waitstate
	return


RA_Lorwyn_ExplainVillage::
	msgbox RA_Lorwyn_ExplainVillage_Text_0
	closemessage
	return


RyuAlchemy_LorwynsDoor_Text_0:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}There's some archaic, ancient looking\n"
	.string "text on the door. You can't make heads\l"
	.string "or tails of it. As you were focusing on\l"
	.string "the characters, the door opens and\l"
	.string "starts to pull you in.$"

RyuAlchemy_LadyLorwyn_Text_0:
	.string "Hello, {PLAYER}. The lessers tell me\n"
	.string "that they think you are worthy of my\l"
	.string "tutelage. We shall see about that!$"

RA_Lorwyn_NeedsFactionStanding_Text_0:
	.string "What are you doing here?\p"
	.string "Leave, or I will torture you with a\n"
	.string "Voodoo doll.$"

RA_Lorwyn_NeedsMining_Text_0:
	.string "You need to be more in tune with the\n"
	.string "Earth before I will divulge anything to\l"
	.string "you.\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(You should increase your mining skill\n"
	.string "further.)$"

RA_Lorwyn_NeedsBotany_Text_0:
	.string "You are not yet one with nature. Return\n"
	.string "when your knowledge of nature has\l"
	.string "expanded.\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(You should increase your botany skill.)$"

RA_Lorwyn_DoTeleport_Text_0:
	.string "Would you like to know more about\n"
	.string "(VillageName)?$"

RA_Lorwyn_DoTeleport_Text_1:
	.string "I'm now prepared to send you to the\n"
	.string "hidden village.$"

RA_Lorwyn_ExplainVillage_Text_0:
	.string "A long time ago, Alchemy was one of the\n"
	.string "most rewarding professions. If you\l"
	.string "could do Alchemy, people from all over\l"
	.string "the world would seek you out for\l"
	.string "miracle cures, or performance boosts.\l"
	.string "However, Alchemists were typically\l"
	.string "burned at the stake if they were\l"
	.string "caught by the guards of certain\l"
	.string "kingdoms. Because of this a magical\l"
	.string "barrier was forged around the\l"
	.string "outskirts of the town, to make it look\l"
	.string "like nothing was there. As a result,\l"
	.string "this village was able to exist\l"
	.string "indefinitely in its time period.\l"
	.string "However, all of the occupants have\l"
	.string "long since died out. The only way to\l"
	.string "visit this place now, is via a special\l"
	.string "time travel spell that was almost lost\l"
	.string "to time. To my knowledge, I am the only\l"
	.string "one who can perform this spell.$"

AlchemyIntroQuestMsg::
	.string "Hello, {PLAYER}! Good news!\n"
	.string "We found a practitioner of\l"
	.string "the lost art of Alchemy!\p"
	.string "Unfortunately, she refuses\n"
	.string "to let any of us in her home!\p"
	.string "Surely she will let you in,\n"
	.string "as you're the strongest\l"
	.string "member of the Outcasts!\p"
	.string "You have to go see lady\n"
	.string "Lorwyn.\p"
	.string "You can find her house near\n"
	.string "Fortree City.\p"
	.string "She likes to be high up,\n"
	.string "close to the sky.$"

LorwynBattleIntro::
	.string "I hope you're prepared to\nface the power of the\lancients!$"

LorwynFinishedBattle::
	.string "Very impressive!\nMy ancients were of no contest!$"
