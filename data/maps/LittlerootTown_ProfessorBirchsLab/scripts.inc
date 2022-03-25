.set LOCALID_BIRCH, 1
.set LOCALID_RIVAL, 2
.set LOCALID_LEAF, 3
.set LOCALID_BLUE, 4
.set LOCALID_AIDE, 5
.set LOCALID_BALL_TREECKO, 6
.set LOCALID_BALL_TORCHIC, 7
.set LOCALID_BALL_MUDKIP, 8


	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

	@ State descriptions for VAR_POSTGAME_BIRCH_GIFT
	@ 1: Beat Elite 4 for the first time
	@ 2: Birch presents starters
	@ 3: Chose a new Hoenn starter
	@ 4: Awaiting Scott's call
	@ 5: Re-enabled Starter gift (will loop back to 2)


LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0


LittlerootTown_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetPostgameLayout
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 1, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseHoennStarter
	.2byte 0

LittlerootTown_ProfessorBirchsLab_OnWarp:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetPostgamePositions
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPostgamePositions
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetPostgamePositions
	.2byte 0

@POSTGAME
LittlerootTown_ProfessorBirchsLab_EventScript_SetPostgameLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 8
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetPostgamePositions::
	addobject LOCALID_BALL_TREECKO
	turnobject LOCALID_BALL_TREECKO, DIR_SOUTH
	setobjectxy LOCALID_BALL_TREECKO, 8, 4
	addobject LOCALID_BALL_TORCHIC
	turnobject LOCALID_BALL_TORCHIC, DIR_SOUTH
	setobjectxy LOCALID_BALL_TORCHIC, 9, 4
	addobject LOCALID_BALL_MUDKIP
	turnobject LOCALID_BALL_MUDKIP, DIR_SOUTH
	setobjectxy LOCALID_BALL_MUDKIP, 10, 4
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	addobject LOCALID_RIVAL
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 8
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseHoennStarter::
	lockall
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 2
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
	.string "PROF. BIRCH: {PLAYER}{KUN}!\p"
	.string "You've come a long way since that\n"
	.string "day you saved me on ROUTE 101.\p"
	.string "You didn't have a POKéMON of your\n"
	.string "own, and now you are the CHAMPION!\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is another rare POKéMON that I\n"
	.string "found during my fieldwork!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"


LittlerootTown_ProfessorBirchsLab_EventScript_Treecko::
	release
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseGift
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TREECKO, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTreecko, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTreecko
	end

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTreecko:
	.string "PROF. BIRCH: The GRASS POKéMON\n"
	.string "TREECKO caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So TREECKO is your choice?$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTreecko::
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	setvar VAR_TEMP_1, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTreeckoToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTreeckoToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTreeckoToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TREECKO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTreecko
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTreecko
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTreeckoToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TREECKO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TreeckoTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TreeckoTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TreeckoTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTreecko
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTreecko::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 3
	setflag FLAG_DAILY_RECEIVED_BIRCH_STARTER
	releaseall
	end


LittlerootTown_ProfessorBirchsLab_EventScript_Torchic::
	release
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseGift
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TORCHIC, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTorchic, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTorchic
	end

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTorchic:
	.string "PROF. BIRCH: The FIRE POKéMON\n"
	.string "TORCHIC is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TORCHIC?$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTorchic::
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTorchicToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTorchicToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTorchicToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TORCHIC
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTorchic
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTorchic
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTorchicToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TORCHIC
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TorchicTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TorchicTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TorchicTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTorchic
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTorchic::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 3
	setflag FLAG_DAILY_RECEIVED_BIRCH_STARTER
	releaseall
	end


LittlerootTown_ProfessorBirchsLab_EventScript_Mudkip::
	release
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseGift
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_MUDKIP, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeMudkip, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveMudkip
	end

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeMudkip:
	.string "PROF. BIRCH: The WATER POKéMON\n"
	.string "MUDKIP is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the MUDKIP?$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveMudkip::
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendMudkipToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendMudkipToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendMudkipToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_MUDKIP
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedMudkip
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedMudkip
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendMudkipToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_MUDKIP
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_MudkipTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_MudkipTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MudkipTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedMudkip
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedMudkip::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 3
	setflag FLAG_DAILY_RECEIVED_BIRCH_STARTER
	releaseall
	end


LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
	.string "PROF. BIRCH: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable POKéMON.$"

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedPostgameGift::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPostgameGift
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPostgameGift:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
	.string "You've become the HOENN CHAMPION,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseGift::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
	.string "You received the promised POKéMON.\p"
	.string "You'll have to prove yourself to.\n"
	.string "PROF BIRCH. before you can receive.\l"
	.string "another gift!$"





@GET STARTER
LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "I've heard that you don't have your\n"
	.string "own POKéMON yet.\p"
	.string "But the way you battled earlier,\n"
	.string "you pulled it off with aplomb!\p"
	.string "I guess you have your father's blood\n"
	.string "in your veins after all!\p"
	.string "Oh, yes. As thanks for rescuing me,\n"
	.string "I'd like you to have the POKéMON you\l"
	.string "used earlier.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
	.string "PROF. BIRCH: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
	.string "PROF. BIRCH: If you work at POKéMON\n"
	.string "and gain experience, I think you'll make\l"
	.string "an extremely good TRAINER.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "POKéMON while helping me out.\p"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
	.string "PROF. BIRCH: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a TRAINER.$"

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
	.string "PROF. BIRCH: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"


@BLUE now interrupts the POKEDEX event and delivers a National Pokedex to Birch
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	playse SE_DOOR
	playbgm MUS_RG_ENCOUNTER_RIVAL, TRUE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoBirch, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_RIVAL, DIR_SOUTH
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	clearflag FLAG_HIDE_BLUE_INSIDE_LAB
	addobject LOCALID_BLUE
	applymovement LOCALID_BLUE, Movement_Blue_Barges_In
	waitmovement 4
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Player_Steps_Aside
	waitmovement 0
	applymovement LOCALID_BLUE, Movement_Blue_Steps_Up
	waitmovement 4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Beat, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_BLUE, DIR_WEST
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Beat2, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_BLUE, DIR_NORTH
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Beat3, MSGBOX_DEFAULT
	waitmessage
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AmIInterrupting, MSGBOX_DEFAULT
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ThisIsAPokedex, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE, Movement_Blue_FacesPlayer
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AnotherTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE, Movement_Blue_Goodbye
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Goodbye, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE, Movement_Blue_Exit
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SmellYaLater, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_BLUE_INSIDE_LAB
	removeobject LOCALID_BLUE
	playbgm MUS_BIRCH_LAB, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveBackToBirch
	turnobject LOCALID_RIVAL, DIR_WEST
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhereWereWe, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	waitmessage
	applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
	.string "I heard you beat {RIVAL} on\n"
	.string "your first try. That's excellent!\p"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "{RIVAL} has an extensive history as\n"
	.string "a TRAINER already.$"

LittlerootTown_ProfessorBirchsLab_Text_YoBirch:
	.string "????: Yo! PROF. BIRCH!$"

Movement_Blue_Barges_In:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_Player_Steps_Aside:
	walk_left
	face_right
	step_end

Movement_Blue_Steps_Up:
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_Text_Beat:
	.string "...$"

LittlerootTown_ProfessorBirchsLab_Text_Beat2:
	.string ".........$"

LittlerootTown_ProfessorBirchsLab_Text_Beat3:
	.string "...............$"

LittlerootTown_ProfessorBirchsLab_Text_AmIInterrupting:
	.string "????: Oh, am I interrupting?\p"
	.string "Sorry about that!\p"
	.string "When GRAMPS heard I was headed to\n"
	.string "HOENN, he asked me to stop by and\l"
	.string "drop these off.\p"
	.string "GRAMPS, I mean, PROFESSOR OAK says\n"
	.string "hello, by the way.$"

LittlerootTown_ProfessorBirchsLab_Text_ThisIsAPokedex:
	.string "PROF. BIRCH: Oh!\p"
	.string "This is a national model POKéDEX!\p"
	.string "This will certainly be useful for\n"
	.string "{PLAYER} and {RIVAL}.$"

Movement_Blue_FacesPlayer:
	face_left
	step_end

LittlerootTown_ProfessorBirchsLab_Text_AnotherTrainer:
	.string "????: Oh, so you're also a POKéMON\n"
	.string "TRAINER?\p"
	.string "My name is BLUE. I just took my\n"
	.string "shot at the POKéMON LEAGUE back\l"
	.string "in KANTO.\p"
	.string "That's right, you're face to face\n"
	.string "with a former CHAMPION.\p"
	.string "I heard a rumor someone in HOENN\n"
	.string "was searching for strong TRAINERS.\p"
	.string "So, I came to see what that's\n"
	.string "all about.\p"
	.string "Maybe I'll see you around, {PLAYER}!$"

Movement_Blue_Goodbye:
	face_up
	step_end

LittlerootTown_ProfessorBirchsLab_Text_Goodbye:
	.string "BLUE: Anyway, sorry for crashing\n"
	.string "the party, PROF.\p"
	.string "I should let you get back to it.$"

Movement_Blue_Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_ProfessorBirchsLab_Text_SmellYaLater:
	.string "BLUE: Smell ya later!$"

Movement_MoveBackToBirch:
	walk_right
	face_up
	step_end

LittlerootTown_ProfessorBirchsLab_Text_WhereWereWe:
	.string "{RIVAL}: Who was that, DAD?\p"
	.string "PROF. BIRCH: He's my colleague's\n"
	.string "grandson - he's been that way \l"
	.string "since he was young...\p"
	.string "He's a very skilled trainer, but\n"
	.string "clearly has a lot to learn about\l"
	.string "what it takes to be a CHAMPION.\p"
	.string "...\p"
	.string "Anyway, where were we?\p"
	.string "Ah! That's right, the POKéDEX!\p"
	.string "The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any POKéMON you meet or catch.\p"
	.string "{RIVAL} already goes everywhere\n"
	.string "with her standard model.\p"
	.string "But, as you've probably noticed,\n"
	.string "{RIVAL}, more unknown species have\l"
	.string "begun to appear in HOENN.\p"
	.string "Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I want the\n"
	.string "two of you to help me study these new\l"
	.string "POKéMON that have been seen in HOENN.\p"
	.string "With your help, perhaps we can learn\n"
	.string "even more about POKéMON!$"


LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
	.string "{PLAYER} received the NATIONAL\n"
	.string "POKéDEX from PROF. BIRCH!$"

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
	.string "You got a POKéDEX, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
	.string "Oh? Your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
	.string "MAY: It's fun if you can get a lot of\n"
	.string "POKéMON!\p"
	.string "I'm going to look all over the place\n"
	.string "because I want different POKéMON.\p"
	.string "If I find any cute POKéMON, I'll catch\n"
	.string "them with POKé BALLS!$"

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
	.string "BRENDAN: Huh…\n"
	.string "So you got a POKéDEX, too.\p"
	.string "Well then, here.\n"
	.string "I'll give you these.$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
	.string "BRENDAN: You know it's more fun to\n"
	.string "have a whole bunch of POKéMON.\p"
	.string "I'm going to explore all over the place\n"
	.string "to find different POKéMON.\p"
	.string "If I find any cool POKéMON, you bet\n"
	.string "I'll try to get them with POKé BALLS.$"

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
	.string "Hey, your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

@BIRCH
LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	call_if_eq VAR_POSTGAME_BIRCH_GIFT, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnotherPokemon
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 2, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnotherPokemon::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnotherPokemon, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 2
	return

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnotherPokemon:
	.string "PROF. BIRCH: Hello, {PLAYER}!\p"
	.string "I see you've been working very\n"
	.string "hard to improve your abilities as\l"
	.string "a POKéMON TRAINER!\p"
	.string "This calls for a reward!\p"
	.string "I've brought back more POKéMON\n"
	.string "from my fieldwork.$"


LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
	.string "PROF. BIRCH: These POKéMON are not\n"
	.string "seen very often, but I seem to have\l"
	.string "a knack for finding them!\p"
	.string "Go ahead and choose one.$"

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
	.string "PROF. BIRCH: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your POKéMON get tired,\n"
	.string "you should get some rest at home.$"

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
	.string "PROF. BIRCH: Countless POKéMON\n"
	.string "await you!\p"
	.string "Argh, I'm getting the itch to get out\n"
	.string "and do fieldwork again!$"

LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
	lock
	faceplayer
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 4, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
	.string "MAY: I wonder where I should go look\n"
	.string "for POKéMON next?$"

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
	.string "BRENDAN: Where should I look for\n"
	.string "POKéMON next…$"

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
	.string "MAY: {PLAYER}{KUN}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the NATIONAL POKéDEX?\p"
	.string "I'm staying here to help the PROF.$"

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
	.string "BRENDAN: Rather than collecting\n"
	.string "POKéMON, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
	.string "Have you gone to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
	.string "BRENDAN: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
	.string "MAY: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the PROF here for\n"
	.string "a while.$"

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
	.string "BRENDAN: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the PROF here\n"
	.string "for a while.$"


@Other Lab Events

LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
	.string "It's a serious-looking machine.\n"
	.string "The PROF must use this for research.$"

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
	.string "It's crammed with books on POKéMON.$"

LittlerootTown_ProfessorBirchsLab_EventScript_Book::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
	.string "It's a book that's too hard to read.$"

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
	.string "Hunh? PROF. BIRCH?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
	.string "PROF. BIRCH is studying the habitats\n"
	.string "and distribution of POKéMON.\p"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"

LittlerootTown_ProfessorBirchsLab_EventScript_Leaf::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_LEAF_BATTLE, LittlerootTown_ProfessorBirchsLab_EventScript_LeafFiredUp
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Leaf, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_LeafRematch
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LeafDecline, MSGBOX_DEFAULT
	turnobject LOCALID_LEAF, DIR_WEST
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_Leaf:
	.string "LEAF: PROF. BIRCH is letting me use\n"
	.string "some of his equipment to do research\l"
	.string "on rare POKéMON.\p"
	.string "Say, want to have a POKéMON battle?$"

LittlerootTown_ProfessorBirchsLab_Text_LeafDecline:
	.string "That's alright. I should focus on my\n"
	.string "research. I just get so fired up when\l"
	.string "think about finding rare POKéMON!$"

LittlerootTown_ProfessorBirchsLab_EventScript_LeafRematch::
	cleartrainerflag TRAINER_LEAF
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_LEAF, LOCALID_LEAF, LittlerootTown_ProfessorBirchsLab_Text_LeafRematchBattleIntro, LittlerootTown_ProfessorBirchsLab_Text_LeafRematchBattleDefeat, LittlerootTown_ProfessorBirchsLab_EventScript_LeafRematchCompleted
	end


LittlerootTown_ProfessorBirchsLab_Text_LeafRematchBattleIntro:
	.string "LEAF: I won't hold back this time!$"


LittlerootTown_ProfessorBirchsLab_Text_LeafRematchBattleDefeat:
	.string "LEAF: I need to get stronger!$"


LittlerootTown_ProfessorBirchsLab_EventScript_LeafRematchCompleted::
	setflag FLAG_DAILY_LEAF_BATTLE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LeafFiredUp, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_LeafFiredUp::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LeafFiredUp, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_Text_LeafFiredUp:
	.string "LEAF: Alright! I'm all fired up!\p"
	.string "I'm going to keep researching\n"
	.string "how to find even more powerful\l"
	.string "POKéMON!$"
