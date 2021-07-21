extern "C" {
#include "z_bg_gnd_nisekabe.hpp"

#define FLAGS 0x80400010

void BgGndNisekabe_Init(Actor* actor, GameState* state);
void BgGndNisekabe_Destroy(Actor* actor, GameState* state);
void BgGndNisekabe_Update(Actor* actor, GameState* state);
void BgGndNisekabe_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Gnd_Nisekabe_InitVars = {
    ACTOR_BG_GND_NISEKABE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndNisekabe),
    (ActorFunc)BgGndNisekabe_Init,
    (ActorFunc)BgGndNisekabe_Destroy,
    (ActorFunc)BgGndNisekabe_Update,
    (ActorFunc)BgGndNisekabe_Draw,
};
*/
}
