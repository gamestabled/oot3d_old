extern "C" {
#include "z_bg_po_syokudai.hpp"

#define FLAGS 0x80000000

void BgPoSyokudai_Init(Actor* actor, GameState* state);
void BgPoSyokudai_Destroy(Actor* actor, GameState* state);
void BgPoSyokudai_Update(Actor* actor, GameState* state);
void BgPoSyokudai_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Po_Syokudai_InitVars = {
    ACTOR_BG_PO_SYOKUDAI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SYOKUDAI,
    sizeof(BgPoSyokudai),
    (ActorFunc)BgPoSyokudai_Init,
    (ActorFunc)BgPoSyokudai_Destroy,
    (ActorFunc)BgPoSyokudai_Update,
    (ActorFunc)BgPoSyokudai_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgPoSyokudai_Init.o")

#pragma GLOBAL_ASM("binary/BgPoSyokudai_Destroy.o")

#pragma GLOBAL_ASM("binary/BgPoSyokudai_Update.o")

#pragma GLOBAL_ASM("binary/BgPoSyokudai_Draw.o")
}
