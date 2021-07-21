extern "C" {
#include "z_bg_gnd_iceblock.hpp"

#define FLAGS 0x80400030

void BgGndIceblock_Init(Actor* actor, GameState* state);
void BgGndIceblock_Destroy(Actor* actor, GameState* state);
void BgGndIceblock_Update(Actor* actor, GameState* state);
void BgGndIceblock_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Gnd_Iceblock_InitVars = {
    ACTOR_BG_GND_ICEBLOCK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndIceblock),
    (ActorFunc)BgGndIceblock_Init,
    (ActorFunc)BgGndIceblock_Destroy,
    (ActorFunc)BgGndIceblock_Update,
    (ActorFunc)BgGndIceblock_Draw,
};
*/
}
