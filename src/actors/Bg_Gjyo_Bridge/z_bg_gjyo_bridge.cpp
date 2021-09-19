extern "C" {
#include "z_bg_gjyo_bridge.hpp"

#define FLAGS 0x80000020

void BgGjyoBridge_Init(Actor* actor, GameState* state);
void BgGjyoBridge_Destroy(Actor* actor, GameState* state);
void BgGjyoBridge_Update(Actor* actor, GameState* state);
void BgGjyoBridge_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Gjyo_Bridge_InitVars = {
    ACTOR_BG_GJYO_BRIDGE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GJYO_OBJECTS,
    sizeof(BgGjyoBridge),
    (ActorFunc)BgGjyoBridge_Init,
    (ActorFunc)BgGjyoBridge_Destroy,
    (ActorFunc)BgGjyoBridge_Update,
    (ActorFunc)BgGjyoBridge_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgGjyoBridge_Init.o")

#pragma GLOBAL_ASM("binary/BgGjyoBridge_Destroy.o")

#pragma GLOBAL_ASM("binary/BgGjyoBridge_Update.o")

#pragma GLOBAL_ASM("binary/BgGjyoBridge_Draw.o")
}
