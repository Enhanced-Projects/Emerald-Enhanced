SlateportCity_SternsShipyard_2F_MapScripts:: @ 820863D
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1:: @ 820863E
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2:: @ 8208647
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding: @ 8208650
	.string "Designing a large ship is more like\n"
	.string "making a big building than putting\l"
	.string "together a transportation vehicle.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy: @ 82086BA
	.string "Don't you think it's strange that\n"
	.string "a ship made of heavy iron floats?\p"
	.string "It floats because of a principle\n"
	.string "called buoyancy.$"

@==================================================================================================Aqua

SS_2FDevonPresTrigger::
	setvar VAR_RYU_AQUA, 113 @player cleared first floor of shipyard out, start president event.
	lockall
	msgbox SS_AndHereIThought
	closemessage
	applymovement 4, SS_StoneToPlayer
	waitmovement 4
	msgbox SS_JudgingBy
	closemessage
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 4
	msgbox SS_ItSeemsYou
	closemessage
	delay 30
	msgbox SS_ToSeeThe
	closemessage
	trainerbattle_single TRAINER_MR_STONE, SS_StoneIntro, SS_StoneDefeat, SS_PostStoneBattle
	goto SS_PostStoneBattle

SS_PostStoneBattle::
	setvar VAR_RYU_AQUA, 115 @player defeated Mr Stone
	msgbox SS_FutureDoesntLookBright
	closemessage
	setflag FLAG_RYU_HIDE_SHIPYARD_DEVON_EMPLOYEES
	warpsilent MAP_SLATEPORT_CITY, 255, 56, 39
	waitstate

SS_AndHereIThought:
	.string "And here I thought we'd finally be\n"
    .string "free of the interruptions...$"

SS_JudgingBy:
	.string "Judging by the description my son\n"
    .string "mentioned, you're the one causing so\l"
    .string "much mischief.$"

SS_ItSeemsYou:
	.string "It seems you have a Pokénav...\p"
    .string "That Shelly...she must've nicked a\n"
    .string "copy of the research documents the\l"
    .string "day she left my company.$"

SS_ToSeeThe:
	.string "To see the achievements of Devon\n"
    .string "being utilized in such a manner makes\l"
    .string "my blood boil...$"

SS_StoneIntro:
	.string "I believe it's way past time to teach\n"
    .string "you lot not to mess with Devon Corp.!$"

SS_StoneDefeat:
	.string "You're quite strong, young one.$"

SS_FutureDoesntLookBright:
	.string "Your future doesn't look very\nbright though...\pI'll see to that!$"

SS_StoneToPlayer:
	walk_left
	walk_left
	walk_left
	step_end
