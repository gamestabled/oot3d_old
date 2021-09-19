extern "C" {
#include "z_bg_jya_block.hpp"

#define FLAGS 0x80000000

void BgJyaBlock_Init(Actor* actor, GameState* state);
void BgJyaBlock_Destroy(Actor* actor, GameState* state);
void BgJyaBlock_Update(Actor* actor, GameState* state);
void BgJyaBlock_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Jya_Block_InitVars = {
    ACTOR_BG_JYA_BLOCK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(BgJyaBlock),
    (ActorFunc)BgJyaBlock_Init,
    (ActorFunc)BgJyaBlock_Destroy,
    (ActorFunc)BgJyaBlock_Update,
    (ActorFunc)BgJyaBlock_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgJyaBlock_Init.o")

#pragma GLOBAL_ASM("binary/BgJyaBlock_Destroy.o")

#pragma GLOBAL_ASM("binary/BgJyaBlock_Update.o")

#pragma GLOBAL_ASM("binary/BgJyaBlock_Draw.o")
}
