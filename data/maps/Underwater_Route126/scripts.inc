Underwater_Route126_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_Route126_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route126_OnResume
	.byte 0

Underwater_Route126_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, Underwater_Route126_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, Underwater_Route126_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 0, Underwater_Route126_OnTransition_Day
	end

Underwater_Route126_OnTransition_Day:
	setvar VAR_TIMEOFDAY 0
	end

Underwater_Route126_OnTransition_Night:
	setvar VAR_TIMEOFDAY 1
	end

Underwater_Route126_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY 2
	end

Underwater_Route126_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, Underwater_Route126_OnResume_Night
	goto_if_eq VAR_RESULT, 2, Underwater_Route126_OnResume_Twilight
	goto_if_eq VAR_RESULT, 0, Underwater_Route126_OnResume_Day
	end

Underwater_Route126_OnResume_Day:
	setvar VAR_TIMEOFDAY 0
	end

Underwater_Route126_OnResume_Night:
	setvar VAR_TIMEOFDAY 1
	end

Underwater_Route126_OnResume_Twilight:
	setvar VAR_TIMEOFDAY 2
	end
