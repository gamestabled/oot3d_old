extern "C" {
#include "z_obj_hana.hpp"

#define FLAGS 0x80000000

void ObjHana_Init(Actor* actor, GameState* state);
void ObjHana_Destroy(Actor* actor, GameState* state);
void ObjHana_Update(Actor* actor, GameState* state);
void ObjHana_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Hana_InitVars = {
    ACTOR_OBJ_HANA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(ObjHana),
    (ActorFunc)ObjHana_Init,
    (ActorFunc)ObjHana_Destroy,
    (ActorFunc)ObjHana_Update,
    (ActorFunc)ObjHana_Draw,
};
*/
}
