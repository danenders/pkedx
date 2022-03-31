.set LOCALID_MOVE_DELETER, 1

RustboroCity_PokemonCenter_2F_MapScripts::
	.byte 0

RustboroCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

RustboroCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

RustboroCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

RustboroCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

RustboroCity_PokemonCenter_2F_EventScript_Pressure::
	lock
	faceplayer
	msgbox RustboroCity_PokemonCenter_2F_Text_Pressure, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_2F_Text_Pressure:
	.string "This GYM CHALLENGE is too much\p"
	.string "pressure! I can't take it!$"
