extern "C" {
#include "z_demo_go.hpp"

#define FLAGS 0x00000010

void DemoGo_Init(Actor* actor, GameState* state);
void DemoGo_Destroy(Actor* actor, GameState* state);
void DemoGo_Update(Actor* actor, GameState* state);
void DemoGo_Draw(Actor* actor, GameState* state);

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

#pragma GLOBAL_ASM("binary/DemoGo_Init.o")

#pragma GLOBAL_ASM("binary/DemoGo_Destroy.o")

#pragma GLOBAL_ASM("binary/DemoGo_Update.o")

#pragma GLOBAL_ASM("binary/DemoGo_Draw.o")
}
