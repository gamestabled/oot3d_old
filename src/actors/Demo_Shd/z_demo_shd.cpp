extern "C" {
#include "z_demo_shd.hpp"

#define FLAGS 0x00000030

void DemoShd_Init(Actor* actor, GameState* state);
void DemoShd_Destroy(Actor* actor, GameState* state);
void DemoShd_Update(Actor* actor, GameState* state);
void DemoShd_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Shd_InitVars = {
    ACTOR_DEMO_SHD,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(DemoShd),
    (ActorFunc)DemoShd_Init,
    (ActorFunc)DemoShd_Destroy,
    (ActorFunc)DemoShd_Update,
    (ActorFunc)DemoShd_Draw,
};
*/

#pragma GLOBAL_ASM("binary/DemoShd_Init.o")

#pragma GLOBAL_ASM("binary/DemoShd_Destroy.o")

#pragma GLOBAL_ASM("binary/DemoShd_Update.o")

#pragma GLOBAL_ASM("binary/DemoShd_Draw.o")
}
