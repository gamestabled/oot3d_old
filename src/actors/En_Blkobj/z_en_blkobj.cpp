extern "C" {
#include "z_en_blkobj.hpp"

#define FLAGS 0x00400030

void EnBlkobj_Init(Actor* actor, GameState* state);
void EnBlkobj_Destroy(Actor* actor, GameState* state);
void EnBlkobj_Update(Actor* actor, GameState* state);
void EnBlkobj_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Blkobj_InitVars = {
    ACTOR_EN_BLKOBJ,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BLKOBJ,
    sizeof(EnBlkobj),
    (ActorFunc)EnBlkobj_Init,
    (ActorFunc)EnBlkobj_Destroy,
    (ActorFunc)EnBlkobj_Update,
    (ActorFunc)EnBlkobj_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnBlkobj_Init.o")

#pragma GLOBAL_ASM("binary/EnBlkobj_Destroy.o")

#pragma GLOBAL_ASM("binary/EnBlkobj_Update.o")

#pragma GLOBAL_ASM("binary/EnBlkobj_Draw.o")
}
