extern "C" {
#include "z_bg_bdan_switch.hpp"

#define FLAGS 0x80400010

void BgBdanSwitch_Init(Actor* actor, GameState* state);
void BgBdanSwitch_Destroy(Actor* actor, GameState* state);
void BgBdanSwitch_Update(Actor* actor, GameState* state);
void BgBdanSwitch_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Bgan_Switch.data.o")

/*
ActorInit Bg_Bdan_Switch_InitVars = {
    ACTOR_BG_BDAN_SWITCH,
    ACTORCAT_SWITCH,
    FLAGS,
    OBJECT_BDAN_OBJECTS,
    sizeof(BgBdanSwitch),
    (ActorFunc)BgBdanSwitch_Init,
    (ActorFunc)BgBdanSwitch_Destroy,
    (ActorFunc)BgBdanSwitch_Update,
    (ActorFunc)BgBdanSwitch_Draw,
};
*/

GLOBAL_ASM("binary/BgBdanSwitch_Init.o")

GLOBAL_ASM("binary/BgBdanSwitch_Destroy.o")

GLOBAL_ASM("binary/BgBdanSwitch_Update.o")

GLOBAL_ASM("binary/BgBdanSwitch_Draw.o")
}
