extern "C" {
#include "z_en_zf.hpp"

#define FLAGS 0x00000015

void EnZf_Init(Actor* actor, GameState* state);
void EnZf_Destroy(Actor* actor, GameState* state);
void EnZf_Update(Actor* actor, GameState* state);
void EnZf_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Zf_InitVars = {
    ACTOR_EN_ZF,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ZF,
    sizeof(EnZf),
    (ActorFunc)EnZf_Init,
    (ActorFunc)EnZf_Destroy,
    (ActorFunc)EnZf_Update,
    (ActorFunc)EnZf_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnZf_Init.o")

#pragma GLOBAL_ASM("binary/EnZf_Destroy.o")

#pragma GLOBAL_ASM("binary/EnZf_Update.o")

#pragma GLOBAL_ASM("binary/EnZf_Draw.o")
}
