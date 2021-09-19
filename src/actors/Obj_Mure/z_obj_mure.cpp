extern "C" {
#include "z_obj_mure.hpp"

#define FLAGS 0x00000000

void ObjMure_Init(Actor* actor, GameState* state);
void ObjMure_Destroy(Actor* actor, GameState* state);
void ObjMure_Update(Actor* actor, GameState* state);

/*
ActorInit Obj_Mure_InitVars = {
    ACTOR_OBJ_MURE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjMure),
    (ActorFunc)ObjMure_Init,
    (ActorFunc)ObjMure_Destroy,
    (ActorFunc)ObjMure_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/ObjMure_Init.o")

#pragma GLOBAL_ASM("binary/ObjMure_Destroy.o")

#pragma GLOBAL_ASM("binary/ObjMure_Update.o")
}
