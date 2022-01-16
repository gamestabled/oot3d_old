extern "C" {
#include "z_demo_ik.hpp"

#define FLAGS 0x00000010

void DemoIk_Init(Actor* actor, GameState* state);
void DemoIk_Destroy(Actor* actor, GameState* state);
void DemoIk_Update(Actor* actor, GameState* state);
void DemoIk_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Demo_Ik.data.o")

ActorInit Demo_Ik_InitVars = {
    ACTOR_DEMO_IK,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_IK,
    sizeof(DemoIk),
    (ActorFunc)DemoIk_Init,
    (ActorFunc)DemoIk_Destroy,
    (ActorFunc)DemoIk_Update,
    (ActorFunc)DemoIk_Draw,
};

GLOBAL_ASM("binary/DemoIk_Init.o")

GLOBAL_ASM("binary/DemoIk_Destroy.o")

GLOBAL_ASM("binary/DemoIk_Update.o")

GLOBAL_ASM("binary/DemoIk_Draw.o")
}
