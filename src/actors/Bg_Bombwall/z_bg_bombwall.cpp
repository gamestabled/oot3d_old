extern "C" {
#include "z_bg_bombwall.hpp"

#define FLAGS 0x80400000

void BgBombwall_Init(Actor* actor, GameState* state);
void BgBombwall_Destroy(Actor* actor, GameState* state);
void BgBombwall_Update(Actor* actor, GameState* state);
void BgBombwall_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Bombwall_InitVars = {
    ACTOR_BG_BOMBWALL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(BgBombwall),
    (ActorFunc)BgBombwall_Init,
    (ActorFunc)BgBombwall_Destroy,
    (ActorFunc)BgBombwall_Update,
    (ActorFunc)BgBombwall_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgBombwall_Init.o")

#pragma GLOBAL_ASM("binary/BgBombwall_Destroy.o")

#pragma GLOBAL_ASM("binary/BgBombwall_Update.o")

#pragma GLOBAL_ASM("binary/BgBombwall_Draw.o")
}
