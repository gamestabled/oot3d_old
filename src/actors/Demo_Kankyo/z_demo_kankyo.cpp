extern "C" {
#include "z_demo_kankyo.hpp"

#define FLAGS 0x00000030

void DemoKankyo_Init(Actor* actor, GameState* state);
void DemoKankyo_Destroy(Actor* actor, GameState* state);
void DemoKankyo_Update(Actor* actor, GameState* state);
void DemoKankyo_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Kankyo_InitVars = {
    ACTOR_DEMO_KANKYO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(DemoKankyo),
    (ActorFunc)DemoKankyo_Init,
    (ActorFunc)DemoKankyo_Destroy,
    (ActorFunc)DemoKankyo_Update,
    (ActorFunc)DemoKankyo_Draw,
};
*/

GLOBAL_ASM("binary/DemoKankyo_Init.o")

GLOBAL_ASM("binary/DemoKankyo_Destroy.o")

GLOBAL_ASM("binary/DemoKankyo_Update.o")

GLOBAL_ASM("binary/DemoKankyo_Draw.o")
}
