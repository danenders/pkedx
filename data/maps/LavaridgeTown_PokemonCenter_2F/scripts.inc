.include "data/scripts/pkmn_center_services.inc"
.set LOCALID_MOVE_DELETER, 1

LavaridgeTown_PokemonCenter_2F_MapScripts::
	.byte 0

LavaridgeTown_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end
