#ifndef _Z_ITEM_B_HEART_H_
#define _Z_ITEM_B_HEART_H_

#include "global.hpp"

struct ItemBHeart;

typedef struct ItemBHeart {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x24];
} ItemBHeart; // size = 0x1C8

extern ActorInit Item_B_Heart_InitVars;

#endif
