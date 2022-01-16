extern "C" {
#include "z_demo_ext.hpp"

#define FLAGS 0x80000010

void DemoExt_Init(Actor* actor, GameState* state);
void DemoExt_Destroy(Actor* actor, GameState* state);
void DemoExt_Update(Actor* actor, GameState* state);
void DemoExt_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Demo_Ext.data.o")

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

GLOBAL_ASM("binary/DemoExt_Init.o")

GLOBAL_ASM("binary/DemoExt_Destroy.o")

GLOBAL_ASM("binary/DemoExt_Update.o")

GLOBAL_ASM("binary/DemoExt_Draw.o")
}
