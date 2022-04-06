PetalburgCity_PostOffice_MapScripts::
	.byte 0


PetalburgCity_PostOffice_EventScripts_Worker::
	lock
	faceplayer
	msgbox PetalburgCity_PostOffice_Text_Worker, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_EventScripts_OldWoman::
	lock
	faceplayer
	msgbox PetalburgCity_PostOffice_Text_OldWoman, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_EventScripts_Shopper::
	lock
	faceplayer
	msgbox PetalburgCity_PostOffice_Text_Shopper, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_OldWoman:
	.string "I'm waiting for my grandson to\n"
	.string "write me a letter from KANTO.$"

PetalburgCity_PostOffice_Text_Shopper:
	.string "Should I get the stamps with a\n"
	.string "PIKACHU or MARILL on them?$"

PetalburgCity_PostOffice_Text_Worker:
	.string "We process mail from all around\n"
	.string "HOENN here!\p"
	.string "We even get packages from KANTO\n"
	.string "and JOHTO sometimes too!$"


PetalburgCity_PostOffice_EventScripts_DeliveryQuest::
	lock
	faceplayer
	goto_if_set FLAG_DELIVERY_STARTED, PetalburgCity_PostOffice_EventScripts_DeliveryStatus
	goto_if_set FLAG_DAILY_DELIVERY_QUEST, PetalburgCity_PostOffice_EventScripts_ComeBackTomorrow
	msgbox PetalburgCity_PostOffice_Text_HelpWithDeliveries, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PostOffice_EventScripts_AssignDelivery
	msgbox PetalburgCity_PostOffice_Text_CouldUseAHand, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_EventScripts_AssignDelivery::
	checkitemspace ITEM_PARCEL
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_PostOffice_EventScripts_NoRoom
	giveitem ITEM_PARCEL
	goto_if_set FLAG_BADGE08_GET, PetalburgCity_PostOffice_EventScripts_AssignDeliveryAll
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_PostOffice_EventScripts_AssignDeliveryMost
	goto_if_set FLAG_BADGE03_GET, PetalburgCity_PostOffice_EventScripts_AssignDeliveryMore
	goto_if_set FLAG_BADGE01_GET, PetalburgCity_PostOffice_EventScripts_AssignDeliveryFew
	goto PetalburgCity_PostOffice_EventScripts_AssignDeliveryEasy
	end

PetalburgCity_PostOffice_EventScripts_NoRoom::
	msgbox PetalburgCity_PostOffice_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_NoRoom:
	.string "Oh! This PARCEL is too big\n"
	.string "to fit in your bag right now.\p"
	.string "Come back when you have some\n"
	.string "more room to carry it.$"

PetalburgCity_PostOffice_EventScripts_AssignDeliveryEasy::
	setflag FLAG_DAILY_DELIVERY_QUEST
	setflag FLAG_DELIVERY_STARTED
	random 3
	goto_if_eq VAR_RESULT, 1, PetalburgCity_PostOffice_EventScripts_DestinationPetalburg
	goto_if_eq VAR_RESULT, 2, PetalburgCity_PostOffice_EventScripts_DestinationLittleroot
	goto_if_eq VAR_RESULT, 3, PetalburgCity_PostOffice_EventScripts_DestinationOldale
	end

PetalburgCity_PostOffice_EventScripts_AssignDeliveryFew::
	setflag FLAG_DAILY_DELIVERY_QUEST
	setflag FLAG_DELIVERY_STARTED
	random 4
	goto_if_eq VAR_RESULT, 1, PetalburgCity_PostOffice_EventScripts_DestinationPetalburg
	goto_if_eq VAR_RESULT, 2, PetalburgCity_PostOffice_EventScripts_DestinationRustboro
	goto_if_eq VAR_RESULT, 3, PetalburgCity_PostOffice_EventScripts_DestinationLittleroot
	goto_if_eq VAR_RESULT, 4, PetalburgCity_PostOffice_EventScripts_DestinationOldale
	end

PetalburgCity_PostOffice_EventScripts_AssignDeliveryMore::
	setflag FLAG_DAILY_DELIVERY_QUEST
	setflag FLAG_DELIVERY_STARTED
	random 6
	goto_if_eq VAR_RESULT, 1, PetalburgCity_PostOffice_EventScripts_DestinationPetalburg
	goto_if_eq VAR_RESULT, 2, PetalburgCity_PostOffice_EventScripts_DestinationMauville
	goto_if_eq VAR_RESULT, 3, PetalburgCity_PostOffice_EventScripts_DestinationRustboro
	goto_if_eq VAR_RESULT, 4, PetalburgCity_PostOffice_EventScripts_DestinationLittleroot
	goto_if_eq VAR_RESULT, 5, PetalburgCity_PostOffice_EventScripts_DestinationOldale
	goto_if_eq VAR_RESULT, 6, PetalburgCity_PostOffice_EventScripts_DestinationDewford
	end

PetalburgCity_PostOffice_EventScripts_AssignDeliveryMost::
	setflag FLAG_DAILY_DELIVERY_QUEST
	setflag FLAG_DELIVERY_STARTED
	random 10
	goto_if_eq VAR_RESULT, 1, PetalburgCity_PostOffice_EventScripts_DestinationPetalburg
	goto_if_eq VAR_RESULT, 2, PetalburgCity_PostOffice_EventScripts_DestinationSlateport
	goto_if_eq VAR_RESULT, 3, PetalburgCity_PostOffice_EventScripts_DestinationMauville
	goto_if_eq VAR_RESULT, 4, PetalburgCity_PostOffice_EventScripts_DestinationRustboro
	goto_if_eq VAR_RESULT, 5, PetalburgCity_PostOffice_EventScripts_DestinationLittleroot
	goto_if_eq VAR_RESULT, 6, PetalburgCity_PostOffice_EventScripts_DestinationOldale
	goto_if_eq VAR_RESULT, 7, PetalburgCity_PostOffice_EventScripts_DestinationDewford
	goto_if_eq VAR_RESULT, 8, PetalburgCity_PostOffice_EventScripts_DestinationFallarbor
	end

PetalburgCity_PostOffice_EventScripts_AssignDeliveryAll::
	setflag FLAG_DAILY_DELIVERY_QUEST
	setflag FLAG_DELIVERY_STARTED
	random 16
	goto_if_eq VAR_RESULT, 1, PetalburgCity_PostOffice_EventScripts_DestinationPetalburg
	goto_if_eq VAR_RESULT, 2, PetalburgCity_PostOffice_EventScripts_DestinationSlateport
	goto_if_eq VAR_RESULT, 3, PetalburgCity_PostOffice_EventScripts_DestinationMauville
	goto_if_eq VAR_RESULT, 4, PetalburgCity_PostOffice_EventScripts_DestinationRustboro
	goto_if_eq VAR_RESULT, 5, PetalburgCity_PostOffice_EventScripts_DestinationFortree
	goto_if_eq VAR_RESULT, 6, PetalburgCity_PostOffice_EventScripts_DestinationLilycove
	goto_if_eq VAR_RESULT, 7, PetalburgCity_PostOffice_EventScripts_DestinationMossdeep
	goto_if_eq VAR_RESULT, 8, PetalburgCity_PostOffice_EventScripts_DestinationSootopolis
	goto_if_eq VAR_RESULT, 9, PetalburgCity_PostOffice_EventScripts_DestinationEvergrande
	goto_if_eq VAR_RESULT, 10, PetalburgCity_PostOffice_EventScripts_DestinationLittleroot
	goto_if_eq VAR_RESULT, 11, PetalburgCity_PostOffice_EventScripts_DestinationOldale
	goto_if_eq VAR_RESULT, 12, PetalburgCity_PostOffice_EventScripts_DestinationDewford
	goto_if_eq VAR_RESULT, 13, PetalburgCity_PostOffice_EventScripts_DestinationLavaridge
	goto_if_eq VAR_RESULT, 14, PetalburgCity_PostOffice_EventScripts_DestinationFallarbor
	goto_if_eq VAR_RESULT, 15, PetalburgCity_PostOffice_EventScripts_DestinationVerdanturf
	goto_if_eq VAR_RESULT, 16, PetalburgCity_PostOffice_EventScripts_DestinationPacifidlog
	end

PetalburgCity_PostOffice_EventScripts_DestinationPetalburg::
	setflag FLAG_DELIVERY_TO_PETALBURG
	msgbox PetalburgCity_PostOffice_Text_DestinationPetalburg
	release
	end

PetalburgCity_PostOffice_Text_DestinationPetalburg:
	.string "This customer is located in\n"
	.string "PETALBURG CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationSlateport::
	setflag FLAG_DELIVERY_TO_SLATEPORT
	msgbox PetalburgCity_PostOffice_Text_DestinationSlateport
	release
	end

PetalburgCity_PostOffice_Text_DestinationSlateport:
	.string "This customer is located in\n"
	.string "SLATEPORT CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationMauville::
	setflag FLAG_DELIVERY_TO_MAUVILLE
	msgbox PetalburgCity_PostOffice_Text_DestinationMauville
	release
	end

PetalburgCity_PostOffice_Text_DestinationMauville:
	.string "This customer is located in\n"
	.string "MAUVILLE CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationRustboro::
	setflag FLAG_DELIVERY_TO_RUSTBORO
	msgbox PetalburgCity_PostOffice_Text_DestinationRustboro
	release
	end

PetalburgCity_PostOffice_Text_DestinationRustboro:
	.string "This customer is located in\n"
	.string "RUSTBORO CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationFortree::
	setflag FLAG_DELIVERY_TO_FORTREE
	msgbox PetalburgCity_PostOffice_Text_DestinationFortree
	release
	end

PetalburgCity_PostOffice_Text_DestinationFortree:
	.string "This customer is located in\n"
	.string "FORTREE CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationLilycove::
	setflag FLAG_DELIVERY_TO_LILYCOVE
	msgbox PetalburgCity_PostOffice_Text_DestinationLilycove
	release
	end

PetalburgCity_PostOffice_Text_DestinationLilycove:
	.string "This customer is located in\n"
	.string "LILYCOVE CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationMossdeep::
	setflag FLAG_DELIVERY_TO_MOSSDEEP
	msgbox PetalburgCity_PostOffice_Text_DestinationMossdeep
	release
	end

PetalburgCity_PostOffice_Text_DestinationMossdeep:
	.string "This customer is located in\n"
	.string "MOSSDEEP CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationSootopolis::
	setflag FLAG_DELIVERY_TO_SOOTOPOLIS
	msgbox PetalburgCity_PostOffice_Text_DestinationSootopolis
	release
	end

PetalburgCity_PostOffice_Text_DestinationSootopolis:
	.string "This customer is located in\n"
	.string "SOOTOPOLIS CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationEvergrande::
	setflag FLAG_DELIVERY_TO_EVERGRANDE
	msgbox PetalburgCity_PostOffice_Text_DestinationEvergrande
	release
	end

PetalburgCity_PostOffice_Text_DestinationEvergrande:
	.string "This customer is located in\n"
	.string "EVERGRANDE CITY.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationLittleroot::
	setflag FLAG_DELIVERY_TO_LITTLEROOT
	msgbox PetalburgCity_PostOffice_Text_DestinationLittleroot
	release
	end

PetalburgCity_PostOffice_Text_DestinationLittleroot:
	.string "This customer is located in\n"
	.string "LITTLEROOT TOWN.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationOldale::
	setflag FLAG_DELIVERY_TO_OLDALE
	msgbox PetalburgCity_PostOffice_Text_DestinationOldale
	release
	end

PetalburgCity_PostOffice_Text_DestinationOldale:
	.string "This customer is located in\n"
	.string "OLDALE TOWN.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationDewford::
	setflag FLAG_DELIVERY_TO_DEWFORD
	msgbox PetalburgCity_PostOffice_Text_DestinationDewford
	release
	end

PetalburgCity_PostOffice_Text_DestinationDewford:
	.string "This customer is located in\n"
	.string "DEWFORD TOWN.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationLavaridge::
	setflag FLAG_DELIVERY_TO_LAVARIDGE
	msgbox PetalburgCity_PostOffice_Text_DestinationLavaridge
	release
	end

PetalburgCity_PostOffice_Text_DestinationLavaridge:
	.string "This customer is located in\n"
	.string "LAVARIDGE TOWN.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationFallarbor::
	setflag FLAG_DELIVERY_TO_FALLARBOR
	msgbox PetalburgCity_PostOffice_Text_DestinationFallarbor
	release
	end

PetalburgCity_PostOffice_Text_DestinationFallarbor:
	.string "This customer is located in\n"
	.string "FALLARBOR TOWN.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationVerdanturf::
	setflag FLAG_DELIVERY_TO_VERDANTURF
	msgbox PetalburgCity_PostOffice_Text_DestinationVerdanturf
	release
	end

PetalburgCity_PostOffice_Text_DestinationVerdanturf:
	.string "This customer is located in\n"
	.string "VERDANTURF TOWN.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_EventScripts_DestinationPacifidlog::
	setflag FLAG_DELIVERY_TO_PACIFIDLOG
	msgbox PetalburgCity_PostOffice_Text_DestinationPacifidlog
	release
	end

PetalburgCity_PostOffice_Text_DestinationPacifidlog:
	.string "This customer is located in\n"
	.string "PACIFIDLOG TOWN.\p"
	.string "Unfortunately, the label is\n"
	.string "a bit worn, so I can't tell\l"
	.string "exactly who it's for.\p"
	.string "But you shouldn't have any\n"
	.string "trouble, right {PLAYER}?$"

PetalburgCity_PostOffice_Text_HelpWithDeliveries::
	.string "We're a small POST OFFICE, but we\n"
	.string "serve all of HOENN!\p"
	.string "To be honest, it's a lot of work!\p"
	.string "We sure could use the help of a\n"
	.string "TRAINER like you.\p"
	.string "While you're out traveling, could\n"
	.string "you deliver this PARCEL for us?$"

PetalburgCity_PostOffice_Text_CouldUseAHand::
	.string "That's a shame, we could use the\n"
	.string "help...\p"
	.string "Too bad my AZUMARILL can't learn\n"
	.string "TELEPORT or FLY...$"

PetalburgCity_PostOffice_EventScripts_ComeBackTomorrow::
	msgbox PetalburgCity_PostOffice_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_ComeBackTomorrow:
	.string "I don't have any more deliveries\n"
	.string "for you to make today, {PLAYER}.$"

PetalburgCity_PostOffice_EventScripts_DeliveryStatus::
	goto_if_set FLAG_DELIVERY_COMPLETED, PetalburgCity_PostOffice_EventScripts_DeliveryCompleted
	goto_if_unset FLAG_DAILY_DELIVERY_QUEST, PetalburgCity_PostOffice_EventScripts_DeliveryFailed
	goto PetalburgCity_PostOffice_EventScripts_DeliveryActive
	end

PetalburgCity_PostOffice_EventScripts_DeliveryActive::
	goto_if_set FLAG_DELIVERY_TO_PETALBURG, PetalburgCity_PostOffice_EventScripts_DeliveryThatToPetalburg
	goto_if_set FLAG_DELIVERY_TO_SLATEPORT, PetalburgCity_PostOffice_EventScripts_DeliveryThatToSlateport
	goto_if_set FLAG_DELIVERY_TO_MAUVILLE, PetalburgCity_PostOffice_EventScripts_DeliveryThatToMauville
	goto_if_set FLAG_DELIVERY_TO_RUSTBORO, PetalburgCity_PostOffice_EventScripts_DeliveryThatToRustboro
	goto_if_set FLAG_DELIVERY_TO_FORTREE, PetalburgCity_PostOffice_EventScripts_DeliveryThatToFortree
	goto_if_set FLAG_DELIVERY_TO_LILYCOVE, PetalburgCity_PostOffice_EventScripts_DeliveryThatToLilycove
	goto_if_set FLAG_DELIVERY_TO_MOSSDEEP, PetalburgCity_PostOffice_EventScripts_DeliveryThatToMossdeep 
	goto_if_set FLAG_DELIVERY_TO_SOOTOPOLIS, PetalburgCity_PostOffice_EventScripts_DeliveryThatToSootopolis 
	goto_if_set FLAG_DELIVERY_TO_EVERGRANDE, PetalburgCity_PostOffice_EventScripts_DeliveryThatToEvergrande
	goto_if_set FLAG_DELIVERY_TO_LITTLEROOT, PetalburgCity_PostOffice_EventScripts_DeliveryThatToLittleroot
	goto_if_set FLAG_DELIVERY_TO_OLDALE, PetalburgCity_PostOffice_EventScripts_DeliveryThatToOldale
	goto_if_set FLAG_DELIVERY_TO_DEWFORD, PetalburgCity_PostOffice_EventScripts_DeliveryThatToDewford
	goto_if_set FLAG_DELIVERY_TO_LAVARIDGE, PetalburgCity_PostOffice_EventScripts_DeliveryThatToLavaridge
	goto_if_set FLAG_DELIVERY_TO_FALLARBOR, PetalburgCity_PostOffice_EventScripts_DeliveryThatToFallarbor
	goto_if_set FLAG_DELIVERY_TO_VERDANTURF, PetalburgCity_PostOffice_EventScripts_DeliveryThatToVerdanturf
	goto_if_set FLAG_DELIVERY_TO_PACIFIDLOG, PetalburgCity_PostOffice_EventScripts_DeliveryThatToPacifidlog
	end

PetalburgCity_PostOffice_EventScripts_DeliveryThatToPetalburg::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToPetalburg, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToPetalburg:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to PETALBURG CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToSlateport::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToSlateport, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToSlateport:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to SLATEPORT CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToMauville::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToMauville, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToMauville:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to MAUVILLE CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToRustboro::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToRustboro, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToRustboro:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to RUSTBORO CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToFortree::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToFortree, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToFortree:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to FORTREE CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToLilycove::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToLilycove, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToLilycove:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to LILYCOVE CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToMossdeep::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToMossdeep, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToMossdeep:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to MOSSDEEP CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToSootopolis::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToSootopolis, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToSootopolis:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to SOOTOPOLIS CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToEvergrande::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToEvergrande, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToEvergrande:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to EVERGRANDE CITY, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToLittleroot::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToLittleroot, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToLittleroot:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to LITTLEROOT TOWN, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToOldale::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToOldale, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToOldale:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to OLDALE TOWN, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToDewford::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToDewford:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to DEWFORD TOWN, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToLavaridge::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToLavaridge, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToLavaridge:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to LAVARIDGE TOWN, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToFallarbor::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToFallarbor, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToFallarbor:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to FALLARBOR TOWN, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToVerdanturf::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToVerdanturf, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToVerdanturf:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to VERDANTURF TOWN, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryThatToPacifidlog::
	msgbox PetalburgCity_PostOffice_Text_DeliveryThatToPacifidlog, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PostOffice_Text_DeliveryThatToPacifidlog:
	.string "Don't forget to deliver that PARCEL\n"
	.string "to PACIFIDLOG TOWN, {PLAYER}.\p"
	.string "The customer expects it today!$"

PetalburgCity_PostOffice_EventScripts_DeliveryCompleted::
	msgbox PetalburgCity_PostOffice_Text_DeliveryCompleted, MSGBOX_DEFAULT
	showmoneybox 0,0
	playse SE_SHOP
	addmoney 3000
	updatemoneybox
	msgbox PetalburgCity_PostOffice_Text_CashReward, MSGBOX_DEFAULT
	hidemoneybox
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	release
	end

PetalburgCity_PostOffice_Text_DeliveryCompleted:
	.string "Thanks for delivering the PARCEL,\n"
	.string "{PLAYER}!\p"
	.string "Our customer was so happy to get\n"
	.string "it that they left a generous tip!\p"
	.string "Here's some for you!$"

PetalburgCity_PostOffice_Text_CashReward:
	.string "You got ¥3,000!$"

PetalburgCity_PostOffice_EventScripts_DeliveryFailed::
	lock
	faceplayer
	msgbox PetalburgCity_PostOffice_Text_AngryCustomer, MSGBOX_DEFAULT
	removeitem ITEM_PARCEL
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	release
	end

PetalburgCity_PostOffice_Text_AngryCustomer:
	.string "This is very disappointing.\p"
	.string "We just received a call from a\n"
	.string "very unhappy customer.\p"
	.string "We'll have someone else deliver\n"
	.string "this PARCEL for you.\p"
	.string "Please don't let this happen\n"
	.string "again.$"

PetalburgCity_PostOffice_EventScripts_ResetDeliveries::
	clearflag FLAG_DELIVERY_STARTED
	clearflag FLAG_DELIVERY_COMPLETED
	clearflag FLAG_DELIVERY_TO_PETALBURG 
	clearflag FLAG_DELIVERY_TO_SLATEPORT
	clearflag FLAG_DELIVERY_TO_MAUVILLE
	clearflag FLAG_DELIVERY_TO_RUSTBORO 
	clearflag FLAG_DELIVERY_TO_FORTREE
	clearflag FLAG_DELIVERY_TO_LILYCOVE
	clearflag FLAG_DELIVERY_TO_MOSSDEEP 
	clearflag FLAG_DELIVERY_TO_SOOTOPOLIS 
	clearflag FLAG_DELIVERY_TO_EVERGRANDE
	clearflag FLAG_DELIVERY_TO_LITTLEROOT
	clearflag FLAG_DELIVERY_TO_OLDALE
	clearflag FLAG_DELIVERY_TO_DEWFORD
	clearflag FLAG_DELIVERY_TO_LAVARIDGE
	clearflag FLAG_DELIVERY_TO_FALLARBOR
	clearflag FLAG_DELIVERY_TO_VERDANTURF
	clearflag FLAG_DELIVERY_TO_PACIFIDLOG
	return


PetalburgCity_PostOffice_Text_HappyCustomer:
	.string "You delivered the PARCEL to\n"
	.string "the happy customer!$"

PetalburgCity_PostOffice_Text_UnhappyCustomer:
	.string "You delivered the PARCEL to\n"
	.string "the unhappy customer!$"

PetalburgCity_PostOffice_Text_MyParcelIsLate:
	.string "Oh! My PARCEL!\p"
	.string "I was beginning to think it would\n"
	.string "never arrive.\p"
	.string "Thank you for delivering this, but\n"
	.string "I hope it's faster next time...$"

PetalburgCity_PostOffice_Text_ThanksParcelDelivered:
	.string "Oh! My PARCEL!\p"
	.string "I didn't expect it to get here so\n"
	.string "soon!\p"
	.string "Thank you for delivering this!$"
