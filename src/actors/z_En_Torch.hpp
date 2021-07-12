#ifndef _Z_EN_TORCH_H_
#define _Z_EN_TORCH_H_

#include "z3D.hpp"

typedef struct EnTorch {
    /* 0x000 */ Actor actor;
} EnTorch;

extern ActorInit EnTorch_InitVars;
extern u8 sChestContents[]; //externed so it isnt optimized out for now. once EnTorch_Init matches, it can become static

#endif
