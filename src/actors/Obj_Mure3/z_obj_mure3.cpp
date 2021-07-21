extern "C" {
#include "z_obj_mure3.hpp"

#define FLAGS 0x00000000

void ObjMure3_Init(Actor* actor, GameState* state);
void ObjMure3_Destroy(Actor* actor, GameState* state);
void ObjMure3_Update(Actor* actor, GameState* state);

/*
ActorInit Obj_Mure3_InitVars = {
    ACTOR_OBJ_MURE3,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjMure3),
    (ActorFunc)ObjMure3_Init,
    (ActorFunc)ObjMure3_Destroy,
    (ActorFunc)ObjMure3_Update,
    (ActorFunc)NULL,
};
*/
}
