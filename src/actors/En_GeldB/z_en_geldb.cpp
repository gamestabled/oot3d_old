extern "C" {
#include "z_en_geldb.hpp"

#define FLAGS 0x00000015

void EnGeldB_Init(Actor* actor, GameState* state);
void EnGeldB_Destroy(Actor* actor, GameState* state);
void EnGeldB_Update(Actor* actor, GameState* state);
void EnGeldB_Draw(Actor* actor, GameState* state);

/*
ActorInit En_GeldB_InitVars = {
    ACTOR_EN_GELDB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GELDB,
    sizeof(EnGeldB),
    (ActorFunc)EnGeldB_Init,
    (ActorFunc)EnGeldB_Destroy,
    (ActorFunc)EnGeldB_Update,
    (ActorFunc)EnGeldB_Draw,
};
*/
}
