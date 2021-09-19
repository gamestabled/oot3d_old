extern "C" {
#include "z_bg_hidan_syoku.hpp"

#define FLAGS 0x80400010

void BgHidanSyoku_Init(Actor* actor, GameState* state);
void BgHidanSyoku_Destroy(Actor* actor, GameState* state);
void BgHidanSyoku_Update(Actor* actor, GameState* state);
void BgHidanSyoku_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Hidan_Syoku_InitVars = {
    ACTOR_BG_HIDAN_SYOKU,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanSyoku),
    (ActorFunc)BgHidanSyoku_Init,
    (ActorFunc)BgHidanSyoku_Destroy,
    (ActorFunc)BgHidanSyoku_Update,
    (ActorFunc)BgHidanSyoku_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgHidanSyoku_Init.o")

#pragma GLOBAL_ASM("binary/BgHidanSyoku_Destroy.o")

#pragma GLOBAL_ASM("binary/BgHidanSyoku_Update.o")

#pragma GLOBAL_ASM("binary/BgHidanSyoku_Draw.o")
}
