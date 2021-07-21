extern "C" {
#include "z_en_jj.hpp"

#define FLAGS 0x00000030

void EnJj_Init(Actor* actor, GameState* state);
void EnJj_Destroy(Actor* actor, GameState* state);
void EnJj_Update(Actor* actor, GameState* state);
void EnJj_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Jj_InitVars = {
    ACTOR_EN_JJ,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_JJ,
    sizeof(EnJj),
    (ActorFunc)EnJj_Init,
    (ActorFunc)EnJj_Destroy,
    (ActorFunc)EnJj_Update,
    (ActorFunc)EnJj_Draw,
};
*/
}
