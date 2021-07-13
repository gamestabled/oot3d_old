#ifndef _Z_OBJ_KIBAKO2_H_
#define _Z_OBJ_KIBAKO2_H_

#include "global.hpp"

struct ObjKibako2;

typedef struct ObjKibako2 {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x7C];
} ObjKibako2; // size = 0x220

extern ActorInit Obj_Kibako2_InitVars;

#endif
