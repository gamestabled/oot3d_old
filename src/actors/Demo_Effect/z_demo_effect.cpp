extern "C" {
#include "z_demo_effect.hpp"

#define FLAGS 0x00000030

void DemoEffect_Init(Actor* actor, GameState* state);
void DemoEffect_Destroy(Actor* actor, GameState* state);
void DemoEffect_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Demo_Effect.data.o")

ActorInit Demo_Effect_InitVars = {
    ACTOR_DEMO_EFFECT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(DemoEffect),
    (ActorFunc)DemoEffect_Init,
    (ActorFunc)DemoEffect_Destroy,
    (ActorFunc)DemoEffect_Update,
    NULL,
};

GLOBAL_ASM("binary/DemoEffect_Init.o")

GLOBAL_ASM("binary/DemoEffect_Destroy.o")

GLOBAL_ASM("binary/DemoEffect_Update.o")
}
