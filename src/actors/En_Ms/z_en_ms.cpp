extern "C" {
#include "z_en_ms.hpp"

#define FLAGS 0x00000009

void EnMs_Init(Actor* actor, GameState* state);
void EnMs_Destroy(Actor* actor, GameState* state);
void EnMs_Update(Actor* actor, GameState* state);
void EnMs_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ms_InitVars = {
    ACTOR_EN_MS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MS,
    sizeof(EnMs),
    (ActorFunc)EnMs_Init,
    (ActorFunc)EnMs_Destroy,
    (ActorFunc)EnMs_Update,
    (ActorFunc)EnMs_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnMs_Init.o")

#pragma GLOBAL_ASM("binary/EnMs_Destroy.o")

#pragma GLOBAL_ASM("binary/EnMs_Update.o")

#pragma GLOBAL_ASM("binary/EnMs_Draw.o")
}
