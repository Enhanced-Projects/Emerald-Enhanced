static const u16 sRange[9][2] = {//Trainer level ranges
    {11,16},
    {17,22},
    {23,28},
    {29,34},
    {35,40},
    {42,49},
    {50,57}, 
    {58,65},
    {66,72},
};

static const u16 sGymRange[9][2] = {//Gym Leader level ranges
    {14,19},
    {20,24},
    {25,33},
    {34,39},
    {40,45},
    {50,54},
    {55,62}, 
    {69,76},
    {77,84},
};

static const u16 sWildRange[9][2] = {//Wild level ranges
    {5,10},
    {10,20},
    {19,29},
    {28,35},
    {36,41},
    {40,45},
    {44,49},
    {48,53},
    {52,60},
};

enum
{
    SCALING_TYPE_WILD,
    SCALING_TYPE_TRAINER,
    SCALING_TYPE_BOSS,
};

// Final levels will be player party average + the adjustment here + Random() % 5
static const s16 sAutoscalingAdjustments[3] = {
    [SCALING_TYPE_WILD] = -8,
    [SCALING_TYPE_TRAINER] = -5,
    [SCALING_TYPE_BOSS] = 0, // E4, gym leaders, etc.
};
