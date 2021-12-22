extern "C" {
#include "z_bg_ydan_sp.hpp"

#define FLAGS 0x80000000

void BgYdanSp_Init(Actor* actor, GameState* state);
void BgYdanSp_Destroy(Actor* actor, GameState* state);
void BgYdanSp_Update(Actor* actor, GameState* state);
void BgYdanSp_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Ydan_Sp.data.o")

/*
ActorInit Bg_Ydan_Sp_InitVars = {
    ACTOR_BG_YDAN_SP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_YDAN_OBJECTS,
    sizeof(BgYdanSp),
    (ActorFunc)BgYdanSp_Init,
    (ActorFunc)BgYdanSp_Destroy,
    (ActorFunc)BgYdanSp_Update,
    (ActorFunc)BgYdanSp_Draw,
};
*/

GLOBAL_ASM("binary/BgYdanSp_Init.o")

GLOBAL_ASM("binary/BgYdanSp_Destroy.o")

GLOBAL_ASM("binary/BgYdanSp_Update.o")

GLOBAL_ASM("binary/BgYdanSp_Draw.o")
}
