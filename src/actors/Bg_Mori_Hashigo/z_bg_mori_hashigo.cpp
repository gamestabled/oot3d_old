extern "C" {
#include "z_bg_mori_hashigo.hpp"

#define FLAGS 0x80400000

void BgMoriHashigo_Init(Actor* actor, GameState* state);
void BgMoriHashigo_Destroy(Actor* actor, GameState* state);
void BgMoriHashigo_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Mori_Hashigo_InitVars = {
    ACTOR_BG_MORI_HASHIGO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriHashigo),
    (ActorFunc)BgMoriHashigo_Init,
    (ActorFunc)BgMoriHashigo_Destroy,
    (ActorFunc)BgMoriHashigo_Update,
    (ActorFunc)NULL,
};
*/
}
