#include "global.h"
#include "event_data.h"
#include "item.h"
#include "tx_randomizer_and_challenges.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "constants/items.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"

// Generic functions
bool8 AreFeaturesActivated(void)
{
    if (gSaveBlock1Ptr->tx_Features_ShinyChance
        || gSaveBlock1Ptr->tx_Features_WildMonDropItems
        || gSaveBlock1Ptr->tx_Mode_AlternateSpawns
        || gSaveBlock1Ptr->tx_Mode_InfiniteTMs
        || gSaveBlock1Ptr->tx_Mode_PoisonSurvive
        || gSaveBlock1Ptr->tx_Features_EasierFeebas)
        return TRUE;

    return FALSE;
}

bool8 IsRandomizerActivated(void)
{
    if (gSaveBlock1Ptr->tx_Random_Chaos
        || gSaveBlock1Ptr->tx_Random_WildPokemon
        || gSaveBlock1Ptr->tx_Random_Similar
        || gSaveBlock1Ptr->tx_Random_MapBased
        || gSaveBlock1Ptr->tx_Random_IncludeLegendaries
        || gSaveBlock1Ptr->tx_Random_Type
        || gSaveBlock1Ptr->tx_Random_TypeEffectiveness
        || gSaveBlock1Ptr->tx_Random_Abilities
        || gSaveBlock1Ptr->tx_Random_Moves
        || gSaveBlock1Ptr->tx_Random_Trainer
        || gSaveBlock1Ptr->tx_Random_Evolutions
        || gSaveBlock1Ptr->tx_Random_EvolutionMethods
        || gSaveBlock1Ptr->tx_Random_OneForOne
        || gSaveBlock1Ptr->tx_Random_Items)
        return TRUE;

    return FALSE;
}

bool8 IsRandomItemsActivated(void)
{
    return gSaveBlock1Ptr->tx_Random_Items;
}

bool8 IsDifficultyOptionsActivated(void)
{
    if (gSaveBlock1Ptr->tx_Challenges_PartyLimit
        || gSaveBlock1Ptr->tx_Challenges_LevelCap
        || gSaveBlock1Ptr->tx_Challenges_ExpMultiplier
        || gSaveBlock1Ptr->tx_Challenges_NoItemPlayer
        || gSaveBlock1Ptr->tx_Challenges_NoItemTrainer
        || gSaveBlock1Ptr->tx_Challenges_PkmnCenter)
        return TRUE;

    return FALSE;
}

bool8 IsOneTypeChallengeActive(void)
{
    return (gSaveBlock1Ptr->tx_Challenges_OneTypeChallenge != TX_CHALLENGE_TYPE_OFF);
}

bool8 AreAnyChallengesActive(void)
{
    if (gSaveBlock1Ptr->tx_Challenges_EvoLimit
        || gSaveBlock1Ptr->tx_Challenges_BaseStatEqualizer
        || gSaveBlock1Ptr->tx_Challenges_Mirror
        || gSaveBlock1Ptr->tx_Challenges_Mirror_Thief
        || gSaveBlock1Ptr->tx_Challenges_MaxPartyIVs
        || gSaveBlock1Ptr->tx_Features_LimitDifficulty
        || IsOneTypeChallengeActive())
        return TRUE;

    return FALSE;
}


bool8 IsNuzlockeNicknamingActive(void)
{
    if (!gSaveBlock1Ptr->tx_Challenges_Nuzlocke)
        return FALSE;
    if (FlagGet(FLAG_IS_CHAMPION))
        return FALSE;

    if (gSaveBlock1Ptr->tx_Nuzlocke_Nicknaming == 0)
        return TRUE;
    return FALSE;
}

bool8 IsPokecenterChallengeActivated(void)
{
    return gSaveBlock1Ptr->tx_Challenges_PkmnCenter;
}

bool8 HMsOverwriteOptionActive(void)
{
    return (gSaveBlock1Ptr->tx_Challenges_Nuzlocke 
            || gSaveBlock1Ptr->tx_Challenges_Mirror 
            || gSaveBlock1Ptr->tx_Random_Moves
            || IsOneTypeChallengeActive());
}

enum LevelCap {
    LEVEL_CAP_NO_BADGES,
    LEVEL_CAP_BADGE_1,
    LEVEL_CAP_BADGE_2,
    LEVEL_CAP_BADGE_3,
    LEVEL_CAP_BADGE_4,
    LEVEL_CAP_BADGE_5,
    LEVEL_CAP_BADGE_6,
    LEVEL_CAP_BADGE_7,
    LEVEL_CAP_BADGE_8
};
static const u8 sLevelCapTable_Normal[] = //HNS UPDATED
{
    [LEVEL_CAP_NO_BADGES]   = 11, 
    [LEVEL_CAP_BADGE_1]     = 16, 
    [LEVEL_CAP_BADGE_2]     = 21,
    [LEVEL_CAP_BADGE_3]     = 25,
    [LEVEL_CAP_BADGE_4]     = 31,
    [LEVEL_CAP_BADGE_5]     = 36,
    [LEVEL_CAP_BADGE_6]     = 38,
    [LEVEL_CAP_BADGE_7]     = 45,
    [LEVEL_CAP_BADGE_8]     = 56,
};
static const u8 sLevelCapTable_Hard[] = //HNS UPDATED
{
    [LEVEL_CAP_NO_BADGES]   = 8,
    [LEVEL_CAP_BADGE_1]     = 15,
    [LEVEL_CAP_BADGE_2]     = 20,
    [LEVEL_CAP_BADGE_3]     = 23,
    [LEVEL_CAP_BADGE_4]     = 29,
    [LEVEL_CAP_BADGE_5]     = 33,
    [LEVEL_CAP_BADGE_6]     = 37,
    [LEVEL_CAP_BADGE_7]     = 42,
    [LEVEL_CAP_BADGE_8]     = 54,
};
// Scaling IVs and EVs
static const u8 sIV_Table[] = 
{
    [LEVEL_CAP_NO_BADGES]   = 7,
    [LEVEL_CAP_BADGE_1]     = 10,
    [LEVEL_CAP_BADGE_2]     = 13,
    [LEVEL_CAP_BADGE_3]     = 16,
    [LEVEL_CAP_BADGE_4]     = 19,
    [LEVEL_CAP_BADGE_5]     = 22,
    [LEVEL_CAP_BADGE_6]     = 25,
    [LEVEL_CAP_BADGE_7]     = 28,
    [LEVEL_CAP_BADGE_8]     = 31,
};
static const u8 sEV_Table[] = 
{
    [LEVEL_CAP_NO_BADGES]   = 12,
    [LEVEL_CAP_BADGE_1]     = 24,
    [LEVEL_CAP_BADGE_2]     = 36,
    [LEVEL_CAP_BADGE_3]     = 48,
    [LEVEL_CAP_BADGE_4]     = 60,
    [LEVEL_CAP_BADGE_5]     = 72,
    [LEVEL_CAP_BADGE_6]     = 80,
    [LEVEL_CAP_BADGE_7]     = 100,
    [LEVEL_CAP_BADGE_8]     = 128,
};

u8 GetCurrentBadgeCount(void)
{
    u16 i, badgeCount = 0;
    for (i = FLAG_BADGE01_GET; i < FLAG_BADGE01_GET + NUM_BADGES; i++) //count badges
    {
        if (FlagGet(i))
            badgeCount++;
    }
    return badgeCount;
}

u8 GetCurrentTrainerIVs(void)
{
    u8 badgeCount = GetCurrentBadgeCount();

    switch (gSaveBlock1Ptr->tx_Challenges_TrainerScalingIVs)
    {
    case 1:     return sIV_Table[badgeCount];
    default:    return MAX_PER_STAT_IVS;
    }
}
u8 GetCurrentTrainerEVs(void)
{
    u8 badgeCount = GetCurrentBadgeCount();

    switch (gSaveBlock1Ptr->tx_Challenges_TrainerScalingEVs)
    {
    case 1:     return sEV_Table[badgeCount];
    case 2:     return 128;
    case 3:     return 252;
    default:    return 0;
    }
}