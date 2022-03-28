.set LOCALID_MOVE_DELETER, 1

LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lock
	msgbox LilycoveCity_MoveDeletersHouse_Text_PassedOnSkills, MSGBOX_YESNO
	release
	end

LilycoveCity_MoveDeletersHouse_Text_PassedOnSkills:
	.string "Oh, hello!\p"
	.string "I used to be the MOVE DELETER.\n"
	.string "but I passed on my skills to my\l"
	.string "PUPILS at the POKeMON LEAGUE.\p"
	.string "I didn't want to forget the art\n"
	.string "of MOVE DELETING.\p"
	.string "So now a new generation will\n"
	.string "share my skills with TRAINERS.$"

