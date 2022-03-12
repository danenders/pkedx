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
	lock
	faceplayer
	goto_if_set FLAG_MEWTWO_DEFEATED
 	msgbox AlteringCave_Text_PowerfulPokemon, MSGBOX_DEFAULT
	release
	end

AlteringCave_EventScript_Leaf_Searching::
	msgbox AlteringCave_Text_MewtwoWillReturn, MSGBOX_DEFAULT
	release
	end

AlteringCave_Text_PowerfulPokemon:
	.string "LEAF: I'm searching for a\n"
	.string "powerful POKéMON.$"

AlteringCave_Text_MewtwoWillReturn:
	.string "LEAF: I saw MEWTWO flee the\n"
	.string "cave!\p"
	.string "I'm waiting for it to return!$"
