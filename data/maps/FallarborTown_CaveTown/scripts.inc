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

FallarborTown_CaveTown_Text_GemRefinerSign:
	.string "Fallarbor Gem Ore Refiner\n"
	.string "“From rough rock to dazzling diamond”$"

FallarborTown_CaveTown_EventScript_FallarborShardRefinerSign::
	msgbox FallarborTown_CaveTown_Text_ShardRefinerSign, MSGBOX_SIGN
	end

FallarborTown_CaveTown_Text_ShardRefinerSign:
	.string "Fallarbor Shard Ore Refiner\n"
	.string "“Where ancient shards are unearthed”$"
