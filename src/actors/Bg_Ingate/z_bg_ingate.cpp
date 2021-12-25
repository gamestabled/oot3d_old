extern "C" {
#include "z_bg_ingate.hpp"

#define FLAGS 0x80400030

void BgIngate_Init(Actor* actor, GameState* state);
void BgIngate_Destroy(Actor* actor, GameState* state);
void BgIngate_Update(Actor* actor, GameState* state);
void BgIngate_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Ingate.data.o")

/*
ActorInit Bg_Ingate_InitVars = {
    ACTOR_BG_INGATE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_INGATE,
    sizeof(BgIngate),
    (ActorFunc)BgIngate_Init,
    (ActorFunc)BgIngate_Destroy,
    (ActorFunc)BgIngate_Update,
    (ActorFunc)BgIngate_Draw,
};
*/

GLOBAL_ASM("binary/BgIngate_Init.o")

GLOBAL_ASM("binary/BgIngate_Destroy.o")

GLOBAL_ASM("binary/BgIngate_Update.o")

GLOBAL_ASM("binary/BgIngate_Draw.o")
}
