extern "C" {
#include "z_bg_mori_bigst.hpp"

#define FLAGS 0x80400010

void BgMoriBigst_Init(Actor* actor, GameState* state);
void BgMoriBigst_Destroy(Actor* actor, GameState* state);
void BgMoriBigst_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Mori_Bigst_InitVars = {
    ACTOR_BG_MORI_BIGST,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriBigst),
    (ActorFunc)BgMoriBigst_Init,
    (ActorFunc)BgMoriBigst_Destroy,
    (ActorFunc)BgMoriBigst_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/BgMoriBigst_Init.o")

#pragma GLOBAL_ASM("binary/BgMoriBigst_Destroy.o")

#pragma GLOBAL_ASM("binary/BgMoriBigst_Update.o")
}
