extern "C" {
#include "z_en_m_thunder.hpp"

#define FLAGS 0x00000000

void EnMThunder_Init(Actor* actor, GameState* state);
void EnMThunder_Destroy(Actor* actor, GameState* state);
void EnMThunder_Update(Actor* actor, GameState* state);
void EnMThunder_Draw(Actor* actor, GameState* state);

/*
ActorInit En_M_Thunder_InitVars = {
    ACTOR_EN_M_THUNDER,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnMThunder),
    (ActorFunc)EnMThunder_Init,
    (ActorFunc)EnMThunder_Destroy,
    (ActorFunc)EnMThunder_Update,
    (ActorFunc)EnMThunder_Draw,
};
*/
}
