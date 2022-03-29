.set LOCALID_MOVE_DELETER, 1

PacifidlogTown_PokemonCenter_2F_MapScripts::
	.byte 0

PacifidlogTown_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_VacationMan::
	lock
	faceplayer
	msgbox PacifidlogTown_PokemonCenter_2F_Text_VacationMan, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_2F_Text_VacationMan:
	.string "Even on vacation, I can't get\n"
	.string "my rank out of my head...$"

PacifidlogTown_PokemonCenter_2F_EventScript_VacationWoman::
	lock
	faceplayer
	msgbox PacifidlogTown_PokemonCenter_2F_Text_VacationWoman, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_2F_Text_VacationWoman:
	.string "There's not a lot of prize money\n"
	.string "in battling, so we're taking a\l"
	.string "a modest vacation.$"