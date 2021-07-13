#ifndef _Z_EN_STREAM_H_
#define _Z_EN_STREAM_H_

#include "global.hpp"

struct EnStream;

typedef struct EnStream {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x10];
} EnStream; // size = 0x1B4

extern ActorInit En_Stream_InitVars;

#endif
