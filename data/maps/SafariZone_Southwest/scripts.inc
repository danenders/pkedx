SafariZone_Southwest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_Southwest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SafariZone_Southwest_OnResume
	.byte 0

SafariZone_Southwest_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, SafariZone_Southwest_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, SafariZone_Southwest_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 0, SafariZone_Southwest_OnTransition_Day
	end

SafariZone_Southwest_OnTransition_Day:
	setvar VAR_TIMEOFDAY 0
	end

SafariZone_Southwest_OnTransition_Night:
	setvar VAR_TIMEOFDAY 1
	end

SafariZone_Southwest_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY 2
	end

SafariZone_Southwest_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, SafariZone_Southwest_OnResume_Night
	goto_if_eq VAR_RESULT, 2, SafariZone_Southwest_OnResume_Twilight
	goto_if_eq VAR_RESULT, 0, SafariZone_Southwest_OnResume_Day
	end	

SafariZone_Southwest_OnResume_Day:
	setvar VAR_TIMEOFDAY 0
	end

SafariZone_Southwest_OnResume_Night:
	setvar VAR_TIMEOFDAY 1
	end

SafariZone_Southwest_OnResume_Twilight:
	setvar VAR_TIMEOFDAY 2
	end

SafariZone_Southwest_EventScript_Woman::
	msgbox SafariZone_Southwest_Text_Woman, MSGBOX_NPC
	end

SafariZone_Southwest_EventScript_RestHouseSign::
	msgbox SafariZone_Southwest_Text_RestHouseSign, MSGBOX_SIGN
	end