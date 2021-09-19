extern "C" {
#include "z_bg_gnd_darkmeiro.hpp"

#define FLAGS 0x80400030

void BgGndDarkmeiro_Init(Actor* actor, GameState* state);
void BgGndDarkmeiro_Destroy(Actor* actor, GameState* state);
void BgGndDarkmeiro_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Gnd_Darkmeiro_InitVars = {
    ACTOR_BG_GND_DARKMEIRO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndDarkmeiro),
    (ActorFunc)BgGndDarkmeiro_Init,
    (ActorFunc)BgGndDarkmeiro_Destroy,
    (ActorFunc)BgGndDarkmeiro_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/BgGndDarkmeiro_Init.o")

#pragma GLOBAL_ASM("binary/BgGndDarkmeiro_Destroy.o")

#pragma GLOBAL_ASM("binary/BgGndDarkmeiro_Update.o")
}
