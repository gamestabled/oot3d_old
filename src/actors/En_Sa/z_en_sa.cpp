extern "C" {
#include "z_en_sa.hpp"

#define FLAGS 0x02000019

void EnSa_Init(Actor* actor, GameState* state);
void EnSa_Destroy(Actor* actor, GameState* state);
void EnSa_Update(Actor* actor, GameState* state);
void EnSa_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Sa_InitVars = {
    ACTOR_EN_SA,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SA,
    sizeof(EnSa),
    (ActorFunc)EnSa_Init,
    (ActorFunc)EnSa_Destroy,
    (ActorFunc)EnSa_Update,
    (ActorFunc)EnSa_Draw,
};
*/
}
