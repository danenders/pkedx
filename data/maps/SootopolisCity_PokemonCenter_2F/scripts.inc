.set LOCALID_MOVE_DELETER, 1

SootopolisCity_PokemonCenter_2F_MapScripts::
	.byte 0

SootopolisCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_Ruckus::
	lock
	faceplayer
	msgbox SootopolisCity_PokemonCenter_2F_Text_Ruckus, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_2F_Text_Ruckus:
	.string "Why do people like TEAM MAGMA and\n"
	.string "TEAM AQUA feel like they need to\l"
	.string "make such a ruckus?\p"
	.string "They should be more like me and\n"
	.string "learn to relax a little!$"
