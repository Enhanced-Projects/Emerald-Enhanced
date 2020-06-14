MtPyre_Summit_MapScripts:: @ 8231FF7
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition: @ 8231FFD
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions:: @ 8232009
	end
	
	
MPS_Spiritomb::
	goto_if_set FLAG_RYU_FINISHED_SPIRITOMB_SIDEQUEST, ryu_end
	goto_if_set FLAG_RYU_SPIRITOMB_IN_PROGRESS, MPS_SpiritombContinue
	setflag FLAG_RYU_SPIRITOMB_IN_PROGRESS
	setvar VAR_RYU_SPIRITOMB_FAINTS, 0
	msgbox MPS_SpiritombIntro
	closemessage
	@insert special gfx effect here TODO: do
	msgbox MPS_SpiritombIntro2
	closemessage
	release
	end
	
MPS_SpiritombContinue::
	compare VAR_RYU_SPIRITOMB_FAINTS, 107
	goto_if_ge MPS_SpiritombFinish
	msgbox MPS_SpiritombNotFinishedYet
	release
	end
	
MPS_SpiritombFinish::
	msgbox MPS_SpiritombUnleashed
	playmoncry SPECIES_SPIRITOMB, 2
	waitmoncry
	closemessage
	msgbox MPS_SpiritombAttacks
	playmoncry SPECIES_SPIRITOMB, 2
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setflag FLAG_TEMP_D
	setwildbattle SPECIES_SPIRITOMB, VAR_RESULT, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	setflag FLAG_RYU_FINISHED_SPIRITOMB_SIDEQUEST
	release
	end

MPS_SpiritombIntro:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}...Hey…\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}...Did that stone just talk?\p"
	.string "{COLOR RED}{SHADOW LIGHT_GREY}...Hey you...\p"
	.string "I'm a spirit trapped here, kekeke.\p"
	.string "I have an offer you can't resist…..\n"
	.string "Kekeke, do you like Master Balls?\p"
	.string "If you slay 107 innocent pokemon,\n"
	.string "come back here… kekeke.\p"
	.string "I will grant you a Master Ball…$"
	
MPS_SpiritombIntro2:
	.string "({COLOR LIGHT_GREEN}{SHADOW GREEN}A Master Ball, huh?\n"
	.string " Just for fainting some pokemon?)\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}That… sounds like a good deal.\p"
	.string "{COLOR RED}{SHADOW LIGHT_GREY}Then you better get on it…\n"
	.string "Kekeke!$"

MPS_SpiritombAttacks:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Will you give me my Master Ball now?\p"
	.string "{COLOR RED}{SHADOW LIGHT_GREY}Kekeke!\p"
	.string "KEKEKE!\p"
	.string "I have deceived you!\n"
	.string "You were merely a puppet!\p"
	.string "I just used you to gather souls!\n"
	.string "I have become powerful!\p"
	.string "Kekeke!\p"
	.string "Now we will destroy you!$"
	
MPS_SpiritombNotFinishedYet:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}Why are you still here?\n"
	.string "Gather more souls for me!$"
	
MPS_SpiritombUnleashed:
	.string "{COLOR RED}{SHADOW LIGHT_GREY}So you have returned...\n"
	.string "I have enough souls!\p"
	.string "We have enough souls!$"

MP_Gengarite::
	finditem ITEM_GENGARITE, 1
	setflag FLAG_RYU_OBTAINED_GENGARITE
	removeobject 13
	release
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0:: @ 8232018
	lockall
	goto_if_unset FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD, ryu_end
	goto_if_set FLAG_SHOWN_EON_TICKET, ryu_end
	msgbox MP_OldPeopleGiveEonTicket MSGBOX_DEFAULT
	additem ITEM_EON_TICKET
	setflag FLAG_SHOWN_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1:: @ 8232024
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2:: @ 8232030
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits:: @ 823203C
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, ryu_end
	goto_if_set FLAG_RYU_DS_SHELLY_LOVERS, MP_AltArchieFight
	playbgm MUS_MGM0, 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MP_MaxieTryingToStop MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	delay 50
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	removeobject 2
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 11
	removeobject 12
	special DrawWholeMapView
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadescreen 0
	delay 20
	setvar VAR_MT_PYRE_STATE, 4
	msgbox MP_MaxieConclusion MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MP_moveoutofway
	waitmovement 0
	applymovement 8, MP_MaxieLeaves
	waitmovement 0
	fadescreen 1
	removeobject 8
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	fadedefaultbgm
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, MP_PlayerReturnToTop
	waitmovement 0
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_SHOWN_EON_TICKET
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	setflag FLAG_RYU_MISSION4COMPLETE
	releaseall
	end

MP_PlayerReturnToTop:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
MP_MaxieConclusion:
	.string "Maxie: I guess there's nothing\nleft to do except...\lwait for the end of the world.\pCongratulations, {PLAYER}, you\nushered in the apocalypse.$"
	
MP_moveoutofway:
	walk_down
	walk_right
	step_end
	
MP_MaxieLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_EventScript_ArchieFacePlayer0:: @ 82320E0
	applymovement 2, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1:: @ 82320EB
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2:: @ 82320EC
	applymovement 2, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0:: @ 82320F7
	applymovement 3, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1:: @ 823210C
	applymovement 3, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2:: @ 8232117
	applymovement 3, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0: @ 823212C
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1: @ 8232130
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2: @ 8232132
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0: @ 8232136
	walk_left
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2: @ 8232139
	walk_right
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_EventScript_OldMan:: @ 823213C
	lock
	faceplayer
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza:: @ 8232167
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManNewTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale:: @ 8232187
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale:: @ 8232190
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale:: @ 8232199
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady:: @ 82321A2
	lock
	faceplayer
	msgbox Normal_old_lady
	release
	end

Normal_old_lady:
	.string "Have you met our grandkids?\nThey run the gym in that eastern island.\pIf you see them, tell them to\nvisit us sometime!$"

MtPyre_Summit_EventScript_OldLadyOrbsReturned:: @ 82321CB
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake:: @ 82321D8
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned:: @ 82321E2
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0:: @ 82321EC
	lockall
	setvar VAR_0x8008, 0
	goto_if_set FLAG_RYU_DS_SHELLY_LOVERS, MP_AltArchieFight
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1:: @ 82321F8
	lockall
	setvar VAR_0x8008, 1
	goto_if_set FLAG_RYU_DS_SHELLY_LOVERS, MP_AltArchieFight
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2:: @ 8232204
	lockall
	setvar VAR_0x8008, 2
	goto_if_set FLAG_RYU_DS_SHELLY_LOVERS, MP_AltArchieFight
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs:: @ 8232210
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0:: @ 82322C4
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement 2, MtPyre_Summit_Movement_MaxieExit
	applymovement 8, MtPyre_Summit_Movement_ArchieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1:: @ 82322DD
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement 2, MtPyre_Summit_Movement_MaxieExit
	applymovement 8, MtPyre_Summit_Movement_ArchieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2:: @ 82322F6
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement 2, MtPyre_Summit_Movement_MaxieExit
	applymovement 8, MtPyre_Summit_Movement_ArchieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0:: @ 823230F
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement 2, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement 8, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1:: @ 8232328
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement 2, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement 8, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2:: @ 8232341
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement 2, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement 8, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0:: @ 823235A
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement 8, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1:: @ 8232376
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement 8, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2:: @ 8232392
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement 8, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0: @ 82323AE
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie: @ 82323B2
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_MaxieExit: @ 82323B6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_ArchieExit: @ 82323BD
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0: @ 82323C4
	delay_16
	delay_8
	walk_left
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1: @ 82323CB
	delay_16
	delay_8
	walk_right
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2: @ 82323D2
	delay_16
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0: @ 82323D8
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1: @ 82323DD
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2: @ 82323E2
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie: @ 82323E7
	delay_16
	walk_in_place_fastest_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie: @ 82323EA
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0: @ 82323ED
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1: @ 82323F3
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2: @ 82323F8
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_EventScript_Grunt1:: @ 82323FD
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2:: @ 8232414
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3:: @ 823242B
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4:: @ 8232442
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MP_MaxieTryingToStop:
	.string "Maxie: Archie! I cannot allow you\nto take the orbs! You'll destroy\lthe world!\pArchie: You're too late, Maxie.\n"
	.string "While {PLAYER} was toying with\lyou, I finished my task.\pMaxie: What have you done...$"


MtPyre_Summit_Text_Grunt1Intro: @ 8232459
	.string "No! Those Team Magma goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"

MtPyre_Summit_Text_Grunt1Defeat: @ 82324A0
	.string "I thought you were one of the MAGMAS\n"
	.string "who happened to come back…$"

MtPyre_Summit_Text_Grunt1PostBattle: @ 82324E0
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"

MtPyre_Summit_Text_Grunt2Intro: @ 8232513
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you came earlier, you only would've\n"
	.string "had to battle the wimpy Team Magma.\p"
	.string "But since you arrived now, you have\n"
	.string "to take on us toughies!$"

MtPyre_Summit_Text_Grunt2Defeat: @ 82325B0
	.string "Urgh… I should've let you take on\n"
	.string "Team Magma first…$"

MtPyre_Summit_Text_Grunt2PostBattle: @ 82325E4
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"

MtPyre_Summit_Text_Grunt3Intro: @ 823261D
	.string "You…\n"
	.string "We saw you at MT. CHIMNEY.\p"
	.string "You don't belong to either TEAM,\n"
	.string "so why would you be here?$"

MtPyre_Summit_Text_Grunt3Defeat: @ 8232678
	.string "If you're going to mess with anyone,\n"
	.string "let it be TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle: @ 82326B3
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The BOSS should have snatched what\n"
	.string "he was after!$"

MtPyre_Summit_Text_Grunt4Intro: @ 823271B
	.string "Oh, I know!\n"
	.string "You tried to join Team Magma,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our Team Aqua!$"

MtPyre_Summit_Text_Grunt4Defeat: @ 823279A
	.string "If you want to join Team Aqua that\n"
	.string "badly, we can consider it…$"

MtPyre_Summit_Text_Grunt4PostBattle: @ 82327D8
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo: @ 823281A
	.string "Archie: Team Magma's Maxie was no\n"
	.string "match for you. I'm not suprised.\p"
	.string "Well anyways, we got what we came\n"
	.string "here for.\p"
	.string "You can head back to HQ. I won't\p"
	.string "have much further work for you,\n"
	.string "but you can feel free to check\p"
	.string "out our base in lilycove.\p"
	.string "There's probably some stuff laying\n"
	.string "around that you can collect.\p"
	.string "Thanks for all your hard work,\n"
	.string "soldier. You were instrumental to\p"
	.string "our cause.\p"
	.string "Team Aqua... MOVE OUT!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis: @ 823290E
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken: @ 8232AD8
	.string "The BLUE ORB and RED ORB taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"

MtPyre_Summit_Text_GroudonKyogreAwakened: @ 8232B4F
	.string "Oh, my goodness…\p"
	.string "You say that both GROUDON and KYOGRE\n"
	.string "have been awakened?\p"
	.string "It is said that the BLUE ORB and\n"
	.string "the RED ORB quelled the rage of\l"
	.string "the two Pokémon…\p"
	.string "It is also said that the true owner\n"
	.string "of the ORBS still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the ORBS belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a Pokémon, but no one knows.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs: @ 8232CA6
	.string "The two men who took the ORBS came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs: @ 8232D1E
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient Pokémon…\p"
	.string "In the same way that we humans and\n"
	.string "Pokémon have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient Pokémon have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_WillYouHearOutMyTale: @ 8232E0C
	.string "Mt. Pyre is where we calm the spirits\n"
	.string "of Pokémon that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of Hoenn…\p"
	.string "The disembodied spirits of Pokémon\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the Hoenn region?$"

MtPyre_Summit_Text_GroudonKyogreTale: @ 8232F27
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The BLUE ORB and the RED ORB brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two ORBS and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_WellThatTooIsFine: @ 8233162
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_MaxieSilence: @ 8233183
	.string "Maxie: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn: @ 82331A6
	.string "It is my role to pass on the legends\n"
	.string "of Hoenn to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "SOOTOPOLIS rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of Hoenn?$"

MtPyre_Summit_Text_HoennTrioTale: @ 823325D
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the Pokémon of\n"
	.string "the sky descended from a storm.\p"
	.string "The Pokémon, shining a vivid green,\n"
	.string "becalmed the two enraged Pokémon.\p"
	.string "Then, its duty done, the green Pokémon\n"
	.string "flew off into the wild blue yonder…$"

@==================================================================================================Special Scripts

MP_OldPeopleGiveEonTicket:
	.string "Hello, there, child. We were\ninstructed to give this to you.\p... ... ... ... ...\pWho instructed us?\nThe powers that be.  It's your fate.$"


MP_Landmark::
	lock
	setflag FLAG_RYU_LANDMARK_MTPYRE
	release
	end

MP_Courtney::
	trainerbattle_single TRAINER_COURTNEY_3, MP_Courtney_Intro, MP_Courtney_Defeat, MP_Courtney_Leave
	end
	
MP_Maxie::
	trainerbattle_single TRAINER_MAXIE_3, MP_Maxie_Intro, MP_Maxie_Defeat, MP_Maxie_Walkaway
	end

MP_Courtney_Intro:
	.string "We meet again, {PLAYER}. \p"
	.string "I'm getting real tired of you\n"
	.string "getting in Maxie's way.\p"
	.string "I'll put you down!$"
	
MP_Courtney_Defeat:	
	.string "WHY CAN'T I WIN?! It's not fair,\n"
	.string "you're cheating somehow!$"
	
MP_Courtney_Outro:
	.string "Courtney: I'm going back to the base.\n"
	.string "Sorry I let you down again, Maxie...$"
	
MP_Maxie_Intro:
	.string "I was waiting to ambush you here.\p"
	.string "After I finish with you, I'll take\n"
	.string "down Archie.\p"
	.string "If I'm not allowed to have my way,\n"
	.string "He isn't allowed to, either.$"
	
MP_Maxie_Defeat:
	.string "No matter.\p"
	.string "I'll just deal with Archie now!$"
	
MP_Courtney_Leave::
	msgbox MP_Courtney_Outro MSGBOX_DEFAULT
	waitmessage
	applymovement 9, MP_CourtLeave
	goto MP_Maxie_Walkaway
	release
	end
	
MP_Maxie_Walkaway::
	applymovement 10, MP_Maxie_Leaving
	waitmovement 0
	removeobject 10
	removeobject 9
	addobject 8
	special DrawWholeMapView
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	special DrawWholeMapView
	release
	end
	
MP_CourtLeave:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

MP_Maxie_Leaving:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MP_AltArchieFight::
	lockall
	call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	applymovement 2, MP_ArchieMoveFacePlayer
	msgbox MP_RelArchieIntro MSGBOX_DEFAULT
	closemessage
	applymovement 2, MP_ArchieReturnToOldPeople
	waitmovement 0
	msgbox MP_ArchieIntro2 MSGBOX_DEFAULT
	msgbox MP_RelShellyWait MSGBOX_DEFAULT
	waitmessage
	applymovement 2, MP_ArchieMoveFaceShelly
	waitmovement 0
	applymovement 12, Common_Movement_HeartEmote
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	msgbox MP_RelShellyReveal MSGBOX_DEFAULT
	delay 30
	applymovement 11, Common_Movement_ExclamationMark
    applymovement 2, Common_Movement_QuestionMark
	waitmovement 0 @SHITS GETTING REAL
	closemessage
	msgbox MP_ArchieBetrayal MSGBOX_DEFAULT
	waitmessage
	special SavePlayerParty 
	trainerbattle 10 TRAINER_MATT, 0, NULL, MH_MattSpcdefeat
	trainerbattle 11 TRAINER_ARCHIE, 0, NULL, MH_ArchieSpcdefeat
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, TRAINER_SHELLY_3
	setvar VAR_0x8007, TRAINER_BACK_PIC_SHELLY
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	msgbox MP_ArchieDefeated MSGBOX_DEFAULT
	fadescreen 1
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	removeobject 2
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 11
	addobject 12
	fadescreen 0
	applymovement 12, MP_ShellyStepRight
	waitmovement 0
	msgbox MP_RelShellyConfession MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne MP_RelShellyDeclined
	applymovement 12, LCC_DAWN_KISS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	msgbox MP_ShellyLeaving MSGBOX_DEFAULT
	applymovement 12, MP_ShellyExit
	waitmovement 0
	removeobject 12
	setflag FLAG_RYU_DS_SHELLY_PARTNERS
	setflag FLAG_RYU_DS_HAS_PARTNER
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_RYU_MISSION4COMPLETE
	clearflag FLAG_RYU_STARTING_M4
	setvar VAR_TEMP_0, 69
	setvar VAR_MT_PYRE_STATE, 4
	release
	end
	
MP_RelShellyDeclined:@NEUTRAL end.
	clearflag FLAG_RYU_DS_SHELLY_LOVERS
	msgbox MP_RelShellyDeclinedmsg MSGBOX_DEFAULT
	applymovement 12, MP_ShellyExit
	waitmovement 0
	removeobject 12
	clearflag FLAG_RYU_STARTING_M4
	release
	end
	
	
MP_RelArchieIntro:
	.string "Archie: Ah! {PLAYER}, nice of you\nto join us. We were just\lcollecting the Orb to awaken\lKyogre!\lNice work back at Magma's hideout.\las you can imagine, they were...\lsort of a hindrance to our plans.$"
	
MP_ArchieIntro2:
    .string "All right, old lady, give it up!$"

MP_RelShellyWait:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Wait just a minute!$"
	
MP_RelShellyReveal:
	.string "{COLOR LIGHT_RED}{SHADOW RED}As soon as I discovered your plans\l{PLAYER} and I worked out that you\lare no better than Maxie. You're\lgoing to destroy the world!\lYou see, I found love in {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}!\lAnd we're going to stop you!$"
	
MP_ArchieBetrayal:
	.string "Matt: No way! Betrayed by our very\nown Lieutenant!\p Well if you're against Archie,\nthen you're against me!\lWe need to silence you\lso that our plans can continue!$"
	
MH_MattSpcdefeat:
	.string "Matt: Shelly.. why.. how could you?$"
	
MH_ArchieSpcdefeat:
	.string "Archie: I knew there was something\n"
	.string "up with you and {PLAYER}. Didn't\p"
	.string "know it ran this deep...$"
	
MP_ArchieDefeated:
	.string "Archie: With both of you against\nus... there's no way I can\lcomplete my work... I'm just\lgoing to retire. Apparently my\ldream was inappropriate. For that\lI apologize. Shelly. Please take\lcare of Team Aqua for me. You're\l"
	.string "at the helm now.\p {PLAYER}, If it weren't for you, I might have\lcaused more harm than good.\lPlease, take care of Shelly, and\lhelp Team Aqua turn a new leaf.\lGoodbye.\l ... ... ... ... ... ...\pMatt: I don't... I can't...\nArchie...\l"
	.string "Very well. I will retire as well.\lI can't work for a traitor. I will\lget my revenge. Better keep watch!$"

MP_RelShellyConfession:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}, thanks for\nhelping me. I wouldn't have been\lable to stop Archie on my own.\lI'm sorry if I embarassed you,\lconfessing in front of everyone.\lI have to know, though...\pDo you feel the same way?$"
	
MP_RelShellyDeclinedmsg:
	.string "Shelly: Oh... I...\nI'm sorry, {PLAYER}. For what you\lhave done here, you have my\lgratitude.\lI will always remember you, and\lthe gift you gave me.\lWhen you do find someone you love,\l"
	.string "I hope they make you as happy as\lyou made me...\l... ... ... ... ...\p(Shelly turns away, and starts\nwalking sullenly towards the\lexit, tears streaming from her\leyes)$"
	
MP_ShellyLeaving:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}... I'm so happy...\p {COLOR LIGHT_GREEN}{SHADOW GREEN}(She takes a deep breath\nand wipes her eyes.)\p{COLOR LIGHT_RED}{SHADOW RED}I'm going to head back to the\noffice in Lilycove. Come visit me\lsometime, we have some things to\ldiscuss.... and other things to\ldo. I have to get Aqua's affairs\lin order anyway.$"
	
MP_ArchieReturnToOldPeople:
	walk_up
	walk_up
	walk_in_place_up
	step_end
	
MP_ShellyStepRight:
	walk_right
	walk_down
	walk_down
	walk_in_place_fastest_down
	step_end
	
MP_ShellyExit:	
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
MP_ArchieMoveFacePlayer:
	walk_down
	walk_down
	step_end
	
	
MP_ArchieMoveFaceShelly:
	walk_in_place_fast_up
	step_end
	
