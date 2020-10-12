@@Frontier mode scripts


RyuFrontierModeStarterMenu::
    msgbox RyuFrontierStarterMenuIntro
    closemessage
	goto RyuFrontierStarterMenu1
	
RyuFrontierStarterMenuIntro:
	.string "Please choose from the\nfollowing list of\lstarter teams.$"
	
RF_CompletedGivingStarter:
	.string "Your Frontier starter\nteam has been given.\pEnjoy frontier mode!$"
	
RF_ChooseThisSet:
	.string "Is this the starter set\nyou want to use?$"
	
	
RyuFrontierStarterMenu1::
	multichoicedefault 0, 0, MULTI_FRONTIERMODE_STARTER1, 1, 1
	switch VAR_RESULT
	case 0, RF_StarterMenu3Jump
	case 1, RF_HyperOffense
	case 2, RF_Offense
	case 3, RF_Balance
	case 4, RF_BulkyOffense
	case 5, RF_Stall
	case 6, RF_Blank1
	case 7, RF_Blank1
	case 8, RF_StarterMenu2Jump
	goto RF_Blank1
	
RyuFrontierStarterMenu2::
	multichoicedefault 0, 0, MULTI_FRONTIERMODE_STARTER2, 1, 1
	switch VAR_RESULT
	case 0, RF_StarterMenu1Jump
	case 1, RF_Hail
	case 2, RF_Rain
	case 3, RF_Sun
	case 4, RF_Sandstorm
	case 5, RF_GrassyTerrain
	case 6, RF_PsychicTerrain
	case 7, RF_TrickRoom
	case 8, RF_StarterMenu3Jump
	goto RF_Blank2
	
RyuFrontierStarterMenu3::
	multichoicedefault 0, 0, MULTI_FRONTIERMODE_STARTER3, 1, 1
	switch VAR_RESULT
	case 0, RF_StarterMenu2Jump
	case 1, RF_BatonPass
	case 2, RF_Gimmick
	case 3, RF_Eggtactical
	case 4, RF_Masochist
	case 5, RF_Fear
	case 6, RF_Blank3
	case 7, RF_Blank3
	case 8, RF_StarterMenu1Jump
	goto RF_Blank3

RF_StarterMenu3Jump::
    goto RyuFrontierStarterMenu3

RF_StarterMenu2Jump::
    goto RyuFrontierStarterMenu2

RF_StarterMenu1Jump::
    goto RyuFrontierStarterMenu1
	

RF_HyperOffense::
	drawinfobox INFOBOX_F_STARTER_HYPER_OFFENSE
	msgbox RF_HyperOffenseIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu1
	setvar VAR_TEMP_A, FRONTIER_MON_ARIADOS_HYPER_OFFENSE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_TOXICROAK_HYPER_OFFENSE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_ZANGOOSE_HYPER_OFFENSE
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end

RF_HyperOffenseIntro:
	.string "Showing the Hyper Offense team\ndescription.$"
	
RF_Offense::
	drawinfobox INFOBOX_F_STARTER_OFFENSE
	msgbox RF_OffenseIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu1
	setvar VAR_TEMP_A, FRONTIER_MON_AURORUS_OFFENSE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_BEARTIC_OFFENSE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_MEGA_GALLADE_OFFENSE
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_OffenseIntro:
	.string "Showing the Offense team\ndescription.$"
	
RF_Balance::
	drawinfobox INFOBOX_F_STARTER_BALANCE
	msgbox RF_BalanceIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu1
	setvar VAR_TEMP_A, FRONTIER_MON_TYPHLOSION_BALANCE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_FERALIGATR_BALANCE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_VENUSAUR_BALANCE
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_BalanceIntro:
	.string "Showing the Balance team\ndescription.$"
		
RF_BulkyOffense::
	drawinfobox INFOBOX_F_STARTER_BULKY_OFFENSE
	msgbox RF_BulkyOffenseIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu1
	setvar VAR_TEMP_A, FRONTIER_MON_SWAMPERT_BULKY_OFFENSE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_RHYDON_BULKY_OFFENSE
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_MEGANIUM_BULKY_OFFENSE
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_BulkyOffenseIntro:
	.string "Showing the Bulky Offense team\ndescription.$"
	
RF_Stall::
	drawinfobox INFOBOX_F_STARTER_STALL
	msgbox RF_StallIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu1
	setvar VAR_TEMP_A, FRONTIER_MON_REGICE_STALL
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_SLOWBRO_STALL
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_GLISCOR_STALL
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_StallIntro:
	.string "Showing the Stall team description.$"

@starter menu 2
RF_Hail::
	drawinfobox INFOBOX_F_STARTER_HAIL
	msgbox RF_HailIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu2
	setvar VAR_TEMP_A, FRONTIER_MON_WALREIN_HAIL
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_DEWGONG_HAIL
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_RAIKOU_HAIL
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_HailIntro:
	.string "Showing the Hail team description.$"
	
RF_Rain::
	drawinfobox INFOBOX_F_STARTER_RAIN
	msgbox RF_RainIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu2
	setvar VAR_TEMP_A, FRONTIER_MON_LAPRAS_RAIN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_SEISMITOAD_RAIN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_ROTOM_FAN_RAIN
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_RainIntro:
	.string "Showing the Rain team description.$"
	
RF_Sun::
	drawinfobox INFOBOX_F_STARTER_SUN
	msgbox RF_SunIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu2
	setvar VAR_TEMP_A, FRONTIER_MON_MAGCARGO_SUN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_VICTREEBEL_SUN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_MEGA_HOUNDOOM_SUN
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_SunIntro:
	.string "Showing the Sun team description.$"
	
RF_Sandstorm::
	drawinfobox INFOBOX_F_STARTER_SANDSTORM
	msgbox RF_SandstormIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu2
	setvar VAR_TEMP_A, FRONTIER_MON_GIGALITH_SANDSTORM
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_EXCADRILL_SANDSTORM
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_STOUTLAND_SANDSTORM
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_SandstormIntro:
	.string "Showing the Sandstorm team\ndescription.$"
	
RF_GrassyTerrain::
	drawinfobox INFOBOX_F_STARTER_GRASSY_TERRAIN
	msgbox RF_GrassyTerrainIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu2
	setvar VAR_TEMP_A, FRONTIER_MON_ROTOM_MOW_GRASSY_TERRAIN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_GOGOAT_GRASSY_TERRAIN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_SEVIPER_GRASSY_TERRAIN
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_GrassyTerrainIntro:
	.string "Showing the Grassy Terrain team\ndescription.$"
	
RF_PsychicTerrain::
	drawinfobox INFOBOX_F_STARTER_PSYCHIC_TERRAIN
	msgbox RF_PsychicTerrainIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu2
	setvar VAR_TEMP_A, FRONTIER_MON_BEHEEYEM_PSYCHIC_TERRAIN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_DELPHOX_PSYCHIC_TERRAIN
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_MEGA_SHARPEDO_PSYCHIC_TERRAIN
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_PsychicTerrainIntro:
	.string "Showing the Psychic Terrain team\ndescription.$"
	
RF_TrickRoom::
	drawinfobox INFOBOX_F_STARTER_TRICK_ROOM
	msgbox RF_TrickRoomIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu2
	setvar VAR_TEMP_A, FRONTIER_MON_OCTILLERY_TRICK_ROOM
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_DARMANITAN_ZEN_TRICK_ROOM
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_RAMPARDOS_TRICK_ROOM
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_TrickRoomIntro:
	.string "Showing the Trick Room team\ndescription.$"

@starter menu 3
RF_BatonPass::
	drawinfobox INFOBOX_F_STARTER_BATON_PASS
	msgbox RF_BatonPassIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu3
	setvar VAR_TEMP_A, FRONTIER_MON_JOLTEON_BATON_PASS
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_VAPOREON_BATON_PASS
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_ESPEON_BATON_PASS
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_BatonPassIntro:
	.string "Showing the Baton Pass team\ndescription.$"
	
RF_Gimmick::
	drawinfobox INFOBOX_F_STARTER_GIMMICK
	msgbox RF_GimmickIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu3
	setvar VAR_TEMP_A, FRONTIER_MON_TOXICROAK_GIMMICK
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_TOXAPEX_GIMMICK
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_SKARMORY_GIMMICK
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_GimmickIntro:
	.string "Showing the Gimmick team\ndescription.$"
	
RF_Eggtactical::
	drawinfobox INFOBOX_F_STARTER_EGGTACTICAL
	msgbox RF_EggtacticalIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu3
	setvar VAR_TEMP_A, FRONTIER_MON_NINJASK_EGGTACTICAL
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_SCIZOR_EGGTACTICAL
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_UMBREON_EGGTACTICAL
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_EggtacticalIntro:
	.string "Showing the Eggtactical team\ndescription.$"
	
RF_Masochist::
	drawinfobox INFOBOX_F_STARTER_MASOCHIST
	msgbox RF_MasochistIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu3
	setvar VAR_TEMP_A, FRONTIER_MON_DELIBIRD_MASOCHIST
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_DUNSPARCE_MASOCHIST
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_LUVDISC_MASOCHIST
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_MasochistIntro:
	.string "Showing the Masochist team\ndescription.$"

RF_Fear::
	drawinfobox INFOBOX_F_STARTER_FEAR
	msgbox RF_FearIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu3
	setvar VAR_TEMP_A, FRONTIER_MON_HIPPOWDON_FEAR
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_TOGEDEMARU_FEAR
	setflag FLAG_TEMP_D
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, FRONTIER_MON_MAGNEMITE_FEAR
	setflag FLAG_TEMP_D
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end

RF_FearIntro:
	.string "Showing the Fear team description.$"

@blank options (also default)
RF_Blank1::
	goto RyuFrontierStarterMenu1
	
RF_Blank2::
	goto RyuFrontierStarterMenu2
	
RF_Blank3::
	goto RyuFrontierStarterMenu3
