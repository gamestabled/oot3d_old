extern "C" {
#include "z_bg_ice_turara.hpp"

#define FLAGS 0x80400000

void BgIceTurara_Init(Actor* actor, GameState* state);
void BgIceTurara_Destroy(Actor* actor, GameState* state);
void BgIceTurara_Update(Actor* actor, GameState* state);
void BgIceTurara_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Ice_Turara_InitVars = {
    ACTOR_BG_ICE_TURARA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_ICE_OBJECTS,
    sizeof(BgIceTurara),
    (ActorFunc)BgIceTurara_Init,
    (ActorFunc)BgIceTurara_Destroy,
    (ActorFunc)BgIceTurara_Update,
    (ActorFunc)BgIceTurara_Draw,
};
*/
}
