extern "C" {
#include "z_en_st.hpp"

#define FLAGS 0x00000035

void EnSt_Init(Actor* actor, GameState* state);
void EnSt_Destroy(Actor* actor, GameState* state);
void EnSt_Update(Actor* actor, GameState* state);
void EnSt_Draw(Actor* actor, GameState* state);

/*
ActorInit En_St_InitVars = {
    ACTOR_EN_ST,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ST,
    sizeof(EnSt),
    (ActorFunc)EnSt_Init,
    (ActorFunc)EnSt_Destroy,
    (ActorFunc)EnSt_Update,
    (ActorFunc)EnSt_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnSt_Init.o")

#pragma GLOBAL_ASM("binary/EnSt_Destroy.o")

#pragma GLOBAL_ASM("binary/EnSt_Update.o")

#pragma GLOBAL_ASM("binary/EnSt_Draw.o")
}
