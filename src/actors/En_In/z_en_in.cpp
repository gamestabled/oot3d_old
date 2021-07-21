extern "C" {
#include "z_en_in.hpp"

#define FLAGS 0x00000019

void EnIn_Init(Actor* actor, GameState* state);
void EnIn_Destroy(Actor* actor, GameState* state);
void EnIn_Update(Actor* actor, GameState* state);
void EnIn_Draw(Actor* actor, GameState* state);

/*
ActorInit En_In_InitVars = {
    ACTOR_EN_IN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_IN,
    sizeof(EnIn),
    (ActorFunc)EnIn_Init,
    (ActorFunc)EnIn_Destroy,
    (ActorFunc)EnIn_Update,
    (ActorFunc)EnIn_Draw,
};
*/
}
