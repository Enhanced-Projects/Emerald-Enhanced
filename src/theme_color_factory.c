#include "theme_color_factory.h"
#include "event_data.h"

//FULL_COLOR
u16 HatColorChangeHue(u16 color) {
    return C_CLOSE_GS(color) ? ((C_TO_GS(color) > 0x4 && C_TO_GS(color) < 0xB) ? (C_TO_GS(color) > 0x6 ? 0x1 : 0xD ) : (~color)) : (RGB_SHIFT(color));
}

u16 HatCreateLightShade(u16 color) {
    return (COLOR_SUM(color, GS_TO_C((C_CHANNEL_HIGH(color) / 2 + C_CHANNEL_HIGH(color) / 8 + (C_CLOSE_GS(color) ? 0 : 32 - C_CHANNEL_HIGH(color)) / 3))));
}

u16 HatCreateDarkShade(u16 color) {
    return (COLOR_SUB(color,GS_TO_C((1 + C_CHANNEL_HIGH(color) / 6 + C_CHANNEL_HIGH(color) / 10))));
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

void (*const ShaderFunctions[])(u16* color, u16 number) = {
    &LightShader,
    &DarkShader
};

static u16 sqrtU16(u16 sqrtArg)
{
    u16 Root = 0;
    u16 Bit, Trial;
    for ( Bit = 0x4000; Bit > 0; Bit >>= 2 )
    {
        Trial = Root + Bit;
        Root >>= 1;
        if ( Trial <= sqrtArg )
        {
            Root += Bit;
            sqrtArg -= Trial;
        }
    }
    return Root;
}

#define cos(a) (a)
//ver0
/*
u16 HatRGBtoHSV(u16 srcColor) {
    u8 R, G, B, M, m, delta, V, S, H;
    R = R(srcColor);
    G = G(srcColor);
    B = B(srcColor);
    M = C_CHANNEL_HIGH(srcColor);
    m = C_CHANNEL_LOW(srcColor);
    delta = (R(srcColor) - G(srcColor) / 2 - B(srcColor) / 2);
    delta /= sqrtU16(R * R + G * G + B * B - R * G - R * B - G * B);
    V = M;
    S = M == 0 ? 0 : 31 - (m * 31 / M);
    H = G(srcColor) >= B(srcColor) ? 31 / (cos(delta)) : 31 - 31 / (cos(delta));
    return (H | (S << 5) | (V << 10));
}

u16 HatHSVtoRGB(u16 srcColor) {
    u8 R, G, B, M, m, delta, V, S, H;
    H = H(srcColor);
    S = S(srcColor);
    V = V(srcColor);
    M = V;
    m = M * (31 - S);

}*/


//ver1
struct HSVColor HatRGBtoHSV(u16 srcColor)
{
    u8 r, g, b, cmax, cmin, diff;
    u16 h, s, v;
    struct HSVColor hsv;
    // R, G, B values are divided by 255
    // to change the range from 0..255 to 0..1
    
    r = R(srcColor);
    g = G(srcColor);
    b = B(srcColor);
 
    // h, s, v = hue, saturation, value
    cmax = C_CHANNEL_HIGH(srcColor); // maximum of r, g, b
    cmin = C_CHANNEL_LOW(srcColor); // minimum of r, g, b
    diff = cmax - cmin; // diff of cmax and cmin.
 
    // if cmax and cmax are equal then h = 0
    if (cmax == cmin)
        h = 0;
 
    // if cmax equal r then compute h
    else if (cmax == r)
        h = ((6 * (100 * (g - b) / diff)) / 10 + 360) % 360;
 
    // if cmax equal g then compute h
    else if (cmax == g)
        h = ((6 * (100 * (b - r) / diff)) /10 + 120) % 360;
 
    // if cmax equal b then compute h
    else if (cmax == b)
        h = ((6 * (100 * (r - g) / diff)) / 10  + 240) % 360;
 
    // if cmax equal zero
    if (cmax == 0)
        s = 0;
    else
        s = (diff * 100 / cmax);
 
    // compute v
    v = cmax * 100 / 31;
    hsv.h = h;
    hsv.s = s;
    hsv.v = v;
    return hsv;
}

u16 HatHSVtoRGB(struct HSVColor hsv)
{
    u32 c, x, m, r, g, b;
    c = hsv.v * hsv.s;
    x = c * (100 - __abs((hsv.h * 100 / 60) % 200 - 100)) / 100;
    m = hsv.v * 100 - c;
    switch (hsv.h / 60) {
        case 0:
            r = c;
            g = x;
            b = 0;
            break;
        case 1:
            r = x;
            g = c;
            b = 0;
            break;
        case 2:
            r = 0;
            g = c;
            b = x;
            break;
        case 3:
            r = 0;
            g = x;
            b = c;
            break;
        case 4:
            r = x;
            g = 0;
            b = c;
            break;
        case 5:
            r = c;
            g = 0;
            b = x;
            break;
    }

    r = (r + m) * 31 / 10000;
    g = (g + m) * 31 / 10000;
    b = (b + m) * 31 / 10000;

    return r | (g << 5) | (b << 10);
}

u16 HatColorRotateHue(u16 srcColor, s16 rotation) {
    struct HSVColor hsv;
    hsv = HatRGBtoHSV(srcColor);
    hsv.h = __max(0, (hsv.h + rotation)) % 360;
    return HatHSVtoRGB(hsv);
}

u16 HatColorChangeSaturation(u16 srcColor, s16 deltaSaturation) {
    struct HSVColor hsv;
    hsv = HatRGBtoHSV(srcColor);
    hsv.s = __clamp(hsv.s + deltaSaturation, 0, 100);
    return HatHSVtoRGB(hsv);
}

u16 HatColorChangeIntensity(u16 srcColor, s16 deltaIntensity) {
    struct HSVColor hsv;
    hsv = HatRGBtoHSV(srcColor);
    hsv.v = __clamp(hsv.s + deltaIntensity, 0, 100);
    return HatHSVtoRGB(hsv);
}

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

u16 (*const HatHSVColorFunctions[])(u16 srcColor, s16 val) = {
    HatColorRotateHue,
    HatColorChangeSaturation,
    //HatColorChangeSaturation//HatColorChangeIntensity
};

#define INFO_COLOR_FUNCTION         0
#define INFO_COLOR_HSV_FUNCTION     1

#define INFO_VALUE_HSV_START        8
#define INFO_VALUE_H                8
#define INFO_VALUE_S                9
#define INFO_VALUE_V                10

#define INFO_HSV_FUNC_ROTATE_H            0
#define INFO_HSV_FUNC_CHANGE_S            1
#define INFO_HSV_FUNC_CHANGE_V            2

s8 GetInfoFromSeed(u8 info, u32 seed) {
    switch (info) {
        case INFO_COLOR_HSV_FUNCTION:
            return (seed ^ (seed >> (info % 8))) % 2;
        
        case INFO_VALUE_H:
            return (seed ^ (seed >> (info % 16))) % 360;
            
        case INFO_VALUE_S:
        case INFO_VALUE_V:
            return (seed ^ (seed >> (info % 16))) % 100 - 50;
            
        default:
            return seed % 3;
    }
}

void HatMakeNewPaletteFromTemplate(u16* palette, u16 size, u32 seed) {
    u32 i;
    u8 func;

    if (!FlagGet(0x40FF)) //FLAG_HAT_TEST_MODE
        return;
    for (i = 0; i < size; ++i) {
        func = GetInfoFromSeed(INFO_COLOR_HSV_FUNCTION, seed);
        if (func == INFO_HSV_FUNC_ROTATE_H && GetInfoFromSeed(0, seed)) {
            palette[i] = HatHSVColorFunctions[INFO_HSV_FUNC_CHANGE_S](palette[i], GetInfoFromSeed(INFO_VALUE_S, seed));
        }
        palette[i] = HatHSVColorFunctions[GetInfoFromSeed(INFO_COLOR_HSV_FUNCTION, seed)](palette[i], GetInfoFromSeed(func + INFO_VALUE_HSV_START, seed));
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