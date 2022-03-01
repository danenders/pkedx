SafariZone_Northwest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_Northwest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SafariZone_Northwest_OnResume
	.byte 0

SafariZone_Northwest_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, SafariZone_Northwest_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, SafariZone_Northwest_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, SafariZone_Northwest_OnTransition_Night
	end

SafariZone_Northwest_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

SafariZone_Northwest_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

SafariZone_Northwest_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

SafariZone_Northwest_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, SafariZone_Northwest_OnResume_Day
	goto_if_eq VAR_RESULT, 1, SafariZone_Northwest_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, SafariZone_Northwest_OnResume_Night
	end	

SafariZone_Northwest_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

SafariZone_Northwest_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

SafariZone_Northwest_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

SafariZone_Northwest_EventScript_Man::
	msgbox SafariZone_Northwest_Text_Man, MSGBOX_NPC
	end

