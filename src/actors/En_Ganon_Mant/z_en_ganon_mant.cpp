extern "C" {
#include "z_en_ganon_mant.hpp"

#define FLAGS 0x00000030

void EnGanonMant_Init(Actor* actor, GameState* state);
void EnGanonMant_Destroy(Actor* actor, GameState* state);
void EnGanonMant_Update(Actor* actor, GameState* state);

/*
ActorInit En_Ganon_Mant_InitVars = {
    ACTOR_EN_GANON_MANT,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnGanonMant),
    (ActorFunc)EnGanonMant_Init,
    (ActorFunc)EnGanonMant_Destroy,
    (ActorFunc)EnGanonMant_Update,
    (ActorFunc)NULL,
};
*/
}
