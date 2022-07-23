#ifndef GUARD_THEME_COLOR_FACTORY_H
#define GUARD_THEME_COLOR_FACTORY_H
#include "gba/types.h"

// ########### THEME DEFINITIONS #################
#define THEME_UI_MODERN             0
#define THEME_UI_CLASSIC            1
#define THEME_UI_VANILLA            2
#define THEME_UI_MAX                3

#define THEME_COLOR_LIGHT           0
#define THEME_COLOR_DARK            1
#define THEME_COLOR_USER            2
#define THEME_COLOR_VANILLA         3
#define THEME_COLOR_MAX             4

//   #### COLOR DEFINITIONS #########
//Base color decomp definitions
#define __min(a, b) (((a) < (b) ? (a) : (b)))
#define __max(a, b) (((a) >= (b) ? (a) : (b)))
#define __abs(x) (((x) < 0) ? -(x) : (x))

#define R(color) (color%32)
#define G(color) ((color>>5)%32)
#define B(color) ((color>>10)%32)

//Internal Definitions
#define GS_TO_C(grey) (grey | (grey << 5) | (grey << 10))
#define RGB_TO_C(r, g, b) (r | (g << 5) | (b << 10))
#define C_TO_GS(color) ((u16) ((R(color) * 0.3f) + (G(color) * 0.59f) + (B(color) * 0.11f)))
#define GTOB (0.59f / 0.11f)
#define GTOR (0.59f / 0.3f)
#define BTOR (0.11f / 0.3f)
#define RTOG (0.3f / 0.59f)
#define C_GTOB(color) ((u16) __min(31, G(color) * GTOB))
#define C_BTOR(color) ((u16) ((B(color) * BTOR) + __min(20, G(color) - C_GTOB(color) / GTOB * GTOR)))
#define C_RTOG(color) ((u16) (R(color) * RTOG) + __max(0, G(color) - 15))
#define COLOR_SUM(color1, color2) (RGB_TO_C(__min(31, R(color1) + (R(color2))), __min(31, G(color1) + (G(color2))), __min(31, B(color1) + (B(color2)))))
#define COLOR_SUB(color1, color2) (RGB_TO_C(__max(0, R(color1) - (R(color2))), __max(0, G(color1) - (G(color2))), __max(0, B(color1) - (B(color2)))))
#define C_CHANNEL_LOW(color) (R(color) < G(color) ? (R(color) < B(color) ? R(color):B(color)) : (G(color) < B(color)) ? G(color) : B(color))
#define C_CHANNEL_HIGH(color) (R(color) > G(color) ? (R(color) > B(color) ? R(color) : B(color)) : (G(color) > B(color)) ? (G(color)) : (B(color)))
#define C_CHANNEL_LOW_INDEX(color) (R(color) < G(color) ? (R(color) < B(color) ? 0 : 2) : (G(color) < B(color)) ? 1 : 2)
#define C_CHANNEL_HIGH_INDEX(color) (R(color) > G(color) ? (R(color) > B(color) ? 0 : 2) : (G(color) > B(color)) ? 1 : 2)
#define C_IS_GS(color) (R(color) == G(color) && R(color) == B(color) ? 1 : 0)
#define C_CLOSE_GS(color) ((C_CHANNEL_HIGH(color) - C_CHANNEL_LOW(color)) < 3 ? 1 : 0)
#define C_CHANNEL_SUM(color) (R(color) + G(color) + B(color))
#define C_CHANNEL_OR (color) (R(color) | (G(color) << 5 ) | (B(color) << 10))
#define RGB_SHIFT(color) (RGB_TO_C(B(color), R(color), G(color)))

//// EXTERNAL DEFINITIONS

// Hue Alterations
#define COLOR_TO_GREYSCALE(color) C_TO_GS(color)
#define GREYSCALE_TO_COLOR(color) GS_TO_C(color)
#define COLOR_CHANGE_HUE(color) HatColorChangeHue(color) //(C_IS_GS(color) ? ~color : RGB_SHIFT(color)) 
#define COLOR_CHANGE_HUE_KEEP_GS(color) (RGB_TO_C(C_RTOG(color), C_GTOB(color), C_BTOR(color)))
#define COLOR_PICK_HIGHER_CONTRAST(color1, color2, compareColor) HatPickHigherContrast(color1, color2, compareColor)
// Shade Alterations
/*
COLOR_AUTO_SHADE(colorToShade, thresholdShadeToDarkOrLight)
eg COLOR_AUTO_SHADE(0x3e0, THRESHOLD_LOW)

COLOR_AUTO_SHADE_INVERSE is like AUTO_SHADE but turns dark color to darker and light color to lighter
eg COLOR_AUTO_SHADE_INVERSE(save->UserColor[USER_COLOR_BG], THRESHOLD_LOW)

COLOR_AUTO_SHADE_COND(             
    colorToShade, 
    compareValue1,                         // compare term1, needs to be lower than 2 to proceed with the action
    compareValue2,                         // compare term2
    actionToDoIfComparisonIsSuccessfull,   //Used if comparison is successful
    thresholdShadeToDarkOrLight            //Used if action is auto or autoInverse
)--- If compareValue1 is smaller than compareValue2 do action else nothing ---
eg COLOR_AUTO_SHADE_COND(
    save->UserColor[USER_COLOR_TEXT], 
    save->UserColor[USER_COLOR_BG], 
    10, 
    SHADE_ACTION_AUTO,
    THRESHOLD_LOW
)
*/
#define COLOR_PICK_LIGHT(color1, color2) (C_TO_GS(color1) > C_TO_GS(color2) ? color1 : color2)
#define COLOR_PICK_LIGHT3(color1, color2, color3) (COLOR_PICK_LIGHT(COLOR_PICK_LIGHT(color1, color2), color3))
#define COLOR_PICK_DARK(color1, color2) (C_TO_GS(color1) < C_TO_GS(color2) ? color1 : color2)
#define COLOR_PICK_DARK3(color1, color2, color3) (COLOR_PICK_DARK(COLOR_PICK_DARK(color1, color2), color3))
#define COLOR_CHANGE_SHADE_AVG(color) (C_CHANNEL_SUM(color) > 46 ? (COLOR_SUB(color, GS_TO_C((C_CHANNEL_LOW(color) / 2 + 16)))) : (COLOR_SUM(color, GS_TO_C((C_CHANNEL_LOW(color) / 2 + 16)))))
#define COLOR_CREATE_DARK_SHADE(color) (COLOR_SUB(color,GS_TO_C((1 + C_CHANNEL_HIGH(color) / 6 + C_CHANNEL_HIGH(color) / 10))))
#define COLOR_CREATE_LIGHT_SHADE(color) (COLOR_SUM(color, GS_TO_C((C_CHANNEL_HIGH(color) / 2 + C_CHANNEL_HIGH(color) / 8 + (C_CLOSE_GS(color) ? 0 : 32 - C_CHANNEL_HIGH(color)) / 3))))
#define COLOR_CREATE_LIGHT_SHADE_STEP(color, step) (COLOR_SUM(color, GS_TO_C((1 + step))))
#define COLOR_CREATE_DARK_SHADE_STEP(color, step) (COLOR_SUB(color, GS_TO_C((1 + step))))

#define COLOR_AUTO_SHADE(color, threshold) HatAutoShade(color, threshold)
#define COLOR_AUTO_SHADE_INVERSE(color, threshold) HatAutoShadeInverse(color, threshold)
#define COLOR_AUTO_SHADE_COND(colorToShade, compareColor1, compareColor2, action, threshold) HatAutoShadeCond(colorToShade, compareColor1, compareColor2, action, threshold)
#define COLOR_AUTO_SHADE_CONTRAST(colorToShade, compareColor, threshold) HatAutoShadeContrast(colorToShade, compareColor, threshold)
#define COLOR_AUTO_SHADE_CONTRAST_INVERSE(colorToShade, compareColor, threshold) HatAutoShadeContrastInverse(colorToShade, compareColor, threshold)
// used to get same shading action as someone else, to be used with AUTO_SHADE_COND
// eg COLOR_AUTO_SHADE_COND(colorToShade, COMPARE_SKIP_COLOR_1, COMPARE_SKIP_COLOR_2, COLOR_GET_AS_CONTRAST_ACTION(otherColor, otherCompareColor, otherThreshold), otherThreshold)
#define COLOR_GET_AS_CONTRAST_ACTION(colorToShade, compareColor, threshold) (abs(C_TO_GS(colorToShade) - C_TO_GS(compareColor)) < threshold ? (C_TO_GS(colorToShade) - C_TO_GS(compareColor) > 0 ? SHADE_ACTION_LIGHT : SHADE_ACTION_DARK) : SHADE_ACTION_NONE)
#define COLOR_GET_AS_CONTRAST_INVERSE_ACTION(colorToShade, compareColor, threshold) (abs(C_TO_GS(colorToShade) - C_TO_GS(compareColor)) < threshold ? (C_TO_GS(colorToShade) - C_TO_GS(compareColor) > 0 ? SHADE_ACTION_DARK : SHADE_ACTION_LIGHT) : SHADE_ACTION_NONE)
#define COLOR_SHADES(srcColor, func, dest, size, stepLimit) HatGenerateShades(srcColor, func, dest, size, stepLimit)


//// Value Naming

// AUTO_SHADE Threshold 
#define THRESHOLD_LOW                   5
#define THRESHOLD_DEFAULT               10
#define THRESHOLD_MEDIUM                15
#define THRESHOLD_HIGH                  20
#define THRESHOLD_MAX                   25

// AUTO_SHADE_COND Comparison Skip
#define COMPARE_SKIP_COLOR_1            0x0
#define COMPARE_SKIP_COLOR_2            0xFFFF

// Action
#define SHADE_ACTION_NONE               -1
#define SHADE_ACTION_AUTO               0
#define SHADE_ACTION_AUTO_INVERSE       1
#define SHADE_ACTION_LIGHT              2
#define SHADE_ACTION_DARK               3

// Functions
#define SHADER_LIGHT                    0
#define SHADER_DARK                     1


// User Colors
#define USER_COLOR_UNUSED0              0 // 
#define USER_COLOR_BG                   1 // X USER_COLOR window background
#define USER_COLOR_TEXT                 2 // X USER_COLOR text
#define USER_COLOR_TEXT_SHADOW          3 // X USER_COLOR text shadow
#define USER_COLOR_UNUSED1              4 // very dark red
#define USER_COLOR_UNUSED2              5 // pink
#define USER_COLOR_UNUSED3              6 // dark pale green
#define USER_COLOR_UNUSED4              7 // pale green 
#define USER_COLOR_UNUSED5              8 //
#define USER_COLOR_UNUSED6              9  // grey
#define USER_COLOR_UNUSED7              10 // white
#define USER_COLOR_UNUSED8              11 // yellow
#define USER_COLOR_UNUSED9              12 //
#define USER_COLOR_BORDER               13 // X USER_COLOR window border
#define USER_COLOR_HIGHLIGHT            14 // X USER_COLOR window highlight
#define USER_COLOR_UNUSED10             15 // turquoise


#define COLOR_BAG_BG_MALE                   0x7DE8
#define COLOR_BAG_BG_SHADOW_MALE            0x3524
#define COLOR_BAG_BG_FEMALE                 0x7D99
#define COLOR_BAG_BG_SHADOW_FEMALE          0x4186
#define COLOR_BAG_POCKET_SELECTED           0x2A56
#define COLOR_BAG_POCKET_UNSELECTED         0x437F

#define COLOR_LIGHT_THEME_BG_DARK           0x1C82
#define COLOR_LIGHT_THEME_BG                0x6AF7
#define COLOR_LIGHT_THEME_BG_LIGHT          0x7FFF
#define COLOR_LIGHT_THEME_TEXT              0x0000
#define COLOR_LIGHT_THEME_TEXT_SHADOW       0x5AD6
#define COLOR_LIGHT_THEME_TEXT_SHADOW_N     0x7E7A
#define COLOR_LIGHT_THEME_CONTRAST          0x3546
#define COLOR_NEON_BORDER_1                 0x7EA2
#define COLOR_NEON_BORDER_2                 0x698C
#define COLOR_NEON_BORDER_3                 0x6B2A

#define COLOR_DARK_THEME_BG_LIGHT           0x842
#define COLOR_DARK_THEME_TEXT               0x6B5A
#define COLOR_DARK_THEME_TEXT_SHADOW        0x39CE


#define COLOR_SPECIES_TEXT_DARK             0x739C
#define COLOR_SPECIES_TEXT_DARK_SHADOW      0x318C

#define COLOR_SPECIES_TEXT_LIGHT            0x2108
#define COLOR_SPECIES_TEXT_LIGHT_SHADOW     0x5EF7

#define BAG_COLOR_BOTTOM_BACKGROUND_SHADOW  7
#define BAG_COLOR_BOTTOM_BACKGROUND         12
#define BAG_COLOR_POCKET_SELECTED           10
#define BAG_COLOR_POCKET_UNSLECTED          14

#define COLOR_WHITE                         0x7FFF
#define COLOR_BLACK                         0x0
#define COLOR_RED                           0x1F
#define COLOR_GREEN                         0x3E0
#define COLOR_BLUE                          0x7C00
#define COLOR_DARK_RED                      0xE
#define COLOR_DARK_GREY                     0x2108
#define COLOR_LIGHT_GREY                    0x6739
#define COLOR_LIGHT_GREY_1                  0x5294

// Wrapper Functions
// need a func to prevent buffer overflow -> compiler segfault
u16 HatColorChangeHue(u16 color);
u16 HatPickHigherContrast(u16 color1, u16 color2, u16 compareColor);
u16 HatAutoShade(u16 color, u16 threshold);
u16 HatAutoShadeInverse(u16 color, u16 threshold);
u16 HatAutoShadeContrast(u16 colorToShade, u16 compareColor, u16 threshold);
u16 HatAutoShadeContrastInverse(u16 colorToShade, u16 compareColor, u16 threshold);
u16 HatAutoShadeCond(u16 colorToShade, u16 compareColor1, u16 compareColor2, s16 action, u16 threshold);
void HatGenerateShades(u16 srcColor, u16 func, u16* dest, u16 size, u16 stepLimit);
#endif