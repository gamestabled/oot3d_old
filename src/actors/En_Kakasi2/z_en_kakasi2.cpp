extern "C" {
#include "z_en_kakasi2.hpp"

#define FLAGS 0x0A000031

void EnKakasi2_Init(Actor* actor, GameState* state);
void EnKakasi2_Destroy(Actor* actor, GameState* state);
void EnKakasi2_Update(Actor* actor, GameState* state);

/*
ActorInit En_Kakasi2_InitVars = {
    ACTOR_EN_KAKASI2,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_KA,
    sizeof(EnKakasi2),
    (ActorFunc)EnKakasi2_Init,
    (ActorFunc)EnKakasi2_Destroy,
    (ActorFunc)EnKakasi2_Update,
    (ActorFunc)NULL,
};
*/
}
