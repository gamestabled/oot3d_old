extern "C" {
#include "z_demo_go.hpp"

#define FLAGS 0x00000010

void DemoGo_Init(Actor* actor, GameState* state);
void DemoGo_Destroy(Actor* actor, GameState* state);
void DemoGo_Update(Actor* actor, GameState* state);
void DemoGo_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Demo_Go.data.o")

/*
ActorInit Demo_Go_InitVars = {
    ACTOR_DEMO_GO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OF1D_MAP,
    sizeof(DemoGo),
    (ActorFunc)DemoGo_Init,
    (ActorFunc)DemoGo_Destroy,
    (ActorFunc)DemoGo_Update,
    (ActorFunc)DemoGo_Draw,
};
*/

GLOBAL_ASM("binary/DemoGo_Init.o")

GLOBAL_ASM("binary/DemoGo_Destroy.o")

GLOBAL_ASM("binary/DemoGo_Update.o")

GLOBAL_ASM("binary/DemoGo_Draw.o")
}
