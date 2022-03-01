SafariZone_Southeast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_Southeast_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SafariZone_Southeast_OnResume
	.byte 0

@ Event scripts for SafariZone_Southeast are in SafariZone_South/scripts.inc

SafariZone_Southeast_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, SafariZone_Southeast_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, SafariZone_Southeast_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, SafariZone_Southeast_OnTransition_Night
	end

SafariZone_Southeast_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

SafariZone_Southeast_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

SafariZone_Southeast_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

SafariZone_Southeast_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, SafariZone_Southeast_OnResume_Day
	goto_if_eq VAR_RESULT, 1, SafariZone_Southeast_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, SafariZone_Southeast_OnResume_Night
	end	

SafariZone_Southeast_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

SafariZone_Southeast_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

SafariZone_Southeast_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end