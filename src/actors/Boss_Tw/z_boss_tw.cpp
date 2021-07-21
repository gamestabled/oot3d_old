extern "C" {
#include "z_boss_tw.hpp"

#define FLAGS 0x00000035

void BossTw_Init(Actor* actor, GameState* state);
void BossTw_Destroy(Actor* actor, GameState* state);
void BossTw_Update(Actor* actor, GameState* state);
void BossTw_Draw(Actor* actor, GameState* state);

/*
ActorInit Boss_Tw_InitVars = {
    ACTOR_BOSS_TW,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_TW,
    sizeof(BossTw),
    (ActorFunc)BossTw_Init,
    (ActorFunc)BossTw_Destroy,
    (ActorFunc)BossTw_Update,
    (ActorFunc)BossTw_Draw,
};
*/
}
