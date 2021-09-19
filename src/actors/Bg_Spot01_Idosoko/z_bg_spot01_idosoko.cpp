extern "C" {
#include "z_bg_spot01_idosoko.hpp"

#define FLAGS 0x80400010

void BgSpot01Idosoko_Init(Actor* actor, GameState* state);
void BgSpot01Idosoko_Destroy(Actor* actor, GameState* state);
void BgSpot01Idosoko_Update(Actor* actor, GameState* state);
void BgSpot01Idosoko_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Spot01_Idosoko_InitVars = {
    ACTOR_BG_SPOT01_IDOSOKO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT01_MATOYA,
    sizeof(BgSpot01Idosoko),
    (ActorFunc)BgSpot01Idosoko_Init,
    (ActorFunc)BgSpot01Idosoko_Destroy,
    (ActorFunc)BgSpot01Idosoko_Update,
    (ActorFunc)BgSpot01Idosoko_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgSpot01Idosoko_Init.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idosoko_Destroy.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idosoko_Update.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idosoko_Draw.o")
}
