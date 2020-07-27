#include "global.h"
#include "event_data.h"
#include "menu.h"
#include "script.h"
#include "palette.h"
#include "field_message_box.h"
#include "rtc.h"
#include "window.h"
#include "string_util.h"
#include "strings.h"

EWRAM_DATA static u8 sPrintWindowId = 1;

#define BOXLIST(name) {name, ARRAY_COUNT(name)}

struct InfoBox
{
    const u8 *text;
};

struct InfoBoxListStruct
{
    const struct InfoBox *list;
    u8 count;
};


//Strings for use in infobox

const u8 gText_RyuStatHpDisplay[] = _("{STR_VAR_1}");
const u8 gText_RyuStatAtkDisplay[] = _("{STR_VAR_2}");
const u8 gText_RyuStatDefDisplay[] = _("{STR_VAR_3}");
const u8 gText_RyuStatSpAtkDisplay[] = _("{RYU_STR_1}");
const u8 gText_RyuStatSpDefDisplay[] = _("{RYU_STR_2}");
const u8 gText_RyuStatSpeedDisplay[] = _("{RYU_STR_3}");

const u8 gText_FHyperOffenseLine1[] = _("A hyper offense based around both");
const u8 gText_FHyperOffenseLine2[] = _("Sticky Web and Toxic Spikes.");
const u8 gText_FHyperOffenseLine3[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Ariados {COLOR DARK_GREY}{SHADOW LIGHT_GREY}sets both up, {COLOR LIGHT_BLUE}{SHADOW BLUE}Toxicroak");
const u8 gText_FHyperOffenseLine4[] = _("can sweep with Merciless doubling");
const u8 gText_FHyperOffenseLine5[] = _("damage output, while Toxic Boost");
const u8 gText_FHyperOffenseLine6[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Zangoose {COLOR DARK_GREY}{SHADOW LIGHT_GREY}benefits from the Web.");

const u8 gText_FOffenseLine1[] = _("An Aurora Veil team with {COLOR LIGHT_BLUE}{SHADOW BLUE}Aurorus");
const u8 gText_FOffenseLine2[] = _("as the setter. {COLOR LIGHT_BLUE}{SHADOW BLUE}Beartic {COLOR DARK_GREY}{SHADOW LIGHT_GREY}can set up");
const u8 gText_FOffenseLine3[] = _("Belly Drum and sweep with its 3");
const u8 gText_FOffenseLine4[] = _("priority moves, while {COLOR LIGHT_BLUE}{SHADOW BLUE}Mega Gallade {COLOR DARK_GREY}{SHADOW LIGHT_GREY}has");
const u8 gText_FOffenseLine5[] = _("Swords Dance and useful resistances");
const u8 gText_FOffenseLine6[] = _("to Fighting and Rock.");

const u8 gText_FBalanceLine1[] = _("A Fire-Water-Grass core with");
const u8 gText_FBalanceLine2[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Typhlosion {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a very offensive");
const u8 gText_FBalanceLine3[] = _("Focus Sash user, {COLOR LIGHT_BLUE}{SHADOW BLUE}Feraligatr {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a");
const u8 gText_FBalanceLine4[] = _("Dragon Dance sweeper, and {COLOR LIGHT_BLUE}{SHADOW BLUE}Venusaur");
const u8 gText_FBalanceLine5[] = _("as a bulky backbone that still does");
const u8 gText_FBalanceLine6[] = _("decent damage.");

const u8 gText_FBulkyOffenseLine1[] = _("A bulky team featuring {COLOR LIGHT_BLUE}{SHADOW BLUE}Swampert");
const u8 gText_FBulkyOffenseLine2[] = _("and {COLOR LIGHT_BLUE}{SHADOW BLUE}Rhydon {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as strong yet bulky");
const u8 gText_FBulkyOffenseLine3[] = _("attackers with Assault Vest/Eviolite.");
const u8 gText_FBulkyOffenseLine4[] = _("Regenerator {COLOR LIGHT_BLUE}{SHADOW BLUE}Meganium {COLOR DARK_GREY}{SHADOW LIGHT_GREY}keeps them");
const u8 gText_FBulkyOffenseLine5[] = _("healthy with Wish + Baton Pass,");
const u8 gText_FBulkyOffenseLine6[] = _("while still doing decent damage.");

const u8 gText_FStallLine1[] = _("A stall team with Heatproof {COLOR LIGHT_BLUE}{SHADOW BLUE}Regice");
const u8 gText_FStallLine2[] = _("as special wall, Regenerator {COLOR LIGHT_BLUE}{SHADOW BLUE}Slowbro");
const u8 gText_FStallLine3[] = _("as physical wall, and Swords Dance");
const u8 gText_FStallLine4[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Gliscor {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the win condition. The");
const u8 gText_FStallLine5[] = _("plan is switching between walls,");
const u8 gText_FStallLine6[] = _("until Gliscor finds an opening.");

const u8 gText_FHailLine1[] = _("A Hail team with Snow Warning");
const u8 gText_FHailLine2[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Walrein {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the setter, Swords");
const u8 gText_FHailLine3[] = _("Dance + Slush Rush {COLOR LIGHT_BLUE}{SHADOW BLUE}Dewgong {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the");
const u8 gText_FHailLine4[] = _("sweeper, and Weather Ball {COLOR LIGHT_BLUE}{SHADOW BLUE}Raikou");
const u8 gText_FHailLine5[] = _("as a general benefitter that does");
const u8 gText_FHailLine6[] = _("not share weaknesses.");

const u8 gText_FRainLine1[] = _("A Rain team with Drizzle {COLOR LIGHT_BLUE}{SHADOW BLUE}Lapras");
const u8 gText_FRainLine2[] = _("as setter, Swift Swim {COLOR LIGHT_BLUE}{SHADOW BLUE}Seismitoad");
const u8 gText_FRainLine3[] = _("as physical sweeper, and Thunder");
const u8 gText_FRainLine4[] = _("+ Hurricane {COLOR LIGHT_BLUE}{SHADOW BLUE}Rotom-Fan {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a counter");
const u8 gText_FRainLine5[] = _("to Water and Grass types that may");
const u8 gText_FRainLine6[] = _("threaten the team.");

const u8 gText_FSunLine1[] = _("A Sun team with Drought {COLOR LIGHT_BLUE}{SHADOW BLUE}Magcargo");
const u8 gText_FSunLine2[] = _("as setter and Shell Smash sweeper,");
const u8 gText_FSunLine3[] = _("Chlorophyll {COLOR LIGHT_BLUE}{SHADOW BLUE}Victreebel {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as speed");
const u8 gText_FSunLine4[] = _("control, and Solar Power {COLOR LIGHT_BLUE}{SHADOW BLUE}Mega");
const u8 gText_FSunLine5[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Houndoom {COLOR DARK_GREY}{SHADOW LIGHT_GREY}with Nasty Plot as a very");
const u8 gText_FSunLine6[] = _("powerful sweeper.");

const u8 gText_FSandstormLine1[] = _("A Sandstorm team with Sand Stream");
const u8 gText_FSandstormLine2[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Gigalith {COLOR DARK_GREY}{SHADOW LIGHT_GREY}with Stealth Rock +");
const u8 gText_FSandstormLine3[] = _("Explosion as an offensive setter.");
const u8 gText_FSandstormLine4[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Excadrill {COLOR DARK_GREY}{SHADOW LIGHT_GREY}and {COLOR LIGHT_BLUE}{SHADOW BLUE}Stoutland {COLOR DARK_GREY}{SHADOW LIGHT_GREY}form a duo of");
const u8 gText_FSandstormLine5[] = _("Swords Dance + Sand Rush sweepers.");
const u8 gText_FSandstormLine6[] = _("Stoutland's Fire Fang handles Skarmory.");

const u8 gText_FGrassyTerrainLine1[] = _("A Grassy Terrain team with Grassy");
const u8 gText_FGrassyTerrainLine2[] = _("Surge {COLOR LIGHT_BLUE}{SHADOW BLUE}Rotom-Mow {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the setter, {COLOR LIGHT_BLUE}{SHADOW BLUE}Gogoat");
const u8 gText_FGrassyTerrainLine3[] = _("as a very bulky setup sweeper thanks");
const u8 gText_FGrassyTerrainLine4[] = _("to Grass Pelt, and Nasty Plot {COLOR LIGHT_BLUE}{SHADOW BLUE}Seviper");
const u8 gText_FGrassyTerrainLine5[] = _("to provide nice resistances while");
const u8 gText_FGrassyTerrainLine6[] = _("having almost no weaknesses itself.");

const u8 gText_FPsychicTerrainLine1[] = _("A Psychic Terrain team with Psychic");
const u8 gText_FPsychicTerrainLine2[] = _("Surge {COLOR LIGHT_BLUE}{SHADOW BLUE}Beheeyem {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the setter, {COLOR LIGHT_BLUE}{SHADOW BLUE}Delphox");
const u8 gText_FPsychicTerrainLine3[] = _("as a fast attacker that appreciates the");
const u8 gText_FPsychicTerrainLine4[] = _("priority negation, and {COLOR LIGHT_BLUE}{SHADOW BLUE}Mega Sharpedo {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as");
const u8 gText_FPsychicTerrainLine5[] = _("a Dark counter that benefits from the");
const u8 gText_FPsychicTerrainLine6[] = _("terrain as well.");

const u8 gText_FTrickRoomLine1[] = _("A Trick Room team with {COLOR LIGHT_BLUE}{SHADOW BLUE}Octillery {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as an");
const u8 gText_FTrickRoomLine2[] = _("offensive setter with strong Mega");
const u8 gText_FTrickRoomLine3[] = _("Launcher attacks, {COLOR LIGHT_BLUE}{SHADOW BLUE}Zen Darmanitan {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a");
const u8 gText_FTrickRoomLine4[] = _("secondary setter that can sweep with");
const u8 gText_FTrickRoomLine5[] = _("Weakness Policy, and Reckless + Head");
const u8 gText_FTrickRoomLine6[] = _("Smash {COLOR LIGHT_BLUE}{SHADOW BLUE}Rampardos {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a strong breaker.");

const u8 gText_FBatonPassLine1[] = _("A Baton Pass team with Speed Boost");
const u8 gText_FBatonPassLine2[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Jolteon {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the speed passer, Acid Armor");
const u8 gText_FBatonPassLine3[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Vaporeon {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the defense passer, and");
const u8 gText_FBatonPassLine4[] = _("Calm Mind + Stored Power {COLOR LIGHT_BLUE}{SHADOW BLUE}Espeon {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the");
const u8 gText_FBatonPassLine5[] = _("sweeper. Magic Bounce helps negating");
const u8 gText_FBatonPassLine6[] = _("common Baton Pass counters like Roar.");

const u8 gText_FGimmickLine1[] = _("A Toxic Spikes team with Merciless");
const u8 gText_FGimmickLine2[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Toxicroak {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as the setter, forcing out");
const u8 gText_FGimmickLine3[] = _("pokemon with Red Card and Circle Throw.");
const u8 gText_FGimmickLine4[] = _("Offensive Merciless {COLOR LIGHT_BLUE}{SHADOW BLUE}Toxapex {COLOR DARK_GREY}{SHADOW LIGHT_GREY}deals high");
const u8 gText_FGimmickLine5[] = _("damage with Venoshock, and Sky Drop");
const u8 gText_FGimmickLine6[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Skarmory {COLOR DARK_GREY}{SHADOW LIGHT_GREY}stall out the Toxic damage.");

const u8 gText_FEggtacticalLine1[] = _("A team of pokemon selected by lord");
const u8 gText_FEggtacticalLine2[] = _("Egg himself. Features Swords Dance");
const u8 gText_FEggtacticalLine3[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Ninjask {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a fast sweeper, Swords");
const u8 gText_FEggtacticalLine4[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Mega Scizor {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a bulky sweeper, and");
const u8 gText_FEggtacticalLine5[] = _("defensive {COLOR LIGHT_BLUE}{SHADOW BLUE}Umbreon {COLOR DARK_GREY}{SHADOW LIGHT_GREY}as a pokemon to");
const u8 gText_FEggtacticalLine6[] = _("fall back on against threats.");

const u8 gText_FMasochistLine1[] = _("A team featuring the best of the");
const u8 gText_FMasochistLine2[] = _("best, for when you want to have an");
const u8 gText_FMasochistLine3[] = _("easy time. Contains a vicious");
const u8 gText_FMasochistLine4[] = _("Choice Band wallbreaker, a very");
const u8 gText_FMasochistLine5[] = _("bulky setup sweeper, and the best");
const u8 gText_FMasochistLine6[] = _("Rain sweeper in the game.");

const u8 gText_FFearLine1[] = _("A FEAR team of lvl 1 {COLOR LIGHT_BLUE}{SHADOW BLUE}Togedemaru {COLOR DARK_GREY}{SHADOW LIGHT_GREY}and");
const u8 gText_FFearLine2[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Magnemite{COLOR DARK_GREY}{SHADOW LIGHT_GREY}, backed up by {COLOR LIGHT_BLUE}{SHADOW BLUE}Hippowdon{COLOR DARK_GREY}{SHADOW LIGHT_GREY}.");
const u8 gText_FFearLine3[] = _("Togedemaru has an Endeavor Shell Bell");
const u8 gText_FFearLine4[] = _("set aided by Sandstorm. Sturdy");
const u8 gText_FFearLine5[] = _("Magnemite paralyzes and Swaggers,");
const u8 gText_FFearLine6[] = _("while Recycling its Berry Juice.");

//String list groups for individual infoboxes

static const struct InfoBox sInfoBoxPokemonData[] = 
{
    {gText_RyuStatHpDisplay},
    {gText_RyuStatAtkDisplay},
    {gText_RyuStatDefDisplay},
    {gText_RyuStatSpAtkDisplay},
    {gText_RyuStatSpDefDisplay},
    {gText_RyuStatSpeedDisplay},
};

static const struct InfoBox sInfoBoxFHyperOffenseStarter[] = 
{
    {gText_FHyperOffenseLine1},
    {gText_FHyperOffenseLine2},
    {gText_FHyperOffenseLine3},
    {gText_FHyperOffenseLine4},
    {gText_FHyperOffenseLine5},
    {gText_FHyperOffenseLine6},
};

static const struct InfoBox sInfoBoxFOffenseStarter[] = 
{
    {gText_FOffenseLine1},
    {gText_FOffenseLine2},
    {gText_FOffenseLine3},
    {gText_FOffenseLine4},
    {gText_FOffenseLine5},
    {gText_FOffenseLine6},
};

static const struct InfoBox sInfoBoxFBalanceStarter[] = 
{
    {gText_FBalanceLine1},
    {gText_FBalanceLine2},
    {gText_FBalanceLine3},
    {gText_FBalanceLine4},
    {gText_FBalanceLine5},
    {gText_FBalanceLine6},
};

static const struct InfoBox sInfoBoxFBulkyOffenseStarter[] = 
{
    {gText_FBulkyOffenseLine1},
    {gText_FBulkyOffenseLine2},
    {gText_FBulkyOffenseLine3},
    {gText_FBulkyOffenseLine4},
    {gText_FBulkyOffenseLine5},
    {gText_FBulkyOffenseLine6},
};

static const struct InfoBox sInfoBoxFStallStarter[] = 
{
    {gText_FStallLine1},
    {gText_FStallLine2},
    {gText_FStallLine3},
    {gText_FStallLine4},
    {gText_FStallLine5},
    {gText_FStallLine6},
};

static const struct InfoBox sInfoBoxFHailStarter[] = 
{
    {gText_FHailLine1},
    {gText_FHailLine2},
    {gText_FHailLine3},
    {gText_FHailLine4},
    {gText_FHailLine5},
    {gText_FHailLine6},
};

static const struct InfoBox sInfoBoxFRainStarter[] = 
{
    {gText_FRainLine1},
    {gText_FRainLine2},
    {gText_FRainLine3},
    {gText_FRainLine4},
    {gText_FRainLine5},
    {gText_FRainLine6},
};

static const struct InfoBox sInfoBoxFSunStarter[] = 
{
    {gText_FSunLine1},
    {gText_FSunLine2},
    {gText_FSunLine3},
    {gText_FSunLine4},
    {gText_FSunLine5},
    {gText_FSunLine6},
};

static const struct InfoBox sInfoBoxFSandstormStarter[] = 
{
    {gText_FSandstormLine1},
    {gText_FSandstormLine2},
    {gText_FSandstormLine3},
    {gText_FSandstormLine4},
    {gText_FSandstormLine5},
    {gText_FSandstormLine6},
};

static const struct InfoBox sInfoBoxFGrassyTerrainStarter[] = 
{
    {gText_FGrassyTerrainLine1},
    {gText_FGrassyTerrainLine2},
    {gText_FGrassyTerrainLine3},
    {gText_FGrassyTerrainLine4},
    {gText_FGrassyTerrainLine5},
    {gText_FGrassyTerrainLine6},
};

static const struct InfoBox sInfoBoxFPsychicTerrainStarter[] = 
{
    {gText_FPsychicTerrainLine1},
    {gText_FPsychicTerrainLine2},
    {gText_FPsychicTerrainLine3},
    {gText_FPsychicTerrainLine4},
    {gText_FPsychicTerrainLine5},
    {gText_FPsychicTerrainLine6},
};

static const struct InfoBox sInfoBoxFTrickRoomStarter[] = 
{
    {gText_FTrickRoomLine1},
    {gText_FTrickRoomLine2},
    {gText_FTrickRoomLine3},
    {gText_FTrickRoomLine4},
    {gText_FTrickRoomLine5},
    {gText_FTrickRoomLine6},
};

static const struct InfoBox sInfoBoxFBatonPassStarter[] = 
{
    {gText_FBatonPassLine1},
    {gText_FBatonPassLine2},
    {gText_FBatonPassLine3},
    {gText_FBatonPassLine4},
    {gText_FBatonPassLine5},
    {gText_FBatonPassLine6},
};

static const struct InfoBox sInfoBoxFGimmickStarter[] = 
{
    {gText_FGimmickLine1},
    {gText_FGimmickLine2},
    {gText_FGimmickLine3},
    {gText_FGimmickLine4},
    {gText_FGimmickLine5},
    {gText_FGimmickLine6},
};

static const struct InfoBox sInfoBoxFEggtacticalStarter[] = 
{
    {gText_FEggtacticalLine1},
    {gText_FEggtacticalLine2},
    {gText_FEggtacticalLine3},
    {gText_FEggtacticalLine4},
    {gText_FEggtacticalLine5},
    {gText_FEggtacticalLine6},
};

static const struct InfoBox sInfoBoxFMasochistStarter[] = 
{
    {gText_FMasochistLine1},
    {gText_FMasochistLine2},
    {gText_FMasochistLine3},
    {gText_FMasochistLine4},
    {gText_FMasochistLine5},
    {gText_FMasochistLine6},
};

static const struct InfoBox sInfoBoxFFearStarter[] = 
{
    {gText_FFearLine1},
    {gText_FFearLine2},
    {gText_FFearLine3},
    {gText_FFearLine4},
    {gText_FFearLine5},
    {gText_FFearLine6},
};

//You also need to add INFOBOX(name) to the bottom of vars.h so that these can be accessed from script.

//List of infobox groups used when calling them
static const struct InfoBoxListStruct sInfoBoxes[] =
{
    BOXLIST(sInfoBoxPokemonData),  //INFOBOXPOKEMONDATA
    BOXLIST(sInfoBoxFHyperOffenseStarter), //INFOBOX_F_STARTER_HYPER_OFFENSE
    BOXLIST(sInfoBoxFOffenseStarter), //INFOBOX_F_STARTER_OFFENSE
    BOXLIST(sInfoBoxFBalanceStarter), //INFOBOX_F_STARTER_BALANCE
    BOXLIST(sInfoBoxFBulkyOffenseStarter), //INFOBOX_F_STARTER_BULKY_OFFENSE
    BOXLIST(sInfoBoxFStallStarter), //INFOBOX_F_STARTER_STALL
    BOXLIST(sInfoBoxFHailStarter), //INFOBOX_F_STARTER_HAIL
    BOXLIST(sInfoBoxFRainStarter), //INFOBOX_F_STARTER_RAIN
    BOXLIST(sInfoBoxFSunStarter), //INFOBOX_F_STARTER_SUN
    BOXLIST(sInfoBoxFSandstormStarter), //INFOBOX_F_STARTER_SANDSTORM
    BOXLIST(sInfoBoxFGrassyTerrainStarter), //INFOBOX_F_STARTER_GRASSY_TERRAIN
    BOXLIST(sInfoBoxFPsychicTerrainStarter), //INFOBOX_F_STARTER_PSYCHIC_TERRAIN
    BOXLIST(sInfoBoxFTrickRoomStarter), //INFOBOX_F_STARTER_TRICK_ROOM
    BOXLIST(sInfoBoxFBatonPassStarter), //INFOBOX_F_STARTER_BATON_PASS
    BOXLIST(sInfoBoxFGimmickStarter), //INFOBOX_F_STARTER_GIMMICK
    BOXLIST(sInfoBoxFEggtacticalStarter), //INFOBOX_F_STARTER_EGGTACTICAL
    BOXLIST(sInfoBoxFMasochistStarter), //INFOBOX_F_STARTER_MASOCHIST
    BOXLIST(sInfoBoxFFearStarter) //INFOBOX_F_STARTER_FEAR
};

void PrintInfoTable(u8 windowId, u8 itemCount, const struct InfoBox *strs)
{
    u32 i;

    for (i = 0; i < itemCount; i++)
    {
        StringExpandPlaceholders(gStringVar4, strs[i].text);
        AddTextPrinterParameterized(windowId, 1, gStringVar4, 4, (i * 16) + 1, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void PrintInfoBox(u16 number)
{
    u8 i = 0;
    u16 y = 0;
    u8 count = sInfoBoxes[number].count;
    struct WindowTemplate template;
    const struct InfoBox *list = sInfoBoxes[number].list;

    SetWindowTemplateFields(&template, 0, 1, 1, 28, 12, 15, 4);
    sPrintWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sPrintWindowId, 0);
    PutWindowTilemap(sPrintWindowId);
    DrawStdFrameWithCustomTileAndPalette(sPrintWindowId, FALSE, 0x214, 14);
    PrintInfoTable(sPrintWindowId, count, list);
}



void RemoveInfoBox(void)
{
    ClearStdWindowAndFrameToTransparent(sPrintWindowId, FALSE);
    CopyWindowToVram(sPrintWindowId, 2);
    RemoveWindow(sPrintWindowId);
}

