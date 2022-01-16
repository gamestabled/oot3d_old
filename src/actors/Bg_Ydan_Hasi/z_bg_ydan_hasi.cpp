extern "C" {
#include "z_bg_ydan_hasi.hpp"

#define FLAGS 0x80400030

void BgYdanHasi_Init(Actor* actor, GameState* state);
void BgYdanHasi_Destroy(Actor* actor, GameState* state);
void BgYdanHasi_Update(Actor* actor, GameState* state);
void BgYdanHasi_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Ydan_Hasi.data.o")

ActorInit Bg_Ydan_Hasi_InitVars = {
    ACTOR_BG_YDAN_HASI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_YDAN_OBJECTS,
    sizeof(BgYdanHasi),
    (ActorFunc)BgYdanHasi_Init,
    (ActorFunc)BgYdanHasi_Destroy,
    (ActorFunc)BgYdanHasi_Update,
    (ActorFunc)BgYdanHasi_Draw,
};

GLOBAL_ASM("binary/BgYdanHasi_Init.o")

GLOBAL_ASM("binary/BgYdanHasi_Destroy.o")

GLOBAL_ASM("binary/BgYdanHasi_Update.o")

GLOBAL_ASM("binary/BgYdanHasi_Draw.o")
}
