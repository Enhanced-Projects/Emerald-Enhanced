FallarborTown_CaveTown_MapScripts::
	.byte 0

FallarborTown_CaveTown_EventScript_FallarborFossilLabSign::
	msgbox FallarborTown_CaveTown_Text_FossilLabSign, MSGBOX_SIGN
	end

FallarborTown_CaveTown_Text_FossilLabSign:
	.string "Fallarbor Fossil Lab\n"
	.string "“The study of the extinct.”$"

FallarborTown_CaveTown_EventScript_FallarborGemRefinerSign::
	msgbox FallarborTown_CaveTown_Text_GemRefinerSign, MSGBOX_SIGN
	end

FallarborTown_CaveTown_Text_GemRefinerSign::
	.string "Fallarbor Gem Ore Refiner\n"
	.string "“From rough rock to dazzling diamond”$"

FallarborTown_CaveTown_EventScript_FallarborShardRefinerSign::
	msgbox FallarborTown_CaveTown_Text_ShardRefinerSign, MSGBOX_SIGN
	end

FallarborTown_CaveTown_Text_ShardRefinerSign:
	.string "Fallarbor Shard Ore Refiner\n"
	.string "“Where ancient shards are unearthed”$"

@@=================================================================================================

@@As a note, leveling up is facilitated by the mining script itself, the master just comments based on the player's mining level, or gives them an initial level.
FTCT_MiningMaster::@@This script goes on the mining master.
	special checkbadgecount
	compare VAR_RESULT, 4
	goto_if_ge FTCT_MiningMasterStandard@@The mining master checks badges. If the count is greater than or equal to 4, go to the normal miningmaster script.
	goto FTCT_MiningMasterNoBadges @@script execution detected that you have less than 4 badges, so it skips the above line and executes this one.
	
FTCT_MiningMasterStandard::@Normal miningmaster script
	switch VAR_RYU_PLAYER_MINING_SKILL@@Checks what level mining the player has
	case 0, FTCT_MiningMasterIntroZero
	case 1, FTCT_MiningMasterIntro1
	case 2, FTCT_MiningMasterIntro2
	case 3, FTCT_MiningMasterIntro3
	goto FTCT_MiningMasterIntroZero@@failsafe in case somehow the player's mining level is greater than 3 or less than zero. Prevents null pointer crashes.

FTCT_MiningMasterNoBadges::
	msgbox FTCT_MiningMasterDefaultIntro@@This message shows when the player doesn't have enough badges to do mining stuff.
	release
	end

FTCT_MiningMasterIntroZero::@@Intro shown when the player has enough badges and hasn't yet learned to mine.
	msgbox FTCT_MiningIntroduction
	closemessage
	fadescreen FADE_TO_BLACK
	delay 60
	fadescreen FADE_FROM_BLACK
	setvar VAR_RYU_PLAYER_MINING_SKILL, 1      @@player can now mine. At this point, MiningMasterIntroZero can no longer be reached due to the player having mining level 1.
	msgbox FTCT_GoForthAndMine@@ message telling the player to go start mining.
	release
	end
	

FTCT_MiningMasterIntro1::@@Intro shown when the player is level 1 mining. Nothing special here, just the unique message for being level 1.
	msgbox FTCT_Level1DescriptiveText
	release
	end


FTCT_MiningMasterIntro2::@@Intro shown when the player is level 2 mining.
	msgbox FTCT_Level2DescriptiveText
	release
	end


FTCT_MiningMasterIntro3::@@Intro shown when the player is level 3 mining.
	msgbox FTCT_Level3DescriptiveText
	release
	end
	
FTCT_MiningIntroduction:
	.string "Welcome to our cavern town!\pI am the Mining Master.\pI will give you the skill to\nmine rocks to get natural\lresources.$"
	
FTCT_GoForthAndMine:
	.string "...and that's all there is to it!\pNow go forth and discover\nsome earthen treasures!$"
	
FTCT_MiningMasterDefaultIntro:
	.string "Hello, Traveller.\nYou should be careful around here!\pYou never know what you'll\nstumble onto!$"
	
FTCT_Level1DescriptiveText:
	.string "$"
	
FTCT_Level2DescriptiveText:
	.string "$"
	
FTCT_Level3DescriptiveText:
	.string "$"
