#ifndef _Z_EN_VASE_H_
#define _Z_EN_VASE_H_

#include "global.hpp"

struct EnVase;

typedef struct EnVase {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x4];
} EnVase; // size = 0x1A8

extern ActorInit En_Vase_InitVars;

#endif
