static const u8 sWholeNewWorldAchLabel[] = _("A Whole New World");
static const u8 sWholeNewWorldAchDesc[] = _("Welcome to Emerald Enhanced.\nExplore to your heart's content!");

static const u8 sEnhancedBattleAchLabel[] = _("Enhanced Battle");
static const u8 sEnhancedBattleAchDesc[] = _("You have awakened as a battle master!");

static const u8 sNewRegionWhoDisAchLabel[] = _("New Region Who Dis");
static const u8 sNewRegionWhoDisAchDesc[] = _("You made a friend!\nEverything is better with friends.");

static const u8 sAdventureTimeAchLabel[] = _("Adventure Time");
static const u8 sAdventureTimeAchDesc[] = _("You started your first quest.\nGood Luck!");

static const u8 sTrueLoveAchLabel[] = _("Love at First Sight");
static const u8 sTrueLoveAchDesc[] = _("You have entered a relationship.\nNow you wonder what you would\ndo without them.");

static const u8 sSilentStrongTypeAchLabel[] = _("Silent, Strong type");
static const u8 sSilentStrongTypeAchDesc[] = _("The quiet ones usually have the most to say!\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Lana)");

static const u8 sChildhoodFriendAchLabel[] = _("A Childhood Friend");
static const u8 sChildhoodFriendAchDesc[] = _("{RIVAL} would follow you off of a cliff.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced {RIVAL})");

static const u8 sNerdLoveAchLabel[] = _("Nerd Love");
static const u8 sNerdLoveAchDesc[] = _("You feel her rubbing off on you.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Lanette)");

static const u8 sFWBAchLabel[] = _("Friends with Benefits");
static const u8 sFWBAchDesc[] = _("You have a secret weapon!\nYour own, personal nurse.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Joy)");

static const u8 sWetnWildAchLabel[] = _("Wet and Wild");
static const u8 sWetnWildAchDesc[] = _("You found a girl who loves to get wet.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Shelly)");

static const u8 sFieryPassionAchLabel[] = _("Fiery Passion");
static const u8 sFieryPassionAchDesc[] = _("She's blazing hot!\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Courtney)");

static const u8 sTrueEndingAchLabel[] = _("The True Ending");
static const u8 sTrueEndingAchDesc[] = _("You're quite the lady killer, eh?\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Got the Harem ending)");

static const struct AtlasAchPointData sAchAtlasData[] =
{
    [ACH_WHOLE_NEW_WORLD] = {12, 55, CATEGORY_EXPLORATION, ACH_WHOLE_NEW_WORLD, sWholeNewWorldAchLabel, sWholeNewWorldAchDesc},
    [ACH_ENHANCED_BATTLE] = {28, 55, CATEGORY_BATTLE, ACH_ENHANCED_BATTLE, sEnhancedBattleAchLabel, sEnhancedBattleAchDesc},
    [ACH_NEW_REGION_WHO_DIS] = {57, 55, CATEGORY_COMPANIONS, ACH_NEW_REGION_WHO_DIS, sNewRegionWhoDisAchLabel, sNewRegionWhoDisAchDesc},
    [ACH_ADVENTURE_TIME] = {43, 55, CATEGORY_QUESTING, ACH_ADVENTURE_TIME, sAdventureTimeAchLabel, sAdventureTimeAchDesc},
    [ACH_TRUE_LOVE] = {57, 52, CATEGORY_COMPANIONS, ACH_TRUE_LOVE, sTrueLoveAchLabel, sTrueLoveAchDesc},
    [ACH_SILENT_STRONG_TYPE] = {59, 48, CATEGORY_COMPANIONS, ACH_SILENT_STRONG_TYPE, sSilentStrongTypeAchLabel, sSilentStrongTypeAchDesc},
    [ACH_CHILDHOOD_FRIEND] = {59, 50, CATEGORY_COMPANIONS, ACH_CHILDHOOD_FRIEND, sChildhoodFriendAchLabel, sChildhoodFriendAchDesc},
    [ACH_FIERY_PASSION] = {59, 52, CATEGORY_COMPANIONS, ACH_FIERY_PASSION, sFieryPassionAchLabel, sFieryPassionAchDesc},
    [ACH_NERD_LOVE] = {61, 48, CATEGORY_COMPANIONS, ACH_NERD_LOVE, sNerdLoveAchLabel, sNerdLoveAchDesc},
    [ACH_FWB] = {61, 50, CATEGORY_COMPANIONS, ACH_FWB, sFWBAchLabel, sFWBAchDesc},
    [ACH_WET_N_WILD] = {61, 52, CATEGORY_COMPANIONS, ACH_WET_N_WILD, sWetnWildAchLabel, sWetnWildAchDesc},
    [ACH_TRUE_ENDING] = {60, 46, CATEGORY_COMPANIONS, ACH_TRUE_ENDING, sTrueEndingAchLabel, sTrueEndingAchDesc}, 
};