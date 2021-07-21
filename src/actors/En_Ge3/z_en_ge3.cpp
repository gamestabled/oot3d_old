extern "C" {
#include "z_en_ge3.hpp"

#define FLAGS 0x00000019

void EnGe3_Init(Actor* actor, GameState* state);
void EnGe3_Destroy(Actor* actor, GameState* state);
void EnGe3_Update(Actor* actor, GameState* state);
void EnGe3_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ge3_InitVars = {
    ACTOR_EN_GE3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GELDB,
    sizeof(EnGe3),
    (ActorFunc)EnGe3_Init,
    (ActorFunc)EnGe3_Destroy,
    (ActorFunc)EnGe3_Update,
    (ActorFunc)EnGe3_Draw,
};
*/
}
