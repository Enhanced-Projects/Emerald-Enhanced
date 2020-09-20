MtFreeze_MapScripts::
	map_script ON_FRAME, MtFreeze_OpenEntranceOnFrame
	.byte 0

MtFreeze_EntranceTrigger::
	lock
	goto_if_set FLAG_MT_FREEZE_OPENED, MtFreeze_Release
	specialvar VAR_RESULT, TobyCheckPlayerHasMon
	compare VAR_RESULT, TRUE
	goto_if_eq MtFreeze_OpenEntrance1
	releaseall
	end

MtFreeze_OpenEntrance1::
	playmoncry SPECIES_CRYOGONAL, 0
	setmetatile 18, 34, 804, 1
	setmetatile 19, 34, 794, 1
	setmetatile 20, 34, 795, 1
	setmetatile 21, 34, 806, 1
	setmetatile 18, 34, 814, 1
	setmetatile 19, 35, 802, 0
	setmetatile 20, 35, 803, 0
	setmetatile 21, 34, 806, 1
	special DrawWholeMapView
	setflag FLAG_MT_FREEZE_OPENED
	releaseall
	end

MtFreeze_Release::
	releaseall
	end

MtFreeze_OpenEntranceOnFrame::
	map_script_2 VAR_TEMP_3, 0, MtFreeze_OpenEntrance2
	.2byte 0
	
MtFreeze_OpenEntrance2::
	setvar VAR_TEMP_3, 100
	goto_if_set FLAG_MT_FREEZE_OPENED, ryu_end
	setmetatile 18, 34, 753, 1
	setmetatile 19, 34, 753, 1
	setmetatile 20, 34, 753, 1
	setmetatile 21, 34, 753, 1
	setmetatile 18, 35, 753, 1
	setmetatile 19, 35, 811, 1
	setmetatile 20, 35, 811, 1
	setmetatile 21, 35, 753, 1
	special DrawWholeMapView @if the game still freezes when this activates, remove this line
	end

MtFreeze_Articuno::
	goto_if_set FLAG_RYU_ARTICUNO, ryu_end
	goto_if_set FLAG_RYU_ARTICUNO_RAN, ryu_end
	msgbox OverworldLegendary_IntroArticuno
	setvar VAR_TEMP_5, SPECIES_ARTICUNO
	setvar VAR_TEMP_9, ITEM_DRY_ICE
	call RyuLegendary_GeneralLegendEncounter
	switch VAR_RESULT
	case B_OUTCOME_RAN, MtFreeze_ArticunoGotAway
	case B_OUTCOME_LOST, MtFreeze_ArticunoGotAway
	case B_OUTCOME_MON_FLED, MtFreeze_ArticunoGotAway
	case B_OUTCOME_PLAYER_TELEPORTED, MtFreeze_ArticunoGotAway
	setflag FLAG_RYU_ARTICUNO
	removeobject 3 @Put the porymap object ID here
	release
	end

MtFreeze_ArticunoGotAway::
	setflag FLAG_RYU_ARTICUNO_RAN
	removeobject 3 @Put the porymap object ID here
	release
	end

OverworldLegendary_IntroArticuno: @put your intro here
	.string "$"
