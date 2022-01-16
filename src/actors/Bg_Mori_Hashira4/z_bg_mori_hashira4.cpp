extern "C" {
#include "z_bg_mori_hashira4.hpp"

#define FLAGS 0x00000010

void BgMoriHashira4_Init(Actor* actor, GameState* state);
void BgMoriHashira4_Destroy(Actor* actor, GameState* state);
void BgMoriHashira4_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Mori_Hashira4.data.o")

ActorInit Bg_Mori_Hashira4_InitVars = {
    ACTOR_BG_MORI_HASHIRA4,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriHashira4),
    (ActorFunc)BgMoriHashira4_Init,
    (ActorFunc)BgMoriHashira4_Destroy,
    (ActorFunc)BgMoriHashira4_Update,
    NULL,
};

GLOBAL_ASM("binary/BgMoriHashira4_Init.o")

GLOBAL_ASM("binary/BgMoriHashira4_Destroy.o")

GLOBAL_ASM("binary/BgMoriHashira4_Update.o")
}
