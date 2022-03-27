.set LOCALID_MOVE_DELETER, 1

FallarborTown_PokemonCenter_2F_MapScripts::
	.byte 0

FallarborTown_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

FallarborTown_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

FallarborTown_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

FallarborTown_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

FallarborTown_PokemonCenter_2F_EventScript_LanetteFan::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_2F_Text_Lanette, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_2F_Text_Lanette:
	.string "I heard FALLARBOR is home to some\n"
	.string "kind of computer genius.\p"
	.string "I can't even change my clocks!$"
