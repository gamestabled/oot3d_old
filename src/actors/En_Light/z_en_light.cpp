extern "C" {
#include "z_en_light.hpp"

#define FLAGS 0x00000000

void EnLight_Init(Actor* actor, GameState* state);
void EnLight_Destroy(Actor* actor, GameState* state);
void EnLight_Update(Actor* actor, GameState* state);
void EnLight_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Light_InitVars = {
    ACTOR_EN_LIGHT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnLight),
    (ActorFunc)EnLight_Init,
    (ActorFunc)EnLight_Destroy,
    (ActorFunc)EnLight_Update,
    (ActorFunc)EnLight_Draw,
};
*/

GLOBAL_ASM("binary/EnLight_Init.o")

GLOBAL_ASM("binary/EnLight_Destroy.o")

GLOBAL_ASM("binary/EnLight_Update.o")

GLOBAL_ASM("binary/EnLight_Draw.o")
}
