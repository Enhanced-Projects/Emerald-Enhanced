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

#define BOXLIST(name) {name, ARRAY_COUNT(name)}

EWRAM_DATA static u8 sPrintWindowId = 1;

struct InfoBoxList
{
    const u8 *text;
    union {
        void (*void_u8)(u8);
        u8 (*u8_void)(void);
    } func;
};

struct InfoBoxListStruct
{
    const struct InfoBoxList *list;
    u8 count;
};

static const struct InfoBoxList sInfoBoxListPokeblocks[] = 
{
    {gText_RedPokeblock},
    {gText_BluePokeblock},
    {gText_PinkPokeblock},
    {gText_GreenPokeblock},
    {gText_YellowPokeblock},
    {gText_PurplePokeblock},
    {gText_IndigoPokeblock},
    {gText_BrownPokeblock},
    {gText_LiteBluePokeblock},
    {gText_OlivePokeblock},
};

static const struct InfoBoxListStruct sInfoBoxList[] =
{
    [INFOBOXPOKEBLOCKS] = BOXLIST(sInfoBoxListPokeblocks),
};

void PrintInfoBox(u16 number)
{
    struct WindowTemplate template;

    const struct InfoListBox *boxlist = sInfoBoxList[number].list;

    //prepare window
    SetWindowTemplateFields(&template, 0, 4, 4, 29, 19, 15, 8);
    sPrintWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sPrintWindowId, 0);
    PutWindowTilemap(sPrintWindowId);
    CopyWindowToVram(sPrintWindowId, 1);
    DrawStdFrameWithCustomTileAndPalette(sPrintWindowId, FALSE, 0x214, 14);

    //first batch
    StringCopy(gStringVar1, &number);
    StringCopy(gStringVar2, &number);
    StringCopy(gStringVar3, &number);
    StringCopy(gRyuStringVar1, &number);
    StringCopy(gRyuStringVar2, &number);
    StringCopy(gRyuStringVar3, &number);

    AddTextPrinterParameterized(sPrintWindowId, 0, gStringVar1, 0, 0, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gStringVar2, 0, 16, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gStringVar3, 0, 32, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gRyuStringVar3, 0, 48, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gRyuStringVar3, 0, 64, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gRyuStringVar3, 0, 80, 0, NULL);

    //second batch
    StringCopy(gStringVar1, &number);
    StringCopy(gStringVar2, &number);
    StringCopy(gStringVar3, &number);
    StringCopy(gRyuStringVar1, &number);

    AddTextPrinterParameterized(sPrintWindowId, 0, gStringVar1, 0, 96, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gStringVar2, 0, 112, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gStringVar3, 0, 128, 0, NULL);
    AddTextPrinterParameterized(sPrintWindowId, 0, gRyuStringVar3, 0, 144, 0, NULL);
}



void RemoveInfoBox(void)
{
    ClearStdWindowAndFrameToTransparent(sPrintWindowId, FALSE);
    CopyWindowToVram(sPrintWindowId, 2);
    RemoveWindow(sPrintWindowId);
}

