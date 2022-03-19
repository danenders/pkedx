.set LOCALID_MEWTWO, 1
.set LOCALID_LEAF, 2

AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnResume
	.byte 0

AlteringCave_OnTransition:
	call_if_set FLAG_CAUGHT_MEWTWO, AlteringCave_EventScript_HideMewtwo
	call_if_unset FLAG_CAUGHT_MEWTWO, AlteringCave_EventScript_TryShowMewtwo
	end

AlteringCave_EventScript_HideMewtwo::
	setflag FLAG_HIDE_MEWTWO
	return

AlteringCave_EventScript_TryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEWTWO
	return

AlteringCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_EventScript_TryRemoveMewtwo
	end

AlteringCave_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MEWTWO
	return

AlteringCave_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MEWTWO, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_EventScript_RanFromMewtwo
	setflag FLAG_CAUGHT_MEWTWO
	release
	end

AlteringCave_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

AlteringCave_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

AlteringCave_EventScript_Leaf::
	trainerbattle_single TRAINER_LEAF, AlteringCave_Text_LeafBattleIntro, AlteringCave_Text_LeafBattleDefeat
	goto AlteringCave_EventScript_LeafBattled
	end

AlteringCave_EventScript_LeafBattled::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MEWTWO, AlteringCave_EventScript_MewtwoWillReturn
	goto_if_set FLAG_CAUGHT_MEWTWO, AlteringCave_EventScript_ICantBelieveIt
	msgbox AlteringCave_Text_LeafDefeated, MSGBOX_DEFAULT
	release
	end

AlteringCave_Text_LeafBattleIntro:
	.string "LEAF: {PLAYER}! I won't miss my\n"
	.string "chance to catch this POKéMON!$"

AlteringCave_Text_LeafBattleDefeat:
	.string "LEAF: Maybe I'm not strong enough\n"
	.string "to complete my mission...$"

AlteringCave_Text_LeafDefeated:
	.string "LEAF: If I can't beat you, {PLAYER}\n"
	.string "then I won't stand a chance\l"
	.string "against the POKéMON I'm chasing.$"


AlteringCave_EventScript_MewtwoWillReturn::
	applymovement LOCALID_LEAF, Common_Movement_ExclamationMark
	msgbox AlteringCave_Text_MewtwoWillReturn, MSGBOX_DEFAULT
	release
	end

AlteringCave_Text_MewtwoWillReturn:
	.string "LEAF: I saw MEWTWO flee the cave!\p"
	.string "I'm waiting for it to return!$"

AlteringCave_EventScript_ICantBelieveIt::
	msgbox AlteringCave_Text_ICantBelieveIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, AlteringCave_EventScript_GetStronger
	goto_if_eq VAR_RESULT, FALSE, AlteringCave_EventScript_MorePokemonAwait
	end

AlteringCave_Text_ICantBelieveIt:
	.string "LEAF: Wow, {PLAYER}!\p"
	.string "I can't believe it!\p"
	.string "You actually caught MEWTWO.\p"
	.string "I guess we can consider this\n"
	.string "the end of my mission...$"

AlteringCave_EventScript_GetStronger::
	msgbox AlteringCave_Text_GetStronger, MSGBOX_DEFAULT
	goto AlteringCave_EventScript_LeafLeaves
	end

AlteringCave_Text_GetStronger:
	.string "LEAF: It feels harder when you\n"
	.string "put it like that, {PLAYER}...\p"
	.string "But if anyone was able to\n"
	.string "complete my mission, I'm\l"
	.string "glad it was you, {PLAYER}!\p"
	.string "From now on, my new mission\n"
	.string "will be to get strong enough\l"
	.string "to surpass you!\p"
	.string "I won't lose to you again!$"

AlteringCave_EventScript_MorePokemonAwait::
	msgbox AlteringCave_Text_MorePokemonAwait, MSGBOX_DEFAULT
	goto AlteringCave_EventScript_LeafLeaves
	release
	end

AlteringCave_Text_MorePokemonAwait:
	.string "That's right, {PLAYER}!\p"
	.string "There's always more POKéMON\n"
	.string "to be discovered!\p"
	.string "I'm going to make it my new\n"
	.string "mission to discover a POKéMON\l"
	.string "even more powerful than MEWTWO!$"

AlteringCave_EventScript_LeafLeaves::
	fadescreen FADE_TO_BLACK
	setflag FLAG_LEAF_INSIDE_AC
	removeobject LOCALID_LEAF
	fadescreen FADE_FROM_BLACK
	release
	end
