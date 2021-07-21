extern "C" {
#include "z_en_gb.hpp"

#define FLAGS 0x00000009

void EnGb_Init(Actor* actor, GameState* state);
void EnGb_Destroy(Actor* actor, GameState* state);
void EnGb_Update(Actor* actor, GameState* state);
void EnGb_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Gb_InitVars = {
    ACTOR_EN_GB,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_PS,
    sizeof(EnGb),
    (ActorFunc)EnGb_Init,
    (ActorFunc)EnGb_Destroy,
    (ActorFunc)EnGb_Update,
    (ActorFunc)EnGb_Draw,
};
*/
}
