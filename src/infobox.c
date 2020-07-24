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

const u8 gText_FHyperOffenseLine1[] = _("A hyper offense team of Ariados,");
const u8 gText_FHyperOffenseLine2[] = _("Toxicroak and Zangoose. Ariados sets");
const u8 gText_FHyperOffenseLine3[] = _("Sticky Web + Toxic Spikes, Toxicroak");
const u8 gText_FHyperOffenseLine4[] = _("can sweep with Merciless doubling");
const u8 gText_FHyperOffenseLine5[] = _("damage output, while Zangoose has");
const u8 gText_FHyperOffenseLine6[] = _("Toxic Boost to double its Attack.");

const u8 gText_FFEARTeamLine1[] = _("A FEAR team of level 1 Aron and");
const u8 gText_FFEARTeamLine2[] = _("Magnemite, backed up by Hippowdon.");
const u8 gText_FFEARTeamLine3[] = _("Aron has an Endeavor Shell Bell set");
const u8 gText_FFEARTeamLine4[] = _("aided by Sandstorm. Sturdy");
const u8 gText_FFEARTeamLine5[] = _("Magnemite paralyzes and Swaggers,");
const u8 gText_FFEARTeamLine6[] = _("while Recycling its Berry Juice");

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

static const struct InfoBox sInfoBoxFFEARTeamStarter[] = 
{
    {gText_FFEARTeamLine1},
    {gText_FFEARTeamLine2},
    {gText_FFEARTeamLine3},
    {gText_FFEARTeamLine4},
    {gText_FFEARTeamLine5},
    {gText_FFEARTeamLine6},
};

//You also need to add INFOBOX(name) to the bottom of vars.h so that these can be accessed from script.

//List of infobox groups used when calling them
static const struct InfoBoxListStruct sInfoBoxes[] =
{
    BOXLIST(sInfoBoxPokemonData),  //INFOBOXPOKEMONDATA
    BOXLIST(sInfoBoxFHyperOffenseStarter), //INFOBOX_F_STARTER_HYPER_OFFENSE
    BOXLIST(sInfoBoxFFEARTeamStarter) //INFOBOX_F_STARTER_FEAR_TEAM
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

