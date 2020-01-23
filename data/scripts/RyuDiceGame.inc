

RyuDiceGame::
	goto_if_set FLAG_RYU_NUZLOCKEMODE, RDG_BallBlackMarket
	msgbox tutorialQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq DiceGameTutorial
	msgbox diceGameQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne ryu_end
	checkmoney 20000
	compare VAR_RESULT, 1
	goto_if_ne CantPlayBroke
	showmoneybox 16, 0, 0
	nop
	goto diceGameBetQuery

RDG_BallBlackMarket::
	lock
	faceplayer
	setvar VAR_RYU_PRICE_MULTIPLIER, 800
	clearflag FLAG_RYU_NUZLOCKEMODE
	msgbox BBM_intro, MSGBOX_DEFAULT
	message gBallBlackMarket
	waitmessage
	pokemart RyuDiceGame_BallBlackMarket
	msgbox BBM_Outro
	setflag FLAG_RYU_NUZLOCKEMODE
	setvar VAR_RYU_PRICE_MULTIPLIER, 150
	release
	end

	.align 2
RyuDiceGame_BallBlackMarket:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE

BBM_intro:
    .string "Shifty Old Man: {SHADOW BLUE}PSST! Hey, You!\p"
    .string "I got some top tier, high quality\n"
    .string "balls for sale. You can't get\l"
    .string "these anywhere else!$"

BBM_Outro:
    .string "Shifty Old Man: Yeah... get out of\n"
    .string "here before the feds catch on...$"

	
DiceGameTutorial::
	msgbox diceGameTutorialMsg
	closemessage
	return
	
diceGameBetQuery::
	msgbox betHowMuch
	multichoice 0, 0, 136, 1
	switch VAR_RESULT
	case 0, diceGameBet100
	case 1, diceGameBet1000
	case 2, diceGameBet10000
	end
	
diceGameBet100::
    setvar VAR_TEMP_A, 100
	setvar VAR_TEMP_B, 100
    goto DiceGame

diceGameBet1000::
    setvar VAR_TEMP_A, 1000
	setvar VAR_TEMP_B, 1000
    goto DiceGame

diceGameBet10000::
    setvar VAR_TEMP_A, 10000
	setvar VAR_TEMP_B, 10000
    goto DiceGame

DiceGame::
	setvar VAR_TEMP_8, 0
	takemoney VAR_TEMP_A
	updatemoneybox 0, 0
	nop
	specialvar VAR_TEMP_8, RyuRollDice
	copyvar VAR_TEMP_9, VAR_TEMP_1
	copyvar VAR_TEMP_F, VAR_TEMP_2
	special RyuDrawDicePics
	buffernumberstring 0, VAR_TEMP_1
	buffernumberstring 1, VAR_TEMP_2
	msgbox playerRolled
	closemessage
	special RemoveBothCutsceneSpriteIds
	copyvar VAR_TEMP_9, VAR_TEMP_3
	copyvar VAR_TEMP_F, VAR_TEMP_4
	special RyuDrawDicePics
	buffernumberstring 0, VAR_TEMP_3
	buffernumberstring 1, VAR_TEMP_4
	msgbox aiRolled
	closemessage
	special RemoveBothCutsceneSpriteIds
	compare VAR_TEMP_8, WIN
	goto_if_eq diceGameWin
	compare VAR_TEMP_8, LOSS
	goto_if_eq diceGameLost
	compare VAR_TEMP_8, DRAW
	goto_if_eq diceGameDoubleDown
	goto diceGameError
	
diceGameLost::
	buffernumberstring 0, VAR_TEMP_A
	msgbox playerLoseMsg
	closemessage
	takemoney VAR_TEMP_A
	updatemoneybox 0, 0
	nop
	goto diceGamePlayAgainQuery
	
diceGamePlayAgainQuery::
	msgbox diceGameKeepPlayingMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq diceGameBetQuery
	hidemoneybox
	nop
	nop
	release
	end
	
diceGameTie::
	msgbox drawMsg
	closemessage
	msgbox diceDoubleQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq diceGameDoubleDown
	givemoney VAR_TEMP_A
	updatemoneybox 0, 0
	nop
	msgbox tieNoReplay
	closemessage
	hidemoneybox
	nop
	nop
	release
	end

diceGameWin::
	buffernumberstring 0, VAR_TEMP_A
	msgbox playerWinMsg
	closemessage
	givemoney VAR_TEMP_A
	givemoney VAR_TEMP_A
	updatemoneybox 0, 0
	nop
	goto diceGamePlayAgainQuery
	
diceGameDoubleDown::
	checkmoney 10000
	compare VAR_RESULT, 0
	goto_if_eq CantPlayBroke
	compare VAR_TEMP_B, 25000
	goto_if_ge diceGameBetLimitReached
	addvar VAR_TEMP_0, 1
	setvar VAR_TEMP_7, 1
	takemoney VAR_TEMP_A
	updatemoneybox 0, 0
	nop
	specialvar VAR_TEMP_8, RyuRollDice
	copyvar VAR_TEMP_9, VAR_TEMP_1
	copyvar VAR_TEMP_F, VAR_TEMP_2
	special RyuDrawDicePics
	buffernumberstring 0, VAR_TEMP_1
	buffernumberstring 1, VAR_TEMP_2
	msgbox playerRolled
	closemessage
	special RemoveBothCutsceneSpriteIds
	copyvar VAR_TEMP_9, VAR_TEMP_3
	copyvar VAR_TEMP_F, VAR_TEMP_4
	special RyuDrawDicePics
	buffernumberstring 0, VAR_TEMP_3
	buffernumberstring 1, VAR_TEMP_4
	msgbox aiRolled
	closemessage
	special RemoveBothCutsceneSpriteIds
	compare VAR_TEMP_8, WIN
	goto_if_eq diceGameDDWin
	compare VAR_TEMP_8, LOSS
	goto_if_eq diceGameLost
	compare VAR_TEMP_8, DRAW
	goto_if_eq diceGameDoubleDown
	goto diceGameError
	
diceGameDDWin::
	compare VAR_TEMP_0, 0
	call_if_ne DDWinLoop
	buffernumberstring 2, VAR_TEMP_7
	msgbox playerDDWinMsg
	givemoney VAR_TEMP_A
	closemessage
	updatemoneybox 0, 0
	nop
	goto diceGamePlayAgainQuery
	
DDWinLoop::
	givemoney VAR_TEMP_A
	goto DDWinLoopAdvance
	
DDWinLoopAdvance::
	compare VAR_TEMP_0, 0
	goto_if_eq DDWin_done
	subvar VAR_TEMP_0, 1
	goto DDWinLoop
	
DDWin_done::
	return
	
	
diceGameBetLimitReached::
	msgbox limitReached
	givemoney VAR_TEMP_B
	updatemoneybox 0, 0
	nop
	closemessage
	hidemoneybox
	nop
	nop
	release
	end
	
limitReached:
	.string "You reached the bet limit.\nRefunding equal parts.$"
	
CantPlayBroke::
	msgbox notEnoughMoneyToPlay
	closemessage
	release
	end
	
diceGameError:
	msgbox diceGameErrorMsg
	closemessage
	release
	end
	
tutorialQuery:
	.string "Would you like a tutorial on how to\nplay the dice game?$"
	
diceGameTutorialMsg:
    .string "The rules of the game are as\n"
    .string "follows.\p"
    .string "There are only 2 winning rolls.\n"
    .string "They are 7 and 11.\p"
    .string "There are 3 losing rolls.\n"
    .string "They are Snake Eyes, 3 total, and\l"
    .string "double Sixes.\p"
    .string "If neither player rolls a winning\n"
    .string "or losing roll, then the bet is\p"
    .string "doubled and you roll again.\n"
    .string "The rerolls continue until you\p"
    .string "win or lose. If you win, you will\n"
    .string "collect winnings. If you lose,\p"
    .string "you don't get any winnings back.\n"
    .string "Have fun!$"

	
tieNoReplay:
	.string "There was no winner.\nRefunding both players.$"

diceGameQuery:
	.string "Would you like to play the Dice game?$"
	
diceGameInfo:
	.string "Rules are very simple. We both roll\n2 6-sided dice.\pWhoever rolls the highest wins.$"
	
betHowMuch:
	.string "How much would you like to bet?$"
	
notEnoughMoneyToPlay:
	.string "You don't have enough money to\nsafely play.$"

playerRolled:
	.string "You rolled {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY} and {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_2}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}.$"
	
aiRolled:
	.string "Opponent rolled {COLOR LIGHT_RED}{SHADOW RED}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY} and {COLOR LIGHT_RED}{SHADOW RED}{STR_VAR_2}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}.$"
	
playerTotal:
	.string "Your total is {COLOR LIGHT_BLUE}{SHADOW BLUE}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}.$"

aiTotal:
	.string "Opponent's total is {COLOR LIGHT_RED}{SHADOW RED}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}.$"
	
diceGameErrorMsg:
	.string "An error has been detected. Ending the dice game.$"
	
playerLoseMsg:
	.string "You lost!\nPaying {STR_VAR_1} to the stranger.$"

diceGameKeepPlayingMsg:
	.string "Would you like to keep playing?$"
	
playerWinMsg:
	.string "You won!\nThe stranger pays you {STR_VAR_1}.$"
	
playerDDWinMsg:
	.string "You won!\nThe stranger pays you\l dividends for {STR_VAR_1} wins.$"
	
drawMsg:
	.string "It was a draw!$"
	
diceDoubleQuery:
	.string "Would you like to double down\nand play again?$"
	
diceGameCancelPlay:
	.string "Thanks for playing!$"
	
notPlayingGame:
	.string "Come back if you want to lose more\nmoney!$"
