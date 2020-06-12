FallarborTown_MiningMasterHouse_MapScripts::
	.byte 0

FallarborTown_MiningMasterHouse_EventScript_Wife::
	msgbox FallarborTown_MiningMasterHouse_Text_MadeSoMuchMoney, MSGBOX_NPC
	end

FallarborTown_MiningMasterHouse_Text_MadeSoMuchMoney:
	.string "My husband made so much money from\n"
	.string "mining for rare ores that we could\l"
	.string "afford this big house.\p"
	.string "Once he and his friend next door\n"
	.string "started making money from mining,\l"
	.string "more people moved here to help out.\l"
	.string "This big mine is the result.$"

FallarborTown_MiningMasterHouse_EventScript_Son::
	msgbox FallarborTown_MiningMasterHouse_Text_WhenIGrowUp, MSGBOX_NPC
	end

FallarborTown_MiningMasterHouse_Text_WhenIGrowUp:
	.string "When I grow up, I want to become a\n"
	.string "miner like dad!$"

FallarborTown_MiningMasterHouse_EventScript_Daughter::
	msgbox FallarborTown_MiningMasterHouse_Text_TheseRocks, MSGBOX_NPC
	end

FallarborTown_MiningMasterHouse_Text_TheseRocks:
	.string "These rocks are some of the stuff\n"
	.string "daddy dug up in the mines.\p"
	.string "Apparently they're very special rocks,\n"
	.string "but I'm too young to understand…$"

@@=================================================================================================

@@As a note, leveling up is facilitated by the mining script itself, the master just comments based on the player's mining level, or gives them an initial level.
FTCT_MiningMaster::@@This script goes on the mining master.
	lock
	faceplayer
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
	.string "Welcome to our cavern town!\pI am the Mining Master.\pI will teach you the skill to\nmine rocks to get natural\lresources.$"
	
FTCT_GoForthAndMine:
	.string "...and that's all there is to it!\pNow go forth and discover\nsome earthen treasures!$"
	
FTCT_MiningMasterDefaultIntro:
	.string "Hello, traveller.\nThey call me the mining master.\pIf you show me your power by\nobtaining 4 badges, I'll teach you\la special skill!$"
	
FTCT_Level1DescriptiveText:
	.string "You're still a rookie.\pIf you keep digging, you'll get\nmore skilled and find rarer items!$"
	
FTCT_Level2DescriptiveText:
	.string "I see you've advanced. Keep it up!\nYou can still get more skilled.$"
	
FTCT_Level3DescriptiveText:
	.string "You're the most skilled miner I know!\pI don't think you can get any\n better than this!$"
