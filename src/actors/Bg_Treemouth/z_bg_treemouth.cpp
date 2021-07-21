extern "C" {
#include "z_bg_treemouth.hpp"

#define FLAGS 0x80400030

void BgTreemouth_Init(Actor* actor, GameState* state);
void BgTreemouth_Destroy(Actor* actor, GameState* state);
void BgTreemouth_Update(Actor* actor, GameState* state);
void BgTreemouth_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Treemouth_InitVars = {
    ACTOR_BG_TREEMOUTH,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT04_OBJECTS,
    sizeof(BgTreemouth),
    (ActorFunc)BgTreemouth_Init,
    (ActorFunc)BgTreemouth_Destroy,
    (ActorFunc)BgTreemouth_Update,
    (ActorFunc)BgTreemouth_Draw,
};
*/
}
