extern "C" {
#include "z_bg_ice_objects.hpp"

#define FLAGS 0x80400030

void BgIceObjects_Init(Actor* actor, GameState* state);
void BgIceObjects_Destroy(Actor* actor, GameState* state);
void BgIceObjects_Update(Actor* actor, GameState* state);
void BgIceObjects_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Ice_Objects_InitVars = {
    ACTOR_BG_ICE_OBJECTS,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_ICE_OBJECTS,
    sizeof(BgIceObjects),
    (ActorFunc)BgIceObjects_Init,
    (ActorFunc)BgIceObjects_Destroy,
    (ActorFunc)BgIceObjects_Update,
    (ActorFunc)BgIceObjects_Draw,
};
*/

GLOBAL_ASM("binary/BgIceObjects_Init.o")

GLOBAL_ASM("binary/BgIceObjects_Destroy.o")

GLOBAL_ASM("binary/BgIceObjects_Update.o")

GLOBAL_ASM("binary/BgIceObjects_Draw.o")
}
