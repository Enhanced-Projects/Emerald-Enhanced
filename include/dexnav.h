#ifndef GUARD_DEXNAV_H
#define GUARD_DEXNAV_H

///// Customizable Options
#define VAR_DEXNAV                      0x40F7   // unused variable
#define POKETOOLS_COUNT                 2
#define DEXNAV_TIMEOUT                  15  //15 seconds is the time out. Max of 1092 seconds allowed
#define SNEAKING_PROXIMITY              5   //Tile amount
#define MAX_PROXIMITY                   20
//Tile Behaviours
#define FLDEFF_CAVE_DUST    		 	67
#define FLDEFF_REPEATING_SPARKLES    	68
//#define FLDEFF_LAVA_BUBBLES             69
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
#define SEARCHLEVEL0_ITEM               0
#define SEARCHLEVEL5_ITEM               0
#define SEARCHLEVEL10_ITEM              1
#define SEARCHLEVEL25_ITEM              7
#define SEARCHLEVEL50_ITEM              6
#define SEARCHLEVEL100_ITEM             12
//Chance of encountering one star potential
#define SEARCHLEVEL0_ONESTAR            0
#define SEARCHLEVEL5_ONESTAR            14
#define SEARCHLEVEL10_ONESTAR           17
#define SEARCHLEVEL25_ONESTAR           17
#define SEARCHLEVEL50_ONESTAR           15
#define SEARCHLEVEL100_ONESTAR          8
//Chance of encountering two star potential
#define SEARCHLEVEL0_TWOSTAR            0
#define SEARCHLEVEL5_TWOSTAR            1
#define SEARCHLEVEL10_TWOSTAR           9
#define SEARCHLEVEL25_TWOSTAR           16
#define SEARCHLEVEL50_TWOSTAR           17
#define SEARCHLEVEL100_TWOSTAR          24
//Chance of encountering three star potential
#define SEARCHLEVEL0_THREESTAR          0
#define SEARCHLEVEL5_THREESTAR          0
#define SEARCHLEVEL10_THREESTAR         1
#define SEARCHLEVEL25_THREESTAR         7
#define SEARCHLEVEL50_THREESTAR         6
#define SEARCHLEVEL100_THREESTAR        12



// Structs
#define ROW_LAND 0
#define ROW_WATER 1

#define NUM_LAND_MONS           12
#define NUM_WATER_MONS          5

extern const u8 SystemScript_StartDexNavBattle[];

struct FieldEffectScript
{
	u8 command;
	bool8 (*func)(void);
};

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

#define ENCOUNTER_TYPE_LAND 0
#define ENCOUNTER_TYPE_WATER 1

#define TILE_FLAG_ENCOUNTER_TILE 1
#define TILE_FLAG_SURFABLE 2
#define TILE_FLAG_WILD_DOUBLE 4
#define TILE_FLAG_SHAKING 8


//src/dexnav.c
void ToolSelection(u8 taskId);
void FieldEff_CaveDust(void);
void FieldEff_Sparkles(void);


#endif //GUARD_DEXNAV_H