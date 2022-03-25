.set LOCALID_CURATOR, 2
.set LOCALID_ARTIST_2, 8
.set LOCALID_OAK, 11

LilycoveCity_LilycoveMuseum_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_1F_OnLoad
	.byte 0

LilycoveCity_LilycoveMuseum_1F_OnLoad::
	goto_if_unset FLAG_DAILY_RED_BATTLE, LilycoveCity_LilycoveMuseum_1F_EventScript_HideOak
	goto_if_unset FLAG_DAILY_BLUE_BATTLE, LilycoveCity_LilycoveMuseum_1F_EventScript_HideOak
	goto_if_unset FLAG_DAILY_LEAF_BATTLE, LilycoveCity_LilycoveMuseum_1F_EventScript_HideOak
	call_if_unset FLAG_DAILY_KANTO_STARTER, LilycoveCity_LilycoveMuseum_1F_EventScript_SetKantoStarterGift
	clearflag FLAG_HIDE_OAK_MUSEUM
	addobject LOCALID_OAK
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_HideOak::
	setflag FLAG_HIDE_OAK_MUSEUM
	removeobject LOCALID_OAK
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SetKantoStarterGift::
	random 3
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_SetBulbasaur
	goto_if_eq VAR_RESULT, 2, LilycoveCity_LilycoveMuseum_1F_EventScript_SetCharmander
	goto_if_eq VAR_RESULT, 3, LilycoveCity_LilycoveMuseum_1F_EventScript_SetSquirtle
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SetBulbasaur::
	setvar VAR_KANTO_STARTER, 1
	setflag FLAG_DAILY_KANTO_STARTER
	return

LilycoveCity_LilycoveMuseum_1F_EventScript_SetCharmander::
	setvar VAR_KANTO_STARTER, 2
	setflag FLAG_DAILY_KANTO_STARTER
	return

LilycoveCity_LilycoveMuseum_1F_EventScript_SetSquirtle::
	setvar VAR_KANTO_STARTER, 3
	setflag FLAG_DAILY_KANTO_STARTER
	return


LilycoveCity_LilycoveMuseum_1F_EventScript_Oak::
	lock
	faceplayer
	playbgm MUS_RG_OAK, TRUE
	goto_if_set FLAG_DAILY_OAK_PRESENT, LilycoveCity_LilycoveMuseum_1F_EventScript_DailyOakCompleted
	goto_if_set FLAG_MET_PROFESSOR_OAK, LilycoveCity_LilycoveMuseum_1F_EventScript_OakGift
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OakIntroduction, MSGBOX_DEFAULT
	setflag FLAG_MET_PROFESSOR_OAK
	goto LilycoveCity_LilycoveMuseum_1F_EventScript_OakGift
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_DailyOakCompleted::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MysteriousCreatures, MSGBOX_DEFAULT
	release
	playbgm MUS_LILYCOVE_MUSEUM, TRUE
	end

LilycoveCity_LilycoveMuseum_1F_Text_MysteriousCreatures:
	.string "OAK: POKéMON are certainly\n"
	.string "mysterious creatures.\p"
	.string "Seeing TRAINERS like you raise\n"
	.string "POKéMON with care brings me hope\l"
	.string "that we can one day unravel those\l"
	.string "mysteries.$"

LilycoveCity_LilycoveMuseum_1F_Text_OakIntroduction:
	.string "????: This artifact is quite\n"
	.string "fascinating, is it not?\p"
	.string "There is still so much we do\n"
	.string "not know about the origins of\l"
	.string "POKéMON.\p"
	.string "Oh! Where are my manners!\p"
	.string "My name is OAK. I'm a POKéMON\n"
	.string "PROFESSOR.\p"
	.string "I heard from my GRANDSON that he\n"
	.string "and his friends me a promising\l"
	.string "young POKéMON TRAINER during their\l"
	.string "travels here...\p"
	.string "Yes...you must be the HOENN\n"
	.string "POKéMON LEAGUE CHAMPION I've\l"
	.string "heard so much about.$"

LilycoveCity_LilycoveMuseum_1F_EventScript_OakGift::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OakGift, MSGBOX_DEFAULT
	goto_if_eq VAR_KANTO_STARTER, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_GetBulbasaurEgg
	goto_if_eq VAR_KANTO_STARTER, 2, LilycoveCity_LilycoveMuseum_1F_EventScript_GetCharmanderEgg
	goto_if_eq VAR_KANTO_STARTER, 3, LilycoveCity_LilycoveMuseum_1F_EventScript_GetSquirtleEgg
	end

LilycoveCity_LilycoveMuseum_1F_Text_OakGift:
	.string "Have you been working on your\n"
	.string "POKéDEX?\p"
	.string "During my research, I've come\n"
	.string "across this POKéMON EGG.\p"
	.string "I'd like someone that understands\n"
	.string "the bonds between a POKéMON and a\l"
	.string "POKéMON TRAINER to care for it.$"

LilycoveCity_LilycoveMuseum_1F_EventScript_GetBulbasaurEgg::
	giveegg SPECIES_BULBASAUR
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, LilycoveCity_LilycoveMuseum_1F_EventScript_CantGive
	playfanfare MUS_OBTAIN_ITEM
	message LilycoveCity_LilycoveMuseum_1F_Text_Text_ReceivedTheEgg
	waitfanfare
	setflag FLAG_DAILY_OAK_PRESENT
	goto LilycoveCity_LilycoveMuseum_1F_EventScript_DailyOakCompleted
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GetCharmanderEgg::
	giveegg SPECIES_CHARMANDER
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, LilycoveCity_LilycoveMuseum_1F_EventScript_CantGive
	playfanfare MUS_OBTAIN_ITEM
	message LilycoveCity_LilycoveMuseum_1F_Text_Text_ReceivedTheEgg
	waitfanfare
	setflag FLAG_DAILY_OAK_PRESENT
	goto LilycoveCity_LilycoveMuseum_1F_EventScript_DailyOakCompleted
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GetSquirtleEgg::
	giveegg SPECIES_SQUIRTLE
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, LilycoveCity_LilycoveMuseum_1F_EventScript_CantGive
	playfanfare MUS_OBTAIN_ITEM
	message LilycoveCity_LilycoveMuseum_1F_Text_Text_ReceivedTheEgg
	waitfanfare
	setflag FLAG_DAILY_OAK_PRESENT
	goto LilycoveCity_LilycoveMuseum_1F_EventScript_DailyOakCompleted
	end

LilycoveCity_LilycoveMuseum_1F_Text_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

LilycoveCity_LilycoveMuseum_1F_EventScript_CantGive::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CantGive, MSGBOX_DEFAULT
	playbgm MUS_LILYCOVE_MUSEUM, TRUE
	release
	end

LilycoveCity_LilycoveMuseum_1F_Text_CantGive:
	.string "OAK: Hmm...you don't seem\n"
	.string "to take this egg right now.\p"
	.string "Why don't you try making some\n"
	.string "room for it first.$"


LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "Welcome to LILYCOVE MUSEUM.\p"
	.string "Please take the time to enjoy our\n"
	.string "collection of fantastic artwork\l"
	.string "featuring POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "I'm the CURATOR of this MUSEUM of\n"
	.string "fine arts.\p"
	.string "It's heartening to see someone so\n"
	.string "young as you in our MUSEUM.\p"
	.string "Have you viewed our collection of\n"
	.string "paintings already?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "Ah, then let me not disturb you.\n"
	.string "Please, do take your time.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "Oh? I do believe that you seem to\n"
	.string "be a POKéMON TRAINER.\p"
	.string "Have you an interest in paintings,\n"
	.string "too?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "I see…\p"
	.string "I'm honored that you would visit\n"
	.string "us in spite of that.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "Ah, excellent!\n"
	.string "You do like paintings!\p"
	.string "Then, may I ask you to come with me?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "It's a very old painting.\n"
	.string "The paint is peeling here and there.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "It's an odd landscape with bizarre\n"
	.string "and fantastic scenery.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "It's a painting of a beautiful, smiling\n"
	.string "woman with a POKéMON on her lap.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "It's a painting of a legendary POKéMON\n"
	.string "from long ago.\p"
	.string "The artist painted this from\n"
	.string "imagination.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "It's a painting of GRASS POKéMON\n"
	.string "swaying in a breeze.\p"
	.string "They appear to be enjoying the wind's\n"
	.string "gentle caress.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "It's a delicious-looking painting\n"
	.string "of BERRIES.\p"
	.string "This painting could make you hungry!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "It's a replica of a famous sculpture.\p"
	.string "It depicts an ancient BIRD POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "It's a big POKé BALL carved from\n"
	.string "a black stone.\p"
	.string "It was apparently used in festivals\n"
	.string "in the olden days.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "It's a huge stone tablet inscribed\n"
	.string "with POKéMON and dense text in the\l"
	.string "small characters of an ancient,\l"
	.string "unreadable language.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "Hmmm…\n"
	.string "What works of great magnificence…$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "Battling with POKéMON is fun,\n"
	.string "I'll grant you that.\p"
	.string "But one mustn't forget our love for\n"
	.string "the fine arts.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "This ART MUSEUM… Well, you could\n"
	.string "see many fantastic paintings.\p"
	.string "And the CURATOR is a wonderful person.\p"
	.string "Among artists like myself, this MUSEUM\n"
	.string "is an inspiration.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "This lady is pretty!\n"
	.string "She's like Mommy!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "This POKéMON is adorable!\n"
	.string "Just like our little boy!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "I'd heard that this ART MUSEUM got\n"
	.string "in some new paintings.\p"
	.string "So, naturally I hurried over.\p"
	.string "Are the new paintings up on\n"
	.string "the second floor?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "Lately, the CURATOR has been\n"
	.string "unusually cheerful.\p"
	.string "I bet something good happened for him.\n"
	.string "Definitely.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "I aim to see many great paintings\n"
	.string "here and learn from them.\p"
	.string "I have this dream of one day having\n"
	.string "my artwork exhibited here.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "The ART MUSEUM has become a favorite\n"
	.string "tourist destination.\p"
	.string "It's great for LILYCOVE…\n"
	.string "No, great for the HOENN region!\p"
	.string "This is what I've heard--a lone TRAINER\n"
	.string "procured all the paintings upstairs.$"
