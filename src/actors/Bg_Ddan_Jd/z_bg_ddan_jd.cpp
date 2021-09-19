extern "C" {
#include "z_bg_ddan_jd.hpp"

#define FLAGS 0x80400030

void BgDdanJd_Init(Actor* actor, GameState* state);
void BgDdanJd_Destroy(Actor* actor, GameState* state);
void BgDdanJd_Update(Actor* actor, GameState* state);
void BgDdanJd_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Ddan_Jd_InitVars = {
    ACTOR_BG_DDAN_JD,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_DDAN_OBJECTS,
    sizeof(BgDdanJd),
    (ActorFunc)BgDdanJd_Init,
    (ActorFunc)BgDdanJd_Destroy,
    (ActorFunc)BgDdanJd_Update,
    (ActorFunc)BgDdanJd_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgDdanJd_Init.o")

#pragma GLOBAL_ASM("binary/BgDdanJd_Destroy.o")

#pragma GLOBAL_ASM("binary/BgDdanJd_Update.o")

#pragma GLOBAL_ASM("binary/BgDdanJd_Draw.o")
}
