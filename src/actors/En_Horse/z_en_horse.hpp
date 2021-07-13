#ifndef _Z_EN_HORSE_H_
#define _Z_EN_HORSE_H_

#include "global.hpp"

struct EnHorse;

typedef struct EnHorse {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0xEF4];
} EnHorse; // size = 0x1098

extern ActorInit En_Horse_InitVars;

#endif
