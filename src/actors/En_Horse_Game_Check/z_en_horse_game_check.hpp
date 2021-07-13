#ifndef _Z_EN_HORSE_GAME_CHECK_H_
#define _Z_EN_HORSE_GAME_CHECK_H_

#include "global.hpp"

struct EnHorseGameCheck;

typedef struct EnHorseGameCheck {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x5C];
} EnHorseGameCheck; // size = 0x200

extern ActorInit En_Horse_Game_Check_InitVars;

#endif
