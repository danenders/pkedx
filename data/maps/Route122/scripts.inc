Route122_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnTransition
	map_script MAP_SCRIPT_ON_RESUME,Route122_OnResume
	.byte 0

Route122_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route122_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route122_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Route122_OnTransition_Night
	end

Route122_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route122_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route122_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route122_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route122_OnResume_Day
	goto_if_eq VAR_RESULT, 1, Route122_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, Route122_OnResume_Night
	end	

Route122_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route122_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route122_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end
