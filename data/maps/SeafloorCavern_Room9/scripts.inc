SeafloorCavern_Room9_MapScripts:: @ 8234DC8
	.byte 0
	
SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
    releaseall
    end

SFC_AltKyogre::
	lockall
	goto_if_set FLAG_RYU_KYOGRE, ryu_end
	goto_if_unset FLAG_RYU_AQUA_LINE_DONE, ryu_end
	msgbox SFC_KyogreStaringIntently MSGBOX_DEFAULT
	playmoncry SPECIES_KYOGRE, 0
	closemessage
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	waitmoncry
	delay 10
	fadescreen 1
	removeobject 7
	removeobject 1
	fadescreen 0
	setwildbattle SPECIES_KYOGRE, VAR_RESULT, ITEM_MYSTIC_WATER
	setflag FLAG_RYU_KYOGRE
	special BattleSetup_StartLegendaryBattle
	waitstate
	setvar VAR_SKY_PILLAR_STATE, 3
	releaseall
	end
	
SFC_KyogreStaringIntently:
	.string "Kyogre is staring intently at you.$"
	
SFC_Setflags::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	setflag FLAG_RYU_AQUA_LINE_DONE
	clearflag FLAG_RYU_KYOGRE
	releaseall
	end
	
SFC9_Archie::
	lockall
	faceplayer
	msgbox SFC9_SoYoureThe
	closemessage
	trainerbattle_single TRAINER_ARCHIE, SFC9ArchieIntro, SFC9ArchieDefeat, SFC9_ArchieSceneEnd
	goto SFC9_ArchieSceneEnd
	
SFC9_ArchieSceneEnd::
	msgbox SFC9_ItSeemsIm, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SFC9_TakeOpportunity
	goto SFC9_CompleteTheMission
	setvar VAR_RYU_MAGMA, 450@Player completed the mission, Return to magma HQ.
	goto_if_unset FLAG_RYU_DS_COURTNEY_CLOSEFRIENDS, SFC9_CancelCourtney
	release
	end
	
SFC9_CancelCourtney::
	clearflag FLAG_RYU_DS_COURTNEY_FRIENDS
	goto ryu_end
	
SFC9_TakeOpportunity::
	msgbox SFC9_ActuallyIhave
	closemessage
	playse SE_PIN
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 2
	msgbox SFC9_ADealThis
	closemessage
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 2
	delay 40
	msgbox SFC9_TeamMagmaTo
	closemessage
	delay 40
	msgbox SFC9_BecauseTheAlternative
	closemessage
	delay 40
	msgbox SFC9_Ellipsis
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 2, Common_Movement_FaceUp
	waitmovement 2
	call SFC_DoKyogreAnimation
	setvar VAR_RYU_MAGMA, 550@player's doing alternate magma line
	warpsilent MAP_SOOTOPOLIS_CITY_MAGMA_EVENT, 255, 20, 37
	waitstate
	
SFC9_CompleteTheMission::
	applymovement OBJ_EVENT_ID_PLAYER, SFC9_WalkInPlaceTakeOrb
	waitmovement OBJ_EVENT_ID_PLAYER
	giveitem ITEM_BLUE_ORB, 1
	closemessage
	delay 40
	msgbox SFC9_AquaGone
	closemessage
	delay 40
	applymovement 2, Common_Movement_FaceUp
	waitmovement 2
	msgbox SFC9_LeaveUsBe
	closemessage
	setvar VAR_RYU_MAGMA, 450@Player's doing the main magma line
	clearflag FLAG_RYU_MAXIE_END_EVENT
	warpsilent MAP_MAGMA_HIDEOUT_4F, 255, 5, 13
	
SFC9_Shelly::
	trainerbattle_single TRAINER_SHELLY_2, SFC9ShellyIntro, SFC9ShellyDefeat
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	removeobject 5
	releaseall
	end
	
SFC9_Matt::
	trainerbattle_single TRAINER_MATT, SFC9MattIntro, SFC9MattDefeat
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	removeobject 6
	releaseall
	end

SFC9ShellyIntro:
	.string "To get through all of Team Aqua...\n"
    .string "you're quite the capable one, but-$"

SFC9ShellyDefeat:
	.string "How could this be!?$"

SFC9MattIntro:
	.string "Bro's about to awaken the sea beast\n"
    .string "Kyogre, and we're not letting you get\p"
    .string "past us!$"

SFC9MattDefeat:
	.string "I'm sorry, Bro...$"
	
SFC9_AquaGone:
	.string "I've no other options. I shall\n"
	.string "return to my roots, and try to\l"
	.string "live a normal life.\p"
	.string "That is, if the world doesn't\n"
	.string "end...$"
	
SFC9_SoYoureThe:
	.string "So...you're the one who's been\n"
    .string "causin' all kinda unrest in Hoenn.\p"
    .string "Quite a shame that is...for all the\n"
    .string "ill deeds you've done, you've got a\l"
    .string "gift.\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}It's over, Aqua Leader Archie.\n"
    .string "My mission is to stop you.\l"
    .string "I will not fail.$"

SFC9ArchieIntro:
	.string "Then there's no use for chatter.\n"
    .string "Time to start walkin' the plank!$"

SFC9ArchieDefeat:
	.string "Is this really how our tale ends...?$"
	
SFC9_LeaveUsBe:
	.string "Now leave us be.\n"
    .string "Groudon must be ready to be awakened\l"
    .string "at any moment.$"
	
SFC9_ActuallyIhave:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Actually, I have a proposition.$"

SFC9_ADealThis:
	.string "A deal? At this stage of the game?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}I want to take over Team Magma.$"

SFC9_TeamMagmaTo:
	.string "Team Magma, to be led by a whelp\n"
    .string "like you...give me one reason why I\l"
    .string "should.$"

SFC9_BecauseTheAlternative:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Because the alternative is to lose\n"
    .string "everything you and your team stand\l"
    .string "for.\p"
    .string "You've got no other option.$"

SFC9_Ellipsis:
	.string "... ... ... ...\n"
    .string "Heh, feels like I'm walking down the\l"
    .string "plank myself…\p"
	.string "Hah, you'd have done good in\n"
	.string "Team Aqua. That is\p"
	.string "a prime example of pirate\n"
	.string "treachery. I love it.\p"
    .string "What's the plan then?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}First, Kyogre...$"
	
SFC9_ItSeemsIm:
	.string "It seems I'm at my wits' end…\n"
    .string "Listen, young one...you've no idea\l"
    .string "what you're allowing Maxie to do...\p"
    .string "The choice is yours, {PLAYER}.\p"
	.string "Should we take out Maxie?$"
	
SFC9_WalkInPlaceTakeOrb:
	walk_in_place_slow_down
	walk_in_place_slow_up
	step_end


SFC_DoKyogreAnimation::
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SFC_BlueOrbShines, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_W197
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 1
	playfanfare MUS_ME_TAMA
	playse SE_TAMA
	special DoOrbEffect
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject 4  @ sleeping Kyogre
	addobject 1     @ awakened Kyogre
	waitstate
	delay 60
	applymovement 1, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 1, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject 1
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	return
	
SFC_BlueOrbShines:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (The Blue Orb shines brightly)$"
	
SeafloorCavern_Room9_Movement_KyogreExit: @ 823504B
	slide_up
	slide_up
	step_end
	
SeafloorCavern_Room9_Movement_KyogreApproach: @ 8235040
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end
	
SCME_BlueOrbEffect::
	setweather WEATHER_NONE
	doweather
	msgbox SFC_BlueOrbShines, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_W197
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 1
	special DoOrbEffect
	waitstate
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	removeobject 2
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	return

















