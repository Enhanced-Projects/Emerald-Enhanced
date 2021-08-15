#ifndef GUARD_PIDGEY_UI_SYS_H
#define GUARD_PIDGEY_UI_SYS_H

struct PidgeyUIBGData
{
    bool8 isVisible;
    u8 palSlot;
    u8 palCount;
    const void * palette;
    const void * tilemap;
    u32 mapSize;
    const void * tiles;
    u32 tileSize;
};

struct UIData
{
    void (*returnCallback)(void);
    void (*taskFunc)(u8);
    void (*customInitFunc)(u8);
    struct PidgeyUIBGData bgData[3]; // BG 0 is used for windows
    const struct BgTemplate * bgTemplates;
    const struct WindowTemplate * windowTemplates;
};

void StartPidgeyUI(const struct UIData * uidata);
void ClosePidgeyUI(u8 taskId);

#endif//GUARD_PIDGEY_UI_SYS_H