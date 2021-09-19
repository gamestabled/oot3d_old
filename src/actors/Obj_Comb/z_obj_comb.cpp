extern "C" {
#include "z_obj_comb.hpp"

#define FLAGS 0x80000000

void ObjComb_Init(Actor* actor, GameState* state);
void ObjComb_Destroy(Actor* actor, GameState* state);
void ObjComb_Update(Actor* actor, GameState* state);
void ObjComb_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Comb_InitVars = {
    ACTOR_OBJ_COMB,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(ObjComb),
    (ActorFunc)ObjComb_Init,
    (ActorFunc)ObjComb_Destroy,
    (ActorFunc)ObjComb_Update,
    (ActorFunc)ObjComb_Draw,
};
*/

#pragma GLOBAL_ASM("binary/ObjComb_Init.o")

#pragma GLOBAL_ASM("binary/ObjComb_Destroy.o")

#pragma GLOBAL_ASM("binary/ObjComb_Update.o")

#pragma GLOBAL_ASM("binary/ObjComb_Draw.o")
}
