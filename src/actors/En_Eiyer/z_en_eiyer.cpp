extern "C" {
#include "z_en_eiyer.hpp"

#define FLAGS 0x00000005

void EnEiyer_Init(Actor* actor, GameState* state);
void EnEiyer_Destroy(Actor* actor, GameState* state);
void EnEiyer_Update(Actor* actor, GameState* state);
void EnEiyer_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Eiyer_InitVars = {
    ACTOR_EN_EIYER,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_EI,
    sizeof(EnEiyer),
    (ActorFunc)EnEiyer_Init,
    (ActorFunc)EnEiyer_Destroy,
    (ActorFunc)EnEiyer_Update,
    (ActorFunc)EnEiyer_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnEiyer_Init.o")

#pragma GLOBAL_ASM("binary/EnEiyer_Destroy.o")

#pragma GLOBAL_ASM("binary/EnEiyer_Update.o")

#pragma GLOBAL_ASM("binary/EnEiyer_Draw.o")
}
