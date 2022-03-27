.set LOCALID_MOVE_DELETER, 1

EverGrandeCity_PokemonCenter_2F_MapScripts::
	.byte 0

EverGrandeCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

EverGrandeCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

EverGrandeCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

EverGrandeCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

EverGrandeCity_PokemonCenter_2F_EventScript_AllTheWay::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_2F_Text_AllTheWay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_2F_Text_AllTheWay:
	.string "Finally...it is finished.\p"
	.string "My ZIGZAGOON and I have finally\n"
	.string "made it to the POKeMON LEAGUE.$"

EverGrandeCity_PokemonCenter_2F_EventScript_Zigzagoon::
	lock
	faceplayer
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	waitmoncry
	release
	end