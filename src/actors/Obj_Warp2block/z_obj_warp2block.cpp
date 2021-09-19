extern "C" {
#include "z_obj_warp2block.hpp"

#define FLAGS 0x0A000031

void ObjWarp2block_Init(Actor* actor, GameState* state);
void ObjWarp2block_Destroy(Actor* actor, GameState* state);
void ObjWarp2block_Update(Actor* actor, GameState* state);
void ObjWarp2block_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Warp2block_InitVars = {
    ACTOR_OBJ_WARP2BLOCK,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_TIMEBLOCK,
    sizeof(ObjWarp2block),
    (ActorFunc)ObjWarp2block_Init,
    (ActorFunc)ObjWarp2block_Destroy,
    (ActorFunc)ObjWarp2block_Update,
    (ActorFunc)ObjWarp2block_Draw,
};
*/

#pragma GLOBAL_ASM("binary/ObjWarp2block_Init.o")

#pragma GLOBAL_ASM("binary/ObjWarp2block_Destroy.o")

#pragma GLOBAL_ASM("binary/ObjWarp2block_Update.o")

#pragma GLOBAL_ASM("binary/ObjWarp2block_Draw.o")
}
