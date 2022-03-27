.set LOCALID_MOVE_DELETER, 1

VerdanturfTown_PokemonCenter_2F_MapScripts::
	.byte 0

VerdanturfTown_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Kid::
	lock
	faceplayer
	msgbox VerdanturfTown_PokemonCenter_2F_Text_GoAllTheWay, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_2F_Text_GoAllTheWay:
	.string "I just hit BEGINNER rank.\p"
	.string "AZURILL and I are going to go\n"
	.string "all the way!$"

VerdanturfTown_PokemonCenter_2F_EventScript_Azurill::
	lock
	faceplayer
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	waitmoncry
	release
	end