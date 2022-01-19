#include "global.h"
#include "constants/general.h"
#include "constants/rgb.h"
#include "event_data.h"

//PRESET THEMES

const u16 BlueSteelRGBTheme[16][3] = {
    {14, 25, 20},
    {3, 3, 2},
    {0, 20, 31},
    {0, 0, 0},
    {15, 2, 9},
    {31, 22, 28},
    {4, 19, 1},
    {18, 30, 18},
    {5, 9, 23},
    {25, 27, 30},
    {31, 31, 31},
    {3, 3, 3},
    {3, 3, 3},
    {22, 22, 22},
    {10, 10, 10},
    {9, 14, 20},
};

const u16 RoyalPurpleRGBTheme[16][3] = {
    {14, 25, 20},
    {3, 3, 2},
    {18, 0, 20},
    {9, 0, 12},
    {15, 2, 9},
    {31, 22, 28},
    {4, 19, 1},
    {18, 30, 18},
    {5, 9, 23},
    {25, 27, 30},
    {31, 31, 31},
    {3, 3, 3},
    {3, 3, 3},
    {15, 0, 20},
    {10, 0, 10},
    {9, 14, 20}
};

const u16 CustomInterfacePaletteSlots[] = {
    2, //standard text color
    3, //standard text shadow
    14, //textbox decorative highlight
    13, //textbox decorative frame
    1, //textbox and text background color
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
    switch (index)
    {
        case 0:
            for(i = 0;i < ARRAY_COUNT(gSaveBlock2Ptr->userInterfaceTextboxPalette); i++)
                {
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[i] = RGB((BlueSteelRGBTheme[i][0]), (BlueSteelRGBTheme[i][1]), (BlueSteelRGBTheme[i][2]));
                    break;
                }
        case 1:
            for(i = 0;i < ARRAY_COUNT(gSaveBlock2Ptr->userInterfaceTextboxPalette); i++)
                {
                    gSaveBlock2Ptr->userInterfaceTextboxPalette[i] = RGB((RoyalPurpleRGBTheme[i][0]), (RoyalPurpleRGBTheme[i][1]), (RoyalPurpleRGBTheme[i][2]));
                    break;
                }
    }
}
