extern "C" {
#include "z_bg_mizu_movebg.hpp"

#define FLAGS 0x80400010

void BgMizuMovebg_Init(Actor* actor, GameState* state);
void BgMizuMovebg_Destroy(Actor* actor, GameState* state);
void BgMizuMovebg_Update(Actor* actor, GameState* state);
void BgMizuMovebg_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Mizu_Movebg_InitVars = {
    ACTOR_BG_MIZU_MOVEBG,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuMovebg),
    (ActorFunc)BgMizuMovebg_Init,
    (ActorFunc)BgMizuMovebg_Destroy,
    (ActorFunc)BgMizuMovebg_Update,
    (ActorFunc)BgMizuMovebg_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgMizuMovebg_Init.o")

#pragma GLOBAL_ASM("binary/BgMizuMovebg_Destroy.o")

#pragma GLOBAL_ASM("binary/BgMizuMovebg_Update.o")

#pragma GLOBAL_ASM("binary/BgMizuMovebg_Draw.o")
}
