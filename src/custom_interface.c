#include "global.h"
#include "constants/general.h"
#include "constants/rgb.h"
#include "event_data.h"

//PRESET THEMES

const u16 BlueSteelRGBTheme[16] = {
    RGB(14, 25, 20),
    RGB(3, 3, 2),
    RGB(0, 20, 31),
    RGB(0, 0, 0),
    RGB(15, 2, 9),
    RGB(31, 22, 28),
    RGB(4, 19, 1),
    RGB(18, 30, 18),
    RGB(5, 9, 23),
    RGB(25, 27, 30),
    RGB(31, 31, 31),
    RGB(3, 3, 3),
    RGB(3, 3, 3),
    RGB(22, 22, 22),
    RGB(10, 10, 10),
    RGB(9, 14, 20),
};

const u16 RoyalPurpleRGBTheme[16] = {
    RGB(14, 25, 20),
    RGB(3, 3, 2),
    RGB(18, 0, 20),
    RGB(9, 0, 12),
    RGB(15, 2, 9),
    RGB(31, 22, 28),
    RGB(4, 19, 1),
    RGB(18, 30, 18),
    RGB(5, 9, 23),
    RGB(25, 27, 30),
    RGB(31, 31, 31),
    RGB(3, 3, 3),
    RGB(3, 3, 3),
    RGB(15, 0, 20),
    RGB(10, 0, 10),
    RGB(9, 14, 20)
};

const u16 CustomInterfacePaletteSlots[] = {
    2, //standard text color
    3, //standard text shadow
    14, //textbox decorative highlight
    13, //textbox decorative frame
    1, //textbox and text background color
};

const u16 *UserPresetThemes[] = {
    BlueSteelRGBTheme,
    RoyalPurpleRGBTheme,
};

void SetUserRGBValue(void)
{
    u8 mode = CustomInterfacePaletteSlots[gSpecialVar_0x8004];
    u8 redValue = gSpecialVar_0x8001;
    u8 greenValue = gSpecialVar_0x8002;
    u8 blueValue = gSpecialVar_0x8003;

    gSaveBlock2Ptr->userInterfaceTextboxPalette[mode] = RGB(redValue, greenValue, blueValue);

    if (gSpecialVar_0x8004 == USER_COLOR_WINDOW_BACKGROUND) //have to also set the text highlight color to match.
    {
        gSaveBlock2Ptr->userInterfaceTextboxPalette[11] = RGB(redValue, greenValue, blueValue);
        gSaveBlock2Ptr->userInterfaceTextboxPalette[12] = RGB(redValue, greenValue, blueValue);
        gSaveBlock2Ptr->userInterfaceTextboxPalette[1] = RGB(redValue, greenValue, blueValue);
    }

}

void printThemeColors (void)
{
    u32 i;
    u16 r;
    u16 g;
    u16 b;
    for (i = 0; i < 16;i++)
    {
        r = (GET_R(gSaveBlock2Ptr->userInterfaceTextboxPalette[i]));
        g = (GET_G(gSaveBlock2Ptr->userInterfaceTextboxPalette[i]));
        b = (GET_B(gSaveBlock2Ptr->userInterfaceTextboxPalette[i]));
        mgba_printf(LOGINFO, "index %d, RGB Colors: (%d, %d, %d)", i, r, g, b);
    }
}

void ApplyPresetRGBUserTheme (void)
{
    u32 index = gSpecialVar_0x8001;
    u32 i;
    for(i = 0;i < ARRAY_COUNT(gSaveBlock2Ptr->userInterfaceTextboxPalette); i++)
        gSaveBlock2Ptr->userInterfaceTextboxPalette[i] = UserPresetThemes[index][i];
}
