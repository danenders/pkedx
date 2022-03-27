.set LOCALID_MOVE_DELETER, 1

DewfordTown_PokemonCenter_2F_MapScripts::
	.byte 0

DewfordTown_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_MoveDeleterHelp::
	lock
	faceplayer
	msgbox DewfordTown_PokemonCenter_2F_Text_MoveDeleterHelp, MSGBOX_DEFAULT
	release
	end

DewfordTown_PokemonCenter_2F_Text_MoveDeleterHelp:
	.string "I taught my POKeMON an HM, but\n"
	.string "had some regrets...\p"
	.string "Luckily, the LEAGUE employs the\n"
	.string "MOVE DELETER'S students!$"
