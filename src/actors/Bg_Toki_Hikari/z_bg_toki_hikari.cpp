extern "C" {
#include "z_bg_toki_hikari.hpp"

#define FLAGS 0x80400020

void BgTokiHikari_Init(Actor* actor, GameState* state);
void BgTokiHikari_Destroy(Actor* actor, GameState* state);
void BgTokiHikari_Update(Actor* actor, GameState* state);
void BgTokiHikari_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Toki_Hikari_InitVars = {
    ACTOR_BG_TOKI_HIKARI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_TOKI_OBJECTS,
    sizeof(BgTokiHikari),
    (ActorFunc)BgTokiHikari_Init,
    (ActorFunc)BgTokiHikari_Destroy,
    (ActorFunc)BgTokiHikari_Update,
    (ActorFunc)BgTokiHikari_Draw,
};
*/
}
