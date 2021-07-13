#ifndef _Z_EN_TORCH_H_
#define _Z_EN_TORCH_H_

#include "global.hpp"

struct EnTorch;

typedef struct EnTorch {
    /* 0x0000 */ Actor actor;
} EnTorch; // size = 0x1A4

extern ActorInit En_Torch_InitVars;
extern u8 sChestContents[]; //externed so it isnt optimized out for now. once EnTorch_Init matches, it can become static

#endif
