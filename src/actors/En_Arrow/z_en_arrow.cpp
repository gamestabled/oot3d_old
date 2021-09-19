extern "C" {
#include "z_en_arrow.hpp"

#define FLAGS 0x00000030

void EnArrow_Init(Actor* actor, GameState* state);
void EnArrow_Destroy(Actor* actor, GameState* state);
void EnArrow_Update(Actor* actor, GameState* state);
void EnArrow_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Arrow_InitVars = {
    ACTOR_EN_ARROW,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnArrow),
    (ActorFunc)EnArrow_Init,
    (ActorFunc)EnArrow_Destroy,
    (ActorFunc)EnArrow_Update,
    (ActorFunc)EnArrow_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnArrow_Init.o")

#pragma GLOBAL_ASM("binary/EnArrow_Destroy.o")

#pragma GLOBAL_ASM("binary/EnArrow_Update.o")

#pragma GLOBAL_ASM("binary/EnArrow_Draw.o")
}
