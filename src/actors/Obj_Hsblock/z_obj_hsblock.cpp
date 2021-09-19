extern "C" {
#include "z_obj_hsblock.hpp"

#define FLAGS 0x00000000

void ObjHsblock_Init(Actor* actor, GameState* state);
void ObjHsblock_Destroy(Actor* actor, GameState* state);
void ObjHsblock_Update(Actor* actor, GameState* state);
void ObjHsblock_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Hsblock_InitVars = {
    ACTOR_OBJ_HSBLOCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_D_HSBLOCK,
    sizeof(ObjHsblock),
    (ActorFunc)ObjHsblock_Init,
    (ActorFunc)ObjHsblock_Destroy,
    (ActorFunc)ObjHsblock_Update,
    (ActorFunc)ObjHsblock_Draw,
};
*/

#pragma GLOBAL_ASM("binary/ObjHsblock_Init.o")

#pragma GLOBAL_ASM("binary/ObjHsblock_Destroy.o")

#pragma GLOBAL_ASM("binary/ObjHsblock_Update.o")

#pragma GLOBAL_ASM("binary/ObjHsblock_Draw.o")
}
