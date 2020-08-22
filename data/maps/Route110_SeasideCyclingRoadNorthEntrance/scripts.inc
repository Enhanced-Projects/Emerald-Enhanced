Route110_SeasideCyclingRoadNorthEntrance_MapScripts:: @ 826EA77
	.byte 0

Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk:: @ 826EA78
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release

Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad: @ 826EAC1
	.string "On CYCLING ROAD, you can go all out\n"
	.string "and cycle as fast as you'd like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"
