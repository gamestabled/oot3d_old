extern "C" {
#include "z_en_si.hpp"

#define FLAGS 0x00000201

void EnSi_Init(Actor* actor, GameState* state);
void EnSi_Destroy(Actor* actor, GameState* state);
void EnSi_Update(Actor* actor, GameState* state);
void EnSi_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Si_InitVars = {
    ACTOR_EN_SI,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_ST,
    sizeof(EnSi),
    (ActorFunc)EnSi_Init,
    (ActorFunc)EnSi_Destroy,
    (ActorFunc)EnSi_Update,
    (ActorFunc)EnSi_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnSi_Init.o")

#pragma GLOBAL_ASM("binary/EnSi_Destroy.o")

#pragma GLOBAL_ASM("binary/EnSi_Update.o")

#pragma GLOBAL_ASM("binary/EnSi_Draw.o")
}
