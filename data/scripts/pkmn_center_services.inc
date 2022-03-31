@SERVICES
Common_EventScript_Pkmn_Center_Services_RankBoard::
	msgbox Text_Pkmn_Center_Services__RankBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EventScript_Pkmn_Center_Services_Rankings
	release
	end

Common_EventScript_Pkmn_Center_Services_MoveDeleter::
	goto_if_unset FLAG_BADGE03_GET, EventScript_Pkmn_Center_Services_MustBeSeasoned
	goto EventScript_Pkmn_Center_Services_MoveDeleter
	end

Common_EventScript_Pkmn_Center_Services_BerryClerk::
	goto_if_unset FLAG_BADGE01_GET, EventScript_Pkmn_Center_Services_MustBeBeginner
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_IS_CHAMPION, EventScript_Pkmn_Center_Services_BerryClerk_Champion
	goto_if_set FLAG_BADGE07_GET, EventScript_Pkmn_Center_Services_BerryClerk_Elite
	goto_if_set FLAG_BADGE05_GET, EventScript_Pkmn_Center_Services_BerryClerk_Veteran
	goto_if_set FLAG_BADGE03_GET, EventScript_Pkmn_Center_Services_BerryClerk_Seasoned
	goto EventScript_Pkmn_Center_Services_BerryClerk_Beginner
	end

Common_EventScript_Pkmn_Center_Services_EliteShop::
	goto_if_unset FLAG_BADGE07_GET, EventScript_Pkmn_Center_Services_MustBeElite
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_IS_CHAMPION, EventScript_Pkmn_Center_Services_EliteShop_Champion
	goto EventScript_Pkmn_Center_Services_EliteShop_Elite
	end

@BADGE CHECKS
EventScript_Pkmn_Center_Services_MustBeBeginner::
	msgbox Text_Pkmn_Center_Services__MustBeBeginner, MSGBOX_DEFAULT
	release
	end

Text_Pkmn_Center_Services__MustBeBeginner:
	.string "I'm sorry, but you need to be at\n"
	.string "least BEGINNER RANK in the HOENN\l"
	.string "LEAGUE to use our services.$"

EventScript_Pkmn_Center_Services_MustBeSeasoned::
	msgbox Text_Pkmn_Center_Services__MustBeSeasoned, MSGBOX_DEFAULT
	release
	end

Text_Pkmn_Center_Services__MustBeSeasoned:
	.string "I'm sorry, but you need to be a\n"
	.string "SEASONED TRAINER in the HOENN\l"
	.string "LEAGUE to use my services.$"

EventScript_Pkmn_Center_Services_MustBeElite::
	msgbox Text_Pkmn_Center_Services__MustBeElite, MSGBOX_DEFAULT
	release
	end

Text_Pkmn_Center_Services__MustBeElite:
	.string "Whoa, slow down there, kid!\p"
	.string "I only work the most ELITE\n"
	.string "trainers.\p"
	.string "Come back and see me after you\n"
	.string "earn a few more badges.$"

@RANK CHECK
EventScript_Pkmn_Center_Services_Rankings::
	msgbox Text_Pkmn_Center_Services__Ranking_Searching, MSGBOX_DEFAULT
	goto_if_set FLAG_IS_CHAMPION, EventScript_Pkmn_Center_Services_Ranking_Champion
	goto_if_set FLAG_BADGE07_GET, EventScript_Pkmn_Center_Services_Ranking_Elite
	goto_if_set FLAG_BADGE05_GET, EventScript_Pkmn_Center_Services_Ranking_Veteran
	goto_if_set FLAG_BADGE03_GET, EventScript_Pkmn_Center_Services_Ranking_Seasoned
	goto_if_set FLAG_BADGE01_GET, EventScript_Pkmn_Center_Services_Ranking_Beginner
	goto EventScript_Pkmn_Center_Services_Ranking_Unranked
	end


Text_Pkmn_Center_Services__RankBoard:
	.string "It's the POKéMON LEAGUE rankings.\p"
	.string "Look up your current rank?$"

EventScript_Pkmn_Center_Services_Ranking_Unranked::
	playse SE_RG_HELP_OPEN
	msgbox Text_Pkmn_Center_Services__Ranking_Unranked, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_Ranking_Beginner::
	playse SE_RG_HELP_OPEN
	msgbox Text_Pkmn_Center_Services__Ranking_Beginner, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_Ranking_Seasoned::
	playse SE_RG_HELP_OPEN
	msgbox Text_Pkmn_Center_Services__Ranking_Seasoned, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_Ranking_Veteran::
	playse SE_RG_HELP_OPEN
	msgbox Text_Pkmn_Center_Services__Ranking_Veteran, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_Ranking_Elite::
	playse SE_RG_HELP_OPEN
	msgbox Text_Pkmn_Center_Services__Ranking_Elite, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_Ranking_Champion::
	playse SE_RG_HELP_OPEN
	waitse
	msgbox Text_Pkmn_Center_Services__Ranking_Champion, MSGBOX_DEFAULT
	release
	end

Text_Pkmn_Center_Services__Ranking_Searching:
	.string "Searching database....\p"
	.string "..........\p"
	.string "Found TRAINER....\p"
	.string "{PLAYER} from LITTLEROOT...$"

Text_Pkmn_Center_Services__Ranking_Unranked:
	.string "You are currently UNRANKED!$"

Text_Pkmn_Center_Services__Ranking_Beginner:
	.string "Your current rank is:\p"
	.string "BEGINNER!$"

Text_Pkmn_Center_Services__Ranking_Seasoned:
	.string "Your current rank is:\p"
	.string "SEASONED!$"

Text_Pkmn_Center_Services__Ranking_Veteran:
	.string "Your current rank is:\p"
	.string "VETERAN!$"

Text_Pkmn_Center_Services__Ranking_Elite:
	.string "Your current rank is:\p"
	.string "ELITE!$"

Text_Pkmn_Center_Services__Ranking_Champion:
	.string "Your current rank is:\p"
	.string "CHAMPION!$"


@ELITE SHOP
EventScript_Pkmn_Center_Services_EliteShop_Champion::
	pokemart Pkmn_Center_Services_Mart_EliteShop_Champion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_EliteShop_Elite::
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
EventScript_Pkmn_Center_Services_BerryClerk_Champion::
	pokemart Pkmn_Center_Services_BerryShop_Champion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_BerryClerk_Elite::
	pokemart Pkmn_Center_Services_BerryShop_Elite
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_BerryClerk_Veteran::
	pokemart Pkmn_Center_Services_BerryShop_Veteran
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_BerryClerk_Seasoned::
	pokemart Pkmn_Center_Services_BerryShop_Seasoned
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_Pkmn_Center_Services_BerryClerk_Beginner::
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
EventScript_Pkmn_Center_Services_MoveDeleter::
	lockall
	waitmovement 0
	msgbox Text_Pkmn_Center_Services__ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, EventScript_Pkmn_Center_Services_ChooseMonAndMoveToForget
	case NO, EventScript_Pkmn_Center_Services_ComeAgain
	releaseall
	end

EventScript_Pkmn_Center_Services_ChooseMonAndMoveToForget::
	msgbox Text_Pkmn_Center_Services__WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_Pkmn_Center_Services_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_Pkmn_Center_Services_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, EventScript_Pkmn_Center_Services_MonOnlyKnowsOneMove
	msgbox Text_Pkmn_Center_Services__WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, EventScript_Pkmn_Center_Services_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox Text_Pkmn_Center_Services__MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, EventScript_Pkmn_Center_Services_TryForgetMove
	case NO, EventScript_Pkmn_Center_Services_ComeAgain
	releaseall
	end

EventScript_Pkmn_Center_Services_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, EventScript_Pkmn_Center_Services_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox Text_Pkmn_Center_Services__MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Pkmn_Center_Services_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox Text_Pkmn_Center_Services__MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Pkmn_Center_Services_EggCantForgetMoves::
	msgbox Text_Pkmn_Center_Services__EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Pkmn_Center_Services_ComeAgain::
	msgbox Text_Pkmn_Center_Services__ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Pkmn_Center_Services_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox Text_Pkmn_Center_Services__CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

Text_Pkmn_Center_Services__ICanMakeMonForgetMove:
	.string "Uh…\n"
	.string "Oh, yes, I'm a MOVE DELETER.\p"
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

Text_Pkmn_Center_Services__WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

Text_Pkmn_Center_Services__WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

Text_Pkmn_Center_Services__MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

Text_Pkmn_Center_Services__MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

Text_Pkmn_Center_Services__MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

Text_Pkmn_Center_Services__ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

Text_Pkmn_Center_Services__EggCantForgetMoves:
	.string "What?\n"
	.string "No EGG should know any moves.$"

Text_Pkmn_Center_Services__CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"
