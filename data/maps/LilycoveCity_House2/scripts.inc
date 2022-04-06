LilycoveCity_House2_MapScripts::
	.byte 0

LilycoveCity_House2_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_DELIVERY_TO_LILYCOVE, LilycoveCity_House2_EventScript_FatManParcel
	goto_if_set FLAG_RECEIVED_TM44, LilycoveCity_House2_EventScript_ReceivedRest
	msgbox LilycoveCity_House2_Text_NotAwakeYetHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM44
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM44
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_ReceivedRest::
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_Text_NotAwakeYetHaveThis:
	.string "Huh? What? What's that?\p"
	.string "I'm not near awake yet…\n"
	.string "You can have this…$"

LilycoveCity_House2_Text_SleepIsEssential:
	.string "Yawn…\p"
	.string "Sleep is essential for good health…\n"
	.string "Sleep and regain health…$"

LilycoveCity_House2_EventScript_FatManParcel::
	goto_if_unset FLAG_DAILY_DELIVERY_QUEST, LilycoveCity_House2_EventScript_FatManParcelLate
	msgbox PetalburgCity_PostOffice_Text_ThanksParcelDelivered, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_PostOffice_Text_HappyCustomer
	waitfanfare
	removeitem ITEM_PARCEL
	setflag FLAG_DELIVERY_COMPLETED
	clearflag FLAG_DELIVERY_TO_LILYCOVE
	release
	end

LilycoveCity_House2_EventScript_FatManParcelLate::
	msgbox PetalburgCity_PostOffice_Text_MyParcelIsLate, MSGBOX_DEFAULT
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	message PetalburgCity_PostOffice_Text_UnhappyCustomer
	waitmessage
	removeitem ITEM_PARCEL
	release
	end
