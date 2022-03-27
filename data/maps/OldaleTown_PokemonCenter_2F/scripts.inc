.set LOCALID_MOVE_DELETER, 1

OldaleTown_PokemonCenter_2F_MapScripts::
	.byte 0

OldaleTown_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_CheckRank::
	lock
	faceplayer
	msgbox OldaleTown_PokemonCenter_2F_Text_CheckRank, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_Text_CheckRank:
	.string "I want to check my RANK, but I'm\n"
	.string "too nervous!$"

OldaleTown_PokemonCenter_2F_EventScript_Girlfriend::
	lock
	faceplayer
	msgbox OldaleTown_PokemonCenter_2F_Text_Girlfriend, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_Text_Girlfriend:
	.string "My boyfriend has been staring\n"
	.string "at that RANKINGS BOARD all day!$"
