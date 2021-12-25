extern "C" {
#include "z_obj_hamishi.hpp"

#define FLAGS 0x80000000

void ObjHamishi_Init(Actor* actor, GameState* state);
void ObjHamishi_Destroy(Actor* actor, GameState* state);
void ObjHamishi_Update(Actor* actor, GameState* state);
void ObjHamishi_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Obj_Hamishi.data.o")

/*
ActorInit Obj_Hamishi_InitVars = {
    ACTOR_OBJ_HAMISHI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(ObjHamishi),
    (ActorFunc)ObjHamishi_Init,
    (ActorFunc)ObjHamishi_Destroy,
    (ActorFunc)ObjHamishi_Update,
    (ActorFunc)ObjHamishi_Draw,
};
*/

GLOBAL_ASM("binary/ObjHamishi_Init.o")

GLOBAL_ASM("binary/ObjHamishi_Destroy.o")

GLOBAL_ASM("binary/ObjHamishi_Update.o")

GLOBAL_ASM("binary/ObjHamishi_Draw.o")
}
