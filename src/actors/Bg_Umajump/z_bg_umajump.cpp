extern "C" {
#include "z_bg_umajump.hpp"

#define FLAGS 0x80400030

void BgUmajump_Init(Actor* actor, GameState* state);
void BgUmajump_Destroy(Actor* actor, GameState* state);
void BgUmajump_Update(Actor* actor, GameState* state);
void BgUmajump_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Umajump_InitVars = {
    ACTOR_BG_UMAJUMP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_UMAJUMP,
    sizeof(BgUmajump),
    (ActorFunc)BgUmajump_Init,
    (ActorFunc)BgUmajump_Destroy,
    (ActorFunc)BgUmajump_Update,
    (ActorFunc)BgUmajump_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgUmajump_Init.o")

#pragma GLOBAL_ASM("binary/BgUmajump_Destroy.o")

#pragma GLOBAL_ASM("binary/BgUmajump_Update.o")

#pragma GLOBAL_ASM("binary/BgUmajump_Draw.o")
}
