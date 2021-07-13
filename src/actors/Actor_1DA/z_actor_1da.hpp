#ifndef _Z_ACTOR_1DA_H_
#define _Z_ACTOR_1DA_H_

#include "global.hpp"

struct Actor1DA;

typedef struct Actor1DA {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x1C];
} Actor1DA; // size = 0x1C0

extern ActorInit Actor_1DA_InitVars;

#endif
