Route107_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route107_OnTransition
	map_script MAP_SCRIPT_ON_RESUME,Route107_OnResume
	.byte 0

Route107_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route107_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route107_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, Route107_OnTransition_Twilight
	end

Route107_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route107_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route107_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route107_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route107_OnResume_Day
	goto_if_eq VAR_RESULT, 1, Route107_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, Route107_OnResume_Night
	end	

Route107_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route107_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route107_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route107_EventScript_Darrin::
	trainerbattle_single TRAINER_DARRIN, Route107_Text_DarrinIntro, Route107_Text_DarrinDefeated
	msgbox Route107_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Tony::
	trainerbattle_single TRAINER_TONY_1, Route107_Text_TonyIntro, Route107_Text_TonyDefeated, Route107_EventScript_TonyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route107_EventScript_TonyRematch
	msgbox Route107_Text_TonyPostBattle, MSGBOX_DEFAULT
	release
	end

Route107_EventScript_TonyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route107_Text_TonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end

Route107_EventScript_TonyRematch::
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_TonyRematchIntro, Route107_Text_TonyRematchDefeated
	msgbox Route107_Text_TonyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route107_Text_DeniseIntro, Route107_Text_DeniseDefeated
	msgbox Route107_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Beth::
	trainerbattle_single TRAINER_BETH, Route107_Text_BethIntro, Route107_Text_BethDefeated
	msgbox Route107_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Lisa::
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_LisaIntro, Route107_Text_LisaDefeated, Route107_Text_LisaNotEnoughPokemon
	msgbox Route107_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Ray::
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_RayIntro, Route107_Text_RayDefeated, Route107_Text_RayNotEnoughPokemon
	msgbox Route107_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Camron::
	trainerbattle_single TRAINER_CAMRON, Route107_Text_CamronIntro, Route107_Text_CamronDefeated
	msgbox Route107_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

