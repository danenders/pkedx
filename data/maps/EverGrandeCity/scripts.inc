EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_OnResume
	.byte 0

EverGrandeCity_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, EverGrandeCity_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, EverGrandeCity_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, EverGrandeCity_OnTransition_Night
	end

EverGrandeCity_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, EverGrandeCity_OnResume_Day
	goto_if_eq VAR_RESULT, 1, EverGrandeCity_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, EverGrandeCity_OnResume_Night
	end	

EverGrandeCity_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

EverGrandeCity_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

EverGrandeCity_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

