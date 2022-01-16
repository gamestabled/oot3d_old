extern "C" {
#include "z_obj_mure.hpp"

#define FLAGS 0x00000000

void ObjMure_Init(Actor* actor, GameState* state);
void ObjMure_Destroy(Actor* actor, GameState* state);
void ObjMure_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Obj_Mure.data.o")

ActorInit Obj_Mure_InitVars = {
    ACTOR_OBJ_MURE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjMure),
    (ActorFunc)ObjMure_Init,
    (ActorFunc)ObjMure_Destroy,
    (ActorFunc)ObjMure_Update,
    NULL,
};

GLOBAL_ASM("binary/ObjMure_Init.o")

GLOBAL_ASM("binary/ObjMure_Destroy.o")

GLOBAL_ASM("binary/ObjMure_Update.o")
}
