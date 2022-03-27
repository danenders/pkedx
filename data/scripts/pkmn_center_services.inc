@BADGE CHECKS
Pkmn_Center_Services_EventScript_MustBeBeginner::
	msgbox Pkmn_Center_Services_Text_MustBeBeginner, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_Text_MustBeBeginner:
	.string "I'm sorry, but you need to be at\n"
	.string "least BEGINNER RANK in the HOENN\l"
	.string "LEAGUE to use our services.$"

Pkmn_Center_Services_EventScript_MustBeSeasoned::
	msgbox Pkmn_Center_Services_Text_MustBeSeasoned, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_Text_MustBeSeasoned:
	.string "I'm sorry, but you need to be a\n"
	.string "SEASONED TRAINER in the HOENN\l"
	.string "LEAGUE to use my services.$"

Pkmn_Center_Services_EventScript_MustBeElite::
	msgbox Pkmn_Center_Services_Text_MustBeElite, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_Text_MustBeElite:
	.string "Whoa, slow down there, kid!\p"
	.string "I only work the most ELITE\n"
	.string "trainers.\p"
	.string "Come back and see me after you\n"
	.string "earn a few more badges.$"

@RANK CHECK
Pkmn_Center_Services_EventScript_RankBoard::
	msgbox Pkmn_Center_Services_Text_RankBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Pkmn_Center_Services_EventScript_Rankings
	release
	end

Pkmn_Center_Services_Text_RankBoard:
	.string "It's the POKéMON LEAGUE rankings.\p"
	.string "Look up your current rank?$"

Pkmn_Center_Services_EventScript_Rankings::
	msgbox Pkmn_Center_Services_Text_Ranking_Searching, MSGBOX_DEFAULT
	goto_if_set FLAG_IS_CHAMPION, Pkmn_Center_Services_EventScript_Ranking_Champion
	goto_if_set FLAG_BADGE07_GET, Pkmn_Center_Services_EventScript_Ranking_Elite
	goto_if_set FLAG_BADGE05_GET, Pkmn_Center_Services_EventScript_Ranking_Veteran
	goto_if_set FLAG_BADGE03_GET, Pkmn_Center_Services_EventScript_Ranking_Seasoned
	goto_if_set FLAG_BADGE01_GET, Pkmn_Center_Services_EventScript_Ranking_Beginner
	goto Pkmn_Center_Services_EventScript_Ranking_Unranked
	end

Pkmn_Center_Services_EventScript_Ranking_Unranked::
	playse SE_RG_HELP_OPEN
	msgbox Pkmn_Center_Services_Text_Ranking_Unranked, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_Ranking_Beginner::
	playse SE_RG_HELP_OPEN
	msgbox Pkmn_Center_Services_Text_Ranking_Beginner, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_Ranking_Seasoned::
	playse SE_RG_HELP_OPEN
	msgbox Pkmn_Center_Services_Text_Ranking_Seasoned, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_Ranking_Veteran::
	playse SE_RG_HELP_OPEN
	msgbox Pkmn_Center_Services_Text_Ranking_Veteran, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_Ranking_Elite::
	playse SE_RG_HELP_OPEN
	msgbox Pkmn_Center_Services_Text_Ranking_Elite, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_Ranking_Champion::
	playse SE_RG_HELP_OPEN
	waitse
	msgbox Pkmn_Center_Services_Text_Ranking_Champion, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_Text_Ranking_Searching:
	.string "Searching database....\p"
	.string "..........\p"
	.string "Found TRAINER....\p"
	.string "{PLAYER} from LITTLEROOT...$"

Pkmn_Center_Services_Text_Ranking_Unranked:
	.string "You are currently UNRANKED!$"

Pkmn_Center_Services_Text_Ranking_Beginner:
	.string "Your current rank is:\p"
	.string "BEGINNER!$"

Pkmn_Center_Services_Text_Ranking_Seasoned:
	.string "Your current rank is:\p"
	.string "SEASONED!$"

Pkmn_Center_Services_Text_Ranking_Veteran:
	.string "Your current rank is:\p"
	.string "VETERAN!$"

Pkmn_Center_Services_Text_Ranking_Elite:
	.string "Your current rank is:\p"
	.string "ELITE!$"

Pkmn_Center_Services_Text_Ranking_Champion:
	.string "Your current rank is:\p"
	.string "CHAMPION!$"

@ELITE SHOP
Pkmn_Center_Services_EventScript_EliteShop_Champion::
	pokemart Pkmn_Center_Services_Mart_EliteShop_Champion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_EliteShop_Elite::
	pokemart Pkmn_Center_Services_Mart_EliteShop_Elite
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Pkmn_Center_Services_Mart_EliteShop_Elite:
	.2byte ITEM_PP_UP
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_NONE
	release
	end

	.align 2
Pkmn_Center_Services_Mart_EliteShop_Champion:
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_NONE
	release
	end


@BERRY SHOPS
Pkmn_Center_Services_EventScript_BerryClerk_Champion::
	pokemart Pkmn_Center_Services_BerryShop_Champion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_BerryClerk_Elite::
	pokemart Pkmn_Center_Services_BerryShop_Elite
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_BerryClerk_Veteran::
	pokemart Pkmn_Center_Services_BerryShop_Veteran
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_BerryClerk_Seasoned::
	pokemart Pkmn_Center_Services_BerryShop_Seasoned
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Pkmn_Center_Services_EventScript_BerryClerk_Beginner::
	pokemart Pkmn_Center_Services_BerryShop_Beginner
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end


	.align 2
Pkmn_Center_Services_BerryShop_Champion:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_NONE
	release
	end

	.align 2
Pkmn_Center_Services_BerryShop_Elite:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_NONE
	release
	end

	.align 2
Pkmn_Center_Services_BerryShop_Veteran:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_NONE
	release
	end

	.align 2
Pkmn_Center_Services_BerryShop_Seasoned:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_NONE
	release
	end

	.align 2
Pkmn_Center_Services_BerryShop_Beginner:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_NONE
	release
	end


@MOVE DELETER
Pkmn_Center_Services_EventScript_MoveDeleter::
	lockall
	waitmovement 0
	msgbox Pkmn_Center_Services_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Pkmn_Center_Services_EventScript_ChooseMonAndMoveToForget
	case NO, Pkmn_Center_Services_EventScript_ComeAgain
	releaseall
	end

Pkmn_Center_Services_EventScript_ChooseMonAndMoveToForget::
	msgbox Pkmn_Center_Services_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Pkmn_Center_Services_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Pkmn_Center_Services_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, Pkmn_Center_Services_EventScript_MonOnlyKnowsOneMove
	msgbox Pkmn_Center_Services_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, Pkmn_Center_Services_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox Pkmn_Center_Services_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Pkmn_Center_Services_EventScript_TryForgetMove
	case NO, Pkmn_Center_Services_EventScript_ComeAgain
	releaseall
	end

Pkmn_Center_Services_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, Pkmn_Center_Services_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox Pkmn_Center_Services_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

Pkmn_Center_Services_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox Pkmn_Center_Services_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

Pkmn_Center_Services_EventScript_EggCantForgetMoves::
	msgbox Pkmn_Center_Services_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

Pkmn_Center_Services_EventScript_ComeAgain::
	msgbox Pkmn_Center_Services_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

Pkmn_Center_Services_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox Pkmn_Center_Services_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

Pkmn_Center_Services_Text_ICanMakeMonForgetMove:
	.string "Uh…\n"
	.string "Oh, yes, I'm a MOVE DELETER.\p"
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

Pkmn_Center_Services_Text_WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

Pkmn_Center_Services_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

Pkmn_Center_Services_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

Pkmn_Center_Services_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

Pkmn_Center_Services_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

Pkmn_Center_Services_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

Pkmn_Center_Services_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No EGG should know any moves.$"

Pkmn_Center_Services_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"