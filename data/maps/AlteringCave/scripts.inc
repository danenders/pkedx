AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnResume
	.byte 0

AlteringCave_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, AlteringCave_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, AlteringCave_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, AlteringCave_OnTransition_Night
	end

AlteringCave_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AlteringCave_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AlteringCave_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AlteringCave_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, AlteringCave_OnResume_Day
	goto_if_eq VAR_RESULT, 1, AlteringCave_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, AlteringCave_OnResume_Night
	end	

AlteringCave_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

AlteringCave_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

AlteringCave_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end
