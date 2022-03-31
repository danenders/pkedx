.set LOCALID_MOVE_DELETER, 1

SlateportCity_PokemonCenter_2F_MapScripts::
	.byte 0

SlateportCity_PokemonCenter_2F_EventScript_RankBoard::
	lock
	call Common_EventScript_Pkmn_Center_Services_RankBoard
	release
	end

SlateportCity_PokemonCenter_2F_EventScript_MoveDeleter::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_MOVE_DELETER
	call Common_EventScript_Pkmn_Center_Services_MoveDeleter
	release
	end

SlateportCity_PokemonCenter_2F_EventScript_BerryClerk::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_BerryClerk
	release
	end

SlateportCity_PokemonCenter_2F_EventScript_EliteShop::
	lock
	faceplayer
	call Common_EventScript_Pkmn_Center_Services_EliteShop
	release
	end

SlateportCity_PokemonCenter_2F_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_SLATEPORT_FISHERMAN_RANKED, SlateportCity_PokemonCenter_2F_EventScript_FishermanSmallTalk
	goto_if_unset FLAG_BADGE05_GET, SlateportCity_PokemonCenter_2F_EventScript_FishermanRootingForYou
	goto_if_set FLAG_IS_CHAMPION, SlateportCity_PokemonCenter_2F_EventScript_YouDidIt
	msgbox SlateportCity_PokemonCenter_2F_Text_NiceJob, MSGBOX_DEFAULT
	giveitem ITEM_PEARL
	setflag FLAG_DAILY_SLATEPORT_FISHERMAN_RANKED
	release
	end	

SlateportCity_PokemonCenter_2F_EventScript_FishermanSmallTalk::
	msgbox SlateportCity_PokemonCenter_2F_Text_FishermanSmallTalk, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonCenter_2F_Text_FishermanSmallTalk:
	.string "Always aim for the top!$"

SlateportCity_PokemonCenter_2F_EventScript_FishermanRootingForYou::
	msgbox SlateportCity_PokemonCenter_2F_Text_InYourCorner, MSGBOX_DEFAULT
	release
	end	

SlateportCity_PokemonCenter_2F_Text_InYourCorner:
	.string "I've had my eye on the rankings.\p"
	.string "I think you're going places, kid!\p"
	.string "Come see me when you've made it\n"
	.string "a little further!$"

SlateportCity_PokemonCenter_2F_EventScript_YouDidIt::
	msgbox SlateportCity_PokemonCenter_2F_Text_YouDidIt, MSGBOX_DEFAULT
	giveitem ITEM_BIG_PEARL
	setflag FLAG_DAILY_SLATEPORT_FISHERMAN_RANKED
	release
	end	

SlateportCity_PokemonCenter_2F_Text_YouDidIt:
	.string "You did it, kid!\p"
	.string "You reached the top. But don't\n"
	.string "there's always a bigger fish!\p"
	.string "Take this for a prize, but\n"
	.string "keep pushing yourself even\l"
	.string "even further!$"

SlateportCity_PokemonCenter_2F_Text_NiceJob:
	.string "Nice job, kid!\p"
	.string "You're going places!\p"
	.string "Take this as a prize, but don't\n"
	.string "stop chasing those dreams!$"
