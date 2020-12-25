static const u8 sWholeNewWorldAchLabel[] = _("A Whole New World");
static const u8 sWholeNewWorldAchDesc[] = _("Welcome to Emerald Enhanced.\nExplore to your heart's content!\n(Completed tutorial)");

static const u8 sEnhancedBattleAchLabel[] = _("Enhanced Battle");
static const u8 sEnhancedBattleAchDesc[] = _("You have awakened as a battle master!\n(Finished your first battle)");

static const u8 sNewRegionWhoDisAchLabel[] = _("New Region Who Dis");
static const u8 sNewRegionWhoDisAchDesc[] = _("You made a friend!\nEverything is better with friends.\n(Befriended someone for the first time.)");

static const u8 sAdventureTimeAchLabel[] = _("Adventure Time");
static const u8 sAdventureTimeAchDesc[] = _("You started your first quest.\nGood Luck!\n");

static const u8 sTrueLoveAchLabel[] = _("Love at First Sight");
static const u8 sTrueLoveAchDesc[] = _("You have entered a relationship.\nNow you wonder what you would\ndo without them.");

static const u8 sSilentStrongTypeAchLabel[] = _("Silent, Strong type");
static const u8 sSilentStrongTypeAchDesc[] = _("The quiet ones usually have the most to say!\n(Romanced Lana)");

static const u8 sChildhoodFriendAchLabel[] = _("A Childhood Friend");
static const u8 sChildhoodFriendAchDesc[] = _("{RIVAL} would follow you off of a cliff.\n(Romanced {RIVAL})");

static const u8 sNerdLoveAchLabel[] = _("Nerd Love");
static const u8 sNerdLoveAchDesc[] = _("You feel her rubbing off on you.\n(Romanced Lanette)");

static const u8 sFWBAchLabel[] = _("Friends with Benefits");
static const u8 sFWBAchDesc[] = _("You have a secret weapon!\nYour own, personal nurse.\n(Romanced Joy)");

static const u8 sWetnWildAchLabel[] = _("Wet and Wild");
static const u8 sWetnWildAchDesc[] = _("You found a girl who loves to get wet.\n(Romanced Shelly)");

static const u8 sFieryPassionAchLabel[] = _("Fiery Passion");
static const u8 sFieryPassionAchDesc[] = _("She's blazing hot!\n(Romanced Courtney)");

static const u8 sTrueEndingAchLabel[] = _("The True Ending");
static const u8 sTrueEndingAchDesc[] = _("You're quite the lady killer, eh?\n(Got the Harem ending)");

static const u8 sEternalDamnationLabel[] = _("Eternal Damnation");
static const u8 sEternalDamnationAchDesc[] = _("And thus, a new monarchy was born!\n(Completed Magma Alt Romance line)");
static const u8 sHuntingTripAchLabel[] = _("Hunting Trip");
static const u8 sHuntingTripAchDesc[] = _("There's something strangely cathartic about\nhunting a person down and finishing the job.\n(Completed the Magma Alt line)");
static const u8 sThroughTheFireAchLabel[] = _("Through the Fire and Flames");
static const u8 sThroughTheFireAchDesc[] = _("You made a deal with the devil.\nAll who stand in your way will perish.\n(Completed Magma main Romance line)");
static const u8 sHeatedArgumentLabel[] = _("A Heated Argument");
static const u8 sHeatedArgumentAchDesc[] = _("You could say he... went up in flames.\n(Completed Magma Main line)");
static const u8 sEyeOfTheStormLabel[] = _("Eye of the Storm");
static const u8 sEyeOfTheStormAchDesc[] = _("You travelled into the eye of the storm,\nand lived to tell the tale.\n(Completed Aqua Romance line)");
static const u8 sWaterLoggedLabel[] = _("Water Logged");
static const u8 sWaterLoggedAchDesc[] = _("You're a little wet and very disappointed.\nAt least you didn't go to jail!\n(Completed Aqua Neutral line)");
static const u8 sAstronomicalLabel[] = _("Astronomical!");
static const u8 sAstronomicalAchDesc[] = _("The possibilities are {SHADOW BLUE}literally{SHADOW GREEN} endless!\n(Completed Devon Scientist line)");
static const u8 sCorporateShillLabel[] = _("Corporate Shill");
static const u8 sCorporateShillAchDesc[] = _("Stocks, lobbying, tax evasion, oh my!\n(Completed Devon Corporate line)");
static const u8 sDejaVuLabel[] = _("Deja Vu?");
static const u8 sDejaVuDesc[] = _("Hey! a lot of this looks familiar!\n(Got every main quest ending possible.)");

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
    [ACH_ETERNAL_DAMNATION] = {1, 8, CATEGORY_QUESTING, ACH_ETERNAL_DAMNATION, sEternalDamnationLabel, sEternalDamnationAchDesc}, //magma alt romance ending
    [ACH_HUNTING_TRIP] = {3, 8, CATEGORY_QUESTING, ACH_HUNTING_TRIP, sHuntingTripAchLabel, sHuntingTripAchDesc}, //magma alt non romance ending
    [ACH_THROUGH_THE_FIRE] = {5, 8, CATEGORY_QUESTING, ACH_THROUGH_THE_FIRE, sThroughTheFireAchLabel, sThroughTheFireAchDesc}, // magma main romance ending
    [ACH_HEATED_ARGUMENT] = {7, 8, CATEGORY_QUESTING, ACH_HEATED_ARGUMENT, sHeatedArgumentLabel, sHeatedArgumentAchDesc}, // magma main non romance ending
    [ACH_EYE_OF_STORM] = {9, 8, CATEGORY_QUESTING, ACH_EYE_OF_STORM, sEyeOfTheStormLabel, sEyeOfTheStormAchDesc}, // Aqua shelly ending
    [ACH_WATER_LOGGED] = {11, 8, CATEGORY_QUESTING, ACH_WATER_LOGGED, sWaterLoggedLabel, sWaterLoggedAchDesc}, // Aqua neutral ending
    [ACH_ASTRONOMICAL] = {13, 8, CATEGORY_QUESTING, ACH_ASTRONOMICAL, sAstronomicalLabel, sAstronomicalAchDesc}, // Devon Scientist ending
    [ACH_CORPORATE_SHILL] = {15, 8, CATEGORY_QUESTING, ACH_CORPORATE_SHILL, sCorporateShillLabel, sCorporateShillAchDesc}, // Devon Corporate ending
    [ACH_DEJA_VU] = {17, 8, CATEGORY_QUESTING, ACH_DEJA_VU, sDejaVuLabel, sDejaVuDesc}, // Completed all main quest endings
};