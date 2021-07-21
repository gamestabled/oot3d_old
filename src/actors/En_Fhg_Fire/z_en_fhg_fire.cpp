extern "C" {
#include "z_en_fhg_fire.hpp"

#define FLAGS 0x00000030

void EnFhgFire_Init(Actor* actor, GameState* state);
void EnFhgFire_Destroy(Actor* actor, GameState* state);
void EnFhgFire_Update(Actor* actor, GameState* state);
void EnFhgFire_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Fhg_Fire_InitVars = {
    ACTOR_PLAYER,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_FHG,
    sizeof(EnFhgFire),
    (ActorFunc)EnFhgFire_Init,
    (ActorFunc)EnFhgFire_Destroy,
    (ActorFunc)EnFhgFire_Update,
    (ActorFunc)EnFhgFire_Draw,
};
*/
}
