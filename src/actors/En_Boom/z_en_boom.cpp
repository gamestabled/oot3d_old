extern "C" {
#include "z_en_boom.hpp"

#define FLAGS 0x00000030

void EnBoom_Init(Actor* actor, GameState* state);
void EnBoom_Destroy(Actor* actor, GameState* state);
void EnBoom_Update(Actor* actor, GameState* state);
void EnBoom_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Boom_InitVars = {
    ACTOR_EN_BOOM,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnBoom),
    (ActorFunc)EnBoom_Init,
    (ActorFunc)EnBoom_Destroy,
    (ActorFunc)EnBoom_Update,
    (ActorFunc)EnBoom_Draw,
};
*/
}
