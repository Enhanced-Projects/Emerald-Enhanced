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
	case 3, RF_Balanced
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
	case 5, RF_FEAR
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
	setvar VAR_TEMP_A, 160
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, 708
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, 78
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end

RF_HyperOffenseIntro:
	.string "Showing the\nHyper Offense team description.$"

RF_FearTeamIntro:
	.string "Showing the FEAR team\ndescription.$"
	
RF_Offense::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Balanced::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_BulkyOffense::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Stall::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end

@starter menu 2
RF_Hail::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Rain::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Sun::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Sandstorm::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_GrassyTerrain::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_PsychicTerrain::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_TrickRoom::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end

@starter menu 3
RF_BatonPass::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Gimmick::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Eggtactical::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end
	
RF_Masochist::
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end

RF_FEAR::
	drawinfobox INFOBOX_F_STARTER_FEAR_TEAM
	msgbox RF_FearTeamIntro
	removeinfobox
	closemessage
	msgbox RF_ChooseThisSet, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RyuFrontierStarterMenu1
	setvar VAR_TEMP_A, 975
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, 976
	setflag FLAG_TEMP_D
	special RyuGiveFrontierMon
	delay 20
	setvar VAR_TEMP_A, 977
	setflag FLAG_TEMP_D
	special RyuGiveFrontierMon
	msgbox RF_CompletedGivingStarter
	clearflag FLAG_RYU_CHOOSING_FRONTIER_STARTER
	release
	end

@blank options (also default)
RF_Blank1::
	goto RyuFrontierStarterMenu1
	
RF_Blank2::
	goto RyuFrontierStarterMenu2
	
RF_Blank3::
	goto RyuFrontierStarterMenu3






