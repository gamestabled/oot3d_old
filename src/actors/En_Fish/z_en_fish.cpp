extern "C" {
#include "z_en_fish.hpp"

#define FLAGS 0x00000000

void EnFish_Init(Actor* actor, GameState* state);
void EnFish_Destroy(Actor* actor, GameState* state);
void EnFish_Update(Actor* actor, GameState* state);
void EnFish_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Fish_InitVars = {
    ACTOR_EN_FISH,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnFish),
    (ActorFunc)EnFish_Init,
    (ActorFunc)EnFish_Destroy,
    (ActorFunc)EnFish_Update,
    (ActorFunc)EnFish_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnFish_Init.o")

#pragma GLOBAL_ASM("binary/EnFish_Destroy.o")

#pragma GLOBAL_ASM("binary/EnFish_Update.o")

#pragma GLOBAL_ASM("binary/EnFish_Draw.o")
}
