extern "C" {
#include "z_bg_spot18_futa.hpp"

#define FLAGS 0x80400000

void BgSpot18Futa_Init(Actor* actor, GameState* state);
void BgSpot18Futa_Destroy(Actor* actor, GameState* state);
void BgSpot18Futa_Update(Actor* actor, GameState* state);
void BgSpot18Futa_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Spot18_Futa_InitVars = {
    ACTOR_BG_SPOT18_FUTA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT18_OBJ,
    sizeof(BgSpot18Futa),
    (ActorFunc)BgSpot18Futa_Init,
    (ActorFunc)BgSpot18Futa_Destroy,
    (ActorFunc)BgSpot18Futa_Update,
    (ActorFunc)BgSpot18Futa_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgSpot18Futa_Init.o")

#pragma GLOBAL_ASM("binary/BgSpot18Futa_Destroy.o")

#pragma GLOBAL_ASM("binary/BgSpot18Futa_Update.o")

#pragma GLOBAL_ASM("binary/BgSpot18Futa_Draw.o")
}
