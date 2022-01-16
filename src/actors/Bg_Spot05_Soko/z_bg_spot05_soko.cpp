extern "C" {
#include "z_bg_spot05_soko.hpp"

#define FLAGS 0x80400000

void BgSpot05Soko_Init(Actor* actor, GameState* state);
void BgSpot05Soko_Destroy(Actor* actor, GameState* state);
void BgSpot05Soko_Update(Actor* actor, GameState* state);
void BgSpot05Soko_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Spot05_Soko.data.o")

ActorInit Bg_Spot05_Soko_InitVars = {
    ACTOR_BG_SPOT05_SOKO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT05_OBJECTS,
    sizeof(BgSpot05Soko),
    (ActorFunc)BgSpot05Soko_Init,
    (ActorFunc)BgSpot05Soko_Destroy,
    (ActorFunc)BgSpot05Soko_Update,
    (ActorFunc)BgSpot05Soko_Draw,
};

GLOBAL_ASM("binary/BgSpot05Soko_Init.o")

GLOBAL_ASM("binary/BgSpot05Soko_Destroy.o")

GLOBAL_ASM("binary/BgSpot05Soko_Update.o")

GLOBAL_ASM("binary/BgSpot05Soko_Draw.o")
}
