#ifndef _Z_EN_KZ_H_
#define _Z_EN_KZ_H_

#include "global.hpp"

struct EnKz;

typedef struct EnKz {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0xDAC];
} EnKz; // size = 0xF50

extern ActorInit En_Kz_InitVars;

#endif
