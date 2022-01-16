extern "C" {
#include "z_bg_gate_shutter.hpp"

#define FLAGS 0x80400000

void BgGateShutter_Init(Actor* actor, GameState* state);
void BgGateShutter_Destroy(Actor* actor, GameState* state);
void BgGateShutter_Update(Actor* actor, GameState* state);
void BgGateShutter_Draw(Actor* actor, GameState* state);

ActorInit Bg_Gate_Shutter_InitVars = {
    ACTOR_BG_GATE_SHUTTER,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_SPOT01_MATOYAB,
    sizeof(BgGateShutter),
    (ActorFunc)BgGateShutter_Init,
    (ActorFunc)BgGateShutter_Destroy,
    (ActorFunc)BgGateShutter_Update,
    (ActorFunc)BgGateShutter_Draw,
};

GLOBAL_ASM("binary/BgGateShutter_Init.o")

GLOBAL_ASM("binary/BgGateShutter_Destroy.o")

GLOBAL_ASM("binary/BgGateShutter_Update.o")

GLOBAL_ASM("binary/BgGateShutter_Draw.o")
}
