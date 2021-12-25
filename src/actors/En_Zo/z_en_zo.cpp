extern "C" {
#include "z_en_zo.hpp"

#define FLAGS 0x00000009

void EnZo_Init(Actor* actor, GameState* state);
void EnZo_Destroy(Actor* actor, GameState* state);
void EnZo_Update(Actor* actor, GameState* state);
void EnZo_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Zo.data.o")

/*
ActorInit En_Zo_InitVars = {
    ACTOR_EN_ZO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZO,
    sizeof(EnZo),
    (ActorFunc)EnZo_Init,
    (ActorFunc)EnZo_Destroy,
    (ActorFunc)EnZo_Update,
    (ActorFunc)EnZo_Draw,
};
*/

GLOBAL_ASM("binary/EnZo_Init.o")

GLOBAL_ASM("binary/EnZo_Destroy.o")

GLOBAL_ASM("binary/EnZo_Update.o")

GLOBAL_ASM("binary/EnZo_Draw.o")
}
