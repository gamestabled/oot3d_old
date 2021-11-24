extern "C" {
#include "z_eff_dust.hpp"

#define FLAGS 0x00000030

void EffDust_Init(Actor* actor, GameState* state);
void EffDust_Destroy(Actor* actor, GameState* state);
void EffDust_Update(Actor* actor, GameState* state);
void EffDust_Draw(Actor* actor, GameState* state);

/*
ActorInit Eff_Dust_InitVars = {
    ACTOR_EFF_DUST,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EffDust),
    (ActorFunc)EffDust_Init,
    (ActorFunc)EffDust_Destroy,
    (ActorFunc)EffDust_Update,
    (ActorFunc)EffDust_Draw,
};
*/

GLOBAL_ASM("binary/EffDust_Init.o")

GLOBAL_ASM("binary/EffDust_Destroy.o")

GLOBAL_ASM("binary/EffDust_Update.o")

GLOBAL_ASM("binary/EffDust_Draw.o")
}
