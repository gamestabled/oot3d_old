extern "C" {
#include "z_en_cow.hpp"

#define FLAGS 0x00000009

void EnCow_Init(Actor* actor, GameState* state);
void EnCow_Destroy(Actor* actor, GameState* state);
void EnCow_Update(Actor* actor, GameState* state);
void EnCow_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Cow_InitVars = {
    ACTOR_EN_COW,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_COW,
    sizeof(EnCow),
    (ActorFunc)EnCow_Init,
    (ActorFunc)EnCow_Destroy,
    (ActorFunc)EnCow_Update,
    (ActorFunc)EnCow_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnCow_Init.o")

#pragma GLOBAL_ASM("binary/EnCow_Destroy.o")

#pragma GLOBAL_ASM("binary/EnCow_Update.o")

#pragma GLOBAL_ASM("binary/EnCow_Draw.o")
}
