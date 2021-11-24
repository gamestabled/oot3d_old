extern "C" {
#include "z_boss_mo.hpp"

#define FLAGS 0x00000035

void BossMo_Init(Actor* actor, GameState* state);
void BossMo_Destroy(Actor* actor, GameState* state);
void BossMo_Update(Actor* actor, GameState* state);
void BossMo_Draw(Actor* actor, GameState* state);

/*
ActorInit Boss_Mo_InitVars = {
    ACTOR_BOSS_MO,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_MO,
    sizeof(BossMo),
    (ActorFunc)BossMo_Init,
    (ActorFunc)BossMo_Destroy,
    (ActorFunc)BossMo_Update,
    (ActorFunc)BossMo_Draw,
};
*/

GLOBAL_ASM("binary/BossMo_Init.o")

GLOBAL_ASM("binary/BossMo_Destroy.o")

GLOBAL_ASM("binary/BossMo_Update.o")

GLOBAL_ASM("binary/BossMo_Draw.o")
}
