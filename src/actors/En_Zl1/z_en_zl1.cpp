extern "C" {
#include "z_en_zl1.hpp"

#define FLAGS 0x00000019

void EnZl1_Init(Actor* actor, GameState* state);
void EnZl1_Destroy(Actor* actor, GameState* state);
void EnZl1_Update(Actor* actor, GameState* state);
void EnZl1_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Zl1_InitVars = {
    ACTOR_EN_ZL1,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZL1,
    sizeof(EnZl1),
    (ActorFunc)EnZl1_Init,
    (ActorFunc)EnZl1_Destroy,
    (ActorFunc)EnZl1_Update,
    (ActorFunc)EnZl1_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnZl1_Init.o")

#pragma GLOBAL_ASM("binary/EnZl1_Destroy.o")

#pragma GLOBAL_ASM("binary/EnZl1_Update.o")

#pragma GLOBAL_ASM("binary/EnZl1_Draw.o")
}
