extern "C" {
#include "z_en_bb.hpp"

#define FLAGS 0x01000015

void EnBb_Init(Actor* actor, GameState* state);
void EnBb_Destroy(Actor* actor, GameState* state);
void EnBb_Update(Actor* actor, GameState* state);
void EnBb_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Bb_InitVars = {
    ACTOR_EN_BB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BB,
    sizeof(EnBb),
    (ActorFunc)EnBb_Init,
    (ActorFunc)EnBb_Destroy,
    (ActorFunc)EnBb_Update,
    (ActorFunc)EnBb_Draw,
};
*/
}
