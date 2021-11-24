extern "C" {
#include "z_bg_hidan_curtain.hpp"

#define FLAGS 0x80400010

void BgHidanCurtain_Init(Actor* actor, GameState* state);
void BgHidanCurtain_Destroy(Actor* actor, GameState* state);
void BgHidanCurtain_Update(Actor* actor, GameState* state);
void BgHidanCurtain_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Hidan_Curtain_InitVars = {
    ACTOR_BG_HIDAN_CURTAIN,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgHidanCurtain),
    (ActorFunc)BgHidanCurtain_Init,
    (ActorFunc)BgHidanCurtain_Destroy,
    (ActorFunc)BgHidanCurtain_Update,
    (ActorFunc)BgHidanCurtain_Draw,
};
*/

GLOBAL_ASM("binary/BgHidanCurtain_Init.o")

GLOBAL_ASM("binary/BgHidanCurtain_Destroy.o")

GLOBAL_ASM("binary/BgHidanCurtain_Update.o")

GLOBAL_ASM("binary/BgHidanCurtain_Draw.o")
}
