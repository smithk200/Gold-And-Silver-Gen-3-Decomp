@
@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/FarawayIsland_Entrance/map.json
@

	.align 2

FarawayIsland_Entrance_ObjectEvents:
	object_event 1, OBJ_EVENT_GFX_SAILOR, 13, 39, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, TRAINER_TYPE_NONE, 0, FarawayIsland_Entrance_EventScript_Sailor, 0
	object_event 2, OBJ_EVENT_GFX_SS_TIDAL, 13, 41, 1, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, TRAINER_TYPE_NONE, 0, 0x0, 0

FarawayIsland_Entrance_MapWarps:
	warp_def 22, 7, 3, 0, MAP_FARAWAY_ISLAND_INTERIOR
	warp_def 23, 7, 3, 1, MAP_FARAWAY_ISLAND_INTERIOR

FarawayIsland_Entrance_MapCoordEvents:
	coord_event 9, 18, 3, TRIGGER_RUN_IMMEDIATELY, 0, FarawayIsland_Entrance_EventScript_SetCloudsWeather
	coord_event 10, 20, 3, TRIGGER_RUN_IMMEDIATELY, 0, FarawayIsland_Entrance_EventScript_ClearWeather
	coord_event 22, 9, 3, TRIGGER_RUN_IMMEDIATELY, 0, FarawayIsland_Entrance_EventScript_SetCloudsWeather

FarawayIsland_Entrance_MapBGEvents:
	bg_sign_event 3, 32, 0, BG_EVENT_PLAYER_FACING_NORTH, FarawayIsland_Entrance_EventScript_Sign

FarawayIsland_Entrance_MapEvents::
	map_events FarawayIsland_Entrance_ObjectEvents, FarawayIsland_Entrance_MapWarps, FarawayIsland_Entrance_MapCoordEvents, FarawayIsland_Entrance_MapBGEvents

