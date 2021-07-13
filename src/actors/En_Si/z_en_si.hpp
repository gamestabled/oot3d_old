#ifndef _Z_EN_SI_H_
#define _Z_EN_SI_H_

#include "global.hpp"

struct EnSi;

typedef struct EnSi {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x6C];
} EnSi; // size = 0x210

extern ActorInit En_Si_InitVars;

#endif
