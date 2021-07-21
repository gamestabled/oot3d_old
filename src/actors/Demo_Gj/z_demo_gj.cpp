extern "C" {
#include "z_demo_gj.hpp"

#define FLAGS 0x00400030

void DemoGj_Init(Actor* actor, GameState* state);
void DemoGj_Destroy(Actor* actor, GameState* state);
void DemoGj_Update(Actor* actor, GameState* state);
void DemoGj_Draw(Actor* actor, GameState* state);

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
}
