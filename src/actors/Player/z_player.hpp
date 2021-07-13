#ifndef _Z_PLAYER_H_
#define _Z_PLAYER_H_

#include "global.hpp"

struct Player;

typedef struct Player {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x28A8];
} Player; // size = 0x2A4C

extern ActorInit Player_InitVars;

#endif
