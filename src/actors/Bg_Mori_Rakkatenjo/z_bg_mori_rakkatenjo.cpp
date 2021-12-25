extern "C" {
#include "z_bg_mori_rakkatenjo.hpp"

#define FLAGS 0x80400030

void BgMoriRakkatenjo_Init(Actor* actor, GameState* state);
void BgMoriRakkatenjo_Destroy(Actor* actor, GameState* state);
void BgMoriRakkatenjo_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Mori_Rakkatenjo.data.o")

/*
ActorInit Bg_Mori_Rakkatenjo_InitVars = {
    ACTOR_BG_MORI_RAKKATENJO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriRakkatenjo),
    (ActorFunc)BgMoriRakkatenjo_Init,
    (ActorFunc)BgMoriRakkatenjo_Destroy,
    (ActorFunc)BgMoriRakkatenjo_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/BgMoriRakkatenjo_Init.o")

GLOBAL_ASM("binary/BgMoriRakkatenjo_Destroy.o")

GLOBAL_ASM("binary/BgMoriRakkatenjo_Update.o")
}
