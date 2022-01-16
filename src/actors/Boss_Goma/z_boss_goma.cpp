extern "C" {
#include "z_boss_goma.hpp"

#define FLAGS 0x00000035

void BossGoma_Init(Actor* actor, GameState* state);
void BossGoma_Destroy(Actor* actor, GameState* state);
void BossGoma_Update(Actor* actor, GameState* state);
void BossGoma_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Boss_Goma.data.o")

ActorInit Boss_Goma_InitVars = {
    ACTOR_BOSS_GOMA,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GOMA,
    sizeof(BossGoma),
    (ActorFunc)BossGoma_Init,
    (ActorFunc)BossGoma_Destroy,
    (ActorFunc)BossGoma_Update,
    (ActorFunc)BossGoma_Draw,
};

GLOBAL_ASM("binary/BossGoma_Init.o")

GLOBAL_ASM("binary/BossGoma_Destroy.o")

GLOBAL_ASM("binary/BossGoma_Update.o")

GLOBAL_ASM("binary/BossGoma_Draw.o")
}
