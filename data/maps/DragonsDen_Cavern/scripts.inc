.set LOCALID_DRAGONSDEN2_CLAIR, 5
.set LOCALID_DEN_CLAIR, 35

DragonsDen_Cavern_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}… So you're here.\p"
	.string "If you think you can keep up,\n"
	.string "with me, come to the FIGHTING\l"
	.string "DOJO in SAFFRON.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock 
	playse SE_PIN
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	call DragonsDen_Cavern_EventScript_Clair
	applymovement LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	release
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_ClairGiveDragonclaw, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_CLAW
	msgbox DragonsDen_Cavern_Text_ClairDescribeDragonclaw, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_ClairGiveDragonclaw:
    .string "CLAIR: WAIT!\p"
	.string "I'm sorry about this.\n"
    .string "Here, take this as my apology.$"

DragonsDen_Cavern_Text_ClairDescribeDragonclaw:
    .string "That contains DRAGON CLAW.\p"
    .string "No, it doesn't have anything to\n"
    .string "do with my nails.\p"
    .string "If you don't want it, you don't\n"
    .string "have to take it.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "What's the matter? Aren't\n"
    .string "you going on to the Pokémon\l"
    .string "LEAGUE?\p"
    .string "After you become CHAMPION, you\n"
    .string "can rematch any GYM LEADER you\l"
    .string "want.\p"
    .string "Go to the Pokémon LEAGUE.\p"
    .string "Do you know how to get there?\p"
    .string "From here, go to NEW BARK TOWN.\p"
    .string "Then SURF east to Pokémon LEAGUE.\p"
    .string "The route there is very tough.\p"
    .string "Don't you dare lose at the Pokémon\n"
    .string "LEAGUE!\p"
    .string "If you do, I'll feel even worse\n"
    .string "about having lost to you!\p"
    .string "Give it everything you've got.$"

DragonsDen_Cavern_Trigger_MultiBattle_Left::
	setvar VAR_TEMP_1, 0
	goto DragonsDen_Cavern_EventScript_MultiBattle

DragonsDen_Cavern_Trigger_MultiBattle_Mid::
	setvar VAR_TEMP_1, 1
	goto DragonsDen_Cavern_EventScript_MultiBattle

DragonsDen_Cavern_Trigger_MultiBattle_Right::
	setvar VAR_TEMP_1, 2
	goto DragonsDen_Cavern_EventScript_MultiBattle

DragonsDen_Cavern_EventScript_MultiBattle::
	playse SE_PIN
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	call_if_eq VAR_TEMP_1, 0, DragonsDen_Cavern_EventScript_PlayerWalksToSilverL
	call_if_eq VAR_TEMP_1, 1, DragonsDen_Cavern_EventScript_PlayerWalksToSilverM
	call_if_eq VAR_TEMP_1, 2, DragonsDen_Cavern_EventScript_PlayerWalksToSilverR
	msgbox DragonsDen_Cavern_Text_SilverBefore, MSGBOX_AUTOCLOSE
	fadeoutbgm 0
	playbgm MUS_HG_DRAGONS_DEN, FALSE
	playse SE_PIN
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_LANCE
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR_MULTI
	addobject LOCALID_LANCE_DRAGONS_DEN_MULTI
	addobject LOCALID_CLAIR_DRAGONS_DEN_MULTI
	applymovement LOCALID_LANCE_DRAGONS_DEN_MULTI, DragonsDen_Cavern_Movement_LanceWalksToSilver
	applymovement LOCALID_CLAIR_DRAGONS_DEN_MULTI, DragonsDen_Cavern_Movement_ClairWalksToSilver
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_PlayerMovesForMultiBattle
	waitmovement 0
	delay 20
	msgbox DragonsDen_Cavern_Text_LancePreBattle1, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_Silver_WhereHaveYouBeenAllThisTime, MSGBOX_AUTOCLOSE
	msgbox DragonsDen_Cavern_Text_LanceCalmDown, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_Silver_YouCantBeatMeOneOnOne, MSGBOX_AUTOCLOSE
	msgbox DragonsDen_Cavern_Text_LanceADoubleBattleIsReallyNotBad, MSGBOX_AUTOCLOSE
	applymovement LOCALID_CLAIR_DRAGONS_DEN_MULTI, Common_Movement_WalkDown
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_ClairYouThereWantToBattle, MSGBOX_AUTOCLOSE
	msgbox DragonsDen_Cavern_Text_SilverYouMustBeKidding, MSGBOX_DEFAULT
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, DragonsDen_Cavern_Movement_SilverPushesClair
	applymovement LOCALID_CLAIR_DRAGONS_DEN_MULTI, DragonsDen_Cavern_Movement_ClairBacksUpFromSilver
	waitmovement 0
	delay 20
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, DragonsDen_Cavern_Movement_SilverTurnsToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_SilverNoWayICanBattleWithHer, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_CLAIR_DRAGONS_DEN_MULTI, Common_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_STARTER_MON, 0, DragonsDen_Cavern_MultiBattle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, DragonsDen_Cavern_MultiBattle_Totodile
	call_if_eq VAR_STARTER_MON, 2, DragonsDen_Cavern_MultiBattle_Chikorita
	release
	end

DragonsDen_Cavern_MultiBattle_Cyndaquil::
	multi_fixed_2_vs_2 TRAINER_LANCE_DRAGONS_DEN_SILVER, DragonsDen_Cavern_MultiBattleLanceLoss, TRAINER_CLAIR_DRAGONS_DEN_SILVER, DragonsDen_Cavern_MultiBattleClairLoss, PARTNER_SILVER_CYNDAQUIL
	goto DragonsDen_Cavern_MultiBattle_PostBattle

DragonsDen_Cavern_MultiBattle_Totodile::
	multi_fixed_2_vs_2 TRAINER_LANCE_DRAGONS_DEN_SILVER, DragonsDen_Cavern_MultiBattleLanceLoss, TRAINER_CLAIR_DRAGONS_DEN_SILVER, DragonsDen_Cavern_MultiBattleClairLoss, PARTNER_SILVER_TOTODILE
	goto DragonsDen_Cavern_MultiBattle_PostBattle

DragonsDen_Cavern_MultiBattle_Chikorita::
	multi_fixed_2_vs_2 TRAINER_LANCE_DRAGONS_DEN_SILVER, DragonsDen_Cavern_MultiBattleLanceLoss, TRAINER_CLAIR_DRAGONS_DEN_SILVER, DragonsDen_Cavern_MultiBattleClairLoss, PARTNER_SILVER_CHIKORITA
	goto DragonsDen_Cavern_MultiBattle_PostBattle

DragonsDen_Cavern_MultiBattle_PostBattle::
	msgbox DragonsDen_Cavern_Text_LanceJustAsIExpected, MSGBOX_AUTOCLOSE
	applymovement LOCALID_LANCE_DRAGONS_DEN_MULTI, DragonsDen_Cavern_Movement_Multi_LanceLeaves
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_LANCE
	removeobject LOCALID_LANCE_DRAGONS_DEN_MULTI
	msgbox DragonsDen_Cavern_Text_ClairIMustExcuseMyself, MSGBOX_AUTOCLOSE
	applymovement LOCALID_CLAIR_DRAGONS_DEN_MULTI, DragonsDen_Cavern_Movement_Multi_ClairLeaves
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR_MULTI
	removeobject LOCALID_CLAIR_DRAGONS_DEN_MULTI
	applymovement LOCALID_SILVER_DRAGONS_DEN_MULTI, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_SilverItWasntSupposedToGoThisWay, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILVER_DRAGONS_DEN_MULTI
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_SILVER
	fadescreen FADE_FROM_BLACK
	setvar VAR_SILVER_POSTGAME_STATE, 2
	release
	end

DragonsDen_Cavern_EventScript_PlayerWalksToSilverL::
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_PlayerWalksToSilverL
	waitmovement 0
	return

DragonsDen_Cavern_EventScript_PlayerWalksToSilverM::
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_PlayerWalksToSilverM
	waitmovement 0
	return

DragonsDen_Cavern_EventScript_PlayerWalksToSilverR::
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_PlayerWalksToSilverR
	waitmovement 0
	return

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "DRAGON SHRINE\p"
    .string "A shrine honoring the dragon\n"
    .string "Pokémon\p"
    .string "said to have lived in DRAGON'S\n"
    .string "DEN.$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "…\n"
    .string "What? {PLAYER}?\p"
    .string "…No, I won't battle you now…\p"
    .string "My Pokémon aren't ready to beat\n"
    .string "you.\p"
    .string "I can't push them too hard now.\p"
    .string "I have to be disciplined to become\n"
    .string "the greatest Pokémon trainer…$"

DragonsDen_Cavern_Text_SilverTraining2:
    .string "…\p"
    .string "Whew…\p"
    .string "Learn to stay out of my way…$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "You! How dare you enter\n"
    .string "uninvited!$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "S-strong!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "The SHRINE ahead is home to the\n"
    .string "MASTER of our dragon-user clan.\p"
    .string "You're not allowed to just go in!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "You shouldn't be in here!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "Oh yikes, I lost!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "Soon I'm going to get permission\n"
    .string "from our MASTER to use dragons.\p"
    .string "When I do, I'm going to become an\n"
    .string "admirable dragon trainer and gain\l"
    .string "our MASTER's approval.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "It's a stranger we don't know.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "Ouchies.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "It was like having to battle\n"
    .string "LANCE.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "Who are you?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "Meanie.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "We'll tell on you.\p"
    .string "MASTER will be angry with you.$"

DragonsDen_Cavern_Text_SilverBefore:
	.string "Silver: …What?\n"
	.string "Are you here to make fun of\l"
	.string "my training?\p"
	.string "Humph!\n"
	.string "I took my time coming all the way here,\l"
	.string "but the Master won't tell me anything,\l"
	.string "and he's making a big deal out of it…\p"
	.string "So I decided to train my Pokémon\n"
	.string "here instead.$"

DragonsDen_Cavern_Text_LancePreBattle1:
	.string "Lance: Hi, {PLAYER}!\n"
	.string "And… you.\l"
	.string "We met at the Team Rocket hideout.$"

DragonsDen_Cavern_Text_Silver_WhereHaveYouBeenAllThisTime:
	.string "{RIVAL}: You!\n"
	.string "Where have you been all this time?\p"
	.string "Prepare to lose to me this time.\n"
	.string "I challenge you!$"

DragonsDen_Cavern_Text_LanceCalmDown:
	.string "Lance: Calm down.\n"
	.string "I was in a bit of a hurry then.\p"
	.string "Sorry for that.\n"
	.string "But… I always welcome challengers!\p"
	.string "Hey!\n"
	.string "How about a Double Battle?$"

DragonsDen_Cavern_Text_Silver_YouCantBeatMeOneOnOne:
	.string "Humph!\n"
	.string "You can't beat me one-on-one, can you?$"

DragonsDen_Cavern_Text_LanceADoubleBattleIsReallyNotBad:
	.string "Lance: Come on.\n"
	.string "A Double Battle is really not bad.\p"
	.string "{PLAYER}, you'll be on my side!$"

DragonsDen_Cavern_Text_ClairYouThereWantToBattle:
	.string "Clair: Well then, you over there!\n"
	.string "Will you team up with me?$"

DragonsDen_Cavern_Text_SilverYouMustBeKidding:
	.string "{RIVAL}: You must be kidding!\p"
	.string "That embarrassing one in the weird\n"
	.string "costume for me?$"

DragonsDen_Cavern_Text_SilverNoWayICanBattleWithHer:
	.string "No way I can battle with her!\p"
	.string "{PLAYER}! Come to my side!\n"
	.string "We'll beat Lance together!$"

DragonsDen_Cavern_MultiBattleClairLoss:
	.string "Oh, I see…$"

DragonsDen_Cavern_MultiBattleLanceLoss:
	.string "Did you see that, Clair?$"

DragonsDen_Cavern_Text_LanceJustAsIExpected:
	.string "Lance: Just as I expected.\n"
	.string "You two make quite a team…\p"
	.string "Going solo is certainly one way to aim\n"
	.string "for the top…\p"
	.string "But that's not all there is to Pokémon\n"
	.string "battle. Although I don't feel it's\l"
	.string "necessary to remind you guys.\p"
	.string "See you, {PLAYER},\n"
	.string "another time!$"

DragonsDen_Cavern_Text_ClairIMustExcuseMyself:
	.string "Clair: I must excuse myself.\p"
	.string "…{PLAYER}, it was a fun battle.\p"
	.string "That goes for you, too, wise guy.$"

DragonsDen_Cavern_Text_SilverItWasntSupposedToGoThisWay:
	.string "{RIVAL}: {PLAYER}…\p"
	.string "It wasn't supposed to go this way…\n"
	.string "Anyway, I am not giving up beating you!\p"
	.string "I'll train my Pokémon and… my own\n"
	.string "heart, too.\p"
	.string "I'll come back as the toughest\n"
	.string "challenge for you!$"

DragonsDen_Cavern_Movement_PlayerWalksToSilverL:
	walk_down
	step_end

DragonsDen_Cavern_Movement_PlayerWalksToSilverM:
	walk_left
	walk_down
	step_end

DragonsDen_Cavern_Movement_PlayerWalksToSilverR:
	walk_left
	walk_left
	walk_down
	step_end

DragonsDen_Cavern_Movement_LanceWalksToSilver:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

DragonsDen_Cavern_Movement_ClairWalksToSilver:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

DragonsDen_Cavern_Movement_PlayerMovesForMultiBattle:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_down
	face_up
	step_end

DragonsDen_Cavern_Movement_SilverPushesClair:
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairBacksUpFromSilver:
	walk_faster_up
	walk_faster_up
	face_down
	step_end

DragonsDen_Cavern_Movement_SilverTurnsToPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

DragonsDen_Cavern_Movement_Multi_LanceLeaves:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_Multi_ClairLeaves:
	slide_up
	slide_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end