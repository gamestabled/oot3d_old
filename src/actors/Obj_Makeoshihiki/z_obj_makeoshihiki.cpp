extern "C" {
#include "z_obj_makeoshihiki.hpp"

#define FLAGS 0x00000020

void ObjMakeoshihiki_Init(Actor* actor, GameState* state);
void ObjMakeoshihiki_Destroy(Actor* actor, GameState* state);
void ObjMakeoshihiki_Update(Actor* actor, GameState* state);
void ObjMakeoshihiki_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Makeoshihiki_InitVars = {
    ACTOR_OBJ_MAKEOSHIHIKI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(ObjMakeoshihiki),
    (ActorFunc)ObjMakeoshihiki_Init,
    (ActorFunc)ObjMakeoshihiki_Destroy,
    (ActorFunc)ObjMakeoshihiki_Update,
    (ActorFunc)ObjMakeoshihiki_Draw,
};
*/
}
