.set LOCALID_MOVE_DELETER, 1

PetalburgCity_PokemonCenter_2F_MapScripts::
	.byte 0

PetalburgCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

PetalburgCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

PetalburgCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

PetalburgCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

PetalburgCity_PokemonCenter_2F_EventScript_TooMuch::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_2F_Text_TooMuch, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonCenter_2F_Text_TooMuch:
	.string "NORMAN is too much for me to\n"
	.string "to take on, so I came to see\l"
	.string "if there were any items that\l"
	.string "might help me on sale here.$"
