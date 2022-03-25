.set LOCALID_ETHAN, 4
.set LOCALID_LYRA, 5
.set LOCALID_KRIS, 6

SafariZone_RestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_RestHouse_MapScripts_OnTransition
	.byte 0

SafariZone_RestHouse_MapScripts_OnTransition::
	goto_if_unset FLAG_DAILY_JOHTO_VISITOR, SafariZone_RestHouse_MapScripts_JohtoVisitor
	end

SafariZone_RestHouse_MapScripts_JohtoVisitor::
	random 3
	goto_if_eq VAR_RESULT, 1, SafariZone_RestHouse_MapScripts_EthanVisiting
	goto_if_eq VAR_RESULT, 2, SafariZone_RestHouse_MapScripts_LyraVisiting
	goto_if_eq VAR_RESULT, 3, SafariZone_RestHouse_MapScripts_KrisVisiting
	end

SafariZone_RestHouse_MapScripts_EthanVisiting::
	setvar VAR_JOHTO_VISITOR, 1
	clearflag FLAG_HIDE_SAFARI_ZONE_ETHAN
	addobject LOCALID_ETHAN
	setflag FLAG_HIDE_SAFARI_ZONE_LYRA
	removeobject LOCALID_LYRA
	setflag FLAG_HIDE_SAFARI_ZONE_KRIS
	removeobject LOCALID_KRIS
	setflag FLAG_DAILY_JOHTO_VISITOR
	end

SafariZone_RestHouse_MapScripts_LyraVisiting::
	setvar VAR_JOHTO_VISITOR, 2
	clearflag FLAG_HIDE_SAFARI_ZONE_LYRA
	addobject LOCALID_LYRA
	setflag FLAG_HIDE_SAFARI_ZONE_ETHAN
	removeobject LOCALID_ETHAN
	setflag FLAG_HIDE_SAFARI_ZONE_KRIS
	removeobject LOCALID_KRIS
	setflag FLAG_DAILY_JOHTO_VISITOR
	end

SafariZone_RestHouse_MapScripts_KrisVisiting::
	setvar VAR_JOHTO_VISITOR, 3
	clearflag FLAG_HIDE_SAFARI_ZONE_KRIS
	addobject LOCALID_KRIS
	setflag FLAG_HIDE_SAFARI_ZONE_ETHAN
	removeobject LOCALID_ETHAN
	setflag FLAG_HIDE_SAFARI_ZONE_LYRA
	removeobject LOCALID_LYRA
	setflag FLAG_DAILY_JOHTO_VISITOR
	end


SafariZone_RestHouse_MapScripts_Ethan::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_DECLINED_JOHTO_EGG, SafariZone_RestHouse_MapScripts_EthanReattempt
	goto_if_set FLAG_DAILY_SAFARI_PRESENT, SafariZone_RestHouse_MapScripts_EthanCoolEgg
	msgbox SafariZone_RestHouse_Text_EthanVisitingHoenn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SafariZone_RestHouse_MapScripts_GiveTotodileEgg
	setflag FLAG_DAILY_DECLINED_JOHTO_EGG
	msgbox SafariZone_RestHouse_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_EthanVisitingHoenn:
	.string "ETHAN: I'm visitng HOENN to look\n"
	.string "for COOL POKéMON!\p"
	.string "I found this COOL EGG, but I\n"
	.string "don't have room to take it\l"
	.string "with me back to JOHTO.\p"
	.string "You look like a COOL TRAINER,\n"
	.string "do you want to take this egg?$"

SafariZone_RestHouse_MapScripts_EthanCoolEgg::
	msgbox SafariZone_RestHouse_Text_EthanCoolEgg, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_EthanCoolEgg:
	.string "ETHAN: Hey, {PLAYER}!\p"
	.string "Did that egg hatch into a\n"
	.string "COOL POKéMON?$"

SafariZone_RestHouse_MapScripts_EthanReattempt::
	msgbox SafariZone_RestHouse_Text_EthanReattempt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SafariZone_RestHouse_MapScripts_GiveTotodileEgg
	setflag FLAG_DAILY_DECLINED_JOHTO_EGG
	msgbox SafariZone_RestHouse_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_EthanReattempt:
	.string "ETHAN: Yo, {PLAYER}!\p"
	.string "Back for that egg?\p"

SafariZone_RestHouse_MapScripts_GiveTotodileEgg::
	clearflag FLAG_DAILY_DECLINED_JOHTO_EGG
	giveegg SPECIES_TOTODILE
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, SafariZone_RestHouse_MapScripts_CantGiveEgg
	playfanfare MUS_OBTAIN_ITEM
	message SafariZone_RestHouse_Text_ReceivedTheEgg
	waitfanfare
	setflag FLAG_DAILY_SAFARI_PRESENT
	goto SafariZone_RestHouse_MapScripts_EthanCoolEgg
	end

SafariZone_RestHouse_MapScripts_Lyra::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_DECLINED_JOHTO_EGG, SafariZone_RestHouse_MapScripts_LyraReattempt
	goto_if_set FLAG_DAILY_SAFARI_PRESENT, SafariZone_RestHouse_MapScripts_LyraCuteEgg
	msgbox SafariZone_RestHouse_Text_LyraVisitingHoenn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SafariZone_RestHouse_MapScripts_GiveChikoritaEgg
	setflag FLAG_DAILY_DECLINED_JOHTO_EGG
	msgbox SafariZone_RestHouse_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_LyraVisitingHoenn:
	.string "LYRA: I'm visitng HOENN to look\n"
	.string "for CUTE POKéMON!\p"
	.string "I found this CUTE EGG, but I\n"
	.string "don't have room to take it\l"
	.string "with me back to JOHTO.\p"
	.string "You look like a CUTE TRAINER,\n"
	.string "do you want to take this egg?$"

SafariZone_RestHouse_MapScripts_LyraCuteEgg::
	msgbox SafariZone_RestHouse_Text_LyraCuteEgg, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_LyraCuteEgg:
	.string "LYRA: Hey, {PLAYER}!\p"
	.string "Did that egg hatch into a\n"
	.string "CUTE POKéMON?$"

SafariZone_RestHouse_Text_LyraReattempt:
	.string "LYRA: Hi, {PLAYER}!\p"
	.string "Back for that egg?\p"

SafariZone_RestHouse_MapScripts_LyraReattempt::
	msgbox SafariZone_RestHouse_Text_LyraReattempt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SafariZone_RestHouse_MapScripts_GiveChikoritaEgg
	setflag FLAG_DAILY_DECLINED_JOHTO_EGG
	msgbox SafariZone_RestHouse_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_MapScripts_GiveChikoritaEgg::
	clearflag FLAG_DAILY_DECLINED_JOHTO_EGG
	giveegg SPECIES_CHIKORITA
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, SafariZone_RestHouse_MapScripts_CantGiveEgg
	playfanfare MUS_OBTAIN_ITEM
	message SafariZone_RestHouse_Text_ReceivedTheEgg
	waitfanfare
	setflag FLAG_DAILY_SAFARI_PRESENT
	goto SafariZone_RestHouse_MapScripts_LyraCuteEgg
	end


SafariZone_RestHouse_MapScripts_Kris::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_DECLINED_JOHTO_EGG, SafariZone_RestHouse_MapScripts_KrisReattempt
	goto_if_set FLAG_DAILY_SAFARI_PRESENT, SafariZone_RestHouse_MapScripts_KrisSeriousEgg
	msgbox SafariZone_RestHouse_Text_KrisVisitingHoenn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SafariZone_RestHouse_MapScripts_GiveCyndaquilEgg
	setflag FLAG_DAILY_DECLINED_JOHTO_EGG
	msgbox SafariZone_RestHouse_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_KrisVisitingHoenn:
	.string "KRIS: I'm visitng HOENN to look\n"
	.string "for SERIOUS POKéMON!\p"
	.string "I found this SERIOUS EGG, but I\n"
	.string "don't have room to take it\l"
	.string "with me back to JOHTO.\p"
	.string "You look like a SERIOUS TRAINER,\n"
	.string "do you want to take this egg?$"

SafariZone_RestHouse_MapScripts_KrisSeriousEgg::
	msgbox SafariZone_RestHouse_Text_KrisSeriousEgg, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_KrisSeriousEgg:
	.string "KRIS: Hey, {PLAYER}!\p"
	.string "Did that egg hatch into a\n"
	.string "SERIOUS POKéMON?$"

SafariZone_RestHouse_Text_KrisReattempt:
	.string "KRIS: Hey, {PLAYER}!\p"
	.string "Back for that egg?\p"


SafariZone_RestHouse_MapScripts_KrisReattempt::
	msgbox SafariZone_RestHouse_Text_KrisReattempt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SafariZone_RestHouse_MapScripts_GiveCyndaquilEgg
	setflag FLAG_DAILY_DECLINED_JOHTO_EGG
	msgbox SafariZone_RestHouse_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_MapScripts_GiveCyndaquilEgg::
	clearflag FLAG_DAILY_DECLINED_JOHTO_EGG
	giveegg SPECIES_CYNDAQUIL
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, SafariZone_RestHouse_MapScripts_CantGiveEgg
	playfanfare MUS_OBTAIN_ITEM
	message SafariZone_RestHouse_Text_ReceivedTheEgg
	waitfanfare
	setflag FLAG_DAILY_SAFARI_PRESENT
	goto SafariZone_RestHouse_MapScripts_KrisSeriousEgg
	end

SafariZone_RestHouse_Text_MaybeLater:
	.string "Oh, really? That's a shame.\p"
	.string "Well, I'll be here all day if\n"
	.string "if you change your mind.$"

SafariZone_RestHouse_MapScripts_CantGiveEgg::
	setflag FLAG_DAILY_DECLINED_JOHTO_EGG
	msgbox SafariZone_RestHouse_Text_CantGiveEgg, MSGBOX_DEFAULT
	release
	end

SafariZone_RestHouse_Text_CantGiveEgg:
	.string "You need to make some room\n"
	.string "before I can give you this egg!$"

SafariZone_RestHouse_Text_ReceivedTheEgg:
	.string "You received a POKéMON EGG!$"

SafariZone_RestHouse_EventScript_Youngster::
	msgbox SafariZone_RestHouse_Text_Youngster, MSGBOX_NPC
	end

SafariZone_RestHouse_EventScript_PsychicM::
	msgbox SafariZone_RestHouse_Text_PsychicM, MSGBOX_NPC
	end

SafariZone_RestHouse_EventScript_FatMan::
	msgbox SafariZone_RestHouse_Text_FatMan, MSGBOX_NPC
	end

