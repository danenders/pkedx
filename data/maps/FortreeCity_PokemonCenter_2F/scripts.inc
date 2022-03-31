.set LOCALID_MOVE_DELETER, 1

FortreeCity_PokemonCenter_2F_MapScripts::
	.byte 0

FortreeCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

FortreeCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

FortreeCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

FortreeCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

FortreeCity_PokemonCenter_2F_EventScript_WhatsTheDeal::
	lock
	faceplayer
	msgbox FortreeCity_PokemonCenter_2F_Text_WhatsTheDeal, MSGBOX_DEFAULT
	release
	end

FortreeCity_PokemonCenter_2F_Text_WhatsTheDeal:
	.string "What's that guy's deal, anyway?\p"
	.string "He won't even talk to me until\n"
	.string "a higher RANK!$"
