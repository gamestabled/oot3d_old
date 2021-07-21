extern "C" {
#include "z_demo_tre_lgt.hpp"

#define FLAGS 0x00000010

void DemoTreLgt_Init(Actor* actor, GameState* state);
void DemoTreLgt_Destroy(Actor* actor, GameState* state);
void DemoTreLgt_Update(Actor* actor, GameState* state);
void DemoTreLgt_Draw(Actor* actor, GameState* state);

/*
ActorInit Demo_Tre_Lgt_InitVars = {
    ACTOR_DEMO_TRE_LGT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_BOX,
    sizeof(DemoTreLgt),
    (ActorFunc)DemoTreLgt_Init,
    (ActorFunc)DemoTreLgt_Destroy,
    (ActorFunc)DemoTreLgt_Update,
    (ActorFunc)DemoTreLgt_Draw,
};
*/
}
