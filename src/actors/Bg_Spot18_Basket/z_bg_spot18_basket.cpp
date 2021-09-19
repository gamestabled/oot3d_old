extern "C" {
#include "z_bg_spot18_basket.hpp"

#define FLAGS 0x80400010

void BgSpot18Basket_Init(Actor* actor, GameState* state);
void BgSpot18Basket_Destroy(Actor* actor, GameState* state);
void BgSpot18Basket_Update(Actor* actor, GameState* state);
void BgSpot18Basket_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Spot18_Basket_InitVars = {
    ACTOR_BG_SPOT18_BASKET,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT18_OBJ,
    sizeof(BgSpot18Basket),
    (ActorFunc)BgSpot18Basket_Init,
    (ActorFunc)BgSpot18Basket_Destroy,
    (ActorFunc)BgSpot18Basket_Update,
    (ActorFunc)BgSpot18Basket_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgSpot18Basket_Init.o")

#pragma GLOBAL_ASM("binary/BgSpot18Basket_Destroy.o")

#pragma GLOBAL_ASM("binary/BgSpot18Basket_Update.o")

#pragma GLOBAL_ASM("binary/BgSpot18Basket_Draw.o")
}
