extern "C" {
#include "z_en_test.hpp"

#define FLAGS 0x00000015

void EnTest_Init(Actor* actor, GameState* state);
void EnTest_Destroy(Actor* actor, GameState* state);
void EnTest_Update(Actor* actor, GameState* state);
void EnTest_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Test_InitVars = {
    ACTOR_EN_TEST,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SK2,
    sizeof(EnTest),
    (ActorFunc)EnTest_Init,
    (ActorFunc)EnTest_Destroy,
    (ActorFunc)EnTest_Update,
    (ActorFunc)EnTest_Draw,
};
*/
}
