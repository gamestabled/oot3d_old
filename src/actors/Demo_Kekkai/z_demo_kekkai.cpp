extern "C" {
#include "z_demo_kekkai.hpp"

#define FLAGS 0x00000030

void DemoKekkai_Init(Actor* actor, GameState* state);
void DemoKekkai_Destroy(Actor* actor, GameState* state);
void DemoKekkai_Update(Actor* actor, GameState* state);
void DemoKekkai_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Kekkai_InitVars = {
    ACTOR_DEMO_KEKKAI,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(DemoKekkai),
    (ActorFunc)DemoKekkai_Init,
    (ActorFunc)DemoKekkai_Destroy,
    (ActorFunc)DemoKekkai_Update,
    (ActorFunc)DemoKekkai_Draw,
};
*/
}
