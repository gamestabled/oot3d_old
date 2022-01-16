extern "C" {
#include "z_demo_geff.hpp"

#define FLAGS 0x00000030

void DemoGeff_Init(Actor* actor, GameState* state);
void DemoGeff_Destroy(Actor* actor, GameState* state);
void DemoGeff_Update(Actor* actor, GameState* state);
void DemoGeff_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Demo_Geff.data.o")

ActorInit Demo_Geff_InitVars = {
    ACTOR_DEMO_GEFF,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GEFF,
    sizeof(DemoGeff),
    (ActorFunc)DemoGeff_Init,
    (ActorFunc)DemoGeff_Destroy,
    (ActorFunc)DemoGeff_Update,
    (ActorFunc)DemoGeff_Draw,
};

GLOBAL_ASM("binary/DemoGeff_Init.o")

GLOBAL_ASM("binary/DemoGeff_Destroy.o")

GLOBAL_ASM("binary/DemoGeff_Update.o")

GLOBAL_ASM("binary/DemoGeff_Draw.o")
}
