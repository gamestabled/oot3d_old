extern "C" {
#include "z_obj_tsubo.hpp"

#define FLAGS 0x00800010

void ObjTsubo_Init(Actor* actor, GameState* state);
void ObjTsubo_Destroy(Actor* actor, GameState* state);
void ObjTsubo_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Obj_Tsubo.data.o")

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
    NULL,
};
*/

GLOBAL_ASM("binary/ObjTsubo_Init.o")

GLOBAL_ASM("binary/ObjTsubo_Destroy.o")

GLOBAL_ASM("binary/ObjTsubo_Update.o")
}
