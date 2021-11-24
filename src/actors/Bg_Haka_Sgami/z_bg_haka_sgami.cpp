extern "C" {
#include "z_bg_haka_sgami.hpp"

#define FLAGS 0x80400011

void BgHakaSgami_Init(Actor* actor, GameState* state);
void BgHakaSgami_Destroy(Actor* actor, GameState* state);
void BgHakaSgami_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Haka_Sgami_InitVars = {
    ACTOR_BG_HAKA_SGAMI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgHakaSgami),
    (ActorFunc)BgHakaSgami_Init,
    (ActorFunc)BgHakaSgami_Destroy,
    (ActorFunc)BgHakaSgami_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/BgHakaSgami_Init.o")

GLOBAL_ASM("binary/BgHakaSgami_Destroy.o")

GLOBAL_ASM("binary/BgHakaSgami_Update.o")
}
