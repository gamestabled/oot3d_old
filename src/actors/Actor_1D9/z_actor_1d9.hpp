#ifndef _Z_ACTOR_1D9_H_
#define _Z_ACTOR_1D9_H_

#include "global.hpp"

struct Actor1D9;

typedef struct Actor1D9 {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x250];
} Actor1D9; // size = 0x3F4

extern ActorInit Actor_1D9_InitVars;

#endif
