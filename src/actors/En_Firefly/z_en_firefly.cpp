extern "C" {
#include "z_en_firefly.hpp"

#define FLAGS 0x00005005

void EnFirefly_Init(Actor* actor, GameState* state);
void EnFirefly_Destroy(Actor* actor, GameState* state);
void EnFirefly_Update(Actor* actor, GameState* state);
void EnFirefly_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Firefly.data.o")

/*
ActorInit En_Firefly_InitVars = {
    ACTOR_EN_FIREFLY,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_FIREFLY,
    sizeof(EnFirefly),
    (ActorFunc)EnFirefly_Init,
    (ActorFunc)EnFirefly_Destroy,
    (ActorFunc)EnFirefly_Update,
    (ActorFunc)EnFirefly_Draw,
};
*/

GLOBAL_ASM("binary/EnFirefly_Init.o")

GLOBAL_ASM("binary/EnFirefly_Destroy.o")

GLOBAL_ASM("binary/EnFirefly_Update.o")

GLOBAL_ASM("binary/EnFirefly_Draw.o")
}
