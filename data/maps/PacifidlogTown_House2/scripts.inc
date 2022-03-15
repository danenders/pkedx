PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILL: Rurii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "It appears to be very friendly with the\n"
	.string "TRAINER.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL: Rururi!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "It doesn't appear to like the TRAINER\n"
	.string "very much.$"



PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_IntroduceMyself
	goto_if_set FLAG_DAILY_FANCLUB_PRESENT, PacifidlogTown_House2_EventScript_ImproveBonds
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 2, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_IntroduceMyself::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	return

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Er-hem!\p"
	.string "I am the POKéMON FAN CLUB's most\n"
	.string "important person, the CHAIRMAN's\l"
	.string "younger brother.\p"
	.string "I'm here enjoying my vacation with\n"
	.string "POKéMON, yes, indeed.$"

PacifidlogTown_House2_EventScript_ImproveBonds::
	msgbox PacifidlogTown_House2_Text_ImproveBonds, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ImproveBonds:
	.string "POKéMON TRAINERS must always work\n"
	.string "to improve their bonds with their\l"
	.string "POKéMON partners.\p"
	.string "Come back tomorrow to show me how\n"
	.string "those bonds have grown!$"

PacifidlogTown_House2_EventScript_RespectPokemon::
	msgbox PacifidlogTown_House2_Text_RespectPokemon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_RespectPokemon:
	.string "POKéMON are our friends and partners.\p"
	.string "It is important that we always\n"
	.string "respect that relationship.$"

PacifidlogTown_House2_EventScript_GiveCandy::
	goto_if_set FLAG_DAILY_FANCLUB_PRESENT, PacifidlogTown_House2_EventScript_RespectPokemon
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FANCLUB_PRESENT
	msgbox PacifidlogTown_House2_Text_RespectPokemon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Ah!\n"
	.string "Your POKéMON…\p"
	.string "It clearly likes you very much.\p"
	.string "A POKéMON that adoring and adorable\n"
	.string "deserves a treat like this, no?$"

PacifidlogTown_House2_EventScript_GiveBerry::
	goto_if_set FLAG_DAILY_FANCLUB_PRESENT, PacifidlogTown_House2_EventScript_RespectPokemon
	msgbox PacifidlogTown_House2_Text_ImproveRelationship, MSGBOX_DEFAULT
	random 6
	goto_if_eq VAR_RESULT, 1, PacifidlogTown_House2_EventScript_Grepa
	goto_if_eq VAR_RESULT, 2, PacifidlogTown_House2_EventScript_Hondew
	goto_if_eq VAR_RESULT, 3, PacifidlogTown_House2_EventScript_Pomeg
	goto_if_eq VAR_RESULT, 4, PacifidlogTown_House2_EventScript_Kelpsy
	goto_if_eq VAR_RESULT, 5, PacifidlogTown_House2_EventScript_Qualot
	goto_if_eq VAR_RESULT, 6, PacifidlogTown_House2_EventScript_Tamato
	end

PacifidlogTown_House2_Text_ImproveRelationship:
	.string "Ah!\n"
	.string "Your POKéMON…\p"
	.string "You and your POKéMON could be\n"
	.string "doing more to improve your bond.\p"
	.string "Why don't you try giving it a\n"
	.string "treat like this.$"

PacifidlogTown_House2_EventScript_Grepa::
	giveitem ITEM_GREPA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FANCLUB_PRESENT
	end

PacifidlogTown_House2_EventScript_Hondew::
	giveitem ITEM_HONDEW_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FANCLUB_PRESENT
	end

PacifidlogTown_House2_EventScript_Pomeg::
	giveitem ITEM_POMEG_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FANCLUB_PRESENT
	end

PacifidlogTown_House2_EventScript_Kelpsy::
	giveitem ITEM_KELPSY_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FANCLUB_PRESENT
	end

PacifidlogTown_House2_EventScript_Qualot::
	giveitem ITEM_QUALOT_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FANCLUB_PRESENT
	end

PacifidlogTown_House2_EventScript_Tamato::
	giveitem ITEM_TAMATO_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FANCLUB_PRESENT
	end


PacifidlogTown_House2_EventScript_GiveReturn::
	goto_if_set FLAG_RECEIVED_TM27, PacifidlogTown_House2_EventScript_GiveCandy
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM27
	setflag FLAG_DAILY_FANCLUB_PRESENT
	call_if_set FLAG_RECEIVED_TM21, PacifidlogTown_House2_EventScript_CollectedTMs
	msgbox PacifidlogTown_House2_Text_ExplainReturn, MSGBOX_DEFAULT
	release
	end	

PacifidlogTown_House2_Text_AdoringPokemonTakeThisTM:
	.string "Ah!\n"
	.string "Your POKéMON…\p"
	.string "It clearly likes you very much.\p"
	.string "A POKéMON that adoring and adorable\n"
	.string "deserves a TM like this, no?$"

PacifidlogTown_House2_Text_ExplainReturn:
	.string "If a POKéMON likes you a lot, RETURN's\n"
	.string "power is enhanced.$"

PacifidlogTown_House2_EventScript_GiveFrustration::
	goto_if_set FLAG_RECEIVED_TM21, PacifidlogTown_House2_EventScript_GiveBerry
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM21
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM21
	setflag FLAG_DAILY_FANCLUB_PRESENT
	call_if_set FLAG_RECEIVED_TM27, PacifidlogTown_House2_EventScript_CollectedTMs
	msgbox PacifidlogTown_House2_Text_ExplainFrustration, MSGBOX_DEFAULT
	release
	end	

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Ah!\n"
	.string "Your POKéMON…\p"
	.string "It has a vicious look to it.\p"
	.string "A frightening POKéMON like that\n"
	.string "deserves a TM like this.$"

PacifidlogTown_House2_Text_ExplainFrustration:
	.string "If a POKéMON doesn't like you,\n"
	.string "FRUSTRATION's power goes up.$"

PacifidlogTown_House2_EventScript_CollectedTMs::
	setflag FLAG_RECEIVED_FANCLUB_TMS
	return

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Ah!\n"
	.string "Your POKéMON…\p"
	.string "Hmm…\n"
	.string "It's not bad, but it's also not good.\p"
	.string "You, as the TRAINER, need to put in\n"
	.string "some more effort.$"
