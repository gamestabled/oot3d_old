extern "C" {
#include "z_demo_gt.hpp"

#define FLAGS 0x00400030

void DemoGt_Init(Actor* actor, GameState* state);
void DemoGt_Destroy(Actor* actor, GameState* state);
void DemoGt_Update(Actor* actor, GameState* state);
void DemoGt_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Gt_InitVars = {
    ACTOR_DEMO_GT,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GT,
    sizeof(DemoGt),
    (ActorFunc)DemoGt_Init,
    (ActorFunc)DemoGt_Destroy,
    (ActorFunc)DemoGt_Update,
    (ActorFunc)DemoGt_Draw,
};
*/

GLOBAL_ASM("binary/DemoGt_Init.o")

GLOBAL_ASM("binary/DemoGt_Destroy.o")

GLOBAL_ASM("binary/DemoGt_Update.o")

GLOBAL_ASM("binary/DemoGt_Draw.o")
}
