extern "C" {
#include "z_bg_toki_swd.hpp"

#define FLAGS 0x80000010

void BgTokiSwd_Init(Actor* actor, GameState* state);
void BgTokiSwd_Destroy(Actor* actor, GameState* state);
void BgTokiSwd_Update(Actor* actor, GameState* state);
void BgTokiSwd_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Toki_Swd_InitVars = {
    ACTOR_BG_TOKI_SWD,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_TOKI_OBJECTS,
    sizeof(BgTokiSwd),
    (ActorFunc)BgTokiSwd_Init,
    (ActorFunc)BgTokiSwd_Destroy,
    (ActorFunc)BgTokiSwd_Update,
    (ActorFunc)BgTokiSwd_Draw,
};
*/
}