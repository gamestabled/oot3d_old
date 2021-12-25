extern "C" {
#include "z_obj_dekujr.hpp"

#define FLAGS 0x00000039

void ObjDekujr_Init(Actor* actor, GameState* state);
void ObjDekujr_Destroy(Actor* actor, GameState* state);
void ObjDekujr_Update(Actor* actor, GameState* state);
void ObjDekujr_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Obj_Dekujr.data.o")

/*
ActorInit Obj_Dekujr_InitVars = {
    ACTOR_OBJ_DEKUJR,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DEKUJR,
    sizeof(ObjDekujr),
    (ActorFunc)ObjDekujr_Init,
    (ActorFunc)ObjDekujr_Destroy,
    (ActorFunc)ObjDekujr_Update,
    (ActorFunc)ObjDekujr_Draw,
};
*/

GLOBAL_ASM("binary/ObjDekujr_Init.o")

GLOBAL_ASM("binary/ObjDekujr_Destroy.o")

GLOBAL_ASM("binary/ObjDekujr_Update.o")

GLOBAL_ASM("binary/ObjDekujr_Draw.o")
}
