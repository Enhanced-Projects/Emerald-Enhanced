#include "theme_color_factory.h"

//FULL_COLOR
u16 HatColorChangeHue(u16 color) {
    return C_CLOSE_GS(color) ? ((C_TO_GS(color) > 0x4 && C_TO_GS(color) < 0xB) ? (C_TO_GS(color) > 0x6 ? 0x1 : 0xD ) : (~color)) : (RGB_SHIFT(color));
}

u16 HatAutoShade(u16 color, u16 threshold) { 
    return (COLOR_TO_GREYSCALE(color) < threshold) ? (COLOR_CREATE_LIGHT_SHADE(color)) :(COLOR_CREATE_DARK_SHADE(color)); 
}

u16 HatAutoShadeInverse(u16 color, u16 threshold) { 
    return COLOR_TO_GREYSCALE(color) < threshold ? COLOR_CREATE_DARK_SHADE(color) : COLOR_CREATE_LIGHT_SHADE(color); 
}

u16 HatAutoShadeContrast(u16 colorToShade, u16 compareColor, u16 threshold) {
    return abs(C_TO_GS(colorToShade) - C_TO_GS(compareColor)) < threshold ? (C_TO_GS(colorToShade) - C_TO_GS(compareColor) > 0 ? COLOR_CREATE_LIGHT_SHADE(colorToShade) : COLOR_CREATE_DARK_SHADE(colorToShade)) : colorToShade;
}

u16 HatAutoShadeContrastInverse(u16 colorToShade, u16 compareColor, u16 threshold) {
    return abs(C_TO_GS(colorToShade) - C_TO_GS(compareColor)) < threshold ? (C_TO_GS(colorToShade) - C_TO_GS(compareColor) > 0 ? COLOR_CREATE_DARK_SHADE(colorToShade) : COLOR_CREATE_LIGHT_SHADE(colorToShade)) : colorToShade;
}

u16 HatAutoShadeCond(u16 colorToShade, u16 compareColor1, u16 compareColor2, s16 action, u16 threshold) {
    return C_TO_GS(compareColor1) < C_TO_GS(compareColor2) ? (SHADE_ACTION_AUTO == action ? COLOR_AUTO_SHADE(colorToShade, threshold) : SHADE_ACTION_AUTO_INVERSE == action ? COLOR_AUTO_SHADE_INVERSE(colorToShade, threshold) : SHADE_ACTION_LIGHT == action ? COLOR_CREATE_LIGHT_SHADE(colorToShade) : SHADE_ACTION_DARK == action ? COLOR_CREATE_DARK_SHADE(colorToShade) : colorToShade) : colorToShade;
}

u16 HatPickHigherContrast(u16 color1, u16 color2, u16 compareColor) {
    return __abs(C_TO_GS(color1) - C_TO_GS(compareColor)) > __abs(C_TO_GS(color2) - C_TO_GS(compareColor)) ? color1 : color2;
}

u16 HatPickLowerContrast(u16 color1, u16 color2, u16 compareColor) {
    return __abs(C_TO_GS(color1) - C_TO_GS(compareColor)) > __abs(C_TO_GS(color2) - C_TO_GS(compareColor)) ? color2 : color1;
}

void LightShader(u16* color, u16 step) {
    *color = COLOR_CREATE_LIGHT_SHADE_STEP(*color, step);
}

void DarkShader(u16* color, u16 step) {
    *color = COLOR_CREATE_DARK_SHADE_STEP(*color, step);
}

void (*ShaderFunctions[])(u16* color, u16 number) = {
    &LightShader,
    &DarkShader
};

//ver1
void HatGenerateShades(u16 srcColor, u16 func, u16* dest, u16 size, u16 stepLimit) {
    u32 i, step = 0;
    u16 current = srcColor, prev = srcColor;
    stepLimit = __max(stepLimit, size);
    for (i = 0; i < size; i++) {
        ShaderFunctions[func](&current, 1 + i * stepLimit / size);
        if (current == prev) {
            current ^= 0x10 << (5 * ((C_CHANNEL_HIGH_INDEX(srcColor) + step++) % 3));
        }
        *(dest++) = current;
    }
}
//ver0
/*
void HatGenerateShades(u16 srcColor, u16 func, u16* dest, s16* endOffset, u16 size, u16 stepLimit) {
    u32 i, step;
    u16 current = srcColor, prev = srcColor;
    stepLimit = __max(stepLimit, size);
    for (i = 0; i < size; i++) {
        switch (func) {
            case SHADER_LIGHT:
                step = i;
                break;
            case SHADER_DARK:
                current = srcColor;
                step = size - i - 1;
                break;
            default:
                break;
        }
        ShaderFunctions[func](&current, 1 + step * stepLimit / size);
        if (current == 0x0 && prev == 0x0)
            continue;
        else if (current == prev)
            break;
        prev = current;
        *(dest++) = current;
    }
    *endOffset = i;
}*/