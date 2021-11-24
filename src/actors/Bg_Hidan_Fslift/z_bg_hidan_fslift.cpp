extern "C" {
#include "z_bg_hidan_fslift.hpp"

#define FLAGS 0x80400010

void BgHidanFslift_Init(Actor* actor, GameState* state);
void BgHidanFslift_Destroy(Actor* actor, GameState* state);
void BgHidanFslift_Update(Actor* actor, GameState* state);
void BgHidanFslift_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Hidan_Fslift_InitVars = {
    ACTOR_BG_HIDAN_FSLIFT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanFslift),
    (ActorFunc)BgHidanFslift_Init,
    (ActorFunc)BgHidanFslift_Destroy,
    (ActorFunc)BgHidanFslift_Update,
    (ActorFunc)BgHidanFslift_Draw,
};
*/

GLOBAL_ASM("binary/BgHidanFslift_Init.o")

GLOBAL_ASM("binary/BgHidanFslift_Destroy.o")

GLOBAL_ASM("binary/BgHidanFslift_Update.o")

GLOBAL_ASM("binary/BgHidanFslift_Draw.o")
}
