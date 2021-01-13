RustboroCity_PidgeysCoop_MapScripts::
	.byte 0

RustboroCity_PidgeysCoop_EventScript_Pidgey::
	lock
	faceplayer
	msgbox RustboroCity_PidgeysCoop_Text_PidgeyTalk, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PidgeysCoop_EventScript_Books::
	lockall
	msgbox RustboroCity_PidgeysCoop_Text_ProgBooks, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PidgeysCoop_EventScript_Bookshelf::
	lockall
	msgbox RustboroCity_PidgeysCoop_Text_Bookshelf, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PidgeysCoop_EventScript_PidgeyPc::
	lockall
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGPIDGEYSCREENSHOT
	msgbox RustboroCity_PidgeysCoop_Text_PidgeyPc, MSGBOX_DEFAULT
	clearfullscreenimage
	releaseall
	end

RustboroCity_PidgeysCoop_Text_PidgeyTalk::
	.string "So you found me...\p"
	.string "You know? I was once an NPC\n"
	.string "in Littleroot Town\p"
	.string "Then they redesigned the area\n"
	.string "and I was moved somewhere else\p"
	.string "And now here I am making\n"
	.string "a stupid Achievement instead of\l" 
	.string "working on the AP system\p"
	.string "Actually i forgot to ask.\n"
	.string "Why the hell did you even\l"
	.string "mess with that laptop?\p"
	.string "Anyways have fun finding the rest\n"
	.string "of these weird Achievements that may\l"
	.string "or may not exist in the game.$"

RustboroCity_PidgeysCoop_Text_ProgBooks::
	.string "There are some books related to\n"
	.string "Programming stacked up here\p"
	.string "The most worn out book is labled\n"
	.string "(The K&R C Programming Language)\p"
	.string "The most clean looking one is labeled\n"
	.string "(The Rust Programming Language)\p"
	.string "What's with all these weird names?\p"
	.string "Creativity is clearly lacking in\n"
	.string "the people who write these books.$"

RustboroCity_PidgeysCoop_Text_Bookshelf::
	.string "It's an assortment of dictionaries\n"
	.string "and random novels.$"

RustboroCity_PidgeysCoop_Text_PidgeyPc::
	.string "There is unreadble gibberish\n"
	.string "on the screen$"
