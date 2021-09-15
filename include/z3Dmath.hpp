#ifndef _Z_MATH_H_
#define _Z_MATH_H_

#include "z3Dvec.hpp"

typedef struct {
    /* 0x00 */ f32 radius;
    /* 0x04 */ f32 height;
    /* 0x08 */ f32 yShift;
    /* 0x0C */ Vec3f pos;
} Cylinderf; // size = 0x18

#endif
