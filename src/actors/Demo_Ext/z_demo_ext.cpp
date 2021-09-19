extern "C" {
#include "z_demo_ext.hpp"

#define FLAGS 0x80000010

void DemoExt_Init(Actor* actor, GameState* state);
void DemoExt_Destroy(Actor* actor, GameState* state);
void DemoExt_Update(Actor* actor, GameState* state);
void DemoExt_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Ext_InitVars = {
    ACTOR_DEMO_EXT,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_FHG,
    sizeof(DemoExt),
    (ActorFunc)DemoExt_Init,
    (ActorFunc)DemoExt_Destroy,
    (ActorFunc)DemoExt_Update,
    (ActorFunc)DemoExt_Draw,
};
*/

#pragma GLOBAL_ASM("binary/DemoExt_Init.o")

#pragma GLOBAL_ASM("binary/DemoExt_Destroy.o")

#pragma GLOBAL_ASM("binary/DemoExt_Update.o")

#pragma GLOBAL_ASM("binary/DemoExt_Draw.o")
}
