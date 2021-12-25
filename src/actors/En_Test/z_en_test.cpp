extern "C" {
#include "z_en_test.hpp"

#define FLAGS 0x00000015

void EnTest_Init(Actor* actor, GameState* state);
void EnTest_Destroy(Actor* actor, GameState* state);
void EnTest_Update(Actor* actor, GameState* state);
void EnTest_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Test.data.o")

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

GLOBAL_ASM("binary/EnTest_Init.o")

GLOBAL_ASM("binary/EnTest_Destroy.o")

GLOBAL_ASM("binary/EnTest_Update.o")

GLOBAL_ASM("binary/EnTest_Draw.o")
}
