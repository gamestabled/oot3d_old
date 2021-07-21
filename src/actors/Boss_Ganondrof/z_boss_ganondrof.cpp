extern "C" {
#include "z_boss_ganondrof.hpp"

#define FLAGS 0x00000035

void BossGanondrof_Init(Actor* actor, GameState* state);
void BossGanondrof_Destroy(Actor* actor, GameState* state);
void BossGanondrof_Update(Actor* actor, GameState* state);
void BossGanondrof_Draw(Actor* actor, GameState* state);

/*
ActorInit Boss_Ganondrof_InitVars = {
    ACTOR_BOSS_GANONDROF,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GND,
    sizeof(BossGanondrof),
    (ActorFunc)BossGanondrof_Init,
    (ActorFunc)BossGanondrof_Destroy,
    (ActorFunc)BossGanondrof_Update,
    (ActorFunc)BossGanondrof_Draw,
};
*/
}
