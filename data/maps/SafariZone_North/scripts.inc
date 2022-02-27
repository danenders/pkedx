SafariZone_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SafariZone_North_OnResume
	.byte 0

SafariZone_North_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, SafariZone_North_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, SafariZone_North_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 0, SafariZone_North_OnTransition_Day
	end

SafariZone_North_OnTransition_Day:
	setvar VAR_TIMEOFDAY 0
	end

SafariZone_North_OnTransition_Night:
	setvar VAR_TIMEOFDAY 1
	end

SafariZone_North_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY 2
	end

SafariZone_North_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, SafariZone_North_OnResume_Night
	goto_if_eq VAR_RESULT, 2, SafariZone_North_OnResume_Twilight
	goto_if_eq VAR_RESULT, 0, SafariZone_North_OnResume_Day
	end	

SafariZone_North_OnResume_Day:
	setvar VAR_TIMEOFDAY 0
	end

SafariZone_North_OnResume_Night:
	setvar VAR_TIMEOFDAY 1
	end

SafariZone_North_OnResume_Twilight:
	setvar VAR_TIMEOFDAY 2
	end

SafariZone_North_EventScript_Fisherman::
	msgbox SafariZone_North_Text_Fisherman, MSGBOX_NPC
	end

SafariZone_North_EventScript_Man::
	msgbox SafariZone_North_Text_Man, MSGBOX_NPC
	end

