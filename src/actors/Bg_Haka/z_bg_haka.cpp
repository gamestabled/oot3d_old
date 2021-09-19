extern "C" {
#include "z_bg_haka.hpp"

#define FLAGS 0x00000000

void BgHaka_Init(Actor* actor, GameState* state);
void BgHaka_Destroy(Actor* actor, GameState* state);
void BgHaka_Update(Actor* actor, GameState* state);
void BgHaka_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Haka_InitVars = {
    ACTOR_BG_HAKA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA,
    sizeof(BgHaka),
    (ActorFunc)BgHaka_Init,
    (ActorFunc)BgHaka_Destroy,
    (ActorFunc)BgHaka_Update,
    (ActorFunc)BgHaka_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgHaka_Init.o")

#pragma GLOBAL_ASM("binary/BgHaka_Destroy.o")

#pragma GLOBAL_ASM("binary/BgHaka_Update.o")

#pragma GLOBAL_ASM("binary/BgHaka_Draw.o")
}
