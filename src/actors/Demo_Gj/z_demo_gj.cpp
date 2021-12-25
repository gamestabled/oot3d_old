extern "C" {
#include "z_demo_gj.hpp"

#define FLAGS 0x00400030

void DemoGj_Init(Actor* actor, GameState* state);
void DemoGj_Destroy(Actor* actor, GameState* state);
void DemoGj_Update(Actor* actor, GameState* state);
void DemoGj_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Demo_Gj.data.o")

/*
ActorInit Demo_Gj_InitVars = {
    ACTOR_DEMO_GJ,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GJ,
    sizeof(DemoGj),
    (ActorFunc)DemoGj_Init,
    (ActorFunc)DemoGj_Destroy,
    (ActorFunc)DemoGj_Update,
    (ActorFunc)DemoGj_Draw,
};
*/

GLOBAL_ASM("binary/DemoGj_Init.o")

GLOBAL_ASM("binary/DemoGj_Destroy.o")

GLOBAL_ASM("binary/DemoGj_Update.o")

GLOBAL_ASM("binary/DemoGj_Draw.o")
}
