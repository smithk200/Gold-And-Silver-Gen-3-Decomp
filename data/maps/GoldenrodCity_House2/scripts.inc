GoldenrodCity_House2_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "Once while I was battling, my\n"
    .string "Pokémon couldn't make any moves.\p"
    .string "The POWER POINTS, or PP, of its\n"
    .string "moves were all gone.$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "Sometimes, a healthy Pokémon may be\n"
    .string "unable to use its moves.\p"
    .string "If that happens, heal it at a\n"
    .string "Pokémon CENTER or use an item.$"
