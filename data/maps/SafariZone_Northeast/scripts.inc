SafariZone_Northeast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_Northeast_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SafariZone_Northeast_OnResume
	.byte 0

SafariZone_Northeast_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, SafariZone_Northeast_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, SafariZone_Northeast_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, SafariZone_Northeast_OnTransition_Night
	end

SafariZone_Northeast_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

SafariZone_Northeast_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

SafariZone_Northeast_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

SafariZone_Northeast_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, SafariZone_Northeast_OnResume_Day
	goto_if_eq VAR_RESULT, 1, SafariZone_Northeast_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, SafariZone_Northeast_OnResume_Night
	end	

SafariZone_Northeast_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

SafariZone_Northeast_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

SafariZone_Northeast_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

@ Event scripts for SafariZone_Northeast are in SafariZone_South/scripts.inc
