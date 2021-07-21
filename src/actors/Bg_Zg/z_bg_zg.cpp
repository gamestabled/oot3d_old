extern "C" {
#include "z_bg_zg.hpp"

#define FLAGS 0x80000010

void BgZg_Init(Actor* actor, GameState* state);
void BgZg_Destroy(Actor* actor, GameState* state);
void BgZg_Update(Actor* actor, GameState* state);
void BgZg_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Zg_InitVars = {
    ACTOR_BG_ZG,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZG,
    sizeof(BgZg),
    (ActorFunc)BgZg_Init,
    (ActorFunc)BgZg_Destroy,
    (ActorFunc)BgZg_Update,
    (ActorFunc)BgZg_Draw,
};
*/
}
