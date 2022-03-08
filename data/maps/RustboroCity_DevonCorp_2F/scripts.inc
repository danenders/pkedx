.set LOCALID_FOSSIL_SCIENTIST, 5

RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
	.string "We're developing a device for talking\n"
	.string "with POKéMON.\p"
	.string "But we haven't had much success…$"

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
	.string "I'm developing new kinds of\n"
	.string "POKé BALLS…\p"
	.string "But I haven't made much headway…$"

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
	.string "We finally made new kinds of\n"
	.string "POKé BALLS!\p"
	.string "The REPEAT BALL makes it easier to\n"
	.string "catch POKéMON you've caught before.\p"
	.string "The TIMER BALL gets better at catching\n"
	.string "POKéMON the longer a battle runs.\p"
	.string "Both are proudly developed by\n"
	.string "the DEVON CORPORATION.\p"
	.string "Please give them a try!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
	.string "I made the POKéNAV!\p"
	.string "As an engineer, I feel blessed to have\n"
	.string "made something so great!$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
	.string "Oh, wow!\n"
	.string "That's a POKéNAV!\p"
	.string "It came about as a result of our\n"
	.string "PRESIDENT's desire to learn about\l"
	.string "the feelings of POKéMON.\p"
	.string "Would you like me to describe its\n"
	.string "features in detail?\p"
	.string "No, no. I think you'll find out just by\n"
	.string "trying the POKéNAV out.$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
	.string "I'm trying to develop a device that\n"
	.string "visually reproduces the dreams of\l"
	.string "POKéMON…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
	.string "Oh, is that so?\p"
	.string "DEVON's technological expertise\n"
	.string "is outstanding, I tell you.$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
	.string "I've been trying to develop a device\n"
	.string "that resurrects POKéMON from fossils…\p"
	.string "And, it's working!$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
	.string "Wait! That thing you have there…\n"
	.string "Is that a POKéMON fossil?\p"
	.string "Would you like to bring that POKéMON\n"
	.string "back to life?\p"
	.string "I can with my newly developed\n"
	.string "FOSSIL REGENERATOR.$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeDomeFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeHelixFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeOldAmber
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, RustboroCity_DevonCorp_2F_EventScript_KabutoReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, RustboroCity_DevonCorp_2F_EventScript_OmanyteReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, RustboroCity_DevonCorp_2F_EventScript_AerodactylReady
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
	.string "The FOSSIL REGENERATOR, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MultipleFossils::
	msgbox RustboroCity_DevonCorp_2F_Text_MultipleFossils, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseAFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseAFossil::
	message RustboroCity_DevonCorp_2F_Text_ChooseAFossil
	waitmessage
	multichoice 17, 6, MULTI_FOSSIL, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil
	case 3, RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil
	case 4, RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber
	case 5, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	end

RustboroCity_DevonCorp_2F_Text_MultipleFossils:
	.string "Oh, now that's a surprise!\n"
	.string "You have multiple fossils?\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one POKéMON at a time.$"

RustboroCity_DevonCorp_2F_Text_ChooseAFossil:
	.string "Which of these fossils would you\n"
	.string "like to regenerate?$"

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_NoFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_NoFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_NoFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_NoFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_NoFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber
	end

RustboroCity_DevonCorp_2F_EventScript_NoFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_MustBeMistaken, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseAFossil
	end

RustboroCity_DevonCorp_2F_Text_MustBeMistaken:
	.string "You must be mistaken...\n"
	.string "You don't have a {STR_VAR_1}.$"

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeDomeFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	goto RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeHelixFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	goto RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeOldAmber::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_MultipleFossils
	goto RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber
	end

RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_DOME_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_OLD_AMBER
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
	release
	end

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the DEVON RESEARCHER.$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
	.string "Thanks for waiting!\p"
	.string "Your fossilized POKéMON has been\n"
	.string "brought back to life!\p"
	.string "The fossil was an ancient POKéMON.\n"
	.string "{STR_VAR_2}, it was!$"

RustboroCity_DevonCorp_2F_EventScript_LileepReady::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
	setvar VAR_TEMP_1, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
	setvar VAR_TEMP_1, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	return

RustboroCity_DevonCorp_2F_EventScript_KabutoReady::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveKabuto
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	givemon SPECIES_KABUTO, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedKabutoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedKabutoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferKabutoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferKabutoToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferKabutoToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedKabutoFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	return

RustboroCity_DevonCorp_2F_EventScript_OmanyteReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyte
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyteParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedOmanyteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanytePC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedOmanyteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferOmanyteToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferOmanyteToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferOmanyteToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedOmanyteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	return

RustboroCity_DevonCorp_2F_EventScript_AerodactylReady::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAerodactyl
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAerodactyl::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAerodactylParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAerodactylPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAerodactylParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAerodactylFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAerodactylPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAerodactylFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAerodactylToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAerodactylToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferAerodactylToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedAerodactylFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	return

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the DEVON RESEARCHER.$"

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingPokemon::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
	.string "Uh-oh, you've got too many POKéMON.\n"
	.string "You have no room for this one.$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
	.string "I'm trying to develop a new feature\n"
	.string "for the POKéNAV…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
	.string "Well, now what shall I work on\n"
	.string "developing next?\p"
	.string "Our company allows us to make our\n"
	.string "inspirations into reality.\p"
	.string "One couldn't ask for a better\n"
	.string "environment as an engineer.$"

