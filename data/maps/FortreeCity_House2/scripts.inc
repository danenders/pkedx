FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_DazzlingBeamGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM43, FortreeCity_House2_EventScript_ExplainTM43
	call_if_unset FLAG_MET_TM43_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_ThatWasFun, MSGBOX_DEFAULT
	giveitem ITEM_TM43
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM43
	msgbox FortreeCity_House2_Text_ExplainTM43, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_PlayGames, MSGBOX_DEFAULT
	setflag FLAG_MET_TM43_GIVER
	return

FortreeCity_House2_EventScript_TM43::
	msgbox FortreeCity_House2_Text_ExplainTM43, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_PlayGames:
	.string "People… POKéMON…\p"
	.string "They pass the time by playing\n"
	.string "games with each other…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Would you be kind enough to\n"
	.string "play a game with me…\p"
	.string "I hold a coin in my hand.\p"
	.string "Now, tell me, have I palmed it in\n"
	.string "the right hand? Or in the left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_ThatWasFun:
	.string "Oh! Splendid!\n"
	.string "A game does not need to be hard\n"
	.string "to be fun.\p"
	.string "Take this TM as a gift for$"
	.string "entertaining this old woman.$"

FortreeCity_House2_Text_ExplainTM43:
	.string "DAZZLING BEAM is a powerful\n"
	.string "FAIRY type move.\p"
	.string "When I was a young trainer…\n"
	.string "we did not understand the true\l"
	.string "nature of FAIRY type POKéMON.\p"
	.string "I hope you and your POKéMON\n"
	.string "can have fun playing games\l"
	.string "together, even when things\l"
	.string "are changing…"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "No, too bad.\n"
	.string "You guessed wrong.$"

