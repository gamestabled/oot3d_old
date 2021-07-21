extern "C" {
#include "z_en_rl.hpp"

#define FLAGS 0x00000010

void EnRl_Init(Actor* actor, GameState* state);
void EnRl_Destroy(Actor* actor, GameState* state);
void EnRl_Update(Actor* actor, GameState* state);
void EnRl_Draw(Actor* actor, GameState* state);

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
}
