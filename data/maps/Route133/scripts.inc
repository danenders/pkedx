Route133_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route133_OnTransition
	map_script MAP_SCRIPT_ON_RESUME,Route133_OnResume
	.byte 0

Route133_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route133_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route133_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Route133_OnTransition_Night
	end

Route133_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route133_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route133_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route133_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route133_OnResume_Day
	goto_if_eq VAR_RESULT, 1, Route133_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, Route133_OnResume_Night
	end	

Route133_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route133_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route133_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route133_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA, Route133_Text_DebraIntro, Route133_Text_DebraDefeat
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Linda::
	trainerbattle_single TRAINER_LINDA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Beck::
	trainerbattle_single TRAINER_BECK, Route133_Text_BeckIntro, Route133_Text_BeckDefeat
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Mollie::
	trainerbattle_single TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Conor::
	trainerbattle_single TRAINER_CONOR, Route133_Text_ConorIntro, Route133_Text_ConorDefeat
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
	end

