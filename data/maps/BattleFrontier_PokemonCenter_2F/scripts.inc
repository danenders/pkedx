.set LOCALID_MOVE_DELETER, 1

BattleFrontier_PokemonCenter_2F_MapScripts::
	.byte 0

BattleFrontier_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

BattleFrontier_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

BattleFrontier_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

BattleFrontier_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

BattleFrontier_PokemonCenter_2F_EventScript_FrontierLady::
	lock
	faceplayer
	msgbox BattleFrontier_PokemonCenter_2F_Text_FrontierLady, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_2F_Text_FrontierLady:
	.string "I rose to the top of the RANKS,\n"
	.string "but the BATTLE FRONTIER is a\l"
	.string "completely different level than\l"
	.string "the LEAGUE!$"
