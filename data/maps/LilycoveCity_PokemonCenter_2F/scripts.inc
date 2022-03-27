.set LOCALID_MOVE_DELETER, 1

LilycoveCity_PokemonCenter_2F_MapScripts::
	.byte 0

LilycoveCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end


LilycoveCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_OldMap::
	lock
	msgbox LilycoveCity_PokemonCenter_2F_Text_OldMap, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_2F_Text_OldMap:
	.string "I heard some guys talking about\n"
	.string "an exhibit at the MUSEUM...\p"
	.string "Who gets that excited over some\n"
	.string "dusty OLD SEA MAP?$"
