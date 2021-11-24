extern "C" {
#include "z_bg_mori_hineri.hpp"

#define FLAGS 0x00400030

void BgMoriHineri_Init(Actor* actor, GameState* state);
void BgMoriHineri_Destroy(Actor* actor, GameState* state);
void BgMoriHineri_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Mori_Hineri_InitVars = {
    ACTOR_BG_MORI_HINERI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgMoriHineri),
    (ActorFunc)BgMoriHineri_Init,
    (ActorFunc)BgMoriHineri_Destroy,
    (ActorFunc)BgMoriHineri_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/BgMoriHineri_Init.o")

GLOBAL_ASM("binary/BgMoriHineri_Destroy.o")

GLOBAL_ASM("binary/BgMoriHineri_Update.o")
}
