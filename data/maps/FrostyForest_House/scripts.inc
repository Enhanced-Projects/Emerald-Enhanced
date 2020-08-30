FrostyForest_House_MapScripts::
	.byte 0

FrostyForest_House_EventScript_HexManiac::
	lock
	faceplayer
	msgbox FrostyForest_House_Text_FeelFreeTo, MSGBOX_DEFAULT
	release
	end

FrostyForest_House_Text_IfYouMake:
	.string "Feel free to use my bed to heal.$"
