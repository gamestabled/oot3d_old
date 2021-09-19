extern "C" {
#include "z_en_eg.hpp"

#define FLAGS 0x00000010

void EnEg_Init(Actor* actor, GameState* state);
void EnEg_Destroy(Actor* actor, GameState* state);
void EnEg_Update(Actor* actor, GameState* state);
void EnEg_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Eg_InitVars = {
    ACTOR_EN_EG,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_ZL2,
    sizeof(EnEg),
    (ActorFunc)EnEg_Init,
    (ActorFunc)EnEg_Destroy,
    (ActorFunc)EnEg_Update,
    (ActorFunc)EnEg_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnEg_Init.o")

#pragma GLOBAL_ASM("binary/EnEg_Destroy.o")

#pragma GLOBAL_ASM("binary/EnEg_Update.o")

#pragma GLOBAL_ASM("binary/EnEg_Draw.o")
}
