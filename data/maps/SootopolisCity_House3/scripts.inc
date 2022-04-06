SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	goto_if_set FLAG_DELIVERY_TO_SOOTOPOLIS, SootopolisCity_House3_EventScript_GirlParcel
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "You're a POKéMON TRAINER, aren't you?\p"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
	.string "Even more than his student WALLACE!\p"
	.string "Do you have any?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, then you must be pretty strong.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, dear…\n"
	.string "That's a little lonesome.\p"
	.string "Try working a little harder to get\n"
	.string "a fan following.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Dedicated fans come over from even\n"
	.string "outside of HOENN.\p"
	.string "It was really wild when I went to the\n"
	.string "TRAINER FAN CLUB in LILYCOVE.$"

SootopolisCity_House3_EventScript_GirlParcel::
	goto_if_unset FLAG_DAILY_DELIVERY_QUEST, SootopolisCity_House3_EventScript_GirlParcelLate
	msgbox PetalburgCity_PostOffice_Text_ThanksParcelDelivered, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_PostOffice_Text_HappyCustomer
	waitfanfare
	removeitem ITEM_PARCEL
	setflag FLAG_DELIVERY_COMPLETED
	clearflag FLAG_DELIVERY_TO_SOOTOPOLIS
	release
	end

SootopolisCity_House3_EventScript_GirlParcelLate::
	msgbox PetalburgCity_PostOffice_Text_MyParcelIsLate, MSGBOX_DEFAULT
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	message PetalburgCity_PostOffice_Text_UnhappyCustomer
	waitmessage
	removeitem ITEM_PARCEL
	release
	end
