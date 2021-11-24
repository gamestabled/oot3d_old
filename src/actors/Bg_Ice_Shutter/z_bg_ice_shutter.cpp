extern "C" {
#include "z_bg_ice_shutter.hpp"

#define FLAGS 0x80400010

void BgIceShutter_Init(Actor* actor, GameState* state);
void BgIceShutter_Destroy(Actor* actor, GameState* state);
void BgIceShutter_Update(Actor* actor, GameState* state);
void BgIceShutter_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Ice_Shutter_InitVars = {
    ACTOR_BG_ICE_SHUTTER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_ICE_OBJECTS,
    sizeof(BgIceShutter),
    (ActorFunc)BgIceShutter_Init,
    (ActorFunc)BgIceShutter_Destroy,
    (ActorFunc)BgIceShutter_Update,
    (ActorFunc)BgIceShutter_Draw,
};
*/

GLOBAL_ASM("binary/BgIceShutter_Init.o")

GLOBAL_ASM("binary/BgIceShutter_Destroy.o")

GLOBAL_ASM("binary/BgIceShutter_Update.o")

GLOBAL_ASM("binary/BgIceShutter_Draw.o")
}
