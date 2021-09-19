extern "C" {
#include "z_bg_spot01_idomizu.hpp"

#define FLAGS 0x80400030

void BgSpot01Idomizu_Init(Actor* actor, GameState* state);
void BgSpot01Idomizu_Destroy(Actor* actor, GameState* state);
void BgSpot01Idomizu_Update(Actor* actor, GameState* state);
void BgSpot01Idomizu_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Spot01_Idomizu_InitVars = {
    ACTOR_BG_SPOT01_IDOMIZU,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT01_OBJECTS,
    sizeof(BgSpot01Idomizu),
    (ActorFunc)BgSpot01Idomizu_Init,
    (ActorFunc)BgSpot01Idomizu_Destroy,
    (ActorFunc)BgSpot01Idomizu_Update,
    (ActorFunc)BgSpot01Idomizu_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgSpot01Idomizu_Init.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idomizu_Destroy.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idomizu_Update.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idomizu_Draw.o")
}
