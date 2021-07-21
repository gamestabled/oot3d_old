extern "C" {
#include "z_bg_mori_hashira4.hpp"

#define FLAGS 0x00000010

void BgMoriHashira4_Init(Actor* actor, GameState* state);
void BgMoriHashira4_Destroy(Actor* actor, GameState* state);
void BgMoriHashira4_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Mori_Hashira4_InitVars = {
    ACTOR_BG_MORI_HASHIRA4,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriHashira4),
    (ActorFunc)BgMoriHashira4_Init,
    (ActorFunc)BgMoriHashira4_Destroy,
    (ActorFunc)BgMoriHashira4_Update,
    (ActorFunc)NULL,
};
*/
}
