#pragma once

#include "z3Dvec.hpp"

typedef struct {
    /* 0x00 */ char unk_00[0x2];
    /* 0x02 */ s16 ySurface;
} WaterBox;

typedef struct {
    /* 0x00 */ char unk_00[0x28];
    /* 0x28 */ WaterBox* waterBoxes;
} CollisionHeader;

void ReadCollisionHeaderFromZsi(void* arg1, CollisionHeader** col);
