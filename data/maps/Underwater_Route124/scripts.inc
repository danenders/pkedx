Underwater_Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_Route124_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route124_OnResume
	.byte 0

Underwater_Route124_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Underwater_Route124_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Underwater_Route124_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Underwater_Route124_OnTransition_Night
	end

Underwater_Route124_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Underwater_Route124_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Underwater_Route124_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Underwater_Route124_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Underwater_Route124_OnResume_Day
	goto_if_eq VAR_RESULT, 1, Underwater_Route124_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, Underwater_Route124_OnResume_Night
	end

Underwater_Route124_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Underwater_Route124_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Underwater_Route124_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

