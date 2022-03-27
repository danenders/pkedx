.set LOCALID_MOVE_DELETER, 1

MossdeepCity_PokemonCenter_2F_MapScripts::
	.byte 0

MossdeepCity_PokemonCenter_2F_EventScript_Woman5::
	lock
	faceplayer
	msgbox MossdeepCity_PokemonCenter_2F_Text_Woman5, MSGBOX_DEFAULT
	release
	end

MossdeepCity_PokemonCenter_2F_Text_Woman5:
	.string "If I win a whole lot of link battles\n"
	.string "and show everyone how good I am,\l"
	.string "I might get a fan following!$"

MossdeepCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Pkmn_Center_Services_EventScript_RankBoard
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, Pkmn_Center_Services_EventScript_MustBeSeasoned
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Pkmn_Center_Services_EventScript_MoveDeleter
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE01_GET, Pkmn_Center_Services_Text_MustBeBeginner
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_IS_CHAMPION, Pkmn_Center_Services_EventScript_BerryClerk_Champion
	goto_if_set FLAG_BADGE07_GET, Pkmn_Center_Services_EventScript_BerryClerk_Elite
	goto_if_set FLAG_BADGE05_GET, Pkmn_Center_Services_EventScript_BerryClerk_Veteran
	goto_if_set FLAG_BADGE03_GET, Pkmn_Center_Services_EventScript_BerryClerk_Seasoned
	goto Pkmn_Center_Services_EventScript_BerryClerk_Beginner
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE07_GET, Pkmn_Center_Services_Text_MustBeElite
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_IS_CHAMPION, Pkmn_Center_Services_EventScript_EliteShop_Champion
	goto Pkmn_Center_Services_EventScript_EliteShop_Elite
	release
	end