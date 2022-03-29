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

LavaridgeTown_PokemonCenter_2F_EventScript_Mime::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MRMIME, LavaridgeTown_PokemonCenter_2F_EventScript_ReceivedMime
	msgbox LavaridgeTown_PokemonCenter_2F_Text_HaveMimeWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_PokemonCenter_2F_EventScript_DeclineMime
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_PokemonCenter_2F_EventScript_NoRoomForMime
	msgbox LavaridgeTown_PokemonCenter_2F_Text_ReceivedMime, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_MRMIME
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_PokemonCenter_2F_Text_GetMime
	waitfanfare
	givemon SPECIES_MR_MIME, 20
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_HaveMimeWillYouTakeIt:
	.string "The TRAINER in front of you is staring\n"
	.string "intently at you.\p"
	.string "They gesture to your POKeBALLs and\n"
	.string "and nod.\p"
	.string "The TRAINER points to you, and then\n"
	.string "points back to themselves...\p"
	.string "It seems they wish to give you something.\p"
	.string "They hold out a POKeBALL towards you.\p"
	.string "Will you take it?$"

LavaridgeTown_PokemonCenter_2F_Text_MimeGiven:
	.string "The other TRAINER claps happily!$"

LavaridgeTown_PokemonCenter_2F_Text_GetMime:
	.string "{PLAYER} received MR.MIME!$"

LavaridgeTown_PokemonCenter_2F_EventScript_ReceivedMime::
	msgbox LavaridgeTown_PokemonCenter_2F_Text_MimeGiven, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_ReceivedMime:
	.string "The other TRAINER stares back at you\n"
	.string "blankly...$"

LavaridgeTown_PokemonCenter_2F_EventScript_NoRoomForMime::
	msgbox LavaridgeTown_PokemonCenter_2F_Text_NoRoomForMime, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_NoRoomForMime:
	.string "The trainer gestures to your bag\n"
	.string "and shakes their head…$"

LavaridgeTown_PokemonCenter_2F_EventScript_DeclineMime::
	msgbox LavaridgeTown_PokemonCenter_2F_Text_DeclineMime, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_DeclineMime:
	.string "The other TRAINER frowns...$"

LavaridgeTown_PokemonCenter_2F_EventScript_Jynx::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_JYNX, LavaridgeTown_PokemonCenter_2F_EventScript_ReceivedJynx
	msgbox LavaridgeTown_PokemonCenter_2F_Text_HaveJynxWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_PokemonCenter_2F_EventScript_DeclineJynx
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_PokemonCenter_2F_EventScript_NoRoomForJynx
	msgbox LavaridgeTown_PokemonCenter_2F_Text_ReceivedJynx, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_JYNX
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_PokemonCenter_2F_Text_GetJynx
	waitfanfare
	givemon SPECIES_JYNX, 20
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_HaveJynxWillYouTakeIt:
	.string "I just got back from visiting KANTO.\p"
	.string "I found a POKeMON I've never seen\n"
	.string "any other TRAINER use before!\p"
	.string "It must be really rare or strong.\p"
	.string "I'm not a TRAINER, but you look like\n"
	.string "someone who collects RARE POKeMON!\p"
	.string "Would you train this POKemON for me?$"

LavaridgeTown_PokemonCenter_2F_Text_JynxGiven:
	.string "I knew I could count on you!$"

LavaridgeTown_PokemonCenter_2F_Text_GetJynx:
	.string "{PLAYER} received JYNX!$"

LavaridgeTown_PokemonCenter_2F_EventScript_ReceivedJynx::
	msgbox LavaridgeTown_PokemonCenter_2F_Text_JynxGiven, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_ReceivedJynx:
	.string "I've never seen anyone else use\n"
	.string "this POKeMON!$"

LavaridgeTown_PokemonCenter_2F_EventScript_NoRoomForJynx::
	msgbox LavaridgeTown_PokemonCenter_2F_Text_NoRoomForJynx, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_NoRoomForJynx:
	.string "Oops, looks like you don't have\n"
	.string "room for this POKeMON right now.$"

LavaridgeTown_PokemonCenter_2F_EventScript_DeclineJynx::
	msgbox LavaridgeTown_PokemonCenter_2F_Text_DeclineJynx, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_2F_Text_DeclineJynx:
	.string "Oh, that's too bad.$"
