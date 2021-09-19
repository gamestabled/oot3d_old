extern "C" {
#include "z_bg_mizu_uzu.hpp"

#define FLAGS 0x00000000

void BgMizuUzu_Init(Actor* actor, GameState* state);
void BgMizuUzu_Destroy(Actor* actor, GameState* state);
void BgMizuUzu_Update(Actor* actor, GameState* state);
void BgMizuUzu_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Mizu_Uzu_InitVars = {
    ACTOR_BG_MIZU_UZU,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuUzu),
    (ActorFunc)BgMizuUzu_Init,
    (ActorFunc)BgMizuUzu_Destroy,
    (ActorFunc)BgMizuUzu_Update,
    (ActorFunc)BgMizuUzu_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgMizuUzu_Init.o")

#pragma GLOBAL_ASM("binary/BgMizuUzu_Destroy.o")

#pragma GLOBAL_ASM("binary/BgMizuUzu_Update.o")

#pragma GLOBAL_ASM("binary/BgMizuUzu_Draw.o")
}
