extern "C" {
#include "z_bg_hidan_kowarerukabe.hpp"

#define FLAGS 0x80400030

void BgHidanKowarerukabe_Init(Actor* actor, GameState* state);
void BgHidanKowarerukabe_Destroy(Actor* actor, GameState* state);
void BgHidanKowarerukabe_Update(Actor* actor, GameState* state);
void BgHidanKowarerukabe_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Hidan_Kowarerukabe.data.o")

/*
ActorInit Bg_Hidan_Kowarerukabe_InitVars = {
    ACTOR_BG_HIDAN_KOWARERUKABE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanKowarerukabe),
    (ActorFunc)BgHidanKowarerukabe_Init,
    (ActorFunc)BgHidanKowarerukabe_Destroy,
    (ActorFunc)BgHidanKowarerukabe_Update,
    (ActorFunc)BgHidanKowarerukabe_Draw,
};
*/

GLOBAL_ASM("binary/BgHidanKowarerukabe_Init.o")

GLOBAL_ASM("binary/BgHidanKowarerukabe_Destroy.o")

GLOBAL_ASM("binary/BgHidanKowarerukabe_Update.o")

GLOBAL_ASM("binary/BgHidanKowarerukabe_Draw.o")
}
