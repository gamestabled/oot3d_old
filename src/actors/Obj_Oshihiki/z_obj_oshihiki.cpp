extern "C" {
#include "z_obj_oshihiki.hpp"

#define FLAGS 0x00400010

void ObjOshihiki_Init(Actor* actor, GameState* state);
void ObjOshihiki_Destroy(Actor* actor, GameState* state);
void ObjOshihiki_Update(Actor* actor, GameState* state);
void ObjOshihiki_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Oshihiki_InitVars = {
    ACTOR_OBJ_OSHIHIKI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(ObjOshihiki),
    (ActorFunc)ObjOshihiki_Init,
    (ActorFunc)ObjOshihiki_Destroy,
    (ActorFunc)ObjOshihiki_Update,
    (ActorFunc)ObjOshihiki_Draw,
};
*/

GLOBAL_ASM("binary/ObjOshihiki_Init.o")

GLOBAL_ASM("binary/ObjOshihiki_Destroy.o")

GLOBAL_ASM("binary/ObjOshihiki_Update.o")

GLOBAL_ASM("binary/ObjOshihiki_Draw.o")
}
