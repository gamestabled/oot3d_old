#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "z3D.hpp"

extern SaveContext gSaveContext; //0x00587958

extern f32 FLOAT_0054ac20;
extern s8 DAT_0054ac24;

extern u32 gBitFlags[32];
extern u16 gEquipMasks[4];
extern u16 gEquipNegMasks[4];
extern u32 gUpgradeMasks[8];
extern u32 gUpgradeNegMasks[8];
extern u8 gEquipShifts[4];
extern u8 gUpgradeShifts[8];
extern u16 gUpgradeCapacities[8][4];
extern u32 gGsFlagsMask[4];
extern u32 gGsFlagsShift[4];
extern u8 gItemSlots[56];

extern GameInfo* gGameInfo;

#endif
