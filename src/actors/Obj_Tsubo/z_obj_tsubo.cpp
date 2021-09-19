extern "C" {
#include "z_obj_tsubo.hpp"

#define FLAGS 0x00800010

void ObjTsubo_Init(Actor* actor, GameState* state);
void ObjTsubo_Destroy(Actor* actor, GameState* state);
void ObjTsubo_Update(Actor* actor, GameState* state);

/*
ActorInit Obj_Tsubo_InitVars = {
    ACTOR_OBJ_TSUBO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjTsubo),
    (ActorFunc)ObjTsubo_Init,
    (ActorFunc)ObjTsubo_Destroy,
    (ActorFunc)ObjTsubo_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/ObjTsubo_Init.o")

#pragma GLOBAL_ASM("binary/ObjTsubo_Destroy.o")

#pragma GLOBAL_ASM("binary/ObjTsubo_Update.o")
}
