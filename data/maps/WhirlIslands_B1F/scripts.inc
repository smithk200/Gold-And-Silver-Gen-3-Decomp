WhirlIslands_B1F_MapScripts::
	.byte 0

WhirlIslands_B1F_EventScript_Item_Max_Revive::
	finditem ITEM_MAX_REVIVE
	end

WhirlIslands_B1F_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end

WhirlIslands_B1F_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end

WhirlIslands_B1F_Trigger_Sunlight::
	setweather WEATHER_SUNNY
	doweather
	end

WhirlIslands_B1F_Trigger_Rain::
	setweather WEATHER_RAIN
	doweather
	end

WhirlIslands_B1F_EventScript_Item_Big_Nugget::
	finditem ITEM_BIG_NUGGET
	end

WhirlIslands_B1F_EventScript_Item_Carbos::
	finditem ITEM_CARBOS
	end

WhirlIslands_B1F_EventScript_Item_Calcium::
	finditem ITEM_CALCIUM
	end

WhirlIslands_B1F_EventScript_Item_Escape_Rope::
	finditem ITEM_ESCAPE_ROPE
	end