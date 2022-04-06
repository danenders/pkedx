FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Maniac::
	msgbox FortreeCity_House3_Text_MetStevenHadAmazingPokemon, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_SchoolKidM::
	goto_if_set FLAG_DELIVERY_TO_FORTREE, FortreeCity_House3_EventScript_SchoolKidMParcel
	msgbox FortreeCity_House3_Text_OhYouHavePokedex, MSGBOX_NPC
	end

FortreeCity_House3_Text_MetStevenHadAmazingPokemon:
	.string "While speaking about POKéDEXES,\n"
	.string "I remembered something.\p"
	.string "I met this TRAINER, STEVEN, when\n"
	.string "I was searching for rare stones.\p"
	.string "Hoo, boy, he had some amazing POKéMON\n"
	.string "with him.\p"
	.string "They weren't just rare, they were\n"
	.string "trained to terrifying extremes!\p"
	.string "He might even be stronger than the\n"
	.string "GYM LEADER in this town…$"

FortreeCity_House3_Text_OhYouHavePokedex:
	.string "What's that thing you have there?\p"
	.string "… … … … … …\p"
	.string "Oh, it's called a POKéDEX?\n"
	.string "It's really awesome!$"

FortreeCity_House3_EventScript_SchoolKidMParcel::
	goto_if_unset FLAG_DAILY_DELIVERY_QUEST, FortreeCity_House3_EventScript_SchoolKidMParcelLate
	msgbox PetalburgCity_PostOffice_Text_ThanksParcelDelivered, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_PostOffice_Text_HappyCustomer
	waitfanfare
	removeitem ITEM_PARCEL
	setflag FLAG_DELIVERY_COMPLETED
	clearflag FLAG_DELIVERY_TO_FORTREE
	release
	end

FortreeCity_House3_EventScript_SchoolKidMParcelLate::
	msgbox PetalburgCity_PostOffice_Text_MyParcelIsLate, MSGBOX_DEFAULT
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	message PetalburgCity_PostOffice_Text_UnhappyCustomer
	waitmessage
	removeitem ITEM_PARCEL
	release
	end
