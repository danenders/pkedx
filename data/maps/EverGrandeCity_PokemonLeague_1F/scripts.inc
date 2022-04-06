.set LOCALID_NURSE, 1
.set LOCALID_GUARD_1, 3
.set LOCALID_GUARD_2, 4
.set LOCALID_LEAGUEWORKER, 6
.set LOCALID_LANETTE, 5

EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	call_if_unset FLAG_MET_LANETTE, EverGrandeCity_PokemonLeague_1F_EventScript_LanetteNotHere
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
	setobjectxyperm LOCALID_GUARD_1, 9, 2
	setobjectxyperm LOCALID_GUARD_2, 10, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement LOCALID_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement LOCALID_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_OBTAIN_BADGE
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm LOCALID_GUARD_1
	copyobjectxytoperm LOCALID_GUARD_2
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
	playse SE_FAILURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_left
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
	walk_right
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
	.string "You haven't obtained all the BADGES.\p"
	.string "If you're bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth:
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"


EverGrandeCity_PokemonLeague_1F_EventScript_LanetteNotHere::
	call_if_unset FLAG_BADGE08_GET, EverGrandeCity_PokemonLeague_1F_EventScript_LeagueWorker
	removeobject LOCALID_LEAGUEWORKER
	end

EverGrandeCity_PokemonLeague_1F_EventScript_LeagueWorker::
	setflag FLAG_HIDE_LANETTE_AT_LEAGUE
	addobject LOCALID_LEAGUEWORKER
	end

EverGrandeCity_PokemonLeague_1F_EventScript_WorkingUpstairs::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonLeague_1F_Text_WorkingUpstairs, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_Text_WorkingUpstairs:
	.string "Sorry kid, can't let you upstairs\n"
	.string "just yet.\p"
	.string "They're installing a lot of HI-TECH\n"
	.string "equipment up there.$"


EverGrandeCity_PokemonLeague_1F_EventScript_Lanette::
	goto_if_unset FLAG_IS_CHAMPION, EverGrandeCity_PokemonLeague_1F_EventScript_LanetteNotReady
	msgbox EverGrandeCity_PokemonLeague_1F_Text_Lanette, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonLeague_1F_EventScript_LanetteExit
	call_if_eq VAR_FACING, DIR_SOUTH, EverGrandeCity_PokemonLeague_1F_EventScript_LanetteExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonLeague_1F_EventScript_LanetteExitBlocked
	waitmovement 0
	removeobject LOCALID_LANETTE
	setflag FLAG_HIDE_LANETTE_AT_LEAGUE
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_LanetteExit::
	applymovement LOCALID_LANETTE, Movement_LanetteExit
	return

EverGrandeCity_PokemonLeague_1F_EventScript_LanetteExitBlocked::
	applymovement LOCALID_LANETTE, Movement_LanetteExitBlocked
	return

Movement_LanetteExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_LanetteExitBlocked:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonLeague_1F_Text_Lanette:
	.string "LANETTE: Wow, {PLAYER}!\p"
	.string "You defeated the ELITE FOUR?\p"
	.string "That's awesome!\p"
	.string "While you were challenging the\n"
	.string "LEAGUE, we finished renovations\l"
	.string "for the CABLE CLUB upstairs!\p"
	.string "I'm heading out, but come see\n"
	.string "me at my house sometime!$"

EverGrandeCity_PokemonLeague_1F_EventScript_LanetteNotReady::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonLeague_1F_Text_LanetteNotReady, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_Text_LanetteNotReady:
	.string "LANETTE: Hi, {PLAYER}!\p"
	.string "I'm helping the LEAGUE install\n"
	.string "the equipment for a CABLE CLUB\l"
	.string "upstairs!\p"
	.string "If it works, you'll be able to\n"
	.string "communicate with trainers from\l"
	.string "all different regions\p"
	.string "Wouldn't that be cool?\p"
	.string "We still need a little more time\n"
	.string "before it's ready, though.$"


EverGrandeCity_PokemonLeague_1F_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_DELIVERY_TO_EVERGRANDE, EverGrandeCity_PokemonLeague_1F_EventScript_BoyParcel
	msgbox EverGrandeCity_PokemonLeague_1F_Text_Boy, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_Text_Boy:
	.string "The ELITE FOUR were too tough\n"
	.string "for me, so I'm going to stick\l"
	.string "to what I know - video games!$"

EverGrandeCity_PokemonLeague_1F_EventScript_BoyParcel::
	goto_if_unset FLAG_DAILY_DELIVERY_QUEST, EverGrandeCity_PokemonLeague_1F_EventScript_BoyParcelLate
	msgbox PetalburgCity_PostOffice_Text_ThanksParcelDelivered, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_PostOffice_Text_HappyCustomer
	waitfanfare
	removeitem ITEM_PARCEL
	setflag FLAG_DELIVERY_COMPLETED
	clearflag FLAG_DELIVERY_TO_EVERGRANDE
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_BoyParcelLate::
	msgbox PetalburgCity_PostOffice_Text_MyParcelIsLate, MSGBOX_DEFAULT
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	message PetalburgCity_PostOffice_Text_UnhappyCustomer
	waitmessage
	removeitem ITEM_PARCEL
	release
	end
