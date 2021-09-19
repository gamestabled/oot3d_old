extern "C" {
#include "z_en_ge1.hpp"

#define FLAGS 0x00000009

void EnGe1_Init(Actor* actor, GameState* state);
void EnGe1_Destroy(Actor* actor, GameState* state);
void EnGe1_Update(Actor* actor, GameState* state);
void EnGe1_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ge1_InitVars = {
    ACTOR_EN_GE1,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GE1,
    sizeof(EnGe1),
    (ActorFunc)EnGe1_Init,
    (ActorFunc)EnGe1_Destroy,
    (ActorFunc)EnGe1_Update,
    (ActorFunc)EnGe1_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnGe1_Init.o")

#pragma GLOBAL_ASM("binary/EnGe1_Destroy.o")

#pragma GLOBAL_ASM("binary/EnGe1_Update.o")

#pragma GLOBAL_ASM("binary/EnGe1_Draw.o")
}
