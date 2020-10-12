MirageCave_MapScripts::
	.byte 0

MirageCave_TriggerPortal::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_FaceUp
	@ shake screen
	@ fade screen to black
	@ play Thunder sound effect
	@ move the player one down, one left, facing right
	@ play the cries of Guzzlord, Pheromosa and Xurkitree
	setflag FLAG_NIGILEGO_ESCAPED
	setflag FLAG_BUZZWOLE_ESCAPED
	setflag FLAG_PHEROMOSA_ESCAPED
	setflag FLAG_XURKITREE_ESCAPED
	setflag FLAG_CELESTEELA_ESCAPED
	setflag FLAG_KARTANA_ESCAPED
	setflag FLAG_GUZZLORD_ESCAPED
	setflag FLAG_STAKATAKA_ESCAPED
	setmetatile 12, 3, 849, 1
	setmetatile 13, 3, 850, 1
	setmetatile 14, 3, 851, 1
	setmetatile 11, 4, 856, 1
	setmetatile 12, 4, 857, 1
	setmetatile 13, 4, 858, 1
	setmetatile 14, 4, 859, 1
	setmetatile 15, 4, 860, 1
	setmetatile 11, 5, 864, 1
	setmetatile 12, 5, 865, 1
	setmetatile 13, 5, 866, 1
	setmetatile 14, 5, 867, 1
	setmetatile 15, 5, 868, 1
	setmetatile 11, 6, 872, 1
	setmetatile 12, 6, 873, 1
	setmetatile 13, 6, 874, 1
	setmetatile 14, 6, 875, 1
	setmetatile 15, 6, 876, 1
	setmetatile 12, 7, 881, 1
	setmetatile 13, 7, 882, 1
	setmetatile 14, 7, 883, 1
	special DrawWholeMapView
	@ show screen again
	@ some text I'll put in myself
	releaseall
	end
