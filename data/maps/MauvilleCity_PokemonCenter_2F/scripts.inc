.set LOCALID_MOVE_DELETER, 1

MauvilleCity_PokemonCenter_2F_MapScripts::
	.byte 0

MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_2F_Text_Youngster:
	.string "Did you know that you can link battle\n"
	.string "at the COLOSSEUM here?\p"
	.string "They put up your record on the wall\n"
	.string "for everyone to see.\p"
	.string "It's embarrassing if you lose more\n"
	.string "often than you win…$"

MauvilleCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

MauvilleCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

MauvilleCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

MauvilleCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end
