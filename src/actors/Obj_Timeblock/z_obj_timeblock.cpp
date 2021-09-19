extern "C" {
#include "z_obj_timeblock.hpp"

#define FLAGS 0x0A000011

void ObjTimeblock_Init(Actor* actor, GameState* state);
void ObjTimeblock_Destroy(Actor* actor, GameState* state);
void ObjTimeblock_Update(Actor* actor, GameState* state);
void ObjTimeblock_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Timeblock_InitVars = {
    ACTOR_OBJ_TIMEBLOCK,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_TIMEBLOCK,
    sizeof(ObjTimeblock),
    (ActorFunc)ObjTimeblock_Init,
    (ActorFunc)ObjTimeblock_Destroy,
    (ActorFunc)ObjTimeblock_Update,
    (ActorFunc)ObjTimeblock_Draw,
};
*/

#pragma GLOBAL_ASM("binary/ObjTimeblock_Init.o")

#pragma GLOBAL_ASM("binary/ObjTimeblock_Destroy.o")

#pragma GLOBAL_ASM("binary/ObjTimeblock_Update.o")

#pragma GLOBAL_ASM("binary/ObjTimeblock_Draw.o")
}
