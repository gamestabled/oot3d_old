extern "C" {
#include "z_obj_syokudai.hpp"

#define FLAGS 0x00000410

void ObjSyokudai_Init(Actor* actor, GameState* state);
void ObjSyokudai_Destroy(Actor* actor, GameState* state);
void ObjSyokudai_Update(Actor* actor, GameState* state);
void ObjSyokudai_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Obj_Syokudai.data.o")

ActorInit Obj_Syokudai_InitVars = {
    ACTOR_OBJ_SYOKUDAI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SYOKUDAI,
    sizeof(ObjSyokudai),
    (ActorFunc)ObjSyokudai_Init,
    (ActorFunc)ObjSyokudai_Destroy,
    (ActorFunc)ObjSyokudai_Update,
    (ActorFunc)ObjSyokudai_Draw,
};

GLOBAL_ASM("binary/ObjSyokudai_Init.o")

GLOBAL_ASM("binary/ObjSyokudai_Destroy.o")

GLOBAL_ASM("binary/ObjSyokudai_Update.o")

GLOBAL_ASM("binary/ObjSyokudai_Draw.o")
}
