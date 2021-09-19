extern "C" {
#include "z_demo_ec.hpp"

#define FLAGS 0x00000010

void DemoEc_Init(Actor* actor, GameState* state);
void DemoEc_Destroy(Actor* actor, GameState* state);
void DemoEc_Update(Actor* actor, GameState* state);
void DemoEc_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Ec_InitVars = {
    ACTOR_DEMO_EC,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_EC,
    sizeof(DemoEc),
    (ActorFunc)DemoEc_Init,
    (ActorFunc)DemoEc_Destroy,
    (ActorFunc)DemoEc_Update,
    (ActorFunc)DemoEc_Draw,
};
*/

#pragma GLOBAL_ASM("binary/DemoEc_Init.o")

#pragma GLOBAL_ASM("binary/DemoEc_Destroy.o")

#pragma GLOBAL_ASM("binary/DemoEc_Update.o")

#pragma GLOBAL_ASM("binary/DemoEc_Draw.o")
}
