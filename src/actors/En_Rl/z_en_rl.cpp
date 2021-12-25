extern "C" {
#include "z_en_rl.hpp"

#define FLAGS 0x00000010

void EnRl_Init(Actor* actor, GameState* state);
void EnRl_Destroy(Actor* actor, GameState* state);
void EnRl_Update(Actor* actor, GameState* state);
void EnRl_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Rl.data.o")

/*
ActorInit En_Rl_InitVars = {
    ACTOR_EN_RL,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_RL,
    sizeof(EnRl),
    (ActorFunc)EnRl_Init,
    (ActorFunc)EnRl_Destroy,
    (ActorFunc)EnRl_Update,
    (ActorFunc)EnRl_Draw,
};
*/

GLOBAL_ASM("binary/EnRl_Init.o")

GLOBAL_ASM("binary/EnRl_Destroy.o")

GLOBAL_ASM("binary/EnRl_Update.o")

GLOBAL_ASM("binary/EnRl_Draw.o")
}
