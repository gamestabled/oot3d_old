extern "C" {
#include "z_demo_im.hpp"

#define FLAGS 0x00000011

void DemoIm_Init(Actor* actor, GameState* state);
void DemoIm_Destroy(Actor* actor, GameState* state);
void DemoIm_Update(Actor* actor, GameState* state);
void DemoIm_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Im_InitVars = {
    ACTOR_DEMO_IM,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_IM,
    sizeof(DemoIm),
    (ActorFunc)DemoIm_Init,
    (ActorFunc)DemoIm_Destroy,
    (ActorFunc)DemoIm_Update,
    (ActorFunc)DemoIm_Draw,
};
*/

GLOBAL_ASM("binary/DemoIm_Init.o")

GLOBAL_ASM("binary/DemoIm_Destroy.o")

GLOBAL_ASM("binary/DemoIm_Update.o")

GLOBAL_ASM("binary/DemoIm_Draw.o")
}
