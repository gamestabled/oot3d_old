extern "C" {
#include "z_bg_spot18_shutter.hpp"

#define FLAGS 0x80400030

void BgSpot18Shutter_Init(Actor* actor, GameState* state);
void BgSpot18Shutter_Destroy(Actor* actor, GameState* state);
void BgSpot18Shutter_Update(Actor* actor, GameState* state);
void BgSpot18Shutter_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Spot18_Shutter.data.o")

/*
ActorInit Bg_Spot18_Shutter_InitVars = {
    ACTOR_BG_SPOT18_SHUTTER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT18_OBJ,
    sizeof(BgSpot18Shutter),
    (ActorFunc)BgSpot18Shutter_Init,
    (ActorFunc)BgSpot18Shutter_Destroy,
    (ActorFunc)BgSpot18Shutter_Update,
    (ActorFunc)BgSpot18Shutter_Draw,
};
*/

GLOBAL_ASM("binary/BgSpot18Shutter_Init.o")

GLOBAL_ASM("binary/BgSpot18Shutter_Destroy.o")

GLOBAL_ASM("binary/BgSpot18Shutter_Update.o")

GLOBAL_ASM("binary/BgSpot18Shutter_Draw.o")
}
