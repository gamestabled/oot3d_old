#ifndef _Z_BG_SPOT01_IDOMIZU_H_
#define _Z_BG_SPOT01_IDOMIZU_H_

#include "global.hpp"

struct BgSpot01Idomizu;

typedef struct BgSpot01Idomizu {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x10];
} BgSpot01Idomizu; // size = 0x1B4

extern ActorInit Bg_Spot01_Idomizu_InitVars;

#endif
