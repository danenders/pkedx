LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	goto_if_set FLAG_DELIVERY_TO_LAVARIDGE, LavaridgeTown_House_EventScript_OldManParcel
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "My wife's warming an EGG in the hot\n"
	.string "springs. This is what she told me.\p"
	.string "She left two POKéMON with the DAY CARE.\n"
	.string "And they discovered that EGG!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: Pshoo!$"

LavaridgeTown_House_EventScript_OldManParcel::
	goto_if_unset FLAG_DAILY_DELIVERY_QUEST, LavaridgeTown_House_EventScript_OldManParcelLate
	msgbox PetalburgCity_PostOffice_Text_ThanksParcelDelivered, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_PostOffice_Text_HappyCustomer
	waitfanfare
	removeitem ITEM_PARCEL
	setflag FLAG_DELIVERY_COMPLETED
	clearflag FLAG_DELIVERY_TO_LAVARIDGE
	release
	end

LavaridgeTown_House_EventScript_OldManParcelLate::
	msgbox PetalburgCity_PostOffice_Text_MyParcelIsLate, MSGBOX_DEFAULT
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	message PetalburgCity_PostOffice_Text_UnhappyCustomer
	waitmessage
	removeitem ITEM_PARCEL
	release
	end
