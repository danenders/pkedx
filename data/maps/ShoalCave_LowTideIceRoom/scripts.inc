.set LOCALID_ARTICUNO, 3

ShoalCave_LowTideIceRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideIceRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ShoalCave_LowTideIceRoom_OnResume
	.byte 0

ShoalCave_LowTideIceRoom_OnTransition:
	call_if_set FLAG_CAUGHT_ARTICUNO, ShoalCave_LowTideIceRoom_EventScript_HideArticuno
	call_if_unset FLAG_CAUGHT_ARTICUNO, ShoalCave_LowTideIceRoom_EventScript_TryShowArticuno
	end

ShoalCave_LowTideIceRoom_EventScript_HideArticuno::
	setflag FLAG_HIDE_ARTICUNO
	return

ShoalCave_LowTideIceRoom_EventScript_TryShowArticuno::
	goto_if_set FLAG_DEFEATED_ARTICUNO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ARTICUNO
	return

ShoalCave_LowTideIceRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ShoalCave_LowTideIceRoom_EventScript_TryRemoveArticuno
	end

ShoalCave_LowTideIceRoom_EventScript_TryRemoveArticuno::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ARTICUNO
	return

ShoalCave_LowTideIceRoom_EventScript_Articuno::
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
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ARTICUNO, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ShoalCave_LowTideIceRoom_EventScript_DefeatedArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ShoalCave_LowTideIceRoom_EventScript_RanFromArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ShoalCave_LowTideIceRoom_EventScript_RanFromArticuno
	setflag FLAG_CAUGHT_ARTICUNO
	release
	end

ShoalCave_LowTideIceRoom_EventScript_DefeatedArticuno::
	setflag FLAG_DEFEATED_ARTICUNO
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

ShoalCave_LowTideIceRoom_EventScript_RanFromArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end
