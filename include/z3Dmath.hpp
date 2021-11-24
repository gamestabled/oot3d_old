#pragma once

#include "z3Dvec.hpp"
#include "macros.hpp"

typedef struct {
    /* 0x00 */ f32 radius;
    /* 0x04 */ f32 height;
    /* 0x08 */ f32 yShift;
    /* 0x0C */ Vec3f pos;
} Cylinderf; // size = 0x18

inline f32 Math_Vec3f_DistXZ(Vec3f* a, Vec3f* b) {
    f32 dx = b->x - a->x;
    f32 dz = b->z - a->z;

    return __sqrtf(SQ(dx) + SQ(dz));
}

inline f32 Math_Vec3f_DistXYZ(Vec3f* a, Vec3f* b) {
    f32 dx = b->x - a->x;
    f32 dy = b->y - a->y;
    f32 dz = b->z - a->z;

    return __sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
}
