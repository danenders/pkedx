Route106_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route106_OnTransition
	map_script MAP_SCRIPT_ON_RESUME,Route106_OnResume
	.byte 0

Route106_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, Route106_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, Route106_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 0, Route106_OnTransition_Day
	end

Route106_OnTransition_Day:
	setvar VAR_TIMEOFDAY 0
	end

Route106_OnTransition_Night:
	setvar VAR_TIMEOFDAY 1
	end

Route106_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY 2
	end

Route106_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 1, Route106_OnResume_Night
	goto_if_eq VAR_RESULT, 2, Route106_OnResume_Twilight
	goto_if_eq VAR_RESULT, 0, Route106_OnResume_Day
	end	

Route106_OnResume_Day:
	setvar VAR_TIMEOFDAY 0
	end

Route106_OnResume_Night:
	setvar VAR_TIMEOFDAY 1
	end

Route106_OnResume_Twilight:
	setvar VAR_TIMEOFDAY 2
	end

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

