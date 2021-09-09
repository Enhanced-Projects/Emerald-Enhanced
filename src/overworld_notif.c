#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

struct Notification
{
    u8 flags;
    u8 dispTime;

    u8 notifText[0x40];
};

void ShowNotificationWindow(void)
{
    /*
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8* mapDisplayHeaderSource;

    if (InBattlePyramid())
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[7];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[3]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }
    */
    AddMapNamePopUpWindow();
    DrawStdWindowFrame(GetMapNamePopUpWindowId(), TRUE);
    //x = GetStringCenterAlignXOffset(7, withoutPrefixPtr, 80);
    //mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    //mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    //mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    AddTextPrinterParameterized(GetMapNamePopUpWindowId(), 7, (u8[])_("Placeholder"), 0, 0, 0xFF, NULL);
    CopyWindowToVram(GetMapNamePopUpWindowId(), 3);
}