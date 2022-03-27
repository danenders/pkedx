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
	.string "If I win a whole lot of battles\n"
	.string "and show everyone how good I am,\l"
	.string "I might get a fan following!$"

MossdeepCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end
