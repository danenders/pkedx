MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_Exterior_OnResume
	.byte 0

MtPyre_Exterior_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, MtPyre_Exterior_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, MtPyre_Exterior_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, MtPyre_Exterior_OnTransition_Night
	end

MtPyre_Exterior_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, MtPyre_Exterior_OnResume_Day
	goto_if_eq VAR_RESULT, 1, MtPyre_Exterior_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, MtPyre_Exterior_OnResume_Night
	end	

MtPyre_Exterior_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

MtPyre_Exterior_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

MtPyre_Exterior_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	doweather
	end
