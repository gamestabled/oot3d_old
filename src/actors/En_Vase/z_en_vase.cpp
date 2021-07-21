extern "C" {
#include "z_en_vase.hpp"

#define FLAGS 0x80000010

void EnVase_Init(Actor* actor, GameState* state);
void EnVase_Destroy(Actor* actor, GameState* state);
void EnVase_Update(Actor* actor, GameState* state);
void EnVase_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Vase_InitVars = {
    ACTOR_EN_VASE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_VASE,
    sizeof(EnVase),
    (ActorFunc)EnVase_Init,
    (ActorFunc)EnVase_Destroy,
    (ActorFunc)EnVase_Update,
    (ActorFunc)EnVase_Draw,
};
*/
}
