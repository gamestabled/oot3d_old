#ifndef _Z_BG_TREEMOUTH_H_
#define _Z_BG_TREEMOUTH_H_

#include "global.hpp"

struct BgTreemouth;

typedef struct BgTreemouth {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x28];
} BgTreemouth; // size = 0x1CC

extern ActorInit Bg_Treemouth_InitVars;

#endif
