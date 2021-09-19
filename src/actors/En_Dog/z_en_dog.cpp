extern "C" {
#include "z_en_dog.hpp"

#define FLAGS 0x00000000

void EnDog_Init(Actor* actor, GameState* state);
void EnDog_Destroy(Actor* actor, GameState* state);
void EnDog_Update(Actor* actor, GameState* state);
void EnDog_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Dog_InitVars = {
    ACTOR_EN_DOG,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DOG,
    sizeof(EnDog),
    (ActorFunc)EnDog_Init,
    (ActorFunc)EnDog_Destroy,
    (ActorFunc)EnDog_Update,
    (ActorFunc)EnDog_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnDog_Init.o")

#pragma GLOBAL_ASM("binary/EnDog_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDog_Update.o")

#pragma GLOBAL_ASM("binary/EnDog_Draw.o")
}
