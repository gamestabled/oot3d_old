extern "C" {
#include "z_bg_heavy_block.hpp"

#define FLAGS 0x80000000

void BgHeavyBlock_Init(Actor* actor, GameState* state);
void BgHeavyBlock_Destroy(Actor* actor, GameState* state);
void BgHeavyBlock_Update(Actor* actor, GameState* state);
void BgHeavyBlock_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Heavy_Block.data.o")

ActorInit Bg_Heavy_Block_InitVars = {
    ACTOR_BG_HEAVY_BLOCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HEAVY_OBJECT,
    sizeof(BgHeavyBlock),
    (ActorFunc)BgHeavyBlock_Init,
    (ActorFunc)BgHeavyBlock_Destroy,
    (ActorFunc)BgHeavyBlock_Update,
    (ActorFunc)BgHeavyBlock_Draw,
};

GLOBAL_ASM("binary/BgHeavyBlock_Init.o")

GLOBAL_ASM("binary/BgHeavyBlock_Destroy.o")

GLOBAL_ASM("binary/BgHeavyBlock_Update.o")

GLOBAL_ASM("binary/BgHeavyBlock_Draw.o")
}
