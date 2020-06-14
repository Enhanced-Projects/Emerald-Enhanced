FallarborTown_CaveTown_MapScripts::
	.byte 0

FallarborTown_CaveTown_Text_GemRefinerSign::
	msgbox FTCT_GemRefinerSignMessage
	release
	end
	
FTCT_GemRefinerSignMessage:
	.string "Fallarbor Gem Ore Refiner\n"
	.string "“From rough rock to dazzling diamond”$"

FallarborTown_CaveTown_Text_ShardRefinerSign::
	msgbox FTCT_ShardRefinerSignMessage
	release
	end

FTCT_ShardRefinerSignMessage:
	.string "Fallarbor Shard Ore Refiner\n"
	.string "“Where ancient shards are unearthed”$"

FallarborTown_CaveTown_Text_FossilLabSign::
	msgbox FTCT_FossilLabSignMessage
	release
	end
	
FTCT_FossilLabSignMessage:
	.string "Fallarbor Fossil Lab\n"
	.string "“The study of the extinct.”$"

FallarborTown_CaveTown_Text_FossilManiacSign::
	msgbox FTCT_FossilManiacSignMessage
	release
	end
	
FTCT_FossilManiacSignMessage:
	.string "Fossil Maniac's House\n"
	.string "“All rare fossils are mine!”$"

FallarborTown_CaveTown_Text_MiningMasterSign::
	msgbox FTCT_MiningMasterSignMessage
	release
	end
	
FTCT_MiningMasterSignMessage:
	.string "Mining Master's House\n"
	.string "“Learn how to mine valuables.”$"

FallarborTown_CaveTown_Text_TownSign::
	msgbox FTCT_TownSignMessage
	release
	end
	
FTCT_TownSignMessage:
	.string "Fallarbor Mine\n"
	.string "“A humble mining town.”$"

FallarborTown_CaveTown_Text_DesertUnderpassSign::
	msgbox FTCT_DesertUnderpassSignMessage
	release
	end
	
FTCT_DesertUnderpassSignMessage:
	.string "Desert Underpass$"

FallarborTown_CaveTown_EventScript_MineShaftBlocker::
	msgbox FTCT_Text_ShouldntGoHere, MSGBOX_NPC
	end

FTCT_Text_ShouldntGoHere:
	.string "You shouldn't go in here, we're using\n"
	.string "explosives to excavate minerals.$"

FallarborTown_CaveTown_EventScript_DrillScientist::
	msgbox FTCT_Text_ThisIsOneOf, MSGBOX_NPC
	end

FTCT_Text_ThisIsOneOf:
	.string "This is one of the drills originally\n"
	.string "used to excavate this cave.\p"
	.string "We've come a long way ever since the\n"
	.string "Fossil Maniac dug the first tunnel…$"

FallarborTown_CaveTown_EventScript_Boy::
	msgbox FTCT_Text_ImTryingToFind, MSGBOX_NPC
	end

FTCT_Text_ImTryingToFind:
	.string "I'm trying to find rare ores in the\n"
	.string "rocks around here.\p"
	.string "The Mining Master taught me how.\p"
	.string "I think the rocks in this main cave\n"
	.string "have all been mined dry though…$"

FallarborTown_CaveTown_EventScript_MiningLover::
	msgbox FTCT_Text_DoYouAlsoLove, MSGBOX_NPC
	end

FTCT_Text_DoYouAlsoLove:
	.string "Do you also love to mine?\p"
	.string "Finding rare gems underground is\n"
	.string "like, so exciting to me!\p"
	.string "Maybe I'm a bit of a fanatic,\n"
	.string "though.$"

FallarborTown_CaveTown_EventScript_Questioner::
	msgbox FTCT_Text_HaveYouVisited, MSGBOX_NPC
	end

FTCT_Text_HaveYouVisited:
	.string "Have you visited the Mining Master?\n"
	.string "He's so cool!$"

FallarborTown_CaveTown_EventScript_MiddleManiac::
	msgbox FTCT_Text_DoYouLike, MSGBOX_NPC
	end

FTCT_Text_DoYouLike:
	.string "Do you like our little town in this\n"
	.string "mine? It took a lot of digging…$"

FallarborTown_CaveTown_EventScript_OldFart::
	msgbox FTCT_Text_ThisTown, MSGBOX_NPC
	end

FTCT_Text_ThisTown:
	.string "This town wasn't always like this.\p"
	.string "It started out as a series of tunnels\n"
	.string "dug by the Fossil Maniac and the\l"
	.string "Mining Master.\p"
	.string "They recruited more miners from\n"
	.string "around the region, and laid the\l"
	.string "foundation for this growing town.$"
