extern "C" {
#include "z_en_ge2.hpp"

#define FLAGS 0x00000019

void EnGe2_Init(Actor* actor, GameState* state);
void EnGe2_Destroy(Actor* actor, GameState* state);
void EnGe2_Update(Actor* actor, GameState* state);
void EnGe2_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ge2_InitVars = {
    ACTOR_EN_GE2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GLA,
    sizeof(EnGe2),
    (ActorFunc)EnGe2_Init,
    (ActorFunc)EnGe2_Destroy,
    (ActorFunc)EnGe2_Update,
    (ActorFunc)EnGe2_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnGe2_Init.o")

#pragma GLOBAL_ASM("binary/EnGe2_Destroy.o")

#pragma GLOBAL_ASM("binary/EnGe2_Update.o")

#pragma GLOBAL_ASM("binary/EnGe2_Draw.o")
}
