extern "C" {
#include "z_obj_bombiwa.hpp"

#define FLAGS 0x00000000

void ObjBombiwa_Init(Actor* actor, GameState* state);
void ObjBombiwa_Destroy(Actor* actor, GameState* state);
void ObjBombiwa_Update(Actor* actor, GameState* state);
void ObjBombiwa_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Bombiwa_InitVars = {
    ACTOR_OBJ_BOMBIWA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BOMBIWA,
    sizeof(ObjBombiwa),
    (ActorFunc)ObjBombiwa_Init,
    (ActorFunc)ObjBombiwa_Destroy,
    (ActorFunc)ObjBombiwa_Update,
    (ActorFunc)ObjBombiwa_Draw,
};
*/
}
