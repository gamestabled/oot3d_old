extern "C" {
#include "z_bg_mori_idomizu.hpp"

#define FLAGS 0x80400030

void BgMoriIdomizu_Init(Actor* actor, GameState* state);
void BgMoriIdomizu_Destroy(Actor* actor, GameState* state);
void BgMoriIdomizu_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Mori_Idomizu_InitVars = {
    ACTOR_BG_MORI_IDOMIZU,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriIdomizu),
    (ActorFunc)BgMoriIdomizu_Init,
    (ActorFunc)BgMoriIdomizu_Destroy,
    (ActorFunc)BgMoriIdomizu_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/BgMoriIdomizu_Init.o")

#pragma GLOBAL_ASM("binary/BgMoriIdomizu_Destroy.o")

#pragma GLOBAL_ASM("binary/BgMoriIdomizu_Update.o")
}
