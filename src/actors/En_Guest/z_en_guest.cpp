extern "C" {
#include "z_en_guest.hpp"

#define FLAGS 0x00000019

void EnGuest_Init(Actor* actor, GameState* state);
void EnGuest_Destroy(Actor* actor, GameState* state);
void EnGuest_Update(Actor* actor, GameState* state);

/*
ActorInit En_Guest_InitVars = {
    ACTOR_EN_GUEST,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_BOJ,
    sizeof(EnGuest),
    (ActorFunc)EnGuest_Init,
    (ActorFunc)EnGuest_Destroy,
    (ActorFunc)EnGuest_Update,
    (ActorFunc)NULL,
};
*/
}
