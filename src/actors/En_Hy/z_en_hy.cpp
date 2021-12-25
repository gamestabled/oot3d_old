extern "C" {
#include "z_en_hy.hpp"

#define FLAGS 0x00000019

void EnHy_Init(Actor* actor, GameState* state);
void EnHy_Destroy(Actor* actor, GameState* state);
void EnHy_Update(Actor* actor, GameState* state);
void EnHy_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Hy.data.o")

/*
ActorInit En_Hy_InitVars = {
    ACTOR_EN_HY,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnHy),
    (ActorFunc)EnHy_Init,
    (ActorFunc)EnHy_Destroy,
    (ActorFunc)EnHy_Update,
    (ActorFunc)EnHy_Draw,
};
*/

GLOBAL_ASM("binary/EnHy_Init.o")

GLOBAL_ASM("binary/EnHy_Destroy.o")

GLOBAL_ASM("binary/EnHy_Update.o")

GLOBAL_ASM("binary/EnHy_Draw.o")
}
