.set LOCALID_RAIKOU, 2
.set LOCALID_ENTEI, 3
.set LOCALID_SUICUNE, 4

ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ArtisanCave_B1F_OnResume
	.byte 0

ArtisanCave_B1F_OnTransition:
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	call_if_set FLAG_CAUGHT_RAIKOU, ArtisanCave_B1F_EventScript_HideRaikou
	call_if_unset FLAG_CAUGHT_RAIKOU, ArtisanCave_B1F_EventScript_TryShowRaikou
	call_if_set FLAG_CAUGHT_ENTEI, ArtisanCave_B1F_EventScript_HideEntei
	call_if_unset FLAG_CAUGHT_ENTEI, ArtisanCave_B1F_EventScript_TryShowEntei
	call_if_set FLAG_CAUGHT_SUICUNE, ArtisanCave_B1F_EventScript_HideSuicune
	call_if_unset FLAG_CAUGHT_SUICUNE, ArtisanCave_B1F_EventScript_TryShowSuicune	
	end

ArtisanCave_B1F_EventScript_HideRaikou::
	setflag FLAG_HIDE_RAIKOU
	return

ArtisanCave_B1F_EventScript_HideEntei::
	setflag FLAG_HIDE_ENTEI
	return

ArtisanCave_B1F_EventScript_HideSuicune::
	setflag FLAG_HIDE_SUICUNE
	return

ArtisanCave_B1F_EventScript_TryShowRaikou::
	goto_if_unset FLAG_CAUGHT_ZAPDOS, ArtisanCave_B1F_EventScript_HideRaikou
	goto_if_set FLAG_DEFEATED_RAIKOU, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_RAIKOU
	return

ArtisanCave_B1F_EventScript_TryShowEntei::
	goto_if_unset FLAG_CAUGHT_MOLTRES, ArtisanCave_B1F_EventScript_HideEntei
	goto_if_set FLAG_DEFEATED_ENTEI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ENTEI
	return

ArtisanCave_B1F_EventScript_TryShowSuicune::
	goto_if_unset FLAG_CAUGHT_ARTICUNO, ArtisanCave_B1F_EventScript_HideSuicune
	goto_if_set FLAG_DEFEATED_SUICUNE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SUICUNE
	return

ArtisanCave_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ArtisanCave_B1F_EventScript_TryRemoveRaikou
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ArtisanCave_B1F_EventScript_TryRemoveEntei
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ArtisanCave_B1F_EventScript_TryRemoveSuicune
	end

ArtisanCave_B1F_EventScript_TryRemoveRaikou::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_RAIKOU
	return

ArtisanCave_B1F_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ENTEI
	return

ArtisanCave_B1F_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SUICUNE
	return

ArtisanCave_B1F_EventScript_Raikou::
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
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_RAIKOU, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArtisanCave_B1F_EventScript_DefeatedRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ArtisanCave_B1F_EventScript_RanFromRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ArtisanCave_B1F_EventScript_RanFromRaikou
	setflag FLAG_CAUGHT_RAIKOU
	release
	end

ArtisanCave_B1F_EventScript_DefeatedRaikou::
	setflag FLAG_DEFEATED_RAIKOU
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end

ArtisanCave_B1F_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end


ArtisanCave_B1F_EventScript_Entei::
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
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ENTEI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArtisanCave_B1F_EventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ArtisanCave_B1F_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ArtisanCave_B1F_EventScript_RanFromEntei
	setflag FLAG_CAUGHT_ENTEI
	release
	end

ArtisanCave_B1F_EventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end

ArtisanCave_B1F_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end


ArtisanCave_B1F_EventScript_Suicune::
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
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_SUICUNE, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArtisanCave_B1F_EventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ArtisanCave_B1F_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ArtisanCave_B1F_EventScript_RanFromSuicune
	setflag FLAG_CAUGHT_SUICUNE
	release
	end

ArtisanCave_B1F_EventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryFlewAway
	end

ArtisanCave_B1F_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryFlewAway
	end
