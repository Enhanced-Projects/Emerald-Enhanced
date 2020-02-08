#ifndef GUARD_DEXNAV_H
#define GUARD_DEXNAV_H

#define POKETOOLS_COUNT 2

#define ROW_LAND 0
#define ROW_WATER 1

// Structs
#define NUM_LAND_MONS           12
#define NUM_WATER_MONS          5
struct DexnavHudData
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 moveId[MAX_MON_MOVES];
    /*0x0A*/ u16 heldItem;
    /*0x0C*/ u8 ability;
    /*0x0D*/ u8 potential;
    /*0x0E*/ u8 searchLevel;
    /*0x0F*/ u8 pokemonLevel;
    /*0x10*/ u8 moveNameLength;
    /*0x11*/ u8 proximity;
    /*0x12*/ u8 environment;
	/*0x13*/ u8 unownLetter;
    /*0x14*/ s16 tileX; // position of shaking grass
    /*0x16*/ s16 tileY;
    /*0x18*/ u8 objIdSpecies;
    /*0x19*/ u8 objIdBlackBar[4];
    /*0x1D*/ u8 objIdSight;
    /*0x1E*/ u8 objIdAbility;
    /*0x1F*/ u8 objIdMove;
    /*0x20*/ u8 objIdItem;
    /*0x21*/ u8 objIdShakingGrass;
    /*0x22*/ u8 objIdPotential[3];
    /*0x25*/ u8 movementTimes;
// GUI data
    /*0x26*/ u16 grassSpecies[NUM_LAND_MONS];
    /*0x3E*/ u16 waterSpecies[NUM_WATER_MONS];
	/*0x48*/ u16 hiddenSpecies[NUM_LAND_MONS + 1];
	/*0x62*/ u8 unownForms[NUM_LAND_MONS];
	/*0x6E*/ u8 unownFormsByDNavIndices[NUM_LAND_MONS];
	/*0x7A*/ u8 numGrassMons;
	/*0x7B*/ u8 numWaterMons;
	/*0x7C*/ u8 numHiddenLandMons;
	/*0x7D*/ u8 numHiddenWaterMons;
    /*0x7E*/ u8 cursorId;
    /*0x7F*/ u8 objids[17];
    /*0x90*/ u8 selectedIndex;
    /*0x91*/ u8 selectedArr;
    /*0x92*/ u8 abilityNum;
    /*0x94*/ void* backBuffer;
}; /* size = 0x98 */

extern const u8 SystemScript_StartDexNavBattle[];

// DEFINES
#define DEXNAV_TIMEOUT              15  //15 seconds is the time out. Max of 1092 seconds allowed
#define SNEAKING_PROXIMITY          5   //Tile amount

//Chance of encountering egg move at search levels
#define SEARCHLEVEL0_MOVECHANCE         0
#define SEARCHLEVEL5_MOVECHANCE         21
#define SEARCHLEVEL10_MOVECHANCE        46
#define SEARCHLEVEL25_MOVECHANCE        58
#define SEARCHLEVEL50_MOVECHANCE        63
#define SEARCHLEVEL100_MOVECHANCE       83

//Chance of encountering Hidden Abilities at search levels
#define SEARCHLEVEL0_ABILITYCHANCE      0
#define SEARCHLEVEL5_ABILITYCHANCE      0
#define SEARCHLEVEL10_ABILITYCHANCE     5
#define SEARCHLEVEL25_ABILITYCHANCE     15
#define SEARCHLEVEL50_ABILITYCHANCE     20
#define SEARCHLEVEL100_ABILITYCHANCE    23

//Chance of encountering held item
#define SEARCHLEVEL0_ITEM           0
#define SEARCHLEVEL5_ITEM           0
#define SEARCHLEVEL10_ITEM          1
#define SEARCHLEVEL25_ITEM          7
#define SEARCHLEVEL50_ITEM          6
#define SEARCHLEVEL100_ITEM         12

//Chance of encountering one star potential
#define SEARCHLEVEL0_ONESTAR        0
#define SEARCHLEVEL5_ONESTAR        14
#define SEARCHLEVEL10_ONESTAR       17
#define SEARCHLEVEL25_ONESTAR       17
#define SEARCHLEVEL50_ONESTAR       15
#define SEARCHLEVEL100_ONESTAR      8

//Chance of encountering two star potential
#define SEARCHLEVEL0_TWOSTAR        0
#define SEARCHLEVEL5_TWOSTAR        1
#define SEARCHLEVEL10_TWOSTAR       9
#define SEARCHLEVEL25_TWOSTAR       16
#define SEARCHLEVEL50_TWOSTAR       17
#define SEARCHLEVEL100_TWOSTAR      24

//Chance of encountering three star potential
#define SEARCHLEVEL0_THREESTAR      0
#define SEARCHLEVEL5_THREESTAR      0
#define SEARCHLEVEL10_THREESTAR     1
#define SEARCHLEVEL25_THREESTAR     7
#define SEARCHLEVEL50_THREESTAR     6
#define SEARCHLEVEL100_THREESTAR    12

#define SCANSTART_X             0
#define SCANSTART_Y             0
#define SCANSIZE_X              12
#define SCANSIZE_Y              12

// tags
#define ICON_PAL_TAG            56000
#define ICON_GFX_TAG            55130
#define SELECTION_CURSOR_TAG    512
#define SMOKE_TAG               10000
#define CAPTURED_ALL_TAG        55160        // shared by TAG_MEGA_INDICATOR_TILE

#define ICONX                   16
#define ICONY                   146

#define CPUFSSET 1
#define CPUModeFS(size, mode) ((size >> 2) | (mode << 24))

#define SPECIES_TABLES_TERMIN 0xFEFE

//src/dexnav.c
void ToolSelection(u8 taskId);
void InitDexNavHUD(u16 species, u8 environment);


#endif //GUARD_DEXNAV_H