extern "C" {
#include "z_bg_mori_kaitenkabe.hpp"

#define FLAGS 0x80400020

void BgMoriKaitenkabe_Init(Actor* actor, GameState* state);
void BgMoriKaitenkabe_Destroy(Actor* actor, GameState* state);
void BgMoriKaitenkabe_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Mori_Kaitenkabe_InitVars = {
    ACTOR_BG_MORI_KAITENKABE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriKaitenkabe),
    (ActorFunc)BgMoriKaitenkabe_Init,
    (ActorFunc)BgMoriKaitenkabe_Destroy,
    (ActorFunc)BgMoriKaitenkabe_Update,
    (ActorFunc)NULL,
};
*/
}
