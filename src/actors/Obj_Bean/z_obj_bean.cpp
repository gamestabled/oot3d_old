extern "C" {
#include "z_obj_bean.hpp"

#define FLAGS 0x00400000

void ObjBean_Init(Actor* actor, GameState* state);
void ObjBean_Destroy(Actor* actor, GameState* state);
void ObjBean_Update(Actor* actor, GameState* state);
void ObjBean_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Obj_Bean.data.o")

ActorInit Obj_Bean_InitVars = {
    ACTOR_OBJ_BEAN,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MAMENOKI,
    sizeof(ObjBean),
    (ActorFunc)ObjBean_Init,
    (ActorFunc)ObjBean_Destroy,
    (ActorFunc)ObjBean_Update,
    (ActorFunc)ObjBean_Draw,
};

GLOBAL_ASM("binary/ObjBean_Init.o")

GLOBAL_ASM("binary/ObjBean_Destroy.o")

GLOBAL_ASM("binary/ObjBean_Update.o")

GLOBAL_ASM("binary/ObjBean_Draw.o")
}
