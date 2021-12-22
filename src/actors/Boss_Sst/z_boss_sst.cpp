extern "C" {
#include "z_boss_sst.hpp"

#define FLAGS 0x00000435

void BossSst_Init(Actor* actor, GameState* state);
void BossSst_Destroy(Actor* actor, GameState* state);
void BossSst_Update(Actor* actor, GameState* state);
void BossSst_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Boss_Sst.data.o")

/*
ActorInit Boss_Sst_InitVars = {
    ACTOR_BOSS_SST,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_SST,
    sizeof(BossSst),
    (ActorFunc)BossSst_Init,
    (ActorFunc)BossSst_Destroy,
    (ActorFunc)BossSst_Update,
    (ActorFunc)BossSst_Draw,
};
*/

GLOBAL_ASM("binary/BossSst_Init.o")

GLOBAL_ASM("binary/BossSst_Destroy.o")

GLOBAL_ASM("binary/BossSst_Update.o")

GLOBAL_ASM("binary/BossSst_Draw.o")
}
