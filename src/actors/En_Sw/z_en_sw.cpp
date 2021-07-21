extern "C" {
#include "z_en_sw.hpp"

#define FLAGS 0x00000035

void EnSw_Init(Actor* actor, GameState* state);
void EnSw_Destroy(Actor* actor, GameState* state);
void EnSw_Update(Actor* actor, GameState* state);
void EnSw_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Sw_InitVars = {
    ACTOR_EN_SW,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ST,
    sizeof(EnSw),
    (ActorFunc)EnSw_Init,
    (ActorFunc)EnSw_Destroy,
    (ActorFunc)EnSw_Update,
    (ActorFunc)EnSw_Draw,
};
*/
}
