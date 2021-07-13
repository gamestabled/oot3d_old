#ifndef _Z_OBJ_BOMBIWA_H_
#define _Z_OBJ_BOMBIWA_H_

#include "global.hpp"

struct ObjBombiwa;

typedef struct ObjBombiwa {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x5C];
} ObjBombiwa; // size = 0x200

extern ActorInit Obj_Bombiwa_InitVars;

#endif
