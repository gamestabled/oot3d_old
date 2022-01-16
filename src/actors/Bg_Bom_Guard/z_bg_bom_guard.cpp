extern "C" {
#include "z_bg_bom_guard.hpp"

#define FLAGS 0x80400010

void BgBomGuard_Init(Actor* actor, GameState* state);
void BgBomGuard_Destroy(Actor* actor, GameState* state);
void BgBomGuard_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Bom_Guard.data.o")

ActorInit Bg_Bom_Guard_InitVars = {
    ACTOR_BG_BOM_GUARD,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BOWL,
    sizeof(BgBomGuard),
    (ActorFunc)BgBomGuard_Init,
    (ActorFunc)BgBomGuard_Destroy,
    (ActorFunc)BgBomGuard_Update,
    NULL,
};

GLOBAL_ASM("binary/BgBomGuard_Init.o")

GLOBAL_ASM("binary/BgBomGuard_Destroy.o")

GLOBAL_ASM("binary/BgBomGuard_Update.o")
}
