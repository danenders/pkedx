LilycoveCity_DepartmentStore_6F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_6F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_6F_Pokemart_CommonStones
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_6F_Pokemart_CommonStones:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_6F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_6F_Pokemart_RareStones
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_6F_Pokemart_RareStones:
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_6F_EventScript_Hiker::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStore_6F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_6F_Text_Hiker:
	.string "Back in my day, you had to search\n"
	.string "high and low for rare stones.\p"
	.string "You were lucky if you could even\n"
	.string "a single one!$"

LilycoveCity_DepartmentStore_6F_EventScript_Lass::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStore_6F_Text_Lass, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_6F_Text_Lass:
	.string "Please don't interrupt me!\p"
	.string "I'm trying to decide which stone\n"
	.string "I should buy for my EEVEE.$"

LilycoveCity_DepartmentStore_6F_EventScript_Youngster::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStore_6F_Text_Youngster, MSGBOX_YESNO
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStore_6F_EventScript_YoungsterYes
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_6F_EventScript_YoungsterNo
	release
	end

LilycoveCity_DepartmentStore_6F_Text_Youngster:
	.string "I'm buying a gift for my new\n"
	.string "girlfriend!\p"
	.string "Do you think she would want\n"
	.string "a rare stone?$"

LilycoveCity_DepartmentStore_6F_EventScript_YoungsterYes:
	msgbox LilycoveCity_DepartmentStore_6F_Text_YoungsterYes, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_DepartmentStore_6F_EventScript_YoungsterNo:
	msgbox LilycoveCity_DepartmentStore_6F_Text_YoungsterNo, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_DepartmentStore_6F_Text_YoungsterYes:
	.string "Yeah, stones are pretty cool!$"

LilycoveCity_DepartmentStore_6F_Text_YoungsterNo:
	.string "Oh no! Am I behind the times?$"
