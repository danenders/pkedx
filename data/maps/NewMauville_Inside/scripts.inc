.set LOCALID_ZAPDOS, 9

NewMauville_Inside_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
	.byte 0

NewMauville_Inside_OnResume:
	call_if_eq VAR_TEMP_1, 1, NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	call_if_eq VAR_TEMP_2, 1, NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveZapdos
	end

NewMauville_Inside_EventScript_TryRemoveVoltorb::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewMauville_Inside_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	call_if_unset FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
	call_if_unset FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
	call_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
	call_if_set FLAG_CAUGHT_ZAPDOS, NewMauville_Inside_EventScript_HideZapdos
	call_if_unset FLAG_CAUGHT_ZAPDOS, NewMauville_Inside_EventScript_TryShowZapdos
	end

NewMauville_Inside_EventScript_ShowVoltorb1::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1
	return

NewMauville_Inside_EventScript_ShowVoltorb2::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2
	return

NewMauville_Inside_EventScript_ShowVoltorb3::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3
	return

NewMauville_Inside_OnLoad:
	call_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	end

NewMauville_Inside_EventScript_BlueButton::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_GreenButton::
	lockall
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_SetBarrierStateBlueButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, FALSE
	return

NewMauville_Inside_EventScript_SetBarrierStateGreenButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, FALSE
	return

NewMauville_Inside_EventScript_RedButton::
	lockall
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	setvar VAR_NEW_MAUVILLE_STATE, 2
	releaseall
	end

NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, TRUE
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, TRUE
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, TRUE
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, TRUE
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, TRUE
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, TRUE
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, TRUE
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, TRUE
	special DrawWholeMapView
	return

NewMauville_Inside_EventScript_Generator::
	lockall
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_GeneratorOff
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_GeneratorOff::
	msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_Voltorb1::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb1
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb1::
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb2::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb2
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb2::
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb3::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb3
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb3::
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_Text_GeneratorRadiatingHeat:
	.string "The generator is radiating heat that\n"
	.string "can be felt even at a distance.\p"
	.string "It looks like it should be turned off\n"
	.string "as soon as possible.$"

NewMauville_Inside_Text_GeneratorQuietedDown:
	.string "The generator quieted down.$"

NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped:
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "The generator appears to have\n"
	.string "stopped…$"

NewMauville_Inside_EventScript_HideZapdos::
	setflag FLAG_HIDE_ZAPDOS
	return

NewMauville_Inside_EventScript_TryShowZapdos::
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ZAPDOS
	return

NewMauville_Inside_EventScript_TryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ZAPDOS
	return

NewMauville_Inside_EventScript_Zapdos::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ZAPDOS, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_RanFromZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_RanFromZapdos
	setflag FLAG_CAUGHT_ZAPDOS
	release
	end

NewMauville_Inside_EventScript_DefeatedZapdos::
	setflag FLAG_DEFEATED_ZAPDOS
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Inside_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end



NewMauville_Inside_EventScript_MeltanPuzzleBox1::
	lock
	goto_if_set FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanCaught
	goto_if_set FLAG_DEFEATED_MELTAN, NewMauville_Inside_EventScript_MeltanDefeated
	goto_if_unset FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanPuzzle1
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzle1::
	checkitem ITEM_MELTAN_CANDY
	call_if_eq VAR_RESULT, TRUE, NewMauville_Inside_EventScript_MeltanPuzzleStep1
	call_if_eq VAR_RESULT, FALSE, NewMauville_Inside_EventScript_SomethingLivingHere
	end

NewMauville_Inside_EventScript_MeltanPuzzleStep1::
	goto_if_eq VAR_TEMP_3, 0, NewMauville_Inside_EventScript_MeltanPuzzleStep1Correct
	playse SE_FLEE
	msgbox NewMauville_Inside_Text_MeltanPuzzleReset, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzleStep1Correct::
	setvar VAR_TEMP_3, 1
	playse SE_CLICK
	msgbox NewMauville_Inside_Text_MeltanPuzzleCorrect, MSGBOX_DEFAULT
	waitmessage
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzleBox2::
	lock
	goto_if_set FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanCaught
	goto_if_set FLAG_DEFEATED_MELTAN, NewMauville_Inside_EventScript_MeltanDefeated
	goto_if_unset FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanPuzzle2
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzle2::
	checkitem ITEM_MELTAN_CANDY
	call_if_eq VAR_RESULT, TRUE, NewMauville_Inside_EventScript_MeltanPuzzleStep2
	call_if_eq VAR_RESULT, FALSE, NewMauville_Inside_EventScript_SomethingLivingHere
	end

NewMauville_Inside_EventScript_MeltanPuzzleStep2::
	goto_if_eq VAR_TEMP_3, 1, NewMauville_Inside_EventScript_MeltanPuzzleStep2Correct
	playse SE_FLEE
	msgbox NewMauville_Inside_Text_MeltanPuzzleReset, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_TEMP_3, 0
	release
	end	

NewMauville_Inside_EventScript_MeltanPuzzleStep2Correct::
	setvar VAR_TEMP_3, 2
	playse SE_CLICK
	msgbox NewMauville_Inside_Text_MeltanPuzzleCorrect, MSGBOX_DEFAULT
	waitmessage
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzleBox3::
	lock
	goto_if_set FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanCaught
	goto_if_set FLAG_DEFEATED_MELTAN, NewMauville_Inside_EventScript_MeltanDefeated
	goto_if_unset FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanPuzzle3
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzle3::
	checkitem ITEM_MELTAN_CANDY
	call_if_eq VAR_RESULT, TRUE, NewMauville_Inside_EventScript_MeltanPuzzleStep3
	call_if_eq VAR_RESULT, FALSE, NewMauville_Inside_EventScript_SomethingLivingHere
	end

NewMauville_Inside_EventScript_MeltanPuzzleStep3::
	goto_if_eq VAR_TEMP_3, 2, NewMauville_Inside_EventScript_MeltanPuzzleStep3Correct
	playse SE_FLEE
	msgbox NewMauville_Inside_Text_MeltanPuzzleReset, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_TEMP_3, 0
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzleStep3Correct::
	setvar VAR_TEMP_3, 3
	playse SE_CLICK
	msgbox NewMauville_Inside_Text_MeltanPuzzleSolved, MSGBOX_DEFAULT
	waitmessage
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzleBox4::
	lock
	goto_if_set FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanCaught
	goto_if_set FLAG_DEFEATED_MELTAN, NewMauville_Inside_EventScript_MeltanDefeated
	goto_if_unset FLAG_CAUGHT_MELTAN, NewMauville_Inside_EventScript_MeltanPuzzle4
	release
	end

NewMauville_Inside_EventScript_MeltanPuzzle4::
	checkitem ITEM_MELTAN_CANDY
	call_if_eq VAR_RESULT, TRUE, NewMauville_Inside_EventScript_MeltanPuzzleStep4
	call_if_eq VAR_RESULT, FALSE, NewMauville_Inside_EventScript_SomethingLivingHere2
	end

NewMauville_Inside_EventScript_MeltanPuzzleStep4::
	goto_if_eq VAR_TEMP_3, 3, NewMauville_Inside_EventScript_EncounterMeltan
	playse SE_FLEE
	msgbox NewMauville_Inside_Text_MeltanPuzzleReset, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_TEMP_3, 0
	release
	end


NewMauville_Inside_Text_MeltanPuzzleCorrect:
	.string "Something rustled nearby...$"

NewMauville_Inside_Text_MeltanPuzzleReset:
	.string "Something rustled in the distance.$"

NewMauville_Inside_Text_MeltanPuzzleSolved:
	.string "You heard a clang in the corner!$"

NewMauville_Inside_EventScript_EncounterMeltan::
	lock
	message NewMauville_Inside_Text_MeltanJumpsOut
	waitmessage
	playmoncry SPECIES_MELTAN, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MELTAN, 25
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_MeltanDisappeared
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_MeltanDisappeared
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_MeltanDisappeared
	setflag FLAG_CAUGHT_MELTAN
	release
	end

NewMauville_Inside_EventScript_MeltanDefeated::
	msgbox NewMauville_Inside_Text_MeltanDisappeared, MSGBOX_DEFAULT
	release
	end

NewMauville_Inside_EventScript_MeltanDisappeared::
	setflag FLAG_DEFEATED_MELTAN
	fadescreen FADE_TO_BLACK
	delay 20
	fadescreen FADE_FROM_BLACK
	msgbox NewMauville_Inside_Text_MeltanRanOff, MSGBOX_DEFAULT
	release
	end

NewMauville_Inside_Text_MeltanRanOff:
	.string "The MELTAN ran off...$"

NewMauville_Inside_Text_MeltanDisappeared:
	.string "Theres no sign of MELTAN...$"

NewMauville_Inside_Text_MeltanJumpsOut:
	.string "Something jumped out from behind\n"
	.string "the machinery!$"

NewMauville_Inside_EventScript_MeltanCaught::
	msgbox NewMauville_Inside_Text_MeltanCaught, MSGBOX_DEFAULT
	end

NewMauville_Inside_Text_MeltanCaught:
	.string "There's nothing inside.$"

NewMauville_Inside_EventScript_SomethingLivingHere::
	msgbox NewMauville_Inside_Text_SomethingLivingHere, MSGBOX_DEFAULT
	release
	end

NewMauville_Inside_Text_SomethingLivingHere:
	.string "It looks like this box's contents\n"
	.string "were all scattered about...\p"
	.string "Perhaps a POKEMON got inside?$"

NewMauville_Inside_EventScript_SomethingLivingHere2::
	msgbox NewMauville_Inside_Text_SomethingLivingHere2, MSGBOX_DEFAULT
	release
	end

NewMauville_Inside_Text_SomethingLivingHere2:
	.string "It looks like this machine\n"
	.string "has been moved around...\p"
	.string "Perhaps a POKEMON got behind it?$"

