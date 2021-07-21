extern "C" {
#include "z_en_sth.hpp"

#define FLAGS 0x00000019

void EnSth_Init(Actor* actor, GameState* state);
void EnSth_Destroy(Actor* actor, GameState* state);
void EnSth_Update(Actor* actor, GameState* state);

/*
ActorInit En_Sth_InitVars = {
    ACTOR_EN_STH,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnSth),
    (ActorFunc)EnSth_Init,
    (ActorFunc)EnSth_Destroy,
    (ActorFunc)EnSth_Update,
    (ActorFunc)NULL,
};
*/
}
