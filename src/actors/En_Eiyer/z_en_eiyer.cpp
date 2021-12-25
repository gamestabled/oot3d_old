extern "C" {
#include "z_en_eiyer.hpp"

#define FLAGS 0x00000005

void EnEiyer_Init(Actor* actor, GameState* state);
void EnEiyer_Destroy(Actor* actor, GameState* state);
void EnEiyer_Update(Actor* actor, GameState* state);
void EnEiyer_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Eiyer.data.o")

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

GLOBAL_ASM("binary/EnEiyer_Init.o")

GLOBAL_ASM("binary/EnEiyer_Destroy.o")

GLOBAL_ASM("binary/EnEiyer_Update.o")

GLOBAL_ASM("binary/EnEiyer_Draw.o")
}
