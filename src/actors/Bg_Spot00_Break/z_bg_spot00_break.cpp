extern "C" {
#include "z_bg_spot00_break.hpp"

#define FLAGS 0x00400030

void BgSpot00Break_Init(Actor* actor, GameState* state);
void BgSpot00Break_Destroy(Actor* actor, GameState* state);
void BgSpot00Break_Update(Actor* actor, GameState* state);
void BgSpot00Break_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Spot00_Break.data.o")

ActorInit Bg_Spot00_Break_InitVars = {
    ACTOR_BG_SPOT00_BREAK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT00_BREAK,
    sizeof(BgSpot00Break),
    (ActorFunc)BgSpot00Break_Init,
    (ActorFunc)BgSpot00Break_Destroy,
    (ActorFunc)BgSpot00Break_Update,
    (ActorFunc)BgSpot00Break_Draw,
};

GLOBAL_ASM("binary/BgSpot00Break_Init.o")

GLOBAL_ASM("binary/BgSpot00Break_Destroy.o")

GLOBAL_ASM("binary/BgSpot00Break_Update.o")

GLOBAL_ASM("binary/BgSpot00Break_Draw.o")
}
