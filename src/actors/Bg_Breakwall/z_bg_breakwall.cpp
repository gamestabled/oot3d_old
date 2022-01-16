extern "C" {
#include "z_bg_breakwall.hpp"

#define FLAGS 0x00400010

void BgBreakwall_Init(Actor* actor, GameState* state);
void BgBreakwall_Destroy(Actor* actor, GameState* state);
void BgBreakwall_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Breakwall.data.o")

ActorInit Bg_Breakwall_InitVars = {
    ACTOR_BG_BREAKWALL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgBreakwall),
    (ActorFunc)BgBreakwall_Init,
    (ActorFunc)BgBreakwall_Destroy,
    (ActorFunc)BgBreakwall_Update,
    NULL,
};

GLOBAL_ASM("binary/BgBreakwall_Init.o")

GLOBAL_ASM("binary/BgBreakwall_Destroy.o")

GLOBAL_ASM("binary/BgBreakwall_Update.o")
}
