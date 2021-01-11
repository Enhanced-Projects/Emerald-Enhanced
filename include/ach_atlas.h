#ifndef GUARD_ACH_ATLAS_H
#define GUARD_ACH_ATLAS_H

enum
{
    CATEGORY_EXPLORATION,  //dark_grey/light_grey. also for misc achievements
    CATEGORY_BATTLE,       //light_red/red
    CATEGORY_COMPANIONS,   //light_blue/blue
    CATEGORY_QUESTING      //light_green/green
};

enum
{
    ACTION_NONE,
    ACTION_MOVE_LEFT,
    ACTION_MOVE_RIGHT,
    ACTION_MOVE_UP,
    ACTION_MOVE_DOWN,
    ACTION_DISPLAY_DESC,
    ACTION_GO_BACK
};

struct AtlasAchPointData
{
    u8 x;
    u8 y;
    u8 category;
    u8 flagId;
    const u8 * nameString;
    const u8 * descString;
};

struct AchAtlas // this would be better off as a u8 array lmao
{
    u8 cursorSpriteId;
    s8 cursorX;
    s8 cursorY;
    s8 cursorHeldCounter;
    s8 tilemapPosX;
    s8 tilemapPosY;
    bool8 shouldUpdateTilemap;
    bool8 isOnAchTile;
};

#define WAIT_FAST_SCROLL 60
#define WAIT_SLOW_SCROLL 15

#define ACH_ATLAS_WIDTH 64
#define ACH_ATLAS_HEIGHT 64

#define TILEMAP_START_X 21 
#define TILEMAP_START_Y 27

#define MAXIMUM_AP 100 //this is probably never going to change, but people like constants so it's whatever.

void CB2_OpenAtlas(void);

void GiveAchievement(u32 id);
void GiveAchievementDebug(u32 id);
bool32 CheckAchievement(u32 id);
void TakeAchievement(u32 id);

//AP internal
void SetAPFlag(u32 id);
bool32 CheckAPFlag(u32 id);
void ClearAPFlag(u32 id);
int GetPlayerAPMax(void);
int GetCurrentAPUsed(void);


//AP utility
bool8 CheckCanIgnoreTrainers();

#endif//GUARD_ACH_ATLAS_H