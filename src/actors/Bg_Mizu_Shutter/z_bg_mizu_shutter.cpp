extern "C" {
#include "z_bg_mizu_shutter.hpp"

#define FLAGS 0x80000010

void BgMizuShutter_Init(Actor* actor, GameState* state);
void BgMizuShutter_Destroy(Actor* actor, GameState* state);
void BgMizuShutter_Update(Actor* actor, GameState* state);
void BgMizuShutter_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Mizu_Shutter_InitVars = {
    ACTOR_BG_MIZU_SHUTTER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuShutter),
    (ActorFunc)BgMizuShutter_Init,
    (ActorFunc)BgMizuShutter_Destroy,
    (ActorFunc)BgMizuShutter_Update,
    (ActorFunc)BgMizuShutter_Draw,
};
*/

GLOBAL_ASM("binary/BgMizuShutter_Init.o")

GLOBAL_ASM("binary/BgMizuShutter_Destroy.o")

GLOBAL_ASM("binary/BgMizuShutter_Update.o")

GLOBAL_ASM("binary/BgMizuShutter_Draw.o")
}
