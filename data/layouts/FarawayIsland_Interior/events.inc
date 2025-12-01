@
@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/FarawayIsland_Interior/map.json
@

	.align 2

FarawayIsland_Interior_ObjectEvents:
	object_event 1, OBJ_EVENT_GFX_MEW, 13, 17, 3, MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS, 15, 15, TRAINER_TYPE_NONE, 1, FarawayIsland_Interior_EventScript_Mew, FLAG_HIDE_MEW

FarawayIsland_Interior_MapWarps:
	warp_def 12, 19, 0, 0, MAP_FARAWAY_ISLAND_ENTRANCE
	warp_def 13, 19, 0, 1, MAP_FARAWAY_ISLAND_ENTRANCE

FarawayIsland_Interior_MapEvents::
	map_events FarawayIsland_Interior_ObjectEvents, FarawayIsland_Interior_MapWarps, NULL, NULL

