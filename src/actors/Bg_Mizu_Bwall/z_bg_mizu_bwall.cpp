extern "C" {
#include "z_bg_mizu_bwall.hpp"

#define FLAGS 0x80400010

void BgMizuBwall_Init(Actor* actor, GameState* state);
void BgMizuBwall_Destroy(Actor* actor, GameState* state);
void BgMizuBwall_Update(Actor* actor, GameState* state);
void BgMizuBwall_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Mizu_Bwall_InitVars = {
    ACTOR_BG_MIZU_BWALL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuBwall),
    (ActorFunc)BgMizuBwall_Init,
    (ActorFunc)BgMizuBwall_Destroy,
    (ActorFunc)BgMizuBwall_Update,
    (ActorFunc)BgMizuBwall_Draw,
};
*/

GLOBAL_ASM("binary/BgMizuBwall_Init.o")

GLOBAL_ASM("binary/BgMizuBwall_Destroy.o")

GLOBAL_ASM("binary/BgMizuBwall_Update.o")

GLOBAL_ASM("binary/BgMizuBwall_Draw.o")
}
