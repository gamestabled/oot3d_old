extern "C" {
#include "z_en_niw_girl.hpp"

#define FLAGS 0x00000019

void EnNiwGirl_Init(Actor* actor, GameState* state);
void EnNiwGirl_Destroy(Actor* actor, GameState* state);
void EnNiwGirl_Update(Actor* actor, GameState* state);
void EnNiwGirl_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Niw_Girl_InitVars = {
    ACTOR_EN_NIW_GIRL,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GR,
    sizeof(EnNiwGirl),
    (ActorFunc)EnNiwGirl_Init,
    (ActorFunc)EnNiwGirl_Destroy,
    (ActorFunc)EnNiwGirl_Update,
    (ActorFunc)EnNiwGirl_Draw,
};
*/
}
